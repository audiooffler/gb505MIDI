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

#include "ParameterSlider.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
ParameterSlider::ParameterSlider (const String& componentName)
    : Slider(componentName)
{

    //[UserPreSize]
	m_paramPtr = nullptr;
    //[/UserPreSize]

    setSize (48, 48);


    //[Constructor] You can add your own custom stuff here..
    //[/Constructor]
}

ParameterSlider::~ParameterSlider()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
	if (getParamPtr() != nullptr) getParamPtr()->removeChangeListener(this);
    //[/Destructor_pre]



    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void ParameterSlider::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
	Slider::paint(g);
    //[/UserPrePaint]

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void ParameterSlider::resized()
{
    //[UserResized] Add your own custom resize handling here..
	Slider::resized();
	if (getTextBoxPosition() == Slider::NoTextBox) setPopupDisplayEnabled(true, this->getParentComponent());
    //[/UserResized]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
ParameterSlider::ParameterSlider(Parameter* paramPtr)
    : Slider(),
	  m_paramPtr(paramPtr)
{
	if (m_paramPtr!=nullptr) m_paramPtr->addChangeListener(this);
	updateText();
}

void ParameterSlider::setParameter(Parameter* param)
{
	m_paramPtr = param;
	if (param != nullptr)
	{
		m_paramPtr->addChangeListener(this);
		setVisible(true);
		setTooltip(param->getDescription());
		setRange(param->getMin(), param->getMax(), 1.0);
		setValue(param->getValue(), dontSendNotification);
		updateText();
	}
	else setVisible(false);
}

Parameter* ParameterSlider::getParamPtr()
{
	return m_paramPtr;
}

String ParameterSlider::getTextFromValue(double value)
{
	if (m_paramPtr == nullptr) return Slider::getTextFromValue(value);
	else return m_paramPtr->getDisplayedValue((uint8)value);
}


double ParameterSlider::getValueFromText(const String& text)
{
	if (m_paramPtr != nullptr)
	{
		int index(m_paramPtr->getDisplayedValues().indexOf(text, true));
		if (index >= 0)
		{
			return index+m_paramPtr->getMin();
		}
		else if ((index = m_paramPtr->getDisplayedValues().indexOf("+" + String(text.getIntValue()), true)) >= 0)
		{
			return index + m_paramPtr->getMin();
		}
		else return text.getIntValue() + m_paramPtr->getMin();
	}
	else return text.getIntValue();
}


String ParameterSlider::getTooltip()
{
	return (m_paramPtr == nullptr) ? "" : m_paramPtr->getDescription();
}

void ParameterSlider::setTooltip(const String &newTooltip)
{
	Slider::setTooltip(newTooltip);
	for (int i = 0; i < getNumChildComponents(); i++)
	{
		if (SettableTooltipClient* component = dynamic_cast<SettableTooltipClient*>(getChildComponent(i)))
		{
			component->setTooltip(newTooltip);
		}
	}
}

void ParameterSlider::changeListenerCallback(ChangeBroadcaster *source)
{
	if (Parameter* param = dynamic_cast<Parameter*>(source))
	{
		if (param == m_paramPtr && (uint8)getValue() != m_paramPtr->getValue())
		{
			setValue(m_paramPtr->getValue(), dontSendNotification);
			return;
		}
		if (m_paramPtr->getDescription() != getTooltip()) setTooltip(m_paramPtr->getDescription());
		if (m_paramPtr->getMin() != (uint8)getMinimum() || m_paramPtr->getMax() != (uint8)getMaximum())
			setRange(m_paramPtr->getMin(), m_paramPtr->getMax(), 1.0);
		updateText();
	}
}

void ParameterSlider::valueChanged()
{
	if (m_paramPtr != nullptr)
	{
		m_paramPtr->setValue((uint8)getValue(), Parameter::GuiWidget);
	}
}
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Introjucer information section --

    This is where the Introjucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="ParameterSlider" componentName=""
                 parentClasses="public Slider, public ChangeListener" constructorParams="const String&amp; componentName"
                 variableInitialisers="Slider(componentName)" snapPixels="8" snapActive="1"
                 snapShown="1" overlayOpacity="0.330" fixedSize="0" initialWidth="48"
                 initialHeight="48">
  <BACKGROUND backgroundColour="0"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
