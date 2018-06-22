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

#ifndef __JUCE_HEADER_8764F7452D9674EC__
#define __JUCE_HEADER_8764F7452D9674EC__

//[Headers]     -- You can add your own extra header files here --
#include "JuceHeader.h"
#include "../ParameterWidgets/Knob.h"
//[/Headers]

#include "../GroupWidgets/PanelGroupGrey.h"
#include "../ParameterWidgets/GrabSwitch.h"


//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Introjucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class RhyFxSendEditor  : public Component,
                         public Slider::Listener
{
public:
    //==============================================================================
    RhyFxSendEditor (const String &componentName, int toneNumber);
    ~RhyFxSendEditor();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    void setupParameters(int toneNumber);
    //[/UserMethods]

    void paint (Graphics& g) override;
    void resized() override;
    void sliderValueChanged (Slider* sliderThatWasMoved) override;

    // Binary resources:
    static const char* mixer_png;
    static const int mixer_pngSize;


private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    int m_toneNumber = 35;
    //[/UserVariables]

    //==============================================================================
    ScopedPointer<PanelGroupGrey> m_fxGrp;
    ScopedPointer<Label> m_mfxLabel;
    ScopedPointer<Label> m_delayLabel;
    ScopedPointer<Label> m_reverbLabel;
    ScopedPointer<GrabSwitch> m_mfxGrab;
    ScopedPointer<Knob> m_delaySlider;
    ScopedPointer<Knob> m_ReverbSlider;
    ScopedPointer<ImageButton> m_imageButton;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (RhyFxSendEditor)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

#endif   // __JUCE_HEADER_8764F7452D9674EC__
