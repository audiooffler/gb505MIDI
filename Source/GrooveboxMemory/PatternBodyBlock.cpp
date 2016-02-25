/*
  ==============================================================================

    PatternBodyBlock.cpp
    Created: 22 Jan 2016 8:27:56pm
    Author:  Martin

  ==============================================================================
*/

#include "PatternBodyBlock.h"
#include "PatternSetupBlock.h"
#include "OverallMemoryBlock.h"
#include "../GUI/GrooveboxLookAndFeel.h"

extern OverallMemoryBlock* grooveboxMemory;

PatternBodyBlock::PatternBodyBlock() :
	GrooveboxMemoryBlock(0x40000000, "Pattern Body Data", "1-6", 0x00000000),
	m_patternTableFilterParams(new VirtualPatternTableFilterBlock())
{
	m_name = "Pattern Body";
	// no parameters, just big data block
	m_sequenceBlocks.clear();
	m_filteredsequenceBlocks.clear();
	//TableListBox::updateContent();
	PatternEventData::mostRecentAbsoluteTick = 0;
	PatternEventData::lastRelativeTickIncrement = 0;
	m_patternTableFilterParams->getParameter(VirtualPatternTableFilterBlock::ViewPart1)->addChangeListener(this);
	m_patternTableFilterParams->getParameter(VirtualPatternTableFilterBlock::ViewPart2)->addChangeListener(this);
	m_patternTableFilterParams->getParameter(VirtualPatternTableFilterBlock::ViewPart3)->addChangeListener(this);
	m_patternTableFilterParams->getParameter(VirtualPatternTableFilterBlock::ViewPart4)->addChangeListener(this);
	m_patternTableFilterParams->getParameter(VirtualPatternTableFilterBlock::ViewPart5)->addChangeListener(this);
	m_patternTableFilterParams->getParameter(VirtualPatternTableFilterBlock::ViewPart6)->addChangeListener(this);
	m_patternTableFilterParams->getParameter(VirtualPatternTableFilterBlock::ViewPart7)->addChangeListener(this);
	m_patternTableFilterParams->getParameter(VirtualPatternTableFilterBlock::ViewPartR)->addChangeListener(this);
	m_patternTableFilterParams->getParameter(VirtualPatternTableFilterBlock::ViewMuteCtrl)->addChangeListener(this);
	m_patternTableFilterParams->getParameter(VirtualPatternTableFilterBlock::ViewSingeParts)->addChangeListener(this);
	m_patternTableFilterParams->getParameter(VirtualPatternTableFilterBlock::ViewNotes)->addChangeListener(this);
	m_patternTableFilterParams->getParameter(VirtualPatternTableFilterBlock::ViewNotesMin)->addChangeListener(this);
	m_patternTableFilterParams->getParameter(VirtualPatternTableFilterBlock::ViewNotesMax)->addChangeListener(this);
	m_patternTableFilterParams->getParameter(VirtualPatternTableFilterBlock::ViewPC)->addChangeListener(this);
	m_patternTableFilterParams->getParameter(VirtualPatternTableFilterBlock::ViewCC)->addChangeListener(this);
	m_patternTableFilterParams->getParameter(VirtualPatternTableFilterBlock::ViewCCMin)->addChangeListener(this);
	m_patternTableFilterParams->getParameter(VirtualPatternTableFilterBlock::ViewCCMax)->addChangeListener(this);
	m_patternTableFilterParams->getParameter(VirtualPatternTableFilterBlock::ViewBend)->addChangeListener(this);
	m_patternTableFilterParams->getParameter(VirtualPatternTableFilterBlock::ViewPAft)->addChangeListener(this);
	m_patternTableFilterParams->getParameter(VirtualPatternTableFilterBlock::ViewPAftMin)->addChangeListener(this);
	m_patternTableFilterParams->getParameter(VirtualPatternTableFilterBlock::ViewPAftMax)->addChangeListener(this);
	m_patternTableFilterParams->getParameter(VirtualPatternTableFilterBlock::ViewCAft)->addChangeListener(this);
	m_patternTableFilterParams->getParameter(VirtualPatternTableFilterBlock::ViewTempo)->addChangeListener(this);
	m_patternTableFilterParams->getParameter(VirtualPatternTableFilterBlock::ViewMute)->addChangeListener(this);
	m_patternTableFilterParams->getParameter(VirtualPatternTableFilterBlock::ViewSysEx)->addChangeListener(this);
	m_patternTableFilterParams->getParameter(VirtualPatternTableFilterBlock::ViewNotesOff)->addChangeListener(this);
	m_patternTableFilterParams->getParameter(VirtualPatternTableFilterBlock::ViewInc)->addChangeListener(this);

	m_midiCCNames.set(5, "PORTA TIME");
	m_midiCCNames.set(7, "PART LEVEL");
	m_midiCCNames.set(10, "PART PAN");
	m_midiCCNames.set(15, "LFO1 WAVE");
	m_midiCCNames.set(16, "LFO1 RATE");
	m_midiCCNames.set(18, "LFO1->PITCH");
	m_midiCCNames.set(19, "LFO1->FILTER");
	m_midiCCNames.set(21, "COARSE TUNE");
	m_midiCCNames.set(25, "P-ENV-DEPTH");
	m_midiCCNames.set(26, "P-ENV A");
	m_midiCCNames.set(27, "P-ENV D");
	m_midiCCNames.set(28, "F-ENV S");
	m_midiCCNames.set(29, "F-ENV R");
	m_midiCCNames.set(31, "A-ENV S");
	m_midiCCNames.set(34, "FILTER TYPE");
	m_midiCCNames.set(35, "TONE PAN");
	m_midiCCNames.set(36, "TONE LVL");
	m_midiCCNames.set(37, "RND PAN");
	m_midiCCNames.set(39, "P-ENV S");
	m_midiCCNames.set(40, "P-ENV R");
	m_midiCCNames.set(65, "PORTA SW");
	m_midiCCNames.set(71, "FILTER RES");
	m_midiCCNames.set(72, "A-ENV R");
	m_midiCCNames.set(73, "A-ENV A");
	m_midiCCNames.set(74, "FILTER CUT");
	m_midiCCNames.set(75, "A-ENV D");
	m_midiCCNames.set(77, "FINE TUNE");
	m_midiCCNames.set(80, "LFO1->AMP");
	m_midiCCNames.set(81, "F-ENV-DEPTH");
	m_midiCCNames.set(82, "F-ENV A");
	m_midiCCNames.set(83, "F-ENV D");
	m_midiCCNames.set(85, "KEY SHIFT");
	m_midiCCNames.set(86, "M-FX SW");
	m_midiCCNames.set(91, "REVERB");
	m_midiCCNames.set(94, "DELAY");
	m_midiCCNames.set(126, "SOLO ON");
	m_midiCCNames.set(127, "SOLO OFF");

	clearPattern();
}

PatternBodyBlock::~PatternBodyBlock()
{
	sysExBuilder.reset();
}

bool PatternBodyBlock::handleSysEx(SyxMsg* sysExMsg)
{
	uint32 address = sysExMsg->get32BitAddress();
	if (address < 0x40000000) return false;

	// if first sysex of pattern body received --> clear
	if (address == 0x40000000)
	{
		m_sequenceBlocks.clear();
		m_filteredsequenceBlocks.clear();
		PatternEventData::mostRecentAbsoluteTick = 0;
		PatternEventData::lastRelativeTickIncrement = 0;
	}
	uint8* sysExDataPtr;
	uint32 sysExDataSize;
	sysExMsg->getSysExDataArrayPtr(&sysExDataPtr, sysExDataSize);
	ScopedPointer<const uint8> patternDataBlock = nullptr;
	int patternDataBlockSize;
	patternDataBlock = unpack7BitTo8BitData(sysExDataPtr, sysExDataSize, patternDataBlockSize); // new, to be deleted

	for (int i = 0; i < patternDataBlockSize; i += 8)
	{
		// skip last bytes if incomplete
		if (i + 7 > patternDataBlockSize) continue;

		PatternEventData* newPatternEvent = new PatternEventData(patternDataBlock+i, patternDataBlockSize-i);
		m_sequenceBlocks.add(newPatternEvent);

		// sysex: min 2 byte (F0 + F7), default F0 + 12 more bytes (incl CHK + F7), max: F0 + 510 more (incl CHK & F7)
		if (newPatternEvent->getType() == Evt_SysExSize)
		{
			sysExBuilder.setSize(newPatternEvent->getSysExSize());
			sysExBuilderByteIndex = 0;
		}
		else if (newPatternEvent->getType() == Evt_SysExData)
		{
			for (int b = 4; b < 8 && sysExBuilderByteIndex<sysExBuilder.getSize(); b++)
			{
				sysExBuilder[sysExBuilderByteIndex] = newPatternEvent->bytes[b];
				sysExBuilderByteIndex++;
				if (newPatternEvent->bytes[b] == 0xF7)	// SYSEX EOX --> create midi message
				{
					// add additional merged sysex
					PatternEventData* joinedSysExEvent = new PatternEventData(newPatternEvent->absoluteTick, &sysExBuilder);
					m_sequenceBlocks.add(joinedSysExEvent);
					sysExBuilder.setSize(0);
					sysExBuilderByteIndex = 0;
					break;
				}
			}
		}
	}
	refreshFilteredContent();
	return true;
}

// unpack SysEx data array, size of unpacked data is returned via rerence parameter. don't forger to delete the returned array after usage
const uint8* PatternBodyBlock::unpack7BitTo8BitData(const uint8* packed7BitData, int packed7BitDataSize, int &unpackedDataSize)
{
	// following declarations will be function paramers, last one by refrence
	unpackedDataSize = (packed7BitDataSize - (packed7BitDataSize / 8))/8*8;
	uint8 *unpackedData = new uint8[unpackedDataSize] {};	// initialized with zeroes

	uint8 currentPacked7Bit(0);
	uint8 nextPacked7Bit(0);
	uint8 bitsFromNextByte(1);

	for (int i = 0, j = 0; i < packed7BitDataSize && j < unpackedDataSize; i++)
	{
		bitsFromNextByte = i % 8 + 1;
		// skip every 8th pair, else get unpacked byte from 2 packed7Bit bytes
		if (bitsFromNextByte != 8)
		{
			// shift left once (removes 1st bit) and left for every used bits from last time
			currentPacked7Bit = ((uint8*)packed7BitData)[i] << bitsFromNextByte;
			// if there's a next one: shift left one (remove 1st bit) and get the rest
			nextPacked7Bit = (i == packed7BitDataSize - 1) ?
				0 :
				((uint8*)packed7BitData)[i + 1] << 1 >> (8 - bitsFromNextByte);
			unpackedData[j] = currentPacked7Bit + nextPacked7Bit;
			j++;
		}
	}
	return unpackedData;
}

const String PatternBodyBlock::PatternEventData::NOTENAMES[] = { "C -1","C#-1","D -1","D#-1","E -1","F -1","F#-1","G -1","G#-1","A -1","A#-1","B -1","C  0","C# 0","D  0","D# 0","E  0","F  0","F# 0","G  0","G# 0","A  0","A# 0","B  0","C  1","C# 1","D  1","D# 1","E  1","F  1","F# 1","G  1","G# 1","A  1","A# 1","B  1","C  2","C# 2","D  2","D# 2","E  2","F  2","F# 2","G  2","G# 2","A  2","A# 2","B  2","C  3","C# 3","D  3","D# 3","E  3","F  3","F# 3","G  3","G# 3","A  3","A# 3","B  3","C  4","C# 4","D  4","D# 4","E  4","F  4","F# 4","G  4","G# 4","A  4","A# 4","B  4","C  5","C# 5","D  5","D# 5","E  5","F  5","F# 5","G  5","G# 5","A  5","A# 5","B  5","C  6","C# 6","D  6","D# 6","E  6","F  6","F# 6","G  6","G# 6","A  6","A# 6","B  6","C  7","C# 7","D  7","D# 7","E  7","F  7","F# 7","G  7","G# 7","A  7","A# 7","B  7","C  8","C# 8","D  8","D# 8","E  8","F  8","F# 8","G  8","G# 8","A  8","A# 8","B  8","C  9","C# 9","D  9","D# 9","E  9","F  9","F# 9","G  9" };
unsigned long PatternBodyBlock::PatternEventData::mostRecentAbsoluteTick = 0;
uint8 PatternBodyBlock::PatternEventData::lastRelativeTickIncrement = 0;

String PatternBodyBlock::PatternEventData::getAbsoluteTickString(unsigned int absoluteTicks, uint8 ticksPerBeat, uint8 beatsPerMeasure, bool asLength/*=false*/)
{
	unsigned int ticksRest = (absoluteTicks % ticksPerBeat);
	unsigned int beats = absoluteTicks / ticksPerBeat;
	unsigned int measure = beats / beatsPerMeasure;
	beats = beats % beatsPerMeasure;
	return String(measure + (asLength ? 0 : 1)).paddedLeft('0', 2) + "-" + String(beats + (asLength ? 0 : 1)).paddedLeft('0', 2) + "-" + String(ticksRest).paddedLeft('0', 2);
}

String PatternBodyBlock::PatternEventData::getPartString(PatternBodyBlock::PatternPart part)
{
	switch (part)
	{
	case PatternBodyBlock::Pattern_Part_1:
		return "PART 1";
	case PatternBodyBlock::Pattern_Part_2:
		return "PART 2";
	case PatternBodyBlock::Pattern_Part_3:
		return "PART 3";
	case PatternBodyBlock::Pattern_Part_4:
		return "PART 4";
	case PatternBodyBlock::Pattern_Part_5:
		return "PART 5";
	case PatternBodyBlock::Pattern_Part_6:
		return "PART 6";
	case PatternBodyBlock::Pattern_Part_7:
		return "PART 7";
	case PatternBodyBlock::Pattern_Part_R:
		return "PART R";
	case PatternBodyBlock::Pattern_MuteCtrl:
		return "MUTE-CT";
	case PatternBodyBlock::Pattern_Part_Unknown:
	default:
		return "PART?";
	}
}

String PatternBodyBlock::PatternEventData::getRhythmGroupString(RhythmGroup rhythmGroup)
{
	switch (rhythmGroup)
	{
	case PatternBodyBlock::Rhythm_Group_BD:
		return "BD";
	case PatternBodyBlock::Rhythm_Group_SD:
		return "SD";
	case PatternBodyBlock::Rhythm_Group_HH:
		return "HH";
	case PatternBodyBlock::Rhythm_Group_CLP:
		return "CLP";
	case PatternBodyBlock::Rhythm_Group_CYM:
		return "CYM";
	case PatternBodyBlock::Rhythm_Group_TomPerc:
		return"TOM/PERC";
	case PatternBodyBlock::Rhythm_Group_Hit:
		return "HIT";
	case PatternBodyBlock::Rhythm_Group_Others:
		return "OTHERS";
	case PatternBodyBlock::Rhythm_Group_All:
		return "ALL";
	case PatternBodyBlock::Rhythm_Group_Unknown:
	default:
		return "Unknown";
	}
}

PatternBodyBlock::PatternEventData::PatternEventData(const uint8* pointerToData, unsigned int pointedDataRestLength) :
	m_joinedSysexData(nullptr)
{
	for (unsigned int j = 0; j < 8; j++) 
	{
		bytes[j] = j < pointedDataRestLength ? pointerToData[j] : 0;
	}
	absoluteTick = PatternEventData::mostRecentAbsoluteTick + lastRelativeTickIncrement;
	PatternEventData::mostRecentAbsoluteTick = absoluteTick;
	PatternEventData::lastRelativeTickIncrement = getRelativeTickIncrement();
}

PatternBodyBlock::PatternEventData::PatternEventData(unsigned long absTick, MemoryBlock* joinedSysex) :
	m_joinedSysexData (new MemoryBlock)
{
	for (unsigned int j = 0; j < 8; j++) { bytes[j] = 0; }
	absoluteTick = absTick;
	m_joinedSysexData->setSize(joinedSysex->getSize());
	m_joinedSysexData->copyFrom(joinedSysex->getData(), 0, joinedSysex->getSize());
}

PatternBodyBlock::PatternEventData::PatternEventData(unsigned long absTick, int8 key, uint8 part):
	m_joinedSysexData(nullptr)
{
	bytes[0] = 0; // no valid tick inc for note-offs!
	bytes[1] = key;
	bytes[2] = part;
	bytes[3] = part;
	bytes[4] = 0; // velocity = 0 for note off
	bytes[5] = 0;
	bytes[6] = 0;
	bytes[7] = 0;
	isNoteOff = true;
	absoluteTick = absTick;
}

// constructor for free data enty
PatternBodyBlock::PatternEventData::PatternEventData(unsigned long absTick, const uint8 byte0, const uint8 byte1, const uint8 byte2, const uint8 byte3 /*= 0*/, const uint8 byte4 /*= 0*/, const uint8 byte5 /*= 0*/, const uint8 byte6 /*= 0*/, const uint8 byte7 /*= 0*/) :
	m_joinedSysexData(nullptr),
	isNoteOff(false)
{
	bytes[0] = byte0;
	bytes[1] = byte1;
	bytes[2] = byte2;
	bytes[3] = byte3;
	bytes[4] = byte4;
	bytes[5] = byte5;
	bytes[6] = byte6;
	bytes[7] = byte7;
	absoluteTick = absTick;
}

// constructor from midi event, relative tick will be null, just absolue tick set. so in PatternBodyBlock ticks must be refreshed after adding these
PatternBodyBlock::PatternEventData::PatternEventData(unsigned long absTick, MidiMessage &midiMessage)
{

}

PatternBodyBlock::PatternEventData::~PatternEventData()
{
	if (m_joinedSysexData != nullptr)m_joinedSysexData->reset();
}

uint8 PatternBodyBlock::PatternEventData::getRelativeTickIncrement()
{
	return bytes[0];
}

PatternBodyBlock::PatternEventType PatternBodyBlock::PatternEventData::getType()
{
	// BYTE 1: get sequencer event type
	switch (bytes[1])
	{
	case 0x80: return Evt_TickInc;
	case 0x8D: return Evt_PAft;
	case 0x8E: return Evt_Cc;
	case 0x8F: return Evt_Pc;
	case 0x90: return Evt_CAft;
	case 0x91: return Evt_PBend;
	case 0x93:
		if (bytes[4] == 0x01) return Evt_PartMute;
		else if (bytes[4] == 0x02) return Evt_RhyMute;
		else if (bytes[4] == 0x03) return Evt_Tempo;
	case 0x95: return Evt_SysExSize;
	case 0x96: return Evt_SysExData;
	default:
		if (isNoteOff)
		{
			return Evt_NoteOff;
		}
		if (bytes[1] >= 0x00 && bytes[1] <= 0x7F)	// note event
		{
			return Evt_Note;
		}
		else if (m_joinedSysexData!=nullptr && m_joinedSysexData->getSize() > 0)
		{
			return Evt_SysExJoined;
		}
		else
		{
			return Evt_Unknown;
		}
	}
}

String PatternBodyBlock::PatternEventData::getTypeString()
{
	PatternEventType type = getType();
	switch (type)
	{
	case PatternBodyBlock::Evt_Note: 
		return PatternBodyBlock::PatternEventData::NOTENAMES[bytes[1]];
	case PatternBodyBlock::Evt_NoteOff:
		return PatternBodyBlock::PatternEventData::NOTENAMES[bytes[1]] + " Off";
	case PatternBodyBlock::Evt_TickInc:
		return "INC";
	case PatternBodyBlock::Evt_PAft:
		return "P-AFT";
	case PatternBodyBlock::Evt_Cc:
		return "CC";
	case PatternBodyBlock::Evt_Pc:
		return "PC";
	case PatternBodyBlock::Evt_CAft:
		return "C-AFT";
	case PatternBodyBlock::Evt_PBend:
		return "BEND";
	case PatternBodyBlock::Evt_Tempo:
		return "TEMPO";
	case PatternBodyBlock::Evt_PartMute:
		return "MUTE PT";
	case PatternBodyBlock::Evt_RhyMute:
		return "MUTE RY";
	case PatternBodyBlock::Evt_SysExSize:
		return "SYX-SIZ";
	case PatternBodyBlock::Evt_SysExData:
		return "SYX-DAT";
	case PatternBodyBlock::Evt_SysExJoined:
		return "SYSEX";
	case PatternBodyBlock::Evt_Unknown:
	default:
		return "TYPE?";
	}
}

PatternBodyBlock::PatternPart PatternBodyBlock::PatternEventData::getPart()
{
	// BYTE 2: get part/channel for event
	switch (bytes[2])
	{
	case 0x00:	return Pattern_Part_1;
	case 0x01:	return Pattern_Part_2;
	case 0x02:	return Pattern_Part_3;
	case 0x03:	return Pattern_Part_4;
	case 0x04:	return Pattern_Part_5;
	case 0x05:	return Pattern_Part_6;
	case 0x06:	return Pattern_Part_7;
	case 0x09:	return Pattern_Part_R;
	case 0x0E:	return Pattern_MuteCtrl;
	default: 
		// fallback to byte 3
		switch (bytes[3])
		{
		case 0x00:	return Pattern_Part_1;
		case 0x01:	return Pattern_Part_2;
		case 0x02:	return Pattern_Part_3;
		case 0x03:	return Pattern_Part_4;
		case 0x04:	return Pattern_Part_5;
		case 0x05:	return Pattern_Part_6;
		case 0x06:	return Pattern_Part_7;
		case 0x09:	return Pattern_Part_R;
		case 0x0E:	return Pattern_MuteCtrl;
		default:	
			if (getType() == Evt_SysExJoined) return Pattern_MuteCtrl;
			else return Pattern_Part_Unknown;
		}
	}
}

int PatternBodyBlock::PatternEventData::getMidiChannel()
{
	return (int)getPart() + 1;
}

int PatternBodyBlock::PatternEventData::getNoteNumber()
{
	return bytes[1];
}

uint8 PatternBodyBlock::PatternEventData::getNoteVelocity()
{
	return bytes[4];
}

uint16 PatternBodyBlock::PatternEventData::getNoteGateTicks()
{
	return (uint16)bytes[6] << 8 | (uint16)bytes[7];
}

uint8 PatternBodyBlock::PatternEventData::getPAftKey()
{
	return bytes[5];
}

String PatternBodyBlock::PatternEventData::getPAftKeyString()
{
	return NOTENAMES[getPAftKey()];
}

uint8 PatternBodyBlock::PatternEventData::getPAftPressure()
{
	return bytes[6];
}

uint8 PatternBodyBlock::PatternEventData::getCcNo()
{
	return bytes[5];
}

uint8 PatternBodyBlock::PatternEventData::getCcValue()
{
	return bytes[6];
}

uint8 PatternBodyBlock::PatternEventData::getPcProgram()
{
	return bytes[5];
}

uint8 PatternBodyBlock::PatternEventData::getCAftPressure()
{
	return bytes[5];
}

uint16 PatternBodyBlock::PatternEventData::getPitchBendValue()
{
	return (uint16)bytes[5] << 7 | (uint16)bytes[6];
}

String PatternBodyBlock::PatternEventData::getPitchBendString()
{
	int val = (int)getPitchBendValue() - 0x2000;
	return String((val > 0) ? "+" : "") + String(val);
}

PatternBodyBlock::PatternPart PatternBodyBlock::PatternEventData::getMutePart()
{
	return (PatternBodyBlock::PatternPart)bytes[5];
}

PatternBodyBlock::RhythmGroup PatternBodyBlock::PatternEventData::getMuteRhythmGroup()
{
	return (PatternBodyBlock::RhythmGroup)bytes[5];
}

bool PatternBodyBlock::PatternEventData::getMuteState()	// false=Mute, true=On
{
	return bytes[7]!=0;
}

float PatternBodyBlock::PatternEventData::getTempoValue()
{
	return (float)((uint16)bytes[6] << 8 | (uint16)bytes[7]) / 100.0f;
}

uint32 PatternBodyBlock::PatternEventData::getSysExSize()
{
	return (uint32)bytes[4] << 24 | (uint32)bytes[5] << 16 | (uint32)bytes[6] << 8 | (uint32)bytes[7];
}

uint8* PatternBodyBlock::PatternEventData::getSysExBytesPtr() // pointer to last 4 bytes
{
	return &(bytes[4]);
}

void PatternBodyBlock::PatternEventData::getSysExBytesCopyTo(uint8* fourBytes) // make sure to give reference to a 4-byte array which values are to be set
{
	if (fourBytes != nullptr)
	{
		fourBytes[0] = bytes[4];
		fourBytes[1] = bytes[5];
		fourBytes[2] = bytes[5];
		fourBytes[3] = bytes[7];
	}
}

String PatternBodyBlock::PatternEventData::toDebugString(uint8 ticksPerBeat, uint8 beatsPerMeasure)
{
	PatternEventType type = getType();
	uint8 sysExData[4] = { 0, 0, 0, 0 };
	if (type == Evt_SysExData) getSysExBytesCopyTo(sysExData);
	String result = String::toHexString(bytes, 8, 1).toUpperCase() + "\t";
	result += getAbsoluteTickString(absoluteTick, ticksPerBeat, beatsPerMeasure) + "\t";
	result += String(getRelativeTickIncrement()) + "\t";
	if (type != Evt_TickInc) result += getPartString(getPart()) + "\t";
	result += getTypeString() + "\t";
	result += String(bytes[2]) + "\t";
	switch (type)
	{
	case PatternBodyBlock::Evt_Note:
		result += "v: " + String(getNoteVelocity()).paddedLeft('0', 3) + "\t";
		result += getAbsoluteTickString(getNoteGateTicks(), ticksPerBeat, beatsPerMeasure, true) + "\t";
		break;
	case PatternBodyBlock::Evt_TickInc:
		break;
	case PatternBodyBlock::Evt_PAft:
		result += getPAftKeyString() + "\t";
		result += "p: "+String(getPAftPressure()).paddedLeft('0',3) + "\t";
		break;
	case PatternBodyBlock::Evt_Cc:
		result += "no: " + String(getCcNo()).paddedLeft('0', 3) + "\t";
		result += "to: " + String(getCcValue()).paddedLeft('0', 3) + "\t";
		break;
	case PatternBodyBlock::Evt_Pc:
		result += "pr: " + String(getPcProgram()).paddedLeft('0', 3) + "\t";
		break;
	case PatternBodyBlock::Evt_CAft:
		result += "p: " + String(getCAftPressure()).paddedLeft('0', 3) + "\t"; 
		break;
	case PatternBodyBlock::Evt_PBend:
		result += getPitchBendString().paddedLeft('0', 6) + "\t";
		break;
	case PatternBodyBlock::Evt_Tempo:
		result += String(getTempoValue()).paddedLeft('0', 6) + "\t";
		break;
	case PatternBodyBlock::Evt_PartMute:
		result += getPartString(getMutePart())+"\t";
		result += String(getMuteState() ? +"On" : "Mute") + "\t";
		break;
	case PatternBodyBlock::Evt_RhyMute:
		result += getRhythmGroupString(getMuteRhythmGroup()) + "\t";
		result += String(getMuteState() ? +"On" : "Mute") + "\t";
		break;
	case PatternBodyBlock::Evt_SysExSize:
		result += String(getSysExSize()) + "\t";
		break;
	case PatternBodyBlock::Evt_SysExData:
		result += String::toHexString(sysExData, 4, 1).toUpperCase()+"\t";
		break;
	case PatternBodyBlock::Evt_Unknown:
	default:
		break;
	}
	return result;
}

MidiMessage PatternBodyBlock::PatternEventData::toMidiMessage()
{
	if (getType() == PatternBodyBlock::Evt_SysExJoined)
	{
		return MidiMessage::createSysExMessage((m_joinedSysexData->getData()), m_joinedSysexData->getSize());
	}
	else if (getType() == PatternBodyBlock::Evt_PartMute)
	{
		uint8 quickSysExAddress[2]{0x70, 0x01};
		uint8 quickSysExData[2]{bytes[5], bytes[7]};
		uint8 deviceId((grooveboxConnector != nullptr) ? grooveboxConnector->getActiveDeviceId() : 0x10);
		ScopedPointer<SyxMsg> syx = new SyxMsg(SyxMsg::Type_DT1_Quick, deviceId, quickSysExAddress, quickSysExData, 2, SyxMsg::calcDt1Checksum(quickSysExAddress, 2, quickSysExData, 2));
		MidiMessage msg = syx->getAsMidiMessage();
		return msg;
	}
	else if (getType() == PatternBodyBlock::Evt_RhyMute)
	{
		uint8 quickSysExAddress[2]{0x70, 0x02};
		uint8 quickSysExData[2]{bytes[5], bytes[7]};
		uint8 deviceId((grooveboxConnector != nullptr) ? grooveboxConnector->getActiveDeviceId() : 0x10);
		ScopedPointer<SyxMsg> syx = new SyxMsg(SyxMsg::Type_DT1_Quick, deviceId, quickSysExAddress, quickSysExData, 2, SyxMsg::calcDt1Checksum(quickSysExAddress, 2, quickSysExData, 2));
		MidiMessage msg = syx->getAsMidiMessage();
		return msg;
	}
	switch (getType())
	{
	case PatternBodyBlock::Evt_Note:
		return MidiMessage::noteOn(getMidiChannel(), getNoteNumber(), getNoteVelocity());
	case PatternBodyBlock::Evt_NoteOff:
		return MidiMessage::noteOff(getMidiChannel(), getNoteNumber());
	case PatternBodyBlock::Evt_PAft:
		return MidiMessage::aftertouchChange(getMidiChannel(), getPAftKey(), getPAftPressure());
	case PatternBodyBlock::Evt_Cc:
		return MidiMessage::controllerEvent(getMidiChannel(), getCcNo(), getCcValue());
	case PatternBodyBlock::Evt_Pc:
		return MidiMessage::programChange(getMidiChannel(), getPcProgram());
	case PatternBodyBlock::Evt_CAft:
		return MidiMessage::channelPressureChange(getMidiChannel(), getCAftPressure());
	case PatternBodyBlock::Evt_PBend:
		return MidiMessage::pitchWheel(getMidiChannel(), getPitchBendValue());
	case PatternBodyBlock::Evt_Tempo:
		return MidiMessage::tempoMetaEvent((int)(6000000000 / ((uint16)bytes[6] << 8 | (uint16)bytes[7])));	
	default:
		return MidiMessage(); // just an active sense message (empty sysex)
	}
}

const String PatternBodyBlock::PATTERNTABLE_COLUMN_NAMES_FOR_IDS[] = {"", "[0]", "[1]", "[2]", "[3]", "[4]", "[5]", "[6]", "[7]", "", "Pos", "Inc", "Type", "Part", "Data 1", "Data 2" };

int PatternBodyBlock::getNumRows()
{
	return m_filteredsequenceBlocks.size();
}

void PatternBodyBlock::paintRowBackground(Graphics& g, int /*rowNumber*/, int /*width*/, int /*height*/, bool rowIsSelected)
{
	g.fillAll(rowIsSelected ? GrooveboxLookAndFeel::Mc307LcdThumb : Colours::transparentBlack);
}

void PatternBodyBlock::paintCell(Graphics& g, int rowNumber, int columnId, int width, int height, bool /*rowIsSelected*/)
{
	// left and bottom border
	g.setFont(Font(Font::getDefaultMonospacedFontName(), 12, Font::bold));
	g.setColour(Colours::grey);
	g.drawLine((float)width, 0.0f, (float)width, (float)height);
	g.drawLine(0.0f, (float)height, (float)width, (float)height);
	if (rowNumber < m_filteredsequenceBlocks.size())
	{
		PatternEventData* event = m_filteredsequenceBlocks[rowNumber];
		String cellText;
		switch ((PatternTableListColumnId)columnId)
		{
		case PatternBodyBlock::Col_Position:
			cellText = PatternEventData::getAbsoluteTickString(event->absoluteTick, getTicksPerBeat(), m_beatSigNumerator);
			break;
		case PatternBodyBlock::Col_Raw0:
			cellText = String::toHexString((int)event->bytes[0]).toUpperCase().paddedLeft('0',2);
			break;
		case PatternBodyBlock::Col_TicksInc:
			cellText = String(event->getRelativeTickIncrement());
			break;
		case PatternBodyBlock::Col_Raw1:
			cellText = String::toHexString((int)event->bytes[1]).toUpperCase().paddedLeft('0', 2);
			break;
		case PatternBodyBlock::Col_EventType:
			cellText = event->getTypeString();
			break;
		case PatternBodyBlock::Col_Raw2:
			cellText = String::toHexString((int)event->bytes[2]).toUpperCase().paddedLeft('0', 2);
			break;
		case PatternBodyBlock::Col_Raw3:
			cellText = String::toHexString((int)event->bytes[3]).toUpperCase().paddedLeft('0', 2);
			break;
		case PatternBodyBlock::Col_Part:
			cellText = PatternEventData::getPartString(event->getPart());
			break;
		case PatternBodyBlock::Col_Raw4:
			cellText = String::toHexString((int)event->bytes[4]).toUpperCase().paddedLeft('0', 2);
			break;
		case PatternBodyBlock::Col_Raw5:
			cellText = String::toHexString((int)event->bytes[5]).toUpperCase().paddedLeft('0', 2);
			break;
		case PatternBodyBlock::Col_Raw6:
			cellText = String::toHexString((int)event->bytes[6]).toUpperCase().paddedLeft('0', 2);
			break;
		case PatternBodyBlock::Col_Raw7:
			cellText = String::toHexString((int)event->bytes[7]).toUpperCase().paddedLeft('0', 2);
			break;
		case PatternBodyBlock::Col_Value1:
			switch (event->getType())
			{
			case PatternBodyBlock::Evt_Note:
				cellText = String(event->getNoteVelocity());
				break;
			case PatternBodyBlock::Evt_PAft:
				cellText = String(event->getPAftKeyString());
				break;
			case PatternBodyBlock::Evt_Cc:
				cellText = String(event->getCcNo()) + " " + m_midiCCNames[event->getCcNo()];
				break;
			case PatternBodyBlock::Evt_Pc:
				cellText = String(event->getPcProgram());
				break;
			case PatternBodyBlock::Evt_CAft:
				cellText = String(event->getCcValue());
				break;
			case PatternBodyBlock::Evt_PBend:
				cellText = String(event->getPitchBendString());
				break;
			case PatternBodyBlock::Evt_Tempo:
				cellText = String(event->getTempoValue());
				break;
			case PatternBodyBlock::Evt_PartMute:
				cellText = PatternEventData::getPartString(event->getMutePart());
				break;
			case PatternBodyBlock::Evt_RhyMute:
				cellText = PatternEventData::getRhythmGroupString(event->getMuteRhythmGroup());
				break;
			case PatternBodyBlock::Evt_SysExSize:
				cellText = String(event->getSysExSize());
				break;
			case PatternBodyBlock::Evt_SysExData:
				cellText = String::toHexString(event->getSysExBytesPtr(), 4).toUpperCase();
				break;
			default:
				break;
			}
			break;
		case PatternBodyBlock::Col_Value2:
			switch (event->getType())
			{
			case PatternBodyBlock::Evt_Note:
				cellText = PatternEventData::getAbsoluteTickString(event->getNoteGateTicks(), getTicksPerBeat(), m_beatSigNumerator, true /*gate time counting measures and beats from 0*/);
				break;
			case PatternBodyBlock::Evt_PAft:
				cellText = String(event->getPAftPressure());
				break;
			case PatternBodyBlock::Evt_Cc:
				cellText = String(event->getCcValue());
				break;
			case PatternBodyBlock::Evt_PartMute:
				cellText = String(event->getMuteState() ? "On" : "Mute");
				break;
			case PatternBodyBlock::Evt_RhyMute:
				cellText = String(event->getMuteState() ? "On" : "Mute");
				break;
			default:
				break;
			}
			break;
			break;
		default:
			break;
		}
		g.setColour(columnId>=10?Colours::black:Colours::grey);
		g.drawText(cellText, 2, 0, width - 4, height, columnId >= 10 && columnId != Col_Part ? Justification::centredRight : Justification::centred);
	}

}

String PatternBodyBlock::getCellTooltip(int /*rowNumber*/, int /*columnId*/)
{
	return String::empty;
}

void PatternBodyBlock::selectedRowsChanged(int lastRowSelected)
{
	if (lastRowSelected >= 0 && lastRowSelected < m_filteredsequenceBlocks.size() && tableSelectionMidiOut!=nullptr)
	{
		for (int i = 1; i < 17; i++)
		{
			tableSelectionMidiOut->sendMessageNow(MidiMessage::allNotesOff(i));
		}
		if (m_filteredsequenceBlocks[lastRowSelected]->getMidiChannel() >= 1 && m_filteredsequenceBlocks[lastRowSelected]->getMidiChannel() <= 16)
			tableSelectionMidiOut->sendMessageNow(m_filteredsequenceBlocks[lastRowSelected]->toMidiMessage());
	}
}

void PatternBodyBlock::setTableSelectionMidiOutId(int id)
{
	if (id >= 0 && id < MidiOutput::getDevices().size())
	{
		tableSelectionMidiOut = MidiOutput::openDevice(id);
	}
}

PatternBodyBlock::VirtualPatternTableFilterBlock::VirtualPatternTableFilterBlock() :
	GrooveboxMemoryBlock(0xF0000000, "Pattern Table Filter Paramters","",0x21)
{
	m_name = "Pattern Filters";
	setupParameter("View Part 1", ViewPart1, 0, 1, 1, StringArray::fromTokens("Off On", false), "View Part 1");
	setupParameter("View Part 2", ViewPart2, 0, 1, 1, StringArray::fromTokens("Off On", false), "View Part 2");
	setupParameter("View Part 3", ViewPart3, 0, 1, 1, StringArray::fromTokens("Off On", false), "View Part 3");
	setupParameter("View Part 4", ViewPart4, 0, 1, 1, StringArray::fromTokens("Off On", false), "View Part 4");
	setupParameter("View Part 5", ViewPart5, 0, 1, 1, StringArray::fromTokens("Off On", false), "View Part 5");
	setupParameter("View Part 6", ViewPart6, 0, 1, 1, StringArray::fromTokens("Off On", false), "View Part 6");
	setupParameter("View Part 7", ViewPart7, 0, 1, 1, StringArray::fromTokens("Off On", false), "View Part 7");
	setupParameter("View Part R", ViewPartR, 0, 1, 1, StringArray::fromTokens("Off On", false), "View Part R");
	setupParameter("View Mute Ctrl", ViewMuteCtrl, 0, 1, 1, StringArray::fromTokens("Off On", false), "View Mute Control Part");

	setupParameter("View Single Parts", ViewSingeParts, 0, 1, 0, StringArray::fromTokens("Off On", false));

	StringArray noteNames(StringArray::fromTokens("C -1;C#-1;D -1;D#-1;E -1;F -1;F#-1;G -1;G#-1;A -1;A#-1;B -1;C  0;C# 0;D  0;D# 0;E  0;F  0;F# 0;G  0;G# 0;A  0;A# 0;B  0;C  1;C# 1;D  1;D# 1;E  1;F  1;F# 1;G  1;G# 1;A  1;A# 1;B  1;C  2;C# 2;D  2;D# 2;E  2;F  2;F# 2;G  2;G# 2;A  2;A# 2;B  2;C  3;C# 3;D  3;D# 3;E  3;F  3;F# 3;G  3;G# 3;A  3;A# 3;B  3;C  4;C# 4;D  4;D# 4;E  4;F  4;F# 4;G  4;G# 4;A  4;A# 4;B  4;C  5;C# 5;D  5;D# 5;E  5;F  5;F# 5;G  5;G# 5;A  5;A# 5;B  5;C  6;C# 6;D  6;D# 6;E  6;F  6;F# 6;G  6;G# 6;A  6;A# 6;B  6;C  7;C# 7;D  7;D# 7;E  7;F  7;F# 7;G  7;G# 7;A  7;A# 7;B  7;C  8;C# 8;D  8;D# 8;E  8;F  8;F# 8;G  8;G# 8;A  8;A# 8;B  8;C  9;C# 9;D  9;D# 9;E  9;F  9;F# 9;G  9", ";", String::empty));
	setupParameter("View Notes", ViewNotes, 0, 1, 1, StringArray::fromTokens("Off On", false), "View Note On Events");
	setupParameter("View Notes Min", ViewNotesMin, 0, 127, 0, noteNames, "Note Key range lower limit");
	setupParameter("View Notes Max", ViewNotesMax, 0, 127, 127, noteNames, "Note Key range upper limit");
	setupParameter("View PC", ViewPC, 0, 1, 1, StringArray::fromTokens("Off On", false), "View Program Change Events");
	setupParameter("View CC", ViewCC, 0, 1, 1, StringArray::fromTokens("Off On", false), "View Controller Change Events");
	setupParameter("View CC Min", ViewCCMin, 0, 127, 0, StringArray(), "Controller number range lower limit");
	setupParameter("View CC Max", ViewCCMax, 0, 127, 127, StringArray(), "Controller number range upper limit");
	setupParameter("View BEND", ViewBend, 0, 1, 1, StringArray::fromTokens("Off On", false), "View Pitch Bend Events");
	setupParameter("View P-AFT", ViewPAft, 0, 1, 1, StringArray::fromTokens("Off On", false), "View Polyphonic Aftertouch Events");
	setupParameter("View P-AFT Min", ViewPAftMin, 0, 127, 0, noteNames, "Aftertouch Key range lower limit");
	setupParameter("View P-AFT Max", ViewPAftMax, 0, 127, 127, noteNames, "Aftertouch Key range upper limit");
	setupParameter("View C-AFT", ViewCAft, 0, 1, 1, StringArray::fromTokens("Off On", false), "View Channel Aftertouch Events");
	setupParameter("View Tempo", ViewTempo, 0, 1, 1, StringArray::fromTokens("Off On", false), "View Tempo Change Events");
	setupParameter("View Mute", ViewMute, 0, 1, 1, StringArray::fromTokens("Off On", false), "View Mute Events");
	setupParameter("View SysEx", ViewSysEx, 0, 1, 1, StringArray::fromTokens("Off On", false), "View System Exclusive Events");
	setupParameter("View Notes Off", ViewNotesOff, 0, 1, 0, StringArray::fromTokens("Off On", false), "View Note Off Events");
	setupParameter("View Inc", ViewInc, 0, 1, 0, StringArray::fromTokens("Off On", false), "View Increment Events");
}

void PatternBodyBlock::refreshFilteredContent()
{
	m_filteredsequenceBlocks.clear(true);
	for (int i = 0; i < m_sequenceBlocks.size(); i++)
	{
		if (filter(m_sequenceBlocks[i]))
		{
			PatternEventData* eventCopy = new PatternEventData(*(m_sequenceBlocks[i]));
			m_filteredsequenceBlocks.add(eventCopy);
		}
	}
	// produce note-offs
	if (m_patternTableFilterParams->getParameter(VirtualPatternTableFilterBlock::ViewNotesOff)->getValue() == 1)
	{
		PatternEventData* currentNoteOnEventPtr = nullptr;
		for (int e = 0; e < m_filteredsequenceBlocks.size(); e++)
		{
			currentNoteOnEventPtr = m_filteredsequenceBlocks[e];
			if (currentNoteOnEventPtr->getType() != Evt_Note) continue;
			unsigned long absNoteEndTick = currentNoteOnEventPtr->absoluteTick + currentNoteOnEventPtr->getNoteGateTicks();
			PatternEventData* newNoteOffEvent = new PatternEventData(absNoteEndTick, (uint8)currentNoteOnEventPtr->getNoteNumber(), (uint8)currentNoteOnEventPtr->getPart());
			for (int s = 0; s < m_filteredsequenceBlocks.size(); s++)
			{
				if (m_filteredsequenceBlocks[s]->absoluteTick > absNoteEndTick)
				{
					// sort before
					m_filteredsequenceBlocks.insert(s, newNoteOffEvent);
					break;
				}
				else if (s == m_filteredsequenceBlocks.size() - 1)
				{
					// add to end
					m_filteredsequenceBlocks.add(newNoteOffEvent);
					break;
				}
			}
		}
	}
	sendChangeMessage();
}

void PatternBodyBlock::changeListenerCallback(ChangeBroadcaster *source)
{
	if (Parameter* param = dynamic_cast<Parameter*>(source))
	{
		if (param->getBlock() == m_patternTableFilterParams)
		{
			// when switching to single mode
			if (param->getAddressOffset() == PatternBodyBlock::VirtualPatternTableFilterBlock::ViewSingeParts && param->getValue() == 1)
			{
				Array<uint16> currentlyViewedParts;
				if (m_patternTableFilterParams->getParameter(VirtualPatternTableFilterBlock::ViewPartR)->getValue() == 1)
				{
					currentlyViewedParts.add(VirtualPatternTableFilterBlock::ViewPartR);
				}
				for (uint16 addressOffset = PatternBodyBlock::VirtualPatternTableFilterBlock::ViewPart1; addressOffset <= PatternBodyBlock::VirtualPatternTableFilterBlock::ViewPart7; addressOffset++)
				{
					if (m_patternTableFilterParams->getParameter(addressOffset)->getValue() == 1)
					{
						currentlyViewedParts.add(addressOffset);
					}
				}
				if (m_patternTableFilterParams->getParameter(VirtualPatternTableFilterBlock::ViewMuteCtrl)->getValue() == 1)
				{
					currentlyViewedParts.add(VirtualPatternTableFilterBlock::ViewMuteCtrl);
				}
				// set view off for all parts except first in list of currently viewed
				if (currentlyViewedParts.size() > 1)
				{
					for (uint16 i = 1; i < currentlyViewedParts.size(); i++)
					{
						m_patternTableFilterParams->getParameter(currentlyViewedParts[i])->setValue(0, Parameter::Init);
					}
				}
			}
			else if (param->getAddressOffset() >= PatternBodyBlock::VirtualPatternTableFilterBlock::ViewPart1 && param->getAddressOffset() <= PatternBodyBlock::VirtualPatternTableFilterBlock::ViewMuteCtrl)
			{
				// if a part is selected and if view single part mode
				if (param->getValue()==1 && m_patternTableFilterParams->getParameter(PatternBodyBlock::VirtualPatternTableFilterBlock::ViewSingeParts)->getValue() == 1)
				{
					for (uint16 addressOffset = PatternBodyBlock::VirtualPatternTableFilterBlock::ViewPart1; addressOffset <= PatternBodyBlock::VirtualPatternTableFilterBlock::ViewPart7; addressOffset++)
					{
						if (param->getAddressOffset() != addressOffset) m_patternTableFilterParams->getParameter(addressOffset)->setValue(0, Parameter::Init);
					}
					if (param->getAddressOffset() != VirtualPatternTableFilterBlock::ViewPartR) m_patternTableFilterParams->getParameter(VirtualPatternTableFilterBlock::ViewPartR)->setValue(0, Parameter::Init);
					if (param->getAddressOffset() != VirtualPatternTableFilterBlock::ViewMuteCtrl) m_patternTableFilterParams->getParameter(VirtualPatternTableFilterBlock::ViewMuteCtrl)->setValue(0, Parameter::Init);
				}
			}
			refreshFilteredContent();
		}
	}
}

bool PatternBodyBlock::filter(PatternEventData* event) const
{
	if (event->getPart() == Pattern_Part_1 && m_patternTableFilterParams->getParameter(VirtualPatternTableFilterBlock::ViewPart1)->getValue() == 0) return false;
	if (event->getPart() == Pattern_Part_2 && m_patternTableFilterParams->getParameter(VirtualPatternTableFilterBlock::ViewPart2)->getValue() == 0) return false;
	if (event->getPart() == Pattern_Part_3 && m_patternTableFilterParams->getParameter(VirtualPatternTableFilterBlock::ViewPart3)->getValue() == 0) return false;
	if (event->getPart() == Pattern_Part_4 && m_patternTableFilterParams->getParameter(VirtualPatternTableFilterBlock::ViewPart4)->getValue() == 0) return false;
	if (event->getPart() == Pattern_Part_5 && m_patternTableFilterParams->getParameter(VirtualPatternTableFilterBlock::ViewPart5)->getValue() == 0) return false;
	if (event->getPart() == Pattern_Part_6 && m_patternTableFilterParams->getParameter(VirtualPatternTableFilterBlock::ViewPart6)->getValue() == 0) return false;
	if (event->getPart() == Pattern_Part_7 && m_patternTableFilterParams->getParameter(VirtualPatternTableFilterBlock::ViewPart7)->getValue() == 0) return false;
	if (event->getPart() == Pattern_Part_R && m_patternTableFilterParams->getParameter(VirtualPatternTableFilterBlock::ViewPartR)->getValue() == 0) return false;
	if (event->getPart() == Pattern_MuteCtrl && m_patternTableFilterParams->getParameter(VirtualPatternTableFilterBlock::ViewMuteCtrl)->getValue() == 0) return false;
	if (event->getType() == PatternEventType::Evt_TickInc)
	{
		if (m_patternTableFilterParams->getParameter(VirtualPatternTableFilterBlock::ViewInc)->getValue() == 0) return false;
	}
	if (event->getType() == PatternEventType::Evt_Note)
	{
		if (m_patternTableFilterParams->getParameter(VirtualPatternTableFilterBlock::ViewNotes)->getValue() == 0) return false;
	}
	if (event->getType() == PatternEventType::Evt_NoteOff)
	{
		if (m_patternTableFilterParams->getParameter(VirtualPatternTableFilterBlock::ViewNotesOff)->getValue() == 0) return false;
	}
	if (event->getType() == PatternEventType::Evt_Note || event->getType() == PatternEventType::Evt_NoteOff)
	{
		if (event->getNoteNumber()<m_patternTableFilterParams->getParameter(VirtualPatternTableFilterBlock::ViewNotesMin)->getValue()) return false;
		if (event->getNoteNumber()>m_patternTableFilterParams->getParameter(VirtualPatternTableFilterBlock::ViewNotesMax)->getValue()) return false;
	}
	if (event->getType() == PatternEventType::Evt_Pc)
	{
		if (m_patternTableFilterParams->getParameter(VirtualPatternTableFilterBlock::ViewPC)->getValue() == 0) return false;
	}
	if (event->getType() == PatternEventType::Evt_Cc)
	{
		if (m_patternTableFilterParams->getParameter(VirtualPatternTableFilterBlock::ViewCC)->getValue() == 0) return false;
		if (event->getCcNo()<m_patternTableFilterParams->getParameter(VirtualPatternTableFilterBlock::ViewCCMin)->getValue()) return false;
		if (event->getCcNo()>m_patternTableFilterParams->getParameter(VirtualPatternTableFilterBlock::ViewCCMax)->getValue()) return false;
	}
	if (event->getType() == PatternEventType::Evt_PBend)
	{
		if (m_patternTableFilterParams->getParameter(VirtualPatternTableFilterBlock::ViewBend)->getValue() == 0) return false;
	}
	if (event->getType() == PatternEventType::Evt_PAft)
	{
		if (m_patternTableFilterParams->getParameter(VirtualPatternTableFilterBlock::ViewPAft)->getValue() == 0) return false;
		if (event->getPAftKey()<m_patternTableFilterParams->getParameter(VirtualPatternTableFilterBlock::ViewPAftMin)->getValue()) return false;
		if (event->getPAftKey()>m_patternTableFilterParams->getParameter(VirtualPatternTableFilterBlock::ViewPAftMax)->getValue()) return false;
	}
	if (event->getType() == PatternEventType::Evt_CAft)
	{
		if (m_patternTableFilterParams->getParameter(VirtualPatternTableFilterBlock::ViewCAft)->getValue() == 0) return false;
	}
	if (event->getType() == PatternEventType::Evt_Tempo)
	{
		if (m_patternTableFilterParams->getParameter(VirtualPatternTableFilterBlock::ViewTempo)->getValue() == 0) return false;
	}
	if (event->getType() == PatternEventType::Evt_PartMute || event->getType() == PatternEventType::Evt_RhyMute)
	{
		if (m_patternTableFilterParams->getParameter(VirtualPatternTableFilterBlock::ViewMute)->getValue() == 0) return false;
	}
	if (event->getType() == PatternEventType::Evt_SysExData || event->getType() == PatternEventType::Evt_SysExSize || event->getType() == PatternEventType::Evt_SysExJoined)
	{
		if (m_patternTableFilterParams->getParameter(VirtualPatternTableFilterBlock::ViewSysEx)->getValue() == 0) return false;
	}
	return true;
}

// calculates and refreshes relative inc times from absolute times, from start to first event, between all events from last to end of pattern, if nescessary creates INC entries
void PatternBodyBlock::refreshRelativeTickIncrements()
{
	// delete all existing INC events (they might not be up-to-date)
	for (int i = m_sequenceBlocks.size() - 1; i >= 0; i--) { if (m_sequenceBlocks[i]->getType() == Evt_TickInc) { m_sequenceBlocks.remove(i); } }

	const unsigned long patternStart = 0;
	const unsigned long patternEnd = m_lengthInMeasures * m_beatSigNumerator * getTicksPerBeat();
	
	unsigned long delta(0);
	unsigned long currentAbsoluteTick = patternStart;

	// if emty sequence
	if (m_sequenceBlocks.size() == 0)
	{
		delta = patternEnd - currentAbsoluteTick;
		for (unsigned int j = 0; j < (delta / 0xFF); j++)
		{
			m_sequenceBlocks.add(new PatternEventData(currentAbsoluteTick, 0xFF, 0x80, 0x00));
			currentAbsoluteTick += 0xFF;
		}
		uint8 rest = delta % 0xFF;
		if (rest > 0)
		{
			m_sequenceBlocks.add(new PatternEventData(currentAbsoluteTick, rest, 0x80, 0x00));
			currentAbsoluteTick += rest;
		}
	}
	else
		for (int i = 0; i < m_sequenceBlocks.size(); i++)
	{
		
		delta = ((i + 1) < m_sequenceBlocks.size() ? m_sequenceBlocks[i + 1]->absoluteTick : patternEnd) - currentAbsoluteTick;
		for (unsigned int j = 0; j < (delta / 0xFF); j++)
		{
			m_sequenceBlocks.add(new PatternEventData(currentAbsoluteTick, 0xFF, 0x80, 0x00));
			i++; // increment i, added inc-event would be handled in next itereation otherwise
			currentAbsoluteTick += 0xFF;
		}
		uint8 rest = delta % 0xFF;
		if (rest > 0)
		{
			if (i + 1 >= m_sequenceBlocks.size()) // at end of pattern: add another inc til end
			{
				m_sequenceBlocks.add(new PatternEventData(currentAbsoluteTick, rest, 0x80, 0x00));
				i++; // increment i, added inc-event would be handled in next itereation otherwise
			}
			else
			{
				m_sequenceBlocks[i + 1]->bytes[0] = rest;
			}
			currentAbsoluteTick += rest;
		}
	}
	refreshFilteredContent();
}

// clears entries m_sequenceBlocks, calls refreshRelativeTickIncrements(), calls refreshFilteredContent()
void PatternBodyBlock::clearPattern()
{
	m_sequenceBlocks.clear();
	refreshRelativeTickIncrements();
}

// to be called when beat signature in pattern setup is changed, only 96 (for signatures of N/4) 48 (N/8) or 24 (N/16) will be accepted, else defaulting to 96. updates the viewed table (for tick time display interpretation)
void PatternBodyBlock::setBeatSignature(BeatSignature beatSignature)
{
	m_beatSigNumerator = beatSignature.getNumerator();
	m_beatSigDenominator = beatSignature.getDenominator();
	refreshRelativeTickIncrements();
}

void PatternBodyBlock::setLengthInMeasures(uint8 measures)
{
	m_lengthInMeasures = measures;
	refreshRelativeTickIncrements();
}

// ticks per beat = 96 / (denominator / 4) (e.g. for 11/16 beat --> 96 / (16/4) = 96/4 = 24)
uint8 PatternBodyBlock::getTicksPerBeat()
{
	return 96 / (m_beatSigDenominator / 4);
}

MidiFile* PatternBodyBlock::convertToMidiFile()
{
	PatternSetupConfigBlock* patternSetupConfigPtr = grooveboxMemory->getPatternSetupBlock()->getPatternSetupConfigBlockPtr();
	PatternSetupEffectsBlock* patternSetupEffectsPtr = grooveboxMemory->getPatternSetupBlock()->getPatternSetupEffectsBlockPtr();

	MidiFile* midiFile = new MidiFile();
	midiFile->setTicksPerQuarterNote(96);

	uint8 deviceId = jmax<uint8>(grooveboxConnector->getActiveDeviceId(), 0x10);

	double oneBeat = getTicksPerBeat();
	double oneMeasure = (double)m_beatSigNumerator * oneBeat;
	
	ScopedPointer<MidiMessageSequence> muteCtrlTrack = new MidiMessageSequence();
	muteCtrlTrack->addEvent(SyxMsg::createTextMetaEvent(SyxMsg::TrackName, patternSetupConfigPtr->getPatternName()));
	muteCtrlTrack->addEvent(SyxMsg::createTextMetaEvent(SyxMsg::CopyrightNotice, "Converted with gbMIDI. (C) 2016 by Martin Spindler"));
	muteCtrlTrack->addEvent(SyxMsg::createTextMetaEvent(SyxMsg::DeviceName, "Roland groovebox MC-505 device family"));
	muteCtrlTrack->addEvent(MidiMessage::timeSignatureMetaEvent(patternSetupConfigPtr->getBeatSignature().getNumerator(), patternSetupConfigPtr->getBeatSignature().getDenominator()));
	muteCtrlTrack->addEvent(MidiMessage::tempoMetaEvent((int)(60000000.0 / patternSetupConfigPtr->getTempoBpm())));
	muteCtrlTrack->addEvent(SyxMsg::createTextMetaEvent(SyxMsg::Marker, "Setup"));

	// add 7 tracks (0..6: part 1 to 7; 7: rhythm part, 8: mute ctrl part (sysEx messages)), 
	ScopedPointer<MidiMessageSequence> partRTrack = new MidiMessageSequence();
	partRTrack->addSequence(grooveboxMemory->getPatternSetupBlock()->getPatternSetupPartBlockPtr(AllParts::PartR)->getSinglePartSetupMidiMessageSequence(), 0, 0, oneMeasure);

	ScopedPointer<MidiMessageSequence> part1Track = new MidiMessageSequence();
	part1Track->addSequence(grooveboxMemory->getPatternSetupBlock()->getPatternSetupPartBlockPtr(AllParts::Part1)->getSinglePartSetupMidiMessageSequence(), 0, 0, oneMeasure);

	ScopedPointer<MidiMessageSequence> part2Track = new MidiMessageSequence();
	part2Track->addSequence(grooveboxMemory->getPatternSetupBlock()->getPatternSetupPartBlockPtr(AllParts::Part2)->getSinglePartSetupMidiMessageSequence(), 0, 0, oneMeasure);

	ScopedPointer<MidiMessageSequence> part3Track = new MidiMessageSequence();
	part3Track->addSequence(grooveboxMemory->getPatternSetupBlock()->getPatternSetupPartBlockPtr(AllParts::Part3)->getSinglePartSetupMidiMessageSequence(), 0, 0, oneMeasure);

	ScopedPointer<MidiMessageSequence> part4Track = new MidiMessageSequence();
	part4Track->addSequence(grooveboxMemory->getPatternSetupBlock()->getPatternSetupPartBlockPtr(AllParts::Part4)->getSinglePartSetupMidiMessageSequence(), 0, 0, oneMeasure);

	ScopedPointer<MidiMessageSequence> part5Track = new MidiMessageSequence();
	part5Track->addSequence(grooveboxMemory->getPatternSetupBlock()->getPatternSetupPartBlockPtr(AllParts::Part5)->getSinglePartSetupMidiMessageSequence(), 0, 0, oneMeasure);

	ScopedPointer<MidiMessageSequence> part6Track = new MidiMessageSequence();
	part6Track->addSequence(grooveboxMemory->getPatternSetupBlock()->getPatternSetupPartBlockPtr(AllParts::Part6)->getSinglePartSetupMidiMessageSequence(), 0, 0, oneMeasure);

	ScopedPointer<MidiMessageSequence> part7Track = new MidiMessageSequence();
	part7Track->addSequence(grooveboxMemory->getPatternSetupBlock()->getPatternSetupPartBlockPtr(AllParts::Part7)->getSinglePartSetupMidiMessageSequence(), 0, 0, oneMeasure);

	muteCtrlTrack->addEvent(SyxMsg::createChannelPrefixMetaEvent(0x0E, 1.0));
	muteCtrlTrack->addEvent(SyxMsg::createTextMetaEvent(SyxMsg::TextEvent, "--- SETUP --------------------------------------"), 1.0);
	muteCtrlTrack->addEvent(SyxMsg::createTextMetaEvent(SyxMsg::TrackName, "[MUTE-CTRL]"),1.0);

	// note: don't add TrackName meta event to very first track. might be just a reaper issue but reaper shows all meta (text) events of the first track in all other tracks too

	// effects setups
	MidiMessageSequence mFxSetup = patternSetupEffectsPtr->getM_FX_SetupMidiMessageSequence(deviceId);
	muteCtrlTrack->addSequence(mFxSetup, 6.0, 0.0, oneMeasure);
	MidiMessageSequence revSetup = patternSetupEffectsPtr->getReverbSetupMidiMessageSequence(deviceId);
	muteCtrlTrack->addSequence(revSetup, 12.0, 0.0, oneMeasure);
	MidiMessageSequence dlySetup = patternSetupEffectsPtr->getDelaySetupMidiMessageSequence(deviceId);
	muteCtrlTrack->addSequence(dlySetup, 18.0, 0.0, oneMeasure);
	// parts setup
	muteCtrlTrack->addSequence(patternSetupConfigPtr->getInitalMuteStates(deviceId), oneBeat, 0, oneMeasure);
	muteCtrlTrack->addEvent(SyxMsg::createTextMetaEvent(SyxMsg::TextEvent, "--- END OF SETUP -------------------------------"), oneBeat+oneBeat);

	// offset 1 measure (use first measure for setup)
	muteCtrlTrack->addEvent(SyxMsg::createTextMetaEvent(SyxMsg::Marker, "Pattern Loop Region Start", oneMeasure));
	PatternEventData* event = nullptr;
	for (int i = 0; i < m_sequenceBlocks.size(); i++)
	{
		event = m_sequenceBlocks[i];
		MidiMessageSequence* c_trackPointer = nullptr;
		switch (event->getPart())
		{
		case Pattern_Part_1:	c_trackPointer = part1Track; break;
		case Pattern_Part_2:	c_trackPointer = part2Track; break;
		case Pattern_Part_3:	c_trackPointer = part3Track; break;
		case Pattern_Part_4:	c_trackPointer = part4Track; break;
		case Pattern_Part_5:	c_trackPointer = part5Track; break;
		case Pattern_Part_6:	c_trackPointer = part6Track; break;
		case Pattern_Part_7:	c_trackPointer = part7Track; break;
		case Pattern_Part_R:	c_trackPointer = partRTrack; break;
		case Pattern_MuteCtrl:	c_trackPointer = muteCtrlTrack; break;
		default: break;
		}

		// create midi events
		if (c_trackPointer != nullptr)
		{
			if (event->getType() == Evt_Note)
			{
				c_trackPointer->addEvent(event->toMidiMessage(), event->absoluteTick + oneMeasure);
				c_trackPointer->addEvent(MidiMessage::noteOff(event->getMidiChannel(), event->getNoteNumber()), event->absoluteTick + oneMeasure + event->getNoteGateTicks());
			}
			else if (event->getType() == Evt_PAft || event->getType() == Evt_Cc || event->getType() == Evt_Pc || event->getType() == Evt_CAft || event->getType() == Evt_PBend || event->getType() == Evt_Tempo || event->getType() == Evt_SysExJoined)
			{
				c_trackPointer->addEvent(event->toMidiMessage(), event->absoluteTick + oneMeasure);
			}
			else if (event->getType() == Evt_PartMute)
			{
				c_trackPointer->addEvent(SyxMsg::createTextMetaEvent(SyxMsg::TextEvent, String(event->getMuteState() ? "Unmute " : "Mute ") + event->getPartString(event->getPart()), event->absoluteTick + oneMeasure));
				c_trackPointer->addEvent(event->toMidiMessage(), event->absoluteTick + oneMeasure);
			}
			else if (event->getType() == Evt_RhyMute)
			{
				c_trackPointer->addEvent(SyxMsg::createTextMetaEvent(SyxMsg::TextEvent, String(event->getMuteState() ? "Unmute " : "Mute ") + event->getRhythmGroupString(event->getMuteRhythmGroup()), event->absoluteTick + oneMeasure));
				c_trackPointer->addEvent(event->toMidiMessage(), event->absoluteTick + oneMeasure);
			}
			// igonore Evt_SysExSize, Evt_SysExData, Evt_TickInc, Evt_Unknown
		}
	}
	if (event!=nullptr)
		muteCtrlTrack->addEvent(SyxMsg::createTextMetaEvent(SyxMsg::Marker, "Pattern Loop Region End", oneMeasure + (oneMeasure*patternSetupConfigPtr->getPatternLengthInMeasures())));

	midiFile->addTrack(*partRTrack);
	midiFile->addTrack(*part1Track);
	midiFile->addTrack(*part2Track);
	midiFile->addTrack(*part3Track);
	midiFile->addTrack(*part4Track);
	midiFile->addTrack(*part5Track);
	midiFile->addTrack(*part6Track);
	midiFile->addTrack(*part7Track);
	midiFile->addTrack(*muteCtrlTrack);
	return midiFile;
}

void PatternBodyBlock::createBlockSendMessages(OwnedArray<SyxMsg, CriticalSection>* syxMsgArrayPtr)/* override*/
{
	// concatenate all 8-bit events
	MemoryBlock allEventsAs8Bit;
	PatternEventData* event = nullptr;
	for (int i = 0; i < m_sequenceBlocks.size(); i++)
	{
		event = m_sequenceBlocks[i];
		// skip events that were built after loading
		if (event->getType() == Evt_SysExJoined || event->getType() == Evt_NoteOff) continue;
		allEventsAs8Bit.append(event->bytes, 8);
	}

	DBG("unpacked data: " + String::toHexString(allEventsAs8Bit.getData(), allEventsAs8Bit.getSize()));

	// encode every 7 bytes into 8x 7-bit MIDI data bytes
	MemoryBlock allEventsAs7Bit;
	uint8 encodedBlock[8] = { 0, 0, 0, 0, 0, 0, 0, 0 }; // current 8x 7Bit-Bytes Block, made from 7x 8Bit-Bytes
	uint8 originalBlock[7] = { 0, 0, 0, 0, 0, 0, 0};
	for (unsigned int i = 0; i < allEventsAs8Bit.getSize(); i+=7)
	{
		// get original block of 7 8-bit-bytes
		for (int j = 0; j < 7; j++)  {  originalBlock[j] = (i + j) < allEventsAs8Bit.getSize() ? allEventsAs8Bit[i + j] : 0; }
		
		// set encoded block of 8 7-bit-midi-bytes
		encodedBlock[0] =                                     originalBlock[0] >> 1; //                                           7 most significant bits from 1st byte
		encodedBlock[1] = ((originalBlock[0] & 0x01) << 6) | (originalBlock[1] >> 2); // 1 least significant bit  from 1st byte + 6 most significant bits from 2nd byte
		encodedBlock[2] = ((originalBlock[1] & 0x03) << 5) | (originalBlock[2] >> 3); // 2 least significant bits from 2nd byte + 5 most significant bits from 3rd byte
		encodedBlock[3] = ((originalBlock[2] & 0x07) << 4) | (originalBlock[3] >> 4); // 3 least significant bits from 3rd byte + 4 most significant bits from 4th byte
		encodedBlock[4] = ((originalBlock[3] & 0x0F) << 3) | (originalBlock[4] >> 5); // 4 least significant bits from 4th byte + 3 most significant bits from 5th byte
		encodedBlock[5] = ((originalBlock[4] & 0x1F) << 2) | (originalBlock[5] >> 6); // 5 least significant bits from 5th byte + 2 most significant bits from 6th byte
		encodedBlock[6] = ((originalBlock[5] & 0x3F) << 1) | (originalBlock[6] >> 7); // 6 least significant bits from 6th byte + 1 most significant bit  from least byte 
		encodedBlock[7] =  (originalBlock[6] & 0x7F);                                 // 7 least significant bits from last byte

		allEventsAs7Bit.append(encodedBlock, 8);
	}
	allEventsAs7Bit.setSize((unsigned int)ceilf((float)allEventsAs8Bit.getSize()*8.0f / 7.0f));
	DBG("encoded data: " + String::toHexString(allEventsAs7Bit.getData(), allEventsAs7Bit.getSize()));

	// output encoded bytes as sysex
	uint8 deviceId((grooveboxConnector != nullptr && grooveboxConnector->getActiveConnection()!=nullptr) ? 
		grooveboxConnector->getActiveDeviceId() : 0x10);
	uint8 address[4] = { 0x40, 00, 00, 00 };
	uint8 addressOffset = 0;
	for (unsigned i = 0 ; i < allEventsAs7Bit.getSize(); i += 128)
	{
		unsigned int dataLength = (i + 128) > allEventsAs7Bit.getSize() ? (allEventsAs7Bit.getSize() - i) : 128;
		uint8* data;
		data = new uint8[dataLength];
		allEventsAs7Bit.copyTo(data, i, dataLength);
		address[2] = addressOffset;
		syxMsgArrayPtr->add(new SyxMsg(SyxMsg::Type_DT1, deviceId, address, data, dataLength));
		addressOffset++;
	}
}