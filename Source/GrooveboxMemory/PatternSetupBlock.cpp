/*
  ==============================================================================

    PatternSetupBlock.cpp
    Created: 18 Feb 2016 10:16:15am
    Author:  Spindler

  ==============================================================================
*/

#include "PatternSetupBlock.h"

#include "OverallMemoryBlock.h"

extern OverallMemoryBlock* grooveboxMemory;

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
			m_numerator = numerator;
			m_denominator = denominator;
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
	
	setupParameter("Pattern Name  1", 0x00, 32, 125, 'E', asciiCharacters, "Name assigned to the pattern.");
	setupParameter("Pattern Name  2", 0x01, 32, 125, 'M', asciiCharacters, "Name assigned to the pattern.");
	setupParameter("Pattern Name  3", 0x02, 32, 125, 'P', asciiCharacters, "Name assigned to the pattern.");
	setupParameter("Pattern Name  4", 0x03, 32, 125, 'T', asciiCharacters, "Name assigned to the pattern.");
	setupParameter("Pattern Name  5", 0x04, 32, 125, 'Y', asciiCharacters, "Name assigned to the pattern.");
	setupParameter("Pattern Name  6", 0x05, 32, 125, ' ', asciiCharacters, "Name assigned to the pattern.");
	setupParameter("Pattern Name  7", 0x06, 32, 125, 'P', asciiCharacters, "Name assigned to the pattern.");
	setupParameter("Pattern Name  8", 0x07, 32, 125, 'A', asciiCharacters, "Name assigned to the pattern.");
	setupParameter("Pattern Name  9", 0x08, 32, 125, 'T', asciiCharacters, "Name assigned to the pattern.");
	setupParameter("Pattern Name 10", 0x09, 32, 125, 'T', asciiCharacters, "Name assigned to the pattern.");
	setupParameter("Pattern Name 11", 0x0A, 32, 125, 'T', asciiCharacters, "Name assigned to the pattern.");
	setupParameter("Pattern Name 12", 0x0B, 32, 125, 'E', asciiCharacters, "Name assigned to the pattern.");
	setupParameter("Pattern Name 13", 0x0C, 32, 125, 'R', asciiCharacters, "Name assigned to the pattern.");
	setupParameter("Pattern Name 14", 0x0D, 32, 125, 'N', asciiCharacters, "Name assigned to the pattern.");
	setupParameter("Pattern Name 15", 0x0E, 32, 125, 32, asciiCharacters, "Name assigned to the pattern.");

	setupParameter("???", 0x0F, 0, 127, 0, StringArray(), "???");

	setupParameter("Beat Signature Numerator", 0x10, 2, 19, 4);
	setupParameter("Beat Signature Denominator", 0x11, 4, 16, 4);
	setupParameter("Measures", 0x12, 0, 32, 4, StringArray(),"Pattern lenght as number of measures.");

	// use convertTempoBpmIntoByteValues and convertTempoByteValuesIntoBPM on these (default of 120.0f * 100 = 12000 = 0x2EE0) 
	setupParameter("Tempo Byte 1", 0x13, 0, 0xF, 0x2, StringArray());
	setupParameter("Tempo Byte 2", 0x14, 0, 0xF, 0xE, StringArray());
	setupParameter("Tempo Byte 3", 0x15, 0, 0xF, 0xE, StringArray());
	setupParameter("Tempo Byte 4", 0x16, 0, 0xF, 0x0, StringArray());

	setupParameter("???", 0x17, 0, 127, 0, StringArray(), "???");
	setupParameter("???", 0x18, 0, 127, 0x0F, StringArray(), "???"); // default found in pattern "Inspired"
	setupParameter("???", 0x19, 0, 127, 0, StringArray(), "???");
	setupParameter("???", 0x1A, 0, 127, 0x02, StringArray(), "???"); // default found in pattern "Inspired"
	setupParameter("???", 0x1B, 0, 127, 0, StringArray(), "???");
	setupParameter("???", 0x1C, 0, 127, 0, StringArray(), "???");
	setupParameter("???", 0x1D, 0, 127, 0, StringArray(), "???");
	setupParameter("???", 0x1E, 0, 127, 0, StringArray(), "???");

	StringArray muteStateStringsParts567 = StringArray::fromTokens("5 ON, 6 ON, 7 ON;5 MT, 6 ON, 7 ON;5 ON, 6 MT, 7 ON;5 MT, 6 MT, 7 ON;5 ON, 6 ON, 7 MT;5 MT, 6 ON, 7 MT;5 ON, 6 MT, 7 MT;5 MT, 6 MT, 7 MT", ";", "");
	setupParameter("Mute Parts 5, 6, 7", 0x1F, 0, 7, 0, muteStateStringsParts567, "Flags for muting Parts 5, 6 and 7");
	StringArray muteStateStringsParts4321 = StringArray::fromTokens("1 ON, 2 ON, 3 ON, 4 ON;1 MT, 2 ON, 3 ON, 4 ON;1 ON, 2 MT, 3 ON, 4 ON;1 MT, 2 MT, 3 ON, 4 ON;1 ON, 2 ON, 3 MT, 4 ON;1 MT, 2 ON, 3 MT, 4 ON;1 ON, 2 MT, 3 MT, 4 ON;1 MT, 2 MT, 3 MT, 4 ON;1 ON, 2 ON, 3 ON, 4 MT;1 MT, 2 ON, 3 ON, 4 MT;1 ON, 2 MT, 3 ON, 4 MT;1 MT, 2 MT, 3 ON, 4 MT;1 ON, 2 ON, 3 MT, 4 MT;1 MT, 2 ON, 3 MT, 4 MT;1 ON, 2 MT, 3 MT, 4 MT;1 MT, 2 MT, 3 MT, 4 MT", ";", "");
	setupParameter("Mute Parts 1, 2, 3, 4", 0x20, 0, 15, 0, muteStateStringsParts4321, "Flags for muting Parts 1, 2, 3 and 4");
	setupParameter("Mute MUTE CTRL", 0x21, 0, 4, 0, StringArray::fromTokens("MUTE-CTRL ON; MUTE-CTRL ON; MUTE-CTRL ON; MUTE-CTRL ON; MUTE-CTRL MT;", ";", ""), "Flag for muting the MUTE CTRL part");
	
	setupParameter("Mute Part R", 0x22, 0, 2, 0, StringArray::fromTokens("R ON; R ON; R MT", ";", ""), "Flag for muting Part R");

	setupParameter("???", 0x23, 0, 127, 0, StringArray(), "???");
	setupParameter("???", 0x24, 0, 127, 0, StringArray(), "???");
	setupParameter("???", 0x25, 0, 127, 0, StringArray(), "???");
	setupParameter("???", 0x26, 0, 127, 0, StringArray(), "???");
	setupParameter("???", 0x27, 0, 127, 0x02, StringArray(), "???"); // default found in pattern "Inspired"
	setupParameter("???", 0x28, 0, 127, 0x0F, StringArray(), "???"); // default found in pattern "Inspired"
	setupParameter("???", 0x29, 0, 127, 0, StringArray(), "???"); 
	setupParameter("???", 0x2A, 0, 127, 0, StringArray(), "???");
	setupParameter("???", 0x2B, 0, 127, 0, StringArray(), "???");
	setupParameter("???", 0x2C, 0, 127, 0, StringArray(), "???");
	setupParameter("???", 0x2D, 0, 127, 0, StringArray(), "???");
	setupParameter("???", 0x2E, 0, 127, 0, StringArray(), "???");

	StringArray muteStateStringsRhyGrp8765 = StringArray::fromTokens("CYM ON, TOM/PERC ON, HIT ON, OTHERS ON;CYM MT, TOM/PERC ON, HIT ON, OTHERS ON;CYM ON, TOM/PERC MT, HIT ON, OTHERS ON;CYM MT, TOM/PERC MT, HIT ON, OTHERS ON;CYM ON, TOM/PERC ON, HIT MT, OTHERS ON;CYM MT, TOM/PERC ON, HIT MT, OTHERS ON;CYM ON, TOM/PERC MT, HIT MT, OTHERS ON;CYM MT, TOM/PERC MT, HIT MT, OTHERS ON;CYM ON, TOM/PERC ON, HIT ON, OTHERS MT;CYM MT, TOM/PERC ON, HIT ON, OTHERS MT;CYM ON, TOM/PERC MT, HIT ON, OTHERS MT;CYM MT, TOM/PERC MT, HIT ON, OTHERS MT;CYM ON, TOM/PERC ON, HIT MT, OTHERS MT;CYM MT, TOM/PERC ON, HIT MT, OTHERS MT;CYM ON, TOM/PERC MT, HIT MT, OTHERS MT;CYM MT, TOM/PERC MT, HIT MT, OTHERS MT", ";","");
	setupParameter("Mute CYM, TOM/PERC, HIT, OTHERS", 0x2F, 0, 15, 0, muteStateStringsRhyGrp8765, "Flags for muting rhythm groups CYM, TOM/PERC, HIT and OTHERS");
	StringArray muteStateStringsRhyGrp4321 = StringArray::fromTokens("BD ON, SD ON, HH ON, CLP ON;BD MT, SD ON, HH ON, CLP ON;BD ON, SD MT, HH ON, CLP ON;BD MT, SD MT, HH ON, CLP ON;BD ON, SD ON, HH MT, CLP ON;BD MT, SD ON, HH MT, CLP ON;BD ON, SD MT, HH MT, CLP ON;BD MT, SD MT, HH MT, CLP ON;BD ON, SD ON, HH ON, CLP MT;BD MT, SD ON, HH ON, CLP MT;BD ON, SD MT, HH ON, CLP MT;BD MT, SD MT, HH ON, CLP MT;BD ON, SD ON, HH MT, CLP MT;BD MT, SD ON, HH MT, CLP MT;BD ON, SD MT, HH MT, CLP MT;BD MT, SD MT, HH MT, CLP MT", ";", "");
	setupParameter("Mute BD, SD, HH, CLP", 0x30, 0, 15, 0, muteStateStringsRhyGrp4321, "Flags for muting rhythm groups BD, SD, HH and CLP");

	setupParameter("???", 0x31, 0, 127, 0, StringArray(), "???");
	setupParameter("???", 0x32, 0, 127, 0x01, StringArray(), "???"); // default found in pattern "Inspired"
	setupParameter("???", 0x33, 0, 127, 0, StringArray(), "???");
	setupParameter("???", 0x34, 0, 127, 0, StringArray(), "???");
	setupParameter("???", 0x35, 0, 127, 0, StringArray(), "???");
	setupParameter("???", 0x36, 0, 127, 0, StringArray(), "???");
	setupParameter("???", 0x37, 0, 127, 0, StringArray(), "???");

	StringArray seqOutStrings = StringArray::fromTokens("INT OUT BOTH",false);
	setupParameter("Sequencer Out Part 1", 0x38, 0, 2, 2, seqOutStrings);
	setupParameter("???", 0x39, 0, 127, 0, StringArray(), "???");
	setupParameter("Sequencer Out Part 2", 0x3A, 0, 2, 2, seqOutStrings);
	setupParameter("???", 0x3B, 0, 127, 0, StringArray(), "???");
	setupParameter("Sequencer Out Part 3", 0x3C, 0, 2, 2, seqOutStrings);
	setupParameter("???", 0x3D, 0, 127, 0, StringArray(), "???");
	setupParameter("Sequencer Out Part 4", 0x3E, 0, 2, 2, seqOutStrings);
	setupParameter("???", 0x3F, 0, 127, 0, StringArray(), "???");
	setupParameter("Sequencer Out Part 5", 0x40, 0, 2, 2, seqOutStrings);
	setupParameter("???", 0x41, 0, 127, 0, StringArray(), "???");
	setupParameter("Sequencer Out Part 6", 0x42, 0, 2, 2, seqOutStrings);
	setupParameter("???", 0x43, 0, 127, 0, StringArray(), "???");
	setupParameter("Sequencer Out Part 7", 0x44, 0, 2, 2, seqOutStrings);
	setupParameter("???", 0x45, 0, 127, 0, StringArray(), "???");
	setupParameter("???", 0x46, 0, 127, 0, StringArray(), "???");
	setupParameter("???", 0x47, 0, 127, 0, StringArray(), "???");
	setupParameter("???", 0x48, 0, 127, 0, StringArray(), "???");
	setupParameter("???", 0x49, 0, 127, 0, StringArray(), "???");
	setupParameter("Sequencer Out Part R", 0x4A, 0, 2, 2, seqOutStrings);
	setupParameter("???", 0x4B, 0, 127, 0, StringArray(), "???");

	setupParameter("???", 0x4C, 0, 127, 0, StringArray(), "???");
	setupParameter("???", 0x4D, 0, 127, 0, StringArray(), "???");
	setupParameter("???", 0x4E, 0, 127, 0, StringArray(), "???");
	setupParameter("???", 0x4F, 0, 127, 0, StringArray(), "???");
	setupParameter("???", 0x50, 0, 127, 0, StringArray(), "???");
	setupParameter("???", 0x51, 0, 127, 0, StringArray(), "???");
	setupParameter("???", 0x52, 0, 127, 0, StringArray(), "???");
	setupParameter("???", 0x53, 0, 127, 0, StringArray(), "???");
	setupParameter("???", 0x54, 0, 127, 0, StringArray(), "???");
	setupParameter("???", 0x55, 0, 127, 0, StringArray(), "???");
	setupParameter("???", 0x56, 0, 127, 0x02, StringArray(), "???"); // default found in pattern "Inspired"
	setupParameter("???", 0x57, 0, 127, 0, StringArray(), "???");
	setupParameter("???", 0x58, 0, 127, 0, StringArray(), "???");
	setupParameter("???", 0x59, 0, 127, 0, StringArray(), "???");
	setupParameter("???", 0x5A, 0, 127, 0, StringArray(), "???");
	setupParameter("???", 0x5B, 0, 127, 0, StringArray(), "???");
	setupParameter("???", 0x5C, 0, 127, 0, StringArray(), "???");
	setupParameter("???", 0x5D, 0, 127, 0, StringArray(), "???");
	setupParameter("???", 0x5E, 0, 127, 0, StringArray(), "???");
	setupParameter("???", 0x5F, 0, 127, 0, StringArray(), "???");
	setupParameter("???", 0x60, 0, 127, 0, StringArray(), "???");
	setupParameter("???", 0x61, 0, 127, 0, StringArray(), "???");
	setupParameter("???", 0x62, 0, 127, 0, StringArray(), "???");
	setupParameter("???", 0x63, 0, 127, 0, StringArray(), "???");
	setupParameter("???", 0x64, 0, 127, 0, StringArray(), "???");
	setupParameter("???", 0x65, 0, 127, 0, StringArray(), "???");
	setupParameter("???", 0x66, 0, 127, 0, StringArray(), "???");
	setupParameter("???", 0x67, 0, 127, 0, StringArray(), "???");
	setupParameter("???", 0x68, 0, 127, 0, StringArray(), "???");
	setupParameter("???", 0x69, 0, 127, 0, StringArray(), "???");
	setupParameter("???", 0x6A, 0, 127, 0, StringArray(), "???");
	setupParameter("???", 0x6B, 0, 127, 0, StringArray(), "???");
	setupParameter("???", 0x6C, 0, 127, 0, StringArray(), "???");
	setupParameter("???", 0x6D, 0, 127, 0, StringArray(), "???");
	setupParameter("???", 0x6E, 0, 127, 0, StringArray(), "???");
	setupParameter("???", 0x6F, 0, 127, 0, StringArray(), "???");
	setupParameter("???", 0x70, 0, 127, 0, StringArray(), "???");
	setupParameter("???", 0x71, 0, 127, 0, StringArray(), "???");
	setupParameter("???", 0x72, 0, 127, 0, StringArray(), "???");
	setupParameter("???", 0x73, 0, 127, 0, StringArray(), "???");
	setupParameter("???", 0x74, 0, 127, 0, StringArray(), "???");
	setupParameter("???", 0x75, 0, 127, 0, StringArray(), "???");
	setupParameter("???", 0x76, 0, 127, 0, StringArray(), "???");
}

// returns the pattern name
String PatternSetupConfigBlock::getPatternName()
{
	return String((char*)m_data.getData(), 15);
}

// name will be reduced to allowed ascii characters and max length of 15 characters
void PatternSetupConfigBlock::setPatternName(String name)
{
	for (int i = 0; i < 15; i++)
	{
		char c = (i < name.length()) ? (char)name[i] : ' ';
		if (c < 32 || c>125) c = 32;	// fallback to space
		m_data[i] = c;
	}
	getParameter(0x00)->sendChangeMessage();
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

unsigned long PatternSetupConfigBlock::getPatternLengthInTicks()
{
	return m_data[0x12] * m_data[0x10] * (96 / (m_data[0x11] / 4));
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
	getParameter(0x14)->setValue(byte2, Parameter::GuiWidget);
	getParameter(0x15)->setValue(byte3, Parameter::GuiWidget);
	getParameter(0x16)->setValue(byte4, Parameter::GuiWidget);
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

MidiMessage PatternSetupConfigBlock::getPartMuteSysEx(uint8 deviceId, AllParts part)
{
	PatternSetupConfigBlock* patternSetupConfigPtr = grooveboxMemory->getPatternSetupBlock()->getPatternSetupConfigBlockPtr();
	uint8 quickSysExAddress[2]{0x70, 0x01};
	uint8 quickSysExData[2]{(uint8)part, patternSetupConfigPtr->isPartMute((PatternBodyBlock::PatternPart)part) ? 1 : 0};	// DataL: 0-6,9; DataE: none(0), mute(1)
	ScopedPointer<SyxMsg> msg(new SyxMsg(SyxMsg::Type_DT1_Quick, deviceId, quickSysExAddress, quickSysExData, 2, SyxMsg::calcDt1Checksum(quickSysExAddress, 2, quickSysExData, 2)));
	return msg->toMidiMessage();
}

MidiMessage PatternSetupConfigBlock::getRhythmGroupMuteSysEx(uint8 deviceId, PatternBodyBlock::RhythmGroup group)
{
	PatternSetupConfigBlock* patternSetupConfigPtr = grooveboxMemory->getPatternSetupBlock()->getPatternSetupConfigBlockPtr();
	uint8 quickSysExAddress[2]{0x70, 0x02};
	uint8 quickSysExData[2]{(uint8)group, patternSetupConfigPtr->isRyhGroupMute(group) ? 1 : 0};	// DataL: 0-7; DataE: none(0), mute(1)
	ScopedPointer<SyxMsg> msg(new SyxMsg(SyxMsg::Type_DT1_Quick, deviceId, quickSysExAddress, quickSysExData, 2, SyxMsg::calcDt1Checksum(quickSysExAddress, 2, quickSysExData, 2)));
	return msg->toMidiMessage();
}

MidiMessageSequence PatternSetupConfigBlock::getInitalMuteStates(uint8 deviceId)
{
	PatternSetupConfigBlock* patternSetupConfigPtr = grooveboxMemory->getPatternSetupBlock()->getPatternSetupConfigBlockPtr();

	MidiMessageSequence messages;

	PatternBodyBlock::PatternPart pattern_part = PatternBodyBlock::Pattern_Part_R;
	AllParts part = PartR;
	messages.addEvent(SyxMsg::createTextMetaEvent(SyxMsg::TextEvent, String("PART R: ") + (patternSetupConfigPtr->isPartMute(pattern_part) ? "MUTED" : "ON")), 0.0);
	messages.addEvent(getPartMuteSysEx(deviceId, part), 0.0);

	for (int i = 0; i < 7; i++)
	{
		pattern_part = (PatternBodyBlock::PatternPart)i;
		part = (AllParts)i;
		messages.addEvent(SyxMsg::createTextMetaEvent(SyxMsg::TextEvent, "PART " + String(i + 1) + ": " + (patternSetupConfigPtr->isPartMute(pattern_part) ? "MUTED" : "ON")),(double)i+1);
		messages.addEvent(getPartMuteSysEx(deviceId, part), (double)i + 1);
	}

	// mute initial state for rhythm groups
	for (int i = 0x00; i < 0x08; i++)
	{
		PatternBodyBlock::RhythmGroup rhyGrp = (PatternBodyBlock::RhythmGroup)i;
		String rhyGrpName(PatternBodyBlock::PatternEventData::getRhythmGroupString(rhyGrp));
		messages.addEvent(SyxMsg::createTextMetaEvent(SyxMsg::TextEvent, rhyGrpName + ": " + (patternSetupConfigPtr->isRyhGroupMute(rhyGrp) ? "MUTED" : "ON")), (double)i+9);
		messages.addEvent(getRhythmGroupMuteSysEx(deviceId, rhyGrp), (double)i + 9);
	}

	return messages;
}

// === PatternSetupEffectsBlock: ==============================================

/*static*/ const StringArray PatternSetupEffectsBlock::mFxTypeNameStrings = StringArray::fromTokens("4BAND EQ,SPECTRUM,ENHANCER,OVERDRIVE,DISTORTION,LO-FI,NOISE,RADIO TUING,PHONOGRAPH,COMPRESSOR,LIMITER,SLICER,TREMOLO,PHASER,CHORUS,SPACE-D,TETRA CHORUS,FLANGER,STEP FLANGER,SHORT DELAY,AUTO PAN,FB PITCH SHIFTER,REVERB,GATE REVERB,ISOLATOR", ",", "");

PatternSetupEffectsBlock::PatternSetupEffectsBlock() :
	GrooveboxMemoryBlock(0x30002000, "Pattern Setup Effect Settings","",0x24),
	m_partInfoCommonBlockPtr(nullptr)
{
	m_name = "Pattern Setup Effects";
	
	setupParameter("???", 0x00, 0, 127, 0x0C, StringArray(), "???"); // default found in pattern "Inspired"
	setupParameter("???", 0x01, 0, 127, 0, StringArray(), "???");

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

	setupParameter("???", 0x0F, 0, 127, 0, StringArray(), "???");
	setupParameter("???", 0x10, 0, 127, 0x7F, StringArray(), "???"); // default found in pattern "Inspired"

	setupParameter("M-FX Delay Send Level", 0x11, 0, 127, 20, StringArray(), "Applies the Delay equally to each of the parts with Multi-effects set at ON regardless of the Part Delay Level for each part.");
	setupParameter("M-FX Reverb Send Level", 0x12, 0, 127, 20, StringArray(), "Applies reverb equally to each of the parts with Multi-effects set at ON regardless of the Part Reverb Level for each part.");

	setupParameter("???", 0x13, 0, 127, 0x7F, StringArray(), "???"); // default found in pattern "Inspired"
	setupParameter("???", 0x14, 0, 127, 0x7F, StringArray(), "???"); // default found in pattern "Inspired"
	setupParameter("???", 0x15, 0, 127, 0x7F, StringArray(), "???"); // default found in pattern "Inspired"
	setupParameter("???", 0x16, 0, 127, 0x7F, StringArray(), "???"); // default found in pattern "Inspired"
	setupParameter("???", 0x17, 0, 127, 0x01, StringArray(), "???"); // default found in pattern "Inspired"

	StringArray hfFreqStrings(StringArray::fromTokens("200 Hz, 250 Hz, 315 Hz, 400 Hz, 500 Hz, 630 Hz, 800 Hz, 1000 Hz, 1250 Hz, 1600 Hz, 2000 Hz, 2500 Hz, 3150 Hz, 4000 Hz, 5000 Hz, 6300 Hz, 8000 Hz, BYPASS", ",", ""));
	setupParameter("Reverb Type", 0x18, 0, 7, 2, StringArray::fromTokens("ROOM1 ROOM2 STAGE1 STAGE2 HALL1 HALL2", false), "- ROOM1: Reverb with short decay and high density.\r\n- ROOM2: Reverb with short decay and low density.\r\n- STAGE1: Reverb with much lingering reverberation.\r\n- STAGE2: Reverb with strong early reflections.\r\n- HALL1: Clear-sounding reverb.\r\n- HALL2: Rich-sounding reverb.\r\n");
	setupParameter("Reverb Master Level", 0x19, 0, 127, 127, StringArray(), "You can adjust the overall volume of reverb for the eight parts(rhythm part and parts 1-7).");
	setupParameter("Reverb Time", 0x1A, 0, 127, 90, StringArray(), "You can adjust the time over which the reverberation will continue.");
	setupParameter("Reverb HF Damp", 0x1B, 0, 17, 13, hfFreqStrings, "Specifies the frequency at which the high frequency portions of the reverberation will be cut.\r\nLowering this setting will cause more of the upper frequency content to be cut, making the reverberation more muted. If 'BYPASS' is selected, the high frequency range will not be cut.");

	setupParameter("???", 0x1C, 0, 127, 0x01, StringArray(), "???"); // default found in pattern "Inspired"

	StringArray feedbackPercentageStrings(StringArray::fromTokens("0% +1% +2% +3% +4% +5% +6% +7% +8% +9% +10% +11% +12% +13% +14% +15% +16% +17% +18% +19% +20% +21% +22% +23% +24% +25% +26% +27% +28% +29% +30% +31% +32% +33% +34% +35% +36% +37% +38% +39% +40% +41% +42% +43% +44% +45% +46% +47% +48% +49% +50% +51% +52% +53% +54% +55% +56% +57% +58% +59% +60% +61% +62% +63% +64% +65% +66% +67% +68% +69% +70% +71% +72% +73% +74% +75% +76% +77% +78% +79% +80% +81% +82% +83% +84% +85% +86% +87% +88% +89% +90% +91% +92% +93% +94% +95% +96% +97% +98%", false));
	setupParameter("Delay Master Level", 0x1D, 0, 127, 127, StringArray(), "This adjusts the volume of the delay sound for all eight parts (the rhythm part and parts 1-7).");
	setupParameter("Delay Type", 0x1E, 0, 1, 1, StringArray::fromTokens("SHORT LONG", false), "- SHORT: A delay which repeats at short intervals.\r\n- LONG: A delay which repeats at long intervals. You can also synchronize the spacing of the repeats to the BPM of the pattern.");
	setupParameter("Delay Time", 0x1F, 0, 120);		// set by refreshParametersForDelayTypeValue
	setupParameter("Delay HF Damp", 0x20, 0, 17, 17, hfFreqStrings, "Specifies the frequency at which the high frequency portions of the delay will be cut.Lowering this setting will cause more of the upper frequency content to be cut, making the delay more muted in tone. If 'BYPASS' is selected, the high frequency range will not be cut.");
	setupParameter("Delay Feedback Level", 0x21, 0, 98, 50, feedbackPercentageStrings, "Sets the amount of delayed sound to be repeated, as a proportion of the original sound.");
	setupParameter("Delay Delay Output Assign", 0x22, 0, 2, 2, StringArray::fromTokens("LINE REV LINE+REV", false), "Allows you to select a destination for the sound after delay has been applied. Selecting LINE outputs the sound to the OUTPUT jacks on the rear panel; selecting REV outputs it to Reverb; or selecting LINE + REV outputs the sound to both the OUTPUT jacks and Reverb.");

	setupParameter("???", 0x23, 0, 127, 0x01, StringArray(), "???"); // default found in pattern "Inspired"
}

MidiMessageSequence PatternSetupEffectsBlock::getM_FX_SetupMidiMessageSequence(uint8 deviceId)
{
	MidiMessageSequence result;
	// addr 01 00 00 0D,	size 13 (type + 12 params)
	uint8* dt1_address = new uint8[4]{0x01, 0x00, 0x00, 0x0D};
	uint8* dt1_data = new uint8[13]{(uint8)m_data[0x02], (uint8)m_data[0x03], (uint8)m_data[0x04], (uint8)m_data[0x05], (uint8)m_data[0x06], (uint8)m_data[0x07], (uint8)m_data[0x08], (uint8)m_data[0x09], (uint8)m_data[0x0A], (uint8)m_data[0x0B], (uint8)m_data[0x0C], (uint8)m_data[0x0D], (uint8)m_data[0x0E]};
	ScopedPointer<SyxMsg> mFXTypeAndParamsSysex = new SyxMsg(SyxMsg::MessageType::Type_DT1, deviceId, dt1_address, dt1_data, 13, SyxMsg::calcDt1Checksum(dt1_address, 4, dt1_data, 13));
	result.addEvent(SyxMsg::createTextMetaEvent(SyxMsg::TextEvent, "Setup M-FX Type and 12 Parameters (" + mFxTypeNameStrings[m_data[0x02]] + ")"));
	result.addEvent(mFXTypeAndParamsSysex->toMidiMessage());
	delete[] dt1_address;
	delete[] dt1_data;
	return result;
}

MidiMessageSequence PatternSetupEffectsBlock::getReverbSetupMidiMessageSequence(uint8 deviceId)
{
	MidiMessageSequence result;
	// addr 01 00 00 28,	size 04
	uint8* dt1_address = new uint8[4]{0x01, 0x00, 0x00, 0x28};
	uint8* dt1_data = new uint8[4]{(uint8)m_data[0x18], (uint8)m_data[0x19], (uint8)m_data[0x1A], (uint8)m_data[0x1B]};
	ScopedPointer<SyxMsg> reverbParamsSysex = new SyxMsg(SyxMsg::MessageType::Type_DT1, deviceId, dt1_address, dt1_data, 4, SyxMsg::calcDt1Checksum(dt1_address, 4, dt1_data, 4));
	result.addEvent(SyxMsg::createTextMetaEvent(SyxMsg::TextEvent, "Setup Reverb Parameters (Type, Level, Time, HF Damp)"));
	result.addEvent(reverbParamsSysex->toMidiMessage());
	delete[] dt1_address;
	delete[] dt1_data;

	dt1_address = new uint8[4]{0x01, 0x00, 0x00, 0x1D};
	dt1_data = new uint8[1]{(uint8)m_data[0x12]};
	ScopedPointer<SyxMsg> mFXSendReverbLevelSysex = new SyxMsg(SyxMsg::MessageType::Type_DT1, deviceId, dt1_address, dt1_data, 1, SyxMsg::calcDt1Checksum(dt1_address, 4, dt1_data, 1));
	result.addEvent(SyxMsg::createTextMetaEvent(SyxMsg::TextEvent, "M-FX to Reverb Send Level"), 1.0);
	result.addEvent(mFXSendReverbLevelSysex->toMidiMessage(), 1.0);
	delete[] dt1_address;
	delete[] dt1_data;

	return result;
}

MidiMessageSequence PatternSetupEffectsBlock::getDelaySetupMidiMessageSequence(uint8 deviceId)
{
	MidiMessageSequence result;
	// addr 01 00 00 22,	size 06
	uint8* dt1_address = new uint8[4]{0x01, 0x00, 0x00, 0x22};
	uint8* dt1_data = new uint8[6]{(uint8)m_data[0x1D], (uint8)m_data[0x1E], (uint8)m_data[0x20], (uint8)m_data[0x1F], (uint8)m_data[0x21], (uint8)m_data[0x22]};
	ScopedPointer<SyxMsg> delayParamsSysex = new SyxMsg(SyxMsg::MessageType::Type_DT1, deviceId, dt1_address, dt1_data, 6, SyxMsg::calcDt1Checksum(dt1_address, 4, dt1_data, 6));
	result.addEvent(SyxMsg::createTextMetaEvent(SyxMsg::TextEvent, "Setup Delay Parameters (Level, Type, HF Damp, Time, Feedback, Output Assign)"));
	result.addEvent(delayParamsSysex->toMidiMessage());
	delete[] dt1_address;
	delete[] dt1_data;

	dt1_address = new uint8[4]{0x01, 0x00, 0x00, 0x1C};
	dt1_data = new uint8[1]{(uint8)m_data[0x11]};
	ScopedPointer<SyxMsg> mFXSendDelayLevelSysex = new SyxMsg(SyxMsg::MessageType::Type_DT1, deviceId, dt1_address, dt1_data, 1, SyxMsg::calcDt1Checksum(dt1_address, 4, dt1_data, 1));
	result.addEvent(SyxMsg::createTextMetaEvent(SyxMsg::TextEvent, "M-FX to Delay Send Level"), 1.0);
	result.addEvent(mFXSendDelayLevelSysex->toMidiMessage(), 1.0);
	delete[] dt1_address;
	delete[] dt1_data;

	return result;
}

void PatternSetupEffectsBlock::changeListenerCallback(ChangeBroadcaster *source)
{
	if (Parameter* param = dynamic_cast<Parameter*>(source))
	{
		if (PartInfoCommonBlock* setupFx = dynamic_cast<PartInfoCommonBlock*>(param->getBlock()))
		{
			if (param->getAddressOffset() >= 0x0D && param->getAddressOffset() <= 0x1D) // m-fx type and 12 parameters, 2 reserved, m-fx MFX send to DLY and to REV
				this->getParameter(param->getAddressOffset() - 0x0B)->setValue(param->getValue(), Parameter::ChangeSource::GuiWidget);
			else if (param->getAddressOffset() >= 0x22 && param->getAddressOffset() <= 0x23) // delay Level, Type
				this->getParameter(param->getAddressOffset() - 0x05)->setValue(param->getValue(), Parameter::ChangeSource::GuiWidget);
			else if (param->getAddressOffset() == 0x24) // delay Damp
				this->getParameter(0x20)->setValue(param->getValue(), Parameter::ChangeSource::LoadingFile);
			else if (param->getAddressOffset() == 0x25) // delay time
				this->getParameter(0x1F)->setValue(param->getValue(), Parameter::ChangeSource::LoadingFile);
			else if (param->getAddressOffset() >= 0x26 && param->getAddressOffset() <= 0x27) // delay Feed, Route
				this->getParameter(param->getAddressOffset() - 0x05)->setValue(param->getValue(), Parameter::ChangeSource::LoadingFile);
			else if (param->getAddressOffset() >= 0x28 && param->getAddressOffset() <= 0x2B) // reverb parameters Type, Level, Time, Damp
				this->getParameter(param->getAddressOffset() - 0x10)->setValue(param->getValue(), Parameter::ChangeSource::LoadingFile);
		}
	}
}

bool PatternSetupEffectsBlock::handleSysEx(SyxMsg* sysExMsg)
{
	bool success = GrooveboxMemoryBlock::handleSysEx(sysExMsg);
	if (success && sysExMsg->get32BitAddress() == m_address && m_partInfoCommonBlockPtr != nullptr)
	{
		uint8* data;
		uint32 size;
		sysExMsg->getSysExDataArrayPtr(&data, size);
		//DBG(String::toHexString(data,size));
		for (uint16 i = 0; i < size; i++)
		{
			uint8 val = data[i];
			if (i >= 0x02 && i <= 0x12) // m-fx type and 12 parameters, 2 reserved, m-fx MFX send to DLY and to REV
				m_partInfoCommonBlockPtr->getParameter(0x0B + i)->setValue(val, Parameter::ChangeSource::LoadingFile);
			else if (i >= 0x1D && i <= 0x1E) // delay Level, Type
				m_partInfoCommonBlockPtr->getParameter(0x05 + i)->setValue(val, Parameter::ChangeSource::LoadingFile);
			else if (i == 0x1F) // delay Time
				m_partInfoCommonBlockPtr->getParameter(0x25)->setValue(val, Parameter::ChangeSource::LoadingFile);
			else if (i == 0x20) // delay HF Damp
				m_partInfoCommonBlockPtr->getParameter(0x24)->setValue(val, Parameter::ChangeSource::LoadingFile);
			else if (i >= 0x21 && i <= 0x22) // delay Feed	Route
				m_partInfoCommonBlockPtr->getParameter(0x05 + i)->setValue(val, Parameter::ChangeSource::LoadingFile);
			else if (i >= 0x18 && i <= 0x1B) // reverb parameters Type, Level, Time, Damp
				m_partInfoCommonBlockPtr->getParameter(0x10 + i)->setValue(val, Parameter::ChangeSource::LoadingFile);
		}
	}
	return success;
}

// === PatternSetupPartBlock: =================================================

PatternSetupPartBlock::PatternSetupPartBlock(AllParts part) :
	GrooveboxMemoryBlock(0x30004000, "Pattern Setup Mixer Part ", "", 9),
	m_part(part),
	m_partInfoPartBlockPtr(nullptr)
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
			panPosStrings.add("center");
		}
		else if (i > 0)
		{
			String s = String(i);
			String s2("R" + s);
			panPosStrings.add(s2);
		}
	}
	StringArray keyShiftStrings; for (int i = -64; i <= 48; i++)
	{
		if (i <= 0) keyShiftStrings.add(String(i));
		else keyShiftStrings.add("+" + String(i));
	}

	setupParameter("Part " + partCharacter + " Bank Select MSB", 0x00, 0x00, 0x7F, 81);
	setupParameter("Part " + partCharacter + " Bank Select LSB", 0x01, 0x00, 0x7F, 0);
	setupParameter("Part " + partCharacter + " Progam Change PC", 0x02, 0x00, 0x7F, 0);
	setupParameter("Part " + partCharacter + " Level", 0x03, 0, 127, 115, StringArray(), String::empty, 7, false);
	setupParameter("Part " + partCharacter + " Pan", 0x04, 0, 127, 64, panPosStrings, String::empty, 10, false);
	setupParameter("Part " + partCharacter + " Key Shift", 0x05, 16, 112, 64, keyShiftStrings, String::empty, 85, true);
	setupParameter("Part " + partCharacter + " Delay Send Level", 0x06, 0, 127, 0, StringArray(), String::empty, 94, false);
	setupParameter("Part " + partCharacter + " Reverb Send Level", 0x07, 0, 127, 0, StringArray(), String::empty, 91, false);
	setupParameter("Part " + partCharacter + " M-FX Switch", 0x08, 0, 4, 0, StringArray::fromTokens("OFF,ON, , ,RHY", ",", ""), String::empty, 86, true);
}

String PatternSetupPartBlock::getBankName(uint8 bankSelMSB00, uint8 bankSelLSB32)
{
	GrooveboxConnector::GrooveboxModel model = GrooveboxConnector::Model_MC_505;
	if (GrooveboxConnector::GrooveBoxConnectionEntry* connection = grooveboxConnector->getActiveConnection())
	{
		model = connection->deviceFamilyNumberCode;
	}

	if (m_part == 9 && bankSelLSB32 == 0)
	{
		switch (bankSelMSB00)
		{
		case 81: return "P:A"; // Preset Rhyhthm Set Bank A
		case 82: return "P:B"; // Preset Rhyhthm Set Bank B JX - 305
		case 83: return "P:B"; // Preset Rhyhthm Set Bank B MC-307
		case 84: return "P:B"; // Preset Rhyhthm Set Bank B D2
		case 85: return "U:"; // User Rhyhthm Set Bank
		case 86: return "C:"; // Card Rhythm Set Bank
		}
	}
	else
	{
		switch (bankSelMSB00)
		{
		case 81:
			switch (bankSelLSB32)
			{
			case 0: return (model == GrooveboxConnector::Model_JX_305 ? "P:A/B" : "P:A"); // Preset Patch Bank A | Preset Patch Banks A, B JX - 305
			case 1: return (model == GrooveboxConnector::Model_JX_305 ? "P:C/D" : "P:B"); // Preset Patch Bank B | Preset Patch Banks C, D JX - 305
			case 2: return (model == GrooveboxConnector::Model_JX_305 ? "P:E/F" : "P:C"); // Preset Patch Bank C | Preset Patch Banks E, F JX - 305
			case 3: return (model == GrooveboxConnector::Model_JX_305 ? "P:G/H" : "P:D"); // Preset Patch Bank D | Preset Patch Banks G, H JX - 305
			}
			break;
		case 82:
			if (bankSelLSB32 == 0) return "P:I/J"; // Preset Patch Bank I,J JX-305
			break;
		case 83:
			switch (bankSelLSB32)
			{
			case 0: return "P:E"; // Preset Patch Banks E MC-307
			case 1: return "P:F"; // Preset Patch Banks F MC-307
			case 2: return "P:G"; // Preset Patch Banks G MC-307
			}
			break;
		case 84:
			if (bankSelLSB32 == 0) return "P:E"; // Preset Patch Bank E D2
			break;
		case 85:
			switch (bankSelLSB32)
			{
			case 0: return (model == GrooveboxConnector::Model_JX_305 ? "U:A/B" : "U:A"); // User Patch Bank A | User Patch Banks A,B JX-305
			case 1: return (model == GrooveboxConnector::Model_JX_305 ? "U:C/D" : "U:B"); // User Patch Bank B | User Patch Banks C,D JX-305
			}
			break;
		case 86:
			switch (bankSelLSB32)
			{
			case 0: return (model == GrooveboxConnector::Model_JX_305 ? "C:A/B" : "C:A"); // Card Patch Bank A | Card Patch Banks A,B JX-305
			case 1: return (model == GrooveboxConnector::Model_JX_305 ? "C:C/D" : "C:B"); // Card Patch Bank B | Card Patch Banks C,D JX-305
			case 2: return (model == GrooveboxConnector::Model_JX_305 ? "C:E/F" : "C:C"); // Card Patch Bank C | Card Patch Banks E,F JX-305
			case 3: return (model == GrooveboxConnector::Model_JX_305 ? "C:G/H" : "C:D"); // Card Patch Bank D | Card Patch Banks G,H JX-305
			}
			break;
		}
	}
	return "?:??"; // Unknown Patch Bank
}

MidiMessageSequence PatternSetupPartBlock::getSinglePartSetupMidiMessageSequence()
{
	MidiMessageSequence messages;

	String programName(getBankName(getParameter(0x00)->getValue(), getParameter(0x01)->getValue()) + String(getParameter(0x02)->getValue() + 1).paddedLeft('0', (m_part == 9 ? 2 : 3)));
	String instrumentName((m_part == 9 ? grooveboxMemory->getRhythmSetBlock()->getRhythmSetCommonBlockPtr()->getRhythmSetName().trim() : grooveboxMemory->getSynthPatchesBlock()->getPatchPartBlockPtr((SynthParts)m_part)->getPatchCommonBlockPtr()->getPatchName().trim()));
	String trackName("[" + (m_part == 9 ? "R" : String((int)m_part + 1))+"]");
	messages.addEvent(SyxMsg::createChannelPrefixMetaEvent((uint8)m_part));
	messages.addEvent(SyxMsg::createTextMetaEvent(SyxMsg::TrackName, trackName + " " + programName+" "+instrumentName),1.0);
	messages.addEvent(SyxMsg::createTextMetaEvent(SyxMsg::TextEvent, "--- SETUP --------------------------------------"), 1.0);
	messages.addEvent(SyxMsg::createTextMetaEvent(SyxMsg::ProgramName, programName), 1.0);
	messages.addEvent(SyxMsg::createTextMetaEvent(SyxMsg::InstrumentName, instrumentName,1.0));

	// patch selection cascade (meta text, bank selection MSB, bank selection LSB, program change:	
	messages.addEvent(MidiMessage::controllerEvent(m_part + 1, 0, getParameter(0x00)->getValue()), 2.0);
	messages.addEvent(MidiMessage::controllerEvent(m_part + 1, 32, getParameter(0x01)->getValue()), 3.0);
	messages.addEvent(MidiMessage::programChange(m_part + 1, getParameter(0x02)->getValue()), 4.0);
	// mixer setup by controllers:
	messages.addEvent(SyxMsg::createTextMetaEvent(SyxMsg::TextEvent, "Volume Level: " + getParameter(0x03)->getDisplayedValue()), 5.0);
	messages.addEvent(MidiMessage::controllerEvent(m_part + 1, 7, getParameter(0x03)->getValue()), 5.0);
	messages.addEvent(SyxMsg::createTextMetaEvent(SyxMsg::TextEvent, "Pan Position: " + getParameter(0x04)->getDisplayedValue()), 6.0);
	messages.addEvent(MidiMessage::controllerEvent(m_part + 1, 10, getParameter(0x04)->getValue()), 6.0);
	messages.addEvent(SyxMsg::createTextMetaEvent(SyxMsg::TextEvent, "Key Shift: " + getParameter(0x05)->getDisplayedValue()), 7.0);
	messages.addEvent(MidiMessage::controllerEvent(m_part + 1, 85, getParameter(0x05)->getValue()), 7.0);
	messages.addEvent(SyxMsg::createTextMetaEvent(SyxMsg::TextEvent, "Reverb Send Level: " + getParameter(0x06)->getDisplayedValue()), 8.0);
	messages.addEvent(MidiMessage::controllerEvent(m_part + 1, 91, getParameter(0x06)->getValue()), 8.0);
	messages.addEvent(SyxMsg::createTextMetaEvent(SyxMsg::TextEvent, "Delay Send Level: " + getParameter(0x07)->getDisplayedValue()), 9.0);
	messages.addEvent(MidiMessage::controllerEvent(m_part + 1, 94, getParameter(0x07)->getValue()), 9.0);
	messages.addEvent(SyxMsg::createTextMetaEvent(SyxMsg::TextEvent, "M-FX: " + getParameter(0x08)->getDisplayedValue()), 10.0);
	messages.addEvent(MidiMessage::controllerEvent(m_part + 1, 86, getParameter(0x08)->getValue()), 10.0);
	messages.addEvent(SyxMsg::createTextMetaEvent(SyxMsg::TextEvent, "--- END OF SETUP -------------------------------"),23.0);
	return messages;
}

// for part info part (performance) changed
void PatternSetupPartBlock::changeListenerCallback(ChangeBroadcaster *source)
{
	if (Parameter* param = dynamic_cast<Parameter*>(source))
	{
		if (PartInfoPartBlock* performancePart = dynamic_cast<PartInfoPartBlock*>(param->getBlock()))
		{
			if (param->getAddressOffset() == 0x02 || param->getAddressOffset() == 0x03) // patch group type /id --> CC 00 (Bank Select MSB), CC 32 (Bank Select LSB)
			{
				uint8 bankSelMsb, bankSelLsb;
				GrooveboxConnector::GrooveboxModel model = (grooveboxConnector != nullptr&&grooveboxConnector->getActiveConnection() != nullptr) ? grooveboxConnector->getActiveConnection()->deviceFamilyNumberCode : GrooveboxConnector::GrooveboxModel::Model_MC_307;
				performancePart->getBankSelMSB_LSBforGroup(performancePart->getParameter(0x02)->getValue(), performancePart->getParameter(0x03)->getValue(), bankSelMsb, bankSelLsb, model);
				this->getParameter(0x00)->setValue(bankSelMsb, Parameter::GuiWidget);
				this->getParameter(0x01)->setValue(bankSelLsb, Parameter::GuiWidget);
			}
			else if (param->getAddressOffset() == 0x04) // patch --> pc
				this->getParameter(0x02)->setValue(param->getValue(), Parameter::GuiWidget);
			else if (param->getAddressOffset() == 0x06) // level
				this->getParameter(0x03)->setValue(param->getValue(), Parameter::GuiWidget);
			else if (param->getAddressOffset() == 0x07) // pan
				this->getParameter(0x04)->setValue(param->getValue(), Parameter::GuiWidget);
			else if (param->getAddressOffset() == 0x08) // key +/- (map 0-96 (-48 - +48, center 48) to 0..127 by adding 0x10 ) 
				this->getParameter(0x05)->setValue(param->getValue() + 0x10, Parameter::GuiWidget);
			else if (param->getAddressOffset() == 0x0A) // m-fx switch
				this->getParameter(0x08)->setValue(param->getValue(), Parameter::GuiWidget);
			else if (param->getAddressOffset() == 0x0C) // delay send
				this->getParameter(0x07)->setValue(param->getValue(), Parameter::GuiWidget);
			else if (param->getAddressOffset() == 0x0D) // rev send
				this->getParameter(0x06)->setValue(param->getValue(), Parameter::GuiWidget);
		}
	}
}

bool PatternSetupPartBlock::handleSysEx(SyxMsg* sysExMsg)
{
	bool success = GrooveboxMemoryBlock::handleSysEx(sysExMsg);
	if (success && sysExMsg->get32BitAddress() == m_address && m_partInfoPartBlockPtr!=nullptr)
	{
		uint8* data;
		uint32 size;
		uint8 bankSelMsb(81), bankSelLsb(0), groupType, groupId;
		sysExMsg->getSysExDataArrayPtr(&data, size);
		for (uint32 i = 0; i < size; i++)
		{
			uint8 val = data[i];
			switch (i)
			{
			case 0:
				bankSelMsb = val;
				break;
			case 1:
				bankSelLsb = val;
				m_partInfoPartBlockPtr->getGroupFromBankSelMSB_LSB(bankSelMsb, bankSelLsb, groupType, groupId);
				m_partInfoPartBlockPtr->getParameter(0x02)->setValue(groupType, Parameter::ChangeSource::LoadingFile);
				m_partInfoPartBlockPtr->getParameter(0x03)->setValue(groupId, Parameter::ChangeSource::LoadingFile);
				break;
			case 2:
				m_partInfoPartBlockPtr->getParameter(0x04)->setValue(val, Parameter::ChangeSource::LoadingFile); // pc
				break;
			case 3:
				m_partInfoPartBlockPtr->getParameter(0x06)->setValue(val, Parameter::ChangeSource::LoadingFile); // level
				break;
			case 4:
				m_partInfoPartBlockPtr->getParameter(0x07)->setValue(val, Parameter::ChangeSource::LoadingFile); // pan
				break;
			case 5: // Key +/- (map 0 127, center 64 to 0-96 (-48 - +48, center 48) by subtracting 0x10 ) 
				m_partInfoPartBlockPtr->getParameter(0x08)->setValue(jmax<uint8>(0, val - 0x10), Parameter::ChangeSource::LoadingFile);
				break;
			case 6:
				m_partInfoPartBlockPtr->getParameter(0x0D)->setValue(val, Parameter::ChangeSource::LoadingFile); // rev send
				break;
			case 7:
				m_partInfoPartBlockPtr->getParameter(0x0C)->setValue(val, Parameter::ChangeSource::LoadingFile); // dly send
				break;
			case 8:
				m_partInfoPartBlockPtr->getParameter(0x0A)->setValue(val, Parameter::ChangeSource::LoadingFile); // m-fx switch
				break;
			default:
				break;
			}
		}
	}
	return success;
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