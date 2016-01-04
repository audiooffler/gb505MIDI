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

#include "FilterEditorAdvanced.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
extern OverallMemoryBlock* grooveboxMemory;
//[/MiscUserDefs]

//==============================================================================
FilterEditorAdvanced::FilterEditorAdvanced (const String &componentName, SynthParts part, Tone tone)
    : Component (componentName), m_part(part), m_tone(tone)
{
    addAndMakeVisible (m_filterGrp = new PanelGroupGrey ("filterGrp", getName()));
    addAndMakeVisible (m_filterGrp2 = new PanelGroupGrey ("filterEnvGrp", getName().toUpperCase()+" ENVELOPE"));
    addAndMakeVisible (m_cutoffSlider = new Knob ("cutoffSlider"));
    m_cutoffSlider->setRange (0, 127, 1);
    m_cutoffSlider->setSliderStyle (Slider::RotaryHorizontalVerticalDrag);
    m_cutoffSlider->setTextBoxStyle (Slider::TextBoxBelow, false, 80, 16);
    m_cutoffSlider->setColour (Slider::textBoxBackgroundColourId, Colour (0xfff2f59b));
    m_cutoffSlider->addListener (this);

    addAndMakeVisible (m_cutoffLabel = new Label ("cutoffLabel",
                                                  "CUTOFF"));
    m_cutoffLabel->setFont (Font (12.00f, Font::bold));
    m_cutoffLabel->setJustificationType (Justification::centred);
    m_cutoffLabel->setEditable (false, false, false);
    m_cutoffLabel->setColour (Label::textColourId, Colours::black);
    m_cutoffLabel->setColour (TextEditor::textColourId, Colours::black);
    m_cutoffLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_filterEnv = new Envelope (m_part, m_tone, EnvelopeTypes::Filter, false));
    addAndMakeVisible (m_cutoffKeyfollowLabel = new Label ("cutoffKeyfollowLabel",
                                                           "KEYFOLLOW"));
    m_cutoffKeyfollowLabel->setFont (Font (12.00f, Font::bold));
    m_cutoffKeyfollowLabel->setJustificationType (Justification::centred);
    m_cutoffKeyfollowLabel->setEditable (false, false, false);
    m_cutoffKeyfollowLabel->setColour (Label::textColourId, Colours::black);
    m_cutoffKeyfollowLabel->setColour (TextEditor::textColourId, Colours::black);
    m_cutoffKeyfollowLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_cutoffKeyfollowSlider = new KeyfollowMicroParameterSlider ("cutoffKeyfollowSlider"));
    m_cutoffKeyfollowSlider->setRange (0, 127, 1);
    m_cutoffKeyfollowSlider->setSliderStyle (Slider::LinearBar);
    m_cutoffKeyfollowSlider->setTextBoxStyle (Slider::TextBoxLeft, false, 40, 20);
    m_cutoffKeyfollowSlider->setColour (Slider::backgroundColourId, Colour (0xfff2f59b));
    m_cutoffKeyfollowSlider->setColour (Slider::thumbColourId, Colour (0xffc4c86d));
    m_cutoffKeyfollowSlider->addListener (this);

    addAndMakeVisible (m_filterEnvelopeDepthSlider = new ParameterEnvelopeSlider ("filterEnvelopeDepthSlider"));
    m_filterEnvelopeDepthSlider->setRange (0, 127, 1);
    m_filterEnvelopeDepthSlider->setSliderStyle (Slider::LinearVertical);
    m_filterEnvelopeDepthSlider->setTextBoxStyle (Slider::TextBoxBelow, false, 56, 16);
    m_filterEnvelopeDepthSlider->setColour (Slider::backgroundColourId, Colour (0x00f2f59b));
    m_filterEnvelopeDepthSlider->setColour (Slider::textBoxBackgroundColourId, Colour (0xfff2f59b));
    m_filterEnvelopeDepthSlider->addListener (this);

    addAndMakeVisible (m_filterEnvelopeDepthLabel = new Label ("filterEnvelopeDepthLabel",
                                                               "DEPTH"));
    m_filterEnvelopeDepthLabel->setFont (Font (12.00f, Font::bold));
    m_filterEnvelopeDepthLabel->setJustificationType (Justification::centred);
    m_filterEnvelopeDepthLabel->setEditable (false, false, false);
    m_filterEnvelopeDepthLabel->setColour (Label::textColourId, Colours::black);
    m_filterEnvelopeDepthLabel->setColour (TextEditor::textColourId, Colours::black);
    m_filterEnvelopeDepthLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_filterVelocitySensSlider = new MicroParameterSlider ("filterVelocitySensSlider"));
    m_filterVelocitySensSlider->setRange (0, 127, 1);
    m_filterVelocitySensSlider->setSliderStyle (Slider::LinearBar);
    m_filterVelocitySensSlider->setTextBoxStyle (Slider::TextBoxLeft, false, 40, 20);
    m_filterVelocitySensSlider->setColour (Slider::backgroundColourId, Colour (0xfff2f59b));
    m_filterVelocitySensSlider->setColour (Slider::thumbColourId, Colour (0xffc4c86d));
    m_filterVelocitySensSlider->addListener (this);

    addAndMakeVisible (m_filterEnvVelocitySensLabel = new Label ("filterEnvVelocitySensLabel",
                                                                 "VELO SENS"));
    m_filterEnvVelocitySensLabel->setFont (Font (12.00f, Font::bold));
    m_filterEnvVelocitySensLabel->setJustificationType (Justification::centred);
    m_filterEnvVelocitySensLabel->setEditable (false, false, false);
    m_filterEnvVelocitySensLabel->setColour (Label::textColourId, Colours::black);
    m_filterEnvVelocitySensLabel->setColour (TextEditor::textColourId, Colours::black);
    m_filterEnvVelocitySensLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_filterEnvVelocityTime1Slider = new MicroParameterSlider ("filterEnvVelocityTime1Slider"));
    m_filterEnvVelocityTime1Slider->setRange (0, 127, 1);
    m_filterEnvVelocityTime1Slider->setSliderStyle (Slider::LinearBar);
    m_filterEnvVelocityTime1Slider->setTextBoxStyle (Slider::TextBoxLeft, false, 40, 20);
    m_filterEnvVelocityTime1Slider->setColour (Slider::backgroundColourId, Colour (0xfff2f59b));
    m_filterEnvVelocityTime1Slider->setColour (Slider::thumbColourId, Colour (0xffc4c86d));
    m_filterEnvVelocityTime1Slider->addListener (this);

    addAndMakeVisible (m_filterEnvVelocityTime1Label = new Label ("filterEnvVelocityTime1Label",
                                                                  "VELO SENS TIME 1"));
    m_filterEnvVelocityTime1Label->setFont (Font (12.00f, Font::bold));
    m_filterEnvVelocityTime1Label->setJustificationType (Justification::centred);
    m_filterEnvVelocityTime1Label->setEditable (false, false, false);
    m_filterEnvVelocityTime1Label->setColour (Label::textColourId, Colours::black);
    m_filterEnvVelocityTime1Label->setColour (TextEditor::textColourId, Colours::black);
    m_filterEnvVelocityTime1Label->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_filterEnvVelocityTime4Slider = new MicroParameterSlider ("filterEnvVelocityTime4Slider"));
    m_filterEnvVelocityTime4Slider->setRange (0, 127, 1);
    m_filterEnvVelocityTime4Slider->setSliderStyle (Slider::LinearBar);
    m_filterEnvVelocityTime4Slider->setTextBoxStyle (Slider::TextBoxLeft, false, 40, 20);
    m_filterEnvVelocityTime4Slider->setColour (Slider::backgroundColourId, Colour (0xfff2f59b));
    m_filterEnvVelocityTime4Slider->setColour (Slider::thumbColourId, Colour (0xffc4c86d));
    m_filterEnvVelocityTime4Slider->addListener (this);

    addAndMakeVisible (m_filterEnvVelocityTime4Label = new Label ("filterEnvVelocityTime4Label",
                                                                  "VELO SENS TIME 4"));
    m_filterEnvVelocityTime4Label->setFont (Font (12.00f, Font::bold));
    m_filterEnvVelocityTime4Label->setJustificationType (Justification::centred);
    m_filterEnvVelocityTime4Label->setEditable (false, false, false);
    m_filterEnvVelocityTime4Label->setColour (Label::textColourId, Colours::black);
    m_filterEnvVelocityTime4Label->setColour (TextEditor::textColourId, Colours::black);
    m_filterEnvVelocityTime4Label->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_filterEnvTimeKeyfollow = new Label ("filterEnvTimeKeyfollow",
                                                             "KEYFOLLOW TIME 2/3/4 "));
    m_filterEnvTimeKeyfollow->setFont (Font (12.00f, Font::bold));
    m_filterEnvTimeKeyfollow->setJustificationType (Justification::centred);
    m_filterEnvTimeKeyfollow->setEditable (false, false, false);
    m_filterEnvTimeKeyfollow->setColour (Label::textColourId, Colours::black);
    m_filterEnvTimeKeyfollow->setColour (TextEditor::textColourId, Colours::black);
    m_filterEnvTimeKeyfollow->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_filterKeyfollowSlider = new KeyfollowMicroParameterSlider ("filterKeyfollowSlider"));
    m_filterKeyfollowSlider->setRange (0, 127, 1);
    m_filterKeyfollowSlider->setSliderStyle (Slider::LinearBar);
    m_filterKeyfollowSlider->setTextBoxStyle (Slider::TextBoxLeft, false, 40, 20);
    m_filterKeyfollowSlider->setColour (Slider::backgroundColourId, Colour (0xfff2f59b));
    m_filterKeyfollowSlider->setColour (Slider::thumbColourId, Colour (0xffc4c86d));
    m_filterKeyfollowSlider->addListener (this);

    addAndMakeVisible (m_resonanceSlider = new Knob ("resonanceSlider"));
    m_resonanceSlider->setRange (0, 127, 1);
    m_resonanceSlider->setSliderStyle (Slider::RotaryHorizontalVerticalDrag);
    m_resonanceSlider->setTextBoxStyle (Slider::TextBoxBelow, false, 80, 16);
    m_resonanceSlider->setColour (Slider::textBoxBackgroundColourId, Colour (0xfff2f59b));
    m_resonanceSlider->addListener (this);

    addAndMakeVisible (m_resonanceLabel = new Label ("resonanceLabel",
                                                     "RESONANCE"));
    m_resonanceLabel->setFont (Font (12.00f, Font::bold));
    m_resonanceLabel->setJustificationType (Justification::centred);
    m_resonanceLabel->setEditable (false, false, false);
    m_resonanceLabel->setColour (Label::textColourId, Colours::black);
    m_resonanceLabel->setColour (TextEditor::textColourId, Colours::black);
    m_resonanceLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_filterEnvVelCurveComboBox = new ParameterComboBox ("filterEnvVelCurveComboBox"));
    m_filterEnvVelCurveComboBox->setEditableText (false);
    m_filterEnvVelCurveComboBox->setJustificationType (Justification::centred);
    m_filterEnvVelCurveComboBox->setTextWhenNothingSelected ("Normal");
    m_filterEnvVelCurveComboBox->setTextWhenNoChoicesAvailable ("(no choices)");
    m_filterEnvVelCurveComboBox->addListener (this);

    addAndMakeVisible (m_filterEnvVelCurveDisplay = new ParameterVelCurveDisplay ("filterEnvVelCurveDisplay"));
    m_filterEnvVelCurveDisplay->setRange (0, 10, 0);
    m_filterEnvVelCurveDisplay->setSliderStyle (Slider::RotaryHorizontalVerticalDrag);
    m_filterEnvVelCurveDisplay->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    m_filterEnvVelCurveDisplay->addListener (this);

    addAndMakeVisible (m_resonanceVelocitySensLabel = new Label ("resonanceVelocitySensLabel",
                                                                 "VELOCITY SENS"));
    m_resonanceVelocitySensLabel->setFont (Font (12.00f, Font::bold));
    m_resonanceVelocitySensLabel->setJustificationType (Justification::centred);
    m_resonanceVelocitySensLabel->setEditable (false, false, false);
    m_resonanceVelocitySensLabel->setColour (Label::textColourId, Colours::black);
    m_resonanceVelocitySensLabel->setColour (TextEditor::textColourId, Colours::black);
    m_resonanceVelocitySensLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_resonanceVelocitySensSlider = new MicroParameterSlider ("resonanceVelocitySensSlider"));
    m_resonanceVelocitySensSlider->setRange (0, 127, 1);
    m_resonanceVelocitySensSlider->setSliderStyle (Slider::LinearBar);
    m_resonanceVelocitySensSlider->setTextBoxStyle (Slider::TextBoxLeft, false, 40, 20);
    m_resonanceVelocitySensSlider->setColour (Slider::backgroundColourId, Colour (0xfff2f59b));
    m_resonanceVelocitySensSlider->setColour (Slider::thumbColourId, Colour (0xffc4c86d));
    m_resonanceVelocitySensSlider->addListener (this);

    addAndMakeVisible (m_filterTypeLabel = new Label ("filterTypeLabel",
                                                      "FILTER TYPE"));
    m_filterTypeLabel->setFont (Font (12.00f, Font::bold));
    m_filterTypeLabel->setJustificationType (Justification::centred);
    m_filterTypeLabel->setEditable (false, false, false);
    m_filterTypeLabel->setColour (Label::textColourId, Colours::black);
    m_filterTypeLabel->setColour (TextEditor::textColourId, Colours::black);
    m_filterTypeLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_filterTypeComboBox = new ParameterComboBox ("filterTypeComboBox"));
    m_filterTypeComboBox->setEditableText (false);
    m_filterTypeComboBox->setJustificationType (Justification::centred);
    m_filterTypeComboBox->setTextWhenNothingSelected (String::empty);
    m_filterTypeComboBox->setTextWhenNoChoicesAvailable ("(no choices)");
    m_filterTypeComboBox->addListener (this);

    addAndMakeVisible (m_filterEnvVelocityCurveLabel = new Label ("filterEnvVelocityCurveLabel",
                                                                  "VELO CURVE"));
    m_filterEnvVelocityCurveLabel->setFont (Font (12.00f, Font::bold));
    m_filterEnvVelocityCurveLabel->setJustificationType (Justification::centred);
    m_filterEnvVelocityCurveLabel->setEditable (false, false, false);
    m_filterEnvVelocityCurveLabel->setColour (Label::textColourId, Colours::black);
    m_filterEnvVelocityCurveLabel->setColour (TextEditor::textColourId, Colours::black);
    m_filterEnvVelocityCurveLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_lfoGrp = new PanelGroupGrey ("lfoGrp", "LFO MODULATION"));
    addAndMakeVisible (m_lfo1FilterDepthSlider = new Knob ("lfo1FilterDepthSlider"));
    m_lfo1FilterDepthSlider->setRange (0, 127, 1);
    m_lfo1FilterDepthSlider->setSliderStyle (Slider::RotaryHorizontalVerticalDrag);
    m_lfo1FilterDepthSlider->setTextBoxStyle (Slider::TextBoxBelow, false, 80, 16);
    m_lfo1FilterDepthSlider->setColour (Slider::textBoxBackgroundColourId, Colour (0xfff2f59b));
    m_lfo1FilterDepthSlider->addListener (this);

    addAndMakeVisible (m_lfo1FilterDepthLabel = new Label ("lfo1FilterDepthLabel",
                                                           "LFO 1 DEPTH"));
    m_lfo1FilterDepthLabel->setFont (Font (12.00f, Font::bold));
    m_lfo1FilterDepthLabel->setJustificationType (Justification::centred);
    m_lfo1FilterDepthLabel->setEditable (false, false, false);
    m_lfo1FilterDepthLabel->setColour (Label::textColourId, Colours::black);
    m_lfo1FilterDepthLabel->setColour (TextEditor::textColourId, Colours::black);
    m_lfo1FilterDepthLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_lfo2FilterDepthSlider = new Knob ("lfo2FilterDepthSlider"));
    m_lfo2FilterDepthSlider->setRange (0, 127, 1);
    m_lfo2FilterDepthSlider->setSliderStyle (Slider::RotaryHorizontalVerticalDrag);
    m_lfo2FilterDepthSlider->setTextBoxStyle (Slider::TextBoxBelow, false, 80, 16);
    m_lfo2FilterDepthSlider->setColour (Slider::textBoxBackgroundColourId, Colour (0xfff2f59b));
    m_lfo2FilterDepthSlider->addListener (this);

    addAndMakeVisible (m_lfo2FilterDepthLabel = new Label ("lfo2FilterDepthLabel",
                                                           "LFO 2 DEPTH"));
    m_lfo2FilterDepthLabel->setFont (Font (12.00f, Font::bold));
    m_lfo2FilterDepthLabel->setJustificationType (Justification::centred);
    m_lfo2FilterDepthLabel->setEditable (false, false, false);
    m_lfo2FilterDepthLabel->setColour (Label::textColourId, Colours::black);
    m_lfo2FilterDepthLabel->setColour (TextEditor::textColourId, Colours::black);
    m_lfo2FilterDepthLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_lfo1AdvancedButton = new TextWithArrowButton ("lfo1AdvancedButton"));
    m_lfo1AdvancedButton->setButtonText ("LFO 1");
    m_lfo1AdvancedButton->addListener (this);

    addAndMakeVisible (m_lfo2AdvancedButton = new TextWithArrowButton ("lfo2AdvancedButton"));
    m_lfo2AdvancedButton->setButtonText ("LFO 2");
    m_lfo2AdvancedButton->addListener (this);

    addAndMakeVisible (m_imageButton = new ImageButton ("imageButton"));
    m_imageButton->setButtonText (String::empty);

    m_imageButton->setImages (false, true, true,
                              ImageCache::getFromMemory (filter_png, filter_pngSize), 1.000f, Colour (0x4340454a),
                              Image(), 1.000f, Colour (0x4340454a),
                              Image(), 1.000f, Colour (0x4340454a));

    //[UserPreSize]
    m_filterGrp->setText("FILTER OF PART "+ String(part+1) + " TONE "+ String(((tone-4096)/512)+1));
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
					m_filterTypeComboBox->setParameter(tone->getParameter(0x50));
					m_cutoffSlider->setParameter(tone->getParameter(0x51));
					m_cutoffKeyfollowSlider->setParameter(tone->getParameter(0x52));
					m_resonanceSlider->setParameter(tone->getParameter(0x53));
					m_resonanceVelocitySensSlider->setParameter(tone->getParameter(0x54));
					m_filterEnvelopeDepthSlider->setParameter(tone->getParameter(0x55));
					m_filterEnvVelCurveComboBox->setParameter(tone->getParameter(0x56));
					m_filterEnvVelCurveDisplay->setParameter(tone->getParameter(0x56));
					m_filterVelocitySensSlider->setParameter(tone->getParameter(0x57));
					m_filterEnvVelocityTime1Slider->setParameter(tone->getParameter(0x58));
					m_filterEnvVelocityTime4Slider->setParameter(tone->getParameter(0x59));
					m_filterKeyfollowSlider->setParameter(tone->getParameter(0x5A));

					m_lfo1FilterDepthSlider->setParameter(tone->getParameter(0x63));
					m_lfo2FilterDepthSlider->setParameter(tone->getParameter(0x64));
				}
			}
		}
	}
    //[/Constructor]
}

FilterEditorAdvanced::~FilterEditorAdvanced()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
	if (m_filterTypeComboBox->getParamPtr() != nullptr)m_filterTypeComboBox->getParamPtr()->removeChangeListener(m_filterTypeComboBox);
	if (m_cutoffSlider->getParamPtr() != nullptr)m_cutoffSlider->getParamPtr()->removeChangeListener(m_cutoffSlider);
	if (m_cutoffKeyfollowSlider->getParamPtr() != nullptr)m_cutoffKeyfollowSlider->getParamPtr()->removeChangeListener(m_cutoffKeyfollowSlider);
	if (m_resonanceSlider->getParamPtr() != nullptr)m_resonanceSlider->getParamPtr()->removeChangeListener(m_resonanceSlider);
	if (m_resonanceVelocitySensSlider->getParamPtr() != nullptr)m_resonanceVelocitySensSlider->getParamPtr()->removeChangeListener(m_resonanceVelocitySensSlider);
	if (m_filterEnvelopeDepthSlider->getParamPtr() != nullptr)m_filterEnvelopeDepthSlider->getParamPtr()->removeChangeListener(m_filterEnvelopeDepthSlider);
	if (m_filterEnvVelCurveComboBox->getParamPtr() != nullptr)m_filterEnvVelCurveComboBox->getParamPtr()->removeChangeListener(m_filterEnvVelCurveComboBox);
	if (m_filterEnvVelCurveDisplay->getParamPtr() != nullptr)m_filterEnvVelCurveDisplay->getParamPtr()->removeChangeListener(m_filterEnvVelCurveDisplay);
	if (m_filterVelocitySensSlider->getParamPtr() != nullptr)m_filterVelocitySensSlider->getParamPtr()->removeChangeListener(m_filterVelocitySensSlider);
	if (m_filterEnvVelocityTime1Slider->getParamPtr() != nullptr)m_filterEnvVelocityTime1Slider->getParamPtr()->removeChangeListener(m_filterEnvVelocityTime1Slider);
	if (m_filterEnvVelocityTime4Slider->getParamPtr() != nullptr)m_filterEnvVelocityTime4Slider->getParamPtr()->removeChangeListener(m_filterEnvVelocityTime4Slider);
	if (m_filterKeyfollowSlider->getParamPtr() != nullptr)m_filterKeyfollowSlider->getParamPtr()->removeChangeListener(m_filterKeyfollowSlider);
    //[/Destructor_pre]

    m_filterGrp = nullptr;
    m_filterGrp2 = nullptr;
    m_cutoffSlider = nullptr;
    m_cutoffLabel = nullptr;
    m_filterEnv = nullptr;
    m_cutoffKeyfollowLabel = nullptr;
    m_cutoffKeyfollowSlider = nullptr;
    m_filterEnvelopeDepthSlider = nullptr;
    m_filterEnvelopeDepthLabel = nullptr;
    m_filterVelocitySensSlider = nullptr;
    m_filterEnvVelocitySensLabel = nullptr;
    m_filterEnvVelocityTime1Slider = nullptr;
    m_filterEnvVelocityTime1Label = nullptr;
    m_filterEnvVelocityTime4Slider = nullptr;
    m_filterEnvVelocityTime4Label = nullptr;
    m_filterEnvTimeKeyfollow = nullptr;
    m_filterKeyfollowSlider = nullptr;
    m_resonanceSlider = nullptr;
    m_resonanceLabel = nullptr;
    m_filterEnvVelCurveComboBox = nullptr;
    m_filterEnvVelCurveDisplay = nullptr;
    m_resonanceVelocitySensLabel = nullptr;
    m_resonanceVelocitySensSlider = nullptr;
    m_filterTypeLabel = nullptr;
    m_filterTypeComboBox = nullptr;
    m_filterEnvVelocityCurveLabel = nullptr;
    m_lfoGrp = nullptr;
    m_lfo1FilterDepthSlider = nullptr;
    m_lfo1FilterDepthLabel = nullptr;
    m_lfo2FilterDepthSlider = nullptr;
    m_lfo2FilterDepthLabel = nullptr;
    m_lfo1AdvancedButton = nullptr;
    m_lfo2AdvancedButton = nullptr;
    m_imageButton = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void FilterEditorAdvanced::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
	#ifdef JUCE_MSVC
	g;
	#endif
    //[/UserPrePaint]

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void FilterEditorAdvanced::resized()
{
    m_filterGrp->setBounds (0, 0, getWidth() - 0, getHeight() - 0);
    m_filterGrp2->setBounds (0, 140, getWidth() - 0, 260);
    m_cutoffSlider->setBounds (128, 36, 48, 60);
    m_cutoffLabel->setBounds (108, 20, 88, 16);
    m_filterEnv->setBounds (72, 156, 296, 156);
    m_cutoffKeyfollowLabel->setBounds (112, 100, 80, 16);
    m_cutoffKeyfollowSlider->setBounds (128, 116, 48, 16);
    m_filterEnvelopeDepthSlider->setBounds (8, 168, 56, 116);
    m_filterEnvelopeDepthLabel->setBounds (12, 156, 48, 16);
    m_filterVelocitySensSlider->setBounds (8, 306, 56, 16);
    m_filterEnvVelocitySensLabel->setBounds (0, 290, 72, 16);
    m_filterEnvVelocityTime1Slider->setBounds (124, 332, 56, 16);
    m_filterEnvVelocityTime1Label->setBounds (84, 316, 112, 16);
    m_filterEnvVelocityTime4Slider->setBounds (300, 332, 56, 16);
    m_filterEnvVelocityTime4Label->setBounds (264, 316, 112, 16);
    m_filterEnvTimeKeyfollow->setBounds (184, 356, 172, 16);
    m_filterKeyfollowSlider->setBounds (252, 372, 56, 16);
    m_resonanceSlider->setBounds (244, 36, 48, 60);
    m_resonanceLabel->setBounds (224, 20, 88, 16);
    m_filterEnvVelCurveComboBox->setBounds (8, 343, 68, 16);
    m_filterEnvVelCurveDisplay->setBounds (20, 363, 36, 36);
    m_resonanceVelocitySensLabel->setBounds (220, 100, 100, 16);
    m_resonanceVelocitySensSlider->setBounds (244, 116, 48, 16);
    m_filterTypeLabel->setBounds (4, 20, 84, 16);
    m_filterTypeComboBox->setBounds (8, 48, 76, 16);
    m_filterEnvVelocityCurveLabel->setBounds (0, 327, 80, 16);
    m_lfoGrp->setBounds (0, 404, getWidth() - 0, 88);
    m_lfo1FilterDepthSlider->setBounds (44, 436, 32, 48);
    m_lfo1FilterDepthLabel->setBounds (24, 420, 88, 16);
    m_lfo2FilterDepthSlider->setBounds (216, 436, 32, 48);
    m_lfo2FilterDepthLabel->setBounds (196, 420, 88, 16);
    m_lfo1AdvancedButton->setBounds (96, 464, 96, 21);
    m_lfo2AdvancedButton->setBounds (268, 464, 96, 21);
    m_imageButton->setBounds (3, 1, 16, 16);
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void FilterEditorAdvanced::sliderValueChanged (Slider* sliderThatWasMoved)
{
    //[UsersliderValueChanged_Pre]
    //[/UsersliderValueChanged_Pre]

    if (sliderThatWasMoved == m_cutoffSlider)
    {
        //[UserSliderCode_m_cutoffSlider] -- add your slider handling code here..
        //[/UserSliderCode_m_cutoffSlider]
    }
    else if (sliderThatWasMoved == m_cutoffKeyfollowSlider)
    {
        //[UserSliderCode_m_cutoffKeyfollowSlider] -- add your slider handling code here..
        //[/UserSliderCode_m_cutoffKeyfollowSlider]
    }
    else if (sliderThatWasMoved == m_filterEnvelopeDepthSlider)
    {
        //[UserSliderCode_m_filterEnvelopeDepthSlider] -- add your slider handling code here..
        //[/UserSliderCode_m_filterEnvelopeDepthSlider]
    }
    else if (sliderThatWasMoved == m_filterVelocitySensSlider)
    {
        //[UserSliderCode_m_filterVelocitySensSlider] -- add your slider handling code here..
        //[/UserSliderCode_m_filterVelocitySensSlider]
    }
    else if (sliderThatWasMoved == m_filterEnvVelocityTime1Slider)
    {
        //[UserSliderCode_m_filterEnvVelocityTime1Slider] -- add your slider handling code here..
        //[/UserSliderCode_m_filterEnvVelocityTime1Slider]
    }
    else if (sliderThatWasMoved == m_filterEnvVelocityTime4Slider)
    {
        //[UserSliderCode_m_filterEnvVelocityTime4Slider] -- add your slider handling code here..
        //[/UserSliderCode_m_filterEnvVelocityTime4Slider]
    }
    else if (sliderThatWasMoved == m_filterKeyfollowSlider)
    {
        //[UserSliderCode_m_filterKeyfollowSlider] -- add your slider handling code here..
        //[/UserSliderCode_m_filterKeyfollowSlider]
    }
    else if (sliderThatWasMoved == m_resonanceSlider)
    {
        //[UserSliderCode_m_resonanceSlider] -- add your slider handling code here..
        //[/UserSliderCode_m_resonanceSlider]
    }
    else if (sliderThatWasMoved == m_filterEnvVelCurveDisplay)
    {
        //[UserSliderCode_m_filterEnvVelCurveDisplay] -- add your slider handling code here..
        //[/UserSliderCode_m_filterEnvVelCurveDisplay]
    }
    else if (sliderThatWasMoved == m_resonanceVelocitySensSlider)
    {
        //[UserSliderCode_m_resonanceVelocitySensSlider] -- add your slider handling code here..
        //[/UserSliderCode_m_resonanceVelocitySensSlider]
    }
    else if (sliderThatWasMoved == m_lfo1FilterDepthSlider)
    {
        //[UserSliderCode_m_lfo1FilterDepthSlider] -- add your slider handling code here..
        //[/UserSliderCode_m_lfo1FilterDepthSlider]
    }
    else if (sliderThatWasMoved == m_lfo2FilterDepthSlider)
    {
        //[UserSliderCode_m_lfo2FilterDepthSlider] -- add your slider handling code here..
        //[/UserSliderCode_m_lfo2FilterDepthSlider]
    }

    //[UsersliderValueChanged_Post]
    //[/UsersliderValueChanged_Post]
}

void FilterEditorAdvanced::comboBoxChanged (ComboBox* comboBoxThatHasChanged)
{
    //[UsercomboBoxChanged_Pre]
    //[/UsercomboBoxChanged_Pre]

    if (comboBoxThatHasChanged == m_filterEnvVelCurveComboBox)
    {
        //[UserComboBoxCode_m_filterEnvVelCurveComboBox] -- add your combo box handling code here..
        //[/UserComboBoxCode_m_filterEnvVelCurveComboBox]
    }
    else if (comboBoxThatHasChanged == m_filterTypeComboBox)
    {
        //[UserComboBoxCode_m_filterTypeComboBox] -- add your combo box handling code here..
        //[/UserComboBoxCode_m_filterTypeComboBox]
    }

    //[UsercomboBoxChanged_Post]
    //[/UsercomboBoxChanged_Post]
}

void FilterEditorAdvanced::buttonClicked (Button* buttonThatWasClicked)
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



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Introjucer information section --

    This is where the Introjucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="FilterEditorAdvanced" componentName=""
                 parentClasses="public Component" constructorParams="const String &amp;componentName, SynthParts part, Tone tone"
                 variableInitialisers="Component (componentName), m_part(part), m_tone(tone)"
                 snapPixels="4" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="1" initialWidth="376" initialHeight="492">
  <BACKGROUND backgroundColour="0"/>
  <JUCERCOMP name="filterGrp" id="52e00682f746b888" memberName="m_filterGrp"
             virtualName="PanelGroupGrey" explicitFocusOrder="0" pos="0 0 0M 0M"
             sourceFile="../GroupWidgets/PanelGroupTransp.cpp" constructorParams="&quot;filterGrp&quot;, getName() "/>
  <JUCERCOMP name="filterGrp" id="f94b4c6bc1e7a151" memberName="m_filterGrp2"
             virtualName="PanelGroupGrey" explicitFocusOrder="0" pos="0 140 0M 260"
             sourceFile="../GroupWidgets/PanelGroupTransp.cpp" constructorParams="&quot;filterEnvGrp&quot;, getName().toUpperCase()+&quot; ENVELOPE&quot;"/>
  <SLIDER name="cutoffSlider" id="533842793459863a" memberName="m_cutoffSlider"
          virtualName="Knob" explicitFocusOrder="0" pos="128 36 48 60"
          textboxbkgd="fff2f59b" min="0" max="127" int="1" style="RotaryHorizontalVerticalDrag"
          textBoxPos="TextBoxBelow" textBoxEditable="1" textBoxWidth="80"
          textBoxHeight="16" skewFactor="1"/>
  <LABEL name="cutoffLabel" id="b464bd3cbdae27fd" memberName="m_cutoffLabel"
         virtualName="" explicitFocusOrder="0" pos="108 20 88 16" textCol="ff000000"
         edTextCol="ff000000" edBkgCol="0" labelText="CUTOFF" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="12" bold="1" italic="0" justification="36"/>
  <JUCERCOMP name="filterEnv" id="99a40d72d7ad1e22" memberName="m_filterEnv"
             virtualName="" explicitFocusOrder="0" pos="72 156 296 156" sourceFile="Envelope.cpp"
             constructorParams="m_part, m_tone, EnvelopeTypes::Filter, false"/>
  <LABEL name="cutoffKeyfollowLabel" id="3a52299341c28960" memberName="m_cutoffKeyfollowLabel"
         virtualName="" explicitFocusOrder="0" pos="112 100 80 16" textCol="ff000000"
         edTextCol="ff000000" edBkgCol="0" labelText="KEYFOLLOW" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="12" bold="1" italic="0" justification="36"/>
  <SLIDER name="cutoffKeyfollowSlider" id="70b45a3a21f5522" memberName="m_cutoffKeyfollowSlider"
          virtualName="KeyfollowMicroParameterSlider" explicitFocusOrder="0"
          pos="128 116 48 16" bkgcol="fff2f59b" thumbcol="ffc4c86d" min="0"
          max="127" int="1" style="LinearBar" textBoxPos="TextBoxLeft"
          textBoxEditable="1" textBoxWidth="40" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="filterEnvelopeDepthSlider" id="b0bd5a61181f569c" memberName="m_filterEnvelopeDepthSlider"
          virtualName="ParameterEnvelopeSlider" explicitFocusOrder="0"
          pos="8 168 56 116" bkgcol="f2f59b" textboxbkgd="fff2f59b" min="0"
          max="127" int="1" style="LinearVertical" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="56" textBoxHeight="16" skewFactor="1"/>
  <LABEL name="filterEnvelopeDepthLabel" id="611da7e96f52143f" memberName="m_filterEnvelopeDepthLabel"
         virtualName="" explicitFocusOrder="0" pos="12 156 48 16" textCol="ff000000"
         edTextCol="ff000000" edBkgCol="0" labelText="DEPTH" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="12" bold="1" italic="0" justification="36"/>
  <SLIDER name="filterVelocitySensSlider" id="ce3036a9c9d2d09a" memberName="m_filterVelocitySensSlider"
          virtualName="MicroParameterSlider" explicitFocusOrder="0" pos="8 306 56 16"
          bkgcol="fff2f59b" thumbcol="ffc4c86d" min="0" max="127" int="1"
          style="LinearBar" textBoxPos="TextBoxLeft" textBoxEditable="1"
          textBoxWidth="40" textBoxHeight="20" skewFactor="1"/>
  <LABEL name="filterEnvVelocitySensLabel" id="da6b2f045679c497" memberName="m_filterEnvVelocitySensLabel"
         virtualName="" explicitFocusOrder="0" pos="0 290 72 16" textCol="ff000000"
         edTextCol="ff000000" edBkgCol="0" labelText="VELO SENS" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="12" bold="1" italic="0" justification="36"/>
  <SLIDER name="filterEnvVelocityTime1Slider" id="26e8b1e9ec956faf" memberName="m_filterEnvVelocityTime1Slider"
          virtualName="MicroParameterSlider" explicitFocusOrder="0" pos="124 332 56 16"
          bkgcol="fff2f59b" thumbcol="ffc4c86d" min="0" max="127" int="1"
          style="LinearBar" textBoxPos="TextBoxLeft" textBoxEditable="1"
          textBoxWidth="40" textBoxHeight="20" skewFactor="1"/>
  <LABEL name="filterEnvVelocityTime1Label" id="fcf555c7750e1905" memberName="m_filterEnvVelocityTime1Label"
         virtualName="" explicitFocusOrder="0" pos="84 316 112 16" textCol="ff000000"
         edTextCol="ff000000" edBkgCol="0" labelText="VELO SENS TIME 1"
         editableSingleClick="0" editableDoubleClick="0" focusDiscardsChanges="0"
         fontname="Default font" fontsize="12" bold="1" italic="0" justification="36"/>
  <SLIDER name="filterEnvVelocityTime4Slider" id="96d5b92b9bc16388" memberName="m_filterEnvVelocityTime4Slider"
          virtualName="MicroParameterSlider" explicitFocusOrder="0" pos="300 332 56 16"
          bkgcol="fff2f59b" thumbcol="ffc4c86d" min="0" max="127" int="1"
          style="LinearBar" textBoxPos="TextBoxLeft" textBoxEditable="1"
          textBoxWidth="40" textBoxHeight="20" skewFactor="1"/>
  <LABEL name="filterEnvVelocityTime4Label" id="d741df9cfd6aac2d" memberName="m_filterEnvVelocityTime4Label"
         virtualName="" explicitFocusOrder="0" pos="264 316 112 16" textCol="ff000000"
         edTextCol="ff000000" edBkgCol="0" labelText="VELO SENS TIME 4"
         editableSingleClick="0" editableDoubleClick="0" focusDiscardsChanges="0"
         fontname="Default font" fontsize="12" bold="1" italic="0" justification="36"/>
  <LABEL name="filterEnvTimeKeyfollow" id="cf887a8299fda426" memberName="m_filterEnvTimeKeyfollow"
         virtualName="" explicitFocusOrder="0" pos="184 356 172 16" textCol="ff000000"
         edTextCol="ff000000" edBkgCol="0" labelText="KEYFOLLOW TIME 2/3/4 "
         editableSingleClick="0" editableDoubleClick="0" focusDiscardsChanges="0"
         fontname="Default font" fontsize="12" bold="1" italic="0" justification="36"/>
  <SLIDER name="filterKeyfollowSlider" id="fd7fba1a74d4d802" memberName="m_filterKeyfollowSlider"
          virtualName="KeyfollowMicroParameterSlider" explicitFocusOrder="0"
          pos="252 372 56 16" bkgcol="fff2f59b" thumbcol="ffc4c86d" min="0"
          max="127" int="1" style="LinearBar" textBoxPos="TextBoxLeft"
          textBoxEditable="1" textBoxWidth="40" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="resonanceSlider" id="323e25f12b9bcb4d" memberName="m_resonanceSlider"
          virtualName="Knob" explicitFocusOrder="0" pos="244 36 48 60"
          textboxbkgd="fff2f59b" min="0" max="127" int="1" style="RotaryHorizontalVerticalDrag"
          textBoxPos="TextBoxBelow" textBoxEditable="1" textBoxWidth="80"
          textBoxHeight="16" skewFactor="1"/>
  <LABEL name="resonanceLabel" id="4a6481529e07d2e7" memberName="m_resonanceLabel"
         virtualName="" explicitFocusOrder="0" pos="224 20 88 16" textCol="ff000000"
         edTextCol="ff000000" edBkgCol="0" labelText="RESONANCE" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="12" bold="1" italic="0" justification="36"/>
  <COMBOBOX name="filterEnvVelCurveComboBox" id="5f5f3969c23f54e2" memberName="m_filterEnvVelCurveComboBox"
            virtualName="ParameterComboBox" explicitFocusOrder="0" pos="8 343 68 16"
            editable="0" layout="36" items="" textWhenNonSelected="Normal"
            textWhenNoItems="(no choices)"/>
  <SLIDER name="filterEnvVelCurveDisplay" id="d9c13bc39fc51534" memberName="m_filterEnvVelCurveDisplay"
          virtualName="ParameterVelCurveDisplay" explicitFocusOrder="0"
          pos="20 363 36 36" min="0" max="10" int="0" style="RotaryHorizontalVerticalDrag"
          textBoxPos="NoTextBox" textBoxEditable="1" textBoxWidth="80"
          textBoxHeight="20" skewFactor="1"/>
  <LABEL name="resonanceVelocitySensLabel" id="cd7bd760659858dc" memberName="m_resonanceVelocitySensLabel"
         virtualName="" explicitFocusOrder="0" pos="220 100 100 16" textCol="ff000000"
         edTextCol="ff000000" edBkgCol="0" labelText="VELOCITY SENS" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="12" bold="1" italic="0" justification="36"/>
  <SLIDER name="resonanceVelocitySensSlider" id="e85bd80388f15147" memberName="m_resonanceVelocitySensSlider"
          virtualName="MicroParameterSlider" explicitFocusOrder="0" pos="244 116 48 16"
          bkgcol="fff2f59b" thumbcol="ffc4c86d" min="0" max="127" int="1"
          style="LinearBar" textBoxPos="TextBoxLeft" textBoxEditable="1"
          textBoxWidth="40" textBoxHeight="20" skewFactor="1"/>
  <LABEL name="filterTypeLabel" id="c41c307042cbea72" memberName="m_filterTypeLabel"
         virtualName="" explicitFocusOrder="0" pos="4 20 84 16" textCol="ff000000"
         edTextCol="ff000000" edBkgCol="0" labelText="FILTER TYPE" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="12" bold="1" italic="0" justification="36"/>
  <COMBOBOX name="filterTypeComboBox" id="e8c10ecedfc6fd9e" memberName="m_filterTypeComboBox"
            virtualName="ParameterComboBox" explicitFocusOrder="0" pos="8 48 76 16"
            editable="0" layout="36" items="" textWhenNonSelected="" textWhenNoItems="(no choices)"/>
  <LABEL name="filterEnvVelocityCurveLabel" id="4fa3b6178a95b9c" memberName="m_filterEnvVelocityCurveLabel"
         virtualName="" explicitFocusOrder="0" pos="0 327 80 16" textCol="ff000000"
         edTextCol="ff000000" edBkgCol="0" labelText="VELO CURVE" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="12" bold="1" italic="0" justification="36"/>
  <JUCERCOMP name="lfoGrp" id="5d2169b0330e13c6" memberName="m_lfoGrp" virtualName="PanelGroupGrey"
             explicitFocusOrder="0" pos="0 404 0M 88" sourceFile="../GroupWidgets/PanelGroupTransp.cpp"
             constructorParams="&quot;lfoGrp&quot;, &quot;LFO MODULATION&quot;"/>
  <SLIDER name="lfo1FilterDepthSlider" id="5139dffd40f5b193" memberName="m_lfo1FilterDepthSlider"
          virtualName="Knob" explicitFocusOrder="0" pos="44 436 32 48"
          textboxbkgd="fff2f59b" min="0" max="127" int="1" style="RotaryHorizontalVerticalDrag"
          textBoxPos="TextBoxBelow" textBoxEditable="1" textBoxWidth="80"
          textBoxHeight="16" skewFactor="1"/>
  <LABEL name="lfo1FilterDepthLabel" id="ddaad26232bd3db3" memberName="m_lfo1FilterDepthLabel"
         virtualName="" explicitFocusOrder="0" pos="24 420 88 16" textCol="ff000000"
         edTextCol="ff000000" edBkgCol="0" labelText="LFO 1 DEPTH" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="12" bold="1" italic="0" justification="36"/>
  <SLIDER name="lfo2FilterDepthSlider" id="37bb334dae2c4ad2" memberName="m_lfo2FilterDepthSlider"
          virtualName="Knob" explicitFocusOrder="0" pos="216 436 32 48"
          textboxbkgd="fff2f59b" min="0" max="127" int="1" style="RotaryHorizontalVerticalDrag"
          textBoxPos="TextBoxBelow" textBoxEditable="1" textBoxWidth="80"
          textBoxHeight="16" skewFactor="1"/>
  <LABEL name="lfo2FilterDepthLabel" id="20feaad1dd36b9a5" memberName="m_lfo2FilterDepthLabel"
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
  <IMAGEBUTTON name="imageButton" id="fe0600a05b8279fe" memberName="m_imageButton"
               virtualName="" explicitFocusOrder="0" pos="3 1 16 16" buttonText=""
               connectedEdges="0" needsCallback="0" radioGroupId="0" keepProportions="1"
               resourceNormal="filter_png" opacityNormal="1" colourNormal="4340454a"
               resourceOver="" opacityOver="1" colourOver="4340454a" resourceDown=""
               opacityDown="1" colourDown="4340454a"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif

//==============================================================================
// Binary resources - be careful not to edit any of these sections!

// JUCER_RESOURCE: filter_png, 216, "../../../Resources/PatchEditSectionIcons/filter.png"
static const unsigned char resource_FilterEditorAdvanced_filter_png[] = { 137,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,0,16,0,0,0,16,8,6,0,0,0,31,243,255,97,0,0,0,1,115,82,71,66,0,174,206,28,233,
0,0,0,6,98,75,71,68,0,255,0,255,0,255,160,189,167,147,0,0,0,9,112,72,89,115,0,0,11,19,0,0,11,19,1,0,154,156,24,0,0,0,7,116,73,77,69,7,222,12,10,20,17,41,68,233,106,74,0,0,0,88,73,68,65,84,56,203,205,147,
59,14,0,32,8,67,121,198,251,95,25,23,7,52,198,240,113,144,145,208,166,180,41,50,71,85,85,2,3,32,89,240,130,201,128,45,73,247,170,88,36,31,165,120,37,111,187,230,5,3,156,72,90,216,241,12,193,245,205,104,
10,246,62,228,65,233,133,167,30,236,105,124,144,66,181,76,84,235,60,0,71,153,87,223,168,164,70,56,0,0,0,0,73,69,78,68,174,66,96,130,0,0};

const char* FilterEditorAdvanced::filter_png = (const char*) resource_FilterEditorAdvanced_filter_png;
const int FilterEditorAdvanced::filter_pngSize = 216;


//[EndFile] You can add extra defines here...
//[/EndFile]
