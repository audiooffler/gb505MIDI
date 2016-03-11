/*
  ==============================================================================

    PatternSetupBlock.h
    Created: 15 Jan 2014 9:19:00pm
    Author:  Martin

  ==============================================================================
*/

#ifndef PATTERNSETUPBLOCK_H_INCLUDED
#define PATTERNSETUPBLOCK_H_INCLUDED

#include "GrooveboxMemoryBlock.h"
#include "PatternBodyBlock.h"
#include "PartInfoBlock.h"

class BeatSignature
{
public:
	// if signature is not allowed, the one with the nearest fraction is taken
	BeatSignature(uint8 numerator, uint8 denominator);

	uint8 getNumerator(){ return m_numerator; }
	uint8 getDenominator(){ return m_denominator; }
	uint8 getTicksPerBeat(){ return 96 / (m_denominator / 4); }

	String toString() { return String(m_numerator) + "/" + String(m_denominator); }
	float getAsFraction(){ return (float)m_numerator / (float)m_denominator; }

private:
	static const unsigned int ALLOWED_FRACTIONS_SIZE;
	static const float allowedFractions[];
	static const uint8 allowedFractionNumerators[];
	static const uint8 allowedFractionDenominators[];
	uint8 m_numerator = 4;
	uint8 m_denominator = 4;
};

class PatternSetupConfigBlock : public GrooveboxMemoryBlock
{
public:
	// eg. 138.8 converts to 3 6 3 8
	static void convertTempoBpmIntoByteValues(float bpm, uint8 &byte1, uint8 &byte2, uint8 &byte3, uint8 &byte4);
	// eg. 3 6 3 8 converts into 138.8
	static float convertTempoByteValuesIntoBPM(uint8 byte1, uint8 byte2, uint8 byte3, uint8 byte4);
	PatternSetupConfigBlock();
	// returns the pattern name
	String getPatternName();
	// name will be reduced to allowed ascii characters and max length of 15 characters
	void setPatternName(String name);
	// beat signature getters / setters
	BeatSignature getBeatSignature();
	// will be corrected to allowed signatures, e.g. 2/2 to 4/4 or rounding of non-standard fractions to allowed ones
	void setBeatSignature(uint8 numerator, uint8 denominator);
	// pattern length in num measures
	uint8 getPatternLengthInMeasures();
	unsigned long getPatternLengthInTicks();
	// will be limited to 0..32
	void setPatternLengthInMeasures(uint8 measures);
	// tempo in BPM
	float getTempoBpm();
	void setTempoBpm(float tempoInBpm);
	// mute flags part 1 - 4
	static const uint8 MUTE_FLAG_PART1 = 1;
	static const uint8 MUTE_FLAG_PART2 = 2;
	static const uint8 MUTE_FLAG_PART3 = 4;
	static const uint8 MUTE_FLAG_PART4 = 8;
	// mute flags part 5 - 7
	static const uint8 MUTE_FLAG_PART5 = 1;
	static const uint8 MUTE_FLAG_PART6 = 2;
	static const uint8 MUTE_FLAG_PART7 = 4;
	// mute flag part R
	static const uint8 MUTE_FLAG_PARTR = 2;
	// mute flag MUTE CTRL part 
	static const uint8 MUTE_FLAG_MUTE_CTRL = 4;
	// sets the mute state for a part (true) or unmutes it (false)
	void setPartMute(PatternBodyBlock::PatternPart part, bool setMute=true);
	// checks mute state for part, returns true if muted
	bool isPartMute(PatternBodyBlock::PatternPart part);
	// mute flags rhythm groups BD - CLP
	static const uint8 MUTE_FLAG_BD = 1;
	static const uint8 MUTE_FLAG_SD = 2;
	static const uint8 MUTE_FLAG_HH = 4;
	static const uint8 MUTE_FLAG_CLP = 8;
	// mute flags rhythm groups CYM - OTHERS
	static const uint8 MUTE_FLAG_CYM = 1;
	static const uint8 MUTE_FLAG_TOMPERC = 2;
	static const uint8 MUTE_FLAG_HIT = 4;
	static const uint8 MUTE_FLAG_OTHERS = 8;
	// sets the mute state for a rhythm group (true) or unmutes it (false)
	void setRyhGroupMute(PatternBodyBlock::RhythmGroup rhythmGroup, bool setMute = true);
	// checks mute state for rhythm group, returns true if muted
	bool isRyhGroupMute(PatternBodyBlock::RhythmGroup rhythmGroup);
	// 0=INT,1=EXT,2=BOTH
	uint8 getSeqOut(PatternBodyBlock::PatternPart part);
	// 0=INT,1=EXT,2=BOTH
	void setSeqOut(PatternBodyBlock::PatternPart part, uint8 seqOut);

	// for forwarding mute states to quick sysex block
	bool handleSysEx(SyxMsg* sysExMsg) override;

	MidiMessage getPartMuteSysEx(uint8 deviceId, AllParts part);
	MidiMessage getRhythmGroupMuteSysEx(uint8 deviceId, PatternBodyBlock::RhythmGroup group);
	MidiMessageSequence getInitalMuteStates(uint8 deviceId);
private:
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(PatternSetupConfigBlock)
};

class PatternSetupEffectsBlock : public GrooveboxMemoryBlock, public ChangeListener
{
public:
	static const StringArray PatternSetupEffectsBlock::mFxTypeNameStrings;
	PatternSetupEffectsBlock();
	MidiMessageSequence getM_FX_SetupMidiMessageSequence(uint8 deviceId);
	MidiMessageSequence getReverbSetupMidiMessageSequence(uint8 deviceId);
	MidiMessageSequence getDelaySetupMidiMessageSequence(uint8 deviceId);
	// for part info common (performance) changed
	bool handleSysEx(SyxMsg* sysExMsg) override;
	void setPartInfoPartBlock(PartInfoCommonBlock* partInfoCommonBlockPtr){ m_partInfoCommonBlockPtr = partInfoCommonBlockPtr; }
	void changeListenerCallback(ChangeBroadcaster *source) override;
private:
	PartInfoCommonBlock* m_partInfoCommonBlockPtr;
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(PatternSetupEffectsBlock)
};

// 8 instances
class PatternSetupPartBlock : public GrooveboxMemoryBlock, public ChangeListener
{
public:
	PatternSetupPartBlock(AllParts part);
	String getBankName(uint8 bankSelMSB00, uint8 bankSelLSB32);
	MidiMessageSequence getSinglePartSetupMidiMessageSequence();
	// for part info part (performance) changed
	void changeListenerCallback(ChangeBroadcaster *source) override;
	bool handleSysEx(SyxMsg* sysExMsg) override;
	void setPartInfoPartBlock(PartInfoPartBlock* partInfoPartBlockPtr){ m_partInfoPartBlockPtr = partInfoPartBlockPtr; }
private:
	AllParts m_part;
	PartInfoPartBlock* m_partInfoPartBlockPtr;
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(PatternSetupPartBlock)
};

// no parameters, just containing subblocks
class PatternSetupBlock : public GrooveboxMemoryBlock
{
public:
	PatternSetupBlock();
	PatternSetupConfigBlock* getPatternSetupConfigBlockPtr();
	PatternSetupEffectsBlock* getPatternSetupEffectsBlockPtr();
	PatternSetupPartBlock* getPatternSetupPartBlockPtr(AllParts part);
private:
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(PatternSetupBlock)
};



#endif  // PATTERNSETUPBLOCK_H_INCLUDED
