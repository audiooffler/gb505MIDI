/*
  ==============================================================================

    GrooveboxPatternSetup.h
    Created: 8 Dec 2013 10:57:48pm
    Author:  Martin

  ==============================================================================
*/

#ifndef GROOVEBOXPATTERNSETUP_H_INCLUDED
#define GROOVEBOXPATTERNSETUP_H_INCLUDED

#include "JuceHeader.h"
#include "MIDIConnection/SyxMsg.h"

class GrooveboxPatternSetup
{
public:
	const static uint8 ptnSetupRQ1Address[];
	const static uint8 ptnSetupRQ1Size[];

	enum PartSelector
	{
		Setup_Part_1 = 0x00,
		Setup_Part_2 = 0x01,
		Setup_Part_3 = 0x02,
		Setup_Part_4 = 0x03,
		Setup_Part_5 = 0x04,
		Setup_Part_6 = 0x05,
		Setup_Part_7 = 0x06,
		Setup_Part_R = 0x09,
		Setup_MuteCtrl = 0x0E
	};

	enum RhythmGroupSelector
	{
		Setup_RhyGrp_BD = 0x00,
		Setup_RhyGrp_SD = 0x01,
		Setup_RhyGrp_HH = 0x02,
		Setup_RhyGrp_CLP = 0x03,
		Setup_RhyGrp_CYM = 0x04,
		Setup_RhyGrp_TOMPERC = 0x05,
		Setup_RhyGrp_HIT = 0x06,
		Setup_RhyGrp_OTHERS = 0x07
	};

	struct M_FX_Setup
	{
		uint8 type = 0;				//   0 -  24
		uint8 param[12];			//   0 - 127 each
		uint8 toDelaySendLevel = 0;	//   0 - 127
		uint8 toReverbSendLevel = 0;//   0 - 127
		String getTypeName()
		{
			switch (type)
			{
			case 0: return "4BAND EQ";
			case 1: return "SPECTRUM";
			case 2: return "ENHANCER";
			case 3: return "OVERDRIVE";
			case 4: return "DISTORTION";
			case 5: return "LO-FI";
			case 6: return "NOISE";
			case 7: return "RADIO TUNING";
			case 8: return "PHONOGRAPH";
			case 9: return "COMPRESSOR";
			case 10: return "LIMITER";
			case 11: return "SLICER";
			case 12: return "TREMOLO";
			case 13: return "PHASER";
			case 14: return "CHORUS";
			case 15: return "SPACE-D";
			case 16: return "TETRA CHORUS";
			case 17: return "FLANGER";
			case 18: return "STEP FLANGER";
			case 19: return "SHORT DELAY";
			case 20: return "AUTO PAN";
			case 21: return "FB PITCH SHIFTER";
			case 22: return "REVERB";
			case 23: return "GATE REVERB";
			case 24: return "ISOLATOR";
			default: return String::empty;
			}
		}
	};

	struct ReverbSetup
	{
		uint8 reverbType = 0;		// 0 - 7  (ROOM1, ROOM2, STAGE1, STAGE2, HALL1, HALL2)
		uint8 reverbLevel = 0;		// 0 - 127
		uint8 reverbTime = 0;		// 0 - 127
		uint8 reverbHFDamp = 0;		// 0 - 17 (200, 250, 315, 400, 500, 630, 800, 1000, 1250, 1600, 2000, 2500, 3150, 4000, 5000, 6300, 8000, BYPASS)

	};

	struct DelaySetup
	{
		uint8 delayLevel = 0;		// 0 - 127
		uint8 delayType = 0;		// 0 - 1 (SHORT, LONG)	
		uint8 delayHFDamp = 0;		// 0 - 17 (200, 250, 315, 400, 500, 630, 800, 1000, 1250, 1600, 2000, 2500, 3150, 4000, 5000, 6300, 8000, BYPASS)
		uint8 delayTime = 0;		// 0 - 120
		uint8 delayFbLevel = 0;		// 0 - 98
		uint8 delayOutAssign = 0;	// 0 - 2 (LINE, REV, LINE+REV)
	};

	struct SinglePartSetup
	{
		SinglePartSetup(GrooveboxPatternSetup::PartSelector partSelector) :
			part(partSelector),
			channel((uint8)partSelector + 1)
		{
		}
		PartSelector part;
		uint8 channel;
		uint8 bankSelectMSB = 0;
		uint8 bankSelectLSB = 0;
		uint8 programNumber = 0;
		uint8 mixerLevel = 0;
		uint8 mixerPan = 0;
		uint8 mixerKeyShift = 0;
		uint8 mixerRevLevel = 0;
		uint8 mixerDlyLevel = 0;
		uint8 mixerMFxSwitch = 0;
	};

	struct PartsSetup
	{
		SinglePartSetup part1 = SinglePartSetup(PartSelector::Setup_Part_1);
		SinglePartSetup part2 = SinglePartSetup(PartSelector::Setup_Part_2);
		SinglePartSetup part3 = SinglePartSetup(PartSelector::Setup_Part_3);
		SinglePartSetup part4 = SinglePartSetup(PartSelector::Setup_Part_4);
		SinglePartSetup part5 = SinglePartSetup(PartSelector::Setup_Part_5);
		SinglePartSetup part6 = SinglePartSetup(PartSelector::Setup_Part_6);
		SinglePartSetup part7 = SinglePartSetup(PartSelector::Setup_Part_7);
		SinglePartSetup partR = SinglePartSetup(PartSelector::Setup_Part_R);
	};

	// takes pointer to data buffer (must have already removed f0, header, checksum and f7)
	GrooveboxPatternSetup(uint8 deviceId):
		m_deviceId (deviceId),
		m_patternName(String::empty),
		m_beatNumerator(4),
		m_beatDenominator(4),
		m_numMeasures(0),
		m_bpm(120.0),
		m_part1PatchName(String::empty),
		m_part2PatchName(String::empty),
		m_part3PatchName(String::empty),
		m_part4PatchName(String::empty),
		m_part5PatchName(String::empty),
		m_part6PatchName(String::empty),
		m_part7PatchName(String::empty),
		m_partRRhythmnSetName(String::empty),
		m_mutePart1(false),
		m_mutePart2(false),
		m_mutePart3(false),
		m_mutePart4(false),
		m_mutePart5(false),
		m_mutePart6(false),
		m_mutePart7(false),
		m_mutePartR(false),
		m_muteMuteCtrl(false),
		m_muteBD(false),
		m_muteSD(false),
		m_muteHH(false),
		m_muteCLP(false),
		m_muteCYM(false),
		m_muteTOMPERC(false),
		m_muteHIT(false),
		m_muteOTHERS(false)
	{
	}

	~GrooveboxPatternSetup(){}

	// don't use this to add new entrys if you want them also parsed. instead use addAndParseSyxMessage
	(OwnedArray<SyxMsg, CriticalSection>)& getSetupSysExMessages() { return m_setupSysExMessages; }

	void addAndParseSyxMessage(SyxMsg* entry) 
	{
		m_setupSysExMessages.add(entry); 
		uint8* dataPtr;
		uint32 dataLength;
		entry->getSysExDataArrayPtr(&dataPtr, dataLength);
		// parse first setup line
		if (entry->get32BitAddress() == 0x30000000)
		{
			m_patternName = (dataLength >= 0xF) ? String((const char*)dataPtr, 15) : "";
			m_beatNumerator = (dataLength >= 0x11) ? dataPtr[0x10] : 0;
			m_beatDenominator = (dataLength >= 0x12) ? dataPtr[0x11] : 1;
			m_numMeasures = (dataLength >= 0x13) ? dataPtr[0x12] : 0;
			m_bpm = (dataLength >= 0x17) ? (dataPtr[0x13] * 0x1000 +
					dataPtr[0x14] * 0x100 +
					dataPtr[0x15] * 0x10 +
					dataPtr[0x16]) / 100.0f : 1.0f;
			// mute bits
			if (dataLength > 0x30)
			{
				m_mutePart1 = (dataPtr[0x20] & 1) != 0;
				m_mutePart2 = (dataPtr[0x20] & 2) != 0;
				m_mutePart3 = (dataPtr[0x20] & 4) != 0;
				m_mutePart4 = (dataPtr[0x20] & 8) != 0;
				m_mutePart5 = (dataPtr[0x1F] & 1) != 0;
				m_mutePart6 = (dataPtr[0x1F] & 2) != 0;
				m_mutePart7 = (dataPtr[0x1F] & 4) != 0;
				m_mutePartR = (dataPtr[0x22] & 2) != 0;
				m_muteMuteCtrl = (dataPtr[0x21] & 4) != 0;
				m_muteBD = (dataPtr[0x30] & 1) != 0;
				m_muteSD = (dataPtr[0x30] & 2) != 0;
				m_muteHH = (dataPtr[0x30] & 4) != 0;
				m_muteCLP = (dataPtr[0x30] & 8) != 0;
				m_muteCYM = (dataPtr[0x2F] & 1) != 0;
				m_muteTOMPERC = (dataPtr[0x2F] & 2) != 0;
				m_muteHIT = (dataPtr[0x2F] & 4) != 0;
				m_muteOTHERS = (dataPtr[0x2F] & 8) != 0;
			}
			// SeqOut(0=INT,1=EXT,2=BOTH)
			// P1 P2 P3 P4 P5 P6 P7 PR
			// 38 3A 3C 3E 40 42 44 4A
			
		}
		// parse M-FX, Reverb and Delay Setup
		else if (entry->get32BitAddress() == 0x30002000)
		{
			// M-FX setup
			if (dataLength > 0x0E)
			{
				m_M_FX_Setup.type = dataPtr[0x02];
				for (int i = 0; i < 12; i++) 
					m_M_FX_Setup.param[i] = dataPtr[0x03 + i];
				m_M_FX_Setup.toDelaySendLevel = dataPtr[0x11];
				m_M_FX_Setup.toReverbSendLevel = dataPtr[0x12];
			}
			// reverb setup
			if (dataLength > 0x1B)
			{
				m_ReverbSetup.reverbType = dataPtr[0x18];
				m_ReverbSetup.reverbLevel = dataPtr[0x19];
				m_ReverbSetup.reverbTime = dataPtr[0x1A];
				m_ReverbSetup.reverbHFDamp = dataPtr[0x1B];
			}
			// delay setup
			if (dataLength > 0x22)
			{
				m_DelaySetup.delayLevel = dataPtr[0x1D];
				m_DelaySetup.delayType = dataPtr[0x1E];
				m_DelaySetup.delayTime = dataPtr[0x1F];
				m_DelaySetup.delayHFDamp = dataPtr[0x20];
				m_DelaySetup.delayFbLevel = dataPtr[0x21];
				m_DelaySetup.delayOutAssign = dataPtr[0x22];
			}
		}
		else if (entry->get32BitAddress() == 0x30004000 && dataLength > 0x08)
		{
			m_PartsSetup.partR.bankSelectMSB =	dataPtr[0x00];
			m_PartsSetup.partR.bankSelectLSB =	dataPtr[0x01];
			m_PartsSetup.partR.programNumber =	dataPtr[0x02];
			m_PartsSetup.partR.mixerLevel =		dataPtr[0x03];
			m_PartsSetup.partR.mixerPan =		dataPtr[0x04];
			m_PartsSetup.partR.mixerKeyShift =	dataPtr[0x05];
			m_PartsSetup.partR.mixerRevLevel =	dataPtr[0x06];
			m_PartsSetup.partR.mixerDlyLevel =	dataPtr[0x07];
			m_PartsSetup.partR.mixerMFxSwitch =	dataPtr[0x08];
		}
		else if (entry->get32BitAddress() == 0x30004100)
		{
			m_PartsSetup.part1.bankSelectMSB = dataPtr[0x00];
			m_PartsSetup.part1.bankSelectLSB = dataPtr[0x01];
			m_PartsSetup.part1.programNumber = dataPtr[0x02];
			m_PartsSetup.part1.mixerLevel = dataPtr[0x03];
			m_PartsSetup.part1.mixerPan = dataPtr[0x04];
			m_PartsSetup.part1.mixerKeyShift = dataPtr[0x05];
			m_PartsSetup.part1.mixerRevLevel = dataPtr[0x06];
			m_PartsSetup.part1.mixerDlyLevel = dataPtr[0x07];
			m_PartsSetup.part1.mixerMFxSwitch = dataPtr[0x08];
		}
		else if (entry->get32BitAddress() == 0x30004200)
		{
			m_PartsSetup.part2.bankSelectMSB = dataPtr[0x00];
			m_PartsSetup.part2.bankSelectLSB = dataPtr[0x01];
			m_PartsSetup.part2.programNumber = dataPtr[0x02];
			m_PartsSetup.part2.mixerLevel = dataPtr[0x03];
			m_PartsSetup.part2.mixerPan = dataPtr[0x04];
			m_PartsSetup.part2.mixerKeyShift = dataPtr[0x05];
			m_PartsSetup.part2.mixerRevLevel = dataPtr[0x06];
			m_PartsSetup.part2.mixerDlyLevel = dataPtr[0x07];
			m_PartsSetup.part2.mixerMFxSwitch = dataPtr[0x08];
		}
		else if (entry->get32BitAddress() == 0x30004300)
		{
			m_PartsSetup.part3.bankSelectMSB = dataPtr[0x00];
			m_PartsSetup.part3.bankSelectLSB = dataPtr[0x01];
			m_PartsSetup.part3.programNumber = dataPtr[0x02];
			m_PartsSetup.part3.mixerLevel = dataPtr[0x03];
			m_PartsSetup.part3.mixerPan = dataPtr[0x04];
			m_PartsSetup.part3.mixerKeyShift = dataPtr[0x05];
			m_PartsSetup.part3.mixerRevLevel = dataPtr[0x06];
			m_PartsSetup.part3.mixerDlyLevel = dataPtr[0x07];
			m_PartsSetup.part3.mixerMFxSwitch = dataPtr[0x08];
		}
		else if (entry->get32BitAddress() == 0x30004400)
		{
			m_PartsSetup.part4.bankSelectMSB = dataPtr[0x00];
			m_PartsSetup.part4.bankSelectLSB = dataPtr[0x01];
			m_PartsSetup.part4.programNumber = dataPtr[0x02];
			m_PartsSetup.part4.mixerLevel = dataPtr[0x03];
			m_PartsSetup.part4.mixerPan = dataPtr[0x04];
			m_PartsSetup.part4.mixerKeyShift = dataPtr[0x05];
			m_PartsSetup.part4.mixerRevLevel = dataPtr[0x06];
			m_PartsSetup.part4.mixerDlyLevel = dataPtr[0x07];
			m_PartsSetup.part4.mixerMFxSwitch = dataPtr[0x08];
		}
		else if (entry->get32BitAddress() == 0x30004500)
		{
			m_PartsSetup.part5.bankSelectMSB = dataPtr[0x00];
			m_PartsSetup.part5.bankSelectLSB = dataPtr[0x01];
			m_PartsSetup.part5.programNumber = dataPtr[0x02];
			m_PartsSetup.part5.mixerLevel = dataPtr[0x03];
			m_PartsSetup.part5.mixerPan = dataPtr[0x04];
			m_PartsSetup.part5.mixerKeyShift = dataPtr[0x05];
			m_PartsSetup.part5.mixerRevLevel = dataPtr[0x06];
			m_PartsSetup.part5.mixerDlyLevel = dataPtr[0x07];
			m_PartsSetup.part5.mixerMFxSwitch = dataPtr[0x08];
		}
		else if (entry->get32BitAddress() == 0x30004600)
		{
			m_PartsSetup.part6.bankSelectMSB = dataPtr[0x00];
			m_PartsSetup.part6.bankSelectLSB = dataPtr[0x01];
			m_PartsSetup.part6.programNumber = dataPtr[0x02];
			m_PartsSetup.part6.mixerLevel = dataPtr[0x03];
			m_PartsSetup.part6.mixerPan = dataPtr[0x04];
			m_PartsSetup.part6.mixerKeyShift = dataPtr[0x05];
			m_PartsSetup.part6.mixerRevLevel = dataPtr[0x06];
			m_PartsSetup.part6.mixerDlyLevel = dataPtr[0x07];
			m_PartsSetup.part6.mixerMFxSwitch = dataPtr[0x08];
		}
		else if (entry->get32BitAddress() == 0x30004700)
		{
			m_PartsSetup.part7.bankSelectMSB = dataPtr[0x00];
			m_PartsSetup.part7.bankSelectLSB = dataPtr[0x01];
			m_PartsSetup.part7.programNumber = dataPtr[0x02];
			m_PartsSetup.part7.mixerLevel = dataPtr[0x03];
			m_PartsSetup.part7.mixerPan = dataPtr[0x04];
			m_PartsSetup.part7.mixerKeyShift = dataPtr[0x05];
			m_PartsSetup.part7.mixerRevLevel = dataPtr[0x06];
			m_PartsSetup.part7.mixerDlyLevel = dataPtr[0x07];
			m_PartsSetup.part7.mixerMFxSwitch = dataPtr[0x08];
		}
	}

	String getPatternName() { return m_patternName; }
	uint8 getBeatNumerator() { return m_beatNumerator; }
	uint8 getBeatDenominator() { return m_beatDenominator; }
	uint8 getNumMeasures() { return m_numMeasures; }
	float getBPM() { return m_bpm; }

	String getPart1PatchName() { return m_part1PatchName.retainCharacters("!\"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[包^_`abcdefghijklmnopqrstuvwxyz{|}"); }
	String getPart2PatchName() { return m_part2PatchName.retainCharacters("!\"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[包^_`abcdefghijklmnopqrstuvwxyz{|}"); }
	String getPart3PatchName() { return m_part3PatchName.retainCharacters("!\"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[包^_`abcdefghijklmnopqrstuvwxyz{|}"); }
	String getPart4PatchName() { return m_part4PatchName.retainCharacters("!\"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[包^_`abcdefghijklmnopqrstuvwxyz{|}"); }
	String getPart5PatchName() { return m_part5PatchName.retainCharacters("!\"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[包^_`abcdefghijklmnopqrstuvwxyz{|}"); }
	String getPart6PatchName() { return m_part6PatchName.retainCharacters("!\"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[包^_`abcdefghijklmnopqrstuvwxyz{|}"); }
	String getPart7PatchName() { return m_part7PatchName.retainCharacters("!\"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[包^_`abcdefghijklmnopqrstuvwxyz{|}"); }
	String getPartRRhythmnSetName() { return m_partRRhythmnSetName.retainCharacters("!\"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[包^_`abcdefghijklmnopqrstuvwxyz{|}"); }
	String getPartPatchName(PartSelector part) 
	{
		switch (part)
		{
		case GrooveboxPatternSetup::Setup_Part_1: return getPart1PatchName();
		case GrooveboxPatternSetup::Setup_Part_2: return getPart2PatchName();
		case GrooveboxPatternSetup::Setup_Part_3: return getPart3PatchName();
		case GrooveboxPatternSetup::Setup_Part_4: return getPart4PatchName();
		case GrooveboxPatternSetup::Setup_Part_5: return getPart5PatchName();
		case GrooveboxPatternSetup::Setup_Part_6: return getPart6PatchName();
		case GrooveboxPatternSetup::Setup_Part_7: return getPart7PatchName();
		case GrooveboxPatternSetup::Setup_Part_R: return getPartRRhythmnSetName();
		default: return String::empty;
		}
	}
	void setPart1PatchName(String name) { m_part1PatchName = name; }
	void setPart2PatchName(String name) { m_part2PatchName = name; }
	void setPart3PatchName(String name) { m_part3PatchName = name; }
	void setPart4PatchName(String name) { m_part4PatchName = name; }
	void setPart5PatchName(String name) { m_part5PatchName = name; }
	void setPart6PatchName(String name) { m_part6PatchName = name; }
	void setPart7PatchName(String name) { m_part7PatchName = name; }
	void setPartRRhythmnSetName(String name) { m_partRRhythmnSetName = name; }

	// returns mute setup for part
	bool isPartMuted(PartSelector part)
	{
		switch (part)
		{
			case Setup_Part_1: return m_mutePart1;
			case Setup_Part_2: return m_mutePart2;
			case Setup_Part_3: return m_mutePart3;
			case Setup_Part_4: return m_mutePart4;
			case Setup_Part_5: return m_mutePart5;
			case Setup_Part_6: return m_mutePart6;
			case Setup_Part_7: return m_mutePart7;
			case Setup_Part_R: return m_mutePartR;
			case Setup_MuteCtrl: return m_muteMuteCtrl;
			default: return false;
		}
	}

	MidiMessage getPartMuteSysEx(PartSelector part)
	{
		uint8 quickSysExAddress[2]{0x70, 0x01};
		uint8 quickSysExData[2]{(uint8)part, isPartMuted(part) ? 1 : 0};	// DataL: 0-6,9; DataE: none(0), mute(1)
		ScopedPointer<SyxMsg> msg (new SyxMsg(SyxMsg::Type_DT1_Quick, m_deviceId, quickSysExAddress, quickSysExData, 2, SyxMsg::calcDt1Checksum(quickSysExAddress, 2, quickSysExData, 2)));
		return msg->toMidiMessage();
	}

	// returns mute setup for rhythm group
	bool isRhythmGroupMuted(RhythmGroupSelector group)
	{
		switch (group)
		{
			case GrooveboxPatternSetup::Setup_RhyGrp_BD:		return m_muteBD;
			case GrooveboxPatternSetup::Setup_RhyGrp_SD:		return m_muteSD;
			case GrooveboxPatternSetup::Setup_RhyGrp_HH:		return m_muteHH;
			case GrooveboxPatternSetup::Setup_RhyGrp_CLP:		return m_muteCLP;
			case GrooveboxPatternSetup::Setup_RhyGrp_CYM:		return m_muteCYM;
			case GrooveboxPatternSetup::Setup_RhyGrp_TOMPERC:	return m_muteTOMPERC;
			case GrooveboxPatternSetup::Setup_RhyGrp_HIT:		return m_muteHIT;
			case GrooveboxPatternSetup::Setup_RhyGrp_OTHERS:	return m_muteOTHERS;
			default: return false;
		}
	}

	MidiMessage getRhythmGroupMuteSysEx(RhythmGroupSelector group)
	{
		uint8 quickSysExAddress[2]{0x70, 0x02};
		uint8 quickSysExData[2]{(uint8)group, isRhythmGroupMuted(group) ? 1 : 0};	// DataL: 0-7; DataE: none(0), mute(1)
		ScopedPointer<SyxMsg> msg(new SyxMsg(SyxMsg::Type_DT1_Quick, m_deviceId, quickSysExAddress, quickSysExData, 2, SyxMsg::calcDt1Checksum(quickSysExAddress, 2, quickSysExData, 2)));
		return msg->toMidiMessage();
	}

	M_FX_Setup getM_FX_Setup() { return m_M_FX_Setup; }
	ReverbSetup getReverbSetup(){ return m_ReverbSetup; }
	DelaySetup getDelaySetup(){ return m_DelaySetup; }
	PartsSetup getPartsSetup(){ return m_PartsSetup; }

	MidiMessageSequence getSinglePartSetupMidiMessageSequence(PartSelector part)
	{
		SinglePartSetup* singlePartSetup;
		switch (part)
		{
		case GrooveboxPatternSetup::Setup_Part_1: 
			singlePartSetup = &m_PartsSetup.part1;
			break;
		case GrooveboxPatternSetup::Setup_Part_2:
			singlePartSetup = &m_PartsSetup.part2;
			break;
		case GrooveboxPatternSetup::Setup_Part_3:
			singlePartSetup = &m_PartsSetup.part3;
			break;
		case GrooveboxPatternSetup::Setup_Part_4:
			singlePartSetup = &m_PartsSetup.part4;
			break;
		case GrooveboxPatternSetup::Setup_Part_5:
			singlePartSetup = &m_PartsSetup.part5;
			break;
		case GrooveboxPatternSetup::Setup_Part_6:
			singlePartSetup = &m_PartsSetup.part6;
			break;
		case GrooveboxPatternSetup::Setup_Part_7:
			singlePartSetup = &m_PartsSetup.part7;
			break;
		case GrooveboxPatternSetup::Setup_Part_R:
			singlePartSetup = &m_PartsSetup.partR;
			break;
		default:
			return MidiMessageSequence();
		}
		MidiMessageSequence messages;
		// patch selection cascade (meta text, bank selection MSB, bank selection LSB, program change:
		messages.addEvent(SyxMsg::createChannelPrefixMetaEvent((uint8)singlePartSetup->part));
		messages.addEvent(SyxMsg::createTextMetaEvent(SyxMsg::ProgramName, getPartName(part) + ": " + getBankName(part, singlePartSetup->bankSelectMSB, singlePartSetup->bankSelectLSB) + ", Program " + String(singlePartSetup->programNumber + 1).paddedLeft('0', 3)), 1.0);
		messages.addEvent(MidiMessage::controllerEvent(singlePartSetup->channel, 0, singlePartSetup->bankSelectMSB), 2.0);
		messages.addEvent(MidiMessage::controllerEvent(singlePartSetup->channel, 32, singlePartSetup->bankSelectLSB), 3.0);
		messages.addEvent(MidiMessage::programChange(singlePartSetup->channel, singlePartSetup->programNumber), 4.0);
		// mixer setup by controllers:
		messages.addEvent(SyxMsg::createTextMetaEvent(SyxMsg::TextEvent, "Mixer Level"), 5.0);
		messages.addEvent(MidiMessage::controllerEvent(singlePartSetup->channel, 7, singlePartSetup->mixerLevel), 5.0);
		messages.addEvent(SyxMsg::createTextMetaEvent(SyxMsg::TextEvent, "Mixer Pan"), 5.0);
		messages.addEvent(MidiMessage::controllerEvent(singlePartSetup->channel, 10, singlePartSetup->mixerPan), 5.0);
		messages.addEvent(SyxMsg::createTextMetaEvent(SyxMsg::TextEvent, "Mixer Key Shift"), 5.0);
		messages.addEvent(MidiMessage::controllerEvent(singlePartSetup->channel, 85, singlePartSetup->mixerKeyShift), 5.0);
		messages.addEvent(SyxMsg::createTextMetaEvent(SyxMsg::TextEvent, "Mixer Reverb"), 5.0);
		messages.addEvent(MidiMessage::controllerEvent(singlePartSetup->channel, 91, singlePartSetup->mixerRevLevel),5.0);
		messages.addEvent(SyxMsg::createTextMetaEvent(SyxMsg::TextEvent, "Mixer Delay"), 5.0);
		messages.addEvent(MidiMessage::controllerEvent(singlePartSetup->channel, 94, singlePartSetup->mixerDlyLevel), 5.0);
		messages.addEvent(SyxMsg::createTextMetaEvent(SyxMsg::TextEvent, "Mixer M-FX Switch"), 5.0);
		messages.addEvent(MidiMessage::controllerEvent(singlePartSetup->channel, 86, singlePartSetup->mixerMFxSwitch),5.0);
		// mute initial state for part
		String partName(String::empty); if ((int)part >= 0 && part < 7) partName = String(part + 1); else if ((int)part == 9) partName = "R";
		messages.addEvent(SyxMsg::createTextMetaEvent(SyxMsg::TextEvent, "Initial mute state of Part " + partName + " : " + (isPartMuted(part) ? "muted" : "not muted")),7.0);
		messages.addEvent(getPartMuteSysEx(part),7.0);
		// mute initial state for rhythm groups
		if (part == GrooveboxPatternSetup::Setup_Part_R) for (int i = 0x00; i < 0x08; i++)
		{
			RhythmGroupSelector rhyGrp = (RhythmGroupSelector)i;
			String rhyGrpName(getRhythmGroupName(rhyGrp));
			messages.addEvent(SyxMsg::createTextMetaEvent(SyxMsg::TextEvent, "Initial mute state of Rhythm Group " + rhyGrpName + " : " + (isRhythmGroupMuted(rhyGrp) ? "muted" : "not muted")),7.0);
			messages.addEvent(getRhythmGroupMuteSysEx((RhythmGroupSelector)i),7.0);
		}
		return messages;
	}

	MidiMessageSequence getAllPartsSetupMidiMessageSequence()
	{
		MidiMessageSequence messages;
		messages.addSequence(getSinglePartSetupMidiMessageSequence(PartSelector::Setup_Part_R), 0.0, 0.0, getSinglePartSetupMidiMessageSequence(PartSelector::Setup_Part_R).getEndTime() + 96.0);
		messages.addSequence(getSinglePartSetupMidiMessageSequence(PartSelector::Setup_Part_1), 12.0, 0.0, getSinglePartSetupMidiMessageSequence(PartSelector::Setup_Part_1).getEndTime() + 12.0 + 96.0);
		messages.addSequence(getSinglePartSetupMidiMessageSequence(PartSelector::Setup_Part_2), 24.0, 0.0, getSinglePartSetupMidiMessageSequence(PartSelector::Setup_Part_2).getEndTime() + 24.0 + 96.0);
		messages.addSequence(getSinglePartSetupMidiMessageSequence(PartSelector::Setup_Part_3), 36.0, 0.0, getSinglePartSetupMidiMessageSequence(PartSelector::Setup_Part_3).getEndTime() + 36.0 + 96.0);
		messages.addSequence(getSinglePartSetupMidiMessageSequence(PartSelector::Setup_Part_4), 48.0, 0.0, getSinglePartSetupMidiMessageSequence(PartSelector::Setup_Part_4).getEndTime() + 48.0 + 96.0);
		messages.addSequence(getSinglePartSetupMidiMessageSequence(PartSelector::Setup_Part_5), 60.0, 0.0, getSinglePartSetupMidiMessageSequence(PartSelector::Setup_Part_5).getEndTime() + 60.0 + 96.0);
		messages.addSequence(getSinglePartSetupMidiMessageSequence(PartSelector::Setup_Part_6), 72.0, 0.0, getSinglePartSetupMidiMessageSequence(PartSelector::Setup_Part_6).getEndTime() + 72.0 + 96.0);
		messages.addSequence(getSinglePartSetupMidiMessageSequence(PartSelector::Setup_Part_7), 84.0, 0.0, getSinglePartSetupMidiMessageSequence(PartSelector::Setup_Part_7).getEndTime() + 84.0 + 96.0);
		return messages;
	}

	MidiMessageSequence getM_FX_SetupMidiMessageSequence()
	{
		MidiMessageSequence result;
		// addr 01 00 00 0D,	size 13 (type + 12 params)
		uint8* dt1_address = new uint8[4]{0x01, 0x00, 0x00, 0x0D};
		uint8* dt1_data = new uint8[13]{m_M_FX_Setup.type, m_M_FX_Setup.param[0], m_M_FX_Setup.param[1], m_M_FX_Setup.param[2], m_M_FX_Setup.param[3], m_M_FX_Setup.param[4], m_M_FX_Setup.param[5], m_M_FX_Setup.param[6], m_M_FX_Setup.param[7], m_M_FX_Setup.param[8], m_M_FX_Setup.param[9], m_M_FX_Setup.param[10], m_M_FX_Setup.param[11]};
		ScopedPointer<SyxMsg> mFXTypeAndParamsSysex = new SyxMsg(SyxMsg::MessageType::Type_DT1, m_deviceId, dt1_address, dt1_data, 13, SyxMsg::calcDt1Checksum(dt1_address, 4, dt1_data, 13));
		result.addEvent(SyxMsg::createTextMetaEvent(SyxMsg::TextEvent, "Setup M-FX Type and 12 Parameters (" + m_M_FX_Setup.getTypeName() + ")"));
		result.addEvent(mFXTypeAndParamsSysex->toMidiMessage());
		delete[] dt1_address;
		delete[] dt1_data;
		return result;
	}
	
	MidiMessageSequence getReverbSetupMidiMessageSequence()
	{	
		MidiMessageSequence result;
		// addr 01 00 00 28,	size 04
		uint8* dt1_address = new uint8[4]{0x01, 0x00, 0x00, 0x28};
		uint8* dt1_data = new uint8[4]{m_ReverbSetup.reverbType, m_ReverbSetup.reverbLevel, m_ReverbSetup.reverbTime, m_ReverbSetup.reverbHFDamp};
		ScopedPointer<SyxMsg> reverbParamsSysex = new SyxMsg(SyxMsg::MessageType::Type_DT1, m_deviceId, dt1_address, dt1_data, 4, SyxMsg::calcDt1Checksum(dt1_address, 4, dt1_data, 4));
		result.addEvent(SyxMsg::createTextMetaEvent(SyxMsg::TextEvent, "Setup Reverb Parameters (Type, Level, Time, HF Damp)"));
		result.addEvent(reverbParamsSysex->toMidiMessage());
		delete[] dt1_address;
		delete[] dt1_data;

		dt1_address = new uint8[4]{0x01, 0x00, 0x00, 0x1D};
		dt1_data = new uint8[1]{m_M_FX_Setup.toReverbSendLevel};
		ScopedPointer<SyxMsg> mFXSendReverbLevelSysex = new SyxMsg(SyxMsg::MessageType::Type_DT1, m_deviceId, dt1_address, dt1_data, 1, SyxMsg::calcDt1Checksum(dt1_address, 4, dt1_data, 1));
		result.addEvent(SyxMsg::createTextMetaEvent(SyxMsg::TextEvent, "M-FX to Reverb Send Level"));
		result.addEvent(mFXSendReverbLevelSysex->toMidiMessage());
		delete[] dt1_address;
		delete[] dt1_data;

		return result;
	}

	MidiMessageSequence getDelaySetupMidiMessageSequence()
	{
		MidiMessageSequence result;
		// addr 01 00 00 22,	size 06
		uint8* dt1_address = new uint8[4]{0x01, 0x00, 0x00, 0x22};
		uint8* dt1_data = new uint8[6]{m_DelaySetup.delayLevel, m_DelaySetup.delayType, m_DelaySetup.delayHFDamp, m_DelaySetup.delayTime, m_DelaySetup.delayFbLevel, m_DelaySetup.delayOutAssign};
		ScopedPointer<SyxMsg> delayParamsSysex = new SyxMsg(SyxMsg::MessageType::Type_DT1, m_deviceId, dt1_address, dt1_data, 6, SyxMsg::calcDt1Checksum(dt1_address, 4, dt1_data, 6));
		result.addEvent(SyxMsg::createTextMetaEvent(SyxMsg::TextEvent, "Setup Delay Parameters (Level, Type, HF Damp, Time, Feedback, Output Assign)"));
		result.addEvent(delayParamsSysex->toMidiMessage());
		delete[] dt1_address;
		delete[] dt1_data;

		dt1_address = new uint8[4]{0x01, 0x00, 0x00, 0x1C};
		dt1_data = new uint8[1]{m_M_FX_Setup.toDelaySendLevel};
		ScopedPointer<SyxMsg> mFXSendDelayLevelSysex = new SyxMsg(SyxMsg::MessageType::Type_DT1, m_deviceId, dt1_address, dt1_data, 1, SyxMsg::calcDt1Checksum(dt1_address, 4, dt1_data, 1));
		result.addEvent(SyxMsg::createTextMetaEvent(SyxMsg::TextEvent, "M-FX to Delay Send Level"));
		result.addEvent(mFXSendDelayLevelSysex->toMidiMessage());
		delete[] dt1_address;
		delete[] dt1_data;

		return result;
	}

	static String getPartName(PartSelector part)
	{
		switch (part)
		{
		case GrooveboxPatternSetup::Setup_Part_1:	return "PART_1";
		case GrooveboxPatternSetup::Setup_Part_2:	return "PART_2";
		case GrooveboxPatternSetup::Setup_Part_3:	return "PART_3";
		case GrooveboxPatternSetup::Setup_Part_4:	return "PART_4";
		case GrooveboxPatternSetup::Setup_Part_5:	return "PART_5";
		case GrooveboxPatternSetup::Setup_Part_6:	return "PART_6";
		case GrooveboxPatternSetup::Setup_Part_7:	return "PART_7";
		case GrooveboxPatternSetup::Setup_Part_R:	return "PART_R";
		case GrooveboxPatternSetup::Setup_MuteCtrl:	return "MUTE-CTRL";
		default: return String::empty;
		}
	}

	static String getRhythmGroupName(RhythmGroupSelector group)
	{
		switch (group)
		{
		case GrooveboxPatternSetup::Setup_RhyGrp_BD:		return "BD";
		case GrooveboxPatternSetup::Setup_RhyGrp_SD:		return "SD";
		case GrooveboxPatternSetup::Setup_RhyGrp_HH:		return "HH";
		case GrooveboxPatternSetup::Setup_RhyGrp_CLP:		return "CLP";
		case GrooveboxPatternSetup::Setup_RhyGrp_CYM:		return "CYM";
		case GrooveboxPatternSetup::Setup_RhyGrp_TOMPERC:	return "TOM/PERC";
		case GrooveboxPatternSetup::Setup_RhyGrp_HIT:		return "HIT";
		case GrooveboxPatternSetup::Setup_RhyGrp_OTHERS:	return "OTHERS";
		default: return String::empty;
		}
	}

	float getMeasureLengthInQarters()
	{
		return ((float)getBeatNumerator() / (float)getBeatDenominator()) * 4.0f;
	}

	int getMeasureLengthInTicks()
	{
		return (int)(getMeasureLengthInQarters() * 96);
	}

private:
	OwnedArray<SyxMsg, CriticalSection> m_setupSysExMessages;
	uint8 m_deviceId;
	String m_patternName;
	uint8 m_beatNumerator;
	uint8 m_beatDenominator;
	uint8 m_numMeasures;
	float m_bpm;

	String m_part1PatchName;
	String m_part2PatchName;
	String m_part3PatchName;
	String m_part4PatchName;
	String m_part5PatchName;
	String m_part6PatchName;
	String m_part7PatchName;
	String m_partRRhythmnSetName;

	bool m_mutePart1;
	bool m_mutePart2;
	bool m_mutePart3;
	bool m_mutePart4;
	bool m_mutePart5;
	bool m_mutePart6;
	bool m_mutePart7;
	bool m_mutePartR;
	bool m_muteMuteCtrl;
	bool m_muteBD;
	bool m_muteSD;
	bool m_muteHH;
	bool m_muteCLP;
	bool m_muteCYM;
	bool m_muteTOMPERC;
	bool m_muteHIT;
	bool m_muteOTHERS;

	M_FX_Setup m_M_FX_Setup;
	ReverbSetup m_ReverbSetup;
	DelaySetup m_DelaySetup;
	PartsSetup m_PartsSetup;

	String getBankName(PartSelector part, uint8 bankSelMSB00, uint8 bankSelLSB32)
	{
		if (part == 9)
		{
			if (bankSelMSB00 == 81 && bankSelLSB32 == 0)
			{
				return "Preset Rhyhthm Set Bank A";
			}
			else if (bankSelMSB00 == 83 && bankSelLSB32 == 0)
			{
				return "Preset Rhyhthm Set Bank B";
			}
			else if (bankSelMSB00 == 85 && bankSelLSB32 == 0)
			{
				return "User Rhyhthm Set Bank ";
			}
		}
		else
		{
			if (bankSelMSB00 == 81)
			{
				if (bankSelLSB32 == 0) return "Preset Patch Bank A";
				else if (bankSelLSB32 == 1) return "Preset Patch Bank B";
				else if (bankSelLSB32 == 2) return "Preset Patch Bank C";
				else if (bankSelLSB32 == 3) return "Preset Patch Bank D";
			}
			else if (bankSelMSB00 == 83)
			{
				if (bankSelLSB32 == 0) return "Preset Patch Bank E";
				else if (bankSelLSB32 == 1) return "PresetPatch Bank F";
				else if (bankSelLSB32 == 2) return "Preset Patch Bank G";
			}
			else if (bankSelMSB00 == 85)
			{
				if (bankSelLSB32 == 0) return "User Patch Bank A";
				else if (bankSelLSB32 == 1) return "User Patch Bank B";
			}
		}
		return "Unknown Patch Bank";
	}

	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(GrooveboxPatternSetup)
};



#endif  // GROOVEBOXPATTERNSETUP_H_INCLUDED
