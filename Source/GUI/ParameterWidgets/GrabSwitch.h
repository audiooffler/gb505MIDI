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

#ifndef __JUCE_HEADER_43F1600427C5B164__
#define __JUCE_HEADER_43F1600427C5B164__

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
    ~GrabSwitch();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    //[/UserMethods]

    void paint (Graphics& g);
    void resized();
    void mouseDown (const MouseEvent& e);
    void mouseUp (const MouseEvent& e);

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
    Image cachedImage_grabSwitchOff54x49_png;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (GrabSwitch)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

#endif   // __JUCE_HEADER_43F1600427C5B164__
