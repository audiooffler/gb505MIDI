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
		GrooveboxMemoryBlock(0x00003000 | (uint8)part << 8, "Quick SysEx Part " + String(part + 1), "3-1", 0x57), 
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
		StringArray filterTypes(StringArray::fromTokens("OFF LPF BPF HPF PKG", false));
		StringArray panPosStrings;
		for (int i = -64; i <= 63; i++)
		{
			if (i<0) panPosStrings.add("L" + String(-i));
			else if (i == 0) panPosStrings.add(String(i));
			else if (i>0) panPosStrings.add("R" + String(i));
		}
		StringArray randomPanSwitchStrings;
		for (int i = 0; i <= 127; i++)
		{
			if (i<63) randomPanSwitchStrings.add("OFF");
			else randomPanSwitchStrings.add("ON");
		}
		StringArray modulationDepthStrings; for (int i = -63; i <= 63; i++)
		{
			if (i<0) modulationDepthStrings.add("-" + String(-i));
			else if (i == 0) modulationDepthStrings.add(String(i));
			else if (i>0) modulationDepthStrings.add("+" + String(i));
		}
		StringArray keyShiftStrings; for (int i = -48; i <= 48; i++)
		{
			if (i <= 0) keyShiftStrings.add(String(i));
			else keyShiftStrings.add("+" + String(i));
		}


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
		+——————————————————————————————————————————————————————————————————————————————+				*/
		setupParameter("LFO1 Wave Form", 0x0F, 0, 7, 0, lfoWaveforms, lfoWaveformDescription);
		setupParameter("LFO1 Fade Time", 0x14, 0, 127, 0, StringArray(), lfoFadeTimeDescription);
		setupParameter("Coarse Tune",	 0x15, 16, 112, 64, coarseTuneStrings, "Adjust the pitch of each tone in semitone steps. Higher settings will raise the pitch. Lower settings will lower the pitch.");
		setupParameter("Pitch Env Depth", 0x19, 52, 76, 64, pitchEnvelopeDepthStrings, "Here's how you can adjust the depth of the Pitch Envelope. Increasingly positive (+) settings will produce a greater width of pitch change. Negative (-) settings will invert the shape of the envelope, causing the pitch to change in the opposite direction.");
		setupParameter("Pitch Env Attack", 0x1A, 0, 127, 0, StringArray(), "Specifies the time until the next pitch level is reached.\r\nHigher settings will result in a longer time until the next pitch level is reached.");
		setupParameter("Pitch Env Decay", 0x1B, 0, 127, 0, StringArray(), "Specifies the time until the next pitch level is reached.\r\nHigher settings will result in a longer time until the next pitch level is reached.");
		setupParameter("Filter Env Sustain", 0x1C, 1, 127, 64, StringArray(), "Specifies the cutoff frequency at each level.\r\nRaising this setting will also raise the cutoff frequency.");
		setupParameter("Filter Env Release", 0x1D, 0, 127, 0, StringArray(), "Specifies the time until the next cutoff frequency is reached.\r\nHigher settings will lengthen the time until the next cutoff frequency is reached.");
		setupParameter("Amp Env Sustain", 0x1F, 0, 127, 0, StringArray(), "Specifies the volume at each point. Higher settings will also raise the volume.");
		setupParameter("Filter Type", 0x22, 0, 4, 0, filterTypes, "- OFF: The filter will not be applied.\r\n"
			"- LPF (Low Pass Filter): This type of filter is most commonly used and allows audio signals with frequencies lower than the cutoff frequency to pass through. It is used to make the sound more mellow.\r\n"
			"- BPF (Band Pass Filter): This filter cuts off all audio signals except for those with frequencies around the cutoff frequency.\r\n"
			"- HPF (High Pass Filter): This filter allows audio signals with frequencies exceeding the cutoff frequency to pass. It is effectively used to make sounds brighter and sharper.\r\n"
			"- PKG (Peaking Filter): This filter enhances audio signals with frequencies around the cutoff frequency. It will emphasize the midrange, and is useful for creating a distinctive sound.\r\n"
			"By selecting the Peaking Filter as the Filter Type and using the LFO to modulate the cutoff frequency, you can create a \"wah\" effect.");
		setupParameter("Tone Pan", 0x23, 0, 127, 64, panPosStrings, "This parameter sets the stereo location for each tone.\r\nThe pan of the overall patch can be modified and set for each pattern by the Setup parameter Part Pan. The Tone Pan value will be added to this setting.");
		setupParameter("Tone Level", 0x24, 0, 127, 0, StringArray(), "This setting adjusts the volume of each tone. This is used mainly to adjust the volume balance between tones.");
		setupParameter("Random Pan Switch", 0x25, 0, 127, 0, randomPanSwitchStrings, "This setting causes the stereo location to change randomly each time a note is played.\r\nThe Tone Pan setting will be ignored by Tones for which the Random Pan Switch is turned on.");	// TODO: make sure if slider only uses 0 and 63 correctly (set interval, max, after setting parameter!)
		setupParameter("Pitch Env Sustain", 0x27, 1, 127, 63, modulationDepthStrings, "Specifies the pitch difference relative to the normal pitch (as specified by Coarse Tune and Fine Tune).\r\nPositive (+) settings will raise the pitch above the normal pitch. Negative (-) settings will make the pitch lower than the normal pitch.");
		setupParameter("Pitch Env Release", 0x28, 0, 127, 0, StringArray(), "Specifies the time until the next pitch level is reached.\r\nHigher settings will result in a longer time until the next pitch level is reached.");		
		setupParameter("Part Key Shift", 0x55, 16, 112, 64, keyShiftStrings);
		setupParameter("Part M-FX Switch", 0x56, 0, 3, 0, StringArray::fromTokens("OFF,ON, , ",", "));
	}

	SynthParts getPart(){ return m_part; }

private:
	SynthParts m_part;
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(QuickSysExPartBlock)
};

class QuickSysExRhythmBlock : public GrooveboxMemoryBlock
{
public:
	QuickSysExRhythmBlock() :
		GrooveboxMemoryBlock(0x00003900, "Quick SysEx Rhythm", "3-2", 0x57)
	{
		m_name = "Quick SysEx Rhythm";

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
		StringArray coarseTuneStrings; for (int i = -60; i <= 60; i++)
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
		StringArray filterTypes(StringArray::fromTokens("OFF LPF BPF HPF PKG", false));
		StringArray panPosStrings;
		for (int i = -63; i <= 63; i++)
		{
			if (i<0) panPosStrings.add("L" + String(-i));
			else if (i == 0) panPosStrings.add(String(i));
			else if (i>0) panPosStrings.add("R" + String(i));
		}
		StringArray randomPanSwitchStrings;
		for (int i = 0; i <= 127; i++)
		{
			if (i<63) randomPanSwitchStrings.add("OFF");
			else randomPanSwitchStrings.add("ON");
		}
		StringArray modulationDepthStrings; for (int i = -63; i <= 63; i++)
		{
			if (i<0) modulationDepthStrings.add("-" + String(-i));
			else if (i == 0) modulationDepthStrings.add(String(i));
			else if (i>0) modulationDepthStrings.add("+" + String(i));
		}
		StringArray keyShiftStrings; for (int i = -48; i <= 48; i++)
		{
			if (i <= 0) keyShiftStrings.add(String(i));
			else keyShiftStrings.add("+" + String(i));
		}
		StringArray fineTuneStrings; for (int i = -50; i <= 50; i++)
		{
			if (i<0) fineTuneStrings.add("-" + String(-i));
			else if (i == 0) fineTuneStrings.add(String(i));
			else if (i>0) fineTuneStrings.add("+" + String(i));
		}
		/*
				*1:Use when transmitting to and from each Rhythm group in Part R:
		Rhythm group |	DataE	  0000 aaaa
		-------------|---------------------
		BD			 |	  0		  0000 0000
		SD			 |	  1		  0000 0001
		HH			 |	  2		  0000 0010
		CLP			 |	  3		  0000 0011
		CYM		 	 |	  4		  0000 0100
		TOM/PERC	 |	  5		  0000 0101
		HIT 		 |	  6		  0000 0110
		OTHERS 		 |	  7		  0000 0111
		ALL 		 |	  9		  0000 1001
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
		|(Like Syn)55 | 0aaa aaaa 0000 0000 | Part Key Shift       16 - 112 (-48 - +48)|
		|(Like Syn)56 | 0000 00aa 0000 0000 | Part M - FX Switch    0 - 4 * 3          | * 3:OFF, ON, <Reserved, Reserved>, RHY
		+——————————————————————————————————————————————————————————————————————————————+			*/
		setupParameter("Coarse Tune", 0x15, 0, 120, 60, coarseTuneStrings, "Adjust the pitch of each tone in semitone steps. Higher settings will raise the pitch. Lower settings will lower the pitch.");
		setupParameter("Pitch Env Depth", 0x19, 52, 76, 64, pitchEnvelopeDepthStrings, "Here's how you can adjust the depth of the Pitch Envelope. Increasingly positive (+) settings will produce a greater width of pitch change. Negative (-) settings will invert the shape of the envelope, causing the pitch to change in the opposite direction.");
		setupParameter("Pitch Env Attack", 0x1A, 0, 127, 0, StringArray(), "Specifies the time until the next pitch level is reached.\r\nHigher settings will result in a longer time until the next pitch level is reached.");
		setupParameter("Pitch Env Decay", 0x1B, 0, 127, 0, StringArray(), "Specifies the time until the next pitch level is reached.\r\nHigher settings will result in a longer time until the next pitch level is reached.");
		setupParameter("Filter Env Sustain", 0x1C, 1, 127, 64, StringArray(), "Specifies the cutoff frequency at each level.\r\nRaising this setting will also raise the cutoff frequency.");
		setupParameter("Filter Env Release", 0x1D, 0, 127, 0, StringArray(), "Specifies the time until the next cutoff frequency is reached.\r\nHigher settings will lengthen the time until the next cutoff frequency is reached.");
		setupParameter("Amp Env Sustain", 0x1F, 0, 127, 0, StringArray(), "Specifies the volume at each point. Higher settings will also raise the volume.");
		setupParameter("Filter Type", 0x22, 0, 4, 0, filterTypes, "- OFF: The filter will not be applied.\r\n"
			"- LPF (Low Pass Filter): This type of filter is most commonly used and allows audio signals with frequencies lower than the cutoff frequency to pass through. It is used to make the sound more mellow.\r\n"
			"- BPF (Band Pass Filter): This filter cuts off all audio signals except for those with frequencies around the cutoff frequency.\r\n"
			"- HPF (High Pass Filter): This filter allows audio signals with frequencies exceeding the cutoff frequency to pass. It is effectively used to make sounds brighter and sharper.\r\n"
			"- PKG (Peaking Filter): This filter enhances audio signals with frequencies around the cutoff frequency. It will emphasize the midrange, and is useful for creating a distinctive sound.");
		setupParameter("Tone Pan", 0x23, 0, 126, 63, panPosStrings, "This parameter sets the stereo location for each tone.\r\nThe pan of the overall patch can be modified and set for each pattern by the Setup parameter Part Pan. The Tone Pan value will be added to this setting.");
		setupParameter("Tone Level", 0x24, 0, 127, 0, StringArray(), "This setting adjusts the volume of each tone. This is used mainly to adjust the volume balance between tones.");
		setupParameter("Random Pan Switch", 0x25, 0, 127, 0, randomPanSwitchStrings, "This setting causes the stereo location to change randomly each time a note is played.\r\nThe Tone Pan setting will be ignored by Tones for which the Random Pan Switch is turned on.");	// TODO: make sure if slider only uses 0 and 63 correctly (set interval, max, after setting parameter!)
		setupParameter("Pitch Env Sustain", 0x27, 1, 127, 63, modulationDepthStrings, "Specifies the pitch difference relative to the normal pitch (as specified by Coarse Tune and Fine Tune).\r\nPositive (+) settings will raise the pitch above the normal pitch. Negative (-) settings will make the pitch lower than the normal pitch.");
		setupParameter("Pitch Env Release", 0x28, 0, 127, 0, StringArray(), "Specifies the time until the next pitch level is reached.\r\nHigher settings will result in a longer time until the next pitch level is reached.");
		setupParameter("Resonance", 0x47, 0, 127, 0, StringArray(), "Adding a Distinctive Character to the Sound (Resonance). This setting emphasizes the overtones in the region of the cutoff frequency, adding character to the sound.\r\n"
			"As this value is increased, the sound will have more character. As this value is decreased, the sound will be more natural.\r\n"
			"In order to prevent the resonance from being increased excessively, factory settings have been made so that the value will not rise beyond \"110\" even if the [RESONANCE] knob is rotated all the way to the right. This is called the Resonance Limiter. You are free to adjust this upper limit.\r\n"
			"If you have increased the Resonance Limiter setting, be careful not to raise the resonance excessively. Excessively high values may cause sounds to be distorted or the volume level to become unexpectedly high. Some settings may damage your hearing, or your speakers. Please use caution.");
		setupParameter("Amp Env Release Time", 0x48, 0, 127, 0, StringArray(), "Specifies the time until the next level point is reached.\r\nHigher settings will lengthen the time until the next level point is reached.");
		setupParameter("Amp Env Attack Time", 0x49, 0, 127, 0, StringArray(), "Specifies the time until the next level point is reached.\r\nHigher settings will lengthen the time until the next level point is reached.");
		setupParameter("Cutoff Frequency", 0x4A, 0, 127, 0, StringArray(), "Specifies the frequency at which the filter will begin to affect the frequency components of the waveform (the Cutoff Frequency). By changing the cutoff frequency, you can control the brightness of the sound. The effect will depend on the Filter Type.\r\n"
			"- LPF (Low Pass Filter): Increasing the value will brighten the sound, making it more similar to the original waveform, approaching the  original waveform. Lower settings will cut more of the high frequency overtones, making the sound darker. For some waveforms, you may not be able to hear any sound if you lower the value too far.\r\n"
			"- BPF (Band Pass Filter): Higher settings will raise the frequency area that is heard. Lower settings will cause only a progressively lower frequency area to be heard.\r\n"
			"- HPF (High Pass Filter): As this value is increased, the low frequency range will be cut more greatly, making the sound sharper. As this value is decreased, the original sound of the waveform will be heard. For some waveforms, you may hear no sound if this value is raised excessively.\r\n"
			"- PKG (Peaking Filter): As this value is increased, the frequency area that is emphasized will rise. As this value is decreased, the frequency area that is emphasized will fall.");
		setupParameter("Amp Env Decay", 0x4B, 0, 127, 0, StringArray(), "Specifies the time until the next level point is reached.\r\nHigher settings will lengthen the time until the next level point is reached.");
		setupParameter("Fine Tune", 0x4D, 14, 114, 64, fineTuneStrings, "You can adjust the pitch of each tone in 1-cent steps (1/000th of a semitone).\r\nThe greater the value, the higher the pitch, and the smaller value, the lower the pitch.");
		setupParameter("Filter Env Depth", 0x51, 1, 127, 63, modulationDepthStrings, "This setting adjusts the depth of the filter envelope. As the value is increased in the positive(+) direction, the amount of tonal change will increase. With negative(-) settings, the shape of the envelope will be inverted, and the tone will change in the opposite direction.\r\nWhen setting Envelope Depth to a positive(+) value, the effect of the filter envelope will be easier to hear if you set a lower cutoff frequency.");
		setupParameter("Filter Env Attack", 0x52, 0, 127, 0, StringArray(), "Specifies the time until the next cutoff frequency is reached.\r\nHigher settings will lengthen the time until the next cutoff frequency is reached.");
		setupParameter("Filter Env Decay", 0x53, 0, 127, 0, StringArray(), "Specifies the time until the next cutoff frequency is reached.\r\nHigher settings will lengthen the time until the next cutoff frequency is reached.");
		setupParameter("Part Key Shift", 0x55, 16, 112, 64, keyShiftStrings);
		setupParameter("Part M-FX Switch", 0x56, 0, 3, 0, StringArray::fromTokens("OFF,ON, , ", ", "));
	}

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
