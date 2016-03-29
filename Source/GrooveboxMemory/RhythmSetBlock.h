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
	RhythmCommonBlock();
	String getRhythmSetName();
	void setRhytmSetName(String rhythmSetName);

private:
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(RhythmCommonBlock)
};

class RhythmNoteBlock : public GrooveboxMemoryBlock
{
public:
	// key must be of 35=0x23..98=0x62 (64 keys)
	RhythmNoteBlock(uint8 key);
	uint8 getKey(){ return m_key; }
	static const RhythmGroup getRhythmGroup(uint8 key);
	static const String getRhythmGroupString(RhythmGroup rhythmGroup);

private:
	uint8 m_key;
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(RhythmNoteBlock)
};

class RhythmSetBlock : public GrooveboxMemoryBlock
{
public:
	RhythmSetBlock();

	// key must be of 35..98 (64 keys)
	RhythmNoteBlock* getRhythmNoteBlockPtr(uint8 key);
	RhythmCommonBlock* getRhythmSetCommonBlockPtr();

private:
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(RhythmSetBlock)
};

#endif  // RHYTHMSETBLOCK_H_INCLUDED
