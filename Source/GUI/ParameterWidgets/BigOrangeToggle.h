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

#ifndef __JUCE_HEADER_5B95CF5713EF4F88__
#define __JUCE_HEADER_5B95CF5713EF4F88__

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
class BigOrangeToggle  : public ParameterToggle
{
public:
    //==============================================================================
    BigOrangeToggle (const String& componentName);
    ~BigOrangeToggle();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
	BigOrangeToggle();
    //[/UserMethods]

    void paint (Graphics& g) override;
    void resized() override;

    // Binary resources:
    static const char* bigOrangeToggleOff_png;
    static const int bigOrangeToggleOff_pngSize;
    static const char* bigOrangeToggleOn_png;
    static const int bigOrangeToggleOn_pngSize;


private:
    //[UserVariables]   -- You can add your own custom variables in this section.
	Image cachedImage_bigOrangeToggleOn_png;
    //[/UserVariables]

    //==============================================================================
    Image cachedImage_bigOrangeToggleOff_png_1;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (BigOrangeToggle)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

#endif   // __JUCE_HEADER_5B95CF5713EF4F88__
