/*
  ==============================================================================

  This is an automatically generated GUI class created by the Introjucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Introjucer version: 3.1.0

  ------------------------------------------------------------------------------

  The Introjucer is part of the JUCE library - "Jules' Utility Class Extensions"
  Copyright 2004-13 by Raw Material Software Ltd.

  ==============================================================================
*/

//[Headers] You can add your own extra header files here...
#include "../../GrooveboxMemory/OverallMemoryBlock.h"
//[/Headers]

#include "PitchEditorAdvanced.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
extern OverallMemoryBlock* grooveboxMemory;
//[/MiscUserDefs]

//==============================================================================
PitchEditorAdvanced::PitchEditorAdvanced (const String &componentName, SynthParts part, Tone tone)
    : Component (componentName), m_part(part), m_tone(tone)
{
    addAndMakeVisible (m_pitchGrp = new PanelGroupGrey ("pitchGrp", getName()));
    addAndMakeVisible (m_lfoGrp = new PanelGroupGrey ("lfoGrp", "LFO MODULATION"));
    addAndMakeVisible (m_pitchGrp2 = new PanelGroupGrey ("pitchEnvGrp", getName().toUpperCase()+" ENVELOPE"));
    addAndMakeVisible (m_coarseTuneSlider = new Knob ("coarseTuneSlider"));
    m_coarseTuneSlider->setRange (0, 127, 1);
    m_coarseTuneSlider->setSliderStyle (Slider::RotaryHorizontalVerticalDrag);
    m_coarseTuneSlider->setTextBoxStyle (Slider::TextBoxBelow, false, 80, 16);
    m_coarseTuneSlider->setColour (Slider::textBoxBackgroundColourId, Colour (0xfff2f59b));
    m_coarseTuneSlider->addListener (this);

    addAndMakeVisible (m_coarseTuneLabel = new Label ("coarseTuneLabel",
                                                      "COARSE"));
    m_coarseTuneLabel->setFont (Font (12.00f, Font::bold));
    m_coarseTuneLabel->setJustificationType (Justification::centred);
    m_coarseTuneLabel->setEditable (false, false, false);
    m_coarseTuneLabel->setColour (Label::textColourId, Colours::black);
    m_coarseTuneLabel->setColour (TextEditor::textColourId, Colours::black);
    m_coarseTuneLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_pitchEnv = new Envelope (m_part, m_tone, EnvelopeTypes::Pitch, false));
    addAndMakeVisible (m_randomPitchDepthSlider = new MicroParameterSlider ("randomPitchDepthLabel"));
    m_randomPitchDepthSlider->setRange (0, 127, 1);
    m_randomPitchDepthSlider->setSliderStyle (Slider::LinearBar);
    m_randomPitchDepthSlider->setTextBoxStyle (Slider::TextBoxLeft, false, 40, 20);
    m_randomPitchDepthSlider->setColour (Slider::backgroundColourId, Colour (0xfff2f59b));
    m_randomPitchDepthSlider->setColour (Slider::thumbColourId, Colour (0xffc4c86d));
    m_randomPitchDepthSlider->addListener (this);

    addAndMakeVisible (m_randomPitchDepthLabel = new Label ("randomPitchDepthLabel",
                                                            "RANDOMNESS"));
    m_randomPitchDepthLabel->setFont (Font (12.00f, Font::bold));
    m_randomPitchDepthLabel->setJustificationType (Justification::centred);
    m_randomPitchDepthLabel->setEditable (true, true, false);
    m_randomPitchDepthLabel->setColour (Label::textColourId, Colours::black);
    m_randomPitchDepthLabel->setColour (TextEditor::textColourId, Colours::black);
    m_randomPitchDepthLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));
    m_randomPitchDepthLabel->addListener (this);

    addAndMakeVisible (m_pitchKeyfollowLabel = new Label ("pitchKeyfollowLabel",
                                                          "KEYFOLLOW"));
    m_pitchKeyfollowLabel->setFont (Font (12.00f, Font::bold));
    m_pitchKeyfollowLabel->setJustificationType (Justification::centred);
    m_pitchKeyfollowLabel->setEditable (false, false, false);
    m_pitchKeyfollowLabel->setColour (Label::textColourId, Colours::black);
    m_pitchKeyfollowLabel->setColour (TextEditor::textColourId, Colours::black);
    m_pitchKeyfollowLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_pitchKeyfollowSlider = new KeyfollowMicroParameterSlider ("pitchKeyfollowSlider"));
    m_pitchKeyfollowSlider->setRange (0, 127, 1);
    m_pitchKeyfollowSlider->setSliderStyle (Slider::LinearBar);
    m_pitchKeyfollowSlider->setTextBoxStyle (Slider::TextBoxLeft, false, 40, 20);
    m_pitchKeyfollowSlider->setColour (Slider::backgroundColourId, Colour (0xfff2f59b));
    m_pitchKeyfollowSlider->setColour (Slider::thumbColourId, Colour (0xffc4c86d));
    m_pitchKeyfollowSlider->addListener (this);

    addAndMakeVisible (m_pitchEnvelopeDepthSlider = new ParameterEnvelopeSlider ("pitchEnvelopeDepthSlider"));
    m_pitchEnvelopeDepthSlider->setRange (0, 127, 1);
    m_pitchEnvelopeDepthSlider->setSliderStyle (Slider::LinearVertical);
    m_pitchEnvelopeDepthSlider->setTextBoxStyle (Slider::TextBoxBelow, false, 56, 16);
    m_pitchEnvelopeDepthSlider->setColour (Slider::backgroundColourId, Colour (0x00f2f59b));
    m_pitchEnvelopeDepthSlider->setColour (Slider::textBoxBackgroundColourId, Colour (0xfff2f59b));
    m_pitchEnvelopeDepthSlider->addListener (this);

    addAndMakeVisible (m_pitchEnvelopeDepthLabel = new Label ("pitchEnvelopeDepthLabel",
                                                              "DEPTH"));
    m_pitchEnvelopeDepthLabel->setFont (Font (12.00f, Font::bold));
    m_pitchEnvelopeDepthLabel->setJustificationType (Justification::centred);
    m_pitchEnvelopeDepthLabel->setEditable (false, false, false);
    m_pitchEnvelopeDepthLabel->setColour (Label::textColourId, Colours::black);
    m_pitchEnvelopeDepthLabel->setColour (TextEditor::textColourId, Colours::black);
    m_pitchEnvelopeDepthLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_pitchVelocitySensSlider = new MicroParameterSlider ("pitchVelocitySensSlider"));
    m_pitchVelocitySensSlider->setRange (0, 127, 1);
    m_pitchVelocitySensSlider->setSliderStyle (Slider::LinearBar);
    m_pitchVelocitySensSlider->setTextBoxStyle (Slider::TextBoxLeft, false, 40, 20);
    m_pitchVelocitySensSlider->setColour (Slider::backgroundColourId, Colour (0xfff2f59b));
    m_pitchVelocitySensSlider->setColour (Slider::thumbColourId, Colour (0xffc4c86d));
    m_pitchVelocitySensSlider->addListener (this);

    addAndMakeVisible (m_pitchEnvVelocitySensLabel = new Label ("pitchEnvVelocitySensLabel",
                                                                "VELO SENS"));
    m_pitchEnvVelocitySensLabel->setFont (Font (12.00f, Font::bold));
    m_pitchEnvVelocitySensLabel->setJustificationType (Justification::centred);
    m_pitchEnvVelocitySensLabel->setEditable (false, false, false);
    m_pitchEnvVelocitySensLabel->setColour (Label::textColourId, Colours::black);
    m_pitchEnvVelocitySensLabel->setColour (TextEditor::textColourId, Colours::black);
    m_pitchEnvVelocitySensLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_pitchEnvVelocityTime1Slider = new MicroParameterSlider ("pitchEnvVelocityTime1Slider"));
    m_pitchEnvVelocityTime1Slider->setRange (0, 127, 1);
    m_pitchEnvVelocityTime1Slider->setSliderStyle (Slider::LinearBar);
    m_pitchEnvVelocityTime1Slider->setTextBoxStyle (Slider::TextBoxLeft, false, 40, 20);
    m_pitchEnvVelocityTime1Slider->setColour (Slider::backgroundColourId, Colour (0xfff2f59b));
    m_pitchEnvVelocityTime1Slider->setColour (Slider::thumbColourId, Colour (0xffc4c86d));
    m_pitchEnvVelocityTime1Slider->addListener (this);

    addAndMakeVisible (m_pitchEnvVelocityTime1Label = new Label ("pitchEnvVelocityTime1Label",
                                                                 "VELO SENS TIME 1"));
    m_pitchEnvVelocityTime1Label->setFont (Font (12.00f, Font::bold));
    m_pitchEnvVelocityTime1Label->setJustificationType (Justification::centred);
    m_pitchEnvVelocityTime1Label->setEditable (false, false, false);
    m_pitchEnvVelocityTime1Label->setColour (Label::textColourId, Colours::black);
    m_pitchEnvVelocityTime1Label->setColour (TextEditor::textColourId, Colours::black);
    m_pitchEnvVelocityTime1Label->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_pitchEnvVelocityTime4Slider = new MicroParameterSlider ("pitchEnvVelocityTime4Slider"));
    m_pitchEnvVelocityTime4Slider->setRange (0, 127, 1);
    m_pitchEnvVelocityTime4Slider->setSliderStyle (Slider::LinearBar);
    m_pitchEnvVelocityTime4Slider->setTextBoxStyle (Slider::TextBoxLeft, false, 40, 20);
    m_pitchEnvVelocityTime4Slider->setColour (Slider::backgroundColourId, Colour (0xfff2f59b));
    m_pitchEnvVelocityTime4Slider->setColour (Slider::thumbColourId, Colour (0xffc4c86d));
    m_pitchEnvVelocityTime4Slider->addListener (this);

    addAndMakeVisible (m_pitchEnvVelocityTime4Label = new Label ("pitchEnvVelocityTime4Label",
                                                                 "VELO SENS TIME 4"));
    m_pitchEnvVelocityTime4Label->setFont (Font (12.00f, Font::bold));
    m_pitchEnvVelocityTime4Label->setJustificationType (Justification::centred);
    m_pitchEnvVelocityTime4Label->setEditable (false, false, false);
    m_pitchEnvVelocityTime4Label->setColour (Label::textColourId, Colours::black);
    m_pitchEnvVelocityTime4Label->setColour (TextEditor::textColourId, Colours::black);
    m_pitchEnvVelocityTime4Label->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_pitchEnvTimeKeyfollow = new Label ("pitchEnvTimeKeyfollow",
                                                            "KEYFOLLOW TIME 2/3/4 "));
    m_pitchEnvTimeKeyfollow->setFont (Font (12.00f, Font::bold));
    m_pitchEnvTimeKeyfollow->setJustificationType (Justification::centred);
    m_pitchEnvTimeKeyfollow->setEditable (false, false, false);
    m_pitchEnvTimeKeyfollow->setColour (Label::textColourId, Colours::black);
    m_pitchEnvTimeKeyfollow->setColour (TextEditor::textColourId, Colours::black);
    m_pitchEnvTimeKeyfollow->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_pitchKeyfollowSlider2 = new KeyfollowMicroParameterSlider ("pitchKeyfollowSlider"));
    m_pitchKeyfollowSlider2->setRange (0, 127, 1);
    m_pitchKeyfollowSlider2->setSliderStyle (Slider::LinearBar);
    m_pitchKeyfollowSlider2->setTextBoxStyle (Slider::TextBoxLeft, false, 40, 20);
    m_pitchKeyfollowSlider2->setColour (Slider::backgroundColourId, Colour (0xfff2f59b));
    m_pitchKeyfollowSlider2->setColour (Slider::thumbColourId, Colour (0xffc4c86d));
    m_pitchKeyfollowSlider2->addListener (this);

    addAndMakeVisible (m_fineTuneSlider = new Knob ("fineTuneSlider"));
    m_fineTuneSlider->setRange (0, 127, 1);
    m_fineTuneSlider->setSliderStyle (Slider::RotaryHorizontalVerticalDrag);
    m_fineTuneSlider->setTextBoxStyle (Slider::TextBoxBelow, false, 80, 16);
    m_fineTuneSlider->setColour (Slider::textBoxBackgroundColourId, Colour (0xfff2f59b));
    m_fineTuneSlider->addListener (this);

    addAndMakeVisible (m_fineTuneLabel = new Label ("fineTuneLabel",
                                                    "FINE TUNE"));
    m_fineTuneLabel->setFont (Font (12.00f, Font::bold));
    m_fineTuneLabel->setJustificationType (Justification::centred);
    m_fineTuneLabel->setEditable (false, false, false);
    m_fineTuneLabel->setColour (Label::textColourId, Colours::black);
    m_fineTuneLabel->setColour (TextEditor::textColourId, Colours::black);
    m_fineTuneLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_lfo1PitchDepthSlider = new Knob ("lfo1PitchDepthSlider"));
    m_lfo1PitchDepthSlider->setRange (0, 127, 1);
    m_lfo1PitchDepthSlider->setSliderStyle (Slider::RotaryHorizontalVerticalDrag);
    m_lfo1PitchDepthSlider->setTextBoxStyle (Slider::TextBoxBelow, false, 80, 16);
    m_lfo1PitchDepthSlider->setColour (Slider::textBoxBackgroundColourId, Colour (0xfff2f59b));
    m_lfo1PitchDepthSlider->addListener (this);

    addAndMakeVisible (m_lfo1PitchDepthLabel = new Label ("lfo1PitchDepthLabel",
                                                          "LFO 1 DEPTH"));
    m_lfo1PitchDepthLabel->setFont (Font (12.00f, Font::bold));
    m_lfo1PitchDepthLabel->setJustificationType (Justification::centred);
    m_lfo1PitchDepthLabel->setEditable (false, false, false);
    m_lfo1PitchDepthLabel->setColour (Label::textColourId, Colours::black);
    m_lfo1PitchDepthLabel->setColour (TextEditor::textColourId, Colours::black);
    m_lfo1PitchDepthLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_lfo2PitchDepthSlider = new Knob ("lfo2PitchDepthSlider"));
    m_lfo2PitchDepthSlider->setRange (0, 127, 1);
    m_lfo2PitchDepthSlider->setSliderStyle (Slider::RotaryHorizontalVerticalDrag);
    m_lfo2PitchDepthSlider->setTextBoxStyle (Slider::TextBoxBelow, false, 80, 16);
    m_lfo2PitchDepthSlider->setColour (Slider::textBoxBackgroundColourId, Colour (0xfff2f59b));
    m_lfo2PitchDepthSlider->addListener (this);

    addAndMakeVisible (m_lfo2PitchDepthLabel = new Label ("lfo2PitchDepthLabel",
                                                          "LFO 2 DEPTH"));
    m_lfo2PitchDepthLabel->setFont (Font (12.00f, Font::bold));
    m_lfo2PitchDepthLabel->setJustificationType (Justification::centred);
    m_lfo2PitchDepthLabel->setEditable (false, false, false);
    m_lfo2PitchDepthLabel->setColour (Label::textColourId, Colours::black);
    m_lfo2PitchDepthLabel->setColour (TextEditor::textColourId, Colours::black);
    m_lfo2PitchDepthLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_lfo1AdvancedButton = new TextWithArrowButton ("lfo1AdvancedButton"));
    m_lfo1AdvancedButton->setButtonText ("LFO 1");
    m_lfo1AdvancedButton->addListener (this);

    addAndMakeVisible (m_lfo2AdvancedButton = new TextWithArrowButton ("lfo2AdvancedButton"));
    m_lfo2AdvancedButton->setButtonText ("LFO 2");
    m_lfo2AdvancedButton->addListener (this);

    addAndMakeVisible (m_pitchCmnGrp = new PanelGroupGrey ("pitchCmnGrp", "COMMON PITCH (TONES 1-4)"));
    addAndMakeVisible (m_bendDownLabel = new Label ("bendDownLabel",
                                                    "DOWN"));
    m_bendDownLabel->setFont (Font (12.00f, Font::bold));
    m_bendDownLabel->setJustificationType (Justification::centredRight);
    m_bendDownLabel->setEditable (false, false, false);
    m_bendDownLabel->setColour (Label::textColourId, Colours::black);
    m_bendDownLabel->setColour (TextEditor::textColourId, Colours::black);
    m_bendDownLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_bendDownSlider = new MicroParameterSlider ("bendDownSlider"));
    m_bendDownSlider->setRange (0, 127, 1);
    m_bendDownSlider->setSliderStyle (Slider::LinearBar);
    m_bendDownSlider->setTextBoxStyle (Slider::TextBoxLeft, false, 40, 20);
    m_bendDownSlider->setColour (Slider::backgroundColourId, Colour (0xfff2f59b));
    m_bendDownSlider->setColour (Slider::thumbColourId, Colour (0xffc4c86d));
    m_bendDownSlider->addListener (this);

    addAndMakeVisible (m_bendUpSlider = new MicroParameterSlider ("bendUpSlider"));
    m_bendUpSlider->setRange (0, 127, 1);
    m_bendUpSlider->setSliderStyle (Slider::LinearBar);
    m_bendUpSlider->setTextBoxStyle (Slider::TextBoxLeft, false, 40, 20);
    m_bendUpSlider->setColour (Slider::backgroundColourId, Colour (0xfff2f59b));
    m_bendUpSlider->setColour (Slider::thumbColourId, Colour (0xffc4c86d));
    m_bendUpSlider->addListener (this);

    addAndMakeVisible (m_bendUpLabel = new Label ("bendUpLabel",
                                                  "UP"));
    m_bendUpLabel->setFont (Font (12.00f, Font::bold));
    m_bendUpLabel->setJustificationType (Justification::centredRight);
    m_bendUpLabel->setEditable (false, false, false);
    m_bendUpLabel->setColour (Label::textColourId, Colours::black);
    m_bendUpLabel->setColour (TextEditor::textColourId, Colours::black);
    m_bendUpLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_stretchTuneDepthLabel = new Label ("stretchTuneDepthLabel",
                                                            "STRETCH\n"
                                                            "TUNE\n"
                                                            "DEPTH"));
    m_stretchTuneDepthLabel->setFont (Font (12.00f, Font::bold));
    m_stretchTuneDepthLabel->setJustificationType (Justification::centred);
    m_stretchTuneDepthLabel->setEditable (false, false, false);
    m_stretchTuneDepthLabel->setColour (Label::textColourId, Colours::black);
    m_stretchTuneDepthLabel->setColour (TextEditor::textColourId, Colours::black);
    m_stretchTuneDepthLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_stretchTuneDepthLabel2 = new Label ("stretchTuneDepthLabel",
                                                             "BEND RANGE"));
    m_stretchTuneDepthLabel2->setFont (Font (12.00f, Font::bold));
    m_stretchTuneDepthLabel2->setJustificationType (Justification::centred);
    m_stretchTuneDepthLabel2->setEditable (false, false, false);
    m_stretchTuneDepthLabel2->setColour (Label::textColourId, Colours::black);
    m_stretchTuneDepthLabel2->setColour (TextEditor::textColourId, Colours::black);
    m_stretchTuneDepthLabel2->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (imageButton5 = new ImageButton ("new button"));
    imageButton5->setButtonText (String::empty);

    imageButton5->setImages (false, true, true,
                             ImageCache::getFromMemory (pitch_png, pitch_pngSize), 1.000f, Colour (0x4340454a),
                             Image(), 1.000f, Colour (0x4340454a),
                             Image(), 1.000f, Colour (0x4340454a));
    addAndMakeVisible (m_stretchTuneDepthComboBox = new ParameterComboBox ("stretchTuneDepthComboBox"));
    m_stretchTuneDepthComboBox->setEditableText (false);
    m_stretchTuneDepthComboBox->setJustificationType (Justification::centred);
    m_stretchTuneDepthComboBox->setTextWhenNothingSelected ("OFF");
    m_stretchTuneDepthComboBox->setTextWhenNoChoicesAvailable ("(no choices)");
    m_stretchTuneDepthComboBox->addItem ("OFF", 1);
    m_stretchTuneDepthComboBox->addItem ("1", 2);
    m_stretchTuneDepthComboBox->addItem ("2", 3);
    m_stretchTuneDepthComboBox->addItem ("3", 4);
    m_stretchTuneDepthComboBox->addListener (this);


    //[UserPreSize]
    m_pitchGrp->setText("PITCH OF PART "+ String(part+1) + " TONE "+ String(((tone-4096)/512)+1));
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
					m_bendUpSlider->setParameter(patchCommon->getParameter(0x31));
					m_bendDownSlider->setParameter(patchCommon->getParameter(0x32));
				    m_stretchTuneDepthComboBox->setParameter(patchCommon->getParameter(0x42));
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
					m_coarseTuneSlider->setParameter(tone->getParameter(0x3D));
					m_fineTuneSlider->setParameter(tone->getParameter(0x3E));
					m_randomPitchDepthSlider->setParameter(tone->getParameter(0x3F));
					m_pitchKeyfollowSlider->setParameter(tone->getParameter(0x40));

					m_pitchEnvelopeDepthSlider->setParameter(tone->getParameter(0x41));
					m_pitchVelocitySensSlider->setParameter(tone->getParameter(0x42));
					m_pitchEnvVelocityTime1Slider->setParameter(tone->getParameter(0x43));
					m_pitchEnvVelocityTime4Slider->setParameter(tone->getParameter(0x44));
					m_pitchKeyfollowSlider2->setParameter(tone->getParameter(0x45));

					m_lfo1PitchDepthSlider->setParameter(tone->getParameter(0x4E));
					m_lfo2PitchDepthSlider->setParameter(tone->getParameter(0x4F));
				}
			}
		}
	}
    //[/Constructor]
}

PitchEditorAdvanced::~PitchEditorAdvanced()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
	if (m_coarseTuneSlider->getParamPtr() != nullptr)m_coarseTuneSlider->getParamPtr()->removeChangeListener(m_coarseTuneSlider);
	if (m_fineTuneSlider->getParamPtr() != nullptr)m_fineTuneSlider->getParamPtr()->removeChangeListener(m_fineTuneSlider);
	if (m_randomPitchDepthSlider->getParamPtr() != nullptr)m_randomPitchDepthSlider->getParamPtr()->removeChangeListener(m_randomPitchDepthSlider);
	if (m_pitchKeyfollowSlider->getParamPtr() != nullptr)m_pitchKeyfollowSlider->getParamPtr()->removeChangeListener(m_pitchKeyfollowSlider);
	if (m_pitchEnvelopeDepthSlider->getParamPtr() != nullptr)m_pitchEnvelopeDepthSlider->getParamPtr()->removeChangeListener(m_pitchEnvelopeDepthSlider);
	if (m_pitchVelocitySensSlider->getParamPtr() != nullptr)m_pitchVelocitySensSlider->getParamPtr()->removeChangeListener(m_pitchVelocitySensSlider);
	if (m_pitchEnvVelocityTime1Slider->getParamPtr() != nullptr)m_pitchEnvVelocityTime1Slider->getParamPtr()->removeChangeListener(m_pitchEnvVelocityTime1Slider);
	if (m_pitchEnvVelocityTime4Slider->getParamPtr() != nullptr)m_pitchEnvVelocityTime4Slider->getParamPtr()->removeChangeListener(m_pitchEnvVelocityTime4Slider);
	if (m_pitchKeyfollowSlider2->getParamPtr() != nullptr)m_pitchKeyfollowSlider2->getParamPtr()->removeChangeListener(m_pitchKeyfollowSlider2);
    //[/Destructor_pre]

    m_pitchGrp = nullptr;
    m_lfoGrp = nullptr;
    m_pitchGrp2 = nullptr;
    m_coarseTuneSlider = nullptr;
    m_coarseTuneLabel = nullptr;
    m_pitchEnv = nullptr;
    m_randomPitchDepthSlider = nullptr;
    m_randomPitchDepthLabel = nullptr;
    m_pitchKeyfollowLabel = nullptr;
    m_pitchKeyfollowSlider = nullptr;
    m_pitchEnvelopeDepthSlider = nullptr;
    m_pitchEnvelopeDepthLabel = nullptr;
    m_pitchVelocitySensSlider = nullptr;
    m_pitchEnvVelocitySensLabel = nullptr;
    m_pitchEnvVelocityTime1Slider = nullptr;
    m_pitchEnvVelocityTime1Label = nullptr;
    m_pitchEnvVelocityTime4Slider = nullptr;
    m_pitchEnvVelocityTime4Label = nullptr;
    m_pitchEnvTimeKeyfollow = nullptr;
    m_pitchKeyfollowSlider2 = nullptr;
    m_fineTuneSlider = nullptr;
    m_fineTuneLabel = nullptr;
    m_lfo1PitchDepthSlider = nullptr;
    m_lfo1PitchDepthLabel = nullptr;
    m_lfo2PitchDepthSlider = nullptr;
    m_lfo2PitchDepthLabel = nullptr;
    m_lfo1AdvancedButton = nullptr;
    m_lfo2AdvancedButton = nullptr;
    m_pitchCmnGrp = nullptr;
    m_bendDownLabel = nullptr;
    m_bendDownSlider = nullptr;
    m_bendUpSlider = nullptr;
    m_bendUpLabel = nullptr;
    m_stretchTuneDepthLabel = nullptr;
    m_stretchTuneDepthLabel2 = nullptr;
    imageButton5 = nullptr;
    m_stretchTuneDepthComboBox = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void PitchEditorAdvanced::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
	#ifdef JUCE_MSVC
	g;
	#endif
    //[/UserPrePaint]

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void PitchEditorAdvanced::resized()
{
    m_pitchGrp->setBounds (0, 0, getWidth() - 0, getHeight() - 0);
    m_lfoGrp->setBounds (0, 404, getWidth() - 0, 88);
    m_pitchGrp2->setBounds (0, 140, getWidth() - 0, 260);
    m_coarseTuneSlider->setBounds (24, 36, 48, 60);
    m_coarseTuneLabel->setBounds (4, 20, 88, 16);
    m_pitchEnv->setBounds (72, 156, 296, 156);
    m_randomPitchDepthSlider->setBounds (196, 36, 56, 16);
    m_randomPitchDepthLabel->setBounds (180, 20, 88, 16);
    m_pitchKeyfollowLabel->setBounds (272, 20, 88, 16);
    m_pitchKeyfollowSlider->setBounds (288, 36, 56, 16);
    m_pitchEnvelopeDepthSlider->setBounds (8, 168, 56, 116);
    m_pitchEnvelopeDepthLabel->setBounds (12, 156, 48, 16);
    m_pitchVelocitySensSlider->setBounds (8, 306, 56, 16);
    m_pitchEnvVelocitySensLabel->setBounds (0, 290, 72, 16);
    m_pitchEnvVelocityTime1Slider->setBounds (124, 332, 56, 16);
    m_pitchEnvVelocityTime1Label->setBounds (84, 316, 112, 16);
    m_pitchEnvVelocityTime4Slider->setBounds (300, 332, 56, 16);
    m_pitchEnvVelocityTime4Label->setBounds (264, 316, 112, 16);
    m_pitchEnvTimeKeyfollow->setBounds (184, 356, 172, 16);
    m_pitchKeyfollowSlider2->setBounds (252, 372, 56, 16);
    m_fineTuneSlider->setBounds (99, 36, 48, 60);
    m_fineTuneLabel->setBounds (79, 20, 88, 16);
    m_lfo1PitchDepthSlider->setBounds (44, 436, 32, 48);
    m_lfo1PitchDepthLabel->setBounds (24, 420, 88, 16);
    m_lfo2PitchDepthSlider->setBounds (216, 436, 32, 48);
    m_lfo2PitchDepthLabel->setBounds (196, 420, 88, 16);
    m_lfo1AdvancedButton->setBounds (96, 464, 96, 21);
    m_lfo2AdvancedButton->setBounds (268, 464, 96, 21);
    m_pitchCmnGrp->setBounds (172, 56, getWidth() - 172, 76);
    m_bendDownLabel->setBounds (256, 110, 52, 16);
    m_bendDownSlider->setBounds (312, 110, 56, 16);
    m_bendUpSlider->setBounds (312, 90, 56, 16);
    m_bendUpLabel->setBounds (256, 90, 52, 16);
    m_stretchTuneDepthLabel->setBounds (180, 73, 64, 36);
    m_stretchTuneDepthLabel2->setBounds (256, 72, 112, 16);
    imageButton5->setBounds (3, 1, 16, 16);
    m_stretchTuneDepthComboBox->setBounds (184, 110, 56, 16);
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void PitchEditorAdvanced::sliderValueChanged (Slider* sliderThatWasMoved)
{
    //[UsersliderValueChanged_Pre]
    //[/UsersliderValueChanged_Pre]

    if (sliderThatWasMoved == m_coarseTuneSlider)
    {
        //[UserSliderCode_m_coarseTuneSlider] -- add your slider handling code here..
        //[/UserSliderCode_m_coarseTuneSlider]
    }
    else if (sliderThatWasMoved == m_randomPitchDepthSlider)
    {
        //[UserSliderCode_m_randomPitchDepthSlider] -- add your slider handling code here..
        //[/UserSliderCode_m_randomPitchDepthSlider]
    }
    else if (sliderThatWasMoved == m_pitchKeyfollowSlider)
    {
        //[UserSliderCode_m_pitchKeyfollowSlider] -- add your slider handling code here..
        //[/UserSliderCode_m_pitchKeyfollowSlider]
    }
    else if (sliderThatWasMoved == m_pitchEnvelopeDepthSlider)
    {
        //[UserSliderCode_m_pitchEnvelopeDepthSlider] -- add your slider handling code here..
        //[/UserSliderCode_m_pitchEnvelopeDepthSlider]
    }
    else if (sliderThatWasMoved == m_pitchVelocitySensSlider)
    {
        //[UserSliderCode_m_pitchVelocitySensSlider] -- add your slider handling code here..
        //[/UserSliderCode_m_pitchVelocitySensSlider]
    }
    else if (sliderThatWasMoved == m_pitchEnvVelocityTime1Slider)
    {
        //[UserSliderCode_m_pitchEnvVelocityTime1Slider] -- add your slider handling code here..
        //[/UserSliderCode_m_pitchEnvVelocityTime1Slider]
    }
    else if (sliderThatWasMoved == m_pitchEnvVelocityTime4Slider)
    {
        //[UserSliderCode_m_pitchEnvVelocityTime4Slider] -- add your slider handling code here..
        //[/UserSliderCode_m_pitchEnvVelocityTime4Slider]
    }
    else if (sliderThatWasMoved == m_pitchKeyfollowSlider2)
    {
        //[UserSliderCode_m_pitchKeyfollowSlider2] -- add your slider handling code here..
        //[/UserSliderCode_m_pitchKeyfollowSlider2]
    }
    else if (sliderThatWasMoved == m_fineTuneSlider)
    {
        //[UserSliderCode_m_fineTuneSlider] -- add your slider handling code here..
        //[/UserSliderCode_m_fineTuneSlider]
    }
    else if (sliderThatWasMoved == m_lfo1PitchDepthSlider)
    {
        //[UserSliderCode_m_lfo1PitchDepthSlider] -- add your slider handling code here..
        //[/UserSliderCode_m_lfo1PitchDepthSlider]
    }
    else if (sliderThatWasMoved == m_lfo2PitchDepthSlider)
    {
        //[UserSliderCode_m_lfo2PitchDepthSlider] -- add your slider handling code here..
        //[/UserSliderCode_m_lfo2PitchDepthSlider]
    }
    else if (sliderThatWasMoved == m_bendDownSlider)
    {
        //[UserSliderCode_m_bendDownSlider] -- add your slider handling code here..
        //[/UserSliderCode_m_bendDownSlider]
    }
    else if (sliderThatWasMoved == m_bendUpSlider)
    {
        //[UserSliderCode_m_bendUpSlider] -- add your slider handling code here..
        //[/UserSliderCode_m_bendUpSlider]
    }

    //[UsersliderValueChanged_Post]
    //[/UsersliderValueChanged_Post]
}

void PitchEditorAdvanced::labelTextChanged (Label* labelThatHasChanged)
{
    //[UserlabelTextChanged_Pre]
    //[/UserlabelTextChanged_Pre]

    if (labelThatHasChanged == m_randomPitchDepthLabel)
    {
        //[UserLabelCode_m_randomPitchDepthLabel] -- add your label text handling code here..
        //[/UserLabelCode_m_randomPitchDepthLabel]
    }

    //[UserlabelTextChanged_Post]
    //[/UserlabelTextChanged_Post]
}

void PitchEditorAdvanced::buttonClicked (Button* buttonThatWasClicked)
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

    //[UserbuttonClicked_Post]
    //[/UserbuttonClicked_Post]
}

void PitchEditorAdvanced::comboBoxChanged (ComboBox* comboBoxThatHasChanged)
{
    //[UsercomboBoxChanged_Pre]
    //[/UsercomboBoxChanged_Pre]

    if (comboBoxThatHasChanged == m_stretchTuneDepthComboBox)
    {
        //[UserComboBoxCode_m_stretchTuneDepthComboBox] -- add your combo box handling code here..
        //[/UserComboBoxCode_m_stretchTuneDepthComboBox]
    }

    //[UsercomboBoxChanged_Post]
    //[/UsercomboBoxChanged_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Introjucer information section --

    This is where the Introjucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="PitchEditorAdvanced" componentName=""
                 parentClasses="public Component" constructorParams="const String &amp;componentName, SynthParts part, Tone tone"
                 variableInitialisers="Component (componentName), m_part(part), m_tone(tone)"
                 snapPixels="4" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="1" initialWidth="376" initialHeight="492">
  <BACKGROUND backgroundColour="0"/>
  <JUCERCOMP name="pitchGrp" id="52e00682f746b888" memberName="m_pitchGrp"
             virtualName="PanelGroupGrey" explicitFocusOrder="0" pos="0 0 0M 0M"
             sourceFile="../GroupWidgets/PanelGroupTransp.cpp" constructorParams="&quot;pitchGrp&quot;, getName() "/>
  <JUCERCOMP name="lfoGrp" id="5d2169b0330e13c6" memberName="m_lfoGrp" virtualName="PanelGroupGrey"
             explicitFocusOrder="0" pos="0 404 0M 88" sourceFile="../GroupWidgets/PanelGroupTransp.cpp"
             constructorParams="&quot;lfoGrp&quot;, &quot;LFO MODULATION&quot;"/>
  <JUCERCOMP name="pitchGrp" id="f94b4c6bc1e7a151" memberName="m_pitchGrp2"
             virtualName="PanelGroupGrey" explicitFocusOrder="0" pos="0 140 0M 260"
             sourceFile="../GroupWidgets/PanelGroupTransp.cpp" constructorParams="&quot;pitchEnvGrp&quot;, getName().toUpperCase()+&quot; ENVELOPE&quot;"/>
  <SLIDER name="coarseTuneSlider" id="533842793459863a" memberName="m_coarseTuneSlider"
          virtualName="Knob" explicitFocusOrder="0" pos="24 36 48 60" textboxbkgd="fff2f59b"
          min="0" max="127" int="1" style="RotaryHorizontalVerticalDrag"
          textBoxPos="TextBoxBelow" textBoxEditable="1" textBoxWidth="80"
          textBoxHeight="16" skewFactor="1"/>
  <LABEL name="coarseTuneLabel" id="b464bd3cbdae27fd" memberName="m_coarseTuneLabel"
         virtualName="" explicitFocusOrder="0" pos="4 20 88 16" textCol="ff000000"
         edTextCol="ff000000" edBkgCol="0" labelText="COARSE" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="12" bold="1" italic="0" justification="36"/>
  <JUCERCOMP name="pitchEnv" id="99a40d72d7ad1e22" memberName="m_pitchEnv"
             virtualName="" explicitFocusOrder="0" pos="72 156 296 156" sourceFile="Envelope.cpp"
             constructorParams="m_part, m_tone, EnvelopeTypes::Pitch, false"/>
  <SLIDER name="randomPitchDepthLabel" id="579dec6fe706db7d" memberName="m_randomPitchDepthSlider"
          virtualName="MicroParameterSlider" explicitFocusOrder="0" pos="196 36 56 16"
          bkgcol="fff2f59b" thumbcol="ffc4c86d" min="0" max="127" int="1"
          style="LinearBar" textBoxPos="TextBoxLeft" textBoxEditable="1"
          textBoxWidth="40" textBoxHeight="20" skewFactor="1"/>
  <LABEL name="randomPitchDepthLabel" id="cd360160053c8317" memberName="m_randomPitchDepthLabel"
         virtualName="" explicitFocusOrder="0" pos="180 20 88 16" textCol="ff000000"
         edTextCol="ff000000" edBkgCol="0" labelText="RANDOMNESS" editableSingleClick="1"
         editableDoubleClick="1" focusDiscardsChanges="0" fontname="Default font"
         fontsize="12" bold="1" italic="0" justification="36"/>
  <LABEL name="pitchKeyfollowLabel" id="3a52299341c28960" memberName="m_pitchKeyfollowLabel"
         virtualName="" explicitFocusOrder="0" pos="272 20 88 16" textCol="ff000000"
         edTextCol="ff000000" edBkgCol="0" labelText="KEYFOLLOW" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="12" bold="1" italic="0" justification="36"/>
  <SLIDER name="pitchKeyfollowSlider" id="70b45a3a21f5522" memberName="m_pitchKeyfollowSlider"
          virtualName="KeyfollowMicroParameterSlider" explicitFocusOrder="0"
          pos="288 36 56 16" bkgcol="fff2f59b" thumbcol="ffc4c86d" min="0"
          max="127" int="1" style="LinearBar" textBoxPos="TextBoxLeft"
          textBoxEditable="1" textBoxWidth="40" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="pitchEnvelopeDepthSlider" id="b0bd5a61181f569c" memberName="m_pitchEnvelopeDepthSlider"
          virtualName="ParameterEnvelopeSlider" explicitFocusOrder="0"
          pos="8 168 56 116" bkgcol="f2f59b" textboxbkgd="fff2f59b" min="0"
          max="127" int="1" style="LinearVertical" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="56" textBoxHeight="16" skewFactor="1"/>
  <LABEL name="pitchEnvelopeDepthLabel" id="611da7e96f52143f" memberName="m_pitchEnvelopeDepthLabel"
         virtualName="" explicitFocusOrder="0" pos="12 156 48 16" textCol="ff000000"
         edTextCol="ff000000" edBkgCol="0" labelText="DEPTH" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="12" bold="1" italic="0" justification="36"/>
  <SLIDER name="pitchVelocitySensSlider" id="ce3036a9c9d2d09a" memberName="m_pitchVelocitySensSlider"
          virtualName="MicroParameterSlider" explicitFocusOrder="0" pos="8 306 56 16"
          bkgcol="fff2f59b" thumbcol="ffc4c86d" min="0" max="127" int="1"
          style="LinearBar" textBoxPos="TextBoxLeft" textBoxEditable="1"
          textBoxWidth="40" textBoxHeight="20" skewFactor="1"/>
  <LABEL name="pitchEnvVelocitySensLabel" id="da6b2f045679c497" memberName="m_pitchEnvVelocitySensLabel"
         virtualName="" explicitFocusOrder="0" pos="0 290 72 16" textCol="ff000000"
         edTextCol="ff000000" edBkgCol="0" labelText="VELO SENS" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="12" bold="1" italic="0" justification="36"/>
  <SLIDER name="pitchEnvVelocityTime1Slider" id="26e8b1e9ec956faf" memberName="m_pitchEnvVelocityTime1Slider"
          virtualName="MicroParameterSlider" explicitFocusOrder="0" pos="124 332 56 16"
          bkgcol="fff2f59b" thumbcol="ffc4c86d" min="0" max="127" int="1"
          style="LinearBar" textBoxPos="TextBoxLeft" textBoxEditable="1"
          textBoxWidth="40" textBoxHeight="20" skewFactor="1"/>
  <LABEL name="pitchEnvVelocityTime1Label" id="fcf555c7750e1905" memberName="m_pitchEnvVelocityTime1Label"
         virtualName="" explicitFocusOrder="0" pos="84 316 112 16" textCol="ff000000"
         edTextCol="ff000000" edBkgCol="0" labelText="VELO SENS TIME 1"
         editableSingleClick="0" editableDoubleClick="0" focusDiscardsChanges="0"
         fontname="Default font" fontsize="12" bold="1" italic="0" justification="36"/>
  <SLIDER name="pitchEnvVelocityTime4Slider" id="96d5b92b9bc16388" memberName="m_pitchEnvVelocityTime4Slider"
          virtualName="MicroParameterSlider" explicitFocusOrder="0" pos="300 332 56 16"
          bkgcol="fff2f59b" thumbcol="ffc4c86d" min="0" max="127" int="1"
          style="LinearBar" textBoxPos="TextBoxLeft" textBoxEditable="1"
          textBoxWidth="40" textBoxHeight="20" skewFactor="1"/>
  <LABEL name="pitchEnvVelocityTime4Label" id="d741df9cfd6aac2d" memberName="m_pitchEnvVelocityTime4Label"
         virtualName="" explicitFocusOrder="0" pos="264 316 112 16" textCol="ff000000"
         edTextCol="ff000000" edBkgCol="0" labelText="VELO SENS TIME 4"
         editableSingleClick="0" editableDoubleClick="0" focusDiscardsChanges="0"
         fontname="Default font" fontsize="12" bold="1" italic="0" justification="36"/>
  <LABEL name="pitchEnvTimeKeyfollow" id="cf887a8299fda426" memberName="m_pitchEnvTimeKeyfollow"
         virtualName="" explicitFocusOrder="0" pos="184 356 172 16" textCol="ff000000"
         edTextCol="ff000000" edBkgCol="0" labelText="KEYFOLLOW TIME 2/3/4 "
         editableSingleClick="0" editableDoubleClick="0" focusDiscardsChanges="0"
         fontname="Default font" fontsize="12" bold="1" italic="0" justification="36"/>
  <SLIDER name="pitchKeyfollowSlider" id="fd7fba1a74d4d802" memberName="m_pitchKeyfollowSlider2"
          virtualName="KeyfollowMicroParameterSlider" explicitFocusOrder="0"
          pos="252 372 56 16" bkgcol="fff2f59b" thumbcol="ffc4c86d" min="0"
          max="127" int="1" style="LinearBar" textBoxPos="TextBoxLeft"
          textBoxEditable="1" textBoxWidth="40" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="fineTuneSlider" id="323e25f12b9bcb4d" memberName="m_fineTuneSlider"
          virtualName="Knob" explicitFocusOrder="0" pos="99 36 48 60" textboxbkgd="fff2f59b"
          min="0" max="127" int="1" style="RotaryHorizontalVerticalDrag"
          textBoxPos="TextBoxBelow" textBoxEditable="1" textBoxWidth="80"
          textBoxHeight="16" skewFactor="1"/>
  <LABEL name="fineTuneLabel" id="4a6481529e07d2e7" memberName="m_fineTuneLabel"
         virtualName="" explicitFocusOrder="0" pos="79 20 88 16" textCol="ff000000"
         edTextCol="ff000000" edBkgCol="0" labelText="FINE TUNE" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="12" bold="1" italic="0" justification="36"/>
  <SLIDER name="lfo1PitchDepthSlider" id="5139dffd40f5b193" memberName="m_lfo1PitchDepthSlider"
          virtualName="Knob" explicitFocusOrder="0" pos="44 436 32 48"
          textboxbkgd="fff2f59b" min="0" max="127" int="1" style="RotaryHorizontalVerticalDrag"
          textBoxPos="TextBoxBelow" textBoxEditable="1" textBoxWidth="80"
          textBoxHeight="16" skewFactor="1"/>
  <LABEL name="lfo1PitchDepthLabel" id="ddaad26232bd3db3" memberName="m_lfo1PitchDepthLabel"
         virtualName="" explicitFocusOrder="0" pos="24 420 88 16" textCol="ff000000"
         edTextCol="ff000000" edBkgCol="0" labelText="LFO 1 DEPTH" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="12" bold="1" italic="0" justification="36"/>
  <SLIDER name="lfo2PitchDepthSlider" id="37bb334dae2c4ad2" memberName="m_lfo2PitchDepthSlider"
          virtualName="Knob" explicitFocusOrder="0" pos="216 436 32 48"
          textboxbkgd="fff2f59b" min="0" max="127" int="1" style="RotaryHorizontalVerticalDrag"
          textBoxPos="TextBoxBelow" textBoxEditable="1" textBoxWidth="80"
          textBoxHeight="16" skewFactor="1"/>
  <LABEL name="lfo2PitchDepthLabel" id="20feaad1dd36b9a5" memberName="m_lfo2PitchDepthLabel"
         virtualName="" explicitFocusOrder="0" pos="196 420 88 16" textCol="ff000000"
         edTextCol="ff000000" edBkgCol="0" labelText="LFO 2 DEPTH" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="12" bold="1" italic="0" justification="36"/>
  <TEXTBUTTON name="lfo1AdvancedButton" id="9de90d61ee7dcce4" memberName="m_lfo1AdvancedButton"
              virtualName="TextWithArrowButton" explicitFocusOrder="0" pos="96 464 96 21"
              buttonText="LFO 1" connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="lfo2AdvancedButton" id="596fa9d632d5c1d1" memberName="m_lfo2AdvancedButton"
              virtualName="TextWithArrowButton" explicitFocusOrder="0" pos="268 464 96 21"
              buttonText="LFO 2" connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <JUCERCOMP name="pitchCmnGrp" id="3cc1808e6723d195" memberName="m_pitchCmnGrp"
             virtualName="PanelGroupGrey" explicitFocusOrder="0" pos="172 56 172M 76"
             sourceFile="../GroupWidgets/PanelGroupTransp.cpp" constructorParams="&quot;pitchCmnGrp&quot;, &quot;COMMON PITCH (TONES 1-4)&quot;"/>
  <LABEL name="bendDownLabel" id="c25b4b466360573c" memberName="m_bendDownLabel"
         virtualName="" explicitFocusOrder="0" pos="256 110 52 16" textCol="ff000000"
         edTextCol="ff000000" edBkgCol="0" labelText="DOWN" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="12" bold="1" italic="0" justification="34"/>
  <SLIDER name="bendDownSlider" id="2e2bb5b326d78063" memberName="m_bendDownSlider"
          virtualName="MicroParameterSlider" explicitFocusOrder="0" pos="312 110 56 16"
          bkgcol="fff2f59b" thumbcol="ffc4c86d" min="0" max="127" int="1"
          style="LinearBar" textBoxPos="TextBoxLeft" textBoxEditable="1"
          textBoxWidth="40" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="bendUpSlider" id="c55451f652b9879b" memberName="m_bendUpSlider"
          virtualName="MicroParameterSlider" explicitFocusOrder="0" pos="312 90 56 16"
          bkgcol="fff2f59b" thumbcol="ffc4c86d" min="0" max="127" int="1"
          style="LinearBar" textBoxPos="TextBoxLeft" textBoxEditable="1"
          textBoxWidth="40" textBoxHeight="20" skewFactor="1"/>
  <LABEL name="bendUpLabel" id="8e13461a1fae68" memberName="m_bendUpLabel"
         virtualName="" explicitFocusOrder="0" pos="256 90 52 16" textCol="ff000000"
         edTextCol="ff000000" edBkgCol="0" labelText="UP" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="12" bold="1" italic="0" justification="34"/>
  <LABEL name="stretchTuneDepthLabel" id="55d3e07f135088b0" memberName="m_stretchTuneDepthLabel"
         virtualName="" explicitFocusOrder="0" pos="180 73 64 36" textCol="ff000000"
         edTextCol="ff000000" edBkgCol="0" labelText="STRETCH&#10;TUNE&#10;DEPTH"
         editableSingleClick="0" editableDoubleClick="0" focusDiscardsChanges="0"
         fontname="Default font" fontsize="12" bold="1" italic="0" justification="36"/>
  <LABEL name="stretchTuneDepthLabel" id="492759f4bd90a4a3" memberName="m_stretchTuneDepthLabel2"
         virtualName="" explicitFocusOrder="0" pos="256 72 112 16" textCol="ff000000"
         edTextCol="ff000000" edBkgCol="0" labelText="BEND RANGE" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="12" bold="1" italic="0" justification="36"/>
  <IMAGEBUTTON name="new button" id="547857ffe69caa20" memberName="imageButton5"
               virtualName="" explicitFocusOrder="0" pos="3 1 16 16" buttonText=""
               connectedEdges="0" needsCallback="0" radioGroupId="0" keepProportions="1"
               resourceNormal="pitch_png" opacityNormal="1" colourNormal="4340454a"
               resourceOver="" opacityOver="1" colourOver="4340454a" resourceDown=""
               opacityDown="1" colourDown="4340454a"/>
  <COMBOBOX name="stretchTuneDepthComboBox" id="e8c10ecedfc6fd9e" memberName="m_stretchTuneDepthComboBox"
            virtualName="ParameterComboBox" explicitFocusOrder="0" pos="184 110 56 16"
            editable="0" layout="36" items="OFF&#10;1&#10;2&#10;3" textWhenNonSelected="OFF"
            textWhenNoItems="(no choices)"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif

//==============================================================================
// Binary resources - be careful not to edit any of these sections!

// JUCER_RESOURCE: pitch_png, 225, "../../../Resources/PatchEditSectionIcons/pitch.png"
static const unsigned char resource_PitchEditorAdvanced_pitch_png[] = { 137,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,0,16,0,0,0,16,8,6,0,0,0,31,243,255,97,0,0,0,1,115,82,71,66,0,174,206,28,233,0,
0,0,6,98,75,71,68,0,255,0,255,0,255,160,189,167,147,0,0,0,9,112,72,89,115,0,0,11,19,0,0,11,19,1,0,154,156,24,0,0,0,7,116,73,77,69,7,222,12,10,20,19,38,230,96,21,89,0,0,0,97,73,68,65,84,56,203,165,147,
75,14,0,33,8,67,41,153,251,95,185,110,152,68,141,40,159,110,205,171,80,0,98,34,73,73,8,0,164,10,47,204,11,166,201,123,211,23,188,148,122,144,70,74,189,153,104,42,172,140,65,52,88,173,246,238,26,236,240,
109,10,161,22,96,242,76,180,26,222,175,239,4,206,191,205,149,164,211,142,108,105,123,140,237,99,66,247,156,7,144,160,99,229,152,124,254,63,0,0,0,0,73,69,78,68,174,66,96,130,0,0};

const char* PitchEditorAdvanced::pitch_png = (const char*) resource_PitchEditorAdvanced_pitch_png;
const int PitchEditorAdvanced::pitch_pngSize = 225;


//[EndFile] You can add extra defines here...
//[/EndFile]
