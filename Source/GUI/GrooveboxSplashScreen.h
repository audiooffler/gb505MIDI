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

#ifndef __JUCE_HEADER_391753278C39F36C__
#define __JUCE_HEADER_391753278C39F36C__

//[Headers]     -- You can add your own extra header files here --
#include "JuceHeader.h"
//[/Headers]

#include "GroupWidgets/PanelGroupGrey.h"


//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Introjucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class GrooveboxSplashScreen  : public SplashScreen,
                               public Button::Listener
{
public:
    //==============================================================================
    GrooveboxSplashScreen (const String &title, int width, int height, bool useDropShadow);
    ~GrooveboxSplashScreen();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    //[/UserMethods]

    void paint (Graphics& g);
    void resized();
    void buttonClicked (Button* buttonThatWasClicked);

    // Binary resources:
    static const char* grooveboxLogo_png;
    static const int grooveboxLogo_pngSize;
    static const char* icon_png;
    static const int icon_pngSize;


private:
    //[UserVariables]   -- You can add your own custom variables in this section.
	double m_progress=-1.0;
    //[/UserVariables]

    //==============================================================================
    ScopedPointer<PanelGroupGrey> m_groupComponent;
    ScopedPointer<ImageButton> m_rolandGrooveboxImageButton;
    ScopedPointer<ImageButton> m_gbMidiImageButton;
    ScopedPointer<Label> m_descrLabel;
    ScopedPointer<Label> m_authorLabel;
    ScopedPointer<Label> m_rolandTmLabel;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (GrooveboxSplashScreen)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

#endif   // __JUCE_HEADER_391753278C39F36C__
