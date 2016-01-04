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

#include "KeyfollowMicroParameterSlider.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
KeyfollowMicroParameterSlider::KeyfollowMicroParameterSlider (const String &componentName)
    : MicroParameterSlider(componentName)
{

    //[UserPreSize]
	m_bubble = nullptr;
    //[/UserPreSize]

    setSize (56, 16);


    //[Constructor] You can add your own custom stuff here..
    //[/Constructor]
}

KeyfollowMicroParameterSlider::~KeyfollowMicroParameterSlider()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]



    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void KeyfollowMicroParameterSlider::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
	MicroParameterSlider::paint(g);
    //[/UserPrePaint]

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void KeyfollowMicroParameterSlider::resized()
{
    //[UserResized] Add your own custom resize handling here..
    MicroParameterSlider::resized();
    //[/UserResized]
}

void KeyfollowMicroParameterSlider::mouseEnter (const MouseEvent& e)
{
    //[UserCode_mouseEnter] -- Add your code here...
	#ifdef JUCE_MSVC
	e;
	#endif
	m_bubble = new KeyfollowBubbleComponent(this);
	m_bubble->setPosition(this);
	m_bubble->addToDesktop(0);
	m_bubble->setVisible(true);
	//addAndMakeVisible(m_bubble);
    //[/UserCode_mouseEnter]
}

void KeyfollowMicroParameterSlider::mouseExit (const MouseEvent& e)
{
    //[UserCode_mouseExit] -- Add your code here...
	#ifdef JUCE_MSVC
	e;
	#endif
	if (m_bubble != nullptr)
	{
		m_bubble->setVisible(false);
		m_bubble->removeFromDesktop();
	}
	//removeChildComponent(m_bubble);
	m_bubble = nullptr;
    //[/UserCode_mouseExit]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Introjucer information section --

    This is where the Introjucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="KeyfollowMicroParameterSlider"
                 componentName="" parentClasses="public MicroParameterSlider"
                 constructorParams="const String &amp;componentName" variableInitialisers="MicroParameterSlider(componentName)"
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="1" initialWidth="56" initialHeight="16">
  <METHODS>
    <METHOD name="mouseEnter (const MouseEvent&amp; e)"/>
    <METHOD name="mouseExit (const MouseEvent&amp; e)"/>
  </METHODS>
  <BACKGROUND backgroundColour="0"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
