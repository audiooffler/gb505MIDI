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

#ifndef __JUCE_HEADER_656963D41A6E40C6__
#define __JUCE_HEADER_656963D41A6E40C6__

//[Headers]     -- You can add your own extra header files here --
#include "JuceHeader.h"
#include "../../GrooveboxMemory/GrooveboxMemoryBlock.h"
#include "../ParameterWidgets/MicroParameterSlider.h"
#include "../ParameterWidgets/ParameterComboBox.h"
#include "../ParameterWidgets/Knob.h"
#include "../ParameterWidgets/KeyfollowMicroParameterSlider.h"
#include "../ParameterWidgets/ParameterEnvelopeSlider.h"
#include "../ParameterWidgets/TextWithArrowButton.h"
#include "LfoEditorAdvanced.h"
//[/Headers]

#include "../GroupWidgets/PanelGroupGrey.h"
#include "../GroupWidgets/PanelGroupTransp.h"
#include "Envelope.h"


//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Introjucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class PitchEditorAdvanced  : public Component,
                             public SliderListener,
                             public LabelListener,
                             public ButtonListener,
                             public ComboBoxListener
{
public:
    //==============================================================================
    PitchEditorAdvanced (const String &componentName, SynthParts part, Tone tone);
    ~PitchEditorAdvanced();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    //[/UserMethods]

    void paint (Graphics& g) override;
    void resized() override;
    void sliderValueChanged (Slider* sliderThatWasMoved) override;
    void labelTextChanged (Label* labelThatHasChanged) override;
    void buttonClicked (Button* buttonThatWasClicked) override;
    void comboBoxChanged (ComboBox* comboBoxThatHasChanged) override;

    // Binary resources:
    static const char* pitch_png;
    static const int pitch_pngSize;
    static const char* lfo_png;
    static const int lfo_pngSize;


private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    SynthParts m_part;
    Tone m_tone;
    //[/UserVariables]

    //==============================================================================
    ScopedPointer<PanelGroupGrey> m_pitchGrp;
    ScopedPointer<PanelGroupGrey> m_lfoGrp;
    ScopedPointer<PanelGroupGrey> m_pitchGrp2;
    ScopedPointer<Knob> m_coarseTuneSlider;
    ScopedPointer<Label> m_coarseTuneLabel;
    ScopedPointer<Envelope> m_pitchEnv;
    ScopedPointer<MicroParameterSlider> m_randomPitchDepthSlider;
    ScopedPointer<Label> m_randomPitchDepthLabel;
    ScopedPointer<Label> m_pitchKeyfollowLabel;
    ScopedPointer<KeyfollowMicroParameterSlider> m_pitchKeyfollowSlider;
    ScopedPointer<ParameterEnvelopeSlider> m_pitchEnvelopeDepthSlider;
    ScopedPointer<Label> m_pitchEnvelopeDepthLabel;
    ScopedPointer<MicroParameterSlider> m_pitchVelocitySensSlider;
    ScopedPointer<Label> m_pitchEnvVelocitySensLabel;
    ScopedPointer<MicroParameterSlider> m_pitchEnvVelocityTime1Slider;
    ScopedPointer<Label> m_pitchEnvVelocityTime1Label;
    ScopedPointer<MicroParameterSlider> m_pitchEnvVelocityTime4Slider;
    ScopedPointer<Label> m_pitchEnvVelocityTime4Label;
    ScopedPointer<Label> m_pitchEnvTimeKeyfollow;
    ScopedPointer<KeyfollowMicroParameterSlider> m_pitchKeyfollowSlider2;
    ScopedPointer<Knob> m_fineTuneSlider;
    ScopedPointer<Label> m_fineTuneLabel;
    ScopedPointer<Knob> m_lfo1PitchDepthSlider;
    ScopedPointer<Label> m_lfo1PitchDepthLabel;
    ScopedPointer<Knob> m_lfo2PitchDepthSlider;
    ScopedPointer<Label> m_lfo2PitchDepthLabel;
    ScopedPointer<TextWithArrowButton> m_lfo1AdvancedButton;
    ScopedPointer<TextWithArrowButton> m_lfo2AdvancedButton;
    ScopedPointer<PanelGroupGrey> m_pitchCmnGrp;
    ScopedPointer<Label> m_bendDownLabel;
    ScopedPointer<MicroParameterSlider> m_bendDownSlider;
    ScopedPointer<MicroParameterSlider> m_bendUpSlider;
    ScopedPointer<Label> m_bendUpLabel;
    ScopedPointer<Label> m_stretchTuneDepthLabel;
    ScopedPointer<Label> m_stretchTuneDepthLabel2;
    ScopedPointer<ImageButton> imageButton5;
    ScopedPointer<ParameterComboBox> m_stretchTuneDepthComboBox;
    ScopedPointer<ImageButton> imageButton2;
    ScopedPointer<ImageButton> m_imageButton3;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (PitchEditorAdvanced)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

#endif   // __JUCE_HEADER_656963D41A6E40C6__
