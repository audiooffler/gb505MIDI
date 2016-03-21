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
#include "QuickSysExBlock.h"
#include "../GUI/GrooveboxLookAndFeel.h"

extern OverallMemoryBlock* grooveboxMemory;
extern QuickSysExBlock* quickSysEx;

PatternBodyBlock::PatternBodyBlock() :
	GrooveboxMemoryBlock(0x40000000, "Pattern Body Data", "1-6", 0x00000000),
	m_patternTableFilterParams(new VirtualPatternTableFilterBlock()),
	m_playerThread(new PlayerThread())
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

	m_midiCCNames.set(0, "BANK SEL MSB");
	m_midiCCNames.set(1, "MODULATION");
	m_midiCCNames.set(5, "PORTA TIME");
	m_midiCCNames.set(6, "RPN DATA MSB");
	m_midiCCNames.set(7, "PART LEVEL");
	m_midiCCNames.set(10, "PART PAN");
	m_midiCCNames.set(11, "EXPRESSION");
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
	m_midiCCNames.set(32, "BANK SEL LSB");
	m_midiCCNames.set(34, "FILTER TYPE");
	m_midiCCNames.set(35, "TONE PAN");
	m_midiCCNames.set(36, "TONE LVL");
	m_midiCCNames.set(37, "RND PAN");
	m_midiCCNames.set(38, "RPN DATA LSB");
	m_midiCCNames.set(39, "P-ENV S");
	m_midiCCNames.set(40, "P-ENV R");
	m_midiCCNames.set(64, "HOLD-1");
	m_midiCCNames.set(65, "PORTA SW");
	m_midiCCNames.set(66, "SOSTENUTO");
	m_midiCCNames.set(67, "SOFT");
	m_midiCCNames.set(69, "HOLD-2");
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
	m_midiCCNames.set(84, "PORTA CTRL");
	m_midiCCNames.set(85, "KEY SHIFT");
	m_midiCCNames.set(86, "M-FX SW");
	m_midiCCNames.set(91, "REVERB");
	m_midiCCNames.set(94, "DELAY");
	m_midiCCNames.set(100, "RPN LSB");
	m_midiCCNames.set(101, "RPN MSB");
	m_midiCCNames.set(120, "ALL SOUNDS OFF");
	m_midiCCNames.set(121, "RESET ALL CTRLS");
	m_midiCCNames.set(123, "ALL NOTES OFF");
	m_midiCCNames.set(124, "OMNI OFF");
	m_midiCCNames.set(125, "OMNI ON");
	m_midiCCNames.set(126, "SOLO ON");
	m_midiCCNames.set(127, "SOLO OFF");

	m_keyDrumGroupes.set(35, "BD"); m_keyDrumGroupes.set(36, "BD"); m_keyDrumGroupes.set(47, "BD"); m_keyDrumGroupes.set(48, "BD"); m_keyDrumGroupes.set(95, "BD"); m_keyDrumGroupes.set(96, "BD");
	m_keyDrumGroupes.set(38, "SD"); m_keyDrumGroupes.set(40, "SD"); m_keyDrumGroupes.set(50, "SD"); m_keyDrumGroupes.set(52, "SD"); m_keyDrumGroupes.set(96, "SD"); m_keyDrumGroupes.set(98, "SD");
	m_keyDrumGroupes.set(42, "HH"); m_keyDrumGroupes.set(44, "HH"); m_keyDrumGroupes.set(46, "HH"); m_keyDrumGroupes.set(54, "HH"); m_keyDrumGroupes.set(56, "HH"); m_keyDrumGroupes.set(58, "HH");
	m_keyDrumGroupes.set(39, "CLP"); m_keyDrumGroupes.set(51, "CLP"); m_keyDrumGroupes.set(94, "CLP");
	m_keyDrumGroupes.set(61, "CYM"); m_keyDrumGroupes.set(63, "CYM"); m_keyDrumGroupes.set(64, "CYM"); m_keyDrumGroupes.set(65, "CYM"); m_keyDrumGroupes.set(67, "CYM"); m_keyDrumGroupes.set(69, "CYM"); m_keyDrumGroupes.set(71, "CYM");
	m_keyDrumGroupes.set(37, "PERC"); m_keyDrumGroupes.set(41, "PERC"); m_keyDrumGroupes.set(43, "PERC"); m_keyDrumGroupes.set(45, "PERC"); m_keyDrumGroupes.set(49, "PERC"); m_keyDrumGroupes.set(53, "PERC"); m_keyDrumGroupes.set(55, "PERC"); m_keyDrumGroupes.set(57, "PERC"); m_keyDrumGroupes.set(59, "PERC"); m_keyDrumGroupes.set(60, "PERC"); m_keyDrumGroupes.set(62, "PERC"); m_keyDrumGroupes.set(66, "PERC"); m_keyDrumGroupes.set(68, "PERC"); m_keyDrumGroupes.set(70, "PERC"); m_keyDrumGroupes.set(72, "PERC"); m_keyDrumGroupes.set(73, "PERC"); m_keyDrumGroupes.set(74, "PERC"); m_keyDrumGroupes.set(75, "PERC"); m_keyDrumGroupes.set(76, "PERC"); m_keyDrumGroupes.set(77, "PERC"); m_keyDrumGroupes.set(78, "PERC"); m_keyDrumGroupes.set(79, "PERC"); m_keyDrumGroupes.set(80, "PERC"); m_keyDrumGroupes.set(81, "PERC"); m_keyDrumGroupes.set(82, "PERC");
	m_keyDrumGroupes.set(83, "HIT"); m_keyDrumGroupes.set(84, "HIT"); m_keyDrumGroupes.set(85, "HIT"); m_keyDrumGroupes.set(86, "HIT"); m_keyDrumGroupes.set(87, "HIT"); m_keyDrumGroupes.set(88, "HIT");
	m_keyDrumGroupes.set(89, "OTHERS"); m_keyDrumGroupes.set(90, "OTHERS"); m_keyDrumGroupes.set(91, "OTHERS"); m_keyDrumGroupes.set(92, "OTHERS"); m_keyDrumGroupes.set(93, "OTHERS");
}

PatternBodyBlock::~PatternBodyBlock()
{
	m_playerThread->stopThread(500);
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

String PatternBodyBlock::PatternEventData::getAbsoluteTickString(unsigned int absoluteTicks, bool asLength/*=false*/)
{
	unsigned int ticksPerBeat = grooveboxMemory->getPatternSetupBlock()->getPatternSetupConfigBlockPtr()->getBeatSignature().getTicksPerBeat();
	unsigned int beatsPerMeasure = grooveboxMemory->getPatternSetupBlock()->getPatternSetupConfigBlockPtr()->getBeatSignature().getNumerator();
	unsigned int ticksRest = (absoluteTicks % grooveboxMemory->getPatternSetupBlock()->getPatternSetupConfigBlockPtr()->getBeatSignature().getTicksPerBeat());
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

PatternBodyBlock::PatternEventData::PatternEventData(const uint8* pointerToData, unsigned int pointedDataRestLength)
{
	for (unsigned int j = 0; j < 8; j++) 
	{
		bytes[j] = j < pointedDataRestLength ? pointerToData[j] : 0;
	}
	absoluteTick = PatternEventData::mostRecentAbsoluteTick + lastRelativeTickIncrement;
	PatternEventData::mostRecentAbsoluteTick = absoluteTick;
	PatternEventData::lastRelativeTickIncrement = getRelativeTickIncrement();
}

PatternBodyBlock::PatternEventData::PatternEventData(unsigned long absTick, int8 key, uint8 part)
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
PatternBodyBlock::PatternEventData::PatternEventData(unsigned long absTick, MidiMessageSequence::MidiEventHolder* midiEventHolder):
	isNoteOff(false)
{
	// init with zeroes
	for (int i = 0; i < 8; i++)bytes[i] = 0;

	// set channel bytes
	bytes[2] = (uint8)midiEventHolder->message.getChannel()-1;
	bytes[3] = bytes[2];

	if (midiEventHolder->message.isNoteOn())
	{
		bytes[1] = (uint8)midiEventHolder->message.getNoteNumber();
		bytes[4] = (uint8)midiEventHolder->message.getVelocity();

		uint16 gateTime = 0;
		if (MidiMessageSequence::MidiEventHolder* noteOffHolder = midiEventHolder->noteOffObject)
		{
			gateTime = (uint16)(noteOffHolder->message.getTimeStamp() - midiEventHolder->message.getTimeStamp());
		}
		bytes[6] = (uint8)(gateTime >> 8);
		bytes[7] = (uint8)gateTime & 0xFF;
	}
	else if (midiEventHolder->message.isController())
	{
		bytes[1] = 0x8E;
		bytes[5] = (uint8)midiEventHolder->message.getControllerNumber();
		bytes[6] = (uint8)midiEventHolder->message.getControllerValue();
	}
	else if (midiEventHolder->message.isProgramChange())
	{
		bytes[1] = 0x8F;
		bytes[5] = (uint8)midiEventHolder->message.getProgramChangeNumber();
	}
	else if (midiEventHolder->message.isAftertouch())
	{
		bytes[1] = 0x8D;
		bytes[5] = (uint8)midiEventHolder->message.getNoteNumber();
		bytes[6] = (uint8)midiEventHolder->message.getAfterTouchValue();
	}
	else if (midiEventHolder->message.isChannelPressure())
	{
		bytes[1] = 0x90;
		bytes[5] = (uint8)midiEventHolder->message.getChannelPressureValue();
	}
	else if (midiEventHolder->message.isPitchWheel())
	{
		bytes[1] = 0x91;
		int value = midiEventHolder->message.getPitchWheelValue();
		bytes[6] = (uint8)(value >> 7);
		bytes[5] = value & 0x7F;
	}
	absoluteTick = absTick;
}

PatternBodyBlock::PatternEventData::~PatternEventData()
{
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
			return Pattern_Part_Unknown;
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
	return (uint16)bytes[6] << 7 | (uint16)bytes[5];
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

RhythmGroup PatternBodyBlock::PatternEventData::getMuteRhythmGroup()
{
	return (RhythmGroup)bytes[5];
}

bool PatternBodyBlock::PatternEventData::getMuteState()	// false=Mute, true=On
{
	return bytes[7]==0;
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

String PatternBodyBlock::PatternEventData::toDebugString()
{
	PatternEventType type = getType();
	uint8 sysExData[4] = { 0, 0, 0, 0 };
	if (type == Evt_SysExData) getSysExBytesCopyTo(sysExData);
	String result = String::toHexString(bytes, 8, 1).toUpperCase() + "\t";
	result += getAbsoluteTickString(absoluteTick) + "\t";
	result += String(getRelativeTickIncrement()) + "\t";
	if (type != Evt_TickInc) result += getPartString(getPart()) + "\t";
	result += getTypeString() + "\t";
	result += String(bytes[2]) + "\t";
	switch (type)
	{
	case PatternBodyBlock::Evt_Note:
		result += "v: " + String(getNoteVelocity()).paddedLeft('0', 3) + "\t";
		result += getAbsoluteTickString(getNoteGateTicks(), true) + "\t";
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
		result += String(getMuteState() ? +"Mute" : "On") + "\t";
		break;
	case PatternBodyBlock::Evt_RhyMute:
		result += RhythmNoteBlock::getRhythmGroupString(getMuteRhythmGroup()) + "\t";
		result += String(getMuteState() ? +"Mute" : "On") + "\t";
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
	if (getType() == Evt_Unknown || getPart() == Pattern_Part_Unknown) return MidiMessage(); // just an active sense message (empty sysex)

	if (getType() == PatternBodyBlock::Evt_PartMute)
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
			cellText = event->PatternEventData::getAbsoluteTickString(event->absoluteTick);
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
			if (event->getType() == Evt_Note && event->getPart() == PartR) cellText = m_keyDrumGroupes[event->bytes[1]] + " " + cellText;
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
				cellText = String(event->getCcNo()) + " " + (m_midiCCNames[event->getCcNo()].isNotEmpty() ? m_midiCCNames[event->getCcNo()] : String(event->getCcNo()));
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
				cellText = RhythmNoteBlock::getRhythmGroupString(event->getMuteRhythmGroup());
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
				cellText = event->PatternEventData::getAbsoluteTickString(event->getNoteGateTicks(), true /*gate time counting measures and beats from 0*/);
				break;
			case PatternBodyBlock::Evt_PAft:
				cellText = String(event->getPAftPressure());
				break;
			case PatternBodyBlock::Evt_Cc:
				cellText = String(event->getCcValue());
				break;
			case PatternBodyBlock::Evt_PartMute:
				cellText = String(event->getMuteState() ? "Mute" : "On");
				break;
			case PatternBodyBlock::Evt_RhyMute:
				cellText = String(event->getMuteState() ? "Mute" : "On");
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

void PatternBodyBlock::timerCallback()
{
	if (tableSelectionMidiOut != nullptr)
	{
		for (int i = 1; i < 17; i++) tableSelectionMidiOut->sendMessageNow(MidiMessage::allNotesOff(i));
	}
	stopTimer();
}

void PatternBodyBlock::selectedRowsChanged(int lastRowSelected)
{
	m_lastSelectedRowFilteredsequence = lastRowSelected;
	if (lastRowSelected >= 0 && lastRowSelected < m_filteredsequenceBlocks.size() && tableSelectionMidiOut!=nullptr && !m_playerThread->isThreadRunning())
	{
		stopTimer();
		for (int i = 1; i < 17; i++)
		{
			tableSelectionMidiOut->sendMessageNow(MidiMessage::allNotesOff(i));
		}
		if (m_filteredsequenceBlocks[lastRowSelected]->getMidiChannel() >= 1 && m_filteredsequenceBlocks[lastRowSelected]->getMidiChannel() <= 16)
		{
			MidiMessage midiMsg = m_filteredsequenceBlocks[lastRowSelected]->toMidiMessage();
			if (midiMsg.isNoteOn())
			{
				double bpm = grooveboxMemory->getPatternSetupBlock()->getPatternSetupConfigBlockPtr()->getTempoBpm();
				double noteGateTimeInSeconds = m_filteredsequenceBlocks[lastRowSelected]->getNoteGateTicks() * 60.0/(96.0*bpm);
				startTimer((int)(noteGateTimeInSeconds * 1000.0));
			}
			tableSelectionMidiOut->sendMessageNow(midiMsg);
		}
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
	if (event->getType() == PatternEventType::Evt_SysExData || event->getType() == PatternEventType::Evt_SysExSize)
	{
		if (m_patternTableFilterParams->getParameter(VirtualPatternTableFilterBlock::ViewSysEx)->getValue() == 0) return false;
	}
	return true;
}

bool PatternBodyBlock::isPatternEmpty()
{
	if (m_sequenceBlocks.size() == 0) return true; 
	else
	{
		for (int i = 0; i<m_sequenceBlocks.size(); i++)
		{
			if (m_sequenceBlocks[i]->getType() != PatternEventType::Evt_TickInc)
			{
				return false;
			}
		}
	}
	return true;
}

// calculates and refreshes relative inc times from absolute times, from start to first event, between all events from last to end of pattern, if nescessary creates INC entries
void PatternBodyBlock::refreshRelativeTickIncrements()
{
	if (grooveboxMemory->getPatternSetupBlock()->getPatternSetupConfigBlockPtr()->getPatternLengthInMeasures() < 1) return;
	// delete all existing INC events (they might not be up-to-date)
	for (int i = m_sequenceBlocks.size() - 1; i >= 0; i--) { if (m_sequenceBlocks[i]->getType() == Evt_TickInc) { m_sequenceBlocks.remove(i); } }

	const unsigned long patternStart = 0;
	const unsigned long patternEnd = getPatternLengthInTicks();
	
	unsigned long delta(0);
	unsigned long currentAbsoluteTick = patternStart;

	// if empty sequence: add INCs
	if (m_sequenceBlocks.size() == 0)
	{
		delta = jmax<unsigned long>(patternEnd - currentAbsoluteTick, 0);
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
	else // between sequence events set delta to next (or to patternEnd for last event)
	{
		for (int i = 0; i < m_sequenceBlocks.size(); i++)
		{
			if (i == 0) // at start, before first
			{
				delta = jmax<unsigned long>(m_sequenceBlocks[0]->absoluteTick - patternStart, 0);
				for (unsigned int j = 0; j < (delta / 0xFF); j++)
				{
					m_sequenceBlocks.insert(i,new PatternEventData(currentAbsoluteTick, 0xFF, 0x80, 0x00));
					i++; // increment i, added inc-event would be handled in next itereation otherwise
					currentAbsoluteTick += 0xFF;
				}
				uint8 rest = delta % 0xFF;
				if (rest > 0 || i == 0) // always insert at least on INC at start (guessed, because that's what the MC-307 dumps always seem to have)
				{
					m_sequenceBlocks.insert(i,new PatternEventData(currentAbsoluteTick, rest, 0x80, 0x00));
					i++; // increment i, added inc-event would be handled in next itereation otherwise
					currentAbsoluteTick += rest;
				}

			}
			// till next or end
			delta = jmin<unsigned long>(((i + 1) < m_sequenceBlocks.size() ? m_sequenceBlocks[i + 1]->absoluteTick : patternEnd) - currentAbsoluteTick, patternEnd);
			unsigned int num255s = delta / 0xFF;
			unsigned int rest = delta % 0xFF;

			if (num255s == 0)
			{
				if (rest > 0) // if just some rest
				{
					m_sequenceBlocks[i]->bytes[0] = (uint8)rest;
					currentAbsoluteTick += rest;
				}
			}
			else 
			{
				// set first 255 inc to current
				m_sequenceBlocks[i]->bytes[0] = 0xFF;
				currentAbsoluteTick += 0xFF;
				num255s--;
				// if more add INCs
				while (num255s > 0)
				{
					PatternEventData* inc = new PatternEventData(currentAbsoluteTick, 0xFF, 0x80, 0x00);
					if (i + 1 >= m_sequenceBlocks.size())  m_sequenceBlocks.add(inc);
					else m_sequenceBlocks.insert(i + 1, inc);
					i++; // increment i, added inc-event would be handled in next itereation otherwise
					currentAbsoluteTick += 0xFF;
					num255s--;
				}
				// add rest inc
				if (rest > 0)
				{
					PatternEventData* inc = new PatternEventData(currentAbsoluteTick, (uint8)rest, 0x80, 0x00);
					if (i + 1 >= m_sequenceBlocks.size())  m_sequenceBlocks.add(inc);
					else m_sequenceBlocks.insert(i + 1, inc);
					i++; // increment i, added inc-event would be handled in next itereation otherwise
					currentAbsoluteTick += rest;
				}
			}
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

MidiFile* PatternBodyBlock::convertToMidiFile()
{
	PatternSetupConfigBlock* patternSetupConfigPtr = grooveboxMemory->getPatternSetupBlock()->getPatternSetupConfigBlockPtr();
	PatternSetupEffectsBlock* patternSetupEffectsPtr = grooveboxMemory->getPatternSetupBlock()->getPatternSetupEffectsBlockPtr();

	MidiFile* midiFile = new MidiFile();
	midiFile->setTicksPerQuarterNote(96);

	uint8 deviceId = jmax<uint8>(grooveboxConnector->getActiveDeviceId(), 0x10);

	double oneBeat = grooveboxMemory->getPatternSetupBlock()->getPatternSetupConfigBlockPtr()->getBeatSignature().getTicksPerBeat();
	double oneMeasure = (double)grooveboxMemory->getPatternSetupBlock()->getPatternSetupConfigBlockPtr()->getBeatSignature().getNumerator() * oneBeat;
	
	ScopedPointer<MidiMessageSequence> muteCtrlTrack = new MidiMessageSequence();
	ScopedPointer<MidiMessageSequence> metaInfoTrack = new MidiMessageSequence();

	metaInfoTrack->addEvent(SyxMsg::createTextMetaEvent(SyxMsg::TrackName, patternSetupConfigPtr->getPatternName()));
	metaInfoTrack->addEvent(SyxMsg::createTextMetaEvent(SyxMsg::CopyrightNotice, "Converted with gbMIDI. (C) 2016 by Martin Spindler"));
	metaInfoTrack->addEvent(SyxMsg::createTextMetaEvent(SyxMsg::DeviceName, "Roland groovebox MC-505 device family"));
	metaInfoTrack->addEvent(MidiMessage::timeSignatureMetaEvent(patternSetupConfigPtr->getBeatSignature().getNumerator(), patternSetupConfigPtr->getBeatSignature().getDenominator()));
	metaInfoTrack->addEvent(MidiMessage::tempoMetaEvent((int)(60000000.0 / patternSetupConfigPtr->getTempoBpm())));

	// add 7 tracks (0..6: part 1 to 7; 7: rhythm part, 8: mute ctrl part (sysEx messages)), 
	ScopedPointer<MidiMessageSequence> partRTrack = new MidiMessageSequence();
	partRTrack->addSequence(grooveboxMemory->getPatternSetupBlock()->getPatternSetupPartBlockPtr(AllParts::PartR)->getSinglePartSetupMidiMessageSequence(), 0, 0, 2.0*oneMeasure);

	ScopedPointer<MidiMessageSequence> part1Track = new MidiMessageSequence();
	part1Track->addSequence(grooveboxMemory->getPatternSetupBlock()->getPatternSetupPartBlockPtr(AllParts::Part1)->getSinglePartSetupMidiMessageSequence(), 0, 0, 2.0*oneMeasure);

	ScopedPointer<MidiMessageSequence> part2Track = new MidiMessageSequence();
	part2Track->addSequence(grooveboxMemory->getPatternSetupBlock()->getPatternSetupPartBlockPtr(AllParts::Part2)->getSinglePartSetupMidiMessageSequence(), 0, 0, 2.0*oneMeasure);

	ScopedPointer<MidiMessageSequence> part3Track = new MidiMessageSequence();
	part3Track->addSequence(grooveboxMemory->getPatternSetupBlock()->getPatternSetupPartBlockPtr(AllParts::Part3)->getSinglePartSetupMidiMessageSequence(), 0, 0, 2.0*oneMeasure);

	ScopedPointer<MidiMessageSequence> part4Track = new MidiMessageSequence();
	part4Track->addSequence(grooveboxMemory->getPatternSetupBlock()->getPatternSetupPartBlockPtr(AllParts::Part4)->getSinglePartSetupMidiMessageSequence(), 0, 0, 2.0*oneMeasure);

	ScopedPointer<MidiMessageSequence> part5Track = new MidiMessageSequence();
	part5Track->addSequence(grooveboxMemory->getPatternSetupBlock()->getPatternSetupPartBlockPtr(AllParts::Part5)->getSinglePartSetupMidiMessageSequence(), 0, 0, 2.0*oneMeasure);

	ScopedPointer<MidiMessageSequence> part6Track = new MidiMessageSequence();
	part6Track->addSequence(grooveboxMemory->getPatternSetupBlock()->getPatternSetupPartBlockPtr(AllParts::Part6)->getSinglePartSetupMidiMessageSequence(), 0, 0, 2.0*oneMeasure);

	ScopedPointer<MidiMessageSequence> part7Track = new MidiMessageSequence();
	part7Track->addSequence(grooveboxMemory->getPatternSetupBlock()->getPatternSetupPartBlockPtr(AllParts::Part7)->getSinglePartSetupMidiMessageSequence(), 0, 0, 2.0*oneMeasure);

	muteCtrlTrack->addEvent(SyxMsg::createTextMetaEvent(SyxMsg::Marker, "Setup"));
	muteCtrlTrack->addEvent(SyxMsg::createChannelPrefixMetaEvent(0x0E, 1.0));
	muteCtrlTrack->addEvent(SyxMsg::createTextMetaEvent(SyxMsg::TextEvent, "--- SETUP --------------------------------------"), 1.0);
	muteCtrlTrack->addEvent(SyxMsg::createTextMetaEvent(SyxMsg::TrackName, "[MUTE-CTRL]"),1.0);

	// note: don't add TrackName meta event to very first track. might be just a reaper issue but reaper shows all meta (text) events of the first track in all other tracks too

	
	OwnedArray<SyxMsg,CriticalSection> synthAndRhyhtmBlockSendMessages;
	grooveboxMemory->getSynthPatchesBlock()->createBlockSendMessages(&synthAndRhyhtmBlockSendMessages);
	grooveboxMemory->getRhythmSetBlock()->createBlockSendMessages(&synthAndRhyhtmBlockSendMessages);
	String text = "";
	for (int i = 0; i < synthAndRhyhtmBlockSendMessages.size(); i++)
	{
		if (i < 35) // 7x5 synth patches (patch common + 4 tones each=
		{
			text = "Part " + String((i / 5) + 1)+" Patch ";
			switch (i % 5)
			{
			case 0:
				text += "Common";
				break;
			default:
				text += "Tone " + String(i % 5);
				break;
			}
		}
		else if (i==35) // rhythm common
		{
			text = "Rhythm Set Common";
		}
		else // if (i > 35) rhythm note keys
		{
			text = "Rhythm Set Note for Key# " + String(i - 1);
		}
		muteCtrlTrack->addEvent(SyxMsg::createTextMetaEvent(SyxMsg::TextEvent, text), 4.0 + ((double)i*3.840));
		muteCtrlTrack->addEvent(synthAndRhyhtmBlockSendMessages[i]->toMidiMessage(), 4.0 + ((double)i*3.840));
	}

	// effects setups
	MidiMessageSequence mFxSetup = patternSetupEffectsPtr->getM_FX_SetupMidiMessageSequence(deviceId);
	muteCtrlTrack->addSequence(mFxSetup, oneMeasure + oneBeat, 0.0, 2.0*oneMeasure);
	MidiMessageSequence revSetup = patternSetupEffectsPtr->getReverbSetupMidiMessageSequence(deviceId);
	muteCtrlTrack->addSequence(revSetup, oneMeasure + oneBeat + 3.0, 0.0, 2.0*oneMeasure);
	MidiMessageSequence dlySetup = patternSetupEffectsPtr->getDelaySetupMidiMessageSequence(deviceId);
	muteCtrlTrack->addSequence(dlySetup, oneMeasure + oneBeat + 6.0, 0.0, 2.0*oneMeasure);
	// parts mute setup
	muteCtrlTrack->addSequence(patternSetupConfigPtr->getInitalMuteStates(deviceId), oneMeasure + oneBeat +8.0, 0, 2.0*oneMeasure);


	muteCtrlTrack->addEvent(SyxMsg::createTextMetaEvent(SyxMsg::TextEvent, "--- END OF SETUP -------------------------------"), 2.0*oneMeasure);

	// offset 2 measures (use first two measures for setup)
	muteCtrlTrack->addEvent(SyxMsg::createTextMetaEvent(SyxMsg::Marker, "Pattern Loop Region Start", 2.0*oneMeasure));
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
				c_trackPointer->addEvent(event->toMidiMessage(), event->absoluteTick + (2.0*oneMeasure));
				c_trackPointer->addEvent(MidiMessage::noteOff(event->getMidiChannel(), event->getNoteNumber()), event->absoluteTick + (2.0*oneMeasure) + event->getNoteGateTicks());
			}
			else if (event->getType() == Evt_PAft || event->getType() == Evt_Cc || event->getType() == Evt_Pc || event->getType() == Evt_CAft || event->getType() == Evt_PBend || event->getType() == Evt_Tempo)
			{
				c_trackPointer->addEvent(event->toMidiMessage(), event->absoluteTick + (2.0*oneMeasure));
			}
			else if (event->getType() == Evt_PartMute)
			{
				c_trackPointer->addEvent(SyxMsg::createTextMetaEvent(SyxMsg::TextEvent, String(event->getMuteState() ? "Mute " : "Unmute ") + event->getPartString(event->getPart()), event->absoluteTick + oneMeasure));
				c_trackPointer->addEvent(event->toMidiMessage(), event->absoluteTick + (2.0*oneMeasure));
			}
			else if (event->getType() == Evt_RhyMute)
			{
				c_trackPointer->addEvent(SyxMsg::createTextMetaEvent(SyxMsg::TextEvent, String(event->getMuteState() ? "Mute " : "Unmute ") + RhythmNoteBlock::getRhythmGroupString(event->getMuteRhythmGroup()), event->absoluteTick + oneMeasure));
				c_trackPointer->addEvent(event->toMidiMessage(), event->absoluteTick + (2.0*oneMeasure));
			}
			else if (event->getType() == Evt_SysExSize)
			{
				unsigned int sysExDataSize = event->getSysExSize();
				if (sysExDataSize > 0)
				{
					unsigned int sysExDataBytesToWrite = sysExDataSize;
					MemoryBlock sysExBuilderMemBlock;
					// check the following events for SysExData;
					while ((i + 1) < m_sequenceBlocks.size() && m_sequenceBlocks[i + 1]->getType() == Evt_SysExData && sysExDataBytesToWrite > 0)
					{
						event = m_sequenceBlocks[i + 1];
						sysExBuilderMemBlock.append(&(event->bytes[4]), jmin<int>(sysExDataBytesToWrite, 4));
						sysExDataBytesToWrite -= (sysExDataBytesToWrite > 3) ? 4 : sysExDataBytesToWrite;
						i++;
					}
					if (sysExBuilderMemBlock.getSize() == sysExDataSize)
					{
						ScopedPointer<SyxMsg> msg = new SyxMsg((uint8*)sysExBuilderMemBlock.getData(), sysExDataSize, true);
						c_trackPointer->addEvent(msg->toMidiMessage(), event->absoluteTick + (2.0*oneMeasure));
					}
				}
			}
			// igonore Evt_TickInc, Evt_Unknown
		}
	}
	if (event!=nullptr)
		muteCtrlTrack->addEvent(SyxMsg::createTextMetaEvent(SyxMsg::Marker, "Pattern Loop Region End", (2.0*oneMeasure) + (oneMeasure*patternSetupConfigPtr->getPatternLengthInMeasures())));

	midiFile->addTrack(*metaInfoTrack);
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
		if (event->getType() == Evt_NoteOff) continue;
		allEventsAs8Bit.append(event->bytes, 8);
	}

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
		delete[] data;
	}
}

/*static*/ unsigned int PatternBodyBlock::convertTicksTo96TPQN(const double time, const MidiMessageSequence& tempoEvents, const int timeFormat)
{
	double ticksPerSecondAtPpq96 = 96 / (tempoEvents.getNumEvents()>0 ? tempoEvents.getEventPointer(0)->message.getTempoSecondsPerQuarterNote() : 0.5);
	if (timeFormat < 0)
	{
		double timeInSeconds = time / (-(timeFormat >> 8) * (timeFormat & 0xff));
		return (unsigned int)(timeInSeconds * ticksPerSecondAtPpq96);
	}

	double lastTime = 0.0, correctedTime = 0.0;
	const double tickLen = 1.0 / (timeFormat & 0x7fff); // ticks per quarter
	double secsPerTick = 0.5 * tickLen;
	const int numTempoEvents = tempoEvents.getNumEvents();

	for (int i = 0; i < numTempoEvents; ++i)
	{
		const MidiMessage& m = tempoEvents.getEventPointer(i)->message;
		const double eventTime = m.getTimeStamp();

		if (eventTime >= time)
			break;

		correctedTime += (eventTime - lastTime) * secsPerTick;
		lastTime = eventTime;

		if (m.isTempoMetaEvent())
		{
			secsPerTick = tickLen * m.getTempoSecondsPerQuarterNote();
			ticksPerSecondAtPpq96 = 96 / (tempoEvents.getNumEvents()>0 ? m.getTempoSecondsPerQuarterNote() : 0.5);
		}
		while (i + 1 < numTempoEvents)
		{
			const MidiMessage& m2 = tempoEvents.getEventPointer(i + 1)->message;

			if (m2.getTimeStamp() != eventTime)
				break;

			if (m2.isTempoMetaEvent())
			{
				secsPerTick = tickLen * m2.getTempoSecondsPerQuarterNote();
				ticksPerSecondAtPpq96 = 96 / (tempoEvents.getNumEvents()>0 ? m2.getTempoSecondsPerQuarterNote() : 0.5);
			}
			++i;
		}
	}

	double timeInSeconds = correctedTime + (time - lastTime) * secsPerTick;
	return (unsigned int)(timeInSeconds * ticksPerSecondAtPpq96);
}

void PatternBodyBlock::loadMidiFile(File &file)
{
	ScopedPointer<InputStream> loadStream = file.createInputStream();
	MidiFile midiFile;
	midiFile.readFrom(*loadStream);

	MidiMessageSequence tempoEvents, timeSigEvents;
	midiFile.findAllTempoEvents(tempoEvents);
	midiFile.findAllTimeSigEvents(tempoEvents); // might also contain tempo
	midiFile.findAllTimeSigEvents(timeSigEvents);

	// convert to 96 TPQN
	for (int i = 0; i < midiFile.getNumTracks(); ++i)
	{
		const MidiMessageSequence& ms = *midiFile.getTrack(i);
		for (int j = ms.getNumEvents(); --j >= 0;)
		{
			MidiMessage& m = ms.getEventPointer(j)->message;
			m.setTimeStamp(convertTicksTo96TPQN(m.getTimeStamp(), tempoEvents, midiFile.getTimeFormat()));
		}
	}

	PatternSetupConfigBlock* setupConfig = grooveboxMemory->getPatternSetupBlock()->getPatternSetupConfigBlockPtr();
	
	// load setup bpm and beat time signature
	double bpm = (tempoEvents.getNumEvents()>0 ? 60.0 / tempoEvents.getEventPointer(0)->message.getTempoSecondsPerQuarterNote() : 120);
	setupConfig->setTempoBpm((float)bpm);
	int numerator = 4, denominator = 4;
	if (timeSigEvents.getNumEvents() > 0){ timeSigEvents.getEventPointer(0)->message.getTimeSignatureInfo(numerator, denominator); }
	setupConfig->setBeatSignature((uint8)numerator, (uint8)denominator);
	const uint8 oneBeatLengthInTicks = setupConfig->getBeatSignature().getTicksPerBeat();
	const unsigned int oneMeasureLengthInTicks = setupConfig->getBeatSignature().getNumerator() * oneBeatLengthInTicks;

	MidiMessageSequence::MidiEventHolder* current;

	// check first track: if the very first event is at timestamp 0.0 and is track name: take as title
	setupConfig->setPatternName("");
	if (midiFile.getNumTracks() > 0)
	{
		current = midiFile.getTrack(0)->getEventPointer(0);
		if (current!=nullptr && current->message.isTrackNameEvent() && current->message.getTimeStamp() == 0.0)
			setupConfig->setPatternName(current->message.getTextFromTextMetaEvent());
	}

	// merge into one sequence
	MidiMessageSequence mergedSequence;
	for (int i = 0; i < midiFile.getNumTracks(); i++) mergedSequence.addSequence(*midiFile.getTrack(i), 0.0, 0.0, midiFile.getLastTimestamp()+1.0);
	mergedSequence.sort();
	mergedSequence.updateMatchedPairs();

	// get more information about the pattern
	unsigned long patternBodyStartTickInMidi = 0;
	unsigned long numMeasuresInMidiIncludingSetup = (unsigned long)(mergedSequence.getEndTime() / oneMeasureLengthInTicks);
	unsigned long patternBodyEndTickInMidi = jmax<unsigned long>(numMeasuresInMidiIncludingSetup,1) * oneMeasureLengthInTicks;
	uint8 numMeasures = 1;
	bool firstNote = true;
	for (int i = 0; i < mergedSequence.getNumEvents(); i++)
	{
		current = mergedSequence.getEventPointer(i);
		if (current == nullptr) continue;
		
		// try to load title if not found yet
		if (current->message.isTrackNameEvent() && setupConfig->getPatternName().trim().isEmpty() && current->message.getTimeStamp() == 0.0)
		{
			setupConfig->setPatternName(current->message.getTextFromTextMetaEvent());
		}
		
		// find first note to estimate pattern body start
		if (current->message.isNoteOn())
		{
			if (firstNote)
			{
				// get measure the first note is in
				while (patternBodyStartTickInMidi + oneMeasureLengthInTicks - 1 < (unsigned long)current->message.getTimeStamp())
				{
					patternBodyStartTickInMidi += oneMeasureLengthInTicks;
				}
				firstNote = false; // okay, if first note was found
			}
		}
		if (!current->message.isMetaEvent()&&!current->message.isNoteOff())
		{
			patternBodyEndTickInMidi = (unsigned long)current->message.getTimeStamp()+1;
		}
	}
	unsigned long numTicks = patternBodyEndTickInMidi - patternBodyStartTickInMidi;
	numMeasures = jlimit<uint8>(1, 32, (uint8) ceil((double)numTicks / oneMeasureLengthInTicks));
	setupConfig->setPatternLengthInMeasures(numMeasures);
	setupConfig->getParameter(0x12)->sendChangeMessage();

	bool beforeFirstNoteOnChannel[10] = { true, true, true, true, true, true, true, true, true, true}; // for channel 1 2 3 4 5 6 7 8 9 R
	m_sequenceBlocks.clear();
	// iterate and load messages into pattern setup and body, when loading body data decrease time stamp by offset of patternBodyStartTickInMidi
	for (int i = 0; i < mergedSequence.getNumEvents(); i++)
	{
		current = mergedSequence.getEventPointer(i);
		if (current == nullptr) continue;

		// setup data if some setup measures inserted before pattern body
		if ((unsigned long)current->message.getTimeStamp() < patternBodyStartTickInMidi)
		{
			if (current->message.isController())
			{
				uint8 channel = (uint8)current->message.getChannel();
				AllParts part = AllParts(channel - 1);
				uint8 ccNo = (uint8)current->message.getControllerNumber();
				uint8 val = (uint8)current->message.getControllerValue();
				grooveboxMemory->handleCCFromGroovebox(channel, ccNo, val);
				if ((part >= Part1 && part <= Part7) || part == PartR)
				{
					PatternSetupPartBlock* setupPart = grooveboxMemory->getPatternSetupBlock()->getPatternSetupPartBlockPtr(part);
					switch (ccNo)
					{
					case 0:setupPart->getParameter(0x00)->setValue(val, Parameter::Init); break; // cc0 -> bank sel msb
					case 32:setupPart->getParameter(0x01)->setValue(val, Parameter::Init); break; // cc32 -> bank sel lsb
					case 7:setupPart->getParameter(0x03)->setValue(val, Parameter::Init); break; // cc0 -> vol
					case 10:setupPart->getParameter(0x04)->setValue(val, Parameter::Init); break; // cc0 -> vol
					case 85:setupPart->getParameter(0x05)->setValue(val, Parameter::Init); break; // cc85 -> key shift
					case 91:setupPart->getParameter(0x06)->setValue(val, Parameter::Init); break; // cc91 -> reverb
					case 94:setupPart->getParameter(0x07)->setValue(val, Parameter::Init); break; // cc94 -> delay
					case 86:setupPart->getParameter(0x08)->setValue(val, Parameter::Init); break; // cc86 -> m-fx switch 
					default: break;
					}
					grooveboxMemory->handleCCFromGroovebox(channel, ccNo, val);
					if (tableSelectionMidiOut != nullptr) tableSelectionMidiOut->sendMessageNow(MidiMessage::controllerEvent((int)part + 1, ccNo, val));
				}
			}
			else if (current->message.isProgramChange())
			{
				uint8 channel = (uint8)current->message.getChannel();
				AllParts part = AllParts(channel - 1);
				uint8 progNo = (uint8)current->message.getProgramChangeNumber();
				if ((part >= Part1 && part <= Part7) || part == PartR)
				{
					PatternSetupPartBlock* setupPart = grooveboxMemory->getPatternSetupBlock()->getPatternSetupPartBlockPtr(part);
					setupPart->getParameter(0x02)->setValue(progNo, Parameter::Init); // pc
					if (tableSelectionMidiOut != nullptr) tableSelectionMidiOut->sendMessageNow(MidiMessage::programChange((int)part + 1, progNo));
				}
			}
			else if (current->message.isSysEx())
			{
				int size = current->message.getSysExDataSize();
				const uint8* data = current->message.getSysExData();
				ScopedPointer<SyxMsg> msg = new SyxMsg(data, size, false);
				if (msg->getType() == SyxMsg::Type_DT1)
				{
					grooveboxMemory->handleSysEx(msg);
				}
				else if (msg->getType() == SyxMsg::Type_DT1_Quick)
				{
					quickSysEx->handleSysEx(msg);					
				}
			}
		}
		else // body data if ((unsigned long) current->message.getTimeStamp() >= patternBodyStartTickInMidi)
		{
			uint8 channel = (uint8) current->message.getChannel();
			AllParts part = (AllParts) (channel-1);
			if (current->message.isNoteOn() || 
				current->message.isController() || 
				current->message.isProgramChange() || 
				current->message.isAftertouch() || 
				current->message.isChannelPressure() || 
				current->message.isPitchWheel())
			{
				// if no setup measure(s) and if before first note in this channel:
				if (current->message.isController() && patternBodyStartTickInMidi == 0 && beforeFirstNoteOnChannel[part])
				{
					uint8 ccNo = (uint8)current->message.getControllerNumber();
					uint8 val = (uint8)current->message.getControllerValue();
					if ((part >= Part1 && part <= Part7) || part == PartR)
					{
						PatternSetupPartBlock* setupPart = grooveboxMemory->getPatternSetupBlock()->getPatternSetupPartBlockPtr(part);
						switch (ccNo)
						{
						case 0:setupPart->getParameter(0x00)->setValue(val, Parameter::Init); mergedSequence.deleteEvent(i, false); if (i>0) i--; break; // cc0 -> bank sel msb
						case 32:setupPart->getParameter(0x01)->setValue(val, Parameter::Init); mergedSequence.deleteEvent(i, false); if (i>0) i--; break; // cc32 -> bank sel lsb
						case 7:setupPart->getParameter(0x03)->setValue(val, Parameter::Init); mergedSequence.deleteEvent(i, false); if (i>0) i--;  break; // cc0 -> vol
						case 10:setupPart->getParameter(0x04)->setValue(val, Parameter::Init); mergedSequence.deleteEvent(i, false); if (i>0) i--; break; // cc0 -> vol
						case 85:setupPart->getParameter(0x05)->setValue(val, Parameter::Init); mergedSequence.deleteEvent(i, false); if (i>0) i--; break; // cc85 -> key shift
						case 91:setupPart->getParameter(0x06)->setValue(val, Parameter::Init); mergedSequence.deleteEvent(i, false); if (i>0) i--; break; // cc91 -> reverb
						case 94:setupPart->getParameter(0x07)->setValue(val, Parameter::Init); mergedSequence.deleteEvent(i, false); if (i>0) i--; break; // cc94 -> delay
						case 86:setupPart->getParameter(0x08)->setValue(val, Parameter::Init); mergedSequence.deleteEvent(i, false); if (i>0) i--; break; // cc86 -> m-fx switch 
						default: break;
						}
						grooveboxMemory->handleCCFromGroovebox(channel, ccNo, val);
						if (tableSelectionMidiOut != nullptr) tableSelectionMidiOut->sendMessageNow(MidiMessage::controllerEvent((int)part + 1, ccNo, val));
					}
				}
				else if (current->message.isProgramChange() && patternBodyStartTickInMidi == 0 && beforeFirstNoteOnChannel[part])
				{
					uint8 progNo = (uint8)current->message.getProgramChangeNumber();
					if ((part >= Part1 && part <= Part7) || part == PartR)
					{
						PatternSetupPartBlock* setupPart = grooveboxMemory->getPatternSetupBlock()->getPatternSetupPartBlockPtr(part);
						setupPart->getParameter(0x02)->setValue(progNo, Parameter::Init); // pc
						mergedSequence.deleteEvent(i, false); if (i>0) i--; // remove current pc message
						if (tableSelectionMidiOut != nullptr) tableSelectionMidiOut->sendMessageNow(MidiMessage::programChange((int)part + 1, progNo));
					}
				}
				else
					if (PatternEventData* newEvent = new PatternEventData((unsigned long)current->message.getTimeStamp() - patternBodyStartTickInMidi /*absTicks*/, current))
				{
					if (newEvent->getType() == PatternEventType::Evt_Unknown)
						delete newEvent;
					else
						m_sequenceBlocks.add(newEvent);
					if (current->message.isNoteOnOrOff()) beforeFirstNoteOnChannel[part] = false;
				}
			}
			else if (current->message.isSysEx())
			{	
				ScopedPointer<SyxMsg> syx = new SyxMsg(current->message);
				// quick sysex mute 
				if (syx->getType() == SyxMsg::MessageType::Type_DT1_Quick && (syx->getAddressOffset() >> 8) == 0x70)
				{
					uint32 size;
					uint8* data;
					syx->getSysExDataArrayPtr(&data, size);
					uint8 ccDataL = data[0];
					uint8 ddDataE = data[1];
					PatternEventData* newEvent = new PatternEventData((unsigned long)current->message.getTimeStamp() - patternBodyStartTickInMidi /*absTicks*/,0,0,0);
					newEvent->bytes[1] = 0x93; // mute event type
					newEvent->bytes[2] = 0x0E; // mute ctrl part
					newEvent->bytes[3] = 0x0E; // mute ctrl part
					newEvent->bytes[4] = syx->getAddressOffset() & 0xFF; // 1 = part mute, 2 = rhy mute
					newEvent->bytes[5] = ccDataL; // part or rhythm group
					newEvent->bytes[6] = 0;
					newEvent->bytes[7] = ddDataE; // 0=mute, 1=on;
					m_sequenceBlocks.add(newEvent);
				}
				
				else
				{
					uint32 size;
					uint8* data;
					syx->getAsSysExData(&data, size);
					PatternEventData* newSysExSizeEvent = new PatternEventData((unsigned long)current->message.getTimeStamp() - patternBodyStartTickInMidi /*absTicks*/, 0, 0, 0);
					newSysExSizeEvent->bytes[1] = 0x95; // sysex size event type
					newSysExSizeEvent->bytes[2] = 0x0E; // mute ctrl part
					newSysExSizeEvent->bytes[3] = 0x0E; // mute ctrl part
					newSysExSizeEvent->bytes[4] = (size >> 24) & 0xFF;
					newSysExSizeEvent->bytes[5] = (size >> 16) & 0xFF;
					newSysExSizeEvent->bytes[6] = (size >> 8) & 0xFF;
					newSysExSizeEvent->bytes[7] = size & 0xFF;
					m_sequenceBlocks.add(newSysExSizeEvent);
					unsigned int sIdx = 0;
					// create events of 4 data bytes
					for (int d = 0; d < (int)(ceilf((float)size / 4)); d++)
					{
						PatternEventData* newSysExDataEvent = new PatternEventData((unsigned long)current->message.getTimeStamp() - patternBodyStartTickInMidi /*absTicks*/, 0, 0, 0);
						newSysExDataEvent->bytes[1] = 0x96; // sysex data event type
						newSysExDataEvent->bytes[2] = 0x0E; // mute ctrl part
						newSysExDataEvent->bytes[3] = 0x0E; // mute ctrl part
						// copy bytes from sysex to event (if exceeding size, fill up with zereos)
						for (int b = 4; b < 8; b++)
						{
							newSysExDataEvent->bytes[(uint8)b] = sIdx < size ? data[sIdx] : 0;
							sIdx++;
						}
						m_sequenceBlocks.add(newSysExDataEvent);
					}
				}
			}
		}
	}

	// if no song title found, set by file name
	if (setupConfig->getPatternName().trim().isEmpty()) setupConfig->setPatternName(file.getFileNameWithoutExtension());

	// calculate realative ticks and insert tick increments
	refreshRelativeTickIncrements();
}

bool PatternBodyBlock::saveRawBinary(File& file)
{
	if (file.existsAsFile()) file.deleteFile();	// overwrite!

	PatternBodyBlock::PatternEventData* event = nullptr;
	for (int i = 0; i < m_sequenceBlocks.size(); i++)
	{
		event = m_sequenceBlocks[i];
		// skip events that were built after loading
		if (event->getType() == Evt_NoteOff) continue;
		
		file.appendData(event->bytes, 8);
	}
	return true;
}

bool PatternBodyBlock::saveRawCsv(File& file)
{
	if (file.existsAsFile()) file.deleteFile();	// overwrite!

	PatternBodyBlock::PatternEventData* event = nullptr;
	for (int i = 0; i < m_sequenceBlocks.size(); i++)
	{
		event = m_sequenceBlocks[i];
		// skip events that were built after loading
		if (event->getType() == Evt_NoteOff) continue;

		file.appendText(String::toHexString(event->bytes, 8).toUpperCase() + (i + 1 < m_sequenceBlocks.size() ? "\r\n" : ""));
	}
	return true;
}

const OwnedArray<PatternBodyBlock::PatternEventData>* PatternBodyBlock::getFilteredSequenceBlocks() 
{
	return &m_filteredsequenceBlocks; 
}

unsigned long PatternBodyBlock::getPatternLengthInTicks()
{
	return grooveboxMemory->getPatternSetupBlock()->getPatternSetupConfigBlockPtr()->getPatternLengthInTicks();
}

PatternBodyBlock::PlayerThread::PlayerThread() :
Thread("Pattern Player Thread")
{

}

void PatternBodyBlock::PlayerThread::run()
{
	PatternBodyBlock* pattern = grooveboxMemory->getPatternBodyBlock();
	PatternSetupConfigBlock* setup = grooveboxMemory->getPatternSetupBlock()->getPatternSetupConfigBlockPtr();

	if (pattern->isPatternEmpty()) return;

	unsigned long patternEnd;
	double bpm;
	int currentIndex = currentIndex = pattern->m_lastSelectedRowFilteredsequence;
	PatternBodyBlock::PatternEventData* current;
	int nextIndex = currentIndex + 1;
	PatternBodyBlock::PatternEventData* next;

	// difftime
	unsigned long ticksToWaitUntilNext;
	int milliSecondsToWaitUntilNext;

	uint32 computationTimeOfLastWait = Time::getMillisecondCounter();

	while (!threadShouldExit())
	{
		if (pattern->m_filteredsequenceBlocks.size() < 1)break;
		// tempo / pattern length might change while playing!
		patternEnd = pattern->getPatternLengthInTicks();
		bpm = setup->getTempoBpm();

		// start with first selected row
		if (currentIndex < 0 || currentIndex >= pattern->m_filteredsequenceBlocks.size()) currentIndex = 0;
		current = pattern->m_filteredsequenceBlocks[currentIndex];
		m_currentAbsoluteTimeInTicks = current->absoluteTick;
		// next row would be:
		nextIndex = currentIndex + 1;
		if (nextIndex < 0 || nextIndex >= pattern->m_filteredsequenceBlocks.size()) nextIndex = 0;
		next = pattern->m_filteredsequenceBlocks[nextIndex];
		// but if exceeding pattern length search next within pattern
		if (next->absoluteTick > patternEnd) 
		{ 
			nextIndex = 0; 
			next = pattern->m_filteredsequenceBlocks[nextIndex]; 
		}
		// midi out, time note-off
		//m_patternEventTable->selectRow(currentRow, true, true);
		if (pattern->tableSelectionMidiOut != nullptr)
		{
			pattern->tableSelectionMidiOut->sendMessageNow(current->toMidiMessage());
			if (current->getType() == PatternEventType::Evt_Note)
			{
				double secondsToNoteOff = current->getNoteGateTicks() * 60.0 / (96.0*bpm);
				// note off timer for channel / key
				startTimer(getNoteOffID((uint8)current->getPart(), (uint8)current->getNoteNumber()), (int)(secondsToNoteOff*1000.0));
			}
			pattern->m_lastSelectedRowFilteredsequence = currentIndex;
		}

		// continue with next event
		currentIndex = nextIndex;

		// difftime to next
		ticksToWaitUntilNext = (nextIndex == 0) ? patternEnd - current->absoluteTick + next->absoluteTick : next->absoluteTick - current->absoluteTick;
		if ((signed long)ticksToWaitUntilNext < 0) ticksToWaitUntilNext = 0;
		// wait if pause
		if (ticksToWaitUntilNext > 0)
		{
			milliSecondsToWaitUntilNext = (int)(ticksToWaitUntilNext * 625.0 / bpm); // ticksToWaitUntilNext * 60.0 * 1000.0 / (96.0*bpm)
			// compensate calculation time
			wait(milliSecondsToWaitUntilNext - (Time::getMillisecondCounter() - computationTimeOfLastWait));
			m_currentAbsoluteTimeInTicks = next->absoluteTick;
			sendChangeMessage(); // broadcast change of time in absolute ticks
			computationTimeOfLastWait = Time::getMillisecondCounter();
		}
	}
}

void PatternBodyBlock::PlayerThread::timerCallback(int noteOffId)
{
	uint8 part = 0, key = 0;
	getPartAndKeyFromNoteOffId(noteOffId, part, key);
	if (grooveboxMemory->getPatternBodyBlock()->tableSelectionMidiOut != nullptr)
	{
		grooveboxMemory->getPatternBodyBlock()->tableSelectionMidiOut->sendMessageNow(MidiMessage::noteOff(part + 1, key));
	}
	stopTimer(noteOffId);
}