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

class BeatSignature;

class PatternBodyBlock : public GrooveboxMemoryBlock, public TableListBoxModel, public ChangeBroadcaster, public ChangeListener, public Timer /*for noteOff->midiOut after gate-time*/
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
		Col_Part = 13,
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
		//const static unsigned int ticksPerQuarterNote;
		static unsigned long mostRecentAbsoluteTick;	// static, for all PatternEventData instances, increased by constructor of new instances by their relative tick increment
		static uint8 lastRelativeTickIncrement; // set on instance construction by byte 1
		// MM-BB-TT depends on beat signature. for gate times set asLength to true (conting beats and measures from 0 on instead beginning with number 1)
		String getAbsoluteTickString(unsigned int absoluteTicks, bool asLength = false);
		static String getPartString(PatternPart part);

		PatternEventData(const uint8* pointerToData, unsigned int pointedDataRestLength);
		// constructor for note off
		PatternEventData(unsigned long absTick, int8 key, uint8 part);
		// constructor for free data enty
		PatternEventData(unsigned long absTick, const uint8 byte0, const uint8 byte1, const uint8 byte2, const uint8 byte3 = 0, const uint8 byte4 = 0, const uint8 byte5 = 0, const uint8 byte6 = 0, const uint8 byte7 = 0);
		// constructor from midi event, relative tick will be null, just absolue tick set. so in PatternBodyBlock ticks must be refreshed after adding these
		PatternEventData(unsigned long absTick, MidiMessageSequence::MidiEventHolder* midiEventHolder);

		~PatternEventData();

		uint8 bytes[8];
		unsigned long absoluteTick;	// set on construction by mostRecentAbsoluteTick + lastRelativeTickIncrement
		bool isNoteOff = false;

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
		float getTempoValue();
		uint32 getSysExSize();
		uint8* getSysExBytesPtr(); // pointer to last 4 bytes
		void getSysExBytesCopyTo(uint8* fourBytes); // make sure to give reference to a 4-byte array which values are to be set
		String toDebugString();
		MidiMessage toMidiMessage();
	};

	PatternBodyBlock();
	~PatternBodyBlock();

	bool handleSysEx(SyxMsg* sysExMsg) override;

	// unpack SysEx data array, size of unpacked data is returned via rerence parameter. don't forger to delete the returned array after usage
	static const uint8* unpack7BitTo8BitData(const uint8* packed7BitData, int packed7BitDataSize, int &unpackedDataSize);

	int getNumRows() override;
	void paintRowBackground(Graphics& g, int rowNumber, int width, int height, bool rowIsSelected) override;
	void paintCell(Graphics& g, int rowNumber, int columnId, int width, int height, bool rowIsSelected) override;
	String getCellTooltip(int rowNumber, int columnId) override;
	void timerCallback() override;
	void selectedRowsChanged(int lastRowSelected) override;
	void setTableSelectionMidiOutId(int id);
	MidiOutput* getOpenTableSelectionMidiOut() { return tableSelectionMidiOut.get(); }

	void refreshFilteredContent();
	void changeListenerCallback(ChangeBroadcaster *source) override;

	class VirtualPatternTableFilterBlock : public GrooveboxMemoryBlock, public ChangeBroadcaster
	{
	public:
		enum ParameterAdressOffsets
		{
			ViewPart1 = 0x00,
			ViewPart2 = 0x01,
			ViewPart3 = 0x02,
			ViewPart4 = 0x03,
			ViewPart5 = 0x04,
			ViewPart6 = 0x05,
			ViewPart7 = 0x06,
			ViewPartR = 0x09,
			ViewMuteCtrl = 0x0E,
			ViewSingeParts = 0x0F,
			ViewNotes = 0x10,
			ViewNotesMin = 0x11,
			ViewNotesMax = 0x12,
			ViewPC = 0x13,
			ViewCC = 0x14,
			ViewCCMin = 0x15,
			ViewCCMax = 0x16,
			ViewBend = 0x17,
			ViewPAft = 0x18,
			ViewPAftMin = 0x19,
			ViewPAftMax = 0x1A,
			ViewCAft = 0x1B,
			ViewTempo = 0x1C,
			ViewMute = 0x1D,
			ViewSysEx = 0x1E,
			ViewNotesOff = 0x1F,
			ViewInc = 0x20
		};
		VirtualPatternTableFilterBlock();
	private:
		JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(VirtualPatternTableFilterBlock)
	};
	VirtualPatternTableFilterBlock* getPatternTableFilterParams(){ return m_patternTableFilterParams; }

	// returns true, if event is to be shown according to VirtualPatternTableFilterBlock m_patternTableFilterParams
	bool filter(PatternEventData* event) const;

	bool isPatternEmpty();

	// calculates and refreshes relative inc times from absolute times, from start to first event, between all events from last to end of pattern, if nescessary creates INC entries
	void refreshRelativeTickIncrements();

	// clears entries m_sequenceBlocks, calls refreshRelativeTickIncrements(), calls refreshFilteredContent()
	void clearPattern();

	// creates a new MidiFile
	MidiFile* convertToMidiFile();

	static unsigned int convertTicksTo96TPQN(const double time, const MidiMessageSequence& tempoEvents, const int timeFormat);
	void loadMidiFile(File& file);

	// get data request messages from this block and its sub blocks, the result is added to the array specified in the parameter, overridden for serializing pattern data
	void createBlockSendMessages(OwnedArray<SyxMsg, CriticalSection>* syxMsgArrayPtr) override;

	bool saveRawBinary(File& file);
	bool saveRawCsv(File& file);

	const OwnedArray<PatternEventData>* getFilteredSequenceBlocks();

	unsigned long getPatternLengthInTicks(); // depends on m_lengthInMeasures and time signature

	friend class PlayerThread;
	class PlayerThread : public Thread, public MultiTimer, public ChangeBroadcaster
	{
	public:
		PlayerThread();
		void run() override;
		// note-off timers
		void timerCallback(int noteOffId) override;
		static int getNoteOffID(uint8 part, uint8 key){ return (part << 8) + key; }
		static void getPartAndKeyFromNoteOffId(int noteOffId, uint8 &part, uint8 &key){ key = (uint8)(noteOffId & 0x7F); part = (uint8)(noteOffId >> 8); }
		// to be called on change message
		unsigned long getPlayBackTimeInAbsoluteTicks(){ return m_currentAbsoluteTimeInTicks; }
	private:
		unsigned long m_currentAbsoluteTimeInTicks=0;
	};

	PlayerThread* getPlayerThread() { return m_playerThread; }

private:
	OwnedArray<PatternEventData> m_sequenceBlocks;	// containing 8 bytes each
	OwnedArray<PatternEventData> m_filteredsequenceBlocks;	// event references (still owned by m_sequenceBlocks) to be shown in table (m_sequenceBlocks after view filtering according to VirtualPatternTableFilterBlock m_patternTableFilterParams)
	int m_lastSelectedRowFilteredsequence = -1;
    std::unique_ptr<juce::MidiOutput> tableSelectionMidiOut = nullptr;
	ScopedPointer<PlayerThread> m_playerThread;
	ScopedPointer<VirtualPatternTableFilterBlock> m_patternTableFilterParams;
	HashMap<int, String> m_midiCCNames;
	HashMap<int, String> m_keyDrumGroupes;
	unsigned int sysExBuilderByteIndex = 0;
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(PatternBodyBlock)
};



#endif  // PATTERNBODYBLOCK_H_INCLUDED
