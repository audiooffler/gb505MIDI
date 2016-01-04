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
#include "../../GrooveboxMemory/Waveforms.h"
#include "../WaveformBrowser.h"
//[/Headers]

#include "PatchToneEditor.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
extern OverallMemoryBlock* grooveboxMemory;
extern Waveforms* waveForms;
//[/MiscUserDefs]

//==============================================================================
PatchToneEditor::PatchToneEditor (const String& labelText, SynthParts part, Tone tone)
    : m_part (part),
      m_tone (tone)
{
    addAndMakeVisible (m_toneGrp = new PanelGroupGrey ("toneGrp","TONE"));
    addAndMakeVisible (m_pitchEnv = new Envelope ("Pitch Envelope",-63,63,false));
    addAndMakeVisible (m_filterEnv = new Envelope ("Filter Envelope",0,127,false));
    addAndMakeVisible (m_ampEnv = new Envelope ("Amlitude Envelope",0,127,true));
    addAndMakeVisible (m_onToggle = new BlackToggle());
    addAndMakeVisible (m_onLabel = new Label ("onLabel",
                                              "On:"));
    m_onLabel->setFont (Font (13.00f, Font::plain));
    m_onLabel->setJustificationType (Justification::centredLeft);
    m_onLabel->setEditable (false, false, false);
    m_onLabel->setColour (Label::textColourId, Colours::black);
    m_onLabel->setColour (TextEditor::textColourId, Colours::black);
    m_onLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_waveButton = new TextButton ("new button"));
    m_waveButton->setButtonText ("A:001 Dist TB 303a");
    m_waveButton->addListener (this);

    addAndMakeVisible (m_waveLabel = new Label ("waveLabel",
                                                "Waveform:"));
    m_waveLabel->setFont (Font (13.00f, Font::plain));
    m_waveLabel->setJustificationType (Justification::centredRight);
    m_waveLabel->setEditable (false, false, false);
    m_waveLabel->setColour (Label::textColourId, Colours::black);
    m_waveLabel->setColour (TextEditor::textColourId, Colours::black);
    m_waveLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_fxmGrp = new PanelGroupGrey ("FXMGrp","FXM"));
    addAndMakeVisible (m_fxmToggle = new BlackToggle());
    addAndMakeVisible (m_fxmOnLabel = new Label ("fxmOnLabel",
                                                 "On:"));
    m_fxmOnLabel->setFont (Font (13.00f, Font::plain));
    m_fxmOnLabel->setJustificationType (Justification::centredLeft);
    m_fxmOnLabel->setEditable (false, false, false);
    m_fxmOnLabel->setColour (Label::textColourId, Colours::black);
    m_fxmOnLabel->setColour (TextEditor::textColourId, Colours::black);
    m_fxmOnLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_fxmColorSlider = new MicroParameterSlider ("fxmColorSlider"));
    m_fxmColorSlider->setRange (0, 127, 1);
    m_fxmColorSlider->setSliderStyle (Slider::LinearBar);
    m_fxmColorSlider->setTextBoxStyle (Slider::TextBoxLeft, false, 40, 20);
    m_fxmColorSlider->setColour (Slider::backgroundColourId, Colour (0xfff2f59b));
    m_fxmColorSlider->setColour (Slider::thumbColourId, Colour (0xffc4c86d));
    m_fxmColorSlider->addListener (this);

    addAndMakeVisible (m_fxmColorLabel = new Label ("fxmColorLabel",
                                                    "Color:"));
    m_fxmColorLabel->setFont (Font (13.00f, Font::plain));
    m_fxmColorLabel->setJustificationType (Justification::centredLeft);
    m_fxmColorLabel->setEditable (false, false, false);
    m_fxmColorLabel->setColour (Label::textColourId, Colours::black);
    m_fxmColorLabel->setColour (TextEditor::textColourId, Colours::black);
    m_fxmColorLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_fxmDepthSlider = new MicroParameterSlider ("fxmDepthSlider"));
    m_fxmDepthSlider->setRange (0, 127, 1);
    m_fxmDepthSlider->setSliderStyle (Slider::LinearBar);
    m_fxmDepthSlider->setTextBoxStyle (Slider::TextBoxLeft, false, 40, 20);
    m_fxmDepthSlider->setColour (Slider::backgroundColourId, Colour (0xfff2f59b));
    m_fxmDepthSlider->setColour (Slider::thumbColourId, Colour (0xffc4c86d));
    m_fxmDepthSlider->addListener (this);

    addAndMakeVisible (m_fxmDepthLabel = new Label ("fxmDepthLabel",
                                                    "Depth:"));
    m_fxmDepthLabel->setFont (Font (13.00f, Font::plain));
    m_fxmDepthLabel->setJustificationType (Justification::centredLeft);
    m_fxmDepthLabel->setEditable (false, false, false);
    m_fxmDepthLabel->setColour (Label::textColourId, Colours::black);
    m_fxmDepthLabel->setColour (TextEditor::textColourId, Colours::black);
    m_fxmDepthLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_controllersGrp = new PanelGroupGrey ("ControllersGrp","CONTROLLERS"));
    addAndMakeVisible (m_modulationLabel = new Label ("modulationLabel",
                                                      "MODULATION"));
    m_modulationLabel->setFont (Font (13.00f, Font::plain));
    m_modulationLabel->setJustificationType (Justification::centred);
    m_modulationLabel->setEditable (false, false, false);
    m_modulationLabel->setColour (Label::textColourId, Colours::black);
    m_modulationLabel->setColour (TextEditor::textColourId, Colours::black);
    m_modulationLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_modDestComboBox1 = new ParameterComboBox ("modDestComboBox"));
    m_modDestComboBox1->setEditableText (false);
    m_modDestComboBox1->setJustificationType (Justification::centredLeft);
    m_modDestComboBox1->setTextWhenNothingSelected (String::empty);
    m_modDestComboBox1->setTextWhenNoChoicesAvailable ("(no choices)");
    m_modDestComboBox1->addListener (this);

    addAndMakeVisible (m_modDestComboBox2 = new ParameterComboBox ("modDestComboBox"));
    m_modDestComboBox2->setEditableText (false);
    m_modDestComboBox2->setJustificationType (Justification::centredLeft);
    m_modDestComboBox2->setTextWhenNothingSelected (String::empty);
    m_modDestComboBox2->setTextWhenNoChoicesAvailable ("(no choices)");
    m_modDestComboBox2->addListener (this);

    addAndMakeVisible (m_modDestComboBox3 = new ParameterComboBox ("modDestComboBox"));
    m_modDestComboBox3->setEditableText (false);
    m_modDestComboBox3->setJustificationType (Justification::centredLeft);
    m_modDestComboBox3->setTextWhenNothingSelected (String::empty);
    m_modDestComboBox3->setTextWhenNoChoicesAvailable ("(no choices)");
    m_modDestComboBox3->addListener (this);

    addAndMakeVisible (m_modDestComboBox4 = new ParameterComboBox ("modDestComboBox"));
    m_modDestComboBox4->setEditableText (false);
    m_modDestComboBox4->setJustificationType (Justification::centredLeft);
    m_modDestComboBox4->setTextWhenNothingSelected (String::empty);
    m_modDestComboBox4->setTextWhenNoChoicesAvailable ("(no choices)");
    m_modDestComboBox4->addListener (this);

    addAndMakeVisible (m_pitchbendLabel = new Label ("pitchbendLabel",
                                                     "PITCH BEND"));
    m_pitchbendLabel->setFont (Font (13.00f, Font::plain));
    m_pitchbendLabel->setJustificationType (Justification::centred);
    m_pitchbendLabel->setEditable (false, false, false);
    m_pitchbendLabel->setColour (Label::textColourId, Colours::black);
    m_pitchbendLabel->setColour (TextEditor::textColourId, Colours::black);
    m_pitchbendLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_aftertouchLabel = new Label ("aftertouchLabel",
                                                      "AFTERTOUCH"));
    m_aftertouchLabel->setFont (Font (13.00f, Font::plain));
    m_aftertouchLabel->setJustificationType (Justification::centred);
    m_aftertouchLabel->setEditable (false, false, false);
    m_aftertouchLabel->setColour (Label::textColourId, Colours::black);
    m_aftertouchLabel->setColour (TextEditor::textColourId, Colours::black);
    m_aftertouchLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_modDestSlider1 = new MicroParameterSlider ("modDestSlider"));
    m_modDestSlider1->setRange (0, 127, 1);
    m_modDestSlider1->setSliderStyle (Slider::LinearBar);
    m_modDestSlider1->setTextBoxStyle (Slider::TextBoxLeft, false, 40, 20);
    m_modDestSlider1->setColour (Slider::backgroundColourId, Colour (0xfff2f59b));
    m_modDestSlider1->setColour (Slider::thumbColourId, Colour (0xffc4c86d));
    m_modDestSlider1->addListener (this);

    addAndMakeVisible (m_modDestSlider2 = new MicroParameterSlider ("modDestSlider"));
    m_modDestSlider2->setRange (0, 127, 1);
    m_modDestSlider2->setSliderStyle (Slider::LinearBar);
    m_modDestSlider2->setTextBoxStyle (Slider::TextBoxLeft, false, 40, 20);
    m_modDestSlider2->setColour (Slider::backgroundColourId, Colour (0xfff2f59b));
    m_modDestSlider2->setColour (Slider::thumbColourId, Colour (0xffc4c86d));
    m_modDestSlider2->addListener (this);

    addAndMakeVisible (m_modDestSlider3 = new MicroParameterSlider ("modDestSlider"));
    m_modDestSlider3->setRange (0, 127, 1);
    m_modDestSlider3->setSliderStyle (Slider::LinearBar);
    m_modDestSlider3->setTextBoxStyle (Slider::TextBoxLeft, false, 40, 20);
    m_modDestSlider3->setColour (Slider::backgroundColourId, Colour (0xfff2f59b));
    m_modDestSlider3->setColour (Slider::thumbColourId, Colour (0xffc4c86d));
    m_modDestSlider3->addListener (this);

    addAndMakeVisible (m_modDestSlider4 = new MicroParameterSlider ("modDestSlider"));
    m_modDestSlider4->setRange (0, 127, 1);
    m_modDestSlider4->setSliderStyle (Slider::LinearBar);
    m_modDestSlider4->setTextBoxStyle (Slider::TextBoxLeft, false, 40, 20);
    m_modDestSlider4->setColour (Slider::backgroundColourId, Colour (0xfff2f59b));
    m_modDestSlider4->setColour (Slider::thumbColourId, Colour (0xffc4c86d));
    m_modDestSlider4->addListener (this);

    addAndMakeVisible (m_pitchbendDestComboBox1 = new ParameterComboBox ("pitchbendDestComboBox"));
    m_pitchbendDestComboBox1->setEditableText (false);
    m_pitchbendDestComboBox1->setJustificationType (Justification::centredLeft);
    m_pitchbendDestComboBox1->setTextWhenNothingSelected (String::empty);
    m_pitchbendDestComboBox1->setTextWhenNoChoicesAvailable ("(no choices)");
    m_pitchbendDestComboBox1->addListener (this);

    addAndMakeVisible (m_pitchbendDestSlider1 = new MicroParameterSlider ("pitchbendDestSlider"));
    m_pitchbendDestSlider1->setRange (0, 127, 1);
    m_pitchbendDestSlider1->setSliderStyle (Slider::LinearBar);
    m_pitchbendDestSlider1->setTextBoxStyle (Slider::TextBoxLeft, false, 40, 20);
    m_pitchbendDestSlider1->setColour (Slider::backgroundColourId, Colour (0xfff2f59b));
    m_pitchbendDestSlider1->setColour (Slider::thumbColourId, Colour (0xffc4c86d));
    m_pitchbendDestSlider1->addListener (this);

    addAndMakeVisible (m_pitchbendDestComboBox2 = new ParameterComboBox ("pitchbendDestComboBox"));
    m_pitchbendDestComboBox2->setEditableText (false);
    m_pitchbendDestComboBox2->setJustificationType (Justification::centredLeft);
    m_pitchbendDestComboBox2->setTextWhenNothingSelected (String::empty);
    m_pitchbendDestComboBox2->setTextWhenNoChoicesAvailable ("(no choices)");
    m_pitchbendDestComboBox2->addListener (this);

    addAndMakeVisible (m_pitchbendDestSlider2 = new MicroParameterSlider ("pitchbendDestSlider"));
    m_pitchbendDestSlider2->setRange (0, 127, 1);
    m_pitchbendDestSlider2->setSliderStyle (Slider::LinearBar);
    m_pitchbendDestSlider2->setTextBoxStyle (Slider::TextBoxLeft, false, 40, 20);
    m_pitchbendDestSlider2->setColour (Slider::backgroundColourId, Colour (0xfff2f59b));
    m_pitchbendDestSlider2->setColour (Slider::thumbColourId, Colour (0xffc4c86d));
    m_pitchbendDestSlider2->addListener (this);

    addAndMakeVisible (m_pitchbendDestComboBox3 = new ParameterComboBox ("pitchbendDestComboBox"));
    m_pitchbendDestComboBox3->setEditableText (false);
    m_pitchbendDestComboBox3->setJustificationType (Justification::centredLeft);
    m_pitchbendDestComboBox3->setTextWhenNothingSelected (String::empty);
    m_pitchbendDestComboBox3->setTextWhenNoChoicesAvailable ("(no choices)");
    m_pitchbendDestComboBox3->addListener (this);

    addAndMakeVisible (m_pitchbendDestSlider3 = new MicroParameterSlider ("pitchbendDestSlider"));
    m_pitchbendDestSlider3->setRange (0, 127, 1);
    m_pitchbendDestSlider3->setSliderStyle (Slider::LinearBar);
    m_pitchbendDestSlider3->setTextBoxStyle (Slider::TextBoxLeft, false, 40, 20);
    m_pitchbendDestSlider3->setColour (Slider::backgroundColourId, Colour (0xfff2f59b));
    m_pitchbendDestSlider3->setColour (Slider::thumbColourId, Colour (0xffc4c86d));
    m_pitchbendDestSlider3->addListener (this);

    addAndMakeVisible (m_pitchbendDestComboBox4 = new ParameterComboBox ("pitchbendDestComboBox"));
    m_pitchbendDestComboBox4->setEditableText (false);
    m_pitchbendDestComboBox4->setJustificationType (Justification::centredLeft);
    m_pitchbendDestComboBox4->setTextWhenNothingSelected (String::empty);
    m_pitchbendDestComboBox4->setTextWhenNoChoicesAvailable ("(no choices)");
    m_pitchbendDestComboBox4->addListener (this);

    addAndMakeVisible (m_pitchbendDestSlider4 = new MicroParameterSlider ("pitchbendDestSlider"));
    m_pitchbendDestSlider4->setRange (0, 127, 1);
    m_pitchbendDestSlider4->setSliderStyle (Slider::LinearBar);
    m_pitchbendDestSlider4->setTextBoxStyle (Slider::TextBoxLeft, false, 40, 20);
    m_pitchbendDestSlider4->setColour (Slider::backgroundColourId, Colour (0xfff2f59b));
    m_pitchbendDestSlider4->setColour (Slider::thumbColourId, Colour (0xffc4c86d));
    m_pitchbendDestSlider4->addListener (this);

    addAndMakeVisible (m_aftertouchDestComboBox1 = new ParameterComboBox ("aftertouchDestComboBox"));
    m_aftertouchDestComboBox1->setEditableText (false);
    m_aftertouchDestComboBox1->setJustificationType (Justification::centredLeft);
    m_aftertouchDestComboBox1->setTextWhenNothingSelected (String::empty);
    m_aftertouchDestComboBox1->setTextWhenNoChoicesAvailable ("(no choices)");
    m_aftertouchDestComboBox1->addListener (this);

    addAndMakeVisible (m_aftertouchDestSlider1 = new MicroParameterSlider ("aftertouchDestSlider"));
    m_aftertouchDestSlider1->setRange (0, 127, 1);
    m_aftertouchDestSlider1->setSliderStyle (Slider::LinearBar);
    m_aftertouchDestSlider1->setTextBoxStyle (Slider::TextBoxLeft, false, 40, 20);
    m_aftertouchDestSlider1->setColour (Slider::backgroundColourId, Colour (0xfff2f59b));
    m_aftertouchDestSlider1->setColour (Slider::thumbColourId, Colour (0xffc4c86d));
    m_aftertouchDestSlider1->addListener (this);

    addAndMakeVisible (m_aftertouchDestComboBox2 = new ParameterComboBox ("aftertouchDestComboBox"));
    m_aftertouchDestComboBox2->setEditableText (false);
    m_aftertouchDestComboBox2->setJustificationType (Justification::centredLeft);
    m_aftertouchDestComboBox2->setTextWhenNothingSelected (String::empty);
    m_aftertouchDestComboBox2->setTextWhenNoChoicesAvailable ("(no choices)");
    m_aftertouchDestComboBox2->addListener (this);

    addAndMakeVisible (m_aftertouchDestSlider2 = new MicroParameterSlider ("aftertouchDestSlider"));
    m_aftertouchDestSlider2->setRange (0, 127, 1);
    m_aftertouchDestSlider2->setSliderStyle (Slider::LinearBar);
    m_aftertouchDestSlider2->setTextBoxStyle (Slider::TextBoxLeft, false, 40, 20);
    m_aftertouchDestSlider2->setColour (Slider::backgroundColourId, Colour (0xfff2f59b));
    m_aftertouchDestSlider2->setColour (Slider::thumbColourId, Colour (0xffc4c86d));
    m_aftertouchDestSlider2->addListener (this);

    addAndMakeVisible (m_aftertouchDestComboBox3 = new ParameterComboBox ("aftertouchDestComboBox"));
    m_aftertouchDestComboBox3->setEditableText (false);
    m_aftertouchDestComboBox3->setJustificationType (Justification::centredLeft);
    m_aftertouchDestComboBox3->setTextWhenNothingSelected (String::empty);
    m_aftertouchDestComboBox3->setTextWhenNoChoicesAvailable ("(no choices)");
    m_aftertouchDestComboBox3->addListener (this);

    addAndMakeVisible (m_aftertouchDestSlider3 = new MicroParameterSlider ("aftertouchDestSlider"));
    m_aftertouchDestSlider3->setRange (0, 127, 1);
    m_aftertouchDestSlider3->setSliderStyle (Slider::LinearBar);
    m_aftertouchDestSlider3->setTextBoxStyle (Slider::TextBoxLeft, false, 40, 20);
    m_aftertouchDestSlider3->setColour (Slider::backgroundColourId, Colour (0xfff2f59b));
    m_aftertouchDestSlider3->setColour (Slider::thumbColourId, Colour (0xffc4c86d));
    m_aftertouchDestSlider3->addListener (this);

    addAndMakeVisible (m_aftertouchDestComboBox4 = new ParameterComboBox ("aftertouchDestComboBox"));
    m_aftertouchDestComboBox4->setEditableText (false);
    m_aftertouchDestComboBox4->setJustificationType (Justification::centredLeft);
    m_aftertouchDestComboBox4->setTextWhenNothingSelected (String::empty);
    m_aftertouchDestComboBox4->setTextWhenNoChoicesAvailable ("(no choices)");
    m_aftertouchDestComboBox4->addListener (this);

    addAndMakeVisible (m_aftertouchDestSlider4 = new MicroParameterSlider ("aftertouchDestSlider"));
    m_aftertouchDestSlider4->setRange (0, 127, 1);
    m_aftertouchDestSlider4->setSliderStyle (Slider::LinearBar);
    m_aftertouchDestSlider4->setTextBoxStyle (Slider::TextBoxLeft, false, 40, 20);
    m_aftertouchDestSlider4->setColour (Slider::backgroundColourId, Colour (0xfff2f59b));
    m_aftertouchDestSlider4->setColour (Slider::thumbColourId, Colour (0xffc4c86d));
    m_aftertouchDestSlider4->addListener (this);

    addAndMakeVisible (m_onLabel2 = new Label ("onLabel",
                                               "Wave Gain:"));
    m_onLabel2->setFont (Font (13.00f, Font::plain));
    m_onLabel2->setJustificationType (Justification::centredLeft);
    m_onLabel2->setEditable (false, false, false);
    m_onLabel2->setColour (Label::textColourId, Colours::black);
    m_onLabel2->setColour (TextEditor::textColourId, Colours::black);
    m_onLabel2->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_waveGainSlider = new MicroParameterSlider ("fxmColorSlider"));
    m_waveGainSlider->setRange (0, 127, 1);
    m_waveGainSlider->setSliderStyle (Slider::LinearBar);
    m_waveGainSlider->setTextBoxStyle (Slider::TextBoxLeft, false, 40, 20);
    m_waveGainSlider->setColour (Slider::backgroundColourId, Colour (0xfff2f59b));
    m_waveGainSlider->setColour (Slider::thumbColourId, Colour (0xffc4c86d));
    m_waveGainSlider->addListener (this);


    //[UserPreSize]
    m_toneGrp->setText(labelText);
	m_fxmGrp->setTextLabelPosition(Justification::left);
	m_controllersGrp->setTextLabelPosition(Justification::left);
    //[/UserPreSize]

    setSize (304, 760);


    //[Constructor] You can add your own custom stuff here..
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
			if (tone!=nullptr)
			{
				m_onToggle->setParameter(tone->getParameter(0x00));
				m_waveGroupType = tone->getParameter(0x01);
				m_waveGroupId = tone->getParameter(0x02);
				m_waveNumber = tone->getParameter(0x03);
				changeListenerCallback(m_waveNumber);
				m_waveGroupType->addChangeListener(this);
				m_waveGroupId->addChangeListener(this);
				m_waveNumber->addChangeListener(this);
				m_waveGainSlider->setParameter(tone->getParameter(0x05));
				m_fxmToggle->setParameter(tone->getParameter(0x06));
				m_fxmColorSlider->setParameter(tone->getParameter(0x07));
				m_fxmDepthSlider->setParameter(tone->getParameter(0x08));
				m_modDestComboBox1->setParameter(tone->getParameter(0x15));
				m_modDestSlider1->setParameter(tone->getParameter(0x16));
				m_modDestComboBox2->setParameter(tone->getParameter(0x17));
				m_modDestSlider2->setParameter(tone->getParameter(0x18));
				m_modDestComboBox3->setParameter(tone->getParameter(0x19));
				m_modDestSlider3->setParameter(tone->getParameter(0x1A));
				m_modDestComboBox4->setParameter(tone->getParameter(0x1B));
				m_modDestSlider4->setParameter(tone->getParameter(0x1C));
				m_pitchbendDestComboBox1->setParameter(tone->getParameter(0x1D));
				m_pitchbendDestSlider1->setParameter(tone->getParameter(0x1E));
				m_pitchbendDestComboBox2->setParameter(tone->getParameter(0x1F));
				m_pitchbendDestSlider2->setParameter(tone->getParameter(0x20));
				m_pitchbendDestComboBox3->setParameter(tone->getParameter(0x21));
				m_pitchbendDestSlider3->setParameter(tone->getParameter(0x22));
				m_pitchbendDestComboBox4->setParameter(tone->getParameter(0x23));
				m_pitchbendDestSlider4->setParameter(tone->getParameter(0x24));
				m_aftertouchDestComboBox1->setParameter(tone->getParameter(0x25));
				m_aftertouchDestSlider1->setParameter(tone->getParameter(0x26));
				m_aftertouchDestComboBox2->setParameter(tone->getParameter(0x27));
				m_aftertouchDestSlider2->setParameter(tone->getParameter(0x28));
				m_aftertouchDestComboBox3->setParameter(tone->getParameter(0x29));
				m_aftertouchDestSlider3->setParameter(tone->getParameter(0x2A));
				m_aftertouchDestComboBox4->setParameter(tone->getParameter(0x2B));
				m_aftertouchDestSlider4->setParameter(tone->getParameter(0x2C));
			}
		}
	}

    //[/Constructor]
}

PatchToneEditor::~PatchToneEditor()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    m_toneGrp = nullptr;
    m_pitchEnv = nullptr;
    m_filterEnv = nullptr;
    m_ampEnv = nullptr;
    m_onToggle = nullptr;
    m_onLabel = nullptr;
    m_waveButton = nullptr;
    m_waveLabel = nullptr;
    m_fxmGrp = nullptr;
    m_fxmToggle = nullptr;
    m_fxmOnLabel = nullptr;
    m_fxmColorSlider = nullptr;
    m_fxmColorLabel = nullptr;
    m_fxmDepthSlider = nullptr;
    m_fxmDepthLabel = nullptr;
    m_controllersGrp = nullptr;
    m_modulationLabel = nullptr;
    m_modDestComboBox1 = nullptr;
    m_modDestComboBox2 = nullptr;
    m_modDestComboBox3 = nullptr;
    m_modDestComboBox4 = nullptr;
    m_pitchbendLabel = nullptr;
    m_aftertouchLabel = nullptr;
    m_modDestSlider1 = nullptr;
    m_modDestSlider2 = nullptr;
    m_modDestSlider3 = nullptr;
    m_modDestSlider4 = nullptr;
    m_pitchbendDestComboBox1 = nullptr;
    m_pitchbendDestSlider1 = nullptr;
    m_pitchbendDestComboBox2 = nullptr;
    m_pitchbendDestSlider2 = nullptr;
    m_pitchbendDestComboBox3 = nullptr;
    m_pitchbendDestSlider3 = nullptr;
    m_pitchbendDestComboBox4 = nullptr;
    m_pitchbendDestSlider4 = nullptr;
    m_aftertouchDestComboBox1 = nullptr;
    m_aftertouchDestSlider1 = nullptr;
    m_aftertouchDestComboBox2 = nullptr;
    m_aftertouchDestSlider2 = nullptr;
    m_aftertouchDestComboBox3 = nullptr;
    m_aftertouchDestSlider3 = nullptr;
    m_aftertouchDestComboBox4 = nullptr;
    m_aftertouchDestSlider4 = nullptr;
    m_onLabel2 = nullptr;
    m_waveGainSlider = nullptr;


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
    m_toneGrp->setBounds (0, 0, getWidth() - 0, getHeight() - 0);
    m_pitchEnv->setBounds (8, 320, 288, 152);
    m_filterEnv->setBounds (8, 480, 288, 152);
    m_ampEnv->setBounds (8, 640, 288, 152);
    m_onToggle->setBounds (48, 24, 25, 17);
    m_onLabel->setBounds (16, 21, 38, 24);
    m_waveButton->setBounds (156, 22, 136, 21);
    m_waveLabel->setBounds (80, 21, 76, 24);
    m_fxmGrp->setBounds (8, 68, 288, 52);
    m_fxmToggle->setBounds (52, 92, 25, 17);
    m_fxmOnLabel->setBounds (20, 88, 40, 24);
    m_fxmColorSlider->setBounds (128, 92, 56, 16);
    m_fxmColorLabel->setBounds (84, 88, 44, 24);
    m_fxmDepthSlider->setBounds (236, 92, 56, 16);
    m_fxmDepthLabel->setBounds (188, 88, 48, 24);
    m_controllersGrp->setBounds (8, 128, 288, 184);
    m_modulationLabel->setBounds (12, 144, 88, 24);
    m_modDestComboBox1->setBounds (16, 164, 80, 16);
    m_modDestComboBox2->setBounds (16, 200, 80, 16);
    m_modDestComboBox3->setBounds (16, 236, 80, 16);
    m_modDestComboBox4->setBounds (16, 272, 80, 16);
    m_pitchbendLabel->setBounds (108, 144, 88, 24);
    m_aftertouchLabel->setBounds (204, 144, 88, 24);
    m_modDestSlider1->setBounds (16, 180, 56, 16);
    m_modDestSlider2->setBounds (16, 216, 56, 16);
    m_modDestSlider3->setBounds (16, 252, 56, 16);
    m_modDestSlider4->setBounds (16, 288, 56, 16);
    m_pitchbendDestComboBox1->setBounds (112, 164, 80, 16);
    m_pitchbendDestSlider1->setBounds (112, 180, 56, 16);
    m_pitchbendDestComboBox2->setBounds (112, 200, 80, 16);
    m_pitchbendDestSlider2->setBounds (112, 216, 56, 16);
    m_pitchbendDestComboBox3->setBounds (112, 236, 80, 16);
    m_pitchbendDestSlider3->setBounds (112, 252, 56, 16);
    m_pitchbendDestComboBox4->setBounds (112, 272, 80, 16);
    m_pitchbendDestSlider4->setBounds (112, 288, 56, 16);
    m_aftertouchDestComboBox1->setBounds (208, 164, 80, 16);
    m_aftertouchDestSlider1->setBounds (208, 180, 56, 16);
    m_aftertouchDestComboBox2->setBounds (208, 200, 80, 16);
    m_aftertouchDestSlider2->setBounds (208, 216, 56, 16);
    m_aftertouchDestComboBox3->setBounds (208, 236, 80, 16);
    m_aftertouchDestSlider3->setBounds (208, 252, 56, 16);
    m_aftertouchDestComboBox4->setBounds (208, 272, 80, 16);
    m_aftertouchDestSlider4->setBounds (208, 288, 56, 16);
    m_onLabel2->setBounds (16, 44, 76, 24);
    m_waveGainSlider->setBounds (96, 48, 56, 16);
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
		dialogLaunch.dialogTitle = "Select Waveform for PART " + String((int)m_part + 1) + ", "+ m_toneGrp->getText();
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

    //[UserbuttonClicked_Post]
    //[/UserbuttonClicked_Post]
}

void PatchToneEditor::sliderValueChanged (Slider* sliderThatWasMoved)
{
    //[UsersliderValueChanged_Pre]
    //[/UsersliderValueChanged_Pre]

    if (sliderThatWasMoved == m_fxmColorSlider)
    {
        //[UserSliderCode_m_fxmColorSlider] -- add your slider handling code here..
        //[/UserSliderCode_m_fxmColorSlider]
    }
    else if (sliderThatWasMoved == m_fxmDepthSlider)
    {
        //[UserSliderCode_m_fxmDepthSlider] -- add your slider handling code here..
        //[/UserSliderCode_m_fxmDepthSlider]
    }
    else if (sliderThatWasMoved == m_modDestSlider1)
    {
        //[UserSliderCode_m_modDestSlider1] -- add your slider handling code here..
        //[/UserSliderCode_m_modDestSlider1]
    }
    else if (sliderThatWasMoved == m_modDestSlider2)
    {
        //[UserSliderCode_m_modDestSlider2] -- add your slider handling code here..
        //[/UserSliderCode_m_modDestSlider2]
    }
    else if (sliderThatWasMoved == m_modDestSlider3)
    {
        //[UserSliderCode_m_modDestSlider3] -- add your slider handling code here..
        //[/UserSliderCode_m_modDestSlider3]
    }
    else if (sliderThatWasMoved == m_modDestSlider4)
    {
        //[UserSliderCode_m_modDestSlider4] -- add your slider handling code here..
        //[/UserSliderCode_m_modDestSlider4]
    }
    else if (sliderThatWasMoved == m_pitchbendDestSlider1)
    {
        //[UserSliderCode_m_pitchbendDestSlider1] -- add your slider handling code here..
        //[/UserSliderCode_m_pitchbendDestSlider1]
    }
    else if (sliderThatWasMoved == m_pitchbendDestSlider2)
    {
        //[UserSliderCode_m_pitchbendDestSlider2] -- add your slider handling code here..
        //[/UserSliderCode_m_pitchbendDestSlider2]
    }
    else if (sliderThatWasMoved == m_pitchbendDestSlider3)
    {
        //[UserSliderCode_m_pitchbendDestSlider3] -- add your slider handling code here..
        //[/UserSliderCode_m_pitchbendDestSlider3]
    }
    else if (sliderThatWasMoved == m_pitchbendDestSlider4)
    {
        //[UserSliderCode_m_pitchbendDestSlider4] -- add your slider handling code here..
        //[/UserSliderCode_m_pitchbendDestSlider4]
    }
    else if (sliderThatWasMoved == m_aftertouchDestSlider1)
    {
        //[UserSliderCode_m_aftertouchDestSlider1] -- add your slider handling code here..
        //[/UserSliderCode_m_aftertouchDestSlider1]
    }
    else if (sliderThatWasMoved == m_aftertouchDestSlider2)
    {
        //[UserSliderCode_m_aftertouchDestSlider2] -- add your slider handling code here..
        //[/UserSliderCode_m_aftertouchDestSlider2]
    }
    else if (sliderThatWasMoved == m_aftertouchDestSlider3)
    {
        //[UserSliderCode_m_aftertouchDestSlider3] -- add your slider handling code here..
        //[/UserSliderCode_m_aftertouchDestSlider3]
    }
    else if (sliderThatWasMoved == m_aftertouchDestSlider4)
    {
        //[UserSliderCode_m_aftertouchDestSlider4] -- add your slider handling code here..
        //[/UserSliderCode_m_aftertouchDestSlider4]
    }
    else if (sliderThatWasMoved == m_waveGainSlider)
    {
        //[UserSliderCode_m_waveGainSlider] -- add your slider handling code here..
        //[/UserSliderCode_m_waveGainSlider]
    }

    //[UsersliderValueChanged_Post]
    //[/UsersliderValueChanged_Post]
}

void PatchToneEditor::comboBoxChanged (ComboBox* comboBoxThatHasChanged)
{
    //[UsercomboBoxChanged_Pre]
    //[/UsercomboBoxChanged_Pre]

    if (comboBoxThatHasChanged == m_modDestComboBox1)
    {
        //[UserComboBoxCode_m_modDestComboBox1] -- add your combo box handling code here..
        //[/UserComboBoxCode_m_modDestComboBox1]
    }
    else if (comboBoxThatHasChanged == m_modDestComboBox2)
    {
        //[UserComboBoxCode_m_modDestComboBox2] -- add your combo box handling code here..
        //[/UserComboBoxCode_m_modDestComboBox2]
    }
    else if (comboBoxThatHasChanged == m_modDestComboBox3)
    {
        //[UserComboBoxCode_m_modDestComboBox3] -- add your combo box handling code here..
        //[/UserComboBoxCode_m_modDestComboBox3]
    }
    else if (comboBoxThatHasChanged == m_modDestComboBox4)
    {
        //[UserComboBoxCode_m_modDestComboBox4] -- add your combo box handling code here..
        //[/UserComboBoxCode_m_modDestComboBox4]
    }
    else if (comboBoxThatHasChanged == m_pitchbendDestComboBox1)
    {
        //[UserComboBoxCode_m_pitchbendDestComboBox1] -- add your combo box handling code here..
        //[/UserComboBoxCode_m_pitchbendDestComboBox1]
    }
    else if (comboBoxThatHasChanged == m_pitchbendDestComboBox2)
    {
        //[UserComboBoxCode_m_pitchbendDestComboBox2] -- add your combo box handling code here..
        //[/UserComboBoxCode_m_pitchbendDestComboBox2]
    }
    else if (comboBoxThatHasChanged == m_pitchbendDestComboBox3)
    {
        //[UserComboBoxCode_m_pitchbendDestComboBox3] -- add your combo box handling code here..
        //[/UserComboBoxCode_m_pitchbendDestComboBox3]
    }
    else if (comboBoxThatHasChanged == m_pitchbendDestComboBox4)
    {
        //[UserComboBoxCode_m_pitchbendDestComboBox4] -- add your combo box handling code here..
        //[/UserComboBoxCode_m_pitchbendDestComboBox4]
    }
    else if (comboBoxThatHasChanged == m_aftertouchDestComboBox1)
    {
        //[UserComboBoxCode_m_aftertouchDestComboBox1] -- add your combo box handling code here..
        //[/UserComboBoxCode_m_aftertouchDestComboBox1]
    }
    else if (comboBoxThatHasChanged == m_aftertouchDestComboBox2)
    {
        //[UserComboBoxCode_m_aftertouchDestComboBox2] -- add your combo box handling code here..
        //[/UserComboBoxCode_m_aftertouchDestComboBox2]
    }
    else if (comboBoxThatHasChanged == m_aftertouchDestComboBox3)
    {
        //[UserComboBoxCode_m_aftertouchDestComboBox3] -- add your combo box handling code here..
        //[/UserComboBoxCode_m_aftertouchDestComboBox3]
    }
    else if (comboBoxThatHasChanged == m_aftertouchDestComboBox4)
    {
        //[UserComboBoxCode_m_aftertouchDestComboBox4] -- add your combo box handling code here..
        //[/UserComboBoxCode_m_aftertouchDestComboBox4]
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
                 parentClasses="public Component, public ChangeListener" constructorParams="const String&amp; labelText, SynthParts part, Tone tone"
                 variableInitialisers="m_part (part),&#10;m_tone (tone)" snapPixels="4"
                 snapActive="1" snapShown="1" overlayOpacity="0.330" fixedSize="1"
                 initialWidth="304" initialHeight="760">
  <BACKGROUND backgroundColour="0"/>
  <JUCERCOMP name="toneGrp" id="118e74c21359a1c1" memberName="m_toneGrp" virtualName=""
             explicitFocusOrder="0" pos="0 0 0M 0M" sourceFile="PanelGroupGrey.cpp"
             constructorParams="&quot;toneGrp&quot;,&quot;TONE&quot;"/>
  <JUCERCOMP name="pitchEnv" id="99a40d72d7ad1e22" memberName="m_pitchEnv"
             virtualName="" explicitFocusOrder="0" pos="8 320 288 152" sourceFile="Envelope.cpp"
             constructorParams="&quot;Pitch Envelope&quot;,-63,63,false"/>
  <JUCERCOMP name="filterEnv" id="521337ba1cd03159" memberName="m_filterEnv"
             virtualName="" explicitFocusOrder="0" pos="8 480 288 152" sourceFile="Envelope.cpp"
             constructorParams="&quot;Filter Envelope&quot;,0,127,false"/>
  <JUCERCOMP name="ampEnv" id="f84b427a83f125de" memberName="m_ampEnv" virtualName=""
             explicitFocusOrder="0" pos="8 640 288 152" sourceFile="Envelope.cpp"
             constructorParams="&quot;Amlitude Envelope&quot;,0,127,true"/>
  <JUCERCOMP name="onToggle" id="b0e7322ed6fe4133" memberName="m_onToggle"
             virtualName="" explicitFocusOrder="0" pos="48 24 25 17" sourceFile="BlackToggle.cpp"
             constructorParams=""/>
  <LABEL name="onLabel" id="a5103dfa4b0cded3" memberName="m_onLabel" virtualName=""
         explicitFocusOrder="0" pos="16 21 38 24" textCol="ff000000" edTextCol="ff000000"
         edBkgCol="0" labelText="On:" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="13"
         bold="0" italic="0" justification="33"/>
  <TEXTBUTTON name="new button" id="603fab9f912b12cf" memberName="m_waveButton"
              virtualName="" explicitFocusOrder="0" pos="156 22 136 21" buttonText="A:001 Dist TB 303a"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <LABEL name="waveLabel" id="77636cfe920d8c67" memberName="m_waveLabel"
         virtualName="" explicitFocusOrder="0" pos="80 21 76 24" textCol="ff000000"
         edTextCol="ff000000" edBkgCol="0" labelText="Waveform:" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="13" bold="0" italic="0" justification="34"/>
  <JUCERCOMP name="fxmGrp" id="ae3eed65b8ca1538" memberName="m_fxmGrp" virtualName=""
             explicitFocusOrder="0" pos="8 68 288 52" sourceFile="PanelGroupGrey.cpp"
             constructorParams="&quot;FXMGrp&quot;,&quot;FXM&quot;"/>
  <JUCERCOMP name="fxmToggle" id="4cb4ce270163d019" memberName="m_fxmToggle"
             virtualName="" explicitFocusOrder="0" pos="52 92 25 17" sourceFile="BlackToggle.cpp"
             constructorParams=""/>
  <LABEL name="fxmOnLabel" id="8003d288f01ddf16" memberName="m_fxmOnLabel"
         virtualName="" explicitFocusOrder="0" pos="20 88 40 24" textCol="ff000000"
         edTextCol="ff000000" edBkgCol="0" labelText="On:" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="13" bold="0" italic="0" justification="33"/>
  <SLIDER name="fxmColorSlider" id="e251907fb7141880" memberName="m_fxmColorSlider"
          virtualName="MicroParameterSlider" explicitFocusOrder="0" pos="128 92 56 16"
          bkgcol="fff2f59b" thumbcol="ffc4c86d" min="0" max="127" int="1"
          style="LinearBar" textBoxPos="TextBoxLeft" textBoxEditable="1"
          textBoxWidth="40" textBoxHeight="20" skewFactor="1"/>
  <LABEL name="fxmColorLabel" id="10469cfe4109278d" memberName="m_fxmColorLabel"
         virtualName="" explicitFocusOrder="0" pos="84 88 44 24" textCol="ff000000"
         edTextCol="ff000000" edBkgCol="0" labelText="Color:" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="13" bold="0" italic="0" justification="33"/>
  <SLIDER name="fxmDepthSlider" id="c2a5b378e06cd22d" memberName="m_fxmDepthSlider"
          virtualName="MicroParameterSlider" explicitFocusOrder="0" pos="236 92 56 16"
          bkgcol="fff2f59b" thumbcol="ffc4c86d" min="0" max="127" int="1"
          style="LinearBar" textBoxPos="TextBoxLeft" textBoxEditable="1"
          textBoxWidth="40" textBoxHeight="20" skewFactor="1"/>
  <LABEL name="fxmDepthLabel" id="2589d92458f34088" memberName="m_fxmDepthLabel"
         virtualName="" explicitFocusOrder="0" pos="188 88 48 24" textCol="ff000000"
         edTextCol="ff000000" edBkgCol="0" labelText="Depth:" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="13" bold="0" italic="0" justification="33"/>
  <JUCERCOMP name="controllersGrp" id="b1682db57b20287e" memberName="m_controllersGrp"
             virtualName="" explicitFocusOrder="0" pos="8 128 288 184" sourceFile="PanelGroupGrey.cpp"
             constructorParams="&quot;ControllersGrp&quot;,&quot;CONTROLLERS&quot;"/>
  <LABEL name="modulationLabel" id="7b351347affdb490" memberName="m_modulationLabel"
         virtualName="" explicitFocusOrder="0" pos="12 144 88 24" textCol="ff000000"
         edTextCol="ff000000" edBkgCol="0" labelText="MODULATION" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="13" bold="0" italic="0" justification="36"/>
  <COMBOBOX name="modDestComboBox" id="5f5f3969c23f54e2" memberName="m_modDestComboBox1"
            virtualName="ParameterComboBox" explicitFocusOrder="0" pos="16 164 80 16"
            editable="0" layout="33" items="" textWhenNonSelected="" textWhenNoItems="(no choices)"/>
  <COMBOBOX name="modDestComboBox" id="771446e138706472" memberName="m_modDestComboBox2"
            virtualName="ParameterComboBox" explicitFocusOrder="0" pos="16 200 80 16"
            editable="0" layout="33" items="" textWhenNonSelected="" textWhenNoItems="(no choices)"/>
  <COMBOBOX name="modDestComboBox" id="6dd02b8276c17234" memberName="m_modDestComboBox3"
            virtualName="ParameterComboBox" explicitFocusOrder="0" pos="16 236 80 16"
            editable="0" layout="33" items="" textWhenNonSelected="" textWhenNoItems="(no choices)"/>
  <COMBOBOX name="modDestComboBox" id="4f44976e3785b130" memberName="m_modDestComboBox4"
            virtualName="ParameterComboBox" explicitFocusOrder="0" pos="16 272 80 16"
            editable="0" layout="33" items="" textWhenNonSelected="" textWhenNoItems="(no choices)"/>
  <LABEL name="pitchbendLabel" id="970628036020a7e" memberName="m_pitchbendLabel"
         virtualName="" explicitFocusOrder="0" pos="108 144 88 24" textCol="ff000000"
         edTextCol="ff000000" edBkgCol="0" labelText="PITCH BEND" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="13" bold="0" italic="0" justification="36"/>
  <LABEL name="aftertouchLabel" id="c2aa167417218a4" memberName="m_aftertouchLabel"
         virtualName="" explicitFocusOrder="0" pos="204 144 88 24" textCol="ff000000"
         edTextCol="ff000000" edBkgCol="0" labelText="AFTERTOUCH" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="13" bold="0" italic="0" justification="36"/>
  <SLIDER name="modDestSlider" id="e90b1ea2a9f03eaf" memberName="m_modDestSlider1"
          virtualName="MicroParameterSlider" explicitFocusOrder="0" pos="16 180 56 16"
          bkgcol="fff2f59b" thumbcol="ffc4c86d" min="0" max="127" int="1"
          style="LinearBar" textBoxPos="TextBoxLeft" textBoxEditable="1"
          textBoxWidth="40" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="modDestSlider" id="a0c69a60b8ce07c9" memberName="m_modDestSlider2"
          virtualName="MicroParameterSlider" explicitFocusOrder="0" pos="16 216 56 16"
          bkgcol="fff2f59b" thumbcol="ffc4c86d" min="0" max="127" int="1"
          style="LinearBar" textBoxPos="TextBoxLeft" textBoxEditable="1"
          textBoxWidth="40" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="modDestSlider" id="2403725c31cd4313" memberName="m_modDestSlider3"
          virtualName="MicroParameterSlider" explicitFocusOrder="0" pos="16 252 56 16"
          bkgcol="fff2f59b" thumbcol="ffc4c86d" min="0" max="127" int="1"
          style="LinearBar" textBoxPos="TextBoxLeft" textBoxEditable="1"
          textBoxWidth="40" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="modDestSlider" id="cc0c5881f6b7a023" memberName="m_modDestSlider4"
          virtualName="MicroParameterSlider" explicitFocusOrder="0" pos="16 288 56 16"
          bkgcol="fff2f59b" thumbcol="ffc4c86d" min="0" max="127" int="1"
          style="LinearBar" textBoxPos="TextBoxLeft" textBoxEditable="1"
          textBoxWidth="40" textBoxHeight="20" skewFactor="1"/>
  <COMBOBOX name="pitchbendDestComboBox" id="f1c8aff4c931d28f" memberName="m_pitchbendDestComboBox1"
            virtualName="ParameterComboBox" explicitFocusOrder="0" pos="112 164 80 16"
            editable="0" layout="33" items="" textWhenNonSelected="" textWhenNoItems="(no choices)"/>
  <SLIDER name="pitchbendDestSlider" id="a3041600e48a43d6" memberName="m_pitchbendDestSlider1"
          virtualName="MicroParameterSlider" explicitFocusOrder="0" pos="112 180 56 16"
          bkgcol="fff2f59b" thumbcol="ffc4c86d" min="0" max="127" int="1"
          style="LinearBar" textBoxPos="TextBoxLeft" textBoxEditable="1"
          textBoxWidth="40" textBoxHeight="20" skewFactor="1"/>
  <COMBOBOX name="pitchbendDestComboBox" id="3c71809600dc3a9c" memberName="m_pitchbendDestComboBox2"
            virtualName="ParameterComboBox" explicitFocusOrder="0" pos="112 200 80 16"
            editable="0" layout="33" items="" textWhenNonSelected="" textWhenNoItems="(no choices)"/>
  <SLIDER name="pitchbendDestSlider" id="87cddee3503965fd" memberName="m_pitchbendDestSlider2"
          virtualName="MicroParameterSlider" explicitFocusOrder="0" pos="112 216 56 16"
          bkgcol="fff2f59b" thumbcol="ffc4c86d" min="0" max="127" int="1"
          style="LinearBar" textBoxPos="TextBoxLeft" textBoxEditable="1"
          textBoxWidth="40" textBoxHeight="20" skewFactor="1"/>
  <COMBOBOX name="pitchbendDestComboBox" id="d7754475a590b5e2" memberName="m_pitchbendDestComboBox3"
            virtualName="ParameterComboBox" explicitFocusOrder="0" pos="112 236 80 16"
            editable="0" layout="33" items="" textWhenNonSelected="" textWhenNoItems="(no choices)"/>
  <SLIDER name="pitchbendDestSlider" id="4713cc6004cd872a" memberName="m_pitchbendDestSlider3"
          virtualName="MicroParameterSlider" explicitFocusOrder="0" pos="112 252 56 16"
          bkgcol="fff2f59b" thumbcol="ffc4c86d" min="0" max="127" int="1"
          style="LinearBar" textBoxPos="TextBoxLeft" textBoxEditable="1"
          textBoxWidth="40" textBoxHeight="20" skewFactor="1"/>
  <COMBOBOX name="pitchbendDestComboBox" id="cb3f18fd42248fb1" memberName="m_pitchbendDestComboBox4"
            virtualName="ParameterComboBox" explicitFocusOrder="0" pos="112 272 80 16"
            editable="0" layout="33" items="" textWhenNonSelected="" textWhenNoItems="(no choices)"/>
  <SLIDER name="pitchbendDestSlider" id="545815f3cafc1ec2" memberName="m_pitchbendDestSlider4"
          virtualName="MicroParameterSlider" explicitFocusOrder="0" pos="112 288 56 16"
          bkgcol="fff2f59b" thumbcol="ffc4c86d" min="0" max="127" int="1"
          style="LinearBar" textBoxPos="TextBoxLeft" textBoxEditable="1"
          textBoxWidth="40" textBoxHeight="20" skewFactor="1"/>
  <COMBOBOX name="aftertouchDestComboBox" id="ae961678edb4578" memberName="m_aftertouchDestComboBox1"
            virtualName="ParameterComboBox" explicitFocusOrder="0" pos="208 164 80 16"
            editable="0" layout="33" items="" textWhenNonSelected="" textWhenNoItems="(no choices)"/>
  <SLIDER name="aftertouchDestSlider" id="b6a63c9b656f3e48" memberName="m_aftertouchDestSlider1"
          virtualName="MicroParameterSlider" explicitFocusOrder="0" pos="208 180 56 16"
          bkgcol="fff2f59b" thumbcol="ffc4c86d" min="0" max="127" int="1"
          style="LinearBar" textBoxPos="TextBoxLeft" textBoxEditable="1"
          textBoxWidth="40" textBoxHeight="20" skewFactor="1"/>
  <COMBOBOX name="aftertouchDestComboBox" id="8bd1536b9a229e76" memberName="m_aftertouchDestComboBox2"
            virtualName="ParameterComboBox" explicitFocusOrder="0" pos="208 200 80 16"
            editable="0" layout="33" items="" textWhenNonSelected="" textWhenNoItems="(no choices)"/>
  <SLIDER name="aftertouchDestSlider" id="b7ea5857540707b8" memberName="m_aftertouchDestSlider2"
          virtualName="MicroParameterSlider" explicitFocusOrder="0" pos="208 216 56 16"
          bkgcol="fff2f59b" thumbcol="ffc4c86d" min="0" max="127" int="1"
          style="LinearBar" textBoxPos="TextBoxLeft" textBoxEditable="1"
          textBoxWidth="40" textBoxHeight="20" skewFactor="1"/>
  <COMBOBOX name="aftertouchDestComboBox" id="eb932ac155acda76" memberName="m_aftertouchDestComboBox3"
            virtualName="ParameterComboBox" explicitFocusOrder="0" pos="208 236 80 16"
            editable="0" layout="33" items="" textWhenNonSelected="" textWhenNoItems="(no choices)"/>
  <SLIDER name="aftertouchDestSlider" id="91a760d063513cf9" memberName="m_aftertouchDestSlider3"
          virtualName="MicroParameterSlider" explicitFocusOrder="0" pos="208 252 56 16"
          bkgcol="fff2f59b" thumbcol="ffc4c86d" min="0" max="127" int="1"
          style="LinearBar" textBoxPos="TextBoxLeft" textBoxEditable="1"
          textBoxWidth="40" textBoxHeight="20" skewFactor="1"/>
  <COMBOBOX name="aftertouchDestComboBox" id="2643f9236d3349d9" memberName="m_aftertouchDestComboBox4"
            virtualName="ParameterComboBox" explicitFocusOrder="0" pos="208 272 80 16"
            editable="0" layout="33" items="" textWhenNonSelected="" textWhenNoItems="(no choices)"/>
  <SLIDER name="aftertouchDestSlider" id="349543ba9a2367af" memberName="m_aftertouchDestSlider4"
          virtualName="MicroParameterSlider" explicitFocusOrder="0" pos="208 288 56 16"
          bkgcol="fff2f59b" thumbcol="ffc4c86d" min="0" max="127" int="1"
          style="LinearBar" textBoxPos="TextBoxLeft" textBoxEditable="1"
          textBoxWidth="40" textBoxHeight="20" skewFactor="1"/>
  <LABEL name="onLabel" id="622e567326097c53" memberName="m_onLabel2"
         virtualName="" explicitFocusOrder="0" pos="16 44 76 24" textCol="ff000000"
         edTextCol="ff000000" edBkgCol="0" labelText="Wave Gain:" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="13" bold="0" italic="0" justification="33"/>
  <SLIDER name="fxmColorSlider" id="d3b7483dd2b91927" memberName="m_waveGainSlider"
          virtualName="MicroParameterSlider" explicitFocusOrder="0" pos="96 48 56 16"
          bkgcol="fff2f59b" thumbcol="ffc4c86d" min="0" max="127" int="1"
          style="LinearBar" textBoxPos="TextBoxLeft" textBoxEditable="1"
          textBoxWidth="40" textBoxHeight="20" skewFactor="1"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
