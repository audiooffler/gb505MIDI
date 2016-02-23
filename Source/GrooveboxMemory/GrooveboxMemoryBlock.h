/*
  ==============================================================================

  GrooveboxMemoryBlock.h
  Created: 7 Jan 2014 8:19:19pm
  Author:  Martin

  ==============================================================================
  */

#ifndef GrooveboxMemoryBlock_H_INCLUDED
#define GrooveboxMemoryBlock_H_INCLUDED

#include "JuceHeader.h"
#include "../MIDIConnection/SyxMsg.h"
#include "Parameter.h"
#include "../MIDIConnection/GrooveboxConnector.h"

extern GrooveboxConnector* grooveboxConnector;
extern UndoManager* undoManager;

class GrooveboxMemoryBlock
{
	friend class Parameter;

public:

	enum BlockType
	{
		DataBlock,
		GroupBlock
	};

	// creates a grooevbox sysex memory block. the name property must be set by subclass constructrors.
	// careful when calculating with address or totalSize, interpret as 4 x 7 bit instread of 4 x 8 bit!
	GrooveboxMemoryBlock(uint32 address, String description = String::empty, String referenceSectionInOperationManual = String::empty, uint32 totalSize = 0);
	
	// virtual constructor makes this class abstract, only concrete subclasses can be instantiated
	virtual ~GrooveboxMemoryBlock() = 0;		
	const String getBlockName();
	uint32 getAddress();
	String getDescription();
	String getReferenceSectionInOperationManual();
	uint32 getTotalSizeMidiHexNotation();
	uint32 getTotalSizeRealValue();

	OwnedArray<GrooveboxMemoryBlock, CriticalSection>* getSubBlocks();

	StringArray getSubBlockNames();

	GrooveboxMemoryBlock* getSubBlock(int i);

	GrooveboxMemoryBlock* getSubBlock(String name);

	// get by offset address in block
	Parameter* getParameter(uint16 addressOffset);

	// look up parameter that is registered to a MIDI CC number. returns nullptr if none in this block matches the CC number.
	Parameter* getParameterForCC(uint8 ccNo);

	// handle one sysex message
	virtual bool handleSysEx(SyxMsg* msg);

	// called when loading from sysex file or by RetrieveSysExThread
	// overrideable, e.g. for pattern setup and pattern body blocks
	// TODO: quick sysex
	virtual void handleSysEx(OwnedArray<SyxMsg, CriticalSection>& sysExMessageArray);

	// does nothing but calling handleCC of children by default but may be overridden in subclasses to handle CC evets
	void handleCCFromGroovebox(uint8 channel, uint8 controllerType, uint8 value);

	// Create a sysex request message for getting a parameter. Gets 1 byte by default, but more can be requested (e.g. for getting name Patch Name parameters in one row: 12)
	virtual SyxMsg* createParameterRequestMsg(Parameter* param, uint8 size = 1);

	// get data request messages from this block and its sub blocks,
	// the result is added to the array specified in the parameter
	void createBlockRequestMessages(OwnedArray<SyxMsg, CriticalSection>* syxMsgArrayPtr);

	// Create a sysex send message for setting a parameter. Sets 1 byte by default, but more in a row can be sent (e.g. for setting name Patch Name parameters in one row: 12)
	// TODO: override for some parameters to create quick sysex send or for scale tunes create gs (by default DT1 sysex is created)
	virtual SyxMsg* createParameterSendMsg(Parameter* param, uint8 size = 1);

	// create sysex message for sending block data of this block and all sub blocks,
	// the result is added to the array specified in the parameter
	virtual void createBlockSendMessages(OwnedArray<SyxMsg, CriticalSection>* syxMsgArrayPtr);

	// added SubBlock will be owned and deleted by this class
	void addSubBlock(GrooveboxMemoryBlock* subBlock);

	// add, set (if addressOffset already used) or delete (if addressOffset already used and name is empty)
	void setupParameter(String name, uint16 addressOffset, uint8 min, uint8 max, uint8 default = 0, StringArray displayedValues = StringArray(), String description = String::empty, uint8 cc = 102, bool ccIsMode2Only = false);

protected:

	String m_name;	  // name of the data block
	uint32 m_address; // compulsory, careful when calculating: interpret as 4 x 7 bit instead of 4 x 8 bit!
	String m_description; // set optional, descriptive
	String m_referenceSectionInOperationManual; // set optional, descriptive
	uint32 m_totalSize; // set optional, careful when calculating: interpret as 4 x 7 bit instead of 4 x 8 bit!
	OwnedArray<GrooveboxMemoryBlock, CriticalSection> m_subBlocks; // filled optionally (may have no sub blocks)
	OwnedArray<Parameter, CriticalSection> m_parameters; // filled optionally (may have none if it just has sub blocks)
	MemoryBlock m_data; // filled optionally (may have none if it just has sub blocks)
	BlockType m_type;	// is this a data block or just a group block containing sub blocks

	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(GrooveboxMemoryBlock)
};

enum SynthParts
{
	SynthPart1 = 0x00,
	SynthPart2 = 0x01,
	SynthPart3 = 0x02,
	SynthPart4 = 0x03,
	SynthPart5 = 0x04,
	SynthPart6 = 0x05,
	SynthPart7 = 0x06
};

enum AllParts
{
	Part1 = 0x00,
	Part2 = 0x01,
	Part3 = 0x02,
	Part4 = 0x03,
	Part5 = 0x04,
	Part6 = 0x05,
	Part7 = 0x06,
	PartR = 0x09
};

enum Tone
{
	Tone1 = 0x1000,
	Tone2 = 0x1200,
	Tone3 = 0x1400,
	Tone4 = 0x1600,
};

enum RhythmGroup
{
	BD		 = 0,
	SD		 = 1, 
	HH		 = 2, 
	CLP		 = 3, 
	CYM		 = 4, 
	TOM_PERC = 5, 
	HIT		 = 6, 
	OTHERS	 = 7,
	ALL		 = 9
};

#endif  // GrooveboxMemoryBlock_H_INCLUDED
