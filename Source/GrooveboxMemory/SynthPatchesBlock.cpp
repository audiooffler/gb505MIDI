/*
  ==============================================================================

    SynthPatchesBlock.cpp
    Created: 10 Nov 2014 7:57:14pm
    Author:  Martin

  ==============================================================================
*/

#include "SynthPatchesBlock.h"

// ----------------------------------------------------------------------------

PatchCommonBlock::PatchCommonBlock(SynthParts part) :
	GrooveboxMemoryBlock(0x02000000 | (uint32)part << 16, "Patch Common of Part " + String((uint8)part + 1), "1-3-1", 0x4A),
	m_part(part)
{
	m_name = "Patch Common";
	/*  3:*/StringArray boosterGain(StringArray::fromTokens("0dB; +6dB; +12dB; +18dB", ";", String()));
	StringArray switchOnOffStrings(StringArray::fromTokens("OFF ON", false));
	StringArray asciiCharacters;
	asciiCharacters.add(" ");
	asciiCharacters.addTokens("! \" # $ % & ' ( ) * + , - . / 0 1 2 3 4 5 6 7 8 9 : ; < = > ? @ A B C D E F G H I J K L M N O P Q R S T U V W X Y Z [ \\ ] ^ _ ` a b c d e f g h i j k l m n o p q r s t u v w x y z { | }", false);

	// add, set (if addressOffset already used) or delete (if addressOffset already used and name is empty)
	// void setupParameter(String name, uint16 addressOffset, uint8 min, uint8 max, uint8 default = 0, StringArray displayedValues = StringArray(), String description = String(), uint8 cc = 102, bool ccIsMode2Only = false);
	setupParameter("Patch Name  1", 0x00, 32, 125, 'L', asciiCharacters, "Name assigned to the patch.");
	setupParameter("Patch Name  2", 0x01, 32, 125, 'e', asciiCharacters, "Name assigned to the patch.");
	setupParameter("Patch Name  3", 0x02, 32, 125, 'a', asciiCharacters, "Name assigned to the patch.");
	setupParameter("Patch Name  4", 0x03, 32, 125, 'd', asciiCharacters, "Name assigned to the patch.");
	setupParameter("Patch Name  5", 0x04, 32, 125, 32, asciiCharacters, "Name assigned to the patch.");
	setupParameter("Patch Name  6", 0x05, 32, 125, 'T', asciiCharacters, "Name assigned to the patch.");
	setupParameter("Patch Name  7", 0x06, 32, 125, 'B', asciiCharacters, "Name assigned to the patch.");
	setupParameter("Patch Name  8", 0x07, 32, 125, 32, asciiCharacters, "Name assigned to the patch.");
	setupParameter("Patch Name  9", 0x08, 32, 125, '1', asciiCharacters, "Name assigned to the patch.");
	setupParameter("Patch Name 10", 0x09, 32, 125, 32, asciiCharacters, "Name assigned to the patch.");
	setupParameter("Patch Name 11", 0x0A, 32, 125, 32, asciiCharacters, "Name assigned to the patch.");
	setupParameter("Patch Name 12", 0x0B, 32, 125, 32, asciiCharacters, "Name assigned to the patch.");

	setupParameter("Reserved", 0x0C, 0, 39, 0x00, StringArray(), "JV-2080 Patch Common EFX Type");
	setupParameter("Reserved", 0x0D, 0, 127, 0x00, StringArray(), "JV-2080 Patch Common EFX Parameter 1");
	setupParameter("Reserved", 0x0E, 0, 127, 0x0F, StringArray(), "JV-2080 Patch Common EFX Parameter 2");
	setupParameter("Reserved", 0x0F, 0, 127, 0x00, StringArray(), "JV-2080 Patch Common EFX Parameter 3");
	setupParameter("Reserved", 0x10, 0, 127, 0x0F, StringArray(), "JV-2080 Patch Common EFX Parameter 4");
	setupParameter("Reserved", 0x11, 0, 127, 0x07, StringArray(), "JV-2080 Patch Common EFX Parameter 5");
	setupParameter("Reserved", 0x12, 0, 127, 0x01, StringArray(), "JV-2080 Patch Common EFX Parameter 6");
	setupParameter("Reserved", 0x13, 0, 127, 0x0F, StringArray(), "JV-2080 Patch Common EFX Parameter 7");
	setupParameter("Reserved", 0x14, 0, 127, 0x07, StringArray(), "JV-2080 Patch Common EFX Parameter 8");
	setupParameter("Reserved", 0x15, 0, 127, 0x01, StringArray(), "JV-2080 Patch Common EFX Parameter 9");
	setupParameter("Reserved", 0x16, 0, 127, 0x0F, StringArray(), "JV-2080 Patch Common EFX Parameter 10");
	setupParameter("Reserved", 0x17, 0, 127, 0x7F, StringArray(), "JV-2080 Patch Common EFX Parameter 11");
	setupParameter("Reserved", 0x18, 0, 127, 0x00, StringArray(), "JV-2080 Patch Common EFX Parameter 12");
	setupParameter("Reserved", 0x19, 0, 2, 0x00, StringArray::fromTokens("MIX DIR1 DIR2",false), "JV-2080 Patch Common EFX Output Assign");
	setupParameter("Reserved", 0x1A, 0, 127, 0x7F, StringArray(), "JV-2080 Patch Common EFX Mix Out Send Level");
	setupParameter("Reserved", 0x1B, 0, 127, 0x00, StringArray(), "JV-2080 Patch Common EFX Chorus Send Level");
	setupParameter("Reserved", 0x1C, 0, 127, 0x00, StringArray(), "JV-2080 Patch Common EFX Reverb Send Level");
	setupParameter("Reserved", 0x1D, 0, 10, 0x00, StringArray(), "JV-2080 Patch Common EFX Control Source 1");
	setupParameter("Reserved", 0x1E, 0, 126, 0x3F, StringArray(), "JV-2080 Patch Common EFX Control Depth 1");
	setupParameter("Reserved", 0x1F, 0, 10, 0x00, StringArray(), "JV-2080 Patch Common EFX Control Source 2");
	setupParameter("Reserved", 0x20, 0, 126, 0x3F, StringArray(), "JV-2080 Patch Common EFX Control Depth 2");
	setupParameter("Reserved", 0x21, 0, 127, 0x7F, StringArray(), "JV-2080 Patch Common Chorus Level");
	setupParameter("Reserved", 0x22, 0, 127, 0x01, StringArray(), "JV-2080 Patch Common Chorus Rate");
	setupParameter("Reserved", 0x23, 0, 127, 0x11, StringArray(), "JV-2080 Patch Common Chorus Depth");
	setupParameter("Reserved", 0x24, 0, 127, 0x00, StringArray(), "JV-2080 Patch Common Chorus Pre-Delay");
	setupParameter("Reserved", 0x25, 0, 127, 0x00, StringArray(), "JV-2080 Patch Common Chorus Feedback");
	setupParameter("Reserved", 0x26, 0, 2, 0x00, StringArray(), "JV-2080 Patch Common Chorus Output");
	setupParameter("Reserved", 0x27, 0, 7, 0x02, StringArray(), "JV-2080 Patch Common Reverb Type");
	setupParameter("Reserved", 0x28, 0, 127, 0x7F, StringArray(), "JV-2080 Patch Common Reverb Level");
	setupParameter("Reserved", 0x29, 0, 127, 0x5A, StringArray(), "JV-2080 Patch Common Reverb Time");
	setupParameter("Reserved", 0x2A, 0, 17, 0x0D, StringArray(), "JV-2080 Patch Common Reverb HF Damp");
	setupParameter("Reserved", 0x2B, 0, 127, 0x00, StringArray(), "JV-2080 Patch Common Delay Feedback");

	setupParameter("Reserved", 0x2C, 20, 250, 120, StringArray(), "JV-2080 Patch Common Patch Tempo");// a 2 byte parameter, will automatically handled as ms / ls nibble, told by the maximum above 127
	/*setupParameter("Reserved MS Nibble", 0x2C, 0, 0xF);
	setupParameter("Reserved LS Nibble", 0x2D, 0, 0xF);*/
	setupParameter("Reserved", 0x2E, 0, 127, 0x7F, StringArray(), "JV-2080 Patch Common Patch Level");
	setupParameter("Reserved", 0x2F, 0, 127, 0x40, StringArray(), "JV-2080 Patch Common Patch Pan");
	setupParameter("Reserved", 0x30, 0, 127, 0x00, StringArray(), "JV-2080 Patch Common Analog Feel");

	setupParameter("Bend Range Up", 0x31, 0, 12, 12, StringArray::fromTokens("0 +1 +2 +3 +4 +5 +6 +7 +8 +9 +10 +11 +12", false), "Amount of pitch change(in semitone units) that will occur when the pitch bend lever of an external MIDI device is raising.");
	setupParameter("Bend Range Down", 0x32, 0, 48, 12, StringArray::fromTokens("0 -1 -2 -3 -4 -5 -6 -7 -8 -9 -10 -11 -12 -13 -14 -15 -16 -17 -18 -19 -20 -21 -22 -23 -24 -25 -26 -27 -28 -29 -30 -31 -32 -33 -34 -35 -36 -37 -38 -39 -40 -41 -42 -43 -44 -45 -46 -47 -48", false), "Amount of pitch change (in semitone units) that will occur when the pitch bend lever of an external MIDI device is lowering.");
	setupParameter("Solo Switch", 0x33, 0, 1, 0, switchOnOffStrings, "Solo playback function. Synthesized reed and bass sounds are effectively set up by turning the SOLO switch on.");
	setupParameter("Solo Legato Switch", 0x34, 0, 1, 0, switchOnOffStrings, "When Solo Legato is on, playing a note while the previous note is still held will cause only the pitch to change, without generating a new attack.This creates a smooth transition between notes, which is effective when you wish to simulate the hammering-on and pulling-off techniques used by a guitarist.");
	setupParameter("Portamento Switch", 0x35, 0, 1, 0, switchOnOffStrings, "Smoothens transitions from the pitch of one key to another. Applied when the Solo switch is turned on, this function achieves an effect like a violin played using the slide technique.");
	setupParameter("Portamento Mode", 0x36, 0, 1, 0, StringArray::fromTokens("NORMAL LEGATO", false), "In LEGATO Mode, Portamento will only be applied for notes played legato (i.e., notes played before the previous note is released).");
	setupParameter("Portamento Type", 0x37, 0, 1, 0, StringArray::fromTokens("RATE TIME", false), "RATE: The time over which the pitch change occurs will depend on the distance between the two pitches.\r\nTIME: The pitch change will occur over a fixed time, regardless of the distance between pitches.");
	setupParameter("Portamento Start", 0x38, 0, 1, 0, StringArray::fromTokens("PITCH NOTE", false), "PITCH: When another key is pressed while the pitch is changing, the new portamento movement will begin from the pitch at that moment.\r\nNOTE: The new portamento movement will begin from the pitch toward which it had been moving.");
	setupParameter("Portamento Time", 0x39, 0, 127, 0, StringArray(), "Time (duration) over which the pitch will change when portamento is used.");

	setupParameter("Reserved", 0x3A, 0, 15, 0x09, StringArray(), "JV-2080 Patch Common Patch Control Source 2");
	setupParameter("Reserved", 0x3B, 0, 15, 0x0A, StringArray(), "JV-2080 Patch Common Patch Control Source 3");
	setupParameter("Reserved", 0x3C, 0, 2, 0x00, StringArray(), "JV-2080 Patch Common EFX Control Hold/Peak");
	setupParameter("Reserved", 0x3D, 0, 2, 0x00, StringArray(), "JV-2080 Patch Common Control 1 Hold/Peak");
	setupParameter("Reserved", 0x3E, 0, 2, 0x00, StringArray(), "JV-2080 Patch Common Control 2 Hold/Peak");
	setupParameter("Reserved", 0x3F, 0, 2, 0x00, StringArray(), "JV-2080 Patch Common Control 3 Hold/Peak");

	setupParameter("Velocity Range Switch", 0x40, 0, 1, 0, switchOnOffStrings, "Specifies whether or not the Velocity Range settings will be enabled. By using velocity range settings, you can cause different tones to sound in response to notes played at different strengths on the external MIDI keyboard.");

	setupParameter("Reserved", 0x41, 0, 6, 3, StringArray::fromTokens("-3 -2 -1 0 +1 +2 +3", false), "JV-2080 Patch Common Octave Shift");

	setupParameter("Stretch Tune Depth", 0x42, 0, 3, 0, StringArray::fromTokens("OFF 1 2 3", false), "Select the stretch tuning curve. The selected curve will affect the way that chords will sound.\r\nWhen this is \"OFF,\" equal temperament will be used. As the value is increased, the pitch difference between the high range and low range will increase.\r\nStretch Tuning is a unique method of tuning specific to pianos.In general, pianos are tuned so that their high range is sharper and their low range is flatter than the equal tempered pitch.This makes chords sound better.");
	setupParameter("Voice Priority", 0x43, 0, 1, 0, StringArray::fromTokens("LAST LOUDEST", false), "LAST: The last-played notes will take priority. If more than 64 notes are played, the first-played notes will be turned off successively.\r\nLOUDEST:The loudest notes will take priority.If more than 64 notes are played, the notes with the lowest volume will be turned off successively.");
	setupParameter("Structure Type 1 and 2", 0x44, 0, 9, 0, StringArray::fromTokens("1 2 3 4 5 6 7 8 9 10", false), "Specifies how tones 1 and 2 will be combined.\r\nWith TYPE 2-10 selected, turning off one of the paired tones will cause the other tone to sound as TYPE 1");
	setupParameter("Booster 1 and 2", 0x45, 0, 3, 0, boosterGain, "When a Structure Type of \"TYPE3\" or \"TYPE4\" is selected, you can adjust the depth of the booster. The Booster is a function that increases the input signal in order to distort it. Higher settings will produce greater distortion.\r\nIn addition to using this for distortion, you can use the waveform of one of the tones as an LFO to shift the other waveform up and down, producing an effect similar to PWM(Pulse Width Modulation).This is even more effective when used in conjunction with the Wave Gain of the WAVE/FXM.");
	setupParameter("Structure Type 3 and 4", 0x46, 0, 9, 0, StringArray::fromTokens("1 2 3 4 5 6 7 8 9 10", false), "Specifies how tones 3 and 4 will be combined.\r\nWith TYPE 2-10 selected, turning off one of the paired tones will cause the other tone to sound as TYPE 1");
	setupParameter("Booster 3 and 4", 0x47, 0, 3, 0, boosterGain, "When a Structure Type of \"TYPE3\" or \"TYPE4\" is selected, you can adjust the depth of the booster. The Booster is a function that increases the input signal in order to distort it. Higher settings will produce greater distortion.\r\nIn addition to using this for distortion, you can use the waveform of one of the tones as an LFO to shift the other waveform up and down, producing an effect similar to PWM(Pulse Width Modulation).This is even more effective when used in conjunction with the Wave Gain of the WAVE/FXM.");

	setupParameter("Reserved", 0x48, 0, 1, 1, StringArray(), "JV-2080 Patch Common Clock Source");
	setupParameter("Reserved", 0x49, 0, 127, 0, StringArray(), "JV-2080 Patch Common Patch Category");
}

void PatchCommonBlock::setPatchName(String name)
{
	for (int i = 0; i < 12 && i < name.length(); i++)
	{
		char c = (char)name[i];
		if (c < 32 || c>125) c = 32;	// fallback to space
		m_data[i] = c;
	}
}

// ----------------------------------------------------------------------------

PatchToneBlock::PatchToneBlock(SynthParts part, Tone tone) :
	GrooveboxMemoryBlock(0x02000000 | ((uint32)part << 16 | (uint32)tone), "Tone " + String(((((uint16)tone >> 8) - 0x10) / 2) + 1) + " of Part " + String((uint8)part + 1), "1-3-2", 0x0101),
	m_tone(tone),
    m_part(part)
{
	switch (m_tone)
	{
	case Tone1: m_name = "Tone 1"; break;
	case Tone2: m_name = "Tone 2"; break;
	case Tone3: m_name = "Tone 3"; break;
	case Tone4: m_name = "Tone 4"; break;
	default: break;
	}
	/*  1:*/StringArray waveGroupIdsStrings(StringArray::fromTokens("Reserved;Group A;Group B;Group C", ";", String()));
	/*  2:*/StringArray waveGainStrings(StringArray::fromTokens(" -6dB;  0dB; +6dB;+12dB", ";", String()));
	/*  5:*/StringArray noteNames(StringArray::fromTokens("C -1;C#-1;D -1;D#-1;E -1;F -1;F#-1;G -1;G#-1;A -1;A#-1;B -1;C  0;C# 0;D  0;D# 0;E  0;F  0;F# 0;G  0;G# 0;A  0;A# 0;B  0;C  1;C# 1;D  1;D# 1;E  1;F  1;F# 1;G  1;G# 1;A  1;A# 1;B  1;C  2;C# 2;D  2;D# 2;E  2;F  2;F# 2;G  2;G# 2;A  2;A# 2;B  2;C  3;C# 3;D  3;D# 3;E  3;F  3;F# 3;G  3;G# 3;A  3;A# 3;B  3;C  4;C# 4;D  4;D# 4;E  4;F  4;F# 4;G  4;G# 4;A  4;A# 4;B  4;C  5;C# 5;D  5;D# 5;E  5;F  5;F# 5;G  5;G# 5;A  5;A# 5;B  5;C  6;C# 6;D  6;D# 6;E  6;F  6;F# 6;G  6;G# 6;A  6;A# 6;B  6;C  7;C# 7;D  7;D# 7;E  7;F  7;F# 7;G  7;G# 7;A  7;A# 7;B  7;C  8;C# 8;D  8;D# 8;E  8;F  8;F# 8;G  8;G# 8;A  8;A# 8;B  8;C  9;C# 9;D  9;D# 9;E  9;F  9;F# 9;G  9", ";", String()));
	/*  7:*/StringArray controlDestinations(StringArray::fromTokens("OFF;Pitch;Filter Cutoff;Filter Res;Tone Level;Tone Pan;LFO1 Pitch;LFO2 Pitch;LFO1 Filter;LFO2 Filter;LFO1 Amp;LFO2 Amp;LFO1 Pan;LFO2 Pan;LFO1 Rate;LFO2 Rate", ";", String()));
	StringArray modulationDepthStrings; for (int i = -63; i <= 63; i++)
	{
		if (i<0) modulationDepthStrings.add("-" + String(-i));
		else if (i == 0) modulationDepthStrings.add(String(i));
		else if (i>0) modulationDepthStrings.add("+" + String(i));
	}
	/*  8:*/StringArray lfoWaveforms(StringArray::fromTokens("TRI;SIN;SAW;SQR;TRP;S&H;RND;CHAOS", ";", String()));
	/*  9:*/StringArray lfoOffset(StringArray::fromTokens("-100; -50;   0; +50;+100", ";", String()));
	/* 10:*/StringArray lfoFadeModes(StringArray::fromTokens("On-In;On-Out;Off-In;Off-Out", ";", String()));
	StringArray coarseTuneStrings; for (int i = -48; i <= 48; i++)
	{
		if (i<0) coarseTuneStrings.add("-" + String(-i));
		else if (i == 0) coarseTuneStrings.add(String(i));
		else if (i>0) coarseTuneStrings.add("+" + String(i));
	}
	StringArray fineTuneStrings; for (int i = -50; i <= 50; i++)
	{
		if (i<0) fineTuneStrings.add("-" + String(-i));
		else if (i == 0) fineTuneStrings.add(String(i));
		else if (i>0) fineTuneStrings.add("+" + String(i));
	}
	StringArray pitchEnvelopeDepthStrings; for (int i = -12; i <= 12; i++)
	{
		if (i<0) pitchEnvelopeDepthStrings.add("-" + String(-i));
		else if (i == 0) pitchEnvelopeDepthStrings.add(String(i));
		else if (i>0) pitchEnvelopeDepthStrings.add("+" + String(i));
	}
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
	/* 11:*/StringArray randomPitchFactors(StringArray::fromTokens("0 1 2 3 4 5 6 7 8 9 10 20 30 40 50 60 70 80 90 100 200 300 400 500 600 700 800 900 1000 1100 1200", false));
	/* 12:*/StringArray keyFollowFactors(StringArray::fromTokens("-100, -70, -50, -30, -10,   0, +10, +20, +30, +40, +50, +70,+100,+120,+150,+200", ",", String()));
	/* 13:*/StringArray veloSensFactors(StringArray::fromTokens("-100; -98; -96; -94; -92; -90; -88; -86; -84; -82; -80; -78; -76; -74; -72; -70; -68; -66; -64; -62; -60; -58; -56; -54; -52; -50; -48; -46; -44; -42; -40; -38; -36; -34; -32; -30; -28; -26; -24; -22; -20; -18; -16; -14; -12; -10;  -8;  -6;  -4;  -2;   0;  +2;  +4;  +6;  +8; +10; +12; +14; +16; +18; +20; +22; +24; +26; +28; +30; +32; +34; +36; +38; +40; +42; +44; +46; +48; +50; +52; +54; +56; +58; +60; +62; +64; +66; +68; +70; +72; +74; +76; +78; +80; +82; +84; +86; +88; +90; +92; +94; +96; +98;+100;+102;+104;+106;+108;+110;+112;+114;+116;+118;+120;+122;+124;+126;+128;+130;+132;+134;+136;+138;+140;+142;+144;+146;+148;+150", ";", String()));
	/* 14:*/StringArray veloTimeFactorsAndEnvKeyFollow(StringArray::fromTokens("-100, -70, -50, -40, -30, -20, -10,   0, +10, +20, +30, +40, +50, +70,+100", ",", String()));
	/* 15:*/StringArray filterTypes(StringArray::fromTokens("OFF LPF BPF HPF PKG", false));
	/* 16:*/StringArray biasDirection(StringArray::fromTokens("LOWER UPPER LOW&UP ALL", false));
	StringArray switchOnOffStrings(StringArray::fromTokens("OFF ON", false));
	StringArray velocityCurves(StringArray::fromTokens("Curve 1;Curve 2;Curve 3;Curve 4;Curve 5;Curve 6;Curve 7", ";", String()));

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
	String lfoKeySyncDescription(String("This parameter synchronizes the LFO cycle to the timing at which the keyboard pads are played.\r\n") +
		"When Key Sync is on, the LFO waveform will begin for each note when it is played, producing a spacious sound with a sense of movement. When Key Sync is off, a single LFO waveform will be applied to all notes, producing a unified sound. When you wish to emphasize the effect (vibrato etc.), you may want to turn this parameter off. Also, when Tempo Sync is on, leaving Key Sync off will allow you to synchronize precisely to the tempo (BPM) of the pattern.\r\n" +
		"Range:\r\n" +
		"- ON:The LFO cycle will begin when the keyboard is played.\r\n" +
		"- OFF:The same LFO waveform will be output regardless of the timing at which the keyboard is played.\r\n");
	String lfoRateDescription(String("Adjusts the LFO modulation speed.\r\n") +
		"As this value is increased, the sound will be modulated more rapidly.As this value is decreased, the sound will be modulated more slowly.\r\n" +
		"When LFO Tempo Sync is \"ON\", you can specify this parameter in terms of a note value.\r\n" +
		"LFO Rate settings are common to PITCH (pitch), FILTER (brightness)and AMP(volume).The rate cannot be set independently for these three.");
	String lfoOffsetDescription(String("This parameter offsets the LFO waveform upward or downward from the central value(pitch or cutoff frequency, etc.)\r\n") +
		"As this value is increased in the positive (+) direction, the waveform will be moved upward from the central value. As this value is increased in the negative (-) direction, the waveform will be moved downward from the central value.)");
	String lfoDelayTimeDescription(String("Depending on the Fade Mode setting, specify the time over which the LFO will be applied or the time over which it will continue, etc.\r\n") +
		"Higher settings will produce longer times.");
	String lfoFadeModeDescription(String("Select the way in which the LFO effect will be applied.\r\n") +
		"Range:\r\n" +
		"- OnI (On-In): The effect will be applied gradually, after the keyboard pad is pressed.\r\n" +
		"- OnO (On-Out): The effect will be applied immediately when the keyboard pad is pressed, and will gradually disappear.\r\n" +
		"- OfI (Off-In): The effect will be applied gradually, starting when the keyboard pad is released.\r\n" +
		"- OfO (Off-Out): The effect will be applied while the keyboard pad remains pressed, and will gradually disappear after it is released.");
	String lfoFadeTimeDescription(String("Specifies the time over which the LFO amplitude will reach the maximum (minimum) after the Delay TIME has elapsed.\r\n") +
		"Higher settings will produce longer times.");
	String lfoTempoSyncDescription(String("This parameter synchronizes the LFO modulation frequency to the tempo of the pattern.\r\n") +
		"Range:\r\n" +
		"- ON: The modulation speed will be synchronized to the tempo (BPM), and the LFO Rate parameter can be set in terms of a note value." +
		"- OFF: The modulation speed will be determined by the LFO Rate setting, regardless of the tempo(BPM).");

	// void setupParameter(String name, uint16 addressOffset, uint8 min, uint8 max, uint8 default = 0, StringArray displayedValues = StringArray(), String description = String(), uint8 cc = 102, bool ccIsMode2Only = false);
	setupParameter("Tone Switch", 0x00, 0, 1, (tone == Tone1 || tone == Tone2)?1:0, switchOnOffStrings, "Turn this \"ON\" if you want the tone to sound, or \"OFF\" if you do not want the tone to sound.\r\nIn order to make the best use of the available polyphony, unused tones should be turned \"OFF.\"");
	setupParameter("Wave Group Type", 0x01, 0, 0, 0, StringArray::fromTokens("0", false));
	setupParameter("Wave Group ID", 0x02, 1, 3, 1, waveGroupIdsStrings);
	setupParameter("Wave Number", 0x03, 0, 254, (tone == Tone2 || tone == Tone4) ? 1 : 3);
	setupParameter("Wave Gain", 0x05, 0, 3, 2, waveGainStrings, "This boosts the waveform. Raising this setting 6 dB will double the gain. If you are using the booster to distort the sound, setting this to the maximum value will be effective.");
	setupParameter("FXM Switch", 0x06, 0, 1, 0, switchOnOffStrings, "FXM (Frequency Cross Modulation) uses a specific waveform to apply frequency modulation to the selected waveform, creating complex overtones.This is useful for creating dramatic sounds or sound effects. When you wish to use FXM, turn this \"ON.\"");
	setupParameter("FXM Color", 0x07, 0, 3, 0, StringArray(), "Select one of four types of frequency modulation for FXM to apply.\r\n As this value is increased, the sound will become rougher. Lower values will produce a metallic sound.");
	setupParameter("FXM Depth", 0x08, 0, 15, 0, StringArray(), "Adjusts the depth of frequency modulation produced by FXM. As this value is increased, modulation will be applied more deeply.\r\nAs the value is decreased, modulation depth will decrease.");

	setupParameter("Tone Delay Mode", 0x09, 0, 7, 0, StringArray::fromTokens("NORMAL HOLD PLAYMATE CLOCK-SYNC TAP-SYNC KEY-OFF-NORMAL KEY-OFF-DECAY TEMPO-SYNC", false), "Select the type of tone delay.");
	setupParameter("Tone Delay Time", 0x0A, 0, 127, 0, StringArray(), "Specify the time from when the key is pressed until when the tone will sound.");

	setupParameter("Velocity Cross Fade", 0x0B, 0, 127, 0, StringArray(), "Specifies the way in which the volume will change when a keyboard is played with a velocity that falls outside the velocity range setting.By using Velocity Crossfade, you can use playing dynamics on the keyboard to smoothly connect two tones.\r\nHigher settings will cause the volume to decrease more gradually when the velocity falls outside of the velocity range.");
	setupParameter("Velocity Range Lower", 0x0C, 1, 127, 1, StringArray(), "Specifies the lower velocity limit for which the tone will sound.\r\nThe tone will not be sounded by notes played with a velocity lower than this setting.");
	setupParameter("Velocity Range Upper", 0x0D, 1, 127, 127, StringArray(), "Specifies the upper velocity limit for which the tone will sound.\r\nThe tone will not be sounded by notes played with a velocity stronger than this setting.");
	setupParameter("Keyboard Range Lower", 0x0E, 0, 127, 0, noteNames, "Specifies the lowest note that the tone will sound.\r\nIf a note below this setting is played, it will not sound.");
	setupParameter("Keyboard Range Upper", 0x0F, 0, 127, 127, noteNames, "Specifies the highest note that the tone will sound.\r\nIf a note above this setting is played, it will not sound.");

	setupParameter("Reserved", 0x10, 0, 1, 1, StringArray(), "JV-2080 Patch Tone Redamper Control Switch");
	setupParameter("Reserved", 0x11, 0, 1, 1, StringArray(), "JV-2080 Patch Tone Volume Control Switch");
	setupParameter("Reserved", 0x12, 0, 1, 1, StringArray(), "JV-2080 Patch Tone Hold-1 Control Switch");
	setupParameter("Reserved", 0x13, 0, 1, 1, StringArray(), "JV-2080 Patch Tone Pitch Bend Control Switch");
	setupParameter("Reserved", 0x14, 0, 1, 2, StringArray(), "JV-2080 Patch Tone Pan Control Switch");

	setupParameter("Modulation Destination 1", 0x15, 0, 15, 0, controlDestinations, "Parameter 1 that will be controlled temporarily when the modulation controller of the external MIDI device is operated.");
	setupParameter("Modulation Depth 1", 0x16, 0, 126, 63, modulationDepthStrings, "Specifies the amount of change that will occur for Parameter 1.\r\nWith positive (+) settings, higher values will allow greater control. With negative (-) settings, the direction of the change will be inverted.");
	setupParameter("Modulation Destination 2", 0x17, 0, 15, 0, controlDestinations, "Parameter 2 that will be controlled temporarily when the modulation controller of the external MIDI device is operated.");
	setupParameter("Modulation Depth 2", 0x18, 0, 126, 63, modulationDepthStrings, "Specifies the amount of change that will occur for Parameter 2.\r\nWith positive (+) settings, higher values will allow greater control. With negative (-) settings, the direction of the change will be inverted.");
	setupParameter("Modulation Destination 3", 0x19, 0, 15, 0, controlDestinations, "Parameter 3 that will be controlled temporarily when the modulation controller of the external MIDI device is operated.");
	setupParameter("Modulation Depth 3", 0x1A, 0, 126, 63, modulationDepthStrings, "Specifies the amount of change that will occur for Parameter 3.\r\nWith positive (+) settings, higher values will allow greater control. With negative (-) settings, the direction of the change will be inverted.");
	setupParameter("Modulation Destination 4", 0x1B, 0, 15, 0, controlDestinations, "Parameter 4 that will be controlled temporarily when the modulation controller of the external MIDI device is operated.");
	setupParameter("Modulation Depth 4", 0x1C, 0, 126, 63, modulationDepthStrings, "Specifies the amount of change that will occur for Parameter 4.\r\nWith positive (+) settings, higher values will allow greater control. With negative (-) settings, the direction of the change will be inverted.");
	setupParameter("Pitch Bend Destination 1", 0x1D, 0, 15, 0, controlDestinations, "Parameter 1 that will be controlled temporarily when the pitch bend controller of the external MIDI device is operated.");
	setupParameter("Pitch Bend Depth 1", 0x1E, 0, 126, 63, modulationDepthStrings, "Specifies the amount of change that will occur for Parameter 1.\r\nWith positive (+) settings, higher values will allow greater control. With negative (-) settings, the direction of the change will be inverted.");
	setupParameter("Pitch Bend Destination 2", 0x1F, 0, 15, 0, controlDestinations, "Parameter 2 that will be controlled temporarily when the pitch bend controller of the external MIDI device is operated.");
	setupParameter("Pitch Bend Depth 2", 0x20, 0, 126, 63, modulationDepthStrings, "Specifies the amount of change that will occur for Parameter 2.\r\nWith positive (+) settings, higher values will allow greater control. With negative (-) settings, the direction of the change will be inverted.");
	setupParameter("Pitch Bend Destination 3", 0x21, 0, 15, 0, controlDestinations, "Parameter 3 that will be controlled temporarily when the pitch bend controller of the external MIDI device is operated.");
	setupParameter("Pitch Bend Depth 3", 0x22, 0, 126, 63, modulationDepthStrings, "Specifies the amount of change that will occur for Parameter 3.\r\nWith positive (+) settings, higher values will allow greater control. With negative (-) settings, the direction of the change will be inverted.");
	setupParameter("Pitch Bend Destination 4", 0x23, 0, 15, 0, controlDestinations, "Parameter 4 that will be controlled temporarily when the pitch bend controller of the external MIDI device is operated.");
	setupParameter("Pitch Bend Depth 4", 0x24, 0, 126, 63, modulationDepthStrings, "Specifies the amount of change that will occur for Parameter 4.\r\nWith positive (+) settings, higher values will allow greater control. With negative (-) settings, the direction of the change will be inverted.");
	setupParameter("Aftertouch Destination 1", 0x25, 0, 15, 0, controlDestinations, "Parameter 1 that will be controlled temporarily when the aftertouch controller of the external MIDI device is operated.");
	setupParameter("Aftertouch Depth 1", 0x26, 0, 126, 63, modulationDepthStrings, "Specifies the amount of change that will occur for Parameter 1.\r\nWith positive (+) settings, higher values will allow greater control. With negative (-) settings, the direction of the change will be inverted.");
	setupParameter("Aftertouch Destination 2", 0x27, 0, 15, 0, controlDestinations, "Parameter 2 that will be controlled temporarily when the aftertouch controller of the external MIDI device is operated.");
	setupParameter("Aftertouch Depth 2", 0x28, 0, 126, 63, modulationDepthStrings, "Specifies the amount of change that will occur for Parameter 2.\r\nWith positive (+) settings, higher values will allow greater control. With negative (-) settings, the direction of the change will be inverted.");
	setupParameter("Aftertouch Destination 3", 0x29, 0, 15, 0, controlDestinations, "Parameter 3 that will be controlled temporarily when the aftertouch controller of the external MIDI device is operated.");
	setupParameter("Aftertouch Depth 3", 0x2A, 0, 126, 63, modulationDepthStrings, "Specifies the amount of change that will occur for Parameter 3.\r\nWith positive (+) settings, higher values will allow greater control. With negative (-) settings, the direction of the change will be inverted.");
	setupParameter("Aftertouch Destination 4", 0x2B, 0, 15, 0, controlDestinations, "Parameter 4 that will be controlled temporarily when the aftertouch controller of the external MIDI device is operated.");
	setupParameter("Aftertouch Depth 4", 0x2C, 0, 126, 63, modulationDepthStrings, "Specifies the amount of change that will occur for Parameter 4.\r\nWith positive (+) settings, higher values will allow greater control. With negative (-) settings, the direction of the change will be inverted.");

	setupParameter("LFO1 Waveform", 0x2D, 0, 7, 1, lfoWaveforms, lfoWaveformDescription);
	setupParameter("LFO1 Key Sync", 0x2E, 0, 7, 0, switchOnOffStrings, lfoKeySyncDescription);
	setupParameter("LFO1 Rate", 0x2F, 0, 127, 0x64, StringArray(), lfoRateDescription);	// TODO: change description by LFO Tempo Sync Setting
	setupParameter("LFO1 Offset", 0x30, 0, 4, 2, lfoOffset, lfoOffsetDescription);
	setupParameter("LFO1 Delay Time", 0x31, 0, 127, 0x0A, StringArray(), lfoDelayTimeDescription);
	setupParameter("LFO1 Fade Mode", 0x32, 0, 3, 0, lfoFadeModes, lfoFadeModeDescription);
	setupParameter("LFO1 Fade Time", 0x33, 0, 127, 0, StringArray(), lfoFadeTimeDescription);
	setupParameter("LFO1 Tempo Sync", 0x34, 0, 1, 0, switchOnOffStrings, lfoTempoSyncDescription);
	setupParameter("LFO2 Waveform", 0x35, 0, 7, 0, lfoWaveforms, lfoWaveformDescription);
	setupParameter("LFO2 Key Sync", 0x36, 0, 1, 0, switchOnOffStrings, lfoKeySyncDescription);
	setupParameter("LFO2 Rate", 0x37, 0, 127, 0x5c, StringArray(), lfoRateDescription);	// TODO: change description by LFO Tempo Sync Setting
	setupParameter("LFO2 Offset", 0x38, 0, 4, 2, lfoOffset, lfoOffsetDescription);
	setupParameter("LFO2 Delay Time", 0x39, 0, 127, 0, StringArray(), lfoDelayTimeDescription);
	setupParameter("LFO2 Fade Mode", 0x3A, 0, 3, 0, lfoFadeModes, lfoFadeModeDescription);
	setupParameter("LFO2 Fade Time", 0x3B, 0, 127, 0, StringArray(), lfoFadeTimeDescription);
	setupParameter("LFO2 Tempo Sync", 0x3C, 0, 1, 0, switchOnOffStrings, lfoTempoSyncDescription);

	setupParameter("Coarse Tune", 0x3D, 0, 96, 48, coarseTuneStrings, "Adjust the pitch of each tone in semitone steps. Higher settings will raise the pitch. Lower settings will lower the pitch.");
	setupParameter("Fine Tune", 0x3E, 0, 100, 50, fineTuneStrings, "You can adjust the pitch of each tone in 1-cent steps (1/100th of a semitone).\r\nThe greater the value, the higher the pitch, and the smaller value, the lower the pitch.\r\nIf you select the same waveform for two tones, set the same Coarse Tune value for both tones and then use Fine Tune to create a slight pitch difference between the two tones, the sound will appear more spacious (the Detune effect).");
	setupParameter("Random Pitch Depth", 0x3F, 0, 30, 0, randomPitchFactors, "This applies a degree of randomness to the pitch of each note. As this value is increased, a greater degree of randomness will be applied. As this value is decreased, there will be less randomness.\r\nWith a value of \"0\" there will be no effect.");
	setupParameter("Pitch Keyfollow", 0x40, 0, 15, 12, keyFollowFactors, "This setting causes the pitch to be affected by the key pad location.\r\n"
		"Unless you are creating a special type of sound, you will normally leave this at \"+100.\"\r\n"
		"With positive (+) settings, the pitch will rise as you play higher notes (i.e., notes toward the right of the keyboard).\r\n"
		"With negative (-) settings, the pitch will fall as you play higher notes.\r\n"
		"- +100: As on a conventional keyboard instrument, the pitch will rise one octave when you move 12 notes upward on the keyboard.\r\n"
		"- +200: The pitch will rise two octaves when you move 12 notes upward on the keyboard.\r\n"
		"- 0: The pitch will be the same regardless of which note you play.\r\n"
		"- 100: The pitch will fall one octave when you move 12 notes upward on the keyboard.\r\n"
		"When you are creating sounds of instruments that naturally have minimal change in pitch, such as percussion instruments, it is effective to set Pitch Key Follow to a setting of \"+10\" or \"+20.\"");
	setupParameter("Pitch Envelope Depth", 0x41, 0, 24, 12, pitchEnvelopeDepthStrings, "Here's how you can adjust the depth of the Pitch Envelope. Increasingly positive (+) settings will produce a greater width of pitch change. Negative (-) settings will invert the shape of the envelope, causing the pitch to change in the opposite direction.");
	setupParameter("Pitch Envelope Velocity Sens", 0x42, 0, 125, 50, veloSensFactors, "This setting lets you control the Pitch Envelope depth by the force with which you play the external MIDI keyboard.\r\n"
		"With positive (+) settings, the pitch will change more greatly as you play the keyboard more strongly. With negative (-) settings, the pitch will change less as you play the keyboard more strongly.\r\n"
		"When TIME is set to a positive (+) value, softly-played notes will have little pitch change, and strongly-played notes will have greater pitch change;\r\n"
		"this lets you simulate \"the pitch instability at the beginning of each note\" that is characteristic of wind instruments.");
	setupParameter("Pitch Envelope Velocity Time1", 0x43, 0, 14, 7, veloTimeFactorsAndEnvKeyFollow, "The strength with which a keyboard key on an external MIDI keyboard is pressed is used to control TIME 1.\r\n"
		"With positive (+) settings, TIME1 will become faster as you play the keyboard more strongly. With negative (-) settings, TIME1 will become slower as you play the keyboard more strongly.");
	setupParameter("Pitch Envelope Velocity Time4", 0x44, 0, 14, 7, veloTimeFactorsAndEnvKeyFollow, "The speed at which a keyboard key on an external MIDI keyboard is released is used to control TIME 4.\r\n"
		"With positive (+) settings, releasing the keyboard more quickly will cause TIME4 to be faster. With negative (-) settings, releasing the keyboard more quickly will cause TIME4 to be slower.");
	setupParameter("Pitch Envelope Time Keyfollow", 0x45, 0, 14, 7, veloTimeFactorsAndEnvKeyFollow, "This setting causes the pitch envelope times (TIME 2/3/4) to be affected by the keyboard pad position. Higher settings will produce a greater change relative to the C4 key envelope.\r\n"
		"With positive (+) settings, times will become shorter as you play higher notes. With negative (-) settings, times will become longer as you play higher notes.");
	setupParameter("Pitch Envelope Time 1", 0x46, 0, 127, 0, StringArray(), "Specifies the time until the next pitch level is reached.\r\nHigher settings will result in a longer time until the next pitch level is reached.");
	setupParameter("Pitch Envelope Time 2", 0x47, 0, 127, 0, StringArray(), "Specifies the time until the next pitch level is reached.\r\nHigher settings will result in a longer time until the next pitch level is reached.");
	setupParameter("Pitch Envelope Time 3", 0x48, 0, 127, 0, StringArray(), "Specifies the time until the next pitch level is reached.\r\nHigher settings will result in a longer time until the next pitch level is reached.");
	setupParameter("Pitch Envelope Time 4", 0x49, 0, 127, 0, StringArray(), "Specifies the time until the next pitch level is reached.\r\nHigher settings will result in a longer time until the next pitch level is reached.");
	setupParameter("Pitch Envelope Level 1", 0x4A, 0, 126, (tone == Tone1 || tone == Tone2) ? 0x7E : 0x3F, modulationDepthStrings, "Specifies the pitch difference relative to the normal pitch (as specified by Coarse Tune and Fine Tune).\r\nPositive (+) settings will raise the pitch above the normal pitch. Negative (-) settings will make the pitch lower than the normal pitch.");
	setupParameter("Pitch Envelope Level 2", 0x4B, 0, 126, (tone == Tone1 || tone == Tone2) ? 0x7E : 0x3F, modulationDepthStrings, "Specifies the pitch difference relative to the normal pitch (as specified by Coarse Tune and Fine Tune).\r\nPositive (+) settings will raise the pitch above the normal pitch. Negative (-) settings will make the pitch lower than the normal pitch.");
	setupParameter("Pitch Envelope Level 3", 0x4C, 0, 126, 63, modulationDepthStrings, "Specifies the pitch difference relative to the normal pitch (as specified by Coarse Tune and Fine Tune).\r\nPositive (+) settings will raise the pitch above the normal pitch. Negative (-) settings will make the pitch lower than the normal pitch.");
	setupParameter("Pitch Envelope Level 4", 0x4D, 0, 126, 63, modulationDepthStrings, "Specifies the pitch difference relative to the normal pitch (as specified by Coarse Tune and Fine Tune).\r\nPositive (+) settings will raise the pitch above the normal pitch. Negative (-) settings will make the pitch lower than the normal pitch.");
	setupParameter("Pitch LFO1 Depth", 0x4E, 0, 126, 0x49, modulationDepthStrings, "The pitch level wavers cyclically, creating a vibrato effect. The wavering increases the further from 0 the value becomes, and the effect is reversed by switching the - and + signs.\r\nBy giving two tones the same rate setting and setting their Pitch Depth to \"+30\" and \"-30\" respectively to apply opposite-phase LFO, you can create a vibrato effect in which the pitches change in opposite directions.");
	setupParameter("Pitch LFO2 Depth", 0x4F, 0, 126, 63, modulationDepthStrings, "The pitch level wavers cyclically, creating a vibrato effect. The wavering increases the further from 0 the value becomes, and the effect is reversed by switching the - and + signs.\r\nBy giving two tones the same rate setting and setting their Pitch Depth to \"+30\" and \"-30\" respectively to apply opposite-phase LFO, you can create a vibrato effect in which the pitches change in opposite directions.");

	setupParameter("Filter Type", 0x50, 0, 4, 1, filterTypes, "- OFF: The filter will not be applied.\r\n"
		"- LPF (Low Pass Filter): This type of filter is most commonly used and allows audio signals with frequencies lower than the cutoff frequency to pass through. It is used to make the sound more mellow.\r\n"
		"- BPF (Band Pass Filter): This filter cuts off all audio signals except for those with frequencies around the cutoff frequency.\r\n"
		"- HPF (High Pass Filter): This filter allows audio signals with frequencies exceeding the cutoff frequency to pass. It is effectively used to make sounds brighter and sharper.\r\n"
		"- PKG (Peaking Filter): This filter enhances audio signals with frequencies around the cutoff frequency. It will emphasize the midrange, and is useful for creating a distinctive sound.\r\n"
		"By selecting the Peaking Filter as the Filter Type and using the LFO to modulate the cutoff frequency, you can create a \"wah\" effect.");
	setupParameter("Cutoff Frequency", 0x51, 0, 127, (tone == Tone1 || tone == Tone3) ? 0x7A : 0x4D, StringArray(), "Specifies the frequency at which the filter will begin to affect the frequency components of the waveform (the Cutoff Frequency). By changing the cutoff frequency, you can control the brightness of the sound. The effect will depend on the Filter Type.\r\n"
		"- LPF (Low Pass Filter): Increasing the value will brighten the sound, making it more similar to the original waveform, approaching the  original waveform. Lower settings will cut more of the high frequency overtones, making the sound darker. For some waveforms, you may not be able to hear any sound if you lower the value too far.\r\n"
		"- BPF (Band Pass Filter): Higher settings will raise the frequency area that is heard. Lower settings will cause only a progressively lower frequency area to be heard.\r\n"
		"- HPF (High Pass Filter): As this value is increased, the low frequency range will be cut more greatly, making the sound sharper. As this value is decreased, the original sound of the waveform will be heard. For some waveforms, you may hear no sound if this value is raised excessively.\r\n"
		"- PKG (Peaking Filter): As this value is increased, the frequency area that is emphasized will rise. As this value is decreased, the frequency area that is emphasized will fall.");
	setupParameter("Cutoff Keyfollow", 0x52, 0, 15, (tone == Tone1 || tone == Tone3) ? 7 : 5, keyFollowFactors, "This setting causes the cutoff frequency to be affected by the keyboard pad position.\r\n"
		"With positive (+) settings, the cutoff frequency will also rise as you play higher notes. With negative (-) settings, the cutoff frequency will become lower as you play higher notes.\r\n"
		"- +100: When you move 12 notes upward from C4 on the keyboard, the cutoff frequency will rise one octave.\r\n"
		"- +200: When you move 12 notes upward from C4 on the keyboard, the cutoff frequency will rise two octaves.\r\n"
		"-    0: The cutoff frequency will be the same for all notes.\r\n"
		"- -100: When you move 12 notes upward from C4 on the keyboard, the cutoff frequency will fall one octave.\r\n"
		"If you set Cutoff Frequency to a value of approximately \"64\", the key follow effect will be easy to hear.");
	setupParameter("Resonance", 0x53, 0, 127, 0, StringArray(), "This setting emphasizes the overtones in the region of the cutoff frequency, adding character to the sound.\r\n"
		"As this value is increased, the sound will have more character. As this value is decreased, the sound will be more natural.\r\n"
		"In order to prevent the resonance from being increased excessively, factory settings have been made so that the value will not rise beyond \"115\" even if the [RESONANCE] knob is rotated all the way to the right. This is called the Resonance Limiter. You are free to adjust this upper limit.\r\n"
		"If you have increased the Resonance Limiter setting, be careful not to raise the resonance excessively. Excessively high values may cause sounds to be distorted or the volume level to become unexpectedly high. Some settings may damage your hearing, or your speakers. Please use caution.");
	setupParameter("Resonance Velocity Sens", 0x54, 0, 125, 50, veloSensFactors, "Specifies how resonance depth will be affected by your playing dynamics on the external MIDI keyboard.\r\nWith positive (+) settings, playing the keyboard more strongly will cause the change to be greater. With negative (-) settings, playing the keyboard more strongly will cause the change to be less.");
	setupParameter("Filter Envelope Depth", 0x55, 0, 126, 63, modulationDepthStrings, "This setting adjusts the depth of the filter envelope. As the value is increased in the positive(+) direction, the amount of tonal change will increase. With negative(-) settings, the shape of the envelope will be inverted, and the tone will change in the opposite direction.\r\nWhen setting Envelope Depth to a positive(+) value, the effect of the filter envelope will be easier to hear if you set a lower cutoff frequency.");
	setupParameter("Filter Envelope Velocity Curve", 0x56, 0, 6, 0, velocityCurves, "Select the curve of change with which the force of your playing on the external MIDI keyboard will affect the amount of change produced by the filter envelope.");
	setupParameter("Filter Envelope Velocity Sens", 0x57, 0, 125, 50, veloSensFactors, "Specifies how the force of your playing on the external MIDI keyboard will affect the filter envelope.\r\n"
		"With positive (+) settings, the tone will change more as you play more strongly on the keyboard. With negative (-) settings, the tone will change less as you play more strongly on the keyboard.\r\n"
		"With positive (+) settings of TIME, the sound will be brighter for strongly-played notes, and darker for softly-played notes.");
	setupParameter("Filter Envelope Velocity Time1", 0x58, 0, 14, 7, veloTimeFactorsAndEnvKeyFollow, "The strength with which a keyboard key on an external MIDI keyboard is pressed is used to control TIME 1.\r\n"
		"With positive (+) settings, TIME1 will become faster as you play the keyboard more strongly. With negative (-) settings, TIME1 will become slower as you play the keyboard more strongly.");
	setupParameter("Filter Envelope Velocity Time4", 0x59, 0, 14, 7, veloTimeFactorsAndEnvKeyFollow, "The speed at which a keyboard key on an external MIDI keyboard is released is used to control TIME 4.\r\n"
		"With positive (+) settings, releasing the keyboard more quickly will cause TIME4 to be faster. With negative (-) settings, releasing the keyboard more quickly will cause TIME4 to be slower.");
	setupParameter("Filter Envelope Time Keyfollow", 0x5A, 0, 14, 7, veloTimeFactorsAndEnvKeyFollow, "This setting causes the pitch envelope times (TIME 2/3/4) to be affected by the keyboard pad position. Higher settings will produce a greater change relative to the C4 key envelope.\r\n"
		"With positive (+) settings, times will become shorter as you play higher notes. With negative (-) settings, times will become longer as you play higher notes.");
	setupParameter("Filter Envelope Time 1", 0x5B, 0, 127, 0, StringArray(), "Specifies the time until the next cutoff frequency is reached.\r\nHigher settings will lengthen the time until the next cutoff frequency is reached.");
	setupParameter("Filter Envelope Time 2", 0x5C, 0, 127, 0, StringArray(), "Specifies the time until the next cutoff frequency is reached.\r\nHigher settings will lengthen the time until the next cutoff frequency is reached.");
	setupParameter("Filter Envelope Time 3", 0x5D, 0, 127, 0, StringArray(), "Specifies the time until the next cutoff frequency is reached.\r\nHigher settings will lengthen the time until the next cutoff frequency is reached.");
	setupParameter("Filter Envelope Time 4", 0x5E, 0, 127, 0, StringArray(), "Specifies the time until the next cutoff frequency is reached.\r\nHigher settings will lengthen the time until the next cutoff frequency is reached.");
	setupParameter("Filter Envelope Level 1", 0x5F, 0, 127, 127, StringArray(), "Specifies the cutoff frequency at each level.\r\nRaising this setting will also raise the cutoff frequency.");
	setupParameter("Filter Envelope Level 2", 0x60, 0, 127, 127, StringArray(), "Specifies the cutoff frequency at each level.\r\nRaising this setting will also raise the cutoff frequency.");
	setupParameter("Filter Envelope Level 3", 0x61, 0, 127, 127, StringArray(), "Specifies the cutoff frequency at each level.\r\nRaising this setting will also raise the cutoff frequency.");
	setupParameter("Filter Envelope Level 4", 0x62, 0, 127, 0, StringArray(), "Specifies the cutoff frequency at each level.\r\nRaising this setting will also raise the cutoff frequency.");
	setupParameter("Filter LFO1 Depth", 0x63, 0, 126, 63, modulationDepthStrings, "The cutoff level wavers cyclically, creating wah effect. The wavering increases the further from 0 the value becomes, and the effect is reversed by switching the - and + signs.");
	setupParameter("Filter LFO2 Depth", 0x64, 0, 126, 63, modulationDepthStrings, "The cutoff level wavers cyclically, creating wah effect. The wavering increases the further from 0 the value becomes, and the effect is reversed by switching the - and + signs.");

	setupParameter("Tone Level", 0x65, 0, 127, (tone == Tone1 || tone == Tone3) ? 0x7F : 0x66, StringArray(), "This setting adjusts the volume of each tone. This is used mainly to adjust the volume balance between tones.");
	setupParameter("Bias Direction", 0x66, 0, 3, 3, biasDirection, "The Bias parameters specify how the keyboard position will affect the Tone Level. This can be used to simulate the way in which the volume of an acoustic instrument changes according to the location (pitch) of the note.\r\n"
		"Select the keyboard area(s) that will be affected above and/or below the specified Bias Point.\r\n"
		"Available Settings:\r\n"
		" - LWR: The volume will be modified for the keyboard area below the note specified as the Bias Point.\r\n"
		" - UPR: The volume will be modified for the keyboard area above the note specified as the Bias Point.\r\n"
		" - L&U: The volume will be modified symmetrically toward the left and right of the note specified as the Bias Point.\r\n"
		" - ALL: The volume will be modified linearly from the note specified as the Bias Point.\r\n"
		"If you use two tones and set a Bias Direction of \"UPR\" for one and \"LWR\" for the other, the two tones will fade smoothly into each other as you play across the Bias Point. (This is known as \"key crossfade\".)\r\n"
		"By setting Bias Direction to \"L&U\", you can create sounds that are heard only in a specific area of the keyboard.");
	setupParameter("Bias Point", 0x67, 0, 127, 0x3C, noteNames, "Specifies the key relative to which the volume will be modified.");
	setupParameter("Bias Level", 0x68, 0, 14, 0x07, veloTimeFactorsAndEnvKeyFollow, "Adjusts the slope of the volume change that will occur in the direction specified by Bias Direction.\r\n"
		"With positive (+) settings, the slope of volume change will increase in the positive (+) direction. With negative (-) settings, the slope of volume change will increase in the negative (-) direction.\r\n"
		"Even with positive (+) settings of this parameter, the volume cannot exceed the maximum level.");
	setupParameter("Amp Envelope Velocity Curve", 0x69, 0, 6, 0, velocityCurves, "Select the curve at which the strength of your playing on the external MIDI keyboard will affect the depth of the amplifier envelope.");
	setupParameter("Amp Envelope Velocity Sens", 0x6A, 0, 125, 0x64, veloSensFactors, "Specifies how the depth of the amplifier envelope will be affected by the strength of your playing on the external MIDI keyboard.\r\n"
		"If velocity sensitivity is set to a positive (+) value, the volume will be loud when you play strongly and soft when you play softly. As this value is increased, the volume difference between strongly played and softly played notes will gradually increase.\r\n"
		"With positive (+) settings, the volume will increase as you play more strongly on the keyboard. With negative (-) settings, the volume will decrease as you play more strongly on the keyboard. If this is set to \"0\", the volume will not be affected by the strength of your playing on the keyboard.");
	setupParameter("Amp Envelope Velocity Time1", 0x6B, 0, 14, 7, veloTimeFactorsAndEnvKeyFollow, "The strength with which a keyboard key on an external MIDI keyboard is pressed is used to control TIME 1.\r\n"
		"With positive (+) settings, TIME1 will become faster as you play the keyboard more strongly. With negative (-) settings, TIME1 will become slower as you play the keyboard more strongly.");
	setupParameter("Amp Envelope Velocity Time4", 0x6C, 0, 14, 7, veloTimeFactorsAndEnvKeyFollow, "The speed at which a keyboard key on an external MIDI keyboard is released is used to control TIME 4.\r\n"
		"With positive (+) settings, releasing the keyboard more quickly will cause TIME4 to be faster. With negative (-) settings, releasing the keyboard more quickly will cause TIME4 to be slower.");
	setupParameter("Amp Envelope Time Keyfollow", 0x6D, 0, 14, 7, veloTimeFactorsAndEnvKeyFollow, "This setting causes the pitch envelope times (TIME 2/3/4) to be affected by the keyboard pad position. Higher settings will produce a greater change relative to the C4 key envelope.\r\n"
		"With positive (+) settings, times will become shorter as you play higher notes. With negative (-) settings, times will become longer as you play higher notes.");
	setupParameter("Amp Envelope Time 1", 0x6E, 0, 127, 0, StringArray(), "Specifies the time until the next level point is reached.\r\nHigher settings will lengthen the time until the next level point is reached.");
	setupParameter("Amp Envelope Time 2", 0x6F, 0, 127, 0, StringArray(), "Specifies the time until the next level point is reached.\r\nHigher settings will lengthen the time until the next level point is reached.");
	setupParameter("Amp Envelope Time 3", 0x70, 0, 127, 0x5E, StringArray(), "Specifies the time until the next level point is reached.\r\nHigher settings will lengthen the time until the next level point is reached.");
	setupParameter("Amp Envelope Time 4", 0x71, 0, 127, 0x0A, StringArray(), "Specifies the time until the next level point is reached.\r\nHigher settings will lengthen the time until the next level point is reached.");
	setupParameter("Amp Envelope Level 1", 0x72, 0, 127, 0x7F, StringArray(), "Specifies the volume at each point. Higher settings will also raise the volume.");
	setupParameter("Amp Envelope Level 2", 0x73, 0, 127, 0x7F, StringArray(), "Specifies the volume at each point. Higher settings will also raise the volume.");
	setupParameter("Amp Envelope Level 3", 0x74, 0, 127, 0x28, StringArray(), "Specifies the volume at each point. Higher settings will also raise the volume.");
	setupParameter("Amp LFO1 Depth", 0x75, 0, 126, 0x41, modulationDepthStrings, "The volume level wavers cyclically, creating a tremolo effect. The wavering increases the further from 0 the value becomes, and the effect is reversed by switching the - and + signs.");
	setupParameter("Amp LFO2 Depth", 0x76, 0, 126, 63, modulationDepthStrings, "The volume level wavers cyclically, creating a tremolo effect. The wavering increases the further from 0 the value becomes, and the effect is reversed by switching the - and + signs.");
	setupParameter("Tone Pan", 0x77, 0, 127, 64, panPosStrings, "This parameter sets the stereo location for each tone.\r\nThe pan of the overall patch can be modified and set for each pattern by the Setup parameter Part Pan. The Tone Pan value will be added to this setting.");
	setupParameter("Pan Key follow", 0x78, 0, 14, 7, veloTimeFactorsAndEnvKeyFollow, "This parameter causes the stereo location to change according to the keyboard pad that is played.\r\nWith positive (+) settings, the sound will move toward the right as you play higher notes. With negative (-) settings, the sound will move toward the left as you play higher notes.");
	setupParameter("Random Pan Switch", 0x79, 0, 127, 0, randomPanSwitchStrings, "This setting causes the stereo location to change randomly each time a note is played.\r\nThe Tone Pan setting will be ignored by Tones for which the Random Pan Switch is turned on.");	// TODO: make sure if slider only uses 0 and 63 correctly (set interval, max, after setting parameter!)
	setupParameter("Alternate Pan Depth", 0x7A, 0, 127, 0x40, panPosStrings, "This parameter causes the stereo location of the sound to alternate between left and right each time a note is played. When this parameter is set in the L direction, the sound will alternate in the order of left -> right-> left-> right. When set in the R direction, the sound will alternate in the order of right -> left-> right-> left.\r\n"
		"Higher settings will cause greater change.\r\n"
		"By using two tones and setting the Alternate Pan Depth of one to \"L63\" and of the other to \"R63\", you can make the two tones switch places alternately.");
	setupParameter("Pan LFO1 Depth", 0x7B, 0, 126, 63, modulationDepthStrings, "Adjusts the effect that the LFO will have on pan (stereo location).\r\n As this value is increased in the positive(+) direction, the LFO will have a greater effect on pan.Negative(-) settings will invert the LFO waveform, causing the pan to change in the opposite direction.");
	setupParameter("Pan LFO2 Depth", 0x7C, 0, 126, 63, modulationDepthStrings, "Adjusts the effect that the LFO will have on pan (stereo location).\r\n As this value is increased in the positive(+) direction, the LFO will have a greater effect on pan.Negative(-) settings will invert the LFO waveform, causing the pan to change in the opposite direction.");

	setupParameter("Reserved", 0x7D, 0, 3, 0, StringArray(), "JV-2080 Patch Tone Output Assign");
	setupParameter("Reserved", 0x7E, 0, 127, 0x7F, StringArray(), "JV-2080 Patch Tone Mix/EFX Send Level");
	setupParameter("Reserved", 0x7F, 0, 127, 0x40, StringArray(), "JV-2080 Patch Tone Chorus Send Level");
	setupParameter("Reserved", 0x80, 0, 127, 0x40, StringArray(), "JV-2080 Patch Tone Reverb Send Level");
}

// ----------------------------------------------------------------------------

PatchPartBlock::PatchPartBlock(SynthParts part) :
	GrooveboxMemoryBlock(0x02000000 | ((uint32)part << 16), "Patches for Part " + String((uint8)part + 1), "1-3"),
	m_part(part)
{
	m_name = "Patch Part " + String((uint8)m_part + 1);
	addSubBlock(new PatchCommonBlock(part));
	addSubBlock(new PatchToneBlock(part, Tone1));
	addSubBlock(new PatchToneBlock(part, Tone2));
	addSubBlock(new PatchToneBlock(part, Tone3));
	addSubBlock(new PatchToneBlock(part, Tone4));
}

PatchToneBlock* PatchPartBlock::getPatchToneBlockPtr(Tone tone)
{
	switch (tone)
	{
	case Tone1: return dynamic_cast<PatchToneBlock*> (getSubBlock(1));
	case Tone2: return dynamic_cast<PatchToneBlock*> (getSubBlock(2));
	case Tone3: return dynamic_cast<PatchToneBlock*> (getSubBlock(3));
	case Tone4: return dynamic_cast<PatchToneBlock*> (getSubBlock(4));
	default: return nullptr;
	}
}

// ----------------------------------------------------------------------------

SynthPatchesBlock::SynthPatchesBlock() :
	GrooveboxMemoryBlock(0x02000000, "Patches for Part 1 to 7")
{
	m_name = "Patches Part 1-7";
	addSubBlock(new PatchPartBlock(SynthPart1));
	addSubBlock(new PatchPartBlock(SynthPart2));
	addSubBlock(new PatchPartBlock(SynthPart3));
	addSubBlock(new PatchPartBlock(SynthPart4));
	addSubBlock(new PatchPartBlock(SynthPart5));
	addSubBlock(new PatchPartBlock(SynthPart6));
	addSubBlock(new PatchPartBlock(SynthPart7));
}

PatchPartBlock* SynthPatchesBlock::getPatchPartBlockPtr(SynthParts part)
{
	switch (part)
	{
	case SynthPart1: return dynamic_cast<PatchPartBlock*> (getSubBlock(0));
	case SynthPart2: return dynamic_cast<PatchPartBlock*> (getSubBlock(1));
	case SynthPart3: return dynamic_cast<PatchPartBlock*> (getSubBlock(2));
	case SynthPart4: return dynamic_cast<PatchPartBlock*> (getSubBlock(3));
	case SynthPart5: return dynamic_cast<PatchPartBlock*> (getSubBlock(4));
	case SynthPart6: return dynamic_cast<PatchPartBlock*> (getSubBlock(5));
	case SynthPart7: return dynamic_cast<PatchPartBlock*> (getSubBlock(6));
	default: return nullptr;
	}
}

// ----------------------------------------------------------------------------
