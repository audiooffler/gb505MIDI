/*
  ==============================================================================

    RhythmSetBlock.h
    Created: 15 Jan 2014 9:18:53pm
    Author:  Martin

  ==============================================================================
*/

#ifndef RHYTHMSETBLOCK_H_INCLUDED
#define RHYTHMSETBLOCK_H_INCLUDED

#include "GrooveboxMemoryBlock.h"

class RhythmCommonBlock : public GrooveboxMemoryBlock
{
public:
	RhythmCommonBlock() :
		GrooveboxMemoryBlock(0x02090000, "Rhythm Set Name", "1-4-1", 0x0C)
	{
		m_name = "Rhythm Common";
	}

	String getRhythmSetName()
	{
		return String((char*)m_data.getData(), 12);
	}

	void setRhytmSetName(String rhythmSetName)
	{
		for (int i = 0; i < 12 && i < rhythmSetName.length(); i++)
		{
			char c = (char) rhythmSetName[i];
			if (c < 32 || c>125) c = 32;	// fallback to space
			m_data[i] = c;
		}
	}

private:
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(RhythmCommonBlock)
};

class RhythmNoteBlock : public GrooveboxMemoryBlock
{
public:
	// key must be of 35..98 (64 keys)
	RhythmNoteBlock(uint8 key) :
		GrooveboxMemoryBlock(0x02090000 | key, "Rhythm Note for Key " + String(key), "1-4-2"),
		m_key(key)
	{
		m_name = "Rhythm Note";
	}

	uint8 getKey(){ return m_key; }
private:
	uint8 m_key;
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(RhythmNoteBlock)
};



class RhythmSetBlock : public GrooveboxMemoryBlock
{
public:
	RhythmSetBlock() :
		GrooveboxMemoryBlock(0x02090000, "Rhythm Set", "1-4")
	{
		m_name = "Rhythm Setup";
		addSubBlock(new RhythmCommonBlock());
		// add address blocks for 64 keys
		for (uint8 i = 35; i <= 98; i++)
		{
			addSubBlock(new RhythmNoteBlock(i));
		}
	}

	// key must be of 35..98 (64 keys)
	RhythmNoteBlock* getRhythmNoteBlockPtr(uint8 key)
	{
		return dynamic_cast<RhythmNoteBlock*>(getSubBlock(key - 24)); // (map 35 --> 1 : -24)
	}
	
	RhythmCommonBlock* getRhythmSetCommonBlockPtr()
	{
		return dynamic_cast<RhythmCommonBlock*>(getSubBlock(0));
	}

private:
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(RhythmSetBlock)
};

#endif  // RHYTHMSETBLOCK_H_INCLUDED
