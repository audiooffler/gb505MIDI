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
class GrabSwitch  : public ParameterToggle
{
public:
    //==============================================================================
    GrabSwitch (const String &name);
    ~GrabSwitch() override;

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    //[/UserMethods]

    void paint (juce::Graphics& g) override;
    void resized() override;
    void mouseDown (const juce::MouseEvent& e) override;
    void mouseUp (const juce::MouseEvent& e) override;

    // Binary resources:
    static const char* grabSwitchGrab54x49_png;
    static const int grabSwitchGrab54x49_pngSize;
    static const char* grabSwitchOff54x49_png;
    static const int grabSwitchOff54x49_pngSize;
    static const char* grabSwitchOn54x49_png;
    static const int grabSwitchOn54x49_pngSize;


private:
    //[UserVariables]   -- You can add your own custom variables in this section.
	bool m_grabbed;
	Image cachedImage_grabSwitchOn54x49_png;
	Image cachedImage_grabSwitchGrab54x49_png;
	Image* m_currentImgPtr;
	bool hitTest(int x, int y);
    //[/UserVariables]

    //==============================================================================
    juce::Image cachedImage_grabSwitchOff54x49_png_1;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (GrabSwitch)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

