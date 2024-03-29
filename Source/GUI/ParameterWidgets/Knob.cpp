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

#include "Knob.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
Knob::Knob (const String &componentName)
    : ParameterSlider(componentName)
{

    //[UserPreSize]
	setRotaryParameters((float)(-149.7*double_Pi / 180) + (float)double_Pi, (float)(149.7*double_Pi / 180), true);

    //[/UserPreSize]

    setSize (48, 64);


    //[Constructor] You can add your own custom stuff here..
	setColour(textBoxBackgroundColourId,GrooveboxLookAndFeel::Mc307LcdBackground);
    //[/Constructor]
}

Knob::~Knob()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]



    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void Knob::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    //[UserPaint] Add your own custom painting code here..
	ParameterSlider::paint(g);
    //[/UserPaint]
}

void Knob::resized()
{
    //[UserResized] Add your own custom resize handling here..
	ParameterSlider::resized();
    //[/UserResized]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...

//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Introjucer information section --

    This is where the Introjucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="Knob" componentName="" parentClasses="public ParameterSlider"
                 constructorParams="const String &amp;componentName" variableInitialisers="ParameterSlider(componentName)"
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="1" initialWidth="48" initialHeight="64">
  <BACKGROUND backgroundColour="ffffff"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
