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

#ifndef __JUCE_HEADER_7D79B06845363EDC__
#define __JUCE_HEADER_7D79B06845363EDC__

//[Headers]     -- You can add your own extra header files here --
#include "JuceHeader.h"
#include "KeyfollowBubbleComponent.h"
#include "MicroParameterSlider.h"
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Introjucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class KeyfollowMicroParameterSlider  : public MicroParameterSlider
{
public:
    //==============================================================================
    KeyfollowMicroParameterSlider (const String &componentName);
    ~KeyfollowMicroParameterSlider();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    //[/UserMethods]

    void paint (Graphics& g);
    void resized();
    void mouseEnter (const MouseEvent& e);
    void mouseExit (const MouseEvent& e);



private:
    //[UserVariables]   -- You can add your own custom variables in this section.
	ScopedPointer<KeyfollowBubbleComponent> m_bubble;
    //[/UserVariables]

    //==============================================================================


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (KeyfollowMicroParameterSlider)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

#endif   // __JUCE_HEADER_7D79B06845363EDC__
