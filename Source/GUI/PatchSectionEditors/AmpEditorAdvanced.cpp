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

//[Headers] You can add your own extra header files here...
#include "../../GrooveboxMemory/OverallMemoryBlock.h"
//[/Headers]

#include "AmpEditorAdvanced.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
extern OverallMemoryBlock* grooveboxMemory;
//[/MiscUserDefs]

//==============================================================================
AmpEditorAdvanced::AmpEditorAdvanced (const String &componentName, SynthParts part, Tone tone)
    : Component (componentName), m_part(part), m_tone(tone)
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    m_ampGrp.reset (new PanelGroupGrey ("ampGrp", getName()));
    addAndMakeVisible (m_ampGrp.get());
    m_ampEnvGrp.reset (new PanelGroupGrey ("ampEnvGrp", getName().toUpperCase()+" ENVELOPE"));
    addAndMakeVisible (m_ampEnvGrp.get());
    m_panGrp.reset (new PanelGroupGrey ("panGrp", "PAN"));
    addAndMakeVisible (m_panGrp.get());
    m_biasGrp.reset (new PanelGroupGrey ("biasGrp", "BIAS"));
    addAndMakeVisible (m_biasGrp.get());
    m_tonePanSlider.reset (new Knob ("tonePanSlider"));
    addAndMakeVisible (m_tonePanSlider.get());
    m_tonePanSlider->setRange (0, 127, 1);
    m_tonePanSlider->setSliderStyle (juce::Slider::RotaryHorizontalVerticalDrag);
    m_tonePanSlider->setTextBoxStyle (juce::Slider::TextBoxBelow, false, 80, 16);
    m_tonePanSlider->setColour (juce::Slider::textBoxBackgroundColourId, juce::Colour (0xfff2f59b));
    m_tonePanSlider->addListener (this);

    m_tonePanSlider->setBounds (208, 40, 48, 60);

    m_tonePanLabel.reset (new juce::Label ("tonePanLabel",
                                           TRANS("TONE PAN")));
    addAndMakeVisible (m_tonePanLabel.get());
    m_tonePanLabel->setFont (juce::Font (12.00f, juce::Font::plain).withTypefaceStyle ("Bold"));
    m_tonePanLabel->setJustificationType (juce::Justification::centred);
    m_tonePanLabel->setEditable (false, false, false);
    m_tonePanLabel->setColour (juce::Label::textColourId, juce::Colours::black);
    m_tonePanLabel->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    m_tonePanLabel->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    m_tonePanLabel->setBounds (196, 20, 72, 16);

    m_ampEnv.reset (new Envelope ((AllParts)m_part, m_tone, EnvelopeTypes::Amp, false));
    addAndMakeVisible (m_ampEnv.get());
    m_ampEnv->setBounds (72, 156, 296, 156);

    m_panKeyfollowLabel.reset (new juce::Label ("panKeyfollowLabel",
                                                TRANS("KEYFOLLOW")));
    addAndMakeVisible (m_panKeyfollowLabel.get());
    m_panKeyfollowLabel->setFont (juce::Font (12.00f, juce::Font::plain).withTypefaceStyle ("Bold"));
    m_panKeyfollowLabel->setJustificationType (juce::Justification::centred);
    m_panKeyfollowLabel->setEditable (false, false, false);
    m_panKeyfollowLabel->setColour (juce::Label::textColourId, juce::Colours::black);
    m_panKeyfollowLabel->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    m_panKeyfollowLabel->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    m_panKeyfollowLabel->setBounds (280, 32, 80, 16);

    m_panKeyfollowSlider.reset (new KeyfollowMicroParameterSlider ("panKeyfollowSlider"));
    addAndMakeVisible (m_panKeyfollowSlider.get());
    m_panKeyfollowSlider->setRange (0, 127, 1);
    m_panKeyfollowSlider->setSliderStyle (juce::Slider::LinearBar);
    m_panKeyfollowSlider->setTextBoxStyle (juce::Slider::TextBoxLeft, false, 40, 20);
    m_panKeyfollowSlider->setColour (juce::Slider::backgroundColourId, juce::Colour (0xfff2f59b));
    m_panKeyfollowSlider->setColour (juce::Slider::thumbColourId, juce::Colour (0xffc4c86d));
    m_panKeyfollowSlider->addListener (this);

    m_panKeyfollowSlider->setBounds (296, 48, 48, 16);

    m_ampVelocitySensSlider.reset (new MicroParameterSlider ("ampVelocitySensSlider"));
    addAndMakeVisible (m_ampVelocitySensSlider.get());
    m_ampVelocitySensSlider->setRange (0, 127, 1);
    m_ampVelocitySensSlider->setSliderStyle (juce::Slider::LinearBar);
    m_ampVelocitySensSlider->setTextBoxStyle (juce::Slider::TextBoxLeft, false, 40, 20);
    m_ampVelocitySensSlider->setColour (juce::Slider::backgroundColourId, juce::Colour (0xfff2f59b));
    m_ampVelocitySensSlider->setColour (juce::Slider::thumbColourId, juce::Colour (0xffc4c86d));
    m_ampVelocitySensSlider->addListener (this);

    m_ampVelocitySensSlider->setBounds (8, 306, 56, 16);

    m_ampEnvVelocitySensLabel.reset (new juce::Label ("ampEnvVelocitySensLabel",
                                                      TRANS("VELO SENS")));
    addAndMakeVisible (m_ampEnvVelocitySensLabel.get());
    m_ampEnvVelocitySensLabel->setFont (juce::Font (12.00f, juce::Font::plain).withTypefaceStyle ("Bold"));
    m_ampEnvVelocitySensLabel->setJustificationType (juce::Justification::centred);
    m_ampEnvVelocitySensLabel->setEditable (false, false, false);
    m_ampEnvVelocitySensLabel->setColour (juce::Label::textColourId, juce::Colours::black);
    m_ampEnvVelocitySensLabel->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    m_ampEnvVelocitySensLabel->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    m_ampEnvVelocitySensLabel->setBounds (0, 290, 72, 16);

    m_ampEnvVelocityTime1Slider.reset (new MicroParameterSlider ("ampEnvVelocityTime1Slider"));
    addAndMakeVisible (m_ampEnvVelocityTime1Slider.get());
    m_ampEnvVelocityTime1Slider->setRange (0, 127, 1);
    m_ampEnvVelocityTime1Slider->setSliderStyle (juce::Slider::LinearBar);
    m_ampEnvVelocityTime1Slider->setTextBoxStyle (juce::Slider::TextBoxLeft, false, 40, 20);
    m_ampEnvVelocityTime1Slider->setColour (juce::Slider::backgroundColourId, juce::Colour (0xfff2f59b));
    m_ampEnvVelocityTime1Slider->setColour (juce::Slider::thumbColourId, juce::Colour (0xffc4c86d));
    m_ampEnvVelocityTime1Slider->addListener (this);

    m_ampEnvVelocityTime1Slider->setBounds (124, 332, 56, 16);

    m_ampEnvVelocityTime1Label.reset (new juce::Label ("ampEnvVelocityTime1Label",
                                                       TRANS("VELO SENS TIME 1")));
    addAndMakeVisible (m_ampEnvVelocityTime1Label.get());
    m_ampEnvVelocityTime1Label->setFont (juce::Font (12.00f, juce::Font::plain).withTypefaceStyle ("Bold"));
    m_ampEnvVelocityTime1Label->setJustificationType (juce::Justification::centred);
    m_ampEnvVelocityTime1Label->setEditable (false, false, false);
    m_ampEnvVelocityTime1Label->setColour (juce::Label::textColourId, juce::Colours::black);
    m_ampEnvVelocityTime1Label->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    m_ampEnvVelocityTime1Label->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    m_ampEnvVelocityTime1Label->setBounds (84, 316, 112, 16);

    m_ampEnvVelocityTime4Slider.reset (new MicroParameterSlider ("ampEnvVelocityTime4Slider"));
    addAndMakeVisible (m_ampEnvVelocityTime4Slider.get());
    m_ampEnvVelocityTime4Slider->setRange (0, 127, 1);
    m_ampEnvVelocityTime4Slider->setSliderStyle (juce::Slider::LinearBar);
    m_ampEnvVelocityTime4Slider->setTextBoxStyle (juce::Slider::TextBoxLeft, false, 40, 20);
    m_ampEnvVelocityTime4Slider->setColour (juce::Slider::backgroundColourId, juce::Colour (0xfff2f59b));
    m_ampEnvVelocityTime4Slider->setColour (juce::Slider::thumbColourId, juce::Colour (0xffc4c86d));
    m_ampEnvVelocityTime4Slider->addListener (this);

    m_ampEnvVelocityTime4Slider->setBounds (300, 332, 56, 16);

    m_ampEnvVelocityTime4Label.reset (new juce::Label ("ampEnvVelocityTime4Label",
                                                       TRANS("VELO SENS TIME 4")));
    addAndMakeVisible (m_ampEnvVelocityTime4Label.get());
    m_ampEnvVelocityTime4Label->setFont (juce::Font (12.00f, juce::Font::plain).withTypefaceStyle ("Bold"));
    m_ampEnvVelocityTime4Label->setJustificationType (juce::Justification::centred);
    m_ampEnvVelocityTime4Label->setEditable (false, false, false);
    m_ampEnvVelocityTime4Label->setColour (juce::Label::textColourId, juce::Colours::black);
    m_ampEnvVelocityTime4Label->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    m_ampEnvVelocityTime4Label->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    m_ampEnvVelocityTime4Label->setBounds (264, 316, 112, 16);

    m_ampEnvTimeKeyfollow.reset (new juce::Label ("ampEnvTimeKeyfollow",
                                                  TRANS("KEYFOLLOW TIME 2/3/4 ")));
    addAndMakeVisible (m_ampEnvTimeKeyfollow.get());
    m_ampEnvTimeKeyfollow->setFont (juce::Font (12.00f, juce::Font::plain).withTypefaceStyle ("Bold"));
    m_ampEnvTimeKeyfollow->setJustificationType (juce::Justification::centred);
    m_ampEnvTimeKeyfollow->setEditable (false, false, false);
    m_ampEnvTimeKeyfollow->setColour (juce::Label::textColourId, juce::Colours::black);
    m_ampEnvTimeKeyfollow->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    m_ampEnvTimeKeyfollow->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    m_ampEnvTimeKeyfollow->setBounds (184, 356, 172, 16);

    m_ampKeyfollowSlider.reset (new KeyfollowMicroParameterSlider ("ampKeyfollowSlider"));
    addAndMakeVisible (m_ampKeyfollowSlider.get());
    m_ampKeyfollowSlider->setRange (0, 127, 1);
    m_ampKeyfollowSlider->setSliderStyle (juce::Slider::LinearBar);
    m_ampKeyfollowSlider->setTextBoxStyle (juce::Slider::TextBoxLeft, false, 40, 20);
    m_ampKeyfollowSlider->setColour (juce::Slider::backgroundColourId, juce::Colour (0xfff2f59b));
    m_ampKeyfollowSlider->setColour (juce::Slider::thumbColourId, juce::Colour (0xffc4c86d));
    m_ampKeyfollowSlider->addListener (this);

    m_ampKeyfollowSlider->setBounds (252, 372, 56, 16);

    m_ampEnvVelCurveComboBox.reset (new ParameterComboBox ("ampEnvVelCurveComboBox"));
    addAndMakeVisible (m_ampEnvVelCurveComboBox.get());
    m_ampEnvVelCurveComboBox->setEditableText (false);
    m_ampEnvVelCurveComboBox->setJustificationType (juce::Justification::centred);
    m_ampEnvVelCurveComboBox->setTextWhenNothingSelected (TRANS("Normal"));
    m_ampEnvVelCurveComboBox->setTextWhenNoChoicesAvailable (TRANS("(no choices)"));
    m_ampEnvVelCurveComboBox->addListener (this);

    m_ampEnvVelCurveComboBox->setBounds (8, 343, 68, 16);

    m_ampEnvVelCurveDisplay.reset (new ParameterVelCurveDisplay ("ampEnvVelCurveDisplay"));
    addAndMakeVisible (m_ampEnvVelCurveDisplay.get());
    m_ampEnvVelCurveDisplay->setRange (0, 10, 0);
    m_ampEnvVelCurveDisplay->setSliderStyle (juce::Slider::RotaryHorizontalVerticalDrag);
    m_ampEnvVelCurveDisplay->setTextBoxStyle (juce::Slider::NoTextBox, false, 80, 20);
    m_ampEnvVelCurveDisplay->addListener (this);

    m_ampEnvVelCurveDisplay->setBounds (20, 363, 36, 36);

    m_ampBiasDirectionLabel.reset (new juce::Label ("ampBiasDirectionLabel",
                                                    TRANS("DIRECTION")));
    addAndMakeVisible (m_ampBiasDirectionLabel.get());
    m_ampBiasDirectionLabel->setFont (juce::Font (12.00f, juce::Font::plain).withTypefaceStyle ("Bold"));
    m_ampBiasDirectionLabel->setJustificationType (juce::Justification::centred);
    m_ampBiasDirectionLabel->setEditable (false, false, false);
    m_ampBiasDirectionLabel->setColour (juce::Label::textColourId, juce::Colours::black);
    m_ampBiasDirectionLabel->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    m_ampBiasDirectionLabel->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    m_ampBiasDirectionLabel->setBounds (96, 32, 84, 16);

    m_ampBiasDirectionComboBox.reset (new ParameterComboBox ("ampBiasDirectionComboBox"));
    addAndMakeVisible (m_ampBiasDirectionComboBox.get());
    m_ampBiasDirectionComboBox->setEditableText (false);
    m_ampBiasDirectionComboBox->setJustificationType (juce::Justification::centred);
    m_ampBiasDirectionComboBox->setTextWhenNothingSelected (juce::String());
    m_ampBiasDirectionComboBox->setTextWhenNoChoicesAvailable (TRANS("(no choices)"));
    m_ampBiasDirectionComboBox->addListener (this);

    m_ampBiasDirectionComboBox->setBounds (88, 48, 100, 16);

    m_ampEnvVelocityCurveLabel.reset (new juce::Label ("ampEnvVelocityCurveLabel",
                                                       TRANS("VELO CURVE")));
    addAndMakeVisible (m_ampEnvVelocityCurveLabel.get());
    m_ampEnvVelocityCurveLabel->setFont (juce::Font (12.00f, juce::Font::plain).withTypefaceStyle ("Bold"));
    m_ampEnvVelocityCurveLabel->setJustificationType (juce::Justification::centred);
    m_ampEnvVelocityCurveLabel->setEditable (false, false, false);
    m_ampEnvVelocityCurveLabel->setColour (juce::Label::textColourId, juce::Colours::black);
    m_ampEnvVelocityCurveLabel->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    m_ampEnvVelocityCurveLabel->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    m_ampEnvVelocityCurveLabel->setBounds (0, 327, 80, 16);

    m_biasPointLabel.reset (new juce::Label ("biasPointLabel",
                                             TRANS("POINT")));
    addAndMakeVisible (m_biasPointLabel.get());
    m_biasPointLabel->setFont (juce::Font (12.00f, juce::Font::plain).withTypefaceStyle ("Bold"));
    m_biasPointLabel->setJustificationType (juce::Justification::centred);
    m_biasPointLabel->setEditable (false, false, false);
    m_biasPointLabel->setColour (juce::Label::textColourId, juce::Colours::black);
    m_biasPointLabel->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    m_biasPointLabel->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    m_biasPointLabel->setBounds (88, 68, 48, 16);

    m_biasPointSlider.reset (new MicroParameterSlider ("biasPointSlider"));
    addAndMakeVisible (m_biasPointSlider.get());
    m_biasPointSlider->setRange (0, 127, 1);
    m_biasPointSlider->setSliderStyle (juce::Slider::LinearBar);
    m_biasPointSlider->setTextBoxStyle (juce::Slider::TextBoxLeft, false, 40, 20);
    m_biasPointSlider->setColour (juce::Slider::backgroundColourId, juce::Colour (0xfff2f59b));
    m_biasPointSlider->setColour (juce::Slider::thumbColourId, juce::Colour (0xffc4c86d));
    m_biasPointSlider->addListener (this);

    m_biasPointSlider->setBounds (88, 84, 48, 16);

    m_biasLevelLabel.reset (new juce::Label ("biasLevelLabel",
                                             TRANS("LEVEL")));
    addAndMakeVisible (m_biasLevelLabel.get());
    m_biasLevelLabel->setFont (juce::Font (12.00f, juce::Font::plain).withTypefaceStyle ("Bold"));
    m_biasLevelLabel->setJustificationType (juce::Justification::centred);
    m_biasLevelLabel->setEditable (false, false, false);
    m_biasLevelLabel->setColour (juce::Label::textColourId, juce::Colours::black);
    m_biasLevelLabel->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    m_biasLevelLabel->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    m_biasLevelLabel->setBounds (140, 68, 48, 16);

    m_biasLevelSlider.reset (new MicroParameterSlider ("biasLevelSlider"));
    addAndMakeVisible (m_biasLevelSlider.get());
    m_biasLevelSlider->setRange (0, 127, 1);
    m_biasLevelSlider->setSliderStyle (juce::Slider::LinearBar);
    m_biasLevelSlider->setTextBoxStyle (juce::Slider::TextBoxLeft, false, 40, 20);
    m_biasLevelSlider->setColour (juce::Slider::backgroundColourId, juce::Colour (0xfff2f59b));
    m_biasLevelSlider->setColour (juce::Slider::thumbColourId, juce::Colour (0xffc4c86d));
    m_biasLevelSlider->addListener (this);

    m_biasLevelSlider->setBounds (140, 84, 48, 16);

    m_panRandomToggle.reset (new BlackToggle());
    addAndMakeVisible (m_panRandomToggle.get());
    m_panRandomToggle->setBounds (307, 82, 25, 17);

    m_panRandomLabel.reset (new juce::Label ("panRandomLabel",
                                             TRANS("RANDOM")));
    addAndMakeVisible (m_panRandomLabel.get());
    m_panRandomLabel->setFont (juce::Font (12.00f, juce::Font::plain).withTypefaceStyle ("Bold"));
    m_panRandomLabel->setJustificationType (juce::Justification::centred);
    m_panRandomLabel->setEditable (false, false, false);
    m_panRandomLabel->setColour (juce::Label::textColourId, juce::Colours::black);
    m_panRandomLabel->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    m_panRandomLabel->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    m_panRandomLabel->setBounds (287, 66, 64, 16);

    m_panAlternateSlider.reset (new MicroParameterSlider ("panAlternateSlider"));
    addAndMakeVisible (m_panAlternateSlider.get());
    m_panAlternateSlider->setRange (0, 127, 1);
    m_panAlternateSlider->setSliderStyle (juce::Slider::LinearBar);
    m_panAlternateSlider->setTextBoxStyle (juce::Slider::TextBoxLeft, false, 40, 20);
    m_panAlternateSlider->setColour (juce::Slider::backgroundColourId, juce::Colour (0xfff2f59b));
    m_panAlternateSlider->setColour (juce::Slider::thumbColourId, juce::Colour (0xffc4c86d));
    m_panAlternateSlider->addListener (this);

    m_panAlternateSlider->setBounds (292, 116, 56, 16);

    m_panAlternateLabel.reset (new juce::Label ("panAlternateLabel",
                                                TRANS("ALTERNATE")));
    addAndMakeVisible (m_panAlternateLabel.get());
    m_panAlternateLabel->setFont (juce::Font (12.00f, juce::Font::plain).withTypefaceStyle ("Bold"));
    m_panAlternateLabel->setJustificationType (juce::Justification::centred);
    m_panAlternateLabel->setEditable (false, false, false);
    m_panAlternateLabel->setColour (juce::Label::textColourId, juce::Colours::black);
    m_panAlternateLabel->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    m_panAlternateLabel->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    m_panAlternateLabel->setBounds (280, 100, 80, 16);

    m_lfoGrp.reset (new PanelGroupGrey ("lfoGrp", "LFO MODULATION"));
    addAndMakeVisible (m_lfoGrp.get());
    m_lfo1AmpDepthSlider.reset (new Knob ("lfo1AmpDepthSlider"));
    addAndMakeVisible (m_lfo1AmpDepthSlider.get());
    m_lfo1AmpDepthSlider->setRange (0, 127, 1);
    m_lfo1AmpDepthSlider->setSliderStyle (juce::Slider::RotaryHorizontalVerticalDrag);
    m_lfo1AmpDepthSlider->setTextBoxStyle (juce::Slider::TextBoxBelow, false, 80, 16);
    m_lfo1AmpDepthSlider->setColour (juce::Slider::textBoxBackgroundColourId, juce::Colour (0xfff2f59b));
    m_lfo1AmpDepthSlider->addListener (this);

    m_lfo1AmpDepthSlider->setBounds (16, 436, 32, 48);

    m_lfo1AmpDepthLabel.reset (new juce::Label ("lfo1AmpDepthLabel",
                                                TRANS("LVL LFO 1")));
    addAndMakeVisible (m_lfo1AmpDepthLabel.get());
    m_lfo1AmpDepthLabel->setFont (juce::Font (12.00f, juce::Font::plain).withTypefaceStyle ("Bold"));
    m_lfo1AmpDepthLabel->setJustificationType (juce::Justification::centred);
    m_lfo1AmpDepthLabel->setEditable (false, false, false);
    m_lfo1AmpDepthLabel->setColour (juce::Label::textColourId, juce::Colours::black);
    m_lfo1AmpDepthLabel->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    m_lfo1AmpDepthLabel->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    m_lfo1AmpDepthLabel->setBounds (0, 420, 68, 16);

    m_lfo2AmpDepthSlider.reset (new Knob ("lfo2AmpDepthSlider"));
    addAndMakeVisible (m_lfo2AmpDepthSlider.get());
    m_lfo2AmpDepthSlider->setRange (0, 127, 1);
    m_lfo2AmpDepthSlider->setSliderStyle (juce::Slider::RotaryHorizontalVerticalDrag);
    m_lfo2AmpDepthSlider->setTextBoxStyle (juce::Slider::TextBoxBelow, false, 80, 16);
    m_lfo2AmpDepthSlider->setColour (juce::Slider::textBoxBackgroundColourId, juce::Colour (0xfff2f59b));
    m_lfo2AmpDepthSlider->addListener (this);

    m_lfo2AmpDepthSlider->setBounds (204, 436, 32, 48);

    m_lfo2AmpDepthLabel.reset (new juce::Label ("lfo2AmpDepthLabel",
                                                TRANS("LVL LFO 2")));
    addAndMakeVisible (m_lfo2AmpDepthLabel.get());
    m_lfo2AmpDepthLabel->setFont (juce::Font (12.00f, juce::Font::plain).withTypefaceStyle ("Bold"));
    m_lfo2AmpDepthLabel->setJustificationType (juce::Justification::centred);
    m_lfo2AmpDepthLabel->setEditable (false, false, false);
    m_lfo2AmpDepthLabel->setColour (juce::Label::textColourId, juce::Colours::black);
    m_lfo2AmpDepthLabel->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    m_lfo2AmpDepthLabel->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    m_lfo2AmpDepthLabel->setBounds (188, 420, 68, 16);

    m_lfo1AdvancedButton.reset (new TextWithArrowButton ("lfo1AdvancedButton"));
    addAndMakeVisible (m_lfo1AdvancedButton.get());
    m_lfo1AdvancedButton->setButtonText (TRANS("LFO 1"));
    m_lfo1AdvancedButton->addListener (this);

    m_lfo1AdvancedButton->setBounds (124, 464, 56, 21);

    m_lfo2AdvancedButton.reset (new TextWithArrowButton ("lfo2AdvancedButton"));
    addAndMakeVisible (m_lfo2AdvancedButton.get());
    m_lfo2AdvancedButton->setButtonText (TRANS("LFO 2"));
    m_lfo2AdvancedButton->addListener (this);

    m_lfo2AdvancedButton->setBounds (312, 464, 56, 21);

    m_lfo1PanDepthSlider.reset (new Knob ("lfo1PanDepthSlider"));
    addAndMakeVisible (m_lfo1PanDepthSlider.get());
    m_lfo1PanDepthSlider->setRange (0, 127, 1);
    m_lfo1PanDepthSlider->setSliderStyle (juce::Slider::RotaryHorizontalVerticalDrag);
    m_lfo1PanDepthSlider->setTextBoxStyle (juce::Slider::TextBoxBelow, false, 80, 16);
    m_lfo1PanDepthSlider->setColour (juce::Slider::textBoxBackgroundColourId, juce::Colour (0xfff2f59b));
    m_lfo1PanDepthSlider->addListener (this);

    m_lfo1PanDepthSlider->setBounds (84, 436, 32, 48);

    m_lfo1PanDepthLabel.reset (new juce::Label ("lfo1PanDepthLabel",
                                                TRANS("PAN LFO 1")));
    addAndMakeVisible (m_lfo1PanDepthLabel.get());
    m_lfo1PanDepthLabel->setFont (juce::Font (12.00f, juce::Font::plain).withTypefaceStyle ("Bold"));
    m_lfo1PanDepthLabel->setJustificationType (juce::Justification::centred);
    m_lfo1PanDepthLabel->setEditable (false, false, false);
    m_lfo1PanDepthLabel->setColour (juce::Label::textColourId, juce::Colours::black);
    m_lfo1PanDepthLabel->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    m_lfo1PanDepthLabel->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    m_lfo1PanDepthLabel->setBounds (68, 420, 68, 16);

    m_lfo2PanDepthSlider.reset (new Knob ("lfo2PanDepthSlider"));
    addAndMakeVisible (m_lfo2PanDepthSlider.get());
    m_lfo2PanDepthSlider->setRange (0, 127, 1);
    m_lfo2PanDepthSlider->setSliderStyle (juce::Slider::RotaryHorizontalVerticalDrag);
    m_lfo2PanDepthSlider->setTextBoxStyle (juce::Slider::TextBoxBelow, false, 80, 16);
    m_lfo2PanDepthSlider->setColour (juce::Slider::textBoxBackgroundColourId, juce::Colour (0xfff2f59b));
    m_lfo2PanDepthSlider->addListener (this);

    m_lfo2PanDepthSlider->setBounds (272, 436, 32, 48);

    m_lfo2PanDepthLabel.reset (new juce::Label ("lfo2PanDepthLabel",
                                                TRANS("PAN LFO 2")));
    addAndMakeVisible (m_lfo2PanDepthLabel.get());
    m_lfo2PanDepthLabel->setFont (juce::Font (12.00f, juce::Font::plain).withTypefaceStyle ("Bold"));
    m_lfo2PanDepthLabel->setJustificationType (juce::Justification::centred);
    m_lfo2PanDepthLabel->setEditable (false, false, false);
    m_lfo2PanDepthLabel->setColour (juce::Label::textColourId, juce::Colours::black);
    m_lfo2PanDepthLabel->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    m_lfo2PanDepthLabel->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    m_lfo2PanDepthLabel->setBounds (256, 420, 68, 16);

    m_imageButton.reset (new juce::ImageButton ("imageButton"));
    addAndMakeVisible (m_imageButton.get());
    m_imageButton->setButtonText (juce::String());

    m_imageButton->setImages (false, true, true,
                              juce::ImageCache::getFromMemory (amp_png, amp_pngSize), 1.000f, juce::Colour (0x4340454a),
                              juce::Image(), 1.000f, juce::Colour (0x4340454a),
                              juce::Image(), 1.000f, juce::Colour (0x4340454a));
    m_imageButton->setBounds (3, 1, 16, 16);

    m_toneLevelSlider.reset (new ParameterEnvelopeSlider ("toneLevelSlider"));
    addAndMakeVisible (m_toneLevelSlider.get());
    m_toneLevelSlider->setRange (0, 127, 1);
    m_toneLevelSlider->setSliderStyle (juce::Slider::LinearVertical);
    m_toneLevelSlider->setTextBoxStyle (juce::Slider::TextBoxBelow, false, 56, 16);
    m_toneLevelSlider->setColour (juce::Slider::backgroundColourId, juce::Colour (0x00f2f59b));
    m_toneLevelSlider->setColour (juce::Slider::textBoxBackgroundColourId, juce::Colour (0xfff2f59b));
    m_toneLevelSlider->addListener (this);

    m_toneLevelSlider->setBounds (8, 168, 56, 116);

    m_filterEnvelopeDepthLabel.reset (new juce::Label ("filterEnvelopeDepthLabel",
                                                       TRANS("TONE LEVEL")));
    addAndMakeVisible (m_filterEnvelopeDepthLabel.get());
    m_filterEnvelopeDepthLabel->setFont (juce::Font (12.00f, juce::Font::plain).withTypefaceStyle ("Bold"));
    m_filterEnvelopeDepthLabel->setJustificationType (juce::Justification::centred);
    m_filterEnvelopeDepthLabel->setEditable (false, false, false);
    m_filterEnvelopeDepthLabel->setColour (juce::Label::textColourId, juce::Colours::black);
    m_filterEnvelopeDepthLabel->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    m_filterEnvelopeDepthLabel->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    m_filterEnvelopeDepthLabel->setBounds (0, 156, 72, 16);

    m_imageButton2.reset (new juce::ImageButton ("imageButton"));
    addAndMakeVisible (m_imageButton2.get());
    m_imageButton2->setButtonText (juce::String());

    m_imageButton2->setImages (false, true, true,
                               juce::ImageCache::getFromMemory (amp_png, amp_pngSize), 1.000f, juce::Colour (0x4340454a),
                               juce::Image(), 1.000f, juce::Colour (0x4340454a),
                               juce::Image(), 1.000f, juce::Colour (0x4340454a));
    m_imageButton2->setBounds (3, 141, 16, 16);

    m_imageButton3.reset (new juce::ImageButton ("imageButton"));
    addAndMakeVisible (m_imageButton3.get());
    m_imageButton3->setButtonText (juce::String());
    m_imageButton3->addListener (this);

    m_imageButton3->setImages (false, true, true,
                               juce::ImageCache::getFromMemory (lfo_png, lfo_pngSize), 1.000f, juce::Colour (0x4340454a),
                               juce::Image(), 1.000f, juce::Colour (0x4340454a),
                               juce::Image(), 1.000f, juce::Colour (0x4340454a));
    m_imageButton3->setBounds (3, 405, 16, 16);


    //[UserPreSize]
	m_ampGrp->setText("AMP OF PART " + String(part + 1) + " TONE " + String(((tone - 4096) / 512) + 1));
    //[/UserPreSize]

    setSize (376, 492);


    //[Constructor] You can add your own custom stuff here..
	if (grooveboxMemory != nullptr)
	{
		SynthPatchesBlock* synthPatches = grooveboxMemory->getSynthPatchesBlock();
		if (synthPatches != nullptr)
		{
			PatchPartBlock* patchPart = synthPatches->getPatchPartBlockPtr(m_part);
			if (patchPart != nullptr)
			{
				if (PatchCommonBlock* patchCommon = patchPart->getPatchCommonBlockPtr())
				{
				}
				PatchToneBlock* tone = nullptr;
				switch (m_tone)
				{
				case Tone1:
					if (PatchToneBlock* tone1 = patchPart->getPatchToneBlockPtr(Tone1)) tone = tone1;
					break;
				case Tone2:
					if (PatchToneBlock* tone2 = patchPart->getPatchToneBlockPtr(Tone2)) tone = tone2;
					break;
				case Tone3:
					if (PatchToneBlock* tone3 = patchPart->getPatchToneBlockPtr(Tone3)) tone = tone3;
					break;
				case Tone4:
					if (PatchToneBlock* tone4 = patchPart->getPatchToneBlockPtr(Tone4)) tone = tone4;
					break;
				}
				if (tone != nullptr)
				{
					m_toneLevelSlider->setParameter(tone->getParameter(0x65));

					m_ampBiasDirectionComboBox->setParameter(tone->getParameter(0x66));
					m_biasPointSlider->setParameter(tone->getParameter(0x67));
					m_biasLevelSlider->setParameter(tone->getParameter(0x68));

					m_ampEnvVelCurveComboBox->setParameter(tone->getParameter(0x69));
					m_ampEnvVelCurveDisplay->setParameter(tone->getParameter(0x69));
					m_ampVelocitySensSlider->setParameter(tone->getParameter(0x6A));
					m_ampEnvVelocityTime1Slider->setParameter(tone->getParameter(0x6B));
					m_ampEnvVelocityTime4Slider->setParameter(tone->getParameter(0x6C));
					m_ampKeyfollowSlider->setParameter(tone->getParameter(0x6D));

					m_tonePanSlider->setParameter(tone->getParameter(0x77));
					m_panKeyfollowSlider->setParameter(tone->getParameter(0x78));
					m_panRandomToggle->setParameter(tone->getParameter(0x79));
					m_panAlternateSlider->setParameter(tone->getParameter(0x7A));

					m_lfo1AmpDepthSlider->setParameter(tone->getParameter(0x75));
					m_lfo2AmpDepthSlider->setParameter(tone->getParameter(0x76));
					m_lfo1PanDepthSlider->setParameter(tone->getParameter(0x7B));
					m_lfo2PanDepthSlider->setParameter(tone->getParameter(0x7C));
				}
			}
		}
	}
    //[/Constructor]
}

AmpEditorAdvanced::~AmpEditorAdvanced()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    m_ampGrp = nullptr;
    m_ampEnvGrp = nullptr;
    m_panGrp = nullptr;
    m_biasGrp = nullptr;
    m_tonePanSlider = nullptr;
    m_tonePanLabel = nullptr;
    m_ampEnv = nullptr;
    m_panKeyfollowLabel = nullptr;
    m_panKeyfollowSlider = nullptr;
    m_ampVelocitySensSlider = nullptr;
    m_ampEnvVelocitySensLabel = nullptr;
    m_ampEnvVelocityTime1Slider = nullptr;
    m_ampEnvVelocityTime1Label = nullptr;
    m_ampEnvVelocityTime4Slider = nullptr;
    m_ampEnvVelocityTime4Label = nullptr;
    m_ampEnvTimeKeyfollow = nullptr;
    m_ampKeyfollowSlider = nullptr;
    m_ampEnvVelCurveComboBox = nullptr;
    m_ampEnvVelCurveDisplay = nullptr;
    m_ampBiasDirectionLabel = nullptr;
    m_ampBiasDirectionComboBox = nullptr;
    m_ampEnvVelocityCurveLabel = nullptr;
    m_biasPointLabel = nullptr;
    m_biasPointSlider = nullptr;
    m_biasLevelLabel = nullptr;
    m_biasLevelSlider = nullptr;
    m_panRandomToggle = nullptr;
    m_panRandomLabel = nullptr;
    m_panAlternateSlider = nullptr;
    m_panAlternateLabel = nullptr;
    m_lfoGrp = nullptr;
    m_lfo1AmpDepthSlider = nullptr;
    m_lfo1AmpDepthLabel = nullptr;
    m_lfo2AmpDepthSlider = nullptr;
    m_lfo2AmpDepthLabel = nullptr;
    m_lfo1AdvancedButton = nullptr;
    m_lfo2AdvancedButton = nullptr;
    m_lfo1PanDepthSlider = nullptr;
    m_lfo1PanDepthLabel = nullptr;
    m_lfo2PanDepthSlider = nullptr;
    m_lfo2PanDepthLabel = nullptr;
    m_imageButton = nullptr;
    m_toneLevelSlider = nullptr;
    m_filterEnvelopeDepthLabel = nullptr;
    m_imageButton2 = nullptr;
    m_imageButton3 = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void AmpEditorAdvanced::paint (juce::Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
#ifdef JUCE_MSVC
	g;
#endif
    //[/UserPrePaint]

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void AmpEditorAdvanced::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    m_ampGrp->setBounds (0, 0, getWidth() - 0, getHeight() - 0);
    m_ampEnvGrp->setBounds (0, 140, getWidth() - 0, 260);
    m_panGrp->setBounds (272, 18, getWidth() - 280, 118);
    m_biasGrp->setBounds (84, 18, getWidth() - 268, 118);
    m_lfoGrp->setBounds (0, 404, getWidth() - 0, 88);
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void AmpEditorAdvanced::sliderValueChanged (juce::Slider* sliderThatWasMoved)
{
    //[UsersliderValueChanged_Pre]
    //[/UsersliderValueChanged_Pre]

    if (sliderThatWasMoved == m_tonePanSlider.get())
    {
        //[UserSliderCode_m_tonePanSlider] -- add your slider handling code here..
        //[/UserSliderCode_m_tonePanSlider]
    }
    else if (sliderThatWasMoved == m_panKeyfollowSlider.get())
    {
        //[UserSliderCode_m_panKeyfollowSlider] -- add your slider handling code here..
        //[/UserSliderCode_m_panKeyfollowSlider]
    }
    else if (sliderThatWasMoved == m_ampVelocitySensSlider.get())
    {
        //[UserSliderCode_m_ampVelocitySensSlider] -- add your slider handling code here..
        //[/UserSliderCode_m_ampVelocitySensSlider]
    }
    else if (sliderThatWasMoved == m_ampEnvVelocityTime1Slider.get())
    {
        //[UserSliderCode_m_ampEnvVelocityTime1Slider] -- add your slider handling code here..
        //[/UserSliderCode_m_ampEnvVelocityTime1Slider]
    }
    else if (sliderThatWasMoved == m_ampEnvVelocityTime4Slider.get())
    {
        //[UserSliderCode_m_ampEnvVelocityTime4Slider] -- add your slider handling code here..
        //[/UserSliderCode_m_ampEnvVelocityTime4Slider]
    }
    else if (sliderThatWasMoved == m_ampKeyfollowSlider.get())
    {
        //[UserSliderCode_m_ampKeyfollowSlider] -- add your slider handling code here..
        //[/UserSliderCode_m_ampKeyfollowSlider]
    }
    else if (sliderThatWasMoved == m_ampEnvVelCurveDisplay.get())
    {
        //[UserSliderCode_m_ampEnvVelCurveDisplay] -- add your slider handling code here..
        //[/UserSliderCode_m_ampEnvVelCurveDisplay]
    }
    else if (sliderThatWasMoved == m_biasPointSlider.get())
    {
        //[UserSliderCode_m_biasPointSlider] -- add your slider handling code here..
        //[/UserSliderCode_m_biasPointSlider]
    }
    else if (sliderThatWasMoved == m_biasLevelSlider.get())
    {
        //[UserSliderCode_m_biasLevelSlider] -- add your slider handling code here..
        //[/UserSliderCode_m_biasLevelSlider]
    }
    else if (sliderThatWasMoved == m_panAlternateSlider.get())
    {
        //[UserSliderCode_m_panAlternateSlider] -- add your slider handling code here..
        //[/UserSliderCode_m_panAlternateSlider]
    }
    else if (sliderThatWasMoved == m_lfo1AmpDepthSlider.get())
    {
        //[UserSliderCode_m_lfo1AmpDepthSlider] -- add your slider handling code here..
        //[/UserSliderCode_m_lfo1AmpDepthSlider]
    }
    else if (sliderThatWasMoved == m_lfo2AmpDepthSlider.get())
    {
        //[UserSliderCode_m_lfo2AmpDepthSlider] -- add your slider handling code here..
        //[/UserSliderCode_m_lfo2AmpDepthSlider]
    }
    else if (sliderThatWasMoved == m_lfo1PanDepthSlider.get())
    {
        //[UserSliderCode_m_lfo1PanDepthSlider] -- add your slider handling code here..
        //[/UserSliderCode_m_lfo1PanDepthSlider]
    }
    else if (sliderThatWasMoved == m_lfo2PanDepthSlider.get())
    {
        //[UserSliderCode_m_lfo2PanDepthSlider] -- add your slider handling code here..
        //[/UserSliderCode_m_lfo2PanDepthSlider]
    }
    else if (sliderThatWasMoved == m_toneLevelSlider.get())
    {
        //[UserSliderCode_m_toneLevelSlider] -- add your slider handling code here..
        //[/UserSliderCode_m_toneLevelSlider]
    }

    //[UsersliderValueChanged_Post]
    //[/UsersliderValueChanged_Post]
}

void AmpEditorAdvanced::comboBoxChanged (juce::ComboBox* comboBoxThatHasChanged)
{
    //[UsercomboBoxChanged_Pre]
    //[/UsercomboBoxChanged_Pre]

    if (comboBoxThatHasChanged == m_ampEnvVelCurveComboBox.get())
    {
        //[UserComboBoxCode_m_ampEnvVelCurveComboBox] -- add your combo box handling code here..
        //[/UserComboBoxCode_m_ampEnvVelCurveComboBox]
    }
    else if (comboBoxThatHasChanged == m_ampBiasDirectionComboBox.get())
    {
        //[UserComboBoxCode_m_ampBiasDirectionComboBox] -- add your combo box handling code here..
        //[/UserComboBoxCode_m_ampBiasDirectionComboBox]
    }

    //[UsercomboBoxChanged_Post]
    //[/UsercomboBoxChanged_Post]
}

void AmpEditorAdvanced::buttonClicked (juce::Button* buttonThatWasClicked)
{
    //[UserbuttonClicked_Pre]
    //[/UserbuttonClicked_Pre]

    if (buttonThatWasClicked == m_lfo1AdvancedButton.get())
    {
        //[UserButtonCode_m_lfo1AdvancedButton] -- add your button handler code here..
        std::unique_ptr<Component> advancedLfoEditor (new LfoEditorAdvanced("LFO", m_part, m_tone, false));
		CallOutBox::launchAsynchronously(std::move(advancedLfoEditor), m_lfo1AdvancedButton->getScreenBounds(), nullptr);
        //[/UserButtonCode_m_lfo1AdvancedButton]
    }
    else if (buttonThatWasClicked == m_lfo2AdvancedButton.get())
    {
        //[UserButtonCode_m_lfo2AdvancedButton] -- add your button handler code here..
        std::unique_ptr<Component> advancedLfoEditor ( new LfoEditorAdvanced("LFO", m_part, m_tone, true));
		CallOutBox::launchAsynchronously(std::move(advancedLfoEditor), m_lfo2AdvancedButton->getScreenBounds(), nullptr);
        //[/UserButtonCode_m_lfo2AdvancedButton]
    }
    else if (buttonThatWasClicked == m_imageButton3.get())
    {
        //[UserButtonCode_m_imageButton3] -- add your button handler code here..
        //[/UserButtonCode_m_imageButton3]
    }

    //[UserbuttonClicked_Post]
    //[/UserbuttonClicked_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="AmpEditorAdvanced" componentName=""
                 parentClasses="public Component" constructorParams="const String &amp;componentName, SynthParts part, Tone tone"
                 variableInitialisers="Component (componentName), m_part(part), m_tone(tone)"
                 snapPixels="4" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="1" initialWidth="376" initialHeight="492">
  <BACKGROUND backgroundColour="0"/>
  <JUCERCOMP name="ampGrp" id="52e00682f746b888" memberName="m_ampGrp" virtualName="PanelGroupGrey"
             explicitFocusOrder="0" pos="0 0 0M 0M" sourceFile="../GroupWidgets/PanelGroupGrey.cpp"
             constructorParams="&quot;ampGrp&quot;, getName() "/>
  <JUCERCOMP name="ampEnvGrp" id="f94b4c6bc1e7a151" memberName="m_ampEnvGrp"
             virtualName="PanelGroupGrey" explicitFocusOrder="0" pos="0 140 0M 260"
             sourceFile="../GroupWidgets/PanelGroupTransp.cpp" constructorParams="&quot;ampEnvGrp&quot;, getName().toUpperCase()+&quot; ENVELOPE&quot;"/>
  <JUCERCOMP name="panGrp" id="442175acfce18c1f" memberName="m_panGrp" virtualName="PanelGroupGrey"
             explicitFocusOrder="0" pos="272 18 280M 118" sourceFile="../GroupWidgets/PanelGroupTransp.cpp"
             constructorParams="&quot;panGrp&quot;, &quot;PAN&quot;"/>
  <JUCERCOMP name="biasGrp" id="f33a7f17bedf43c1" memberName="m_biasGrp" virtualName="PanelGroupGrey"
             explicitFocusOrder="0" pos="84 18 268M 118" sourceFile="../GroupWidgets/PanelGroupTransp.cpp"
             constructorParams="&quot;biasGrp&quot;, &quot;BIAS&quot;"/>
  <SLIDER name="tonePanSlider" id="533842793459863a" memberName="m_tonePanSlider"
          virtualName="Knob" explicitFocusOrder="0" pos="208 40 48 60"
          textboxbkgd="fff2f59b" min="0.0" max="127.0" int="1.0" style="RotaryHorizontalVerticalDrag"
          textBoxPos="TextBoxBelow" textBoxEditable="1" textBoxWidth="80"
          textBoxHeight="16" skewFactor="1.0" needsCallback="1"/>
  <LABEL name="tonePanLabel" id="b464bd3cbdae27fd" memberName="m_tonePanLabel"
         virtualName="" explicitFocusOrder="0" pos="196 20 72 16" textCol="ff000000"
         edTextCol="ff000000" edBkgCol="0" labelText="TONE PAN" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="12.0" kerning="0.0" bold="1" italic="0" justification="36"
         typefaceStyle="Bold"/>
  <JUCERCOMP name="ampEnv" id="99a40d72d7ad1e22" memberName="m_ampEnv" virtualName=""
             explicitFocusOrder="0" pos="72 156 296 156" sourceFile="Envelope.cpp"
             constructorParams="(AllParts)m_part, m_tone, EnvelopeTypes::Amp, false"/>
  <LABEL name="panKeyfollowLabel" id="3a52299341c28960" memberName="m_panKeyfollowLabel"
         virtualName="" explicitFocusOrder="0" pos="280 32 80 16" textCol="ff000000"
         edTextCol="ff000000" edBkgCol="0" labelText="KEYFOLLOW" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="12.0" kerning="0.0" bold="1" italic="0" justification="36"
         typefaceStyle="Bold"/>
  <SLIDER name="panKeyfollowSlider" id="70b45a3a21f5522" memberName="m_panKeyfollowSlider"
          virtualName="KeyfollowMicroParameterSlider" explicitFocusOrder="0"
          pos="296 48 48 16" bkgcol="fff2f59b" thumbcol="ffc4c86d" min="0.0"
          max="127.0" int="1.0" style="LinearBar" textBoxPos="TextBoxLeft"
          textBoxEditable="1" textBoxWidth="40" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <SLIDER name="ampVelocitySensSlider" id="ce3036a9c9d2d09a" memberName="m_ampVelocitySensSlider"
          virtualName="MicroParameterSlider" explicitFocusOrder="0" pos="8 306 56 16"
          bkgcol="fff2f59b" thumbcol="ffc4c86d" min="0.0" max="127.0" int="1.0"
          style="LinearBar" textBoxPos="TextBoxLeft" textBoxEditable="1"
          textBoxWidth="40" textBoxHeight="20" skewFactor="1.0" needsCallback="1"/>
  <LABEL name="ampEnvVelocitySensLabel" id="da6b2f045679c497" memberName="m_ampEnvVelocitySensLabel"
         virtualName="" explicitFocusOrder="0" pos="0 290 72 16" textCol="ff000000"
         edTextCol="ff000000" edBkgCol="0" labelText="VELO SENS" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="12.0" kerning="0.0" bold="1" italic="0" justification="36"
         typefaceStyle="Bold"/>
  <SLIDER name="ampEnvVelocityTime1Slider" id="26e8b1e9ec956faf" memberName="m_ampEnvVelocityTime1Slider"
          virtualName="MicroParameterSlider" explicitFocusOrder="0" pos="124 332 56 16"
          bkgcol="fff2f59b" thumbcol="ffc4c86d" min="0.0" max="127.0" int="1.0"
          style="LinearBar" textBoxPos="TextBoxLeft" textBoxEditable="1"
          textBoxWidth="40" textBoxHeight="20" skewFactor="1.0" needsCallback="1"/>
  <LABEL name="ampEnvVelocityTime1Label" id="fcf555c7750e1905" memberName="m_ampEnvVelocityTime1Label"
         virtualName="" explicitFocusOrder="0" pos="84 316 112 16" textCol="ff000000"
         edTextCol="ff000000" edBkgCol="0" labelText="VELO SENS TIME 1"
         editableSingleClick="0" editableDoubleClick="0" focusDiscardsChanges="0"
         fontname="Default font" fontsize="12.0" kerning="0.0" bold="1"
         italic="0" justification="36" typefaceStyle="Bold"/>
  <SLIDER name="ampEnvVelocityTime4Slider" id="96d5b92b9bc16388" memberName="m_ampEnvVelocityTime4Slider"
          virtualName="MicroParameterSlider" explicitFocusOrder="0" pos="300 332 56 16"
          bkgcol="fff2f59b" thumbcol="ffc4c86d" min="0.0" max="127.0" int="1.0"
          style="LinearBar" textBoxPos="TextBoxLeft" textBoxEditable="1"
          textBoxWidth="40" textBoxHeight="20" skewFactor="1.0" needsCallback="1"/>
  <LABEL name="ampEnvVelocityTime4Label" id="d741df9cfd6aac2d" memberName="m_ampEnvVelocityTime4Label"
         virtualName="" explicitFocusOrder="0" pos="264 316 112 16" textCol="ff000000"
         edTextCol="ff000000" edBkgCol="0" labelText="VELO SENS TIME 4"
         editableSingleClick="0" editableDoubleClick="0" focusDiscardsChanges="0"
         fontname="Default font" fontsize="12.0" kerning="0.0" bold="1"
         italic="0" justification="36" typefaceStyle="Bold"/>
  <LABEL name="ampEnvTimeKeyfollow" id="cf887a8299fda426" memberName="m_ampEnvTimeKeyfollow"
         virtualName="" explicitFocusOrder="0" pos="184 356 172 16" textCol="ff000000"
         edTextCol="ff000000" edBkgCol="0" labelText="KEYFOLLOW TIME 2/3/4 "
         editableSingleClick="0" editableDoubleClick="0" focusDiscardsChanges="0"
         fontname="Default font" fontsize="12.0" kerning="0.0" bold="1"
         italic="0" justification="36" typefaceStyle="Bold"/>
  <SLIDER name="ampKeyfollowSlider" id="fd7fba1a74d4d802" memberName="m_ampKeyfollowSlider"
          virtualName="KeyfollowMicroParameterSlider" explicitFocusOrder="0"
          pos="252 372 56 16" bkgcol="fff2f59b" thumbcol="ffc4c86d" min="0.0"
          max="127.0" int="1.0" style="LinearBar" textBoxPos="TextBoxLeft"
          textBoxEditable="1" textBoxWidth="40" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <COMBOBOX name="ampEnvVelCurveComboBox" id="5f5f3969c23f54e2" memberName="m_ampEnvVelCurveComboBox"
            virtualName="ParameterComboBox" explicitFocusOrder="0" pos="8 343 68 16"
            editable="0" layout="36" items="" textWhenNonSelected="Normal"
            textWhenNoItems="(no choices)"/>
  <SLIDER name="ampEnvVelCurveDisplay" id="d9c13bc39fc51534" memberName="m_ampEnvVelCurveDisplay"
          virtualName="ParameterVelCurveDisplay" explicitFocusOrder="0"
          pos="20 363 36 36" min="0.0" max="10.0" int="0.0" style="RotaryHorizontalVerticalDrag"
          textBoxPos="NoTextBox" textBoxEditable="1" textBoxWidth="80"
          textBoxHeight="20" skewFactor="1.0" needsCallback="1"/>
  <LABEL name="ampBiasDirectionLabel" id="c41c307042cbea72" memberName="m_ampBiasDirectionLabel"
         virtualName="" explicitFocusOrder="0" pos="96 32 84 16" textCol="ff000000"
         edTextCol="ff000000" edBkgCol="0" labelText="DIRECTION" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="12.0" kerning="0.0" bold="1" italic="0" justification="36"
         typefaceStyle="Bold"/>
  <COMBOBOX name="ampBiasDirectionComboBox" id="e8c10ecedfc6fd9e" memberName="m_ampBiasDirectionComboBox"
            virtualName="ParameterComboBox" explicitFocusOrder="0" pos="88 48 100 16"
            editable="0" layout="36" items="" textWhenNonSelected="" textWhenNoItems="(no choices)"/>
  <LABEL name="ampEnvVelocityCurveLabel" id="4fa3b6178a95b9c" memberName="m_ampEnvVelocityCurveLabel"
         virtualName="" explicitFocusOrder="0" pos="0 327 80 16" textCol="ff000000"
         edTextCol="ff000000" edBkgCol="0" labelText="VELO CURVE" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="12.0" kerning="0.0" bold="1" italic="0" justification="36"
         typefaceStyle="Bold"/>
  <LABEL name="biasPointLabel" id="8db74046eb660d30" memberName="m_biasPointLabel"
         virtualName="" explicitFocusOrder="0" pos="88 68 48 16" textCol="ff000000"
         edTextCol="ff000000" edBkgCol="0" labelText="POINT" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="12.0" kerning="0.0" bold="1" italic="0" justification="36"
         typefaceStyle="Bold"/>
  <SLIDER name="biasPointSlider" id="4ef39c9a6ee52b73" memberName="m_biasPointSlider"
          virtualName="MicroParameterSlider" explicitFocusOrder="0" pos="88 84 48 16"
          bkgcol="fff2f59b" thumbcol="ffc4c86d" min="0.0" max="127.0" int="1.0"
          style="LinearBar" textBoxPos="TextBoxLeft" textBoxEditable="1"
          textBoxWidth="40" textBoxHeight="20" skewFactor="1.0" needsCallback="1"/>
  <LABEL name="biasLevelLabel" id="1b7c77405f23be2c" memberName="m_biasLevelLabel"
         virtualName="" explicitFocusOrder="0" pos="140 68 48 16" textCol="ff000000"
         edTextCol="ff000000" edBkgCol="0" labelText="LEVEL" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="12.0" kerning="0.0" bold="1" italic="0" justification="36"
         typefaceStyle="Bold"/>
  <SLIDER name="biasLevelSlider" id="2155aedfd6600e68" memberName="m_biasLevelSlider"
          virtualName="MicroParameterSlider" explicitFocusOrder="0" pos="140 84 48 16"
          bkgcol="fff2f59b" thumbcol="ffc4c86d" min="0.0" max="127.0" int="1.0"
          style="LinearBar" textBoxPos="TextBoxLeft" textBoxEditable="1"
          textBoxWidth="40" textBoxHeight="20" skewFactor="1.0" needsCallback="1"/>
  <JUCERCOMP name="panRandomToggle" id="1dee3cc7cfd57bb1" memberName="m_panRandomToggle"
             virtualName="" explicitFocusOrder="0" pos="307 82 25 17" sourceFile="../ParameterWidgets/BlackToggle.cpp"
             constructorParams=""/>
  <LABEL name="panRandomLabel" id="1e3525d1a10dd56c" memberName="m_panRandomLabel"
         virtualName="" explicitFocusOrder="0" pos="287 66 64 16" textCol="ff000000"
         edTextCol="ff000000" edBkgCol="0" labelText="RANDOM" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="12.0" kerning="0.0" bold="1" italic="0" justification="36"
         typefaceStyle="Bold"/>
  <SLIDER name="panAlternateSlider" id="7aed98a67fac3fdb" memberName="m_panAlternateSlider"
          virtualName="MicroParameterSlider" explicitFocusOrder="0" pos="292 116 56 16"
          bkgcol="fff2f59b" thumbcol="ffc4c86d" min="0.0" max="127.0" int="1.0"
          style="LinearBar" textBoxPos="TextBoxLeft" textBoxEditable="1"
          textBoxWidth="40" textBoxHeight="20" skewFactor="1.0" needsCallback="1"/>
  <LABEL name="panAlternateLabel" id="674286f7173a73be" memberName="m_panAlternateLabel"
         virtualName="" explicitFocusOrder="0" pos="280 100 80 16" textCol="ff000000"
         edTextCol="ff000000" edBkgCol="0" labelText="ALTERNATE" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="12.0" kerning="0.0" bold="1" italic="0" justification="36"
         typefaceStyle="Bold"/>
  <JUCERCOMP name="lfoGrp" id="5d2169b0330e13c6" memberName="m_lfoGrp" virtualName="PanelGroupGrey"
             explicitFocusOrder="0" pos="0 404 0M 88" sourceFile="../GroupWidgets/PanelGroupTransp.cpp"
             constructorParams="&quot;lfoGrp&quot;, &quot;LFO MODULATION&quot;"/>
  <SLIDER name="lfo1AmpDepthSlider" id="5139dffd40f5b193" memberName="m_lfo1AmpDepthSlider"
          virtualName="Knob" explicitFocusOrder="0" pos="16 436 32 48"
          textboxbkgd="fff2f59b" min="0.0" max="127.0" int="1.0" style="RotaryHorizontalVerticalDrag"
          textBoxPos="TextBoxBelow" textBoxEditable="1" textBoxWidth="80"
          textBoxHeight="16" skewFactor="1.0" needsCallback="1"/>
  <LABEL name="lfo1AmpDepthLabel" id="ddaad26232bd3db3" memberName="m_lfo1AmpDepthLabel"
         virtualName="" explicitFocusOrder="0" pos="0 420 68 16" textCol="ff000000"
         edTextCol="ff000000" edBkgCol="0" labelText="LVL LFO 1" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="12.0" kerning="0.0" bold="1" italic="0" justification="36"
         typefaceStyle="Bold"/>
  <SLIDER name="lfo2AmpDepthSlider" id="37bb334dae2c4ad2" memberName="m_lfo2AmpDepthSlider"
          virtualName="Knob" explicitFocusOrder="0" pos="204 436 32 48"
          textboxbkgd="fff2f59b" min="0.0" max="127.0" int="1.0" style="RotaryHorizontalVerticalDrag"
          textBoxPos="TextBoxBelow" textBoxEditable="1" textBoxWidth="80"
          textBoxHeight="16" skewFactor="1.0" needsCallback="1"/>
  <LABEL name="lfo2AmpDepthLabel" id="20feaad1dd36b9a5" memberName="m_lfo2AmpDepthLabel"
         virtualName="" explicitFocusOrder="0" pos="188 420 68 16" textCol="ff000000"
         edTextCol="ff000000" edBkgCol="0" labelText="LVL LFO 2" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="12.0" kerning="0.0" bold="1" italic="0" justification="36"
         typefaceStyle="Bold"/>
  <TEXTBUTTON name="lfo1AdvancedButton" id="9de90d61ee7dcce4" memberName="m_lfo1AdvancedButton"
              virtualName="TextWithArrowButton" explicitFocusOrder="0" pos="124 464 56 21"
              buttonText="LFO 1" connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="lfo2AdvancedButton" id="596fa9d632d5c1d1" memberName="m_lfo2AdvancedButton"
              virtualName="TextWithArrowButton" explicitFocusOrder="0" pos="312 464 56 21"
              buttonText="LFO 2" connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <SLIDER name="lfo1PanDepthSlider" id="c423b0297a1ea359" memberName="m_lfo1PanDepthSlider"
          virtualName="Knob" explicitFocusOrder="0" pos="84 436 32 48"
          textboxbkgd="fff2f59b" min="0.0" max="127.0" int="1.0" style="RotaryHorizontalVerticalDrag"
          textBoxPos="TextBoxBelow" textBoxEditable="1" textBoxWidth="80"
          textBoxHeight="16" skewFactor="1.0" needsCallback="1"/>
  <LABEL name="lfo1PanDepthLabel" id="ae0b0bedb7b968c0" memberName="m_lfo1PanDepthLabel"
         virtualName="" explicitFocusOrder="0" pos="68 420 68 16" textCol="ff000000"
         edTextCol="ff000000" edBkgCol="0" labelText="PAN LFO 1" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="12.0" kerning="0.0" bold="1" italic="0" justification="36"
         typefaceStyle="Bold"/>
  <SLIDER name="lfo2PanDepthSlider" id="d7070b8492bc762b" memberName="m_lfo2PanDepthSlider"
          virtualName="Knob" explicitFocusOrder="0" pos="272 436 32 48"
          textboxbkgd="fff2f59b" min="0.0" max="127.0" int="1.0" style="RotaryHorizontalVerticalDrag"
          textBoxPos="TextBoxBelow" textBoxEditable="1" textBoxWidth="80"
          textBoxHeight="16" skewFactor="1.0" needsCallback="1"/>
  <LABEL name="lfo2PanDepthLabel" id="4c1b4ff05ff89f84" memberName="m_lfo2PanDepthLabel"
         virtualName="" explicitFocusOrder="0" pos="256 420 68 16" textCol="ff000000"
         edTextCol="ff000000" edBkgCol="0" labelText="PAN LFO 2" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="12.0" kerning="0.0" bold="1" italic="0" justification="36"
         typefaceStyle="Bold"/>
  <IMAGEBUTTON name="imageButton" id="f18ffef17196cb40" memberName="m_imageButton"
               virtualName="" explicitFocusOrder="0" pos="3 1 16 16" buttonText=""
               connectedEdges="0" needsCallback="0" radioGroupId="0" keepProportions="1"
               resourceNormal="amp_png" opacityNormal="1.0" colourNormal="4340454a"
               resourceOver="" opacityOver="1.0" colourOver="4340454a" resourceDown=""
               opacityDown="1.0" colourDown="4340454a"/>
  <SLIDER name="toneLevelSlider" id="b0bd5a61181f569c" memberName="m_toneLevelSlider"
          virtualName="ParameterEnvelopeSlider" explicitFocusOrder="0"
          pos="8 168 56 116" bkgcol="f2f59b" textboxbkgd="fff2f59b" min="0.0"
          max="127.0" int="1.0" style="LinearVertical" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="56" textBoxHeight="16" skewFactor="1.0"
          needsCallback="1"/>
  <LABEL name="filterEnvelopeDepthLabel" id="611da7e96f52143f" memberName="m_filterEnvelopeDepthLabel"
         virtualName="" explicitFocusOrder="0" pos="0 156 72 16" textCol="ff000000"
         edTextCol="ff000000" edBkgCol="0" labelText="TONE LEVEL" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="12.0" kerning="0.0" bold="1" italic="0" justification="36"
         typefaceStyle="Bold"/>
  <IMAGEBUTTON name="imageButton" id="3a50d5aaabf6910d" memberName="m_imageButton2"
               virtualName="" explicitFocusOrder="0" pos="3 141 16 16" buttonText=""
               connectedEdges="0" needsCallback="0" radioGroupId="0" keepProportions="1"
               resourceNormal="amp_png" opacityNormal="1.0" colourNormal="4340454a"
               resourceOver="" opacityOver="1.0" colourOver="4340454a" resourceDown=""
               opacityDown="1.0" colourDown="4340454a"/>
  <IMAGEBUTTON name="imageButton" id="570f3b3b741de5e4" memberName="m_imageButton3"
               virtualName="" explicitFocusOrder="0" pos="3 405 16 16" buttonText=""
               connectedEdges="0" needsCallback="1" radioGroupId="0" keepProportions="1"
               resourceNormal="lfo_png" opacityNormal="1.0" colourNormal="4340454a"
               resourceOver="" opacityOver="1.0" colourOver="4340454a" resourceDown=""
               opacityDown="1.0" colourDown="4340454a"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif

//==============================================================================
// Binary resources - be careful not to edit any of these sections!

// JUCER_RESOURCE: amp_png, 238, "../../../Resources/PatchEditSectionIcons/amp.png"
static const unsigned char resource_AmpEditorAdvanced_amp_png[] = { 137,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,0,16,0,0,0,16,8,6,0,0,0,31,243,255,97,0,0,0,1,115,82,71,66,0,174,206,28,233,0,0,0,
6,98,75,71,68,0,255,0,255,0,255,160,189,167,147,0,0,0,9,112,72,89,115,0,0,11,19,0,0,11,19,1,0,154,156,24,0,0,0,7,116,73,77,69,7,222,12,10,20,17,54,201,225,103,191,0,0,0,110,73,68,65,84,56,203,165,83,209,
18,192,48,4,195,249,255,95,182,151,185,51,19,166,203,75,175,218,68,84,49,221,48,51,163,5,152,153,233,148,252,224,76,100,11,168,206,100,101,181,128,160,140,113,223,137,40,202,234,34,78,70,34,50,217,71,
245,183,14,162,109,95,179,163,177,4,20,203,66,90,246,182,233,59,116,224,182,179,8,34,190,4,242,133,137,248,249,17,39,232,246,231,245,131,113,192,225,191,227,124,1,168,181,108,17,98,157,50,130,0,0,0,0,
73,69,78,68,174,66,96,130,0,0};

const char* AmpEditorAdvanced::amp_png = (const char*) resource_AmpEditorAdvanced_amp_png;
const int AmpEditorAdvanced::amp_pngSize = 238;

// JUCER_RESOURCE: lfo_png, 235, "../../../Resources/PatchEditSectionIcons/lfo.png"
static const unsigned char resource_AmpEditorAdvanced_lfo_png[] = { 137,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,0,16,0,0,0,16,8,6,0,0,0,31,243,255,97,0,0,0,1,115,82,71,66,0,174,206,28,233,0,0,0,
6,98,75,71,68,0,255,0,255,0,255,160,189,167,147,0,0,0,9,112,72,89,115,0,0,11,19,0,0,11,19,1,0,154,156,24,0,0,0,7,116,73,77,69,7,222,12,10,20,17,26,251,57,11,92,0,0,0,107,73,68,65,84,56,203,165,83,91,14,
192,32,8,163,141,247,191,50,251,153,9,16,22,6,240,37,216,242,168,8,121,77,85,85,26,6,0,50,37,59,206,132,108,147,176,3,78,139,253,233,192,98,226,153,178,181,170,131,236,254,198,92,7,83,49,89,85,119,239,
157,236,192,153,140,106,19,208,6,163,194,23,24,201,214,103,119,125,163,86,231,11,144,205,158,9,205,172,74,36,87,254,234,51,97,251,157,31,197,207,111,229,235,115,88,252,0,0,0,0,73,69,78,68,174,66,96,130,
0,0};

const char* AmpEditorAdvanced::lfo_png = (const char*) resource_AmpEditorAdvanced_lfo_png;
const int AmpEditorAdvanced::lfo_pngSize = 235;


//[EndFile] You can add extra defines here...
//[/EndFile]

