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
}

bool PatternBodyBlock::handleSysEx(SyxMsg* sysExMsg)
{
	uint32 address = sysExMsg->get32BitAddress();
	if (address >= 0x40000000)
	{
		// if first sysex of pattern body received --> clear
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
			PatternEventData* newPatternEvent = new PatternEventData();
			for (int j = 0; j < 8 && i < patternDataBlockSize; j++) newPatternEvent->byte[j] = patternDataBlock[i + j];
			m_sequenceBlocks.add(newPatternEvent);
			DBG(newPatternEvent->getTypeString()+"\t" + String::toHexString((int)newPatternEvent->byte[0]).paddedLeft('0', 2) + " " + 
				String::toHexString((int)newPatternEvent->byte[1]).paddedLeft('0', 2) + " " +
				String::toHexString((int)newPatternEvent->byte[2]).paddedLeft('0', 2) + " " +
				String::toHexString((int)newPatternEvent->byte[3]).paddedLeft('0', 2) + " " +
				String::toHexString((int)newPatternEvent->byte[4]).paddedLeft('0', 2) + " " +
				String::toHexString((int)newPatternEvent->byte[5]).paddedLeft('0', 2) + " " +
				String::toHexString((int)newPatternEvent->byte[6]).paddedLeft('0', 2) + " " +
				String::toHexString((int)newPatternEvent->byte[7]).paddedLeft('0', 2) + " ");
			/*
			// BYTE 0: get tick increment
			uint8 c_tickIncrement = eventBlockPtr[0];

			// BYTE 1: get sequencer event type
			PatternEventType c_eventType(Evt_Unknown);
			switch (eventBlockPtr[1])
			{
			case 0x80: c_eventType = Evt_TickInc; break;
			case 0x8D: c_eventType = Evt_PAft; break;
			case 0x8E: c_eventType = Evt_Cc; break;
			case 0x8F: c_eventType = Evt_Pc; break;
			case 0x90: c_eventType = Evt_CAft; break;
			case 0x91: c_eventType = Evt_PBend; break;
			case 0x93:
				if (eventBlockPtr[4] == 0x01) c_eventType = Evt_PartMute;
				else if (eventBlockPtr[4] == 0x02) c_eventType = Evt_RhyMute;
				else if (eventBlockPtr[4] == 0x03) c_eventType = Evt_Tempo;
				break;
			case 0x95: c_eventType = Evt_SysExSize; break;
			case 0x96: c_eventType = Evt_SysExData; break;
			default:
				if (eventBlockPtr[1] >= 0x00 && eventBlockPtr[1] <= 0x7F)	// note event
				{
					c_eventType = Evt_Note;
				}
				break;
			}

			// BYTE 2: get part/channel for event
			PatternPart c_eventPart(Pattern_Part_Unknown);
			MidiMessageSequence* c_trackPointer = nullptr;
			switch (eventBlockPtr[2])
			{
			case 0x00:	c_eventPart = Pattern_Part_1; c_trackPointer = part1Track; break;
			case 0x01:	c_eventPart = Pattern_Part_2; c_trackPointer = part2Track; break;
			case 0x02:	c_eventPart = Pattern_Part_3; c_trackPointer = part3Track; break;
			case 0x03:	c_eventPart = Pattern_Part_4; c_trackPointer = part4Track; break;
			case 0x04:	c_eventPart = Pattern_Part_5; c_trackPointer = part5Track; break;
			case 0x05:	c_eventPart = Pattern_Part_6; c_trackPointer = part6Track; break;
			case 0x06:	c_eventPart = Pattern_Part_7; c_trackPointer = part7Track; break;
			case 0x09:	c_eventPart = Pattern_Part_R; c_trackPointer = partRTrack; break;
			case 0x0E:	c_eventPart = Pattern_MuteCtrl; c_trackPointer = muteCtrlTrack; break;
			default: break;
			}

			// create midi events
			if (c_trackPointer != nullptr)
			{
				if (c_eventType == GrooveboxPattern::Evt_Note)
				{
					c_trackPointer->addEvent(MidiMessage::noteOn(c_eventPart + 1, eventBlockPtr[1], eventBlockPtr[4]), currentTimestamp);
					c_trackPointer->addEvent(MidiMessage::noteOff(c_eventPart + 1, eventBlockPtr[1]), currentTimestamp + (uint16)(eventBlockPtr[6] << 8 | eventBlockPtr[7]));
				}
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

PatternBodyBlock::PatternEventData::PatternEventData() 
{
	for (int j = 0; j < 8; j++) byte[j] = 0; 
}

uint8 PatternBodyBlock::PatternEventData::getTickIncrement()
{
	return byte[0];
}

PatternBodyBlock::PatternEventType PatternBodyBlock::PatternEventData::getType()
{
	// BYTE 1: get sequencer event type
	PatternEventType c_eventType(Evt_Unknown);
	switch (byte[1])
	{
	case 0x80: c_eventType = Evt_TickInc; break;
	case 0x8D: c_eventType = Evt_PAft; break;
	case 0x8E: c_eventType = Evt_Cc; break;
	case 0x8F: c_eventType = Evt_Pc; break;
	case 0x90: c_eventType = Evt_CAft; break;
	case 0x91: c_eventType = Evt_PBend; break;
	case 0x93:
		if (byte[4] == 0x01) c_eventType = Evt_PartMute;
		else if (byte[4] == 0x02) c_eventType = Evt_RhyMute;
		else if (byte[4] == 0x03) c_eventType = Evt_Tempo;
		break;
	case 0x95: c_eventType = Evt_SysExSize; break;
	case 0x96: c_eventType = Evt_SysExData; break;
	default:
		if (byte[1] >= 0x00 && byte[1] <= 0x7F)	// note event
		{
			c_eventType = Evt_Note;
		}
		break;
	}
	return c_eventType;
}

String PatternBodyBlock::PatternEventData::getTypeString()
{
	PatternEventType type = getType();
	switch (type)
	{
	case PatternBodyBlock::Evt_Note: 
		return PatternBodyBlock::PatternEventData::NOTENAMES[byte[1]];
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
		return "MUTE R";
	case PatternBodyBlock::Evt_SysExSize:
		return "SYX-SIZE";
	case PatternBodyBlock::Evt_SysExData:
		return "SYX-DATA";
	case PatternBodyBlock::Evt_Unknown:
	default:
		return "?";
	}
}