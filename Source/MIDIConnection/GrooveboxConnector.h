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
			case Model_MC_505: return "Roland MC-505 (groovebox)";
			case Model_JX_305: return "Roland JX-305 (groovesynth)";
			case Model_MC_307: return "Roland MC-307 (groovebox)";
			case Model_D2: return "Roland D2 (groovebox)";
			default:
				return TRANS("Unknown, unsupported device");
			}
		}
	};

	GrooveboxConnector();

	~GrooveboxConnector();

	bool openGrooveboxMidiInAndOut(bool warnMsgBox=true);

	int refreshConnections(bool warnMsgBox = true);

	void addConnection(GrooveBoxConnectionEntry* entry);

	uint8 getActiveDeviceId();
	String getActiveDeviceIdAsString();
	GrooveBoxConnectionEntry* getActiveConnection();

	GrooveboxModel getActiveConnectionGrooveboxModel();

	void setActiveConnection(uint8 idToSelect) { m_selectedDeviceId = idToSelect; }

	(OwnedArray<GrooveBoxConnectionEntry, CriticalSection>)& getConnections() { return m_activeConnections;  }

	void handleIncomingMidiMessage(MidiInput* input, const MidiMessage& msg);

	// creates a thread to send out requests (RQ1-SysEx messages) and collect/handle the answers
	// a progress window is shown if the window title is not empty
	// if no response is received within given timeout after a request, the response will be skipped (or the last response already arrived)
	(OwnedArray<SyxMsg, CriticalSection>)& requestSysExData(OwnedArray<SyxMsg, CriticalSection>& requestSysExMessagesPtr, String windowTitle, int timeOutInMs)
	{
		if (m_checkThread!=nullptr && m_checkThread->isThreadRunning())
		{
			m_checkThread->signalThreadShouldExit();
			m_checkThread->stopThread(50);
			m_checkThread->waitForThreadToExit(50);
		}
		deleteAndZero(m_checkThread);
		m_checkThread = new RetrieveSysExThread(requestSysExMessagesPtr, windowTitle, timeOutInMs);
		m_checkThread->runThread();
		//m_checkThread->waitForThreadToExit(timeOutInMs*requestSysExMessagesPtr.size());
		return m_checkThread->getRetrievedMessages();
	}

private:
	uint8 m_selectedDeviceId;
	OwnedArray<GrooveBoxConnectionEntry, CriticalSection> m_activeConnections;

	class RetrieveSysExThread;

	// the timer to end the RetrieveSysExThread
	class MIDIRetrieveTimeOutTimer : public Timer
	{
	public:
		MIDIRetrieveTimeOutTimer(RetrieveSysExThread* threadRef);
		void timerCallback();

	private:
		RetrieveSysExThread* m_threadPtr;
		JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(MIDIRetrieveTimeOutTimer);
	};

	// sends a request message out and waits for incoming sysex messages, 
	// which are stored by the thread and can be handled afterwards by the caller.
	// a timeout will finish the thread if no more sysex message arrive in time
	// the request messages stay property of the caller, he is responsible for deletion
	class RetrieveSysExThread : public ThreadWithProgressWindow
	{
	public:
		// for multiple requests to be made sequentially
		RetrieveSysExThread(OwnedArray<SyxMsg, CriticalSection>& requestSysExMessagesPtr, String windowTitle, int timeOutInMs);
		// for single requests
		RetrieveSysExThread(SyxMsg* requestSysExMessagePtr, String windowTitel, int timeOutInMs);
		~RetrieveSysExThread();

		void run();

		void addMidiMessage(MidiInput *midiIn, const MidiMessage &midiInMsg);
		(OwnedArray<SyxMsg, CriticalSection>)& getRetrievedMessages() { return m_retrievedSysExMessages; }
		StringArray getPartPatchNames(){ return m_partPatchNames; }
		ScopedPointer<WaitableEvent> callNextRequestEvent;
	private:

		ScopedPointer<MIDIRetrieveTimeOutTimer> m_timeoutTimer;
		int m_retrieveTimeout = 250;
		OwnedArray <SyxMsg, CriticalSection> m_requestMessages;
		StringArray m_partPatchNames;	// Part R [0], Part 1 [1], ... Part 7 [7]
		OwnedArray<SyxMsg, CriticalSection> m_retrievedSysExMessages;

		JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(RetrieveSysExThread);
	};

	RetrieveSysExThread* m_checkThread;

	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(GrooveboxConnector)
};

#endif  // GROOVEBOXCONNECTOR_H_INCLUDED
