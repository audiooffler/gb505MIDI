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

#pragma once

//[Headers]     -- You can add your own extra header files here --
#include "JuceHeader.h"
#include "ParameterToggle.h"
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Introjucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class BigGreenToggle  : public ParameterToggle
{
public:
    //==============================================================================
    BigGreenToggle (const String& componentName);
    ~BigGreenToggle() override;

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
	BigGreenToggle();
    //[/UserMethods]

    void paint (juce::Graphics& g) override;
    void resized() override;

    // Binary resources:
    static const char* bigOrangeToggleOff_png;
    static const int bigOrangeToggleOff_pngSize;
    static const char* bigGreenToggleOn_png;
    static const int bigGreenToggleOn_pngSize;


private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    Image cachedImage_bigGreenToggleOn_png;
    //[/UserVariables]

    //==============================================================================
    juce::Image cachedImage_bigOrangeToggleOff_png_1;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (BigGreenToggle)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

