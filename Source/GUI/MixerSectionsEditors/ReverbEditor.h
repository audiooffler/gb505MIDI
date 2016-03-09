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

#ifndef __JUCE_HEADER_DB2227C1418B1EA__
#define __JUCE_HEADER_DB2227C1418B1EA__

//[Headers]     -- You can add your own extra header files here --
#include "JuceHeader.h"
#include "../ParameterWidgets/ParameterComboBox.h"
#include "../ParameterWidgets/Knob.h"
#include "../ParameterWidgets/MicroParameterSlider.h"
//[/Headers]

#include "../GroupWidgets/PanelGroupGrey.h"


//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Introjucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class ReverbEditor  : public Component,
                      public ComboBoxListener,
                      public SliderListener
{
public:
    //==============================================================================
    ReverbEditor ();
    ~ReverbEditor();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    //[/UserMethods]

    void paint (Graphics& g) override;
    void resized() override;
    void comboBoxChanged (ComboBox* comboBoxThatHasChanged) override;
    void sliderValueChanged (Slider* sliderThatWasMoved) override;



private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    //[/UserVariables]

    //==============================================================================
    ScopedPointer<PanelGroupGrey> m_reverbEditorPanelGroup;
    ScopedPointer<ParameterComboBox> m_reverbTypeComboBox;
    ScopedPointer<Label> m_reverbTypeLabel;
    ScopedPointer<Knob> m_timeSlider;
    ScopedPointer<Label> m_timeLabel;
    ScopedPointer<Label> m_dampLabel;
    ScopedPointer<Knob> m_levelSlider;
    ScopedPointer<Label> m_levelLabel;
    ScopedPointer<MicroParameterSlider> m_dampSlider;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (ReverbEditor)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

#endif   // __JUCE_HEADER_DB2227C1418B1EA__
