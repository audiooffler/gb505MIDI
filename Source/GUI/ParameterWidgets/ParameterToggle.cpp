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

#include "ParameterToggle.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
ParameterToggle::ParameterToggle() : ToggleButton()
{
	m_paramPtr = nullptr;
	setSize(32, 32);
}
//[/MiscUserDefs]

//==============================================================================
ParameterToggle::ParameterToggle (const String& componentName)
    : ToggleButton()
{

    //[UserPreSize]
	m_paramPtr = nullptr;
	this->setName(componentName);
    //[/UserPreSize]

    setSize (32, 32);


    //[Constructor] You can add your own custom stuff here..
    //[/Constructor]
}

ParameterToggle::~ParameterToggle()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
	if (getParamPtr() != nullptr) getParamPtr()->removeChangeListener(this);
    //[/Destructor_pre]



    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void ParameterToggle::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
	#ifdef JUCE_MSVC
	g;
	#endif
    //[/UserPrePaint]

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void ParameterToggle::resized()
{
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
ParameterToggle::ParameterToggle(Parameter* paramPtr)
	: ToggleButton(),
	  m_paramPtr(paramPtr)
{
	setSize(32, 32);
	if (m_paramPtr != nullptr) m_paramPtr->addChangeListener(this);
}

void ParameterToggle::setParameter(Parameter* param)
{
	m_paramPtr = param;
	if (param != nullptr)
	{
		m_paramPtr->addChangeListener(this);
		setVisible(true);
		setTooltip(param->getDescription());
		setToggleState(param->getValue()>0, dontSendNotification);
	}
	else setVisible(false);
}

Parameter* ParameterToggle::getParamPtr()
{
	return m_paramPtr;
}

String ParameterToggle::getTooltip()
{
	return (m_paramPtr == nullptr) ? "" : m_paramPtr->getDescription();
}

void ParameterToggle::changeListenerCallback(ChangeBroadcaster *source)
{
	if (Parameter* param = dynamic_cast<Parameter*>(source))
	{
		if (param == m_paramPtr && getToggleState() != (m_paramPtr->getValue()>0))
		{
			setToggleState((m_paramPtr->getValue()>0), dontSendNotification);
			return;
		}
		if (m_paramPtr->getDescription() != getTooltip()) setTooltip(m_paramPtr->getDescription());
	}

}

void ParameterToggle::buttonStateChanged()
{
	if (m_paramPtr != nullptr)
	{
		m_paramPtr->setValue(getToggleState()?1:0, Parameter::GuiWidget);
	}
}
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Introjucer information section --

    This is where the Introjucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="ParameterToggle" componentName=""
                 parentClasses="public ToggleButton, public ChangeListener" constructorParams="const String&amp; componentName"
                 variableInitialisers="ToggleButton()" snapPixels="8" snapActive="1"
                 snapShown="1" overlayOpacity="0.330" fixedSize="1" initialWidth="32"
                 initialHeight="32">
  <BACKGROUND backgroundColour="0"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
