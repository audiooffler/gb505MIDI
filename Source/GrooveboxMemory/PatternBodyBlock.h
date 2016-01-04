/*
  ==============================================================================

    PatternBodyBlock.h
    Created: 15 Jan 2014 9:19:05pm
    Author:  Martin

  ==============================================================================
*/

#ifndef PATTERNBODYBLOCK_H_INCLUDED
#define PATTERNBODYBLOCK_H_INCLUDED

#include "GrooveboxMemoryBlock.h"

enum PatternParts
{
	Pattern_Part_1 = 0x00,
	Pattern_Part_2 = 0x01,
	Pattern_Part_3 = 0x02,
	Pattern_Part_4 = 0x03,
	Pattern_Part_5 = 0x04,
	Pattern_Part_6 = 0x05,
	Pattern_Part_7 = 0x06,
	Pattern_Part_R = 0x09,
	Pattern_MuteCtrl = 0x0E,
	Pattern_Part_Unknown = 0xFF
};

enum PatternEventType
{
	Evt_Note = 0,
	Evt_TickInc = 1,
	Evt_PAft = 2,
	Evt_Cc = 3,
	Evt_Pc = 4,
	Evt_CAft = 5,
	Evt_PBend = 6,
	Evt_Tempo = 7,
	Evt_PartMute = 8,
	Evt_RhyMute = 9,
	Evt_SysExSize = 10,
	Evt_SysExData = 11,
	Evt_Unknown = -1
};

// TODO: to csv (readable in excel), similar to microscope view -> select channels (all/none dialog)
//String PatternBodyBlock::toCsvString()
//{
//
//}
class PatternBodyBlock : public GrooveboxMemoryBlock
{
public:
	struct PatternEventData
	{
		uint8 byte[8];
	};

	PatternBodyBlock() :
		GrooveboxMemoryBlock(0x40000000, "Pattern Body Data", "1-6", 0x00000000)
	{
		m_name = "Pattern Body";
		// no parameters, just big data block
	}

	String toCsvString();
private:
	OwnedArray<PatternEventData> m_sequenceBlocks;	// containing 8 bytes each
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(PatternBodyBlock)
};



#endif  // PATTERNBODYBLOCK_H_INCLUDED
