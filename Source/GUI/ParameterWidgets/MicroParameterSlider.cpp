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
#include "../GrooveboxLookAndFeel.h"
//[/Headers]

#include "MicroParameterSlider.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
MicroParameterSlider::MicroParameterSlider(const String &componentName, bool isInTable)
	: MicroParameterSlider(componentName)
{
	m_isInTable = isInTable;
}
//[/MiscUserDefs]

//==============================================================================
MicroParameterSlider::MicroParameterSlider (const String &componentName)
    : ParameterSlider(componentName)
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]


    //[UserPreSize]
    setRange (0, 127, 1);
	setSliderStyle (Slider::LinearBar);
	setMouseDragSensitivity (128	);
	setSliderSnapsToMousePosition(false);
	setTextBoxStyle (Slider::TextBoxLeft, false, 64, 20);
	setColour(Slider::backgroundColourId, GrooveboxLookAndFeel::Mc307LcdBackground);
	setColour(Slider::thumbColourId, GrooveboxLookAndFeel::Mc307LcdThumb);
	setColour(textBoxBackgroundColourId, GrooveboxLookAndFeel::Mc307LcdBackground);
    //[/UserPreSize]

    setSize (56, 16);


    //[Constructor] You can add your own custom stuff here..
    //[/Constructor]
}

MicroParameterSlider::~MicroParameterSlider()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]



    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void MicroParameterSlider::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    ParameterSlider::paint(g);
    //[/UserPrePaint]

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void MicroParameterSlider::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    //[UserResized] Add your own custom resize handling here..
    ParameterSlider::resized();
    //[/UserResized]
}

void MicroParameterSlider::mouseDown (const MouseEvent& e)
{
    //[UserCode_mouseDown] -- Add your code here...
	if (m_isInTable) getParentComponent()->mouseDown(e);
	ParameterSlider::mouseDown(e);
    //[/UserCode_mouseDown]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Introjucer information section --

    This is where the Introjucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="MicroParameterSlider" componentName=""
                 parentClasses="public ParameterSlider" constructorParams="const String &amp;componentName"
                 variableInitialisers="ParameterSlider(componentName)" snapPixels="8"
                 snapActive="1" snapShown="1" overlayOpacity="0.330" fixedSize="1"
                 initialWidth="56" initialHeight="16">
  <METHODS>
    <METHOD name="mouseDown (const MouseEvent&amp; e)"/>
  </METHODS>
  <BACKGROUND backgroundColour="0"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
