/*
  ==============================================================================

    RhythmSetBlock.cpp
    Created: 18 Mar 2016 9:58:19am
    Author:  Spindler

  ==============================================================================
*/

#include "RhythmSetBlock.h"

RhythmCommonBlock::RhythmCommonBlock() :
	GrooveboxMemoryBlock(0x02090000, "Rhythm Set Name", "1-4-1", 0x0C)
{
	m_name = "Rhythm Common";

	StringArray asciiCharacters;
	asciiCharacters.add(" ");
	asciiCharacters.addTokens("! \" # $ % & ' ( ) * + , - . / 0 1 2 3 4 5 6 7 8 9 : ; < = > ? @ A B C D E F G H I J K L M N O P Q R S T U V W X Y Z [ \\ ] ^ _ ` a b c d e f g h i j k l m n o p q r s t u v w x y z { | }", false);

	setupParameter("Rhythm Name  1", 0x00, 32, 125, 'I', asciiCharacters, "Name assigned to the patch.");
	setupParameter("Rhythm Name  2", 0x01, 32, 125, 'n', asciiCharacters, "Name assigned to the patch.");
	setupParameter("Rhythm Name  3", 0x02, 32, 125, 'i', asciiCharacters, "Name assigned to the patch.");
	setupParameter("Rhythm Name  4", 0x03, 32, 125, 't', asciiCharacters, "Name assigned to the patch.");
	setupParameter("Rhythm Name  5", 0x04, 32, 125, 32, asciiCharacters, "Name assigned to the patch.");
	setupParameter("Rhythm Name  6", 0x05, 32, 125, 'R', asciiCharacters, "Name assigned to the patch.");
	setupParameter("Rhythm Name  7", 0x06, 32, 125, 'h', asciiCharacters, "Name assigned to the patch.");
	setupParameter("Rhythm Name  8", 0x07, 32, 125, 'y', asciiCharacters, "Name assigned to the patch.");
	setupParameter("Rhythm Name  9", 0x08, 32, 125, 32, asciiCharacters, "Name assigned to the patch.");
	setupParameter("Rhythm Name 10", 0x09, 32, 125, 'S', asciiCharacters, "Name assigned to the patch.");
	setupParameter("Rhythm Name 11", 0x0A, 32, 125, 'e', asciiCharacters, "Name assigned to the patch.");
	setupParameter("Rhythm Name 12", 0x0B, 32, 125, 't', asciiCharacters, "Name assigned to the patch.");
}

String RhythmCommonBlock::getRhythmSetName()
{
	return String((char*)m_data.getData(), 12);
}

void RhythmCommonBlock::setRhytmSetName(String rhythmSetName)
{
	for (int i = 0; i < 12 && i < rhythmSetName.length(); i++)
	{
		char c = (char)rhythmSetName[i];
		if (c < 32 || c>125) c = 32;	// fallback to space
		m_data[i] = c;
	}
}


	// key must be of 35=0x23..98=0x62 (64 keys)
RhythmNoteBlock::RhythmNoteBlock(uint8 key) :
	GrooveboxMemoryBlock(0x02090000 | (key << 8), "Rhythm Note for Key " + String(key), "1-4-2", 0x3a),
	m_key(key)
{
	m_name = "Rhythm Note";

	StringArray switchOnOffStrings(StringArray::fromTokens("OFF ON", false));
	StringArray waveGroupIdsStrings(StringArray::fromTokens("Reserved;Group A;Group B;Group C", ";", String()));
	StringArray waveGainStrings(StringArray::fromTokens(" -6dB;  0dB; +6dB;+12dB", ";", String()));
	StringArray bendRangeStrings;
	for (int i = 0; i <= 12; i++) bendRangeStrings.add(String(CharPointer_UTF8("\xc2\xb1")) + String(i)); // +/-
	setupParameter("Tone Switch", 0x00, 0, 1, 1, switchOnOffStrings, "Turn this \"ON\" if you want the tone to sound, or \"OFF\" if you do not want the tone to sound.");
	setupParameter("Wave Group Type", 0x01, 0, 0, 0, StringArray::fromTokens("0", false));
	setupParameter("Wave Group ID", 0x02, 1, 3, 1, waveGroupIdsStrings);
	setupParameter("Wave Number", 0x03, 0, 254, 202);
	setupParameter("Wave Gain", 0x05, 0, 3, 1, waveGainStrings, "This boosts the waveform. Raising this setting 6 dB will double the gain.");
	setupParameter("Bend Range", 0x06, 0, 12, 0, bendRangeStrings, "Specifies the amount of pitch change (in semitone units) that will occur when the pitch bend lever of an external MIDI device is operated.\r\n"
		"Higher settings will result in a greater pitch change when the pitch bend lever is moved to the left or right.\r\n"
		"For example, if Bend Range Up is set to \"+12\" the pitch will rise one octave when the pitch bend lever is moved to the right - most position.");
	setupParameter("Mute Group", 0x07, 0, 31, 0, StringArray::fromTokens(" 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31",false), "The Mute Group function lets you prevent percussion instruments in the same mute group from sounding simultaneously.\r\n"
		"If you are not using the mute group function, set this OFF.\r\n"
		"For example, on an acoustic drum set, it is physically impossible for the open hi-hat sound to be heard at the same time as the closed hi-hat sound. To simulate this, you can specify the same mute group number for both hi-hat sounds.");
	setupParameter("Envelope Mode", 0x08, 0, 1, 0, StringArray::fromTokens("NO-SUS SUSTAIN", false), "Specifies how the sound will play when a sustained-type waveform such as a whistle (a looped waveform) is selected. Range:\r\n"
		"NO-SUS: The sound will decay naturally even if you continue holding the keyboard pad.\r\n"
		"SUSTAIN: The sound will continue as long as the keyboard pad is pressed\r\n"
		"If a waveform with a long decay (one-shot waveform) is selected, setting this parameter to SUSTAIN will have no effect.");

	setupParameter("Reserved", 0x09, 0, 1, 1, StringArray(), "JV-2080 Rhythm Note Volume Control Switch");
	setupParameter("Reserved", 0x0A, 0, 1, 1, StringArray(), "JV-2080 Rhythm Note Hold-1 Control Switch");
	setupParameter("Reserved", 0x0B, 0, 2, 1, StringArray(), "JV-2080 Rhythm Note Pan Control Switch");

	StringArray coarseTuneStrings; for (int i = -60; i <= 60; i++)
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
	StringArray randomPitchFactors(StringArray::fromTokens("0 1 2 3 4 5 6 7 8 9 10 20 30 40 50 60 70 80 90 100 200 300 400 500 600 700 800 900 1000 1100 1200", false));
	StringArray pitchEnvelopeDepthStrings; for (int i = -12; i <= 12; i++)
	{
		if (i<0) pitchEnvelopeDepthStrings.add("-" + String(-i));
		else if (i == 0) pitchEnvelopeDepthStrings.add(String(i));
		else if (i>0) pitchEnvelopeDepthStrings.add("+" + String(i));
	}
	StringArray veloSensFactors(StringArray::fromTokens("-100; -98; -96; -94; -92; -90; -88; -86; -84; -82; -80; -78; -76; -74; -72; -70; -68; -66; -64; -62; -60; -58; -56; -54; -52; -50; -48; -46; -44; -42; -40; -38; -36; -34; -32; -30; -28; -26; -24; -22; -20; -18; -16; -14; -12; -10;  -8;  -6;  -4;  -2;   0;  +2;  +4;  +6;  +8; +10; +12; +14; +16; +18; +20; +22; +24; +26; +28; +30; +32; +34; +36; +38; +40; +42; +44; +46; +48; +50; +52; +54; +56; +58; +60; +62; +64; +66; +68; +70; +72; +74; +76; +78; +80; +82; +84; +86; +88; +90; +92; +94; +96; +98;+100;+102;+104;+106;+108;+110;+112;+114;+116;+118;+120;+122;+124;+126;+128;+130;+132;+134;+136;+138;+140;+142;+144;+146;+148;+150", ";", String()));
	StringArray veloTimeFactorsAndEnvKeyFollow(StringArray::fromTokens("-100, -70, -50, -40, -30, -20, -10,   0, +10, +20, +30, +40, +50, +70,+100", ",", String()));
	StringArray modulationDepthStrings; for (int i = -63; i <= 63; i++)
	{
		if (i<0) modulationDepthStrings.add("-" + String(-i));
		else if (i == 0) modulationDepthStrings.add(String(i));
		else if (i>0) modulationDepthStrings.add("+" + String(i));
	}
	setupParameter("Coarse Tune", 0x0C, 0, 120, 0x44, coarseTuneStrings, "Adjust the pitch of each tone in semitone steps. Higher settings will raise the pitch. Lower settings will lower the pitch.");
	setupParameter("Fine Tune", 0x0D, 0, 100, 50, fineTuneStrings, "You can adjust the pitch of each tone in 1-cent steps (1/000th of a semitone).\r\nThe greater the value, the higher the pitch, and the smaller value, the lower the pitch.");
	setupParameter("Random Pitch Depth", 0x0E, 0, 30, 0, randomPitchFactors, "This applies a degree of randomness to the pitch of each note. As this value is increased, a greater degree of randomness will be applied. As this value is decreased, there will be less randomness.\r\nWith a value of \"0\" there will be no effect.");

	setupParameter("Pitch Envelope Depth", 0x0F, 0, 24, 12, pitchEnvelopeDepthStrings, "Here's how you can adjust the depth of the Pitch Envelope. Increasingly positive (+) settings will produce a greater width of pitch change. Negative (-) settings will invert the shape of the envelope, causing the pitch to change in the opposite direction.");
	setupParameter("Pitch Envelope Velocity Sens", 0x10, 0, 125, 50, veloSensFactors, "This setting lets you control the Pitch Envelope depth by the velocity.\r\n"
		"With positive (+) settings, the pitch will change more greatly as you play the keyboard more strongly. With negative (-) settings, the pitch will change less as you play the keyboard more strongly.\r\n"
		"When TIME is set to a positive (+) value, softly-played notes will have little pitch change, and strongly-played notes will have greater pitch change;\r\n"
		"this lets you simulate \"the pitch instability at the beginning of each note\" that is characteristic of wind instruments.");
	setupParameter("Pitch Envelope Velocity Time", 0x11, 0, 14, 7, veloTimeFactorsAndEnvKeyFollow, "The strength with which a keyboard key on an external MIDI keyboard is pressed is used to control TIME 1.\r\n"
		"With positive (+) settings, TIME1 will become faster as you play the keyboard more strongly. With negative (-) settings, TIME1 will become slower as you play the keyboard more strongly.\r\n"
		"When Velocity TIME Sensitivity is set to a positive value, the pitch will change slowly for softly-played notes, and rapidly for strongly-played notes.");
	setupParameter("Pitch Envelope Time 1", 0x12, 0, 127, 0, StringArray(), "Specifies the time until the next pitch level is reached.\r\nHigher settings will result in a longer time until the next pitch level is reached.");
	setupParameter("Pitch Envelope Time 2", 0x13, 0, 127, 0, StringArray(), "Specifies the time until the next pitch level is reached.\r\nHigher settings will result in a longer time until the next pitch level is reached.");
	setupParameter("Pitch Envelope Time 3", 0x14, 0, 127, 0, StringArray(), "Specifies the time until the next pitch level is reached.\r\nHigher settings will result in a longer time until the next pitch level is reached.");
	setupParameter("Pitch Envelope Time 4", 0x15, 0, 127, 0, StringArray(), "Specifies the time until the next pitch level is reached.\r\nHigher settings will result in a longer time until the next pitch level is reached.");
	setupParameter("Pitch Envelope Level 1", 0x16, 0, 126, 63, modulationDepthStrings, "Specifies the pitch difference relative to the normal pitch (as specified by Coarse Tune and Fine Tune).\r\nPositive (+) settings will raise the pitch above the normal pitch. Negative (-) settings will make the pitch lower than the normal pitch.");
	setupParameter("Pitch Envelope Level 2", 0x17, 0, 126, 63, modulationDepthStrings, "Specifies the pitch difference relative to the normal pitch (as specified by Coarse Tune and Fine Tune).\r\nPositive (+) settings will raise the pitch above the normal pitch. Negative (-) settings will make the pitch lower than the normal pitch.");
	setupParameter("Pitch Envelope Level 3", 0x18, 0, 126, 63, modulationDepthStrings, "Specifies the pitch difference relative to the normal pitch (as specified by Coarse Tune and Fine Tune).\r\nPositive (+) settings will raise the pitch above the normal pitch. Negative (-) settings will make the pitch lower than the normal pitch.");
	setupParameter("Pitch Envelope Level 4", 0x19, 0, 126, 63, modulationDepthStrings, "Specifies the pitch difference relative to the normal pitch (as specified by Coarse Tune and Fine Tune).\r\nPositive (+) settings will raise the pitch above the normal pitch. Negative (-) settings will make the pitch lower than the normal pitch.");

	StringArray filterTypes(StringArray::fromTokens("OFF LPF BPF HPF PKG", false));
	setupParameter("Filter Type", 0x1A, 0, 4, 1, filterTypes, "- OFF: The filter will not be applied.\r\n"
		"- LPF (Low Pass Filter): This type of filter is most commonly used and allows audio signals with frequencies lower than the cutoff frequency to pass through. It is used to make the sound more mellow.\r\n"
		"- BPF (Band Pass Filter): This filter cuts off all audio signals except for those with frequencies around the cutoff frequency.\r\n"
		"- HPF (High Pass Filter): This filter allows audio signals with frequencies exceeding the cutoff frequency to pass. It is effectively used to make sounds brighter and sharper.\r\n"
		"- PKG (Peaking Filter): This filter enhances audio signals with frequencies around the cutoff frequency. It will emphasize the midrange, and is useful for creating a distinctive sound.\r\n");
	setupParameter("Cutoff Frequency", 0x1B, 0, 127, 127, StringArray(), "Specifies the frequency at which the filter will begin to affect the frequency components of the waveform (the Cutoff Frequency). By changing the cutoff frequency, you can control the brightness of the sound. The effect will depend on the Filter Type.\r\n"
		"- LPF (Low Pass Filter): Increasing the value will brighten the sound, making it more similar to the original waveform, approaching the  original waveform. Lower settings will cut more of the high frequency overtones, making the sound darker. For some waveforms, you may not be able to hear any sound if you lower the value too far.\r\n"
		"- BPF (Band Pass Filter): Higher settings will raise the frequency area that is heard. Lower settings will cause only a progressively lower frequency area to be heard.\r\n"
		"- HPF (High Pass Filter): As this value is increased, the low frequency range will be cut more greatly, making the sound sharper. As this value is decreased, the original sound of the waveform will be heard. For some waveforms, you may hear no sound if this value is raised excessively.\r\n"
		"- PKG (Peaking Filter): As this value is increased, the frequency area that is emphasized will rise. As this value is decreased, the frequency area that is emphasized will fall.");
	setupParameter("Resonance", 0x1C, 0, 127, 0, StringArray(), "Adding a Distinctive Character to the Sound (Resonance). This setting emphasizes the overtones in the region of the cutoff frequency, adding character to the sound.\r\n"
		"As this value is increased, the sound will have more character. As this value is decreased, the sound will be more natural.\r\n"
		"In order to prevent the resonance from being increased excessively, factory settings have been made so that the value will not rise beyond \"110\" even if the [RESONANCE] knob is rotated all the way to the right. This is called the Resonance Limiter. You are free to adjust this upper limit.\r\n"
		"If you have increased the Resonance Limiter setting, be careful not to raise the resonance excessively. Excessively high values may cause sounds to be distorted or the volume level to become unexpectedly high. Some settings may damage your hearing, or your speakers. Please use caution.");
	setupParameter("Resonance Velocity Sens", 0x1D, 0, 125, 50, veloSensFactors, "Specifies how resonance depth will be affected by your playing velocity.\r\nWith positive (+) settings, playing the keyboard more strongly will cause the change to be greater. With negative (-) settings, playing the keyboard more strongly will cause the change to be less.");

	setupParameter("Filter Envelope Depth", 0x1E, 0, 126, 63, modulationDepthStrings, "This setting adjusts the depth of the filter envelope. As the value is increased in the positive(+) direction, the amount of tonal change will increase. With negative(-) settings, the shape of the envelope will be inverted, and the tone will change in the opposite direction.\r\nWhen setting Envelope Depth to a positive(+) value, the effect of the filter envelope will be easier to hear if you set a lower cutoff frequency.");
	setupParameter("Filter Envelope Velocity Sens", 0x1F, 0, 125, 50, veloSensFactors, "Specifies how the force of your playing on the external MIDI keyboard will affect the filter envelope.\r\n"
		"With positive (+) settings, the tone will change more as you play more strongly on the keyboard. With negative (-) settings, the tone will change less as you play more strongly on the keyboard.\r\n"
		"With positive (+) settings of TIME, the sound will be brighter for strongly-played notes, and darker for softly-played notes.");
	setupParameter("Filter Envelope Velocity Time", 0x20, 0, 14, 7, veloTimeFactorsAndEnvKeyFollow, "This parameter lets your playing dynamics on the external MIDI keyboard control the overall time of the entire envelope.\r\n"
		"With positive (+) settings, TIME1 will become faster as you play the keyboard more strongly. With negative (-) settings, TIME1 will become slower as you play the keyboard more strongly.");
	setupParameter("Filter Envelope Time 1", 0x21, 0, 127, 0, StringArray(), "Specifies the time until the next cutoff frequency is reached.\r\nHigher settings will lengthen the time until the next cutoff frequency is reached.");
	setupParameter("Filter Envelope Time 2", 0x22, 0, 127, 0, StringArray(), "Specifies the time until the next cutoff frequency is reached.\r\nHigher settings will lengthen the time until the next cutoff frequency is reached.");
	setupParameter("Filter Envelope Time 3", 0x23, 0, 127, 0, StringArray(), "Specifies the time until the next cutoff frequency is reached.\r\nHigher settings will lengthen the time until the next cutoff frequency is reached.");
	setupParameter("Filter Envelope Time 4", 0x24, 0, 127, 0, StringArray(), "Specifies the time until the next cutoff frequency is reached.\r\nHigher settings will lengthen the time until the next cutoff frequency is reached.");
	setupParameter("Filter Envelope Level 1", 0x25, 0, 127, 127, StringArray(), "Specifies the cutoff frequency at each level.\r\nRaising this setting will also raise the cutoff frequency.");
	setupParameter("Filter Envelope Level 2", 0x26, 0, 127, 127, StringArray(), "Specifies the cutoff frequency at each level.\r\nRaising this setting will also raise the cutoff frequency.");
	setupParameter("Filter Envelope Level 3", 0x27, 0, 127, 127, StringArray(), "Specifies the cutoff frequency at each level.\r\nRaising this setting will also raise the cutoff frequency.");
	setupParameter("Filter Envelope Level 4", 0x28, 0, 127, 127, StringArray(), "Specifies the cutoff frequency at each level.\r\nRaising this setting will also raise the cutoff frequency.");

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
	setupParameter("Tone Level", 0x29, 0, 127, 127, StringArray(), "This setting adjusts the volume of each tone. This is used mainly to adjust the volume balance between tones.");
	setupParameter("Amp Envelope Velocity Sens", 0x2A, 0, 125, 0x64, veloSensFactors, "Specifies how the depth of the amplifier envelope will be affected by the strength of your playing velocity.\r\n"
		"If velocity sensitivity is set to a positive (+) value, the volume will be loud when you play strongly and soft when you play softly. As this value is increased, the volume difference between strongly played and softly played notes will gradually increase.\r\n"
		"With positive (+) settings, the volume will increase as you play more strongly on the keyboard. With negative (-) settings, the volume will decrease as you play more strongly on the keyboard. If this is set to \"0\", the volume will not be affected by the strength of your playing on the keyboard.");
	setupParameter("Amp Envelope Velocity Time", 0x2B, 0, 14, 7, veloTimeFactorsAndEnvKeyFollow, "Specifies how the dynamics of your playing will affect TIME1-4.\r\n"
		"Specifies the time until the next level is reached. You can make settings for the four parameters TIME 1-4."
		"With positive (+) settings, time will become faster as you play the keyboard more strongly. With negative (-) settings, time will become slower as you play the keyboard more strongly.");
	setupParameter("Amp Envelope Time 1", 0x2C, 0, 127, 0, StringArray(), "Specifies the time until the next level point is reached.\r\nHigher settings will lengthen the time until the next level point is reached.");
	setupParameter("Amp Envelope Time 2", 0x2D, 0, 127, 0, StringArray(), "Specifies the time until the next level point is reached.\r\nHigher settings will lengthen the time until the next level point is reached.");
	setupParameter("Amp Envelope Time 3", 0x2E, 0, 127, 4, StringArray(), "Specifies the time until the next level point is reached.\r\nHigher settings will lengthen the time until the next level point is reached.");
	setupParameter("Amp Envelope Time 4", 0x2F, 0, 127, 127, StringArray(), "Specifies the time until the next level point is reached.\r\nHigher settings will lengthen the time until the next level point is reached.");
	setupParameter("Amp Envelope Level 1", 0x30, 0, 127, 127, StringArray(), "Specifies the volume at each point. Higher settings will also raise the volume.");
	setupParameter("Amp Envelope Level 2", 0x31, 0, 127, 127, StringArray(), "Specifies the volume at each point. Higher settings will also raise the volume.");
	setupParameter("Amp Envelope Level 3", 0x32, 0, 127, 0x7A, StringArray(), "Specifies the volume at each point. Higher settings will also raise the volume.");
	setupParameter("Tone Pan", 0x33, 0, 127, 64, panPosStrings, "This parameter sets the stereo location for each tone.\r\nThe pan of the overall patch can be modified and set for each pattern by the Setup parameter Part Pan. The Tone Pan value will be added to this setting.");
	setupParameter("Random Pan Switch", 0x34, 0, 127, 0, randomPanSwitchStrings, "This setting causes the stereo location to change randomly each time a note is played.\r\nThe Tone Pan setting will be ignored by Tones for which the Random Pan Switch is turned on.");	// TODO: make sure if slider only uses 0 and 63 correctly (set interval, max, after setting parameter!)
	setupParameter("Alternate Pan Depth", 0x35, 0, 127, 0x40, panPosStrings, "This parameter causes the stereo location of the sound to alternate between left and right each time a note is played. When this parameter is set in the L direction, the sound will alternate in the order of left -> right-> left-> right. When set in the R direction, the sound will alternate in the order of right -> left-> right-> left.\r\n"
		"Higher settings will cause greater change.\r\n");

	setupParameter("M-FX Switch", 0x36, 0, 3, 0, StringArray::fromTokens("OFF,ON, , ", ",", ""), "This switch is used to specify M-FX on/off for each rhythm tone.\r\n"
		"OFF: Sounds are output from the OUTPUT jacks without any M-FX effect applied.\r\n"
		"ON: Sounds are output from the OUTPUT jacks with M-FX effects applied.\r\n"
		"The RHYTHM TONE M-FX switch can only be activated when the PART M-FX switch for the rhythm part is set to \"RHY.\"\r\n"
		"If the PART M-FX switch for the rhythm part is set to ON, M-FX effects are applied to all rhythm tones regardless of the setting of the RHYTHM TONE M-FX switch.");

	setupParameter("Reserved", 0x37, 0, 127, 127, StringArray(), "JV-2080 Rhythm Note Mix/EFX Send Level");

	setupParameter("Delay Send Level", 0x38, 0, 127, 0, StringArray(), "Specifies the reverb volume for each rhythm tone. Higher settings will increase the reverb volume.\r\n"
		"The Rhythm Tone Reverb Level setting is valid only if the Part M-FX SW setting of the rhythm part is set to \"RHY\".Also in this case, if the Reverb Level and the Part Reverb Level setting of the rhythm part are low, there will be no reverb even if the Rhythm Tone Reverb Level is raised.");
	setupParameter("Reverb Send Level", 0x39, 0, 127, 127, StringArray(), "Specifies the amount of delay for each rhythm tone. Higher settings will increase the delay volume.\r\n"
		"The Rhythm Tone Delay Level setting is valid only when the Part M-FX SW setting of the rhythm part is set to \"RHY\". Also in this case, if the Delay Level and the Part Delay Level setting of the rhythm part are low, there will be no delay even if the Rhythm Tone Delay Level is raised.");
}

/*static */const RhythmGroup RhythmNoteBlock::getRhythmGroup(uint8 key)
{
	RhythmGroup rhyGroup = RhythmGroup::UNKNOWN;
	if ((key >= 35 && key <= 36) || (key >= 47 && key <= 48) || (key >= 95 && key <= 96)) rhyGroup = RhythmGroup::BD;
	else if (key == 38 || key == 40 || key == 50 || key == 52 || key == 97 || key == 98) rhyGroup = RhythmGroup::SD;
	else if (key == 39 || key == 51 || key == 94) rhyGroup = RhythmGroup::CLP;
	else if (key == 42 || key == 42 || key == 44 || key == 46 || key == 54 || key == 56 || key == 58) rhyGroup = RhythmGroup::HH;
	else if (key == 61 || key == 63 || key == 64 || key == 65 || key == 67 || key == 69 || key == 71) rhyGroup = RhythmGroup::CYM;
	else if (key == 37 || key == 41 || key == 43 || key == 45 || key == 41 || key == 49 || key == 41 || key == 53 || key == 55 || key == 57 || key == 59 || key == 60 || key == 62 || key == 66 || key == 68 || key == 70 || (key >= 72 && key <= 82)) rhyGroup = RhythmGroup::TOM_PERC;
	else if (key >= 83 && key <= 88) rhyGroup = RhythmGroup::HIT;
	else if (key >= 89 && key <= 93) rhyGroup = RhythmGroup::OTHERS;
	return rhyGroup;
}

/*static*/ const String RhythmNoteBlock::getRhythmGroupString(RhythmGroup rhythmGroup)
{
	switch (rhythmGroup)
	{
	case RhythmGroup::BD:
		return "BD";
	case RhythmGroup::SD:
		return "SD";
	case RhythmGroup::HH:
		return "HH";
	case RhythmGroup::CLP:
		return "CLP";
	case RhythmGroup::CYM:
		return "CYM";
	case RhythmGroup::TOM_PERC:
		return"TOM/PERC";
	case RhythmGroup::HIT:
		return "HIT";
	case RhythmGroup::OTHERS:
		return "OTHERS";
	case RhythmGroup::ALL:
		return "ALL";
	case RhythmGroup::UNKNOWN:
	default:
		return "Unknown";
	}
}


RhythmSetBlock::RhythmSetBlock() :
	GrooveboxMemoryBlock(0x02090000, "Rhythm Set", "1-4")
{
	m_name = "Rhythm Setup";
	addSubBlock(new RhythmCommonBlock());
	// add address blocks for 64 keys
	for (uint8 i = 35; i <= 98; i++)
	{
		addSubBlock(new RhythmNoteBlock(i));
	}
}

	// key must be of 35..98 (64 keys)
RhythmNoteBlock* RhythmSetBlock::getRhythmNoteBlockPtr(uint8 key)
{
	return dynamic_cast<RhythmNoteBlock*>(getSubBlock(key - 35 + 1));
}

RhythmCommonBlock* RhythmSetBlock::getRhythmSetCommonBlockPtr()
{
	return dynamic_cast<RhythmCommonBlock*>(getSubBlock(0));
}
