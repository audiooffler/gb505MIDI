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

#include "RectangleGrey.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
RectangleGrey::RectangleGrey ()
{

    //[UserPreSize]
    //[/UserPreSize]

    setSize (128, 32);


    //[Constructor] You can add your own custom stuff here..
    //[/Constructor]
}

RectangleGrey::~RectangleGrey()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]



    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void RectangleGrey::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colour (0xff7f848d));

    g.setGradientFill (ColourGradient (Colour (0xff969a9d),
                                       48.0f, static_cast<float> (proportionOfHeight (0.0127f)),
                                       Colour (0xff767b7d),
                                       56.0f, static_cast<float> (proportionOfHeight (0.7722f)),
                                       false));
    g.fillRoundedRectangle (0.0f, 0.0f, static_cast<float> (getWidth() - 0), static_cast<float> (getHeight() - 0), 5.000f);

    g.setColour (Colour (0xff888b90));
    g.drawRoundedRectangle (0.0f, 0.0f, static_cast<float> (getWidth() - 0), static_cast<float> (getHeight() - 0), 5.000f, 2.000f);

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void RectangleGrey::resized()
{
    //[UserResized] Add your own custom resize handling here..
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

<JUCER_COMPONENT documentType="Component" className="RectangleGrey" componentName=""
                 parentClasses="public Component" constructorParams="" variableInitialisers=""
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="1" initialWidth="128" initialHeight="32">
  <BACKGROUND backgroundColour="ff7f848d">
    <ROUNDRECT pos="0 0 0M 0M" cornerSize="5" fill="linear: 48 1.266%, 56 77.215%, 0=ff969a9d, 1=ff767b7d"
               hasStroke="1" stroke="2, mitered, butt" strokeColour="solid: ff888b90"/>
  </BACKGROUND>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
