/*
  ==============================================================================

    GrooveboxConnector.cpp
    Created: 12 Dec 2013 2:48:59am
    Author:  Martin

  ==============================================================================
*/

#include "GrooveboxConnector.h"
#include "../GrooveboxMemory/OverallMemoryBlock.h"
#include "../GrooveboxMemory/QuickSysExBlock.h"
#include "../GrooveboxMemory/Waveforms.h"

extern ApplicationProperties* appProperties;
extern MidiInput* midiInputDevice;
extern MidiOutput* midiOutputDevice;
extern int preferredMidiInId;
extern int preferredMidiOutId;
extern OverallMemoryBlock* grooveboxMemory;
extern QuickSysExBlock* quickSysEx;
extern Waveforms* waveForms;

GrooveboxConnector::GrooveboxConnector() :
	m_selectedDeviceId(0),	// 0 is invalid (no connection) - only values from 0x10 (17) to 0x7F are allowed
	m_checkThread(nullptr)
{
}

GrooveboxConnector::~GrooveboxConnector()
{
	m_activeConnections.clear();
	if (m_checkThread != nullptr)
	{
		m_checkThread->waitForThreadToExit(50);
		delete m_checkThread;
	}
}

bool GrooveboxConnector::openGrooveboxMidiInAndOut(bool warnMsgBox)
{
	// open midi in and out
	if (midiOutputDevice != nullptr) deleteAndZero(midiOutputDevice);
	if ((midiOutputDevice = MidiOutput::openDevice(preferredMidiOutId)) == nullptr)
	{
		if (warnMsgBox) AlertWindow::showMessageBox(AlertWindow::WarningIcon, TRANS("Error opening Midi out port."), TRANS("Could not access selected MIDI out port.\r\nThis might be because it's still in use by another application."));
		return false;
	}
	if (midiInputDevice != nullptr) deleteAndZero(midiInputDevice);
	if ((midiInputDevice = MidiInput::openDevice(preferredMidiInId, this)) == nullptr)
	{
		if (warnMsgBox) AlertWindow::showMessageBox(AlertWindow::WarningIcon, TRANS("Error opening Midi in port."), TRANS("Could not access selected MIDI in port.\r\nThis might be because it's still in use by another application."));
		return false;
	}
	return true;
}

int GrooveboxConnector::refreshConnections(bool warnMsgBox)
{
	{
		m_activeConnections.clear();
	}
	
	// (re)open midi in and out
	if (!openGrooveboxMidiInAndOut(warnMsgBox)) return 0;

	// Thread with progress Window: send broadcast sysex and wait for replys, stop after timeout (waiting long enough without any more replies)
	// use a MidiMessageCollector handler during running thread
	
	ScopedPointer<SyxMsg> inquiry = new SyxMsg(SyxMsg::Type_Inquiry_Request);

	m_checkThread = new RetrieveSysExThread(inquiry, TRANS("Checking connections..."), 100);
	m_checkThread->runThread();

	// after thread: read connections from retrieved data
	for (int i = 0; i < m_checkThread->getRetrievedMessages().size(); i++)
	{
		SyxMsg* syxMsg (m_checkThread->getRetrievedMessages()[i]);
		if (syxMsg->getType() == SyxMsg::Type_Inquiry_Reply)
		{
			// will be managed by ownedarray or is to be deleted
			GrooveboxConnector::GrooveBoxConnectionEntry* newEntry = new GrooveboxConnector::GrooveBoxConnectionEntry();
			newEntry->deviceId = syxMsg->getInquiryReplyDevId();
			newEntry->manufactorId = syxMsg->getInquiryReplyManId();
			newEntry->deviceFamilyCode = syxMsg->getInquiryReplyDevFamCode();
			newEntry->deviceFamilyNumberCode = (GrooveboxModel) syxMsg->getInquiryReplyDevFamNumberCode();
			newEntry->softwareRevisionLevel = syxMsg->getInquiryReplySoftwareRevision();

			if (newEntry->manufactorId == SyxMsg::SYSEX_ROLAND_MANUFACTURER_ID &&
				newEntry->deviceFamilyCode == SyxMsg::SYSEX_GROOVEBOX_FAMILY_CODE &&
				newEntry->deviceFamilyNumberCode != Model_Unknown)
			{
				m_activeConnections.add(newEntry);
			}
			else
			{
				delete newEntry;
			}
		}
	}
	deleteAndZero(m_checkThread);
	// now that the active connections are known: which one to select?

	uint8 deviceIdToUse(0);
	if (m_activeConnections.size() > 0)
	{
		deviceIdToUse = (uint8) appProperties->getUserSettings()->getIntValue("DeviceId", 17) - 1;
		// if only one: automatically use this, if multiple: look for saved one. if not possible, use lowest one
		bool savedOneIsConnected(false);
		for (int i = 0; i < m_activeConnections.size(); i++)
		{
			if (m_activeConnections[i]->deviceId == deviceIdToUse) savedOneIsConnected = true;
			if (waveForms != nullptr) waveForms->reloadForModel(m_activeConnections[i]->deviceFamilyNumberCode);
		}
		// save the first one found
		if (!savedOneIsConnected)
		{
			deviceIdToUse = m_activeConnections[0]->deviceId;
			appProperties->getUserSettings()->setValue("DeviceId", deviceIdToUse);
			if (waveForms != nullptr) waveForms->reloadForModel(m_activeConnections[0]->deviceFamilyNumberCode);
		}
		m_selectedDeviceId = deviceIdToUse;
	}
	return deviceIdToUse;
}

void GrooveboxConnector::addConnection(GrooveBoxConnectionEntry* entry)
{
	m_activeConnections.add(entry);
}

uint8 GrooveboxConnector::getActiveDeviceId() { return m_selectedDeviceId; }
String GrooveboxConnector::getActiveDeviceIdAsString() { return String(m_selectedDeviceId + 1); }

GrooveboxConnector::GrooveBoxConnectionEntry* GrooveboxConnector::getActiveConnection()
{
	for (int i = 0; i < m_activeConnections.size(); i++)
	{
		if (m_selectedDeviceId == m_activeConnections[i]->deviceId) return m_activeConnections[i];
	}
	return nullptr;
}

GrooveboxConnector::GrooveboxModel GrooveboxConnector::getActiveConnectionGrooveboxModel()
{
	GrooveBoxConnectionEntry* activeConnection = getActiveConnection();
	return (activeConnection == nullptr) ? Model_Unknown : activeConnection->deviceFamilyNumberCode;
}

void GrooveboxConnector::handleIncomingMidiMessage(MidiInput* input, const MidiMessage& msg)
{
	if (m_checkThread != nullptr && m_checkThread->isThreadRunning())
	{
		// get responses
		m_checkThread->addMidiMessage(input, msg);
	}
	else if (input == midiInputDevice)
	{
		//DBG("Midi In Message from \"" + input->getName().trim() + "\": " + String::toHexString(msg.getRawData(), msg.getRawDataSize()).toUpperCase());
		// TODO CC, SYSEX, PC, Note, ...? Handling
		if (msg.isController())
		{
			grooveboxMemory->handleCCFromGroovebox((uint8)msg.getChannel(), (uint8)msg.getControllerNumber(), (uint8)msg.getControllerValue());	// cc to sysex memory parameters
		}
		else if (msg.isSysEx())
		{
			ScopedPointer<SyxMsg> syxMsg = new SyxMsg(msg);
			if (syxMsg->getDeviceId() == m_selectedDeviceId && syxMsg->isCheckSumOkay())
			{
				if (syxMsg->getType() == SyxMsg::Type_DT1)
				{
					grooveboxMemory->handleSysEx(syxMsg);
				}
				else if (syxMsg->getType() == SyxMsg::Type_DT1_Quick)
				{
					quickSysEx->handleSysEx(syxMsg);
				}
			}
		}
	}
}

GrooveboxConnector::MIDIRetrieveTimeOutTimer::MIDIRetrieveTimeOutTimer(RetrieveSysExThread* threadRef) :Timer()
{
	m_threadPtr = threadRef;
}

void GrooveboxConnector::MIDIRetrieveTimeOutTimer::timerCallback()
{
	// timer ran out, so the response might me received completely.
	// tell the thread to continue with next request
	m_threadPtr->callNextRequestEvent->signal();
	stopTimer();
}

GrooveboxConnector::RetrieveSysExThread::RetrieveSysExThread(OwnedArray<SyxMsg, CriticalSection>& requestSysExMessagesPtr, String windowTitle, int timeOutInMs) :
ThreadWithProgressWindow(windowTitle, true, false, timeOutInMs),
m_retrieveTimeout(timeOutInMs),
m_timeoutTimer(new MIDIRetrieveTimeOutTimer(this)),
callNextRequestEvent(new WaitableEvent())
{
	// copy request messages
	for (int i = 0; i < requestSysExMessagesPtr.size(); i++)
	{
		m_requestMessages.add(requestSysExMessagesPtr[i]->copyToNew());
	}
	setProgress(-1.0);
}


GrooveboxConnector::RetrieveSysExThread::RetrieveSysExThread(SyxMsg* requestSysExMessagePtr, String windowTitle, int timeOutInMs) :
ThreadWithProgressWindow(windowTitle, true, false, timeOutInMs),
m_retrieveTimeout(timeOutInMs),
m_timeoutTimer(new MIDIRetrieveTimeOutTimer(this)),
callNextRequestEvent(new WaitableEvent())
{
	m_requestMessages.add(requestSysExMessagePtr->copyToNew());
	setProgress(-1.0);
}

GrooveboxConnector::RetrieveSysExThread::~RetrieveSysExThread()
{
}

void GrooveboxConnector::RetrieveSysExThread::run()
{
	if (midiOutputDevice != nullptr && midiInputDevice != nullptr)
	{
		m_retrievedSysExMessages.clear();
		midiInputDevice->start();

		while (m_requestMessages.size() > 0 && !threadShouldExit())
		{

			// send inquiry request broadcast out
			SyxMsg* currentRequest = m_requestMessages.getFirst();
			midiOutputDevice->sendMessageNow(currentRequest->getAsMidiMessage());
			m_requestMessages.removeObject(currentRequest, true);
			// now rest in loop until exit is signalled by external timer, triggered by handleIncomingMidiMessage
			m_timeoutTimer->startTimer(m_retrieveTimeout);
			// wait till timer signals
			callNextRequestEvent->wait();

			// { ... }

			// after timeout, continue:

			// 
			if (m_requestMessages.size() == 0)
			{
				signalThreadShouldExit();
			}
			// else if more m_requestMessages left, continue(request next, restart timer...)
		}
	}
	else return;
}

void GrooveboxConnector::RetrieveSysExThread::addMidiMessage(MidiInput *midiIn, const MidiMessage &midiInMsg)
{
	if (midiIn == midiInputDevice && midiInMsg.isSysEx())
	{
		SyxMsg* syxMsg = new SyxMsg(midiInMsg.getSysExData(), midiInMsg.getSysExDataSize());
		//DBG("Retrieved " + String::toHexString(midiInMsg.getRawData(), midiInMsg.getRawDataSize()));
		// reset timeout
		m_timeoutTimer->startTimer(m_retrieveTimeout);
		// collect incoming sysex into an array, where he caller can get them from after the tread finished
		m_retrievedSysExMessages.add(syxMsg);
	}
}