/*
  ==============================================================================

    OverallMemoryBlock.h
    Created: 19 Jan 2014 2:33:49pm
    Author:  Martin

  ==============================================================================
*/

#ifndef OVERALLMEMORYBLOCK_H_INCLUDED
#define OVERALLMEMORYBLOCK_H_INCLUDED

#include "GrooveboxMemoryBlock.h"
#include "SystemBlock.h"
#include "PartInfoBlock.h"
#include "SynthPatchesBlock.h"
#include "RhythmSetBlock.h"
#include "PatternSetupBlock.h"
#include "PatternBodyBlock.h"

class OverallMemoryBlock : public GrooveboxMemoryBlock
{
public:

	OverallMemoryBlock() : GrooveboxMemoryBlock(0x00000000, "Groovebox SysEx Memory")
	{
		m_name = "Overall";
		addSubBlock(new SystemBlock());
		addSubBlock(new PartInfoBlock());
		addSubBlock(new SynthPatchesBlock());
		addSubBlock(new RhythmSetBlock());
		addSubBlock(new PatternSetupBlock());
		addSubBlock(new PatternBodyBlock());
	}

	SystemBlock* getSystemBlock() { return dynamic_cast<SystemBlock*> (m_subBlocks[0]); }
	PartInfoBlock* getPartInfoBlock() { return dynamic_cast<PartInfoBlock*> (m_subBlocks[1]); }
	SynthPatchesBlock* getSynthPatchesBlock() { return dynamic_cast<SynthPatchesBlock*> (m_subBlocks[2]); }
	RhythmSetBlock* getRhythmSetBlock() { return dynamic_cast<RhythmSetBlock*> (m_subBlocks[3]); }
	PatternSetupBlock* getPatternSetupBlock() { return dynamic_cast<PatternSetupBlock*> (m_subBlocks[4]); }
	PatternBodyBlock* getPatternBodyBlock() { return dynamic_cast<PatternBodyBlock*> (m_subBlocks[5]); }

private:
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(OverallMemoryBlock);
};

#endif  // OVERALLMEMORYBLOCK_H_INCLUDED
