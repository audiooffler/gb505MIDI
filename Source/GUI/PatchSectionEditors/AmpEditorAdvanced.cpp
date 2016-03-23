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

    addAndMakeVisible (m_ampGrp = new PanelGroupGrey ("ampGrp", getName()));
    addAndMakeVisible (m_ampEnvGrp = new PanelGroupGrey ("ampEnvGrp", getName().toUpperCase()+" ENVELOPE"));
    addAndMakeVisible (m_panGrp = new PanelGroupGrey ("panGrp", "PAN"));
    addAndMakeVisible (m_biasGrp = new PanelGroupGrey ("biasGrp", "BIAS"));
    addAndMakeVisible (m_tonePanSlider = new Knob ("tonePanSlider"));
    m_tonePanSlider->setRange (0, 127, 1);
    m_tonePanSlider->setSliderStyle (Slider::RotaryHorizontalVerticalDrag);
    m_tonePanSlider->setTextBoxStyle (Slider::TextBoxBelow, false, 80, 16);
    m_tonePanSlider->setColour (Slider::textBoxBackgroundColourId, Colour (0xfff2f59b));
    m_tonePanSlider->addListener (this);

    addAndMakeVisible (m_tonePanLabel = new Label ("tonePanLabel",
                                                   TRANS("TONE PAN")));
    m_tonePanLabel->setFont (Font (12.00f, Font::bold));
    m_tonePanLabel->setJustificationType (Justification::centred);
    m_tonePanLabel->setEditable (false, false, false);
    m_tonePanLabel->setColour (Label::textColourId, Colours::black);
    m_tonePanLabel->setColour (TextEditor::textColourId, Colours::black);
    m_tonePanLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_ampEnv = new Envelope ((AllParts)m_part, m_tone, EnvelopeTypes::Amp, false));
    addAndMakeVisible (m_panKeyfollowLabel = new Label ("panKeyfollowLabel",
                                                        TRANS("KEYFOLLOW")));
    m_panKeyfollowLabel->setFont (Font (12.00f, Font::bold));
    m_panKeyfollowLabel->setJustificationType (Justification::centred);
    m_panKeyfollowLabel->setEditable (false, false, false);
    m_panKeyfollowLabel->setColour (Label::textColourId, Colours::black);
    m_panKeyfollowLabel->setColour (TextEditor::textColourId, Colours::black);
    m_panKeyfollowLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_panKeyfollowSlider = new KeyfollowMicroParameterSlider ("panKeyfollowSlider"));
    m_panKeyfollowSlider->setRange (0, 127, 1);
    m_panKeyfollowSlider->setSliderStyle (Slider::LinearBar);
    m_panKeyfollowSlider->setTextBoxStyle (Slider::TextBoxLeft, false, 40, 20);
    m_panKeyfollowSlider->setColour (Slider::backgroundColourId, Colour (0xfff2f59b));
    m_panKeyfollowSlider->setColour (Slider::thumbColourId, Colour (0xffc4c86d));
    m_panKeyfollowSlider->addListener (this);

    addAndMakeVisible (m_ampVelocitySensSlider = new MicroParameterSlider ("ampVelocitySensSlider"));
    m_ampVelocitySensSlider->setRange (0, 127, 1);
    m_ampVelocitySensSlider->setSliderStyle (Slider::LinearBar);
    m_ampVelocitySensSlider->setTextBoxStyle (Slider::TextBoxLeft, false, 40, 20);
    m_ampVelocitySensSlider->setColour (Slider::backgroundColourId, Colour (0xfff2f59b));
    m_ampVelocitySensSlider->setColour (Slider::thumbColourId, Colour (0xffc4c86d));
    m_ampVelocitySensSlider->addListener (this);

    addAndMakeVisible (m_ampEnvVelocitySensLabel = new Label ("ampEnvVelocitySensLabel",
                                                              TRANS("VELO SENS")));
    m_ampEnvVelocitySensLabel->setFont (Font (12.00f, Font::bold));
    m_ampEnvVelocitySensLabel->setJustificationType (Justification::centred);
    m_ampEnvVelocitySensLabel->setEditable (false, false, false);
    m_ampEnvVelocitySensLabel->setColour (Label::textColourId, Colours::black);
    m_ampEnvVelocitySensLabel->setColour (TextEditor::textColourId, Colours::black);
    m_ampEnvVelocitySensLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_ampEnvVelocityTime1Slider = new MicroParameterSlider ("ampEnvVelocityTime1Slider"));
    m_ampEnvVelocityTime1Slider->setRange (0, 127, 1);
    m_ampEnvVelocityTime1Slider->setSliderStyle (Slider::LinearBar);
    m_ampEnvVelocityTime1Slider->setTextBoxStyle (Slider::TextBoxLeft, false, 40, 20);
    m_ampEnvVelocityTime1Slider->setColour (Slider::backgroundColourId, Colour (0xfff2f59b));
    m_ampEnvVelocityTime1Slider->setColour (Slider::thumbColourId, Colour (0xffc4c86d));
    m_ampEnvVelocityTime1Slider->addListener (this);

    addAndMakeVisible (m_ampEnvVelocityTime1Label = new Label ("ampEnvVelocityTime1Label",
                                                               TRANS("VELO SENS TIME 1")));
    m_ampEnvVelocityTime1Label->setFont (Font (12.00f, Font::bold));
    m_ampEnvVelocityTime1Label->setJustificationType (Justification::centred);
    m_ampEnvVelocityTime1Label->setEditable (false, false, false);
    m_ampEnvVelocityTime1Label->setColour (Label::textColourId, Colours::black);
    m_ampEnvVelocityTime1Label->setColour (TextEditor::textColourId, Colours::black);
    m_ampEnvVelocityTime1Label->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_ampEnvVelocityTime4Slider = new MicroParameterSlider ("ampEnvVelocityTime4Slider"));
    m_ampEnvVelocityTime4Slider->setRange (0, 127, 1);
    m_ampEnvVelocityTime4Slider->setSliderStyle (Slider::LinearBar);
    m_ampEnvVelocityTime4Slider->setTextBoxStyle (Slider::TextBoxLeft, false, 40, 20);
    m_ampEnvVelocityTime4Slider->setColour (Slider::backgroundColourId, Colour (0xfff2f59b));
    m_ampEnvVelocityTime4Slider->setColour (Slider::thumbColourId, Colour (0xffc4c86d));
    m_ampEnvVelocityTime4Slider->addListener (this);

    addAndMakeVisible (m_ampEnvVelocityTime4Label = new Label ("ampEnvVelocityTime4Label",
                                                               TRANS("VELO SENS TIME 4")));
    m_ampEnvVelocityTime4Label->setFont (Font (12.00f, Font::bold));
    m_ampEnvVelocityTime4Label->setJustificationType (Justification::centred);
    m_ampEnvVelocityTime4Label->setEditable (false, false, false);
    m_ampEnvVelocityTime4Label->setColour (Label::textColourId, Colours::black);
    m_ampEnvVelocityTime4Label->setColour (TextEditor::textColourId, Colours::black);
    m_ampEnvVelocityTime4Label->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_ampEnvTimeKeyfollow = new Label ("ampEnvTimeKeyfollow",
                                                          TRANS("KEYFOLLOW TIME 2/3/4 ")));
    m_ampEnvTimeKeyfollow->setFont (Font (12.00f, Font::bold));
    m_ampEnvTimeKeyfollow->setJustificationType (Justification::centred);
    m_ampEnvTimeKeyfollow->setEditable (false, false, false);
    m_ampEnvTimeKeyfollow->setColour (Label::textColourId, Colours::black);
    m_ampEnvTimeKeyfollow->setColour (TextEditor::textColourId, Colours::black);
    m_ampEnvTimeKeyfollow->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_ampKeyfollowSlider = new KeyfollowMicroParameterSlider ("ampKeyfollowSlider"));
    m_ampKeyfollowSlider->setRange (0, 127, 1);
    m_ampKeyfollowSlider->setSliderStyle (Slider::LinearBar);
    m_ampKeyfollowSlider->setTextBoxStyle (Slider::TextBoxLeft, false, 40, 20);
    m_ampKeyfollowSlider->setColour (Slider::backgroundColourId, Colour (0xfff2f59b));
    m_ampKeyfollowSlider->setColour (Slider::thumbColourId, Colour (0xffc4c86d));
    m_ampKeyfollowSlider->addListener (this);

    addAndMakeVisible (m_ampEnvVelCurveComboBox = new ParameterComboBox ("ampEnvVelCurveComboBox"));
    m_ampEnvVelCurveComboBox->setEditableText (false);
    m_ampEnvVelCurveComboBox->setJustificationType (Justification::centred);
    m_ampEnvVelCurveComboBox->setTextWhenNothingSelected (TRANS("Normal"));
    m_ampEnvVelCurveComboBox->setTextWhenNoChoicesAvailable (TRANS("(no choices)"));
    m_ampEnvVelCurveComboBox->addListener (this);

    addAndMakeVisible (m_ampEnvVelCurveDisplay = new ParameterVelCurveDisplay ("ampEnvVelCurveDisplay"));
    m_ampEnvVelCurveDisplay->setRange (0, 10, 0);
    m_ampEnvVelCurveDisplay->setSliderStyle (Slider::RotaryHorizontalVerticalDrag);
    m_ampEnvVelCurveDisplay->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    m_ampEnvVelCurveDisplay->addListener (this);

    addAndMakeVisible (m_ampBiasDirectionLabel = new Label ("ampBiasDirectionLabel",
                                                            TRANS("DIRECTION")));
    m_ampBiasDirectionLabel->setFont (Font (12.00f, Font::bold));
    m_ampBiasDirectionLabel->setJustificationType (Justification::centred);
    m_ampBiasDirectionLabel->setEditable (false, false, false);
    m_ampBiasDirectionLabel->setColour (Label::textColourId, Colours::black);
    m_ampBiasDirectionLabel->setColour (TextEditor::textColourId, Colours::black);
    m_ampBiasDirectionLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_ampBiasDirectionComboBox = new ParameterComboBox ("ampBiasDirectionComboBox"));
    m_ampBiasDirectionComboBox->setEditableText (false);
    m_ampBiasDirectionComboBox->setJustificationType (Justification::centred);
    m_ampBiasDirectionComboBox->setTextWhenNothingSelected (String());
    m_ampBiasDirectionComboBox->setTextWhenNoChoicesAvailable (TRANS("(no choices)"));
    m_ampBiasDirectionComboBox->addListener (this);

    addAndMakeVisible (m_ampEnvVelocityCurveLabel = new Label ("ampEnvVelocityCurveLabel",
                                                               TRANS("VELO CURVE")));
    m_ampEnvVelocityCurveLabel->setFont (Font (12.00f, Font::bold));
    m_ampEnvVelocityCurveLabel->setJustificationType (Justification::centred);
    m_ampEnvVelocityCurveLabel->setEditable (false, false, false);
    m_ampEnvVelocityCurveLabel->setColour (Label::textColourId, Colours::black);
    m_ampEnvVelocityCurveLabel->setColour (TextEditor::textColourId, Colours::black);
    m_ampEnvVelocityCurveLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_biasPointLabel = new Label ("biasPointLabel",
                                                     TRANS("POINT")));
    m_biasPointLabel->setFont (Font (12.00f, Font::bold));
    m_biasPointLabel->setJustificationType (Justification::centred);
    m_biasPointLabel->setEditable (false, false, false);
    m_biasPointLabel->setColour (Label::textColourId, Colours::black);
    m_biasPointLabel->setColour (TextEditor::textColourId, Colours::black);
    m_biasPointLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_biasPointSlider = new MicroParameterSlider ("biasPointSlider"));
    m_biasPointSlider->setRange (0, 127, 1);
    m_biasPointSlider->setSliderStyle (Slider::LinearBar);
    m_biasPointSlider->setTextBoxStyle (Slider::TextBoxLeft, false, 40, 20);
    m_biasPointSlider->setColour (Slider::backgroundColourId, Colour (0xfff2f59b));
    m_biasPointSlider->setColour (Slider::thumbColourId, Colour (0xffc4c86d));
    m_biasPointSlider->addListener (this);

    addAndMakeVisible (m_biasLevelLabel = new Label ("biasLevelLabel",
                                                     TRANS("LEVEL")));
    m_biasLevelLabel->setFont (Font (12.00f, Font::bold));
    m_biasLevelLabel->setJustificationType (Justification::centred);
    m_biasLevelLabel->setEditable (false, false, false);
    m_biasLevelLabel->setColour (Label::textColourId, Colours::black);
    m_biasLevelLabel->setColour (TextEditor::textColourId, Colours::black);
    m_biasLevelLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_biasLevelSlider = new MicroParameterSlider ("biasLevelSlider"));
    m_biasLevelSlider->setRange (0, 127, 1);
    m_biasLevelSlider->setSliderStyle (Slider::LinearBar);
    m_biasLevelSlider->setTextBoxStyle (Slider::TextBoxLeft, false, 40, 20);
    m_biasLevelSlider->setColour (Slider::backgroundColourId, Colour (0xfff2f59b));
    m_biasLevelSlider->setColour (Slider::thumbColourId, Colour (0xffc4c86d));
    m_biasLevelSlider->addListener (this);

    addAndMakeVisible (m_panRandomToggle = new BlackToggle());
    addAndMakeVisible (m_panRandomLabel = new Label ("panRandomLabel",
                                                     TRANS("RANDOM")));
    m_panRandomLabel->setFont (Font (12.00f, Font::bold));
    m_panRandomLabel->setJustificationType (Justification::centred);
    m_panRandomLabel->setEditable (false, false, false);
    m_panRandomLabel->setColour (Label::textColourId, Colours::black);
    m_panRandomLabel->setColour (TextEditor::textColourId, Colours::black);
    m_panRandomLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_panAlternateSlider = new MicroParameterSlider ("panAlternateSlider"));
    m_panAlternateSlider->setRange (0, 127, 1);
    m_panAlternateSlider->setSliderStyle (Slider::LinearBar);
    m_panAlternateSlider->setTextBoxStyle (Slider::TextBoxLeft, false, 40, 20);
    m_panAlternateSlider->setColour (Slider::backgroundColourId, Colour (0xfff2f59b));
    m_panAlternateSlider->setColour (Slider::thumbColourId, Colour (0xffc4c86d));
    m_panAlternateSlider->addListener (this);

    addAndMakeVisible (m_panAlternateLabel = new Label ("panAlternateLabel",
                                                        TRANS("ALTERNATE")));
    m_panAlternateLabel->setFont (Font (12.00f, Font::bold));
    m_panAlternateLabel->setJustificationType (Justification::centred);
    m_panAlternateLabel->setEditable (false, false, false);
    m_panAlternateLabel->setColour (Label::textColourId, Colours::black);
    m_panAlternateLabel->setColour (TextEditor::textColourId, Colours::black);
    m_panAlternateLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_lfoGrp = new PanelGroupGrey ("lfoGrp", "LFO MODULATION"));
    addAndMakeVisible (m_lfo1AmpDepthSlider = new Knob ("lfo1AmpDepthSlider"));
    m_lfo1AmpDepthSlider->setRange (0, 127, 1);
    m_lfo1AmpDepthSlider->setSliderStyle (Slider::RotaryHorizontalVerticalDrag);
    m_lfo1AmpDepthSlider->setTextBoxStyle (Slider::TextBoxBelow, false, 80, 16);
    m_lfo1AmpDepthSlider->setColour (Slider::textBoxBackgroundColourId, Colour (0xfff2f59b));
    m_lfo1AmpDepthSlider->addListener (this);

    addAndMakeVisible (m_lfo1AmpDepthLabel = new Label ("lfo1AmpDepthLabel",
                                                        TRANS("LVL LFO 1")));
    m_lfo1AmpDepthLabel->setFont (Font (12.00f, Font::bold));
    m_lfo1AmpDepthLabel->setJustificationType (Justification::centred);
    m_lfo1AmpDepthLabel->setEditable (false, false, false);
    m_lfo1AmpDepthLabel->setColour (Label::textColourId, Colours::black);
    m_lfo1AmpDepthLabel->setColour (TextEditor::textColourId, Colours::black);
    m_lfo1AmpDepthLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_lfo2AmpDepthSlider = new Knob ("lfo2AmpDepthSlider"));
    m_lfo2AmpDepthSlider->setRange (0, 127, 1);
    m_lfo2AmpDepthSlider->setSliderStyle (Slider::RotaryHorizontalVerticalDrag);
    m_lfo2AmpDepthSlider->setTextBoxStyle (Slider::TextBoxBelow, false, 80, 16);
    m_lfo2AmpDepthSlider->setColour (Slider::textBoxBackgroundColourId, Colour (0xfff2f59b));
    m_lfo2AmpDepthSlider->addListener (this);

    addAndMakeVisible (m_lfo2AmpDepthLabel = new Label ("lfo2AmpDepthLabel",
                                                        TRANS("LVL LFO 2")));
    m_lfo2AmpDepthLabel->setFont (Font (12.00f, Font::bold));
    m_lfo2AmpDepthLabel->setJustificationType (Justification::centred);
    m_lfo2AmpDepthLabel->setEditable (false, false, false);
    m_lfo2AmpDepthLabel->setColour (Label::textColourId, Colours::black);
    m_lfo2AmpDepthLabel->setColour (TextEditor::textColourId, Colours::black);
    m_lfo2AmpDepthLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_lfo1AdvancedButton = new TextWithArrowButton ("lfo1AdvancedButton"));
    m_lfo1AdvancedButton->setButtonText (TRANS("LFO 1"));
    m_lfo1AdvancedButton->addListener (this);

    addAndMakeVisible (m_lfo2AdvancedButton = new TextWithArrowButton ("lfo2AdvancedButton"));
    m_lfo2AdvancedButton->setButtonText (TRANS("LFO 2"));
    m_lfo2AdvancedButton->addListener (this);

    addAndMakeVisible (m_lfo1PanDepthSlider = new Knob ("lfo1PanDepthSlider"));
    m_lfo1PanDepthSlider->setRange (0, 127, 1);
    m_lfo1PanDepthSlider->setSliderStyle (Slider::RotaryHorizontalVerticalDrag);
    m_lfo1PanDepthSlider->setTextBoxStyle (Slider::TextBoxBelow, false, 80, 16);
    m_lfo1PanDepthSlider->setColour (Slider::textBoxBackgroundColourId, Colour (0xfff2f59b));
    m_lfo1PanDepthSlider->addListener (this);

    addAndMakeVisible (m_lfo1PanDepthLabel = new Label ("lfo1PanDepthLabel",
                                                        TRANS("PAN LFO 1")));
    m_lfo1PanDepthLabel->setFont (Font (12.00f, Font::bold));
    m_lfo1PanDepthLabel->setJustificationType (Justification::centred);
    m_lfo1PanDepthLabel->setEditable (false, false, false);
    m_lfo1PanDepthLabel->setColour (Label::textColourId, Colours::black);
    m_lfo1PanDepthLabel->setColour (TextEditor::textColourId, Colours::black);
    m_lfo1PanDepthLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_lfo2PanDepthSlider = new Knob ("lfo2PanDepthSlider"));
    m_lfo2PanDepthSlider->setRange (0, 127, 1);
    m_lfo2PanDepthSlider->setSliderStyle (Slider::RotaryHorizontalVerticalDrag);
    m_lfo2PanDepthSlider->setTextBoxStyle (Slider::TextBoxBelow, false, 80, 16);
    m_lfo2PanDepthSlider->setColour (Slider::textBoxBackgroundColourId, Colour (0xfff2f59b));
    m_lfo2PanDepthSlider->addListener (this);

    addAndMakeVisible (m_lfo2PanDepthLabel = new Label ("lfo2PanDepthLabel",
                                                        TRANS("PAN LFO 2")));
    m_lfo2PanDepthLabel->setFont (Font (12.00f, Font::bold));
    m_lfo2PanDepthLabel->setJustificationType (Justification::centred);
    m_lfo2PanDepthLabel->setEditable (false, false, false);
    m_lfo2PanDepthLabel->setColour (Label::textColourId, Colours::black);
    m_lfo2PanDepthLabel->setColour (TextEditor::textColourId, Colours::black);
    m_lfo2PanDepthLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_imageButton = new ImageButton ("imageButton"));
    m_imageButton->setButtonText (String());

    m_imageButton->setImages (false, true, true,
                              ImageCache::getFromMemory (amp_png, amp_pngSize), 1.000f, Colour (0x4340454a),
                              Image(), 1.000f, Colour (0x4340454a),
                              Image(), 1.000f, Colour (0x4340454a));
    addAndMakeVisible (m_toneLevelSlider = new ParameterEnvelopeSlider ("toneLevelSlider"));
    m_toneLevelSlider->setRange (0, 127, 1);
    m_toneLevelSlider->setSliderStyle (Slider::LinearVertical);
    m_toneLevelSlider->setTextBoxStyle (Slider::TextBoxBelow, false, 56, 16);
    m_toneLevelSlider->setColour (Slider::backgroundColourId, Colour (0x00f2f59b));
    m_toneLevelSlider->setColour (Slider::textBoxBackgroundColourId, Colour (0xfff2f59b));
    m_toneLevelSlider->addListener (this);

    addAndMakeVisible (m_filterEnvelopeDepthLabel = new Label ("filterEnvelopeDepthLabel",
                                                               TRANS("TONE LEVEL")));
    m_filterEnvelopeDepthLabel->setFont (Font (12.00f, Font::bold));
    m_filterEnvelopeDepthLabel->setJustificationType (Justification::centred);
    m_filterEnvelopeDepthLabel->setEditable (false, false, false);
    m_filterEnvelopeDepthLabel->setColour (Label::textColourId, Colours::black);
    m_filterEnvelopeDepthLabel->setColour (TextEditor::textColourId, Colours::black);
    m_filterEnvelopeDepthLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_imageButton2 = new ImageButton ("imageButton"));
    m_imageButton2->setButtonText (String());

    m_imageButton2->setImages (false, true, true,
                               ImageCache::getFromMemory (amp_png, amp_pngSize), 1.000f, Colour (0x4340454a),
                               Image(), 1.000f, Colour (0x4340454a),
                               Image(), 1.000f, Colour (0x4340454a));
    addAndMakeVisible (m_imageButton3 = new ImageButton ("imageButton"));
    m_imageButton3->setButtonText (String());
    m_imageButton3->addListener (this);

    m_imageButton3->setImages (false, true, true,
                               ImageCache::getFromMemory (lfo_png, lfo_pngSize), 1.000f, Colour (0x4340454a),
                               Image(), 1.000f, Colour (0x4340454a),
                               Image(), 1.000f, Colour (0x4340454a));

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
void AmpEditorAdvanced::paint (Graphics& g)
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
    m_tonePanSlider->setBounds (208, 40, 48, 60);
    m_tonePanLabel->setBounds (196, 20, 72, 16);
    m_ampEnv->setBounds (72, 156, 296, 156);
    m_panKeyfollowLabel->setBounds (280, 32, 80, 16);
    m_panKeyfollowSlider->setBounds (296, 48, 48, 16);
    m_ampVelocitySensSlider->setBounds (8, 306, 56, 16);
    m_ampEnvVelocitySensLabel->setBounds (0, 290, 72, 16);
    m_ampEnvVelocityTime1Slider->setBounds (124, 332, 56, 16);
    m_ampEnvVelocityTime1Label->setBounds (84, 316, 112, 16);
    m_ampEnvVelocityTime4Slider->setBounds (300, 332, 56, 16);
    m_ampEnvVelocityTime4Label->setBounds (264, 316, 112, 16);
    m_ampEnvTimeKeyfollow->setBounds (184, 356, 172, 16);
    m_ampKeyfollowSlider->setBounds (252, 372, 56, 16);
    m_ampEnvVelCurveComboBox->setBounds (8, 343, 68, 16);
    m_ampEnvVelCurveDisplay->setBounds (20, 363, 36, 36);
    m_ampBiasDirectionLabel->setBounds (96, 32, 84, 16);
    m_ampBiasDirectionComboBox->setBounds (88, 48, 100, 16);
    m_ampEnvVelocityCurveLabel->setBounds (0, 327, 80, 16);
    m_biasPointLabel->setBounds (88, 68, 48, 16);
    m_biasPointSlider->setBounds (88, 84, 48, 16);
    m_biasLevelLabel->setBounds (140, 68, 48, 16);
    m_biasLevelSlider->setBounds (140, 84, 48, 16);
    m_panRandomToggle->setBounds (307, 82, 25, 17);
    m_panRandomLabel->setBounds (287, 66, 64, 16);
    m_panAlternateSlider->setBounds (292, 116, 56, 16);
    m_panAlternateLabel->setBounds (280, 100, 80, 16);
    m_lfoGrp->setBounds (0, 404, getWidth() - 0, 88);
    m_lfo1AmpDepthSlider->setBounds (16, 436, 32, 48);
    m_lfo1AmpDepthLabel->setBounds (0, 420, 68, 16);
    m_lfo2AmpDepthSlider->setBounds (204, 436, 32, 48);
    m_lfo2AmpDepthLabel->setBounds (188, 420, 68, 16);
    m_lfo1AdvancedButton->setBounds (124, 464, 56, 21);
    m_lfo2AdvancedButton->setBounds (312, 464, 56, 21);
    m_lfo1PanDepthSlider->setBounds (84, 436, 32, 48);
    m_lfo1PanDepthLabel->setBounds (68, 420, 68, 16);
    m_lfo2PanDepthSlider->setBounds (272, 436, 32, 48);
    m_lfo2PanDepthLabel->setBounds (256, 420, 68, 16);
    m_imageButton->setBounds (3, 1, 16, 16);
    m_toneLevelSlider->setBounds (8, 168, 56, 116);
    m_filterEnvelopeDepthLabel->setBounds (0, 156, 72, 16);
    m_imageButton2->setBounds (3, 141, 16, 16);
    m_imageButton3->setBounds (3, 405, 16, 16);
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void AmpEditorAdvanced::sliderValueChanged (Slider* sliderThatWasMoved)
{
    //[UsersliderValueChanged_Pre]
    //[/UsersliderValueChanged_Pre]

    if (sliderThatWasMoved == m_tonePanSlider)
    {
        //[UserSliderCode_m_tonePanSlider] -- add your slider handling code here..
        //[/UserSliderCode_m_tonePanSlider]
    }
    else if (sliderThatWasMoved == m_panKeyfollowSlider)
    {
        //[UserSliderCode_m_panKeyfollowSlider] -- add your slider handling code here..
        //[/UserSliderCode_m_panKeyfollowSlider]
    }
    else if (sliderThatWasMoved == m_ampVelocitySensSlider)
    {
        //[UserSliderCode_m_ampVelocitySensSlider] -- add your slider handling code here..
        //[/UserSliderCode_m_ampVelocitySensSlider]
    }
    else if (sliderThatWasMoved == m_ampEnvVelocityTime1Slider)
    {
        //[UserSliderCode_m_ampEnvVelocityTime1Slider] -- add your slider handling code here..
        //[/UserSliderCode_m_ampEnvVelocityTime1Slider]
    }
    else if (sliderThatWasMoved == m_ampEnvVelocityTime4Slider)
    {
        //[UserSliderCode_m_ampEnvVelocityTime4Slider] -- add your slider handling code here..
        //[/UserSliderCode_m_ampEnvVelocityTime4Slider]
    }
    else if (sliderThatWasMoved == m_ampKeyfollowSlider)
    {
        //[UserSliderCode_m_ampKeyfollowSlider] -- add your slider handling code here..
        //[/UserSliderCode_m_ampKeyfollowSlider]
    }
    else if (sliderThatWasMoved == m_ampEnvVelCurveDisplay)
    {
        //[UserSliderCode_m_ampEnvVelCurveDisplay] -- add your slider handling code here..
        //[/UserSliderCode_m_ampEnvVelCurveDisplay]
    }
    else if (sliderThatWasMoved == m_biasPointSlider)
    {
        //[UserSliderCode_m_biasPointSlider] -- add your slider handling code here..
        //[/UserSliderCode_m_biasPointSlider]
    }
    else if (sliderThatWasMoved == m_biasLevelSlider)
    {
        //[UserSliderCode_m_biasLevelSlider] -- add your slider handling code here..
        //[/UserSliderCode_m_biasLevelSlider]
    }
    else if (sliderThatWasMoved == m_panAlternateSlider)
    {
        //[UserSliderCode_m_panAlternateSlider] -- add your slider handling code here..
        //[/UserSliderCode_m_panAlternateSlider]
    }
    else if (sliderThatWasMoved == m_lfo1AmpDepthSlider)
    {
        //[UserSliderCode_m_lfo1AmpDepthSlider] -- add your slider handling code here..
        //[/UserSliderCode_m_lfo1AmpDepthSlider]
    }
    else if (sliderThatWasMoved == m_lfo2AmpDepthSlider)
    {
        //[UserSliderCode_m_lfo2AmpDepthSlider] -- add your slider handling code here..
        //[/UserSliderCode_m_lfo2AmpDepthSlider]
    }
    else if (sliderThatWasMoved == m_lfo1PanDepthSlider)
    {
        //[UserSliderCode_m_lfo1PanDepthSlider] -- add your slider handling code here..
        //[/UserSliderCode_m_lfo1PanDepthSlider]
    }
    else if (sliderThatWasMoved == m_lfo2PanDepthSlider)
    {
        //[UserSliderCode_m_lfo2PanDepthSlider] -- add your slider handling code here..
        //[/UserSliderCode_m_lfo2PanDepthSlider]
    }
    else if (sliderThatWasMoved == m_toneLevelSlider)
    {
        //[UserSliderCode_m_toneLevelSlider] -- add your slider handling code here..
        //[/UserSliderCode_m_toneLevelSlider]
    }

    //[UsersliderValueChanged_Post]
    //[/UsersliderValueChanged_Post]
}

void AmpEditorAdvanced::comboBoxChanged (ComboBox* comboBoxThatHasChanged)
{
    //[UsercomboBoxChanged_Pre]
    //[/UsercomboBoxChanged_Pre]

    if (comboBoxThatHasChanged == m_ampEnvVelCurveComboBox)
    {
        //[UserComboBoxCode_m_ampEnvVelCurveComboBox] -- add your combo box handling code here..
        //[/UserComboBoxCode_m_ampEnvVelCurveComboBox]
    }
    else if (comboBoxThatHasChanged == m_ampBiasDirectionComboBox)
    {
        //[UserComboBoxCode_m_ampBiasDirectionComboBox] -- add your combo box handling code here..
        //[/UserComboBoxCode_m_ampBiasDirectionComboBox]
    }

    //[UsercomboBoxChanged_Post]
    //[/UsercomboBoxChanged_Post]
}

void AmpEditorAdvanced::buttonClicked (Button* buttonThatWasClicked)
{
    //[UserbuttonClicked_Pre]
    //[/UserbuttonClicked_Pre]

    if (buttonThatWasClicked == m_lfo1AdvancedButton)
    {
        //[UserButtonCode_m_lfo1AdvancedButton] -- add your button handler code here..
		LfoEditorAdvanced* advancedLfoEditor = new LfoEditorAdvanced("LFO", m_part, m_tone, false);
		CallOutBox::launchAsynchronously(advancedLfoEditor, m_lfo1AdvancedButton->getScreenBounds(), nullptr);
        //[/UserButtonCode_m_lfo1AdvancedButton]
    }
    else if (buttonThatWasClicked == m_lfo2AdvancedButton)
    {
        //[UserButtonCode_m_lfo2AdvancedButton] -- add your button handler code here..
		LfoEditorAdvanced* advancedLfoEditor = new LfoEditorAdvanced("LFO", m_part, m_tone, true);
		CallOutBox::launchAsynchronously(advancedLfoEditor, m_lfo2AdvancedButton->getScreenBounds(), nullptr);
        //[/UserButtonCode_m_lfo2AdvancedButton]
    }
    else if (buttonThatWasClicked == m_imageButton3)
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
/*  -- Introjucer information section --

    This is where the Introjucer stores the metadata that describe this GUI layout, so
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
          textboxbkgd="fff2f59b" min="0" max="127" int="1" style="RotaryHorizontalVerticalDrag"
          textBoxPos="TextBoxBelow" textBoxEditable="1" textBoxWidth="80"
          textBoxHeight="16" skewFactor="1"/>
  <LABEL name="tonePanLabel" id="b464bd3cbdae27fd" memberName="m_tonePanLabel"
         virtualName="" explicitFocusOrder="0" pos="196 20 72 16" textCol="ff000000"
         edTextCol="ff000000" edBkgCol="0" labelText="TONE PAN" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="12" bold="1" italic="0" justification="36"/>
  <JUCERCOMP name="ampEnv" id="99a40d72d7ad1e22" memberName="m_ampEnv" virtualName=""
             explicitFocusOrder="0" pos="72 156 296 156" sourceFile="Envelope.cpp"
             constructorParams="(AllParts)m_part, m_tone, EnvelopeTypes::Amp, false"/>
  <LABEL name="panKeyfollowLabel" id="3a52299341c28960" memberName="m_panKeyfollowLabel"
         virtualName="" explicitFocusOrder="0" pos="280 32 80 16" textCol="ff000000"
         edTextCol="ff000000" edBkgCol="0" labelText="KEYFOLLOW" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="12" bold="1" italic="0" justification="36"/>
  <SLIDER name="panKeyfollowSlider" id="70b45a3a21f5522" memberName="m_panKeyfollowSlider"
          virtualName="KeyfollowMicroParameterSlider" explicitFocusOrder="0"
          pos="296 48 48 16" bkgcol="fff2f59b" thumbcol="ffc4c86d" min="0"
          max="127" int="1" style="LinearBar" textBoxPos="TextBoxLeft"
          textBoxEditable="1" textBoxWidth="40" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="ampVelocitySensSlider" id="ce3036a9c9d2d09a" memberName="m_ampVelocitySensSlider"
          virtualName="MicroParameterSlider" explicitFocusOrder="0" pos="8 306 56 16"
          bkgcol="fff2f59b" thumbcol="ffc4c86d" min="0" max="127" int="1"
          style="LinearBar" textBoxPos="TextBoxLeft" textBoxEditable="1"
          textBoxWidth="40" textBoxHeight="20" skewFactor="1"/>
  <LABEL name="ampEnvVelocitySensLabel" id="da6b2f045679c497" memberName="m_ampEnvVelocitySensLabel"
         virtualName="" explicitFocusOrder="0" pos="0 290 72 16" textCol="ff000000"
         edTextCol="ff000000" edBkgCol="0" labelText="VELO SENS" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="12" bold="1" italic="0" justification="36"/>
  <SLIDER name="ampEnvVelocityTime1Slider" id="26e8b1e9ec956faf" memberName="m_ampEnvVelocityTime1Slider"
          virtualName="MicroParameterSlider" explicitFocusOrder="0" pos="124 332 56 16"
          bkgcol="fff2f59b" thumbcol="ffc4c86d" min="0" max="127" int="1"
          style="LinearBar" textBoxPos="TextBoxLeft" textBoxEditable="1"
          textBoxWidth="40" textBoxHeight="20" skewFactor="1"/>
  <LABEL name="ampEnvVelocityTime1Label" id="fcf555c7750e1905" memberName="m_ampEnvVelocityTime1Label"
         virtualName="" explicitFocusOrder="0" pos="84 316 112 16" textCol="ff000000"
         edTextCol="ff000000" edBkgCol="0" labelText="VELO SENS TIME 1"
         editableSingleClick="0" editableDoubleClick="0" focusDiscardsChanges="0"
         fontname="Default font" fontsize="12" bold="1" italic="0" justification="36"/>
  <SLIDER name="ampEnvVelocityTime4Slider" id="96d5b92b9bc16388" memberName="m_ampEnvVelocityTime4Slider"
          virtualName="MicroParameterSlider" explicitFocusOrder="0" pos="300 332 56 16"
          bkgcol="fff2f59b" thumbcol="ffc4c86d" min="0" max="127" int="1"
          style="LinearBar" textBoxPos="TextBoxLeft" textBoxEditable="1"
          textBoxWidth="40" textBoxHeight="20" skewFactor="1"/>
  <LABEL name="ampEnvVelocityTime4Label" id="d741df9cfd6aac2d" memberName="m_ampEnvVelocityTime4Label"
         virtualName="" explicitFocusOrder="0" pos="264 316 112 16" textCol="ff000000"
         edTextCol="ff000000" edBkgCol="0" labelText="VELO SENS TIME 4"
         editableSingleClick="0" editableDoubleClick="0" focusDiscardsChanges="0"
         fontname="Default font" fontsize="12" bold="1" italic="0" justification="36"/>
  <LABEL name="ampEnvTimeKeyfollow" id="cf887a8299fda426" memberName="m_ampEnvTimeKeyfollow"
         virtualName="" explicitFocusOrder="0" pos="184 356 172 16" textCol="ff000000"
         edTextCol="ff000000" edBkgCol="0" labelText="KEYFOLLOW TIME 2/3/4 "
         editableSingleClick="0" editableDoubleClick="0" focusDiscardsChanges="0"
         fontname="Default font" fontsize="12" bold="1" italic="0" justification="36"/>
  <SLIDER name="ampKeyfollowSlider" id="fd7fba1a74d4d802" memberName="m_ampKeyfollowSlider"
          virtualName="KeyfollowMicroParameterSlider" explicitFocusOrder="0"
          pos="252 372 56 16" bkgcol="fff2f59b" thumbcol="ffc4c86d" min="0"
          max="127" int="1" style="LinearBar" textBoxPos="TextBoxLeft"
          textBoxEditable="1" textBoxWidth="40" textBoxHeight="20" skewFactor="1"/>
  <COMBOBOX name="ampEnvVelCurveComboBox" id="5f5f3969c23f54e2" memberName="m_ampEnvVelCurveComboBox"
            virtualName="ParameterComboBox" explicitFocusOrder="0" pos="8 343 68 16"
            editable="0" layout="36" items="" textWhenNonSelected="Normal"
            textWhenNoItems="(no choices)"/>
  <SLIDER name="ampEnvVelCurveDisplay" id="d9c13bc39fc51534" memberName="m_ampEnvVelCurveDisplay"
          virtualName="ParameterVelCurveDisplay" explicitFocusOrder="0"
          pos="20 363 36 36" min="0" max="10" int="0" style="RotaryHorizontalVerticalDrag"
          textBoxPos="NoTextBox" textBoxEditable="1" textBoxWidth="80"
          textBoxHeight="20" skewFactor="1"/>
  <LABEL name="ampBiasDirectionLabel" id="c41c307042cbea72" memberName="m_ampBiasDirectionLabel"
         virtualName="" explicitFocusOrder="0" pos="96 32 84 16" textCol="ff000000"
         edTextCol="ff000000" edBkgCol="0" labelText="DIRECTION" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="12" bold="1" italic="0" justification="36"/>
  <COMBOBOX name="ampBiasDirectionComboBox" id="e8c10ecedfc6fd9e" memberName="m_ampBiasDirectionComboBox"
            virtualName="ParameterComboBox" explicitFocusOrder="0" pos="88 48 100 16"
            editable="0" layout="36" items="" textWhenNonSelected="" textWhenNoItems="(no choices)"/>
  <LABEL name="ampEnvVelocityCurveLabel" id="4fa3b6178a95b9c" memberName="m_ampEnvVelocityCurveLabel"
         virtualName="" explicitFocusOrder="0" pos="0 327 80 16" textCol="ff000000"
         edTextCol="ff000000" edBkgCol="0" labelText="VELO CURVE" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="12" bold="1" italic="0" justification="36"/>
  <LABEL name="biasPointLabel" id="8db74046eb660d30" memberName="m_biasPointLabel"
         virtualName="" explicitFocusOrder="0" pos="88 68 48 16" textCol="ff000000"
         edTextCol="ff000000" edBkgCol="0" labelText="POINT" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="12" bold="1" italic="0" justification="36"/>
  <SLIDER name="biasPointSlider" id="4ef39c9a6ee52b73" memberName="m_biasPointSlider"
          virtualName="MicroParameterSlider" explicitFocusOrder="0" pos="88 84 48 16"
          bkgcol="fff2f59b" thumbcol="ffc4c86d" min="0" max="127" int="1"
          style="LinearBar" textBoxPos="TextBoxLeft" textBoxEditable="1"
          textBoxWidth="40" textBoxHeight="20" skewFactor="1"/>
  <LABEL name="biasLevelLabel" id="1b7c77405f23be2c" memberName="m_biasLevelLabel"
         virtualName="" explicitFocusOrder="0" pos="140 68 48 16" textCol="ff000000"
         edTextCol="ff000000" edBkgCol="0" labelText="LEVEL" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="12" bold="1" italic="0" justification="36"/>
  <SLIDER name="biasLevelSlider" id="2155aedfd6600e68" memberName="m_biasLevelSlider"
          virtualName="MicroParameterSlider" explicitFocusOrder="0" pos="140 84 48 16"
          bkgcol="fff2f59b" thumbcol="ffc4c86d" min="0" max="127" int="1"
          style="LinearBar" textBoxPos="TextBoxLeft" textBoxEditable="1"
          textBoxWidth="40" textBoxHeight="20" skewFactor="1"/>
  <JUCERCOMP name="panRandomToggle" id="1dee3cc7cfd57bb1" memberName="m_panRandomToggle"
             virtualName="" explicitFocusOrder="0" pos="307 82 25 17" sourceFile="../ParameterWidgets/BlackToggle.cpp"
             constructorParams=""/>
  <LABEL name="panRandomLabel" id="1e3525d1a10dd56c" memberName="m_panRandomLabel"
         virtualName="" explicitFocusOrder="0" pos="287 66 64 16" textCol="ff000000"
         edTextCol="ff000000" edBkgCol="0" labelText="RANDOM" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="12" bold="1" italic="0" justification="36"/>
  <SLIDER name="panAlternateSlider" id="7aed98a67fac3fdb" memberName="m_panAlternateSlider"
          virtualName="MicroParameterSlider" explicitFocusOrder="0" pos="292 116 56 16"
          bkgcol="fff2f59b" thumbcol="ffc4c86d" min="0" max="127" int="1"
          style="LinearBar" textBoxPos="TextBoxLeft" textBoxEditable="1"
          textBoxWidth="40" textBoxHeight="20" skewFactor="1"/>
  <LABEL name="panAlternateLabel" id="674286f7173a73be" memberName="m_panAlternateLabel"
         virtualName="" explicitFocusOrder="0" pos="280 100 80 16" textCol="ff000000"
         edTextCol="ff000000" edBkgCol="0" labelText="ALTERNATE" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="12" bold="1" italic="0" justification="36"/>
  <JUCERCOMP name="lfoGrp" id="5d2169b0330e13c6" memberName="m_lfoGrp" virtualName="PanelGroupGrey"
             explicitFocusOrder="0" pos="0 404 0M 88" sourceFile="../GroupWidgets/PanelGroupTransp.cpp"
             constructorParams="&quot;lfoGrp&quot;, &quot;LFO MODULATION&quot;"/>
  <SLIDER name="lfo1AmpDepthSlider" id="5139dffd40f5b193" memberName="m_lfo1AmpDepthSlider"
          virtualName="Knob" explicitFocusOrder="0" pos="16 436 32 48"
          textboxbkgd="fff2f59b" min="0" max="127" int="1" style="RotaryHorizontalVerticalDrag"
          textBoxPos="TextBoxBelow" textBoxEditable="1" textBoxWidth="80"
          textBoxHeight="16" skewFactor="1"/>
  <LABEL name="lfo1AmpDepthLabel" id="ddaad26232bd3db3" memberName="m_lfo1AmpDepthLabel"
         virtualName="" explicitFocusOrder="0" pos="0 420 68 16" textCol="ff000000"
         edTextCol="ff000000" edBkgCol="0" labelText="LVL LFO 1" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="12" bold="1" italic="0" justification="36"/>
  <SLIDER name="lfo2AmpDepthSlider" id="37bb334dae2c4ad2" memberName="m_lfo2AmpDepthSlider"
          virtualName="Knob" explicitFocusOrder="0" pos="204 436 32 48"
          textboxbkgd="fff2f59b" min="0" max="127" int="1" style="RotaryHorizontalVerticalDrag"
          textBoxPos="TextBoxBelow" textBoxEditable="1" textBoxWidth="80"
          textBoxHeight="16" skewFactor="1"/>
  <LABEL name="lfo2AmpDepthLabel" id="20feaad1dd36b9a5" memberName="m_lfo2AmpDepthLabel"
         virtualName="" explicitFocusOrder="0" pos="188 420 68 16" textCol="ff000000"
         edTextCol="ff000000" edBkgCol="0" labelText="LVL LFO 2" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="12" bold="1" italic="0" justification="36"/>
  <TEXTBUTTON name="lfo1AdvancedButton" id="9de90d61ee7dcce4" memberName="m_lfo1AdvancedButton"
              virtualName="TextWithArrowButton" explicitFocusOrder="0" pos="124 464 56 21"
              buttonText="LFO 1" connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="lfo2AdvancedButton" id="596fa9d632d5c1d1" memberName="m_lfo2AdvancedButton"
              virtualName="TextWithArrowButton" explicitFocusOrder="0" pos="312 464 56 21"
              buttonText="LFO 2" connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <SLIDER name="lfo1PanDepthSlider" id="c423b0297a1ea359" memberName="m_lfo1PanDepthSlider"
          virtualName="Knob" explicitFocusOrder="0" pos="84 436 32 48"
          textboxbkgd="fff2f59b" min="0" max="127" int="1" style="RotaryHorizontalVerticalDrag"
          textBoxPos="TextBoxBelow" textBoxEditable="1" textBoxWidth="80"
          textBoxHeight="16" skewFactor="1"/>
  <LABEL name="lfo1PanDepthLabel" id="ae0b0bedb7b968c0" memberName="m_lfo1PanDepthLabel"
         virtualName="" explicitFocusOrder="0" pos="68 420 68 16" textCol="ff000000"
         edTextCol="ff000000" edBkgCol="0" labelText="PAN LFO 1" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="12" bold="1" italic="0" justification="36"/>
  <SLIDER name="lfo2PanDepthSlider" id="d7070b8492bc762b" memberName="m_lfo2PanDepthSlider"
          virtualName="Knob" explicitFocusOrder="0" pos="272 436 32 48"
          textboxbkgd="fff2f59b" min="0" max="127" int="1" style="RotaryHorizontalVerticalDrag"
          textBoxPos="TextBoxBelow" textBoxEditable="1" textBoxWidth="80"
          textBoxHeight="16" skewFactor="1"/>
  <LABEL name="lfo2PanDepthLabel" id="4c1b4ff05ff89f84" memberName="m_lfo2PanDepthLabel"
         virtualName="" explicitFocusOrder="0" pos="256 420 68 16" textCol="ff000000"
         edTextCol="ff000000" edBkgCol="0" labelText="PAN LFO 2" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="12" bold="1" italic="0" justification="36"/>
  <IMAGEBUTTON name="imageButton" id="f18ffef17196cb40" memberName="m_imageButton"
               virtualName="" explicitFocusOrder="0" pos="3 1 16 16" buttonText=""
               connectedEdges="0" needsCallback="0" radioGroupId="0" keepProportions="1"
               resourceNormal="amp_png" opacityNormal="1" colourNormal="4340454a"
               resourceOver="" opacityOver="1" colourOver="4340454a" resourceDown=""
               opacityDown="1" colourDown="4340454a"/>
  <SLIDER name="toneLevelSlider" id="b0bd5a61181f569c" memberName="m_toneLevelSlider"
          virtualName="ParameterEnvelopeSlider" explicitFocusOrder="0"
          pos="8 168 56 116" bkgcol="f2f59b" textboxbkgd="fff2f59b" min="0"
          max="127" int="1" style="LinearVertical" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="56" textBoxHeight="16" skewFactor="1"/>
  <LABEL name="filterEnvelopeDepthLabel" id="611da7e96f52143f" memberName="m_filterEnvelopeDepthLabel"
         virtualName="" explicitFocusOrder="0" pos="0 156 72 16" textCol="ff000000"
         edTextCol="ff000000" edBkgCol="0" labelText="TONE LEVEL" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="12" bold="1" italic="0" justification="36"/>
  <IMAGEBUTTON name="imageButton" id="3a50d5aaabf6910d" memberName="m_imageButton2"
               virtualName="" explicitFocusOrder="0" pos="3 141 16 16" buttonText=""
               connectedEdges="0" needsCallback="0" radioGroupId="0" keepProportions="1"
               resourceNormal="amp_png" opacityNormal="1" colourNormal="4340454a"
               resourceOver="" opacityOver="1" colourOver="4340454a" resourceDown=""
               opacityDown="1" colourDown="4340454a"/>
  <IMAGEBUTTON name="imageButton" id="570f3b3b741de5e4" memberName="m_imageButton3"
               virtualName="" explicitFocusOrder="0" pos="3 405 16 16" buttonText=""
               connectedEdges="0" needsCallback="1" radioGroupId="0" keepProportions="1"
               resourceNormal="lfo_png" opacityNormal="1" colourNormal="4340454a"
               resourceOver="" opacityOver="1" colourOver="4340454a" resourceDown=""
               opacityDown="1" colourDown="4340454a"/>
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
