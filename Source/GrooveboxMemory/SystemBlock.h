/*
  ==============================================================================

    SystemBlock.h
    Created: 15 Jan 2014 9:17:35pm
    Author:  Martin

  ==============================================================================
*/

#ifndef SYSTEMBLOCK_H_INCLUDED
#define SYSTEMBLOCK_H_INCLUDED

#include "GrooveboxMemoryBlock.h"

class SystemCommonBlock : public GrooveboxMemoryBlock
{
public:
	SystemCommonBlock() : GrooveboxMemoryBlock(0x00000000, "Master Tune, Scale Tune Switch, Effect Switches, Patch Remain Switch, Receive Switches, Transmit Switches", "1-1-1", 0x62)
	{
		m_name = "System Common";

		StringArray masterTuneFreqStrings(StringArray::fromTokens("427.4 Hz;427.6 Hz;427.8 Hz;428.0 Hz;428.2 Hz;428.4 Hz;428.6 Hz;428.8 Hz;429.0 Hz;429.2 Hz;429.4 Hz;429.6 Hz;429.8 Hz;430.0 Hz;430.2 Hz;430.4 Hz;430.6 Hz;430.8 Hz;431.0 Hz;431.2 Hz;431.4 Hz;431.6 Hz;431.8 Hz;432.0 Hz;432.2 Hz;432.4 Hz;432.6 Hz;432.8 Hz;433.0 Hz;433.2 Hz;433.4 Hz;433.6 Hz;433.8 Hz;434.0 Hz;434.2 Hz;434.4 Hz;434.6 Hz;434.8 Hz;435.0 Hz;435.2 Hz;435.4 Hz;435.6 Hz;435.8 Hz;436.0 Hz;436.2 Hz;436.4 Hz;436.6 Hz;436.8 Hz;437.0 Hz;437.2 Hz;437.4 Hz;437.6 Hz;437.8 Hz;438.0 Hz;438.2 Hz;438.4 Hz;438.6 Hz;438.8 Hz;439.0 Hz;439.2 Hz;439.4 Hz;439.6 Hz;439.8 Hz;440.0 Hz;440.2 Hz;440.4 Hz;440.6 Hz;440.8 Hz;441.0 Hz;441.2 Hz;441.4 Hz;441.6 Hz;441.8 Hz;442.0 Hz;442.2 Hz;442.4 Hz;442.6 Hz;442.8 Hz;443.0 Hz;443.2 Hz;443.4 Hz;443.6 Hz;443.8 Hz;444.0 Hz;444.2 Hz;444.4 Hz;444.6 Hz;444.8 Hz;445.0 Hz;445.2 Hz;445.4 Hz;445.6 Hz;445.8 Hz;446.0 Hz;446.2 Hz;446.4 Hz;446.6 Hz;446.8 Hz;447.0 Hz;447.2 Hz;447.4 Hz;447.6 Hz;447.8 Hz;448.0 Hz;448.2 Hz;448.4 Hz;448.6 Hz;448.8 Hz;449.0 Hz;449.2 Hz;449.4 Hz;449.6 Hz;449.8 Hz;450.0 Hz;450.2 Hz;450.4 Hz;450.6 Hz;450.8 Hz;451.0 Hz;451.2 Hz;451.4 Hz;451.6 Hz;451.8 Hz;452.0 Hz;452.2 Hz;452.4 Hz;452.6 Hz", ";", String::empty));
		setupParameter("Master Tune", 0x06, 0, 126, 63, masterTuneFreqStrings, "Frequency of the A4 note from 427.4 Hz to 452.6 Hz in 0.20Hz steps.");

		StringArray switchOnOffStrings(StringArray::fromTokens("OFF ON", false));
		setupParameter("Scale Tune Switch", 0x07, 0, 1, 0, switchOnOffStrings, "Activates/deactivates the Scale Tune function.");
		setupParameter("M-FX Switch",       0x08, 0, 1, 1, switchOnOffStrings, "Multi-Effect Master Switch");
		setupParameter("Delay Switch",      0x09, 0, 1, 1, switchOnOffStrings, "Delay Master Switch");
		setupParameter("Reverb Switch",     0x0A, 0, 1, 1, switchOnOffStrings, "Reverb Master Switch");
		setupParameter("Patch Remain",      0x0B, 0, 1, 1, switchOnOffStrings, "Specifies whether the sound that was being heard at the moment you switched patches or rhythm sets will continue sounding, or whether it will stop.");

		setupParameter("Receive Program Change Switch", 0x14, 0, 1, 1, switchOnOffStrings, "Specifies whether or not each part will receive program changes");
		setupParameter("Receive Bank Select Switch",    0x15, 0, 1, 1, switchOnOffStrings, "Specifies whether or not each part will receive bank select messages.");

		setupParameter("Transmit Program Change Switch", 0x28, 0, 1, 1, switchOnOffStrings, "Specifies whether or not program changes will be transmitted from MIDI OUT when the patch of each part is changed.");
		setupParameter("Transmit Bank Select Switch",    0x29, 0, 1, 1, switchOnOffStrings, "Specifies whether or not bank select messages will be transmitted from MIDI OUT when the patch of each part is changed.");
	}

private:
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(SystemCommonBlock)
};

// 7 intances
class ScaleTuneBlock : public GrooveboxMemoryBlock
{
public:
	ScaleTuneBlock(SynthParts part) :
		GrooveboxMemoryBlock(0x1000 | (uint8)part << 8, "Scale Tune for each note in an octave stating at note C", "1-1-2", 0x0C),
		m_part(part)
	{
		m_name = "Part " + String((uint8)m_part + 1) + " Scale Tune";
		StringArray fineTuningCentStrings;
		for (int i = -64; i <= 63; i++)
		{
			fineTuningCentStrings.add(String(i > 0 ? "+" : "") + String(i) + " cent");
		}
		setupParameter("Scale Tune for C",  0x00, 0, 127, 64, fineTuningCentStrings);
		setupParameter("Scale Tune for C#", 0x01, 0, 127, 64, fineTuningCentStrings);
		setupParameter("Scale Tune for D",  0x02, 0, 127, 64, fineTuningCentStrings);
		setupParameter("Scale Tune for D#", 0x03, 0, 127, 64, fineTuningCentStrings);
		setupParameter("Scale Tune for E",  0x04, 0, 127, 64, fineTuningCentStrings);
		setupParameter("Scale Tune for F",  0x05, 0, 127, 64, fineTuningCentStrings);
		setupParameter("Scale Tune for F#", 0x06, 0, 127, 64, fineTuningCentStrings);
		setupParameter("Scale Tune for G",  0x07, 0, 127, 64, fineTuningCentStrings);
		setupParameter("Scale Tune for G#", 0x08, 0, 127, 64, fineTuningCentStrings);
		setupParameter("Scale Tune for A",  0x09, 0, 127, 64, fineTuningCentStrings);
		setupParameter("Scale Tune for A#", 0x0A, 0, 127, 64, fineTuningCentStrings);
		setupParameter("Scale Tune for B",  0x0B, 0, 127, 64, fineTuningCentStrings);
	}

	SynthParts getPart(){ return m_part; }

private:
	SynthParts m_part;
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ScaleTuneBlock)
};

class SystemBlock : public GrooveboxMemoryBlock
{
public:
	SystemBlock() :
		GrooveboxMemoryBlock(0x00000000, "System Common Block and 7 Part Scale Tune Blocks", "1-1")
	{
		m_name = "System";
		addSubBlock(new SystemCommonBlock());
		addSubBlock(new ScaleTuneBlock(SynthPart1));
		addSubBlock(new ScaleTuneBlock(SynthPart2));
		addSubBlock(new ScaleTuneBlock(SynthPart3));
		addSubBlock(new ScaleTuneBlock(SynthPart4));
		addSubBlock(new ScaleTuneBlock(SynthPart5));
		addSubBlock(new ScaleTuneBlock(SynthPart6));
		addSubBlock(new ScaleTuneBlock(SynthPart7));
	}


	SystemCommonBlock* getSystemCommonBlockPtr()
	{
		return dynamic_cast<SystemCommonBlock*>(getSubBlock(0));
	}

	ScaleTuneBlock* getScaleTuneBlockPtr(SynthParts part)
	{
		switch (part)
		{
		case SynthPart1: return dynamic_cast<ScaleTuneBlock*>(m_subBlocks[1]);
		case SynthPart2: return dynamic_cast<ScaleTuneBlock*>(m_subBlocks[2]);
		case SynthPart3: return dynamic_cast<ScaleTuneBlock*>(m_subBlocks[3]);
		case SynthPart4: return dynamic_cast<ScaleTuneBlock*>(m_subBlocks[4]);
		case SynthPart5: return dynamic_cast<ScaleTuneBlock*>(m_subBlocks[5]);
		case SynthPart6: return dynamic_cast<ScaleTuneBlock*>(m_subBlocks[6]);
		case SynthPart7: return dynamic_cast<ScaleTuneBlock*>(m_subBlocks[7]);
		default: return nullptr;
		}
	}

private:

	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(SystemBlock)
};

#endif  // SYSTEMBLOCK_H_INCLUDED
