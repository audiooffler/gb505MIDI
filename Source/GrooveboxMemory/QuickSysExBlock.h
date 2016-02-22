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
	QuickSysExPartBlock(SynthParts part) :
		GrooveboxMemoryBlock(0x00003000 | (uint8)part << 8, "Quick SysEx Part " + String(part + 1), "3-1", 57), 
		m_part(part)
	{
		m_name = "Quick SysEx Part " + String(part + 1);
		
		StringArray lfoWaveforms(StringArray::fromTokens("TRI;SIN;SAW;SQR;TRP;S&H;RND;CHAOS", ";", String::empty));
		String lfoWaveformDescription(String("Select the LFO output waveform. The sound will be modulated in the same shape as the selected waveform.\r\n") +
			"Available Settings :\r\n" +
			"- TRI(triangle) : The sound will be modulated continuously.This is a frequently - used waveform, and is suited for effects such as vibrato.\r\n" +
			"- SIN(sine wave) : The sound will be modulated smoothly.\r\n" +
			"- SAW(sawtooth wave) : When the sound reaches the upper value, it will return to the original position and begin rising again.\r\n"
			"- SQR(square wave) : The sound will be modulated as if it were being switched between two positions.\r\n"
			"- TRP(trapezoid wave) : The sound will be modulated as if it were being switched between two positions.The curve at the transitions differs from square wave.\r\n" +
			"- S&H(sample & hold) : This setting causes the sound to change unpredictably, and is suitable for creating sound effects.\r\n" +
			"- RND(random) : This setting causes the sound to change unpredictably, and is suitable for creating sound effects. The LFO rate setting will be ignored.\r\n" +
			"- CHS(chaos) : This setting causes the sound to change unpredictably without regard to frequency, and is suitable for creating sound effects. The LFO rate setting will be ignored.");
		String lfoFadeTimeDescription(String("Specifies the time over which the LFO amplitude will reach the maximum (minimum) after the Delay TIME has elapsed.\r\n") +
			"Higher settings will produce longer times.");
		StringArray coarseTuneStrings; for (int i = -48; i <= 48; i++)
		{
			if (i<0) coarseTuneStrings.add("-" + String(-i));
			else if (i == 0) coarseTuneStrings.add(String(i));
			else if (i>0) coarseTuneStrings.add("+" + String(i));
		}
		StringArray pitchEnvelopeDepthStrings; for (int i = -12; i <= 12; i++)
		{
			if (i<0) pitchEnvelopeDepthStrings.add("-" + String(-i));
			else if (i == 0) pitchEnvelopeDepthStrings.add(String(i));
			else if (i>0) pitchEnvelopeDepthStrings.add("+" + String(i));
		}
		setupParameter("LFO1 Wave Form", 0x0F, 0, 7, 0, lfoWaveforms, lfoWaveformDescription);
		setupParameter("LFO1 Fade Time", 0x14, 0, 127, 0, StringArray(), lfoFadeTimeDescription);
		setupParameter("Coarse Tune",	 0x15, 16, 112, 64, coarseTuneStrings, "Adjust the pitch of each tone in semitone steps. Higher settings will raise the pitch. Lower settings will lower the pitch.");
		setupParameter("Pitch Env Depth", 0x19, 52, 76, 64, pitchEnvelopeDepthStrings, "Here's how you can adjust the depth of the Pitch Envelope. Increasingly positive (+) settings will produce a greater width of pitch change. Negative (-) settings will invert the shape of the envelope, causing the pitch to change in the opposite direction.");
		setupParameter("Pitch Env Attack", 0x1A, 0, 127, 0, StringArray(), "Specifies the time until the next pitch level is reached.\r\nHigher settings will result in a longer time until the next pitch level is reached.");
		setupParameter("Pitch Env Decay", 0x1B, 0, 127, 0, StringArray(), "Specifies the time until the next pitch level is reached.\r\nHigher settings will result in a longer time until the next pitch level is reached.");
		setupParameter("Filter Env Sustain", 0x1C, 1, 127, 64, StringArray(), "Specifies the cutoff frequency at each level.\r\nRaising this setting will also raise the cutoff frequency.");
		setupParameter("Filter Env Release", 0x1D, 0, 127, 0, StringArray(), "Specifies the time until the next cutoff frequency is reached.\r\nHigher settings will lengthen the time until the next cutoff frequency is reached.");
		//setupParameter("Amp Env Sustain",	0x1F,0,127
		//setupParameter("Filter Type",		0x22,0,4
		//setupParameter("Tone Pan",			0x23,0,127
		//setupParameter("Tone Level",		0x24,0,127
		//setupParameter("Random Pan Switch",	0x25,0,63
		//setupParameter("Pitch Env Sustain",	0x27,1,127
		//setupParameter("Pitch Env Release",	0x28,0,127
		//setupParameter("Part Key Shift",	0x55,16,112
		//setupParameter("Part M - FX Switch",0x56,0,3
	}

	SynthParts getPart(){ return m_part; }

/*

+——————————————————————————————————————————————————————————————————————————————+
| Offset      | Size       (unused) |                                          |
|     Address | DataL     DataE     | Description           Data(Value L)      |
|—————————————+————————————————————————————————————————————————————————————————|
|          0F | 0000 aaaa 0000 0000 | LFO1 Wave Form        0 - 7    *1        | *1 : TRI, SIN, SAW, SQR, TRP, S&H, RND, CHS
|          14 | 0aaa aaaa 0000 0000 | LFO1 Fade Time        0 - 127            |
|          15 | 0aaa aaaa 0000 0000 | Coarse Tune          16 - 112 (-48 - +48)|
|          19 | 0aaa aaaa 0000 0000 | Pitch Env Depth      52 - 76 (-12 - +12) |
|          1A | 0aaa aaaa 0000 0000 | Pitch Env Attack      0 - 127            |
|          1B | 0aaa aaaa 0000 0000 | Pitch Env Decay       0 - 127            |
|          1C | 0aaa aaaa 0000 0000 | Filter Env Sustain    1 - 127 (-63 - +63)|
|          1D | 0aaa aaaa 0000 0000 | Filter Env Release    0 - 127            |
|          1F | 0aaa aaaa 0000 0000 | Amp Env Sustain       0 - 127            |
|          22 | 0000 0aaa 0000 0000 | Filter Type           0 - 4    *2        | *2 : OFF, LPF, BPF, HPF, PKG
|          23 | 0aaa aaaa 0000 0000 | Tone Pan              0 - 127 (-64 - +63)|
|          24 | 0aaa aaaa 0000 0000 | Tone Level            0 - 127            |
|          25 | 00aa aaaa 0000 0000 | Random Pan Switch     0, 63 (OFF, ON)    |
|          27 | 0aaa aaaa 0000 0000 | Pitch Env Sustain     1 - 127 (-63 - +63)|
|          28 | 0aaa aaaa 0000 0000 | Pitch Env Release     0 - 127            |
|          55 | 0aaa aaaa 0000 0000 | Part Key Shift       16 - 112 (-48 - +48)|
|          56 | 0000 00aa 0000 0000 | Part M - FX Switch    0 - 3    *3        | *3 : OFF, ON, Reserved, Reserved
+——————————————————————————————————————————————————————————————————————————————+

*/

private:
	SynthParts m_part;
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(QuickSysExPartBlock)
};

class QuickSysExRhythmBlock : public GrooveboxMemoryBlock
{
public:
	QuickSysExRhythmBlock() :
		GrooveboxMemoryBlock(0x00003900, "Quick SysEx Rhythm", "3-2", 57)
	{
		m_name = "Quick SysEx Rhythm";
		// TODO: setup Parameters
	}

/*

+——————————————————————————————————————————————————————————————————————————————+
| Offset      | Size       (RhyGrp) |                                          |
|     Address | DataL     DataE * 1 | Description           Data(Value L)      |
|—————————————+————————————————————————————————————————————————————————————————|
|          15 | 0aaa aaaa 0000 aaaa | Coarse Tune           0 - 120(-60 - +60) |
|          19 | 0aaa aaaa 0000 aaaa | Pitch Env Depth      52 - 76 (-12 - +12) |
|          1A | 0aaa aaaa 0000 aaaa | Pitch Env Attack      0 - 127            |
|          1B | 0aaa aaaa 0000 aaaa | Pitch Env Decay       0 - 127            |
|          1C | 0aaa aaaa 0000 aaaa | Filter Env Sustain    0 - 127            |
|          1D | 0aaa aaaa 0000 aaaa | Filter Env Release    0 - 127            |
|          1F | 0aaa aaaa 0000 aaaa | Amp Env Sustain       0 - 127            |
|          22 | 0000 0aaa 0000 aaaa | Filter Type           0 - 4 * 2          | * 2:OFF, LPF, BPF, HPF, PKG
|          23 | 0aaa aaaa 0000 aaaa | Tone Pan              0 - 126 (-63 - +63)|
|          24 | 0aaa aaaa 0000 aaaa | Tone Level            0 - 127            |
|          25 | 00aa aaaa 0000 aaaa | Random Pan Switch     0, 63 (OFF, ON)    |
|          27 | 0aaa aaaa 0000 aaaa | Pitch Env Sustain     0 - 127            |
|          28 | 0aaa aaaa 0000 aaaa | Pitch Env Release     0 - 127            |
|          47 | 0aaa aaaa 0000 aaaa | Resonance             0 - 127            |
|          48 | 0aaa aaaa 0000 aaaa | Amp Env Release Time  0 - 127            |
|          49 | 0aaa aaaa 0000 aaaa | Amp Env Attack Time   0 - 127            |
|          4A | 0aaa aaaa 0000 aaaa | Cutoff Frequency      0 - 127            |
|          4B | 0aaa aaaa 0000 aaaa | Amp Env Decay         0 - 127            |
|          4D | 0aaa aaaa 0000 aaaa | Fine Tune            14 - 114 (-50 - +50)|
|          51 | 0aaa aaaa 0000 aaaa | Filter Env Depth      1 - 127 (-63 - +63)|
|          52 | 0aaa aaaa 0000 aaaa | Filter Env Attack     0 - 127            |
|          53 | 0aaa aaaa 0000 aaaa | Filter Env Decay      0 - 127            |
|          55 | 0aaa aaaa 0000 0000 | Part Key Shift       16 - 112 (-48 - +48)|
|          56 | 0000 00aa 0000 0000 | Part M - FX Switch    0 - 4 * 3          | * 3:OFF, ON, <Reserved, Reserved>, RHY
+——————————————————————————————————————————————————————————————————————————————+
* 1:Use when transmitting to and from each Rhythm group in Part R:
  Rhythm group		 DataE
	   BD			   0
	   SD			   1
	   HH			   2
	   CLP			   3
	   CYM			   4
	   TOM/PERC		   5
	   HIT 			   6
	   OTHERS 		   7
	   ALL 			   9

*/

private:
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(QuickSysExRhythmBlock)
};

class QuickSysExSequencerBlock : public GrooveboxMemoryBlock
{
public:
	QuickSysExSequencerBlock() :
		GrooveboxMemoryBlock(0x00007000, "Quick SysEx Sequencer", "3-3", 0x28)
	{
		m_name = "Quick SysEx Sequencer";
		
		StringArray offOnStrings(StringArray::fromTokens("OFF ON", false));

		// the following addresses are not the real addresses but must be unique, use getParameter(AllParts part) for accessing parameter
		// in real life they all are 0x01 (MSB of virtual address) and DataL (LSB of virtual address) would be the Part 1..7,R (0..6,9)
		setupParameter("Sequencer Part 1 On", 0x10, 0, 1, 1, offOnStrings, "Mute Part 1");
		setupParameter("Sequencer Part 2 On", 0x11, 0, 1, 1, offOnStrings, "Mute Part 2");
		setupParameter("Sequencer Part 3 On", 0x12, 0, 1, 1, offOnStrings, "Mute Part 3");
		setupParameter("Sequencer Part 4 On", 0x13, 0, 1, 1, offOnStrings, "Mute Part 4");
		setupParameter("Sequencer Part 5 On", 0x14, 0, 1, 1, offOnStrings, "Mute Part 5");
		setupParameter("Sequencer Part 6 On", 0x15, 0, 1, 1, offOnStrings, "Mute Part 6");
		setupParameter("Sequencer Part 7 On", 0x16, 0, 1, 1, offOnStrings, "Mute Part 7");
		setupParameter("Sequencer Part R On", 0x19, 0, 1, 1, offOnStrings, "Mute Part R");
		
		// the following addresses are not the real addresses but must be unique, use getParameter(RhythmGroup rhyGrp) for accessing parameter
		// in real life they all are 0x02 (MSB of virtual address) and DataL (LSB of virtual address) would be the Rhythm Group BD..OTHERS (0..7) 
		setupParameter("Sequencer BD On",       0x20, 0, 1, 1, offOnStrings, "Mute BD");
		setupParameter("Sequencer SD On",       0x21, 0, 1, 1, offOnStrings, "Mute SD");
		setupParameter("Sequencer HH On",       0x22, 0, 1, 1, offOnStrings, "Mute HH");
		setupParameter("Sequencer CLP On",      0x23, 0, 1, 1, offOnStrings, "Mute CLP");
		setupParameter("Sequencer CYM On",      0x24, 0, 1, 1, offOnStrings, "Mute CYM");
		setupParameter("Sequencer TOM/PERC On", 0x25, 0, 1, 1, offOnStrings, "Mute TOM/PERC");
		setupParameter("Sequencer HIT On",      0x26, 0, 1, 1, offOnStrings, "Mute HIT");
		setupParameter("Sequencer OTHERS On",   0x27, 0, 1, 1, offOnStrings, "Mute OTHER");
	}

	// gets part mute parameter by part
	Parameter* getParameter(AllParts part)
	{
		switch (part)
		{
		case Part1: return GrooveboxMemoryBlock::getParameter(0x10);
		case Part2: return GrooveboxMemoryBlock::getParameter(0x11);
		case Part3: return GrooveboxMemoryBlock::getParameter(0x12);
		case Part4: return GrooveboxMemoryBlock::getParameter(0x13);
		case Part5: return GrooveboxMemoryBlock::getParameter(0x14);
		case Part6: return GrooveboxMemoryBlock::getParameter(0x15);
		case Part7: return GrooveboxMemoryBlock::getParameter(0x16);
		case PartR: return GrooveboxMemoryBlock::getParameter(0x19);
		default: return nullptr;
		}
	}

	// gets rhythm group parameter by rhythm group
	Parameter* getParameter(RhythmGroup rhyGrp)
	{
		switch (rhyGrp)
		{
		case BD: return GrooveboxMemoryBlock::getParameter(0x20);
		case SD: return GrooveboxMemoryBlock::getParameter(0x21);
		case HH: return GrooveboxMemoryBlock::getParameter(0x22);
		case CLP: return GrooveboxMemoryBlock::getParameter(0x23);
		case CYM: return GrooveboxMemoryBlock::getParameter(0x24);
		case TOM_PERC: return GrooveboxMemoryBlock::getParameter(0x25);
		case HIT: return GrooveboxMemoryBlock::getParameter(0x26);
		case OTHERS: return GrooveboxMemoryBlock::getParameter(0x27);
		default: return nullptr;
		}
	}

	// Create a sysex send message for setting a mute parameter with Quick SysEx. 
	SyxMsg* createMuteQuickSysExSendMsg(Parameter* param)
	{
		if (!m_parameters.contains(param)) return nullptr;
		
		uint8 deviceId((grooveboxConnector != nullptr) ? grooveboxConnector->getActiveDeviceId() : 0x10);
		if (deviceId < 0x10) deviceId = 0x10;
		
		uint8 realAddressOffset ((uint8)(param->getAddressOffset() >> 4)); // Real offset address will be 0x01 (part mute) or 0x02 (rhythm group mute)
		uint8 partOrRhyGroupNo(param->getAddressOffset() & 0xF);  // DataL will be Part no 0..6, 9 (Part 1..7,R) or Rhythm Group Number 0..7 (BD .. OTHERS)

		uint8 quickSysExAddress[2]{0x70, realAddressOffset};
		uint8 quickSysExData[2]{partOrRhyGroupNo, param->getValue()};	// DataE is the actual value of the parameter
		
		return new SyxMsg(SyxMsg::Type_DT1_Quick, deviceId, quickSysExAddress, quickSysExData, 2, SyxMsg::calcDt1Checksum(quickSysExAddress, 2, quickSysExData, 2));
	}

/*

70 00
70 01
70 03

+——————————————————————————————————————————————————————————————————————————————+
| Offset      | Size                |                                          |
|     Address | DataL     DataE     | Description           Data(Value L/E)    |
|—————————————+————————————————————————————————————————————————————————————————|
|          01 | 0000 aaaa 0000 000a | Part Mute             0-6,9 / 0,1        |	Part: Sound (MUTE, ON)
|          02 | 0000 aaaa 0000 000a | Drum Mute             0-7*1 / 0,1        | Rhy Grp: Sound (MUTE, ON)
|          03 | 0aaa aaaa 0aaa aaaa | Tempo                 7-93 / 0-127       |
+——————————————————————————————————————————————————————————————————————————————+
*   1:BD,SD,HH,CLP,CYM,TOM/PEC,HIT,OTHERS

*/

private:
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(QuickSysExSequencerBlock)
};

class QuickSysExBlock : public GrooveboxMemoryBlock
{
public:
	QuickSysExBlock() :
		GrooveboxMemoryBlock(0x00000000, "Quick SysEx Block", "3")
	{
		m_name = "Quick SysEx";
		addSubBlock(new QuickSysExPartBlock(SynthPart1));
		addSubBlock(new QuickSysExPartBlock(SynthPart2));
		addSubBlock(new QuickSysExPartBlock(SynthPart3));
		addSubBlock(new QuickSysExPartBlock(SynthPart4));
		addSubBlock(new QuickSysExPartBlock(SynthPart5));
		addSubBlock(new QuickSysExPartBlock(SynthPart6));
		addSubBlock(new QuickSysExPartBlock(SynthPart7));
		addSubBlock(new QuickSysExRhythmBlock());
		addSubBlock(new QuickSysExSequencerBlock());
	}

	QuickSysExPartBlock* getQuickSysExPartBlock(SynthParts part)
	{
		switch (part)
		{
		case SynthPart1: return dynamic_cast<QuickSysExPartBlock*>(m_subBlocks[0]);
		case SynthPart2: return dynamic_cast<QuickSysExPartBlock*>(m_subBlocks[1]);
		case SynthPart3: return dynamic_cast<QuickSysExPartBlock*>(m_subBlocks[2]);
		case SynthPart4: return dynamic_cast<QuickSysExPartBlock*>(m_subBlocks[3]);
		case SynthPart5: return dynamic_cast<QuickSysExPartBlock*>(m_subBlocks[4]);
		case SynthPart6: return dynamic_cast<QuickSysExPartBlock*>(m_subBlocks[5]);
		case SynthPart7: return dynamic_cast<QuickSysExPartBlock*>(m_subBlocks[6]);
		default: return nullptr;
		}
	}

	QuickSysExRhythmBlock* getQuickSysExRhythmBlock()
	{
		return dynamic_cast<QuickSysExRhythmBlock*>(m_subBlocks[7]);
	}

	QuickSysExSequencerBlock* getQuickSysExSequencerBlock()
	{
		return dynamic_cast<QuickSysExSequencerBlock*>(m_subBlocks[8]);
	}

	void mutePart(AllParts part, bool unmute = false, Parameter::ChangeSource source = Parameter::MidiInFromGroovebox)
	{
		getQuickSysExSequencerBlock()->getParameter(part)->setValue(unmute ? 1 : 0, source);
	}

	void muteRhytm(RhythmGroup rhyGrp, bool unmute = false, Parameter::ChangeSource source = Parameter::MidiInFromGroovebox)
	{
		getQuickSysExSequencerBlock()->getParameter(rhyGrp)->setValue(unmute ? 1 : 0, source);
	}
/*

+——————————————————————————————————————————————————————————————————————————————+
| Start       |                                                                |
|     address | Description                                                    |
|—————————————+————————————————————————————————————————————————————————————————|
|       30 00 | Quick SysEx Part1                                    3 - 1     |
|       31 00 |       : Part2                                                  |
|           : |       :                                                        |
|       36 00 |       : Part7                                                  |
|—————————————+————————————————————————————————————————————————————————————————|
|       39 00 |       : PartR                                        3 - 2     |
|—————————————+————————————————————————————————————————————————————————————————|
|       70 00 |		  : Sequencer                                    3 - 3     |
+——————————————————————————————————————————————————————————————————————————————+

*/

private:

	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(QuickSysExBlock)
};


#endif  // QUICKSYSEXBLOCK_H_INCLUDED
