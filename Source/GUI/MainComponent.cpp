/*
  ==============================================================================

  This is an automatically generated GUI class created by the Introjucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Introjucer version: 3.1.0

  ------------------------------------------------------------------------------

  The Introjucer is part of the JUCE library - "Jules' Utility Class Extensions"
  Copyright 2004-13 by Raw Material Software Ltd.

  ==============================================================================
*/

//[Headers] You can add your own extra header files here...
#include "MixerTab.h"
#include "PatternTab.h"
#include "PatchEditor.h"
#include "MidiLoggerTab.h"
#include "PatternEditorTab.h"
//[/Headers]

#include "MainComponent.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
extern ApplicationCommandManager*  applicationCommandManager;
//[/MiscUserDefs]

//==============================================================================
MainComponent::MainComponent ()
    : TabbedComponent (TabbedButtonBar::TabsAtTop)
{

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
    //[/UserPreSize]

    setSize (640, 480);


    //[Constructor] You can add your own custom stuff here..
	// This registers all of our commands with the command manager but has to be done after the window has
	// been created so we can find the number of rendering engines available
	applicationCommandManager->registerAllCommandsForTarget(this);
	applicationCommandManager->setFirstCommandTarget(this);
	// this lets the command manager use keypresses that arrive in our window to send out commands
	addKeyListener(applicationCommandManager->getKeyMappings());

	if (ApplicationCommandTarget* appCmdTarget = dynamic_cast<ApplicationCommandTarget*>(getCurrentContentComponent()))
	{
		applicationCommandManager->setFirstCommandTarget(appCmdTarget);
	}

	grabKeyboardFocus();
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
	TabbedComponent::paint(g);
    //[/UserPrePaint]

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void MainComponent::resized()
{
    //[UserResized] Add your own custom resize handling here..
	TabbedComponent::resized();
    //[/UserResized]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...

void MainComponent::currentTabChanged(int newCurrentTabIndex, const String &newCurrentTabName)
{
	TabbedComponent::currentTabChanged(newCurrentTabIndex, newCurrentTabName);
	if (ApplicationCommandTarget* appCmdTarget = dynamic_cast<ApplicationCommandTarget*>(getCurrentContentComponent()))
	{
		applicationCommandManager->setFirstCommandTarget(appCmdTarget);
	}
}

//==============================================================================
// The following methods implement the ApplicationCommandTarget interface, allowing
// this window to publish a set of actions it can perform, and which can be mapped
// onto menus, keypresses, etc.

ApplicationCommandTarget* MainComponent::getNextCommandTarget()
{
	// this will return the next parent component that is an ApplicationCommandTarget (in this
	// case, there probably isn't one, but it's best to use this method in your own apps).
	return findFirstTargetParentComponent();
}

void MainComponent::getAllCommands(Array <CommandID>& commands)
{
	// this returns the set of all commands that this target can perform..
	const CommandID ids[] = {
		CommandIDs::gotoPart1Tab,
		CommandIDs::gotoPart2Tab,
		CommandIDs::gotoPart3Tab,
		CommandIDs::gotoPart4Tab,
		CommandIDs::gotoPart5Tab,
		CommandIDs::gotoPart6Tab,
		CommandIDs::gotoPart7Tab,
		CommandIDs::gotoPartRTab,
		CommandIDs::gotoMixerTab,
		CommandIDs::gotoPatternTab,
		CommandIDs::gotoPatternEditorTab
	};
	commands.addArray(ids, numElementsInArray(ids));
}

void MainComponent::getCommandInfo(CommandID commandID, ApplicationCommandInfo& result)
{
	const String gotoTabCategory("Tabs");

	switch (commandID)
	{
	case CommandIDs::gotoPart1Tab:
		result.setInfo("Go to part 1", "Opens the patch editor for part 1", gotoTabCategory, 0);
		result.addDefaultKeypress('1', ModifierKeys::commandModifier);
		break;
	case CommandIDs::gotoPart2Tab:
		result.setInfo("Go to part 2", "Opens the patch editor for part 2", gotoTabCategory, 0);
		result.addDefaultKeypress('2', ModifierKeys::commandModifier);
		break;
	case CommandIDs::gotoPart3Tab:
		result.setInfo("Go to part 3", "Opens the patch editor for part 3", gotoTabCategory, 0);
		result.addDefaultKeypress('3', ModifierKeys::commandModifier);
		break;
	case CommandIDs::gotoPart4Tab:
		result.setInfo("Go to part 4", "Opens the patch editor for part 4", gotoTabCategory, 0);
		result.addDefaultKeypress('4', ModifierKeys::commandModifier);
		break;
	case CommandIDs::gotoPart5Tab:
		result.setInfo("Go to part 5", "Opens the patch editor for part 5", gotoTabCategory, 0);
		result.addDefaultKeypress('5', ModifierKeys::commandModifier);
		break;
	case CommandIDs::gotoPart6Tab:
		result.setInfo("Go to part 6", "Opens the patch editor for part 6", gotoTabCategory, 0);
		result.addDefaultKeypress('6', ModifierKeys::commandModifier);
		break;
	case CommandIDs::gotoPart7Tab:
		result.setInfo("Go to part 7", "Opens the patch editor for part 7", gotoTabCategory, 0);
		result.addDefaultKeypress('7', ModifierKeys::commandModifier);
		break;
	case CommandIDs::gotoPartRTab:
		result.setInfo("Go to part R", "Opens the patch editor for part R", gotoTabCategory, 0);
		result.addDefaultKeypress('r', ModifierKeys::commandModifier);
		break;
	case CommandIDs::gotoMixerTab:
		result.setInfo("Go to mixer", "Opens the mixer panel", gotoTabCategory, 0);
		result.addDefaultKeypress('m', ModifierKeys::commandModifier);
		break;
	case CommandIDs::gotoPatternTab:
		result.setInfo("Go to pattern", "Opens the pattern settings", gotoTabCategory, 0);
		result.addDefaultKeypress('p', ModifierKeys::commandModifier);
		break;
	case CommandIDs::gotoPatternEditorTab:
		result.setInfo("Go to pattern editor", "Opens the pattern event table", gotoTabCategory, 0);
		result.addDefaultKeypress('e', ModifierKeys::commandModifier);
	default:
		break;
	}

}

bool MainComponent::perform(const InvocationInfo& info)
{
	switch (info.commandID)
	{
	case CommandIDs::gotoPart1Tab:
		setCurrentTabIndex(2, true);
		break;
	case CommandIDs::gotoPart2Tab:
		setCurrentTabIndex(3, true);
		break;
	case CommandIDs::gotoPart3Tab:
		setCurrentTabIndex(4, true);
		break;
	case CommandIDs::gotoPart4Tab:
		setCurrentTabIndex(5, true);
		break;
	case CommandIDs::gotoPart5Tab:
		setCurrentTabIndex(6, true);
		break;
	case CommandIDs::gotoPart6Tab:
		setCurrentTabIndex(7, true);
		break;
	case CommandIDs::gotoPart7Tab:
		setCurrentTabIndex(8, true);
		break;
	case CommandIDs::gotoPartRTab:
		//setCurrentTabIndex(9, true);
		break;
	case CommandIDs::gotoMixerTab:
		setCurrentTabIndex(1, true);
		break;
	case CommandIDs::gotoPatternTab:
		setCurrentTabIndex(0, true);
		break;
	case CommandIDs::gotoPatternEditorTab:
		setCurrentTabIndex(10, true);
	default:
		return false;
	}
return true;
}

//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Introjucer information section --

    This is where the Introjucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="MainComponent" componentName=""
                 parentClasses="public TabbedComponent, public ApplicationCommandTarget"
                 constructorParams="" variableInitialisers="TabbedComponent (TabbedButtonBar::TabsAtTop)"
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="0" initialWidth="640" initialHeight="480">
  <BACKGROUND backgroundColour="0"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
