/*
  ==============================================================================

  This is an automatically generated GUI class created by the Projucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Projucer version: 7.0.2

  ------------------------------------------------------------------------------

  The Projucer is part of the JUCE library.
  Copyright (c) 2020 - Raw Material Software Limited.

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
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]


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
void PanelGroupGrey::paint (juce::Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    {
        float x = 0.0f, y = 0.0f, width = static_cast<float> (getWidth() - 0), height = static_cast<float> (getHeight() - 0);
        juce::Colour fillColour1 = juce::Colour (0xff969a9d), fillColour2 = juce::Colour (0xff767b7d);
        juce::Colour strokeColour = juce::Colour (0xff888b90);
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setGradientFill (juce::ColourGradient (fillColour1,
                                             48.0f - 0.0f + x,
                                             static_cast<float> (proportionOfHeight (0.0127f)) - 0.0f + y,
                                             fillColour2,
                                             56.0f - 0.0f + x,
                                             static_cast<float> (proportionOfHeight (0.7722f)) - 0.0f + y,
                                             false));
        g.fillRoundedRectangle (x, y, width, height, 5.000f);
        g.setColour (strokeColour);
        g.drawRoundedRectangle (x, y, width, height, 5.000f, 2.000f);
    }

    {
        int x = 4, y = 3, width = getWidth() - 8, height = 12;
        juce::Colour fillColour = juce::Colour (0xff303030);
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.fillRect (x, y, width, height);
    }

    //[UserPaint] Add your own custom painting code here..
    GroupComponent::paint(g);
    //[/UserPaint]
}

void PanelGroupGrey::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="PanelGroupGrey" componentName=""
                 parentClasses="public GroupComponent" constructorParams="const String&amp; componentName, const String&amp; labelText"
                 variableInitialisers="GroupComponent(componentName,labelText)"
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="1" initialWidth="100" initialHeight="100">
  <BACKGROUND backgroundColour="0">
    <ROUNDRECT pos="0 0 0M 0M" cornerSize="5.0" fill="linear: 48 1.266%, 56 77.215%, 0=ff969a9d, 1=ff767b7d"
               hasStroke="1" stroke="2, mitered, butt" strokeColour="solid: ff888b90"/>
    <RECT pos="4 3 8M 12" fill="solid: ff303030" hasStroke="0"/>
  </BACKGROUND>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]

