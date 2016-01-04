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
#include "../../GrooveboxMemory/Waveforms.h"
#include "../../GrooveboxMemory/OverallMemoryBlock.h"
#include "../../GrooveboxMemory/SynthPatchesBlock.h"
//[/Headers]

#include "WaveformsAllGroups.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
extern OverallMemoryBlock* grooveboxMemory;
extern Waveforms* waveForms;
//[/MiscUserDefs]

//==============================================================================
WaveformsAllGroups::WaveformsAllGroups (GrooveboxConnector::GrooveboxModel grooveboxModel, SynthParts part, Tone tone)
    : m_grooveboxModel (grooveboxModel), m_part (part), m_tone (tone)
{
    addAndMakeVisible (m_waveformsGroupA = new WaveformsGroup (Waveforms::WAVES_A));
    addAndMakeVisible (m_waveformsGroupB = new WaveformsGroup (Waveforms::WAVES_B));

    //[UserPreSize]
	if (m_grooveboxModel == GrooveboxConnector::Model_JX_305) addAndMakeVisible(m_waveformsGroupC = new WaveformsGroup(Waveforms::WAVES_C_JX305));
	else if (m_grooveboxModel == GrooveboxConnector::Model_MC_307) addAndMakeVisible(m_waveformsGroupC = new WaveformsGroup(Waveforms::WAVES_C_MC307));
	else m_waveformsGroupC = nullptr;
    //[/UserPreSize]

    setSize (836, 1320);


    //[Constructor] You can add your own custom stuff here..
	setSize(836, (m_grooveboxModel == GrooveboxConnector::Model_JX_305 || m_grooveboxModel == GrooveboxConnector::Model_MC_307) ? 1980 : 1320);

	for (int i = 0; i < getNumChildComponents(); i++)
	{
		if (WaveformsGroup* waveformsGroup = dynamic_cast<WaveformsGroup*>(getChildComponent(i)))
		{
			// collect all Button references for easier access of all buttons
			for (int b = 0; b < waveformsGroup->getNumChildComponents(); b++)
			{
				if (WaveformButton* wfButton = dynamic_cast<WaveformButton*>(waveformsGroup->getChildComponent(b)))
				{
					allButtonReferences.add(wfButton);
					// also register button listener
					wfButton->addListener(this);
				}
			}
			// also register mouse listener to all groups (and children)
			waveformsGroup->addMouseListener(this, true);
		}
	}

	SynthPatchesBlock* synthPatches = grooveboxMemory->getSynthPatchesBlock();
	if (synthPatches != nullptr)
	{
		PatchPartBlock* patchPart = synthPatches->getPatchPartBlockPtr(m_part);
		if (patchPart != nullptr)
		{
			if (PatchCommonBlock* patchCommon = patchPart->getPatchCommonBlockPtr())
			{
			}
			PatchToneBlock* tone = nullptr;
			switch (m_tone)
			{
			case Tone1:
				if (PatchToneBlock* tone1 = patchPart->getPatchToneBlockPtr(Tone1)) tone = tone1;
				break;
			case Tone2:
				if (PatchToneBlock* tone2 = patchPart->getPatchToneBlockPtr(Tone2)) tone = tone2;
				break;
			case Tone3:
				if (PatchToneBlock* tone3 = patchPart->getPatchToneBlockPtr(Tone3)) tone = tone3;
				break;
			case Tone4:
				if (PatchToneBlock* tone4 = patchPart->getPatchToneBlockPtr(Tone4)) tone = tone4;
				break;
			}
			if (tone != nullptr)
			{
				m_waveGroupType = tone->getParameter(0x01);
				m_waveGroupId = tone->getParameter(0x02);
				m_waveNumber = tone->getParameter(0x03);
				changeListenerCallback(m_waveGroupType);
				m_waveGroupType->addChangeListener(this);
				m_waveGroupId->addChangeListener(this);
				m_waveNumber->addChangeListener(this);
			}
		}
	}
    //[/Constructor]
}

WaveformsAllGroups::~WaveformsAllGroups()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
	m_waveGroupType->removeChangeListener(this);
	m_waveGroupId->removeChangeListener(this);
	m_waveNumber->removeChangeListener(this);
    //[/Destructor_pre]

    m_waveformsGroupA = nullptr;
    m_waveformsGroupB = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
	if (m_grooveboxModel == GrooveboxConnector::Model_JX_305 || m_grooveboxModel == GrooveboxConnector::Model_MC_307) m_waveformsGroupC = nullptr;
    //[/Destructor]
}

//==============================================================================
void WaveformsAllGroups::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colour (0xfff2f59b));

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void WaveformsAllGroups::resized()
{
    m_waveformsGroupA->setBounds (0, 0, 836, 660);
    m_waveformsGroupB->setBounds (0, 660, 836, 660);
    //[UserResized] Add your own custom resize handling here..
	if (m_grooveboxModel == GrooveboxConnector::Model_JX_305 || m_grooveboxModel == GrooveboxConnector::Model_MC_307) m_waveformsGroupC->setBounds(0, 1320, 836, 660);
    //[/UserResized]
}

void WaveformsAllGroups::mouseDoubleClick (const MouseEvent& e)
{
    //[UserCode_mouseDoubleClick] -- Add your code here...
	if (WaveformButton* wfButton = dynamic_cast<WaveformButton*>(e.eventComponent))
	{
		DialogWindow* dw = findParentComponentOfClass<DialogWindow>();
		if (dw != nullptr) dw->exitModalState(1);
	}
    //[/UserCode_mouseDoubleClick]
}

bool WaveformsAllGroups::keyPressed (const KeyPress& key)
{
    //[UserCode_keyPressed] -- Add your code here...
	WaveformButton* focusedButton = getFocusedOrFirstWaveformButton();
	if (focusedButton == nullptr) return false;

	if (key.isKeyCode(KeyPress::escapeKey))
	{
		// closing dialog handled in browser class
	}
	else if (key.isKeyCode(KeyPress::returnKey))
	{
		//DBG("return key pressed while focused " + focusedButton->getButtonText());
		// make editor select value, close dialog
		// triggerClick();
		// close dialog
		DialogWindow* dw = findParentComponentOfClass<DialogWindow>();
		if (dw != nullptr) dw->exitModalState(1);
	}
	else if (key.isKeyCode(KeyPress::spaceKey))
	{
		// same as mouse click (make editor select value, keep dialog open)
		buttonClicked(focusedButton);
		return true;
	}
	else if (key.isKeyCode(KeyPress::leftKey))
	{
		// make editor focus move 32 wavetable buttons up
		WaveformButton* aimedButton = getPrev(focusedButton, 32, true);
		tryScrollToButtonsGroup(aimedButton);
		Desktop::setMousePosition(aimedButton->getScreenBounds().getCentre());
		return true;
	}
	else if (key.isKeyCode(KeyPress::rightKey))
	{
		// make editor focus move 32 wavetable buttons down
		WaveformButton* aimedButton = getNext(focusedButton, 32, true);
		tryScrollToButtonsGroup(aimedButton);
		Desktop::setMousePosition(aimedButton->getScreenBounds().getCentre());
		return true;
	}
	else if (key.isKeyCode(KeyPress::upKey))
	{
		// make editor focus move no previous wavetable button
		WaveformButton* aimedButton = getPrev(focusedButton, 1, true);
		tryScrollToButtonsGroup(aimedButton);
		Desktop::setMousePosition(aimedButton->getScreenBounds().getCentre());
		return true;
	}
	else if (key.isKeyCode(KeyPress::downKey))
	{
		// make editor focus move no next wavetable button
		WaveformButton* aimedButton = getNext(focusedButton, 1, true);
		tryScrollToButtonsGroup(aimedButton);
		Desktop::setMousePosition(aimedButton->getScreenBounds().getCentre());
		return true;
	}
	else if (key.isKeyCode(KeyPress::pageUpKey))
	{
		// make editor focus move 10 wavetable buttons up
		WaveformButton* aimedButton = getPrev(focusedButton, 10, true);
		tryScrollToButtonsGroup(aimedButton);
		Desktop::setMousePosition(aimedButton->getScreenBounds().getCentre());
		return true;
	}
	else if (key.isKeyCode(KeyPress::pageDownKey))
	{
		// make editor focus move 10 wavetable buttons down
		WaveformButton* aimedButton = getNext(focusedButton, 10, true);
		tryScrollToButtonsGroup(aimedButton);
		Desktop::setMousePosition(aimedButton->getScreenBounds().getCentre());
		return true;
	}
	else if (key.isKeyCode(KeyPress::homeKey))
	{
		WaveformButton* aimedButton = allButtonReferences[0];
		tryScrollToButtonsGroup(aimedButton);
		Desktop::setMousePosition(aimedButton->getScreenBounds().getCentre());
		return true;
	}
	else if (key.isKeyCode(KeyPress::endKey))
	{
		WaveformButton* aimedButton = allButtonReferences[allButtonReferences.size()-1];
		tryScrollToButtonsGroup(aimedButton);
		Desktop::setMousePosition(aimedButton->getScreenBounds().getCentre());
		return true;
	}
    return false;  // Return true if your handler uses this key event, or false to allow it to be passed-on.
    //[/UserCode_keyPressed]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
void WaveformsAllGroups::buttonClicked(Button* button)
{
	if (WaveformButton* buttonToSelect = dynamic_cast<WaveformButton*>(button))
	{
		for (int i = 0; i < allButtonReferences.size(); i++)
		{
			allButtonReferences[i]->setToggleState(false, dontSendNotification);
		}
		buttonToSelect->setToggleState(true, dontSendNotification);
		m_waveGroupType->setValue(0, Parameter::GuiWidget);
		m_waveGroupId->setValue(Waveforms::getGroupId(buttonToSelect->getGroup()),Parameter::GuiWidget);
		m_waveNumber->setValue((uint8) buttonToSelect->getIndexInGroup(), Parameter::GuiWidget);
	}
	//if (WaveformButton* wfButton = dynamic_cast<WaveformButton*>(button))
	//{
	//	select(wfButton->getGroup(), wfButton->getNumInGroup());
	//	// make editor select value, keep dialog open
	//}
}

void WaveformsAllGroups::addListenerToAllButtons(ButtonListener* listener)
{
	for (int i = 0; i < allButtonReferences.size(); i++)
	{
		allButtonReferences[i]->addListener(listener);
	}
}

WaveformButton* WaveformsAllGroups::getFocusedOrFirstWaveformButton()
{
	if (WaveformButton* wfButton = dynamic_cast<WaveformButton*>(getCurrentlyFocusedComponent()))
	{
		return wfButton;
	}
	else
	{
		return allButtonReferences.size() > 0 ? allButtonReferences[0] : nullptr;
	}
}

WaveformButton* WaveformsAllGroups::getNext(WaveformButton* buttonToStartFrom, int maxStepSizeWithinGroup, bool tryScrollToGroup)	// skips 1 or n (e.g. 10, 32), but going to next group will get the first of the next group
{
 	if (buttonToStartFrom == nullptr || allButtonReferences.size() < 1) return nullptr;
	WaveformButton* result = buttonToStartFrom;
	int index = allButtonReferences.indexOf(buttonToStartFrom);
	for (int i = 0; i < abs(maxStepSizeWithinGroup); i++)
	{
		if (maxStepSizeWithinGroup > 0)
		{
			index = (index >= allButtonReferences.size()-1) ? 0 : index + 1;
		}
		else if (maxStepSizeWithinGroup < 0){
			index = (index < 1) ? allButtonReferences.size() - 1 : index - 1;
		}
		result = allButtonReferences[index];
		// if group changed
		if (buttonToStartFrom->getButtonText().isNotEmpty() && result->getButtonText().isNotEmpty() &&
			buttonToStartFrom->getButtonText()[0] != result->getButtonText()[0])
		{
			if (tryScrollToGroup) tryScrollToButtonsGroup(result);
			return result;
		}
		// if group was changed, return this and don't search further
	}
	//if (tryScrollToGroup) tryScrollToButtonsGroup(result);
	return result;
}
WaveformButton* WaveformsAllGroups::getPrev(WaveformButton* buttonToStartFrom, int maxStepSizeWithinGroup, bool tryScrollToGroup)  // skips 1 or n (e.g. 10, 32), but going to previous group will get the last of the previous group
{
	return getNext(buttonToStartFrom, -maxStepSizeWithinGroup, tryScrollToGroup);
}

void WaveformsAllGroups::tryScrollToButtonsGroup(WaveformButton* buttonToScrollTo)
{
	// try to get WaveformsGroup
	if (WaveformsGroup* groupCmp = dynamic_cast<WaveformsGroup*>(buttonToScrollTo->getParentComponent()))
	{
		if (getParentComponent() != nullptr && getParentComponent()->getParentComponent() != nullptr)
		// try to get Viewport
		if (Viewport* viewport = dynamic_cast<Viewport*>(getParentComponent()->getParentComponent()))
		{
			// scroll to current group
			viewport->setViewPosition(groupCmp->getBoundsInParent().getTopLeft());
		}
	}
}

void WaveformsAllGroups::changeListenerCallback(ChangeBroadcaster *source)	// parameter changes of groovebox memory block
{
	if (Parameter* param = dynamic_cast<Parameter*>(source))
	{
		// if one of the parameters changed
		if (param == m_waveGroupType || param == m_waveGroupId || param == m_waveNumber)
		{
			WaveformButton* b = select(waveForms->getGroupForId(m_waveGroupId->getValue()), m_waveNumber->getValue());
			tryScrollToButtonsGroup(b);
		}
	}
}

void WaveformsAllGroups::textEditorTextChanged(TextEditor& textEditor)
{
	if (textEditor.getName() == "highlightTextEditor")
	{
		StringArray tags(StringArray::fromTokens(textEditor.getText().toLowerCase().replaceCharacters(",;|\t\r\n", "      "), " ,;|\t\r\n", "\""));
		tags.removeEmptyStrings();
		tags.removeDuplicates(true);
		String buttonName, buttonLongName;
		for (int i = 0; i < allButtonReferences.size(); i++)
		{
			bool highlight(tags.size() > 0 ? true : false);
			buttonName = waveForms->getName(allButtonReferences[i]->getGroup(), allButtonReferences[i]->getIndexInGroup());
			buttonLongName = waveForms->getLongName(allButtonReferences[i]->getGroup(), allButtonReferences[i]->getIndexInGroup());
			for (int t = 0; t < tags.size(); t++)
			{
				if (!buttonName.toLowerCase().contains(tags[t]) && !buttonLongName.toLowerCase().contains(tags[t]))
				{
					highlight = false;
					break;
				}
			}
			allButtonReferences[i]->setHighLight(highlight);
		}
	}
}

WaveformButton* WaveformsAllGroups::select(Waveforms::WaveGroup group, int numInGroup)
{
	WaveformButton* buttonToSelect = nullptr;
	for (int i = 0; i < allButtonReferences.size(); i++)
	{
		allButtonReferences[i]->setToggleState(false, dontSendNotification);
		if (allButtonReferences[i]->getGroup() == group && allButtonReferences[i]->getIndexInGroup() == numInGroup)
			buttonToSelect = allButtonReferences[i];
	}
	buttonToSelect->setToggleState(true, dontSendNotification);
	buttonToSelect->grabKeyboardFocus();
	return buttonToSelect;

}

void WaveformsAllGroups::tryScrollToSelectedButton()
{
	WaveformButton* b = select(waveForms->getGroupForId(m_waveGroupId->getValue()), m_waveNumber->getValue());
	tryScrollToButtonsGroup(b);
	b->grabKeyboardFocus();
}
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Introjucer information section --

    This is where the Introjucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="WaveformsAllGroups" componentName=""
                 parentClasses="public Component, public Button::Listener, public ChangeListener, public TextEditor::Listener"
                 constructorParams="GrooveboxConnector::GrooveboxModel grooveboxModel, SynthParts part, Tone tone"
                 variableInitialisers="m_grooveboxModel (grooveboxModel), m_part (part), m_tone (tone)"
                 snapPixels="4" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="1" initialWidth="836" initialHeight="1320">
  <METHODS>
    <METHOD name="mouseDoubleClick (const MouseEvent&amp; e)"/>
    <METHOD name="keyPressed (const KeyPress&amp; key)"/>
  </METHODS>
  <BACKGROUND backgroundColour="fff2f59b"/>
  <JUCERCOMP name="waveformsGroupA" id="bf4d7806acd82471" memberName="m_waveformsGroupA"
             virtualName="" explicitFocusOrder="0" pos="0 0 836 660" sourceFile="WaveformsGroup.cpp"
             constructorParams="Waveforms::WAVES_A"/>
  <JUCERCOMP name="waveformsGroupB" id="c190439ea854f833" memberName="m_waveformsGroupB"
             virtualName="" explicitFocusOrder="0" pos="0 660 836 660" sourceFile="WaveformsGroup.cpp"
             constructorParams="Waveforms::WAVES_B"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
