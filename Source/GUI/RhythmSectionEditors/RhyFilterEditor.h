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

#ifndef __JUCE_HEADER_FF653CD1685BA2E0__
#define __JUCE_HEADER_FF653CD1685BA2E0__

//[Headers]     -- You can add your own extra header files here --
#include "JuceHeader.h"
#include "../../GrooveboxMemory/GrooveboxMemoryBlock.h"
#include "../ParameterWidgets/MicroParameterSlider.h"
#include "../ParameterWidgets/ParameterComboBox.h"
#include "../ParameterWidgets/Knob.h"
#include "../ParameterWidgets/KeyfollowMicroParameterSlider.h"
#include "../ParameterWidgets/ParameterEnvelopeSlider.h"
#include "../ParameterWidgets/ParameterVelCurveDisplay.h"
#include "../ParameterWidgets/TextWithArrowButton.h"
//[/Headers]

#include "../GroupWidgets/PanelGroupGrey.h"
#include "../GroupWidgets/PanelGroupTransp.h"
#include "../PatchSectionEditors/Envelope.h"


//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Introjucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class RhyFilterEditor  : public Component,
                         public Slider::Listener,
                         public ComboBox::Listener
{
public:
    //==============================================================================
    RhyFilterEditor (const String &componentName, int toneNumber);
    ~RhyFilterEditor();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
	void setupParameters(int toneNumber);
    //[/UserMethods]

    void paint (Graphics& g) override;
    void resized() override;
    void sliderValueChanged (Slider* sliderThatWasMoved) override;
    void comboBoxChanged (ComboBox* comboBoxThatHasChanged) override;

    // Binary resources:
    static const char* filter_png;
    static const int filter_pngSize;


private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    int m_toneNumber;
    //[/UserVariables]

    //==============================================================================
    ScopedPointer<PanelGroupGrey> m_filterGrp;
    ScopedPointer<PanelGroupGrey> m_filterGrp2;
    ScopedPointer<Knob> m_cutoffSlider;
    ScopedPointer<Label> m_cutoffLabel;
    ScopedPointer<Envelope> m_filterEnv;
    ScopedPointer<ParameterEnvelopeSlider> m_filterEnvelopeDepthSlider;
    ScopedPointer<Label> m_filterEnvelopeDepthLabel;
    ScopedPointer<MicroParameterSlider> m_filterVelocitySensSlider;
    ScopedPointer<Label> m_filterEnvVelocitySensLabel;
    ScopedPointer<MicroParameterSlider> m_filterEnvVelocityTime1Slider;
    ScopedPointer<Label> m_filterEnvVelocityTime1Label;
    ScopedPointer<Knob> m_resonanceSlider;
    ScopedPointer<Label> m_resonanceLabel;
    ScopedPointer<Label> m_resonanceVelocitySensLabel;
    ScopedPointer<MicroParameterSlider> m_resonanceVelocitySensSlider;
    ScopedPointer<Label> m_filterTypeLabel;
    ScopedPointer<ParameterComboBox> m_filterTypeComboBox;
    ScopedPointer<ImageButton> m_imageButton;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (RhyFilterEditor)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

#endif   // __JUCE_HEADER_FF653CD1685BA2E0__
