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

#ifndef __JUCE_HEADER_E9A481748703B30E__
#define __JUCE_HEADER_E9A481748703B30E__

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
class FilterEditorAdvanced  : public Component,
                              public SliderListener,
                              public ComboBoxListener,
                              public ButtonListener
{
public:
    //==============================================================================
    FilterEditorAdvanced (const String &componentName, SynthParts part, Tone tone);
    ~FilterEditorAdvanced();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    //[/UserMethods]

    void paint (Graphics& g) override;
    void resized() override;
    void sliderValueChanged (Slider* sliderThatWasMoved) override;
    void comboBoxChanged (ComboBox* comboBoxThatHasChanged) override;
    void buttonClicked (Button* buttonThatWasClicked) override;

    // Binary resources:
    static const char* filter_png;
    static const int filter_pngSize;
    static const char* lfo_png;
    static const int lfo_pngSize;


private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    SynthParts m_part;
    Tone m_tone;
    //[/UserVariables]

    //==============================================================================
    ScopedPointer<PanelGroupGrey> m_filterGrp;
    ScopedPointer<PanelGroupGrey> m_filterGrp2;
    ScopedPointer<Knob> m_cutoffSlider;
    ScopedPointer<Label> m_cutoffLabel;
    ScopedPointer<Envelope> m_filterEnv;
    ScopedPointer<Label> m_cutoffKeyfollowLabel;
    ScopedPointer<KeyfollowMicroParameterSlider> m_cutoffKeyfollowSlider;
    ScopedPointer<ParameterEnvelopeSlider> m_filterEnvelopeDepthSlider;
    ScopedPointer<Label> m_filterEnvelopeDepthLabel;
    ScopedPointer<MicroParameterSlider> m_filterVelocitySensSlider;
    ScopedPointer<Label> m_filterEnvVelocitySensLabel;
    ScopedPointer<MicroParameterSlider> m_filterEnvVelocityTime1Slider;
    ScopedPointer<Label> m_filterEnvVelocityTime1Label;
    ScopedPointer<MicroParameterSlider> m_filterEnvVelocityTime4Slider;
    ScopedPointer<Label> m_filterEnvVelocityTime4Label;
    ScopedPointer<Label> m_filterEnvTimeKeyfollow;
    ScopedPointer<KeyfollowMicroParameterSlider> m_filterKeyfollowSlider;
    ScopedPointer<Knob> m_resonanceSlider;
    ScopedPointer<Label> m_resonanceLabel;
    ScopedPointer<ParameterComboBox> m_filterEnvVelCurveComboBox;
    ScopedPointer<ParameterVelCurveDisplay> m_filterEnvVelCurveDisplay;
    ScopedPointer<Label> m_resonanceVelocitySensLabel;
    ScopedPointer<MicroParameterSlider> m_resonanceVelocitySensSlider;
    ScopedPointer<Label> m_filterTypeLabel;
    ScopedPointer<ParameterComboBox> m_filterTypeComboBox;
    ScopedPointer<Label> m_filterEnvVelocityCurveLabel;
    ScopedPointer<PanelGroupGrey> m_lfoGrp;
    ScopedPointer<Knob> m_lfo1FilterDepthSlider;
    ScopedPointer<Label> m_lfo1FilterDepthLabel;
    ScopedPointer<Knob> m_lfo2FilterDepthSlider;
    ScopedPointer<Label> m_lfo2FilterDepthLabel;
    ScopedPointer<TextWithArrowButton> m_lfo1AdvancedButton;
    ScopedPointer<TextWithArrowButton> m_lfo2AdvancedButton;
    ScopedPointer<ImageButton> m_imageButton;
    ScopedPointer<ImageButton> m_imageButton2;
    ScopedPointer<ImageButton> m_imageButton3;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (FilterEditorAdvanced)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

#endif   // __JUCE_HEADER_E9A481748703B30E__
