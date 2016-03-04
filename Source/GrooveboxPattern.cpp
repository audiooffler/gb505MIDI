/*
  ==============================================================================

    GrooveboxPattern.cpp
    Created: 15 Dec 2013 1:04:29pm
    Author:  Martin

  ==============================================================================
*/


#include "GrooveboxPattern.h"
#include "MIDIConnection/GrooveboxConnector.h"

extern GrooveboxConnector* grooveboxConnector;

const uint8 GrooveboxPattern::ptnBodyRQ1Address[] = { 0x40, 0x00, 0x00, 0x00 };
const uint8 GrooveboxPattern::ptnBodyRQ1Size[] = { 0x7F, 0x7F, 0x7F, 0x7F };
const uint8 GrooveboxPattern::ptnAndSetupRQ1Address[] = {0x30, 0x00, 0x00, 0x00};
const uint8 GrooveboxPattern::ptnAndSetupRQ1Size[] = { 0x7F, 0x7F, 0x7F, 0x7F };
const uint8 GrooveboxPattern::part1PatchNameRQ1Address[] = { 0x02, 0x00, 0x00, 0x00 };
const uint8 GrooveboxPattern::part2PatchNameRQ1Address[] = { 0x02, 0x01, 0x00, 0x00 };
const uint8 GrooveboxPattern::part3PatchNameRQ1Address[] = { 0x02, 0x02, 0x00, 0x00 };
const uint8 GrooveboxPattern::part4PatchNameRQ1Address[] = { 0x02, 0x03, 0x00, 0x00 };
const uint8 GrooveboxPattern::part5PatchNameRQ1Address[] = { 0x02, 0x04, 0x00, 0x00 };
const uint8 GrooveboxPattern::part6PatchNameRQ1Address[] = { 0x02, 0x05, 0x00, 0x00 };
const uint8 GrooveboxPattern::part7PatchNameRQ1Address[] = { 0x02, 0x06, 0x00, 0x00 };
const uint8 GrooveboxPattern::partRRhythmNameRQ1Address[] = { 0x02, 0x09, 0x00, 0x00 };
const uint8 GrooveboxPattern::patchNameRQ1Size[] = { 0x00, 0x00, 0x00, 0x0C };

GrooveboxPattern::GrooveboxPattern(uint8 deviceId):
	m_deviceId(deviceId),
	m_bpm(120.0),
	m_tickLength(60 / (96 * m_bpm))
{

}

GrooveboxPattern::~GrooveboxPattern()
{

}

bool GrooveboxPattern::loadFromArray(OwnedArray<SyxMsg, CriticalSection>& sysExMessageArray)
{
	m_sequenceSysExMessages.clear();
	m_patternSetup = new GrooveboxPatternSetup(m_deviceId);
	if (sysExMessageArray.size() > 0)
	{
		m_sequenceSysExMessages.swapWith<OwnedArray<SyxMsg, CriticalSection>>(sysExMessageArray);
		// check for addresses 
		for (int i = m_sequenceSysExMessages.size() - 1; i >= 0; i--)
		{
			if (m_sequenceSysExMessages[i]->get32BitAddress() < 0x02090000){
				uint8* dataPtr;
				uint32 dataLength;
				m_sequenceSysExMessages[i]->getSysExDataArrayPtr(&dataPtr, dataLength);
				String name = (dataLength >= 0xC) ? String((const char*)dataPtr, 12) : "";
				if (name.trim().isNotEmpty()) m_patternSetup->setPartRRhythmnSetName(name);
			}
			if (m_sequenceSysExMessages[i]->get32BitAddress() < 0x02000000){
				uint8* dataPtr;
				uint32 dataLength;
				m_sequenceSysExMessages[i]->getSysExDataArrayPtr(&dataPtr, dataLength);
				String name = (dataLength >= 0xC) ? String((const char*)dataPtr, 12) : "";
				if (name.trim().isNotEmpty()) m_patternSetup->setPart1PatchName(name);
			}
			if (m_sequenceSysExMessages[i]->get32BitAddress() < 0x02010000){
				uint8* dataPtr;
				uint32 dataLength;
				m_sequenceSysExMessages[i]->getSysExDataArrayPtr(&dataPtr, dataLength);
				String name = (dataLength >= 0xC) ? String((const char*)dataPtr, 12) : "";
				if (name.trim().isNotEmpty()) m_patternSetup->setPart2PatchName(name);
			}
			if (m_sequenceSysExMessages[i]->get32BitAddress() < 0x02020000){
				uint8* dataPtr;
				uint32 dataLength;
				m_sequenceSysExMessages[i]->getSysExDataArrayPtr(&dataPtr, dataLength);
				String name = (dataLength >= 0xC) ? String((const char*)dataPtr, 12) : "";
				if (name.trim().isNotEmpty()) m_patternSetup->setPart3PatchName(name);
			}
			if (m_sequenceSysExMessages[i]->get32BitAddress() < 0x02030000){
				uint8* dataPtr;
				uint32 dataLength;
				m_sequenceSysExMessages[i]->getSysExDataArrayPtr(&dataPtr, dataLength);
				String name = (dataLength >= 0xC) ? String((const char*)dataPtr, 12) : "";
				if (name.trim().isNotEmpty()) m_patternSetup->setPart4PatchName(name);
			}
			if (m_sequenceSysExMessages[i]->get32BitAddress() < 0x02040000){
				uint8* dataPtr;
				uint32 dataLength;
				m_sequenceSysExMessages[i]->getSysExDataArrayPtr(&dataPtr, dataLength);
				String name = (dataLength >= 0xC) ? String((const char*)dataPtr, 12) : "";
				if (name.trim().isNotEmpty()) m_patternSetup->setPart5PatchName(name);
			}
			if (m_sequenceSysExMessages[i]->get32BitAddress() < 0x02050000){
				uint8* dataPtr;
				uint32 dataLength;
				m_sequenceSysExMessages[i]->getSysExDataArrayPtr(&dataPtr, dataLength);
				String name = (dataLength >= 0xC) ? String((const char*)dataPtr, 12) : "";
				if (name.trim().isNotEmpty()) m_patternSetup->setPart6PatchName(name);
			}
			if (m_sequenceSysExMessages[i]->get32BitAddress() < 0x02060000){
				uint8* dataPtr;
				uint32 dataLength;
				m_sequenceSysExMessages[i]->getSysExDataArrayPtr(&dataPtr, dataLength);
				String name = (dataLength >= 0xC) ? String((const char*)dataPtr, 12) : "";
				if (name.trim().isNotEmpty()) m_patternSetup->setPart7PatchName(name);
			}
			// not interested in lower addresses (part info, patches, ...)
			if (m_sequenceSysExMessages[i]->get32BitAddress() < 0x300000) m_sequenceSysExMessages.remove(i);
			// > 30 00 00 00
			else if (m_sequenceSysExMessages[i]->get32BitAddress() >= 0x300000 && m_sequenceSysExMessages[i]->get32BitAddress() < 0x40000000)
			{
				m_patternSetup->addAndParseSyxMessage(m_sequenceSysExMessages[i]->copyToNew());
				m_sequenceSysExMessages.remove(i);
			}
			else if (m_sequenceSysExMessages[i]->get32BitAddress() >= 0x400000) // keep pattern data in this array but parse it now
			{

			}
		}
		if (m_sequenceSysExMessages.size()>0 || m_patternSetup->getSetupSysExMessages().size()>0)
		{
			m_bpm = m_patternSetup->getBPM();
			m_tickLength = 60 / (96 * m_bpm);
			return true;
		}
		else return false;
	}
	return false;
}

bool GrooveboxPattern::loadBinarySysExFile(const File& file)
{
	ScopedPointer<FileInputStream> inputStream = file.createInputStream();
	MemoryBlock readBuffer(0);			// buffer for reading the next 1024 bytes from file input stream
	MemoryBlock currentSysExMessage(0);	// buffer for creating a sysex message from read bytes
	OwnedArray<SyxMsg, CriticalSection> sysExMessageArray;

	while (!inputStream->isExhausted())
	{
		// reset readBuffer 
		readBuffer.setSize(0);
		// read next 1024 bytes from stream into readBuffer
		inputStream->readIntoMemoryBlock(readBuffer, 1024);
		// process read readBuffer bytes
		for (unsigned int i = 0; i < readBuffer.getSize(); i++)
		{
			if ((uint8)readBuffer[i] == 0xF0) // sysex start (0xF0)
			{
				currentSysExMessage.setSize(0);					// clear buffer	
				currentSysExMessage.append(&readBuffer[i],1);   // add F0
			}
			else if ((uint8)readBuffer[i] == 0xF7) // sysex stop (0xF7)
			{
				currentSysExMessage.append(&readBuffer[i], 1);	// add F7 
				// create and store completed sysex message
				sysExMessageArray.add(new SyxMsg((uint8*)currentSysExMessage.getData(), (uint32)currentSysExMessage.getSize(), true));
			}
			else // sysex content data (between 0xF0 and 0xF7 bytes)
			{
				currentSysExMessage.append(&readBuffer[i], 1);	// add byte
			}
		}
	}
	return loadFromArray(sysExMessageArray);
}

bool GrooveboxPattern::loadHexTxtSysExFile(const File& file)
{
	MemoryBlock readBuffer;
	// fix ms excel import/export (interpreted hex to standard dez numbers)
	String fileAsString = file.loadFileAsString().replace(" 0 ", " 00 ").replace(" 1 ", " 01 ").replace(" 2 ", " 02 ").replace(" 3 ", " 03 ").replace(" 4 ", " 04 ").replace(" 5 ", " 05 ").replace(" 6 ", " 06 ").replace(" 7 ", " 07 ").replace(" 8 ", " 08 ").replace(" 9 ", " 09 ");
	readBuffer.loadFromHexString(fileAsString);
	MemoryBlock currentSysExMessage(256, true);
	OwnedArray<SyxMsg, CriticalSection> sysExMessageArray;

	// process read readBuffer bytes
	for (unsigned int i = 0; i < readBuffer.getSize(); i++)
	{
		if ((uint8)readBuffer[i] == 0xF0)		// sysex start
		{
			currentSysExMessage.setSize(0);					// clear buffer	
			currentSysExMessage.append(&readBuffer[i], 1);	// add F0
		}
		else if ((uint8)readBuffer[i] == 0xF7)	// sysex stop
		{
			currentSysExMessage.append(&readBuffer[i], 1);	// add F7 
			// create and store completed sysex message
			sysExMessageArray.add(new SyxMsg((uint8*)currentSysExMessage.getData(), (uint32)currentSysExMessage.getSize(), true));
		}
		else					// other sysex data
		{
			currentSysExMessage.append(&readBuffer[i], 1);	// add byte
		}
	}

	return loadFromArray(sysExMessageArray);
}

bool GrooveboxPattern::loadStandardMidiFile(const File& /*file*/)
{
	return false;
}


MidiFile* GrooveboxPattern::convertToMidiFile()
{
	double currentTimestamp (0.0);
	MidiFile* midiFile = new MidiFile();
	midiFile->setTicksPerQuarterNote(96);

	ScopedPointer<MidiMessageSequence> markerTrack = new MidiMessageSequence();
	ScopedPointer<MidiMessageSequence> infoTrack = new MidiMessageSequence();
	if (m_patternSetup != nullptr && m_patternSetup->getPatternName().isNotEmpty()) 
		infoTrack->addEvent(SyxMsg::createTextMetaEvent(SyxMsg::TextEvent, m_patternSetup->getPatternName()));
	infoTrack->addEvent(SyxMsg::createTextMetaEvent(SyxMsg::CopyrightNotice, "Converted with gbMIDI. (C) 2014 by Martin Spindler"));
	infoTrack->addEvent(SyxMsg::createTextMetaEvent(SyxMsg::DeviceName, "Roland groovebox MC-505 device family"));
	// note: don't add TrackName meta event to very first track. might be just a reaper issue but reaper shows all meta (text) events of the first track in all other tracks too

	// add 7 tracks (0..6: part 1 to 7; 7: rhythm part, 8: mute ctrl part (sysEx messages)), 
	ScopedPointer<MidiMessageSequence> partRTrack = new MidiMessageSequence();
	partRTrack->addEvent(SyxMsg::createTextMetaEvent(SyxMsg::TrackName, "PART-R"));
	if (m_patternSetup != nullptr && m_patternSetup->getPartRRhythmnSetName().isNotEmpty())
		partRTrack->addEvent(SyxMsg::createTextMetaEvent(SyxMsg::InstrumentName, m_patternSetup->getPartRRhythmnSetName()));

	ScopedPointer<MidiMessageSequence> part1Track = new MidiMessageSequence();
	part1Track->addEvent(SyxMsg::createTextMetaEvent(SyxMsg::TrackName, "PART-1"));
	if (m_patternSetup != nullptr && m_patternSetup->getPart1PatchName().isNotEmpty())
		part1Track->addEvent(SyxMsg::createTextMetaEvent(SyxMsg::InstrumentName, m_patternSetup->getPart1PatchName()));

	ScopedPointer<MidiMessageSequence> part2Track = new MidiMessageSequence();
	part2Track->addEvent(SyxMsg::createTextMetaEvent(SyxMsg::TrackName, "PART-2"));
	if (m_patternSetup != nullptr && m_patternSetup->getPart2PatchName().isNotEmpty())
		part2Track->addEvent(SyxMsg::createTextMetaEvent(SyxMsg::InstrumentName, m_patternSetup->getPart2PatchName()));

	ScopedPointer<MidiMessageSequence> part3Track = new MidiMessageSequence();
	part3Track->addEvent(SyxMsg::createTextMetaEvent(SyxMsg::TrackName, "PART-3"));
	if (m_patternSetup != nullptr && m_patternSetup->getPart3PatchName().isNotEmpty())
		part3Track->addEvent(SyxMsg::createTextMetaEvent(SyxMsg::InstrumentName, m_patternSetup->getPart3PatchName()));

	ScopedPointer<MidiMessageSequence> part4Track = new MidiMessageSequence();
	part4Track->addEvent(SyxMsg::createTextMetaEvent(SyxMsg::TrackName, "PART-4"));
	if (m_patternSetup != nullptr && m_patternSetup->getPart4PatchName().isNotEmpty())
		part4Track->addEvent(SyxMsg::createTextMetaEvent(SyxMsg::InstrumentName, m_patternSetup->getPart4PatchName()));

	ScopedPointer<MidiMessageSequence> part5Track = new MidiMessageSequence();
	part5Track->addEvent(SyxMsg::createTextMetaEvent(SyxMsg::TrackName, "PART-5"));
	if (m_patternSetup != nullptr && m_patternSetup->getPart5PatchName().isNotEmpty())
		part5Track->addEvent(SyxMsg::createTextMetaEvent(SyxMsg::InstrumentName, m_patternSetup->getPart5PatchName()));

	ScopedPointer<MidiMessageSequence> part6Track = new MidiMessageSequence();
	part6Track->addEvent(SyxMsg::createTextMetaEvent(SyxMsg::TrackName, "PART-6"));
	if (m_patternSetup != nullptr && m_patternSetup->getPart6PatchName().isNotEmpty())
		part6Track->addEvent(SyxMsg::createTextMetaEvent(SyxMsg::InstrumentName, m_patternSetup->getPart6PatchName()));

	ScopedPointer<MidiMessageSequence> part7Track = new MidiMessageSequence();
	part7Track->addEvent(SyxMsg::createTextMetaEvent(SyxMsg::TrackName, "PART-7"));
	if (m_patternSetup != nullptr && m_patternSetup->getPart7PatchName().isNotEmpty())
		part7Track->addEvent(SyxMsg::createTextMetaEvent(SyxMsg::InstrumentName, m_patternSetup->getPart7PatchName()));

	ScopedPointer<MidiMessageSequence> muteCtrlTrack = new MidiMessageSequence();
	muteCtrlTrack->addEvent(SyxMsg::createTextMetaEvent(SyxMsg::TrackName, "MUTE-CTRL"));
	muteCtrlTrack->addEvent(MidiMessage::timeSignatureMetaEvent(m_patternSetup->getBeatNumerator(), m_patternSetup->getBeatDenominator()));
	muteCtrlTrack->addEvent(MidiMessage::tempoMetaEvent((int)(60000000.0 / m_bpm)));

	ScopedPointer<MidiMessageSequence> setupTrack = new MidiMessageSequence();
	setupTrack->addEvent(SyxMsg::createTextMetaEvent(SyxMsg::TrackName, "Setup (M-FX, REV, DLY, PARTS)"));

	// temporary data accumulator for transcoding groovebox sequencer sysex (on mute ctrl part) data to midi sysex events
	MemoryBlock sysExBuilder;
	unsigned int sysExBuilderByteIndex (0);

	if (m_patternSetup != nullptr)
	{
		// effects setups
		setupTrack->addSequence(m_patternSetup->getM_FX_SetupMidiMessageSequence(), 0.0, 0.0, m_patternSetup->getM_FX_SetupMidiMessageSequence().getEndTime() + 96.0);
		setupTrack->addSequence(m_patternSetup->getReverbSetupMidiMessageSequence(), 32.0, 0.0, m_patternSetup->getReverbSetupMidiMessageSequence().getEndTime() + 32.0 + 96.0);
		setupTrack->addSequence(m_patternSetup->getDelaySetupMidiMessageSequence(), 64.0, 0.0, m_patternSetup->getDelaySetupMidiMessageSequence().getEndTime() + 64.0 + 96.0);
		// parts setup
		setupTrack->addSequence(m_patternSetup->getAllPartsSetupMidiMessageSequence(), 96.0, 0.0, m_patternSetup->getAllPartsSetupMidiMessageSequence().getEndTime() + 96.0 + 96.0);
		// offset for sequence data, first measure should just contain setup messages
		currentTimestamp = m_patternSetup->getMeasureLengthInTicks();	
	}

	// offset 1 measure (use first measure for setup)
	markerTrack->addEvent(SyxMsg::createTextMetaEvent(SyxMsg::CuePoint, "Pattern Loop Region Start", currentTimestamp));
	for (int i = 0; i < m_sequenceSysExMessages.size(); i++)
	{	// itereate all sequenc sysex messages with packed data
		if (m_sequenceSysExMessages[i]->getType() == SyxMsg::Type_DT1 && m_sequenceSysExMessages[i]->get32BitAddress()>=0x40000000)
		{
			uint8* packedDataPtr;
			uint32 packedDataSize;
			m_sequenceSysExMessages[i]->getSysExDataArrayPtr(&packedDataPtr, packedDataSize);
			int unpackedDataSize(0);	// will be set by unpack7BitTo8BitData
			const uint8* decodedData = unpack7BitTo8BitData(packedDataPtr, packedDataSize, unpackedDataSize);
			// iterate blocks
			for (int blockNum = 0; blockNum * 8 < unpackedDataSize - 1; blockNum++)
			{
				const uint8* eventBlockPtr = &decodedData[blockNum * 8];

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
				currentTimestamp += c_tickIncrement/**m_tickLength*/;	// multiplicated with m_tickLength would be the timestamp in seconds
			}
			// after processing all blocks
			delete[] decodedData;
		}
	}
	
	markerTrack->addEvent(SyxMsg::createTextMetaEvent(SyxMsg::CuePoint, "Pattern Loop Region End", currentTimestamp));
	midiFile->addTrack(*infoTrack);
	midiFile->addTrack(*markerTrack);
	midiFile->addTrack(*partRTrack);
	midiFile->addTrack(*part1Track);
	midiFile->addTrack(*part2Track);
	midiFile->addTrack(*part3Track);
	midiFile->addTrack(*part4Track);
	midiFile->addTrack(*part5Track);
	midiFile->addTrack(*part6Track);
	midiFile->addTrack(*part7Track);
	midiFile->addTrack(*muteCtrlTrack);
	midiFile->addTrack(*setupTrack);
	return midiFile;
}

