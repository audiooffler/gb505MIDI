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
//[/Headers]

#include "ParameterLedSwitch.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
ParameterLedSwitch::ParameterLedSwitch (const String& componentName)
    : Component (componentName)
{
    addAndMakeVisible (m_toggleButton1 = new ToggleButton ("toggleButton1"));
    m_toggleButton1->setButtonText ("OPTION 1");
    m_toggleButton1->setRadioGroupId (1);
    m_toggleButton1->addListener (this);
    m_toggleButton1->setToggleState (true, dontSendNotification);

    addAndMakeVisible (m_toggleButton2 = new ToggleButton ("toggleButton2"));
    m_toggleButton2->setButtonText ("OPTION 2");
    m_toggleButton2->setRadioGroupId (1);
    m_toggleButton2->addListener (this);


    //[UserPreSize]
	m_value = 0;
	m_toggleButton1->setWantsKeyboardFocus(false);
	m_toggleButton2->setWantsKeyboardFocus(false);
	this->setWantsKeyboardFocus(true);
	this->addKeyListener(this);
	m_toggleButton1->addKeyListener(this);
	m_toggleButton2->addKeyListener(this);
    //[/UserPreSize]

    setSize (72, 32);


    //[Constructor] You can add your own custom stuff here..
    //[/Constructor]
}

ParameterLedSwitch::~ParameterLedSwitch()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    m_toggleButton1 = nullptr;
    m_toggleButton2 = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
	if (m_paramPtr != nullptr) m_paramPtr->removeChangeListener(this);
    //[/Destructor]
}

//==============================================================================
void ParameterLedSwitch::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    //[UserPaint] Add your own custom painting code here..
	if (hasKeyboardFocus(true))
	{
		g.setColour(findColour(TextEditor::focusedOutlineColourId));
		g.drawRect(0, 0, getWidth(), getHeight());
	}
    //[/UserPaint]
}

void ParameterLedSwitch::resized()
{
    m_toggleButton1->setBounds (0, 0, 72, 16);
    m_toggleButton2->setBounds (0, 16, 72, 16);
    //[UserResized] Add your own custom resize handling here..
	if (getWidth() >= m_toggleButton1->getWidth() + m_toggleButton2->getWidth())
	{
		m_toggleButton2->setBounds(m_toggleButton1->getWidth(), 0, m_toggleButton2->getWidth(), m_toggleButton2->getHeight());
	}
    //[/UserResized]
}

void ParameterLedSwitch::buttonClicked (Button* buttonThatWasClicked)
{
    //[UserbuttonClicked_Pre]
    //[/UserbuttonClicked_Pre]

    if (buttonThatWasClicked == m_toggleButton1)
    {
        //[UserButtonCode_m_toggleButton1] -- add your button handler code here..
        //[/UserButtonCode_m_toggleButton1]
    }
    else if (buttonThatWasClicked == m_toggleButton2)
    {
        //[UserButtonCode_m_toggleButton2] -- add your button handler code here..
        //[/UserButtonCode_m_toggleButton2]
    }

    //[UserbuttonClicked_Post]
	uint8 value(m_toggleButton1->getToggleState() ? 0 : (m_toggleButton2->getToggleState() ? 1 : 0));
	setValue(value);
    //[/UserbuttonClicked_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
uint8 ParameterLedSwitch::getValue()
{
	return m_value;
}

void ParameterLedSwitch::setValue(uint8 v)
{
	if (m_value == v) return;

	m_value = v;
	if (v == 0)
	{
		m_toggleButton1->setToggleState(true, dontSendNotification);
	}
	else
	{
		m_toggleButton2->setToggleState(true, dontSendNotification);
	}

	//DBG("GUI toggled value to " + String(m_value).paddedLeft('0', 3));

	if (m_paramPtr != nullptr)
	{
		m_paramPtr->setValue(m_value,Parameter::GuiWidget);
	}
}

bool ParameterLedSwitch::keyPressed(const KeyPress &key, Component *originatingComponent)
{
	//[UserCode_keyPressed] -- Add your code here...
	if ((originatingComponent == this || originatingComponent == m_toggleButton1 || originatingComponent==m_toggleButton2) &&
		(key.isKeyCode(KeyPress::leftKey) || key.isKeyCode(KeyPress::upKey) || key.isKeyCode(KeyPress::rightKey) || key.isKeyCode(KeyPress::downKey) || key.isKeyCode(KeyPress::returnKey) || key.isKeyCode(KeyPress::spaceKey)))
	{
		setValue((getValue() + 1) % 2);
		return true;
	}
	return false;  // Return true if your handler uses this key event, or false to allow it to be passed-on.
	//[/UserCode_keyPressed]
}

void ParameterLedSwitch::changeListenerCallback(ChangeBroadcaster *source)
{
	if (dynamic_cast<Parameter*>(source) == m_paramPtr)
	{
		if (m_paramPtr->getValue()!=m_value)
		{
			setValue(m_paramPtr->getValue());
		}
		if (m_paramPtr->getDescription() != getTooltip()) setTooltip(m_paramPtr->getDescription());
	}
}

void ParameterLedSwitch::setTooltip(const String &newTooltip)
{
	m_tooltip = newTooltip;
}

String ParameterLedSwitch::getTooltip()
{
	return (m_paramPtr == nullptr) ? m_tooltip : m_paramPtr->getDescription();
}

void ParameterLedSwitch::setParameter(Parameter* param)
{
	m_paramPtr = param;
	if (param != nullptr)
	{
		m_paramPtr->addChangeListener(this);
		setVisible(true);
		setTooltip(m_paramPtr->getDescription());
		// range must always be 0 - 1 for this widget!
		m_toggleButton1->setButtonText(m_paramPtr->getDisplayedValue(0));
		m_toggleButton1->setTooltip(m_paramPtr->getDescription());
		m_toggleButton2->setButtonText(m_paramPtr->getDisplayedValue(1));
		m_toggleButton2->setTooltip(m_paramPtr->getDescription());
		setValue(m_paramPtr->getValue());
	}
	else setVisible(false);
}

Parameter* ParameterLedSwitch::getParamPtr()
{
	return m_paramPtr;
}

void ParameterLedSwitch::focusGained(FocusChangeType /*cause*/){ repaint(); }
void ParameterLedSwitch::focusLost(FocusChangeType /*cause*/){ repaint(); }
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Introjucer information section --

    This is where the Introjucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="ParameterLedSwitch" componentName=""
                 parentClasses="public Component, public KeyListener, public ChangeListener, public SettableTooltipClient"
                 constructorParams="const String&amp; componentName" variableInitialisers="Component (componentName)"
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="1" initialWidth="72" initialHeight="32">
  <BACKGROUND backgroundColour="0"/>
  <TOGGLEBUTTON name="toggleButton1" id="ed866061c8993868" memberName="m_toggleButton1"
                virtualName="" explicitFocusOrder="0" pos="0 0 72 16" buttonText="OPTION 1"
                connectedEdges="0" needsCallback="1" radioGroupId="1" state="1"/>
  <TOGGLEBUTTON name="toggleButton2" id="ef5b8ef336e1ae" memberName="m_toggleButton2"
                virtualName="" explicitFocusOrder="0" pos="0 16 72 16" buttonText="OPTION 2"
                connectedEdges="0" needsCallback="1" radioGroupId="1" state="0"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
