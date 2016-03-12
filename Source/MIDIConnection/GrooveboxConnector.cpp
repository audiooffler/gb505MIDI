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
	m_checkThread(nullptr),
	m_sendBulkDumpThread(nullptr)
{
}

GrooveboxConnector::~GrooveboxConnector()
{
	m_activeConnections.clear();
	m_sendBulkDumpThread = nullptr;
	/*if (m_checkThread != nullptr)
	{
		m_checkThread->waitForThreadToExit(50);
		delete m_checkThread;
	}
	if (m_sendBulkDumpThread != nullptr)
	{
		if (m_sendBulkDumpThread->isThreadRunning()) m_sendBulkDumpThread->stopThread(50);
		delete m_sendBulkDumpThread;
	}*/
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

int GrooveboxConnector::refreshConnections(bool warnMsgBox /*=true*/, int timeOutMilliseconds /*= 10000*/)
{
	{
		m_activeConnections.clear();
	}
	
	// (re)open midi in and out
	if (!openGrooveboxMidiInAndOut(warnMsgBox)) return 0;

	// Thread with progress Window: send broadcast sysex and wait for replys, stop after timeout (waiting long enough without any more replies)
	// use a MidiMessageCollector handler during running thread
	
	m_checkThread = new IndenityRequestReplyThread(TRANS("Searching connected Groovebox..."), timeOutMilliseconds);
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
	else if (m_recvBulkDumpThread != nullptr && m_recvBulkDumpThread->isThreadRunning() && input == midiInputDevice)
	{
		m_recvBulkDumpThread->addReceivedMidiMessage(msg);
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

bool GrooveboxConnector::receiveDump()
{
	if (getActiveConnection() == nullptr) return false;

	String helpText;
	switch (getActiveConnection()->deviceFamilyNumberCode)
	{
	case Model_MC_505:
		helpText = "Make sure your Groovebox is stopped. Select the tempo pattern (U:TMP).\r\n"
			"Hold [SHIFT], press key-pad [16]. Select \"SEND\" and the type of data you want to transmit from the groovebox.";
		break;
	case Model_JX_305:
		helpText = "Select the temporary pattern (TMP). Make sure the Pattern is stopped.\r\n."
			"Press [UTILITY], select \"BULK DUMP\", press [ENTER]. Select \"SEND\" and and the type of data you want to transmit from the groovebox.";
		break;
	case Model_MC_307:
		helpText = "Make sure your Groovebox is stopped.\r\n"
			"Press the [SYSTEM], then [F2 (UTIL)], then [F3 (BULK)]. Select [F1 (TX)] and and the type of data you want to transmit from the groovebox.";
		break;
	case Model_D2:
		helpText = "Make sure your Groovebox is stopped.\r\n"
			"Press[SYSTEM] several times to access the MIDI reception setting display (RX LED).\r\n"
			"Press [ENTER] several times to access the Bulk Dump setting display (dMP).\r\n"
			"Turn [VALUE] to select \"Ptn\" and press [ENTER].";
		break;
	default:
		return false;
	}
	m_recvBulkDumpThread = new RecvBulkDumpThread();
	m_recvBulkDumpThread->setStatusMessage(helpText);
	m_recvBulkDumpThread->launchThread();
	return true;
}

bool GrooveboxConnector::sendPatchesPatternAndSetupAsDump()
{
	if (getActiveConnection() == nullptr) return false;
	
	String helpText;
	switch (getActiveConnection()->deviceFamilyNumberCode)
	{
	case Model_MC_505: 
		helpText = "Make sure your Groovebox is stopped. Select the tempo pattern (U:TMP).\r\n"
			"Hold [SHIFT], press key-pad [16]. Select \"RECEIVE\"."; 
		break;
	case Model_JX_305: 
		helpText = "Select the temporary pattern (TMP). Make sure the Pattern is stopped.\r\n."
			"Press [UTILITY], select \"BULK DUMP\", press [ENTER]. Select \"RECEIVE\" and press [ENTER]."; 
		break;
	case Model_MC_307: 
		helpText = "Make sure your Groovebox is stopped.\r\n"
			"Press the [SYSTEM], then [F2 (UTIL)], then [F3 (BULK)]. Select [F2 (RX)]."; 
		break;
	case Model_D2: 
		helpText = "Make sure your Groovebox is stopped.\r\n"
			"Press[SYSTEM] several times to access the MIDI reception setting display (RX LED).\r\n"
			"Press [ENTER] several times to access the Bulk Load setting display (rcY).\r\n"
			"Turn [VALUE] to select \"Ptn\" and press [ENTER]."; 
		break;
	default:
		return false;
	}
	midiOutputDevice->sendMessageNow(MidiMessage::midiStop());
	if (AlertWindow::showOkCancelBox(AlertWindow::QuestionIcon, "Transmit Bulk Dump?",
		"Please prepare your Groovebox to wait for receiving a bulk dump (BULK RX):\r\n\r\n"
		+ helpText + "\r\n\r\n" +
		"Continue by pressing OK."))
	{
		m_sendBulkDumpThread = new SendBulkDumpThread();
		// feed thread data
		grooveboxMemory->getPartInfoBlock()->createBlockSendMessages(m_sendBulkDumpThread->getSysExCompilationPtr());
		grooveboxMemory->getSynthPatchesBlock()->createBlockSendMessages(m_sendBulkDumpThread->getSysExCompilationPtr());
		grooveboxMemory->getRhythmSetBlock()->createBlockSendMessages(m_sendBulkDumpThread->getSysExCompilationPtr());
		grooveboxMemory->getPatternBodyBlock()->createBlockSendMessages(m_sendBulkDumpThread->getSysExCompilationPtr());
		grooveboxMemory->getPatternSetupBlock()->createBlockSendMessages(m_sendBulkDumpThread->getSysExCompilationPtr());
		m_sendBulkDumpThread->launchThread();
		return true;
	}
	else return false;
}

GrooveboxConnector::MIDIRetrieveTimeOutTimer::MIDIRetrieveTimeOutTimer(IndenityRequestReplyThread* threadRef) :Timer()
{
	m_threadPtr = threadRef;
}

void GrooveboxConnector::MIDIRetrieveTimeOutTimer::timerCallback()
{
	// timer ran out, so the response might me received completely.
	// tell the thread to continue with next request
	stopTimer();
	m_threadPtr->stopThread(100);
}

GrooveboxConnector::IndenityRequestReplyThread::IndenityRequestReplyThread(String windowTitle, int timeOutInMs) :
	ThreadWithProgressWindow(windowTitle, true, true, timeOutInMs),
	inquiry (new SyxMsg(SyxMsg::Type_Inquiry_Request)),
	m_retrieveTimeout(timeOutInMs),
	m_timeoutTimer(new MIDIRetrieveTimeOutTimer(this))
{
	setProgress(-1.0);
}

GrooveboxConnector::IndenityRequestReplyThread::~IndenityRequestReplyThread()
{
}

void GrooveboxConnector::IndenityRequestReplyThread::run()
{
	if (midiOutputDevice != nullptr && midiInputDevice != nullptr)
	{
		m_retrievedSysExMessages.clear();
		midiInputDevice->start();

		// send request:
		midiOutputDevice->sendMessageNow(inquiry->getAsMidiMessage());

		// now rest in loop until exit is signalled by external timer, triggered by handleIncomingMidiMessage
		m_timeoutTimer->startTimer(m_retrieveTimeout);
		while (m_retrievedSysExMessages.size() == 0 && !threadShouldExit())
		{
			// wait till timer signals
			wait(500);
			// repeat inquiry
			if (m_retrievedSysExMessages.size() == 0) midiOutputDevice->sendMessageNow(inquiry->getAsMidiMessage());
			wait(500);
		}
	}
	else return;
}

void GrooveboxConnector::IndenityRequestReplyThread::threadComplete(bool userPressedCancel)
{
	if (userPressedCancel)
	{
	}
}

void GrooveboxConnector::IndenityRequestReplyThread::addMidiMessage(MidiInput *midiIn, const MidiMessage &midiInMsg)
{
	if (midiIn == midiInputDevice && midiInMsg.isSysEx())
	{
		SyxMsg* syxMsg = new SyxMsg(midiInMsg.getSysExData(), midiInMsg.getSysExDataSize());
		//DBG("Retrieved " + String::toHexString(midiInMsg.getRawData(), midiInMsg.getRawDataSize()));
		// reset timeout
		m_timeoutTimer->startTimer(m_retrieveTimeout);
		// collect incoming sysex into an array, where the caller can get them from after the tread finished
		m_retrievedSysExMessages.add(syxMsg);
		signalThreadShouldExit();
	}
}

GrooveboxConnector::SendBulkDumpThread::SendBulkDumpThread()
	: ThreadWithProgressWindow("Transmitting Bulk Dump to Groovebox...", true, true)
{

}

GrooveboxConnector::SendBulkDumpThread::~SendBulkDumpThread()
{
	sysExCompilation.clear();
}

void GrooveboxConnector::SendBulkDumpThread::run()
{
	setProgress(0.0);
	for (int i = 0; i < sysExCompilation.size() && !threadShouldExit(); i++)
	{
		midiOutputDevice->sendMessageNow(sysExCompilation[i]->getAsMidiMessage());
		setProgress(((double)i + 1.0) / (double)sysExCompilation.size());
		Thread::wait(40);
	}
}

void GrooveboxConnector::SendBulkDumpThread::threadComplete(bool userPressedCancel)
{
	if (userPressedCancel)
	{

	}
	sysExCompilation.clear();
}

GrooveboxConnector::RecvBulkDumpThread::RecvBulkDumpThread()
	: ThreadWithProgressWindow("Receiving Bulk Dump from Groovebox...", true, true)
{
	m_timeoutTimer = new TimeOutTimer(this);
}

GrooveboxConnector::RecvBulkDumpThread::~RecvBulkDumpThread()
{
	sysExCompilation.clear();
}

void GrooveboxConnector::RecvBulkDumpThread::run()
{
	setProgress(0.0);
	while (!threadShouldExit())
	{
		wait(20);
	}
}

void GrooveboxConnector::RecvBulkDumpThread::addReceivedMidiMessage(const MidiMessage& msg)
{
	if (msg.isSysEx())
	{
		sysExCompilation.add(new SyxMsg(msg));
		setStatusMessage("");
		setProgress(sysExCompilation.size()/200.0);
		if (TextButton* button = dynamic_cast<TextButton*>(getAlertWindow()->findChildWithID(TRANS("Cancel"))))
		{
			button->setEnabled(false);
			button->setVisible(false);
		}
		getAlertWindow()->setEscapeKeyCancels(false);

		m_timeoutTimer->startTimer(2500);
	}
}

void GrooveboxConnector::RecvBulkDumpThread::threadComplete(bool userPressedCancel)
{
	if (userPressedCancel)
	{
		sysExCompilation.clear();
	}
	else
	{
		grooveboxMemory->loadFromArray(sysExCompilation);
	}
}

GrooveboxConnector::RecvBulkDumpThread::TimeOutTimer::TimeOutTimer(GrooveboxConnector::RecvBulkDumpThread* bulkDumpThread) :
	juce::Timer(),
	m_bulkDumpThread(bulkDumpThread)
{

}

void GrooveboxConnector::RecvBulkDumpThread::TimeOutTimer::timerCallback()
{
	m_bulkDumpThread->signalThreadShouldExit();
}