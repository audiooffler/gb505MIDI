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

#include "PanelGroupGrey.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
PanelGroupGrey::PanelGroupGrey (const String& componentName, const String& labelText)
    : GroupComponent(componentName,labelText)
{

    //[UserPreSize]
	setTextLabelPosition(Justification::centred);
    //[/UserPreSize]

    setSize (100, 100);


    //[Constructor] You can add your own custom stuff here..
    //[/Constructor]
}

PanelGroupGrey::~PanelGroupGrey()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]



    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void PanelGroupGrey::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.setGradientFill (ColourGradient (Colour (0xff969a9d),
                                       48.0f, static_cast<float> (proportionOfHeight (0.0127f)),
                                       Colour (0xff767b7d),
                                       56.0f, static_cast<float> (proportionOfHeight (0.7722f)),
                                       false));
    g.fillRoundedRectangle (0.0f, 0.0f, static_cast<float> (getWidth() - 0), static_cast<float> (getHeight() - 0), 5.000f);

    g.setColour (Colour (0xff888b90));
    g.drawRoundedRectangle (0.0f, 0.0f, static_cast<float> (getWidth() - 0), static_cast<float> (getHeight() - 0), 5.000f, 2.000f);

    g.setColour (Colour (0xff303030));
    g.fillRect (4, 3, getWidth() - 8, 12);

    //[UserPaint] Add your own custom painting code here..
    GroupComponent::paint(g);
    //[/UserPaint]
}

void PanelGroupGrey::resized()
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

<JUCER_COMPONENT documentType="Component" className="PanelGroupGrey" componentName=""
                 parentClasses="public GroupComponent" constructorParams="const String&amp; componentName, const String&amp; labelText"
                 variableInitialisers="GroupComponent(componentName,labelText)"
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="1" initialWidth="100" initialHeight="100">
  <BACKGROUND backgroundColour="0">
    <ROUNDRECT pos="0 0 0M 0M" cornerSize="5" fill="linear: 48 1.266%, 56 77.215%, 0=ff969a9d, 1=ff767b7d"
               hasStroke="1" stroke="2, mitered, butt" strokeColour="solid: ff888b90"/>
    <RECT pos="4 3 8M 12" fill="solid: ff303030" hasStroke="0"/>
  </BACKGROUND>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
