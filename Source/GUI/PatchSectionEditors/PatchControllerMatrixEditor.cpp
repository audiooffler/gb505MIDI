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

#include "PatchControllerMatrixEditor.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
extern OverallMemoryBlock* grooveboxMemory;
//[/MiscUserDefs]

//==============================================================================
PatchControllerMatrixEditor::PatchControllerMatrixEditor (const String &componentName, SynthParts part, Tone tone)
    : Component (componentName), m_part(part), m_tone(tone)
{
    addAndMakeVisible (m_controllersGrp = new PanelGroupGrey ("ControllersGrp","CONTROLLERS"));
    addAndMakeVisible (m_modulationLabel = new Label ("modulationLabel",
                                                      "MODULATION CONTROL"));
    m_modulationLabel->setFont (Font (12.00f, Font::bold));
    m_modulationLabel->setJustificationType (Justification::centred);
    m_modulationLabel->setEditable (false, false, false);
    m_modulationLabel->setColour (Label::textColourId, Colours::black);
    m_modulationLabel->setColour (TextEditor::textColourId, Colours::black);
    m_modulationLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_modDestComboBox1 = new ParameterComboBox ("modDestComboBox"));
    m_modDestComboBox1->setEditableText (false);
    m_modDestComboBox1->setJustificationType (Justification::centredLeft);
    m_modDestComboBox1->setTextWhenNothingSelected ("OFF");
    m_modDestComboBox1->setTextWhenNoChoicesAvailable ("(no choices)");
    m_modDestComboBox1->addItem ("OFF", 1);
    m_modDestComboBox1->addItem ("Pitch", 2);
    m_modDestComboBox1->addItem ("Filter Cutoff", 3);
    m_modDestComboBox1->addItem ("Filter Res", 4);
    m_modDestComboBox1->addItem ("Tone Level", 5);
    m_modDestComboBox1->addItem ("Tone Pan", 6);
    m_modDestComboBox1->addItem ("LFO1 Pitch", 7);
    m_modDestComboBox1->addItem ("LFO2 Pitch", 8);
    m_modDestComboBox1->addItem ("LFO1 Filter", 9);
    m_modDestComboBox1->addItem ("LFO2 Filter", 10);
    m_modDestComboBox1->addItem ("LFO1 Amp", 11);
    m_modDestComboBox1->addItem ("LFO2 Amp", 12);
    m_modDestComboBox1->addItem ("LFO1 Pan", 13);
    m_modDestComboBox1->addItem ("LFO2 Pan", 14);
    m_modDestComboBox1->addItem ("LFO1 Rate", 15);
    m_modDestComboBox1->addItem ("LFO2 Rate", 16);
    m_modDestComboBox1->addListener (this);

    addAndMakeVisible (m_modDestComboBox2 = new ParameterComboBox ("modDestComboBox"));
    m_modDestComboBox2->setEditableText (false);
    m_modDestComboBox2->setJustificationType (Justification::centredLeft);
    m_modDestComboBox2->setTextWhenNothingSelected ("OFF");
    m_modDestComboBox2->setTextWhenNoChoicesAvailable ("(no choices)");
    m_modDestComboBox2->addItem ("OFF", 1);
    m_modDestComboBox2->addItem ("Pitch", 2);
    m_modDestComboBox2->addItem ("Filter Cutoff", 3);
    m_modDestComboBox2->addItem ("Filter Res", 4);
    m_modDestComboBox2->addItem ("Tone Level", 5);
    m_modDestComboBox2->addItem ("Tone Pan", 6);
    m_modDestComboBox2->addItem ("LFO1 Pitch", 7);
    m_modDestComboBox2->addItem ("LFO2 Pitch", 8);
    m_modDestComboBox2->addItem ("LFO1 Filter", 9);
    m_modDestComboBox2->addItem ("LFO2 Filter", 10);
    m_modDestComboBox2->addItem ("LFO1 Amp", 11);
    m_modDestComboBox2->addItem ("LFO2 Amp", 12);
    m_modDestComboBox2->addItem ("LFO1 Pan", 13);
    m_modDestComboBox2->addItem ("LFO2 Pan", 14);
    m_modDestComboBox2->addItem ("LFO1 Rate", 15);
    m_modDestComboBox2->addItem ("LFO2 Rate", 16);
    m_modDestComboBox2->addListener (this);

    addAndMakeVisible (m_modDestComboBox3 = new ParameterComboBox ("modDestComboBox"));
    m_modDestComboBox3->setEditableText (false);
    m_modDestComboBox3->setJustificationType (Justification::centredLeft);
    m_modDestComboBox3->setTextWhenNothingSelected ("OFF");
    m_modDestComboBox3->setTextWhenNoChoicesAvailable ("(no choices)");
    m_modDestComboBox3->addItem ("OFF", 1);
    m_modDestComboBox3->addItem ("Pitch", 2);
    m_modDestComboBox3->addItem ("Filter Cutoff", 3);
    m_modDestComboBox3->addItem ("Filter Res", 4);
    m_modDestComboBox3->addItem ("Tone Level", 5);
    m_modDestComboBox3->addItem ("Tone Pan", 6);
    m_modDestComboBox3->addItem ("LFO1 Pitch", 7);
    m_modDestComboBox3->addItem ("LFO2 Pitch", 8);
    m_modDestComboBox3->addItem ("LFO1 Filter", 9);
    m_modDestComboBox3->addItem ("LFO2 Filter", 10);
    m_modDestComboBox3->addItem ("LFO1 Amp", 11);
    m_modDestComboBox3->addItem ("LFO2 Amp", 12);
    m_modDestComboBox3->addItem ("LFO1 Pan", 13);
    m_modDestComboBox3->addItem ("LFO2 Pan", 14);
    m_modDestComboBox3->addItem ("LFO1 Rate", 15);
    m_modDestComboBox3->addItem ("LFO2 Rate", 16);
    m_modDestComboBox3->addListener (this);

    addAndMakeVisible (m_modDestComboBox4 = new ParameterComboBox ("modDestComboBox"));
    m_modDestComboBox4->setEditableText (false);
    m_modDestComboBox4->setJustificationType (Justification::centredLeft);
    m_modDestComboBox4->setTextWhenNothingSelected ("OFF");
    m_modDestComboBox4->setTextWhenNoChoicesAvailable ("(no choices)");
    m_modDestComboBox4->addItem ("OFF", 1);
    m_modDestComboBox4->addItem ("Pitch", 2);
    m_modDestComboBox4->addItem ("Filter Cutoff", 3);
    m_modDestComboBox4->addItem ("Filter Res", 4);
    m_modDestComboBox4->addItem ("Tone Level", 5);
    m_modDestComboBox4->addItem ("Tone Pan", 6);
    m_modDestComboBox4->addItem ("LFO1 Pitch", 7);
    m_modDestComboBox4->addItem ("LFO2 Pitch", 8);
    m_modDestComboBox4->addItem ("LFO1 Filter", 9);
    m_modDestComboBox4->addItem ("LFO2 Filter", 10);
    m_modDestComboBox4->addItem ("LFO1 Amp", 11);
    m_modDestComboBox4->addItem ("LFO2 Amp", 12);
    m_modDestComboBox4->addItem ("LFO1 Pan", 13);
    m_modDestComboBox4->addItem ("LFO2 Pan", 14);
    m_modDestComboBox4->addItem ("LFO1 Rate", 15);
    m_modDestComboBox4->addItem ("LFO2 Rate", 16);
    m_modDestComboBox4->addListener (this);

    addAndMakeVisible (m_pitchbendLabel = new Label ("pitchbendLabel",
                                                     "PITCH BEND CONTROL"));
    m_pitchbendLabel->setFont (Font (12.00f, Font::bold));
    m_pitchbendLabel->setJustificationType (Justification::centred);
    m_pitchbendLabel->setEditable (false, false, false);
    m_pitchbendLabel->setColour (Label::textColourId, Colours::black);
    m_pitchbendLabel->setColour (TextEditor::textColourId, Colours::black);
    m_pitchbendLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_aftertouchLabel = new Label ("aftertouchLabel",
                                                      "AFTERTOUCH CONTROL"));
    m_aftertouchLabel->setFont (Font (12.00f, Font::bold));
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
    m_pitchbendDestComboBox1->setTextWhenNothingSelected ("OFF");
    m_pitchbendDestComboBox1->setTextWhenNoChoicesAvailable ("(no choices)");
    m_pitchbendDestComboBox1->addItem ("OFF", 1);
    m_pitchbendDestComboBox1->addItem ("Pitch", 2);
    m_pitchbendDestComboBox1->addItem ("Filter Cutoff", 3);
    m_pitchbendDestComboBox1->addItem ("Filter Res", 4);
    m_pitchbendDestComboBox1->addItem ("Tone Level", 5);
    m_pitchbendDestComboBox1->addItem ("Tone Pan", 6);
    m_pitchbendDestComboBox1->addItem ("LFO1 Pitch", 7);
    m_pitchbendDestComboBox1->addItem ("LFO2 Pitch", 8);
    m_pitchbendDestComboBox1->addItem ("LFO1 Filter", 9);
    m_pitchbendDestComboBox1->addItem ("LFO2 Filter", 10);
    m_pitchbendDestComboBox1->addItem ("LFO1 Amp", 11);
    m_pitchbendDestComboBox1->addItem ("LFO2 Amp", 12);
    m_pitchbendDestComboBox1->addItem ("LFO1 Pan", 13);
    m_pitchbendDestComboBox1->addItem ("LFO2 Pan", 14);
    m_pitchbendDestComboBox1->addItem ("LFO1 Rate", 15);
    m_pitchbendDestComboBox1->addItem ("LFO2 Rate", 16);
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
    m_pitchbendDestComboBox2->setTextWhenNothingSelected ("OFF");
    m_pitchbendDestComboBox2->setTextWhenNoChoicesAvailable ("(no choices)");
    m_pitchbendDestComboBox2->addItem ("OFF", 1);
    m_pitchbendDestComboBox2->addItem ("Pitch", 2);
    m_pitchbendDestComboBox2->addItem ("Filter Cutoff", 3);
    m_pitchbendDestComboBox2->addItem ("Filter Res", 4);
    m_pitchbendDestComboBox2->addItem ("Tone Level", 5);
    m_pitchbendDestComboBox2->addItem ("Tone Pan", 6);
    m_pitchbendDestComboBox2->addItem ("LFO1 Pitch", 7);
    m_pitchbendDestComboBox2->addItem ("LFO2 Pitch", 8);
    m_pitchbendDestComboBox2->addItem ("LFO1 Filter", 9);
    m_pitchbendDestComboBox2->addItem ("LFO2 Filter", 10);
    m_pitchbendDestComboBox2->addItem ("LFO1 Amp", 11);
    m_pitchbendDestComboBox2->addItem ("LFO2 Amp", 12);
    m_pitchbendDestComboBox2->addItem ("LFO1 Pan", 13);
    m_pitchbendDestComboBox2->addItem ("LFO2 Pan", 14);
    m_pitchbendDestComboBox2->addItem ("LFO1 Rate", 15);
    m_pitchbendDestComboBox2->addItem ("LFO2 Rate", 16);
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
    m_pitchbendDestComboBox3->setTextWhenNothingSelected ("OFF");
    m_pitchbendDestComboBox3->setTextWhenNoChoicesAvailable ("(no choices)");
    m_pitchbendDestComboBox3->addItem ("OFF", 1);
    m_pitchbendDestComboBox3->addItem ("Pitch", 2);
    m_pitchbendDestComboBox3->addItem ("Filter Cutoff", 3);
    m_pitchbendDestComboBox3->addItem ("Filter Res", 4);
    m_pitchbendDestComboBox3->addItem ("Tone Level", 5);
    m_pitchbendDestComboBox3->addItem ("Tone Pan", 6);
    m_pitchbendDestComboBox3->addItem ("LFO1 Pitch", 7);
    m_pitchbendDestComboBox3->addItem ("LFO2 Pitch", 8);
    m_pitchbendDestComboBox3->addItem ("LFO1 Filter", 9);
    m_pitchbendDestComboBox3->addItem ("LFO2 Filter", 10);
    m_pitchbendDestComboBox3->addItem ("LFO1 Amp", 11);
    m_pitchbendDestComboBox3->addItem ("LFO2 Amp", 12);
    m_pitchbendDestComboBox3->addItem ("LFO1 Pan", 13);
    m_pitchbendDestComboBox3->addItem ("LFO2 Pan", 14);
    m_pitchbendDestComboBox3->addItem ("LFO1 Rate", 15);
    m_pitchbendDestComboBox3->addItem ("LFO2 Rate", 16);
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
    m_pitchbendDestComboBox4->setTextWhenNothingSelected ("OFF");
    m_pitchbendDestComboBox4->setTextWhenNoChoicesAvailable ("(no choices)");
    m_pitchbendDestComboBox4->addItem ("OFF", 1);
    m_pitchbendDestComboBox4->addItem ("Pitch", 2);
    m_pitchbendDestComboBox4->addItem ("Filter Cutoff", 3);
    m_pitchbendDestComboBox4->addItem ("Filter Res", 4);
    m_pitchbendDestComboBox4->addItem ("Tone Level", 5);
    m_pitchbendDestComboBox4->addItem ("Tone Pan", 6);
    m_pitchbendDestComboBox4->addItem ("LFO1 Pitch", 7);
    m_pitchbendDestComboBox4->addItem ("LFO2 Pitch", 8);
    m_pitchbendDestComboBox4->addItem ("LFO1 Filter", 9);
    m_pitchbendDestComboBox4->addItem ("LFO2 Filter", 10);
    m_pitchbendDestComboBox4->addItem ("LFO1 Amp", 11);
    m_pitchbendDestComboBox4->addItem ("LFO2 Amp", 12);
    m_pitchbendDestComboBox4->addItem ("LFO1 Pan", 13);
    m_pitchbendDestComboBox4->addItem ("LFO2 Pan", 14);
    m_pitchbendDestComboBox4->addItem ("LFO1 Rate", 15);
    m_pitchbendDestComboBox4->addItem ("LFO2 Rate", 16);
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
    m_aftertouchDestComboBox1->setTextWhenNothingSelected ("OFF");
    m_aftertouchDestComboBox1->setTextWhenNoChoicesAvailable ("(no choices)");
    m_aftertouchDestComboBox1->addItem ("OFF", 1);
    m_aftertouchDestComboBox1->addItem ("Pitch", 2);
    m_aftertouchDestComboBox1->addItem ("Filter Cutoff", 3);
    m_aftertouchDestComboBox1->addItem ("Filter Res", 4);
    m_aftertouchDestComboBox1->addItem ("Tone Level", 5);
    m_aftertouchDestComboBox1->addItem ("Tone Pan", 6);
    m_aftertouchDestComboBox1->addItem ("LFO1 Pitch", 7);
    m_aftertouchDestComboBox1->addItem ("LFO2 Pitch", 8);
    m_aftertouchDestComboBox1->addItem ("LFO1 Filter", 9);
    m_aftertouchDestComboBox1->addItem ("LFO2 Filter", 10);
    m_aftertouchDestComboBox1->addItem ("LFO1 Amp", 11);
    m_aftertouchDestComboBox1->addItem ("LFO2 Amp", 12);
    m_aftertouchDestComboBox1->addItem ("LFO1 Pan", 13);
    m_aftertouchDestComboBox1->addItem ("LFO2 Pan", 14);
    m_aftertouchDestComboBox1->addItem ("LFO1 Rate", 15);
    m_aftertouchDestComboBox1->addItem ("LFO2 Rate", 16);
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
    m_aftertouchDestComboBox2->setTextWhenNothingSelected ("OFF");
    m_aftertouchDestComboBox2->setTextWhenNoChoicesAvailable ("(no choices)");
    m_aftertouchDestComboBox2->addItem ("OFF", 1);
    m_aftertouchDestComboBox2->addItem ("Pitch", 2);
    m_aftertouchDestComboBox2->addItem ("Filter Cutoff", 3);
    m_aftertouchDestComboBox2->addItem ("Filter Res", 4);
    m_aftertouchDestComboBox2->addItem ("Tone Level", 5);
    m_aftertouchDestComboBox2->addItem ("Tone Pan", 6);
    m_aftertouchDestComboBox2->addItem ("LFO1 Pitch", 7);
    m_aftertouchDestComboBox2->addItem ("LFO2 Pitch", 8);
    m_aftertouchDestComboBox2->addItem ("LFO1 Filter", 9);
    m_aftertouchDestComboBox2->addItem ("LFO2 Filter", 10);
    m_aftertouchDestComboBox2->addItem ("LFO1 Amp", 11);
    m_aftertouchDestComboBox2->addItem ("LFO2 Amp", 12);
    m_aftertouchDestComboBox2->addItem ("LFO1 Pan", 13);
    m_aftertouchDestComboBox2->addItem ("LFO2 Pan", 14);
    m_aftertouchDestComboBox2->addItem ("LFO1 Rate", 15);
    m_aftertouchDestComboBox2->addItem ("LFO2 Rate", 16);
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
    m_aftertouchDestComboBox3->setTextWhenNothingSelected ("OFF");
    m_aftertouchDestComboBox3->setTextWhenNoChoicesAvailable ("(no choices)");
    m_aftertouchDestComboBox3->addItem ("OFF", 1);
    m_aftertouchDestComboBox3->addItem ("Pitch", 2);
    m_aftertouchDestComboBox3->addItem ("Filter Cutoff", 3);
    m_aftertouchDestComboBox3->addItem ("Filter Res", 4);
    m_aftertouchDestComboBox3->addItem ("Tone Level", 5);
    m_aftertouchDestComboBox3->addItem ("Tone Pan", 6);
    m_aftertouchDestComboBox3->addItem ("LFO1 Pitch", 7);
    m_aftertouchDestComboBox3->addItem ("LFO2 Pitch", 8);
    m_aftertouchDestComboBox3->addItem ("LFO1 Filter", 9);
    m_aftertouchDestComboBox3->addItem ("LFO2 Filter", 10);
    m_aftertouchDestComboBox3->addItem ("LFO1 Amp", 11);
    m_aftertouchDestComboBox3->addItem ("LFO2 Amp", 12);
    m_aftertouchDestComboBox3->addItem ("LFO1 Pan", 13);
    m_aftertouchDestComboBox3->addItem ("LFO2 Pan", 14);
    m_aftertouchDestComboBox3->addItem ("LFO1 Rate", 15);
    m_aftertouchDestComboBox3->addItem ("LFO2 Rate", 16);
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
    m_aftertouchDestComboBox4->addItem ("OFF", 1);
    m_aftertouchDestComboBox4->addItem ("Pitch", 2);
    m_aftertouchDestComboBox4->addItem ("Filter Cutoff", 3);
    m_aftertouchDestComboBox4->addItem ("Filter Res", 4);
    m_aftertouchDestComboBox4->addItem ("Tone Level", 5);
    m_aftertouchDestComboBox4->addItem ("Tone Pan", 6);
    m_aftertouchDestComboBox4->addItem ("LFO1 Pitch", 7);
    m_aftertouchDestComboBox4->addItem ("LFO2 Pitch", 8);
    m_aftertouchDestComboBox4->addItem ("LFO1 Filter", 9);
    m_aftertouchDestComboBox4->addItem ("LFO2 Filter", 10);
    m_aftertouchDestComboBox4->addItem ("LFO1 Amp", 11);
    m_aftertouchDestComboBox4->addItem ("LFO2 Amp", 12);
    m_aftertouchDestComboBox4->addItem ("LFO1 Pan", 13);
    m_aftertouchDestComboBox4->addItem ("LFO2 Pan", 14);
    m_aftertouchDestComboBox4->addItem ("LFO1 Rate", 15);
    m_aftertouchDestComboBox4->addItem ("LFO2 Rate", 16);
    m_aftertouchDestComboBox4->addListener (this);

    addAndMakeVisible (m_aftertouchDestSlider4 = new MicroParameterSlider ("aftertouchDestSlider"));
    m_aftertouchDestSlider4->setRange (0, 127, 1);
    m_aftertouchDestSlider4->setSliderStyle (Slider::LinearBar);
    m_aftertouchDestSlider4->setTextBoxStyle (Slider::TextBoxLeft, false, 40, 20);
    m_aftertouchDestSlider4->setColour (Slider::backgroundColourId, Colour (0xfff2f59b));
    m_aftertouchDestSlider4->setColour (Slider::thumbColourId, Colour (0xffc4c86d));
    m_aftertouchDestSlider4->addListener (this);

    addAndMakeVisible (m_modulationLabel1 = new Label ("modulationLabel",
                                                       "1"));
    m_modulationLabel1->setFont (Font (12.00f, Font::bold));
    m_modulationLabel1->setJustificationType (Justification::centredRight);
    m_modulationLabel1->setEditable (false, false, false);
    m_modulationLabel1->setColour (Label::textColourId, Colours::black);
    m_modulationLabel1->setColour (TextEditor::textColourId, Colours::black);
    m_modulationLabel1->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_modulationLabel2 = new Label ("modulationLabel",
                                                       "2"));
    m_modulationLabel2->setFont (Font (12.00f, Font::bold));
    m_modulationLabel2->setJustificationType (Justification::centredRight);
    m_modulationLabel2->setEditable (false, false, false);
    m_modulationLabel2->setColour (Label::textColourId, Colours::black);
    m_modulationLabel2->setColour (TextEditor::textColourId, Colours::black);
    m_modulationLabel2->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_modulationLabel3 = new Label ("modulationLabel",
                                                       "3"));
    m_modulationLabel3->setFont (Font (12.00f, Font::bold));
    m_modulationLabel3->setJustificationType (Justification::centredRight);
    m_modulationLabel3->setEditable (false, false, false);
    m_modulationLabel3->setColour (Label::textColourId, Colours::black);
    m_modulationLabel3->setColour (TextEditor::textColourId, Colours::black);
    m_modulationLabel3->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_modulationLabel4 = new Label ("modulationLabel",
                                                       "4"));
    m_modulationLabel4->setFont (Font (12.00f, Font::bold));
    m_modulationLabel4->setJustificationType (Justification::centredRight);
    m_modulationLabel4->setEditable (false, false, false);
    m_modulationLabel4->setColour (Label::textColourId, Colours::black);
    m_modulationLabel4->setColour (TextEditor::textColourId, Colours::black);
    m_modulationLabel4->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_destLabel1 = new Label ("destLabel1",
                                                 "DESTINATION"));
    m_destLabel1->setFont (Font (12.00f, Font::bold));
    m_destLabel1->setJustificationType (Justification::centred);
    m_destLabel1->setEditable (false, false, false);
    m_destLabel1->setColour (Label::textColourId, Colours::black);
    m_destLabel1->setColour (TextEditor::textColourId, Colours::black);
    m_destLabel1->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_depthLabel1 = new Label ("depthLabel1",
                                                  "DEPTH"));
    m_depthLabel1->setFont (Font (12.00f, Font::bold));
    m_depthLabel1->setJustificationType (Justification::centred);
    m_depthLabel1->setEditable (false, false, false);
    m_depthLabel1->setColour (Label::textColourId, Colours::black);
    m_depthLabel1->setColour (TextEditor::textColourId, Colours::black);
    m_depthLabel1->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_destLabel2 = new Label ("destLabel2",
                                                 "DESTINATION"));
    m_destLabel2->setFont (Font (12.00f, Font::bold));
    m_destLabel2->setJustificationType (Justification::centred);
    m_destLabel2->setEditable (false, false, false);
    m_destLabel2->setColour (Label::textColourId, Colours::black);
    m_destLabel2->setColour (TextEditor::textColourId, Colours::black);
    m_destLabel2->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_depthLabel2 = new Label ("depthLabel2",
                                                  "DEPTH"));
    m_depthLabel2->setFont (Font (12.00f, Font::bold));
    m_depthLabel2->setJustificationType (Justification::centred);
    m_depthLabel2->setEditable (false, false, false);
    m_depthLabel2->setColour (Label::textColourId, Colours::black);
    m_depthLabel2->setColour (TextEditor::textColourId, Colours::black);
    m_depthLabel2->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_modulationLabel5 = new Label ("modulationLabel",
                                                       "1"));
    m_modulationLabel5->setFont (Font (12.00f, Font::bold));
    m_modulationLabel5->setJustificationType (Justification::centredRight);
    m_modulationLabel5->setEditable (false, false, false);
    m_modulationLabel5->setColour (Label::textColourId, Colours::black);
    m_modulationLabel5->setColour (TextEditor::textColourId, Colours::black);
    m_modulationLabel5->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_modulationLabel6 = new Label ("modulationLabel",
                                                       "2"));
    m_modulationLabel6->setFont (Font (12.00f, Font::bold));
    m_modulationLabel6->setJustificationType (Justification::centredRight);
    m_modulationLabel6->setEditable (false, false, false);
    m_modulationLabel6->setColour (Label::textColourId, Colours::black);
    m_modulationLabel6->setColour (TextEditor::textColourId, Colours::black);
    m_modulationLabel6->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_modulationLabel7 = new Label ("modulationLabel",
                                                       "3"));
    m_modulationLabel7->setFont (Font (12.00f, Font::bold));
    m_modulationLabel7->setJustificationType (Justification::centredRight);
    m_modulationLabel7->setEditable (false, false, false);
    m_modulationLabel7->setColour (Label::textColourId, Colours::black);
    m_modulationLabel7->setColour (TextEditor::textColourId, Colours::black);
    m_modulationLabel7->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_modulationLabel8 = new Label ("modulationLabel",
                                                       "4"));
    m_modulationLabel8->setFont (Font (12.00f, Font::bold));
    m_modulationLabel8->setJustificationType (Justification::centredRight);
    m_modulationLabel8->setEditable (false, false, false);
    m_modulationLabel8->setColour (Label::textColourId, Colours::black);
    m_modulationLabel8->setColour (TextEditor::textColourId, Colours::black);
    m_modulationLabel8->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_destLabel3 = new Label ("destLabel2",
                                                 "DESTINATION"));
    m_destLabel3->setFont (Font (12.00f, Font::bold));
    m_destLabel3->setJustificationType (Justification::centred);
    m_destLabel3->setEditable (false, false, false);
    m_destLabel3->setColour (Label::textColourId, Colours::black);
    m_destLabel3->setColour (TextEditor::textColourId, Colours::black);
    m_destLabel3->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_depthLabel3 = new Label ("depthLabel2",
                                                  "DEPTH"));
    m_depthLabel3->setFont (Font (12.00f, Font::bold));
    m_depthLabel3->setJustificationType (Justification::centred);
    m_depthLabel3->setEditable (false, false, false);
    m_depthLabel3->setColour (Label::textColourId, Colours::black);
    m_depthLabel3->setColour (TextEditor::textColourId, Colours::black);
    m_depthLabel3->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_modulationLabel9 = new Label ("modulationLabel",
                                                       "1"));
    m_modulationLabel9->setFont (Font (12.00f, Font::bold));
    m_modulationLabel9->setJustificationType (Justification::centredRight);
    m_modulationLabel9->setEditable (false, false, false);
    m_modulationLabel9->setColour (Label::textColourId, Colours::black);
    m_modulationLabel9->setColour (TextEditor::textColourId, Colours::black);
    m_modulationLabel9->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_modulationLabel10 = new Label ("modulationLabel",
                                                        "2"));
    m_modulationLabel10->setFont (Font (12.00f, Font::bold));
    m_modulationLabel10->setJustificationType (Justification::centredRight);
    m_modulationLabel10->setEditable (false, false, false);
    m_modulationLabel10->setColour (Label::textColourId, Colours::black);
    m_modulationLabel10->setColour (TextEditor::textColourId, Colours::black);
    m_modulationLabel10->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_modulationLabel11 = new Label ("modulationLabel",
                                                        "3"));
    m_modulationLabel11->setFont (Font (12.00f, Font::bold));
    m_modulationLabel11->setJustificationType (Justification::centredRight);
    m_modulationLabel11->setEditable (false, false, false);
    m_modulationLabel11->setColour (Label::textColourId, Colours::black);
    m_modulationLabel11->setColour (TextEditor::textColourId, Colours::black);
    m_modulationLabel11->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_modulationLabel12 = new Label ("modulationLabel",
                                                        "4"));
    m_modulationLabel12->setFont (Font (12.00f, Font::bold));
    m_modulationLabel12->setJustificationType (Justification::centredRight);
    m_modulationLabel12->setEditable (false, false, false);
    m_modulationLabel12->setColour (Label::textColourId, Colours::black);
    m_modulationLabel12->setColour (TextEditor::textColourId, Colours::black);
    m_modulationLabel12->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_bendUpLabel = new Label ("bendUpLabel",
                                                  "UP:"));
    m_bendUpLabel->setFont (Font (12.00f, Font::bold));
    m_bendUpLabel->setJustificationType (Justification::centredRight);
    m_bendUpLabel->setEditable (false, false, false);
    m_bendUpLabel->setColour (Label::textColourId, Colours::black);
    m_bendUpLabel->setColour (TextEditor::textColourId, Colours::black);
    m_bendUpLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_bendDownLabel = new Label ("bendDownLabel",
                                                    "DOWN:"));
    m_bendDownLabel->setFont (Font (12.00f, Font::bold));
    m_bendDownLabel->setJustificationType (Justification::centredRight);
    m_bendDownLabel->setEditable (false, false, false);
    m_bendDownLabel->setColour (Label::textColourId, Colours::black);
    m_bendDownLabel->setColour (TextEditor::textColourId, Colours::black);
    m_bendDownLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_bendCommonLabel = new Label ("bendCommonLabel",
                                                      "COMMON BEND RANGE\n"
                                                      "(FOR ALL 4 TONES)"));
    m_bendCommonLabel->setFont (Font (12.00f, Font::bold));
    m_bendCommonLabel->setJustificationType (Justification::centred);
    m_bendCommonLabel->setEditable (false, false, false);
    m_bendCommonLabel->setColour (Label::textColourId, Colours::black);
    m_bendCommonLabel->setColour (TextEditor::textColourId, Colours::black);
    m_bendCommonLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_bendUpSlider = new MicroParameterSlider ("bendUpSlider"));
    m_bendUpSlider->setRange (0, 127, 1);
    m_bendUpSlider->setSliderStyle (Slider::LinearBar);
    m_bendUpSlider->setTextBoxStyle (Slider::TextBoxLeft, false, 40, 20);
    m_bendUpSlider->setColour (Slider::backgroundColourId, Colour (0xfff2f59b));
    m_bendUpSlider->setColour (Slider::thumbColourId, Colour (0xffc4c86d));
    m_bendUpSlider->addListener (this);

    addAndMakeVisible (m_bendDownSlider = new MicroParameterSlider ("bendDownSlider"));
    m_bendDownSlider->setRange (0, 127, 1);
    m_bendDownSlider->setSliderStyle (Slider::LinearBar);
    m_bendDownSlider->setTextBoxStyle (Slider::TextBoxLeft, false, 40, 20);
    m_bendDownSlider->setColour (Slider::backgroundColourId, Colour (0xfff2f59b));
    m_bendDownSlider->setColour (Slider::thumbColourId, Colour (0xffc4c86d));
    m_bendDownSlider->addListener (this);

    addAndMakeVisible (m_bendRangeImage = new ImageButton ("bendRangeImage"));
    m_bendRangeImage->setButtonText ("new button");

    m_bendRangeImage->setImages (false, true, false,
                                 ImageCache::getFromMemory (pitchBendLever_png, pitchBendLever_pngSize), 1.000f, Colour (0x00000000),
                                 ImageCache::getFromMemory (pitchBendLever_png, pitchBendLever_pngSize), 1.000f, Colour (0x00000000),
                                 Image(), 1.000f, Colour (0x00000000));
    addAndMakeVisible (m_line = new Label ("line",
                                           String::empty));
    m_line->setFont (Font (15.00f, Font::plain));
    m_line->setJustificationType (Justification::centredLeft);
    m_line->setEditable (false, false, false);
    m_line->setColour (Label::outlineColourId, Colours::black);
    m_line->setColour (TextEditor::textColourId, Colours::black);
    m_line->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_line2 = new Label ("line",
                                            String::empty));
    m_line2->setFont (Font (15.00f, Font::plain));
    m_line2->setJustificationType (Justification::centredLeft);
    m_line2->setEditable (false, false, false);
    m_line2->setColour (Label::outlineColourId, Colours::black);
    m_line2->setColour (TextEditor::textColourId, Colours::black);
    m_line2->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (imageButton4 = new ImageButton ("new button"));
    imageButton4->setButtonText (String::empty);

    imageButton4->setImages (false, true, true,
                             ImageCache::getFromMemory (modulation_png, modulation_pngSize), 1.000f, Colour (0x4340454a),
                             Image(), 1.000f, Colour (0x4340454a),
                             Image(), 1.000f, Colour (0x4340454a));

    //[UserPreSize]
    m_controllersGrp->setText("CONTROL MATRIX FOR PART "+ String(part+1) + " TONE "+ String(((tone-4096)/512)+1));
    //[/UserPreSize]

    setSize (516, 252);


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
	}
    //[/Constructor]
}

PatchControllerMatrixEditor::~PatchControllerMatrixEditor()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
	if (m_bendUpSlider->getParamPtr() != nullptr) m_bendUpSlider->getParamPtr()->removeChangeListener(m_bendUpSlider);
	if (m_bendDownSlider->getParamPtr() != nullptr) m_bendDownSlider->getParamPtr()->removeChangeListener(m_bendDownSlider);
	if (m_modDestComboBox1->getParamPtr() != nullptr) m_modDestComboBox1->getParamPtr()->removeChangeListener(m_modDestComboBox1);
	if (m_modDestSlider1->getParamPtr() != nullptr) m_modDestSlider1->getParamPtr()->removeChangeListener(m_modDestSlider1);
	if (m_modDestComboBox2->getParamPtr() != nullptr) m_modDestComboBox2->getParamPtr()->removeChangeListener(m_modDestComboBox2);
	if (m_modDestSlider2->getParamPtr() != nullptr) m_modDestSlider2->getParamPtr()->removeChangeListener(m_modDestSlider2);
	if (m_modDestComboBox3->getParamPtr() != nullptr) m_modDestComboBox3->getParamPtr()->removeChangeListener(m_modDestComboBox3);
	if (m_modDestSlider3->getParamPtr() != nullptr) m_modDestSlider3->getParamPtr()->removeChangeListener(m_modDestSlider3);
	if (m_modDestComboBox4->getParamPtr() != nullptr) m_modDestComboBox4->getParamPtr()->removeChangeListener(m_modDestComboBox4);
	if (m_modDestSlider4->getParamPtr() != nullptr) m_modDestSlider4->getParamPtr()->removeChangeListener(m_modDestSlider4);
	if (m_pitchbendDestComboBox1->getParamPtr() != nullptr) m_pitchbendDestComboBox1->getParamPtr()->removeChangeListener(m_pitchbendDestComboBox1);
	if (m_pitchbendDestSlider1->getParamPtr() != nullptr) m_pitchbendDestSlider1->getParamPtr()->removeChangeListener(m_pitchbendDestSlider1);
	if (m_pitchbendDestComboBox2->getParamPtr() != nullptr) m_pitchbendDestComboBox2->getParamPtr()->removeChangeListener(m_pitchbendDestComboBox2);
	if (m_pitchbendDestSlider2->getParamPtr() != nullptr) m_pitchbendDestSlider2->getParamPtr()->removeChangeListener(m_pitchbendDestSlider2);
	if (m_pitchbendDestComboBox3->getParamPtr() != nullptr) m_pitchbendDestComboBox3->getParamPtr()->removeChangeListener(m_pitchbendDestComboBox3);
	if (m_pitchbendDestSlider3->getParamPtr() != nullptr) m_pitchbendDestSlider3->getParamPtr()->removeChangeListener(m_pitchbendDestSlider3);
	if (m_pitchbendDestComboBox4->getParamPtr() != nullptr) m_pitchbendDestComboBox4->getParamPtr()->removeChangeListener(m_pitchbendDestComboBox4);
	if (m_pitchbendDestSlider4->getParamPtr() != nullptr) m_pitchbendDestSlider4->getParamPtr()->removeChangeListener(m_pitchbendDestSlider4);
	if (m_aftertouchDestComboBox1->getParamPtr() != nullptr) m_aftertouchDestComboBox1->getParamPtr()->removeChangeListener(m_aftertouchDestComboBox1);
	if (m_aftertouchDestSlider1->getParamPtr() != nullptr) m_aftertouchDestSlider1->getParamPtr()->removeChangeListener(m_aftertouchDestSlider1);
	if (m_aftertouchDestComboBox2->getParamPtr() != nullptr) m_aftertouchDestComboBox2->getParamPtr()->removeChangeListener(m_aftertouchDestComboBox2);
	if (m_aftertouchDestSlider2->getParamPtr() != nullptr) m_aftertouchDestSlider2->getParamPtr()->removeChangeListener(m_aftertouchDestSlider2);
	if (m_aftertouchDestComboBox3->getParamPtr() != nullptr) m_aftertouchDestComboBox3->getParamPtr()->removeChangeListener(m_aftertouchDestComboBox3);
	if (m_aftertouchDestSlider3->getParamPtr() != nullptr) m_aftertouchDestSlider3->getParamPtr()->removeChangeListener(m_aftertouchDestSlider3);
	if (m_aftertouchDestComboBox4->getParamPtr() != nullptr) m_aftertouchDestComboBox4->getParamPtr()->removeChangeListener(m_aftertouchDestComboBox4);
	if (m_aftertouchDestSlider4->getParamPtr() != nullptr) m_aftertouchDestSlider4->getParamPtr()->removeChangeListener(m_aftertouchDestSlider4);
    //[/Destructor_pre]

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
    m_modulationLabel1 = nullptr;
    m_modulationLabel2 = nullptr;
    m_modulationLabel3 = nullptr;
    m_modulationLabel4 = nullptr;
    m_destLabel1 = nullptr;
    m_depthLabel1 = nullptr;
    m_destLabel2 = nullptr;
    m_depthLabel2 = nullptr;
    m_modulationLabel5 = nullptr;
    m_modulationLabel6 = nullptr;
    m_modulationLabel7 = nullptr;
    m_modulationLabel8 = nullptr;
    m_destLabel3 = nullptr;
    m_depthLabel3 = nullptr;
    m_modulationLabel9 = nullptr;
    m_modulationLabel10 = nullptr;
    m_modulationLabel11 = nullptr;
    m_modulationLabel12 = nullptr;
    m_bendUpLabel = nullptr;
    m_bendDownLabel = nullptr;
    m_bendCommonLabel = nullptr;
    m_bendUpSlider = nullptr;
    m_bendDownSlider = nullptr;
    m_bendRangeImage = nullptr;
    m_line = nullptr;
    m_line2 = nullptr;
    imageButton4 = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void PatchControllerMatrixEditor::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
	#ifdef JUCE_MSVC
	g;
	#endif
    //[/UserPrePaint]

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void PatchControllerMatrixEditor::resized()
{
    m_controllersGrp->setBounds (0, 0, getWidth() - 0, getHeight() - 0);
    m_modulationLabel->setBounds (13, 16, 144, 16);
    m_modDestComboBox1->setBounds (17, 56, 80, 16);
    m_modDestComboBox2->setBounds (17, 84, 80, 16);
    m_modDestComboBox3->setBounds (17, 112, 80, 16);
    m_modDestComboBox4->setBounds (17, 140, 80, 16);
    m_pitchbendLabel->setBounds (185, 16, 144, 16);
    m_aftertouchLabel->setBounds (365, 16, 144, 16);
    m_modDestSlider1->setBounds (105, 56, 56, 16);
    m_modDestSlider2->setBounds (105, 84, 56, 16);
    m_modDestSlider3->setBounds (105, 112, 56, 16);
    m_modDestSlider4->setBounds (105, 140, 56, 16);
    m_pitchbendDestComboBox1->setBounds (189, 56, 80, 16);
    m_pitchbendDestSlider1->setBounds (277, 56, 56, 16);
    m_pitchbendDestComboBox2->setBounds (189, 84, 80, 16);
    m_pitchbendDestSlider2->setBounds (277, 84, 56, 16);
    m_pitchbendDestComboBox3->setBounds (189, 112, 80, 16);
    m_pitchbendDestSlider3->setBounds (277, 112, 56, 16);
    m_pitchbendDestComboBox4->setBounds (189, 140, 80, 16);
    m_pitchbendDestSlider4->setBounds (277, 140, 56, 16);
    m_aftertouchDestComboBox1->setBounds (365, 56, 80, 16);
    m_aftertouchDestSlider1->setBounds (453, 56, 56, 16);
    m_aftertouchDestComboBox2->setBounds (365, 84, 80, 16);
    m_aftertouchDestSlider2->setBounds (453, 84, 56, 16);
    m_aftertouchDestComboBox3->setBounds (365, 112, 80, 16);
    m_aftertouchDestSlider3->setBounds (453, 112, 56, 16);
    m_aftertouchDestComboBox4->setBounds (365, 140, 80, 16);
    m_aftertouchDestSlider4->setBounds (453, 140, 56, 16);
    m_modulationLabel1->setBounds (1, 56, 16, 16);
    m_modulationLabel2->setBounds (1, 84, 16, 16);
    m_modulationLabel3->setBounds (1, 112, 16, 16);
    m_modulationLabel4->setBounds (1, 140, 16, 16);
    m_destLabel1->setBounds (13, 36, 88, 16);
    m_depthLabel1->setBounds (109, 36, 48, 16);
    m_destLabel2->setBounds (185, 36, 88, 16);
    m_depthLabel2->setBounds (281, 36, 48, 16);
    m_modulationLabel5->setBounds (173, 56, 16, 16);
    m_modulationLabel6->setBounds (173, 84, 16, 16);
    m_modulationLabel7->setBounds (173, 112, 16, 16);
    m_modulationLabel8->setBounds (173, 140, 16, 16);
    m_destLabel3->setBounds (365, 36, 88, 16);
    m_depthLabel3->setBounds (461, 36, 48, 16);
    m_modulationLabel9->setBounds (349, 56, 16, 16);
    m_modulationLabel10->setBounds (349, 84, 16, 16);
    m_modulationLabel11->setBounds (349, 112, 16, 16);
    m_modulationLabel12->setBounds (349, 140, 16, 16);
    m_bendUpLabel->setBounds (189, 196, 80, 16);
    m_bendDownLabel->setBounds (189, 224, 80, 16);
    m_bendCommonLabel->setBounds (185, 164, 144, 32);
    m_bendUpSlider->setBounds (277, 196, 56, 16);
    m_bendDownSlider->setBounds (277, 224, 56, 16);
    m_bendRangeImage->setBounds (205, 198, 63, 27);
    m_line->setBounds (172, 16, 1, 232);
    m_line2->setBounds (348, 16, 1, 232);
    imageButton4->setBounds (3, 1, 16, 16);
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void PatchControllerMatrixEditor::comboBoxChanged (ComboBox* comboBoxThatHasChanged)
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

void PatchControllerMatrixEditor::sliderValueChanged (Slider* sliderThatWasMoved)
{
    //[UsersliderValueChanged_Pre]
    //[/UsersliderValueChanged_Pre]

    if (sliderThatWasMoved == m_modDestSlider1)
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
    else if (sliderThatWasMoved == m_bendUpSlider)
    {
        //[UserSliderCode_m_bendUpSlider] -- add your slider handling code here..
        //[/UserSliderCode_m_bendUpSlider]
    }
    else if (sliderThatWasMoved == m_bendDownSlider)
    {
        //[UserSliderCode_m_bendDownSlider] -- add your slider handling code here..
        //[/UserSliderCode_m_bendDownSlider]
    }

    //[UsersliderValueChanged_Post]
    //[/UsersliderValueChanged_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Introjucer information section --

    This is where the Introjucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="PatchControllerMatrixEditor"
                 componentName="" parentClasses="public Component" constructorParams="const String &amp;componentName, SynthParts part, Tone tone"
                 variableInitialisers="Component (componentName), m_part(part), m_tone(tone)"
                 snapPixels="4" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="1" initialWidth="516" initialHeight="252">
  <BACKGROUND backgroundColour="0"/>
  <JUCERCOMP name="controllersGrp" id="b1682db57b20287e" memberName="m_controllersGrp"
             virtualName="" explicitFocusOrder="0" pos="0 0 0M 0M" sourceFile="../GroupWidgets/PanelGroupGrey.cpp"
             constructorParams="&quot;ControllersGrp&quot;,&quot;CONTROLLERS&quot;"/>
  <LABEL name="modulationLabel" id="7b351347affdb490" memberName="m_modulationLabel"
         virtualName="" explicitFocusOrder="0" pos="13 16 144 16" textCol="ff000000"
         edTextCol="ff000000" edBkgCol="0" labelText="MODULATION CONTROL"
         editableSingleClick="0" editableDoubleClick="0" focusDiscardsChanges="0"
         fontname="Default font" fontsize="12" bold="1" italic="0" justification="36"/>
  <COMBOBOX name="modDestComboBox" id="5f5f3969c23f54e2" memberName="m_modDestComboBox1"
            virtualName="ParameterComboBox" explicitFocusOrder="0" pos="17 56 80 16"
            editable="0" layout="33" items="OFF&#10;Pitch&#10;Filter Cutoff&#10;Filter Res&#10;Tone Level&#10;Tone Pan&#10;LFO1 Pitch&#10;LFO2 Pitch&#10;LFO1 Filter&#10;LFO2 Filter&#10;LFO1 Amp&#10;LFO2 Amp&#10;LFO1 Pan&#10;LFO2 Pan&#10;LFO1 Rate&#10;LFO2 Rate"
            textWhenNonSelected="OFF" textWhenNoItems="(no choices)"/>
  <COMBOBOX name="modDestComboBox" id="771446e138706472" memberName="m_modDestComboBox2"
            virtualName="ParameterComboBox" explicitFocusOrder="0" pos="17 84 80 16"
            editable="0" layout="33" items="OFF&#10;Pitch&#10;Filter Cutoff&#10;Filter Res&#10;Tone Level&#10;Tone Pan&#10;LFO1 Pitch&#10;LFO2 Pitch&#10;LFO1 Filter&#10;LFO2 Filter&#10;LFO1 Amp&#10;LFO2 Amp&#10;LFO1 Pan&#10;LFO2 Pan&#10;LFO1 Rate&#10;LFO2 Rate"
            textWhenNonSelected="OFF" textWhenNoItems="(no choices)"/>
  <COMBOBOX name="modDestComboBox" id="6dd02b8276c17234" memberName="m_modDestComboBox3"
            virtualName="ParameterComboBox" explicitFocusOrder="0" pos="17 112 80 16"
            editable="0" layout="33" items="OFF&#10;Pitch&#10;Filter Cutoff&#10;Filter Res&#10;Tone Level&#10;Tone Pan&#10;LFO1 Pitch&#10;LFO2 Pitch&#10;LFO1 Filter&#10;LFO2 Filter&#10;LFO1 Amp&#10;LFO2 Amp&#10;LFO1 Pan&#10;LFO2 Pan&#10;LFO1 Rate&#10;LFO2 Rate"
            textWhenNonSelected="OFF" textWhenNoItems="(no choices)"/>
  <COMBOBOX name="modDestComboBox" id="4f44976e3785b130" memberName="m_modDestComboBox4"
            virtualName="ParameterComboBox" explicitFocusOrder="0" pos="17 140 80 16"
            editable="0" layout="33" items="OFF&#10;Pitch&#10;Filter Cutoff&#10;Filter Res&#10;Tone Level&#10;Tone Pan&#10;LFO1 Pitch&#10;LFO2 Pitch&#10;LFO1 Filter&#10;LFO2 Filter&#10;LFO1 Amp&#10;LFO2 Amp&#10;LFO1 Pan&#10;LFO2 Pan&#10;LFO1 Rate&#10;LFO2 Rate"
            textWhenNonSelected="OFF" textWhenNoItems="(no choices)"/>
  <LABEL name="pitchbendLabel" id="970628036020a7e" memberName="m_pitchbendLabel"
         virtualName="" explicitFocusOrder="0" pos="185 16 144 16" textCol="ff000000"
         edTextCol="ff000000" edBkgCol="0" labelText="PITCH BEND CONTROL"
         editableSingleClick="0" editableDoubleClick="0" focusDiscardsChanges="0"
         fontname="Default font" fontsize="12" bold="1" italic="0" justification="36"/>
  <LABEL name="aftertouchLabel" id="c2aa167417218a4" memberName="m_aftertouchLabel"
         virtualName="" explicitFocusOrder="0" pos="365 16 144 16" textCol="ff000000"
         edTextCol="ff000000" edBkgCol="0" labelText="AFTERTOUCH CONTROL"
         editableSingleClick="0" editableDoubleClick="0" focusDiscardsChanges="0"
         fontname="Default font" fontsize="12" bold="1" italic="0" justification="36"/>
  <SLIDER name="modDestSlider" id="e90b1ea2a9f03eaf" memberName="m_modDestSlider1"
          virtualName="MicroParameterSlider" explicitFocusOrder="0" pos="105 56 56 16"
          bkgcol="fff2f59b" thumbcol="ffc4c86d" min="0" max="127" int="1"
          style="LinearBar" textBoxPos="TextBoxLeft" textBoxEditable="1"
          textBoxWidth="40" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="modDestSlider" id="a0c69a60b8ce07c9" memberName="m_modDestSlider2"
          virtualName="MicroParameterSlider" explicitFocusOrder="0" pos="105 84 56 16"
          bkgcol="fff2f59b" thumbcol="ffc4c86d" min="0" max="127" int="1"
          style="LinearBar" textBoxPos="TextBoxLeft" textBoxEditable="1"
          textBoxWidth="40" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="modDestSlider" id="2403725c31cd4313" memberName="m_modDestSlider3"
          virtualName="MicroParameterSlider" explicitFocusOrder="0" pos="105 112 56 16"
          bkgcol="fff2f59b" thumbcol="ffc4c86d" min="0" max="127" int="1"
          style="LinearBar" textBoxPos="TextBoxLeft" textBoxEditable="1"
          textBoxWidth="40" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="modDestSlider" id="cc0c5881f6b7a023" memberName="m_modDestSlider4"
          virtualName="MicroParameterSlider" explicitFocusOrder="0" pos="105 140 56 16"
          bkgcol="fff2f59b" thumbcol="ffc4c86d" min="0" max="127" int="1"
          style="LinearBar" textBoxPos="TextBoxLeft" textBoxEditable="1"
          textBoxWidth="40" textBoxHeight="20" skewFactor="1"/>
  <COMBOBOX name="pitchbendDestComboBox" id="f1c8aff4c931d28f" memberName="m_pitchbendDestComboBox1"
            virtualName="ParameterComboBox" explicitFocusOrder="0" pos="189 56 80 16"
            editable="0" layout="33" items="OFF&#10;Pitch&#10;Filter Cutoff&#10;Filter Res&#10;Tone Level&#10;Tone Pan&#10;LFO1 Pitch&#10;LFO2 Pitch&#10;LFO1 Filter&#10;LFO2 Filter&#10;LFO1 Amp&#10;LFO2 Amp&#10;LFO1 Pan&#10;LFO2 Pan&#10;LFO1 Rate&#10;LFO2 Rate"
            textWhenNonSelected="OFF" textWhenNoItems="(no choices)"/>
  <SLIDER name="pitchbendDestSlider" id="a3041600e48a43d6" memberName="m_pitchbendDestSlider1"
          virtualName="MicroParameterSlider" explicitFocusOrder="0" pos="277 56 56 16"
          bkgcol="fff2f59b" thumbcol="ffc4c86d" min="0" max="127" int="1"
          style="LinearBar" textBoxPos="TextBoxLeft" textBoxEditable="1"
          textBoxWidth="40" textBoxHeight="20" skewFactor="1"/>
  <COMBOBOX name="pitchbendDestComboBox" id="3c71809600dc3a9c" memberName="m_pitchbendDestComboBox2"
            virtualName="ParameterComboBox" explicitFocusOrder="0" pos="189 84 80 16"
            editable="0" layout="33" items="OFF&#10;Pitch&#10;Filter Cutoff&#10;Filter Res&#10;Tone Level&#10;Tone Pan&#10;LFO1 Pitch&#10;LFO2 Pitch&#10;LFO1 Filter&#10;LFO2 Filter&#10;LFO1 Amp&#10;LFO2 Amp&#10;LFO1 Pan&#10;LFO2 Pan&#10;LFO1 Rate&#10;LFO2 Rate"
            textWhenNonSelected="OFF" textWhenNoItems="(no choices)"/>
  <SLIDER name="pitchbendDestSlider" id="87cddee3503965fd" memberName="m_pitchbendDestSlider2"
          virtualName="MicroParameterSlider" explicitFocusOrder="0" pos="277 84 56 16"
          bkgcol="fff2f59b" thumbcol="ffc4c86d" min="0" max="127" int="1"
          style="LinearBar" textBoxPos="TextBoxLeft" textBoxEditable="1"
          textBoxWidth="40" textBoxHeight="20" skewFactor="1"/>
  <COMBOBOX name="pitchbendDestComboBox" id="d7754475a590b5e2" memberName="m_pitchbendDestComboBox3"
            virtualName="ParameterComboBox" explicitFocusOrder="0" pos="189 112 80 16"
            editable="0" layout="33" items="OFF&#10;Pitch&#10;Filter Cutoff&#10;Filter Res&#10;Tone Level&#10;Tone Pan&#10;LFO1 Pitch&#10;LFO2 Pitch&#10;LFO1 Filter&#10;LFO2 Filter&#10;LFO1 Amp&#10;LFO2 Amp&#10;LFO1 Pan&#10;LFO2 Pan&#10;LFO1 Rate&#10;LFO2 Rate"
            textWhenNonSelected="OFF" textWhenNoItems="(no choices)"/>
  <SLIDER name="pitchbendDestSlider" id="4713cc6004cd872a" memberName="m_pitchbendDestSlider3"
          virtualName="MicroParameterSlider" explicitFocusOrder="0" pos="277 112 56 16"
          bkgcol="fff2f59b" thumbcol="ffc4c86d" min="0" max="127" int="1"
          style="LinearBar" textBoxPos="TextBoxLeft" textBoxEditable="1"
          textBoxWidth="40" textBoxHeight="20" skewFactor="1"/>
  <COMBOBOX name="pitchbendDestComboBox" id="cb3f18fd42248fb1" memberName="m_pitchbendDestComboBox4"
            virtualName="ParameterComboBox" explicitFocusOrder="0" pos="189 140 80 16"
            editable="0" layout="33" items="OFF&#10;Pitch&#10;Filter Cutoff&#10;Filter Res&#10;Tone Level&#10;Tone Pan&#10;LFO1 Pitch&#10;LFO2 Pitch&#10;LFO1 Filter&#10;LFO2 Filter&#10;LFO1 Amp&#10;LFO2 Amp&#10;LFO1 Pan&#10;LFO2 Pan&#10;LFO1 Rate&#10;LFO2 Rate"
            textWhenNonSelected="OFF" textWhenNoItems="(no choices)"/>
  <SLIDER name="pitchbendDestSlider" id="545815f3cafc1ec2" memberName="m_pitchbendDestSlider4"
          virtualName="MicroParameterSlider" explicitFocusOrder="0" pos="277 140 56 16"
          bkgcol="fff2f59b" thumbcol="ffc4c86d" min="0" max="127" int="1"
          style="LinearBar" textBoxPos="TextBoxLeft" textBoxEditable="1"
          textBoxWidth="40" textBoxHeight="20" skewFactor="1"/>
  <COMBOBOX name="aftertouchDestComboBox" id="ae961678edb4578" memberName="m_aftertouchDestComboBox1"
            virtualName="ParameterComboBox" explicitFocusOrder="0" pos="365 56 80 16"
            editable="0" layout="33" items="OFF&#10;Pitch&#10;Filter Cutoff&#10;Filter Res&#10;Tone Level&#10;Tone Pan&#10;LFO1 Pitch&#10;LFO2 Pitch&#10;LFO1 Filter&#10;LFO2 Filter&#10;LFO1 Amp&#10;LFO2 Amp&#10;LFO1 Pan&#10;LFO2 Pan&#10;LFO1 Rate&#10;LFO2 Rate"
            textWhenNonSelected="OFF" textWhenNoItems="(no choices)"/>
  <SLIDER name="aftertouchDestSlider" id="b6a63c9b656f3e48" memberName="m_aftertouchDestSlider1"
          virtualName="MicroParameterSlider" explicitFocusOrder="0" pos="453 56 56 16"
          bkgcol="fff2f59b" thumbcol="ffc4c86d" min="0" max="127" int="1"
          style="LinearBar" textBoxPos="TextBoxLeft" textBoxEditable="1"
          textBoxWidth="40" textBoxHeight="20" skewFactor="1"/>
  <COMBOBOX name="aftertouchDestComboBox" id="8bd1536b9a229e76" memberName="m_aftertouchDestComboBox2"
            virtualName="ParameterComboBox" explicitFocusOrder="0" pos="365 84 80 16"
            editable="0" layout="33" items="OFF&#10;Pitch&#10;Filter Cutoff&#10;Filter Res&#10;Tone Level&#10;Tone Pan&#10;LFO1 Pitch&#10;LFO2 Pitch&#10;LFO1 Filter&#10;LFO2 Filter&#10;LFO1 Amp&#10;LFO2 Amp&#10;LFO1 Pan&#10;LFO2 Pan&#10;LFO1 Rate&#10;LFO2 Rate"
            textWhenNonSelected="OFF" textWhenNoItems="(no choices)"/>
  <SLIDER name="aftertouchDestSlider" id="b7ea5857540707b8" memberName="m_aftertouchDestSlider2"
          virtualName="MicroParameterSlider" explicitFocusOrder="0" pos="453 84 56 16"
          bkgcol="fff2f59b" thumbcol="ffc4c86d" min="0" max="127" int="1"
          style="LinearBar" textBoxPos="TextBoxLeft" textBoxEditable="1"
          textBoxWidth="40" textBoxHeight="20" skewFactor="1"/>
  <COMBOBOX name="aftertouchDestComboBox" id="eb932ac155acda76" memberName="m_aftertouchDestComboBox3"
            virtualName="ParameterComboBox" explicitFocusOrder="0" pos="365 112 80 16"
            editable="0" layout="33" items="OFF&#10;Pitch&#10;Filter Cutoff&#10;Filter Res&#10;Tone Level&#10;Tone Pan&#10;LFO1 Pitch&#10;LFO2 Pitch&#10;LFO1 Filter&#10;LFO2 Filter&#10;LFO1 Amp&#10;LFO2 Amp&#10;LFO1 Pan&#10;LFO2 Pan&#10;LFO1 Rate&#10;LFO2 Rate"
            textWhenNonSelected="OFF" textWhenNoItems="(no choices)"/>
  <SLIDER name="aftertouchDestSlider" id="91a760d063513cf9" memberName="m_aftertouchDestSlider3"
          virtualName="MicroParameterSlider" explicitFocusOrder="0" pos="453 112 56 16"
          bkgcol="fff2f59b" thumbcol="ffc4c86d" min="0" max="127" int="1"
          style="LinearBar" textBoxPos="TextBoxLeft" textBoxEditable="1"
          textBoxWidth="40" textBoxHeight="20" skewFactor="1"/>
  <COMBOBOX name="aftertouchDestComboBox" id="2643f9236d3349d9" memberName="m_aftertouchDestComboBox4"
            virtualName="ParameterComboBox" explicitFocusOrder="0" pos="365 140 80 16"
            editable="0" layout="33" items="OFF&#10;Pitch&#10;Filter Cutoff&#10;Filter Res&#10;Tone Level&#10;Tone Pan&#10;LFO1 Pitch&#10;LFO2 Pitch&#10;LFO1 Filter&#10;LFO2 Filter&#10;LFO1 Amp&#10;LFO2 Amp&#10;LFO1 Pan&#10;LFO2 Pan&#10;LFO1 Rate&#10;LFO2 Rate"
            textWhenNonSelected="" textWhenNoItems="(no choices)"/>
  <SLIDER name="aftertouchDestSlider" id="349543ba9a2367af" memberName="m_aftertouchDestSlider4"
          virtualName="MicroParameterSlider" explicitFocusOrder="0" pos="453 140 56 16"
          bkgcol="fff2f59b" thumbcol="ffc4c86d" min="0" max="127" int="1"
          style="LinearBar" textBoxPos="TextBoxLeft" textBoxEditable="1"
          textBoxWidth="40" textBoxHeight="20" skewFactor="1"/>
  <LABEL name="modulationLabel" id="cb652f71aa723f54" memberName="m_modulationLabel1"
         virtualName="" explicitFocusOrder="0" pos="1 56 16 16" textCol="ff000000"
         edTextCol="ff000000" edBkgCol="0" labelText="1" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="12" bold="1" italic="0" justification="34"/>
  <LABEL name="modulationLabel" id="30a1d69710d5c680" memberName="m_modulationLabel2"
         virtualName="" explicitFocusOrder="0" pos="1 84 16 16" textCol="ff000000"
         edTextCol="ff000000" edBkgCol="0" labelText="2" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="12" bold="1" italic="0" justification="34"/>
  <LABEL name="modulationLabel" id="401fe4f4e8d70f40" memberName="m_modulationLabel3"
         virtualName="" explicitFocusOrder="0" pos="1 112 16 16" textCol="ff000000"
         edTextCol="ff000000" edBkgCol="0" labelText="3" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="12" bold="1" italic="0" justification="34"/>
  <LABEL name="modulationLabel" id="549518ec8fb63042" memberName="m_modulationLabel4"
         virtualName="" explicitFocusOrder="0" pos="1 140 16 16" textCol="ff000000"
         edTextCol="ff000000" edBkgCol="0" labelText="4" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="12" bold="1" italic="0" justification="34"/>
  <LABEL name="destLabel1" id="2786e9c8788ea3c4" memberName="m_destLabel1"
         virtualName="" explicitFocusOrder="0" pos="13 36 88 16" textCol="ff000000"
         edTextCol="ff000000" edBkgCol="0" labelText="DESTINATION" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="12" bold="1" italic="0" justification="36"/>
  <LABEL name="depthLabel1" id="21f52639be330ecf" memberName="m_depthLabel1"
         virtualName="" explicitFocusOrder="0" pos="109 36 48 16" textCol="ff000000"
         edTextCol="ff000000" edBkgCol="0" labelText="DEPTH" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="12" bold="1" italic="0" justification="36"/>
  <LABEL name="destLabel2" id="918386546fc328c7" memberName="m_destLabel2"
         virtualName="" explicitFocusOrder="0" pos="185 36 88 16" textCol="ff000000"
         edTextCol="ff000000" edBkgCol="0" labelText="DESTINATION" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="12" bold="1" italic="0" justification="36"/>
  <LABEL name="depthLabel2" id="13104128da56f093" memberName="m_depthLabel2"
         virtualName="" explicitFocusOrder="0" pos="281 36 48 16" textCol="ff000000"
         edTextCol="ff000000" edBkgCol="0" labelText="DEPTH" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="12" bold="1" italic="0" justification="36"/>
  <LABEL name="modulationLabel" id="4a3626d42673e74" memberName="m_modulationLabel5"
         virtualName="" explicitFocusOrder="0" pos="173 56 16 16" textCol="ff000000"
         edTextCol="ff000000" edBkgCol="0" labelText="1" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="12" bold="1" italic="0" justification="34"/>
  <LABEL name="modulationLabel" id="dacd4d2db5cbee49" memberName="m_modulationLabel6"
         virtualName="" explicitFocusOrder="0" pos="173 84 16 16" textCol="ff000000"
         edTextCol="ff000000" edBkgCol="0" labelText="2" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="12" bold="1" italic="0" justification="34"/>
  <LABEL name="modulationLabel" id="70bbd7e8da31e7dd" memberName="m_modulationLabel7"
         virtualName="" explicitFocusOrder="0" pos="173 112 16 16" textCol="ff000000"
         edTextCol="ff000000" edBkgCol="0" labelText="3" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="12" bold="1" italic="0" justification="34"/>
  <LABEL name="modulationLabel" id="894d9b3c20e55487" memberName="m_modulationLabel8"
         virtualName="" explicitFocusOrder="0" pos="173 140 16 16" textCol="ff000000"
         edTextCol="ff000000" edBkgCol="0" labelText="4" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="12" bold="1" italic="0" justification="34"/>
  <LABEL name="destLabel2" id="2c4105c2f492c223" memberName="m_destLabel3"
         virtualName="" explicitFocusOrder="0" pos="365 36 88 16" textCol="ff000000"
         edTextCol="ff000000" edBkgCol="0" labelText="DESTINATION" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="12" bold="1" italic="0" justification="36"/>
  <LABEL name="depthLabel2" id="3f6fcca42fe998c4" memberName="m_depthLabel3"
         virtualName="" explicitFocusOrder="0" pos="461 36 48 16" textCol="ff000000"
         edTextCol="ff000000" edBkgCol="0" labelText="DEPTH" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="12" bold="1" italic="0" justification="36"/>
  <LABEL name="modulationLabel" id="4baaa9c92f695651" memberName="m_modulationLabel9"
         virtualName="" explicitFocusOrder="0" pos="349 56 16 16" textCol="ff000000"
         edTextCol="ff000000" edBkgCol="0" labelText="1" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="12" bold="1" italic="0" justification="34"/>
  <LABEL name="modulationLabel" id="728f3ab5847c4755" memberName="m_modulationLabel10"
         virtualName="" explicitFocusOrder="0" pos="349 84 16 16" textCol="ff000000"
         edTextCol="ff000000" edBkgCol="0" labelText="2" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="12" bold="1" italic="0" justification="34"/>
  <LABEL name="modulationLabel" id="ce7b5651d8eecac5" memberName="m_modulationLabel11"
         virtualName="" explicitFocusOrder="0" pos="349 112 16 16" textCol="ff000000"
         edTextCol="ff000000" edBkgCol="0" labelText="3" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="12" bold="1" italic="0" justification="34"/>
  <LABEL name="modulationLabel" id="65b7842f5dcacfd1" memberName="m_modulationLabel12"
         virtualName="" explicitFocusOrder="0" pos="349 140 16 16" textCol="ff000000"
         edTextCol="ff000000" edBkgCol="0" labelText="4" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="12" bold="1" italic="0" justification="34"/>
  <LABEL name="bendUpLabel" id="8e13461a1fae68" memberName="m_bendUpLabel"
         virtualName="" explicitFocusOrder="0" pos="189 196 80 16" textCol="ff000000"
         edTextCol="ff000000" edBkgCol="0" labelText="UP:" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="12" bold="1" italic="0" justification="34"/>
  <LABEL name="bendDownLabel" id="c25b4b466360573c" memberName="m_bendDownLabel"
         virtualName="" explicitFocusOrder="0" pos="189 224 80 16" textCol="ff000000"
         edTextCol="ff000000" edBkgCol="0" labelText="DOWN:" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="12" bold="1" italic="0" justification="34"/>
  <LABEL name="bendCommonLabel" id="9c25ae6f5805698f" memberName="m_bendCommonLabel"
         virtualName="" explicitFocusOrder="0" pos="185 164 144 32" textCol="ff000000"
         edTextCol="ff000000" edBkgCol="0" labelText="COMMON BEND RANGE&#10;(FOR ALL 4 TONES)"
         editableSingleClick="0" editableDoubleClick="0" focusDiscardsChanges="0"
         fontname="Default font" fontsize="12" bold="1" italic="0" justification="36"/>
  <SLIDER name="bendUpSlider" id="c55451f652b9879b" memberName="m_bendUpSlider"
          virtualName="MicroParameterSlider" explicitFocusOrder="0" pos="277 196 56 16"
          bkgcol="fff2f59b" thumbcol="ffc4c86d" min="0" max="127" int="1"
          style="LinearBar" textBoxPos="TextBoxLeft" textBoxEditable="1"
          textBoxWidth="40" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="bendDownSlider" id="2e2bb5b326d78063" memberName="m_bendDownSlider"
          virtualName="MicroParameterSlider" explicitFocusOrder="0" pos="277 224 56 16"
          bkgcol="fff2f59b" thumbcol="ffc4c86d" min="0" max="127" int="1"
          style="LinearBar" textBoxPos="TextBoxLeft" textBoxEditable="1"
          textBoxWidth="40" textBoxHeight="20" skewFactor="1"/>
  <IMAGEBUTTON name="bendRangeImage" id="2718c863156725e7" memberName="m_bendRangeImage"
               virtualName="ImageButton" explicitFocusOrder="0" pos="205 198 63 27"
               buttonText="new button" connectedEdges="0" needsCallback="0"
               radioGroupId="0" keepProportions="0" resourceNormal="pitchBendLever_png"
               opacityNormal="1" colourNormal="0" resourceOver="pitchBendLever_png"
               opacityOver="1" colourOver="0" resourceDown="" opacityDown="1"
               colourDown="0"/>
  <LABEL name="line" id="fd11227ac2737e03" memberName="m_line" virtualName=""
         explicitFocusOrder="0" pos="172 16 1 232" outlineCol="ff000000"
         edTextCol="ff000000" edBkgCol="0" labelText="" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" bold="0" italic="0" justification="33"/>
  <LABEL name="line" id="782b8a7dabffa18" memberName="m_line2" virtualName=""
         explicitFocusOrder="0" pos="348 16 1 232" outlineCol="ff000000"
         edTextCol="ff000000" edBkgCol="0" labelText="" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" bold="0" italic="0" justification="33"/>
  <IMAGEBUTTON name="new button" id="e65716ea6a3aa3da" memberName="imageButton4"
               virtualName="" explicitFocusOrder="0" pos="3 1 16 16" buttonText=""
               connectedEdges="0" needsCallback="0" radioGroupId="0" keepProportions="1"
               resourceNormal="modulation_png" opacityNormal="1" colourNormal="4340454a"
               resourceOver="" opacityOver="1" colourOver="4340454a" resourceDown=""
               opacityDown="1" colourDown="4340454a"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif

//==============================================================================
// Binary resources - be careful not to edit any of these sections!

// JUCER_RESOURCE: pitchBendLever_png, 2588, "../../../Resources/LookAndFeel/PitchBendLever.png"
static const unsigned char resource_PatchControllerMatrixEditor_pitchBendLever_png[] = { 137,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,0,63,0,0,0,27,8,6,0,0,0,203,98,87,255,0,0,0,1,115,82,71,66,0,
174,206,28,233,0,0,0,6,98,75,71,68,0,255,0,255,0,255,160,189,167,147,0,0,0,9,112,72,89,115,0,0,11,19,0,0,11,19,1,0,154,156,24,0,0,0,7,116,73,77,69,7,222,9,9,11,0,3,1,164,68,95,0,0,0,25,116,69,88,116,67,
111,109,109,101,110,116,0,67,114,101,97,116,101,100,32,119,105,116,104,32,71,73,77,80,87,129,14,23,0,0,9,119,73,68,65,84,88,195,213,88,75,111,36,87,25,61,183,238,173,103,187,220,118,63,236,180,237,97,
50,246,120,38,54,30,198,194,36,163,68,26,33,2,230,33,64,202,176,97,193,150,61,66,202,95,128,13,11,54,128,68,16,17,2,54,179,64,40,179,138,52,36,35,49,146,137,4,131,32,131,51,140,159,29,63,104,87,119,219,
253,174,215,173,91,151,133,167,46,238,9,10,66,10,68,190,82,171,187,171,85,183,238,249,206,247,157,239,124,77,240,17,174,239,191,246,214,15,90,155,111,190,58,24,12,192,57,71,146,36,72,211,20,154,166,129,
115,142,56,142,65,41,5,165,20,154,166,193,176,11,119,169,158,251,206,79,127,244,189,71,248,24,22,251,168,54,122,245,39,15,23,122,213,219,223,62,56,56,128,231,121,136,227,24,113,28,35,138,34,8,33,32,165,
68,24,134,208,117,93,5,96,103,103,103,245,249,151,62,255,57,0,31,11,120,237,163,218,104,196,255,195,15,219,173,227,177,48,12,145,166,169,36,132,72,195,48,164,227,56,210,113,28,105,89,150,28,29,29,149,
140,49,105,154,38,164,148,152,157,157,21,127,92,123,235,199,55,94,252,250,202,185,102,30,65,243,121,206,121,154,74,137,32,8,72,16,134,224,113,140,52,77,33,132,128,16,66,149,1,165,84,142,140,140,64,8,145,
60,251,236,252,3,30,31,127,11,192,131,115,11,126,208,239,159,104,84,247,11,227,69,234,142,140,106,81,20,105,156,199,90,146,112,202,57,215,56,79,72,146,112,146,36,9,9,195,80,11,130,64,23,105,154,30,86,
55,95,152,254,196,252,157,229,79,127,217,249,203,159,223,244,207,37,248,94,191,95,15,227,88,23,66,104,203,215,175,173,16,66,64,41,5,128,161,58,15,195,16,253,126,31,191,125,227,141,122,195,243,198,242,
99,133,102,28,133,197,118,72,46,0,120,124,46,193,247,123,189,210,225,225,129,29,71,145,190,189,185,217,136,121,172,113,126,202,58,100,170,69,49,39,72,83,146,36,156,68,113,12,153,166,163,148,49,24,134,
153,54,188,253,239,94,93,190,244,150,183,115,78,193,87,247,246,159,121,188,254,238,8,165,26,82,9,64,166,0,8,0,9,0,16,66,128,115,174,234,95,8,1,215,117,37,99,186,5,0,205,195,191,191,242,153,151,190,176,
246,167,181,223,181,206,29,248,139,51,211,8,122,45,194,121,2,33,146,33,161,251,119,175,52,77,97,24,6,209,8,44,0,32,208,138,17,231,47,3,248,205,185,3,127,117,241,147,114,110,246,34,201,229,114,208,52,13,
255,169,230,91,173,22,142,142,142,112,255,254,125,61,159,207,135,156,243,82,237,253,205,165,115,9,126,44,63,138,141,127,236,225,225,195,135,170,165,73,41,135,152,206,222,227,56,70,146,36,217,139,196,113,
108,6,65,231,38,165,198,198,185,172,249,247,222,123,15,107,247,127,143,205,205,77,48,198,160,105,154,202,128,15,123,79,211,20,73,146,16,0,40,79,148,110,150,39,202,211,91,155,143,15,207,21,248,148,135,
206,248,248,56,158,123,238,57,76,76,76,40,47,127,150,245,236,179,148,82,121,255,122,189,14,206,249,169,253,13,124,114,112,112,112,120,238,152,15,130,0,23,46,92,64,165,82,193,242,242,50,60,207,67,175,215,
3,165,20,82,74,164,105,122,234,167,159,176,61,24,12,208,235,245,112,120,120,136,181,181,53,52,155,77,52,26,141,202,255,51,237,201,211,23,86,87,87,39,116,93,255,89,154,166,150,16,2,140,49,53,152,16,66,
64,200,233,45,25,24,66,72,246,219,203,141,70,131,2,64,169,84,66,189,94,39,73,146,128,82,170,238,201,74,33,77,83,197,124,38,128,97,24,98,48,24,96,105,105,233,126,185,92,110,18,66,100,16,4,6,165,84,80,74,
5,99,76,60,121,94,250,191,100,254,43,174,235,190,240,232,209,163,103,142,143,143,97,154,38,218,237,54,40,165,176,109,27,186,174,195,178,44,4,65,112,186,1,99,168,213,106,106,122,203,174,101,99,43,33,4,
150,101,169,224,81,74,17,69,17,194,48,68,24,134,144,82,14,61,124,125,125,253,165,114,185,28,24,134,161,133,97,104,17,66,16,199,49,124,223,135,148,82,18,66,160,235,186,160,148,198,150,101,33,73,18,48,198,
48,24,12,48,61,61,13,0,104,52,26,208,117,29,182,109,35,73,18,56,142,3,74,41,1,0,215,117,229,220,220,28,194,48,220,101,79,177,174,233,186,254,165,86,171,53,185,181,181,5,223,255,151,213,206,4,74,74,9,195,
48,224,186,46,52,77,131,16,2,154,166,33,142,99,184,174,11,93,215,17,4,1,226,56,134,101,89,208,117,125,104,174,151,82,34,73,18,85,231,31,208,142,52,165,158,231,229,150,151,151,73,161,80,0,99,12,189,94,
15,158,231,97,127,127,63,27,149,41,0,163,219,237,14,221,187,177,177,161,206,170,235,58,124,223,151,166,105,18,66,136,164,148,98,48,24,96,123,123,59,11,70,231,105,230,151,44,203,250,212,222,222,30,1,160,
216,46,151,203,170,95,155,166,9,215,117,213,119,203,178,96,154,38,74,165,18,150,151,151,113,116,116,132,215,95,127,29,71,71,71,136,227,24,253,126,31,134,97,12,101,69,20,69,31,154,142,197,98,145,120,158,
135,40,138,48,63,63,143,98,177,136,185,185,57,248,190,15,198,24,250,253,62,238,221,187,135,48,12,21,1,103,73,178,44,11,174,235,194,178,44,24,134,33,13,195,80,1,73,146,4,134,97,36,132,144,221,167,193,127,
45,8,130,75,39,39,39,144,82,162,80,40,96,106,106,74,41,117,6,148,82,10,211,52,161,235,58,202,229,50,242,249,60,230,231,231,113,235,214,45,236,238,238,226,222,189,123,136,227,24,51,51,51,104,54,155,170,
245,81,74,149,197,205,58,129,16,2,157,78,71,29,96,124,124,28,179,179,179,48,77,19,141,70,3,119,238,220,129,235,186,40,149,74,176,109,27,87,175,94,69,46,151,195,205,155,55,177,179,179,163,246,243,125,31,
132,16,8,33,96,154,38,76,211,132,101,89,228,73,9,74,198,78,161,78,78,78,74,0,239,75,41,255,202,206,164,188,99,24,198,23,61,207,115,124,223,207,230,110,112,206,85,13,27,134,49,228,214,242,249,60,242,249,
60,42,149,10,114,185,28,0,32,12,67,152,166,137,98,177,136,241,241,241,33,177,75,211,20,81,20,169,125,179,244,63,11,30,0,106,181,218,208,119,199,113,208,108,54,1,0,113,28,163,211,233,224,218,181,107,88,
88,88,0,33,4,156,115,84,171,85,116,187,93,104,154,6,203,178,84,151,201,116,70,211,52,232,186,78,44,203,146,66,8,223,113,156,135,103,153,255,44,231,252,114,167,211,129,16,2,153,77,101,140,129,16,50,196,
222,217,107,186,174,99,113,113,17,133,66,1,190,239,163,90,173,170,90,238,118,187,232,245,122,200,231,243,74,233,179,182,151,5,210,48,12,204,205,205,161,86,171,193,247,125,180,90,45,68,81,4,211,52,17,69,
17,116,93,135,231,121,112,28,7,190,239,163,215,235,1,0,222,126,251,109,21,24,223,247,145,207,231,97,24,6,24,99,48,77,19,140,49,245,172,172,75,185,174,43,41,165,36,151,203,53,243,99,227,235,10,60,165,244,
149,102,179,57,85,175,215,17,4,1,70,70,70,20,155,166,105,14,181,42,74,41,44,203,194,228,228,36,46,93,186,4,0,176,44,11,27,27,27,88,95,95,135,16,2,182,109,131,82,138,169,169,41,0,192,232,232,40,132,16,
232,245,122,89,221,169,126,223,110,183,97,219,54,38,39,39,17,134,225,233,136,220,239,131,115,14,93,215,193,57,135,239,251,10,232,217,101,154,38,108,219,86,193,204,218,107,54,87,8,33,20,120,195,48,112,
241,226,69,113,112,112,176,249,235,95,253,242,144,61,73,249,105,198,216,139,7,7,7,36,75,193,48,12,193,57,87,42,159,165,189,166,105,42,24,99,99,99,184,114,229,138,2,223,237,118,177,179,179,131,199,143,
31,163,223,239,131,16,162,2,104,24,134,50,67,182,109,43,86,146,36,81,109,234,202,149,43,74,221,155,205,38,170,213,170,98,26,128,2,94,169,84,212,25,51,81,28,12,6,202,73,74,41,33,165,4,165,84,57,74,74,41,
28,199,145,140,177,125,66,200,195,179,125,254,171,245,122,125,246,108,237,249,190,143,122,189,142,82,169,132,36,73,80,42,149,64,41,85,2,181,184,184,136,217,217,89,156,156,156,160,80,40,224,157,119,222,
193,254,254,62,118,119,119,209,104,52,148,40,54,26,141,15,168,185,97,24,136,227,120,232,218,214,214,22,0,96,101,101,5,229,114,25,11,11,11,88,89,89,193,209,209,17,162,40,194,246,246,54,246,246,246,48,57,
57,137,90,173,6,199,113,112,227,198,13,85,18,217,153,77,211,68,183,219,133,101,89,42,240,82,74,34,132,144,66,8,212,106,181,214,216,216,248,187,0,192,86,87,87,169,97,24,223,104,183,219,185,167,15,228,251,
62,246,246,246,48,51,51,163,218,92,171,213,66,165,82,193,212,212,20,154,205,38,54,55,55,17,69,17,238,222,189,139,106,181,10,0,176,109,27,65,16,124,32,69,179,117,230,57,242,172,203,220,218,218,82,65,184,
124,249,50,92,215,197,210,210,18,76,211,196,210,210,146,50,91,245,122,29,15,30,60,64,181,90,197,238,238,46,42,149,138,42,137,39,194,134,56,142,149,38,61,113,148,36,73,146,132,115,94,47,78,84,254,150,49,
127,221,178,172,197,108,252,124,122,57,142,3,66,8,218,237,54,218,237,54,44,203,66,167,211,193,237,219,183,209,233,116,64,41,85,160,207,250,252,255,98,73,66,136,144,82,106,217,95,233,163,163,163,104,181,
90,56,57,57,65,20,69,104,181,90,184,126,253,186,234,221,153,210,251,190,143,90,173,134,122,189,142,90,173,6,219,182,193,24,131,235,186,74,79,130,32,64,177,88,4,99,76,134,97,88,51,77,243,209,47,126,254,
90,11,0,24,33,228,155,199,199,199,142,166,105,45,215,117,135,60,124,166,236,217,70,89,139,26,12,6,16,66,168,154,154,153,153,81,226,147,49,158,5,50,83,254,145,145,17,100,45,180,82,169,160,86,171,41,183,
24,69,17,52,77,83,162,90,44,22,149,223,111,54,155,152,153,153,193,225,225,33,60,207,35,132,16,216,182,45,93,215,133,235,186,202,34,23,10,5,53,111,100,251,56,142,147,121,10,141,49,102,36,73,146,186,174,
171,254,39,252,39,45,6,165,154,117,106,161,4,0,0,0,0,73,69,78,68,174,66,96,130,0,0};

const char* PatchControllerMatrixEditor::pitchBendLever_png = (const char*) resource_PatchControllerMatrixEditor_pitchBendLever_png;
const int PatchControllerMatrixEditor::pitchBendLever_pngSize = 2588;

// JUCER_RESOURCE: modulation_png, 238, "../../../Resources/PatchEditSectionIcons/modulation.png"
static const unsigned char resource_PatchControllerMatrixEditor_modulation_png[] = { 137,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,0,16,0,0,0,16,8,6,0,0,0,31,243,255,97,0,0,0,1,115,82,71,66,0,174,
206,28,233,0,0,0,6,98,75,71,68,0,255,0,255,0,255,160,189,167,147,0,0,0,9,112,72,89,115,0,0,11,19,0,0,11,19,1,0,154,156,24,0,0,0,7,116,73,77,69,7,222,12,10,20,20,1,12,43,54,245,0,0,0,110,73,68,65,84,56,
203,165,147,65,14,192,32,8,4,93,210,255,127,121,122,177,137,104,43,80,185,153,184,19,118,1,181,94,0,173,80,146,212,254,138,157,102,39,142,192,0,22,137,35,136,69,30,157,215,10,32,91,86,245,188,116,10,32,
73,149,73,60,182,0,28,117,134,100,58,186,62,151,99,211,254,248,207,74,75,211,197,227,219,74,129,189,100,101,169,93,223,64,45,147,246,12,91,224,39,199,164,211,115,190,1,163,41,103,232,114,180,106,233,0,
0,0,0,73,69,78,68,174,66,96,130,0,0};

const char* PatchControllerMatrixEditor::modulation_png = (const char*) resource_PatchControllerMatrixEditor_modulation_png;
const int PatchControllerMatrixEditor::modulation_pngSize = 238;


//[EndFile] You can add extra defines here...
//[/EndFile]
