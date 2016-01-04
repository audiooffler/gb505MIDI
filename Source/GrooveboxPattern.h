/*
  ==============================================================================

    GrooveboxPattern.h
    Created: 15 Dec 2013 1:04:29pm
    Author:  Martin

  ==============================================================================
*/

#ifndef GROOVEBOXPATTERN_H_INCLUDED
#define GROOVEBOXPATTERN_H_INCLUDED

#include "JuceHeader.h"
#include "MIDIConnection/SyxMsg.h"
#include "GrooveboxPatternSetup.h"
#include "PatternEvent.h"

class GrooveboxPattern
{
public:
	const static uint8 ptnBodyRQ1Address[];
	const static uint8 ptnBodyRQ1Size[];
	const static uint8 ptnAndSetupRQ1Address[];
	const static uint8 ptnAndSetupRQ1Size[];
	const static uint8 part1PatchNameRQ1Address[];
	const static uint8 part2PatchNameRQ1Address[];
	const static uint8 part3PatchNameRQ1Address[];
	const static uint8 part4PatchNameRQ1Address[];
	const static uint8 part5PatchNameRQ1Address[];
	const static uint8 part6PatchNameRQ1Address[];
	const static uint8 part7PatchNameRQ1Address[];
	const static uint8 partRRhythmNameRQ1Address[];
	const static uint8 patchNameRQ1Size[];

	enum PatternPart
	{
		Pattern_Part_1 = 0x00,
		Pattern_Part_2 = 0x01,
		Pattern_Part_3 = 0x02,
		Pattern_Part_4 = 0x03,
		Pattern_Part_5 = 0x04,
		Pattern_Part_6 = 0x05,
		Pattern_Part_7 = 0x06,
		Pattern_Part_R = 0x09,
		Pattern_MuteCtrl = 0x0E,
		Pattern_Part_Unknown = 0xFF
	};

	enum PatternEventType
	{
		Evt_Note = 0,
		Evt_TickInc = 1,
		Evt_PAft = 2,
		Evt_Cc = 3,
		Evt_Pc = 4,
		Evt_CAft = 5,
		Evt_PBend = 6,
		Evt_Tempo = 7,
		Evt_PartMute = 8,
		Evt_RhyMute = 9,
		Evt_SysExSize = 10,
		Evt_SysExData = 11,
		Evt_Unknown = -1
	};

	GrooveboxPattern(uint8 deviceId);
	~GrooveboxPattern();

	// Load pattern SysEx data. True if at least some data with address 30 00 00 00 or 40 00 00 00 where retrieved
	bool loadFromArray(OwnedArray<SyxMsg, CriticalSection>& sysExMessageArray);
	bool loadFromGroovebox();
	bool loadBinarySysExFile(const File& file);
	bool loadHexTxtSysExFile(const File& file);
	bool loadStandardMidiFile(const File& file);

	// unpack SysEx data array, size of unpacked data is returned via rerence parameter. don't forger to delete the returned array after usage
	static const uint8* unpack7BitTo8BitData(const uint8* packed7BitData, int packed7BitDataSize, int &unpackedDataSize)
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

	(OwnedArray<SyxMsg, CriticalSection>)& getSequenceSysExMessages() { return m_sequenceSysExMessages; }
	GrooveboxPatternSetup* getSetup() { return m_patternSetup; }

	// true if at least some pattern sysex data or some setup sysex data was loaded
	bool isNotEmpty()
	{
		return (m_sequenceSysExMessages.size() > 0 || (m_patternSetup!=nullptr && m_patternSetup->getSetupSysExMessages().size() > 0));
	}

	// returns a new Midi File (must later be deleted by caller, inits with tempo settings and creates tracks)
	MidiFile* convertToMidiFile();

private:
	uint8 m_deviceId;	// 0x10 (by default)
	double m_bpm = m_patternSetup->getBPM();
	double m_tickLength; // multiplicate with tickIncrement to calculate time stamps in s, initialized when retrieving pattern setup data

	OwnedArray<SyxMsg, CriticalSection> m_sequenceSysExMessages;
	ScopedPointer<GrooveboxPatternSetup> m_patternSetup;
	OwnedArray<PatternEvent> m_patternEvents;

	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(GrooveboxPattern)
};


#endif  // GROOVEBOXPATTERN_H_INCLUDED
