/*
  ==============================================================================

    PatternBodyBlock.cpp
    Created: 22 Jan 2016 8:27:56pm
    Author:  Martin

  ==============================================================================
*/

#include "PatternBodyBlock.h"

PatternBodyBlock::PatternBodyBlock() :
	GrooveboxMemoryBlock(0x40000000, "Pattern Body Data", "1-6", 0x00000000)
{
	m_name = "Pattern Body";
	// no parameters, just big data block
	m_sequenceBlocks.clear();
	PatternEventData::mostRecentAbsoluteTick = 0;
	PatternEventData::lastRelativeTickIncrement = 0;
}

bool PatternBodyBlock::handleSysEx(SyxMsg* sysExMsg)
{
	uint32 address = sysExMsg->get32BitAddress();
	if (address >= 0x40000000)
	{
		// if first sysex of pattern body received --> clear
		if (address == 0x40000000)
		{
			m_sequenceBlocks.clear();
			PatternEventData::mostRecentAbsoluteTick = 0;
			PatternEventData::lastRelativeTickIncrement = 0;
		}
		if (address == 0x40000000) m_sequenceBlocks.clear();
		uint8* sysExDataPtr;
		uint32 sysExDataSize;
		sysExMsg->getSysExDataArrayPtr(&sysExDataPtr, sysExDataSize);
		const uint8* patternDataBlock;
		int patternDataBlockSize;
		patternDataBlock = unpack7BitTo8BitData(sysExDataPtr, sysExDataSize, patternDataBlockSize);
		DBG("address: 0x" + String::toHexString((int)sysExMsg->get32BitAddress()).paddedLeft('0', 8) + ", SysEx size: " + String(sysExDataSize)+
			", Pattern Block size: " + String(patternDataBlockSize));
		for (int i = 0; i < patternDataBlockSize; i += 8)
		{
			PatternEventData* newPatternEvent = new PatternEventData(patternDataBlock+i, patternDataBlockSize-i);
			m_sequenceBlocks.add(newPatternEvent);
			DBG(String(newPatternEvent->absoluteTick).paddedLeft('0', 5) + " " + 
				newPatternEvent->getTypeString() + "\t" +
				newPatternEvent->getPartString() + "\t" +
				(newPatternEvent->getType() == PatternEventType::Evt_Note ? "Vel: " + String(newPatternEvent->getNoteVelocity())+", ": "") + 
				(newPatternEvent->getType() == PatternEventType::Evt_Note ? "GateTicks: " + String(newPatternEvent->getNoteGateTicks())+", " : "") +
				String::toHexString((int)newPatternEvent->bytes[0]).paddedLeft('0', 2) + " " +
				String::toHexString((int)newPatternEvent->bytes[1]).paddedLeft('0', 2) + " " +
				String::toHexString((int)newPatternEvent->bytes[2]).paddedLeft('0', 2) + " " +
				String::toHexString((int)newPatternEvent->bytes[3]).paddedLeft('0', 2) + " " +
				String::toHexString((int)newPatternEvent->bytes[4]).paddedLeft('0', 2) + " " +
				String::toHexString((int)newPatternEvent->bytes[5]).paddedLeft('0', 2) + " " +
				String::toHexString((int)newPatternEvent->bytes[6]).paddedLeft('0', 2) + " " +
				String::toHexString((int)newPatternEvent->bytes[7]).paddedLeft('0', 2) + " ");
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
		return true;
	}
	return false;
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
		if (bytes[1] >= 0x00 && bytes[1] <= 0x7F)	// note event
		{
			return Evt_Note;
		}
		else return Evt_Unknown;
	}
}

String PatternBodyBlock::PatternEventData::getTypeString()
{
	PatternEventType type = getType();
	switch (type)
	{
	case PatternBodyBlock::Evt_Note: 
		return PatternBodyBlock::PatternEventData::NOTENAMES[bytes[1]];
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
	default: return Pattern_Part_Unknown;
	}
}

String PatternBodyBlock::PatternEventData::getPartString()
{
	PatternPart part = getPart();
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

uint8 PatternBodyBlock::PatternEventData::getNoteVelocity()
{
	return bytes[4];
}

uint16 PatternBodyBlock::PatternEventData::getNoteGateTicks()
{
	return (uint16)(bytes[6] << 8 | bytes[7]);
}

uint8 PatternBodyBlock::PatternEventData::getPAftKey()
{
	return bytes[5];
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
	return (uint16)(bytes[5] << 8 | bytes[6]);
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

uint16 PatternBodyBlock::PatternEventData::getTempValue()
{
	return (uint16)(bytes[6] << 8 | bytes[7]);
}

uint32 PatternBodyBlock::PatternEventData::getSysExSize()
{
	return (uint32)(bytes[4] << 24 | bytes[5] << 16 | bytes[6] << 8 | bytes[7]);
}

void PatternBodyBlock::PatternEventData::getSysExBytes(uint8* fourBytes) // make sure to give reference to a 4-byte array which values are to be set
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
	String result = getAbsoluteTickString(absoluteTick) + "\t";
	result += String(getRelativeTickIncrement()) + "\t";
	result += getTypeString() + "\t";
	result += getPartString() + "\t";
	result += String(bytes[3]) + "\t";
}