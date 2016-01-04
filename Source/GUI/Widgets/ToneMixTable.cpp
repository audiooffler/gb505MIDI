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
//[/Headers]

#include "ToneMixTable.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
ToneMixTable::ToneMixTable ()
{
    addAndMakeVisible (m_toneMixTableBoard = new ToneMixTableBoard ("toneMixTableBoard"));
    addAndMakeVisible (m_velocityRangeSwitch = new ToggleButton ("velocityRangeSwitch"));
    m_velocityRangeSwitch->setButtonText (TRANS("Velocity Ranges On"));
    m_velocityRangeSwitch->addListener (this);

    addAndMakeVisible (m_velocityCrossFadeLabel = new Label ("velocityCrossFadeLabel",
                                                             TRANS("Velocity Crossfade:")));
    m_velocityCrossFadeLabel->setFont (Font (15.00f, Font::plain));
    m_velocityCrossFadeLabel->setJustificationType (Justification::centredLeft);
    m_velocityCrossFadeLabel->setEditable (false, false, false);
    m_velocityCrossFadeLabel->setColour (TextEditor::textColourId, Colours::black);
    m_velocityCrossFadeLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_velocityCrossFade1 = new Slider ("velocityCrossFade1"));
    m_velocityCrossFade1->setRange (0, 127, 1);
    m_velocityCrossFade1->setSliderStyle (Slider::LinearHorizontal);
    m_velocityCrossFade1->setTextBoxStyle (Slider::TextBoxRight, false, 50, 20);
    m_velocityCrossFade1->addListener (this);

    addAndMakeVisible (m_tone1Label = new Label ("tone1Label",
                                                 TRANS("Tone 1")));
    m_tone1Label->setFont (Font (15.00f, Font::plain));
    m_tone1Label->setJustificationType (Justification::centred);
    m_tone1Label->setEditable (false, false, false);
    m_tone1Label->setColour (TextEditor::textColourId, Colours::black);
    m_tone1Label->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_velocityCrossFade2 = new Slider ("velocityCrossFade2"));
    m_velocityCrossFade2->setRange (0, 127, 1);
    m_velocityCrossFade2->setSliderStyle (Slider::LinearHorizontal);
    m_velocityCrossFade2->setTextBoxStyle (Slider::TextBoxRight, false, 50, 20);
    m_velocityCrossFade2->addListener (this);

    addAndMakeVisible (m_tone2Label = new Label ("tone2Label",
                                                 TRANS("Tone 2")));
    m_tone2Label->setFont (Font (15.00f, Font::plain));
    m_tone2Label->setJustificationType (Justification::centred);
    m_tone2Label->setEditable (false, false, false);
    m_tone2Label->setColour (TextEditor::textColourId, Colours::black);
    m_tone2Label->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_tone3Label = new Label ("tone3Label",
                                                 TRANS("Tone 3")));
    m_tone3Label->setFont (Font (15.00f, Font::plain));
    m_tone3Label->setJustificationType (Justification::centred);
    m_tone3Label->setEditable (false, false, false);
    m_tone3Label->setColour (TextEditor::textColourId, Colours::black);
    m_tone3Label->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_tone4Label = new Label ("tone4Label",
                                                 TRANS("Tone 4")));
    m_tone4Label->setFont (Font (15.00f, Font::plain));
    m_tone4Label->setJustificationType (Justification::centred);
    m_tone4Label->setEditable (false, false, false);
    m_tone4Label->setColour (TextEditor::textColourId, Colours::black);
    m_tone4Label->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_velocityCrossFade3 = new Slider ("velocityCrossFade3"));
    m_velocityCrossFade3->setRange (0, 127, 1);
    m_velocityCrossFade3->setSliderStyle (Slider::LinearHorizontal);
    m_velocityCrossFade3->setTextBoxStyle (Slider::TextBoxRight, false, 50, 20);
    m_velocityCrossFade3->addListener (this);

    addAndMakeVisible (m_velocityCrossFade4 = new Slider ("velocityCrossFade4"));
    m_velocityCrossFade4->setRange (0, 127, 1);
    m_velocityCrossFade4->setSliderStyle (Slider::LinearHorizontal);
    m_velocityCrossFade4->setTextBoxStyle (Slider::TextBoxRight, false, 50, 20);
    m_velocityCrossFade4->addListener (this);

    addAndMakeVisible (m_velocityRangeUpperLabel = new Label ("velocityRangeUpperLabel",
                                                              TRANS("Velocity Range Upper:")));
    m_velocityRangeUpperLabel->setFont (Font (15.00f, Font::plain));
    m_velocityRangeUpperLabel->setJustificationType (Justification::centredLeft);
    m_velocityRangeUpperLabel->setEditable (false, false, false);
    m_velocityRangeUpperLabel->setColour (TextEditor::textColourId, Colours::black);
    m_velocityRangeUpperLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_velocityRangeUpper1 = new Slider ("velocityRangeUpper1"));
    m_velocityRangeUpper1->setRange (0, 127, 1);
    m_velocityRangeUpper1->setSliderStyle (Slider::LinearHorizontal);
    m_velocityRangeUpper1->setTextBoxStyle (Slider::TextBoxRight, false, 50, 20);
    m_velocityRangeUpper1->addListener (this);

    addAndMakeVisible (m_velocityRangeUpper2 = new Slider ("velocityRangeUpper2"));
    m_velocityRangeUpper2->setRange (0, 127, 1);
    m_velocityRangeUpper2->setSliderStyle (Slider::LinearHorizontal);
    m_velocityRangeUpper2->setTextBoxStyle (Slider::TextBoxRight, false, 50, 20);
    m_velocityRangeUpper2->addListener (this);

    addAndMakeVisible (m_velocityRangeUpper3 = new Slider ("velocityRangeUpper3"));
    m_velocityRangeUpper3->setRange (0, 127, 1);
    m_velocityRangeUpper3->setSliderStyle (Slider::LinearHorizontal);
    m_velocityRangeUpper3->setTextBoxStyle (Slider::TextBoxRight, false, 50, 20);
    m_velocityRangeUpper3->addListener (this);

    addAndMakeVisible (m_velocityRangeUpper4 = new Slider ("velocityRangeUpper4"));
    m_velocityRangeUpper4->setRange (0, 127, 1);
    m_velocityRangeUpper4->setSliderStyle (Slider::LinearHorizontal);
    m_velocityRangeUpper4->setTextBoxStyle (Slider::TextBoxRight, false, 50, 20);
    m_velocityRangeUpper4->addListener (this);

    addAndMakeVisible (m_velocityRangeLowerLabel = new Label ("velocityRangeLowerLabel",
                                                              TRANS("Velocity Range Lower:")));
    m_velocityRangeLowerLabel->setFont (Font (15.00f, Font::plain));
    m_velocityRangeLowerLabel->setJustificationType (Justification::centredLeft);
    m_velocityRangeLowerLabel->setEditable (false, false, false);
    m_velocityRangeLowerLabel->setColour (TextEditor::textColourId, Colours::black);
    m_velocityRangeLowerLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_velocityRangeLower1 = new Slider ("velocityRangeLower1"));
    m_velocityRangeLower1->setRange (0, 127, 1);
    m_velocityRangeLower1->setSliderStyle (Slider::LinearHorizontal);
    m_velocityRangeLower1->setTextBoxStyle (Slider::TextBoxRight, false, 50, 20);
    m_velocityRangeLower1->addListener (this);

    addAndMakeVisible (m_velocityRangeLower2 = new Slider ("velocityRangeLower2"));
    m_velocityRangeLower2->setRange (0, 127, 1);
    m_velocityRangeLower2->setSliderStyle (Slider::LinearHorizontal);
    m_velocityRangeLower2->setTextBoxStyle (Slider::TextBoxRight, false, 50, 20);
    m_velocityRangeLower2->addListener (this);

    addAndMakeVisible (m_velocityRangeLower3 = new Slider ("velocityRangeLower3"));
    m_velocityRangeLower3->setRange (0, 127, 1);
    m_velocityRangeLower3->setSliderStyle (Slider::LinearHorizontal);
    m_velocityRangeLower3->setTextBoxStyle (Slider::TextBoxRight, false, 50, 20);
    m_velocityRangeLower3->addListener (this);

    addAndMakeVisible (m_velocityRangeLower4 = new Slider ("velocityRangeLower4"));
    m_velocityRangeLower4->setRange (0, 127, 1);
    m_velocityRangeLower4->setSliderStyle (Slider::LinearHorizontal);
    m_velocityRangeLower4->setTextBoxStyle (Slider::TextBoxRight, false, 50, 20);
    m_velocityRangeLower4->addListener (this);

    addAndMakeVisible (m_keyRangeLowerLabel = new Label ("keyRangeLowerLabel",
                                                         TRANS("Key Range Lower:")));
    m_keyRangeLowerLabel->setFont (Font (15.00f, Font::plain));
    m_keyRangeLowerLabel->setJustificationType (Justification::centredLeft);
    m_keyRangeLowerLabel->setEditable (false, false, false);
    m_keyRangeLowerLabel->setColour (TextEditor::textColourId, Colours::black);
    m_keyRangeLowerLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_keyRangeLower1 = new Slider ("keyRangeLower1"));
    m_keyRangeLower1->setRange (0, 127, 1);
    m_keyRangeLower1->setSliderStyle (Slider::LinearHorizontal);
    m_keyRangeLower1->setTextBoxStyle (Slider::TextBoxRight, false, 50, 20);
    m_keyRangeLower1->addListener (this);

    addAndMakeVisible (m_keyRangeLower2 = new Slider ("keyRangeLower2"));
    m_keyRangeLower2->setRange (0, 127, 1);
    m_keyRangeLower2->setSliderStyle (Slider::LinearHorizontal);
    m_keyRangeLower2->setTextBoxStyle (Slider::TextBoxRight, false, 50, 20);
    m_keyRangeLower2->addListener (this);

    addAndMakeVisible (m_keyRangeLower3 = new Slider ("keyRangeLower3"));
    m_keyRangeLower3->setRange (0, 127, 1);
    m_keyRangeLower3->setSliderStyle (Slider::LinearHorizontal);
    m_keyRangeLower3->setTextBoxStyle (Slider::TextBoxRight, false, 50, 20);
    m_keyRangeLower3->addListener (this);

    addAndMakeVisible (m_keyRangeLower4 = new Slider ("keyRangeLower4"));
    m_keyRangeLower4->setRange (0, 127, 1);
    m_keyRangeLower4->setSliderStyle (Slider::LinearHorizontal);
    m_keyRangeLower4->setTextBoxStyle (Slider::TextBoxRight, false, 50, 20);
    m_keyRangeLower4->addListener (this);

    addAndMakeVisible (m_keyRangeUpperLabel = new Label ("keyRangeUpperLabel",
                                                         TRANS("Key Range Upper:")));
    m_keyRangeUpperLabel->setFont (Font (15.00f, Font::plain));
    m_keyRangeUpperLabel->setJustificationType (Justification::centredLeft);
    m_keyRangeUpperLabel->setEditable (false, false, false);
    m_keyRangeUpperLabel->setColour (TextEditor::textColourId, Colours::black);
    m_keyRangeUpperLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_keyRangeUpper1 = new Slider ("keyRangeUpper1"));
    m_keyRangeUpper1->setRange (0, 127, 1);
    m_keyRangeUpper1->setSliderStyle (Slider::LinearHorizontal);
    m_keyRangeUpper1->setTextBoxStyle (Slider::TextBoxRight, false, 50, 20);
    m_keyRangeUpper1->addListener (this);

    addAndMakeVisible (m_keyRangeUpper2 = new Slider ("keyRangeUpper2"));
    m_keyRangeUpper2->setRange (0, 127, 1);
    m_keyRangeUpper2->setSliderStyle (Slider::LinearHorizontal);
    m_keyRangeUpper2->setTextBoxStyle (Slider::TextBoxRight, false, 50, 20);
    m_keyRangeUpper2->addListener (this);

    addAndMakeVisible (m_keyRangeUpper3 = new Slider ("keyRangeUpper3"));
    m_keyRangeUpper3->setRange (0, 127, 1);
    m_keyRangeUpper3->setSliderStyle (Slider::LinearHorizontal);
    m_keyRangeUpper3->setTextBoxStyle (Slider::TextBoxRight, false, 50, 20);
    m_keyRangeUpper3->addListener (this);

    addAndMakeVisible (m_keyRangeUpper4 = new Slider ("keyRangeUpper4"));
    m_keyRangeUpper4->setRange (0, 127, 1);
    m_keyRangeUpper4->setSliderStyle (Slider::LinearHorizontal);
    m_keyRangeUpper4->setTextBoxStyle (Slider::TextBoxRight, false, 50, 20);
    m_keyRangeUpper4->addListener (this);

    addAndMakeVisible (m_biasDirectionLabel = new Label ("biasDirectionLabel",
                                                         TRANS("Bias Direction:")));
    m_biasDirectionLabel->setFont (Font (15.00f, Font::plain));
    m_biasDirectionLabel->setJustificationType (Justification::centredLeft);
    m_biasDirectionLabel->setEditable (false, false, false);
    m_biasDirectionLabel->setColour (TextEditor::textColourId, Colours::black);
    m_biasDirectionLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_biasDirection1 = new Slider ("biasDirection1"));
    m_biasDirection1->setRange (0, 3, 1);
    m_biasDirection1->setSliderStyle (Slider::LinearHorizontal);
    m_biasDirection1->setTextBoxStyle (Slider::TextBoxRight, false, 50, 20);
    m_biasDirection1->addListener (this);

    addAndMakeVisible (m_biasDirection2 = new Slider ("biasDirection2"));
    m_biasDirection2->setRange (0, 3, 1);
    m_biasDirection2->setSliderStyle (Slider::LinearHorizontal);
    m_biasDirection2->setTextBoxStyle (Slider::TextBoxRight, false, 50, 20);
    m_biasDirection2->addListener (this);

    addAndMakeVisible (m_biasDirection3 = new Slider ("biasDirection3"));
    m_biasDirection3->setRange (0, 3, 1);
    m_biasDirection3->setSliderStyle (Slider::LinearHorizontal);
    m_biasDirection3->setTextBoxStyle (Slider::TextBoxRight, false, 50, 20);
    m_biasDirection3->addListener (this);

    addAndMakeVisible (m_biasDirection4 = new Slider ("biasDirection4"));
    m_biasDirection4->setRange (0, 3, 1);
    m_biasDirection4->setSliderStyle (Slider::LinearHorizontal);
    m_biasDirection4->setTextBoxStyle (Slider::TextBoxRight, false, 50, 20);
    m_biasDirection4->addListener (this);

    addAndMakeVisible (m_toneLevelLabel = new Label ("toneLevelLabel",
                                                     TRANS("Tone Level:")));
    m_toneLevelLabel->setFont (Font (15.00f, Font::plain));
    m_toneLevelLabel->setJustificationType (Justification::centredLeft);
    m_toneLevelLabel->setEditable (false, false, false);
    m_toneLevelLabel->setColour (TextEditor::textColourId, Colours::black);
    m_toneLevelLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_toneLevel1 = new Slider ("toneLevel1"));
    m_toneLevel1->setRange (0, 127, 1);
    m_toneLevel1->setSliderStyle (Slider::LinearHorizontal);
    m_toneLevel1->setTextBoxStyle (Slider::TextBoxRight, false, 50, 20);
    m_toneLevel1->addListener (this);

    addAndMakeVisible (m_toneLevel2 = new Slider ("toneLevel2"));
    m_toneLevel2->setRange (0, 127, 1);
    m_toneLevel2->setSliderStyle (Slider::LinearHorizontal);
    m_toneLevel2->setTextBoxStyle (Slider::TextBoxRight, false, 50, 20);
    m_toneLevel2->addListener (this);

    addAndMakeVisible (m_toneLevel3 = new Slider ("toneLevel3"));
    m_toneLevel3->setRange (0, 127, 1);
    m_toneLevel3->setSliderStyle (Slider::LinearHorizontal);
    m_toneLevel3->setTextBoxStyle (Slider::TextBoxRight, false, 50, 20);
    m_toneLevel3->addListener (this);

    addAndMakeVisible (m_toneLevel4 = new Slider ("toneLevel4"));
    m_toneLevel4->setRange (0, 127, 1);
    m_toneLevel4->setSliderStyle (Slider::LinearHorizontal);
    m_toneLevel4->setTextBoxStyle (Slider::TextBoxRight, false, 50, 20);
    m_toneLevel4->addListener (this);

    addAndMakeVisible (m_biasPointLabel = new Label ("biasPointLabel",
                                                     TRANS("Bias Point:")));
    m_biasPointLabel->setFont (Font (15.00f, Font::plain));
    m_biasPointLabel->setJustificationType (Justification::centredLeft);
    m_biasPointLabel->setEditable (false, false, false);
    m_biasPointLabel->setColour (TextEditor::textColourId, Colours::black);
    m_biasPointLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_biasPoint1 = new Slider ("biasPoint1"));
    m_biasPoint1->setRange (0, 127, 1);
    m_biasPoint1->setSliderStyle (Slider::LinearHorizontal);
    m_biasPoint1->setTextBoxStyle (Slider::TextBoxRight, false, 50, 20);
    m_biasPoint1->addListener (this);

    addAndMakeVisible (m_biasPoint2 = new Slider ("biasPoint2"));
    m_biasPoint2->setRange (0, 127, 1);
    m_biasPoint2->setSliderStyle (Slider::LinearHorizontal);
    m_biasPoint2->setTextBoxStyle (Slider::TextBoxRight, false, 50, 20);
    m_biasPoint2->addListener (this);

    addAndMakeVisible (m_biasPoint3 = new Slider ("biasPoint3"));
    m_biasPoint3->setRange (0, 127, 1);
    m_biasPoint3->setSliderStyle (Slider::LinearHorizontal);
    m_biasPoint3->setTextBoxStyle (Slider::TextBoxRight, false, 50, 20);
    m_biasPoint3->addListener (this);

    addAndMakeVisible (m_biasPoint4 = new Slider ("biasPoint4"));
    m_biasPoint4->setRange (0, 127, 1);
    m_biasPoint4->setSliderStyle (Slider::LinearHorizontal);
    m_biasPoint4->setTextBoxStyle (Slider::TextBoxRight, false, 50, 20);
    m_biasPoint4->addListener (this);

    addAndMakeVisible (m_biasLevelLabel = new Label ("biasLevelLabel",
                                                     TRANS("Bias Level:")));
    m_biasLevelLabel->setFont (Font (15.00f, Font::plain));
    m_biasLevelLabel->setJustificationType (Justification::centredLeft);
    m_biasLevelLabel->setEditable (false, false, false);
    m_biasLevelLabel->setColour (TextEditor::textColourId, Colours::black);
    m_biasLevelLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_biasLevel1 = new Slider ("biasLevel1"));
    m_biasLevel1->setRange (0, 14, 1);
    m_biasLevel1->setSliderStyle (Slider::LinearHorizontal);
    m_biasLevel1->setTextBoxStyle (Slider::TextBoxRight, false, 50, 20);
    m_biasLevel1->addListener (this);

    addAndMakeVisible (m_biasLevel2 = new Slider ("biasLevel2"));
    m_biasLevel2->setRange (0, 14, 1);
    m_biasLevel2->setSliderStyle (Slider::LinearHorizontal);
    m_biasLevel2->setTextBoxStyle (Slider::TextBoxRight, false, 50, 20);
    m_biasLevel2->addListener (this);

    addAndMakeVisible (m_biasLevel3 = new Slider ("biasLevel3"));
    m_biasLevel3->setRange (0, 14, 1);
    m_biasLevel3->setSliderStyle (Slider::LinearHorizontal);
    m_biasLevel3->setTextBoxStyle (Slider::TextBoxRight, false, 50, 20);
    m_biasLevel3->addListener (this);

    addAndMakeVisible (m_biasLevel4 = new Slider ("biasLevel4"));
    m_biasLevel4->setRange (0, 14, 1);
    m_biasLevel4->setSliderStyle (Slider::LinearHorizontal);
    m_biasLevel4->setTextBoxStyle (Slider::TextBoxRight, false, 50, 20);
    m_biasLevel4->addListener (this);


    //[UserPreSize]
	if (ToneMixTableCanvas* canvas = m_toneMixTableBoard->getToneMixTableCanvasPtr())
	{
		canvas->getToneMixTableTone(ToneMixTableCanvas::Tone1)->addChangeListener(this);
		canvas->getToneMixTableTone(ToneMixTableCanvas::Tone2)->addChangeListener(this);
		canvas->getToneMixTableTone(ToneMixTableCanvas::Tone3)->addChangeListener(this);
		canvas->getToneMixTableTone(ToneMixTableCanvas::Tone4)->addChangeListener(this);
	}
    //[/UserPreSize]

    setSize (1024, 768);


    //[Constructor] You can add your own custom stuff here..
    //[/Constructor]
}

ToneMixTable::~ToneMixTable()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    m_toneMixTableBoard = nullptr;
    m_velocityRangeSwitch = nullptr;
    m_velocityCrossFadeLabel = nullptr;
    m_velocityCrossFade1 = nullptr;
    m_tone1Label = nullptr;
    m_velocityCrossFade2 = nullptr;
    m_tone2Label = nullptr;
    m_tone3Label = nullptr;
    m_tone4Label = nullptr;
    m_velocityCrossFade3 = nullptr;
    m_velocityCrossFade4 = nullptr;
    m_velocityRangeUpperLabel = nullptr;
    m_velocityRangeUpper1 = nullptr;
    m_velocityRangeUpper2 = nullptr;
    m_velocityRangeUpper3 = nullptr;
    m_velocityRangeUpper4 = nullptr;
    m_velocityRangeLowerLabel = nullptr;
    m_velocityRangeLower1 = nullptr;
    m_velocityRangeLower2 = nullptr;
    m_velocityRangeLower3 = nullptr;
    m_velocityRangeLower4 = nullptr;
    m_keyRangeLowerLabel = nullptr;
    m_keyRangeLower1 = nullptr;
    m_keyRangeLower2 = nullptr;
    m_keyRangeLower3 = nullptr;
    m_keyRangeLower4 = nullptr;
    m_keyRangeUpperLabel = nullptr;
    m_keyRangeUpper1 = nullptr;
    m_keyRangeUpper2 = nullptr;
    m_keyRangeUpper3 = nullptr;
    m_keyRangeUpper4 = nullptr;
    m_biasDirectionLabel = nullptr;
    m_biasDirection1 = nullptr;
    m_biasDirection2 = nullptr;
    m_biasDirection3 = nullptr;
    m_biasDirection4 = nullptr;
    m_toneLevelLabel = nullptr;
    m_toneLevel1 = nullptr;
    m_toneLevel2 = nullptr;
    m_toneLevel3 = nullptr;
    m_toneLevel4 = nullptr;
    m_biasPointLabel = nullptr;
    m_biasPoint1 = nullptr;
    m_biasPoint2 = nullptr;
    m_biasPoint3 = nullptr;
    m_biasPoint4 = nullptr;
    m_biasLevelLabel = nullptr;
    m_biasLevel1 = nullptr;
    m_biasLevel2 = nullptr;
    m_biasLevel3 = nullptr;
    m_biasLevel4 = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void ToneMixTable::paint (Graphics& /*g*/)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void ToneMixTable::resized()
{
    m_toneMixTableBoard->setBounds (0, 0, 896, 304);
    m_velocityRangeSwitch->setBounds (0, 320, 152, 24);
    m_velocityCrossFadeLabel->setBounds (0, 416, 152, 24);
    m_velocityCrossFade1->setBounds (160, 416, 152, 24);
    m_tone1Label->setBounds (160, 312, 152, 24);
    m_velocityCrossFade2->setBounds (320, 416, 152, 24);
    m_tone2Label->setBounds (320, 312, 152, 24);
    m_tone3Label->setBounds (480, 312, 152, 24);
    m_tone4Label->setBounds (640, 312, 152, 24);
    m_velocityCrossFade3->setBounds (480, 416, 152, 24);
    m_velocityCrossFade4->setBounds (640, 416, 152, 24);
    m_velocityRangeUpperLabel->setBounds (0, 384, 152, 24);
    m_velocityRangeUpper1->setBounds (160, 384, 152, 24);
    m_velocityRangeUpper2->setBounds (320, 384, 152, 24);
    m_velocityRangeUpper3->setBounds (480, 384, 152, 24);
    m_velocityRangeUpper4->setBounds (640, 384, 152, 24);
    m_velocityRangeLowerLabel->setBounds (0, 352, 152, 24);
    m_velocityRangeLower1->setBounds (160, 352, 152, 24);
    m_velocityRangeLower2->setBounds (320, 352, 152, 24);
    m_velocityRangeLower3->setBounds (480, 352, 152, 24);
    m_velocityRangeLower4->setBounds (640, 352, 152, 24);
    m_keyRangeLowerLabel->setBounds (0, 456, 152, 24);
    m_keyRangeLower1->setBounds (160, 456, 152, 24);
    m_keyRangeLower2->setBounds (320, 456, 152, 24);
    m_keyRangeLower3->setBounds (480, 456, 152, 24);
    m_keyRangeLower4->setBounds (640, 456, 152, 24);
    m_keyRangeUpperLabel->setBounds (0, 488, 152, 24);
    m_keyRangeUpper1->setBounds (160, 488, 152, 24);
    m_keyRangeUpper2->setBounds (320, 488, 152, 24);
    m_keyRangeUpper3->setBounds (480, 488, 152, 24);
    m_keyRangeUpper4->setBounds (640, 488, 152, 24);
    m_biasDirectionLabel->setBounds (0, 560, 152, 24);
    m_biasDirection1->setBounds (160, 560, 152, 24);
    m_biasDirection2->setBounds (320, 560, 152, 24);
    m_biasDirection3->setBounds (480, 560, 152, 24);
    m_biasDirection4->setBounds (640, 560, 152, 24);
    m_toneLevelLabel->setBounds (0, 528, 152, 24);
    m_toneLevel1->setBounds (160, 528, 152, 24);
    m_toneLevel2->setBounds (320, 528, 152, 24);
    m_toneLevel3->setBounds (480, 528, 152, 24);
    m_toneLevel4->setBounds (640, 528, 152, 24);
    m_biasPointLabel->setBounds (0, 592, 152, 24);
    m_biasPoint1->setBounds (160, 592, 152, 24);
    m_biasPoint2->setBounds (320, 592, 152, 24);
    m_biasPoint3->setBounds (480, 592, 152, 24);
    m_biasPoint4->setBounds (640, 592, 152, 24);
    m_biasLevelLabel->setBounds (0, 624, 152, 24);
    m_biasLevel1->setBounds (160, 624, 152, 24);
    m_biasLevel2->setBounds (320, 624, 152, 24);
    m_biasLevel3->setBounds (480, 624, 152, 24);
    m_biasLevel4->setBounds (640, 624, 152, 24);
    //[UserResized] Add your own custom resize handling here..

    // This is called when the ToneMixTable is resized.
    // If you add any child components, this is where you should
    // update their positions.

    //[/UserResized]
}

void ToneMixTable::buttonClicked (Button* buttonThatWasClicked)
{
    //[UserbuttonClicked_Pre]
    //[/UserbuttonClicked_Pre]

    if (buttonThatWasClicked == m_velocityRangeSwitch)
    {
        //[UserButtonCode_m_velocityRangeSwitch] -- add your button handler code here..
		if (ToneMixTableCanvas* canvas = m_toneMixTableBoard->getToneMixTableCanvasPtr())
		{
			canvas->getToneMixTableTone(ToneMixTableCanvas::Tone1)->setVelocityRangesSwitch(m_velocityRangeSwitch->getToggleState() ? 1 : 0);
			canvas->getToneMixTableTone(ToneMixTableCanvas::Tone2)->setVelocityRangesSwitch(m_velocityRangeSwitch->getToggleState() ? 1 : 0);
			canvas->getToneMixTableTone(ToneMixTableCanvas::Tone3)->setVelocityRangesSwitch(m_velocityRangeSwitch->getToggleState() ? 1 : 0);
			canvas->getToneMixTableTone(ToneMixTableCanvas::Tone4)->setVelocityRangesSwitch(m_velocityRangeSwitch->getToggleState() ? 1 : 0);
		}
        //[/UserButtonCode_m_velocityRangeSwitch]
    }

    //[UserbuttonClicked_Post]
    //[/UserbuttonClicked_Post]
}

void ToneMixTable::sliderValueChanged (Slider* sliderThatWasMoved)
{
    //[UsersliderValueChanged_Pre]
    //[/UsersliderValueChanged_Pre]

    if (sliderThatWasMoved == m_velocityCrossFade1)
    {
        //[UserSliderCode_m_velocityCrossFade1] -- add your slider handling code here..
		if (ToneMixTableCanvas* canvas = m_toneMixTableBoard->getToneMixTableCanvasPtr())
		{
			canvas->getToneMixTableTone(ToneMixTableCanvas::Tone1)->setVeloCrossfade((uint8)sliderThatWasMoved->getValue());
			canvas->getToneMixTableXFade(ToneMixTableCanvas::Tone1)->componentMovedOrResized(true,true);
		}
        //[/UserSliderCode_m_velocityCrossFade1]
    }
    else if (sliderThatWasMoved == m_velocityCrossFade2)
    {
        //[UserSliderCode_m_velocityCrossFade2] -- add your slider handling code here..
		if (ToneMixTableCanvas* canvas = m_toneMixTableBoard->getToneMixTableCanvasPtr())
		{
			canvas->getToneMixTableTone(ToneMixTableCanvas::Tone2)->setVeloCrossfade((uint8)sliderThatWasMoved->getValue());
			canvas->getToneMixTableXFade(ToneMixTableCanvas::Tone2)->componentMovedOrResized(true, true);
		}
        //[/UserSliderCode_m_velocityCrossFade2]
    }
    else if (sliderThatWasMoved == m_velocityCrossFade3)
    {
        //[UserSliderCode_m_velocityCrossFade3] -- add your slider handling code here..
		if (ToneMixTableCanvas* canvas = m_toneMixTableBoard->getToneMixTableCanvasPtr())
		{
			canvas->getToneMixTableTone(ToneMixTableCanvas::Tone3)->setVeloCrossfade((uint8)sliderThatWasMoved->getValue());
			canvas->getToneMixTableXFade(ToneMixTableCanvas::Tone3)->componentMovedOrResized(true, true);
		}
        //[/UserSliderCode_m_velocityCrossFade3]
    }
    else if (sliderThatWasMoved == m_velocityCrossFade4)
    {
        //[UserSliderCode_m_velocityCrossFade4] -- add your slider handling code here..
		if (ToneMixTableCanvas* canvas = m_toneMixTableBoard->getToneMixTableCanvasPtr())
		{
			canvas->getToneMixTableTone(ToneMixTableCanvas::Tone4)->setVeloCrossfade((uint8)sliderThatWasMoved->getValue());
			canvas->getToneMixTableXFade(ToneMixTableCanvas::Tone4)->componentMovedOrResized(true, true);
		}
        //[/UserSliderCode_m_velocityCrossFade4]
    }
    else if (sliderThatWasMoved == m_velocityRangeUpper1)
    {
        //[UserSliderCode_m_velocityRangeUpper1] -- add your slider handling code here..
		if (ToneMixTableCanvas* canvas = m_toneMixTableBoard->getToneMixTableCanvasPtr()) canvas->getToneMixTableTone(ToneMixTableCanvas::Tone1)->setVelocityRangeUpper((uint8)sliderThatWasMoved->getValue());
		m_velocityRangeLower1->setRange(0,m_velocityRangeUpper1->getValue(),1.0);
        //[/UserSliderCode_m_velocityRangeUpper1]
    }
    else if (sliderThatWasMoved == m_velocityRangeUpper2)
    {
        //[UserSliderCode_m_velocityRangeUpper2] -- add your slider handling code here..
		if (ToneMixTableCanvas* canvas = m_toneMixTableBoard->getToneMixTableCanvasPtr()) canvas->getToneMixTableTone(ToneMixTableCanvas::Tone2)->setVelocityRangeUpper((uint8)sliderThatWasMoved->getValue());
		m_velocityRangeLower2->setRange(0, m_velocityRangeUpper2->getValue(), 1.0);
        //[/UserSliderCode_m_velocityRangeUpper2]
    }
    else if (sliderThatWasMoved == m_velocityRangeUpper3)
    {
        //[UserSliderCode_m_velocityRangeUpper3] -- add your slider handling code here..
		if (ToneMixTableCanvas* canvas = m_toneMixTableBoard->getToneMixTableCanvasPtr()) canvas->getToneMixTableTone(ToneMixTableCanvas::Tone3)->setVelocityRangeUpper((uint8)sliderThatWasMoved->getValue());
		m_velocityRangeLower3->setRange(0, m_velocityRangeUpper3->getValue(), 1.0);
        //[/UserSliderCode_m_velocityRangeUpper3]
    }
    else if (sliderThatWasMoved == m_velocityRangeUpper4)
    {
        //[UserSliderCode_m_velocityRangeUpper4] -- add your slider handling code here..
		if (ToneMixTableCanvas* canvas = m_toneMixTableBoard->getToneMixTableCanvasPtr()) canvas->getToneMixTableTone(ToneMixTableCanvas::Tone4)->setVelocityRangeUpper((uint8)sliderThatWasMoved->getValue());
		m_velocityRangeLower4->setRange(0, m_velocityRangeUpper4->getValue(), 1.0);
        //[/UserSliderCode_m_velocityRangeUpper4]
    }
    else if (sliderThatWasMoved == m_velocityRangeLower1)
    {
        //[UserSliderCode_m_velocityRangeLower1] -- add your slider handling code here..
		if (ToneMixTableCanvas* canvas = m_toneMixTableBoard->getToneMixTableCanvasPtr()) canvas->getToneMixTableTone(ToneMixTableCanvas::Tone1)->setVelocityRangeLower((uint8)sliderThatWasMoved->getValue());
		m_velocityRangeUpper1->setRange(m_velocityRangeLower1->getValue(), 127, 1.0);
        //[/UserSliderCode_m_velocityRangeLower1]
    }
    else if (sliderThatWasMoved == m_velocityRangeLower2)
    {
        //[UserSliderCode_m_velocityRangeLower2] -- add your slider handling code here..
		if (ToneMixTableCanvas* canvas = m_toneMixTableBoard->getToneMixTableCanvasPtr()) canvas->getToneMixTableTone(ToneMixTableCanvas::Tone2)->setVelocityRangeLower((uint8)sliderThatWasMoved->getValue());
		m_velocityRangeUpper2->setRange(m_velocityRangeLower2->getValue(), 127, 1.0);
        //[/UserSliderCode_m_velocityRangeLower2]
    }
    else if (sliderThatWasMoved == m_velocityRangeLower3)
    {
        //[UserSliderCode_m_velocityRangeLower3] -- add your slider handling code here..
		if (ToneMixTableCanvas* canvas = m_toneMixTableBoard->getToneMixTableCanvasPtr()) canvas->getToneMixTableTone(ToneMixTableCanvas::Tone3)->setVelocityRangeLower((uint8)sliderThatWasMoved->getValue());
		m_velocityRangeUpper3->setRange(m_velocityRangeLower3->getValue(), 127, 1.0);
        //[/UserSliderCode_m_velocityRangeLower3]
    }
    else if (sliderThatWasMoved == m_velocityRangeLower4)
    {
        //[UserSliderCode_m_velocityRangeLower4] -- add your slider handling code here..
		if (ToneMixTableCanvas* canvas = m_toneMixTableBoard->getToneMixTableCanvasPtr()) canvas->getToneMixTableTone(ToneMixTableCanvas::Tone4)->setVelocityRangeLower((uint8)sliderThatWasMoved->getValue());
		m_velocityRangeUpper4->setRange(m_velocityRangeLower4->getValue(), 127, 1.0);
        //[/UserSliderCode_m_velocityRangeLower4]
    }
    else if (sliderThatWasMoved == m_keyRangeLower1)
    {
        //[UserSliderCode_m_keyRangeLower1] -- add your slider handling code here..
		if (ToneMixTableCanvas* canvas = m_toneMixTableBoard->getToneMixTableCanvasPtr()) canvas->getToneMixTableTone(ToneMixTableCanvas::Tone1)->setKeyRangeLower((uint8)sliderThatWasMoved->getValue());
		m_keyRangeUpper1->setRange(m_keyRangeLower1->getValue(), 127, 1.0);
        //[/UserSliderCode_m_keyRangeLower1]
    }
    else if (sliderThatWasMoved == m_keyRangeLower2)
    {
        //[UserSliderCode_m_keyRangeLower2] -- add your slider handling code here..
		if (ToneMixTableCanvas* canvas = m_toneMixTableBoard->getToneMixTableCanvasPtr()) canvas->getToneMixTableTone(ToneMixTableCanvas::Tone2)->setKeyRangeLower((uint8)sliderThatWasMoved->getValue());
		m_keyRangeUpper2->setRange(m_keyRangeLower2->getValue(), 127, 1.0);
        //[/UserSliderCode_m_keyRangeLower2]
    }
    else if (sliderThatWasMoved == m_keyRangeLower3)
    {
        //[UserSliderCode_m_keyRangeLower3] -- add your slider handling code here..
		if (ToneMixTableCanvas* canvas = m_toneMixTableBoard->getToneMixTableCanvasPtr()) canvas->getToneMixTableTone(ToneMixTableCanvas::Tone3)->setKeyRangeLower((uint8)sliderThatWasMoved->getValue());
		m_keyRangeUpper3->setRange(m_keyRangeLower3->getValue(), 127, 1.0);
        //[/UserSliderCode_m_keyRangeLower3]
    }
    else if (sliderThatWasMoved == m_keyRangeLower4)
    {
        //[UserSliderCode_m_keyRangeLower4] -- add your slider handling code here..
		if (ToneMixTableCanvas* canvas = m_toneMixTableBoard->getToneMixTableCanvasPtr()) canvas->getToneMixTableTone(ToneMixTableCanvas::Tone4)->setKeyRangeLower((uint8)sliderThatWasMoved->getValue());
		m_keyRangeUpper4->setRange(m_keyRangeLower4->getValue(), 127, 1.0);
        //[/UserSliderCode_m_keyRangeLower4]
    }
    else if (sliderThatWasMoved == m_keyRangeUpper1)
    {
        //[UserSliderCode_m_keyRangeUpper1] -- add your slider handling code here..
		if (ToneMixTableCanvas* canvas = m_toneMixTableBoard->getToneMixTableCanvasPtr()) canvas->getToneMixTableTone(ToneMixTableCanvas::Tone1)->setKeyRangeUpper((uint8)sliderThatWasMoved->getValue());
		m_keyRangeLower1->setRange(0,m_keyRangeUpper1->getValue(), 1.0);
        //[/UserSliderCode_m_keyRangeUpper1]
    }
    else if (sliderThatWasMoved == m_keyRangeUpper2)
    {
        //[UserSliderCode_m_keyRangeUpper2] -- add your slider handling code here..
		if (ToneMixTableCanvas* canvas = m_toneMixTableBoard->getToneMixTableCanvasPtr()) canvas->getToneMixTableTone(ToneMixTableCanvas::Tone2)->setKeyRangeUpper((uint8)sliderThatWasMoved->getValue());
		m_keyRangeLower2->setRange(0, m_keyRangeUpper2->getValue(), 1.0);
        //[/UserSliderCode_m_keyRangeUpper2]
    }
    else if (sliderThatWasMoved == m_keyRangeUpper3)
    {
        //[UserSliderCode_m_keyRangeUpper3] -- add your slider handling code here..
		if (ToneMixTableCanvas* canvas = m_toneMixTableBoard->getToneMixTableCanvasPtr()) canvas->getToneMixTableTone(ToneMixTableCanvas::Tone3)->setKeyRangeUpper((uint8)sliderThatWasMoved->getValue());
		m_keyRangeLower3->setRange(0, m_keyRangeUpper3->getValue(), 1.0);
        //[/UserSliderCode_m_keyRangeUpper3]
    }
    else if (sliderThatWasMoved == m_keyRangeUpper4)
    {
        //[UserSliderCode_m_keyRangeUpper4] -- add your slider handling code here..
		if (ToneMixTableCanvas* canvas = m_toneMixTableBoard->getToneMixTableCanvasPtr()) canvas->getToneMixTableTone(ToneMixTableCanvas::Tone4)->setKeyRangeUpper((uint8)sliderThatWasMoved->getValue());
		m_keyRangeLower4->setRange(0, m_keyRangeUpper4->getValue(), 1.0);
        //[/UserSliderCode_m_keyRangeUpper4]
    }
    else if (sliderThatWasMoved == m_biasDirection1)
    {
        //[UserSliderCode_m_biasDirection1] -- add your slider handling code here..
		if (ToneMixTableCanvas* canvas = m_toneMixTableBoard->getToneMixTableCanvasPtr())
		{
			canvas->getToneMixTableTone(ToneMixTableCanvas::Tone1)->setBiasDirection((uint8)sliderThatWasMoved->getValue());
			canvas->getToneMixTableXFade(ToneMixTableCanvas::Tone1)->repaint();
		}
        //[/UserSliderCode_m_biasDirection1]
    }
    else if (sliderThatWasMoved == m_biasDirection2)
    {
        //[UserSliderCode_m_biasDirection2] -- add your slider handling code here..
		if (ToneMixTableCanvas* canvas = m_toneMixTableBoard->getToneMixTableCanvasPtr())
		{
			canvas->getToneMixTableTone(ToneMixTableCanvas::Tone2)->setBiasDirection((uint8)sliderThatWasMoved->getValue());
			canvas->getToneMixTableXFade(ToneMixTableCanvas::Tone2)->repaint();
		}
        //[/UserSliderCode_m_biasDirection2]
    }
    else if (sliderThatWasMoved == m_biasDirection3)
    {
        //[UserSliderCode_m_biasDirection3] -- add your slider handling code here..
		if (ToneMixTableCanvas* canvas = m_toneMixTableBoard->getToneMixTableCanvasPtr())
		{
			canvas->getToneMixTableTone(ToneMixTableCanvas::Tone3)->setBiasDirection((uint8)sliderThatWasMoved->getValue());
			canvas->getToneMixTableXFade(ToneMixTableCanvas::Tone3)->repaint();
		}
        //[/UserSliderCode_m_biasDirection3]
    }
    else if (sliderThatWasMoved == m_biasDirection4)
    {
        //[UserSliderCode_m_biasDirection4] -- add your slider handling code here..
		if (ToneMixTableCanvas* canvas = m_toneMixTableBoard->getToneMixTableCanvasPtr())
		{
			canvas->getToneMixTableTone(ToneMixTableCanvas::Tone4)->setBiasDirection((uint8)sliderThatWasMoved->getValue());
			canvas->getToneMixTableXFade(ToneMixTableCanvas::Tone4)->repaint();
		}
        //[/UserSliderCode_m_biasDirection4]
    }
    else if (sliderThatWasMoved == m_toneLevel1)
    {
        //[UserSliderCode_m_toneLevel1] -- add your slider handling code here..
		if (ToneMixTableCanvas* canvas = m_toneMixTableBoard->getToneMixTableCanvasPtr())
		{
			canvas->getToneMixTableTone(ToneMixTableCanvas::Tone1)->setToneLevel((uint8)sliderThatWasMoved->getValue());
			canvas->getToneMixTableXFade(ToneMixTableCanvas::Tone1)->repaint();
		}
        //[/UserSliderCode_m_toneLevel1]
    }
    else if (sliderThatWasMoved == m_toneLevel2)
    {
        //[UserSliderCode_m_toneLevel2] -- add your slider handling code here..
		if (ToneMixTableCanvas* canvas = m_toneMixTableBoard->getToneMixTableCanvasPtr())
		{
			canvas->getToneMixTableTone(ToneMixTableCanvas::Tone2)->setToneLevel((uint8)sliderThatWasMoved->getValue());
			canvas->getToneMixTableXFade(ToneMixTableCanvas::Tone2)->repaint();
		}
        //[/UserSliderCode_m_toneLevel2]
    }
    else if (sliderThatWasMoved == m_toneLevel3)
    {
        //[UserSliderCode_m_toneLevel3] -- add your slider handling code here..
		if (ToneMixTableCanvas* canvas = m_toneMixTableBoard->getToneMixTableCanvasPtr())
		{
			canvas->getToneMixTableTone(ToneMixTableCanvas::Tone3)->setToneLevel((uint8)sliderThatWasMoved->getValue());
			canvas->getToneMixTableXFade(ToneMixTableCanvas::Tone3)->repaint();
		}
        //[/UserSliderCode_m_toneLevel3]
    }
    else if (sliderThatWasMoved == m_toneLevel4)
    {
        //[UserSliderCode_m_toneLevel4] -- add your slider handling code here..
		if (ToneMixTableCanvas* canvas = m_toneMixTableBoard->getToneMixTableCanvasPtr())
		{
			canvas->getToneMixTableTone(ToneMixTableCanvas::Tone4)->setToneLevel((uint8)sliderThatWasMoved->getValue());
			canvas->getToneMixTableXFade(ToneMixTableCanvas::Tone4)->repaint();
		}
        //[/UserSliderCode_m_toneLevel4]
    }
    else if (sliderThatWasMoved == m_biasPoint1)
    {
        //[UserSliderCode_m_biasPoint1] -- add your slider handling code here..
		if (ToneMixTableCanvas* canvas = m_toneMixTableBoard->getToneMixTableCanvasPtr())
		{
			canvas->getToneMixTableTone(ToneMixTableCanvas::Tone1)->setBiasPointKey((uint8)sliderThatWasMoved->getValue());
			canvas->getToneMixTableXFade(ToneMixTableCanvas::Tone1)->repaint();
		}
        //[/UserSliderCode_m_biasPoint1]
    }
    else if (sliderThatWasMoved == m_biasPoint2)
    {
        //[UserSliderCode_m_biasPoint2] -- add your slider handling code here..
		if (ToneMixTableCanvas* canvas = m_toneMixTableBoard->getToneMixTableCanvasPtr())
		{
			canvas->getToneMixTableTone(ToneMixTableCanvas::Tone2)->setBiasPointKey((uint8)sliderThatWasMoved->getValue());
			canvas->getToneMixTableXFade(ToneMixTableCanvas::Tone2)->repaint();
		}
        //[/UserSliderCode_m_biasPoint2]
    }
    else if (sliderThatWasMoved == m_biasPoint3)
    {
        //[UserSliderCode_m_biasPoint3] -- add your slider handling code here..
		if (ToneMixTableCanvas* canvas = m_toneMixTableBoard->getToneMixTableCanvasPtr())
		{
			canvas->getToneMixTableTone(ToneMixTableCanvas::Tone3)->setBiasPointKey((uint8)sliderThatWasMoved->getValue());
			canvas->getToneMixTableXFade(ToneMixTableCanvas::Tone3)->repaint();
		}
        //[/UserSliderCode_m_biasPoint3]
    }
    else if (sliderThatWasMoved == m_biasPoint4)
    {
        //[UserSliderCode_m_biasPoint4] -- add your slider handling code here..
		if (ToneMixTableCanvas* canvas = m_toneMixTableBoard->getToneMixTableCanvasPtr())
		{
			canvas->getToneMixTableTone(ToneMixTableCanvas::Tone4)->setBiasPointKey((uint8)sliderThatWasMoved->getValue());
			canvas->getToneMixTableXFade(ToneMixTableCanvas::Tone4)->repaint();
		}
        //[/UserSliderCode_m_biasPoint4]
    }
    else if (sliderThatWasMoved == m_biasLevel1)
    {
        //[UserSliderCode_m_biasLevel1] -- add your slider handling code here..
		if (ToneMixTableCanvas* canvas = m_toneMixTableBoard->getToneMixTableCanvasPtr())
		{
			canvas->getToneMixTableTone(ToneMixTableCanvas::Tone1)->setBiasLevel((uint8)sliderThatWasMoved->getValue());
			canvas->getToneMixTableXFade(ToneMixTableCanvas::Tone1)->repaint();
		}
        //[/UserSliderCode_m_biasLevel1]
    }
    else if (sliderThatWasMoved == m_biasLevel2)
    {
        //[UserSliderCode_m_biasLevel2] -- add your slider handling code here..
		if (ToneMixTableCanvas* canvas = m_toneMixTableBoard->getToneMixTableCanvasPtr())
		{
			canvas->getToneMixTableTone(ToneMixTableCanvas::Tone2)->setBiasLevel((uint8)sliderThatWasMoved->getValue());
			canvas->getToneMixTableXFade(ToneMixTableCanvas::Tone2)->repaint();
		}
        //[/UserSliderCode_m_biasLevel2]
    }
    else if (sliderThatWasMoved == m_biasLevel3)
    {
        //[UserSliderCode_m_biasLevel3] -- add your slider handling code here..
		if (ToneMixTableCanvas* canvas = m_toneMixTableBoard->getToneMixTableCanvasPtr())
		{
			canvas->getToneMixTableTone(ToneMixTableCanvas::Tone3)->setBiasLevel((uint8)sliderThatWasMoved->getValue());
			canvas->getToneMixTableXFade(ToneMixTableCanvas::Tone3)->repaint();
		}
        //[/UserSliderCode_m_biasLevel3]
    }
    else if (sliderThatWasMoved == m_biasLevel4)
    {
        //[UserSliderCode_m_biasLevel4] -- add your slider handling code here..
		if (ToneMixTableCanvas* canvas = m_toneMixTableBoard->getToneMixTableCanvasPtr())
		{
			canvas->getToneMixTableTone(ToneMixTableCanvas::Tone4)->setBiasLevel((uint8)sliderThatWasMoved->getValue());
			canvas->getToneMixTableXFade(ToneMixTableCanvas::Tone4)->repaint();
		}
        //[/UserSliderCode_m_biasLevel4]
    }

    //[UsersliderValueChanged_Post]
    //[/UsersliderValueChanged_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
void ToneMixTable::changeListenerCallback(ChangeBroadcaster *source)
{
	if (ToneMixTableCanvas* canvas = m_toneMixTableBoard->getToneMixTableCanvasPtr())
	{
		if (ToneMixTableTone* tone = dynamic_cast<ToneMixTableTone*>(source))
		{
			if (tone == canvas->getToneMixTableTone(ToneMixTableCanvas::Tone1))
			{
				m_keyRangeLower1->setValue(tone->getKeyRangeLower(),dontSendNotification);
				m_keyRangeUpper1->setValue(tone->getKeyRangeUpper(), dontSendNotification);
				m_velocityRangeLower1->setValue(tone->getVelocityRangeLower(), dontSendNotification);
				m_velocityRangeUpper1->setValue(tone->getVelocityRangeUpper(), dontSendNotification);
			}
			if (tone == canvas->getToneMixTableTone(ToneMixTableCanvas::Tone2))
			{
				m_keyRangeLower2->setValue(tone->getKeyRangeLower(), dontSendNotification);
				m_keyRangeUpper2->setValue(tone->getKeyRangeUpper(), dontSendNotification);
				m_velocityRangeLower2->setValue(tone->getVelocityRangeLower(), dontSendNotification);
				m_velocityRangeUpper2->setValue(tone->getVelocityRangeUpper(), dontSendNotification);
			}
			if (tone == canvas->getToneMixTableTone(ToneMixTableCanvas::Tone3))
			{
				m_keyRangeLower3->setValue(tone->getKeyRangeLower(), dontSendNotification);
				m_keyRangeUpper3->setValue(tone->getKeyRangeUpper(), dontSendNotification);
				m_velocityRangeLower3->setValue(tone->getVelocityRangeLower(), dontSendNotification);
				m_velocityRangeUpper3->setValue(tone->getVelocityRangeUpper(), dontSendNotification);
			}
			if (tone == canvas->getToneMixTableTone(ToneMixTableCanvas::Tone4))
			{
				m_keyRangeLower4->setValue(tone->getKeyRangeLower(), dontSendNotification);
				m_keyRangeUpper4->setValue(tone->getKeyRangeUpper(), dontSendNotification);
				m_velocityRangeLower4->setValue(tone->getVelocityRangeLower(), dontSendNotification);
				m_velocityRangeUpper4->setValue(tone->getVelocityRangeUpper(), dontSendNotification);
			}
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

<JUCER_COMPONENT documentType="Component" className="ToneMixTable" componentName=""
                 parentClasses="public Component, public ChangeListener" constructorParams=""
                 variableInitialisers="" snapPixels="8" snapActive="1" snapShown="1"
                 overlayOpacity="0.330" fixedSize="0" initialWidth="1024" initialHeight="768">
  <BACKGROUND backgroundColour="0"/>
  <JUCERCOMP name="toneMixTableBoard" id="38be9190ffd03305" memberName="m_toneMixTableBoard"
             virtualName="" explicitFocusOrder="0" pos="0 0 896 304" sourceFile="ToneMixTableBoard.cpp"
             constructorParams="&quot;toneMixTableBoard&quot;"/>
  <TOGGLEBUTTON name="velocityRangeSwitch" id="d31e2a5ab35fe09f" memberName="m_velocityRangeSwitch"
                virtualName="" explicitFocusOrder="0" pos="0 320 152 24" buttonText="Velocity Ranges On"
                connectedEdges="0" needsCallback="1" radioGroupId="0" state="0"/>
  <LABEL name="velocityCrossFadeLabel" id="6d157756df82f292" memberName="m_velocityCrossFadeLabel"
         virtualName="" explicitFocusOrder="0" pos="0 416 152 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Velocity Crossfade:" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" bold="0" italic="0" justification="33"/>
  <SLIDER name="velocityCrossFade1" id="832233e2637f2c3a" memberName="m_velocityCrossFade1"
          virtualName="" explicitFocusOrder="0" pos="160 416 152 24" min="0"
          max="127" int="1" style="LinearHorizontal" textBoxPos="TextBoxRight"
          textBoxEditable="1" textBoxWidth="50" textBoxHeight="20" skewFactor="1"/>
  <LABEL name="tone1Label" id="5015537ae82c7ee2" memberName="m_tone1Label"
         virtualName="" explicitFocusOrder="0" pos="160 312 152 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Tone 1" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         bold="0" italic="0" justification="36"/>
  <SLIDER name="velocityCrossFade2" id="f231a5afac83cfc0" memberName="m_velocityCrossFade2"
          virtualName="" explicitFocusOrder="0" pos="320 416 152 24" min="0"
          max="127" int="1" style="LinearHorizontal" textBoxPos="TextBoxRight"
          textBoxEditable="1" textBoxWidth="50" textBoxHeight="20" skewFactor="1"/>
  <LABEL name="tone2Label" id="1b6987615757ab52" memberName="m_tone2Label"
         virtualName="" explicitFocusOrder="0" pos="320 312 152 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Tone 2" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         bold="0" italic="0" justification="36"/>
  <LABEL name="tone3Label" id="3e6d8fd5ead2c1f1" memberName="m_tone3Label"
         virtualName="" explicitFocusOrder="0" pos="480 312 152 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Tone 3" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         bold="0" italic="0" justification="36"/>
  <LABEL name="tone4Label" id="6a3df457aaba0e99" memberName="m_tone4Label"
         virtualName="" explicitFocusOrder="0" pos="640 312 152 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Tone 4" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         bold="0" italic="0" justification="36"/>
  <SLIDER name="velocityCrossFade3" id="8d69931e22339217" memberName="m_velocityCrossFade3"
          virtualName="" explicitFocusOrder="0" pos="480 416 152 24" min="0"
          max="127" int="1" style="LinearHorizontal" textBoxPos="TextBoxRight"
          textBoxEditable="1" textBoxWidth="50" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="velocityCrossFade4" id="2c131177e5d5004c" memberName="m_velocityCrossFade4"
          virtualName="" explicitFocusOrder="0" pos="640 416 152 24" min="0"
          max="127" int="1" style="LinearHorizontal" textBoxPos="TextBoxRight"
          textBoxEditable="1" textBoxWidth="50" textBoxHeight="20" skewFactor="1"/>
  <LABEL name="velocityRangeUpperLabel" id="f6c3e81cfe1c137f" memberName="m_velocityRangeUpperLabel"
         virtualName="" explicitFocusOrder="0" pos="0 384 152 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Velocity Range Upper:" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" bold="0" italic="0" justification="33"/>
  <SLIDER name="velocityRangeUpper1" id="3732f5805e545704" memberName="m_velocityRangeUpper1"
          virtualName="" explicitFocusOrder="0" pos="160 384 152 24" min="0"
          max="127" int="1" style="LinearHorizontal" textBoxPos="TextBoxRight"
          textBoxEditable="1" textBoxWidth="50" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="velocityRangeUpper2" id="1980dcad67da6429" memberName="m_velocityRangeUpper2"
          virtualName="" explicitFocusOrder="0" pos="320 384 152 24" min="0"
          max="127" int="1" style="LinearHorizontal" textBoxPos="TextBoxRight"
          textBoxEditable="1" textBoxWidth="50" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="velocityRangeUpper3" id="b80095685807b30b" memberName="m_velocityRangeUpper3"
          virtualName="" explicitFocusOrder="0" pos="480 384 152 24" min="0"
          max="127" int="1" style="LinearHorizontal" textBoxPos="TextBoxRight"
          textBoxEditable="1" textBoxWidth="50" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="velocityRangeUpper4" id="8813990ea2b00b82" memberName="m_velocityRangeUpper4"
          virtualName="" explicitFocusOrder="0" pos="640 384 152 24" min="0"
          max="127" int="1" style="LinearHorizontal" textBoxPos="TextBoxRight"
          textBoxEditable="1" textBoxWidth="50" textBoxHeight="20" skewFactor="1"/>
  <LABEL name="velocityRangeLowerLabel" id="30b42c7655a52ba3" memberName="m_velocityRangeLowerLabel"
         virtualName="" explicitFocusOrder="0" pos="0 352 152 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Velocity Range Lower:" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" bold="0" italic="0" justification="33"/>
  <SLIDER name="velocityRangeLower1" id="8df11cfefe7f688e" memberName="m_velocityRangeLower1"
          virtualName="" explicitFocusOrder="0" pos="160 352 152 24" min="0"
          max="127" int="1" style="LinearHorizontal" textBoxPos="TextBoxRight"
          textBoxEditable="1" textBoxWidth="50" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="velocityRangeLower2" id="bc3b58b261335764" memberName="m_velocityRangeLower2"
          virtualName="" explicitFocusOrder="0" pos="320 352 152 24" min="0"
          max="127" int="1" style="LinearHorizontal" textBoxPos="TextBoxRight"
          textBoxEditable="1" textBoxWidth="50" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="velocityRangeLower3" id="2249002a9464112" memberName="m_velocityRangeLower3"
          virtualName="" explicitFocusOrder="0" pos="480 352 152 24" min="0"
          max="127" int="1" style="LinearHorizontal" textBoxPos="TextBoxRight"
          textBoxEditable="1" textBoxWidth="50" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="velocityRangeLower4" id="ccc32e1f95574dec" memberName="m_velocityRangeLower4"
          virtualName="" explicitFocusOrder="0" pos="640 352 152 24" min="0"
          max="127" int="1" style="LinearHorizontal" textBoxPos="TextBoxRight"
          textBoxEditable="1" textBoxWidth="50" textBoxHeight="20" skewFactor="1"/>
  <LABEL name="keyRangeLowerLabel" id="593652f30bc80793" memberName="m_keyRangeLowerLabel"
         virtualName="" explicitFocusOrder="0" pos="0 456 152 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Key Range Lower:" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" bold="0" italic="0" justification="33"/>
  <SLIDER name="keyRangeLower1" id="f9491adf5fb631f4" memberName="m_keyRangeLower1"
          virtualName="" explicitFocusOrder="0" pos="160 456 152 24" min="0"
          max="127" int="1" style="LinearHorizontal" textBoxPos="TextBoxRight"
          textBoxEditable="1" textBoxWidth="50" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="keyRangeLower2" id="50af21cbf6930a81" memberName="m_keyRangeLower2"
          virtualName="" explicitFocusOrder="0" pos="320 456 152 24" min="0"
          max="127" int="1" style="LinearHorizontal" textBoxPos="TextBoxRight"
          textBoxEditable="1" textBoxWidth="50" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="keyRangeLower3" id="d1d2a8fd4b3b1ae6" memberName="m_keyRangeLower3"
          virtualName="" explicitFocusOrder="0" pos="480 456 152 24" min="0"
          max="127" int="1" style="LinearHorizontal" textBoxPos="TextBoxRight"
          textBoxEditable="1" textBoxWidth="50" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="keyRangeLower4" id="f9b7ebcaf228945c" memberName="m_keyRangeLower4"
          virtualName="" explicitFocusOrder="0" pos="640 456 152 24" min="0"
          max="127" int="1" style="LinearHorizontal" textBoxPos="TextBoxRight"
          textBoxEditable="1" textBoxWidth="50" textBoxHeight="20" skewFactor="1"/>
  <LABEL name="keyRangeUpperLabel" id="c3f6bf625bb9b9af" memberName="m_keyRangeUpperLabel"
         virtualName="" explicitFocusOrder="0" pos="0 488 152 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Key Range Upper:" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" bold="0" italic="0" justification="33"/>
  <SLIDER name="keyRangeUpper1" id="38292879c5f9f333" memberName="m_keyRangeUpper1"
          virtualName="" explicitFocusOrder="0" pos="160 488 152 24" min="0"
          max="127" int="1" style="LinearHorizontal" textBoxPos="TextBoxRight"
          textBoxEditable="1" textBoxWidth="50" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="keyRangeUpper2" id="97b65792b152eeaa" memberName="m_keyRangeUpper2"
          virtualName="" explicitFocusOrder="0" pos="320 488 152 24" min="0"
          max="127" int="1" style="LinearHorizontal" textBoxPos="TextBoxRight"
          textBoxEditable="1" textBoxWidth="50" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="keyRangeUpper3" id="873e276a34e3335c" memberName="m_keyRangeUpper3"
          virtualName="" explicitFocusOrder="0" pos="480 488 152 24" min="0"
          max="127" int="1" style="LinearHorizontal" textBoxPos="TextBoxRight"
          textBoxEditable="1" textBoxWidth="50" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="keyRangeUpper4" id="8d404f7b920af523" memberName="m_keyRangeUpper4"
          virtualName="" explicitFocusOrder="0" pos="640 488 152 24" min="0"
          max="127" int="1" style="LinearHorizontal" textBoxPos="TextBoxRight"
          textBoxEditable="1" textBoxWidth="50" textBoxHeight="20" skewFactor="1"/>
  <LABEL name="biasDirectionLabel" id="c5b879d91f81a00d" memberName="m_biasDirectionLabel"
         virtualName="" explicitFocusOrder="0" pos="0 560 152 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Bias Direction:" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" bold="0" italic="0" justification="33"/>
  <SLIDER name="biasDirection1" id="9b78de2572848f2c" memberName="m_biasDirection1"
          virtualName="" explicitFocusOrder="0" pos="160 560 152 24" min="0"
          max="3" int="1" style="LinearHorizontal" textBoxPos="TextBoxRight"
          textBoxEditable="1" textBoxWidth="50" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="biasDirection2" id="dcbfd4eaf0e60e19" memberName="m_biasDirection2"
          virtualName="" explicitFocusOrder="0" pos="320 560 152 24" min="0"
          max="3" int="1" style="LinearHorizontal" textBoxPos="TextBoxRight"
          textBoxEditable="1" textBoxWidth="50" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="biasDirection3" id="5564683d67a4463b" memberName="m_biasDirection3"
          virtualName="" explicitFocusOrder="0" pos="480 560 152 24" min="0"
          max="3" int="1" style="LinearHorizontal" textBoxPos="TextBoxRight"
          textBoxEditable="1" textBoxWidth="50" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="biasDirection4" id="e9ae40d1758a26a2" memberName="m_biasDirection4"
          virtualName="" explicitFocusOrder="0" pos="640 560 152 24" min="0"
          max="3" int="1" style="LinearHorizontal" textBoxPos="TextBoxRight"
          textBoxEditable="1" textBoxWidth="50" textBoxHeight="20" skewFactor="1"/>
  <LABEL name="toneLevelLabel" id="de87c05fd221e249" memberName="m_toneLevelLabel"
         virtualName="" explicitFocusOrder="0" pos="0 528 152 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Tone Level:" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" bold="0" italic="0" justification="33"/>
  <SLIDER name="toneLevel1" id="1fded2c422f50ac4" memberName="m_toneLevel1"
          virtualName="" explicitFocusOrder="0" pos="160 528 152 24" min="0"
          max="127" int="1" style="LinearHorizontal" textBoxPos="TextBoxRight"
          textBoxEditable="1" textBoxWidth="50" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="toneLevel2" id="63214adf81e9299" memberName="m_toneLevel2"
          virtualName="" explicitFocusOrder="0" pos="320 528 152 24" min="0"
          max="127" int="1" style="LinearHorizontal" textBoxPos="TextBoxRight"
          textBoxEditable="1" textBoxWidth="50" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="toneLevel3" id="96843fcd2ce11a9c" memberName="m_toneLevel3"
          virtualName="" explicitFocusOrder="0" pos="480 528 152 24" min="0"
          max="127" int="1" style="LinearHorizontal" textBoxPos="TextBoxRight"
          textBoxEditable="1" textBoxWidth="50" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="toneLevel4" id="2dd99fe3f04e6003" memberName="m_toneLevel4"
          virtualName="" explicitFocusOrder="0" pos="640 528 152 24" min="0"
          max="127" int="1" style="LinearHorizontal" textBoxPos="TextBoxRight"
          textBoxEditable="1" textBoxWidth="50" textBoxHeight="20" skewFactor="1"/>
  <LABEL name="biasPointLabel" id="c08b79261e9bfd0a" memberName="m_biasPointLabel"
         virtualName="" explicitFocusOrder="0" pos="0 592 152 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Bias Point:" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" bold="0" italic="0" justification="33"/>
  <SLIDER name="biasPoint1" id="fea90fcd04290460" memberName="m_biasPoint1"
          virtualName="" explicitFocusOrder="0" pos="160 592 152 24" min="0"
          max="127" int="1" style="LinearHorizontal" textBoxPos="TextBoxRight"
          textBoxEditable="1" textBoxWidth="50" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="biasPoint2" id="651b39ca1ef8dfb7" memberName="m_biasPoint2"
          virtualName="" explicitFocusOrder="0" pos="320 592 152 24" min="0"
          max="127" int="1" style="LinearHorizontal" textBoxPos="TextBoxRight"
          textBoxEditable="1" textBoxWidth="50" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="biasPoint3" id="78d85ef8d646542b" memberName="m_biasPoint3"
          virtualName="" explicitFocusOrder="0" pos="480 592 152 24" min="0"
          max="127" int="1" style="LinearHorizontal" textBoxPos="TextBoxRight"
          textBoxEditable="1" textBoxWidth="50" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="biasPoint4" id="9706594835d83359" memberName="m_biasPoint4"
          virtualName="" explicitFocusOrder="0" pos="640 592 152 24" min="0"
          max="127" int="1" style="LinearHorizontal" textBoxPos="TextBoxRight"
          textBoxEditable="1" textBoxWidth="50" textBoxHeight="20" skewFactor="1"/>
  <LABEL name="biasLevelLabel" id="84d15ac9de51e64" memberName="m_biasLevelLabel"
         virtualName="" explicitFocusOrder="0" pos="0 624 152 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Bias Level:" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" bold="0" italic="0" justification="33"/>
  <SLIDER name="biasLevel1" id="588ff7d940b86835" memberName="m_biasLevel1"
          virtualName="" explicitFocusOrder="0" pos="160 624 152 24" min="0"
          max="14" int="1" style="LinearHorizontal" textBoxPos="TextBoxRight"
          textBoxEditable="1" textBoxWidth="50" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="biasLevel2" id="f14926199f25a6b7" memberName="m_biasLevel2"
          virtualName="" explicitFocusOrder="0" pos="320 624 152 24" min="0"
          max="14" int="1" style="LinearHorizontal" textBoxPos="TextBoxRight"
          textBoxEditable="1" textBoxWidth="50" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="biasLevel3" id="273dd7b5a8f76ee5" memberName="m_biasLevel3"
          virtualName="" explicitFocusOrder="0" pos="480 624 152 24" min="0"
          max="14" int="1" style="LinearHorizontal" textBoxPos="TextBoxRight"
          textBoxEditable="1" textBoxWidth="50" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="biasLevel4" id="70aed7cf946f1ddd" memberName="m_biasLevel4"
          virtualName="" explicitFocusOrder="0" pos="640 624 152 24" min="0"
          max="14" int="1" style="LinearHorizontal" textBoxPos="TextBoxRight"
          textBoxEditable="1" textBoxWidth="50" textBoxHeight="20" skewFactor="1"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
