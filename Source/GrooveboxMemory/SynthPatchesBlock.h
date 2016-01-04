/*
  ==============================================================================

    SynthPatchesBlock.h
    Created: 15 Jan 2014 9:18:32pm
    Author:  Martin

  ==============================================================================
*/

#ifndef SYNTHPATCHESBLOCK_H_INCLUDED
#define SYNTHPATCHESBLOCK_H_INCLUDED

#include "GrooveboxMemoryBlock.h"

enum EnvelopeTypes : short { Pitch, Filter, Amp };

class PatchCommonBlock : public GrooveboxMemoryBlock
{
public:
	PatchCommonBlock(SynthParts part);

	String getPatchName() { return String((char*)m_data.getData(), 12); }

	void setPatchName(String name);

	SynthParts getPart(){ return m_part; }

private:
	SynthParts m_part;
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(PatchCommonBlock)
};

class PatchToneBlock : public GrooveboxMemoryBlock
{
public:
	PatchToneBlock(SynthParts part, Tone tone);

	SynthParts getPart(){ return m_part; }
	Tone getTone(){ return m_tone; }
private:
	Tone m_tone;
	SynthParts m_part;
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(PatchToneBlock)
};

class PatchPartBlock : public GrooveboxMemoryBlock
{
public:
	PatchPartBlock(SynthParts part);

	SynthParts getPart(){ return m_part; }

	PatchCommonBlock* getPatchCommonBlockPtr() { return dynamic_cast<PatchCommonBlock*> (getSubBlock(0)); }

	
	PatchToneBlock* getPatchToneBlockPtr(Tone tone);
private:
	SynthParts m_part;
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(PatchPartBlock)
};

class SynthPatchesBlock : public GrooveboxMemoryBlock
{
public:
	SynthPatchesBlock();

	PatchPartBlock* getPatchPartBlockPtr(SynthParts part);

private:
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(SynthPatchesBlock)
};



#endif  // SYNTHPATCHESBLOCK_H_INCLUDED
