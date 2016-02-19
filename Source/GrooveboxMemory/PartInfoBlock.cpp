/*
  ==============================================================================

    PartInfoBlock.cpp
    Created: 10 Nov 2014 7:46:26pm
    Author:  Martin

  ==============================================================================
*/

#include "PartInfoBlock.h"

// ----------------------------------------------------------------------------

// TODO: Voice Reserve in Pattern Setup also?
PartInfoCommonBlock::PartInfoCommonBlock() :
	GrooveboxMemoryBlock(0x01000000, "Effects Setup, Voice Reserve", "1-2-1", 0x44),
	m_EffectDescription(String::empty)
{
	m_name = "Part Info Common";
	
	StringArray asciiCharacters;
	asciiCharacters.add(" ");
	asciiCharacters.addTokens("! \" # $ % & ' ( ) * + , - . / 0 1 2 3 4 5 6 7 8 9 : ; < = > ? @ A B C D E F G H I J K L M N O P Q R S T U V W X Y Z [ \\ ] ^ _ ` a b c d e f g h i j k l m n o p q r s t u v w x y z { | }", false);
	setupParameter("Reserved", 0x00, 32, 125, 'S', asciiCharacters, "JV-2080 Performance Name 1");
	setupParameter("Reserved", 0x01, 32, 125, 'e', asciiCharacters, "JV-2080 Performance Name 2");
	setupParameter("Reserved", 0x02, 32, 125, 'q', asciiCharacters, "JV-2080 Performance Name 3");
	setupParameter("Reserved", 0x03, 32, 125, ':', asciiCharacters, "JV-2080 Performance Name 4");
	setupParameter("Reserved", 0x04, 32, 125, 'T', asciiCharacters, "JV-2080 Performance Name 5");
	setupParameter("Reserved", 0x05, 32, 125, 'e', asciiCharacters, "JV-2080 Performance Name 6");
	setupParameter("Reserved", 0x06, 32, 125, 'm', asciiCharacters, "JV-2080 Performance Name 7");
	setupParameter("Reserved", 0x07, 32, 125, 'p', asciiCharacters, "JV-2080 Performance Name 8");
	setupParameter("Reserved", 0x08, 32, 125, 'l', asciiCharacters, "JV-2080 Performance Name 9");
	setupParameter("Reserved", 0x09, 32, 125, 'a', asciiCharacters, "JV-2080 Performance Name 10");
	setupParameter("Reserved", 0x0A, 32, 125, 't', asciiCharacters, "JV-2080 Performance Name 11");
	setupParameter("Reserved", 0x0B, 32, 125, 'e', asciiCharacters, "JV-2080 Performance Name 12");

	StringArray jv2080EfxSources = StringArray::fromTokens("PERFORM	1 2 3 4 5 6 7 8 9 11 12 13 14 15 16", false);
	setupParameter("Reserved", 0x0C, 0, 15, 0, jv2080EfxSources, "JV-2080 Performance EFX-A Source");

	StringArray mFxTypeNameStrings(StringArray::fromTokens("4BAND EQ,SPECTRUM,ENHANCER,OVERDRIVE,DISTORTION,LO-FI,NOISE,RADIO TUING,PHONOGRAPH,COMPRESSOR,LIMITER,SLICER,TREMOLO,PHASER,CHORUS,SPACE-D,TETRA CHORUS,FLANGER,STEP FLANGER,SHORT DELAY,AUTO PAN,FB PITCH SHIFTER,REVERB,GATE REVERB,ISOLATOR", ",", String::empty));
	setupParameter("M-FX Type", 0x0D, 0, 24, 0, mFxTypeNameStrings, "Multi-Effects Type");
	setupParameter("M-FX Parameter 1", 0x0E, 0, 127, 0);	// set by refreshParametersForMFXTypeValue
	setupParameter("M-FX Parameter 2", 0x0F, 0, 127, 15);
	setupParameter("M-FX Parameter 3", 0x10, 0, 127, 0);
	setupParameter("M-FX Parameter 4", 0x11, 0, 127, 15);
	setupParameter("M-FX Parameter 5", 0x12, 0, 127, 7);
	setupParameter("M-FX Parameter 6", 0x13, 0, 127, 1);
	setupParameter("M-FX Parameter 7", 0x14, 0, 127, 15);
	setupParameter("M-FX Parameter 8", 0x15, 0, 127, 7);
	setupParameter("M-FX Parameter 9", 0x16, 0, 127, 1);
	setupParameter("M-FX Parameter 10", 0x17, 0, 127, 15);
	setupParameter("M-FX Parameter 11", 0x18, 0, 127, 127);
	setupParameter("M-FX Parameter 12", 0x19, 0, 127);

	setupParameter("Reserved", 0x1A, 0, 2, 0, StringArray::fromTokens("MIX DIR1 DIR2", false), "JV-2080 Performance EFX Output Assign");
	setupParameter("Reserved", 0x1B, 0, 127, 127, StringArray(), "JV-2080 Performance EFX Mix Out Send Level");

	setupParameter("M-FX Delay Send Level", 0x1C, 0, 127, 20, StringArray(), "Applies the Delay equally to each of the parts with Multieffects set at ON regardless of the Part Delay Level for each part.");
	setupParameter("M-FX Reverb Send Level", 0x1D, 0, 127, 20, StringArray(), "Applies reverb equally to each of the parts with Multi-effects set at ON regardless of the Part Reverb Level for each part.");

	StringArray modulationDepthStrings; for (int i = -63; i <= 63; i++)
	{
		if (i<0) modulationDepthStrings.add("-" + String(-i));
		else if (i == 0) modulationDepthStrings.add(String(i));
		else if (i>0) modulationDepthStrings.add("+" + String(i));
	}
	setupParameter("Reserved", 0x1E, 0, 10, 0, StringArray::fromTokens("OFF SYS-CTRL1 SYS-CTRL2 MODULATION BREATH FOOT VOLUME PAN EXPRESSION PITCHBEND AFTERTOUCH", false), "JV-2080 Performance EFX Control Source 1");
	setupParameter("Reserved", 0x1F, 0, 126, 63, modulationDepthStrings, "JV-2080 Performance EFX Control Depth 1");
	setupParameter("Reserved", 0x20, 0, 10, 0, StringArray::fromTokens("OFF SYS-CTRL1 SYS-CTRL2 MODULATION BREATH FOOT VOLUME PAN EXPRESSION PITCHBEND AFTERTOUCH", false), "JV-2080 Performance EFX Control Source 2");
	setupParameter("Reserved", 0x21, 0, 126, 63, modulationDepthStrings, "JV-2080 Performance EFX Control Depth 2");

	StringArray hfFreqStrings(StringArray::fromTokens("200 Hz, 250 Hz, 315 Hz, 400 Hz, 500 Hz, 630 Hz, 800 Hz, 1000 Hz, 1250 Hz, 1600 Hz, 2000 Hz, 2500 Hz, 3150 Hz, 4000 Hz, 5000 Hz, 6300 Hz, 8000 Hz, BYPASS", ",", ""));
	StringArray feedbackPercentageStrings(StringArray::fromTokens("0% +1% +2% +3% +4% +5% +6% +7% +8% +9% +10% +11% +12% +13% +14% +15% +16% +17% +18% +19% +20% +21% +22% +23% +24% +25% +26% +27% +28% +29% +30% +31% +32% +33% +34% +35% +36% +37% +38% +39% +40% +41% +42% +43% +44% +45% +46% +47% +48% +49% +50% +51% +52% +53% +54% +55% +56% +57% +58% +59% +60% +61% +62% +63% +64% +65% +66% +67% +68% +69% +70% +71% +72% +73% +74% +75% +76% +77% +78% +79% +80% +81% +82% +83% +84% +85% +86% +87% +88% +89% +90% +91% +92% +93% +94% +95% +96% +97% +98%", false));
	setupParameter("Delay Master Level", 0x22, 0, 127, 127, StringArray(), "This adjusts the volume of the delay sound for all eight parts (the rhythm part and parts 1-7).");
	setupParameter("Delay Type", 0x23, 0, 1, 1, StringArray::fromTokens("SHORT LONG", false), "- SHORT: A delay which repeats at short intervals.\r\n- LONG: A delay which repeats at long intervals. You can also synchronize the spacing of the repeats to the BPM of the pattern.");
	setupParameter("Delay HF Damp", 0x24, 0, 17, 17, hfFreqStrings, "Specifies the frequency at which the high frequency portions of the delay will be cut.Lowering this setting will cause more of the upper frequency content to be cut, making the delay more muted in tone. If 'BYPASS' is selected, the high frequency range will not be cut.");
	setupParameter("Delay Time", 0x25, 0, 120);		// set by refreshParametersForDelayTypeValue
	setupParameter("Delay Feedback Level", 0x26, 0, 98, 50, feedbackPercentageStrings, "Sets the amount of delayed sound to be repeated, as a proportion of the original sound.");
	setupParameter("Delay Delay Output Assign", 0x27, 0, 2, 2, StringArray::fromTokens("LINE REV LINE+REV", false), "Allows you to select a destination for the sound after delay has been applied. Selecting LINE outputs the sound to the OUTPUT jacks on the rear panel; selecting REV outputs it to Reverb; or selecting LINE + REV outputs the sound to both the OUTPUT jacks and Reverb.");

	setupParameter("Reverb Type", 0x28, 0, 7, 2, StringArray::fromTokens("ROOM1 ROOM2 STAGE1 STAGE2 HALL1 HALL2", false), "- ROOM1: Reverb with short decay and high density.\r\n- ROOM2: Reverb with short decay and low density.\r\n- STAGE1: Reverb with much lingering reverberation.\r\n- STAGE2: Reverb with strong early reflections.\r\n- HALL1: Clear-sounding reverb.\r\n- HALL2: Rich-sounding reverb.\r\n");
	setupParameter("Reverb Master Level", 0x29, 0, 127, 127, StringArray(), "You can adjust the overall volume of reverb for the eight parts(rhythm part and parts 1-7).");
	setupParameter("Reverb Time", 0x2A, 0, 127, 90, StringArray(), "You can adjust the time over which the reverberation will continue.");
	setupParameter("Reverb HF Damp", 0x2B, 0, 17, 13, hfFreqStrings, "Specifies the frequency at which the high frequency portions of the reverberation will be cut.\r\nLowering this setting will cause more of the upper frequency content to be cut, making the reverberation more muted. If 'BYPASS' is selected, the high frequency range will not be cut.");

	setupParameter("Reserved", 0x2C, 0, 127, 0, StringArray(), "JV-2080 Performance Delay Feedback");
	setupParameter("Reserved", 0x2D, 0, 250, 120, StringArray(), "JV-2080 Performance Tempo"); // (0x2D + 0x2E 2 bytes for 8 bit 000aaaa MSB | 000bbbb LSB)
	setupParameter("Reserved", 0x2F, 0, 1, 1, StringArray::fromTokens("OFF ON",false), "JV-2080 Performance Keyboard Range Switch");

	setupParameter("Voice Reserve 1", 0x30, 0, 64, 4, StringArray(), "Specifies the number of notes that will be reserved for part 1 when the total number of requested notes exceeds 64. Voice Reserve settings can be made up to a total of 64 notes for all parts.");
	setupParameter("Voice Reserve 2", 0x31, 0, 64, 4, StringArray(), "Specifies the number of notes that will be reserved for part 2 when the total number of requested notes exceeds 64. Voice Reserve settings can be made up to a total of 64 notes for all parts.");
	setupParameter("Voice Reserve 3", 0x32, 0, 64, 4, StringArray(), "Specifies the number of notes that will be reserved for part 3 when the total number of requested notes exceeds 64. Voice Reserve settings can be made up to a total of 64 notes for all parts.");
	setupParameter("Voice Reserve 4", 0x33, 0, 64, 4, StringArray(), "Specifies the number of notes that will be reserved for part 4 when the total number of requested notes exceeds 64. Voice Reserve settings can be made up to a total of 64 notes for all parts.");
	setupParameter("Voice Reserve 5", 0x34, 0, 64, 4, StringArray(), "Specifies the number of notes that will be reserved for part 5 when the total number of requested notes exceeds 64. Voice Reserve settings can be made up to a total of 64 notes for all parts.");
	setupParameter("Voice Reserve 6", 0x35, 0, 64, 4, StringArray(), "Specifies the number of notes that will be reserved for part 6 when the total number of requested notes exceeds 64. Voice Reserve settings can be made up to a total of 64 notes for all parts.");
	setupParameter("Voice Reserve 7", 0x36, 0, 64, 4, StringArray(), "Specifies the number of notes that will be reserved for part 7 when the total number of requested notes exceeds 64. Voice Reserve settings can be made up to a total of 64 notes for all parts.");
	setupParameter("Reserved", 0x37, 0, 64, 4, StringArray(), "JV-2080 Performance Voice Reserve 8");
	setupParameter("Reserved", 0x38, 0, 64, 4, StringArray(), "JV-2080 Performance Voice Reserve 9");
	setupParameter("Voice Reserve R", 0x39, 0, 64, 4, StringArray(), "Specifies the number of notes that will be reserved for part R when the total number of requested notes exceeds 64. Voice Reserve settings can be made up to a total of 64 notes for all parts.");
	setupParameter("Reserved", 0x3A, 0, 64, 4, StringArray(), "JV-2080 Performance Voice Reserve 11");
	setupParameter("Reserved", 0x3B, 0, 64, 4, StringArray(), "JV-2080 Performance Voice Reserve 12");
	setupParameter("Reserved", 0x3C, 0, 64, 4, StringArray(), "JV-2080 Performance Voice Reserve 13");
	setupParameter("Reserved", 0x3D, 0, 64, 4, StringArray(), "JV-2080 Performance Voice Reserve 14");
	setupParameter("Reserved", 0x3E, 0, 64, 4, StringArray(), "JV-2080 Performance Voice Reserve 15");
	setupParameter("Reserved", 0x3F, 0, 64, 4, StringArray(), "JV-2080 Performance Voice Reserve 16");
	
	setupParameter("Reserved", 0x40, 0, 1, 0, StringArray::fromTokens("LAYER SINGLE",false), "JV-2080 Performance Keyboard Mode");
	setupParameter("Reserved", 0x41, 0, 1, 1, StringArray::fromTokens("PERFORMANCE SYSTEM", false), "JV-2080 Performance Clock Source");
	setupParameter("Reserved", 0x42, 0, 15, 0, jv2080EfxSources, "JV-2080 Performance EFX-B Source");
	setupParameter("Reserved", 0x43, 0, 15, 3, jv2080EfxSources, "JV-2080 Performance EFX-C Source");
}

// typeIndex must by of 0..24
void PartInfoCommonBlock::refreshParametersForMFXTypeValue(uint8 mFXTypeIndex)
{
	// init some common used display values first
	StringArray gainStrings(StringArray::fromTokens("-15,-14,-13,-12,-11,-10,-9,-8,-7,-6,-5,-4,-3,-2,-1,0,+1,+2,+3,+4,+5,+6,+7,+8,+9,+10,+11,+12,+13,+14,+15", ",", ""));
	StringArray peakFrequencyStrings(StringArray::fromTokens("200 Hz,250 Hz,315 Hz,400 Hz,500 Hz,630 Hz,800 Hz,1000 Hz,1250 Hz,1600 Hz,2000 Hz,2500 Hz,3150 Hz,4000 Hz,5000 Hz,6300 Hz,8000 Hz", ",", ""));
	StringArray hpFrequencyStrings(StringArray::fromTokens("200 Hz,250 Hz,315 Hz,400 Hz,500 Hz,630 Hz,800 Hz,1000 Hz,1250 Hz,1600 Hz,2000 Hz,2500 Hz,3150 Hz,4000 Hz,5000 Hz,6300 Hz,8000 Hz, BYPASS", ",", ""));
	StringArray peakQStrings(StringArray::fromTokens("0.5,1.0,2.0,4.0,8.0", ",", ""));
	StringArray panPosStrings;
	for (int i = -64; i <= 63; i++)
	{
		if (i<0) panPosStrings.add("L" + String(-i));
		else if (i == 0) panPosStrings.add(String(i));
		else if (i>0) panPosStrings.add("R" + String(i));
	}
	StringArray slicerRateStrings;
	slicerRateStrings.add(AsciiWithNoteValuesTypeface::getNoteString(AsciiWithNoteValuesTypeface::NoteValue_4th) + " Quarter (1/4)");
	slicerRateStrings.add(AsciiWithNoteValuesTypeface::getNoteString(AsciiWithNoteValuesTypeface::NoteValue_half) + " Half (1/2)");
	slicerRateStrings.add(AsciiWithNoteValuesTypeface::getNoteString(AsciiWithNoteValuesTypeface::NoteValue_whole) + " Whole (1/1)");
	StringArray ampTypeStrings(StringArray::fromTokens("SMALL BUILTIN 2STACK 3STACK", false));
	StringArray outputMonoStereoStrings(StringArray::fromTokens("MONO STEREO", false));
	StringArray postGainDBStrings(StringArray::fromTokens("0 +6dB +12dB +18dB", false));
	StringArray lfoTypeStrings(StringArray::fromTokens("TRI TRP SIN SAW1 SAW2 SQR", false));
	StringArray lfoRateStrings(StringArray::fromTokens("0.1,0.2,0.3,0.4,0.5,0.6,0.7,0.8,0.9,1.0,1.1,1.2,1.3,1.4,1.5,1.6,1.7,1.8,1.9,2.0,2.1,2.2,2.3,2.4,2.5,2.6,2.7,2.8,2.9,3.0,3.1,3.2,3.3,3.4,3.5,3.6,3.7,3.8,3.9,4.0,4.1,4.2,4.3,4.4,4.5,4.6,4.7,4.8,4.9,5.0,5.1,5.2,5.3,5.4,5.5,5.6,5.7,5.8,5.9,6.0,6.1,6.2,6.3,6.4,6.5,6.6,6.7,6.8,6.9,7.0,7.1,7.2,7.3,7.4,7.5,7.6,7.7,7.8,7.9,8.0,8.1,8.2,8.3,8.4,8.5,8.6,8.7,8.8,8.9,9.0,9.1,9.2,9.3,9.4,9.5,9.6,9.7,9.8,9.9,10.0", ",", ""));
	lfoRateStrings.add(AsciiWithNoteValuesTypeface::getNoteString(AsciiWithNoteValuesTypeface::NoteValue_16th) + " Sixteenth (1/16)");
	lfoRateStrings.add(AsciiWithNoteValuesTypeface::getNoteString(AsciiWithNoteValuesTypeface::NoteValue_8th_triplet) + " Eighth Triplet (1/12)");
	lfoRateStrings.add(AsciiWithNoteValuesTypeface::getNoteString(AsciiWithNoteValuesTypeface::NoteValue_16th_dotted) + " Dotted Sixteenth (3/32)");
	lfoRateStrings.add(AsciiWithNoteValuesTypeface::getNoteString(AsciiWithNoteValuesTypeface::NoteValue_8th) + " Eighth (1/8)");
	lfoRateStrings.add(AsciiWithNoteValuesTypeface::getNoteString(AsciiWithNoteValuesTypeface::NoteValue_4th_triplet) + " Quarter Triplet (1/6)");
	lfoRateStrings.add(AsciiWithNoteValuesTypeface::getNoteString(AsciiWithNoteValuesTypeface::NoteValue_8th_dotted) + " Dotted Eighth (3/16)");
	lfoRateStrings.add(AsciiWithNoteValuesTypeface::getNoteString(AsciiWithNoteValuesTypeface::NoteValue_4th) + " Quarter (1/4)");
	lfoRateStrings.add(AsciiWithNoteValuesTypeface::getNoteString(AsciiWithNoteValuesTypeface::NoteValue_half_triplet) + " Half Tiplet (1/3)");
	lfoRateStrings.add(AsciiWithNoteValuesTypeface::getNoteString(AsciiWithNoteValuesTypeface::NoteValue_4th_dotted) + " Dotted Quarter (3/8)");
	lfoRateStrings.add(AsciiWithNoteValuesTypeface::getNoteString(AsciiWithNoteValuesTypeface::NoteValue_half) + " Half (1/2)");
	lfoRateStrings.add(AsciiWithNoteValuesTypeface::getNoteString(AsciiWithNoteValuesTypeface::NoteValue_whole_triplet) + " Whole Triplet (2/3)");
	lfoRateStrings.add(AsciiWithNoteValuesTypeface::getNoteString(AsciiWithNoteValuesTypeface::NoteValue_half_dotted) + " Dotted Half (3/4)");
	lfoRateStrings.add(AsciiWithNoteValuesTypeface::getNoteString(AsciiWithNoteValuesTypeface::NoteValue_whole) + " Whole (1/1)");
	lfoRateStrings.add("2 Measures");
	lfoRateStrings.add("3 Measures");
	lfoRateStrings.add("4 Measures");
	lfoRateStrings.add("8 Measures");
	lfoRateStrings.add("16 Measures");
	StringArray stepRateStrings(StringArray::fromTokens("0.05,0.10,0.15,0.20,0.25,0.30,0.35,0.40,0.45,0.50,0.55,0.60,0.65,0.70,0.75,0.80,0.85,0.90,0.95,1.00,1.05,1.10,1.15,1.20,1.25,1.30,1.35,1.40,1.45,1.50,1.55,1.60,1.65,1.70,1.75,1.80,1.85,1.90,1.95,2.00,2.05,2.10,2.15,2.20,2.25,2.30,2.35,2.40,2.45,2.50,2.55,2.60,2.65,2.70,2.75,2.80,2.85,2.90,2.95,3.00,3.05,3.10,3.15,3.20,3.25,3.30,3.35,3.40,3.45,3.50,3.55,3.60,3.65,3.70,3.75,3.80,3.85,3.90,3.95,4.0,4.1,4.2,4.3,4.4,4.5,4.6,4.7,4.8,4.9,5.0,5.1,5.2,5.3,5.4,5.5,5.6,5.7,5.8,5.9,6.0,6.1,6.2,6.3,6.4,6.5,6.6,6.7,6.8,6.9,7.0,7.5,8.0,8.5,9.0,9.5,10.0", ",", ""));
	stepRateStrings.add(AsciiWithNoteValuesTypeface::getNoteString(AsciiWithNoteValuesTypeface::NoteValue_16th) + " Sixteenth (1/16)");
	stepRateStrings.add(AsciiWithNoteValuesTypeface::getNoteString(AsciiWithNoteValuesTypeface::NoteValue_8th_triplet) + " Eighth Triplet (1/12)");
	stepRateStrings.add(AsciiWithNoteValuesTypeface::getNoteString(AsciiWithNoteValuesTypeface::NoteValue_16th_dotted) + " Dotted Sixteenth (3/32)");
	stepRateStrings.add(AsciiWithNoteValuesTypeface::getNoteString(AsciiWithNoteValuesTypeface::NoteValue_8th) + " Eighth (1/8)");
	stepRateStrings.add(AsciiWithNoteValuesTypeface::getNoteString(AsciiWithNoteValuesTypeface::NoteValue_4th_triplet) + " Quarter Triplet (1/6)");
	stepRateStrings.add(AsciiWithNoteValuesTypeface::getNoteString(AsciiWithNoteValuesTypeface::NoteValue_8th_dotted) + " Dotted Eighth (3/16)");
	stepRateStrings.add(AsciiWithNoteValuesTypeface::getNoteString(AsciiWithNoteValuesTypeface::NoteValue_4th) + " Quarter (1/4)");
	stepRateStrings.add(AsciiWithNoteValuesTypeface::getNoteString(AsciiWithNoteValuesTypeface::NoteValue_half_triplet) + " Half Tiplet (1/3)");
	stepRateStrings.add(AsciiWithNoteValuesTypeface::getNoteString(AsciiWithNoteValuesTypeface::NoteValue_4th_dotted) + " Dotted Quarter (3/8)");
	stepRateStrings.add(AsciiWithNoteValuesTypeface::getNoteString(AsciiWithNoteValuesTypeface::NoteValue_half) + " Half (1/2)");

	StringArray dryWetBalanceStrings(StringArray::fromTokens("D100 : 0W,D99 : 1W,D98 : 2W,D97 : 3W,D96 : 4W,D95 : 5W,D94 : 6W,D93 : 7W,D92 : 8W,D91 : 9W,D90 : 10W,D89 : 11W,D88 : 12W,D87 : 13W,D86 : 14W,D85 : 15W,D84 : 16W,D83 : 17W,D82 : 18W,D81 : 19W,D80 : 20W,D79 : 21W,D78 : 22W,D77 : 23W,D76 : 24W,D75 : 25W,D74 : 26W,D73 : 27W,D72 : 28W,D71 : 29W,D70 : 30W,D69 : 31W,D68 : 32W,D67 : 33W,D66 : 34W,D65 : 35W,D64 : 36W,D63 : 37W,D62 : 38W,D61 : 39W,D60 : 40W,D59 : 41W,D58 : 42W,D57 : 43W,D56 : 44W,D55 : 45W,D54 : 46W,D53 : 47W,D52 : 48W,D51 : 49W,D50 : 50W,D49 : 51W,D48 : 52W,D47 : 53W,D46 : 54W,D45 : 55W,D44 : 56W,D43 : 57W,D42 : 58W,D41 : 59W,D40 : 60W,D39 : 61W,D38 : 62W,D37 : 63W,D36 : 64W,D35 : 65W,D34 : 66W,D33 : 67W,D32 : 68W,D31 : 69W,D30 : 70W,D29 : 71W,D28 : 72W,D27 : 73W,D26 : 74W,D25 : 75W,D24 : 76W,D23 : 77W,D22 : 78W,D21 : 79W,D20 : 80W,D19 : 81W,D18 : 82W,D17 : 83W,D16 : 84W,D15 : 85W,D14 : 86W,D13 : 87W,D12 : 88W,D11 : 89W,D10 : 90W,D9 : 91W,D8 : 92W,D7 : 93W,D6 : 94W,D5 : 95W,D4 : 96W,D3 : 97W,D2 : 98W,D1 : 99W,D0 : 100W", ",", ""));
	StringArray manualFrequencyStrings(StringArray::fromTokens("100 Hz,110 Hz,120 Hz,130 Hz,140 Hz,150 Hz,160 Hz,170 Hz,180 Hz,190 Hz,200 Hz,210 Hz,220 Hz,230 Hz,240 Hz,250 Hz,260 Hz,270 Hz,280 Hz,290 Hz,300 Hz,320 Hz,340 Hz,360 Hz,380 Hz,400 Hz,420 Hz,440 Hz,460 Hz,480 Hz,500 Hz,520 Hz,540 Hz,560 Hz,580 Hz,600 Hz,620 Hz,640 Hz,660 Hz,680 Hz,700 Hz,720 Hz,740 Hz,760 Hz,780 Hz,800 Hz,820 Hz,840 Hz,860 Hz,880 Hz,900 Hz,920 Hz,940 Hz,960 Hz,980 Hz,1000 Hz,1100 Hz,1200 Hz,1300 Hz,1400 Hz,1500 Hz,1600 Hz,1700 Hz,1800 Hz,1900 Hz,2000 Hz,2100 Hz,2200 Hz,2300 Hz,2400 Hz,2500 Hz,2600 Hz,2700 Hz,2800 Hz,2900 Hz,3000 Hz,3100 Hz,3200 Hz,3300 Hz,3400 Hz,3500 Hz,3600 Hz,3700 Hz,3800 Hz,3900 Hz,4000 Hz,4100 Hz,4200 Hz,4300 Hz,4400 Hz,4500 Hz,4600 Hz,4700 Hz,4800 Hz,4900 Hz,5000 Hz,5100 Hz,5200 Hz,5300 Hz,5400 Hz,5500 Hz,5600 Hz,5700 Hz,5800 Hz,5900 Hz,6000 Hz,6100 Hz,6200 Hz,6300 Hz,6400 Hz,6500 Hz,6600 Hz,6700 Hz,6800 Hz,6900 Hz,7000 Hz,7100 Hz,7200 Hz,7300 Hz,7400 Hz,7500 Hz,7600 Hz,7700 Hz,7800 Hz,7900 Hz,8000 Hz", ",", ""));
	StringArray preDelayTimeStrings(StringArray::fromTokens("0.02 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0 1.1 1.2 1.3 1.4 1.5 1.6 1.7 1.8 1.9 2.0 2.1 2.2 2.3 2.4 2.5 2.6 2.7 2.8 2.9 3.0 3.1 3.2 3.3 3.4 3.5 3.6 3.7 3.8 3.9 4.0 4.1 4.2 4.3 4.4 4.5 4.6 4.7 4.8 4.9 5.0 5.5 6.0 6.5 7.0 7.5 8.0 8.5 9.0 9.5 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 33 34 35 36 37 38 39 40 41 42 43 44 45 46 47 48 49 50 52 54 56 58 60 62 64 66 68 70 72 74 76 78 80 82 84 86 88 90 92 94 96 98 100", false));
	StringArray phaseStrings(StringArray::fromTokens("00 20 40 60 80 100 120 140 160 180 200 220 240 260 280 300 320 340 360 380 400 420 440 460 480 500 520 540 560 580 600 620 640 660 680 700 720 740 760 780 800 820 840 860 880 900 920 940 960 980 1000 1020 1040 1060 1080 1100 1120 1140 1160 1180 1200 1220 1240 1260 1280 1300 1320 1340 1360 1380 1400 1420 1440 1460 1480 1500 1520 1540 1560 1580 1600 1620 1640 1660 1680 1700 1720 1740 1760 1780 1800", false));
	StringArray filterTypeStrings(StringArray::fromTokens("OFF LPF HPF", false));
	StringArray feedbackPercentageStrings(StringArray::fromTokens("0% +1% +2% +3% +4% +5% +6% +7% +8% +9% +10% +11% +12% +13% +14% +15% +16% +17% +18% +19% +20% +21% +22% +23% +24% +25% +26% +27% +28% +29% +30% +31% +32% +33% +34% +35% +36% +37% +38% +39% +40% +41% +42% +43% +44% +45% +46% +47% +48% +49% +50% +51% +52% +53% +54% +55% +56% +57% +58% +59% +60% +61% +62% +63% +64% +65% +66% +67% +68% +69% +70% +71% +72% +73% +74% +75% +76% +77% +78% +79% +80% +81% +82% +83% +84% +85% +86% +87% +88% +89% +90% +91% +92% +93% +94% +95% +96% +97% +98%", false));
	StringArray shortDelayTimeStrings(StringArray::fromTokens("0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0 1.1 1.2 1.3 1.4 1.5 1.6 1.7 1.8 1.9 2.0 2.5 3.0 3.5 4.0 4.5 5.0 5.5 6.0 6.5 7.0 7.5 8.0 8.5 9.0 9.5 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 33 34 35 36 37 38 39 40 41 42 43 44 45 46 47 48 49 50 55 60 65 70 75 80 85 90 95 100 105 110 115 120 125 130 135 140 145 150 155 160 165 170 175 180 185 190", false));
	StringArray autoPanRateStrings;
	autoPanRateStrings.add("OFF");
	autoPanRateStrings.add(AsciiWithNoteValuesTypeface::getNoteString(AsciiWithNoteValuesTypeface::NoteValue_16th) + " Sixteenth Note (1/16)");
	autoPanRateStrings.add(AsciiWithNoteValuesTypeface::getNoteString(AsciiWithNoteValuesTypeface::NoteValue_8th_triplet) + " Eighth Triplet (1/12)");
	autoPanRateStrings.add(AsciiWithNoteValuesTypeface::getNoteString(AsciiWithNoteValuesTypeface::NoteValue_16th_dotted) + " Dotted Sixteenth (3 / 32)");
	autoPanRateStrings.add(AsciiWithNoteValuesTypeface::getNoteString(AsciiWithNoteValuesTypeface::NoteValue_8th) + " Eighth (1/8)");
	autoPanRateStrings.add(AsciiWithNoteValuesTypeface::getNoteString(AsciiWithNoteValuesTypeface::NoteValue_4th_triplet) + "Quarter Triplet (1/6)");
	autoPanRateStrings.add(AsciiWithNoteValuesTypeface::getNoteString(AsciiWithNoteValuesTypeface::NoteValue_8th_dotted) + "Dotted Eighth (3/16)");
	autoPanRateStrings.add(AsciiWithNoteValuesTypeface::getNoteString(AsciiWithNoteValuesTypeface::NoteValue_4th) + " Quarter (1/4)");
	autoPanRateStrings.add(AsciiWithNoteValuesTypeface::getNoteString(AsciiWithNoteValuesTypeface::NoteValue_half_triplet) + " Half Tiplet (1/3)");
	autoPanRateStrings.add(AsciiWithNoteValuesTypeface::getNoteString(AsciiWithNoteValuesTypeface::NoteValue_4th_dotted) + " Dotted Quarter (3/8)");
	autoPanRateStrings.add(AsciiWithNoteValuesTypeface::getNoteString(AsciiWithNoteValuesTypeface::NoteValue_half) + " Half (1/2)");
	autoPanRateStrings.add(AsciiWithNoteValuesTypeface::getNoteString(AsciiWithNoteValuesTypeface::NoteValue_whole_triplet) + " Whole Triplet (2/3)");
	autoPanRateStrings.add(AsciiWithNoteValuesTypeface::getNoteString(AsciiWithNoteValuesTypeface::NoteValue_half_dotted) + " Dotted Half (3/4)");
	autoPanRateStrings.add(AsciiWithNoteValuesTypeface::getNoteString(AsciiWithNoteValuesTypeface::NoteValue_whole) + " Whole (1/1)");
	autoPanRateStrings.add("2 Measures"); autoPanRateStrings.add("3 Measures"); autoPanRateStrings.add("4 Measures");
	autoPanRateStrings.add("8 Measures"); autoPanRateStrings.add("16 Measures");
	switch (mFXTypeIndex)
	{
	case 0: // 4BAND EQ
		m_EffectDescription = "This is a 4 band (high, midrange x 2, low) stereo equalizer";
		setupParameter("Low Frequency", 0x0E, 0, 1, 0, StringArray::fromTokens("200 Hz,400 Hz", ",", ""), "Determines the frequency of the low range.");
		setupParameter("Low Gain", 0x0F, 0, 30, 15, gainStrings, "Adjusts the volume of the low frequency range.");
		setupParameter("High Frequency", 0x10, 0, 1, 0, StringArray::fromTokens("4000 Hz, 8000 Hz", ",", ""), "Determines the frequency of the high range.");
		setupParameter("High Gain", 0x11, 0, 30, 15, gainStrings, "Adjusts the volume of the high frequency range.");
		setupParameter("Peaking 1 Frequency", 0x12, 0, 16, 7, peakFrequencyStrings, "Determines the frequency of midrange 1.");
		setupParameter("Peaking 1 Q", 0x13, 0, 4, 1, peakQStrings, "Specifies the width of the frequency range affected by midrange 1. As this setting is increased, the affected area will become narrower.");
		setupParameter("Peaking 1 Gain", 0x14, 0, 30, 15, gainStrings, "Adjusts the volume of midrange 1.");
		setupParameter("Peaking 2 Frequency", 0x15, 0, 16, 7, peakFrequencyStrings, "Determines the frequency of midrange 2.");
		setupParameter("Peaking 2 Q", 0x16, 0, 4, 1, peakQStrings, "Specifies the width of the frequency range affected by midrange 2. As this setting is increased, the affected area will become narrower.");
		setupParameter("Peaking 2 Gain", 0x17, 0, 30, 15, gainStrings, "Adjusts the volume of midrange 2.");
		setupParameter("Output Level", 0x18, 0, 127, 127);
		setupParameter("", 0x19, 0, 127);
		break;
	case 1: // SPECTRUM
		m_EffectDescription = "This is a type of filter, which modifies the tonal character by boosting or cutting specific frequencies. It is similar to an equalizer, but when you wish to add character to the sound, the Spectrum effect will produce a more distinctive result.";
		setupParameter("Low-High Gain", 0x0E, 0, 30, 15, gainStrings, "Specifies the volume change at 500 Hz and 8000 Hz.");
		setupParameter("Middle Gain", 0x0F, 0, 30, 15, gainStrings, "Specifies the volume change at 1250 Hz.");
		setupParameter("Band Width", 0x10, 0, 4, 0, StringArray::fromTokens("1 2 3 4 5", false), "Specifies the width of the bands in which the volume will be adjusted.");
		setupParameter("Output Pan", 0x11, 0, 127, 64, panPosStrings, "Specifies the panning of the sound that is output from the effect.");
		setupParameter("Output Level", 0x12, 0, 127, 127);
		setupParameter("", 0x13, 0, 127);
		setupParameter("", 0x14, 0, 127);
		setupParameter("", 0x15, 0, 127);
		setupParameter("", 0x16, 0, 127);
		setupParameter("", 0x17, 0, 127);
		setupParameter("", 0x18, 0, 127);
		setupParameter("", 0x19, 0, 127);
		break;
	case 2: // ENHANCER
		m_EffectDescription = "By controlling the overtones of the high frequency range, this effect adds sparkle to the sound, giving it more definition.\r\nUse this effect when you want to make a specific sound stand out from the rest of the ensemble, or to give it greater definition.";
		setupParameter("Sens", 0x0E, 0, 127, 127, StringArray(), "Adjusts the depth of the enhancer effect");
		setupParameter("Mix Level", 0x0F, 0, 127, 64, StringArray(), "Determines the proportion at which the overtones generated by the enhancer will be mixed with the original sound.");
		setupParameter("Low Gain", 0x10, 0, 30, 15, gainStrings, "Adjusts the volume of the low frequency range.");
		setupParameter("High Gain", 0x11, 0, 30, 15, gainStrings, "Adjusts the volume of the high frequency range.");
		setupParameter("Output Level", 0x12, 0, 127, 127);
		setupParameter("", 0x13, 0, 127);
		setupParameter("", 0x14, 0, 127);
		setupParameter("", 0x15, 0, 127);
		setupParameter("", 0x16, 0, 127);
		setupParameter("", 0x17, 0, 127);
		setupParameter("", 0x18, 0, 127);
		setupParameter("", 0x19, 0, 127);
		break;
	case 3: // OVERDRIVE
		m_EffectDescription = "This simulates the soft distortion that occurs when you raise the gain of a vacuum tube amp. The effect also contains an amp simulator, and produces the natural distortion that is created by sounds played through a guitar amp. It is suitable for use with guitar and synth-bass sounds.";
		setupParameter("Input Level", 0x0E, 0, 127, 100, StringArray(), "Adjusts the level of the input signal");
		setupParameter("Drive", 0x0F, 0, 127, 100, StringArray(), "Adjusts the depth of distortion. This will also affect the volume.");
		setupParameter("Amplifier Type", 0x10, 0, 3, 1, ampTypeStrings, "Determines the type of guitar amp.\r\nSMALL: small amp\r\nBUILTIN: built-in type amp\r\n2STACK: large double amp stack\r\n3STACK: large double amp stack");
		setupParameter("Output Pan", 0x11, 0, 127, 64, panPosStrings, "Specifies the stereo location of the sound that is output from the effect.");
		setupParameter("Output Level", 0x12, 0, 127, 127);
		setupParameter("", 0x13, 0, 127);
		setupParameter("", 0x14, 0, 127);
		setupParameter("", 0x15, 0, 127);
		setupParameter("", 0x16, 0, 127);
		setupParameter("", 0x17, 0, 127);
		setupParameter("", 0x18, 0, 127);
		setupParameter("", 0x19, 0, 127);
		break;
	case 4: // DISTORTION
		m_EffectDescription = "This effect produces a more severe distortion than the Overdrive effect. It also contains an amp simulator, and produces the natural sound of a guitar amp.";
		setupParameter("Input Level", 0x0E, 0, 127, 100, StringArray(), "Adjusts the level of the input signal.");
		setupParameter("Drive", 0x0F, 0, 127, 100, StringArray(), "Adjusts the depth of distortion. This will also affect the volume.");
		setupParameter("Amplifier Type", 0x10, 0, 3, 3, ampTypeStrings, "Determines the type of guitar amp.\r\nSMALL: small amp\r\nBUILTIN: built-in type amp\r\n2STACK: large double amp stack\r\n3STACK: large double amp stack");
		setupParameter("Output Pan", 0x11, 0, 127, 64, panPosStrings, "Specifies the stereo location of the sound that is output from the effect.");
		setupParameter("Output Level", 0x12, 0, 127, 127);
		setupParameter("", 0x13, 0, 127);
		setupParameter("", 0x14, 0, 127);
		setupParameter("", 0x15, 0, 127);
		setupParameter("", 0x16, 0, 127);
		setupParameter("", 0x17, 0, 127);
		setupParameter("", 0x18, 0, 127);
		setupParameter("", 0x19, 0, 127);
		break;
	case 5: // LO-FI
		m_EffectDescription = "This effect intentionally degrades the audio quality to simulate a Lo-Fi sound. It is particularly effective on drums.";
		setupParameter("Bit Down", 0x0E, 0, 7, 2, StringArray(), "This setting lowers the audio quality.\r\nThe audio quality will worsen as this setting is increased.");
		setupParameter("Sample Rate Down", 0x0F, 0, 3, 2, StringArray::fromTokens("32 16 8 4", false), "This coarsens the output signal.\r\nThe sound will become coarser as this setting is lowered.");
		setupParameter("Post Gain", 0x10, 0, 3, 2, postGainDBStrings, "Adjusts the output signal.");
		setupParameter("Low Gain", 0x11, 0, 30, 15, gainStrings, "Adjusts the boost or cut applied to the low frequency range.");
		setupParameter("High Gain", 0x12, 0, 30, 15, gainStrings, "Adjusts the boost or cut applied to the high frequency range.");
		setupParameter("Output", 0x13, 0, 1, 1, outputMonoStereoStrings, "Specifies how the sound will be output.\r\nWith a setting of 'MONO', the output sound will be monaural.");
		setupParameter("Output Level", 0x14, 0, 127, 127);
		setupParameter("", 0x15, 0, 127);
		setupParameter("", 0x16, 0, 127);
		setupParameter("", 0x17, 0, 127);
		setupParameter("", 0x18, 0, 127);
		setupParameter("", 0x19, 0, 127);
		break;
	case 6: // NOISE
		m_EffectDescription = "In addition to a Lo-Fi effect, this effect also generates various types of noise such as hum, pink noise, and disk noise.";
		setupParameter("Noise Type", 0x0E, 0, 17, 10, StringArray::fromTokens("RND,PINK,LP + RND,PINK + LP + RND,EP + RND,PINK + EP + RND,HUM 50,HUM 50 + PINK,HUM 50 + LP + RND,HUM 50 + PINK + LP + RND,HUM 50 + EP + RND,HUM 50 + PINK + EP + RND,HUM 60,HUM 60 + PINK,HUM 60 + LP + RND,HUM 60 + PINK + LP + RND,HUM 60 + EP + RND,HUM 60 + PINK + EP + RND", ",", ""), "Determines the type of noise(s) that will be generated.");
		//setupParameter("Noise Type", 0x0E, 0, 17, 10, StringArray::fromTokens("RND Disc,Pink Noise,Disc LP + RND Disc,Pink Noise + Disc LP + RND Disc,Disc EP + RND Disc,Pink Noise + Disc EP + RND Disc,Hum (50Hz),Hum (50Hz) + Pink Noise,Hum (50Hz) + Disc LP + RND Disc,Hum (50Hz) + Pink Noise + Disc LP + RND Disc,Hum (50Hz) + Disc EP + RND Disc,Hum (50Hz) + Pink Noise + Disc EP + RND Disc,Hum (60Hz),Hum (60Hz) + Pink Noise,Hum (60Hz) + Disc LP + RND Disc,Hum (60Hz) + Pink Noise + Disc LP + RND Disc,Hum (60Hz) + Disc EP + RND Disc,Hum (60Hz) + Pink Noise + Disc EP + RND Disc", ",", ""), "Determines the type of noise(s) that will be generated.");
		setupParameter("Noise Level", 0x0F, 0, 127, 0, StringArray(), "Specifies the volume of the noise.");
		setupParameter("Noise Filter", 0x10, 0, 17, 17, hpFrequencyStrings, "Adjusts the tone of the noise.\r\nIf you do not wish to filter the noise, select 'BYPASS.'");
		setupParameter("Lo-Fi Level", 0x11, 0, 127, 64, StringArray(), "Increasing this setting will make the original sound rougher.");
		setupParameter("Output Pan", 0x12, 0, 127, 64, panPosStrings, "Specifies the stereo location of the sound that is output from the effect.");
		setupParameter("Output Level", 0x13, 0, 127, 127);
		setupParameter("", 0x14, 0, 127);
		setupParameter("", 0x15, 0, 127);
		setupParameter("", 0x16, 0, 127);
		setupParameter("", 0x17, 0, 127);
		setupParameter("", 0x18, 0, 127);
		setupParameter("", 0x19, 0, 127);

		break;
	case 7: // RADIO TUING
		m_EffectDescription = "This effect simulates the sound of a radio being tuned.";
		setupParameter("Radio Detune", 0x0E, 0, 127, 64, StringArray(), "Specifies the frequency being tuned.\r\nControl this to simulate radio tuning");
		setupParameter("Noise Level", 0x0F, 0, 127, 0, StringArray(), "Specifies the volume of the tuning noise.");
		setupParameter("Low Gain", 0x10, 0, 30, 15, gainStrings, "Adjusts the boost or cut of the low frequency range.");
		setupParameter("High Gain", 0x11, 0, 30, 15, gainStrings, "Adjusts the boost or cut of the high frequency range.");
		setupParameter("Output", 0x12, 0, 1, 1, outputMonoStereoStrings, "Specifies how the sound will be output.\r\nWith a setting of 'MONO', the output sound will be monaural.");
		setupParameter("Output Level", 0x13, 0, 127, 127);
		setupParameter("", 0x14, 0, 127);
		setupParameter("", 0x15, 0, 127);
		setupParameter("", 0x16, 0, 127);
		setupParameter("", 0x17, 0, 127);
		setupParameter("", 0x18, 0, 127);
		setupParameter("", 0x19, 0, 127);
		break;
	case 8: // PHONOGRAPH
		m_EffectDescription = "This effect mutes the tone and adds disc noise to simulate the sound of music played on an old record player.";
		setupParameter("Disc Type", 0x0E, 0, 2, 0, StringArray::fromTokens("LP: 33 RPM record,EP: 45 RPM record,SP: 78 RPM record", ",", ""), "Determines the type of disc noise");
		setupParameter("Disc Noise Level", 0x0F, 0, 127, 0, StringArray(), "Specifies the volume of the disc noise");
		setupParameter("Depth", 0x10, 0, 20, 10, StringArray::fromTokens("0 +1 +2 +3 +4 +5 +6 +7 +8 +9 +10 +11 +12 +13 +14 +15 +16 +17 +18 +19 +20", false), "Adjusts the tone.\r\nAs this value is increased, the high range and low range will be cut, and the mid range will be emphasized.");
		setupParameter("Output Pan", 0x11, 0, 127, 64, panPosStrings, "Specifies the stereo location of the sound that is output from the effect.");
		setupParameter("Output Level", 0x12, 0, 127, 127);
		setupParameter("", 0x13, 0, 127);
		setupParameter("", 0x14, 0, 127);
		setupParameter("", 0x15, 0, 127);
		setupParameter("", 0x16, 0, 127);
		setupParameter("", 0x17, 0, 127);
		setupParameter("", 0x18, 0, 127);
		setupParameter("", 0x19, 0, 127);
		break;
	case 9: // COMPRESSOR
		m_EffectDescription = "This effect suppresses loud volume levels and boosts soft volume levels, making the volume more consistent.";
		setupParameter("Attack", 0x0E, 0, 127, 64, StringArray(), "Specifies the duration of the attack when sound is input.");
		setupParameter("Sustain", 0x0F, 0, 127, 127, StringArray(), "Specifies the time over which low-level sounds will be boosted to reach the specified volume.");
		setupParameter("Post Gain", 0x10, 0, 3, 1, postGainDBStrings, "Adjusts the output signal.");
		setupParameter("Low Gain", 0x11, 0, 30, 15, gainStrings, "Adjusts the boost or cut of the low frequency range.");
		setupParameter("High Gain", 0x12, 0, 30, 15, gainStrings, "Adjusts the boost or cut of the high frequency range.");
		setupParameter("Output Level", 0x13, 0, 127, 127);
		setupParameter("", 0x14, 0, 127);
		setupParameter("", 0x15, 0, 127);
		setupParameter("", 0x16, 0, 127);
		setupParameter("", 0x17, 0, 127);
		setupParameter("", 0x18, 0, 127);
		setupParameter("", 0x19, 0, 127);
		break;
	case 10: // LIMITER
		m_EffectDescription = "This effect compresses the sound when it exceeds a specified volume level, thus preventing distortion.";
		setupParameter("Threshold Level", 0x0E, 0, 127, 64, StringArray(), "Specifies the volume level at which compression will begin.");
		setupParameter("Compression Ratio", 0x0F, 0, 3, 2, StringArray::fromTokens("1.5:1 2:1 4:1 100:1", false), "Specifies the ratio of compression.");
		setupParameter("Release", 0x10, 0, 127, 32, StringArray(), "Specifies the time from when the volume drops below the Threshold Level until compression is no longer applied.");
		setupParameter("Post Gain", 0x11, 0, 3, 1, postGainDBStrings, "Adjusts the output signal.");
		setupParameter("Output Pan", 0x12, 0, 127, 64, panPosStrings, "Specifies the stereo location of the sound that is output from the effect.");
		setupParameter("Output Level", 0x13, 0, 127, 127);
		setupParameter("", 0x14, 0, 127);
		setupParameter("", 0x15, 0, 127);
		setupParameter("", 0x16, 0, 127);
		setupParameter("", 0x17, 0, 127);
		setupParameter("", 0x18, 0, 127);
		setupParameter("", 0x19, 0, 127);
		break;
	case 11: // SLICER
		m_EffectDescription = "By applying successive cuts to the sound, this effect turns a conventional sound into a sound that appears to be played as a backing phrase. This is especially effective when applied to sustain-type sounds.";
		setupParameter("Timing Pattern", 0x0E, 0, 33, 3, StringArray::fromTokens("1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 33 34", false), "Select a pattern to specify the timing at which the sound will be cut.");
		setupParameter("Rate", 0x0F, 0, 2, 1, slicerRateStrings, "Determines the note value unit which will be cut.");
		setupParameter("Accent Pattern", 0x10, 0, 15, 0, StringArray::fromTokens("1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16", false), "Specifies the location of the accents.");
		setupParameter("Accent Level", 0x11, 0, 127, 64, StringArray(), "Adjusts the volume of the accents.\r\nAs this setting is increased, the accent will be more pronounced.");
		setupParameter("Attack", 0x12, 0, 9, 5, StringArray::fromTokens("1 2 3 4 5 6 7 8 9 10", false), "Adjusts the attack speed of the sound.\r\nAs this setting is increased, the attack will become faster.");
		setupParameter("Output Level", 0x13, 0, 127, 127);
		setupParameter("", 0x14, 0, 127);
		setupParameter("", 0x15, 0, 127);
		setupParameter("", 0x16, 0, 127);
		setupParameter("", 0x17, 0, 127);
		setupParameter("", 0x18, 0, 127);
		setupParameter("", 0x19, 0, 127);
		break;
	case 12: // TREMOLO
		m_EffectDescription = "This effect cyclically modulates the volume to create tremolo.";
		setupParameter("LFO Type", 0x0E, 0, 5, 0, lfoTypeStrings, "Determines the waveform that will be used to modulate the sound.");
		setupParameter("Rate", 0x0F, 0, 117, 106, lfoRateStrings, "Specifies the frequency of modulation. If a note value or measure is selected as the value of this parameter, the Rate will synchronize with the BPM of the pattern at intervals of the specified note value or measure.");
		setupParameter("Depth", 0x10, 0, 127, 64, StringArray(), "Specifies the depth of modulation.");
		setupParameter("Low Gain", 0x11, 0, 30, 15, gainStrings, "Adjusts the boost or cut of the low frequency range.");
		setupParameter("High Gain", 0x12, 0, 30, 15, gainStrings, "Adjusts the boost or cut of the high frequency range.");
		setupParameter("Output Level", 0x13, 0, 127, 127);
		setupParameter("", 0x14, 0, 127);
		setupParameter("", 0x15, 0, 127);
		setupParameter("", 0x16, 0, 127);
		setupParameter("", 0x17, 0, 127);
		setupParameter("", 0x18, 0, 127);
		setupParameter("", 0x19, 0, 127);
		break;
	case 13: // PHASER
		m_EffectDescription = "By adding a phase-shifted sound to the original sound, this effect modulates the sound to add depth and a sense of rotation.";
		setupParameter("Manual", 0x0E, 0, 125, 30, manualFrequencyStrings, "Specifies the center frequency at which the sound will be modulated.");
		setupParameter("Rate", 0x0F, 0, 117, 106, lfoRateStrings, "Specifies the frequency of modulation. If a note value or measure is selected as the value of this parameter, the Rate will synchronize with the BPM of the pattern at intervals of the specified note value or measure.");
		setupParameter("Depth", 0x10, 0, 127, 64, StringArray(), "Specifies the depth of modulation.");
		setupParameter("Resonance", 0x11, 0, 127, 64, StringArray(), "This setting emphasizes the frequency range in the vicinity of the center frequency.");
		setupParameter("Mix Level", 0x12, 0, 127, 127, StringArray(), "Adjusts the proportion of the original sound that will be combined with the phase-shifted sound.");
		setupParameter("Output Pan", 0x13, 0, 127, 64, panPosStrings, "Specifies the stereo location of the sound that is output from the effect.");
		setupParameter("Output Level", 0x14, 0, 127, 127);
		setupParameter("", 0x15, 0, 127);
		setupParameter("", 0x16, 0, 127);
		setupParameter("", 0x17, 0, 127);
		setupParameter("", 0x18, 0, 127);
		setupParameter("", 0x19, 0, 127);
		break;
	case 14: // CHORUS
		m_EffectDescription = "This effect creates an impression of multiple sound sources in unison (Chorus effect), giving spaciousness and depth to the sound.";
		setupParameter("Pre Delay Time", 0x0E, 0, 125, 10, preDelayTimeStrings, "Specifies the time from the original sound until when the chorus sound is heard.");
		setupParameter("Rate", 0x0F, 0, 117, 109, lfoRateStrings, "Specifies the frequency of modulation. If a note value or measure is selected as the value of this parameter, the Rate will synchronize with the BPM of the pattern at intervals of the specified note value or measure.");
		setupParameter("Depth", 0x10, 0, 127, 64, StringArray(), "Specifies the depth of modulation.");
		setupParameter("Phase", 0x11, 0, 90, 90, phaseStrings, "Adjusts the spaciousness of the sound. As this setting is increased, the sound will spread more toward left and right.");
		setupParameter("Filter Type", 0x12, 0, 2, 0, filterTypeStrings, "Determines the type of filter that will be applied to the chorus sound.\r\nAvailable settings:\r\nOFF: A filter will not be used.\r\nLPF: The frequency range above the cutoff frequency will be cut.\r\nHPF: The frequency range below the cutoff frequency will be cut.");
		setupParameter("Cutoff Frequency", 0x13, 0, 16, 7, hpFrequencyStrings, "Specifies the cutoff frequency of the filter.");
		setupParameter("Effect Balance", 0x14, 0, 100, 50, dryWetBalanceStrings, "Adjusts the volume balance between the original sound and the chorus sound. With a setting of 'D100:0W', no chorus sound will be output.");
		setupParameter("Output Level", 0x15, 0, 127, 127);
		setupParameter("", 0x16, 0, 127);
		setupParameter("", 0x17, 0, 127);
		setupParameter("", 0x18, 0, 127);
		setupParameter("", 0x19, 0, 127);
		break;
	case 15: // SPACE-D
		m_EffectDescription = "This is a type of chorus, but unlike a conventional chorus, it does not create a sense of modulation.";
		setupParameter("Pre Delay Time", 0x0E, 0, 125, 10, preDelayTimeStrings, "Specifies the time from the original sound until the chorus sound is heard.");
		setupParameter("Rate", 0x0F, 0, 117, 106, lfoRateStrings, "Specifies the rate of modulation. If a note value or measure is selected as the value of this parameter, the Rate will synchronize with the BPM of the pattern at intervals of the specified note value or measure.");
		setupParameter("Depth", 0x10, 0, 127, 64, StringArray(), "Specifies the depth of modulation.");
		setupParameter("Phase", 0x11, 0, 90, 90, phaseStrings, "Adjusts the spread of the sound. As this value is increased, the sound will have a broader left / right spread.");
		setupParameter("Low Gain", 0x12, 0, 30, 15, gainStrings, "Adjusts the boost or cut of the low frequency range.");
		setupParameter("High Gain", 0x13, 0, 30, 15, gainStrings, "Adjusts the boost or cut of the high frequency range.");
		setupParameter("Effect Balance", 0x14, 0, 100, 50, dryWetBalanceStrings, "Adjusts the volume balance between the original sound and the chorus sound.With a setting of 'D100 : 0W' the chorus sound will not be heard.");
		setupParameter("Output Level", 0x15, 0, 127, 127);
		setupParameter("", 0x16, 0, 127);
		setupParameter("", 0x17, 0, 127);
		setupParameter("", 0x18, 0, 127);
		setupParameter("", 0x19, 0, 127);
		break;
	case 16: // TETRA CHORUS
		m_EffectDescription = "This effect layers four chorus sounds to produce even more depth and spaciousness than a conventional chorus.";
		setupParameter("Pre Delay Time", 0x0E, 0, 125, 10, preDelayTimeStrings, "Specifies the time from the original sound until when the chorus sound is heard.");
		setupParameter("Rate", 0x0F, 0, 117, 112, lfoRateStrings, "Specifies the rate of modulation. If a note value or measure is selected as the value of this parameter, the Rate will synchronize with the BPM of the pattern at intervals of the specified note value or measure.");
		setupParameter("Depth", 0x10, 0, 127, 64, StringArray(), "Specifies the depth of modulation.");
		setupParameter("Pre Delay Deviation", 0x11, 0, 20, 0, StringArray(), "Adjusts the difference in pre delay between each of the chorus sounds.");
		setupParameter("Depth Deviation", 0x12, 0, 40, 0, StringArray::fromTokens("-20 -19 -18 -17 -16 -15 -14 -13 -12 -11 -10 -9 -8 -7 -6 -5 -4 -3 -2 -1 0 +1 +2 +3 +4 +5 +6 +7 +8 +9 +10 +11 +12 +13 +14 +15 +16 +17 +18 +19 +20", false), "Adjusts the difference in modulation depth between each of the chorus sounds.");
		setupParameter("Pan Deviation", 0x13, 0, 20, 20, StringArray(), "Adjusts the pan difference between each chorus sound.As this value is increased, the sound will have a greater left / right spread.");
		setupParameter("Effect Balance", 0x14, 0, 100, 50, dryWetBalanceStrings, "Specifies the volume balance between the original sound and the chorus sound. With a setting of 'D100 : 0W', no chorus sound will be output.");
		setupParameter("Output Level", 0x15, 0, 127, 127);
		setupParameter("", 0x16, 0, 127);
		setupParameter("", 0x17, 0, 127);
		setupParameter("", 0x18, 0, 127);
		setupParameter("", 0x19, 0, 127);
		break;
	case 17: // FLANGER
		m_EffectDescription = "This creates a sharper and more mechanical sound than the phaser.It can add a metallic resonance to the sound, or produce an effect that sounds like an jet airplane taking off and landing.";
		setupParameter("Pre Delay Time", 0x0E, 0, 125, 10, preDelayTimeStrings, "Specifies the time from the original sound until the flanger sound is heard.");
		setupParameter("Rate", 0x0F, 0, 117, 109, lfoRateStrings, "Specifies the rate of modulation. If a note value or measure is selected as the value of this parameter, the Rate will synchronize with the BPM of the pattern at intervals of the specified note value or measure.");
		setupParameter("Depth", 0x10, 0, 127, 64, StringArray(), "Specifies the depth of modulation.");
		setupParameter("Feedback Level", 0x11, 0, 98, 50, feedbackPercentageStrings, "Specifies the proportion of the flanger sound that is fed back into the input.");
		setupParameter("Phase", 0x12, 0, 90, 0, phaseStrings, "Adjusts the width of the sound.\r\nAs this setting is increased, the left/right spread of the sound will increase.");
		setupParameter("Filter Type", 0x13, 0, 2, 0, filterTypeStrings, "Determines the type of filter that will be applied to the flanger sound.\r\nAvailable Settings:\r\nOFF: A filter will not be used.\r\nLPF : The frequency range above the cutoff frequency will be cut.\r\nHPF : The frequency range below the cutoff frequency will be cut.");
		setupParameter("Cutoff Frequency", 0x14, 0, 16, 7, peakFrequencyStrings, "Specifies the cutoff frequency of the filter.");
		setupParameter("Effect Balance", 0x15, 0, 100, 50, dryWetBalanceStrings, "Adjusts the volume balance between the original sound and the flanger sound.With a setting of 'D100 : 0W', no flanger sound will be output.");
		setupParameter("Output Level", 0x16, 0, 127, 127);
		setupParameter("", 0x17, 0, 127);
		setupParameter("", 0x18, 0, 127);
		setupParameter("", 0x19, 0, 127);
		break;
	case 18: // STEP FLANGER
		m_EffectDescription = "This is a flanger that changes the pitch of the sound in steps. The frequency of pitch change can also be synchronized to the BPM.";
		setupParameter("Pre Delay Time", 0x0E, 0, 125, 10, preDelayTimeStrings, "Specifies the time from the original sound until the flanger sound is heard.");
		setupParameter("Rate", 0x0F, 0, 117, 39, lfoRateStrings, "Specifies the frequency of modulation.If a note value or measure is selected as the value of this parameter, the Rate will synchronize with the BPM of the pattern at intervals of the specified note value or measure.");
		setupParameter("Depth", 0x10, 0, 127, 64, StringArray(), "Specifies the depth of modulation.");
		setupParameter("Feedback Level", 0x11, 0, 98, 50, feedbackPercentageStrings, "Specifies the proportion of the flanger sound that is fed back into the input.");
		setupParameter("Phase", 0x12, 0, 90, 180, phaseStrings, "Adjusts the spread of the sound.As this value is increased, the left / right spread of the sound will increase.");
		setupParameter("Step Rate", 0x13, 0, 125, 119, stepRateStrings, "Specifies the rate at which the pitch will change.If a note value is selected as the value of this parameter, the Step Rate will synchronize with the BPM of the pattern at intervals of the specified note value.");
		setupParameter("Effect Balance", 0x14, 0, 100, 50, dryWetBalanceStrings, "Adjusts the volume balance between the original sound and the flanger sound.With a setting of 'D100 : 0W', no flanger sound will be output.");
		setupParameter("Output Level", 0x15, 0, 127, 127);
		setupParameter("", 0x16, 0, 127);
		setupParameter("", 0x17, 0, 127);
		setupParameter("", 0x18, 0, 127);
		setupParameter("", 0x19, 0, 127);
		break;
	case 19: // SHORT DELAY
		m_EffectDescription = "This is a short delay which allows you to set the left and right delay times independently.You can also move the panning of the delay sound in synchronization with the BPM.";
		setupParameter("Delay Time Left", 0x0E, 0, 103, 75, shortDelayTimeStrings, "Specifies the time from the original sound until the left delay sound is heard.");
		setupParameter("Delay Time Right", 0x0F, 0, 103, 85, shortDelayTimeStrings, "Specifies the time from the original sound until the right delay sound is heard.");
		setupParameter("HF Damp", 0x10, 0, 17, 17, hpFrequencyStrings, "Determines the frequency at which the high frequency portions of the delay sound will be cut.\r\nAs this parameter is set to a lower frequency, more of the high range will be cut, making the delay sound more muted in tone. If you do not wish to cut the high frequency range, select 'BYPASS'.");
		setupParameter("Feedback Level", 0x11, 0, 98, 50, feedbackPercentageStrings, "Adjusts the number of delay repeats.");
		setupParameter("Auto Pan", 0x12, 0, 18, 0, autoPanRateStrings, "This setting causes the panning of the delay sound to move in synchronization with the BPM.");
		setupParameter("Low Gain", 0x13, 0, 30, 15, gainStrings, "Adjusts the boost or cut of the low frequency range.");
		setupParameter("High Gain", 0x14, 0, 30, 15, gainStrings, "Adjusts the boost or cut of the high frequency range.");
		setupParameter("Effect Balance", 0x15, 0, 100, 50, dryWetBalanceStrings, "Adjusts the volume balance between the original sound and the delay sound.\r\nWith a setting of 'D100:0W' no delay sound will be output.");
		setupParameter("Output Level", 0x16, 0, 127, 127);
		setupParameter("", 0x17, 0, 127);
		setupParameter("", 0x18, 0, 127);
		setupParameter("", 0x19, 0, 127);
		break;
	case 20: // AUTO PAN
		m_EffectDescription = "This effect automatically moves the stereo location of the sound.You can cause the sound to be panned left and right in time with low notes such as a Bass Drum, or in synchronization with the BPM of the pattern.";
		setupParameter("LFO type", 0x0E, 0, 5, 2, lfoTypeStrings, "Determines the waveform that will be used to pan the sound to left and right.");
		setupParameter("Rate", 0x0F, 0, 117, 109, lfoRateStrings, "Specifies the rate at which the pan will be moved.If a note value or measure is selected as the value of this parameter, the Rate will synchronize with the tempo of the pattern at intervals of the specified note value or measure.\r\nIgnored if Bass Sensitivity is set to 'MODE2'");
		setupParameter("Bass Sense", 0x10, 0, 2, 0, StringArray::fromTokens("OFF MODE1 MODE2", false), "Make this setting when you wish to shift the panning at the timing of the bass notes.\r\nRange:\r\nOFF : The panning will change at the speed specified by Rate.\r\nMODE1: The Rate value will increase at the timing of the bass notes.\r\nMODE2: The panning will change at the timing of the bass notes. Rate setting will be ignored.");
		setupParameter("Depth", 0x11, 0, 127, 64, StringArray(), "Specifies the depth of panning.");
		setupParameter("Low Gain", 0x12, 0, 30, 15, gainStrings, "Adjusts the boost or cut of the low frequency range.");
		setupParameter("High Gain", 0x13, 0, 30, 15, gainStrings, "Adjusts the boost or cut of the high frequency range.");
		setupParameter("Output Level", 0x14, 0, 127, 127);
		setupParameter("", 0x15, 0, 127);
		setupParameter("", 0x16, 0, 127);
		setupParameter("", 0x17, 0, 127);
		setupParameter("", 0x18, 0, 127);
		setupParameter("", 0x19, 0, 127);
		break;
	case 21: // FB PITCH SHIFTER
		m_EffectDescription = "This effect shifts the pitch of the original sound and layers it with the original sound.It can be used to play unison lines at an interval of an octave or fifth, or to layer a slightly pitch-shifted with the original sound to create a chorus effect.";
		setupParameter("Coarse Pitch", 0x0E, 0, 36, 24, StringArray::fromTokens("-24 -23 -22 -21 -20 -19 -18 -17 -16 -15 -14 -13 -12 -11 -10 -9 -8 -7 -6 -5 -4 -3 -2 -1 0 +1 +2 +3 +4 +5 +6 +7 +8 +9 +10 +11 +12", false), "Specifies the amount of pitch shift relative to the original sound, in semitone steps.");
		setupParameter("Fine Pitch", 0x0F, 0, 100, 50, StringArray::fromTokens("-100 cent,-98 cent,-96 cent,-94 cent,-92 cent,-90 cent,-88 cent,-86 cent,-84 cent,-82 cent,-80 cent,-78 cent,-76 cent,-74 cent,-72 cent,-70 cent,-68 cent,-66 cent,-64 cent,-62 cent,-60 cent,-58 cent,-56 cent,-54 cent,-52 cent,-50 cent,-48 cent,-46 cent,-44 cent,-42 cent,-40 cent,-38 cent,-36 cent,-34 cent,-32 cent,-30 cent,-28 cent,-26 cent,-24 cent,-22 cent,-20 cent,-18 cent,-16 cent,-14 cent,-12 cent,-10 cent,-8 cent,-6 cent,-4 cent,-2 cent,0 cent,+2 cent,+4 cent,+6 cent,+8 cent,+10 cent,+12 cent,+14 cent,+16 cent,+18 cent,+20 cent,+22 cent,+24 cent,+26 cent,+28 cent,+30 cent,+32 cent,+34 cent,+36 cent,+38 cent,+40 cent,+42 cent,+44 cent,+46 cent,+48 cent,+50 cent,+52 cent,+54 cent,+56 cent,+58 cent,+60 cent,+62 cent,+64 cent,+66 cent,+68 cent,+70 cent,+72 cent,+74 cent,+76 cent,+78 cent,+80 cent,+82 cent,+84 cent,+86 cent,+88 cent,+90 cent,+92 cent,+94 cent,+96 cent,+98 cent,+100 cent", ",", ""), "Adjusts the amount of pitch shift in 2-cent steps.");
		setupParameter("Output Pan", 0x10, 0, 127, 64, panPosStrings, "Determines the stereo location of the pitch-shifted sound.");
		setupParameter("Pre Delay Time", 0x11, 0, 125, 60, preDelayTimeStrings, "Specifies the time from the original sound until the pitchshifted sound is heard.");
		setupParameter("Pitch Shifter Mode", 0x12, 0, 4, 0, StringArray::fromTokens("1 2 3 4 5", false), "Specifies how the pitch will be shifted.As this setting is increased, the response will be slower, but the sound will be more stable.");
		setupParameter("Feedback Level", 0x13, 0, 98, 50, feedbackPercentageStrings, "Specifies the proportion of the pitch-shifted sound that will be fed back into the input.");
		setupParameter("Low Gain", 0x14, 0, 30, 15, gainStrings, "Adjusts the boost or cut of the low frequency range.");
		setupParameter("High Gain", 0x15, 0, 30, 15, gainStrings, "Adjusts the boost or cut of the high frequency range.");
		setupParameter("Effect Balance", 0x16, 0, 100, 50, dryWetBalanceStrings, "");
		setupParameter("Output Level", 0x17, 0, 127, 127);
		setupParameter("", 0x18, 0, 127);
		setupParameter("", 0x19, 0, 127);
		break;
	case 22: // REVERB
		m_EffectDescription = "This effect adds reverberation and ambiance to the sound, creating spatial depth.";
		setupParameter("Reverb Type", 0x0E, 0, 5, 2, StringArray::fromTokens("ROOM1 ROOM2 STAGE1 STAGE2 HALL1 HALL2", false), "You can select one of the following six basic types of reverb.\r\nAvailable Settings:\r\nROOM1: Reverb with short decay and high density.\r\nROOM2: Reverb with short decay and low density.\r\nSTAGE1: Reverb with much subsequent reverberation.\r\nSTAGE2: Reverb with strong early reflections.\r\nHALL1: Clear-sounding reverb.\r\nHALL2: Rich-sounding reverb.");
		setupParameter("Reverb Time", 0x0F, 0, 127, 30, StringArray(), "Specifies the duration of the reverberation.");
		setupParameter("HF Dampe", 0x10, 0, 17, 17, hpFrequencyStrings, "Determines the frequency at which the high frequency portions of the reverberation will be cut. As this parameter is set to a lower frequency, more of the high range will be cut, making the delay sound more muted in tone. If 'BYPASS' is selected, the high frequency range will not be cut.");
		setupParameter("Effect Balance", 0x11, 0, 100, 50, dryWetBalanceStrings, "Specifies the volume balance between the original sound and the reverberation. With a setting of 'D100 : 0W' no reverb sound will be output.");
		setupParameter("Output Level", 0x12, 0, 127, 127);
		setupParameter("", 0x13, 0, 127);
		setupParameter("", 0x14, 0, 127);
		setupParameter("", 0x15, 0, 127);
		setupParameter("", 0x16, 0, 127);
		setupParameter("", 0x17, 0, 127);
		setupParameter("", 0x18, 0, 127);
		setupParameter("", 0x19, 0, 127);
		break;
	case 23: // GATE REVERB
		m_EffectDescription = "This is a type of reverb, in which the reverberation is cut off before the natural completion of its decay.";
		setupParameter("Gate Gate Type", 0x0E, 0, 3, 0, StringArray::fromTokens("NORMAL REVERSE SWEEP1 SWEEP2", false), "Select one of the following four basic types of gated reverb.\r\nAvailable Settings:\r\nNORMAL: Normal gated reverb\r\nREVERSE: Reverse-playback reverb\r\nSWEEP1: The reverberation will sweep from right to left.\r\nSWEEP2: The reverberation will sweep from left to right.\r\n");
		setupParameter("Gate Gate Time", 0x0F, 0, 65, 19, StringArray::fromTokens("5 10 15 20 25 30 35 40 45 50 55 60 65 70 75 80 85 90 95 100 105 110 115 120 125 130 135 140 145 150 155 160 165 170 175 180 185 190 195 200 205 210 215 220 225 230 235 240 245 250 255 260 265 270 275 280 285 290 295 300 305 310 315 320 325 330", false), "Specifies the time from when the reverberation begins until it ends.");
		setupParameter("Effect Balance", 0x10, 0, 100, 50, dryWetBalanceStrings, "Specifies the volume balance between the original sound and the reverberation. With a setting of 'D100 : 0W' no reverb sound will be output.");
		setupParameter("Output Level", 0x11, 0, 127, 127);
		setupParameter("", 0x12, 0, 127);
		setupParameter("", 0x13, 0, 127);
		setupParameter("", 0x14, 0, 127);
		setupParameter("", 0x15, 0, 127);
		setupParameter("", 0x16, 0, 127);
		setupParameter("", 0x17, 0, 127);
		setupParameter("", 0x18, 0, 127);
		setupParameter("", 0x19, 0, 127);
		break;
	case 24: // ISOLATOR
		m_EffectDescription = "An equalizer which cuts the volume greatly, allowing you to add a special effect to the sound by cutting the volume in varying ranges.\r\nThe Isolator parameters are, in general, effective when applied to the following musical instruments.\r\n- LOW: Bass drums and basses\r\n- MID: Vocals and the like\r\n- HIGH: High-pitched musical instruments such as cymbals\r\nA combination of the Isolator and the GRAB switch provides an instantaneous rhythm beating effect.";
		setupParameter("Low Gain", 0x0E, 0, 127, 127, StringArray(), "Specifies the amount of low-frequency range to be cut.");
		setupParameter("Mid Gain", 0x0F, 0, 127, 127, StringArray(), "Specifies the amount of mid-range to be cut.");
		setupParameter("High Gain", 0x10, 0, 127, 127, StringArray(), "Specifies the amount of high-frequency range to be cut.");
		setupParameter("Output Pan", 0x11, 0, 127, 64, panPosStrings, "Specifies the stereo position of the sound output from the effect.");
		setupParameter("Output Level", 0x12, 0, 127, 127);
		setupParameter("", 0x13, 0, 127);
		setupParameter("", 0x14, 0, 127);
		setupParameter("", 0x15, 0, 127);
		setupParameter("", 0x16, 0, 127);
		setupParameter("", 0x17, 0, 127);
		setupParameter("", 0x18, 0, 127);
		setupParameter("", 0x19, 0, 127);
		break;
	default:
		m_EffectDescription = String::empty;
		setupParameter("M-FX Parameter 1", 0x0E, 0, 127, 0);
		setupParameter("M-FX Parameter 2", 0x0F, 0, 127, 15);
		setupParameter("M-FX Parameter 3", 0x10, 0, 127, 0);
		setupParameter("M-FX Parameter 4", 0x11, 0, 127, 15);
		setupParameter("M-FX Parameter 5", 0x12, 0, 127, 7);
		setupParameter("M-FX Parameter 6", 0x13, 0, 127, 1);
		setupParameter("M-FX Parameter 7", 0x14, 0, 127, 15);
		setupParameter("M-FX Parameter 8", 0x15, 0, 127, 7);
		setupParameter("M-FX Parameter 9", 0x16, 0, 127, 1);
		setupParameter("M-FX Parameter 10", 0x17, 0, 127, 15);
		setupParameter("M-FX Parameter 11", 0x18, 0, 127, 127);
		setupParameter("M-FX Parameter 12", 0x19, 0, 127);
		break;
	}
}

// delayType must by of 0..1 (short / long)
void PartInfoCommonBlock::refreshParametersForDelayTypeValue(uint8 delayType)
{
	if (delayType == 0)	// short
	{
		setupParameter("Delay Time", 0x25, 0, 120, 114, StringArray::fromTokens("0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0 1.1 1.2 1.3 1.4 1.5 1.6 1.7 1.8 1.9 2.0 2.5 3.0 3.5 4.0 4.5 5.0 5.5 6.0 6.5 7.0 7.5 8.0 8.5 9.0 9.5 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 33 34 35 36 37 38 39 40 41 42 43 44 45 46 47 48 49 50 55 60 65 70 75 80 85 90 95 100 105 110 115 120 125 130 135 140 145 150 155 160 165 170 175 180 185 190 195 200 205 210 215 220 225 230 235 240 245 250 255 260 265 270 275", false),
			"Adjusts the time from the original sound until when the delayed sound is heard(the interval between repeats).");
	}
	else if (delayType == 1) // long
	{
		setupParameter("Delay Time", 0x25, 0, 120, 114, StringArray::fromTokens("200,205,210,215,220,225,230,235,240,245,250,255,260,265,270,275,280,285,290,295,300,305,310,315,320,325,330,335,340,345,350,355,360,365,370,375,380,385,390,395,400,405,410,415,420,425,430,435,440,445,450,455,460,465,470,475,480,485,490,495,500,510,520,530,540,550,560,570,580,590,600,610,620,630,640,650,660,670,680,690,700,710,720,730,740,750,760,770,780,790,800,810,820,830,840,850,860,870,880,890,900,910,920,930,940,950,960,970,980,990,1000,Sixteenth Note (1/16),Eighth Triplet (1/12),Dotted Sixteenth (3/32),Eighth Note (1/8),Quarter Triplet (1/6),Dotted Eighth (3/16),Quarter Note (1/4),Half Tiplet (1/3),Dotted Quarter (3/8),Half Note (1/2)", ",", ""),
			"Adjusts the time from the original sound until when the delayed sound is heard(the interval between repeats).\r\nIt is not possible to set a delay time longer than 1000 ms (1 second). When the delay time is synchronized to the BPM, selecting a note value which would make the delay time exceed 1000 ms will cause the delay time to be halved, and the delay sound will be heard at 1/2 the specified interval. In addition, even if 1/2 the length would exceed 1000 ms, the delay time will be shortened to 1/4 the length.");
	}
}

// ----------------------------------------------------------------------------

PartInfoPartBlock::PartInfoPartBlock(AllParts part) :
	GrooveboxMemoryBlock(0x01001000 | (uint8)part << 8, "Patch Info, Part Mixer Setup", "1-2-2", 0x1A),
	m_part(part)
{
	m_name = "Part Info Part " + String::charToString(m_part == PartR ? 'R' : (char)49 + (char)m_part);	// 49 is ascii character '1';
	StringArray panPosStrings; for (int i = -64; i <= 63; i++)
	{
		if (i < 0)
		{
			String s = String(-i);
			String s2("L" + s);
			panPosStrings.add(s2);
		}
		else if (i == 0)
		{
			panPosStrings.add("0");
		}
		else if (i > 0)
		{
			String s = String(i);
			String s2("R" + s);
			panPosStrings.add(s2);
		}
	}
	StringArray keyShiftStrings; for (int i = -48; i <= 48; i++)
	{
		if (i <= 0) keyShiftStrings.add(String(i));
		else keyShiftStrings.add("+" + String(i));
	}
	StringArray fineTuneStrings; for (int i = -50; i <= 50; i++)
	{
		if (i<0) fineTuneStrings.add(String(i) + " cent");
		else if (i == 0) fineTuneStrings.add(String(i));
		else if (i>0) fineTuneStrings.add("+" + String(i));
	}
	setupParameter("Receive Switch", 0x00, 0, 1, 1, StringArray::fromTokens("OFF ON", false), "Specifies whether or not MIDI messages from MIDI IN will be received by Part " + String((part == PartR ? 'R' : (uint8)part + 1)) + ".\r\nIf this is 'OFF', the part " + String((part == PartR ? 'R' : (uint8)part + 1)) + " cannot be played from an external MIDI device.");
	setupParameter("Patch Group Type", 0x02, 0, 3, 0);	// use getPatchGroupNameByTypeAndID for display
	setupParameter("Patch Group ID", 0x03, 0, 127, 3);	// use getPatchGroupNameByTypeAndID for display
	setupParameter("Patch Number", 0x04, 0, 254, 0);	// a 2 byte parameter, will automatically handled as ms / ls nibble, told by the maximum above 127
	/*setupParameter("Patch Number MS Nibble", 0x04, 0, 0xF);
	setupParameter("Patch Number LS Nibble", 0x05, 0, 0xF);*/
	String partCharacter(part == PartR ? String::charToString('R') : String::charToString((char)49 + (char)part));	// 49 is ascii character '1'

	setupParameter("Part " + partCharacter + " Level", 0x06, 0, 127, 115, StringArray(), String::empty, 7, false);
	setupParameter("Part " + partCharacter + " Pan", 0x07, 0, 127, 64, panPosStrings, String::empty, 10, false);
	setupParameter("Part " + partCharacter + " Key Shift", 0x08, 0, 96, 48, keyShiftStrings, String::empty, 85, true);
	setupParameter("Part " + partCharacter + " Fine Tune", 0x09, 0, 100, 50, fineTuneStrings);
	setupParameter("Part " + partCharacter + " M-FX Switch", 0x0A, 0, 4, 0, StringArray::fromTokens("OFF,ON, , ,RHY", ",", ""), String::empty, 86, true);

	setupParameter("Delay Send Level", 0x0C, 0, 127, 0, StringArray(), String::empty, 94, false);
	setupParameter("Reverb Send Level", 0x0D, 0, 127, 0, StringArray(), String::empty, 91, false);
}

String PartInfoPartBlock::getPatchGroupNameByTypeAndID(uint8 patchGroupType, uint8 patchGroupId)
{
	if (m_part == PartR)
	{
		if (patchGroupType == 0 && patchGroupId == 3) return "Preset A";
		else if (patchGroupType == 0 && patchGroupId == 4) return "Preset B";
		else if (patchGroupType == 3 && patchGroupId == 1) return "User A";
	}
	else
	{
		if (patchGroupType == 0 && patchGroupId == 3) return "Preset A";
		else if (patchGroupType == 0 && patchGroupId == 4) return "Preset B";
		else if (patchGroupType == 0 && patchGroupId == 5) return "Preset C";
		else if (patchGroupType == 0 && patchGroupId == 6) return "Preset D";
		else if (patchGroupType == 0 && patchGroupId == 7) return "Preset E";
		else if (patchGroupType == 0 && patchGroupId == 8) return "Preset F";
		else if (patchGroupType == 0 && patchGroupId == 9) return "Preset G";
		else if (patchGroupType == 3 && patchGroupId == 1) return "User A";
		else if (patchGroupType == 3 && patchGroupId == 2) return "User B";
	}

	return String::empty;
}

uint8 PartInfoPartBlock::getNumPatchesInGroup(uint8 patchGroupType, uint8 patchGroupId)
{
	if (m_part == PartR)
	{
		if (patchGroupType == 0 && patchGroupId == 3) return 25;
		else if (patchGroupType == 0 && patchGroupId == 4) return 13;
		else if (patchGroupType == 3 && patchGroupId == 1) return 19;
	}
	else
	{
		if (patchGroupType == 0 && patchGroupId == 3) return 128;
		else if (patchGroupType == 0 && patchGroupId == 4) return 128;
		else if (patchGroupType == 0 && patchGroupId == 5) return 128;
		else if (patchGroupType == 0 && patchGroupId == 6) return 128;
		else if (patchGroupType == 0 && patchGroupId == 7) return 128;
		else if (patchGroupType == 0 && patchGroupId == 8) return 128;
		else if (patchGroupType == 0 && patchGroupId == 9) return 32;
		else if (patchGroupType == 3 && patchGroupId == 1) return 128;
		else if (patchGroupType == 3 && patchGroupId == 2) return 128;
	}
	return 0;
}

void PartInfoPartBlock::getBankSelMSB_LSBforGroup(uint8 patchGroupType, uint8 patchGroupId, uint8& msb, uint8& lsb)
{
	if (m_part == PartR)
	{
		if (patchGroupType == 0 && patchGroupId == 3) { msb = 81; lsb = 0; }
		else if (patchGroupType == 0 && patchGroupId == 4) { msb = 83; lsb = 0; }
		else if (patchGroupType == 3 && patchGroupId == 1) { msb = 85; lsb = 0; }
	}
	else
	{
		if (patchGroupType == 0 && patchGroupId == 3) { msb = 81; lsb = 0; }
		else if (patchGroupType == 0 && patchGroupId == 4) { msb = 81; lsb = 1; }
		else if (patchGroupType == 0 && patchGroupId == 5) { msb = 81; lsb = 2; }
		else if (patchGroupType == 0 && patchGroupId == 6) { msb = 81; lsb = 3; }
		else if (patchGroupType == 0 && patchGroupId == 7) { msb = 83; lsb = 0; }
		else if (patchGroupType == 0 && patchGroupId == 8) { msb = 83; lsb = 1; }
		else if (patchGroupType == 0 && patchGroupId == 9) { msb = 83; lsb = 2; }
		else if (patchGroupType == 3 && patchGroupId == 1) { msb = 85; lsb = 0; }
		else if (patchGroupType == 3 && patchGroupId == 2) { msb = 85; lsb = 1; }
	}
}

void PartInfoPartBlock::getGroupFromBankSelMSB_LSB(uint8 msb, uint8 lsb, uint8 &patchGroupType, uint8 &patchGroupId)
{
	if (m_part == PartR)
	{
		if (msb == 81 && lsb == 0) { patchGroupType = 0; patchGroupId = 3; }
		else if (msb == 83 && lsb == 0) { patchGroupType = 0; patchGroupId = 4; }
		else if (msb == 85 && lsb == 0) { patchGroupType = 3; patchGroupId = 1; }
	}
	else
	{
		if (msb == 81 && lsb == 0) { patchGroupType = 0; patchGroupId = 3; }
		else if (msb == 81 && lsb == 1) { patchGroupType = 0; patchGroupId = 5; }
		else if (msb == 81 && lsb == 2) { patchGroupType = 0; patchGroupId = 5; }
		else if (msb == 81 && lsb == 3) { patchGroupType = 0; patchGroupId = 6; }
		else if (msb == 83 && lsb == 0) { patchGroupType = 0; patchGroupId = 7; }
		else if (msb == 83 && lsb == 1) { patchGroupType = 0; patchGroupId = 8; }
		else if (msb == 83 && lsb == 2) { patchGroupType = 0; patchGroupId = 9; }
		else if (msb == 85 && lsb == 0) { patchGroupType = 3; patchGroupId = 1; }
		else if (msb == 85 && lsb == 1) { patchGroupType = 3; patchGroupId = 2; }
	}
}

void PartInfoPartBlock::handleCC(uint8 channel, uint8 controllerType, uint8 value)
{
	if (m_part == (uint8)channel)
	{
		switch (controllerType)
		{
		case 07: m_data[0x06] = uint8(value); break;
		case 10: m_data[0x07] = uint8(value); break;
		case 85: m_data[0x08] = uint8(value); break;
		case 91: m_data[0x0D] = uint8(value); break;
		case 94: m_data[0x0C] = uint8(value); break;
		case 86: m_data[0x0A] = uint8(value); break;
		default:break;
		}
		// TODO: if not coming from midi in port that is part of active connection to groovebox, send to midiout (should be handled outside this, in mini in handler or so...)
	}
}

// ----------------------------------------------------------------------------

PartInfoBlock::PartInfoBlock() :
	GrooveboxMemoryBlock(0x01000000, "Part Info Common Block and 7 + R Part Info Common Blocks", "1-2")
{
	m_name = "Part Info";
	addSubBlock(new PartInfoCommonBlock());
	addSubBlock(new PartInfoPartBlock(Part1));
	addSubBlock(new PartInfoPartBlock(Part2));
	addSubBlock(new PartInfoPartBlock(Part3));
	addSubBlock(new PartInfoPartBlock(Part4));
	addSubBlock(new PartInfoPartBlock(Part5));
	addSubBlock(new PartInfoPartBlock(Part6));
	addSubBlock(new PartInfoPartBlock(Part7));
	addSubBlock(new PartInfoPartBlock(PartR));
}

PartInfoPartBlock* PartInfoBlock::getPartInfoPartBlockPtr(AllParts part)
{
	switch (part)
	{
	case Part1: return dynamic_cast<PartInfoPartBlock*>(getSubBlock(1));
	case Part2: return dynamic_cast<PartInfoPartBlock*>(getSubBlock(2));
	case Part3: return dynamic_cast<PartInfoPartBlock*>(getSubBlock(3));
	case Part4: return dynamic_cast<PartInfoPartBlock*>(getSubBlock(4));
	case Part5: return dynamic_cast<PartInfoPartBlock*>(getSubBlock(5));
	case Part6: return dynamic_cast<PartInfoPartBlock*>(getSubBlock(6));
	case Part7: return dynamic_cast<PartInfoPartBlock*>(getSubBlock(7));
	case PartR: return dynamic_cast<PartInfoPartBlock*>(getSubBlock(8));
	default: return nullptr;
	}
}

// ----------------------------------------------------------------------------