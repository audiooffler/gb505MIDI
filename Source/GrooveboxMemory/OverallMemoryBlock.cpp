/*
  ==============================================================================

    OverallMemoryBlock.cpp
    Created: 16 Jan 2016 6:21:56pm
    Author:  Martin

  ==============================================================================
*/

#include "OverallMemoryBlock.h"
extern GrooveboxConnector* grooveboxConnector;

OverallMemoryBlock::OverallMemoryBlock() : GrooveboxMemoryBlock(0x00000000, "Groovebox SysEx Memory")
{
	m_name = "Overall";
	addSubBlock(new SystemBlock());
	addSubBlock(new PartInfoBlock());
	addSubBlock(new SynthPatchesBlock());
	addSubBlock(new RhythmSetBlock());
	addSubBlock(new PatternSetupBlock());
	addSubBlock(new PatternBodyBlock());
}

SystemBlock* OverallMemoryBlock::getSystemBlock() 
{
	return dynamic_cast<SystemBlock*> (m_subBlocks[0]);
}

PartInfoBlock* OverallMemoryBlock::getPartInfoBlock() 
{
	return dynamic_cast<PartInfoBlock*> (m_subBlocks[1]);
}

SynthPatchesBlock* OverallMemoryBlock::getSynthPatchesBlock() 
{
	return dynamic_cast<SynthPatchesBlock*> (m_subBlocks[2]);
}

RhythmSetBlock* OverallMemoryBlock::getRhythmSetBlock() 
{
	return dynamic_cast<RhythmSetBlock*> (m_subBlocks[3]);
}

PatternSetupBlock* OverallMemoryBlock::getPatternSetupBlock()
{
	return dynamic_cast<PatternSetupBlock*> (m_subBlocks[4]);
}

PatternBodyBlock* OverallMemoryBlock::getPatternBodyBlock()
{
	return dynamic_cast<PatternBodyBlock*> (m_subBlocks[5]);
}

bool OverallMemoryBlock::loadFromArray(OwnedArray<SyxMsg, CriticalSection>& sysExMessageArray)
{
	if (sysExMessageArray.size() > 0)
	{
		this->handleSysEx(sysExMessageArray);
		return true;
	}
	return false;
}

bool OverallMemoryBlock::loadBinarySysExFile(const File& file)
{
	ScopedPointer<FileInputStream> inputStream = file.createInputStream();
	MemoryBlock readBuffer(0);			// buffer for reading the next 1024 bytes from file input stream
	MemoryBlock currentSysExMessage(0);	// buffer for creating a sysex message from read bytes
	OwnedArray<SyxMsg, CriticalSection> sysExMessageArray;

	while (!inputStream->isExhausted())
	{
		// reset readBuffer 
		readBuffer.setSize(0);
		// read next 1024 bytes from stream into readBuffer
		inputStream->readIntoMemoryBlock(readBuffer, 1024);
		// process read readBuffer bytes
		for (unsigned int i = 0; i < readBuffer.getSize(); i++)
		{
			if ((uint8)readBuffer[i] == 0xF0) // sysex start (0xF0)
			{
				currentSysExMessage.setSize(0);					// clear buffer	
				currentSysExMessage.append(&readBuffer[i], 1);   // add F0
			}
			else if ((uint8)readBuffer[i] == 0xF7) // sysex stop (0xF7)
			{
				currentSysExMessage.append(&readBuffer[i], 1);	// add F7 
				// create and store completed sysex message
				sysExMessageArray.add(new SyxMsg((uint8*)currentSysExMessage.getData(), (uint32)currentSysExMessage.getSize(), true));
			}
			else // sysex content data (between 0xF0 and 0xF7 bytes)
			{
				currentSysExMessage.append(&readBuffer[i], 1);	// add byte
			}
		}
	}
	return loadFromArray(sysExMessageArray);
}

bool OverallMemoryBlock::loadHexTxtSysExFile(const File& file)
{
	MemoryBlock readBuffer;
	readBuffer.loadFromHexString(file.loadFileAsString());
	MemoryBlock currentSysExMessage(256, true);
	OwnedArray<SyxMsg, CriticalSection> sysExMessageArray;
	// process read readBuffer bytes
	for (unsigned int i = 0; i < readBuffer.getSize(); i++)
	{
		if ((uint8)readBuffer[i] == 0xF0)		// sysex start
		{
			currentSysExMessage.setSize(0);					// clear buffer	
			currentSysExMessage.append(&readBuffer[i], 1);	// add F0
		}
		else if ((uint8)readBuffer[i] == 0xF7)	// sysex stop
		{
			currentSysExMessage.append(&readBuffer[i], 1);	// add F7 
			// create and store completed sysex message
			sysExMessageArray.add(new SyxMsg((uint8*)currentSysExMessage.getData(), (uint32)currentSysExMessage.getSize(), true));
		}
		else					// other sysex data
		{
			currentSysExMessage.append(&readBuffer[i], 1);	// add byte
		}
	}

	return loadFromArray(sysExMessageArray);
}

bool OverallMemoryBlock::loadStandardMidiFile(const File& /*file*/)
{
	return false;
}
