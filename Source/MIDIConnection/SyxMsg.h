/*
  ==============================================================================

    SyxMsg.h
    Created: 8 Dec 2013 8:09:32pm
    Author:  Martin

  ==============================================================================
*/

#ifndef SYXMSG_H_INCLUDED
#define SYXMSG_H_INCLUDED

#include "JuceHeader.h"

class SyxMsg
{
public:
	enum MessageType
	{
		Type_RQ1,
		Type_DT1,
		Type_DT1_GS,
		Type_DT1_Quick,
		Type_Universal_Realtime,
		Type_Inquiry_Request,
		Type_Inquiry_Reply,
		Type_Unknown
	};

	// copy constructor
	SyxMsg(const SyxMsg& otherToCopy);

	// parse const uint8* sysExData (F0..F7, length n) to SyxMsg
	SyxMsg(const uint8* rawData, uint32 rawDataSize, bool includingF0andF7 = false);

	// takes possesion of the input arrays (deletes their memory when message object is destructed)
	// address must be of length
	SyxMsg(MessageType type, uint8 deviceId = 0x00, const uint8 * address = nullptr, const uint8* sizeOrData = nullptr, uint32 sizeOrDataLength = 0, uint8 checkSum = 0x00);

	SyxMsg(const MidiMessage& msg);

	~SyxMsg();

	MidiMessage getAsMidiMessage();

	/*
	m_dataArray = &m_completeSysEx[5];
	/*  // might be something like
	m_completeSysEx[5],											// ID number (Roland = 41H)
	m_completeSysEx[6], m_completeSysEx[7],								// Device family code (0BH 01H)
	m_completeSysEx[8], m_completeSysEx[9],								// Device family number code (01H 00H)
	m_completeSysEx[10], m_completeSysEx[11], m_completeSysEx[12], m_completeSysEx[13],	// Software revision level (00H 03H 00H 00H)
	*/

	uint8 getInquiryReplyDevId();
	uint8 getInquiryReplyManId();
	uint16 getInquiryReplyDevFamCode();
	uint16 getInquiryReplyDevFamNumberCode();
	uint32 getInquiryReplySoftwareRevision();

	static const uint8 SYSEX_STATUS					 = 0xF0;
	static const uint8 SYSEX_ROLAND_MANUFACTURER_ID	 = 0x41;
	static const uint8 SYSEX_INQUIRY_MANUFACTURER_ID = 0x7E;
	static const uint8 SYSEX_REPLY_MANUFACTURER_ID	 = 0x7F;
	static const uint16 SYSEX_ROLAND__MODEL_ID		 = 0x000B;
	static const uint8 SYSEX_GS_MODEL_ID			 = 0x42;
	static const uint8 SYSEX_ROLAND__QUICK_ID		 = 0x3A;
	static const uint8 SYSEX_ROLAND_COMMAND_RQ1		 = 0x11;
	static const uint8 SYSEX_ROLAND_COMMAND_DT1		 = 0x12;
	static const uint16 SYSEX_GROOVEBOX_FAMILY_CODE  = 0x0B01;
	static const uint8 SYSEX_EOX					 = 0xF7;

	// Creates a 16 byte long data array (icluding f0 and f7) for RQ1 request sysex message. Result is to be deleted by caller.
	static MidiMessage newSysExRq1Msg(uint8 deviceID, uint32 address, uint32 size);

	static uint8 calcRq1Checksum(uint8 add1, uint8 add2, uint8 add3, uint8 add4, uint8 size1, uint8 size2, uint8 size3, uint8 size4);
	static uint8 calcRq1Checksum(const uint8* addressBytes, const uint8* sizeBytes);
	static uint8 calcRq1Checksum(const uint8* addressAndData, int addressAndDataSize);
	static uint8 calcDt1Checksum(const uint8* addressBytes, uint8 addressSize, const uint8* dataBytes, uint32 dataSize);

	MessageType getType();
	String getTypeAsString();

	uint8 getDeviceId();
	
	uint32 get32BitAddress();

	uint32 getBlockStartAddress();

	uint16 getAddressOffset();

	bool isCheckSumOkay();
	void getAsSysExData(uint8** data, uint32 &dataLength) const;

	void getSysExDataArrayPtr(uint8** data, uint32 &dataLength);

	SyxMsg* copyToNew();

	String toString();

	MidiMessage toMidiMessage();

	static uint16 getUnsigned14BitValueFrom7BitBytes(uint8 lsbByte, uint8 msbByte);

	static int16 getSigned14BitValueFrom7BitBytes(uint8 lsbByte, uint8 msbByte);

	enum MidiTextMetaEventType
	{
		TextEvent = 0x01,
		CopyrightNotice = 0x02,
		TrackName = 0x03,
		InstrumentName = 0x04,
		Lyrics = 0x05,
		Marker = 0x06,
		CuePoint = 0x07,
		ProgramName = 0x08,
		DeviceName = 0x09
	};

	static MidiMessage createTextMetaEvent(MidiTextMetaEventType type, String text, double timeStamp = (0.0));

	// MIDI Channel Prefix FF 20 01 cc (cc: 00-0F)
	static MidiMessage createChannelPrefixMetaEvent(uint8 cc, double timeStamp = (0.0));

private:
	MessageType m_type;
	uint8 m_manufacturerId;	// see static consts (e.g. Roland is 0x41)
	uint16 m_modelId;		// MC-505 / MC-307 have 0x000B
	uint8 m_commandId;		// 11(RQ1) or 12 (DT1)
	uint8* m_addressArray;	// pointer to address array (within complete array)
	uint8 m_addressSize;	// (should be 0, 2 or 4)
	uint8* m_dataArray;		// pointer to data array (within complete array)
	uint32 m_dataSize;		// length if data array (0..n bytes, sholud not exceed 128 but by protocoll its possible)	
	uint8 m_deviceId;		// 0x10 by default (which i dez 16, meaning no. 17 starting from 1)
	uint8 m_checkSum;		// the checksum as set by the constructor
	bool m_checkSumOkay;	// indicates that a new checksum check failed against the set checksum
	uint8* m_completeSysEx; // the SysEx (including F0 and F7)
	uint32 m_completeLength;// the SysEx length (including F0 and F7)

	void initFromRawMidiSysEx(const uint8* rawData, const uint32 rawDataSize, bool includingF0andF7);

	JUCE_LEAK_DETECTOR(SyxMsg)
};



#endif  // SYXMSG_H_INCLUDED
