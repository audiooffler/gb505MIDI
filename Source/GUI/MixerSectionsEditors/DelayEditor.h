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

#ifndef __JUCE_HEADER_51F4849208819A4C__
#define __JUCE_HEADER_51F4849208819A4C__

//[Headers]     -- You can add your own extra header files here --
#include "JuceHeader.h"
#include "../ParameterWidgets/Knob.h"
#include "../ParameterWidgets/MicroParameterSlider.h"
//[/Headers]

#include "../GroupWidgets/PanelGroupGrey.h"
#include "../ParameterWidgets/ParameterLedSwitch.h"


//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Introjucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class DelayEditor  : public Component,
                     public Slider::Listener
{
public:
    //==============================================================================
    DelayEditor ();
    ~DelayEditor();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    //[/UserMethods]

    void paint (Graphics& g) override;
    void resized() override;
    void sliderValueChanged (Slider* sliderThatWasMoved) override;



private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    //[/UserVariables]

    //==============================================================================
    ScopedPointer<PanelGroupGrey> m_delayEditorPanelGroup;
    ScopedPointer<Label> m_delayTypeLabel;
    ScopedPointer<ParameterLedSwitch> m_delayTypeToggle;
    ScopedPointer<Knob> m_timeSlider;
    ScopedPointer<Label> m_timeLabel;
    ScopedPointer<Label> m_dampLabel;
    ScopedPointer<MicroParameterSlider> m_dampSlider;
    ScopedPointer<Knob> m_feedbackSlider;
    ScopedPointer<Label> m_feedbackLabel;
    ScopedPointer<Label> m_outputLabel;
    ScopedPointer<ParameterLedSwitch> m_outputToggle;
    ScopedPointer<Knob> m_levelSlider;
    ScopedPointer<Label> m_levelLabel;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (DelayEditor)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

#endif   // __JUCE_HEADER_51F4849208819A4C__
