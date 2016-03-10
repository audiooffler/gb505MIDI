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
#include "../../GrooveboxMemory/Waveforms.h"
#include "../ParameterWidgets/WaveformBrowser.h"
#include "PatchControllerMatrixEditor.h"
#include "PitchEditorAdvanced.h"
#include "FilterEditorAdvanced.h"
#include "AmpEditorAdvanced.h"
#include "FxmEditor.h"
#include "ToneDelayEditor.h"
//[/Headers]

#include "PatchToneEditor.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
extern OverallMemoryBlock* grooveboxMemory;
extern Waveforms* waveForms;
//[/MiscUserDefs]

//==============================================================================
PatchToneEditor::PatchToneEditor (SynthParts part, Tone tone)
    : m_part (part),
      m_tone (tone)
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    addAndMakeVisible (m_ampGrp = new PanelGroupGrey ("AmpGrp","AMP OF TONE "+String(((int)m_tone - 0x1000)/0x200 + 1)));
    addAndMakeVisible (m_filterGrp = new PanelGroupGrey ("FilterGrp","FILTER OF TONE "+String(((int)m_tone - 0x1000)/0x200 + 1)));
    addAndMakeVisible (m_filterEnv = new Envelope (m_part, m_tone, EnvelopeTypes::Filter, true));
    addAndMakeVisible (m_pitchGrp = new PanelGroupGrey ("PitchGrp","PITCH OF TONE "+String(((int)m_tone - 0x1000)/0x200 + 1)));
    addAndMakeVisible (m_waveGrp = new PanelGroupGrey ("WAVEGrp","TONE "+String(((int)m_tone - 0x1000)/0x200 + 1)));
    addAndMakeVisible (m_pitchEnv = new Envelope (m_part, m_tone, EnvelopeTypes::Pitch, true));
    addAndMakeVisible (m_ampEnv = new Envelope (m_part, m_tone, EnvelopeTypes::Amp, true));
    addAndMakeVisible (m_onToggle = new BlackToggle());
    addAndMakeVisible (m_onLabel = new Label ("onLabel",
                                              TRANS("ON")));
    m_onLabel->setFont (Font (12.00f, Font::bold));
    m_onLabel->setJustificationType (Justification::centredRight);
    m_onLabel->setEditable (false, false, false);
    m_onLabel->setColour (Label::textColourId, Colours::black);
    m_onLabel->setColour (TextEditor::textColourId, Colours::black);
    m_onLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_waveButton = new TextButton ("new button"));
    m_waveButton->setButtonText (TRANS("A:001 Dist TB 303a"));
    m_waveButton->addListener (this);

    addAndMakeVisible (m_waveLabel = new Label ("waveLabel",
                                                TRANS("WAVEFORM")));
    m_waveLabel->setFont (Font (12.00f, Font::bold));
    m_waveLabel->setJustificationType (Justification::centredRight);
    m_waveLabel->setEditable (false, false, false);
    m_waveLabel->setColour (Label::textColourId, Colours::black);
    m_waveLabel->setColour (TextEditor::textColourId, Colours::black);
    m_waveLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_onLabel2 = new Label ("onLabel",
                                               TRANS("GAIN")));
    m_onLabel2->setFont (Font (12.00f, Font::bold));
    m_onLabel2->setJustificationType (Justification::centredRight);
    m_onLabel2->setEditable (false, false, false);
    m_onLabel2->setColour (Label::textColourId, Colours::black);
    m_onLabel2->setColour (TextEditor::textColourId, Colours::black);
    m_onLabel2->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_lfo1 = new LfoEditor ("LFO 1 OF TONE "+String(((int)m_tone - 0x1000)/0x200 + 1),m_part, m_tone, false));
    addAndMakeVisible (m_lfo2 = new LfoEditor ("LFO 2 OF TONE "+String(((int)m_tone - 0x1000)/0x200 + 1),m_part, m_tone, true));
    addAndMakeVisible (m_controlMatrixButton = new TextWithArrowButton ("controlMatrixButton"));
    m_controlMatrixButton->setButtonText (TRANS("CTRL MATRIX"));
    m_controlMatrixButton->addListener (this);

    addAndMakeVisible (m_coarseTuneSlider = new MicroParameterSlider ("coarseTuneSlider"));
    m_coarseTuneSlider->setRange (0, 127, 1);
    m_coarseTuneSlider->setSliderStyle (Slider::LinearBar);
    m_coarseTuneSlider->setTextBoxStyle (Slider::TextBoxLeft, false, 40, 20);
    m_coarseTuneSlider->setColour (Slider::backgroundColourId, Colour (0xfff2f59b));
    m_coarseTuneSlider->setColour (Slider::thumbColourId, Colour (0xffc4c86d));
    m_coarseTuneSlider->addListener (this);

    addAndMakeVisible (m_fineTuneSlider = new MicroParameterSlider ("fineTuneSlider"));
    m_fineTuneSlider->setRange (0, 127, 1);
    m_fineTuneSlider->setSliderStyle (Slider::LinearBar);
    m_fineTuneSlider->setTextBoxStyle (Slider::TextBoxLeft, false, 40, 20);
    m_fineTuneSlider->setColour (Slider::backgroundColourId, Colour (0xfff2f59b));
    m_fineTuneSlider->setColour (Slider::thumbColourId, Colour (0xffc4c86d));
    m_fineTuneSlider->addListener (this);

    addAndMakeVisible (m_coarseTuneLabel = new Label ("coarseTuneLabel",
                                                      TRANS("COARSE TUNE")));
    m_coarseTuneLabel->setFont (Font (12.00f, Font::bold));
    m_coarseTuneLabel->setJustificationType (Justification::centredRight);
    m_coarseTuneLabel->setEditable (false, false, false);
    m_coarseTuneLabel->setColour (Label::textColourId, Colours::black);
    m_coarseTuneLabel->setColour (TextEditor::textColourId, Colours::black);
    m_coarseTuneLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_fineTuneLabel = new Label ("fineTuneLabel",
                                                    TRANS("FINE TUNE")));
    m_fineTuneLabel->setFont (Font (12.00f, Font::bold));
    m_fineTuneLabel->setJustificationType (Justification::centredRight);
    m_fineTuneLabel->setEditable (false, false, false);
    m_fineTuneLabel->setColour (Label::textColourId, Colours::black);
    m_fineTuneLabel->setColour (TextEditor::textColourId, Colours::black);
    m_fineTuneLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_pitchEnvelopeDepthSlider = new MicroParameterSlider ("pitchEnvelopeDepthSlider"));
    m_pitchEnvelopeDepthSlider->setRange (0, 127, 1);
    m_pitchEnvelopeDepthSlider->setSliderStyle (Slider::LinearBar);
    m_pitchEnvelopeDepthSlider->setTextBoxStyle (Slider::TextBoxLeft, false, 40, 20);
    m_pitchEnvelopeDepthSlider->setColour (Slider::backgroundColourId, Colour (0xfff2f59b));
    m_pitchEnvelopeDepthSlider->setColour (Slider::thumbColourId, Colour (0xffc4c86d));
    m_pitchEnvelopeDepthSlider->addListener (this);

    addAndMakeVisible (m_pitchEnvelopeDepthLabel = new Label ("pitchEnvelopeDepthLabel",
                                                              TRANS("ENV DEPTH")));
    m_pitchEnvelopeDepthLabel->setFont (Font (12.00f, Font::bold));
    m_pitchEnvelopeDepthLabel->setJustificationType (Justification::centredRight);
    m_pitchEnvelopeDepthLabel->setEditable (false, false, false);
    m_pitchEnvelopeDepthLabel->setColour (Label::textColourId, Colours::black);
    m_pitchEnvelopeDepthLabel->setColour (TextEditor::textColourId, Colours::black);
    m_pitchEnvelopeDepthLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_pitchAdvancedButton = new TextWithArrowButton ("new button"));
    m_pitchAdvancedButton->setButtonText (TRANS("PITCH"));
    m_pitchAdvancedButton->addListener (this);

    addAndMakeVisible (m_filterEnvelopeDepthSlider = new MicroParameterSlider ("filterEnvelopeDepthSlider"));
    m_filterEnvelopeDepthSlider->setRange (0, 127, 1);
    m_filterEnvelopeDepthSlider->setSliderStyle (Slider::LinearBar);
    m_filterEnvelopeDepthSlider->setTextBoxStyle (Slider::TextBoxLeft, false, 40, 20);
    m_filterEnvelopeDepthSlider->setColour (Slider::backgroundColourId, Colour (0xfff2f59b));
    m_filterEnvelopeDepthSlider->setColour (Slider::thumbColourId, Colour (0xffc4c86d));
    m_filterEnvelopeDepthSlider->addListener (this);

    addAndMakeVisible (m_filterEnvelopeDepthLabel = new Label ("filterEnvelopeDepthLabel",
                                                               TRANS("ENV DEPTH")));
    m_filterEnvelopeDepthLabel->setFont (Font (12.00f, Font::bold));
    m_filterEnvelopeDepthLabel->setJustificationType (Justification::centredRight);
    m_filterEnvelopeDepthLabel->setEditable (false, false, false);
    m_filterEnvelopeDepthLabel->setColour (Label::textColourId, Colours::black);
    m_filterEnvelopeDepthLabel->setColour (TextEditor::textColourId, Colours::black);
    m_filterEnvelopeDepthLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_filterAdvancedButton = new TextWithArrowButton ("filterAdvancedButton"));
    m_filterAdvancedButton->setButtonText (TRANS("FILTER"));
    m_filterAdvancedButton->addListener (this);

    addAndMakeVisible (m_cutoffSlider = new MicroParameterSlider ("cutoffSlider"));
    m_cutoffSlider->setRange (0, 127, 1);
    m_cutoffSlider->setSliderStyle (Slider::LinearBar);
    m_cutoffSlider->setTextBoxStyle (Slider::TextBoxBelow, false, 80, 16);
    m_cutoffSlider->setColour (Slider::backgroundColourId, Colour (0xfff2f59b));
    m_cutoffSlider->setColour (Slider::thumbColourId, Colour (0xffc4c86d));
    m_cutoffSlider->setColour (Slider::textBoxBackgroundColourId, Colour (0xfff2f59b));
    m_cutoffSlider->addListener (this);

    addAndMakeVisible (m_cutoffLabel = new Label ("cutoffLabel",
                                                  TRANS("CUT")));
    m_cutoffLabel->setFont (Font (12.00f, Font::bold));
    m_cutoffLabel->setJustificationType (Justification::centredRight);
    m_cutoffLabel->setEditable (false, false, false);
    m_cutoffLabel->setColour (Label::textColourId, Colours::black);
    m_cutoffLabel->setColour (TextEditor::textColourId, Colours::black);
    m_cutoffLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_resonanceLabel = new Label ("resonanceLabel",
                                                     TRANS("RES")));
    m_resonanceLabel->setFont (Font (12.00f, Font::bold));
    m_resonanceLabel->setJustificationType (Justification::centredRight);
    m_resonanceLabel->setEditable (false, false, false);
    m_resonanceLabel->setColour (Label::textColourId, Colours::black);
    m_resonanceLabel->setColour (TextEditor::textColourId, Colours::black);
    m_resonanceLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_filterTypeLabel = new Label ("filterTypeLabel",
                                                      TRANS("TYPE")));
    m_filterTypeLabel->setFont (Font (12.00f, Font::bold));
    m_filterTypeLabel->setJustificationType (Justification::centred);
    m_filterTypeLabel->setEditable (false, false, false);
    m_filterTypeLabel->setColour (Label::textColourId, Colours::black);
    m_filterTypeLabel->setColour (TextEditor::textColourId, Colours::black);
    m_filterTypeLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_filterTypeComboBox = new ParameterComboBox ("filterTypeComboBox"));
    m_filterTypeComboBox->setEditableText (false);
    m_filterTypeComboBox->setJustificationType (Justification::centred);
    m_filterTypeComboBox->setTextWhenNothingSelected (TRANS("OFF"));
    m_filterTypeComboBox->setTextWhenNoChoicesAvailable (TRANS("(no choices)"));
    m_filterTypeComboBox->addItem (TRANS("OFF"), 1);
    m_filterTypeComboBox->addItem (TRANS("LPF"), 2);
    m_filterTypeComboBox->addItem (TRANS("BPF"), 3);
    m_filterTypeComboBox->addItem (TRANS("HPF"), 4);
    m_filterTypeComboBox->addItem (TRANS("PKG"), 5);
    m_filterTypeComboBox->addListener (this);

    addAndMakeVisible (m_resonanceSlider = new MicroParameterSlider ("resonanceSlider"));
    m_resonanceSlider->setRange (0, 127, 1);
    m_resonanceSlider->setSliderStyle (Slider::LinearBar);
    m_resonanceSlider->setTextBoxStyle (Slider::TextBoxBelow, false, 80, 16);
    m_resonanceSlider->setColour (Slider::backgroundColourId, Colour (0xfff2f59b));
    m_resonanceSlider->setColour (Slider::thumbColourId, Colour (0xffc4c86d));
    m_resonanceSlider->setColour (Slider::textBoxBackgroundColourId, Colour (0xfff2f59b));
    m_resonanceSlider->addListener (this);

    addAndMakeVisible (m_ampAdvancedButton = new TextWithArrowButton ("ampAdvancedButton"));
    m_ampAdvancedButton->setButtonText (TRANS("AMP"));
    m_ampAdvancedButton->addListener (this);

    addAndMakeVisible (m_toneLevelSlider = new MixPartLevelFader ("toneLevelSlider"));
    m_toneLevelSlider->setRange (0, 127, 1);
    m_toneLevelSlider->setSliderStyle (Slider::LinearHorizontal);
    m_toneLevelSlider->setTextBoxStyle (Slider::TextBoxAbove, false, 32, 16);
    m_toneLevelSlider->addListener (this);

    addAndMakeVisible (m_toneLevelLabel = new Label ("toneLevelLabel",
                                                     TRANS("TONE LEVEL")));
    m_toneLevelLabel->setFont (Font (12.00f, Font::bold));
    m_toneLevelLabel->setJustificationType (Justification::centredLeft);
    m_toneLevelLabel->setEditable (false, false, false);
    m_toneLevelLabel->setColour (Label::textColourId, Colours::black);
    m_toneLevelLabel->setColour (TextEditor::textColourId, Colours::black);
    m_toneLevelLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_tonePanSlider = new MicroParameterSlider ("cutoffSlider"));
    m_tonePanSlider->setRange (0, 127, 1);
    m_tonePanSlider->setSliderStyle (Slider::LinearBar);
    m_tonePanSlider->setTextBoxStyle (Slider::TextBoxBelow, false, 80, 16);
    m_tonePanSlider->setColour (Slider::backgroundColourId, Colour (0xfff2f59b));
    m_tonePanSlider->setColour (Slider::thumbColourId, Colour (0xffc4c86d));
    m_tonePanSlider->setColour (Slider::textBoxBackgroundColourId, Colour (0xfff2f59b));
    m_tonePanSlider->addListener (this);

    addAndMakeVisible (m_tonePanLabel = new Label ("tonePanLabel",
                                                   TRANS("PAN")));
    m_tonePanLabel->setFont (Font (12.00f, Font::bold));
    m_tonePanLabel->setJustificationType (Justification::centredRight);
    m_tonePanLabel->setEditable (false, false, false);
    m_tonePanLabel->setColour (Label::textColourId, Colours::black);
    m_tonePanLabel->setColour (TextEditor::textColourId, Colours::black);
    m_tonePanLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_fxmAdvancedButton = new TextWithArrowButton ("fxmAdvancedButton"));
    m_fxmAdvancedButton->setButtonText (TRANS("FXM"));
    m_fxmAdvancedButton->addListener (this);

    addAndMakeVisible (imageButton = new ImageButton ("new button"));
    imageButton->setButtonText (String());
    imageButton->addListener (this);

    imageButton->setImages (false, true, true,
                            ImageCache::getFromMemory (wave_png, wave_pngSize), 1.000f, Colour (0x4340454a),
                            Image(), 1.000f, Colour (0x4340454a),
                            Image(), 1.000f, Colour (0x4340454a));
    addAndMakeVisible (imageButton4 = new ImageButton ("new button"));
    imageButton4->setButtonText (String());
    imageButton4->addListener (this);

    imageButton4->setImages (false, true, true,
                             ImageCache::getFromMemory (pitch_png, pitch_pngSize), 1.000f, Colour (0x4340454a),
                             Image(), 1.000f, Colour (0x4340454a),
                             Image(), 1.000f, Colour (0x4340454a));
    addAndMakeVisible (imageButton5 = new ImageButton ("new button"));
    imageButton5->setButtonText (String());
    imageButton5->addListener (this);

    imageButton5->setImages (false, true, true,
                             ImageCache::getFromMemory (filter_png, filter_pngSize), 1.000f, Colour (0x4340454a),
                             Image(), 1.000f, Colour (0x4340454a),
                             Image(), 1.000f, Colour (0x4340454a));
    addAndMakeVisible (imageButton6 = new ImageButton ("new button"));
    imageButton6->setButtonText (String());
    imageButton6->addListener (this);

    imageButton6->setImages (false, true, true,
                             ImageCache::getFromMemory (amp_png, amp_pngSize), 1.000f, Colour (0x4340454a),
                             ImageCache::getFromMemory (amp_png, amp_pngSize), 1.000f, Colour (0x4340454a),
                             ImageCache::getFromMemory (amp_png, amp_pngSize), 1.000f, Colour (0x4340454a));
    addAndMakeVisible (m_delayAdvancedButton = new TextWithArrowButton ("delayAdvancedButton"));
    m_delayAdvancedButton->setButtonText (TRANS("DLY"));
    m_delayAdvancedButton->addListener (this);

    addAndMakeVisible (m_waveGainComboBox = new ParameterComboBox ("waveGainComboBox"));
    m_waveGainComboBox->setEditableText (false);
    m_waveGainComboBox->setJustificationType (Justification::centredRight);
    m_waveGainComboBox->setTextWhenNothingSelected (TRANS("-6dB"));
    m_waveGainComboBox->setTextWhenNoChoicesAvailable (TRANS("(no choices)"));
    m_waveGainComboBox->addItem (TRANS("-6dB"), 1);
    m_waveGainComboBox->addItem (TRANS("0dB"), 2);
    m_waveGainComboBox->addItem (TRANS("+6dB"), 3);
    m_waveGainComboBox->addItem (TRANS("+12dB"), 4);
    m_waveGainComboBox->addListener (this);

    addAndMakeVisible (component = new RectangleTransp());

    //[UserPreSize]
	m_waveGroupType = nullptr;
	m_waveGroupId = nullptr;
	m_waveNumber = nullptr;
    //m_toneGrp->setText(labelText);
    //[/UserPreSize]

    setSize (304, 572);


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
					m_onToggle->setParameter(tone->getParameter(0x00));
					m_waveGroupType = tone->getParameter(0x01);
					m_waveGroupId = tone->getParameter(0x02);
					m_waveNumber = tone->getParameter(0x03);
					changeListenerCallback(m_waveNumber);
					m_waveGroupType->addChangeListener(this);
					m_waveGroupId->addChangeListener(this);
					m_waveNumber->addChangeListener(this);
					m_waveGainComboBox->setParameter(tone->getParameter(0x05));

					m_coarseTuneSlider->setParameter(tone->getParameter(0x3D));
					m_fineTuneSlider->setParameter(tone->getParameter(0x3E));
					m_pitchEnvelopeDepthSlider->setParameter(tone->getParameter(0x41));

					m_filterTypeComboBox->setParameter(tone->getParameter(0x50));
					m_cutoffSlider->setParameter(tone->getParameter(0x51));
					m_resonanceSlider->setParameter(tone->getParameter(0x53));
					m_filterEnvelopeDepthSlider->setParameter(tone->getParameter(0x55));

					m_toneLevelSlider->setParameter(tone->getParameter(0x65));
					m_tonePanSlider->setParameter(tone->getParameter(0x77));
				}
			}
		}
	}
    //[/Constructor]
}

PatchToneEditor::~PatchToneEditor()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
	if (m_waveGroupType != nullptr) m_waveGroupType->removeChangeListener(this);
	if (m_waveGroupId != nullptr) m_waveGroupId->removeChangeListener(this);
	if (m_waveNumber != nullptr) m_waveNumber->removeChangeListener(this);
    //[/Destructor_pre]

    m_ampGrp = nullptr;
    m_filterGrp = nullptr;
    m_filterEnv = nullptr;
    m_pitchGrp = nullptr;
    m_waveGrp = nullptr;
    m_pitchEnv = nullptr;
    m_ampEnv = nullptr;
    m_onToggle = nullptr;
    m_onLabel = nullptr;
    m_waveButton = nullptr;
    m_waveLabel = nullptr;
    m_onLabel2 = nullptr;
    m_lfo1 = nullptr;
    m_lfo2 = nullptr;
    m_controlMatrixButton = nullptr;
    m_coarseTuneSlider = nullptr;
    m_fineTuneSlider = nullptr;
    m_coarseTuneLabel = nullptr;
    m_fineTuneLabel = nullptr;
    m_pitchEnvelopeDepthSlider = nullptr;
    m_pitchEnvelopeDepthLabel = nullptr;
    m_pitchAdvancedButton = nullptr;
    m_filterEnvelopeDepthSlider = nullptr;
    m_filterEnvelopeDepthLabel = nullptr;
    m_filterAdvancedButton = nullptr;
    m_cutoffSlider = nullptr;
    m_cutoffLabel = nullptr;
    m_resonanceLabel = nullptr;
    m_filterTypeLabel = nullptr;
    m_filterTypeComboBox = nullptr;
    m_resonanceSlider = nullptr;
    m_ampAdvancedButton = nullptr;
    m_toneLevelSlider = nullptr;
    m_toneLevelLabel = nullptr;
    m_tonePanSlider = nullptr;
    m_tonePanLabel = nullptr;
    m_fxmAdvancedButton = nullptr;
    imageButton = nullptr;
    imageButton4 = nullptr;
    imageButton5 = nullptr;
    imageButton6 = nullptr;
    m_delayAdvancedButton = nullptr;
    m_waveGainComboBox = nullptr;
    component = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void PatchToneEditor::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
	#ifdef JUCE_MSVC
	g;
	#endif
    //[/UserPrePaint]

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void PatchToneEditor::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    m_ampGrp->setBounds (0, 440, 304, 132);
    m_filterGrp->setBounds (0, 306, 304, 132);
    m_filterEnv->setBounds (4, 367, 296, 72);
    m_pitchGrp->setBounds (0, 172, 304, 132);
    m_waveGrp->setBounds (0, 0, 304, 68);
    m_pitchEnv->setBounds (4, 229, 296, 72);
    m_ampEnv->setBounds (4, 500, 296, 72);
    m_onToggle->setBounds (39, 20, 25, 17);
    m_onLabel->setBounds (-3, 16, 42, 24);
    m_waveButton->setBounds (152, 17, 148, 21);
    m_waveLabel->setBounds (78, 16, 76, 24);
    m_onLabel2->setBounds (-3, 41, 42, 24);
    m_lfo1->setBounds (0, 70, 151, 100);
    m_lfo2->setBounds (153, 70, 151, 100);
    m_controlMatrixButton->setBounds (200, 42, 100, 20);
    m_coarseTuneSlider->setBounds (96, 190, 56, 16);
    m_fineTuneSlider->setBounds (96, 212, 56, 16);
    m_coarseTuneLabel->setBounds (0, 190, 96, 16);
    m_fineTuneLabel->setBounds (0, 212, 96, 16);
    m_pitchEnvelopeDepthSlider->setBounds (240, 212, 56, 16);
    m_pitchEnvelopeDepthLabel->setBounds (144, 212, 96, 16);
    m_pitchAdvancedButton->setBounds (164, 189, 132, 20);
    m_filterEnvelopeDepthSlider->setBounds (240, 347, 56, 16);
    m_filterEnvelopeDepthLabel->setBounds (144, 347, 96, 16);
    m_filterAdvancedButton->setBounds (164, 323, 132, 20);
    m_cutoffSlider->setBounds (36, 324, 56, 16);
    m_cutoffLabel->setBounds (4, 324, 32, 16);
    m_resonanceLabel->setBounds (4, 346, 32, 16);
    m_filterTypeLabel->setBounds (104, 330, 48, 16);
    m_filterTypeComboBox->setBounds (100, 346, 55, 16);
    m_resonanceSlider->setBounds (36, 346, 56, 16);
    m_ampAdvancedButton->setBounds (164, 458, 132, 20);
    m_toneLevelSlider->setBounds (88 - (168 / 2), 501 - 36, 168, 36);
    m_toneLevelLabel->setBounds (-2, 465, 78, 16);
    m_tonePanSlider->setBounds (240, 482, 56, 16);
    m_tonePanLabel->setBounds (208, 482, 32, 16);
    m_fxmAdvancedButton->setBounds (146, 42, 52, 20);
    imageButton->setBounds (3, 1, 16, 16);
    imageButton4->setBounds (3, 173, 16, 16);
    imageButton5->setBounds (3, 307, 16, 16);
    imageButton6->setBounds (3, 441, 16, 16);
    m_delayAdvancedButton->setBounds (92, 42, 52, 20);
    m_waveGainComboBox->setBounds (37, 45, 53, 16);
    component->setBounds (0, 0, getWidth() - 0, getHeight() - 0);
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void PatchToneEditor::buttonClicked (Button* buttonThatWasClicked)
{
    //[UserbuttonClicked_Pre]
    //[/UserbuttonClicked_Pre]

    if (buttonThatWasClicked == m_waveButton)
    {
        //[UserButtonCode_m_waveButton] -- add your button handler code here..
		//WaveformBrowser* waveformBrowserComponent = new WaveformBrowser();
		//ScopedPointer<DialogWindow> dw = contentComponent->findParentComponentOfClass<DialogWindow>();*/
		DialogWindow::LaunchOptions dialogLaunch;
		dialogLaunch.dialogTitle = "Select Waveform for PART " + String((int)m_part + 1) + ", TONE " + String(((int)m_tone - 0x1000)/0x200 + 1);
		WaveformBrowser* waveformBrowser = new WaveformBrowser(m_part, m_tone, waveForms->getGroupForId(m_waveGroupId->getValue()), m_waveNumber->getValue());
		WaveFormDlgCallback* callbackObject = new WaveFormDlgCallback();
		callbackObject->setWaveformSelectParameters(m_waveGroupType, m_waveGroupId, m_waveNumber);
		callbackObject->m_restorable32BitIntForWaveformDuringBrowserDialog =
			waveForms->get32BitIntForWaveform(m_waveGroupId->getValue(), m_waveNumber->getValue(), 0);
		dialogLaunch.content.set(waveformBrowser, true);
		dialogLaunch.escapeKeyTriggersCloseButton = true;
		dialogLaunch.useNativeTitleBar = true;
		dialogLaunch.resizable = false;
		DialogWindow* dw = dialogLaunch.launchAsync();
		ModalComponentManager::getInstance()->attachCallback(dw, callbackObject);
		waveformBrowser->getWaveformsAllGroupsComponent()->tryScrollToSelectedButton();
        //[/UserButtonCode_m_waveButton]
    }
    else if (buttonThatWasClicked == m_controlMatrixButton)
    {
        //[UserButtonCode_m_controlMatrixButton] -- add your button handler code here..
		PatchControllerMatrixEditor* patchControllerMatrixEditor = new PatchControllerMatrixEditor("CONTROL MATRIX", m_part, m_tone);
		CallOutBox::launchAsynchronously(patchControllerMatrixEditor, m_controlMatrixButton->getScreenBounds(), nullptr);
        //[/UserButtonCode_m_controlMatrixButton]
    }
    else if (buttonThatWasClicked == m_pitchAdvancedButton)
    {
        //[UserButtonCode_m_pitchAdvancedButton] -- add your button handler code here..
		PitchEditorAdvanced* advancedPitchEditor = new PitchEditorAdvanced("PITCH", m_part, m_tone);
		CallOutBox::launchAsynchronously(advancedPitchEditor, m_pitchAdvancedButton->getScreenBounds(), nullptr);
        //[/UserButtonCode_m_pitchAdvancedButton]
    }
    else if (buttonThatWasClicked == m_filterAdvancedButton)
    {
        //[UserButtonCode_m_filterAdvancedButton] -- add your button handler code here..
		FilterEditorAdvanced* advancedFilterEditor = new FilterEditorAdvanced("FILTER", m_part, m_tone);
		CallOutBox::launchAsynchronously(advancedFilterEditor, m_filterAdvancedButton->getScreenBounds(), nullptr);
        //[/UserButtonCode_m_filterAdvancedButton]
    }
    else if (buttonThatWasClicked == m_ampAdvancedButton)
    {
        //[UserButtonCode_m_ampAdvancedButton] -- add your button handler code here..
		AmpEditorAdvanced* advancedAmpEditor = new AmpEditorAdvanced("AMP", m_part, m_tone);
		CallOutBox::launchAsynchronously(advancedAmpEditor, m_ampAdvancedButton->getScreenBounds(), nullptr);
        //[/UserButtonCode_m_ampAdvancedButton]
    }
    else if (buttonThatWasClicked == m_fxmAdvancedButton)
    {
        //[UserButtonCode_m_fxmAdvancedButton] -- add your button handler code here..
		FxmEditor* advancedEditor = new FxmEditor("FXM", m_part, m_tone);
		CallOutBox::launchAsynchronously(advancedEditor, buttonThatWasClicked->getScreenBounds(), nullptr);
        //[/UserButtonCode_m_fxmAdvancedButton]
    }
    else if (buttonThatWasClicked == imageButton)
    {
        //[UserButtonCode_imageButton] -- add your button handler code here..
        //[/UserButtonCode_imageButton]
    }
    else if (buttonThatWasClicked == imageButton4)
    {
        //[UserButtonCode_imageButton4] -- add your button handler code here..
        //[/UserButtonCode_imageButton4]
    }
    else if (buttonThatWasClicked == imageButton5)
    {
        //[UserButtonCode_imageButton5] -- add your button handler code here..
        //[/UserButtonCode_imageButton5]
    }
    else if (buttonThatWasClicked == imageButton6)
    {
        //[UserButtonCode_imageButton6] -- add your button handler code here..
        //[/UserButtonCode_imageButton6]
    }
    else if (buttonThatWasClicked == m_delayAdvancedButton)
    {
        //[UserButtonCode_m_delayAdvancedButton] -- add your button handler code here..
		ToneDelayEditor* advancedEditor = new ToneDelayEditor("DELAY", m_part, m_tone);
		CallOutBox::launchAsynchronously(advancedEditor, buttonThatWasClicked->getScreenBounds(), nullptr);
        //[/UserButtonCode_m_delayAdvancedButton]
    }

    //[UserbuttonClicked_Post]
    //[/UserbuttonClicked_Post]
}

void PatchToneEditor::sliderValueChanged (Slider* sliderThatWasMoved)
{
    //[UsersliderValueChanged_Pre]
    //[/UsersliderValueChanged_Pre]

    if (sliderThatWasMoved == m_coarseTuneSlider)
    {
        //[UserSliderCode_m_coarseTuneSlider] -- add your slider handling code here..
        //[/UserSliderCode_m_coarseTuneSlider]
    }
    else if (sliderThatWasMoved == m_fineTuneSlider)
    {
        //[UserSliderCode_m_fineTuneSlider] -- add your slider handling code here..
        //[/UserSliderCode_m_fineTuneSlider]
    }
    else if (sliderThatWasMoved == m_pitchEnvelopeDepthSlider)
    {
        //[UserSliderCode_m_pitchEnvelopeDepthSlider] -- add your slider handling code here..
        //[/UserSliderCode_m_pitchEnvelopeDepthSlider]
    }
    else if (sliderThatWasMoved == m_filterEnvelopeDepthSlider)
    {
        //[UserSliderCode_m_filterEnvelopeDepthSlider] -- add your slider handling code here..
        //[/UserSliderCode_m_filterEnvelopeDepthSlider]
    }
    else if (sliderThatWasMoved == m_cutoffSlider)
    {
        //[UserSliderCode_m_cutoffSlider] -- add your slider handling code here..
        //[/UserSliderCode_m_cutoffSlider]
    }
    else if (sliderThatWasMoved == m_resonanceSlider)
    {
        //[UserSliderCode_m_resonanceSlider] -- add your slider handling code here..
        //[/UserSliderCode_m_resonanceSlider]
    }
    else if (sliderThatWasMoved == m_toneLevelSlider)
    {
        //[UserSliderCode_m_toneLevelSlider] -- add your slider handling code here..
        //[/UserSliderCode_m_toneLevelSlider]
    }
    else if (sliderThatWasMoved == m_tonePanSlider)
    {
        //[UserSliderCode_m_tonePanSlider] -- add your slider handling code here..
        //[/UserSliderCode_m_tonePanSlider]
    }

    //[UsersliderValueChanged_Post]
    //[/UsersliderValueChanged_Post]
}

void PatchToneEditor::comboBoxChanged (ComboBox* comboBoxThatHasChanged)
{
    //[UsercomboBoxChanged_Pre]
    //[/UsercomboBoxChanged_Pre]

    if (comboBoxThatHasChanged == m_filterTypeComboBox)
    {
        //[UserComboBoxCode_m_filterTypeComboBox] -- add your combo box handling code here..
        //[/UserComboBoxCode_m_filterTypeComboBox]
    }
    else if (comboBoxThatHasChanged == m_waveGainComboBox)
    {
        //[UserComboBoxCode_m_waveGainComboBox] -- add your combo box handling code here..
        //[/UserComboBoxCode_m_waveGainComboBox]
    }

    //[UsercomboBoxChanged_Post]
    //[/UsercomboBoxChanged_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
void PatchToneEditor::WaveFormDlgCallback::modalStateFinished(int returnValue)
{
	uint8 groupType;
	uint8 groupId;
	uint8 waveIndexInGroup;
	if (returnValue == 0)	/* no valid group may result in value 0, so this indicates  a dialog abortian */
	{
		// restore old value:
		waveForms->getGroupAndIndexFrom32BitInt(m_restorable32BitIntForWaveformDuringBrowserDialog, groupType, groupId, waveIndexInGroup);
		this->m_groupType->setValue(groupType, Parameter::GuiWidget);
		this->m_groupId->setValue(groupId, Parameter::GuiWidget);
		this->m_waveIndexInGroup->setValue(waveIndexInGroup, Parameter::GuiWidget);
	}
	else /* reconstruct selection from return value of the dialog */
	{

	}
}

// parameter changes of groovebox memory block
void PatchToneEditor::changeListenerCallback(ChangeBroadcaster *source)
{
	if (Parameter* param = dynamic_cast<Parameter*>(source))
	{
		// if one of the parameters changed
		if (param == m_waveGroupType || param == m_waveGroupId ||param == m_waveNumber)
		{
			m_waveButton->setButtonText(waveForms->getButtonText(
				waveForms->getGroupForId(m_waveGroupId->getValue()),
				m_waveNumber->getValue()));
		}
	}
}

//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Introjucer information section --

    This is where the Introjucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="PatchToneEditor" componentName=""
                 parentClasses="public Component, public ChangeListener" constructorParams="SynthParts part, Tone tone"
                 variableInitialisers="m_part (part),&#10;m_tone (tone)" snapPixels="4"
                 snapActive="1" snapShown="1" overlayOpacity="0.330" fixedSize="1"
                 initialWidth="304" initialHeight="572">
  <BACKGROUND backgroundColour="0"/>
  <JUCERCOMP name="ampGrp" id="5cd694ce73de64a1" memberName="m_ampGrp" virtualName=""
             explicitFocusOrder="0" pos="0 440 304 132" sourceFile="../GroupWidgets/PanelGroupGrey.cpp"
             constructorParams="&quot;AmpGrp&quot;,&quot;AMP OF TONE &quot;+String(((int)m_tone - 0x1000)/0x200 + 1)"/>
  <JUCERCOMP name="filterGrp" id="f4657682b52d89a6" memberName="m_filterGrp"
             virtualName="" explicitFocusOrder="0" pos="0 306 304 132" sourceFile="../GroupWidgets/PanelGroupGrey.cpp"
             constructorParams="&quot;FilterGrp&quot;,&quot;FILTER OF TONE &quot;+String(((int)m_tone - 0x1000)/0x200 + 1)"/>
  <JUCERCOMP name="filterEnv" id="bca85c8be5cf169c" memberName="m_filterEnv"
             virtualName="" explicitFocusOrder="0" pos="4 367 296 72" sourceFile="Envelope.cpp"
             constructorParams="m_part, m_tone, EnvelopeTypes::Filter, true"/>
  <JUCERCOMP name="pitchGrp" id="e06439a01507ceb3" memberName="m_pitchGrp"
             virtualName="" explicitFocusOrder="0" pos="0 172 304 132" sourceFile="../GroupWidgets/PanelGroupGrey.cpp"
             constructorParams="&quot;PitchGrp&quot;,&quot;PITCH OF TONE &quot;+String(((int)m_tone - 0x1000)/0x200 + 1)"/>
  <JUCERCOMP name="waveGrp" id="7b720d409c5094e7" memberName="m_waveGrp" virtualName=""
             explicitFocusOrder="0" pos="0 0 304 68" sourceFile="../GroupWidgets/PanelGroupGrey.cpp"
             constructorParams="&quot;WAVEGrp&quot;,&quot;TONE &quot;+String(((int)m_tone - 0x1000)/0x200 + 1)"/>
  <JUCERCOMP name="pitchEnv" id="99a40d72d7ad1e22" memberName="m_pitchEnv"
             virtualName="" explicitFocusOrder="0" pos="4 229 296 72" sourceFile="Envelope.cpp"
             constructorParams="m_part, m_tone, EnvelopeTypes::Pitch, true"/>
  <JUCERCOMP name="ampEnv" id="f84b427a83f125de" memberName="m_ampEnv" virtualName=""
             explicitFocusOrder="0" pos="4 500 296 72" sourceFile="Envelope.cpp"
             constructorParams="m_part, m_tone, EnvelopeTypes::Amp, true"/>
  <JUCERCOMP name="onToggle" id="b0e7322ed6fe4133" memberName="m_onToggle"
             virtualName="" explicitFocusOrder="0" pos="39 20 25 17" sourceFile="../ParameterWidgets/BlackToggle.cpp"
             constructorParams=""/>
  <LABEL name="onLabel" id="a5103dfa4b0cded3" memberName="m_onLabel" virtualName=""
         explicitFocusOrder="0" pos="-3 16 42 24" textCol="ff000000" edTextCol="ff000000"
         edBkgCol="0" labelText="ON" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="12"
         bold="1" italic="0" justification="34"/>
  <TEXTBUTTON name="new button" id="603fab9f912b12cf" memberName="m_waveButton"
              virtualName="" explicitFocusOrder="0" pos="152 17 148 21" buttonText="A:001 Dist TB 303a"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <LABEL name="waveLabel" id="77636cfe920d8c67" memberName="m_waveLabel"
         virtualName="" explicitFocusOrder="0" pos="78 16 76 24" textCol="ff000000"
         edTextCol="ff000000" edBkgCol="0" labelText="WAVEFORM" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="12" bold="1" italic="0" justification="34"/>
  <LABEL name="onLabel" id="622e567326097c53" memberName="m_onLabel2"
         virtualName="" explicitFocusOrder="0" pos="-3 41 42 24" textCol="ff000000"
         edTextCol="ff000000" edBkgCol="0" labelText="GAIN" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="12" bold="1" italic="0" justification="34"/>
  <JUCERCOMP name="lfo1" id="4d93a41b01a9732c" memberName="m_lfo1" virtualName=""
             explicitFocusOrder="0" pos="0 70 151 100" sourceFile="LfoEditor.cpp"
             constructorParams="&quot;LFO 1 OF TONE &quot;+String(((int)m_tone - 0x1000)/0x200 + 1),m_part, m_tone, false"/>
  <JUCERCOMP name="lfo2" id="f5e6a5a006cad326" memberName="m_lfo2" virtualName=""
             explicitFocusOrder="0" pos="153 70 151 100" sourceFile="LfoEditor.cpp"
             constructorParams="&quot;LFO 2 OF TONE &quot;+String(((int)m_tone - 0x1000)/0x200 + 1),m_part, m_tone, true"/>
  <TEXTBUTTON name="controlMatrixButton" id="9de90d61ee7dcce4" memberName="m_controlMatrixButton"
              virtualName="TextWithArrowButton" explicitFocusOrder="0" pos="200 42 100 20"
              buttonText="CTRL MATRIX" connectedEdges="0" needsCallback="1"
              radioGroupId="0"/>
  <SLIDER name="coarseTuneSlider" id="b0244231d82dbdee" memberName="m_coarseTuneSlider"
          virtualName="MicroParameterSlider" explicitFocusOrder="0" pos="96 190 56 16"
          bkgcol="fff2f59b" thumbcol="ffc4c86d" min="0" max="127" int="1"
          style="LinearBar" textBoxPos="TextBoxLeft" textBoxEditable="1"
          textBoxWidth="40" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="fineTuneSlider" id="52c02090b7a2d314" memberName="m_fineTuneSlider"
          virtualName="MicroParameterSlider" explicitFocusOrder="0" pos="96 212 56 16"
          bkgcol="fff2f59b" thumbcol="ffc4c86d" min="0" max="127" int="1"
          style="LinearBar" textBoxPos="TextBoxLeft" textBoxEditable="1"
          textBoxWidth="40" textBoxHeight="20" skewFactor="1"/>
  <LABEL name="coarseTuneLabel" id="ed6131200c17df7c" memberName="m_coarseTuneLabel"
         virtualName="" explicitFocusOrder="0" pos="0 190 96 16" textCol="ff000000"
         edTextCol="ff000000" edBkgCol="0" labelText="COARSE TUNE" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="12" bold="1" italic="0" justification="34"/>
  <LABEL name="fineTuneLabel" id="c3150875d029f68b" memberName="m_fineTuneLabel"
         virtualName="" explicitFocusOrder="0" pos="0 212 96 16" textCol="ff000000"
         edTextCol="ff000000" edBkgCol="0" labelText="FINE TUNE" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="12" bold="1" italic="0" justification="34"/>
  <SLIDER name="pitchEnvelopeDepthSlider" id="b0bd5a61181f569c" memberName="m_pitchEnvelopeDepthSlider"
          virtualName="MicroParameterSlider" explicitFocusOrder="0" pos="240 212 56 16"
          bkgcol="fff2f59b" thumbcol="ffc4c86d" min="0" max="127" int="1"
          style="LinearBar" textBoxPos="TextBoxLeft" textBoxEditable="1"
          textBoxWidth="40" textBoxHeight="20" skewFactor="1"/>
  <LABEL name="pitchEnvelopeDepthLabel" id="611da7e96f52143f" memberName="m_pitchEnvelopeDepthLabel"
         virtualName="" explicitFocusOrder="0" pos="144 212 96 16" textCol="ff000000"
         edTextCol="ff000000" edBkgCol="0" labelText="ENV DEPTH" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="12" bold="1" italic="0" justification="34"/>
  <TEXTBUTTON name="new button" id="416784e642241f6e" memberName="m_pitchAdvancedButton"
              virtualName="TextWithArrowButton" explicitFocusOrder="0" pos="164 189 132 20"
              buttonText="PITCH" connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <SLIDER name="filterEnvelopeDepthSlider" id="d9573a373dc1a224" memberName="m_filterEnvelopeDepthSlider"
          virtualName="MicroParameterSlider" explicitFocusOrder="0" pos="240 347 56 16"
          bkgcol="fff2f59b" thumbcol="ffc4c86d" min="0" max="127" int="1"
          style="LinearBar" textBoxPos="TextBoxLeft" textBoxEditable="1"
          textBoxWidth="40" textBoxHeight="20" skewFactor="1"/>
  <LABEL name="filterEnvelopeDepthLabel" id="a649716dd8172873" memberName="m_filterEnvelopeDepthLabel"
         virtualName="" explicitFocusOrder="0" pos="144 347 96 16" textCol="ff000000"
         edTextCol="ff000000" edBkgCol="0" labelText="ENV DEPTH" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="12" bold="1" italic="0" justification="34"/>
  <TEXTBUTTON name="filterAdvancedButton" id="68d1dfc7d27d182c" memberName="m_filterAdvancedButton"
              virtualName="TextWithArrowButton" explicitFocusOrder="0" pos="164 323 132 20"
              buttonText="FILTER" connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <SLIDER name="cutoffSlider" id="fc593d588328765b" memberName="m_cutoffSlider"
          virtualName="MicroParameterSlider" explicitFocusOrder="0" pos="36 324 56 16"
          bkgcol="fff2f59b" thumbcol="ffc4c86d" textboxbkgd="fff2f59b"
          min="0" max="127" int="1" style="LinearBar" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="16" skewFactor="1"/>
  <LABEL name="cutoffLabel" id="20fe441308e3e8" memberName="m_cutoffLabel"
         virtualName="" explicitFocusOrder="0" pos="4 324 32 16" textCol="ff000000"
         edTextCol="ff000000" edBkgCol="0" labelText="CUT" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="12" bold="1" italic="0" justification="34"/>
  <LABEL name="resonanceLabel" id="d9f54752325a33e6" memberName="m_resonanceLabel"
         virtualName="" explicitFocusOrder="0" pos="4 346 32 16" textCol="ff000000"
         edTextCol="ff000000" edBkgCol="0" labelText="RES" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="12" bold="1" italic="0" justification="34"/>
  <LABEL name="filterTypeLabel" id="f3d39bda614b956b" memberName="m_filterTypeLabel"
         virtualName="" explicitFocusOrder="0" pos="104 330 48 16" textCol="ff000000"
         edTextCol="ff000000" edBkgCol="0" labelText="TYPE" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="12" bold="1" italic="0" justification="36"/>
  <COMBOBOX name="filterTypeComboBox" id="16b5a2469dc361b5" memberName="m_filterTypeComboBox"
            virtualName="ParameterComboBox" explicitFocusOrder="0" pos="100 346 55 16"
            editable="0" layout="36" items="OFF&#10;LPF&#10;BPF&#10;HPF&#10;PKG"
            textWhenNonSelected="OFF" textWhenNoItems="(no choices)"/>
  <SLIDER name="resonanceSlider" id="e1e6b4420e5c8786" memberName="m_resonanceSlider"
          virtualName="MicroParameterSlider" explicitFocusOrder="0" pos="36 346 56 16"
          bkgcol="fff2f59b" thumbcol="ffc4c86d" textboxbkgd="fff2f59b"
          min="0" max="127" int="1" style="LinearBar" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="16" skewFactor="1"/>
  <TEXTBUTTON name="ampAdvancedButton" id="fd7257a8573b0e09" memberName="m_ampAdvancedButton"
              virtualName="TextWithArrowButton" explicitFocusOrder="0" pos="164 458 132 20"
              buttonText="AMP" connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <SLIDER name="toneLevelSlider" id="1b5918ef3651954f" memberName="m_toneLevelSlider"
          virtualName="MixPartLevelFader" explicitFocusOrder="0" pos="88c 501r 168 36"
          min="0" max="127" int="1" style="LinearHorizontal" textBoxPos="TextBoxAbove"
          textBoxEditable="1" textBoxWidth="32" textBoxHeight="16" skewFactor="1"/>
  <LABEL name="toneLevelLabel" id="ce668ccdb69ca30f" memberName="m_toneLevelLabel"
         virtualName="" explicitFocusOrder="0" pos="-2 465 78 16" textCol="ff000000"
         edTextCol="ff000000" edBkgCol="0" labelText="TONE LEVEL" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="12" bold="1" italic="0" justification="33"/>
  <SLIDER name="cutoffSlider" id="4df3f2f966561253" memberName="m_tonePanSlider"
          virtualName="MicroParameterSlider" explicitFocusOrder="0" pos="240 482 56 16"
          bkgcol="fff2f59b" thumbcol="ffc4c86d" textboxbkgd="fff2f59b"
          min="0" max="127" int="1" style="LinearBar" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="16" skewFactor="1"/>
  <LABEL name="tonePanLabel" id="12ba028114e62b81" memberName="m_tonePanLabel"
         virtualName="" explicitFocusOrder="0" pos="208 482 32 16" textCol="ff000000"
         edTextCol="ff000000" edBkgCol="0" labelText="PAN" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="12" bold="1" italic="0" justification="34"/>
  <TEXTBUTTON name="fxmAdvancedButton" id="a7b9c75aeeedbe31" memberName="m_fxmAdvancedButton"
              virtualName="TextWithArrowButton" explicitFocusOrder="0" pos="146 42 52 20"
              buttonText="FXM" connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <IMAGEBUTTON name="new button" id="b10a65e5bda82a98" memberName="imageButton"
               virtualName="" explicitFocusOrder="0" pos="3 1 16 16" buttonText=""
               connectedEdges="0" needsCallback="1" radioGroupId="0" keepProportions="1"
               resourceNormal="wave_png" opacityNormal="1" colourNormal="4340454a"
               resourceOver="" opacityOver="1" colourOver="4340454a" resourceDown=""
               opacityDown="1" colourDown="4340454a"/>
  <IMAGEBUTTON name="new button" id="30e4397d1310ce84" memberName="imageButton4"
               virtualName="" explicitFocusOrder="0" pos="3 173 16 16" buttonText=""
               connectedEdges="0" needsCallback="1" radioGroupId="0" keepProportions="1"
               resourceNormal="pitch_png" opacityNormal="1" colourNormal="4340454a"
               resourceOver="" opacityOver="1" colourOver="4340454a" resourceDown=""
               opacityDown="1" colourDown="4340454a"/>
  <IMAGEBUTTON name="new button" id="b04da16dfec795ff" memberName="imageButton5"
               virtualName="" explicitFocusOrder="0" pos="3 307 16 16" buttonText=""
               connectedEdges="0" needsCallback="1" radioGroupId="0" keepProportions="1"
               resourceNormal="filter_png" opacityNormal="1" colourNormal="4340454a"
               resourceOver="" opacityOver="1" colourOver="4340454a" resourceDown=""
               opacityDown="1" colourDown="4340454a"/>
  <IMAGEBUTTON name="new button" id="62c48d1e24516781" memberName="imageButton6"
               virtualName="" explicitFocusOrder="0" pos="3 441 16 16" buttonText=""
               connectedEdges="0" needsCallback="1" radioGroupId="0" keepProportions="1"
               resourceNormal="amp_png" opacityNormal="1" colourNormal="4340454a"
               resourceOver="amp_png" opacityOver="1" colourOver="4340454a"
               resourceDown="amp_png" opacityDown="1" colourDown="4340454a"/>
  <TEXTBUTTON name="delayAdvancedButton" id="ab29df879b44cb69" memberName="m_delayAdvancedButton"
              virtualName="TextWithArrowButton" explicitFocusOrder="0" pos="92 42 52 20"
              buttonText="DLY" connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <COMBOBOX name="waveGainComboBox" id="1615d6307f31d1e" memberName="m_waveGainComboBox"
            virtualName="ParameterComboBox" explicitFocusOrder="0" pos="37 45 53 16"
            editable="0" layout="34" items="-6dB&#10;0dB&#10;+6dB&#10;+12dB"
            textWhenNonSelected="-6dB" textWhenNoItems="(no choices)"/>
  <JUCERCOMP name="" id="9ebb028778fef461" memberName="component" virtualName=""
             explicitFocusOrder="0" pos="0 0 0M 0M" sourceFile="../GroupWidgets/RectangleTransp.cpp"
             constructorParams=""/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif

//==============================================================================
// Binary resources - be careful not to edit any of these sections!

// JUCER_RESOURCE: wave_png, 229, "../../../Resources/PatchEditSectionIcons/wave.png"
static const unsigned char resource_PatchToneEditor_wave_png[] = { 137,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,0,16,0,0,0,16,8,6,0,0,0,31,243,255,97,0,0,0,1,115,82,71,66,0,174,206,28,233,0,0,0,6,
98,75,71,68,0,255,0,255,0,255,160,189,167,147,0,0,0,9,112,72,89,115,0,0,11,19,0,0,11,19,1,0,154,156,24,0,0,0,7,116,73,77,69,7,222,12,10,20,18,21,64,171,69,14,0,0,0,101,73,68,65,84,56,203,173,147,73,14,
192,48,8,3,49,234,255,191,60,189,164,82,211,146,149,248,134,144,141,17,70,86,0,96,11,144,36,219,37,87,156,22,121,70,20,192,45,9,95,157,218,21,24,238,27,12,57,183,2,128,36,81,208,115,242,238,95,189,27,
71,214,159,33,63,7,85,48,2,177,86,223,151,83,247,169,125,59,190,51,2,45,219,71,207,152,126,38,101,223,249,6,29,4,79,251,253,70,38,152,0,0,0,0,73,69,78,68,174,66,96,130,0,0};

const char* PatchToneEditor::wave_png = (const char*) resource_PatchToneEditor_wave_png;
const int PatchToneEditor::wave_pngSize = 229;

// JUCER_RESOURCE: pitch_png, 225, "../../../Resources/PatchEditSectionIcons/pitch.png"
static const unsigned char resource_PatchToneEditor_pitch_png[] = { 137,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,0,16,0,0,0,16,8,6,0,0,0,31,243,255,97,0,0,0,1,115,82,71,66,0,174,206,28,233,0,0,0,
6,98,75,71,68,0,255,0,255,0,255,160,189,167,147,0,0,0,9,112,72,89,115,0,0,11,19,0,0,11,19,1,0,154,156,24,0,0,0,7,116,73,77,69,7,222,12,10,20,19,38,230,96,21,89,0,0,0,97,73,68,65,84,56,203,165,147,75,14,
0,33,8,67,41,153,251,95,185,110,152,68,141,40,159,110,205,171,80,0,98,34,73,73,8,0,164,10,47,204,11,166,201,123,211,23,188,148,122,144,70,74,189,153,104,42,172,140,65,52,88,173,246,238,26,236,240,109,
10,161,22,96,242,76,180,26,222,175,239,4,206,191,205,149,164,211,142,108,105,123,140,237,99,66,247,156,7,144,160,99,229,152,124,254,63,0,0,0,0,73,69,78,68,174,66,96,130,0,0};

const char* PatchToneEditor::pitch_png = (const char*) resource_PatchToneEditor_pitch_png;
const int PatchToneEditor::pitch_pngSize = 225;

// JUCER_RESOURCE: filter_png, 216, "../../../Resources/PatchEditSectionIcons/filter.png"
static const unsigned char resource_PatchToneEditor_filter_png[] = { 137,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,0,16,0,0,0,16,8,6,0,0,0,31,243,255,97,0,0,0,1,115,82,71,66,0,174,206,28,233,0,0,0,
6,98,75,71,68,0,255,0,255,0,255,160,189,167,147,0,0,0,9,112,72,89,115,0,0,11,19,0,0,11,19,1,0,154,156,24,0,0,0,7,116,73,77,69,7,222,12,10,20,17,41,68,233,106,74,0,0,0,88,73,68,65,84,56,203,205,147,59,
14,0,32,8,67,121,198,251,95,25,23,7,52,198,240,113,144,145,208,166,180,41,50,71,85,85,2,3,32,89,240,130,201,128,45,73,247,170,88,36,31,165,120,37,111,187,230,5,3,156,72,90,216,241,12,193,245,205,104,10,
246,62,228,65,233,133,167,30,236,105,124,144,66,181,76,84,235,60,0,71,153,87,223,168,164,70,56,0,0,0,0,73,69,78,68,174,66,96,130,0,0};

const char* PatchToneEditor::filter_png = (const char*) resource_PatchToneEditor_filter_png;
const int PatchToneEditor::filter_pngSize = 216;

// JUCER_RESOURCE: amp_png, 238, "../../../Resources/PatchEditSectionIcons/amp.png"
static const unsigned char resource_PatchToneEditor_amp_png[] = { 137,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,0,16,0,0,0,16,8,6,0,0,0,31,243,255,97,0,0,0,1,115,82,71,66,0,174,206,28,233,0,0,0,6,
98,75,71,68,0,255,0,255,0,255,160,189,167,147,0,0,0,9,112,72,89,115,0,0,11,19,0,0,11,19,1,0,154,156,24,0,0,0,7,116,73,77,69,7,222,12,10,20,17,54,201,225,103,191,0,0,0,110,73,68,65,84,56,203,165,83,209,
18,192,48,4,195,249,255,95,182,151,185,51,19,166,203,75,175,218,68,84,49,221,48,51,163,5,152,153,233,148,252,224,76,100,11,168,206,100,101,181,128,160,140,113,223,137,40,202,234,34,78,70,34,50,217,71,
245,183,14,162,109,95,179,163,177,4,20,203,66,90,246,182,233,59,116,224,182,179,8,34,190,4,242,133,137,248,249,17,39,232,246,231,245,131,113,192,225,191,227,124,1,168,181,108,17,98,157,50,130,0,0,0,0,
73,69,78,68,174,66,96,130,0,0};

const char* PatchToneEditor::amp_png = (const char*) resource_PatchToneEditor_amp_png;
const int PatchToneEditor::amp_pngSize = 238;


//[EndFile] You can add extra defines here...
//[/EndFile]
