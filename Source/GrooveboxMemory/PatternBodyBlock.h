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

class PatternBodyBlock : public GrooveboxMemoryBlock, public TableListBoxModel, public ChangeBroadcaster
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
		Evt_NoteOff = 12, // not in original roland format, but producable for conversion to midi
		Evt_Unknown = -1
	};

	enum PatternTableListColumnId
	{
		Col_Position = 10,
		Col_Raw0 = 1,
		Col_TicksInc = 11,
		Col_Raw1 = 2,
		Col_EventType = 12,
		Col_Raw2 = 3,
		Col_Raw3 = 4,
		Col_Part= 13,
		Col_Raw4 = 5,
		Col_Raw5 = 6,
		Col_Raw6 = 7,
		Col_Raw7 = 8,
		Col_Value1 = 14,
		Col_Value2 = 15
	};

	const static String PATTERNTABLE_COLUMN_NAMES_FOR_IDS[];

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
		int getMidiChannel(); // for midi conversion: Part1=Ch1...Part7=Ch1,PartR=Ch10
		int getNoteNumber();
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
		String getPitchBendString();
		PatternPart getMutePart();
		RhythmGroup getMuteRhythmGroup();
		bool getMuteState();	// false=Mute, true=On
		uint16 getTempoValue();
		uint32 getSysExSize();
		uint8* getSysExBytesPtr(); // pointer to last 4 bytes
		void getSysExBytesCopyTo(uint8* fourBytes); // make sure to give reference to a 4-byte array which values are to be set
		String toDebugString();
		MidiMessage toMidiMessage();
	};

	PatternBodyBlock();

	bool handleSysEx(SyxMsg* sysExMsg) override;

	// unpack SysEx data array, size of unpacked data is returned via rerence parameter. don't forger to delete the returned array after usage
	static const uint8* unpack7BitTo8BitData(const uint8* packed7BitData, int packed7BitDataSize, int &unpackedDataSize);

	int getNumRows() override;
	void paintRowBackground(Graphics& g, int rowNumber, int width, int height, bool rowIsSelected) override;
	void paintCell(Graphics& g, int rowNumber, int columnId, int width, int height, bool rowIsSelected) override;
	String getCellTooltip(int rowNumber, int columnId) override;
	void selectedRowsChanged(int lastRowSelected) override;
	void setTableSelectionMidiOutId(int id);
	MidiOutput* getOpenTableSelectionMidiOut() { return tableSelectionMidiOut; }
	void setTableFilters(bool p_R = true, bool p_1 = true, bool p_2 = true, bool p_3 = true, bool p_4 = true, bool p_5 = true, bool p_6 = true, bool p_7 = true, bool p_muteCtl = true,
		bool t_note = true, uint8 t_noteLower = 0, uint8 t_noteUpper = 127, bool t_pc = true, bool t_cc = true, uint8 t_ccLower = 0, uint8 t_ccUpper = 127,
		bool t_bend = true, bool t_pAft = true, uint8 t_pAftLower = 0, uint8 t_pAftUpper = 127, bool t_CAft = true, bool t_tempo = true, bool t_mute = true, bool t_sysEx = true);

private:
	OwnedArray<PatternEventData> m_sequenceBlocks;	// containing 8 bytes each
	ScopedPointer<MidiOutput> tableSelectionMidiOut = nullptr;
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(PatternBodyBlock)
};



#endif  // PATTERNBODYBLOCK_H_INCLUDED
