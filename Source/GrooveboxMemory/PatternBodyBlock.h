/*
  ==============================================================================

    PatternBodyBlock.h
    Created: 15 Jan 2014 9:19:05pm
    Author:  Martin

  ==============================================================================
*/

#ifndef PATTERNBODYBLOCK_H_INCLUDED
#define PATTERNBODYBLOCK_H_INCLUDED

#include "GrooveboxMemoryBlock.h"
#include "JuceHeader.h"

class PatternBodyBlock : public GrooveboxMemoryBlock, public TableListBoxModel
{
public:
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

	enum RhythmGroup
	{
		Rhythm_Group_BD = 0x00,
		Rhythm_Group_SD = 0x01,
		Rhythm_Group_HH = 0x02,
		Rhythm_Group_CLP = 0x03,
		Rhythm_Group_CYM = 0x04,
		Rhythm_Group_TomPerc = 0x05,
		Rhythm_Group_Hit = 0x06,
		Rhythm_Group_Others = 0x07,
		Rhythm_Group_All = 0x09,
		Rhythm_Group_Unknown = 0xFF
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

	enum PatternTableListColumnId
	{
		Col_Position = 10,
		Col_Raw0 = 0,
		Col_TicksInc = 11,
		Col_Raw1 = 1,
		Col_EventType = 12,
		Col_Raw2 = 2,
		Col_Raw3 = 3,
		Col_Part= 13,
		Col_Raw4 = 4,
		Col_Raw5 = 5,
		Col_Raw6 = 6,
		Col_Raw7 = 7,
		Col_Value1 = 14,
		Col_Value2 = 15
	};

	struct PatternEventData
	{
		const static String NOTENAMES[];
		const static unsigned int ticksPerQuarterNote;
		static unsigned long mostRecentAbsoluteTick;	// static, for all PatternEventData instances, increased by constructor of new instances by their relative tick increment
		static uint8 lastRelativeTickIncrement; // set on instance construction by byte 1
		static String getAbsoluteTickString(unsigned int absoluteTicks);	// MM-BB-TT. 4/4 measure. TODO: different measures, load from setup
		static String getPartString(PatternPart part);
		static String getRhythmGroupString(RhythmGroup rhythmGroup);

		PatternEventData(const uint8* pointerToData, unsigned int pointedDataRestLength);
		uint8 bytes[8];
		unsigned long absoluteTick;	// set on construction by mostRecentAbsoluteTick + lastRelativeTickIncrement
		
		uint8 getRelativeTickIncrement();
		PatternEventType getType();
		String getTypeString();
		PatternPart getPart();
		uint8 getNoteVelocity();
		uint16 getNoteGateTicks();
		uint8 getPAftKey();
		String getPAftKeyString();
		uint8 getPAftPressure();
		uint8 getCcNo();
		uint8 getCcValue();
		uint8 getPcProgram();
		uint8 getCAftPressure();
		uint16 getPitchBendValue();
		PatternPart getMutePart();
		RhythmGroup getMuteRhythmGroup();
		bool getMuteState();	// false=Mute, true=On
		uint16 getTempoValue();
		uint32 getSysExSize();
		uint8* getSysExBytesPtr(); // pointer to last 4 bytes
		void getSysExBytesCopyTo(uint8* fourBytes); // make sure to give reference to a 4-byte array which values are to be set
		String toDebugString();
	};

	PatternBodyBlock();

	bool handleSysEx(SyxMsg* sysExMsg) override;

	// unpack SysEx data array, size of unpacked data is returned via rerence parameter. don't forger to delete the returned array after usage
	static const uint8* unpack7BitTo8BitData(const uint8* packed7BitData, int packed7BitDataSize, int &unpackedDataSize);

	int getNumRows() override;
	void paintRowBackground(Graphics& g, int rowNumber, int width, int height, bool rowIsSelected) override;
	void paintCell(Graphics& g, int rowNumber, int columnId, int width, int height, bool rowIsSelected) override;
	String getCellTooltip(int rowNumber, int columnId) override;
private:
	OwnedArray<PatternEventData> m_sequenceBlocks;	// containing 8 bytes each
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(PatternBodyBlock)
};



#endif  // PATTERNBODYBLOCK_H_INCLUDED
