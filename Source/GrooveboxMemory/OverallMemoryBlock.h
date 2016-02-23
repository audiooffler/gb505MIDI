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

	OverallMemoryBlock();

	SystemBlock* getSystemBlock();
	PartInfoBlock* getPartInfoBlock();
	SynthPatchesBlock* getSynthPatchesBlock();
	RhythmSetBlock* getRhythmSetBlock();
	PatternSetupBlock* getPatternSetupBlock();
	PatternBodyBlock* getPatternBodyBlock();

	// Load SysEx data
	bool loadFromArray(OwnedArray<SyxMsg, CriticalSection>& sysExMessageArray);
	bool loadFromGroovebox();
	bool loadBinarySysExFile(const File& file);
	bool loadHexTxtSysExFile(const File& file);
	bool loadStandardMidiFile(const File& file);
	bool saveBinarySysExFile(const File& file);
	bool saveHexTextSysExFile(const File&file);

private:
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(OverallMemoryBlock);
};

#endif  // OVERALLMEMORYBLOCK_H_INCLUDED
