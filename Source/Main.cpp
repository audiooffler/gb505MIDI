/*
  ==============================================================================

    This file was auto-generated by the Introjucer!

    It contains the basic startup code for a Juce application.

  ==============================================================================
*/

#include "JuceHeader.h"
#include "GUI/MainWindow.h"
#include "GUI/GrooveboxLookAndFeel.h"
#include "GrooveboxMemory/OverallMemoryBlock.h"
#include "GrooveboxMemory/QuickSysExBlock.h"
#include "GrooveboxMemory/Waveforms.h"
#include "MIDIConnection/GrooveboxConnector.h"
#include "GUI/GrooveboxSplashScreen.h"
#include "GrooveboxMemory/CopyableTone.h"
//#include <vld.h> 

ApplicationProperties* appProperties = nullptr;
std::unique_ptr<MidiInput> midiInputDevice (nullptr);
std::unique_ptr<MidiOutput> midiOutputDevice ( nullptr);
int preferredMidiInId=-1;
int preferredMidiOutId = -1;
GrooveboxConnector* grooveboxConnector = nullptr;
UndoManager* undoManager = nullptr;
OverallMemoryBlock* grooveboxMemory = nullptr;
QuickSysExBlock* quickSysEx = nullptr;
Waveforms* waveForms = nullptr;
ApplicationCommandManager* applicationCommandManager = nullptr;
CopyableTone* copyableToneClipboad = nullptr;

//==============================================================================
class MC307SysExApplication  : public JUCEApplication
{
public:
    //==============================================================================
    MC307SysExApplication() {}

    const String getApplicationName()       { return ProjectInfo::projectName; }
    const String getApplicationVersion()    { return ProjectInfo::versionString; }
    bool moreThanOneInstanceAllowed()       { return true; }

    //==============================================================================
    void initialise (const String& /*commandLine*/)
    {
#ifdef JUCE_WINDOWS
		_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#endif
		//_CrtSetBreakAlloc(9554);
		//_CrtSetBreakAlloc(9553);
		//_CrtSetBreakAlloc(9552);

        // This method is where you should put your application's initialisation code..

		#if JUCE_OPENGL
		openGlContext = new OpenGLContext();
		#endif

		splashScreen = new GrooveboxSplashScreen("STARTING UP " + String(getApplicationName()) + String(CharPointer_UTF8("\xe2\x80\xa6")), 480, 320, true);

		applicationCommandManager = new ApplicationCommandManager();
		applicationCommandManager->registerAllCommandsForTarget(this);
		appProperties = new ApplicationProperties();
		PropertiesFile::Options options;
		options.applicationName = getApplicationName();
        options.osxLibrarySubFolder = "Application Support";
		appProperties->setStorageParameters(options);
		undoManager = new UndoManager();
		midiInputDevice = nullptr;
		midiOutputDevice = nullptr;
		preferredMidiInId = (appProperties->getUserSettings()->getIntValue("MidiInId", MidiInput::getDefaultDeviceIndex()));
		preferredMidiOutId = (appProperties->getUserSettings()->getIntValue("MidiOutId", MidiOutput::getDefaultDeviceIndex()));
		grooveboxConnector = new GrooveboxConnector();
		grooveboxMemory = /*nullptr;*/ new OverallMemoryBlock();
		quickSysEx = new QuickSysExBlock();
		Thread::sleep(500);
		waveForms = new Waveforms((grooveboxConnector->getActiveConnection() != nullptr) ?
			grooveboxConnector->getActiveConnection()->deviceFamilyNumberCode :
			GrooveboxConnector::Model_Unknown);
		lookAndFeel = new GrooveboxLookAndFeel();
		LookAndFeel::setDefaultLookAndFeel(lookAndFeel);
        mainWindow = new MainWindow();
		mainWindow->setResizable(true,true);
		toolTipWindow = new TooltipWindow();
		mainWindow->getContentComponent()->grabKeyboardFocus();
		splashScreen = nullptr;
#if JUCE_OPENGL
		if (openGlContext != nullptr) openGlContext->attachTo(*mainWindow);
#endif
    }

    void shutdown()
    {
		if (copyableToneClipboad != nullptr) deleteAndZero(copyableToneClipboad);
        // Add your application's shutdown code here..
#if JUCE_OPENGL
		if (openGlContext != nullptr) openGlContext->detach();
		openGlContext=nullptr;
#endif
		splashScreen = nullptr;
		mainWindow = nullptr; // (deletes our window)
		lookAndFeel = nullptr;
		appProperties->saveIfNeeded();
		deleteAndZero(appProperties);
		//if (midiInputDevice != nullptr) deleteAndZero(midiInputDevice);
		//if (midiOutputDevice != nullptr) deleteAndZero(midiOutputDevice);
		toolTipWindow = nullptr;
		deleteAndZero(undoManager);
		deleteAndZero(grooveboxConnector);
		if (quickSysEx != nullptr) deleteAndZero(quickSysEx);
		if (waveForms != nullptr) deleteAndZero(waveForms);
		if (grooveboxMemory != nullptr) deleteAndZero(grooveboxMemory);
		if (applicationCommandManager != nullptr) deleteAndZero(applicationCommandManager);
		splashScreen = nullptr;
		// deletes itself, dont uncomment this!: deleteAndZero(splashScreen);
    }

    //==============================================================================
    void systemRequestedQuit()
    {
        // This is called when the app is being asked to quit: you can ignore this
        // request and let the app carry on running, or call quit() to allow the app to close.
        quit();
    }

    void anotherInstanceStarted (const String& /*commandLine*/)
    {
        // When another instance of the app is launched while this one is running,
        // this method is invoked, and the commandLine parameter tells you what
        // the other instance's command-line arguments were.
    }

    
private:
    ScopedPointer<MainWindow> mainWindow;
	ScopedPointer<GrooveboxLookAndFeel> lookAndFeel;
	ScopedPointer<OpenGLContext> openGlContext = nullptr;
	ScopedPointer<GrooveboxSplashScreen> splashScreen = nullptr;
	ScopedPointer<TooltipWindow> toolTipWindow = nullptr;
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(MC307SysExApplication);
};

//==============================================================================
// This macro generates the main() routine that launches the app.
START_JUCE_APPLICATION (MC307SysExApplication)
