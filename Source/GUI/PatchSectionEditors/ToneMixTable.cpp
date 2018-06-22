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

#include "ToneMixTable.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
extern OverallMemoryBlock* grooveboxMemory;
//[/MiscUserDefs]

//==============================================================================
ToneMixTable::ToneMixTable (const String &componentName, SynthParts part)
    : Component (componentName), m_part(part)
{
    addAndMakeVisible (m_grp = new PanelGroupGrey ("grp", getName()));
    addAndMakeVisible (m_ampBiasGrp1 = new PanelGroupTransp ("ampBiasGrp", "AMP BIAS TONE 1"));
    addAndMakeVisible (m_toneMixTableBoard = new ToneMixTableBoard ("toneMixTableBoard", m_part));
    addAndMakeVisible (m_velocityRangeToggle = new BlackToggle());
    addAndMakeVisible (m_velocityRangeLabel = new Label ("velocityRangeLabel",
                                                         TRANS("USE VELOCITY RANGES")));
    m_velocityRangeLabel->setFont (Font (12.00f, Font::bold));
    m_velocityRangeLabel->setJustificationType (Justification::centredLeft);
    m_velocityRangeLabel->setEditable (false, false, false);
    m_velocityRangeLabel->setColour (Label::textColourId, Colours::black);
    m_velocityRangeLabel->setColour (TextEditor::textColourId, Colours::black);
    m_velocityRangeLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_keyRangeGrp1 = new PanelGroupTransp ("keyRangeGrp", "KEY RANGE TONE 1"));
    addAndMakeVisible (m_veloRangeGrp1 = new PanelGroupTransp ("veloRangeGrp", "VELOCITY RANGE TONE 1"));
    addAndMakeVisible (m_velocityCrossFadeSlider1 = new MicroParameterSlider ("velocityCrossFadeSlider"));
    m_velocityCrossFadeSlider1->setRange (0, 127, 1);
    m_velocityCrossFadeSlider1->setSliderStyle (Slider::LinearBar);
    m_velocityCrossFadeSlider1->setTextBoxStyle (Slider::TextBoxLeft, false, 40, 20);
    m_velocityCrossFadeSlider1->setColour (Slider::backgroundColourId, Colour (0xfff2f59b));
    m_velocityCrossFadeSlider1->setColour (Slider::thumbColourId, Colour (0xffc4c86d));
    m_velocityCrossFadeSlider1->addListener (this);

    addAndMakeVisible (m_velocityCrossFadeLabel1 = new Label ("velocityCrossFadeLabel",
                                                              TRANS("CROSSFADE")));
    m_velocityCrossFadeLabel1->setFont (Font (12.00f, Font::bold));
    m_velocityCrossFadeLabel1->setJustificationType (Justification::centredLeft);
    m_velocityCrossFadeLabel1->setEditable (false, false, false);
    m_velocityCrossFadeLabel1->setColour (TextEditor::textColourId, Colours::black);
    m_velocityCrossFadeLabel1->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_velocityRangeUpperSlider1 = new MicroParameterSlider ("velocityRangeUpperSlider"));
    m_velocityRangeUpperSlider1->setRange (0, 127, 1);
    m_velocityRangeUpperSlider1->setSliderStyle (Slider::LinearBar);
    m_velocityRangeUpperSlider1->setTextBoxStyle (Slider::TextBoxLeft, false, 40, 20);
    m_velocityRangeUpperSlider1->setColour (Slider::backgroundColourId, Colour (0xfff2f59b));
    m_velocityRangeUpperSlider1->setColour (Slider::thumbColourId, Colour (0xffc4c86d));
    m_velocityRangeUpperSlider1->addListener (this);

    addAndMakeVisible (m_velocityRangeUpperLabel1 = new Label ("velocityRangeUpperLabel",
                                                               TRANS("UPPER")));
    m_velocityRangeUpperLabel1->setFont (Font (12.00f, Font::bold));
    m_velocityRangeUpperLabel1->setJustificationType (Justification::centredLeft);
    m_velocityRangeUpperLabel1->setEditable (false, false, false);
    m_velocityRangeUpperLabel1->setColour (TextEditor::textColourId, Colours::black);
    m_velocityRangeUpperLabel1->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_velocityRangeLowerLabel1 = new Label ("velocityRangeLowerLabel",
                                                               TRANS("LOWER")));
    m_velocityRangeLowerLabel1->setFont (Font (12.00f, Font::bold));
    m_velocityRangeLowerLabel1->setJustificationType (Justification::centredLeft);
    m_velocityRangeLowerLabel1->setEditable (false, false, false);
    m_velocityRangeLowerLabel1->setColour (TextEditor::textColourId, Colours::black);
    m_velocityRangeLowerLabel1->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_velocityRangeLowerSlider1 = new MicroParameterSlider ("velocityRangeLowerSlider"));
    m_velocityRangeLowerSlider1->setRange (0, 127, 1);
    m_velocityRangeLowerSlider1->setSliderStyle (Slider::LinearBar);
    m_velocityRangeLowerSlider1->setTextBoxStyle (Slider::TextBoxLeft, false, 40, 20);
    m_velocityRangeLowerSlider1->setColour (Slider::backgroundColourId, Colour (0xfff2f59b));
    m_velocityRangeLowerSlider1->setColour (Slider::thumbColourId, Colour (0xffc4c86d));
    m_velocityRangeLowerSlider1->addListener (this);

    addAndMakeVisible (m_keyRangeLowerLabel1 = new Label ("keyRangeLowerLabel",
                                                          TRANS("LOWER")));
    m_keyRangeLowerLabel1->setFont (Font (12.00f, Font::bold));
    m_keyRangeLowerLabel1->setJustificationType (Justification::centred);
    m_keyRangeLowerLabel1->setEditable (false, false, false);
    m_keyRangeLowerLabel1->setColour (TextEditor::textColourId, Colours::black);
    m_keyRangeLowerLabel1->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_keyRangeLowerSlider1 = new MicroParameterSlider ("keyRangeLowerSlider"));
    m_keyRangeLowerSlider1->setRange (0, 127, 1);
    m_keyRangeLowerSlider1->setSliderStyle (Slider::LinearBar);
    m_keyRangeLowerSlider1->setTextBoxStyle (Slider::TextBoxLeft, false, 40, 20);
    m_keyRangeLowerSlider1->setColour (Slider::backgroundColourId, Colour (0xfff2f59b));
    m_keyRangeLowerSlider1->setColour (Slider::thumbColourId, Colour (0xffc4c86d));
    m_keyRangeLowerSlider1->addListener (this);

    addAndMakeVisible (m_keyRangeUpperSlider1 = new MicroParameterSlider ("keyRangeUpperSlider"));
    m_keyRangeUpperSlider1->setRange (0, 127, 1);
    m_keyRangeUpperSlider1->setSliderStyle (Slider::LinearBar);
    m_keyRangeUpperSlider1->setTextBoxStyle (Slider::TextBoxLeft, false, 40, 20);
    m_keyRangeUpperSlider1->setColour (Slider::backgroundColourId, Colour (0xfff2f59b));
    m_keyRangeUpperSlider1->setColour (Slider::thumbColourId, Colour (0xffc4c86d));
    m_keyRangeUpperSlider1->addListener (this);

    addAndMakeVisible (m_keyRangeUpperLabel1 = new Label ("keyRangeUpperLabel",
                                                          TRANS("UPPER")));
    m_keyRangeUpperLabel1->setFont (Font (12.00f, Font::bold));
    m_keyRangeUpperLabel1->setJustificationType (Justification::centred);
    m_keyRangeUpperLabel1->setEditable (false, false, false);
    m_keyRangeUpperLabel1->setColour (TextEditor::textColourId, Colours::black);
    m_keyRangeUpperLabel1->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_biasLevelSlider1 = new MicroParameterSlider ("biasLevelSlider"));
    m_biasLevelSlider1->setRange (0, 127, 1);
    m_biasLevelSlider1->setSliderStyle (Slider::LinearBar);
    m_biasLevelSlider1->setTextBoxStyle (Slider::TextBoxLeft, false, 40, 20);
    m_biasLevelSlider1->setColour (Slider::backgroundColourId, Colour (0xfff2f59b));
    m_biasLevelSlider1->setColour (Slider::thumbColourId, Colour (0xffc4c86d));
    m_biasLevelSlider1->addListener (this);

    addAndMakeVisible (m_biasLevelLabel1 = new Label ("biasLevelLabel",
                                                      TRANS("BIAS LEVEL")));
    m_biasLevelLabel1->setFont (Font (12.00f, Font::bold));
    m_biasLevelLabel1->setJustificationType (Justification::centredLeft);
    m_biasLevelLabel1->setEditable (false, false, false);
    m_biasLevelLabel1->setColour (TextEditor::textColourId, Colours::black);
    m_biasLevelLabel1->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_biasPointLabel1 = new Label ("biasPointLabel",
                                                      TRANS("BIAS POINT")));
    m_biasPointLabel1->setFont (Font (12.00f, Font::bold));
    m_biasPointLabel1->setJustificationType (Justification::centredLeft);
    m_biasPointLabel1->setEditable (false, false, false);
    m_biasPointLabel1->setColour (TextEditor::textColourId, Colours::black);
    m_biasPointLabel1->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_biasPointSlider1 = new MicroParameterSlider ("biasPointSlider"));
    m_biasPointSlider1->setRange (0, 127, 1);
    m_biasPointSlider1->setSliderStyle (Slider::LinearBar);
    m_biasPointSlider1->setTextBoxStyle (Slider::TextBoxLeft, false, 40, 20);
    m_biasPointSlider1->setColour (Slider::backgroundColourId, Colour (0xfff2f59b));
    m_biasPointSlider1->setColour (Slider::thumbColourId, Colour (0xffc4c86d));
    m_biasPointSlider1->addListener (this);

    addAndMakeVisible (m_biasDirectionComboBox1 = new ParameterComboBox ("biasDirectionComboBox"));
    m_biasDirectionComboBox1->setEditableText (false);
    m_biasDirectionComboBox1->setJustificationType (Justification::centredLeft);
    m_biasDirectionComboBox1->setTextWhenNothingSelected (String());
    m_biasDirectionComboBox1->setTextWhenNoChoicesAvailable (TRANS("(no choices)"));
    m_biasDirectionComboBox1->addListener (this);

    addAndMakeVisible (m_biasDirectionLabel1 = new Label ("biasDirectionLabel",
                                                          TRANS("DIRECTION")));
    m_biasDirectionLabel1->setFont (Font (12.00f, Font::bold));
    m_biasDirectionLabel1->setJustificationType (Justification::centredLeft);
    m_biasDirectionLabel1->setEditable (false, false, false);
    m_biasDirectionLabel1->setColour (TextEditor::textColourId, Colours::black);
    m_biasDirectionLabel1->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_toneLevelLabel1 = new Label ("toneLevelLabel",
                                                      TRANS("TONE LEVEL")));
    m_toneLevelLabel1->setFont (Font (12.00f, Font::bold));
    m_toneLevelLabel1->setJustificationType (Justification::centredRight);
    m_toneLevelLabel1->setEditable (false, false, false);
    m_toneLevelLabel1->setColour (TextEditor::textColourId, Colours::black);
    m_toneLevelLabel1->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_toneLevelSlider1 = new MixPartLevelFader ("toneLevelSlider"));
    m_toneLevelSlider1->setRange (0, 127, 1);
    m_toneLevelSlider1->setSliderStyle (Slider::LinearVertical);
    m_toneLevelSlider1->setTextBoxStyle (Slider::TextBoxBelow, false, 32, 16);
    m_toneLevelSlider1->addListener (this);

    addAndMakeVisible (m_keyRangeGrp2 = new PanelGroupTransp ("keyRangeGrp2", "KEY RANGE TONE 2"));
    addAndMakeVisible (m_keyRangeGrp3 = new PanelGroupTransp ("keyRangeGrp3", "KEY RANGE TONE 3"));
    addAndMakeVisible (m_keyRangeGrp4 = new PanelGroupTransp ("keyRangeGrp4", "KEY RANGE TONE 4"));
    addAndMakeVisible (m_ampBiasGrp2 = new PanelGroupTransp ("ampBiasGrp", "AMP BIAS TONE 1"));
    addAndMakeVisible (m_veloRangeGrp2 = new PanelGroupTransp ("veloRangeGrp", "VELOCITY RANGE TONE 1"));
    addAndMakeVisible (m_velocityCrossFadeSlider2 = new MicroParameterSlider ("velocityCrossFadeSlider"));
    m_velocityCrossFadeSlider2->setRange (0, 127, 1);
    m_velocityCrossFadeSlider2->setSliderStyle (Slider::LinearBar);
    m_velocityCrossFadeSlider2->setTextBoxStyle (Slider::TextBoxLeft, false, 40, 20);
    m_velocityCrossFadeSlider2->setColour (Slider::backgroundColourId, Colour (0xfff2f59b));
    m_velocityCrossFadeSlider2->setColour (Slider::thumbColourId, Colour (0xffc4c86d));
    m_velocityCrossFadeSlider2->addListener (this);

    addAndMakeVisible (m_velocityCrossFadeLabel2 = new Label ("velocityCrossFadeLabel",
                                                              TRANS("CROSSFADE")));
    m_velocityCrossFadeLabel2->setFont (Font (12.00f, Font::bold));
    m_velocityCrossFadeLabel2->setJustificationType (Justification::centredLeft);
    m_velocityCrossFadeLabel2->setEditable (false, false, false);
    m_velocityCrossFadeLabel2->setColour (TextEditor::textColourId, Colours::black);
    m_velocityCrossFadeLabel2->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_velocityRangeUpperSlider2 = new MicroParameterSlider ("velocityRangeUpperSlider"));
    m_velocityRangeUpperSlider2->setRange (0, 127, 1);
    m_velocityRangeUpperSlider2->setSliderStyle (Slider::LinearBar);
    m_velocityRangeUpperSlider2->setTextBoxStyle (Slider::TextBoxLeft, false, 40, 20);
    m_velocityRangeUpperSlider2->setColour (Slider::backgroundColourId, Colour (0xfff2f59b));
    m_velocityRangeUpperSlider2->setColour (Slider::thumbColourId, Colour (0xffc4c86d));
    m_velocityRangeUpperSlider2->addListener (this);

    addAndMakeVisible (m_velocityRangeUpperLabel2 = new Label ("velocityRangeUpperLabel",
                                                               TRANS("UPPER")));
    m_velocityRangeUpperLabel2->setFont (Font (12.00f, Font::bold));
    m_velocityRangeUpperLabel2->setJustificationType (Justification::centredLeft);
    m_velocityRangeUpperLabel2->setEditable (false, false, false);
    m_velocityRangeUpperLabel2->setColour (TextEditor::textColourId, Colours::black);
    m_velocityRangeUpperLabel2->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_velocityRangeLowerLabel2 = new Label ("velocityRangeLowerLabel",
                                                               TRANS("LOWER")));
    m_velocityRangeLowerLabel2->setFont (Font (12.00f, Font::bold));
    m_velocityRangeLowerLabel2->setJustificationType (Justification::centredLeft);
    m_velocityRangeLowerLabel2->setEditable (false, false, false);
    m_velocityRangeLowerLabel2->setColour (TextEditor::textColourId, Colours::black);
    m_velocityRangeLowerLabel2->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_velocityRangeLowerSlider2 = new MicroParameterSlider ("velocityRangeLowerSlider"));
    m_velocityRangeLowerSlider2->setRange (0, 127, 1);
    m_velocityRangeLowerSlider2->setSliderStyle (Slider::LinearBar);
    m_velocityRangeLowerSlider2->setTextBoxStyle (Slider::TextBoxLeft, false, 40, 20);
    m_velocityRangeLowerSlider2->setColour (Slider::backgroundColourId, Colour (0xfff2f59b));
    m_velocityRangeLowerSlider2->setColour (Slider::thumbColourId, Colour (0xffc4c86d));
    m_velocityRangeLowerSlider2->addListener (this);

    addAndMakeVisible (m_keyRangeLowerLabel2 = new Label ("keyRangeLowerLabel",
                                                          TRANS("LOWER")));
    m_keyRangeLowerLabel2->setFont (Font (12.00f, Font::bold));
    m_keyRangeLowerLabel2->setJustificationType (Justification::centred);
    m_keyRangeLowerLabel2->setEditable (false, false, false);
    m_keyRangeLowerLabel2->setColour (TextEditor::textColourId, Colours::black);
    m_keyRangeLowerLabel2->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_keyRangeLowerSlider2 = new MicroParameterSlider ("keyRangeLowerSlider"));
    m_keyRangeLowerSlider2->setRange (0, 127, 1);
    m_keyRangeLowerSlider2->setSliderStyle (Slider::LinearBar);
    m_keyRangeLowerSlider2->setTextBoxStyle (Slider::TextBoxLeft, false, 40, 20);
    m_keyRangeLowerSlider2->setColour (Slider::backgroundColourId, Colour (0xfff2f59b));
    m_keyRangeLowerSlider2->setColour (Slider::thumbColourId, Colour (0xffc4c86d));
    m_keyRangeLowerSlider2->addListener (this);

    addAndMakeVisible (m_keyRangeUpperSlider2 = new MicroParameterSlider ("keyRangeUpperSlider"));
    m_keyRangeUpperSlider2->setRange (0, 127, 1);
    m_keyRangeUpperSlider2->setSliderStyle (Slider::LinearBar);
    m_keyRangeUpperSlider2->setTextBoxStyle (Slider::TextBoxLeft, false, 40, 20);
    m_keyRangeUpperSlider2->setColour (Slider::backgroundColourId, Colour (0xfff2f59b));
    m_keyRangeUpperSlider2->setColour (Slider::thumbColourId, Colour (0xffc4c86d));
    m_keyRangeUpperSlider2->addListener (this);

    addAndMakeVisible (m_keyRangeUpperLabel2 = new Label ("keyRangeUpperLabel",
                                                          TRANS("UPPER")));
    m_keyRangeUpperLabel2->setFont (Font (12.00f, Font::bold));
    m_keyRangeUpperLabel2->setJustificationType (Justification::centred);
    m_keyRangeUpperLabel2->setEditable (false, false, false);
    m_keyRangeUpperLabel2->setColour (TextEditor::textColourId, Colours::black);
    m_keyRangeUpperLabel2->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_biasLevelSlider2 = new MicroParameterSlider ("biasLevelSlider"));
    m_biasLevelSlider2->setRange (0, 127, 1);
    m_biasLevelSlider2->setSliderStyle (Slider::LinearBar);
    m_biasLevelSlider2->setTextBoxStyle (Slider::TextBoxLeft, false, 40, 20);
    m_biasLevelSlider2->setColour (Slider::backgroundColourId, Colour (0xfff2f59b));
    m_biasLevelSlider2->setColour (Slider::thumbColourId, Colour (0xffc4c86d));
    m_biasLevelSlider2->addListener (this);

    addAndMakeVisible (m_biasLevelLabel2 = new Label ("biasLevelLabel",
                                                      TRANS("BIAS LEVEL")));
    m_biasLevelLabel2->setFont (Font (12.00f, Font::bold));
    m_biasLevelLabel2->setJustificationType (Justification::centredLeft);
    m_biasLevelLabel2->setEditable (false, false, false);
    m_biasLevelLabel2->setColour (TextEditor::textColourId, Colours::black);
    m_biasLevelLabel2->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_biasPointLabel2 = new Label ("biasPointLabel",
                                                      TRANS("BIAS POINT")));
    m_biasPointLabel2->setFont (Font (12.00f, Font::bold));
    m_biasPointLabel2->setJustificationType (Justification::centredLeft);
    m_biasPointLabel2->setEditable (false, false, false);
    m_biasPointLabel2->setColour (TextEditor::textColourId, Colours::black);
    m_biasPointLabel2->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_biasPointSlider2 = new MicroParameterSlider ("biasPointSlider"));
    m_biasPointSlider2->setRange (0, 127, 1);
    m_biasPointSlider2->setSliderStyle (Slider::LinearBar);
    m_biasPointSlider2->setTextBoxStyle (Slider::TextBoxLeft, false, 40, 20);
    m_biasPointSlider2->setColour (Slider::backgroundColourId, Colour (0xfff2f59b));
    m_biasPointSlider2->setColour (Slider::thumbColourId, Colour (0xffc4c86d));
    m_biasPointSlider2->addListener (this);

    addAndMakeVisible (m_biasDirectionComboBox2 = new ParameterComboBox ("biasDirectionComboBox"));
    m_biasDirectionComboBox2->setEditableText (false);
    m_biasDirectionComboBox2->setJustificationType (Justification::centredLeft);
    m_biasDirectionComboBox2->setTextWhenNothingSelected (String());
    m_biasDirectionComboBox2->setTextWhenNoChoicesAvailable (TRANS("(no choices)"));
    m_biasDirectionComboBox2->addListener (this);

    addAndMakeVisible (m_biasDirectionLabel2 = new Label ("biasDirectionLabel",
                                                          TRANS("DIRECTION")));
    m_biasDirectionLabel2->setFont (Font (12.00f, Font::bold));
    m_biasDirectionLabel2->setJustificationType (Justification::centredLeft);
    m_biasDirectionLabel2->setEditable (false, false, false);
    m_biasDirectionLabel2->setColour (TextEditor::textColourId, Colours::black);
    m_biasDirectionLabel2->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_toneLevelLabel2 = new Label ("toneLevelLabel",
                                                      TRANS("TONE LEVEL")));
    m_toneLevelLabel2->setFont (Font (12.00f, Font::bold));
    m_toneLevelLabel2->setJustificationType (Justification::centredRight);
    m_toneLevelLabel2->setEditable (false, false, false);
    m_toneLevelLabel2->setColour (TextEditor::textColourId, Colours::black);
    m_toneLevelLabel2->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_toneLevelSlider2 = new MixPartLevelFader ("toneLevelSlider"));
    m_toneLevelSlider2->setRange (0, 127, 1);
    m_toneLevelSlider2->setSliderStyle (Slider::LinearVertical);
    m_toneLevelSlider2->setTextBoxStyle (Slider::TextBoxBelow, false, 32, 16);
    m_toneLevelSlider2->addListener (this);

    addAndMakeVisible (m_ampBiasGrp3 = new PanelGroupTransp ("ampBiasGrp", "AMP BIAS TONE 1"));
    addAndMakeVisible (m_veloRangeGrp3 = new PanelGroupTransp ("veloRangeGrp", "VELOCITY RANGE TONE 1"));
    addAndMakeVisible (m_velocityCrossFadeSlider3 = new MicroParameterSlider ("velocityCrossFadeSlider"));
    m_velocityCrossFadeSlider3->setRange (0, 127, 1);
    m_velocityCrossFadeSlider3->setSliderStyle (Slider::LinearBar);
    m_velocityCrossFadeSlider3->setTextBoxStyle (Slider::TextBoxLeft, false, 40, 20);
    m_velocityCrossFadeSlider3->setColour (Slider::backgroundColourId, Colour (0xfff2f59b));
    m_velocityCrossFadeSlider3->setColour (Slider::thumbColourId, Colour (0xffc4c86d));
    m_velocityCrossFadeSlider3->addListener (this);

    addAndMakeVisible (m_velocityCrossFadeLabel3 = new Label ("velocityCrossFadeLabel",
                                                              TRANS("CROSSFADE")));
    m_velocityCrossFadeLabel3->setFont (Font (12.00f, Font::bold));
    m_velocityCrossFadeLabel3->setJustificationType (Justification::centredLeft);
    m_velocityCrossFadeLabel3->setEditable (false, false, false);
    m_velocityCrossFadeLabel3->setColour (TextEditor::textColourId, Colours::black);
    m_velocityCrossFadeLabel3->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_velocityRangeUpperSlider3 = new MicroParameterSlider ("velocityRangeUpperSlider"));
    m_velocityRangeUpperSlider3->setRange (0, 127, 1);
    m_velocityRangeUpperSlider3->setSliderStyle (Slider::LinearBar);
    m_velocityRangeUpperSlider3->setTextBoxStyle (Slider::TextBoxLeft, false, 40, 20);
    m_velocityRangeUpperSlider3->setColour (Slider::backgroundColourId, Colour (0xfff2f59b));
    m_velocityRangeUpperSlider3->setColour (Slider::thumbColourId, Colour (0xffc4c86d));
    m_velocityRangeUpperSlider3->addListener (this);

    addAndMakeVisible (m_velocityRangeUpperLabel3 = new Label ("velocityRangeUpperLabel",
                                                               TRANS("UPPER")));
    m_velocityRangeUpperLabel3->setFont (Font (12.00f, Font::bold));
    m_velocityRangeUpperLabel3->setJustificationType (Justification::centredLeft);
    m_velocityRangeUpperLabel3->setEditable (false, false, false);
    m_velocityRangeUpperLabel3->setColour (TextEditor::textColourId, Colours::black);
    m_velocityRangeUpperLabel3->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_velocityRangeLowerLabel3 = new Label ("velocityRangeLowerLabel",
                                                               TRANS("LOWER")));
    m_velocityRangeLowerLabel3->setFont (Font (12.00f, Font::bold));
    m_velocityRangeLowerLabel3->setJustificationType (Justification::centredLeft);
    m_velocityRangeLowerLabel3->setEditable (false, false, false);
    m_velocityRangeLowerLabel3->setColour (TextEditor::textColourId, Colours::black);
    m_velocityRangeLowerLabel3->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_velocityRangeLowerSlider3 = new MicroParameterSlider ("velocityRangeLowerSlider"));
    m_velocityRangeLowerSlider3->setRange (0, 127, 1);
    m_velocityRangeLowerSlider3->setSliderStyle (Slider::LinearBar);
    m_velocityRangeLowerSlider3->setTextBoxStyle (Slider::TextBoxLeft, false, 40, 20);
    m_velocityRangeLowerSlider3->setColour (Slider::backgroundColourId, Colour (0xfff2f59b));
    m_velocityRangeLowerSlider3->setColour (Slider::thumbColourId, Colour (0xffc4c86d));
    m_velocityRangeLowerSlider3->addListener (this);

    addAndMakeVisible (m_keyRangeLowerLabel3 = new Label ("keyRangeLowerLabel",
                                                          TRANS("LOWER")));
    m_keyRangeLowerLabel3->setFont (Font (12.00f, Font::bold));
    m_keyRangeLowerLabel3->setJustificationType (Justification::centred);
    m_keyRangeLowerLabel3->setEditable (false, false, false);
    m_keyRangeLowerLabel3->setColour (TextEditor::textColourId, Colours::black);
    m_keyRangeLowerLabel3->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_keyRangeLowerSlider3 = new MicroParameterSlider ("keyRangeLowerSlider"));
    m_keyRangeLowerSlider3->setRange (0, 127, 1);
    m_keyRangeLowerSlider3->setSliderStyle (Slider::LinearBar);
    m_keyRangeLowerSlider3->setTextBoxStyle (Slider::TextBoxLeft, false, 40, 20);
    m_keyRangeLowerSlider3->setColour (Slider::backgroundColourId, Colour (0xfff2f59b));
    m_keyRangeLowerSlider3->setColour (Slider::thumbColourId, Colour (0xffc4c86d));
    m_keyRangeLowerSlider3->addListener (this);

    addAndMakeVisible (m_keyRangeUpperSlider3 = new MicroParameterSlider ("keyRangeUpperSlider"));
    m_keyRangeUpperSlider3->setRange (0, 127, 1);
    m_keyRangeUpperSlider3->setSliderStyle (Slider::LinearBar);
    m_keyRangeUpperSlider3->setTextBoxStyle (Slider::TextBoxLeft, false, 40, 20);
    m_keyRangeUpperSlider3->setColour (Slider::backgroundColourId, Colour (0xfff2f59b));
    m_keyRangeUpperSlider3->setColour (Slider::thumbColourId, Colour (0xffc4c86d));
    m_keyRangeUpperSlider3->addListener (this);

    addAndMakeVisible (m_keyRangeUpperLabel3 = new Label ("keyRangeUpperLabel",
                                                          TRANS("UPPER")));
    m_keyRangeUpperLabel3->setFont (Font (12.00f, Font::bold));
    m_keyRangeUpperLabel3->setJustificationType (Justification::centred);
    m_keyRangeUpperLabel3->setEditable (false, false, false);
    m_keyRangeUpperLabel3->setColour (TextEditor::textColourId, Colours::black);
    m_keyRangeUpperLabel3->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_biasLevelSlider3 = new MicroParameterSlider ("biasLevelSlider"));
    m_biasLevelSlider3->setRange (0, 127, 1);
    m_biasLevelSlider3->setSliderStyle (Slider::LinearBar);
    m_biasLevelSlider3->setTextBoxStyle (Slider::TextBoxLeft, false, 40, 20);
    m_biasLevelSlider3->setColour (Slider::backgroundColourId, Colour (0xfff2f59b));
    m_biasLevelSlider3->setColour (Slider::thumbColourId, Colour (0xffc4c86d));
    m_biasLevelSlider3->addListener (this);

    addAndMakeVisible (m_biasLevelLabel3 = new Label ("biasLevelLabel",
                                                      TRANS("BIAS LEVEL")));
    m_biasLevelLabel3->setFont (Font (12.00f, Font::bold));
    m_biasLevelLabel3->setJustificationType (Justification::centredLeft);
    m_biasLevelLabel3->setEditable (false, false, false);
    m_biasLevelLabel3->setColour (TextEditor::textColourId, Colours::black);
    m_biasLevelLabel3->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_biasPointLabel3 = new Label ("biasPointLabel",
                                                      TRANS("BIAS POINT")));
    m_biasPointLabel3->setFont (Font (12.00f, Font::bold));
    m_biasPointLabel3->setJustificationType (Justification::centredLeft);
    m_biasPointLabel3->setEditable (false, false, false);
    m_biasPointLabel3->setColour (TextEditor::textColourId, Colours::black);
    m_biasPointLabel3->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_biasPointSlider3 = new MicroParameterSlider ("biasPointSlider"));
    m_biasPointSlider3->setRange (0, 127, 1);
    m_biasPointSlider3->setSliderStyle (Slider::LinearBar);
    m_biasPointSlider3->setTextBoxStyle (Slider::TextBoxLeft, false, 40, 20);
    m_biasPointSlider3->setColour (Slider::backgroundColourId, Colour (0xfff2f59b));
    m_biasPointSlider3->setColour (Slider::thumbColourId, Colour (0xffc4c86d));
    m_biasPointSlider3->addListener (this);

    addAndMakeVisible (m_biasDirectionComboBox3 = new ParameterComboBox ("biasDirectionComboBox"));
    m_biasDirectionComboBox3->setEditableText (false);
    m_biasDirectionComboBox3->setJustificationType (Justification::centredLeft);
    m_biasDirectionComboBox3->setTextWhenNothingSelected (String());
    m_biasDirectionComboBox3->setTextWhenNoChoicesAvailable (TRANS("(no choices)"));
    m_biasDirectionComboBox3->addListener (this);

    addAndMakeVisible (m_biasDirectionLabel3 = new Label ("biasDirectionLabel",
                                                          TRANS("DIRECTION")));
    m_biasDirectionLabel3->setFont (Font (12.00f, Font::bold));
    m_biasDirectionLabel3->setJustificationType (Justification::centredLeft);
    m_biasDirectionLabel3->setEditable (false, false, false);
    m_biasDirectionLabel3->setColour (TextEditor::textColourId, Colours::black);
    m_biasDirectionLabel3->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_toneLevelLabel3 = new Label ("toneLevelLabel",
                                                      TRANS("TONE LEVEL")));
    m_toneLevelLabel3->setFont (Font (12.00f, Font::bold));
    m_toneLevelLabel3->setJustificationType (Justification::centredRight);
    m_toneLevelLabel3->setEditable (false, false, false);
    m_toneLevelLabel3->setColour (TextEditor::textColourId, Colours::black);
    m_toneLevelLabel3->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_toneLevelSlider3 = new MixPartLevelFader ("toneLevelSlider"));
    m_toneLevelSlider3->setRange (0, 127, 1);
    m_toneLevelSlider3->setSliderStyle (Slider::LinearVertical);
    m_toneLevelSlider3->setTextBoxStyle (Slider::TextBoxBelow, false, 32, 16);
    m_toneLevelSlider3->addListener (this);

    addAndMakeVisible (m_ampBiasGrp4 = new PanelGroupTransp ("ampBiasGrp", "AMP BIAS TONE 1"));
    addAndMakeVisible (m_veloRangeGrp4 = new PanelGroupTransp ("veloRangeGrp", "VELOCITY RANGE TONE 1"));
    addAndMakeVisible (m_velocityCrossFadeSlider4 = new MicroParameterSlider ("velocityCrossFadeSlider"));
    m_velocityCrossFadeSlider4->setRange (0, 127, 1);
    m_velocityCrossFadeSlider4->setSliderStyle (Slider::LinearBar);
    m_velocityCrossFadeSlider4->setTextBoxStyle (Slider::TextBoxLeft, false, 40, 20);
    m_velocityCrossFadeSlider4->setColour (Slider::backgroundColourId, Colour (0xfff2f59b));
    m_velocityCrossFadeSlider4->setColour (Slider::thumbColourId, Colour (0xffc4c86d));
    m_velocityCrossFadeSlider4->addListener (this);

    addAndMakeVisible (m_velocityCrossFadeLabel4 = new Label ("velocityCrossFadeLabel",
                                                              TRANS("CROSSFADE")));
    m_velocityCrossFadeLabel4->setFont (Font (12.00f, Font::bold));
    m_velocityCrossFadeLabel4->setJustificationType (Justification::centredLeft);
    m_velocityCrossFadeLabel4->setEditable (false, false, false);
    m_velocityCrossFadeLabel4->setColour (TextEditor::textColourId, Colours::black);
    m_velocityCrossFadeLabel4->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_velocityRangeUpperSlider4 = new MicroParameterSlider ("velocityRangeUpperSlider"));
    m_velocityRangeUpperSlider4->setRange (0, 127, 1);
    m_velocityRangeUpperSlider4->setSliderStyle (Slider::LinearBar);
    m_velocityRangeUpperSlider4->setTextBoxStyle (Slider::TextBoxLeft, false, 40, 20);
    m_velocityRangeUpperSlider4->setColour (Slider::backgroundColourId, Colour (0xfff2f59b));
    m_velocityRangeUpperSlider4->setColour (Slider::thumbColourId, Colour (0xffc4c86d));
    m_velocityRangeUpperSlider4->addListener (this);

    addAndMakeVisible (m_velocityRangeUpperLabel4 = new Label ("velocityRangeUpperLabel",
                                                               TRANS("UPPER")));
    m_velocityRangeUpperLabel4->setFont (Font (12.00f, Font::bold));
    m_velocityRangeUpperLabel4->setJustificationType (Justification::centredLeft);
    m_velocityRangeUpperLabel4->setEditable (false, false, false);
    m_velocityRangeUpperLabel4->setColour (TextEditor::textColourId, Colours::black);
    m_velocityRangeUpperLabel4->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_velocityRangeLowerLabel4 = new Label ("velocityRangeLowerLabel",
                                                               TRANS("LOWER")));
    m_velocityRangeLowerLabel4->setFont (Font (12.00f, Font::bold));
    m_velocityRangeLowerLabel4->setJustificationType (Justification::centredLeft);
    m_velocityRangeLowerLabel4->setEditable (false, false, false);
    m_velocityRangeLowerLabel4->setColour (TextEditor::textColourId, Colours::black);
    m_velocityRangeLowerLabel4->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_velocityRangeLowerSlider4 = new MicroParameterSlider ("velocityRangeLowerSlider"));
    m_velocityRangeLowerSlider4->setRange (0, 127, 1);
    m_velocityRangeLowerSlider4->setSliderStyle (Slider::LinearBar);
    m_velocityRangeLowerSlider4->setTextBoxStyle (Slider::TextBoxLeft, false, 40, 20);
    m_velocityRangeLowerSlider4->setColour (Slider::backgroundColourId, Colour (0xfff2f59b));
    m_velocityRangeLowerSlider4->setColour (Slider::thumbColourId, Colour (0xffc4c86d));
    m_velocityRangeLowerSlider4->addListener (this);

    addAndMakeVisible (m_keyRangeLowerLabel4 = new Label ("keyRangeLowerLabel",
                                                          TRANS("LOWER")));
    m_keyRangeLowerLabel4->setFont (Font (12.00f, Font::bold));
    m_keyRangeLowerLabel4->setJustificationType (Justification::centred);
    m_keyRangeLowerLabel4->setEditable (false, false, false);
    m_keyRangeLowerLabel4->setColour (TextEditor::textColourId, Colours::black);
    m_keyRangeLowerLabel4->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_keyRangeLowerSlider4 = new MicroParameterSlider ("keyRangeLowerSlider"));
    m_keyRangeLowerSlider4->setRange (0, 127, 1);
    m_keyRangeLowerSlider4->setSliderStyle (Slider::LinearBar);
    m_keyRangeLowerSlider4->setTextBoxStyle (Slider::TextBoxLeft, false, 40, 20);
    m_keyRangeLowerSlider4->setColour (Slider::backgroundColourId, Colour (0xfff2f59b));
    m_keyRangeLowerSlider4->setColour (Slider::thumbColourId, Colour (0xffc4c86d));
    m_keyRangeLowerSlider4->addListener (this);

    addAndMakeVisible (m_keyRangeUpperSlider4 = new MicroParameterSlider ("keyRangeUpperSlider"));
    m_keyRangeUpperSlider4->setRange (0, 127, 1);
    m_keyRangeUpperSlider4->setSliderStyle (Slider::LinearBar);
    m_keyRangeUpperSlider4->setTextBoxStyle (Slider::TextBoxLeft, false, 40, 20);
    m_keyRangeUpperSlider4->setColour (Slider::backgroundColourId, Colour (0xfff2f59b));
    m_keyRangeUpperSlider4->setColour (Slider::thumbColourId, Colour (0xffc4c86d));
    m_keyRangeUpperSlider4->addListener (this);

    addAndMakeVisible (m_keyRangeUpperLabel4 = new Label ("keyRangeUpperLabel",
                                                          TRANS("UPPER")));
    m_keyRangeUpperLabel4->setFont (Font (12.00f, Font::bold));
    m_keyRangeUpperLabel4->setJustificationType (Justification::centred);
    m_keyRangeUpperLabel4->setEditable (false, false, false);
    m_keyRangeUpperLabel4->setColour (TextEditor::textColourId, Colours::black);
    m_keyRangeUpperLabel4->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_biasLevelSlider4 = new MicroParameterSlider ("biasLevelSlider"));
    m_biasLevelSlider4->setRange (0, 127, 1);
    m_biasLevelSlider4->setSliderStyle (Slider::LinearBar);
    m_biasLevelSlider4->setTextBoxStyle (Slider::TextBoxLeft, false, 40, 20);
    m_biasLevelSlider4->setColour (Slider::backgroundColourId, Colour (0xfff2f59b));
    m_biasLevelSlider4->setColour (Slider::thumbColourId, Colour (0xffc4c86d));
    m_biasLevelSlider4->addListener (this);

    addAndMakeVisible (m_biasLevelLabel4 = new Label ("biasLevelLabel",
                                                      TRANS("BIAS LEVEL")));
    m_biasLevelLabel4->setFont (Font (12.00f, Font::bold));
    m_biasLevelLabel4->setJustificationType (Justification::centredLeft);
    m_biasLevelLabel4->setEditable (false, false, false);
    m_biasLevelLabel4->setColour (TextEditor::textColourId, Colours::black);
    m_biasLevelLabel4->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_biasPointLabel4 = new Label ("biasPointLabel",
                                                      TRANS("BIAS POINT")));
    m_biasPointLabel4->setFont (Font (12.00f, Font::bold));
    m_biasPointLabel4->setJustificationType (Justification::centredLeft);
    m_biasPointLabel4->setEditable (false, false, false);
    m_biasPointLabel4->setColour (TextEditor::textColourId, Colours::black);
    m_biasPointLabel4->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_biasPointSlider4 = new MicroParameterSlider ("biasPointSlider"));
    m_biasPointSlider4->setRange (0, 127, 1);
    m_biasPointSlider4->setSliderStyle (Slider::LinearBar);
    m_biasPointSlider4->setTextBoxStyle (Slider::TextBoxLeft, false, 40, 20);
    m_biasPointSlider4->setColour (Slider::backgroundColourId, Colour (0xfff2f59b));
    m_biasPointSlider4->setColour (Slider::thumbColourId, Colour (0xffc4c86d));
    m_biasPointSlider4->addListener (this);

    addAndMakeVisible (m_biasDirectionComboBox4 = new ParameterComboBox ("biasDirectionComboBox"));
    m_biasDirectionComboBox4->setEditableText (false);
    m_biasDirectionComboBox4->setJustificationType (Justification::centredLeft);
    m_biasDirectionComboBox4->setTextWhenNothingSelected (String());
    m_biasDirectionComboBox4->setTextWhenNoChoicesAvailable (TRANS("(no choices)"));
    m_biasDirectionComboBox4->addListener (this);

    addAndMakeVisible (m_biasDirectionLabel4 = new Label ("biasDirectionLabel",
                                                          TRANS("DIRECTION")));
    m_biasDirectionLabel4->setFont (Font (12.00f, Font::bold));
    m_biasDirectionLabel4->setJustificationType (Justification::centredLeft);
    m_biasDirectionLabel4->setEditable (false, false, false);
    m_biasDirectionLabel4->setColour (TextEditor::textColourId, Colours::black);
    m_biasDirectionLabel4->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_toneLevelLabel4 = new Label ("toneLevelLabel",
                                                      TRANS("TONE LEVEL")));
    m_toneLevelLabel4->setFont (Font (12.00f, Font::bold));
    m_toneLevelLabel4->setJustificationType (Justification::centredRight);
    m_toneLevelLabel4->setEditable (false, false, false);
    m_toneLevelLabel4->setColour (TextEditor::textColourId, Colours::black);
    m_toneLevelLabel4->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_toneLevelSlider4 = new MixPartLevelFader ("toneLevelSlider"));
    m_toneLevelSlider4->setRange (0, 127, 1);
    m_toneLevelSlider4->setSliderStyle (Slider::LinearVertical);
    m_toneLevelSlider4->setTextBoxStyle (Slider::TextBoxBelow, false, 32, 16);
    m_toneLevelSlider4->addListener (this);

    addAndMakeVisible (imageButton3 = new ImageButton ("new button"));
    imageButton3->setButtonText (String());
    imageButton3->addListener (this);

    imageButton3->setImages (false, true, true,
                             ImageCache::getFromMemory (tonemixtable_png, tonemixtable_pngSize), 1.000f, Colour (0x4340454a),
                             Image(), 1.000f, Colour (0x4340454a),
                             Image(), 1.000f, Colour (0x4340454a));

    //[UserPreSize]
	m_keyRangeLowerPtr1 = nullptr;
	m_keyRangeUpperPtr1 = nullptr;
	m_velocityLowerPtr1 = nullptr;
	m_velocityUpperPtr1 = nullptr;
	m_keyRangeLowerPtr2 = nullptr;
	m_keyRangeUpperPtr2 = nullptr;
	m_velocityLowerPtr2 = nullptr;
	m_velocityUpperPtr2 = nullptr;
	m_keyRangeLowerPtr3 = nullptr;
	m_keyRangeUpperPtr3 = nullptr;
	m_velocityLowerPtr3 = nullptr;
	m_velocityUpperPtr3 = nullptr;
	m_keyRangeLowerPtr4 = nullptr;
	m_keyRangeUpperPtr4 = nullptr;
	m_velocityLowerPtr4 = nullptr;
	m_velocityUpperPtr4 = nullptr;
    //[/UserPreSize]

    setSize (904, 672);


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
					m_velocityRangeToggle->setParameter(patchCommon->getParameter(0x40));
				}
				if (PatchToneBlock* tone1 = patchPart->getPatchToneBlockPtr(Tone1))
				{
					m_keyRangeLowerSlider1->setParameter(tone1->getParameter(0x0E));
					m_keyRangeLowerPtr1 = tone1->getParameter(0x0E);
					m_keyRangeLowerPtr1->addChangeListener(this);

					m_keyRangeUpperSlider1->setParameter(tone1->getParameter(0x0F));
					m_keyRangeUpperPtr1 = tone1->getParameter(0x0F);
					m_keyRangeUpperPtr1->addChangeListener(this);

					m_velocityRangeLowerSlider1->setParameter(tone1->getParameter(0x0C));
					m_velocityLowerPtr1 = tone1->getParameter(0x0C);
					m_velocityLowerPtr1->addChangeListener(this);

					m_velocityRangeUpperSlider1->setParameter(tone1->getParameter(0x0D));
					m_velocityUpperPtr1 = tone1->getParameter(0x0D);
					m_velocityUpperPtr1->addChangeListener(this);

					m_velocityCrossFadeSlider1->setParameter(tone1->getParameter(0x0B));
					m_toneLevelSlider1->setParameter(tone1->getParameter(0x65));
					m_biasDirectionComboBox1->setParameter(tone1->getParameter(0x66));
					m_biasPointSlider1->setParameter(tone1->getParameter(0x67));
					m_biasLevelSlider1->setParameter(tone1->getParameter(0x68));
				}
				if (PatchToneBlock* tone2 = patchPart->getPatchToneBlockPtr(Tone2))
				{
					m_keyRangeLowerPtr2 = tone2->getParameter(0x0E);
					m_keyRangeLowerPtr2->addChangeListener(this);
					m_keyRangeLowerSlider2->setParameter(m_keyRangeLowerPtr2);
					m_keyRangeUpperPtr2 = tone2->getParameter(0x0F);
					m_keyRangeUpperPtr2->addChangeListener(this);
					m_keyRangeUpperSlider2->setParameter(m_keyRangeUpperPtr2);
					m_velocityLowerPtr2 = tone2->getParameter(0x0C);
					m_velocityLowerPtr2->addChangeListener(this);
					m_velocityRangeLowerSlider2->setParameter(m_velocityLowerPtr2);
					m_velocityUpperPtr2 = tone2->getParameter(0x0D);
					m_velocityUpperPtr2->addChangeListener(this);
					m_velocityRangeUpperSlider2->setParameter(m_velocityUpperPtr2);
					m_velocityCrossFadeSlider2->setParameter(tone2->getParameter(0x0B));
					m_toneLevelSlider2->setParameter(tone2->getParameter(0x65));
					m_biasDirectionComboBox2->setParameter(tone2->getParameter(0x66));
					m_biasPointSlider2->setParameter(tone2->getParameter(0x67));
					m_biasLevelSlider2->setParameter(tone2->getParameter(0x68));
				}
				if (PatchToneBlock* tone3 = patchPart->getPatchToneBlockPtr(Tone3))
				{
					m_keyRangeLowerPtr3 = tone3->getParameter(0x0E);
					m_keyRangeLowerPtr3->addChangeListener(this);
					m_keyRangeLowerSlider3->setParameter(m_keyRangeLowerPtr3);
					m_keyRangeUpperPtr3 = tone3->getParameter(0x0F);
					m_keyRangeUpperPtr3->addChangeListener(this);
					m_keyRangeUpperSlider3->setParameter(m_keyRangeUpperPtr3);
					m_velocityLowerPtr3 = tone3->getParameter(0x0C);
					m_velocityLowerPtr3->addChangeListener(this);
					m_velocityRangeLowerSlider3->setParameter(m_velocityLowerPtr3);
					m_velocityUpperPtr3 = tone3->getParameter(0x0D);
					m_velocityUpperPtr3->addChangeListener(this);
					m_velocityRangeUpperSlider3->setParameter(m_velocityUpperPtr3);
					m_velocityCrossFadeSlider3->setParameter(tone3->getParameter(0x0B));
					m_toneLevelSlider3->setParameter(tone3->getParameter(0x65));
					m_biasDirectionComboBox3->setParameter(tone3->getParameter(0x66));
					m_biasPointSlider3->setParameter(tone3->getParameter(0x67));
					m_biasLevelSlider3->setParameter(tone3->getParameter(0x68));
				}
				if (PatchToneBlock* tone4 = patchPart->getPatchToneBlockPtr(Tone4))
				{
					m_keyRangeLowerPtr4 = tone4->getParameter(0x0E);
					m_keyRangeLowerPtr4->addChangeListener(this);
					m_keyRangeLowerSlider4->setParameter(m_keyRangeLowerPtr4);
					m_keyRangeUpperPtr4 = tone4->getParameter(0x0F);
					m_keyRangeUpperPtr4->addChangeListener(this);
					m_keyRangeUpperSlider4->setParameter(m_keyRangeUpperPtr4);
					m_velocityLowerPtr4 = tone4->getParameter(0x0C);
					m_velocityLowerPtr4->addChangeListener(this);
					m_velocityRangeLowerSlider4->setParameter(m_velocityLowerPtr4);
					m_velocityUpperPtr4 = tone4->getParameter(0x0D);
					m_velocityUpperPtr4->addChangeListener(this);
					m_velocityRangeUpperSlider4->setParameter(m_velocityUpperPtr4);
					m_velocityCrossFadeSlider4->setParameter(tone4->getParameter(0x0B));
					m_toneLevelSlider4->setParameter(tone4->getParameter(0x65));
					m_biasDirectionComboBox4->setParameter(tone4->getParameter(0x66));
					m_biasPointSlider4->setParameter(tone4->getParameter(0x67));
					m_biasLevelSlider4->setParameter(tone4->getParameter(0x68));
				}
			}
		}
	}
	changeListenerCallback(m_keyRangeLowerPtr1);
	changeListenerCallback(m_keyRangeLowerPtr1);
	changeListenerCallback(m_keyRangeUpperPtr1);
	changeListenerCallback(m_velocityLowerPtr1);
	changeListenerCallback(m_velocityUpperPtr1);
	changeListenerCallback(m_keyRangeLowerPtr2);
	changeListenerCallback(m_keyRangeUpperPtr2);
	changeListenerCallback(m_velocityLowerPtr2);
	changeListenerCallback(m_velocityUpperPtr2);
	changeListenerCallback(m_keyRangeLowerPtr3);
	changeListenerCallback(m_keyRangeUpperPtr3);
	changeListenerCallback(m_velocityLowerPtr3);
	changeListenerCallback(m_velocityUpperPtr3);
	changeListenerCallback(m_keyRangeLowerPtr4);
	changeListenerCallback(m_keyRangeUpperPtr4);
	changeListenerCallback(m_velocityLowerPtr4);
	changeListenerCallback(m_velocityUpperPtr4);
	m_toneMixTableBoard->getToneMixTableCanvasPtr()->getToneMixTableTone(Tone::Tone1)->changeListenerCallback(m_keyRangeLowerPtr1);
	m_toneMixTableBoard->getToneMixTableCanvasPtr()->getToneMixTableTone(Tone::Tone2)->changeListenerCallback(m_keyRangeLowerPtr2);
	m_toneMixTableBoard->getToneMixTableCanvasPtr()->getToneMixTableTone(Tone::Tone3)->changeListenerCallback(m_keyRangeLowerPtr3);
	m_toneMixTableBoard->getToneMixTableCanvasPtr()->getToneMixTableTone(Tone::Tone4)->changeListenerCallback(m_keyRangeLowerPtr4);
    //[/Constructor]
}

ToneMixTable::~ToneMixTable()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
	if (m_keyRangeLowerPtr1 != nullptr) m_keyRangeLowerPtr1->removeChangeListener(this);
	if (m_keyRangeUpperPtr1 != nullptr) m_keyRangeUpperPtr1->removeChangeListener(this);
	if (m_velocityLowerPtr1 != nullptr) m_velocityLowerPtr1->removeChangeListener(this);
	if (m_velocityUpperPtr1 != nullptr) m_velocityUpperPtr1->removeChangeListener(this);
	if (m_keyRangeLowerPtr2 != nullptr) m_keyRangeLowerPtr2->removeChangeListener(this);
	if (m_keyRangeUpperPtr2 != nullptr) m_keyRangeUpperPtr2->removeChangeListener(this);
	if (m_velocityLowerPtr2 != nullptr) m_velocityLowerPtr2->removeChangeListener(this);
	if (m_velocityUpperPtr2 != nullptr) m_velocityUpperPtr2->removeChangeListener(this);
	if (m_keyRangeLowerPtr3 != nullptr) m_keyRangeLowerPtr3->removeChangeListener(this);
	if (m_keyRangeUpperPtr3 != nullptr) m_keyRangeUpperPtr3->removeChangeListener(this);
	if (m_velocityLowerPtr3 != nullptr) m_velocityLowerPtr3->removeChangeListener(this);
	if (m_velocityUpperPtr3 != nullptr) m_velocityUpperPtr3->removeChangeListener(this);
	if (m_keyRangeLowerPtr4 != nullptr) m_keyRangeLowerPtr4->removeChangeListener(this);
	if (m_keyRangeUpperPtr4 != nullptr) m_keyRangeUpperPtr4->removeChangeListener(this);
	if (m_velocityLowerPtr4 != nullptr) m_velocityLowerPtr4->removeChangeListener(this);
	if (m_velocityUpperPtr4 != nullptr) m_velocityUpperPtr4->removeChangeListener(this);
    //[/Destructor_pre]

    m_grp = nullptr;
    m_ampBiasGrp1 = nullptr;
    m_toneMixTableBoard = nullptr;
    m_velocityRangeToggle = nullptr;
    m_velocityRangeLabel = nullptr;
    m_keyRangeGrp1 = nullptr;
    m_veloRangeGrp1 = nullptr;
    m_velocityCrossFadeSlider1 = nullptr;
    m_velocityCrossFadeLabel1 = nullptr;
    m_velocityRangeUpperSlider1 = nullptr;
    m_velocityRangeUpperLabel1 = nullptr;
    m_velocityRangeLowerLabel1 = nullptr;
    m_velocityRangeLowerSlider1 = nullptr;
    m_keyRangeLowerLabel1 = nullptr;
    m_keyRangeLowerSlider1 = nullptr;
    m_keyRangeUpperSlider1 = nullptr;
    m_keyRangeUpperLabel1 = nullptr;
    m_biasLevelSlider1 = nullptr;
    m_biasLevelLabel1 = nullptr;
    m_biasPointLabel1 = nullptr;
    m_biasPointSlider1 = nullptr;
    m_biasDirectionComboBox1 = nullptr;
    m_biasDirectionLabel1 = nullptr;
    m_toneLevelLabel1 = nullptr;
    m_toneLevelSlider1 = nullptr;
    m_keyRangeGrp2 = nullptr;
    m_keyRangeGrp3 = nullptr;
    m_keyRangeGrp4 = nullptr;
    m_ampBiasGrp2 = nullptr;
    m_veloRangeGrp2 = nullptr;
    m_velocityCrossFadeSlider2 = nullptr;
    m_velocityCrossFadeLabel2 = nullptr;
    m_velocityRangeUpperSlider2 = nullptr;
    m_velocityRangeUpperLabel2 = nullptr;
    m_velocityRangeLowerLabel2 = nullptr;
    m_velocityRangeLowerSlider2 = nullptr;
    m_keyRangeLowerLabel2 = nullptr;
    m_keyRangeLowerSlider2 = nullptr;
    m_keyRangeUpperSlider2 = nullptr;
    m_keyRangeUpperLabel2 = nullptr;
    m_biasLevelSlider2 = nullptr;
    m_biasLevelLabel2 = nullptr;
    m_biasPointLabel2 = nullptr;
    m_biasPointSlider2 = nullptr;
    m_biasDirectionComboBox2 = nullptr;
    m_biasDirectionLabel2 = nullptr;
    m_toneLevelLabel2 = nullptr;
    m_toneLevelSlider2 = nullptr;
    m_ampBiasGrp3 = nullptr;
    m_veloRangeGrp3 = nullptr;
    m_velocityCrossFadeSlider3 = nullptr;
    m_velocityCrossFadeLabel3 = nullptr;
    m_velocityRangeUpperSlider3 = nullptr;
    m_velocityRangeUpperLabel3 = nullptr;
    m_velocityRangeLowerLabel3 = nullptr;
    m_velocityRangeLowerSlider3 = nullptr;
    m_keyRangeLowerLabel3 = nullptr;
    m_keyRangeLowerSlider3 = nullptr;
    m_keyRangeUpperSlider3 = nullptr;
    m_keyRangeUpperLabel3 = nullptr;
    m_biasLevelSlider3 = nullptr;
    m_biasLevelLabel3 = nullptr;
    m_biasPointLabel3 = nullptr;
    m_biasPointSlider3 = nullptr;
    m_biasDirectionComboBox3 = nullptr;
    m_biasDirectionLabel3 = nullptr;
    m_toneLevelLabel3 = nullptr;
    m_toneLevelSlider3 = nullptr;
    m_ampBiasGrp4 = nullptr;
    m_veloRangeGrp4 = nullptr;
    m_velocityCrossFadeSlider4 = nullptr;
    m_velocityCrossFadeLabel4 = nullptr;
    m_velocityRangeUpperSlider4 = nullptr;
    m_velocityRangeUpperLabel4 = nullptr;
    m_velocityRangeLowerLabel4 = nullptr;
    m_velocityRangeLowerSlider4 = nullptr;
    m_keyRangeLowerLabel4 = nullptr;
    m_keyRangeLowerSlider4 = nullptr;
    m_keyRangeUpperSlider4 = nullptr;
    m_keyRangeUpperLabel4 = nullptr;
    m_biasLevelSlider4 = nullptr;
    m_biasLevelLabel4 = nullptr;
    m_biasPointLabel4 = nullptr;
    m_biasPointSlider4 = nullptr;
    m_biasDirectionComboBox4 = nullptr;
    m_biasDirectionLabel4 = nullptr;
    m_toneLevelLabel4 = nullptr;
    m_toneLevelSlider4 = nullptr;
    imageButton3 = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void ToneMixTable::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
	#ifdef JUCE_MSVC
	g;
	#endif
    //[/UserPrePaint]

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void ToneMixTable::resized()
{
    m_grp->setBounds (0, 0, getWidth() - 0, getHeight() - 0);
    m_ampBiasGrp1->setBounds (4, 516, 220, 144);
    m_toneMixTableBoard->setBounds (4, 21, 896, 302);
    m_velocityRangeToggle->setBounds (160, 404, 25, 17);
    m_velocityRangeLabel->setBounds (8, 404, 148, 16);
    m_keyRangeGrp1->setBounds (4, 332, 220, 64);
    m_veloRangeGrp1->setBounds (4, 424, 220, 84);
    m_velocityCrossFadeSlider1->setBounds (88, 484, 56, 16);
    m_velocityCrossFadeLabel1->setBounds (8, 484, 80, 16);
    m_velocityRangeUpperSlider1->setBounds (88, 464, 56, 16);
    m_velocityRangeUpperLabel1->setBounds (8, 464, 80, 16);
    m_velocityRangeLowerLabel1->setBounds (8, 444, 80, 16);
    m_velocityRangeLowerSlider1->setBounds (88, 444, 56, 16);
    m_keyRangeLowerLabel1->setBounds (8, 352, 104, 16);
    m_keyRangeLowerSlider1->setBounds (32, 372, 56, 16);
    m_keyRangeUpperSlider1->setBounds (140, 372, 56, 16);
    m_keyRangeUpperLabel1->setBounds (116, 352, 104, 16);
    m_biasLevelSlider1->setBounds (88, 616, 56, 16);
    m_biasLevelLabel1->setBounds (12, 616, 76, 16);
    m_biasPointLabel1->setBounds (12, 596, 76, 16);
    m_biasPointSlider1->setBounds (88, 596, 56, 16);
    m_biasDirectionComboBox1->setBounds (88, 574, 80, 17);
    m_biasDirectionLabel1->setBounds (12, 576, 76, 16);
    m_toneLevelLabel1->setBounds (88, 536, 108, 16);
    m_toneLevelSlider1->setBounds (192, 532, 26, 120);
    m_keyRangeGrp2->setBounds (228, 332, 220, 64);
    m_keyRangeGrp3->setBounds (456, 332, 220, 64);
    m_keyRangeGrp4->setBounds (680, 332, 220, 64);
    m_ampBiasGrp2->setBounds (228, 516, 220, 144);
    m_veloRangeGrp2->setBounds (228, 424, 220, 84);
    m_velocityCrossFadeSlider2->setBounds (312, 484, 56, 16);
    m_velocityCrossFadeLabel2->setBounds (232, 484, 80, 16);
    m_velocityRangeUpperSlider2->setBounds (312, 464, 56, 16);
    m_velocityRangeUpperLabel2->setBounds (232, 464, 80, 16);
    m_velocityRangeLowerLabel2->setBounds (232, 444, 80, 16);
    m_velocityRangeLowerSlider2->setBounds (312, 444, 56, 16);
    m_keyRangeLowerLabel2->setBounds (232, 352, 104, 16);
    m_keyRangeLowerSlider2->setBounds (256, 372, 56, 16);
    m_keyRangeUpperSlider2->setBounds (364, 372, 56, 16);
    m_keyRangeUpperLabel2->setBounds (340, 352, 104, 16);
    m_biasLevelSlider2->setBounds (312, 616, 56, 16);
    m_biasLevelLabel2->setBounds (236, 616, 76, 16);
    m_biasPointLabel2->setBounds (236, 596, 76, 16);
    m_biasPointSlider2->setBounds (312, 596, 56, 16);
    m_biasDirectionComboBox2->setBounds (312, 575, 80, 17);
    m_biasDirectionLabel2->setBounds (236, 576, 76, 16);
    m_toneLevelLabel2->setBounds (312, 536, 108, 16);
    m_toneLevelSlider2->setBounds (416, 532, 26, 120);
    m_ampBiasGrp3->setBounds (455, 516, 220, 144);
    m_veloRangeGrp3->setBounds (455, 424, 220, 84);
    m_velocityCrossFadeSlider3->setBounds (539, 484, 56, 16);
    m_velocityCrossFadeLabel3->setBounds (459, 484, 80, 16);
    m_velocityRangeUpperSlider3->setBounds (539, 464, 56, 16);
    m_velocityRangeUpperLabel3->setBounds (459, 464, 80, 16);
    m_velocityRangeLowerLabel3->setBounds (459, 444, 80, 16);
    m_velocityRangeLowerSlider3->setBounds (539, 444, 56, 16);
    m_keyRangeLowerLabel3->setBounds (459, 352, 104, 16);
    m_keyRangeLowerSlider3->setBounds (484, 372, 56, 16);
    m_keyRangeUpperSlider3->setBounds (592, 372, 56, 16);
    m_keyRangeUpperLabel3->setBounds (568, 352, 104, 16);
    m_biasLevelSlider3->setBounds (539, 616, 56, 16);
    m_biasLevelLabel3->setBounds (463, 616, 76, 16);
    m_biasPointLabel3->setBounds (463, 596, 76, 16);
    m_biasPointSlider3->setBounds (539, 596, 56, 16);
    m_biasDirectionComboBox3->setBounds (539, 574, 80, 17);
    m_biasDirectionLabel3->setBounds (463, 576, 76, 16);
    m_toneLevelLabel3->setBounds (539, 536, 108, 16);
    m_toneLevelSlider3->setBounds (643, 532, 26, 120);
    m_ampBiasGrp4->setBounds (680, 516, 220, 144);
    m_veloRangeGrp4->setBounds (680, 424, 220, 84);
    m_velocityCrossFadeSlider4->setBounds (764, 484, 56, 16);
    m_velocityCrossFadeLabel4->setBounds (684, 484, 80, 16);
    m_velocityRangeUpperSlider4->setBounds (764, 464, 56, 16);
    m_velocityRangeUpperLabel4->setBounds (684, 464, 80, 16);
    m_velocityRangeLowerLabel4->setBounds (684, 444, 80, 16);
    m_velocityRangeLowerSlider4->setBounds (764, 444, 56, 16);
    m_keyRangeLowerLabel4->setBounds (684, 352, 104, 16);
    m_keyRangeLowerSlider4->setBounds (708, 372, 56, 16);
    m_keyRangeUpperSlider4->setBounds (820, 372, 56, 16);
    m_keyRangeUpperLabel4->setBounds (792, 352, 104, 16);
    m_biasLevelSlider4->setBounds (764, 616, 56, 16);
    m_biasLevelLabel4->setBounds (688, 616, 76, 16);
    m_biasPointLabel4->setBounds (688, 596, 76, 16);
    m_biasPointSlider4->setBounds (764, 596, 56, 16);
    m_biasDirectionComboBox4->setBounds (764, 574, 80, 17);
    m_biasDirectionLabel4->setBounds (688, 576, 76, 16);
    m_toneLevelLabel4->setBounds (764, 536, 108, 16);
    m_toneLevelSlider4->setBounds (868, 532, 26, 120);
    imageButton3->setBounds (3, 1, 16, 16);
    //[UserResized] Add your own custom resize handling here..

    // This is called when the ToneMixTable is resized.
    // If you add any child components, this is where you should
    // update their positions.

    //[/UserResized]
}

void ToneMixTable::sliderValueChanged (Slider* sliderThatWasMoved)
{
    //[UsersliderValueChanged_Pre]
    //[/UsersliderValueChanged_Pre]

    if (sliderThatWasMoved == m_velocityCrossFadeSlider1)
    {
        //[UserSliderCode_m_velocityCrossFadeSlider1] -- add your slider handling code here..
        //[/UserSliderCode_m_velocityCrossFadeSlider1]
    }
    else if (sliderThatWasMoved == m_velocityRangeUpperSlider1)
    {
        //[UserSliderCode_m_velocityRangeUpperSlider1] -- add your slider handling code here..
        //[/UserSliderCode_m_velocityRangeUpperSlider1]
    }
    else if (sliderThatWasMoved == m_velocityRangeLowerSlider1)
    {
        //[UserSliderCode_m_velocityRangeLowerSlider1] -- add your slider handling code here..
        //[/UserSliderCode_m_velocityRangeLowerSlider1]
    }
    else if (sliderThatWasMoved == m_keyRangeLowerSlider1)
    {
        //[UserSliderCode_m_keyRangeLowerSlider1] -- add your slider handling code here..
        //[/UserSliderCode_m_keyRangeLowerSlider1]
    }
    else if (sliderThatWasMoved == m_keyRangeUpperSlider1)
    {
        //[UserSliderCode_m_keyRangeUpperSlider1] -- add your slider handling code here..
        //[/UserSliderCode_m_keyRangeUpperSlider1]
    }
    else if (sliderThatWasMoved == m_biasLevelSlider1)
    {
        //[UserSliderCode_m_biasLevelSlider1] -- add your slider handling code here..
        //[/UserSliderCode_m_biasLevelSlider1]
    }
    else if (sliderThatWasMoved == m_biasPointSlider1)
    {
        //[UserSliderCode_m_biasPointSlider1] -- add your slider handling code here..
        //[/UserSliderCode_m_biasPointSlider1]
    }
    else if (sliderThatWasMoved == m_toneLevelSlider1)
    {
        //[UserSliderCode_m_toneLevelSlider1] -- add your slider handling code here..
        //[/UserSliderCode_m_toneLevelSlider1]
    }
    else if (sliderThatWasMoved == m_velocityCrossFadeSlider2)
    {
        //[UserSliderCode_m_velocityCrossFadeSlider2] -- add your slider handling code here..
        //[/UserSliderCode_m_velocityCrossFadeSlider2]
    }
    else if (sliderThatWasMoved == m_velocityRangeUpperSlider2)
    {
        //[UserSliderCode_m_velocityRangeUpperSlider2] -- add your slider handling code here..
        //[/UserSliderCode_m_velocityRangeUpperSlider2]
    }
    else if (sliderThatWasMoved == m_velocityRangeLowerSlider2)
    {
        //[UserSliderCode_m_velocityRangeLowerSlider2] -- add your slider handling code here..
        //[/UserSliderCode_m_velocityRangeLowerSlider2]
    }
    else if (sliderThatWasMoved == m_keyRangeLowerSlider2)
    {
        //[UserSliderCode_m_keyRangeLowerSlider2] -- add your slider handling code here..
        //[/UserSliderCode_m_keyRangeLowerSlider2]
    }
    else if (sliderThatWasMoved == m_keyRangeUpperSlider2)
    {
        //[UserSliderCode_m_keyRangeUpperSlider2] -- add your slider handling code here..
        //[/UserSliderCode_m_keyRangeUpperSlider2]
    }
    else if (sliderThatWasMoved == m_biasLevelSlider2)
    {
        //[UserSliderCode_m_biasLevelSlider2] -- add your slider handling code here..
        //[/UserSliderCode_m_biasLevelSlider2]
    }
    else if (sliderThatWasMoved == m_biasPointSlider2)
    {
        //[UserSliderCode_m_biasPointSlider2] -- add your slider handling code here..
        //[/UserSliderCode_m_biasPointSlider2]
    }
    else if (sliderThatWasMoved == m_toneLevelSlider2)
    {
        //[UserSliderCode_m_toneLevelSlider2] -- add your slider handling code here..
        //[/UserSliderCode_m_toneLevelSlider2]
    }
    else if (sliderThatWasMoved == m_velocityCrossFadeSlider3)
    {
        //[UserSliderCode_m_velocityCrossFadeSlider3] -- add your slider handling code here..
        //[/UserSliderCode_m_velocityCrossFadeSlider3]
    }
    else if (sliderThatWasMoved == m_velocityRangeUpperSlider3)
    {
        //[UserSliderCode_m_velocityRangeUpperSlider3] -- add your slider handling code here..
        //[/UserSliderCode_m_velocityRangeUpperSlider3]
    }
    else if (sliderThatWasMoved == m_velocityRangeLowerSlider3)
    {
        //[UserSliderCode_m_velocityRangeLowerSlider3] -- add your slider handling code here..
        //[/UserSliderCode_m_velocityRangeLowerSlider3]
    }
    else if (sliderThatWasMoved == m_keyRangeLowerSlider3)
    {
        //[UserSliderCode_m_keyRangeLowerSlider3] -- add your slider handling code here..
        //[/UserSliderCode_m_keyRangeLowerSlider3]
    }
    else if (sliderThatWasMoved == m_keyRangeUpperSlider3)
    {
        //[UserSliderCode_m_keyRangeUpperSlider3] -- add your slider handling code here..
        //[/UserSliderCode_m_keyRangeUpperSlider3]
    }
    else if (sliderThatWasMoved == m_biasLevelSlider3)
    {
        //[UserSliderCode_m_biasLevelSlider3] -- add your slider handling code here..
        //[/UserSliderCode_m_biasLevelSlider3]
    }
    else if (sliderThatWasMoved == m_biasPointSlider3)
    {
        //[UserSliderCode_m_biasPointSlider3] -- add your slider handling code here..
        //[/UserSliderCode_m_biasPointSlider3]
    }
    else if (sliderThatWasMoved == m_toneLevelSlider3)
    {
        //[UserSliderCode_m_toneLevelSlider3] -- add your slider handling code here..
        //[/UserSliderCode_m_toneLevelSlider3]
    }
    else if (sliderThatWasMoved == m_velocityCrossFadeSlider4)
    {
        //[UserSliderCode_m_velocityCrossFadeSlider4] -- add your slider handling code here..
        //[/UserSliderCode_m_velocityCrossFadeSlider4]
    }
    else if (sliderThatWasMoved == m_velocityRangeUpperSlider4)
    {
        //[UserSliderCode_m_velocityRangeUpperSlider4] -- add your slider handling code here..
        //[/UserSliderCode_m_velocityRangeUpperSlider4]
    }
    else if (sliderThatWasMoved == m_velocityRangeLowerSlider4)
    {
        //[UserSliderCode_m_velocityRangeLowerSlider4] -- add your slider handling code here..
        //[/UserSliderCode_m_velocityRangeLowerSlider4]
    }
    else if (sliderThatWasMoved == m_keyRangeLowerSlider4)
    {
        //[UserSliderCode_m_keyRangeLowerSlider4] -- add your slider handling code here..
        //[/UserSliderCode_m_keyRangeLowerSlider4]
    }
    else if (sliderThatWasMoved == m_keyRangeUpperSlider4)
    {
        //[UserSliderCode_m_keyRangeUpperSlider4] -- add your slider handling code here..
        //[/UserSliderCode_m_keyRangeUpperSlider4]
    }
    else if (sliderThatWasMoved == m_biasLevelSlider4)
    {
        //[UserSliderCode_m_biasLevelSlider4] -- add your slider handling code here..
        //[/UserSliderCode_m_biasLevelSlider4]
    }
    else if (sliderThatWasMoved == m_biasPointSlider4)
    {
        //[UserSliderCode_m_biasPointSlider4] -- add your slider handling code here..
        //[/UserSliderCode_m_biasPointSlider4]
    }
    else if (sliderThatWasMoved == m_toneLevelSlider4)
    {
        //[UserSliderCode_m_toneLevelSlider4] -- add your slider handling code here..
        //[/UserSliderCode_m_toneLevelSlider4]
    }

    //[UsersliderValueChanged_Post]
    //[/UsersliderValueChanged_Post]
}

void ToneMixTable::comboBoxChanged (ComboBox* comboBoxThatHasChanged)
{
    //[UsercomboBoxChanged_Pre]
    //[/UsercomboBoxChanged_Pre]

    if (comboBoxThatHasChanged == m_biasDirectionComboBox1)
    {
        //[UserComboBoxCode_m_biasDirectionComboBox1] -- add your combo box handling code here..
        //[/UserComboBoxCode_m_biasDirectionComboBox1]
    }
    else if (comboBoxThatHasChanged == m_biasDirectionComboBox2)
    {
        //[UserComboBoxCode_m_biasDirectionComboBox2] -- add your combo box handling code here..
        //[/UserComboBoxCode_m_biasDirectionComboBox2]
    }
    else if (comboBoxThatHasChanged == m_biasDirectionComboBox3)
    {
        //[UserComboBoxCode_m_biasDirectionComboBox3] -- add your combo box handling code here..
        //[/UserComboBoxCode_m_biasDirectionComboBox3]
    }
    else if (comboBoxThatHasChanged == m_biasDirectionComboBox4)
    {
        //[UserComboBoxCode_m_biasDirectionComboBox4] -- add your combo box handling code here..
        //[/UserComboBoxCode_m_biasDirectionComboBox4]
    }

    //[UsercomboBoxChanged_Post]
    //[/UsercomboBoxChanged_Post]
}

void ToneMixTable::buttonClicked (Button* buttonThatWasClicked)
{
    //[UserbuttonClicked_Pre]
    //[/UserbuttonClicked_Pre]

    if (buttonThatWasClicked == imageButton3)
    {
        //[UserButtonCode_imageButton3] -- add your button handler code here..
        //[/UserButtonCode_imageButton3]
    }

    //[UserbuttonClicked_Post]
    //[/UserbuttonClicked_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
void ToneMixTable::changeListenerCallback(ChangeBroadcaster* source)
{
	if (source == m_keyRangeLowerPtr1)
	{
		m_keyRangeUpperPtr1->setMin(m_keyRangeLowerPtr1->getValue());
		m_keyRangeUpperSlider1->setRange((double)m_keyRangeLowerPtr1->getValue(), 127.0, 1.0);
	}

	if (source == m_keyRangeUpperPtr1)
	{
		m_keyRangeLowerPtr1->setMax(m_keyRangeUpperPtr1->getValue());
		m_keyRangeLowerSlider1->setRange(0.0, (double)m_keyRangeUpperPtr1->getValue(), 1.0);
	}

	if (source == m_velocityLowerPtr1)
	{
		m_velocityUpperPtr1->setMin(m_velocityLowerPtr1->getValue());
		m_velocityRangeUpperSlider1->setRange((double)m_velocityLowerPtr1->getValue(), 127.0, 1.0);
	}

	if (source == m_velocityUpperPtr1)
	{
		m_velocityLowerPtr1->setMax(m_velocityUpperPtr1->getValue());
		m_velocityRangeLowerSlider1->setRange(1.0, (double)m_velocityUpperPtr1->getValue(), 1.0);
	}

	if (source == m_keyRangeLowerPtr2)
	{
		m_keyRangeUpperPtr2->setMin(m_keyRangeLowerPtr2->getValue());
		m_keyRangeUpperSlider2->setRange((double)m_keyRangeLowerPtr2->getValue(), 127.0, 1.0);
	}

	if (source == m_keyRangeUpperPtr2)
	{
		m_keyRangeLowerPtr2->setMax(m_keyRangeUpperPtr2->getValue());
		m_keyRangeLowerSlider2->setRange(0.0, (double)m_keyRangeUpperPtr2->getValue(), 1.0);
	}

	if (source == m_velocityLowerPtr2)
	{
		m_velocityUpperPtr2->setMin(m_velocityLowerPtr2->getValue());
		m_velocityRangeUpperSlider2->setRange((double)m_velocityLowerPtr2->getValue(), 127.0, 1.0);
	}

	if (source == m_velocityUpperPtr2)
	{
		m_velocityLowerPtr2->setMax(m_velocityUpperPtr2->getValue());
		m_velocityRangeLowerSlider2->setRange(1.0, (double)m_velocityUpperPtr2->getValue(), 1.0);
	}

	if (source == m_keyRangeLowerPtr3)
	{
		m_keyRangeUpperPtr3->setMin(m_keyRangeLowerPtr3->getValue());
		m_keyRangeUpperSlider3->setRange((double)m_keyRangeLowerPtr3->getValue(), 127.0, 1.0);
	}

	if (source == m_keyRangeUpperPtr3)
	{
		m_keyRangeLowerPtr3->setMax(m_keyRangeUpperPtr3->getValue());
		m_keyRangeLowerSlider3->setRange(0.0, (double)m_keyRangeUpperPtr3->getValue(), 1.0);
	}

	if (source == m_velocityLowerPtr3)
	{
		m_velocityUpperPtr3->setMin(m_velocityLowerPtr3->getValue());
		m_velocityRangeUpperSlider3->setRange((double)m_velocityLowerPtr3->getValue(), 127.0, 1.0);
	}

	if (source == m_velocityUpperPtr3)
	{
		m_velocityLowerPtr3->setMax(m_velocityUpperPtr3->getValue());
		m_velocityRangeLowerSlider3->setRange(1.0, (double)m_velocityUpperPtr3->getValue(), 1.0);
	}

	if (source == m_keyRangeLowerPtr4)
	{
		m_keyRangeUpperPtr4->setMin(m_keyRangeLowerPtr4->getValue());
		m_keyRangeUpperSlider4->setRange((double)m_keyRangeLowerPtr4->getValue(), 127.0, 1.0);
	}

	if (source == m_keyRangeUpperPtr4)
	{
		m_keyRangeLowerPtr4->setMax(m_keyRangeUpperPtr4->getValue());
		m_keyRangeLowerSlider4->setRange(0.0, (double)m_keyRangeUpperPtr4->getValue(), 1.0);
	}

	if (source == m_velocityLowerPtr4)
	{
		m_velocityUpperPtr4->setMin(m_velocityLowerPtr4->getValue());
		m_velocityRangeUpperSlider4->setRange((double)m_velocityLowerPtr4->getValue(), 127.0, 1.0);
	}

	if (source == m_velocityUpperPtr4)
	{
		m_velocityLowerPtr4->setMax(m_velocityUpperPtr4->getValue());
		m_velocityRangeLowerSlider4->setRange(1.0, (double)m_velocityUpperPtr4->getValue(), 1.0);
	}

}
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Introjucer information section --

    This is where the Introjucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="ToneMixTable" componentName=""
                 parentClasses="public Component, public ChangeListener" constructorParams="const String &amp;componentName, SynthParts part"
                 variableInitialisers="Component (componentName), m_part(part)"
                 snapPixels="4" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="1" initialWidth="904" initialHeight="672">
  <BACKGROUND backgroundColour="0"/>
  <JUCERCOMP name="grp" id="ff5a5983a4beb5a1" memberName="m_grp" virtualName=""
             explicitFocusOrder="0" pos="0 0 0M 0M" sourceFile="../GroupWidgets/PanelGroupGrey.cpp"
             constructorParams="&quot;grp&quot;, getName()"/>
  <JUCERCOMP name="ampBiasGrp" id="4e78694bc62276b5" memberName="m_ampBiasGrp1"
             virtualName="" explicitFocusOrder="0" pos="4 516 220 144" sourceFile="../GroupWidgets/PanelGroupTransp.cpp"
             constructorParams="&quot;ampBiasGrp&quot;, &quot;AMP BIAS TONE 1&quot;"/>
  <JUCERCOMP name="toneMixTableBoard" id="38be9190ffd03305" memberName="m_toneMixTableBoard"
             virtualName="" explicitFocusOrder="0" pos="4 21 896 302" sourceFile="ToneMixTableBoard.cpp"
             constructorParams="&quot;toneMixTableBoard&quot;, m_part"/>
  <JUCERCOMP name="velocityRangeToggle" id="dffe4f84e35eb99f" memberName="m_velocityRangeToggle"
             virtualName="" explicitFocusOrder="0" pos="160 404 25 17" sourceFile="../ParameterWidgets/BlackToggle.cpp"
             constructorParams=""/>
  <LABEL name="velocityRangeLabel" id="736670945c226895" memberName="m_velocityRangeLabel"
         virtualName="" explicitFocusOrder="0" pos="8 404 148 16" textCol="ff000000"
         edTextCol="ff000000" edBkgCol="0" labelText="USE VELOCITY RANGES"
         editableSingleClick="0" editableDoubleClick="0" focusDiscardsChanges="0"
         fontname="Default font" fontsize="12" bold="1" italic="0" justification="33"/>
  <JUCERCOMP name="keyRangeGrp" id="95f2e95a61789862" memberName="m_keyRangeGrp1"
             virtualName="" explicitFocusOrder="0" pos="4 332 220 64" sourceFile="../GroupWidgets/PanelGroupTransp.cpp"
             constructorParams="&quot;keyRangeGrp&quot;, &quot;KEY RANGE TONE 1&quot;"/>
  <JUCERCOMP name="veloRangeGrp" id="dee218cbc284afaf" memberName="m_veloRangeGrp1"
             virtualName="" explicitFocusOrder="0" pos="4 424 220 84" sourceFile="../GroupWidgets/PanelGroupTransp.cpp"
             constructorParams="&quot;veloRangeGrp&quot;, &quot;VELOCITY RANGE TONE 1&quot;"/>
  <SLIDER name="velocityCrossFadeSlider" id="c47855756a436532" memberName="m_velocityCrossFadeSlider1"
          virtualName="MicroParameterSlider" explicitFocusOrder="0" pos="88 484 56 16"
          bkgcol="fff2f59b" thumbcol="ffc4c86d" min="0" max="127" int="1"
          style="LinearBar" textBoxPos="TextBoxLeft" textBoxEditable="1"
          textBoxWidth="40" textBoxHeight="20" skewFactor="1"/>
  <LABEL name="velocityCrossFadeLabel" id="6d157756df82f292" memberName="m_velocityCrossFadeLabel1"
         virtualName="" explicitFocusOrder="0" pos="8 484 80 16" edTextCol="ff000000"
         edBkgCol="0" labelText="CROSSFADE" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="12"
         bold="1" italic="0" justification="33"/>
  <SLIDER name="velocityRangeUpperSlider" id="d1011c9ec02732d4" memberName="m_velocityRangeUpperSlider1"
          virtualName="MicroParameterSlider" explicitFocusOrder="0" pos="88 464 56 16"
          bkgcol="fff2f59b" thumbcol="ffc4c86d" min="0" max="127" int="1"
          style="LinearBar" textBoxPos="TextBoxLeft" textBoxEditable="1"
          textBoxWidth="40" textBoxHeight="20" skewFactor="1"/>
  <LABEL name="velocityRangeUpperLabel" id="f6c3e81cfe1c137f" memberName="m_velocityRangeUpperLabel1"
         virtualName="" explicitFocusOrder="0" pos="8 464 80 16" edTextCol="ff000000"
         edBkgCol="0" labelText="UPPER" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="12"
         bold="1" italic="0" justification="33"/>
  <LABEL name="velocityRangeLowerLabel" id="30b42c7655a52ba3" memberName="m_velocityRangeLowerLabel1"
         virtualName="" explicitFocusOrder="0" pos="8 444 80 16" edTextCol="ff000000"
         edBkgCol="0" labelText="LOWER" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="12"
         bold="1" italic="0" justification="33"/>
  <SLIDER name="velocityRangeLowerSlider" id="dc9b54da0aa19aa6" memberName="m_velocityRangeLowerSlider1"
          virtualName="MicroParameterSlider" explicitFocusOrder="0" pos="88 444 56 16"
          bkgcol="fff2f59b" thumbcol="ffc4c86d" min="0" max="127" int="1"
          style="LinearBar" textBoxPos="TextBoxLeft" textBoxEditable="1"
          textBoxWidth="40" textBoxHeight="20" skewFactor="1"/>
  <LABEL name="keyRangeLowerLabel" id="593652f30bc80793" memberName="m_keyRangeLowerLabel1"
         virtualName="" explicitFocusOrder="0" pos="8 352 104 16" edTextCol="ff000000"
         edBkgCol="0" labelText="LOWER" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="12"
         bold="1" italic="0" justification="36"/>
  <SLIDER name="keyRangeLowerSlider" id="b9d1900a1c3c44f7" memberName="m_keyRangeLowerSlider1"
          virtualName="MicroParameterSlider" explicitFocusOrder="0" pos="32 372 56 16"
          bkgcol="fff2f59b" thumbcol="ffc4c86d" min="0" max="127" int="1"
          style="LinearBar" textBoxPos="TextBoxLeft" textBoxEditable="1"
          textBoxWidth="40" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="keyRangeUpperSlider" id="b55b7c90bb48008" memberName="m_keyRangeUpperSlider1"
          virtualName="MicroParameterSlider" explicitFocusOrder="0" pos="140 372 56 16"
          bkgcol="fff2f59b" thumbcol="ffc4c86d" min="0" max="127" int="1"
          style="LinearBar" textBoxPos="TextBoxLeft" textBoxEditable="1"
          textBoxWidth="40" textBoxHeight="20" skewFactor="1"/>
  <LABEL name="keyRangeUpperLabel" id="c3f6bf625bb9b9af" memberName="m_keyRangeUpperLabel1"
         virtualName="" explicitFocusOrder="0" pos="116 352 104 16" edTextCol="ff000000"
         edBkgCol="0" labelText="UPPER" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="12"
         bold="1" italic="0" justification="36"/>
  <SLIDER name="biasLevelSlider" id="2155aedfd6600e68" memberName="m_biasLevelSlider1"
          virtualName="MicroParameterSlider" explicitFocusOrder="0" pos="88 616 56 16"
          bkgcol="fff2f59b" thumbcol="ffc4c86d" min="0" max="127" int="1"
          style="LinearBar" textBoxPos="TextBoxLeft" textBoxEditable="1"
          textBoxWidth="40" textBoxHeight="20" skewFactor="1"/>
  <LABEL name="biasLevelLabel" id="84d15ac9de51e64" memberName="m_biasLevelLabel1"
         virtualName="" explicitFocusOrder="0" pos="12 616 76 16" edTextCol="ff000000"
         edBkgCol="0" labelText="BIAS LEVEL" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="12"
         bold="1" italic="0" justification="33"/>
  <LABEL name="biasPointLabel" id="c08b79261e9bfd0a" memberName="m_biasPointLabel1"
         virtualName="" explicitFocusOrder="0" pos="12 596 76 16" edTextCol="ff000000"
         edBkgCol="0" labelText="BIAS POINT" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="12"
         bold="1" italic="0" justification="33"/>
  <SLIDER name="biasPointSlider" id="4ef39c9a6ee52b73" memberName="m_biasPointSlider1"
          virtualName="MicroParameterSlider" explicitFocusOrder="0" pos="88 596 56 16"
          bkgcol="fff2f59b" thumbcol="ffc4c86d" min="0" max="127" int="1"
          style="LinearBar" textBoxPos="TextBoxLeft" textBoxEditable="1"
          textBoxWidth="40" textBoxHeight="20" skewFactor="1"/>
  <COMBOBOX name="biasDirectionComboBox" id="e8c10ecedfc6fd9e" memberName="m_biasDirectionComboBox1"
            virtualName="ParameterComboBox" explicitFocusOrder="0" pos="88 574 80 17"
            editable="0" layout="33" items="" textWhenNonSelected="" textWhenNoItems="(no choices)"/>
  <LABEL name="biasDirectionLabel" id="c5b879d91f81a00d" memberName="m_biasDirectionLabel1"
         virtualName="" explicitFocusOrder="0" pos="12 576 76 16" edTextCol="ff000000"
         edBkgCol="0" labelText="DIRECTION" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="12"
         bold="1" italic="0" justification="33"/>
  <LABEL name="toneLevelLabel" id="de87c05fd221e249" memberName="m_toneLevelLabel1"
         virtualName="" explicitFocusOrder="0" pos="88 536 108 16" edTextCol="ff000000"
         edBkgCol="0" labelText="TONE LEVEL" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="12"
         bold="1" italic="0" justification="34"/>
  <SLIDER name="toneLevelSlider" id="4e958f885c747844" memberName="m_toneLevelSlider1"
          virtualName="MixPartLevelFader" explicitFocusOrder="0" pos="192 532 26 120"
          min="0" max="127" int="1" style="LinearVertical" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="32" textBoxHeight="16" skewFactor="1"/>
  <JUCERCOMP name="keyRangeGrp2" id="e5ea5b0c13a0c16b" memberName="m_keyRangeGrp2"
             virtualName="" explicitFocusOrder="0" pos="228 332 220 64" sourceFile="../GroupWidgets/PanelGroupTransp.cpp"
             constructorParams="&quot;keyRangeGrp2&quot;, &quot;KEY RANGE TONE 2&quot;"/>
  <JUCERCOMP name="keyRangeGrp3" id="271dfdf1d6bc40f2" memberName="m_keyRangeGrp3"
             virtualName="" explicitFocusOrder="0" pos="456 332 220 64" sourceFile="../GroupWidgets/PanelGroupTransp.cpp"
             constructorParams="&quot;keyRangeGrp3&quot;, &quot;KEY RANGE TONE 3&quot;"/>
  <JUCERCOMP name="keyRangeGrp4" id="37b64cd18408e652" memberName="m_keyRangeGrp4"
             virtualName="" explicitFocusOrder="0" pos="680 332 220 64" sourceFile="../GroupWidgets/PanelGroupTransp.cpp"
             constructorParams="&quot;keyRangeGrp4&quot;, &quot;KEY RANGE TONE 4&quot;"/>
  <JUCERCOMP name="ampBiasGrp" id="92d20cb197650cc3" memberName="m_ampBiasGrp2"
             virtualName="" explicitFocusOrder="0" pos="228 516 220 144" sourceFile="../GroupWidgets/PanelGroupTransp.cpp"
             constructorParams="&quot;ampBiasGrp&quot;, &quot;AMP BIAS TONE 1&quot;"/>
  <JUCERCOMP name="veloRangeGrp" id="a42750c31dbebda7" memberName="m_veloRangeGrp2"
             virtualName="" explicitFocusOrder="0" pos="228 424 220 84" sourceFile="../GroupWidgets/PanelGroupTransp.cpp"
             constructorParams="&quot;veloRangeGrp&quot;, &quot;VELOCITY RANGE TONE 1&quot;"/>
  <SLIDER name="velocityCrossFadeSlider" id="b4c650cc12529066" memberName="m_velocityCrossFadeSlider2"
          virtualName="MicroParameterSlider" explicitFocusOrder="0" pos="312 484 56 16"
          bkgcol="fff2f59b" thumbcol="ffc4c86d" min="0" max="127" int="1"
          style="LinearBar" textBoxPos="TextBoxLeft" textBoxEditable="1"
          textBoxWidth="40" textBoxHeight="20" skewFactor="1"/>
  <LABEL name="velocityCrossFadeLabel" id="bdb7f4cde6f68040" memberName="m_velocityCrossFadeLabel2"
         virtualName="" explicitFocusOrder="0" pos="232 484 80 16" edTextCol="ff000000"
         edBkgCol="0" labelText="CROSSFADE" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="12"
         bold="1" italic="0" justification="33"/>
  <SLIDER name="velocityRangeUpperSlider" id="bd71327eeab62136" memberName="m_velocityRangeUpperSlider2"
          virtualName="MicroParameterSlider" explicitFocusOrder="0" pos="312 464 56 16"
          bkgcol="fff2f59b" thumbcol="ffc4c86d" min="0" max="127" int="1"
          style="LinearBar" textBoxPos="TextBoxLeft" textBoxEditable="1"
          textBoxWidth="40" textBoxHeight="20" skewFactor="1"/>
  <LABEL name="velocityRangeUpperLabel" id="afd3758ad98bdbb1" memberName="m_velocityRangeUpperLabel2"
         virtualName="" explicitFocusOrder="0" pos="232 464 80 16" edTextCol="ff000000"
         edBkgCol="0" labelText="UPPER" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="12"
         bold="1" italic="0" justification="33"/>
  <LABEL name="velocityRangeLowerLabel" id="d97d724e7b2ad1fd" memberName="m_velocityRangeLowerLabel2"
         virtualName="" explicitFocusOrder="0" pos="232 444 80 16" edTextCol="ff000000"
         edBkgCol="0" labelText="LOWER" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="12"
         bold="1" italic="0" justification="33"/>
  <SLIDER name="velocityRangeLowerSlider" id="1e6946c42a50afca" memberName="m_velocityRangeLowerSlider2"
          virtualName="MicroParameterSlider" explicitFocusOrder="0" pos="312 444 56 16"
          bkgcol="fff2f59b" thumbcol="ffc4c86d" min="0" max="127" int="1"
          style="LinearBar" textBoxPos="TextBoxLeft" textBoxEditable="1"
          textBoxWidth="40" textBoxHeight="20" skewFactor="1"/>
  <LABEL name="keyRangeLowerLabel" id="80acf0f1f3dafb09" memberName="m_keyRangeLowerLabel2"
         virtualName="" explicitFocusOrder="0" pos="232 352 104 16" edTextCol="ff000000"
         edBkgCol="0" labelText="LOWER" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="12"
         bold="1" italic="0" justification="36"/>
  <SLIDER name="keyRangeLowerSlider" id="d4073480dbf9c2a4" memberName="m_keyRangeLowerSlider2"
          virtualName="MicroParameterSlider" explicitFocusOrder="0" pos="256 372 56 16"
          bkgcol="fff2f59b" thumbcol="ffc4c86d" min="0" max="127" int="1"
          style="LinearBar" textBoxPos="TextBoxLeft" textBoxEditable="1"
          textBoxWidth="40" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="keyRangeUpperSlider" id="3bfe058181f86ed8" memberName="m_keyRangeUpperSlider2"
          virtualName="MicroParameterSlider" explicitFocusOrder="0" pos="364 372 56 16"
          bkgcol="fff2f59b" thumbcol="ffc4c86d" min="0" max="127" int="1"
          style="LinearBar" textBoxPos="TextBoxLeft" textBoxEditable="1"
          textBoxWidth="40" textBoxHeight="20" skewFactor="1"/>
  <LABEL name="keyRangeUpperLabel" id="ec3f84600ecad03d" memberName="m_keyRangeUpperLabel2"
         virtualName="" explicitFocusOrder="0" pos="340 352 104 16" edTextCol="ff000000"
         edBkgCol="0" labelText="UPPER" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="12"
         bold="1" italic="0" justification="36"/>
  <SLIDER name="biasLevelSlider" id="dc5d17839d6aa5ca" memberName="m_biasLevelSlider2"
          virtualName="MicroParameterSlider" explicitFocusOrder="0" pos="312 616 56 16"
          bkgcol="fff2f59b" thumbcol="ffc4c86d" min="0" max="127" int="1"
          style="LinearBar" textBoxPos="TextBoxLeft" textBoxEditable="1"
          textBoxWidth="40" textBoxHeight="20" skewFactor="1"/>
  <LABEL name="biasLevelLabel" id="c40549479e3b7f47" memberName="m_biasLevelLabel2"
         virtualName="" explicitFocusOrder="0" pos="236 616 76 16" edTextCol="ff000000"
         edBkgCol="0" labelText="BIAS LEVEL" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="12"
         bold="1" italic="0" justification="33"/>
  <LABEL name="biasPointLabel" id="5947552502877117" memberName="m_biasPointLabel2"
         virtualName="" explicitFocusOrder="0" pos="236 596 76 16" edTextCol="ff000000"
         edBkgCol="0" labelText="BIAS POINT" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="12"
         bold="1" italic="0" justification="33"/>
  <SLIDER name="biasPointSlider" id="cf07cd4270364f3c" memberName="m_biasPointSlider2"
          virtualName="MicroParameterSlider" explicitFocusOrder="0" pos="312 596 56 16"
          bkgcol="fff2f59b" thumbcol="ffc4c86d" min="0" max="127" int="1"
          style="LinearBar" textBoxPos="TextBoxLeft" textBoxEditable="1"
          textBoxWidth="40" textBoxHeight="20" skewFactor="1"/>
  <COMBOBOX name="biasDirectionComboBox" id="eaec09c7ffaf6902" memberName="m_biasDirectionComboBox2"
            virtualName="ParameterComboBox" explicitFocusOrder="0" pos="312 575 80 17"
            editable="0" layout="33" items="" textWhenNonSelected="" textWhenNoItems="(no choices)"/>
  <LABEL name="biasDirectionLabel" id="de4035a54a0fd3b6" memberName="m_biasDirectionLabel2"
         virtualName="" explicitFocusOrder="0" pos="236 576 76 16" edTextCol="ff000000"
         edBkgCol="0" labelText="DIRECTION" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="12"
         bold="1" italic="0" justification="33"/>
  <LABEL name="toneLevelLabel" id="602e58bcc6868a4e" memberName="m_toneLevelLabel2"
         virtualName="" explicitFocusOrder="0" pos="312 536 108 16" edTextCol="ff000000"
         edBkgCol="0" labelText="TONE LEVEL" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="12"
         bold="1" italic="0" justification="34"/>
  <SLIDER name="toneLevelSlider" id="5172c574f265d0fc" memberName="m_toneLevelSlider2"
          virtualName="MixPartLevelFader" explicitFocusOrder="0" pos="416 532 26 120"
          min="0" max="127" int="1" style="LinearVertical" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="32" textBoxHeight="16" skewFactor="1"/>
  <JUCERCOMP name="ampBiasGrp" id="c317764f9756bd64" memberName="m_ampBiasGrp3"
             virtualName="" explicitFocusOrder="0" pos="455 516 220 144" sourceFile="../GroupWidgets/PanelGroupTransp.cpp"
             constructorParams="&quot;ampBiasGrp&quot;, &quot;AMP BIAS TONE 1&quot;"/>
  <JUCERCOMP name="veloRangeGrp" id="a6b392fdfa792ba3" memberName="m_veloRangeGrp3"
             virtualName="" explicitFocusOrder="0" pos="455 424 220 84" sourceFile="../GroupWidgets/PanelGroupTransp.cpp"
             constructorParams="&quot;veloRangeGrp&quot;, &quot;VELOCITY RANGE TONE 1&quot;"/>
  <SLIDER name="velocityCrossFadeSlider" id="6d90751e71c2e708" memberName="m_velocityCrossFadeSlider3"
          virtualName="MicroParameterSlider" explicitFocusOrder="0" pos="539 484 56 16"
          bkgcol="fff2f59b" thumbcol="ffc4c86d" min="0" max="127" int="1"
          style="LinearBar" textBoxPos="TextBoxLeft" textBoxEditable="1"
          textBoxWidth="40" textBoxHeight="20" skewFactor="1"/>
  <LABEL name="velocityCrossFadeLabel" id="cdd7a9c7b27f6435" memberName="m_velocityCrossFadeLabel3"
         virtualName="" explicitFocusOrder="0" pos="459 484 80 16" edTextCol="ff000000"
         edBkgCol="0" labelText="CROSSFADE" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="12"
         bold="1" italic="0" justification="33"/>
  <SLIDER name="velocityRangeUpperSlider" id="6e21c6f2b7d9b209" memberName="m_velocityRangeUpperSlider3"
          virtualName="MicroParameterSlider" explicitFocusOrder="0" pos="539 464 56 16"
          bkgcol="fff2f59b" thumbcol="ffc4c86d" min="0" max="127" int="1"
          style="LinearBar" textBoxPos="TextBoxLeft" textBoxEditable="1"
          textBoxWidth="40" textBoxHeight="20" skewFactor="1"/>
  <LABEL name="velocityRangeUpperLabel" id="948df792e3bebd74" memberName="m_velocityRangeUpperLabel3"
         virtualName="" explicitFocusOrder="0" pos="459 464 80 16" edTextCol="ff000000"
         edBkgCol="0" labelText="UPPER" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="12"
         bold="1" italic="0" justification="33"/>
  <LABEL name="velocityRangeLowerLabel" id="4149d2531f57d11e" memberName="m_velocityRangeLowerLabel3"
         virtualName="" explicitFocusOrder="0" pos="459 444 80 16" edTextCol="ff000000"
         edBkgCol="0" labelText="LOWER" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="12"
         bold="1" italic="0" justification="33"/>
  <SLIDER name="velocityRangeLowerSlider" id="d187c0cb85f14e8f" memberName="m_velocityRangeLowerSlider3"
          virtualName="MicroParameterSlider" explicitFocusOrder="0" pos="539 444 56 16"
          bkgcol="fff2f59b" thumbcol="ffc4c86d" min="0" max="127" int="1"
          style="LinearBar" textBoxPos="TextBoxLeft" textBoxEditable="1"
          textBoxWidth="40" textBoxHeight="20" skewFactor="1"/>
  <LABEL name="keyRangeLowerLabel" id="2ad36252266430e3" memberName="m_keyRangeLowerLabel3"
         virtualName="" explicitFocusOrder="0" pos="459 352 104 16" edTextCol="ff000000"
         edBkgCol="0" labelText="LOWER" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="12"
         bold="1" italic="0" justification="36"/>
  <SLIDER name="keyRangeLowerSlider" id="11266ddfd4e3bc53" memberName="m_keyRangeLowerSlider3"
          virtualName="MicroParameterSlider" explicitFocusOrder="0" pos="484 372 56 16"
          bkgcol="fff2f59b" thumbcol="ffc4c86d" min="0" max="127" int="1"
          style="LinearBar" textBoxPos="TextBoxLeft" textBoxEditable="1"
          textBoxWidth="40" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="keyRangeUpperSlider" id="824808993381e320" memberName="m_keyRangeUpperSlider3"
          virtualName="MicroParameterSlider" explicitFocusOrder="0" pos="592 372 56 16"
          bkgcol="fff2f59b" thumbcol="ffc4c86d" min="0" max="127" int="1"
          style="LinearBar" textBoxPos="TextBoxLeft" textBoxEditable="1"
          textBoxWidth="40" textBoxHeight="20" skewFactor="1"/>
  <LABEL name="keyRangeUpperLabel" id="5ba4e2ffb599af9c" memberName="m_keyRangeUpperLabel3"
         virtualName="" explicitFocusOrder="0" pos="568 352 104 16" edTextCol="ff000000"
         edBkgCol="0" labelText="UPPER" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="12"
         bold="1" italic="0" justification="36"/>
  <SLIDER name="biasLevelSlider" id="50d2c4d079a53c62" memberName="m_biasLevelSlider3"
          virtualName="MicroParameterSlider" explicitFocusOrder="0" pos="539 616 56 16"
          bkgcol="fff2f59b" thumbcol="ffc4c86d" min="0" max="127" int="1"
          style="LinearBar" textBoxPos="TextBoxLeft" textBoxEditable="1"
          textBoxWidth="40" textBoxHeight="20" skewFactor="1"/>
  <LABEL name="biasLevelLabel" id="e71810223d9ebf07" memberName="m_biasLevelLabel3"
         virtualName="" explicitFocusOrder="0" pos="463 616 76 16" edTextCol="ff000000"
         edBkgCol="0" labelText="BIAS LEVEL" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="12"
         bold="1" italic="0" justification="33"/>
  <LABEL name="biasPointLabel" id="2a9b3e42d504b6c6" memberName="m_biasPointLabel3"
         virtualName="" explicitFocusOrder="0" pos="463 596 76 16" edTextCol="ff000000"
         edBkgCol="0" labelText="BIAS POINT" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="12"
         bold="1" italic="0" justification="33"/>
  <SLIDER name="biasPointSlider" id="bb99fd508d0fbfec" memberName="m_biasPointSlider3"
          virtualName="MicroParameterSlider" explicitFocusOrder="0" pos="539 596 56 16"
          bkgcol="fff2f59b" thumbcol="ffc4c86d" min="0" max="127" int="1"
          style="LinearBar" textBoxPos="TextBoxLeft" textBoxEditable="1"
          textBoxWidth="40" textBoxHeight="20" skewFactor="1"/>
  <COMBOBOX name="biasDirectionComboBox" id="9c6873bf8194ae17" memberName="m_biasDirectionComboBox3"
            virtualName="ParameterComboBox" explicitFocusOrder="0" pos="539 574 80 17"
            editable="0" layout="33" items="" textWhenNonSelected="" textWhenNoItems="(no choices)"/>
  <LABEL name="biasDirectionLabel" id="4b62d71c1433b28b" memberName="m_biasDirectionLabel3"
         virtualName="" explicitFocusOrder="0" pos="463 576 76 16" edTextCol="ff000000"
         edBkgCol="0" labelText="DIRECTION" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="12"
         bold="1" italic="0" justification="33"/>
  <LABEL name="toneLevelLabel" id="9e405c3c37a491b" memberName="m_toneLevelLabel3"
         virtualName="" explicitFocusOrder="0" pos="539 536 108 16" edTextCol="ff000000"
         edBkgCol="0" labelText="TONE LEVEL" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="12"
         bold="1" italic="0" justification="34"/>
  <SLIDER name="toneLevelSlider" id="5ac7bf71b73abd84" memberName="m_toneLevelSlider3"
          virtualName="MixPartLevelFader" explicitFocusOrder="0" pos="643 532 26 120"
          min="0" max="127" int="1" style="LinearVertical" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="32" textBoxHeight="16" skewFactor="1"/>
  <JUCERCOMP name="ampBiasGrp" id="f919f57c347b3de" memberName="m_ampBiasGrp4"
             virtualName="" explicitFocusOrder="0" pos="680 516 220 144" sourceFile="../GroupWidgets/PanelGroupTransp.cpp"
             constructorParams="&quot;ampBiasGrp&quot;, &quot;AMP BIAS TONE 1&quot;"/>
  <JUCERCOMP name="veloRangeGrp" id="4b5aeceaa3a11bf0" memberName="m_veloRangeGrp4"
             virtualName="" explicitFocusOrder="0" pos="680 424 220 84" sourceFile="../GroupWidgets/PanelGroupTransp.cpp"
             constructorParams="&quot;veloRangeGrp&quot;, &quot;VELOCITY RANGE TONE 1&quot;"/>
  <SLIDER name="velocityCrossFadeSlider" id="64c206e1ebf2cf3b" memberName="m_velocityCrossFadeSlider4"
          virtualName="MicroParameterSlider" explicitFocusOrder="0" pos="764 484 56 16"
          bkgcol="fff2f59b" thumbcol="ffc4c86d" min="0" max="127" int="1"
          style="LinearBar" textBoxPos="TextBoxLeft" textBoxEditable="1"
          textBoxWidth="40" textBoxHeight="20" skewFactor="1"/>
  <LABEL name="velocityCrossFadeLabel" id="a95a2308d7fe3be" memberName="m_velocityCrossFadeLabel4"
         virtualName="" explicitFocusOrder="0" pos="684 484 80 16" edTextCol="ff000000"
         edBkgCol="0" labelText="CROSSFADE" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="12"
         bold="1" italic="0" justification="33"/>
  <SLIDER name="velocityRangeUpperSlider" id="db90cdf85e266596" memberName="m_velocityRangeUpperSlider4"
          virtualName="MicroParameterSlider" explicitFocusOrder="0" pos="764 464 56 16"
          bkgcol="fff2f59b" thumbcol="ffc4c86d" min="0" max="127" int="1"
          style="LinearBar" textBoxPos="TextBoxLeft" textBoxEditable="1"
          textBoxWidth="40" textBoxHeight="20" skewFactor="1"/>
  <LABEL name="velocityRangeUpperLabel" id="4210fd6a14949c13" memberName="m_velocityRangeUpperLabel4"
         virtualName="" explicitFocusOrder="0" pos="684 464 80 16" edTextCol="ff000000"
         edBkgCol="0" labelText="UPPER" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="12"
         bold="1" italic="0" justification="33"/>
  <LABEL name="velocityRangeLowerLabel" id="7498c93d72f4968c" memberName="m_velocityRangeLowerLabel4"
         virtualName="" explicitFocusOrder="0" pos="684 444 80 16" edTextCol="ff000000"
         edBkgCol="0" labelText="LOWER" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="12"
         bold="1" italic="0" justification="33"/>
  <SLIDER name="velocityRangeLowerSlider" id="79be1292535430d" memberName="m_velocityRangeLowerSlider4"
          virtualName="MicroParameterSlider" explicitFocusOrder="0" pos="764 444 56 16"
          bkgcol="fff2f59b" thumbcol="ffc4c86d" min="0" max="127" int="1"
          style="LinearBar" textBoxPos="TextBoxLeft" textBoxEditable="1"
          textBoxWidth="40" textBoxHeight="20" skewFactor="1"/>
  <LABEL name="keyRangeLowerLabel" id="49900b1de6335f5a" memberName="m_keyRangeLowerLabel4"
         virtualName="" explicitFocusOrder="0" pos="684 352 104 16" edTextCol="ff000000"
         edBkgCol="0" labelText="LOWER" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="12"
         bold="1" italic="0" justification="36"/>
  <SLIDER name="keyRangeLowerSlider" id="de39aa02bc1a9c1d" memberName="m_keyRangeLowerSlider4"
          virtualName="MicroParameterSlider" explicitFocusOrder="0" pos="708 372 56 16"
          bkgcol="fff2f59b" thumbcol="ffc4c86d" min="0" max="127" int="1"
          style="LinearBar" textBoxPos="TextBoxLeft" textBoxEditable="1"
          textBoxWidth="40" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="keyRangeUpperSlider" id="a0edc46bea8c33f" memberName="m_keyRangeUpperSlider4"
          virtualName="MicroParameterSlider" explicitFocusOrder="0" pos="820 372 56 16"
          bkgcol="fff2f59b" thumbcol="ffc4c86d" min="0" max="127" int="1"
          style="LinearBar" textBoxPos="TextBoxLeft" textBoxEditable="1"
          textBoxWidth="40" textBoxHeight="20" skewFactor="1"/>
  <LABEL name="keyRangeUpperLabel" id="b52c62911423edb6" memberName="m_keyRangeUpperLabel4"
         virtualName="" explicitFocusOrder="0" pos="792 352 104 16" edTextCol="ff000000"
         edBkgCol="0" labelText="UPPER" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="12"
         bold="1" italic="0" justification="36"/>
  <SLIDER name="biasLevelSlider" id="4e4739466c3ca24f" memberName="m_biasLevelSlider4"
          virtualName="MicroParameterSlider" explicitFocusOrder="0" pos="764 616 56 16"
          bkgcol="fff2f59b" thumbcol="ffc4c86d" min="0" max="127" int="1"
          style="LinearBar" textBoxPos="TextBoxLeft" textBoxEditable="1"
          textBoxWidth="40" textBoxHeight="20" skewFactor="1"/>
  <LABEL name="biasLevelLabel" id="6d9fb3c09aac6640" memberName="m_biasLevelLabel4"
         virtualName="" explicitFocusOrder="0" pos="688 616 76 16" edTextCol="ff000000"
         edBkgCol="0" labelText="BIAS LEVEL" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="12"
         bold="1" italic="0" justification="33"/>
  <LABEL name="biasPointLabel" id="1040672c070a986" memberName="m_biasPointLabel4"
         virtualName="" explicitFocusOrder="0" pos="688 596 76 16" edTextCol="ff000000"
         edBkgCol="0" labelText="BIAS POINT" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="12"
         bold="1" italic="0" justification="33"/>
  <SLIDER name="biasPointSlider" id="11dc15499f9d5c52" memberName="m_biasPointSlider4"
          virtualName="MicroParameterSlider" explicitFocusOrder="0" pos="764 596 56 16"
          bkgcol="fff2f59b" thumbcol="ffc4c86d" min="0" max="127" int="1"
          style="LinearBar" textBoxPos="TextBoxLeft" textBoxEditable="1"
          textBoxWidth="40" textBoxHeight="20" skewFactor="1"/>
  <COMBOBOX name="biasDirectionComboBox" id="50d1e087fdeb01f" memberName="m_biasDirectionComboBox4"
            virtualName="ParameterComboBox" explicitFocusOrder="0" pos="764 574 80 17"
            editable="0" layout="33" items="" textWhenNonSelected="" textWhenNoItems="(no choices)"/>
  <LABEL name="biasDirectionLabel" id="315e02780167de21" memberName="m_biasDirectionLabel4"
         virtualName="" explicitFocusOrder="0" pos="688 576 76 16" edTextCol="ff000000"
         edBkgCol="0" labelText="DIRECTION" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="12"
         bold="1" italic="0" justification="33"/>
  <LABEL name="toneLevelLabel" id="7c3b9c9706af1626" memberName="m_toneLevelLabel4"
         virtualName="" explicitFocusOrder="0" pos="764 536 108 16" edTextCol="ff000000"
         edBkgCol="0" labelText="TONE LEVEL" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="12"
         bold="1" italic="0" justification="34"/>
  <SLIDER name="toneLevelSlider" id="c8a53735c8c34432" memberName="m_toneLevelSlider4"
          virtualName="MixPartLevelFader" explicitFocusOrder="0" pos="868 532 26 120"
          min="0" max="127" int="1" style="LinearVertical" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="32" textBoxHeight="16" skewFactor="1"/>
  <IMAGEBUTTON name="new button" id="ee2985b65fb2184c" memberName="imageButton3"
               virtualName="" explicitFocusOrder="0" pos="3 1 16 16" buttonText=""
               connectedEdges="0" needsCallback="1" radioGroupId="0" keepProportions="1"
               resourceNormal="tonemixtable_png" opacityNormal="1" colourNormal="4340454a"
               resourceOver="" opacityOver="1" colourOver="4340454a" resourceDown=""
               opacityDown="1" colourDown="4340454a"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif

//==============================================================================
// Binary resources - be careful not to edit any of these sections!

// JUCER_RESOURCE: tonemixtable_png, 223, "../../../Resources/PatchEditSectionIcons/tonemixtable.png"
static const unsigned char resource_ToneMixTable_tonemixtable_png[] = { 137,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,0,16,0,0,0,16,8,6,0,0,0,31,243,255,97,0,0,0,1,115,82,71,66,0,174,206,28,233,0,
0,0,6,98,75,71,68,0,255,0,255,0,255,160,189,167,147,0,0,0,9,112,72,89,115,0,0,11,19,0,0,11,19,1,0,154,156,24,0,0,0,7,116,73,77,69,7,222,12,10,20,18,45,104,169,253,144,0,0,0,95,73,68,65,84,56,203,181,147,
81,14,192,32,8,67,121,187,255,157,235,143,75,116,81,8,144,241,41,150,66,11,216,12,73,178,68,0,88,21,188,97,42,224,181,8,183,2,91,139,94,167,183,2,223,247,211,63,73,114,71,120,115,46,73,164,65,68,240,132,
34,1,46,73,87,131,255,92,104,239,65,122,37,79,150,69,185,208,133,252,97,20,48,116,207,121,0,77,35,159,126,216,242,55,52,0,0,0,0,73,69,78,68,174,66,96,130,0,0};

const char* ToneMixTable::tonemixtable_png = (const char*) resource_ToneMixTable_tonemixtable_png;
const int ToneMixTable::tonemixtable_pngSize = 223;


//[EndFile] You can add extra defines here...
//[/EndFile]
