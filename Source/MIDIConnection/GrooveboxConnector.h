/*
  ==============================================================================

    GrooveboxConnector.h
    Created: 12 Dec 2013 12:46:14am
    Author:  Martin

  ==============================================================================
*/

#ifndef GROOVEBOXCONNECTOR_H_INCLUDED
#define GROOVEBOXCONNECTOR_H_INCLUDED

#include "JuceHeader.h"
#include "SyxMsg.h"

// this opens the midi in and out which are global objects (they are globally deleted in Main.cpp on exit)
class GrooveboxConnector : public MidiMessageCollector
{
public:

	enum GrooveboxModel{
		Model_MC_505 = 0x0000,
		Model_JX_305 = 0x0100,
		Model_MC_307 = 0x0200,
		Model_D2 = 0x0300,
		Model_Unknown = -1
	};

	struct GrooveBoxConnectionEntry
	{
		uint8 deviceId = 0;
		uint8 manufactorId = 0;
		uint16 deviceFamilyCode = 0;
		GrooveboxModel deviceFamilyNumberCode = Model_Unknown;
		uint32 softwareRevisionLevel = 0;

		String getDeviceIdAsString() { return String(deviceId + 1); }

		String getGrooveboxModelAsString() {
			switch (deviceFamilyNumberCode)
			{
			case Model_MC_505: return "Roland MC-505";
			case Model_JX_305: return "Roland JX-305";
			case Model_MC_307: return "Roland MC-307";
			case Model_D2: return "Roland D2";
			default:
				return TRANS("Unknown, unsupported device");
			}
		}
	};

	GrooveboxConnector();

	~GrooveboxConnector();

	bool openGrooveboxMidiInAndOut(bool warnMsgBox=true);

	int refreshConnections(bool warnMsgBox = true, int timeOutMilliseconds=10000);

	void addConnection(GrooveBoxConnectionEntry* entry);

	uint8 getActiveDeviceId();
	String getActiveDeviceIdAsString();
	GrooveBoxConnectionEntry* getActiveConnection();

	GrooveboxModel getActiveConnectionGrooveboxModel();

	void setActiveConnection(uint8 idToSelect) { m_selectedDeviceId = idToSelect; }

	OwnedArray<GrooveBoxConnectionEntry, CriticalSection>* getConnections() { return &m_activeConnections;  }

	void handleIncomingMidiMessage(MidiInput* input, const MidiMessage& msg);

	bool receiveDump();

	bool sendPatchesPatternAndSetupAsDump();

private:
	uint8 m_selectedDeviceId;
	OwnedArray<GrooveBoxConnectionEntry, CriticalSection> m_activeConnections;

	class IndenityRequestReplyThread;

	// the timer to end the RetrieveSysExThread
	class MIDIRetrieveTimeOutTimer : public Timer
	{
	public:
		MIDIRetrieveTimeOutTimer(IndenityRequestReplyThread* threadRef);
		void timerCallback();

	private:
		IndenityRequestReplyThread* m_threadPtr;
		JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(MIDIRetrieveTimeOutTimer);
	};

	// sends an identity request message out and waits for incoming idenity reply sysex messages, 
	// a timeout will finish the thread if no sysex message arrives in time
	// the request messages stay property of the caller, he is responsible for deletion
	class IndenityRequestReplyThread : public ThreadWithProgressWindow
	{
	public:
		IndenityRequestReplyThread(String windowTitle, int timeOutInMs);
		~IndenityRequestReplyThread();

		void run() override;
		void threadComplete(bool userPressedCancel) override;

		void addMidiMessage(MidiInput *midiIn, const MidiMessage &midiInMsg);
		OwnedArray<SyxMsg, CriticalSection>* getRetrievedMessages() { return &m_retrievedSysExMessages; }

	private:
		ScopedPointer<SyxMsg> inquiry;
		ScopedPointer<MIDIRetrieveTimeOutTimer> m_timeoutTimer;
		int m_retrieveTimeout = 250;
		OwnedArray<SyxMsg, CriticalSection> m_retrievedSysExMessages;

		JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(IndenityRequestReplyThread);
	};

	// before running add SysEx-Messages
	class SendBulkDumpThread : public ThreadWithProgressWindow
	{
	public:
		SendBulkDumpThread();
		~SendBulkDumpThread();
		void run() override;
		void threadComplete(bool userPressedCancel) override;
		OwnedArray<SyxMsg, CriticalSection>* getSysExCompilationPtr(){ return &sysExCompilation; }
	private:
		OwnedArray<SyxMsg, CriticalSection> sysExCompilation;
		JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(SendBulkDumpThread);
	};

	// after running it will contain received SysEx-Messages in its private sysExCompilation array and handle them in threadComplete
	class RecvBulkDumpThread : public ThreadWithProgressWindow
	{
	public:
		RecvBulkDumpThread();
		~RecvBulkDumpThread();
		void run() override;
		void threadComplete(bool userPressedCancel) override;
		OwnedArray<SyxMsg, CriticalSection>* getSysExCompilationPtr(){ return &sysExCompilation; }
		class TimeOutTimer : public juce::Timer
		{
		public:
			TimeOutTimer(RecvBulkDumpThread* bulkDumpThread);
			void timerCallback() override; // for timeup after
		private:
			RecvBulkDumpThread* m_bulkDumpThread;
			JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(TimeOutTimer);
		};
		friend class TimeOutTimer;
		void addReceivedMidiMessage(const MidiMessage& msg);
	private:
		bool afterFirstReceivedMsg = false;
		int estimatedNumOfLinesToReceive = 200;
		OwnedArray<SyxMsg, CriticalSection> sysExCompilation;
		ScopedPointer<TimeOutTimer> m_timeoutTimer;
		JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(RecvBulkDumpThread);
	};
	ScopedPointer<IndenityRequestReplyThread> m_checkThread;
	ScopedPointer<SendBulkDumpThread> m_sendBulkDumpThread;
	ScopedPointer<RecvBulkDumpThread> m_recvBulkDumpThread;

	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(GrooveboxConnector)
};

#endif  // GROOVEBOXCONNECTOR_H_INCLUDED
