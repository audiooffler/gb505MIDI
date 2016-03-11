/*
  ==============================================================================

    QuickSysExBlock.h
    Created: 22 Feb 2014 2:34:36pm
    Author:  Martin

  ==============================================================================
*/

#ifndef QUICKSYSEXBLOCK_H_INCLUDED
#define QUICKSYSEXBLOCK_H_INCLUDED

#include "GrooveboxMemoryBlock.h"

class QuickSysExPartBlock : public GrooveboxMemoryBlock
{
public:
	QuickSysExPartBlock(SynthParts part);
	SynthParts getPart(){ return m_part; }

private:
	SynthParts m_part;
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(QuickSysExPartBlock)
};

class QuickSysExRhythmBlock : public GrooveboxMemoryBlock
{
public:
	QuickSysExRhythmBlock(RhythmGroup rhyGrp);

private:
	RhythmGroup m_rhyGrp;
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(QuickSysExRhythmBlock)
};

class QuickSysExSequencerBlock : public GrooveboxMemoryBlock
{
public:
	QuickSysExSequencerBlock();

	// gets part mute parameter by part
	Parameter* getParameter(AllParts part);

	// gets rhythm group parameter by rhythm group
	Parameter* getParameter(RhythmGroup rhyGrp);

	// Create a sysex send message for setting a mute parameter with Quick SysEx. 
	SyxMsg* createMuteQuickSysExSendMsg(Parameter* param);

private:
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(QuickSysExSequencerBlock)
};

class QuickSysExBlock : public GrooveboxMemoryBlock
{
public:
	QuickSysExBlock();

	bool handleSysEx(SyxMsg* msg) override;

	QuickSysExPartBlock* getQuickSysExPartBlock(SynthParts part);

	QuickSysExRhythmBlock* getQuickSysExRhythmBlock(RhythmGroup rhyGroup);

	QuickSysExSequencerBlock* getQuickSysExSequencerBlock();

	void mutePart(AllParts part, bool mute = false, Parameter::ChangeSource source = Parameter::MidiInFromGroovebox);

	void muteRhytm(RhythmGroup rhyGrp, bool mute = false, Parameter::ChangeSource source = Parameter::MidiInFromGroovebox);

private:

	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(QuickSysExBlock)
};


#endif  // QUICKSYSEXBLOCK_H_INCLUDED
