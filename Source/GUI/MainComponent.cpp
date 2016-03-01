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
#include "PatternTab.h"
#include "PatchEditor.h"
#include "MidiLoggerTab.h"
#include "PatternEditorTab.h"
#include "GrooveboxSplashScreen.h"
//[/Headers]

#include "MainComponent.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
extern ApplicationCommandManager*  applicationCommandManager;
//[/MiscUserDefs]

//==============================================================================
MainComponent::MainComponent ()
    : TabbedComponentWithMenu()
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]


    //[UserPreSize]
	addTab(TRANS("Pattern"), Colours::whitesmoke, new PatternTab(), true);
	addTab(TRANS("Pattern"), Colours::whitesmoke, new PatternEditorTab(), true);
	addTab(TRANS("Mixer"), Colours::whitesmoke, new MixerTab(), true);
	SynthParts part(SynthPart1);
	String partNameString;
	for (int p = (int)SynthPart1; p <= (int)SynthPart7; p++)
	{
		part = (SynthParts)p;
		partNameString = "Patch Part "+String(p+1);
		CustomViewport* patchPartViewPort = new CustomViewport(partNameString);
		patchPartViewPort->setViewedComponent(new PatchEditor(part), true);
		addTab(partNameString, Colours::whitesmoke, patchPartViewPort, true);
	}
	//addTab(TRANS("Patch Part 1"), Colours::whitesmoke, new PatchEditor(SynthPart1), true);

	MidiLoggerTab* loggerTab = new MidiLoggerTab();
	Logger::setCurrentLogger(loggerTab);
	addTab(TRANS("MIDI Logger"), Colours::whitesmoke, loggerTab, true);
	
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
		CommandIDs::gotoPatternTab,
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
		CommandIDs::showInfo
	};
	commands.addArray(ids, numElementsInArray(ids));
}

void MainComponent::getCommandInfo(CommandID commandID, ApplicationCommandInfo& result)
{
	const String gotoTabCategory("Tabs");

	switch (commandID)
	{
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
	case CommandIDs::gotoPartRTab:
		result.setInfo("Part R", "Opens the patch editor for part R", gotoTabCategory, 0);
		result.addDefaultKeypress('r', ModifierKeys::commandModifier);
		break;
	case CommandIDs::gotoMixerTab:
		result.setInfo("Mixer", "Opens the mixer panel", gotoTabCategory, 0);
		result.addDefaultKeypress('m', ModifierKeys::commandModifier);
		break;
	case CommandIDs::gotoPatternTab:
		result.setInfo("Pattern", "Opens the pattern settings", gotoTabCategory, 0);
		result.addDefaultKeypress('p', ModifierKeys::commandModifier);
		break;
	case CommandIDs::gotoPatternEditorTab:
		result.setInfo("Pattern Editor", "Opens the pattern event table", gotoTabCategory, 0);
		result.addDefaultKeypress('e', ModifierKeys::commandModifier);
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
	switch (info.commandID)
	{
	case CommandIDs::gotoPatternTab:
		setCurrentTabIndex(1, true);
		break;
	case CommandIDs::gotoPatternEditorTab:
		setCurrentTabIndex(2, true);
		break;
	case CommandIDs::gotoMixerTab:
		setCurrentTabIndex(3, true);
		break;
	case CommandIDs::gotoPart1Tab:
		setCurrentTabIndex(4, true);
		break;
	case CommandIDs::gotoPart2Tab:
		setCurrentTabIndex(5, true);
		break;
	case CommandIDs::gotoPart3Tab:
		setCurrentTabIndex(6, true);
		break;
	case CommandIDs::gotoPart4Tab:
		setCurrentTabIndex(7, true);
		break;
	case CommandIDs::gotoPart5Tab:
		setCurrentTabIndex(8, true);
		break;
	case CommandIDs::gotoPart6Tab:
		setCurrentTabIndex(9, true);
		break;
	case CommandIDs::gotoPart7Tab:
		setCurrentTabIndex(10, true);
		break;
	case CommandIDs::gotoPartRTab:
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
		for (int i = 0; i < commandsOfMainComponent.size(); i++)
		{
			int currentCommand = commandsOfMainComponent[i];
			if (currentCommand >= gotoPart1Tab && currentCommand < CommandIDs::showInfo)
			{
				gotoViewMenu.addCommandItem(applicationCommandManager, currentCommand);
			}
		}

		menu.addSubMenu("Go to view", gotoViewMenu);

		menu.addSeparator();

		menu.addCommandItem(applicationCommandManager, CommandIDs::showInfo);

		// quit command from application instance
		menu.addCommandItem(applicationCommandManager, StandardApplicationCommandIDs::quit);

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


//[EndFile] You can add extra defines here...
//[/EndFile]
