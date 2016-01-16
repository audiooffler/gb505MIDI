/*
  ==============================================================================

    SyxMsg.cpp
    Created: 16 Jan 2016 5:51:54pm
    Author:  Martin

  ==============================================================================
*/

#include "SyxMsg.h"

// copy constructor
SyxMsg::SyxMsg(const SyxMsg& otherToCopy) :
	m_type(Type_Unknown),
	m_manufacturerId(0),
	m_modelId(0),
	m_commandId(0),
	m_deviceId(0),
	m_addressSize(0),
	m_addressArray(nullptr),
	m_dataArray(nullptr),
	m_dataSize(0),
	m_checkSum(0),
	m_checkSumOkay(false),
	m_completeSysEx(nullptr)
{
	uint8* rawData;
	uint32 rawDataSize;
	bool includingF0andF7(true);
	otherToCopy.getAsSysExData(&rawData, rawDataSize);
	if (includingF0andF7 && (rawData[0] != SYSEX_STATUS || rawData[rawDataSize - 1] != SYSEX_EOX)) return;

	// copy
	m_completeLength = includingF0andF7 ? rawDataSize : rawDataSize + 2;
	m_completeSysEx = new uint8[m_completeLength];
	if (!includingF0andF7)
	{
		m_completeSysEx[0] = 0xF0;
		m_completeSysEx[m_completeLength - 1] = 0xF7;
	}
	for (uint32 i = 0; i < m_completeLength; i++) m_completeSysEx[i] = includingF0andF7 ? rawData[i] : rawData[i - 1];

	// parse RQ1
	if (m_completeLength == 16 &&
		m_completeSysEx[1] == SYSEX_ROLAND_MANUFACTURER_ID &&
		m_completeSysEx[3] == (uint8)(SYSEX_ROLAND__MODEL_ID >> 8) &&
		m_completeSysEx[4] == (uint8)(SYSEX_ROLAND__MODEL_ID & 0x00FF) &&
		m_completeSysEx[5] == SYSEX_ROLAND_COMMAND_RQ1)
	{
		m_type = Type_RQ1;
		m_manufacturerId = SYSEX_ROLAND_MANUFACTURER_ID;
		m_deviceId = m_completeSysEx[2];
		m_modelId = SYSEX_ROLAND__MODEL_ID;
		m_commandId = SYSEX_ROLAND_COMMAND_RQ1;
		m_addressSize = 4;
		m_addressArray = &m_completeSysEx[6];
		m_dataSize = 4;
		m_dataArray = &m_completeSysEx[10];
		m_checkSum = m_completeSysEx[m_completeLength - 2];
		m_checkSumOkay = (m_checkSum == calcRq1Checksum(m_addressArray, m_dataArray));
	}
	// parse DT1 for MC-307
	else if (
		m_completeSysEx[1] == SYSEX_ROLAND_MANUFACTURER_ID &&
		m_completeSysEx[3] == (uint8)(SYSEX_ROLAND__MODEL_ID >> 8) &&
		m_completeSysEx[4] == (uint8)(SYSEX_ROLAND__MODEL_ID & 0x00FF) &&
		m_completeSysEx[5] == SYSEX_ROLAND_COMMAND_DT1)
	{
		m_type = Type_DT1;
		m_manufacturerId = SYSEX_ROLAND_MANUFACTURER_ID;
		m_deviceId = m_completeSysEx[2];
		m_modelId = SYSEX_ROLAND__MODEL_ID;
		m_commandId = SYSEX_ROLAND_COMMAND_DT1;
		m_addressSize = 4;
		m_addressArray = &m_completeSysEx[6];
		m_dataSize = m_completeLength - 12;
		m_dataArray = &m_completeSysEx[10];
		m_checkSum = m_completeSysEx[m_completeLength - 2];
		m_checkSumOkay = (m_checkSum == calcDt1Checksum(m_addressArray, m_addressSize, m_dataArray, m_dataSize));
	}
	// parse DT1 for GS
	else if (
		m_completeSysEx[1] == SYSEX_ROLAND_MANUFACTURER_ID &&
		m_completeSysEx[3] == SYSEX_GS_MODEL_ID &&
		m_completeSysEx[4] == SYSEX_ROLAND_COMMAND_DT1)
	{
		m_type = Type_DT1_GS;
		m_manufacturerId = SYSEX_ROLAND_MANUFACTURER_ID;
		m_deviceId = m_completeSysEx[2];
		m_modelId = (uint16)SYSEX_GS_MODEL_ID;
		m_commandId = SYSEX_ROLAND_COMMAND_DT1;
		m_addressSize = 3;
		m_addressArray = &m_completeSysEx[5];
		m_dataSize = m_completeLength - 10;
		m_dataArray = &m_completeSysEx[8];
		m_checkSum = m_completeSysEx[m_completeLength - 2];
		m_checkSumOkay = (m_checkSum == calcDt1Checksum(m_addressArray, m_addressSize, m_dataArray, m_dataSize));
	}
	// parse DT1 for MC-307 Quick
	else if (
		m_completeLength == 11 &&
		m_completeSysEx[1] == SYSEX_ROLAND_MANUFACTURER_ID &&
		m_completeSysEx[3] == SYSEX_ROLAND__QUICK_ID &&
		m_completeSysEx[4] == SYSEX_ROLAND_COMMAND_DT1)
	{
		m_type = Type_DT1_Quick;
		m_manufacturerId = SYSEX_ROLAND_MANUFACTURER_ID;
		m_deviceId = m_completeSysEx[2];
		m_modelId = (uint16)SYSEX_ROLAND__QUICK_ID;
		m_commandId = SYSEX_ROLAND_COMMAND_DT1;
		m_addressSize = 2;
		m_addressArray = &m_completeSysEx[5];
		m_dataSize = 2;
		m_dataArray = &m_completeSysEx[7];
		m_checkSum = m_completeSysEx[m_completeLength - 2];
		m_checkSumOkay = (m_checkSum == calcDt1Checksum(m_addressArray, m_addressSize, m_dataArray, m_dataSize));
	}
	// parse Inquiry Request
	else if (
		m_completeLength == 6 &&
		m_completeSysEx[1] == 0x7E &&
		m_completeSysEx[3] == 0x06 &&
		m_completeSysEx[4] == 0x01)
	{
		m_type = Type_Inquiry_Request;
		m_manufacturerId = 0x7E;
		m_deviceId = m_completeSysEx[2];
		m_addressSize = 2;
		m_addressArray = &m_completeSysEx[3];
		m_checkSumOkay = true;
	}
	// parse Inquiry Reply
	else if (
		m_completeLength == 15 &&
		m_completeSysEx[1] == 0x7E &&
		m_completeSysEx[3] == 0x06 &&
		m_completeSysEx[4] == 0x02)
	{
		m_type = Type_Inquiry_Reply;
		m_manufacturerId = 0x7E;
		m_deviceId = m_completeSysEx[2];
		m_addressSize = 2;
		m_addressArray = &m_completeSysEx[3];
		m_dataSize = 9;
		m_dataArray = &m_completeSysEx[5];
		/*  // might be something like
		m_completeSysEx[5],											// ID number (Roland = 41H)
		m_completeSysEx[6], m_completeSysEx[7],								// Device family code (0BH 01H)
		m_completeSysEx[8], m_completeSysEx[9],								// Device family number code (01H 00H)
		m_completeSysEx[10], m_completeSysEx[11], m_completeSysEx[12], m_completeSysEx[13],	// Software revision level (00H 03H 00H 00H)
		*/
		m_checkSumOkay = true;
	}
	// parse Universal Realtime
	else if (
		m_completeSysEx[1] == 0x7F)
	{
		m_type = Type_Universal_Realtime;
		m_manufacturerId = 0x7F;
		m_dataSize = m_completeLength - 2;
		m_dataArray = &m_completeSysEx[1];
		m_checkSumOkay = true;
	}
}

// parse const uint8* sysExData (F0..F7, length n) to SyxMsg
SyxMsg::SyxMsg(const uint8* rawData, uint32 rawDataSize, bool includingF0andF7/* = false*/) :
	m_type(Type_Unknown),
	m_manufacturerId(0),
	m_modelId(0),
	m_commandId(0),
	m_deviceId(0),
	m_addressSize(0),
	m_addressArray(nullptr),
	m_dataArray(nullptr),
	m_dataSize(0),
	m_checkSum(0),
	m_checkSumOkay(false),
	m_completeSysEx(nullptr)
{
	initFromRawMidiSysEx(rawData, rawDataSize, includingF0andF7);
}

// takes possesion of the input arrays (deletes their memory when message object is destructed)
// address must be of length
SyxMsg::SyxMsg(MessageType type, uint8 deviceId/* = 0x00*/, const uint8 * address/* = nullptr*/, const uint8* sizeOrData/* = nullptr*/, uint32 sizeOrDataLength/* = 0*/, uint8 checkSum/* = 0x00*/) :
	m_type(type),
	m_manufacturerId(0),
	m_modelId(0),
	m_commandId(0),
	m_deviceId(deviceId),
	m_addressSize(0),
	m_dataSize(sizeOrDataLength),
	m_checkSum(checkSum),
	m_checkSumOkay(true),
	m_completeSysEx(nullptr)
{
	switch (type)
	{
	case Type_RQ1:
		m_manufacturerId = SYSEX_ROLAND_MANUFACTURER_ID;
		m_modelId = SYSEX_ROLAND__MODEL_ID;
		m_commandId = SYSEX_ROLAND_COMMAND_RQ1;
		m_addressSize = 4;
		m_dataSize = 4;
		m_checkSum = calcRq1Checksum(address, sizeOrData);
		//m_checkSumOkay = (m_checkSum == checkSum);	// makes no sense for rq1, it was created here
		m_completeLength = 16;
		m_completeSysEx = new uint8[16]
		{
			SYSEX_STATUS,
				m_manufacturerId,
				m_deviceId,
				(uint8)(m_modelId >> 8),
				(uint8)(m_modelId & 0x00FF),
				m_commandId,
				address[0],
				address[1],
				address[2],
				address[3],
				sizeOrData[0],
				sizeOrData[1],
				sizeOrData[2],
				sizeOrData[3],
				m_checkSum,
				SYSEX_EOX
		};
		m_addressArray = &m_completeSysEx[6];
		m_dataArray = &m_completeSysEx[10];
		break;
	case Type_DT1:
		m_manufacturerId = SYSEX_ROLAND_MANUFACTURER_ID;
		m_modelId = SYSEX_ROLAND__MODEL_ID;
		m_commandId = SYSEX_ROLAND_COMMAND_DT1;
		m_addressSize = 4;
		m_dataSize = sizeOrDataLength;
		m_checkSum = calcDt1Checksum(address, m_addressSize, sizeOrData, m_dataSize);
		m_checkSumOkay = (m_checkSum == checkSum);
		m_completeSysEx = new uint8[12 + m_dataSize]
		{
			SYSEX_STATUS,
				m_manufacturerId,
				m_deviceId,
				(uint8)(m_modelId >> 8),
				(uint8)(m_modelId & 0x00FF),
				m_commandId,
				address[0],
				address[1],
				address[2],
				address[3]/*,
						  data...
						  ...
						  m_checkSum,
						  SYSEX_EOX*/
		};
		for (uint32 i = 0; i < m_dataSize; i++) m_completeSysEx[i + 10] = sizeOrData[i];
		m_completeSysEx[10 + m_dataSize] = m_checkSum;
		m_completeSysEx[11 + m_dataSize] = SYSEX_EOX;
		m_completeLength = 12 + m_dataSize;
		m_addressArray = &m_completeSysEx[6];
		m_dataArray = &m_completeSysEx[10];
		break;
	case Type_DT1_GS:
		m_manufacturerId = SYSEX_ROLAND_MANUFACTURER_ID;
		m_modelId = SYSEX_GS_MODEL_ID;
		m_commandId = SYSEX_ROLAND_COMMAND_DT1;
		m_addressSize = 3;
		m_dataSize = sizeOrDataLength;
		m_checkSum = calcDt1Checksum(address, m_addressSize, sizeOrData, m_dataSize);
		m_checkSumOkay = (m_checkSum == checkSum);
		m_completeSysEx = new uint8[10 + m_dataSize]
		{
			SYSEX_STATUS,
				m_manufacturerId,
				m_deviceId,
				(uint8)(m_modelId & 0x00FF),
				m_commandId,
				address[0],
				address[1],
				address[2]/*,
						  data...
						  ...
						  m_checkSum,
						  SYSEX_EOX*/
		};
		for (uint32 i = 0; i < m_dataSize; i++) m_completeSysEx[i + 10] = sizeOrData[i];
		m_completeSysEx[8 + m_dataSize] = m_checkSum;
		m_completeSysEx[9 + m_dataSize] = SYSEX_EOX;
		m_completeLength = 10 + m_dataSize;
		m_addressArray = &m_completeSysEx[5];
		m_dataArray = &m_completeSysEx[8];
		break;
	case Type_DT1_Quick:
		m_manufacturerId = SYSEX_ROLAND_MANUFACTURER_ID;
		m_modelId = SYSEX_ROLAND__QUICK_ID;
		m_commandId = SYSEX_ROLAND_COMMAND_DT1;
		m_addressSize = 2;
		m_dataSize = 2;
		m_checkSum = calcDt1Checksum(address, m_addressSize, sizeOrData, m_dataSize);
		m_checkSumOkay = (m_checkSum == checkSum);
		m_completeSysEx = new uint8[11]
		{
			SYSEX_STATUS,
				m_manufacturerId,
				m_deviceId,
				(uint8)(m_modelId & 0x00FF),
				m_commandId,
				address[0],
				address[1],
				sizeOrData[0],
				sizeOrData[1],
				m_checkSum,
				SYSEX_EOX
		};
		m_completeLength = 11;
		m_addressArray = &m_completeSysEx[5];
		m_dataArray = &m_completeSysEx[7];
		break;
	case Type_Universal_Realtime:
		if (m_addressArray != nullptr) delete[] m_addressArray;
		m_addressSize = 0;
		m_addressArray = nullptr;
		m_dataSize = sizeOrDataLength;
		m_completeSysEx = new uint8[m_dataSize + 2]
		{
			SYSEX_STATUS,
				0x7F,	// Manufacturer ID for Universal Realtime Messages
		};
		for (uint32 i = 0; i < m_dataSize; i++)
		{
			m_completeSysEx[i + 1] = m_dataArray[i];
		}
		m_completeSysEx[m_dataSize + 1] = SYSEX_EOX;
		m_completeLength = m_dataSize + 2;
		m_dataArray = &m_completeSysEx[1];
		break;
	case Type_Inquiry_Request:
		m_manufacturerId = SYSEX_INQUIRY_MANUFACTURER_ID;
		m_addressSize = 2;
		m_dataSize = 0;
		//if (m_addressArray != nullptr) delete[] m_addressArray;
		//if (m_dataArray != nullptr) delete[] m_dataArray;
		m_dataArray = nullptr;
		m_completeSysEx = new uint8[6]
		{
			SYSEX_STATUS,
				0x7E,		// Manufacturer ID for Universal Non-Realtime Messages
				(deviceId<(uint8)0x10) ? (uint8)0x7F : deviceId,	// if not set (0), broadcast with 0x7F (e.g. use 10 for default setting of new groveboxes (=hex 16, meaning id 17))
				0x06,
				0x01,
				SYSEX_EOX
		};
		m_completeLength = 6;
		m_addressArray = &m_completeSysEx[3];
		break;
	case Type_Inquiry_Reply:
		m_manufacturerId = SYSEX_REPLY_MANUFACTURER_ID;
		m_addressSize = 2;
		m_dataSize = 9;
		/*			if (m_addressArray != nullptr) delete[] m_addressArray;
		if (m_dataArray != nullptr) delete[] m_dataArray;		*/
		m_completeSysEx = new uint8[15]
		{
			SYSEX_STATUS,
				0x7E,		// Manufacturer ID for Universal Non-Realtime Messages
				deviceId,
				0x06,
				0x02,
				m_dataArray[0],													// ID number (Roland = 41H)
				m_dataArray[1], m_dataArray[2],									// Device family code (0BH 01H)
				m_dataArray[3], m_dataArray[4],									// Device family number code (02H 00H)
				m_dataArray[5], m_dataArray[6], m_dataArray[7], m_dataArray[8],	// Software revision level (00H 03H 00H 00H)
				SYSEX_EOX
		};
		m_completeLength = 9;
		m_addressArray = &m_completeSysEx[3];
		m_dataArray = &m_completeSysEx[5];
		break;
	default:
		break;
	}
}

SyxMsg::SyxMsg(const MidiMessage& msg) :
	m_type(Type_Unknown),
	m_manufacturerId(0),
	m_modelId(0),
	m_commandId(0),
	m_deviceId(0),
	m_addressSize(0),
	m_addressArray(nullptr),
	m_dataArray(nullptr),
	m_dataSize(0),
	m_checkSum(0),
	m_checkSumOkay(false),
	m_completeSysEx(nullptr)
{
	if (msg.isSysEx()) initFromRawMidiSysEx(msg.getSysExData(), msg.getSysExDataSize(), false);
}

SyxMsg::~SyxMsg()
{
	if (m_completeSysEx != nullptr) delete[] m_completeSysEx;
}

MidiMessage SyxMsg::getAsMidiMessage()
{
	// for juce leave away f0 and f7 
	return MidiMessage::createSysExMessage(&m_completeSysEx[1], m_completeLength - 2);
}

/*
m_dataArray = &m_completeSysEx[5];
/*  // might be something like
m_completeSysEx[5],											// ID number (Roland = 41H)
m_completeSysEx[6], m_completeSysEx[7],								// Device family code (0BH 01H)
m_completeSysEx[8], m_completeSysEx[9],								// Device family number code (01H 00H)
m_completeSysEx[10], m_completeSysEx[11], m_completeSysEx[12], m_completeSysEx[13],	// Software revision level (00H 03H 00H 00H)
*/

uint8 SyxMsg::getInquiryReplyDevId()
{ 
	return m_deviceId; 
}

uint8 SyxMsg::getInquiryReplyManId() 
{
	return m_dataArray[0];
}

uint16 SyxMsg::getInquiryReplyDevFamCode()
{
	return m_dataArray[1] << 8 | m_dataArray[2];
}

uint16 SyxMsg::getInquiryReplyDevFamNumberCode() 
{ 
	return m_dataArray[3] << 8 | m_dataArray[4]; 
}

uint32 SyxMsg::getInquiryReplySoftwareRevision() 
{
	return m_dataArray[5] << 24 | m_dataArray[5] << 16 | m_dataArray[5] << 8 | m_dataArray[8]; 
}

// Creates a 16 byte long data array (icluding f0 and f7) for RQ1 request sysex message. Result is to be deleted by caller.
MidiMessage SyxMsg::newSysExRq1Msg(uint8 deviceID, uint32 address, uint32 size)
{
	uint8 dd = (uint8)(address & 0x000000FF);
	uint8 cc = (uint8)((address >> 8) & 0x000000FF);
	uint8 bb = (uint8)((address >> 16) & 0x000000FF);
	uint8 aa = (uint8)((address >> 24) & 0x000000FF);
	uint8 vv = (uint8)(size & 0x000000FF);
	uint8 uu = (uint8)((size >> 8) & 0x000000FF);
	uint8 tt = (uint8)((size >> 16) & 0x000000FF);
	uint8 ss = (uint8)((size >> 24) & 0x000000FF);
	// no need for f0 and f7 bytes to create a JUCE SysEx-MidiMessage
	uint8* rq1Data = new uint8[14]
	{
		SYSEX_ROLAND_MANUFACTURER_ID,
			deviceID,
			SYSEX_ROLAND__MODEL_ID >> 8,
			SYSEX_ROLAND__MODEL_ID & 0x00FF,
			SYSEX_ROLAND_COMMAND_RQ1,		// command ID (RQ1)
			aa, bb, cc, dd,	// address bytes
			ss, tt, uu, vv,	// size bytes
			SyxMsg::calcRq1Checksum(aa, bb, cc, dd, ss, tt, uu, vv),
	};
	MidiMessage msg = MidiMessage::createSysExMessage(rq1Data, 14);
	delete[] rq1Data;
	return msg;
}

uint8 SyxMsg::calcRq1Checksum(
	uint8 add1, uint8 add2, uint8 add3, uint8 add4,
	uint8 size1, uint8 size2, uint8 size3, uint8 size4)
{
	return (0x80 - ((add1 + add2 + add3 + add4 + size1 + size2 + size3 + size4) % 0x80)) % 0x80;
}

uint8 SyxMsg::calcRq1Checksum(const uint8* addressBytes, const uint8* sizeBytes)
{
	int sum(0);
	for (int i = 0; i < 4; i++)
	{
		sum += addressBytes[i];
		sum += sizeBytes[i];
	}
	return (0x80 - (sum % 0x80)) % 0x80;
}

uint8 SyxMsg::calcRq1Checksum(const uint8* addressAndData, int addressAndDataSize)
{
	int sum(0);
	for (int i = 0; i < addressAndDataSize; i++) sum += addressAndData[i];
	return (0x80 - (sum % 0x80)) % 0x80;
}

uint8 SyxMsg::calcDt1Checksum(const uint8* addressBytes, uint8 addressSize, const uint8* dataBytes, uint32 dataSize)
{
	int sum(0);
	for (uint8 i = 0; i < addressSize; i++)	sum += addressBytes[i];
	for (uint32 i = 0; i < dataSize; i++)	sum += dataBytes[i];
	return (0x80 - (sum % 0x80)) % 0x80;
}

SyxMsg::MessageType SyxMsg::getType()
{
	return m_type; 
}

String SyxMsg::getTypeAsString()
{
	switch (m_type)
	{
	case SyxMsg::Type_RQ1: return "RQ1"; break;
	case SyxMsg::Type_DT1: return "DT1"; break;
	case SyxMsg::Type_DT1_GS: return "DT1 GS"; break;
	case SyxMsg::Type_DT1_Quick: return "DT1 Quick"; break;
	case SyxMsg::Type_Universal_Realtime: return "Universal Realtime"; break;
	case SyxMsg::Type_Inquiry_Request: return "Inquiry Request"; break;
	case SyxMsg::Type_Inquiry_Reply: return "Inquiry Response"; break;
	case SyxMsg::Type_Unknown: return "Unknown"; break;
	default: return "Unknown"; break;
	}
}

uint8 SyxMsg::getDeviceId() 
{ 
	return m_deviceId; 
}

uint32 SyxMsg::get32BitAddress()
{
	if (m_addressSize == 4)
	{
		return (uint32)(m_addressArray[0] << 24) + (uint32)(m_addressArray[1] << 16) + (uint32)(m_addressArray[2] << 8) + (uint32)(m_addressArray[3]);
	}
	else if (m_addressSize == 3)
	{
		return (uint32)(m_addressArray[0] << 16) + (uint32)(m_addressArray[1] << 8) + (uint32)(m_addressArray[2]);
	}
	else if (m_addressSize == 2)
	{
		return (uint32)(m_addressArray[0] << 8) + (uint32)(m_addressArray[1]);
	}
	return 0;
}

uint32 SyxMsg::getBlockStartAddress()
{ 
	return get32BitAddress() & 0xFFFF0000; 
};

uint16 SyxMsg::getAddressOffset() 
{
	return get32BitAddress() & 0x0000FFFF; 
}

bool SyxMsg::isCheckSumOkay() 
{
	return m_checkSumOkay; 
}

void SyxMsg::getAsSysExData(uint8** data, uint32 &dataLength) const
{
	*data = m_completeSysEx;
	dataLength = m_completeLength;
}

void SyxMsg::getSysExDataArrayPtr(uint8** data, uint32 &dataLength)
{
	*data = m_dataArray;
	dataLength = m_dataSize;
}

SyxMsg* SyxMsg::copyToNew()
{
	return new SyxMsg(m_completeSysEx, m_completeLength, true);
}

String SyxMsg::toString()
{
	return String::toHexString(m_completeSysEx, m_completeLength).toUpperCase();
}

MidiMessage SyxMsg::toMidiMessage()
{
	return MidiMessage::createSysExMessage(&m_completeSysEx[1], m_completeLength - 2);
}

uint16 SyxMsg::getUnsigned14BitValueFrom7BitBytes(uint8 lsbByte, uint8 msbByte)
{
	return (uint16)msbByte << 7 | (uint16)lsbByte;
}

int16 SyxMsg::getSigned14BitValueFrom7BitBytes(uint8 lsbByte, uint8 msbByte)
{
	return ((int)msbByte << 7 | (int)lsbByte) - 0x2000;
}

MidiMessage SyxMsg::createTextMetaEvent(MidiTextMetaEventType type, String text, double timeStamp/* = (0.0)*/)
{
	MemoryBlock rawTextMetaEventMidiData(3 + text.length(), true);
	rawTextMetaEventMidiData[0] = (char)(-1);
	rawTextMetaEventMidiData[1] = (char)type;
	rawTextMetaEventMidiData[2] = (char)text.length();
	for (int i = 0; i < text.length(); i++) rawTextMetaEventMidiData[i + 3] = (char)text[i];
	return MidiMessage(rawTextMetaEventMidiData.getData(), rawTextMetaEventMidiData.getSize(), timeStamp);
}

// MIDI Channel Prefix FF 20 01 cc (cc: 00-0F)
MidiMessage SyxMsg::createChannelPrefixMetaEvent(uint8 cc, double timeStamp /*= (0.0)*/)
{
	MemoryBlock rawTextMetaEventMidiData(4, true);
	rawTextMetaEventMidiData[0] = (char)(-1);
	rawTextMetaEventMidiData[1] = (char)(0x20);
	rawTextMetaEventMidiData[2] = (char)(0x01);
	rawTextMetaEventMidiData[3] = (char)cc;
	return MidiMessage(rawTextMetaEventMidiData.getData(), rawTextMetaEventMidiData.getSize(), timeStamp);
}


void SyxMsg::initFromRawMidiSysEx(const uint8* rawData, const uint32 rawDataSize, bool includingF0andF7)
{
	if (includingF0andF7 && (rawData[0] != SYSEX_STATUS || rawData[rawDataSize - 1] != SYSEX_EOX)) return;

	// copy
	m_completeLength = includingF0andF7 ? rawDataSize : rawDataSize + 2;
	m_completeSysEx = new uint8[m_completeLength];
	if (!includingF0andF7)
	{
		m_completeSysEx[0] = 0xF0;
		m_completeSysEx[m_completeLength - 1] = 0xF7;
	}
	for (uint32 i = 0; i < m_completeLength; i++) m_completeSysEx[i] = includingF0andF7 ? rawData[i] : rawData[i - 1];

	// parse RQ1
	if (m_completeLength == 16 &&
		m_completeSysEx[1] == SYSEX_ROLAND_MANUFACTURER_ID &&
		m_completeSysEx[3] == (uint8)(SYSEX_ROLAND__MODEL_ID >> 8) &&
		m_completeSysEx[4] == (uint8)(SYSEX_ROLAND__MODEL_ID & 0x00FF) &&
		m_completeSysEx[5] == SYSEX_ROLAND_COMMAND_RQ1)
	{
		m_type = Type_RQ1;
		m_manufacturerId = SYSEX_ROLAND_MANUFACTURER_ID;
		m_deviceId = m_completeSysEx[2];
		m_modelId = SYSEX_ROLAND__MODEL_ID;
		m_commandId = SYSEX_ROLAND_COMMAND_RQ1;
		m_addressSize = 4;
		m_addressArray = &m_completeSysEx[6];
		m_dataSize = 4;
		m_dataArray = &m_completeSysEx[10];
		m_checkSum = m_completeSysEx[m_completeLength - 2];
		m_checkSumOkay = (m_checkSum == calcRq1Checksum(m_addressArray, m_dataArray));
	}
	// parse DT1 for MC-307
	else if (
		m_completeSysEx[1] == SYSEX_ROLAND_MANUFACTURER_ID &&
		m_completeSysEx[3] == (uint8)(SYSEX_ROLAND__MODEL_ID >> 8) &&
		m_completeSysEx[4] == (uint8)(SYSEX_ROLAND__MODEL_ID & 0x00FF) &&
		m_completeSysEx[5] == SYSEX_ROLAND_COMMAND_DT1)
	{
		m_type = Type_DT1;
		m_manufacturerId = SYSEX_ROLAND_MANUFACTURER_ID;
		m_deviceId = m_completeSysEx[2];
		m_modelId = SYSEX_ROLAND__MODEL_ID;
		m_commandId = SYSEX_ROLAND_COMMAND_DT1;
		m_addressSize = 4;
		m_addressArray = &m_completeSysEx[6];
		m_dataSize = m_completeLength - 12;
		m_dataArray = &m_completeSysEx[10];
		m_checkSum = m_completeSysEx[m_completeLength - 2];
		m_checkSumOkay = (m_checkSum == calcDt1Checksum(m_addressArray, m_addressSize, m_dataArray, m_dataSize));
	}
	// parse DT1 for GS
	else if (
		m_completeSysEx[1] == SYSEX_ROLAND_MANUFACTURER_ID &&
		m_completeSysEx[3] == SYSEX_GS_MODEL_ID &&
		m_completeSysEx[4] == SYSEX_ROLAND_COMMAND_DT1)
	{
		m_type = Type_DT1_GS;
		m_manufacturerId = SYSEX_ROLAND_MANUFACTURER_ID;
		m_deviceId = m_completeSysEx[2];
		m_modelId = (uint16)SYSEX_GS_MODEL_ID;
		m_commandId = SYSEX_ROLAND_COMMAND_DT1;
		m_addressSize = 3;
		m_addressArray = &m_completeSysEx[5];
		m_dataSize = m_completeLength - 10;
		m_dataArray = &m_completeSysEx[8];
		m_checkSum = m_completeSysEx[m_completeLength - 2];
		m_checkSumOkay = (m_checkSum == calcDt1Checksum(m_addressArray, m_addressSize, m_dataArray, m_dataSize));
	}
	// parse DT1 for MC-307 Quick
	else if (
		m_completeLength == 11 &&
		m_completeSysEx[1] == SYSEX_ROLAND_MANUFACTURER_ID &&
		m_completeSysEx[3] == SYSEX_ROLAND__QUICK_ID &&
		m_completeSysEx[4] == SYSEX_ROLAND_COMMAND_DT1)
	{
		m_type = Type_DT1_Quick;
		m_manufacturerId = SYSEX_ROLAND_MANUFACTURER_ID;
		m_deviceId = m_completeSysEx[2];
		m_modelId = (uint16)SYSEX_ROLAND__QUICK_ID;
		m_commandId = SYSEX_ROLAND_COMMAND_DT1;
		m_addressSize = 2;
		m_addressArray = &m_completeSysEx[5];
		m_dataSize = 2;
		m_dataArray = &m_completeSysEx[7];
		m_checkSum = m_completeSysEx[m_completeLength - 2];
		m_checkSumOkay = (m_checkSum == calcDt1Checksum(m_addressArray, m_addressSize, m_dataArray, m_dataSize));
	}
	// parse Inquiry Request
	else if (
		m_completeLength == 6 &&
		m_completeSysEx[1] == 0x7E &&
		m_completeSysEx[3] == 0x06 &&
		m_completeSysEx[4] == 0x01)
	{
		m_type = Type_Inquiry_Request;
		m_manufacturerId = 0x7E;
		m_deviceId = m_completeSysEx[2];
		m_addressSize = 2;
		m_addressArray = &m_completeSysEx[3];
		m_checkSumOkay = true;
	}
	// parse Inquiry Reply
	else if (
		m_completeLength == 15 &&
		m_completeSysEx[1] == 0x7E &&
		m_completeSysEx[3] == 0x06 &&
		m_completeSysEx[4] == 0x02)
	{
		m_type = Type_Inquiry_Reply;
		m_manufacturerId = 0x7E;
		m_deviceId = m_completeSysEx[2];
		m_addressSize = 2;
		m_addressArray = &m_completeSysEx[3];
		m_dataSize = 9;
		m_dataArray = &m_completeSysEx[5];
		/*  // might be something like
		m_completeSysEx[5],											// ID number (Roland = 41H)
		m_completeSysEx[6], m_completeSysEx[7],								// Device family code (0BH 01H)
		m_completeSysEx[8], m_completeSysEx[9],								// Device family number code (01H 00H)
		m_completeSysEx[10], m_completeSysEx[11], m_completeSysEx[12], m_completeSysEx[13],	// Software revision level (00H 03H 00H 00H)
		*/
		m_checkSumOkay = true;
	}
	// parse Universal Realtime
	else if (
		m_completeSysEx[1] == 0x7F)
	{
		m_type = Type_Universal_Realtime;
		m_manufacturerId = 0x7F;
		m_dataSize = m_completeLength - 2;
		m_dataArray = &m_completeSysEx[1];
		m_checkSumOkay = true;
	}
}