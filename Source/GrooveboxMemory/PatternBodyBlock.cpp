/*
  ==============================================================================

    PatternBodyBlock.cpp
    Created: 22 Jan 2016 8:27:56pm
    Author:  Martin

  ==============================================================================
*/

#include "PatternBodyBlock.h"

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
}

bool PatternBodyBlock::handleSysEx(SyxMsg* sysExMsg)
{
	uint32 address = sysExMsg->get32BitAddress();
	if (address < 0x40000000) return false;

	// temporary data accumulator for transcoding groovebox sequencer sysex (on mute ctrl part) data to midi sysex events
	MemoryBlock sysExBuilder;
	unsigned int sysExBuilderByteIndex(0);

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
	const uint8* patternDataBlock;
	int patternDataBlockSize;
	patternDataBlock = unpack7BitTo8BitData(sysExDataPtr, sysExDataSize, patternDataBlockSize);
	/*DBG("address: 0x" + String::toHexString((int)sysExMsg->get32BitAddress()).paddedLeft('0', 8) + ", SysEx size: " + String(sysExDataSize)+
		", Pattern Block size: " + String(patternDataBlockSize));*/
	for (int i = 0; i < patternDataBlockSize; i += 8)
	{
		PatternEventData* newPatternEvent = new PatternEventData(patternDataBlock+i, patternDataBlockSize-i);
		m_sequenceBlocks.add(newPatternEvent);

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
		/*DBG(newPatternEvent->toDebugString());*/
		/*
		else if (c_eventType == GrooveboxPattern::Evt_TickInc)
		{
			// do nothing, just increments the currentTimestamp
		}
		else if (c_eventType == GrooveboxPattern::Evt_PAft)
		{
			c_trackPointer->addEvent(MidiMessage::aftertouchChange(c_eventPart + 1, eventBlockPtr[5], eventBlockPtr[6]), currentTimestamp);
		}
		else if (c_eventType == GrooveboxPattern::Evt_Cc)
		{
			c_trackPointer->addEvent(MidiMessage::controllerEvent(c_eventPart + 1, eventBlockPtr[5], eventBlockPtr[6]), currentTimestamp);
		}
		else if (c_eventType == GrooveboxPattern::Evt_Pc)
		{
			c_trackPointer->addEvent(MidiMessage::programChange(c_eventPart + 1, eventBlockPtr[5]), currentTimestamp);
		}
		else if (c_eventType == GrooveboxPattern::Evt_CAft)
		{
			c_trackPointer->addEvent(MidiMessage::channelPressureChange(c_eventPart + 1, eventBlockPtr[5]), currentTimestamp);
		}
		else if (c_eventType == GrooveboxPattern::Evt_PBend)
		{
			c_trackPointer->addEvent(MidiMessage::pitchWheel(c_eventPart + 1, SyxMsg::getUnsigned14BitValueFrom7BitBytes(eventBlockPtr[5], eventBlockPtr[6])));
		}
		else if (c_eventType == GrooveboxPattern::Evt_Tempo)
		{
			c_trackPointer->addEvent(MidiMessage::tempoMetaEvent((int)(6000000000 / ((uint16)eventBlockPtr[6] << 8 | (uint16)eventBlockPtr[7]))), currentTimestamp);
		}
		else if (c_eventType == GrooveboxPattern::Evt_PartMute)
		{
			uint8 quickSysExAddress[2]{0x70, 0x01};
			uint8 quickSysExData[2]{eventBlockPtr[5], eventBlockPtr[7]};
			ScopedPointer<SyxMsg> msg = new SyxMsg(SyxMsg::Type_DT1_Quick, m_deviceId, quickSysExAddress, quickSysExData, 2, SyxMsg::calcDt1Checksum(quickSysExAddress, 2, quickSysExData, 2));
			c_trackPointer->addEvent(SyxMsg::createTextMetaEvent(SyxMsg::TextEvent, String((eventBlockPtr[7]) ? "Unmute " : "Mute ") + GrooveboxPatternSetup::getPartName((GrooveboxPatternSetup::PartSelector)eventBlockPtr[5])), currentTimestamp);
			c_trackPointer->addEvent(msg->getAsMidiMessage(), currentTimestamp);
		}
		else if (c_eventType == GrooveboxPattern::Evt_RhyMute)
		{
			uint8 quickSysExAddress[2]{0x70, 0x02};
			uint8 quickSysExData[2]{eventBlockPtr[5], eventBlockPtr[7]};
			ScopedPointer<SyxMsg> msg = new SyxMsg(SyxMsg::Type_DT1_Quick, m_deviceId, quickSysExAddress, quickSysExData, 2, SyxMsg::calcDt1Checksum(quickSysExAddress, 2, quickSysExData, 2));
			c_trackPointer->addEvent(SyxMsg::createTextMetaEvent(SyxMsg::TextEvent, String((eventBlockPtr[7]) ? "Unmute " : "Mute ") + GrooveboxPatternSetup::getRhythmGroupName((GrooveboxPatternSetup::RhythmGroupSelector)eventBlockPtr[5])), currentTimestamp);
			c_trackPointer->addEvent(msg->getAsMidiMessage(), currentTimestamp);
		}
		else if (c_eventType == GrooveboxPattern::Evt_SysExSize)
		{
			sysExBuilder.setSize((uint32)eventBlockPtr[4] << 24 | (uint32)eventBlockPtr[5] << 16 | (uint32)eventBlockPtr[6] << 8 | (uint32)eventBlockPtr[7]);
			sysExBuilderByteIndex = 0;
		}
		else if (c_eventType == GrooveboxPattern::Evt_SysExData)
		{
			for (int b = 4; b < 8 && sysExBuilderByteIndex<sysExBuilder.getSize(); b++)
			{
				sysExBuilder[sysExBuilderByteIndex] = eventBlockPtr[b];
				sysExBuilderByteIndex++;
				if (eventBlockPtr[b] == 0xF7)	// SYSEX EOX --> create midi message
				{
					c_trackPointer->addEvent(MidiMessage::createSysExMessage(sysExBuilder.getData(), sysExBuilder.getSize()), currentTimestamp);
					sysExBuilder.setSize(0);
					sysExBuilderByteIndex = 0;
					break;
				}
			}
		}
		else if (c_eventType == GrooveboxPattern::Evt_Unknown)
		{
			// ignore
		}

		// after finish processing current event: position timestamp for next event
		*/
		//currentTimestamp += c_tickIncrement/**m_tickLength*/;	// multiplicated with m_tickLength would be the timestamp in seconds
		
	}
	// TODO: call TableListBox::updateContent();
	refreshFilteredContent();
	return true;
}

// unpack SysEx data array, size of unpacked data is returned via rerence parameter. don't forger to delete the returned array after usage
const uint8* PatternBodyBlock::unpack7BitTo8BitData(const uint8* packed7BitData, int packed7BitDataSize, int &unpackedDataSize)
{
	// following declarations will be function paramers, last one by refrence
	unpackedDataSize = packed7BitDataSize - (packed7BitDataSize / 8);
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
	//DBG(String::toHexString(unpackedData,unpackedDataSize,1));
	return unpackedData;
}

const String PatternBodyBlock::PatternEventData::NOTENAMES[] = { "C -1","C#-1","D -1","D#-1","E -1","F -1","F#-1","G -1","G#-1","A -1","A#-1","B -1","C  0","C# 0","D  0","D# 0","E  0","F  0","F# 0","G  0","G# 0","A  0","A# 0","B  0","C  1","C# 1","D  1","D# 1","E  1","F  1","F# 1","G  1","G# 1","A  1","A# 1","B  1","C  2","C# 2","D  2","D# 2","E  2","F  2","F# 2","G  2","G# 2","A  2","A# 2","B  2","C  3","C# 3","D  3","D# 3","E  3","F  3","F# 3","G  3","G# 3","A  3","A# 3","B  3","C  4","C# 4","D  4","D# 4","E  4","F  4","F# 4","G  4","G# 4","A  4","A# 4","B  4","C  5","C# 5","D  5","D# 5","E  5","F  5","F# 5","G  5","G# 5","A  5","A# 5","B  5","C  6","C# 6","D  6","D# 6","E  6","F  6","F# 6","G  6","G# 6","A  6","A# 6","B  6","C  7","C# 7","D  7","D# 7","E  7","F  7","F# 7","G  7","G# 7","A  7","A# 7","B  7","C  8","C# 8","D  8","D# 8","E  8","F  8","F# 8","G  8","G# 8","A  8","A# 8","B  8","C  9","C# 9","D  9","D# 9","E  9","F  9","F# 9","G  9" };

const unsigned int PatternBodyBlock::PatternEventData::ticksPerQuarterNote = 96;
unsigned long PatternBodyBlock::PatternEventData::mostRecentAbsoluteTick = 0;
uint8 PatternBodyBlock::PatternEventData::lastRelativeTickIncrement = 0;

String PatternBodyBlock::PatternEventData::getAbsoluteTickString(unsigned int absoluteTicks)
{
	unsigned int ticksRest = (absoluteTicks % ticksPerQuarterNote);
	unsigned int quarter = absoluteTicks / ticksPerQuarterNote;
	unsigned int measure = quarter / 4;
	quarter = quarter % 4;
	return String(measure).paddedLeft('0', 2) + "-" + String(quarter).paddedLeft('0', 2) + "-" + String(ticksRest).paddedLeft('0', 2);
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
		return"TomPerc";
	case PatternBodyBlock::Rhythm_Group_Hit:
		return "Hit";
	case PatternBodyBlock::Rhythm_Group_Others:
		return "Others";
	case PatternBodyBlock::Rhythm_Group_All:
		return "All";
	case PatternBodyBlock::Rhythm_Group_Unknown:
	default:
		return "Unknown";
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

PatternBodyBlock::PatternEventData::PatternEventData(unsigned long absTick, MemoryBlock* joinedSysex)
{
	for (unsigned int j = 0; j < 8; j++) { bytes[j] = 0; }
	absoluteTick = absTick;
	m_joinedSysexData->setSize(joinedSysex->getSize());
	m_joinedSysexData->copyFrom(joinedSysex->getData(), 0, joinedSysex->getSize());
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
		else if (m_joinedSysexData->getSize() > 0)
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
		// fallback to byte 2
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
		default:	return Pattern_Part_Unknown;
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

uint16 PatternBodyBlock::PatternEventData::getTempoValue()
{
	return ((uint16)bytes[6] << 8 | (uint16)bytes[7]) / (uint16)1000;
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
		result += getAbsoluteTickString(getNoteGateTicks()) + "\t";
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
	g.fillAll(rowIsSelected ? Colours::lightskyblue : Colours::transparentBlack);
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
			cellText = PatternEventData::getAbsoluteTickString(event->absoluteTick);
			break;
		case PatternBodyBlock::Col_Raw0:
			cellText = String::toHexString((int)event->bytes[0]).toUpperCase();
			break;
		case PatternBodyBlock::Col_TicksInc:
			cellText = String(event->getRelativeTickIncrement());
			break;
		case PatternBodyBlock::Col_Raw1:
			cellText = String::toHexString((int)event->bytes[1]).toUpperCase();
			break;
		case PatternBodyBlock::Col_EventType:
			cellText = event->getTypeString();
			break;
		case PatternBodyBlock::Col_Raw2:
			cellText = String::toHexString((int)event->bytes[2]).toUpperCase();
			break;
		case PatternBodyBlock::Col_Raw3:
			cellText = String::toHexString((int)event->bytes[3]).toUpperCase();
			break;
		case PatternBodyBlock::Col_Part:
			cellText = PatternEventData::getPartString(event->getPart());
			break;
		case PatternBodyBlock::Col_Raw4:
			cellText = String::toHexString((int)event->bytes[4]).toUpperCase();
			break;
		case PatternBodyBlock::Col_Raw5:
			cellText = String::toHexString((int)event->bytes[5]).toUpperCase();
			break;
		case PatternBodyBlock::Col_Raw6:
			cellText = String::toHexString((int)event->bytes[6]).toUpperCase();
			break;
		case PatternBodyBlock::Col_Raw7:
			cellText = String::toHexString((int)event->bytes[7]).toUpperCase();
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
				cellText = String(event->getCcNo());
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
				cellText = PatternEventData::getAbsoluteTickString(event->getNoteGateTicks());
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
	GrooveboxMemoryBlock(0xF0000000, "Pattern Table Filter Paramters","",0x20)
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

	StringArray noteNames(StringArray::fromTokens("C -1;C#-1;D -1;D#-1;E -1;F -1;F#-1;G -1;G#-1;A -1;A#-1;B -1;C  0;C# 0;D  0;D# 0;E  0;F  0;F# 0;G  0;G# 0;A  0;A# 0;B  0;C  1;C# 1;D  1;D# 1;E  1;F  1;F# 1;G  1;G# 1;A  1;A# 1;B  1;C  2;C# 2;D  2;D# 2;E  2;F  2;F# 2;G  2;G# 2;A  2;A# 2;B  2;C  3;C# 3;D  3;D# 3;E  3;F  3;F# 3;G  3;G# 3;A  3;A# 3;B  3;C  4;C# 4;D  4;D# 4;E  4;F  4;F# 4;G  4;G# 4;A  4;A# 4;B  4;C  5;C# 5;D  5;D# 5;E  5;F  5;F# 5;G  5;G# 5;A  5;A# 5;B  5;C  6;C# 6;D  6;D# 6;E  6;F  6;F# 6;G  6;G# 6;A  6;A# 6;B  6;C  7;C# 7;D  7;D# 7;E  7;F  7;F# 7;G  7;G# 7;A  7;A# 7;B  7;C  8;C# 8;D  8;D# 8;E  8;F  8;F# 8;G  8;G# 8;A  8;A# 8;B  8;C  9;C# 9;D  9;D# 9;E  9;F  9;F# 9;G  9", ";", String::empty));
	setupParameter("View Notes", ViewNotes, 0, 1, 1, StringArray::fromTokens("Off On", false), "View Note Events");
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
}

void PatternBodyBlock::refreshFilteredContent()
{
	m_filteredsequenceBlocks.clearQuick(true);
	for (int i = 0; i < m_sequenceBlocks.size(); i++)
	{
		if (filter(m_sequenceBlocks[i]))
		{
			PatternEventData* eventCopy = new PatternEventData(*(m_sequenceBlocks[i]));
			m_filteredsequenceBlocks.add(eventCopy);
		}
	}
	// produce note-offs
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
	sendChangeMessage();
}

void PatternBodyBlock::changeListenerCallback(ChangeBroadcaster *source)
{
	if (Parameter* param = dynamic_cast<Parameter*>(source))
	{
		if (param->getBlock() == m_patternTableFilterParams)
			refreshFilteredContent();
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
	if (event->getType() == PatternEventType::Evt_Note || event->getType() == PatternEventType::Evt_NoteOff)
	{
		if (m_patternTableFilterParams->getParameter(VirtualPatternTableFilterBlock::ViewNotes)->getValue() == 0) return false;
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