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

#ifndef __JUCE_HEADER_87ACA7DD4D5DA118__
#define __JUCE_HEADER_87ACA7DD4D5DA118__

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
    ~SmallGreenToggle();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
	SmallGreenToggle();
    //[/UserMethods]

    void paint (Graphics& g);
    void resized();

    // Binary resources:
    static const char* smallOrangeToggleOff_png;
    static const int smallOrangeToggleOff_pngSize;
    static const char* smallGreenToggleOn_png;
    static const int smallGreenToggleOn_pngSize;


private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    Image cachedImage_smallGreenToggleOn_png;
    //[/UserVariables]

    //==============================================================================
    Image cachedImage_smallOrangeToggleOff_png;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (SmallGreenToggle)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

#endif   // __JUCE_HEADER_87ACA7DD4D5DA118__