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
class SmallGreenToggle  : public ParameterToggle
{
public:
    //==============================================================================
    SmallGreenToggle (const String& componentName);
    ~SmallGreenToggle() override;

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
	SmallGreenToggle();
	SmallGreenToggle(const String& componentName, bool isInTable);
    //[/UserMethods]

    void paint (juce::Graphics& g) override;
    void resized() override;
    void mouseDown (const juce::MouseEvent& e) override;

    // Binary resources:
    static const char* smallOrangeToggleOff_png;
    static const int smallOrangeToggleOff_pngSize;
    static const char* smallGreenToggleOn_png;
    static const int smallGreenToggleOn_pngSize;


private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    Image cachedImage_smallGreenToggleOn_png;
	bool m_isInTable = false;
    //[/UserVariables]

    //==============================================================================
    juce::Image cachedImage_smallOrangeToggleOff_png_1;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (SmallGreenToggle)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

