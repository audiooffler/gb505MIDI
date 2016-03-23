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

#ifndef __JUCE_HEADER_B31AB66F482E3EDA__
#define __JUCE_HEADER_B31AB66F482E3EDA__

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
#include "../ParameterWidgets/BlackToggle.h"


//==============================================================================
/**
                                                                    //[Comments]
An auto-generated component, created by the Introjucer.

Describe your class and how it works here!
                                                                    //[/Comments]
*/
class AmpEditorAdvanced  : public Component,
                           public SliderListener,
                           public ComboBoxListener,
                           public ButtonListener
{
public:
    //==============================================================================
    AmpEditorAdvanced (const String &componentName, SynthParts part, Tone tone);
    ~AmpEditorAdvanced();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    //[/UserMethods]

    void paint (Graphics& g) override;
    void resized() override;
    void sliderValueChanged (Slider* sliderThatWasMoved) override;
    void comboBoxChanged (ComboBox* comboBoxThatHasChanged) override;
    void buttonClicked (Button* buttonThatWasClicked) override;

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
    ScopedPointer<PanelGroupGrey> m_ampGrp;
    ScopedPointer<PanelGroupGrey> m_ampEnvGrp;
    ScopedPointer<PanelGroupGrey> m_panGrp;
    ScopedPointer<PanelGroupGrey> m_biasGrp;
    ScopedPointer<Knob> m_tonePanSlider;
    ScopedPointer<Label> m_tonePanLabel;
    ScopedPointer<Envelope> m_ampEnv;
    ScopedPointer<Label> m_panKeyfollowLabel;
    ScopedPointer<KeyfollowMicroParameterSlider> m_panKeyfollowSlider;
    ScopedPointer<MicroParameterSlider> m_ampVelocitySensSlider;
    ScopedPointer<Label> m_ampEnvVelocitySensLabel;
    ScopedPointer<MicroParameterSlider> m_ampEnvVelocityTime1Slider;
    ScopedPointer<Label> m_ampEnvVelocityTime1Label;
    ScopedPointer<MicroParameterSlider> m_ampEnvVelocityTime4Slider;
    ScopedPointer<Label> m_ampEnvVelocityTime4Label;
    ScopedPointer<Label> m_ampEnvTimeKeyfollow;
    ScopedPointer<KeyfollowMicroParameterSlider> m_ampKeyfollowSlider;
    ScopedPointer<ParameterComboBox> m_ampEnvVelCurveComboBox;
    ScopedPointer<ParameterVelCurveDisplay> m_ampEnvVelCurveDisplay;
    ScopedPointer<Label> m_ampBiasDirectionLabel;
    ScopedPointer<ParameterComboBox> m_ampBiasDirectionComboBox;
    ScopedPointer<Label> m_ampEnvVelocityCurveLabel;
    ScopedPointer<Label> m_biasPointLabel;
    ScopedPointer<MicroParameterSlider> m_biasPointSlider;
    ScopedPointer<Label> m_biasLevelLabel;
    ScopedPointer<MicroParameterSlider> m_biasLevelSlider;
    ScopedPointer<BlackToggle> m_panRandomToggle;
    ScopedPointer<Label> m_panRandomLabel;
    ScopedPointer<MicroParameterSlider> m_panAlternateSlider;
    ScopedPointer<Label> m_panAlternateLabel;
    ScopedPointer<PanelGroupGrey> m_lfoGrp;
    ScopedPointer<Knob> m_lfo1AmpDepthSlider;
    ScopedPointer<Label> m_lfo1AmpDepthLabel;
    ScopedPointer<Knob> m_lfo2AmpDepthSlider;
    ScopedPointer<Label> m_lfo2AmpDepthLabel;
    ScopedPointer<TextWithArrowButton> m_lfo1AdvancedButton;
    ScopedPointer<TextWithArrowButton> m_lfo2AdvancedButton;
    ScopedPointer<Knob> m_lfo1PanDepthSlider;
    ScopedPointer<Label> m_lfo1PanDepthLabel;
    ScopedPointer<Knob> m_lfo2PanDepthSlider;
    ScopedPointer<Label> m_lfo2PanDepthLabel;
    ScopedPointer<ImageButton> m_imageButton;
    ScopedPointer<ParameterEnvelopeSlider> m_toneLevelSlider;
    ScopedPointer<Label> m_filterEnvelopeDepthLabel;
    ScopedPointer<ImageButton> m_imageButton2;
    ScopedPointer<ImageButton> m_imageButton3;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (AmpEditorAdvanced)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

#endif   // __JUCE_HEADER_B31AB66F482E3EDA__
