/*
  ==============================================================================

    GrooveboxMemoryBlock.cpp
    Created: 15 Jan 2014 11:46:17pm
    Author:  Martin

  ==============================================================================
*/

#include "GrooveboxMemoryBlock.h"
#include "../GUI/ParameterWidgets/ParameterSlider.h"
#include "PartInfoBlock.h"
#include "SynthPatchesBlock.h"
#include "RhythmSetBlock.h"
#include "SystemBlock.h"
#include "OverallMemoryBlock.h"

// creates a grooevbox sysex memory block. the name property must be set by subclass constructrors.
// careful when calculating with address or totalSize, interpret as 4 x 7 bit instread of 4 x 8 bit!
GrooveboxMemoryBlock::GrooveboxMemoryBlock(uint32 address, String description, String referenceSectionInOperationManual, uint32 totalSize) :
m_address(address),
m_description(description),
m_referenceSectionInOperationManual(referenceSectionInOperationManual),
m_totalSize(totalSize)
{	
	if (totalSize > 0)
	{
		m_type = BlockType::DataBlock;
		m_data.setSize(getTotalSizeRealValue(), true);
		// init param array with nullptr for all possible parameters in the block addresses
		for (uint32 i = 0; i < totalSize; i++)
		{
			m_parameters.add(nullptr);
		}
	}
	else m_type = BlockType::GroupBlock;
}

// virtual constructor makes this class abstract, only concrete subclasses can be instantiated
GrooveboxMemoryBlock::~GrooveboxMemoryBlock()
{
}

const String GrooveboxMemoryBlock::getBlockName() 
{
	return m_name; 
}

uint32 GrooveboxMemoryBlock::getAddress() 
{
	return m_address; 
}

String GrooveboxMemoryBlock::getDescription()
{ 
	return m_description; 
}

String GrooveboxMemoryBlock::getReferenceSectionInOperationManual()
{ 
	return m_referenceSectionInOperationManual;
}

uint32 GrooveboxMemoryBlock::getTotalSizeMidiHexNotation() 
{
	return m_totalSize;
}


uint32 GrooveboxMemoryBlock::getTotalSizeRealValue()
{
	if (m_totalSize < 0x80) return m_totalSize;
	else
	{
		return (m_totalSize & 0x000000FF) +
			((m_totalSize & 0x0000FF00) >> 1) +
			((m_totalSize & 0x00FF0000) >> 2) +
			((m_totalSize & 0xFF000000) >> 3);
	}
}

OwnedArray<GrooveboxMemoryBlock, CriticalSection>* GrooveboxMemoryBlock::getSubBlocks()
{
	return &m_subBlocks;
}

StringArray GrooveboxMemoryBlock::getSubBlockNames()
{
	StringArray result;
	for (int i = 0; i<m_subBlocks.size(); i++) result.add(m_subBlocks[i]->getBlockName());
	return result;
}

GrooveboxMemoryBlock* GrooveboxMemoryBlock::getSubBlock(int i)
{
	if (i>=0 && i < m_subBlocks.size()) return m_subBlocks[i];
	else return nullptr;
}

GrooveboxMemoryBlock* GrooveboxMemoryBlock::getSubBlock(String name)
{
	StringArray subBlockNames = getSubBlockNames();
	if (subBlockNames.contains(name)) return m_subBlocks[subBlockNames.indexOf(name)];
	else return nullptr;
}

// get parameter by offset address in block 
Parameter* GrooveboxMemoryBlock::getParameter(uint16 addressOffset)
{
	return m_parameters[addressOffset];
}

Parameter* GrooveboxMemoryBlock::getParameterForCC(uint8 ccNo)
{
	for (int i = 0; i < m_parameters.size(); i++)
	{
		if (m_parameters[i] != nullptr && m_parameters[i]->getCC() == ccNo) return m_parameters[i];
	}
	return nullptr;
}

bool GrooveboxMemoryBlock::handleSysEx(SyxMsg* sysExMsg)
{
	// only hande DT1 sysex messages
	if (sysExMsg == nullptr || sysExMsg->getType() != SyxMsg::Type_DT1) return false;

	uint32 blockStartAddress = sysExMsg->getBlockStartAddress();	// First 2 Bytes
	uint16 addressOffset = sysExMsg->getAddressOffset();			// Least 2 Bytes
	// for the following block types: first 3 Bytes are address || least byte offset
	if (
		dynamic_cast<ScaleTuneBlock*>(this) ||
		dynamic_cast<PartInfoPartBlock*>(this) ||
		dynamic_cast<PatchToneBlock*>(this) ||
		dynamic_cast<RhythmNoteBlock*>(this)
		)
	{
		blockStartAddress = blockStartAddress + (addressOffset & 0xFF00);
		addressOffset = addressOffset & 0xFF;
	}
	bool success(false);

	// if in a block without defined parameters (total byte length is zero) handle in subBlocks if start address is not smaller
	if (m_totalSize < 1 && m_subBlocks.size() > 0 && blockStartAddress >= m_address)
	{
		for (int s = 0; s < m_subBlocks.size(); s++)
		{
			success |= m_subBlocks[s]->handleSysEx(sysExMsg);
		}
	}
	// if no subBlock but byte length defined and start address matching set data
	else if (m_totalSize > 0 && m_subBlocks.size() == 0 && blockStartAddress == m_address)
	{
		uint8* data;
		uint32 dataLength(0);
		sysExMsg->getSysExDataArrayPtr(&data, dataLength);

		//m_data.copyFrom(data, sysExMsg->getAddressOffset(), dataLength);
		for (uint16 t = 0, addressOffset = sysExMsg->getAddressOffset(); t < dataLength; addressOffset++, t++)
		{
			// addressOffset only 1 Byte for these block types:
			if (dynamic_cast<ScaleTuneBlock*>(this) ||		// 1-1-2. Scale Tune (2nd-last Byte for Part-No of 1-1. System)
				dynamic_cast<PartInfoPartBlock*>(this) ||	// 1-2-2. Part Info Part n (2nd-last Byte for Part-No of 1-2. Part Info)
				dynamic_cast<PatchToneBlock*>(this) ||		// 1-3-2. Patch Tone (2nd-last Byte for Tone-No of 1-3. Patch Tone)
				dynamic_cast<RhythmNoteBlock*>(this))		// 1-4-2. Rhythm Note n	(2nd-last Byte for Key-No of 1-3 Rhythm Setup)
			{
				addressOffset = addressOffset & 0xFF;
			}

			if (addressOffset < m_parameters.size())
			{
				if (Parameter* param = m_parameters[addressOffset])
				{
					// 2 byte parameter:
					if (param->getMax()>127 && addressOffset + 1 < m_parameters.size())
					{
						param->setValue((data[t] & 0xF) << 4 | (data[t + 1] & 0xF), Parameter::MidiInFromGroovebox);
						// jump over next byte
						t++; addressOffset++;
					}
					else // 1 byte parameter:
						param->setValue(data[t], Parameter::MidiInFromGroovebox);
					// sysExMessage sucessfully consumed
					success = true;
				}
			}
		}
	}
	return success;
}

// called when loading from sysex file or by RetrieveSysExThread or even when groovebox sends single changes
void GrooveboxMemoryBlock::handleSysEx(OwnedArray<SyxMsg, CriticalSection>& sysExMessageArray)
{
	
	while (sysExMessageArray.size() > 0)
	{
		handleSysEx(sysExMessageArray[0]);
		sysExMessageArray.remove(0, true);
	}
}

// does nothing but calling handleCC of children by default but may be overridden in subclasses to handle CC evets
void GrooveboxMemoryBlock::handleCCFromGroovebox(uint8 channel, uint8 controllerType, uint8 value)
{
	int ccChannel = -1;
	// find channel for CC by block's part 
	if (PartInfoPartBlock* partInfoPart = dynamic_cast<PartInfoPartBlock*>(this))
	{
		ccChannel = (partInfoPart->getPart() + 1);
	}
	else if (PatchCommonBlock* patchCommon = dynamic_cast<PatchCommonBlock*>(this))
	{
		ccChannel = (patchCommon->getPart() + 1);
	}
	else if (PatchToneBlock* patchTone = dynamic_cast<PatchToneBlock*>(this))
	{
		ccChannel = (patchTone->getPart() + 1);
	}
	else if (RhythmNoteBlock* rhythmNote = dynamic_cast<RhythmNoteBlock*>(this))
	{
		ccChannel = 10;
	}
	// if channel matches, look up controller type
	if (ccChannel == channel)
	{
		Parameter* ccParam(getParameterForCC(controllerType));
		if (ccParam != nullptr)
		{
			uint8 v = value - ((ccParam->getMax() > 64) ? (uint8)(64.0 - (ccParam->getMax() - ccParam->getMin()) / 2.0) : 0);
			//DBG(String(ccChannel) + " " + String(controllerType) + " " + String(v));
			ccParam->setValue(v, Parameter::MidiInFromGroovebox);
		}
	}
	
	// inform subblocks about cc for special handling
	for (int i = 0; i < m_subBlocks.size(); i++)
	{
		m_subBlocks[i]->handleCCFromGroovebox(channel, controllerType, value);
	}
	// TODO: if not coming from midi in port that is part of active connection to groovebox, send to midiout (should be handled outside this, in mini in handler or so...)
}

// Create a sysex request message for getting a parameter. Gets 1 byte by default, but more can be requested (e.g. for getting name Patch Name parameters in one row: 12)
SyxMsg* GrooveboxMemoryBlock::createParameterRequestMsg(Parameter* param, uint8 size)
{
	if (!m_parameters.contains(param)) return nullptr;
	uint8 deviceId((grooveboxConnector != nullptr) ? grooveboxConnector->getActiveDeviceId() : 0x10);
	if (deviceId < 0x10) deviceId = 0x10;
	uint32 address(m_address | param->getAddressOffset());
	uint8* addressArray = new uint8[4] { (uint8)((address >> 24) & 0x000000FF), (uint8)((address >> 16) & 0x000000FF), (uint8)((address >> 8) & 0x000000FF), (uint8)(address & 0x000000FF) };
	uint8* sizeArray = new uint8[4] { 0, 0, 0, size };
	uint8 chk(SyxMsg::calcRq1Checksum(addressArray, sizeArray));
	SyxMsg* result = new SyxMsg(SyxMsg::Type_RQ1, deviceId, addressArray, sizeArray, 4, chk);
	delete[] addressArray;
	delete[] sizeArray;
	return result;
}

// get data request messages from this block and its sub blocks,
// the result is added to the array specified in the parameter
void GrooveboxMemoryBlock::createBlockRequestMessages(OwnedArray<SyxMsg, CriticalSection>* syxMsgArrayPtr)
{
	if (syxMsgArrayPtr == nullptr) return;

	uint8 deviceId((grooveboxConnector != nullptr) ? grooveboxConnector->getActiveDeviceId() : 0x10);
	if (deviceId < 0x10) deviceId = 0x10;
	if (m_totalSize>0)
	{
		uint8* addressArray = new uint8[4] { (uint8)((m_address >> 24) & 0x000000FF), (uint8)((m_address >> 16) & 0x000000FF), (uint8)((m_address >> 8) & 0x000000FF), (uint8)(m_address & 0x000000FF) };
		uint8* sizeArray = new uint8[4] { (uint8)((m_totalSize >> 24) & 0x000000FF), (uint8)((m_totalSize >> 16) & 0x000000FF), (uint8)((m_totalSize >> 8) & 0x000000FF), (uint8)(m_totalSize & 0x000000FF) };
		uint8 chk(SyxMsg::calcRq1Checksum(addressArray, sizeArray));
		syxMsgArrayPtr->add(new SyxMsg(SyxMsg::Type_RQ1, deviceId, addressArray, sizeArray, 4, chk));
		delete[] addressArray;
		delete[] sizeArray;
	}
	// collect requests from subblocks
	if (m_subBlocks.size()>0)
	{
		for (int i = 0; i < m_subBlocks.size(); i++)
		{
			// add from subBlocks
			m_subBlocks[i]->createBlockRequestMessages(syxMsgArrayPtr);
		}
	}
}

// Create a sysex send message for setting a parameter with DT1. Sets 1 byte by default, but more in a row can be sent (e.g. for setting name Patch Name parameters in one row: 12)
// TODO: override for some parameters to create quick sysex send or for scale tunes create gs (by default DT1 sysex is created)
SyxMsg* GrooveboxMemoryBlock::createParameterSendMsg(Parameter* param, uint8 size)
{
	if (!m_parameters.contains(param)) return nullptr;
	uint8 deviceId((grooveboxConnector != nullptr) ? grooveboxConnector->getActiveDeviceId() : 0x10);
	if (deviceId < 0x10) deviceId = 0x10;
	uint32 address(m_address | param->getAddressOffset());
	uint8* addressArray = new uint8[4] { (uint8)((address >> 24) & 0x000000FF), (uint8)((address >> 16) & 0x000000FF), (uint8)((address >> 8) & 0x000000FF), (uint8)(address & 0x000000FF) };
	uint8* dataArray = new uint8[size];
	for (uint32 i = 0; i < size && i<getTotalSizeRealValue(); i++)
	{
		dataArray[i] = m_data[i + param->getAddressOffset()];
	}
	uint8 chk(SyxMsg::calcDt1Checksum(addressArray, 4, dataArray, size));
	SyxMsg* result = new SyxMsg(SyxMsg::Type_DT1, deviceId, addressArray, dataArray, size, chk);
	delete[] dataArray;
	delete[] addressArray;
	return result;
}

// create sysex messages for sending block data of this block and all sub blocks,
// the result is added to the array specified in the parameter
void GrooveboxMemoryBlock::createBlockSendMessages(OwnedArray<SyxMsg, CriticalSection>* syxMsgArrayPtr)
{
	if (syxMsgArrayPtr == nullptr) return;

	uint8 deviceId((grooveboxConnector != nullptr) ? grooveboxConnector->getActiveDeviceId() : 0x10);
	if (deviceId < 0x10) deviceId = 0x10;
	if (m_totalSize>0)
	{
		uint8* addressArray = new uint8[4] { (uint8)((m_address >> 24) & 0x000000FF), (uint8)((m_address >> 16) & 0x000000FF), (uint8)((m_address >> 8) & 0x000000FF), (uint8)(m_address & 0x000000FF) };
		uint8* dataArray = new uint8[getTotalSizeRealValue()];
		for (uint32 i = 0; i < getTotalSizeRealValue(); i++)
		{
			dataArray[i] = m_data[i];
		}
		uint8 chk(SyxMsg::calcDt1Checksum(addressArray, 4, dataArray, getTotalSizeRealValue()));
		syxMsgArrayPtr->add(new SyxMsg(SyxMsg::Type_DT1, deviceId, addressArray, dataArray, getTotalSizeRealValue(), chk));
		delete[] dataArray;
		delete[] addressArray;
	}
	// collect requests from subblocks
	if (m_subBlocks.size()>0)
	{
		for (int i = 0; i < m_subBlocks.size(); i++)
		{
			// add from subBlocks
			m_subBlocks[i]->createBlockRequestMessages(syxMsgArrayPtr);
		}
	}
}

// added SubBlock will be owned and deleted by this class
void GrooveboxMemoryBlock::addSubBlock(GrooveboxMemoryBlock* subBlock)
{
	m_subBlocks.add(subBlock);
}

// set up a parameter for this data block (with given addressOffset 
// this can also be used to change parameters (useful for the MFX parameter section when switching the effect type)
void GrooveboxMemoryBlock::setupParameter(String name, uint16 addressOffset, uint8 min, uint8 max, uint8 default, StringArray displayedValues, String description, uint8 cc, bool ccIsMode2Only)
{
	// if empty: create parameter
	if (m_parameters[addressOffset] == nullptr) 
	{
		m_parameters.set(addressOffset, new Parameter(this, name, addressOffset, min, max, default, displayedValues, description, cc, ccIsMode2Only), true);
	}
	// else: change param
	else
	{
		// the parameter stays the same object (keeps its listeners) but changes min, max, displayedValues and description
		m_parameters[addressOffset]->setName(name);
		m_parameters[addressOffset]->setMin(min);
		m_parameters[addressOffset]->setMax(max);
		m_parameters[addressOffset]->setDefault(default);
		m_parameters[addressOffset]->setDisplayedValues(displayedValues);
		m_parameters[addressOffset]->setDescription(description);		
		m_parameters[addressOffset]->setCC(cc);
		m_parameters[addressOffset]->setCCisMode2Only(ccIsMode2Only);
		m_parameters[addressOffset]->sendChangeMessage();
	}
}