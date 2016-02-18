/*
  ==============================================================================

    PatternSetupBlock.cpp
    Created: 18 Feb 2016 10:16:15am
    Author:  Spindler

  ==============================================================================
*/

#include "PatternSetupBlock.h"
/*static */const unsigned int BeatSignature::ALLOWED_FRACTIONS_SIZE = 17;
/*static */const float BeatSignature::allowedFractions[ALLOWED_FRACTIONS_SIZE] = { 0.5f, 0.5625f, 0.625f, 0.6875f, 0.75f, 0.75f, 0.8125f, 0.875f, 0.9375f, 1.0f, 1.0625f, 1.125f, 1.1875f, 1.25f, 1.5f, 1.5f, 1.75f };
/*static*/ const uint8 BeatSignature::allowedFractionNumerators[ALLOWED_FRACTIONS_SIZE] =   { 2,  9, 5, 11, 3, 6, 13, 7, 15, 4, 17, 9, 19, 5, 6, 12, 7 };
/*static*/ const uint8 BeatSignature::allowedFractionDenominators[ALLOWED_FRACTIONS_SIZE] = { 4, 16, 8, 16, 4, 8, 16, 8, 16, 4, 16, 8, 16, 4, 4,  8, 4 };

// if signature is not allowed, the one with the nearest fraction is taken
BeatSignature::BeatSignature(uint8 numerator, uint8 denominator) :
	m_numerator(numerator),
	m_denominator(denominator)
{
	float fraction = getAsFraction();
	bool fractionIsOkay = false;
	
	unsigned int indexOfLeastDiff = 0;
	float leastDiff = FLT_MAX; // indefinite by default

	for (unsigned int i = 0; i < ALLOWED_FRACTIONS_SIZE; i++)
	{
		// found allowed fraction
		if (fraction == allowedFractions[i])
		{
			// for correction of 2/2 ==> 4/4 etc
			m_numerator = allowedFractionNumerators[i];
			m_denominator = allowedFractionDenominators[i];
			// abort search no further correction needed
			fractionIsOkay = true;
			break;
		}
		// update least diff and index of least diff if smaller
		else if (abs(allowedFractions[i] - fraction) < leastDiff)
		{
			leastDiff = abs(allowedFractions[i] - fraction);
			indexOfLeastDiff = i;
		}
	}

	// if fraction not in allowed correct to nearest
	if (!fractionIsOkay)
	{
		m_numerator = allowedFractionNumerators[indexOfLeastDiff];
		m_denominator = allowedFractionDenominators[indexOfLeastDiff];
	}
}

// === PatternSetupConfigBlock: ===============================================

// eg. 138.8 converts to 3 6 3 8
/*static*/ void PatternSetupConfigBlock::convertTempoBpmIntoByteValues(float bpm, uint8 &byte1, uint8 &byte2, uint8 &byte3, uint8 &byte4)
{
	int bpm100 = roundToInt<float>(bpm * 100.0f);	// e.g. 138.8 * 100 = 13880 = 0x3638
	byte1 = bpm100 >> 0xC & 0xF;	// e.g. 3
	byte2 = bpm100 >> 0x8 & 0xF;	// e.g. 6
	byte3 = bpm100 >> 0x4 & 0xF;	// e.g. 3
	byte4 = bpm100 >> 0x0 & 0xF;	// e.g. 8
}
// eg. 3 6 3 8 converts into 138.8
/*static*/ float PatternSetupConfigBlock::convertTempoByteValuesIntoBPM(uint8 byte1, uint8 byte2, uint8 byte3, uint8 byte4)
{
	return (float)((byte1 * 0x1000 + byte2 * 0x100 + byte3 * 0x10 + byte4 * 0x1) / 10) / 10.0f;
}

PatternSetupConfigBlock::PatternSetupConfigBlock() :
	GrooveboxMemoryBlock(0x30000000, "Pattern Setup Header, Mute States and Sequencer Out for Parts", "", 0x77)
{
	m_name = "Pattern Setup Config";

	StringArray asciiCharacters;
	asciiCharacters.add(" ");
	asciiCharacters.addTokens("! \" # $ % & ' ( ) * + , - . / 0 1 2 3 4 5 6 7 8 9 : ; < = > ? @ A B C D E F G H I J K L M N O P Q R S T U V W X Y Z [ \\ ] ^ _ ` a b c d e f g h i j k l m n o p q r s t u v w x y z { | }", false);
	
	setupParameter("Pattern Name  1", 0x00, 32, 125, 32, asciiCharacters, "Name assigned to the pattern.");
	setupParameter("Pattern Name  2", 0x01, 32, 125, 32, asciiCharacters, "Name assigned to the pattern.");
	setupParameter("Pattern Name  3", 0x02, 32, 125, 32, asciiCharacters, "Name assigned to the pattern.");
	setupParameter("Pattern Name  4", 0x03, 32, 125, 32, asciiCharacters, "Name assigned to the pattern.");
	setupParameter("Pattern Name  5", 0x04, 32, 125, 32, asciiCharacters, "Name assigned to the pattern.");
	setupParameter("Pattern Name  6", 0x05, 32, 125, 32, asciiCharacters, "Name assigned to the pattern.");
	setupParameter("Pattern Name  7", 0x06, 32, 125, 32, asciiCharacters, "Name assigned to the pattern.");
	setupParameter("Pattern Name  8", 0x07, 32, 125, 32, asciiCharacters, "Name assigned to the pattern.");
	setupParameter("Pattern Name  9", 0x08, 32, 125, 32, asciiCharacters, "Name assigned to the pattern.");
	setupParameter("Pattern Name 10", 0x09, 32, 125, 32, asciiCharacters, "Name assigned to the pattern.");
	setupParameter("Pattern Name 11", 0x0A, 32, 125, 32, asciiCharacters, "Name assigned to the pattern.");
	setupParameter("Pattern Name 12", 0x0B, 32, 125, 32, asciiCharacters, "Name assigned to the pattern.");
	setupParameter("Pattern Name 13", 0x0C, 32, 125, 32, asciiCharacters, "Name assigned to the pattern.");
	setupParameter("Pattern Name 14", 0x0D, 32, 125, 32, asciiCharacters, "Name assigned to the pattern.");
	setupParameter("Pattern Name 15", 0x0E, 32, 125, 32, asciiCharacters, "Name assigned to the pattern.");

	setupParameter("Beat Signature Numerator", 0x10, 2, 19, 4);
	setupParameter("Beat Signature Denominator", 0x11, 4, 16, 4);
	setupParameter("Measures", 0x12, 0, 32, 4, StringArray(),"Pattern lenght as number of measures.");

	// use convertTempoBpmIntoByteValues and convertTempoByteValuesIntoBPM on these
	setupParameter("Tempo Byte 1", 0x13, 0, 0xF, 0x0, StringArray());
	setupParameter("Tempo Byte 2", 0x14, 0, 0xF, 0x0, StringArray());
	setupParameter("Tempo Byte 3", 0x15, 0, 0xF, 0x0, StringArray());
	setupParameter("Tempo Byte 4", 0x16, 0, 0xF, 0x0, StringArray());

	StringArray muteStateStringsParts567 = StringArray::fromTokens("5 ON, 6 ON, 7 ON;5 MT, 6 ON, 7 ON;5 ON, 6 MT, 7 ON;5 MT, 6 MT, 7 ON;5 ON, 6 ON, 7 MT;5 MT, 6 ON, 7 MT;5 ON, 6 MT, 7 MT;5 MT, 6 MT, 7 MT", ";", "");
	setupParameter("Mute Parts 5, 6, 7", 0x1F, 0, 7, 0, muteStateStringsParts567, "Flags for muting Parts 5, 6 and 7");
	StringArray muteStateStringsParts4321 = StringArray::fromTokens("1 ON, 2 ON, 3 ON, 4 ON;1 MT, 2 ON, 3 ON, 4 ON;1 ON, 2 MT, 3 ON, 4 ON;1 MT, 2 MT, 3 ON, 4 ON;1 ON, 2 ON, 3 MT, 4 ON;1 MT, 2 ON, 3 MT, 4 ON;1 ON, 2 MT, 3 MT, 4 ON;1 MT, 2 MT, 3 MT, 4 ON;1 ON, 2 ON, 3 ON, 4 MT;1 MT, 2 ON, 3 ON, 4 MT;1 ON, 2 MT, 3 ON, 4 MT;1 MT, 2 MT, 3 ON, 4 MT;1 ON, 2 ON, 3 MT, 4 MT;1 MT, 2 ON, 3 MT, 4 MT;1 ON, 2 MT, 3 MT, 4 MT;1 MT, 2 MT, 3 MT, 4 MT", ";", "");
	setupParameter("Mute Parts 1, 2, 3, 4", 0x20, 0, 15, 0, muteStateStringsParts4321, "Flags for muting Parts 1, 2, 3 and 4");
	setupParameter("Mute MUTE CTRL", 0x21, 0, 4, 0, StringArray::fromTokens("MUTE-CTRL ON; MUTE-CTRL ON; MUTE-CTRL ON; MUTE-CTRL ON; MUTE-CTRL MT;", ";", ""), "Flag for muting the MUTE CTRL part");
	
	setupParameter("Mute Part R", 0x22, 0, 2, 0, StringArray::fromTokens("R ON; R ON; R MT", ";", ""), "Flag for muting Part R");
	StringArray muteStateStringsRhyGrp8765 = StringArray::fromTokens("CYM ON, TOM/PERC ON, HIT ON, OTHERS ON;CYM MT, TOM/PERC ON, HIT ON, OTHERS ON;CYM ON, TOM/PERC MT, HIT ON, OTHERS ON;CYM MT, TOM/PERC MT, HIT ON, OTHERS ON;CYM ON, TOM/PERC ON, HIT MT, OTHERS ON;CYM MT, TOM/PERC ON, HIT MT, OTHERS ON;CYM ON, TOM/PERC MT, HIT MT, OTHERS ON;CYM MT, TOM/PERC MT, HIT MT, OTHERS ON;CYM ON, TOM/PERC ON, HIT ON, OTHERS MT;CYM MT, TOM/PERC ON, HIT ON, OTHERS MT;CYM ON, TOM/PERC MT, HIT ON, OTHERS MT;CYM MT, TOM/PERC MT, HIT ON, OTHERS MT;CYM ON, TOM/PERC ON, HIT MT, OTHERS MT;CYM MT, TOM/PERC ON, HIT MT, OTHERS MT;CYM ON, TOM/PERC MT, HIT MT, OTHERS MT;CYM MT, TOM/PERC MT, HIT MT, OTHERS MT", ";","");
	setupParameter("Mute CYM, TOM/PERC, HIT, OTHERS", 0x2F, 0, 15, 0, muteStateStringsRhyGrp8765, "Flags for muting rhythm groups CYM, TOM/PERC, HIT and OTHERS");
	StringArray muteStateStringsRhyGrp4321 = StringArray::fromTokens("BD ON, SD ON, HH ON, CLP ON;BD MT, SD ON, HH ON, CLP ON;BD ON, SD MT, HH ON, CLP ON;BD MT, SD MT, HH ON, CLP ON;BD ON, SD ON, HH MT, CLP ON;BD MT, SD ON, HH MT, CLP ON;BD ON, SD MT, HH MT, CLP ON;BD MT, SD MT, HH MT, CLP ON;BD ON, SD ON, HH ON, CLP MT;BD MT, SD ON, HH ON, CLP MT;BD ON, SD MT, HH ON, CLP MT;BD MT, SD MT, HH ON, CLP MT;BD ON, SD ON, HH MT, CLP MT;BD MT, SD ON, HH MT, CLP MT;BD ON, SD MT, HH MT, CLP MT;BD MT, SD MT, HH MT, CLP MT", ";", "");
	setupParameter("Mute BD, SD, HH, CLP", 0x30, 0, 15, 0, muteStateStringsRhyGrp4321, "Flags for muting rhythm groups BD, SD, HH and CLP");

	StringArray seqOutStrings = StringArray::fromTokens("INT OUT BOTH",false);
	setupParameter("Sequencer Out Part 1", 0x38, 0, 2, 2, seqOutStrings);
	setupParameter("Sequencer Out Part 2", 0x3A, 0, 2, 2, seqOutStrings);
	setupParameter("Sequencer Out Part 3", 0x3C, 0, 2, 2, seqOutStrings);
	setupParameter("Sequencer Out Part 4", 0x3E, 0, 2, 2, seqOutStrings);
	setupParameter("Sequencer Out Part 5", 0x40, 0, 2, 2, seqOutStrings);
	setupParameter("Sequencer Out Part 6", 0x42, 0, 2, 2, seqOutStrings);
	setupParameter("Sequencer Out Part 7", 0x44, 0, 2, 2, seqOutStrings);
	setupParameter("Sequencer Out Part R", 0x4A, 0, 2, 2, seqOutStrings);
}

// returns the pattern name
String PatternSetupConfigBlock::getPatternName()
{
	return String((char*)m_data.getData(), 15);
}

// name will be reduced to allowed ascii characters and max length of 15 characters
void PatternSetupConfigBlock::setPatternName(String name)
{
	for (int i = 0; i < 15 && i < name.length(); i++)
	{
		char c = (char)name[i];
		if (c < 32 || c>125) c = 32;	// fallback to space
		m_data[i] = c;
	}
}

// beat signature getters / setters
BeatSignature PatternSetupConfigBlock::getBeatSignature()
{
	return BeatSignature(m_data[0x10], m_data[0x11]);
}

void PatternSetupConfigBlock::setBeatSignature(uint8 numerator, uint8 denominator)
{
	BeatSignature correctedSig = BeatSignature(numerator, denominator);
	getParameter(0x10)->setValue(correctedSig.getNumerator(), Parameter::GuiWidget);
	getParameter(0x11)->setValue(correctedSig.getDenominator(), Parameter::GuiWidget);
}

uint8 PatternSetupConfigBlock::getPatternLengthInMeasures()
{
	return m_data[0x12];
}

void PatternSetupConfigBlock::setPatternLengthInMeasures(uint8 measures)
{
	m_data[0x12] = (uint8)jlimit<int>(1, 32, measures);
}

// tempo in BPM
float PatternSetupConfigBlock::getTempoBpm()
{
	return convertTempoByteValuesIntoBPM(m_data[0x13], m_data[0x14], m_data[0x15], m_data[0x16]);
}

void PatternSetupConfigBlock::setTempoBpm(float tempoInBpm)
{
	uint8 byte1, byte2, byte3, byte4;
	convertTempoBpmIntoByteValues(tempoInBpm, byte1, byte2, byte3, byte4);
	getParameter(0x13)->setValue(byte1, Parameter::GuiWidget);
	getParameter(0x14)->setValue(byte1, Parameter::GuiWidget);
	getParameter(0x15)->setValue(byte1, Parameter::GuiWidget);
	getParameter(0x16)->setValue(byte1, Parameter::GuiWidget);
}

// checks mute state for part, returns true if muted
bool PatternSetupConfigBlock::isPartMute(PatternBodyBlock::PatternPart part)
{
	switch (part)
	{
	case PatternBodyBlock::Pattern_Part_1:
		return (m_data[0x20] & MUTE_FLAG_PART1) == MUTE_FLAG_PART1;
	case PatternBodyBlock::Pattern_Part_2:
		return (m_data[0x20] & MUTE_FLAG_PART2) == MUTE_FLAG_PART2;
	case PatternBodyBlock::Pattern_Part_3:
		return (m_data[0x20] & MUTE_FLAG_PART3) == MUTE_FLAG_PART3;
	case PatternBodyBlock::Pattern_Part_4:
		return (m_data[0x20] & MUTE_FLAG_PART4) == MUTE_FLAG_PART4;
	case PatternBodyBlock::Pattern_Part_5:
		return (m_data[0x1F] & MUTE_FLAG_PART5) == MUTE_FLAG_PART5;
	case PatternBodyBlock::Pattern_Part_6:
		return (m_data[0x1F] & MUTE_FLAG_PART6) == MUTE_FLAG_PART6;
	case PatternBodyBlock::Pattern_Part_7:
		return (m_data[0x1F] & MUTE_FLAG_PART7) == MUTE_FLAG_PART7;
	case PatternBodyBlock::Pattern_Part_R:
		return (m_data[0x22] & MUTE_FLAG_PARTR) == MUTE_FLAG_PARTR;
	case PatternBodyBlock::Pattern_MuteCtrl:
		return (m_data[0x21] & MUTE_FLAG_MUTE_CTRL) == MUTE_FLAG_MUTE_CTRL;
	case PatternBodyBlock::Pattern_Part_Unknown:
	default:
		return false;
	}
}

// sets the mute state for a part (true) or unmutes it (false)
void PatternSetupConfigBlock::setPartMute(PatternBodyBlock::PatternPart part, bool setMute/* = true*/)
{
	switch (part)
	{
	case PatternBodyBlock::Pattern_Part_1:
		if (setMute) m_data[0x20] |= MUTE_FLAG_PART1;
		else  m_data[0x20] &= ~MUTE_FLAG_PART1;
		break;
	case PatternBodyBlock::Pattern_Part_2:
		if (setMute) m_data[0x20] |= MUTE_FLAG_PART2;
		else  m_data[0x20] &= ~MUTE_FLAG_PART2;
		break;
	case PatternBodyBlock::Pattern_Part_3:
		if (setMute) m_data[0x20] |= MUTE_FLAG_PART3;
		else  m_data[0x20] &= ~MUTE_FLAG_PART3;
		break;
	case PatternBodyBlock::Pattern_Part_4:
		if (setMute) m_data[0x20] |= MUTE_FLAG_PART4;
		else  m_data[0x20] &= ~MUTE_FLAG_PART4;
		break;
	case PatternBodyBlock::Pattern_Part_5:
		if (setMute) m_data[0x1F] |= MUTE_FLAG_PART5;
		else  m_data[0x1F] &= ~MUTE_FLAG_PART5;
		break;
	case PatternBodyBlock::Pattern_Part_6:
		if (setMute) m_data[0x1F] |= MUTE_FLAG_PART6;
		else  m_data[0x1F] &= ~MUTE_FLAG_PART6;
		break;
	case PatternBodyBlock::Pattern_Part_7:
		if (setMute) m_data[0x1F] |= MUTE_FLAG_PART7;
		else  m_data[0x1F] &= ~MUTE_FLAG_PART7;
		break;
	case PatternBodyBlock::Pattern_Part_R:
		if (setMute) m_data[0x22] |= MUTE_FLAG_PARTR;
		else  m_data[0x22] &= ~MUTE_FLAG_PARTR;
		break;
	case PatternBodyBlock::Pattern_MuteCtrl:
		if (setMute) m_data[0x21] |= MUTE_FLAG_MUTE_CTRL;
		else  m_data[0x21] &= ~MUTE_FLAG_MUTE_CTRL;
		break;
	case PatternBodyBlock::Pattern_Part_Unknown:
	default:
		break;
	}
}

// sets the mute state for a rhythm group (true) or unmutes it (false)
void PatternSetupConfigBlock::setRyhGroupMute(PatternBodyBlock::RhythmGroup rhythmGroup, bool setMute/* = true*/)
{
	switch (rhythmGroup)
	{
	case PatternBodyBlock::Rhythm_Group_BD:
		if (setMute) m_data[0x30] |= MUTE_FLAG_BD;
		else  m_data[0x30] &= ~MUTE_FLAG_BD;
		break;
	case PatternBodyBlock::Rhythm_Group_SD:
		if (setMute) m_data[0x30] |= MUTE_FLAG_SD;
		else  m_data[0x30] &= ~MUTE_FLAG_SD;
		break;
	case PatternBodyBlock::Rhythm_Group_HH:
		if (setMute) m_data[0x30] |= MUTE_FLAG_HH;
		else  m_data[0x30] &= ~MUTE_FLAG_HH;
		break;
	case PatternBodyBlock::Rhythm_Group_CLP:
		if (setMute) m_data[0x30] |= MUTE_FLAG_CLP;
		else  m_data[0x30] &= ~MUTE_FLAG_CLP;
		break;
	case PatternBodyBlock::Rhythm_Group_CYM:
		if (setMute) m_data[0x2F] |= MUTE_FLAG_CYM;
		else  m_data[0x2F] &= ~MUTE_FLAG_CYM;
		break;
	case PatternBodyBlock::Rhythm_Group_TomPerc:
		if (setMute) m_data[0x2F] |= MUTE_FLAG_TOMPERC;
		else  m_data[0x2F] &= ~MUTE_FLAG_TOMPERC;
		break;
	case PatternBodyBlock::Rhythm_Group_Hit:
		if (setMute) m_data[0x2F] |= MUTE_FLAG_HIT;
		else  m_data[0x2F] &= ~MUTE_FLAG_HIT;
		break;
	case PatternBodyBlock::Rhythm_Group_Others:
		if (setMute) m_data[0x2F] |= MUTE_FLAG_OTHERS;
		else  m_data[0x2F] &= ~MUTE_FLAG_OTHERS;
		break;
	case PatternBodyBlock::Rhythm_Group_All:
		if (setMute) { m_data[0x2F] = 15; m_data[0x30] = 15; }
		else { m_data[0x2F] = 0; m_data[0x30] = 0; }
		break;
	case PatternBodyBlock::Rhythm_Group_Unknown:
	default:
		break;
	}
}

// checks mute state for rhythm group, returns true if muted
bool PatternSetupConfigBlock::isRyhGroupMute(PatternBodyBlock::RhythmGroup rhythmGroup)
{
	switch (rhythmGroup)
	{
	case PatternBodyBlock::Rhythm_Group_BD:
		return (m_data[0x30] & MUTE_FLAG_BD) == MUTE_FLAG_BD;
	case PatternBodyBlock::Rhythm_Group_SD:
		return (m_data[0x30] & MUTE_FLAG_SD) == MUTE_FLAG_SD;
	case PatternBodyBlock::Rhythm_Group_HH:
		return (m_data[0x30] & MUTE_FLAG_HH) == MUTE_FLAG_HH;
	case PatternBodyBlock::Rhythm_Group_CLP:
		return (m_data[0x30] & MUTE_FLAG_CLP) == MUTE_FLAG_CLP;
	case PatternBodyBlock::Rhythm_Group_CYM:
		return (m_data[0x2F] & MUTE_FLAG_CYM) == MUTE_FLAG_CYM;
	case PatternBodyBlock::Rhythm_Group_TomPerc:
		return (m_data[0x2F] & MUTE_FLAG_TOMPERC) == MUTE_FLAG_TOMPERC;
	case PatternBodyBlock::Rhythm_Group_Hit:
		return (m_data[0x2F] & MUTE_FLAG_HIT) == MUTE_FLAG_HIT;
	case PatternBodyBlock::Rhythm_Group_Others:
		return (m_data[0x2F] & MUTE_FLAG_OTHERS) == MUTE_FLAG_OTHERS;
	case PatternBodyBlock::Rhythm_Group_All:
		return (m_data[0x2F] == 15 && m_data[0x30] == 15);
	case PatternBodyBlock::Rhythm_Group_Unknown:
	default:
		return false;
	}
}

// 0=INT,1=EXT,2=BOTH
uint8 PatternSetupConfigBlock::getSeqOut(PatternBodyBlock::PatternPart part)
{
	switch (part)
	{
	case PatternBodyBlock::Pattern_Part_1:
		return m_data[0x38];
	case PatternBodyBlock::Pattern_Part_2:
		return m_data[0x3A];
	case PatternBodyBlock::Pattern_Part_3:
		return m_data[0x3C];
	case PatternBodyBlock::Pattern_Part_4:
		return m_data[0x3E];
	case PatternBodyBlock::Pattern_Part_5:
		return m_data[0x40];
	case PatternBodyBlock::Pattern_Part_6:
		return m_data[0x42];
	case PatternBodyBlock::Pattern_Part_7:
		return m_data[0x44];
	case PatternBodyBlock::Pattern_Part_R:
		return m_data[0x4A];
	case PatternBodyBlock::Pattern_MuteCtrl:
	case PatternBodyBlock::Pattern_Part_Unknown:
	default:
		return 0;
	}
}

// 0=INT,1=EXT,2=BOTH
void PatternSetupConfigBlock::setSeqOut(PatternBodyBlock::PatternPart part, uint8 seqOut)
{
	switch (part)
	{
	case PatternBodyBlock::Pattern_Part_1:
		m_data[0x38] = seqOut < 2 ? seqOut : 2;
		break;
	case PatternBodyBlock::Pattern_Part_2:
		m_data[0x3A] = seqOut < 2 ? seqOut : 2;
		break;
	case PatternBodyBlock::Pattern_Part_3:
		m_data[0x3C] = seqOut < 2 ? seqOut : 2;
		break;
	case PatternBodyBlock::Pattern_Part_4:
		m_data[0x3D] = seqOut < 2 ? seqOut : 2;
		break;
	case PatternBodyBlock::Pattern_Part_5:
		m_data[0x40] = seqOut < 2 ? seqOut : 2;
		break;
	case PatternBodyBlock::Pattern_Part_6:
		m_data[0x42] = seqOut < 2 ? seqOut : 2;
		break;
	case PatternBodyBlock::Pattern_Part_7:
		m_data[0x44] = seqOut < 2 ? seqOut : 2;
		break;
	case PatternBodyBlock::Pattern_Part_R:
		m_data[0x4A] = seqOut < 2 ? seqOut : 2;
		break;
	case PatternBodyBlock::Pattern_MuteCtrl:
	case PatternBodyBlock::Pattern_Part_Unknown:
	default:
		break;
	}
}

// === PatternSetupEffectsBlock: ==============================================

PatternSetupEffectsBlock::PatternSetupEffectsBlock()
	:GrooveboxMemoryBlock(0x30002000, "Pattern Setup Effect Settings","",0x24)
{
	m_name = "Pattern Setup Effects";
	
	StringArray mFxTypeNameStrings = StringArray::fromTokens("4BAND EQ,SPECTRUM,ENHANCER,OVERDRIVE,DISTORTION,LO-FI,NOISE,RADIO TUING,PHONOGRAPH,COMPRESSOR,LIMITER,SLICER,TREMOLO,PHASER,CHORUS,SPACE-D,TETRA CHORUS,FLANGER,STEP FLANGER,SHORT DELAY,AUTO PAN,FB PITCH SHIFTER,REVERB,GATE REVERB,ISOLATOR", ",", String::empty);
	setupParameter("M-FX Type", 0x02, 00, 24, 00, mFxTypeNameStrings, "Multi-Effects Type");
	setupParameter("M-FX Parameter 1", 0x03, 0, 127);
	setupParameter("M-FX Parameter 2", 0x04, 0, 127);
	setupParameter("M-FX Parameter 3", 0x05, 0, 127);
	setupParameter("M-FX Parameter 4", 0x06, 0, 127);
	setupParameter("M-FX Parameter 5", 0x07, 0, 127);
	setupParameter("M-FX Parameter 6", 0x08, 0, 127);
	setupParameter("M-FX Parameter 7", 0x09, 0, 127);
	setupParameter("M-FX Parameter 8", 0x0A, 0, 127);
	setupParameter("M-FX Parameter 9", 0x0B, 0, 127);
	setupParameter("M-FX Parameter 10", 0x0C, 0, 127);
	setupParameter("M-FX Parameter 11", 0x0D, 0, 127);
	setupParameter("M-FX Parameter 12", 0x0E, 0, 127);

	setupParameter("M-FX Delay Send Level", 0x11, 0, 127, 20, StringArray(), "Applies the Delay equally to each of the parts with Multi-effects set at ON regardless of the Part Delay Level for each part.");
	setupParameter("M-FX Reverb Send Level", 0x12, 0, 127, 20, StringArray(), "Applies reverb equally to each of the parts with Multi-effects set at ON regardless of the Part Reverb Level for each part.");

	StringArray hfFreqStrings(StringArray::fromTokens("200 Hz, 250 Hz, 315 Hz, 400 Hz, 500 Hz, 630 Hz, 800 Hz, 1000 Hz, 1250 Hz, 1600 Hz, 2000 Hz, 2500 Hz, 3150 Hz, 4000 Hz, 5000 Hz, 6300 Hz, 8000 Hz, BYPASS", ",", ""));
	setupParameter("Reverb Type", 0x18, 0, 7, 2, StringArray::fromTokens("ROOM1 ROOM2 STAGE1 STAGE2 HALL1 HALL2", false), "- ROOM1: Reverb with short decay and high density.\r\n- ROOM2: Reverb with short decay and low density.\r\n- STAGE1: Reverb with much lingering reverberation.\r\n- STAGE2: Reverb with strong early reflections.\r\n- HALL1: Clear-sounding reverb.\r\n- HALL2: Rich-sounding reverb.\r\n");
	setupParameter("Reverb Master Level", 0x19, 0, 127, 127, StringArray(), "You can adjust the overall volume of reverb for the eight parts(rhythm part and parts 1-7).");
	setupParameter("Reverb Time", 0x1A, 0, 127, 90, StringArray(), "You can adjust the time over which the reverberation will continue.");
	setupParameter("Reverb HF Damp", 0x1B, 0, 17, 13, hfFreqStrings, "Specifies the frequency at which the high frequency portions of the reverberation will be cut.\r\nLowering this setting will cause more of the upper frequency content to be cut, making the reverberation more muted. If 'BYPASS' is selected, the high frequency range will not be cut.");

	StringArray feedbackPercentageStrings(StringArray::fromTokens("0% +1% +2% +3% +4% +5% +6% +7% +8% +9% +10% +11% +12% +13% +14% +15% +16% +17% +18% +19% +20% +21% +22% +23% +24% +25% +26% +27% +28% +29% +30% +31% +32% +33% +34% +35% +36% +37% +38% +39% +40% +41% +42% +43% +44% +45% +46% +47% +48% +49% +50% +51% +52% +53% +54% +55% +56% +57% +58% +59% +60% +61% +62% +63% +64% +65% +66% +67% +68% +69% +70% +71% +72% +73% +74% +75% +76% +77% +78% +79% +80% +81% +82% +83% +84% +85% +86% +87% +88% +89% +90% +91% +92% +93% +94% +95% +96% +97% +98%", false));
	setupParameter("Delay Master Level", 0x1D, 0, 127, 127, StringArray(), "This adjusts the volume of the delay sound for all eight parts (the rhythm part and parts 1-7).");
	setupParameter("Delay Type", 0x1E, 0, 1, 1, StringArray::fromTokens("SHORT LONG", false), "- SHORT: A delay which repeats at short intervals.\r\n- LONG: A delay which repeats at long intervals. You can also synchronize the spacing of the repeats to the BPM of the pattern.");
	setupParameter("Delay Time", 0x1F, 0, 120);		// set by refreshParametersForDelayTypeValue
	setupParameter("Delay HF Damp", 0x20, 0, 17, 17, hfFreqStrings, "Specifies the frequency at which the high frequency portions of the delay will be cut.Lowering this setting will cause more of the upper frequency content to be cut, making the delay more muted in tone. If 'BYPASS' is selected, the high frequency range will not be cut.");
	setupParameter("Delay Feedback Level", 0x21, 0, 98, 50, feedbackPercentageStrings, "Sets the amount of delayed sound to be repeated, as a proportion of the original sound.");
	setupParameter("Delay Delay Output Assign", 0x22, 0, 2, 2, StringArray::fromTokens("LINE REV LINE+REV", false), "Allows you to select a destination for the sound after delay has been applied. Selecting LINE outputs the sound to the OUTPUT jacks on the rear panel; selecting REV outputs it to Reverb; or selecting LINE + REV outputs the sound to both the OUTPUT jacks and Reverb.");
}

// === PatternSetupPartBlock: =================================================

PatternSetupPartBlock::PatternSetupPartBlock(AllParts part) :
	GrooveboxMemoryBlock(0x30004000, "Pattern Setup Mixer Part ", "", 9),
	m_part(part)
{
	switch (part)
	{
	case PartR: m_address = 0x30004000; m_description += "R"; break;
	case Part1: m_address = 0x30004100; m_description += "1"; break;
	case Part2: m_address = 0x30004200; m_description += "2"; break;
	case Part3: m_address = 0x30004300; m_description += "3"; break;
	case Part4: m_address = 0x30004400; m_description += "4"; break;
	case Part5: m_address = 0x30004500; m_description += "5"; break;
	case Part6: m_address = 0x30004600; m_description += "6"; break;
	case Part7: m_address = 0x30004700; m_description += "7"; break;
	default: break;
	}
	m_name = m_description;
	
	String partCharacter(part == PartR ? "R" : String::charToString((char)49 + (char)part));	// 49 is ascii character '1'
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

	setupParameter("Part " + partCharacter + " Bank Select MSB", 0x00, 0x00, 0x7F, 81);
	setupParameter("Part " + partCharacter + " Bank Select LSB", 0x01, 0x00, 0x7F, 0);
	setupParameter("Part " + partCharacter + " Progam Change PC", 0x02, 0x00, 0x7F, 0);
	setupParameter("Part " + partCharacter + " Level", 0x03, 0, 127, 115, StringArray(), String::empty, 7, false);
	setupParameter("Part " + partCharacter + " Pan", 0x04, 0, 127, 64, panPosStrings, String::empty, 10, false);
	setupParameter("Part " + partCharacter + " Key Shift", 0x05, 0, 96, 48, keyShiftStrings, String::empty, 85, true);
	setupParameter("Part " + partCharacter + " Delay Send Level", 0x06, 0, 127, 0, StringArray(), String::empty, 94, false);
	setupParameter("Part " + partCharacter + " Reverb Send Level", 0x07, 0, 127, 0, StringArray(), String::empty, 91, false);
	setupParameter("Part " + partCharacter + " M-FX Switch", 0x08, 0, 4, 0, StringArray::fromTokens("OFF,ON, , ,RHY", ",", ""), String::empty, 86, true);
}

// === PatternSetupBlock: =====================================================

PatternSetupBlock::PatternSetupBlock() :
	GrooveboxMemoryBlock(0x30000000, "Pattern Setup Data", "1-5")
{
	m_name = "Pattern Setup";
	addSubBlock(new PatternSetupConfigBlock());
	addSubBlock(new PatternSetupEffectsBlock());
	addSubBlock(new PatternSetupPartBlock(PartR));
	addSubBlock(new PatternSetupPartBlock(Part1));
	addSubBlock(new PatternSetupPartBlock(Part2));
	addSubBlock(new PatternSetupPartBlock(Part3));
	addSubBlock(new PatternSetupPartBlock(Part4));
	addSubBlock(new PatternSetupPartBlock(Part5));
	addSubBlock(new PatternSetupPartBlock(Part6));
	addSubBlock(new PatternSetupPartBlock(Part7));
}

PatternSetupConfigBlock* PatternSetupBlock::getPatternSetupConfigBlockPtr()
{ 
	return dynamic_cast<PatternSetupConfigBlock*>(getSubBlock(0));
}

PatternSetupEffectsBlock* PatternSetupBlock::getPatternSetupEffectsBlockPtr() 
{ 
	return dynamic_cast<PatternSetupEffectsBlock*>(getSubBlock(1));
}

PatternSetupPartBlock* PatternSetupBlock::getPatternSetupPartBlockPtr(AllParts part)
{
	switch (part)
	{
	case PartR: return dynamic_cast<PatternSetupPartBlock*>(getSubBlock(2));
	case Part1: return dynamic_cast<PatternSetupPartBlock*>(getSubBlock(3));
	case Part2: return dynamic_cast<PatternSetupPartBlock*>(getSubBlock(4));
	case Part3: return dynamic_cast<PatternSetupPartBlock*>(getSubBlock(5));
	case Part4: return dynamic_cast<PatternSetupPartBlock*>(getSubBlock(6));
	case Part5: return dynamic_cast<PatternSetupPartBlock*>(getSubBlock(7));
	case Part6: return dynamic_cast<PatternSetupPartBlock*>(getSubBlock(8));
	case Part7: return dynamic_cast<PatternSetupPartBlock*>(getSubBlock(9));
	default: return nullptr;
	}
}