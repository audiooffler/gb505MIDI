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

#include "ParameterComboBox.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
ParameterComboBox::ParameterComboBox (const String& componentName)
    : ComboBox(componentName)
{

    //[UserPreSize]
	m_comboBoxlookAndFeel->setColour(PopupMenu::backgroundColourId, GrooveboxLookAndFeel::Mc307LcdBackground);
	setLookAndFeel(m_comboBoxlookAndFeel);
	setColour(backgroundColourId, GrooveboxLookAndFeel::Mc307LcdBackground);
	m_paramPtr = nullptr;
	setEditableText(false);
	addListener(this);
    //[/UserPreSize]

    setSize (48, 48);


    //[Constructor] You can add your own custom stuff here..
    //[/Constructor]
}

ParameterComboBox::~ParameterComboBox()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
	if (m_paramPtr != nullptr) getParamPtr()->removeChangeListener(this);
    //[/Destructor_pre]



    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void ParameterComboBox::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
	ComboBox::paint(g);
    //[/UserPrePaint]

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void ParameterComboBox::resized()
{
    //[UserResized] Add your own custom resize handling here..
	ComboBox::resized();
    //[/UserResized]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
ParameterComboBox::ParameterComboBox(Parameter* paramPtr)
    : ComboBox(),
	  m_paramPtr(paramPtr)
{
	if (m_paramPtr!=nullptr) m_paramPtr->addChangeListener(this);
	// TODO: update entries/selection?
}

void ParameterComboBox::setParameter(Parameter* param)
{
	if (param != nullptr)
	{
		if (m_paramPtr != nullptr) m_paramPtr->removeChangeListener(this);
		m_paramPtr = param;
		m_paramPtr->addChangeListener(this);
		setVisible(true);
		clear(dontSendNotification);
		addItemList(m_paramPtr->getDisplayedValues(), 1);
		//for (int i = 0; i < getNumItems(); i++) setItemEnabled(getItemId(i), true);
		setSelectedItemIndex(m_paramPtr->getValue(), dontSendNotification); // setValue(param->getValue(), dontSendNotification);
		setTooltip(param->getDescription());
		//updateText();
	}
	else setVisible(false);
}

Parameter* ParameterComboBox::getParamPtr()
{
	return m_paramPtr;
}

String ParameterComboBox::getTooltip()
{
	return (m_paramPtr == nullptr) ? "" : m_paramPtr->getDescription();
}

void ParameterComboBox::changeListenerCallback(ChangeBroadcaster *source)
{
	if (Parameter* param = dynamic_cast<Parameter*>(source))
	{
		if (param == m_paramPtr && (uint8)getSelectedItemIndex() != m_paramPtr->getValue())
		{
			setSelectedItemIndex(m_paramPtr->getValue(), dontSendNotification);
			return;
		}
		if (m_paramPtr->getDescription() != getTooltip()) setTooltip(m_paramPtr->getDescription());
		if (m_paramPtr->getMin() != (uint8)0 || m_paramPtr->getMax() != (uint8)getNumItems() - 1)
		{
			clear(dontSendNotification);
			addItemList(m_paramPtr->getDisplayedValues(), 1);
			//setRange(m_paramPtr->getMin(), m_paramPtr->getMax(), 1.0);
		}
	}
}

void ParameterComboBox::comboBoxChanged(ComboBox *comboBoxThatHasChanged)
{
	if (comboBoxThatHasChanged == this && m_paramPtr != nullptr)
	{
		m_paramPtr->setValue((uint8)getSelectedItemIndex(), Parameter::GuiWidget);
	}
}

//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Introjucer information section --

    This is where the Introjucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="ParameterComboBox" componentName=""
                 parentClasses="public ComboBox, public ChangeListener, public ComboBox::Listener"
                 constructorParams="const String&amp; componentName" variableInitialisers="ComboBox(componentName)"
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="0" initialWidth="48" initialHeight="48">
  <BACKGROUND backgroundColour="0"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
