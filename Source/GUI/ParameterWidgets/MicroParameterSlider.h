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

#ifndef __JUCE_HEADER_945B4E0E14D76C2C__
#define __JUCE_HEADER_945B4E0E14D76C2C__

//[Headers]     -- You can add your own extra header files here --
#include "JuceHeader.h"
#include "ParameterSlider.h"
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Introjucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class MicroParameterSlider  : public ParameterSlider
{
public:
    //==============================================================================
    MicroParameterSlider (const String &componentName);
    ~MicroParameterSlider();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
	MicroParameterSlider(const String &componentName, bool isInTable);
    //[/UserMethods]

    void paint (Graphics& g) override;
    void resized() override;
    void mouseDown (const MouseEvent& e) override;



private:
    //[UserVariables]   -- You can add your own custom variables in this section.
	bool m_isInTable = false;
    //[/UserVariables]

    //==============================================================================


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MicroParameterSlider)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

#endif   // __JUCE_HEADER_945B4E0E14D76C2C__
