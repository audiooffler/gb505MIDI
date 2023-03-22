/*
  ==============================================================================

  This is an automatically generated GUI class created by the Projucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Projucer version: 7.0.2

  ------------------------------------------------------------------------------

  The Projucer is part of the JUCE library.
  Copyright (c) 2020 - Raw Material Software Limited.

  ==============================================================================
*/

#pragma once

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
#include "../GroupWidgets/PanelGroupTransp.h"
#include "../GroupWidgets/PanelGroupTransp.h"
#include "Envelope.h"
#include "../ParameterWidgets/BlackToggle.h"
#include "../GroupWidgets/PanelGroupTransp.h"


//==============================================================================
/**
                                                                    //[Comments]
An auto-generated component, created by the Introjucer.

Describe your class and how it works here!
                                                                    //[/Comments]
*/
class AmpEditorAdvanced  : public Component,
                           public juce::Slider::Listener,
                           public juce::ComboBox::Listener,
                           public juce::Button::Listener
{
public:
    //==============================================================================
    AmpEditorAdvanced (const String &componentName, SynthParts part, Tone tone);
    ~AmpEditorAdvanced() override;

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    //[/UserMethods]

    void paint (juce::Graphics& g) override;
    void resized() override;
    void sliderValueChanged (juce::Slider* sliderThatWasMoved) override;
    void comboBoxChanged (juce::ComboBox* comboBoxThatHasChanged) override;
    void buttonClicked (juce::Button* buttonThatWasClicked) override;

    // Binary resources:
    static const char* amp_png;
    static const int amp_pngSize;
    static const char* lfo_png;
    static const int lfo_pngSize;


private:
    //[UserVariables]   -- You can add your own custom variables in this section.
	SynthParts m_part;
	Tone m_tone;
    //[/UserVariables]

    //==============================================================================
    std::unique_ptr<PanelGroupGrey> m_ampGrp;
    std::unique_ptr<PanelGroupGrey> m_ampEnvGrp;
    std::unique_ptr<PanelGroupGrey> m_panGrp;
    std::unique_ptr<PanelGroupGrey> m_biasGrp;
    std::unique_ptr<Knob> m_tonePanSlider;
    std::unique_ptr<juce::Label> m_tonePanLabel;
    std::unique_ptr<Envelope> m_ampEnv;
    std::unique_ptr<juce::Label> m_panKeyfollowLabel;
    std::unique_ptr<KeyfollowMicroParameterSlider> m_panKeyfollowSlider;
    std::unique_ptr<MicroParameterSlider> m_ampVelocitySensSlider;
    std::unique_ptr<juce::Label> m_ampEnvVelocitySensLabel;
    std::unique_ptr<MicroParameterSlider> m_ampEnvVelocityTime1Slider;
    std::unique_ptr<juce::Label> m_ampEnvVelocityTime1Label;
    std::unique_ptr<MicroParameterSlider> m_ampEnvVelocityTime4Slider;
    std::unique_ptr<juce::Label> m_ampEnvVelocityTime4Label;
    std::unique_ptr<juce::Label> m_ampEnvTimeKeyfollow;
    std::unique_ptr<KeyfollowMicroParameterSlider> m_ampKeyfollowSlider;
    std::unique_ptr<ParameterComboBox> m_ampEnvVelCurveComboBox;
    std::unique_ptr<ParameterVelCurveDisplay> m_ampEnvVelCurveDisplay;
    std::unique_ptr<juce::Label> m_ampBiasDirectionLabel;
    std::unique_ptr<ParameterComboBox> m_ampBiasDirectionComboBox;
    std::unique_ptr<juce::Label> m_ampEnvVelocityCurveLabel;
    std::unique_ptr<juce::Label> m_biasPointLabel;
    std::unique_ptr<MicroParameterSlider> m_biasPointSlider;
    std::unique_ptr<juce::Label> m_biasLevelLabel;
    std::unique_ptr<MicroParameterSlider> m_biasLevelSlider;
    std::unique_ptr<BlackToggle> m_panRandomToggle;
    std::unique_ptr<juce::Label> m_panRandomLabel;
    std::unique_ptr<MicroParameterSlider> m_panAlternateSlider;
    std::unique_ptr<juce::Label> m_panAlternateLabel;
    std::unique_ptr<PanelGroupGrey> m_lfoGrp;
    std::unique_ptr<Knob> m_lfo1AmpDepthSlider;
    std::unique_ptr<juce::Label> m_lfo1AmpDepthLabel;
    std::unique_ptr<Knob> m_lfo2AmpDepthSlider;
    std::unique_ptr<juce::Label> m_lfo2AmpDepthLabel;
    std::unique_ptr<TextWithArrowButton> m_lfo1AdvancedButton;
    std::unique_ptr<TextWithArrowButton> m_lfo2AdvancedButton;
    std::unique_ptr<Knob> m_lfo1PanDepthSlider;
    std::unique_ptr<juce::Label> m_lfo1PanDepthLabel;
    std::unique_ptr<Knob> m_lfo2PanDepthSlider;
    std::unique_ptr<juce::Label> m_lfo2PanDepthLabel;
    std::unique_ptr<juce::ImageButton> m_imageButton;
    std::unique_ptr<ParameterEnvelopeSlider> m_toneLevelSlider;
    std::unique_ptr<juce::Label> m_filterEnvelopeDepthLabel;
    std::unique_ptr<juce::ImageButton> m_imageButton2;
    std::unique_ptr<juce::ImageButton> m_imageButton3;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (AmpEditorAdvanced)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

