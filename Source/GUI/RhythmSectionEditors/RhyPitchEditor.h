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

#ifndef __JUCE_HEADER_F0A4A52A85C9DC44__
#define __JUCE_HEADER_F0A4A52A85C9DC44__

//[Headers]     -- You can add your own extra header files here --
#include "JuceHeader.h"
#include "../../GrooveboxMemory/GrooveboxMemoryBlock.h"
#include "../ParameterWidgets/MicroParameterSlider.h"
#include "../ParameterWidgets/ParameterComboBox.h"
#include "../ParameterWidgets/Knob.h"
#include "../ParameterWidgets/KeyfollowMicroParameterSlider.h"
#include "../ParameterWidgets/ParameterEnvelopeSlider.h"
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
class RhyPitchEditor  : public Component,
                        public SliderListener,
                        public LabelListener
{
public:
    //==============================================================================
    RhyPitchEditor (const String &componentName, int toneNumber);
    ~RhyPitchEditor();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    void setupParameters(int toneNumber);
    //[/UserMethods]

    void paint (Graphics& g) override;
    void resized() override;
    void sliderValueChanged (Slider* sliderThatWasMoved) override;
    void labelTextChanged (Label* labelThatHasChanged) override;

    // Binary resources:
    static const char* pitch_png;
    static const int pitch_pngSize;


private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    int m_toneNumber = 35;
    //[/UserVariables]

    //==============================================================================
    ScopedPointer<PanelGroupGrey> m_pitchGrp;
    ScopedPointer<PanelGroupGrey> m_pitchGrp2;
    ScopedPointer<Knob> m_coarseTuneSlider;
    ScopedPointer<Label> m_coarseTuneLabel;
    ScopedPointer<Envelope> m_pitchEnv;
    ScopedPointer<MicroParameterSlider> m_randomPitchDepthSlider;
    ScopedPointer<Label> m_randomPitchDepthLabel;
    ScopedPointer<ParameterEnvelopeSlider> m_pitchEnvelopeDepthSlider;
    ScopedPointer<Label> m_pitchEnvelopeDepthLabel;
    ScopedPointer<MicroParameterSlider> m_pitchVelocitySensSlider;
    ScopedPointer<Label> m_pitchEnvVelocitySensLabel;
    ScopedPointer<MicroParameterSlider> m_pitchEnvVelocityTime1Slider;
    ScopedPointer<Label> m_pitchEnvVelocityTime1Label;
    ScopedPointer<Knob> m_fineTuneSlider;
    ScopedPointer<Label> m_fineTuneLabel;
    ScopedPointer<MicroParameterSlider> m_bendRangeSlider;
    ScopedPointer<Label> m_stretchTuneDepthLabel2;
    ScopedPointer<ImageButton> imageButton5;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (RhyPitchEditor)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

#endif   // __JUCE_HEADER_F0A4A52A85C9DC44__
