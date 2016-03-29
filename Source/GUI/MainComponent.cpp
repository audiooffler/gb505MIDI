/*
  ==============================================================================

  This is an automatically generated GUI class created by the Introjucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Introjucer version: 4.1.0

  ------------------------------------------------------------------------------

  The Introjucer is part of the JUCE library - "Jules' Utility Class Extensions"
  Copyright (c) 2015 - ROLI Ltd.

  ==============================================================================
*/

//[Headers] You can add your own extra header files here...
#include "MixerTab.h"
#include "SystemTab.h"
#include "RhythmSetEditorTab.h"
#include "PatchEditor.h"
#include "MidiLoggerTab.h"
#include "PatternEditorTab.h"
#include "GrooveboxSplashScreen.h"
#include "../GrooveboxMemory/OverallMemoryBlock.h"
//[/Headers]

#include "MainComponent.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
extern ApplicationCommandManager*  applicationCommandManager;
extern OverallMemoryBlock* grooveboxMemory;
//[/MiscUserDefs]

//==============================================================================
MainComponent::MainComponent ()
    : TabbedComponentWithMenu()
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]


    //[UserPreSize]
	Colour tabGrey = Colour(0xD6, 0xDA, 0xDD);

	addTab(TRANS("System"), tabGrey, new SystemTab(), true);
	addTab(TRANS("Pattern"), tabGrey, new PatternEditorTab(), true);
	addTab(TRANS("Mixer"), tabGrey, new MixerTab(), true);
	CustomViewport* rhythmSetViewPort = new CustomViewport("RhythmSetEditor");
	rhythmSetViewPort->setViewedComponent(new RhythmSetEditorTab(), true);
	addTab(TRANS("Rhythm Set PART R"), tabGrey, rhythmSetViewPort, true);
	SynthParts part(SynthPart1);
	String partNameString;
	for (int p = (int)SynthPart1; p <= (int)SynthPart7; p++)
	{
		part = (SynthParts)p;
		partNameString = "Patch PART "+String(p+1);
		CustomViewport* patchPartViewPort = new CustomViewport(partNameString);
		patchPartViewPort->setViewedComponent(new PatchEditor(part), true);
		addTab(partNameString, tabGrey, patchPartViewPort, true);
	}
	
	MidiLoggerTab* loggerTab = new MidiLoggerTab();
	Logger::setCurrentLogger(loggerTab);
	addTab(TRANS("MIDI Logger"), tabGrey, loggerTab, true);

	getMenuButton()->setTriggeredOnMouseDown(true);
	getMenuButton()->addListener(this);

	setCurrentTabIndex(2, false);

    //[/UserPreSize]

    setSize (640, 480);


    //[Constructor] You can add your own custom stuff here..
	// This registers all of our commands with the command manager but has to be done after the window has
	// been created so we can find the number of rendering engines available
	applicationCommandManager->registerAllCommandsForTarget(this);
	//applicationCommandManager->setFirstCommandTarget(this);

	for (int i = 0; i < getNumTabs(); i++)
	{
		if (ApplicationCommandTarget* appCmdTarget = dynamic_cast<ApplicationCommandTarget*>(getTabContentComponent(i)))
		{
			/*applicationCommandManager->setFirstCommandTarget(appCmdTarget);*/
			applicationCommandManager->registerAllCommandsForTarget(appCmdTarget);
		}
	}

	// this lets the command manager use keypresses that arrive in our window to send out commands
	addKeyListener(applicationCommandManager->getKeyMappings());

    //[/Constructor]
}

MainComponent::~MainComponent()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]



    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void MainComponent::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
	TabbedComponentWithMenu::paint(g);
    //[/UserPrePaint]

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void MainComponent::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    //[UserResized] Add your own custom resize handling here..
	TabbedComponentWithMenu::resized();
    //[/UserResized]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...

//void MainComponent::currentTabChanged(int newCurrentTabIndex, const String &newCurrentTabName)
//{
//	TabbedComponentWithMenu::currentTabChanged(newCurrentTabIndex, newCurrentTabName);
//	if (ApplicationCommandTarget* appCmdTarget = dynamic_cast<ApplicationCommandTarget*>(getCurrentContentComponent()))
//	{
//		/*applicationCommandManager->setFirstCommandTarget(appCmdTarget);*/
//		applicationCommandManager->registerAllCommandsForTarget(appCmdTarget);
//	}
//}

//==============================================================================
// The following methods implement the ApplicationCommandTarget interface, allowing
// this window to publish a set of actions it can perform, and which can be mapped
// onto menus, keypresses, etc.

ApplicationCommandTarget* MainComponent::getNextCommandTarget()
{
	// this will return the next parent component that is an ApplicationCommandTarget (in this
	// case, there probably isn't one, but it's best to use this method in your own apps).
	if (ApplicationCommandTarget* foundTarget = findFirstTargetParentComponent())
	{
		return foundTarget;
	}
	else return dynamic_cast<ApplicationCommandTarget*>(JUCEApplication::getInstance());
}

void MainComponent::getAllCommands(Array <CommandID>& commands)
{
	// this returns the set of all commands that this target can perform..
	const CommandID ids[] = {
		CommandIDs::createEmptyPattern,
		/* ---------------------- */
		CommandIDs::fileOpenPattern,
		CommandIDs::fileSavePattern,
		/* ---------------------- */
		CommandIDs::fileSavePatternBinFile,
		/* ---------------------- */
		CommandIDs::grooveBoxLoadPattern,
		CommandIDs::grooveBoxRecvPatternBulk,
		CommandIDs::grooveBoxSendPatternBulk,
		/* ---------------------- */
			CommandIDs::gotoSystemTab,
			CommandIDs::gotoPatternEditorTab,
			CommandIDs::gotoMixerTab,
			CommandIDs::gotoPart1Tab,
			CommandIDs::gotoPart2Tab,
			CommandIDs::gotoPart3Tab,
			CommandIDs::gotoPart4Tab,
			CommandIDs::gotoPart5Tab,
			CommandIDs::gotoPart6Tab,
			CommandIDs::gotoPart7Tab,
			CommandIDs::gotoPartRTab,
		/* ---------------------- */
		CommandIDs::showInfo
	};
	commands.addArray(ids, numElementsInArray(ids));
}

void MainComponent::getCommandInfo(CommandID commandID, ApplicationCommandInfo& result)
{
	const String gotoTabCategory("Tabs");

	switch (commandID)
	{
	case createEmptyPattern:
		result.setInfo("New empty pattern", "Clears the pattern data", "Pattern", 0);
		result.addDefaultKeypress('n', ModifierKeys::commandModifier);
		result.setActive(!grooveboxMemory->getPatternBodyBlock()->isPatternEmpty());
		break;
	case fileOpenPattern:
		result.setInfo("Open Pattern File...", "Opens a pattern file, either a standard MIDI File (.mid), a binary SysEx (.syx) or Hex SysEx text (.txt)", "Pattern", 0);
		result.addDefaultKeypress('o', ModifierKeys::commandModifier);
		break;
	case fileSavePattern:
		result.setInfo("Save Pattern...", "Saves a pattern file, either as Standard MIDI File (.mid), a binary SysEx (.syx) or Hex SysEx text (.txt)", "Pattern", 0);
		result.addDefaultKeypress('s', ModifierKeys::commandModifier);
		result.setActive(!grooveboxMemory->getPatternBodyBlock()->isPatternEmpty());
		break;
	case fileSavePatternBinFile:
		result.setInfo("Export Pattern as Binary...", "Saves the raw decoded pattern events as8 bytes a 8bit binary (.bin)", "Pattern", 0);
		result.addDefaultKeypress('s', ModifierKeys::commandModifier | ModifierKeys::shiftModifier | ModifierKeys::altModifier);
		result.setActive(!grooveboxMemory->getPatternBodyBlock()->isPatternEmpty());
		break;
	case grooveBoxLoadPattern:
		result.setInfo("Send Pattern Request SysEx", "Request temporary pattern data from groovebox.", "Pattern", 0);
		//result.addDefaultKeypress('r', ModifierKeys::commandModifier);
		result.setActive(grooveboxConnector->getActiveConnection() != nullptr);
		break;
	case grooveBoxRecvPatternBulk:
		result.setInfo("Receive Pattern Bulk Dump", "Receive patches, pattern, and / or setup data of temporary pattern from the groovebox.", "Pattern", 0);
		//result.addDefaultKeypress('r', ModifierKeys::commandModifier);
		result.setActive(grooveboxConnector->getActiveConnection() != nullptr);
		break;
	case grooveBoxSendPatternBulk:
		result.setInfo("Transmit Pattern Bulk Dump", "Send patches, pattern, and setup data of temporary pattern to groovebox.", "Pattern", 0);
		//result.addDefaultKeypress('t', ModifierKeys::commandModifier);
		result.setActive(grooveboxConnector->getActiveConnection() != nullptr && !grooveboxMemory->getPatternBodyBlock()->isPatternEmpty());
		break;
	case CommandIDs::gotoSystemTab:
		result.setInfo("System", "Opens the system preferences", gotoTabCategory, 0);
		result.addDefaultKeypress('p', ModifierKeys::commandModifier);
		break;
	case CommandIDs::gotoPatternEditorTab:
		result.setInfo("Pattern Editor", "Opens the pattern event table", gotoTabCategory, 0);
		result.addDefaultKeypress('e', ModifierKeys::commandModifier);
		break;
	case CommandIDs::gotoMixerTab:
		result.setInfo("Mixer", "Opens the mixer panel", gotoTabCategory, 0);
		result.addDefaultKeypress('m', ModifierKeys::commandModifier);
		break;
	case CommandIDs::gotoPartRTab:
		result.setInfo("Part R", "Opens the patch editor for part R", gotoTabCategory, 0);
		result.addDefaultKeypress('r', ModifierKeys::commandModifier);
		break;
	case CommandIDs::gotoPart1Tab:
		result.setInfo("Part 1", "Opens the patch editor for part 1", gotoTabCategory, 0);
		result.addDefaultKeypress('1', ModifierKeys::commandModifier);
		break;
	case CommandIDs::gotoPart2Tab:
		result.setInfo("Part 2", "Opens the patch editor for part 2", gotoTabCategory, 0);
		result.addDefaultKeypress('2', ModifierKeys::commandModifier);
		break;
	case CommandIDs::gotoPart3Tab:
		result.setInfo("Part 3", "Opens the patch editor for part 3", gotoTabCategory, 0);
		result.addDefaultKeypress('3', ModifierKeys::commandModifier);
		break;
	case CommandIDs::gotoPart4Tab:
		result.setInfo("Part 4", "Opens the patch editor for part 4", gotoTabCategory, 0);
		result.addDefaultKeypress('4', ModifierKeys::commandModifier);
		break;
	case CommandIDs::gotoPart5Tab:
		result.setInfo("Part 5", "Opens the patch editor for part 5", gotoTabCategory, 0);
		result.addDefaultKeypress('5', ModifierKeys::commandModifier);
		break;
	case CommandIDs::gotoPart6Tab:
		result.setInfo("Part 6", "Opens the patch editor for part 6", gotoTabCategory, 0);
		result.addDefaultKeypress('6', ModifierKeys::commandModifier);
		break;
	case CommandIDs::gotoPart7Tab:
		result.setInfo("Part 7", "Opens the patch editor for part 7", gotoTabCategory, 0);
		result.addDefaultKeypress('7', ModifierKeys::commandModifier);
		break;
	case CommandIDs::showInfo:
		result.setInfo("Info", "Show info about this application", "info", 0);
		result.addDefaultKeypress('i', ModifierKeys::commandModifier);
		break;
	default:
		break;
	}

}

bool MainComponent::perform(const InvocationInfo& info)
{
	PatternEditorTab* editorTab = dynamic_cast<PatternEditorTab*>(getTabContentComponent(2));
	switch (info.commandID)
	{
	case CommandIDs::createEmptyPattern:
		grooveboxMemory->getPatternBodyBlock()->getPlayerThread()->signalThreadShouldExit();
		grooveboxMemory->initAll(grooveboxMemory);
		editorTab->newPattern();
		return true;
	case CommandIDs::fileOpenPattern:
		grooveboxMemory->getPatternBodyBlock()->getPlayerThread()->signalThreadShouldExit();
		editorTab->loadPatternFile();
		return true;
	case CommandIDs::fileSavePattern:
		editorTab->savePatternFile();
		return true;
	case CommandIDs::fileSavePatternBinFile:
		editorTab->saveRawBinaryFile();
		return true;
	case CommandIDs::grooveBoxLoadPattern:
		//loadFromGroovebox();
		return true;
	case CommandIDs::grooveBoxRecvPatternBulk:
		grooveboxMemory->getPatternBodyBlock()->getPlayerThread()->signalThreadShouldExit();
		grooveboxConnector->receiveDump();
		return true;
	case CommandIDs::grooveBoxSendPatternBulk:
		grooveboxMemory->getPatternBodyBlock()->getPlayerThread()->signalThreadShouldExit();
		grooveboxConnector->sendPatchesPatternAndSetupAsDump();
		return true;
	case CommandIDs::gotoSystemTab:
		setCurrentTabIndex(1, true);
		break;
	case CommandIDs::gotoPatternEditorTab:
		setCurrentTabIndex(2, true);
		break;
	case CommandIDs::gotoMixerTab:
		setCurrentTabIndex(3, true);
		break;
	case CommandIDs::gotoPartRTab:
		setCurrentTabIndex(4, true);
		break;
	case CommandIDs::gotoPart1Tab:
		setCurrentTabIndex(5, true);
		break;
	case CommandIDs::gotoPart2Tab:
		setCurrentTabIndex(6, true);
		break;
	case CommandIDs::gotoPart3Tab:
		setCurrentTabIndex(7, true);
		break;
	case CommandIDs::gotoPart4Tab:
		setCurrentTabIndex(8, true);
		break;
	case CommandIDs::gotoPart5Tab:
		setCurrentTabIndex(9, true);
		break;
	case CommandIDs::gotoPart6Tab:
		setCurrentTabIndex(10, true);
		break;
	case CommandIDs::gotoPart7Tab:
		setCurrentTabIndex(11, true);
		break;
	case CommandIDs::showInfo:
		showInfoDlg();
		break;
	default:
		return false;
	}
return true;
}

Drawable* MainComponent::getDrawableForCommand(CommandID commandID, bool inactive /*=false*/)
{
	Image img;
	switch (commandID)
	{
	case CommandIDs::createEmptyPattern:
		img = ImageCache::getFromMemory(new_png, new_pngSize);
		break;
	case CommandIDs::fileOpenPattern:
		img = ImageCache::getFromMemory(open_png, open_pngSize);
		break;
	case CommandIDs::fileSavePattern:
		img = ImageCache::getFromMemory(save_png, save_pngSize);
		break;
	case CommandIDs::grooveBoxLoadPattern:
		img = ImageCache::getFromMemory(midiIn_png, midiIn_pngSize);
		break;
	case CommandIDs::grooveBoxRecvPatternBulk:
		img = ImageCache::getFromMemory(midiIn_png, midiIn_pngSize);
		break;
	case CommandIDs::grooveBoxSendPatternBulk:
		img = ImageCache::getFromMemory(midiOut_png, midiOut_pngSize);
		break;
	default:
		break;
	}
	if (!img.isNull())
	{
		DrawableImage* drawable = new DrawableImage;
		if (inactive) img.multiplyAllAlphas(0.5);
		drawable->setImage(img);
		return drawable;
	}
	else return nullptr;
}

void MainComponent::buttonClicked(Button* buttonThatWasClicked)
{
	if (buttonThatWasClicked == getMenuButton())
	{
		PopupMenu menu;

		// load commands from current tab
		if (ApplicationCommandTarget* currentTabAsCommandTarget = dynamic_cast<ApplicationCommandTarget*>(getCurrentContentComponent()))
		{
			Array <CommandID> commandsOfCurrentTab;
			currentTabAsCommandTarget->getAllCommands(commandsOfCurrentTab);
			CommandID lastId = 0;
			for (CommandID* currentCommandPtr = commandsOfCurrentTab.begin(); currentCommandPtr < commandsOfCurrentTab.end(); currentCommandPtr++)
			{
				// add a separator if ids are not in strict row of incrementing +1
				if (lastId != 0 && (*currentCommandPtr - lastId) != 1)
					menu.addSeparator();
				menu.addCommandItem(applicationCommandManager, *currentCommandPtr);
				lastId = *currentCommandPtr;
			}
		}

		menu.addSeparator();
		PopupMenu gotoViewMenu;

		// load commands from main component (this)
		Array <CommandID> commandsOfMainComponent;
		getAllCommands(commandsOfMainComponent);
		CommandID lastId = 0;
		for (int i = 0; i < commandsOfMainComponent.size(); i++)
		{
			int currentCommand = commandsOfMainComponent[i];
			if (currentCommand >= gotoPart1Tab && currentCommand <= gotoPatternEditorTab)
			{
				gotoViewMenu.addCommandItem(applicationCommandManager, currentCommand);
			}
			else if (currentCommand != CommandIDs::showInfo)
			{
				// get command info to check if inactive
				ApplicationCommandInfo commandInfo(commandsOfMainComponent[i]);
				getCommandInfo(commandsOfMainComponent[i], commandInfo);

				// add a separator if ids are not in strict row of incrementing +1
				if (lastId != 0 && (commandsOfMainComponent[i] - lastId) != 1) menu.addSeparator();

				Drawable* icon = getDrawableForCommand(commandsOfMainComponent[i], (commandInfo.flags & ApplicationCommandInfo::isDisabled) == ApplicationCommandInfo::isDisabled);

				menu.addCommandItem(applicationCommandManager, commandsOfMainComponent[i], String::empty, icon);

				lastId = commandsOfMainComponent[i];
			}
		}

		menu.addSeparator();
		menu.addSubMenu("Go to view", gotoViewMenu);

		menu.addSeparator();

		menu.addCommandItem(applicationCommandManager, CommandIDs::showInfo, String::empty, Drawable::createFromImageData(info_png, info_pngSize));

		// quit command from application instance
		menu.addCommandItem(applicationCommandManager, StandardApplicationCommandIDs::quit, String::empty, Drawable::createFromImageData(quit_png, quit_pngSize));

		menu.showMenuAsync(PopupMenu::Options().withTargetComponent(buttonThatWasClicked).withMaximumNumColumns(2), nullptr);
	}
}

void MainComponent::showInfoDlg()
{
	GrooveboxSplashScreen* splashScreen = new GrooveboxSplashScreen("", 480, 320, true);
	OptionalScopedPointer<Component> splashScreenPtr(splashScreen, true);
	DialogWindow::LaunchOptions options;
	options.dialogTitle = JUCEApplication::getInstance()->getApplicationName();
	options.content = splashScreenPtr;
	options.escapeKeyTriggersCloseButton = true;
	options.resizable = false;
	options.launchAsync();

}
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Introjucer information section --

    This is where the Introjucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="MainComponent" componentName=""
                 parentClasses="public TabbedComponentWithMenu, public ApplicationCommandTarget, public Button::Listener"
                 constructorParams="" variableInitialisers="TabbedComponentWithMenu()"
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="0" initialWidth="640" initialHeight="480">
  <BACKGROUND backgroundColour="0"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif

//==============================================================================
// Binary resources - be careful not to edit any of these sections!

// JUCER_RESOURCE: new_png, 383, "../../Resources/MenuIcons/new.png"
static const unsigned char resource_MainComponent_new_png[] = { 137,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,0,32,0,0,0,32,8,6,0,0,0,115,122,122,244,0,0,0,4,115,66,73,84,8,8,8,8,124,8,100,136,0,0,
0,9,112,72,89,115,0,0,27,175,0,0,27,175,1,94,26,145,28,0,0,0,25,116,69,88,116,83,111,102,116,119,97,114,101,0,119,119,119,46,105,110,107,115,99,97,112,101,46,111,114,103,155,238,60,26,0,0,0,252,73,68,
65,84,88,133,237,150,191,10,194,48,16,135,63,255,161,224,3,136,107,23,31,66,31,163,125,13,87,65,112,208,78,58,250,24,186,185,184,58,248,28,62,134,40,14,117,232,21,107,77,36,109,90,170,144,15,14,74,114,
151,251,133,220,53,1,135,195,97,135,39,86,27,7,177,194,180,45,5,116,44,227,105,26,250,13,129,32,199,186,190,196,148,38,96,2,236,128,208,192,55,4,246,192,216,112,109,99,150,64,4,108,82,99,71,177,132,149,
248,172,203,78,174,19,145,22,80,40,121,43,167,128,19,241,177,205,129,62,48,144,241,17,176,16,97,179,156,107,22,34,36,222,237,85,44,194,172,62,62,104,124,153,243,128,45,208,213,204,79,128,158,124,223,128,
179,198,239,14,76,129,139,106,210,180,11,126,142,210,142,160,8,233,106,79,186,64,213,162,149,39,135,247,54,172,92,132,170,207,179,63,162,202,68,4,168,207,57,43,0,94,245,225,151,41,64,119,25,169,4,64,142,
203,200,22,157,0,99,108,223,3,15,203,120,107,106,127,146,57,28,255,207,19,61,201,60,235,229,243,199,150,0,0,0,0,73,69,78,68,174,66,96,130,0,0};

const char* MainComponent::new_png = (const char*) resource_MainComponent_new_png;
const int MainComponent::new_pngSize = 383;

// JUCER_RESOURCE: open_png, 536, "../../Resources/MenuIcons/open.png"
static const unsigned char resource_MainComponent_open_png[] = { 137,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,0,32,0,0,0,32,8,6,0,0,0,115,122,122,244,0,0,0,4,115,66,73,84,8,8,8,8,124,8,100,136,0,
0,0,9,112,72,89,115,0,0,27,175,0,0,27,175,1,94,26,145,28,0,0,0,25,116,69,88,116,83,111,102,116,119,97,114,101,0,119,119,119,46,105,110,107,115,99,97,112,101,46,111,114,103,155,238,60,26,0,0,1,149,73,68,
65,84,88,133,237,214,61,75,29,65,24,5,224,231,170,1,65,139,32,166,136,164,144,16,210,137,16,45,4,127,129,85,10,99,72,101,99,155,218,38,216,216,68,72,151,46,109,170,128,130,22,126,65,254,65,138,20,183,
176,75,161,166,73,147,70,69,19,133,107,177,179,184,110,118,215,187,151,185,164,240,30,24,14,59,31,239,57,243,238,59,187,67,15,247,29,141,192,115,88,68,127,27,107,90,216,196,151,152,70,190,133,192,237,
182,159,177,132,7,114,252,25,7,21,243,159,224,45,30,98,173,134,206,37,62,169,48,254,93,178,179,151,119,4,154,84,47,83,217,246,177,40,224,64,81,103,5,154,88,198,179,26,107,166,241,2,131,49,12,180,240,161,
230,154,213,96,160,16,125,53,131,69,199,127,55,80,246,10,26,152,192,131,8,26,143,3,63,194,84,166,255,0,231,233,67,254,20,188,211,121,181,183,219,182,40,207,192,98,224,19,92,213,220,241,93,24,150,100,246,
172,204,192,36,158,75,62,30,227,248,29,81,188,15,199,24,195,70,218,145,199,66,224,175,145,197,97,54,136,159,98,191,204,192,124,224,245,200,226,240,42,240,182,76,1,114,83,132,43,129,255,98,36,178,120,3,
71,33,254,124,126,48,53,208,12,188,27,89,156,36,253,45,73,241,13,165,157,249,87,48,17,120,163,11,6,210,93,239,6,19,183,144,102,160,155,233,63,12,241,95,23,77,200,26,216,139,44,14,51,110,210,63,156,29,
40,58,5,221,172,254,61,201,17,252,7,105,6,46,49,218,5,3,63,66,252,55,249,129,252,151,240,23,150,34,139,143,224,41,46,176,83,54,169,238,165,180,227,159,79,30,157,92,203,59,193,31,188,87,125,225,237,225,
158,226,26,31,72,152,179,158,115,176,206,0,0,0,0,73,69,78,68,174,66,96,130,0,0};

const char* MainComponent::open_png = (const char*) resource_MainComponent_open_png;
const int MainComponent::open_pngSize = 536;

// JUCER_RESOURCE: save_png, 311, "../../Resources/MenuIcons/save.png"
static const unsigned char resource_MainComponent_save_png[] = { 137,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,0,32,0,0,0,32,8,6,0,0,0,115,122,122,244,0,0,0,4,115,66,73,84,8,8,8,8,124,8,100,136,0,
0,0,9,112,72,89,115,0,0,27,175,0,0,27,175,1,94,26,145,28,0,0,0,25,116,69,88,116,83,111,102,116,119,97,114,101,0,119,119,119,46,105,110,107,115,99,97,112,101,46,111,114,103,155,238,60,26,0,0,0,180,73,68,
65,84,88,133,237,215,49,10,194,48,20,198,241,63,34,212,186,58,246,54,173,131,160,103,241,60,226,5,4,187,117,45,120,1,87,79,32,120,6,221,210,161,169,134,66,68,210,54,15,225,125,240,160,33,233,203,143,100,
105,65,243,201,3,48,182,14,95,214,237,157,117,6,56,57,115,155,222,156,1,94,192,214,215,108,54,136,252,91,18,160,4,214,82,0,128,20,168,128,66,10,224,69,196,4,0,44,45,34,151,2,116,136,179,36,0,96,209,61,
204,3,94,190,1,71,103,124,29,34,9,1,92,108,141,18,169,43,120,199,119,2,59,160,14,232,183,26,11,144,217,154,60,226,87,160,0,5,40,64,1,10,80,128,2,220,239,129,59,237,111,84,140,60,35,237,243,7,105,0,124,
246,25,215,24,115,144,94,0,0,0,0,73,69,78,68,174,66,96,130,0,0};

const char* MainComponent::save_png = (const char*) resource_MainComponent_save_png;
const int MainComponent::save_pngSize = 311;

// JUCER_RESOURCE: midiIn_png, 820, "../../Resources/MenuIcons/midiIn.png"
static const unsigned char resource_MainComponent_midiIn_png[] = { 137,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,0,32,0,0,0,32,8,6,0,0,0,115,122,122,244,0,0,0,4,115,66,73,84,8,8,8,8,124,8,100,136,
0,0,0,9,112,72,89,115,0,0,27,175,0,0,27,175,1,94,26,145,28,0,0,0,25,116,69,88,116,83,111,102,116,119,97,114,101,0,119,119,119,46,105,110,107,115,99,97,112,101,46,111,114,103,155,238,60,26,0,0,2,177,73,
68,65,84,88,133,197,215,207,139,85,101,24,7,240,207,157,25,146,116,156,113,227,56,142,233,198,72,99,34,204,133,153,65,139,12,21,55,106,88,238,4,193,64,113,213,31,32,70,139,152,17,196,220,69,165,80,45,
130,22,66,63,8,81,113,16,34,93,104,17,33,149,88,35,142,152,90,84,83,77,33,12,141,139,231,157,233,220,227,61,222,115,239,157,91,95,120,225,60,239,251,60,239,247,123,158,243,254,120,78,69,115,232,193,10,
244,37,251,22,46,227,247,38,231,43,133,10,94,192,39,24,199,95,185,54,142,143,177,61,249,150,158,180,12,6,241,38,158,192,119,248,16,231,112,35,141,47,193,90,108,197,35,248,2,47,225,155,178,66,238,135,205,
184,141,43,120,177,142,232,14,236,72,190,183,176,169,85,242,39,241,43,206,162,191,129,184,254,20,243,11,214,52,75,222,139,81,124,133,5,5,62,67,120,165,96,108,1,190,198,247,98,209,54,140,87,241,39,30,207,
245,119,102,158,127,198,88,198,94,140,238,140,189,42,205,113,160,81,242,185,248,9,111,231,250,207,136,55,234,74,246,82,12,164,231,94,76,136,212,103,113,76,172,161,7,107,17,117,20,8,88,143,121,120,39,215,
255,99,106,255,36,123,204,191,59,97,66,108,209,79,115,49,239,138,172,60,91,192,85,19,195,98,21,119,213,115,44,129,46,145,129,161,90,131,69,25,88,130,235,152,76,118,5,59,177,178,4,225,234,68,54,63,217,
147,105,174,129,194,136,26,248,8,35,25,123,21,166,82,127,61,188,145,124,55,102,250,70,74,198,206,224,168,216,66,211,232,192,203,226,237,234,161,15,207,171,206,238,37,188,213,136,128,3,226,0,154,215,72,
80,1,186,241,27,246,215,26,44,90,3,167,49,7,207,205,130,128,13,120,0,167,26,9,234,20,251,253,196,44,8,56,41,238,134,206,122,142,121,236,22,215,236,150,130,241,62,113,94,172,199,194,2,159,109,105,142,93,
141,146,19,251,247,51,220,84,189,253,230,226,176,40,62,178,181,192,33,213,167,221,163,41,246,172,38,222,126,26,253,34,125,99,120,70,172,153,15,18,249,176,168,1,214,226,32,254,192,251,201,231,41,92,197,
15,226,76,105,9,15,227,75,241,150,199,241,183,40,54,242,216,147,198,142,39,223,139,88,94,111,242,178,21,81,143,184,118,247,137,79,115,10,159,139,20,19,153,122,90,236,154,73,188,39,14,164,11,37,231,47,
141,117,56,130,243,170,235,194,241,212,119,68,44,218,81,113,105,21,29,221,21,60,212,170,152,10,22,165,150,205,228,28,113,43,78,137,11,109,176,70,220,235,216,219,170,128,251,161,72,196,52,249,84,187,5,
228,69,220,196,99,25,242,255,68,64,94,196,68,134,124,70,64,209,93,48,91,184,35,74,249,107,226,0,187,7,237,22,80,193,107,88,214,102,158,66,242,236,55,207,183,182,174,129,122,228,51,2,74,255,68,54,136,30,
245,255,136,190,21,181,226,255,139,187,167,28,164,232,187,247,113,117,0,0,0,0,73,69,78,68,174,66,96,130,0,0};

const char* MainComponent::midiIn_png = (const char*) resource_MainComponent_midiIn_png;
const int MainComponent::midiIn_pngSize = 820;

// JUCER_RESOURCE: midiOut_png, 782, "../../Resources/MenuIcons/midiOut.png"
static const unsigned char resource_MainComponent_midiOut_png[] = { 137,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,0,32,0,0,0,32,8,6,0,0,0,115,122,122,244,0,0,0,4,115,66,73,84,8,8,8,8,124,8,100,136,
0,0,0,9,112,72,89,115,0,0,27,175,0,0,27,175,1,94,26,145,28,0,0,0,25,116,69,88,116,83,111,102,116,119,97,114,101,0,119,119,119,46,105,110,107,115,99,97,112,101,46,111,114,103,155,238,60,26,0,0,2,139,73,
68,65,84,88,133,205,214,75,108,85,85,20,6,224,207,94,99,165,145,68,83,4,202,128,222,234,64,26,100,160,4,102,24,147,10,12,136,242,232,68,67,36,141,33,198,1,51,97,4,81,154,48,39,148,34,9,137,15,96,76,72,
116,164,241,65,32,225,225,192,26,94,26,10,53,16,31,88,72,33,17,26,139,105,97,176,247,133,211,227,185,183,247,28,185,197,63,89,57,89,107,239,181,214,127,246,89,107,157,205,255,8,111,99,246,163,76,62,129,
51,53,72,148,241,76,163,8,60,139,211,184,139,159,208,150,90,159,143,75,104,111,20,129,90,36,202,248,37,218,27,74,32,139,196,210,68,242,105,33,144,38,113,39,145,124,218,8,192,98,140,165,146,79,27,129,74,
193,165,147,55,132,192,227,41,189,140,239,226,179,26,158,196,43,88,232,65,161,254,129,115,56,138,191,139,146,41,155,92,112,89,242,25,134,49,26,229,106,148,138,62,140,62,204,45,66,160,21,207,85,145,247,
49,130,27,232,71,23,90,18,190,45,209,214,143,155,184,134,245,69,72,100,97,187,240,118,159,171,175,6,202,248,34,250,124,240,95,147,191,19,3,245,161,148,195,175,132,221,209,183,167,104,242,231,133,227,60,
132,166,42,123,78,224,219,26,36,14,11,159,173,163,8,129,131,248,83,24,76,21,180,99,65,66,63,133,35,9,125,53,94,78,232,115,132,194,220,159,55,249,108,220,194,135,41,251,207,194,177,54,103,248,180,10,127,
212,129,148,189,23,127,97,86,30,2,61,49,81,103,202,190,9,59,106,248,189,135,229,41,219,139,49,214,134,60,4,118,225,74,30,135,41,240,43,118,102,45,84,43,174,54,252,158,208,91,240,49,214,213,145,236,77,
161,56,147,45,251,155,127,223,49,106,18,120,66,248,19,86,208,46,180,228,91,117,16,88,132,37,38,79,195,49,217,117,83,21,123,113,33,101,123,9,79,215,225,219,100,114,231,192,69,236,169,182,57,11,131,152,
39,180,81,5,3,194,92,152,10,19,194,40,174,160,45,202,96,29,190,247,209,41,84,238,198,60,78,85,240,110,140,245,66,94,199,227,56,43,212,67,81,52,227,60,142,21,113,238,18,152,111,205,88,43,9,83,175,55,202,
27,178,63,231,182,24,227,213,34,4,96,159,48,17,187,19,182,14,124,31,3,143,68,25,197,73,147,91,175,27,183,241,81,209,228,132,35,252,58,146,216,140,153,248,17,151,177,74,56,137,18,94,23,6,215,15,120,10,
91,162,207,87,114,182,95,22,102,224,83,225,45,135,132,158,126,45,99,223,202,184,54,20,247,126,34,92,223,30,10,30,195,90,161,189,198,113,93,56,153,3,81,190,137,182,113,225,239,183,38,79,224,60,104,198,
50,172,16,46,165,149,105,119,85,184,148,126,41,92,76,255,201,25,247,209,225,30,140,139,164,96,236,165,188,76,0,0,0,0,73,69,78,68,174,66,96,130,0,0};

const char* MainComponent::midiOut_png = (const char*) resource_MainComponent_midiOut_png;
const int MainComponent::midiOut_pngSize = 782;

// JUCER_RESOURCE: info_png, 331, "../../Resources/MenuIcons/info.png"
static const unsigned char resource_MainComponent_info_png[] = { 137,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,0,32,0,0,0,32,8,6,0,0,0,115,122,122,244,0,0,0,4,115,66,73,84,8,8,8,8,124,8,100,136,0,
0,0,9,112,72,89,115,0,0,27,175,0,0,27,175,1,94,26,145,28,0,0,0,25,116,69,88,116,83,111,102,116,119,97,114,101,0,119,119,119,46,105,110,107,115,99,97,112,101,46,111,114,103,155,238,60,26,0,0,0,200,73,68,
65,84,88,133,237,214,49,106,66,65,20,70,225,207,232,131,128,8,105,4,177,72,157,13,72,176,16,27,75,193,34,144,210,13,88,166,200,174,178,133,44,34,101,42,251,20,22,130,96,161,22,6,180,17,116,238,131,65,
152,83,13,12,247,191,231,14,204,48,20,10,119,206,8,51,52,114,52,31,98,135,61,22,169,33,15,1,129,182,211,228,157,64,78,136,57,62,240,152,75,160,16,166,25,172,175,48,197,22,171,184,206,245,244,241,137,165,
227,53,124,75,13,106,37,212,188,252,55,127,197,115,106,227,58,152,56,78,31,58,129,200,67,244,23,168,173,69,96,157,91,96,147,91,160,22,138,192,93,11,156,215,86,57,4,186,103,235,94,32,231,102,42,12,240,
229,244,18,254,96,44,225,103,148,242,153,124,194,251,133,189,111,252,38,100,22,10,249,56,0,225,253,21,213,139,70,77,147,0,0,0,0,73,69,78,68,174,66,96,130,0,0};

const char* MainComponent::info_png = (const char*) resource_MainComponent_info_png;
const int MainComponent::info_pngSize = 331;

// JUCER_RESOURCE: quit_png, 286, "../../Resources/MenuIcons/quit.png"
static const unsigned char resource_MainComponent_quit_png[] = { 137,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,0,32,0,0,0,32,8,6,0,0,0,115,122,122,244,0,0,0,4,115,66,73,84,8,8,8,8,124,8,100,136,0,
0,0,9,112,72,89,115,0,0,27,175,0,0,27,175,1,94,26,145,28,0,0,0,25,116,69,88,116,83,111,102,116,119,97,114,101,0,119,119,119,46,105,110,107,115,99,97,112,101,46,111,114,103,155,238,60,26,0,0,0,155,73,68,
65,84,88,133,237,150,65,10,128,48,12,4,71,255,96,209,39,234,115,21,20,244,49,245,82,193,131,150,54,166,138,144,185,150,100,7,74,210,130,97,24,63,160,7,156,160,206,133,218,71,12,128,7,166,76,9,23,106,124,
232,33,166,1,198,208,104,1,58,65,77,251,68,32,87,66,61,60,71,162,88,120,138,68,241,240,152,196,107,225,87,18,43,48,191,25,126,150,56,130,61,176,73,195,107,69,169,74,177,87,148,216,21,164,236,9,181,240,
227,206,37,203,74,45,252,238,76,93,34,101,212,138,73,228,204,185,186,132,100,201,168,74,124,254,28,195,199,31,18,195,48,138,179,3,171,208,82,219,107,156,110,182,0,0,0,0,73,69,78,68,174,66,96,130,0,0};

const char* MainComponent::quit_png = (const char*) resource_MainComponent_quit_png;
const int MainComponent::quit_pngSize = 286;


//[EndFile] You can add extra defines here...
//[/EndFile]
