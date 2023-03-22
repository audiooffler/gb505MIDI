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
#include "../GrooveboxMemory/OverallMemoryBlock.h"
#include "../GrooveboxMemory/QuickSysExBlock.h"
#include "PatchSectionEditors/SoloLegatoEditor.h"
#include "PatchSectionEditors/ToneMixTable.h"
//[/Headers]

#include "PatchEditor.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
extern OverallMemoryBlock* grooveboxMemory;
extern QuickSysExBlock* quickSysEx;
//[/MiscUserDefs]

//==============================================================================
PatchEditor::PatchEditor (SynthParts part)
    : m_part(part)
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    addAndMakeVisible (m_commonGrp4 = new RectangleGrey());
    addAndMakeVisible (m_commonGrp3 = new RectangleGrey());
    addAndMakeVisible (m_commonGrp2 = new RectangleGrey());
    addAndMakeVisible (m_mixGrp = new PanelGroupGrey ("mixerGrp","PART "+String(m_part+1)));
    addAndMakeVisible (m_mixPartTrack = new MixPartTrack ((AllParts)m_part));
    addAndMakeVisible (m_commonGrp1 = new RectangleGrey());
    addAndMakeVisible (m_patchNameLabel = new Label ("patchNameLabel",
                                                     TRANS("PATCH NAME")));
    m_patchNameLabel->setFont (Font (12.00f, Font::bold));
    m_patchNameLabel->setJustificationType (Justification::centredLeft);
    m_patchNameLabel->setEditable (false, false, false);
    m_patchNameLabel->setColour (Label::textColourId, Colours::black);
    m_patchNameLabel->setColour (TextEditor::textColourId, Colours::black);
    m_patchNameLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_patchNameEditor = new ParameterTextEditor ("patchNameEditor"));
    m_patchNameEditor->setMultiLine (false);
    m_patchNameEditor->setReturnKeyStartsNewLine (false);
    m_patchNameEditor->setReadOnly (false);
    m_patchNameEditor->setScrollbarsShown (false);
    m_patchNameEditor->setCaretVisible (true);
    m_patchNameEditor->setPopupMenuEnabled (true);
    m_patchNameEditor->setColour (TextEditor::textColourId, Colours::black);
    m_patchNameEditor->setColour (TextEditor::backgroundColourId, Colour (0xfff2f59b));
    m_patchNameEditor->setColour (TextEditor::outlineColourId, Colours::grey);
    m_patchNameEditor->setText (String());

    addAndMakeVisible (m_voicePriorityLabel = new Label ("voicePriorityLabel",
                                                         TRANS("VOICE\n"
                                                         "PRIORITY")));
    m_voicePriorityLabel->setFont (Font (12.00f, Font::bold));
    m_voicePriorityLabel->setJustificationType (Justification::centredLeft);
    m_voicePriorityLabel->setEditable (false, false, false);
    m_voicePriorityLabel->setColour (Label::textColourId, Colours::black);
    m_voicePriorityLabel->setColour (TextEditor::textColourId, Colours::black);
    m_voicePriorityLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_struct12DisplaySlider = new ParameterStructDisplay ("struct12DisplaySlider", m_part, false));
    m_struct12DisplaySlider->setName ("struct12DisplaySlider");

    addAndMakeVisible (m_struct34DisplaySlider = new ParameterStructDisplay ("struct34DisplaySlider",  m_part, true));
    m_struct34DisplaySlider->setName ("struct34DisplaySlider");

    addAndMakeVisible (m_struct12Label = new Label ("struct12Label",
                                                    TRANS("STRUCTURE\n"
                                                    "TONES 1 & 2")));
    m_struct12Label->setFont (Font (12.00f, Font::bold));
    m_struct12Label->setJustificationType (Justification::centredRight);
    m_struct12Label->setEditable (false, false, false);
    m_struct12Label->setColour (Label::textColourId, Colours::black);
    m_struct12Label->setColour (TextEditor::textColourId, Colours::black);
    m_struct12Label->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_boost12Label = new Label ("boost12Label",
                                                   TRANS("BOOSTER GAIN")));
    m_boost12Label->setFont (Font (12.00f, Font::bold));
    m_boost12Label->setJustificationType (Justification::centredRight);
    m_boost12Label->setEditable (false, false, false);
    m_boost12Label->setColour (Label::textColourId, Colours::black);
    m_boost12Label->setColour (TextEditor::textColourId, Colours::black);
    m_boost12Label->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_struct34Label = new Label ("struct34Label",
                                                    TRANS("STRUCTURE\n"
                                                    "TONES 3 & 4")));
    m_struct34Label->setFont (Font (12.00f, Font::bold));
    m_struct34Label->setJustificationType (Justification::centredLeft);
    m_struct34Label->setEditable (false, false, false);
    m_struct34Label->setColour (Label::textColourId, Colours::black);
    m_struct34Label->setColour (TextEditor::textColourId, Colours::black);
    m_struct34Label->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_boost34Label = new Label ("boost34Label",
                                                   TRANS("BOOSTER GAIN")));
    m_boost34Label->setFont (Font (12.00f, Font::bold));
    m_boost34Label->setJustificationType (Justification::centredLeft);
    m_boost34Label->setEditable (false, false, false);
    m_boost34Label->setColour (Label::textColourId, Colours::black);
    m_boost34Label->setColour (TextEditor::textColourId, Colours::black);
    m_boost34Label->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_voicePriorityToggle = new ParameterLedSwitch ("voicePriorityToggle"));
    addAndMakeVisible (m_soloLegatoEditButton = new TextWithArrowButton ("soloLegatoEditButton"));
    m_soloLegatoEditButton->setButtonText (TRANS("SOLO / PORTAMENTO"));
    m_soloLegatoEditButton->addListener (this);

    addAndMakeVisible (m_toneMixTableButton = new TextWithArrowButton ("toneMixTableButton"));
    m_toneMixTableButton->setButtonText (TRANS("TONE MIX TABLE"));
    m_toneMixTableButton->addListener (this);

    addAndMakeVisible (imageButton2 = new ImageButton ("new button"));
    imageButton2->setButtonText (String());
    imageButton2->addListener (this);

    imageButton2->setImages (false, true, true,
                             ImageCache::getFromMemory (portamento_png, portamento_pngSize), 1.000f, Colour (0x4340454a),
                             Image(), 1.000f, Colour (0x4340454a),
                             Image(), 1.000f, Colour (0x4340454a));
    addAndMakeVisible (imageButton3 = new ImageButton ("new button"));
    imageButton3->setButtonText (String());
    imageButton3->addListener (this);

    imageButton3->setImages (false, true, true,
                             ImageCache::getFromMemory (tonemixtable_png, tonemixtable_pngSize), 1.000f, Colour (0x4340454a),
                             Image(), 1.000f, Colour (0x4340454a),
                             Image(), 1.000f, Colour (0x4340454a));
    addAndMakeVisible (m_toneSelectToggle1 = new BlackToggle());
    addAndMakeVisible (m_toneSelectLabel1 = new Label ("toneSelectLabel",
                                                       TRANS("1")));
    m_toneSelectLabel1->setFont (Font (12.00f, Font::bold));
    m_toneSelectLabel1->setJustificationType (Justification::centred);
    m_toneSelectLabel1->setEditable (false, false, false);
    m_toneSelectLabel1->setColour (Label::textColourId, Colours::black);
    m_toneSelectLabel1->setColour (TextEditor::textColourId, Colours::black);
    m_toneSelectLabel1->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_toneSelectToggle2 = new BlackToggle());
    addAndMakeVisible (m_toneSelectLabel2 = new Label ("toneSelectLabel",
                                                       TRANS("2")));
    m_toneSelectLabel2->setFont (Font (12.00f, Font::bold));
    m_toneSelectLabel2->setJustificationType (Justification::centred);
    m_toneSelectLabel2->setEditable (false, false, false);
    m_toneSelectLabel2->setColour (Label::textColourId, Colours::black);
    m_toneSelectLabel2->setColour (TextEditor::textColourId, Colours::black);
    m_toneSelectLabel2->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_toneSelectToggle3 = new BlackToggle());
    addAndMakeVisible (m_toneSelectLabel3 = new Label ("toneSelectLabel",
                                                       TRANS("3")));
    m_toneSelectLabel3->setFont (Font (12.00f, Font::bold));
    m_toneSelectLabel3->setJustificationType (Justification::centred);
    m_toneSelectLabel3->setEditable (false, false, false);
    m_toneSelectLabel3->setColour (Label::textColourId, Colours::black);
    m_toneSelectLabel3->setColour (TextEditor::textColourId, Colours::black);
    m_toneSelectLabel3->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_toneSelectToggle4 = new BlackToggle());
    addAndMakeVisible (m_toneSelectLabel4 = new Label ("toneSelectLabel",
                                                       TRANS("4")));
    m_toneSelectLabel4->setFont (Font (12.00f, Font::bold));
    m_toneSelectLabel4->setJustificationType (Justification::centred);
    m_toneSelectLabel4->setEditable (false, false, false);
    m_toneSelectLabel4->setColour (Label::textColourId, Colours::black);
    m_toneSelectLabel4->setColour (TextEditor::textColourId, Colours::black);
    m_toneSelectLabel4->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_toneSwitchToggle1 = new BlackToggle());
    addAndMakeVisible (m_toneSwitchLabel1 = new Label ("toneSwitchLabel",
                                                       TRANS("1")));
    m_toneSwitchLabel1->setFont (Font (12.00f, Font::bold));
    m_toneSwitchLabel1->setJustificationType (Justification::centred);
    m_toneSwitchLabel1->setEditable (false, false, false);
    m_toneSwitchLabel1->setColour (Label::textColourId, Colours::black);
    m_toneSwitchLabel1->setColour (TextEditor::textColourId, Colours::black);
    m_toneSwitchLabel1->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_toneSwitchToggle2 = new BlackToggle());
    addAndMakeVisible (m_toneSwitchLabel2 = new Label ("toneSwitchLabel",
                                                       TRANS("2")));
    m_toneSwitchLabel2->setFont (Font (12.00f, Font::bold));
    m_toneSwitchLabel2->setJustificationType (Justification::centred);
    m_toneSwitchLabel2->setEditable (false, false, false);
    m_toneSwitchLabel2->setColour (Label::textColourId, Colours::black);
    m_toneSwitchLabel2->setColour (TextEditor::textColourId, Colours::black);
    m_toneSwitchLabel2->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_toneSwitchToggle3 = new BlackToggle());
    addAndMakeVisible (m_toneSwitchLabel3 = new Label ("toneSwitchLabel",
                                                       TRANS("3")));
    m_toneSwitchLabel3->setFont (Font (12.00f, Font::bold));
    m_toneSwitchLabel3->setJustificationType (Justification::centred);
    m_toneSwitchLabel3->setEditable (false, false, false);
    m_toneSwitchLabel3->setColour (Label::textColourId, Colours::black);
    m_toneSwitchLabel3->setColour (TextEditor::textColourId, Colours::black);
    m_toneSwitchLabel3->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_toneSwitchToggle4 = new BlackToggle());
    addAndMakeVisible (m_toneSwitchLabel4 = new Label ("toneSwitchLabel",
                                                       TRANS("4")));
    m_toneSwitchLabel4->setFont (Font (12.00f, Font::bold));
    m_toneSwitchLabel4->setJustificationType (Justification::centred);
    m_toneSwitchLabel4->setEditable (false, false, false);
    m_toneSwitchLabel4->setColour (Label::textColourId, Colours::black);
    m_toneSwitchLabel4->setColour (TextEditor::textColourId, Colours::black);
    m_toneSwitchLabel4->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_toneSelectMasterLabel = new Label ("toneSelectMasterLabel",
                                                            TRANS("SELECT EDIT TONE")));
    m_toneSelectMasterLabel->setFont (Font (12.00f, Font::bold));
    m_toneSelectMasterLabel->setJustificationType (Justification::centred);
    m_toneSelectMasterLabel->setEditable (false, false, false);
    m_toneSelectMasterLabel->setColour (Label::textColourId, Colours::black);
    m_toneSelectMasterLabel->setColour (TextEditor::textColourId, Colours::black);
    m_toneSelectMasterLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_toneSwitchLabel = new Label ("toneSwitchLabel",
                                                      TRANS("LINK TO SELECTED")));
    m_toneSwitchLabel->setFont (Font (12.00f, Font::bold));
    m_toneSwitchLabel->setJustificationType (Justification::centred);
    m_toneSwitchLabel->setEditable (false, false, false);
    m_toneSwitchLabel->setColour (Label::textColourId, Colours::black);
    m_toneSwitchLabel->setColour (TextEditor::textColourId, Colours::black);
    m_toneSwitchLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (imageButton4 = new ImageButton ("new button"));
    imageButton4->setButtonText (String());
    imageButton4->addListener (this);

    imageButton4->setImages (false, true, true,
                             ImageCache::getFromMemory (solo_png, solo_pngSize), 1.000f, Colour (0x4340454a),
                             Image(), 1.000f, Colour (0x4340454a),
                             Image(), 1.000f, Colour (0x4340454a));
    addAndMakeVisible (imageButton5 = new ImageButton ("new button"));
    imageButton5->setButtonText (String());
    imageButton5->addListener (this);

    imageButton5->setImages (false, true, true,
                             ImageCache::getFromMemory (mixer_png, mixer_pngSize), 1.000f, Colour (0x4340454a),
                             Image(), 1.000f, Colour (0x4340454a),
                             Image(), 1.000f, Colour (0x4340454a));
    addAndMakeVisible (m_editOverviewButton = new TextButton ("editOverviewButton"));
    m_editOverviewButton->setButtonText (TRANS("OVERVIEW"));
    m_editOverviewButton->setConnectedEdges (Button::ConnectedOnRight);
    m_editOverviewButton->setRadioGroupId (1);
    m_editOverviewButton->addListener (this);

    addAndMakeVisible (m_editDetailButton = new TextButton ("editDetailButton"));
    m_editDetailButton->setButtonText (TRANS("DETAIL"));
    m_editDetailButton->setConnectedEdges (Button::ConnectedOnLeft);
    m_editDetailButton->setRadioGroupId (1);
    m_editDetailButton->addListener (this);

    addAndMakeVisible (m_editModeLabel = new Label ("editModeLabel",
                                                    TRANS("SWITCH EDIT MODE")));
    m_editModeLabel->setFont (Font (12.00f, Font::bold));
    m_editModeLabel->setJustificationType (Justification::centred);
    m_editModeLabel->setEditable (false, false, false);
    m_editModeLabel->setColour (TextEditor::textColourId, Colours::black);
    m_editModeLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_editModeLabel2 = new Label ("editModeLabel",
                                                     TRANS("(ALL TONES)  (EDIT TONE)")));
    m_editModeLabel2->setFont (Font (12.00f, Font::bold));
    m_editModeLabel2->setJustificationType (Justification::centred);
    m_editModeLabel2->setEditable (false, false, false);
    m_editModeLabel2->setColour (TextEditor::textColourId, Colours::black);
    m_editModeLabel2->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_boost12ComboBox = new ParameterComboBox ("boost12ComboBox"));
    m_boost12ComboBox->setEditableText (false);
    m_boost12ComboBox->setJustificationType (Justification::centredRight);
    m_boost12ComboBox->setTextWhenNothingSelected (TRANS("0dB"));
    m_boost12ComboBox->setTextWhenNoChoicesAvailable (TRANS("(no choices)"));
    m_boost12ComboBox->addItem (TRANS("0dB"), 1);
    m_boost12ComboBox->addItem (TRANS("+6dB"), 2);
    m_boost12ComboBox->addItem (TRANS("+12dB"), 3);
    m_boost12ComboBox->addItem (TRANS("+18dB"), 4);
    m_boost12ComboBox->addListener (this);

    addAndMakeVisible (m_struct12ComboBox = new ParameterComboBox ("struct12ComboBox"));
    m_struct12ComboBox->setEditableText (false);
    m_struct12ComboBox->setJustificationType (Justification::centredRight);
    m_struct12ComboBox->setTextWhenNothingSelected (TRANS("TYPE 01"));
    m_struct12ComboBox->setTextWhenNoChoicesAvailable (TRANS("(no choices)"));
    m_struct12ComboBox->addItem (TRANS("TYPE 01"), 1);
    m_struct12ComboBox->addItem (TRANS("TYPE 02"), 2);
    m_struct12ComboBox->addItem (TRANS("TYPE 03"), 3);
    m_struct12ComboBox->addItem (TRANS("TYPE 04"), 4);
    m_struct12ComboBox->addItem (TRANS("TYPE 05"), 5);
    m_struct12ComboBox->addItem (TRANS("TYPE 06"), 6);
    m_struct12ComboBox->addItem (TRANS("TYPE 07"), 7);
    m_struct12ComboBox->addItem (TRANS("TYPE 08"), 8);
    m_struct12ComboBox->addItem (TRANS("TYPE 09"), 9);
    m_struct12ComboBox->addItem (TRANS("TYPE 10"), 10);
    m_struct12ComboBox->addListener (this);

    addAndMakeVisible (m_boost34ComboBox = new ParameterComboBox ("boost34ComboBox"));
    m_boost34ComboBox->setEditableText (false);
    m_boost34ComboBox->setJustificationType (Justification::centredRight);
    m_boost34ComboBox->setTextWhenNothingSelected (TRANS("0dB"));
    m_boost34ComboBox->setTextWhenNoChoicesAvailable (TRANS("(no choices)"));
    m_boost34ComboBox->addItem (TRANS("0dB"), 1);
    m_boost34ComboBox->addItem (TRANS("+6dB"), 2);
    m_boost34ComboBox->addItem (TRANS("+12dB"), 3);
    m_boost34ComboBox->addItem (TRANS("+18dB"), 4);
    m_boost34ComboBox->addListener (this);

    addAndMakeVisible (m_struct34ComboBox = new ParameterComboBox ("struct34ComboBox"));
    m_struct34ComboBox->setEditableText (false);
    m_struct34ComboBox->setJustificationType (Justification::centredRight);
    m_struct34ComboBox->setTextWhenNothingSelected (TRANS("TYPE 01"));
    m_struct34ComboBox->setTextWhenNoChoicesAvailable (TRANS("(no choices)"));
    m_struct34ComboBox->addItem (TRANS("TYPE 01"), 1);
    m_struct34ComboBox->addItem (TRANS("TYPE 02"), 2);
    m_struct34ComboBox->addItem (TRANS("TYPE 03"), 3);
    m_struct34ComboBox->addItem (TRANS("TYPE 04"), 4);
    m_struct34ComboBox->addItem (TRANS("TYPE 05"), 5);
    m_struct34ComboBox->addItem (TRANS("TYPE 06"), 6);
    m_struct34ComboBox->addItem (TRANS("TYPE 07"), 7);
    m_struct34ComboBox->addItem (TRANS("TYPE 08"), 8);
    m_struct34ComboBox->addItem (TRANS("TYPE 09"), 9);
    m_struct34ComboBox->addItem (TRANS("TYPE 10"), 10);
    m_struct34ComboBox->addListener (this);

    addAndMakeVisible (m_partNoLabel = new ImageButton ("partNoLabel"));
    m_partNoLabel->setButtonText (TRANS("new button"));
    m_partNoLabel->addListener (this);

    m_partNoLabel->setImages (false, true, true,
                              ImageCache::getFromMemory (partName1_png, partName1_pngSize), 1.000f, Colours::white,
                              Image(), 1.000f, Colour (0x00000000),
                              Image(), 1.000f, Colour (0x00000000));

    //[UserPreSize]
	m_toneSelectToggle1->setToggleState(true, dontSendNotification);
	m_toneSwitchToggle1->setToggleState(true, dontSendNotification);
	m_toneSelectToggle1->addListener(this);
	m_toneSelectToggle2->addListener(this);
	m_toneSelectToggle3->addListener(this);
	m_toneSelectToggle4->addListener(this);
	addAndMakeVisible(m_toneEditor = new PatchToneEditorOverview(m_part));
	switch (m_part)
	{
	case SynthPart1:
		m_partNoLabel->setImages(false, true, true,
			ImageCache::getFromMemory(partName1_png, partName1_pngSize), 1.000f, Colours::white,
			Image(), 1.000f, Colour(0x00000000),
			Image(), 1.000f, Colour(0x00000000));
		break;
	case SynthPart2:
		m_partNoLabel->setImages(false, true, true,
			ImageCache::getFromMemory(partName2_png, partName2_pngSize), 1.000f, Colours::white,
			Image(), 1.000f, Colour(0x00000000),
			Image(), 1.000f, Colour(0x00000000));
		break;
	case SynthPart3:
		m_partNoLabel->setImages(false, true, true,
			ImageCache::getFromMemory(partName3_png, partName3_pngSize), 1.000f, Colours::white,
			Image(), 1.000f, Colour(0x00000000),
			Image(), 1.000f, Colour(0x00000000));
		break;
	case SynthPart4:
		m_partNoLabel->setImages(false, true, true,
			ImageCache::getFromMemory(partName4_png, partName4_pngSize), 1.000f, Colours::white,
			Image(), 1.000f, Colour(0x00000000),
			Image(), 1.000f, Colour(0x00000000));
		break;
	case SynthPart5:
		m_partNoLabel->setImages(false, true, true,
			ImageCache::getFromMemory(partName5_png, partName5_pngSize), 1.000f, Colours::white,
			Image(), 1.000f, Colour(0x00000000),
			Image(), 1.000f, Colour(0x00000000));
		break;
	case SynthPart6:
		m_partNoLabel->setImages(false, true, true,
			ImageCache::getFromMemory(partName6_png, partName6_pngSize), 1.000f, Colours::white,
			Image(), 1.000f, Colour(0x00000000),
			Image(), 1.000f, Colour(0x00000000));
		break;
	case SynthPart7:
		m_partNoLabel->setImages(false, true, true,
			ImageCache::getFromMemory(partName7_png, partName7_pngSize), 1.000f, Colours::white,
			Image(), 1.000f, Colour(0x00000000),
			Image(), 1.000f, Colour(0x00000000));
		break;
	}
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
					m_patchNameEditor->setParameter1(patchCommon->getParameter(0x0));

					m_voicePriorityToggle->setParameter(patchCommon->getParameter(0x43));
					m_struct12ComboBox->setParameter(patchCommon->getParameter(0x44));
					m_boost12ComboBox->setParameter(patchCommon->getParameter(0x45));
					m_struct34ComboBox->setParameter(patchCommon->getParameter(0x46));
					m_boost34ComboBox->setParameter(patchCommon->getParameter(0x47));
				}
			}
		}
	}


	/*
	if (PartInfoPartBlock* p = grooveboxMemory->getPartInfoBlock()->getPartInfoPartBlockPtr(m_part))
	{
		m_mixLevel->setParameter(p->getParameter((uint16)m_mixLevel->getName().getHexValue32()));
		m_panSlider->setParameter(p->getParameter((uint16)m_panSlider->getName().getHexValue32()));
		m_keyShiftSlider->setParameter(p->getParameter((uint16)m_keyShiftSlider->getName().getHexValue32()));
		m_delaySlider->setParameter(p->getParameter((uint16)m_delaySlider->getName().getHexValue32()));
		m_ReverbSlider->setParameter(p->getParameter((uint16)m_ReverbSlider->getName().getHexValue32()));
		m_mfxGrab->setParameter(p->getParameter((uint16)m_mfxGrab->getName().getHexValue32()));
	}
	if (QuickSysExSequencerBlock* s = quickSysEx->getQuickSysExSequencerBlock())
	{
		m_muteToggle->setParameter(s->getParameter(m_part));
	}
	if (QuickSysExSequencerBlock* s = quickSysEx->getQuickSysExSequencerBlock())
	{
		m_toggleBD->setParameter(s->getParameter(RhythmGroup::BD));
		m_toggleSD->setParameter(s->getParameter(RhythmGroup::SD));
		m_toggleHH->setParameter(s->getParameter(RhythmGroup::HH));
		m_toggleCLP->setParameter(s->getParameter(RhythmGroup::CLP));
		m_toggleCYM->setParameter(s->getParameter(RhythmGroup::CYM));
		m_toggleTOMPERC->setParameter(s->getParameter(RhythmGroup::TOM_PERC));
		m_toggleHIT->setParameter(s->getParameter(RhythmGroup::HIT));
		m_toggleOTHERS->setParameter(s->getParameter(RhythmGroup::OTHERS));
	}*/
    //[/UserPreSize]

    setSize (1328, 675);


    //[Constructor] You can add your own custom stuff here..
    //[/Constructor]
}

PatchEditor::~PatchEditor()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    m_commonGrp4 = nullptr;
    m_commonGrp3 = nullptr;
    m_commonGrp2 = nullptr;
    m_mixGrp = nullptr;
    m_mixPartTrack = nullptr;
    m_commonGrp1 = nullptr;
    m_patchNameLabel = nullptr;
    m_patchNameEditor = nullptr;
    m_voicePriorityLabel = nullptr;
    m_struct12DisplaySlider = nullptr;
    m_struct34DisplaySlider = nullptr;
    m_struct12Label = nullptr;
    m_boost12Label = nullptr;
    m_struct34Label = nullptr;
    m_boost34Label = nullptr;
    m_voicePriorityToggle = nullptr;
    m_soloLegatoEditButton = nullptr;
    m_toneMixTableButton = nullptr;
    imageButton2 = nullptr;
    imageButton3 = nullptr;
    m_toneSelectToggle1 = nullptr;
    m_toneSelectLabel1 = nullptr;
    m_toneSelectToggle2 = nullptr;
    m_toneSelectLabel2 = nullptr;
    m_toneSelectToggle3 = nullptr;
    m_toneSelectLabel3 = nullptr;
    m_toneSelectToggle4 = nullptr;
    m_toneSelectLabel4 = nullptr;
    m_toneSwitchToggle1 = nullptr;
    m_toneSwitchLabel1 = nullptr;
    m_toneSwitchToggle2 = nullptr;
    m_toneSwitchLabel2 = nullptr;
    m_toneSwitchToggle3 = nullptr;
    m_toneSwitchLabel3 = nullptr;
    m_toneSwitchToggle4 = nullptr;
    m_toneSwitchLabel4 = nullptr;
    m_toneSelectMasterLabel = nullptr;
    m_toneSwitchLabel = nullptr;
    imageButton4 = nullptr;
    imageButton5 = nullptr;
    m_editOverviewButton = nullptr;
    m_editDetailButton = nullptr;
    m_editModeLabel = nullptr;
    m_editModeLabel2 = nullptr;
    m_boost12ComboBox = nullptr;
    m_struct12ComboBox = nullptr;
    m_boost34ComboBox = nullptr;
    m_struct34ComboBox = nullptr;
    m_partNoLabel = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void PatchEditor::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
	#ifdef JUCE_MSVC
	g;
	#endif
    //[/UserPrePaint]

    g.fillAll (Colour (0xff303030));

    g.setColour (Colour (0xff303030));
    g.drawRoundedRectangle (346.0f, 2.0f, static_cast<float> (getWidth() - 348), static_cast<float> (getHeight() - 579), 5.000f, 0.100f);

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void PatchEditor::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    m_commonGrp4->setBounds (0, 0, 332, 100);
    m_commonGrp3->setBounds (1076, 0, 248, 100);
    m_commonGrp2->setBounds (708, 0, 360, 100);
    m_mixGrp->setBounds (0, 103, 80, 572);
    m_mixPartTrack->setBounds (4, 124, 72, 548);
    m_commonGrp1->setBounds (340, 0, 360, 100);
    m_patchNameLabel->setBounds (88, 4, 84, 24);
    m_patchNameEditor->setBounds (88, 24, 116, 22);
    m_voicePriorityLabel->setBounds (1244, 8, 72, 32);
    m_struct12DisplaySlider->setBounds (440, 4, 256, 90);
    m_struct34DisplaySlider->setBounds (716, 4, 256, 90);
    m_struct12Label->setBounds (340, 8, 100, 32);
    m_boost12Label->setBounds (340, 56, 96, 24);
    m_struct34Label->setBounds (972, 8, 100, 32);
    m_boost34Label->setBounds (972, 56, 100, 24);
    m_voicePriorityToggle->setBounds (1244, 44, 72, 32);
    m_soloLegatoEditButton->setBounds (1088, 28, 140, 20);
    m_toneMixTableButton->setBounds (1088, 72, 140, 20);
    imageButton2->setBounds (1164, 8, 16, 16);
    imageButton3->setBounds (1152, 52, 16, 16);
    m_toneSelectToggle1->setBounds (220, 30, 25, 17);
    m_toneSelectLabel1->setBounds (220, 15, 24, 16);
    m_toneSelectToggle2->setBounds (248, 30, 25, 17);
    m_toneSelectLabel2->setBounds (248, 15, 24, 16);
    m_toneSelectToggle3->setBounds (276, 30, 25, 17);
    m_toneSelectLabel3->setBounds (276, 15, 24, 16);
    m_toneSelectToggle4->setBounds (304, 30, 25, 17);
    m_toneSelectLabel4->setBounds (304, 15, 24, 16);
    m_toneSwitchToggle1->setBounds (220, 78, 25, 17);
    m_toneSwitchLabel1->setBounds (220, 63, 24, 16);
    m_toneSwitchToggle2->setBounds (248, 78, 25, 17);
    m_toneSwitchLabel2->setBounds (248, 63, 24, 16);
    m_toneSwitchToggle3->setBounds (276, 78, 25, 17);
    m_toneSwitchLabel3->setBounds (276, 63, 24, 16);
    m_toneSwitchToggle4->setBounds (304, 78, 25, 17);
    m_toneSwitchLabel4->setBounds (304, 63, 24, 16);
    m_toneSelectMasterLabel->setBounds (216, 4, 116, 16);
    m_toneSwitchLabel->setBounds (220, 52, 108, 16);
    imageButton4->setBounds (1137, 8, 16, 16);
    imageButton5->setBounds (3, 104, 16, 16);
    m_editOverviewButton->setBounds (52, 77, 80, 20);
    m_editDetailButton->setBounds (132, 77, 80, 20);
    m_editModeLabel->setBounds (52, 52, 160, 16);
    m_editModeLabel2->setBounds (52, 63, 160, 16);
    m_boost12ComboBox->setBounds (364, 76, 69, 16);
    m_struct12ComboBox->setBounds (364, 40, 69, 16);
    m_boost34ComboBox->setBounds (976, 76, 68, 16);
    m_struct34ComboBox->setBounds (976, 40, 68, 16);
    m_partNoLabel->setBounds (40 - (24 / 2), 25, 24, 18);
    //[UserResized] Add your own custom resize handling here..
	m_toneEditor->setBounds(84, 103, 1244, 572);
    //[/UserResized]
}

void PatchEditor::buttonClicked (Button* buttonThatWasClicked)
{
    //[UserbuttonClicked_Pre]
    //[/UserbuttonClicked_Pre]

    if (buttonThatWasClicked == m_soloLegatoEditButton)
    {
        //[UserButtonCode_m_soloLegatoEditButton] -- add your button handler code here..
		std::unique_ptr<Component> soloLegatoEditor ( new SoloLegatoEditor("SOLO / LEGATO EDITOR", m_part) );
		CallOutBox::launchAsynchronously(std::move(soloLegatoEditor), buttonThatWasClicked->getScreenBounds(), nullptr);
        //[/UserButtonCode_m_soloLegatoEditButton]
    }
    else if (buttonThatWasClicked == m_toneMixTableButton)
    {
        //[UserButtonCode_m_toneMixTableButton] -- add your button handler code here..
        std::unique_ptr<Component> toneMixTable ( new ToneMixTable("TONE MIX TABLE", m_part) );
		CallOutBox::launchAsynchronously(std::move(toneMixTable), buttonThatWasClicked->getScreenBounds(), nullptr);
        //[/UserButtonCode_m_toneMixTableButton]
    }
    else if (buttonThatWasClicked == imageButton2)
    {
        //[UserButtonCode_imageButton2] -- add your button handler code here..
        //[/UserButtonCode_imageButton2]
    }
    else if (buttonThatWasClicked == imageButton3)
    {
        //[UserButtonCode_imageButton3] -- add your button handler code here..
        //[/UserButtonCode_imageButton3]
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
    else if (buttonThatWasClicked == m_editOverviewButton)
    {
        //[UserButtonCode_m_editOverviewButton] -- add your button handler code here..
		removeChildComponent(m_toneEditor);
		addAndMakeVisible(m_toneEditor = new PatchToneEditorOverview(m_part));
		m_toneEditor->setBounds(84, 103, 1244, 572);
        //[/UserButtonCode_m_editOverviewButton]
    }
    else if (buttonThatWasClicked == m_editDetailButton)
    {
        //[UserButtonCode_m_editDetailButton] -- add your button handler code here..
		removeChildComponent(m_toneEditor);
		Tone t = Tone1;
		if (m_toneSelectToggle2->getToggleState()) t = Tone2;
		if (m_toneSelectToggle3->getToggleState()) t = Tone3;
		if (m_toneSelectToggle4->getToggleState()) t = Tone4;
		addAndMakeVisible(m_toneEditor = new PatchToneEditorAdvanced(m_part,t));
		m_toneEditor->setBounds(84, 103, 1244, 572);
        //[/UserButtonCode_m_editDetailButton]
    }
    else if (buttonThatWasClicked == m_partNoLabel)
    {
        //[UserButtonCode_m_partNoLabel] -- add your button handler code here..
        //[/UserButtonCode_m_partNoLabel]
    }

    //[UserbuttonClicked_Post]
	else if (buttonThatWasClicked == m_toneSelectToggle1)
	{
		m_toneSelectToggle2->setToggleState(false, dontSendNotification);
		m_toneSelectToggle3->setToggleState(false, dontSendNotification);
		m_toneSelectToggle4->setToggleState(false, dontSendNotification);
		m_toneSwitchToggle1->setToggleState(true, sendNotification);
		m_toneSwitchToggle2->setToggleState(false, sendNotification);
		m_toneSwitchToggle3->setToggleState(false, sendNotification);
		m_toneSwitchToggle4->setToggleState(false, sendNotification);
		if (dynamic_cast<PatchToneEditorAdvanced*>(m_toneEditor.get())!=nullptr)
		{
			removeChildComponent(m_toneEditor);
			addAndMakeVisible(m_toneEditor = new PatchToneEditorAdvanced(m_part, Tone1));
			m_toneEditor->setBounds(84, 103, 1244, 572);
		}
	}
	else if (buttonThatWasClicked == m_toneSelectToggle2)
	{
		m_toneSelectToggle1->setToggleState(false, dontSendNotification);
		m_toneSelectToggle3->setToggleState(false, dontSendNotification);
		m_toneSelectToggle4->setToggleState(false, dontSendNotification);
		m_toneSwitchToggle1->setToggleState(false, sendNotification);
		m_toneSwitchToggle2->setToggleState(true, sendNotification);
		m_toneSwitchToggle3->setToggleState(false, sendNotification);
		m_toneSwitchToggle4->setToggleState(false, sendNotification);
		if (dynamic_cast<PatchToneEditorAdvanced*>(m_toneEditor.get()) != nullptr)
		{
			removeChildComponent(m_toneEditor);
			addAndMakeVisible(m_toneEditor = new PatchToneEditorAdvanced(m_part, Tone2));
			m_toneEditor->setBounds(84, 103, 1244, 572);
		}
	}
	else if (buttonThatWasClicked == m_toneSelectToggle3)
	{
		m_toneSelectToggle1->setToggleState(false, dontSendNotification);
		m_toneSelectToggle2->setToggleState(false, dontSendNotification);
		m_toneSelectToggle4->setToggleState(false, dontSendNotification);
		m_toneSwitchToggle1->setToggleState(false, sendNotification);
		m_toneSwitchToggle2->setToggleState(false, sendNotification);
		m_toneSwitchToggle3->setToggleState(true, sendNotification);
		m_toneSwitchToggle4->setToggleState(false, sendNotification);
		if (dynamic_cast<PatchToneEditorAdvanced*>(m_toneEditor.get()) != nullptr)
		{
			removeChildComponent(m_toneEditor);
			addAndMakeVisible(m_toneEditor = new PatchToneEditorAdvanced(m_part, Tone3));
			m_toneEditor->setBounds(84, 103, 1244, 572);
		}
	}
	else if (buttonThatWasClicked == m_toneSelectToggle4)
	{
		m_toneSelectToggle1->setToggleState(false, dontSendNotification);
		m_toneSelectToggle2->setToggleState(false, dontSendNotification);
		m_toneSelectToggle3->setToggleState(false, dontSendNotification);
		m_toneSwitchToggle1->setToggleState(false, sendNotification);
		m_toneSwitchToggle2->setToggleState(false, sendNotification);
		m_toneSwitchToggle3->setToggleState(false, sendNotification);
		m_toneSwitchToggle4->setToggleState(true, sendNotification);
		if (dynamic_cast<PatchToneEditorAdvanced*>(m_toneEditor.get()) != nullptr)
		{
			removeChildComponent(m_toneEditor);
			addAndMakeVisible(m_toneEditor = new PatchToneEditorAdvanced(m_part, Tone4));
			m_toneEditor->setBounds(84, 103, 1244, 572);
		}
	}
    //[/UserbuttonClicked_Post]
}

void PatchEditor::comboBoxChanged (ComboBox* comboBoxThatHasChanged)
{
    //[UsercomboBoxChanged_Pre]
    //[/UsercomboBoxChanged_Pre]

    if (comboBoxThatHasChanged == m_boost12ComboBox)
    {
        //[UserComboBoxCode_m_boost12ComboBox] -- add your combo box handling code here..
        //[/UserComboBoxCode_m_boost12ComboBox]
    }
    else if (comboBoxThatHasChanged == m_struct12ComboBox)
    {
        //[UserComboBoxCode_m_struct12ComboBox] -- add your combo box handling code here..
        //[/UserComboBoxCode_m_struct12ComboBox]
    }
    else if (comboBoxThatHasChanged == m_boost34ComboBox)
    {
        //[UserComboBoxCode_m_boost34ComboBox] -- add your combo box handling code here..
        //[/UserComboBoxCode_m_boost34ComboBox]
    }
    else if (comboBoxThatHasChanged == m_struct34ComboBox)
    {
        //[UserComboBoxCode_m_struct34ComboBox] -- add your combo box handling code here..
        //[/UserComboBoxCode_m_struct34ComboBox]
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

<JUCER_COMPONENT documentType="Component" className="PatchEditor" componentName=""
                 parentClasses="public Component" constructorParams="SynthParts part"
                 variableInitialisers="m_part(part)" snapPixels="4" snapActive="1"
                 snapShown="1" overlayOpacity="0.330" fixedSize="1" initialWidth="1328"
                 initialHeight="675">
  <BACKGROUND backgroundColour="ff303030">
    <ROUNDRECT pos="346 2 348M 579M" cornerSize="5" fill="solid: 0" hasStroke="1"
               stroke="0.1, mitered, butt" strokeColour="solid: ff303030"/>
  </BACKGROUND>
  <JUCERCOMP name="commonGrp1" id="b95f1f3b55f39c2b" memberName="m_commonGrp4"
             virtualName="" explicitFocusOrder="0" pos="0 0 332 100" sourceFile="GroupWidgets/RectangleGrey.cpp"
             constructorParams=""/>
  <JUCERCOMP name="commonGrp3" id="a6da69a2b4215128" memberName="m_commonGrp3"
             virtualName="" explicitFocusOrder="0" pos="1076 0 248 100" sourceFile="GroupWidgets/RectangleGrey.cpp"
             constructorParams=""/>
  <JUCERCOMP name="commonGrp2" id="a6f4acfbc3ae99f8" memberName="m_commonGrp2"
             virtualName="" explicitFocusOrder="0" pos="708 0 360 100" sourceFile="GroupWidgets/RectangleGrey.cpp"
             constructorParams=""/>
  <JUCERCOMP name="mixGrp" id="46883b20b70a0a85" memberName="m_mixGrp" virtualName=""
             explicitFocusOrder="0" pos="0 103 80 572" sourceFile="GroupWidgets/PanelGroupGrey.cpp"
             constructorParams="&quot;mixerGrp&quot;,&quot;PART &quot;+String(m_part+1)"/>
  <JUCERCOMP name="mixPartTrack" id="e1ecee494a7b5f08" memberName="m_mixPartTrack"
             virtualName="" explicitFocusOrder="0" pos="4 124 72 548" sourceFile="MixerSectionsEditors/MixPartTrack.cpp"
             constructorParams="(AllParts)m_part"/>
  <JUCERCOMP name="commonGrp1" id="359de6c6e3b8a36e" memberName="m_commonGrp1"
             virtualName="" explicitFocusOrder="0" pos="340 0 360 100" sourceFile="GroupWidgets/RectangleGrey.cpp"
             constructorParams=""/>
  <LABEL name="patchNameLabel" id="2ec0efd8ffa587b" memberName="m_patchNameLabel"
         virtualName="" explicitFocusOrder="0" pos="88 4 84 24" textCol="ff000000"
         edTextCol="ff000000" edBkgCol="0" labelText="PATCH NAME" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="12" bold="1" italic="0" justification="33"/>
  <TEXTEDITOR name="patchNameEditor" id="9686a2e1612f5756" memberName="m_patchNameEditor"
              virtualName="ParameterTextEditor" explicitFocusOrder="0" pos="88 24 116 22"
              textcol="ff000000" bkgcol="fff2f59b" outlinecol="ff808080" initialText=""
              multiline="0" retKeyStartsLine="0" readonly="0" scrollbars="0"
              caret="1" popupmenu="1"/>
  <LABEL name="voicePriorityLabel" id="39a07dbc337265d" memberName="m_voicePriorityLabel"
         virtualName="" explicitFocusOrder="0" pos="1244 8 72 32" textCol="ff000000"
         edTextCol="ff000000" edBkgCol="0" labelText="VOICE&#10;PRIORITY"
         editableSingleClick="0" editableDoubleClick="0" focusDiscardsChanges="0"
         fontname="Default font" fontsize="12" bold="1" italic="0" justification="33"/>
  <GENERICCOMPONENT name="struct12DisplaySlider" id="feda1e7cf5b32466" memberName="m_struct12DisplaySlider"
                    virtualName="ParameterStructDisplay" explicitFocusOrder="0" pos="440 4 256 90"
                    class="ParameterStructDisplay" params="&quot;struct12DisplaySlider&quot;, m_part, false"/>
  <GENERICCOMPONENT name="struct34DisplaySlider" id="78f6fd0ab7fe6c3d" memberName="m_struct34DisplaySlider"
                    virtualName="ParameterStructDisplay" explicitFocusOrder="0" pos="716 4 256 90"
                    class="ParameterStructDisplay" params="&quot;struct34DisplaySlider&quot;,  m_part, true"/>
  <LABEL name="struct12Label" id="e5912a00f51820c8" memberName="m_struct12Label"
         virtualName="" explicitFocusOrder="0" pos="340 8 100 32" textCol="ff000000"
         edTextCol="ff000000" edBkgCol="0" labelText="STRUCTURE&#10;TONES 1 &amp; 2"
         editableSingleClick="0" editableDoubleClick="0" focusDiscardsChanges="0"
         fontname="Default font" fontsize="12" bold="1" italic="0" justification="34"/>
  <LABEL name="boost12Label" id="27b94a007dc0cfab" memberName="m_boost12Label"
         virtualName="" explicitFocusOrder="0" pos="340 56 96 24" textCol="ff000000"
         edTextCol="ff000000" edBkgCol="0" labelText="BOOSTER GAIN" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="12" bold="1" italic="0" justification="34"/>
  <LABEL name="struct34Label" id="7759ad3a88d38258" memberName="m_struct34Label"
         virtualName="" explicitFocusOrder="0" pos="972 8 100 32" textCol="ff000000"
         edTextCol="ff000000" edBkgCol="0" labelText="STRUCTURE&#10;TONES 3 &amp; 4"
         editableSingleClick="0" editableDoubleClick="0" focusDiscardsChanges="0"
         fontname="Default font" fontsize="12" bold="1" italic="0" justification="33"/>
  <LABEL name="boost34Label" id="4df2f4657039f05d" memberName="m_boost34Label"
         virtualName="" explicitFocusOrder="0" pos="972 56 100 24" textCol="ff000000"
         edTextCol="ff000000" edBkgCol="0" labelText="BOOSTER GAIN" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="12" bold="1" italic="0" justification="33"/>
  <JUCERCOMP name="voicePriorityToggle" id="8cb46d1f8b5ba80d" memberName="m_voicePriorityToggle"
             virtualName="" explicitFocusOrder="0" pos="1244 44 72 32" sourceFile="ParameterWidgets/ParameterLedSwitch.cpp"
             constructorParams="&quot;voicePriorityToggle&quot;"/>
  <TEXTBUTTON name="soloLegatoEditButton" id="416784e642241f6e" memberName="m_soloLegatoEditButton"
              virtualName="TextWithArrowButton" explicitFocusOrder="0" pos="1088 28 140 20"
              buttonText="SOLO / PORTAMENTO" connectedEdges="0" needsCallback="1"
              radioGroupId="0"/>
  <TEXTBUTTON name="toneMixTableButton" id="acd55872215a4fd1" memberName="m_toneMixTableButton"
              virtualName="TextWithArrowButton" explicitFocusOrder="0" pos="1088 72 140 20"
              buttonText="TONE MIX TABLE" connectedEdges="0" needsCallback="1"
              radioGroupId="0"/>
  <IMAGEBUTTON name="new button" id="b65b49f61860262f" memberName="imageButton2"
               virtualName="" explicitFocusOrder="0" pos="1164 8 16 16" buttonText=""
               connectedEdges="0" needsCallback="1" radioGroupId="0" keepProportions="1"
               resourceNormal="portamento_png" opacityNormal="1" colourNormal="4340454a"
               resourceOver="" opacityOver="1" colourOver="4340454a" resourceDown=""
               opacityDown="1" colourDown="4340454a"/>
  <IMAGEBUTTON name="new button" id="ee2985b65fb2184c" memberName="imageButton3"
               virtualName="" explicitFocusOrder="0" pos="1152 52 16 16" buttonText=""
               connectedEdges="0" needsCallback="1" radioGroupId="0" keepProportions="1"
               resourceNormal="tonemixtable_png" opacityNormal="1" colourNormal="4340454a"
               resourceOver="" opacityOver="1" colourOver="4340454a" resourceDown=""
               opacityDown="1" colourDown="4340454a"/>
  <JUCERCOMP name="toneSelectToggle" id="1d7902cb6f52a8a2" memberName="m_toneSelectToggle1"
             virtualName="" explicitFocusOrder="0" pos="220 30 25 17" sourceFile="ParameterWidgets/BlackToggle.cpp"
             constructorParams=""/>
  <LABEL name="toneSelectLabel" id="bc5132eee7a0ee16" memberName="m_toneSelectLabel1"
         virtualName="" explicitFocusOrder="0" pos="220 15 24 16" textCol="ff000000"
         edTextCol="ff000000" edBkgCol="0" labelText="1" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="12" bold="1" italic="0" justification="36"/>
  <JUCERCOMP name="toneSelectToggle" id="5f20f6944bcf8a18" memberName="m_toneSelectToggle2"
             virtualName="" explicitFocusOrder="0" pos="248 30 25 17" sourceFile="ParameterWidgets/BlackToggle.cpp"
             constructorParams=""/>
  <LABEL name="toneSelectLabel" id="a9d11f53fadf9619" memberName="m_toneSelectLabel2"
         virtualName="" explicitFocusOrder="0" pos="248 15 24 16" textCol="ff000000"
         edTextCol="ff000000" edBkgCol="0" labelText="2" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="12" bold="1" italic="0" justification="36"/>
  <JUCERCOMP name="toneSelectToggle" id="8a83575ae2e8ad4f" memberName="m_toneSelectToggle3"
             virtualName="" explicitFocusOrder="0" pos="276 30 25 17" sourceFile="ParameterWidgets/BlackToggle.cpp"
             constructorParams=""/>
  <LABEL name="toneSelectLabel" id="13ffbb3bbdd2eef5" memberName="m_toneSelectLabel3"
         virtualName="" explicitFocusOrder="0" pos="276 15 24 16" textCol="ff000000"
         edTextCol="ff000000" edBkgCol="0" labelText="3" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="12" bold="1" italic="0" justification="36"/>
  <JUCERCOMP name="toneSelectToggle" id="a4cd42eac3440f15" memberName="m_toneSelectToggle4"
             virtualName="" explicitFocusOrder="0" pos="304 30 25 17" sourceFile="ParameterWidgets/BlackToggle.cpp"
             constructorParams=""/>
  <LABEL name="toneSelectLabel" id="36ba5ec2ee7349db" memberName="m_toneSelectLabel4"
         virtualName="" explicitFocusOrder="0" pos="304 15 24 16" textCol="ff000000"
         edTextCol="ff000000" edBkgCol="0" labelText="4" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="12" bold="1" italic="0" justification="36"/>
  <JUCERCOMP name="toneSwitchToggle" id="c18b35c5077acf90" memberName="m_toneSwitchToggle1"
             virtualName="" explicitFocusOrder="0" pos="220 78 25 17" sourceFile="ParameterWidgets/BlackToggle.cpp"
             constructorParams=""/>
  <LABEL name="toneSwitchLabel" id="e0cfdfd5412e2fc" memberName="m_toneSwitchLabel1"
         virtualName="" explicitFocusOrder="0" pos="220 63 24 16" textCol="ff000000"
         edTextCol="ff000000" edBkgCol="0" labelText="1" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="12" bold="1" italic="0" justification="36"/>
  <JUCERCOMP name="toneSwitchToggle" id="68fe6ada0994c8b6" memberName="m_toneSwitchToggle2"
             virtualName="" explicitFocusOrder="0" pos="248 78 25 17" sourceFile="ParameterWidgets/BlackToggle.cpp"
             constructorParams=""/>
  <LABEL name="toneSwitchLabel" id="f5cd62f49f307058" memberName="m_toneSwitchLabel2"
         virtualName="" explicitFocusOrder="0" pos="248 63 24 16" textCol="ff000000"
         edTextCol="ff000000" edBkgCol="0" labelText="2" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="12" bold="1" italic="0" justification="36"/>
  <JUCERCOMP name="toneSwitchToggle" id="8179fd7220d6a632" memberName="m_toneSwitchToggle3"
             virtualName="" explicitFocusOrder="0" pos="276 78 25 17" sourceFile="ParameterWidgets/BlackToggle.cpp"
             constructorParams=""/>
  <LABEL name="toneSwitchLabel" id="702ed7c64cc8e020" memberName="m_toneSwitchLabel3"
         virtualName="" explicitFocusOrder="0" pos="276 63 24 16" textCol="ff000000"
         edTextCol="ff000000" edBkgCol="0" labelText="3" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="12" bold="1" italic="0" justification="36"/>
  <JUCERCOMP name="toneSwitchToggle" id="a9a423dc2bef70fa" memberName="m_toneSwitchToggle4"
             virtualName="" explicitFocusOrder="0" pos="304 78 25 17" sourceFile="ParameterWidgets/BlackToggle.cpp"
             constructorParams=""/>
  <LABEL name="toneSwitchLabel" id="cb57d79bc5ad0ab7" memberName="m_toneSwitchLabel4"
         virtualName="" explicitFocusOrder="0" pos="304 63 24 16" textCol="ff000000"
         edTextCol="ff000000" edBkgCol="0" labelText="4" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="12" bold="1" italic="0" justification="36"/>
  <LABEL name="toneSelectMasterLabel" id="7bd2b29e9aabb630" memberName="m_toneSelectMasterLabel"
         virtualName="" explicitFocusOrder="0" pos="216 4 116 16" textCol="ff000000"
         edTextCol="ff000000" edBkgCol="0" labelText="SELECT EDIT TONE"
         editableSingleClick="0" editableDoubleClick="0" focusDiscardsChanges="0"
         fontname="Default font" fontsize="12" bold="1" italic="0" justification="36"/>
  <LABEL name="toneSwitchLabel" id="d95d813eca4c5310" memberName="m_toneSwitchLabel"
         virtualName="" explicitFocusOrder="0" pos="220 52 108 16" textCol="ff000000"
         edTextCol="ff000000" edBkgCol="0" labelText="LINK TO SELECTED"
         editableSingleClick="0" editableDoubleClick="0" focusDiscardsChanges="0"
         fontname="Default font" fontsize="12" bold="1" italic="0" justification="36"/>
  <IMAGEBUTTON name="new button" id="8aea62b0ef417b25" memberName="imageButton4"
               virtualName="" explicitFocusOrder="0" pos="1137 8 16 16" buttonText=""
               connectedEdges="0" needsCallback="1" radioGroupId="0" keepProportions="1"
               resourceNormal="solo_png" opacityNormal="1" colourNormal="4340454a"
               resourceOver="" opacityOver="1" colourOver="4340454a" resourceDown=""
               opacityDown="1" colourDown="4340454a"/>
  <IMAGEBUTTON name="new button" id="941a767f4267791c" memberName="imageButton5"
               virtualName="" explicitFocusOrder="0" pos="3 104 16 16" buttonText=""
               connectedEdges="0" needsCallback="1" radioGroupId="0" keepProportions="1"
               resourceNormal="mixer_png" opacityNormal="1" colourNormal="4340454a"
               resourceOver="" opacityOver="1" colourOver="4340454a" resourceDown=""
               opacityDown="1" colourDown="4340454a"/>
  <TEXTBUTTON name="editOverviewButton" id="afab28f9f5f23e5d" memberName="m_editOverviewButton"
              virtualName="" explicitFocusOrder="0" pos="52 77 80 20" buttonText="OVERVIEW"
              connectedEdges="2" needsCallback="1" radioGroupId="1"/>
  <TEXTBUTTON name="editDetailButton" id="28ff6553ef9e90f9" memberName="m_editDetailButton"
              virtualName="" explicitFocusOrder="0" pos="132 77 80 20" buttonText="DETAIL"
              connectedEdges="1" needsCallback="1" radioGroupId="1"/>
  <LABEL name="editModeLabel" id="2d02233a57f6c581" memberName="m_editModeLabel"
         virtualName="" explicitFocusOrder="0" pos="52 52 160 16" edTextCol="ff000000"
         edBkgCol="0" labelText="SWITCH EDIT MODE" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="12" bold="1" italic="0" justification="36"/>
  <LABEL name="editModeLabel" id="f03ad3efdca4fc13" memberName="m_editModeLabel2"
         virtualName="" explicitFocusOrder="0" pos="52 63 160 16" edTextCol="ff000000"
         edBkgCol="0" labelText="(ALL TONES)  (EDIT TONE)" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="12" bold="1" italic="0" justification="36"/>
  <COMBOBOX name="boost12ComboBox" id="1615d6307f31d1e" memberName="m_boost12ComboBox"
            virtualName="ParameterComboBox" explicitFocusOrder="0" pos="364 76 69 16"
            editable="0" layout="34" items="0dB&#10;+6dB&#10;+12dB&#10;+18dB"
            textWhenNonSelected="0dB" textWhenNoItems="(no choices)"/>
  <COMBOBOX name="struct12ComboBox" id="630e3cf9088967a0" memberName="m_struct12ComboBox"
            virtualName="ParameterComboBox" explicitFocusOrder="0" pos="364 40 69 16"
            editable="0" layout="34" items="TYPE 01&#10;TYPE 02&#10;TYPE 03&#10;TYPE 04&#10;TYPE 05&#10;TYPE 06&#10;TYPE 07&#10;TYPE 08&#10;TYPE 09&#10;TYPE 10"
            textWhenNonSelected="TYPE 01" textWhenNoItems="(no choices)"/>
  <COMBOBOX name="boost34ComboBox" id="94d151bba0950ab3" memberName="m_boost34ComboBox"
            virtualName="ParameterComboBox" explicitFocusOrder="0" pos="976 76 68 16"
            editable="0" layout="34" items="0dB&#10;+6dB&#10;+12dB&#10;+18dB"
            textWhenNonSelected="0dB" textWhenNoItems="(no choices)"/>
  <COMBOBOX name="struct34ComboBox" id="6cfe29db7b104959" memberName="m_struct34ComboBox"
            virtualName="ParameterComboBox" explicitFocusOrder="0" pos="976 40 68 16"
            editable="0" layout="34" items="TYPE 01&#10;TYPE 02&#10;TYPE 03&#10;TYPE 04&#10;TYPE 05&#10;TYPE 06&#10;TYPE 07&#10;TYPE 08&#10;TYPE 09&#10;TYPE 10"
            textWhenNonSelected="TYPE 01" textWhenNoItems="(no choices)"/>
  <IMAGEBUTTON name="partNoLabel" id="168089c13a9f22fd" memberName="m_partNoLabel"
               virtualName="" explicitFocusOrder="0" pos="40c 25 24 18" buttonText="new button"
               connectedEdges="0" needsCallback="1" radioGroupId="0" keepProportions="1"
               resourceNormal="partName1_png" opacityNormal="1" colourNormal="ffffffff"
               resourceOver="" opacityOver="1" colourOver="0" resourceDown=""
               opacityDown="1" colourDown="0"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif

//==============================================================================
// Binary resources - be careful not to edit any of these sections!

// JUCER_RESOURCE: pitchBendLever_png, 2588, "../../Resources/LookAndFeel/PitchBendLever.png"
static const unsigned char resource_PatchEditor_pitchBendLever_png[] = { 137,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,0,63,0,0,0,27,8,6,0,0,0,203,98,87,255,0,0,0,1,115,82,71,66,0,174,206,28,233,0,
0,0,6,98,75,71,68,0,255,0,255,0,255,160,189,167,147,0,0,0,9,112,72,89,115,0,0,11,19,0,0,11,19,1,0,154,156,24,0,0,0,7,116,73,77,69,7,222,9,9,11,0,3,1,164,68,95,0,0,0,25,116,69,88,116,67,111,109,109,101,
110,116,0,67,114,101,97,116,101,100,32,119,105,116,104,32,71,73,77,80,87,129,14,23,0,0,9,119,73,68,65,84,88,195,213,88,75,111,36,87,25,61,183,238,173,103,187,220,118,63,236,180,237,97,50,246,120,38,54,
30,198,194,36,163,68,26,33,2,230,33,64,202,176,97,193,150,61,66,202,95,128,13,11,54,128,68,16,17,2,54,179,64,40,179,138,52,36,35,49,146,137,4,131,32,131,51,140,159,29,63,104,87,119,219,253,174,215,173,
91,151,133,167,46,238,9,10,66,10,68,190,82,171,187,171,85,183,238,249,206,247,157,239,124,77,240,17,174,239,191,246,214,15,90,155,111,190,58,24,12,192,57,71,146,36,72,211,20,154,166,129,115,142,56,142,
65,41,5,165,20,154,166,193,176,11,119,169,158,251,206,79,127,244,189,71,248,24,22,251,168,54,122,245,39,15,23,122,213,219,223,62,56,56,128,231,121,136,227,24,113,28,35,138,34,8,33,32,165,68,24,134,208,
117,93,5,96,103,103,103,245,249,151,62,255,57,0,31,11,120,237,163,218,104,196,255,195,15,219,173,227,177,48,12,145,166,169,36,132,72,195,48,164,227,56,210,113,28,105,89,150,28,29,29,149,140,49,105,154,
38,164,148,152,157,157,21,127,92,123,235,199,55,94,252,250,202,185,102,30,65,243,121,206,121,154,74,137,32,8,72,16,134,224,113,140,52,77,33,132,128,16,66,149,1,165,84,142,140,140,64,8,145,60,251,236,252,
3,30,31,127,11,192,131,115,11,126,208,239,159,104,84,247,11,227,69,234,142,140,106,81,20,105,156,199,90,146,112,202,57,215,56,79,72,146,112,146,36,9,9,195,80,11,130,64,23,105,154,30,86,55,95,152,254,196,
252,157,229,79,127,217,249,203,159,223,244,207,37,248,94,191,95,15,227,88,23,66,104,203,215,175,173,16,66,64,41,5,128,161,58,15,195,16,253,126,31,191,125,227,141,122,195,243,198,242,99,133,102,28,133,
197,118,72,46,0,120,124,46,193,247,123,189,210,225,225,129,29,71,145,190,189,185,217,136,121,172,113,126,202,58,100,170,69,49,39,72,83,146,36,156,68,113,12,153,166,163,148,49,24,134,153,54,188,253,239,
94,93,190,244,150,183,115,78,193,87,247,246,159,121,188,254,238,8,165,26,82,9,64,166,0,8,0,9,0,16,66,128,115,174,234,95,8,1,215,117,37,99,186,5,0,205,195,191,191,242,153,151,190,176,246,167,181,223,181,
206,29,248,139,51,211,8,122,45,194,121,2,33,146,33,161,251,119,175,52,77,97,24,6,209,8,44,0,32,208,138,17,231,47,3,248,205,185,3,127,117,241,147,114,110,246,34,201,229,114,208,52,13,255,169,230,91,173,
22,142,142,142,112,255,254,125,61,159,207,135,156,243,82,237,253,205,165,115,9,126,44,63,138,141,127,236,225,225,195,135,170,165,73,41,135,152,206,222,227,56,70,146,36,217,139,196,113,108,6,65,231,38,
165,198,198,185,172,249,247,222,123,15,107,247,127,143,205,205,77,48,198,160,105,154,202,128,15,123,79,211,20,73,146,16,0,40,79,148,110,150,39,202,211,91,155,143,15,207,21,248,148,135,206,248,248,56,158,
123,238,57,76,76,76,40,47,127,150,245,236,179,148,82,121,255,122,189,14,206,249,169,253,13,124,114,112,112,112,120,238,152,15,130,0,23,46,92,64,165,82,193,242,242,50,60,207,67,175,215,3,165,20,82,74,164,
105,122,234,167,159,176,61,24,12,208,235,245,112,120,120,136,181,181,53,52,155,77,52,26,141,202,255,51,237,201,211,23,86,87,87,39,116,93,255,89,154,166,150,16,2,140,49,53,152,16,66,64,200,233,45,25,24,
66,72,246,219,203,141,70,131,2,64,169,84,66,189,94,39,73,146,128,82,170,238,201,74,33,77,83,197,124,38,128,97,24,98,48,24,96,105,105,233,126,185,92,110,18,66,100,16,4,6,165,84,80,74,5,99,76,60,121,94,
250,191,100,254,43,174,235,190,240,232,209,163,103,142,143,143,97,154,38,218,237,54,40,165,176,109,27,186,174,195,178,44,4,65,112,186,1,99,168,213,106,106,122,203,174,101,99,43,33,4,150,101,169,224,81,
74,17,69,17,194,48,68,24,134,144,82,14,61,124,125,125,253,165,114,185,28,24,134,161,133,97,104,17,66,16,199,49,124,223,135,148,82,18,66,160,235,186,160,148,198,150,101,33,73,18,48,198,48,24,12,48,61,61,
13,0,104,52,26,208,117,29,182,109,35,73,18,56,142,3,74,41,1,0,215,117,229,220,220,28,194,48,220,101,79,177,174,233,186,254,165,86,171,53,185,181,181,5,223,255,151,213,206,4,74,74,9,195,48,224,186,46,52,
77,131,16,2,154,166,33,142,99,184,174,11,93,215,17,4,1,226,56,134,101,89,208,117,125,104,174,151,82,34,73,18,85,231,31,208,142,52,165,158,231,229,150,151,151,73,161,80,0,99,12,189,94,15,158,231,97,127,
127,63,27,149,41,0,163,219,237,14,221,187,177,177,161,206,170,235,58,124,223,151,166,105,18,66,136,164,148,98,48,24,96,123,123,59,11,70,231,105,230,151,44,203,250,212,222,222,30,1,160,216,46,151,203,170,
95,155,166,9,215,117,213,119,203,178,96,154,38,74,165,18,150,151,151,113,116,116,132,215,95,127,29,71,71,71,136,227,24,253,126,31,134,97,12,101,69,20,69,31,154,142,197,98,145,120,158,135,40,138,48,63,
63,143,98,177,136,185,185,57,248,190,15,198,24,250,253,62,238,221,187,135,48,12,21,1,103,73,178,44,11,174,235,194,178,44,24,134,33,13,195,80,1,73,146,4,134,97,36,132,144,221,167,193,127,45,8,130,75,39,
39,39,144,82,162,80,40,96,106,106,74,41,117,6,148,82,10,211,52,161,235,58,202,229,50,242,249,60,230,231,231,113,235,214,45,236,238,238,226,222,189,123,136,227,24,51,51,51,104,54,155,170,245,81,74,149,
197,205,58,129,16,2,157,78,71,29,96,124,124,28,179,179,179,48,77,19,141,70,3,119,238,220,129,235,186,40,149,74,176,109,27,87,175,94,69,46,151,195,205,155,55,177,179,179,163,246,243,125,31,132,16,8,33,
96,154,38,76,211,132,101,89,228,73,9,74,198,78,161,78,78,78,74,0,239,75,41,255,202,206,164,188,99,24,198,23,61,207,115,124,223,207,230,110,112,206,85,13,27,134,49,228,214,242,249,60,242,249,60,42,149,
10,114,185,28,0,32,12,67,152,166,137,98,177,136,241,241,241,33,177,75,211,20,81,20,169,125,179,244,63,11,30,0,106,181,218,208,119,199,113,208,108,54,1,0,113,28,163,211,233,224,218,181,107,88,88,88,0,33,
4,156,115,84,171,85,116,187,93,104,154,6,203,178,84,151,201,116,70,211,52,232,186,78,44,203,146,66,8,223,113,156,135,103,153,255,44,231,252,114,167,211,129,16,2,153,77,101,140,129,16,50,196,222,217,107,
186,174,99,113,113,17,133,66,1,190,239,163,90,173,170,90,238,118,187,232,245,122,200,231,243,74,233,179,182,151,5,210,48,12,204,205,205,161,86,171,193,247,125,180,90,45,68,81,4,211,52,17,69,17,116,93,
135,231,121,112,28,7,190,239,163,215,235,1,0,222,126,251,109,21,24,223,247,145,207,231,97,24,6,24,99,48,77,19,140,49,245,172,172,75,185,174,43,41,165,36,151,203,53,243,99,227,235,10,60,165,244,149,102,
179,57,85,175,215,17,4,1,70,70,70,20,155,166,105,14,181,42,74,41,44,203,194,228,228,36,46,93,186,4,0,176,44,11,27,27,27,88,95,95,135,16,2,182,109,131,82,138,169,169,41,0,192,232,232,40,132,16,232,245,
122,89,221,169,126,223,110,183,97,219,54,38,39,39,17,134,225,233,136,220,239,131,115,14,93,215,193,57,135,239,251,10,232,217,101,154,38,108,219,86,193,204,218,107,54,87,8,33,20,120,195,48,112,241,226,
69,113,112,112,176,249,235,95,253,242,144,61,73,249,105,198,216,139,7,7,7,36,75,193,48,12,193,57,87,42,159,165,189,166,105,42,24,99,99,99,184,114,229,138,2,223,237,118,177,179,179,131,199,143,31,163,223,
239,131,16,162,2,104,24,134,50,67,182,109,43,86,146,36,81,109,234,202,149,43,74,221,155,205,38,170,213,170,98,26,128,2,94,169,84,212,25,51,81,28,12,6,202,73,74,41,33,165,4,165,84,57,74,74,41,28,199,145,
140,177,125,66,200,195,179,125,254,171,245,122,125,246,108,237,249,190,143,122,189,142,82,169,132,36,73,80,42,149,64,41,85,2,181,184,184,136,217,217,89,156,156,156,160,80,40,224,157,119,222,193,254,254,
62,118,119,119,209,104,52,148,40,54,26,141,15,168,185,97,24,136,227,120,232,218,214,214,22,0,96,101,101,5,229,114,25,11,11,11,88,89,89,193,209,209,17,162,40,194,246,246,54,246,246,246,48,57,57,137,90,
173,6,199,113,112,227,198,13,85,18,217,153,77,211,68,183,219,133,101,89,42,240,82,74,34,132,144,66,8,212,106,181,214,216,216,248,187,0,192,86,87,87,169,97,24,223,104,183,219,185,167,15,228,251,62,246,
246,246,48,51,51,163,218,92,171,213,66,165,82,193,212,212,20,154,205,38,54,55,55,17,69,17,238,222,189,139,106,181,10,0,176,109,27,65,16,124,32,69,179,117,230,57,242,172,203,220,218,218,82,65,184,124,249,
50,92,215,197,210,210,18,76,211,196,210,210,146,50,91,245,122,29,15,30,60,64,181,90,197,238,238,46,42,149,138,42,137,39,194,134,56,142,149,38,61,113,148,36,73,146,132,115,94,47,78,84,254,150,49,127,221,
178,172,197,108,252,124,122,57,142,3,66,8,218,237,54,218,237,54,44,203,66,167,211,193,237,219,183,209,233,116,64,41,85,160,207,250,252,255,98,73,66,136,144,82,106,217,95,233,163,163,163,104,181,90,56,
57,57,65,20,69,104,181,90,184,126,253,186,234,221,153,210,251,190,143,90,173,134,122,189,142,90,173,6,219,182,193,24,131,235,186,74,79,130,32,64,177,88,4,99,76,134,97,88,51,77,243,209,47,126,254,90,11,
0,24,33,228,155,199,199,199,142,166,105,45,215,117,135,60,124,166,236,217,70,89,139,26,12,6,16,66,168,154,154,153,153,81,226,147,49,158,5,50,83,254,145,145,17,100,45,180,82,169,160,86,171,41,183,24,69,
17,52,77,83,162,90,44,22,149,223,111,54,155,152,153,153,193,225,225,33,60,207,35,132,16,216,182,45,93,215,133,235,186,202,34,23,10,5,53,111,100,251,56,142,147,121,10,141,49,102,36,73,146,186,174,171,254,
39,252,39,45,6,165,154,117,106,161,4,0,0,0,0,73,69,78,68,174,66,96,130,0,0};

const char* PatchEditor::pitchBendLever_png = (const char*) resource_PatchEditor_pitchBendLever_png;
const int PatchEditor::pitchBendLever_pngSize = 2588;

// JUCER_RESOURCE: solo_png, 233, "../../Resources/PatchEditSectionIcons/solo.png"
static const unsigned char resource_PatchEditor_solo_png[] = { 137,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,0,16,0,0,0,16,8,6,0,0,0,31,243,255,97,0,0,0,1,115,82,71,66,0,174,206,28,233,0,0,0,6,98,
75,71,68,0,255,0,255,0,255,160,189,167,147,0,0,0,9,112,72,89,115,0,0,11,19,0,0,11,19,1,0,154,156,24,0,0,0,7,116,73,77,69,7,222,12,10,20,19,7,170,9,5,7,0,0,0,105,73,68,65,84,56,203,181,83,65,14,128,48,
8,163,196,255,127,185,94,88,194,16,156,138,235,101,25,161,13,45,1,98,32,73,121,1,0,144,175,228,137,147,145,43,65,26,252,95,179,38,0,200,68,166,177,13,42,77,236,21,24,54,188,157,104,67,87,171,242,153,100,
185,232,147,244,163,160,175,29,49,253,223,50,24,98,241,45,5,170,221,111,95,227,37,184,187,41,202,222,206,49,161,123,206,39,14,54,103,229,37,165,45,72,0,0,0,0,73,69,78,68,174,66,96,130,0,0};

const char* PatchEditor::solo_png = (const char*) resource_PatchEditor_solo_png;
const int PatchEditor::solo_pngSize = 233;

// JUCER_RESOURCE: portamento_png, 224, "../../Resources/PatchEditSectionIcons/portamento.png"
static const unsigned char resource_PatchEditor_portamento_png[] = { 137,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,0,16,0,0,0,16,8,6,0,0,0,31,243,255,97,0,0,0,1,115,82,71,66,0,174,206,28,233,0,0,0,
6,98,75,71,68,0,255,0,255,0,255,160,189,167,147,0,0,0,9,112,72,89,115,0,0,11,19,0,0,11,19,1,0,154,156,24,0,0,0,7,116,73,77,69,7,222,12,10,20,19,23,183,190,21,99,0,0,0,96,73,68,65,84,56,203,165,147,73,
14,192,48,8,3,177,213,255,127,153,94,90,137,44,45,134,248,26,205,196,68,4,246,196,221,221,10,1,0,235,194,3,211,129,163,132,29,40,94,202,207,106,127,181,67,88,154,119,243,128,60,129,83,193,11,207,144,36,
80,224,180,65,6,47,130,56,175,2,15,130,238,66,177,82,123,119,118,85,43,203,27,166,50,56,253,206,55,49,229,71,255,134,170,242,114,0,0,0,0,73,69,78,68,174,66,96,130,0,0};

const char* PatchEditor::portamento_png = (const char*) resource_PatchEditor_portamento_png;
const int PatchEditor::portamento_pngSize = 224;

// JUCER_RESOURCE: tonemixtable_png, 223, "../../Resources/PatchEditSectionIcons/tonemixtable.png"
static const unsigned char resource_PatchEditor_tonemixtable_png[] = { 137,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,0,16,0,0,0,16,8,6,0,0,0,31,243,255,97,0,0,0,1,115,82,71,66,0,174,206,28,233,0,0,
0,6,98,75,71,68,0,255,0,255,0,255,160,189,167,147,0,0,0,9,112,72,89,115,0,0,11,19,0,0,11,19,1,0,154,156,24,0,0,0,7,116,73,77,69,7,222,12,10,20,18,45,104,169,253,144,0,0,0,95,73,68,65,84,56,203,181,147,
81,14,192,32,8,67,121,187,255,157,235,143,75,116,81,8,144,241,41,150,66,11,216,12,73,178,68,0,88,21,188,97,42,224,181,8,183,2,91,139,94,167,183,2,223,247,211,63,73,114,71,120,115,46,73,164,65,68,240,132,
34,1,46,73,87,131,255,92,104,239,65,122,37,79,150,69,185,208,133,252,97,20,48,116,207,121,0,77,35,159,126,216,242,55,52,0,0,0,0,73,69,78,68,174,66,96,130,0,0};

const char* PatchEditor::tonemixtable_png = (const char*) resource_PatchEditor_tonemixtable_png;
const int PatchEditor::tonemixtable_pngSize = 223;

// JUCER_RESOURCE: mixer_png, 237, "../../Resources/PatchEditSectionIcons/mixer.png"
static const unsigned char resource_PatchEditor_mixer_png[] = { 137,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,0,16,0,0,0,16,8,6,0,0,0,31,243,255,97,0,0,0,1,115,82,71,66,0,174,206,28,233,0,0,0,6,98,
75,71,68,0,255,0,255,0,255,160,189,167,147,0,0,0,9,112,72,89,115,0,0,11,19,0,0,11,19,1,0,154,156,24,0,0,0,7,116,73,77,69,7,223,1,3,21,23,50,215,208,54,137,0,0,0,109,73,68,65,84,56,203,173,83,65,14,192,
32,8,107,9,255,255,114,119,217,140,58,117,64,70,98,148,3,180,208,74,73,184,163,61,130,65,0,240,174,152,201,6,2,64,43,22,63,12,100,139,174,187,92,221,105,97,85,228,106,131,215,168,182,160,171,15,228,97,
103,254,39,3,78,183,34,254,240,130,246,3,160,5,232,242,100,182,170,140,165,17,122,253,183,42,48,153,195,102,103,101,63,147,175,236,153,217,197,5,106,27,26,44,105,0,198,59,0,0,0,0,73,69,78,68,174,66,96,
130,0,0};

const char* PatchEditor::mixer_png = (const char*) resource_PatchEditor_mixer_png;
const int PatchEditor::mixer_pngSize = 237;

// JUCER_RESOURCE: partName1_png, 277, "../../Resources/LookAndFeel/PartName1.png"
static const unsigned char resource_PatchEditor_partName1_png[] = { 137,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,0,32,0,0,0,24,8,6,0,0,0,155,83,255,52,0,0,0,4,115,66,73,84,8,8,8,8,124,8,100,136,0,
0,0,9,112,72,89,115,0,0,22,37,0,0,22,37,1,73,82,36,240,0,0,0,25,116,69,88,116,83,111,102,116,119,97,114,101,0,119,119,119,46,105,110,107,115,99,97,112,101,46,111,114,103,155,238,60,26,0,0,0,146,73,68,
65,84,72,137,237,150,177,13,194,64,16,4,119,44,18,18,122,113,19,36,36,46,1,209,16,237,184,21,58,112,104,68,224,192,193,146,162,7,89,127,24,225,228,86,218,228,239,247,52,186,251,224,177,173,45,213,68,46,
3,39,96,44,60,0,61,112,252,138,192,118,181,37,117,146,188,224,75,164,159,237,216,4,42,116,5,246,145,64,20,224,33,233,246,226,169,168,31,36,181,161,142,209,145,21,43,57,235,125,13,221,63,87,48,174,204,
255,252,13,36,64,2,36,64,2,36,64,2,36,64,88,187,149,249,89,210,253,195,89,181,216,250,91,254,4,124,118,180,26,84,31,31,91,0,0,0,0,73,69,78,68,174,66,96,130,0,0};

const char* PatchEditor::partName1_png = (const char*) resource_PatchEditor_partName1_png;
const int PatchEditor::partName1_pngSize = 277;

// JUCER_RESOURCE: partName2_png, 409, "../../Resources/LookAndFeel/PartName2.png"
static const unsigned char resource_PatchEditor_partName2_png[] = { 137,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,0,32,0,0,0,24,8,6,0,0,0,155,83,255,52,0,0,0,4,115,66,73,84,8,8,8,8,124,8,100,136,0,
0,0,9,112,72,89,115,0,0,22,37,0,0,22,37,1,73,82,36,240,0,0,0,25,116,69,88,116,83,111,102,116,119,97,114,101,0,119,119,119,46,105,110,107,115,99,97,112,101,46,111,114,103,155,238,60,26,0,0,1,22,73,68,65,
84,72,137,237,150,61,74,4,65,16,133,191,146,49,16,19,3,67,17,76,252,9,22,204,141,68,188,132,23,240,14,38,130,39,216,208,251,24,154,8,70,30,97,65,97,127,96,117,69,121,38,219,90,211,179,51,8,110,109,39,
62,40,168,174,154,225,189,238,106,30,109,146,40,137,42,37,102,214,3,238,130,120,38,192,61,112,35,233,161,214,145,196,252,20,142,1,5,199,59,112,154,56,37,177,22,180,227,54,172,3,183,190,80,185,252,13,120,
10,32,221,5,54,220,122,223,204,182,37,61,3,63,35,136,10,224,146,230,40,14,87,57,130,81,87,115,213,119,160,136,128,205,174,102,149,23,204,236,28,184,0,14,88,142,192,163,5,181,193,119,150,93,152,107,226,
189,224,177,198,153,25,209,103,48,249,12,56,241,2,252,8,206,104,30,249,199,92,212,95,145,172,248,42,183,98,47,96,103,193,79,123,146,94,150,32,160,21,126,199,150,245,166,209,228,185,128,34,248,23,208,48,
34,7,51,179,173,32,222,153,164,87,160,230,3,125,226,77,40,69,191,212,131,164,129,226,2,252,29,152,2,67,183,86,75,222,213,251,237,119,227,148,88,233,103,249,23,187,55,44,190,136,109,213,126,0,0,0,0,73,
69,78,68,174,66,96,130,0,0};

const char* PatchEditor::partName2_png = (const char*) resource_PatchEditor_partName2_png;
const int PatchEditor::partName2_pngSize = 409;

// JUCER_RESOURCE: partName3_png, 434, "../../Resources/LookAndFeel/PartName3.png"
static const unsigned char resource_PatchEditor_partName3_png[] = { 137,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,0,32,0,0,0,24,8,6,0,0,0,155,83,255,52,0,0,0,4,115,66,73,84,8,8,8,8,124,8,100,136,0,
0,0,9,112,72,89,115,0,0,22,37,0,0,22,37,1,73,82,36,240,0,0,0,25,116,69,88,116,83,111,102,116,119,97,114,101,0,119,119,119,46,105,110,107,115,99,97,112,101,46,111,114,103,155,238,60,26,0,0,1,47,73,68,65,
84,72,137,197,150,177,74,67,65,16,69,207,104,2,242,72,175,8,162,85,10,171,124,66,90,11,75,59,191,192,239,16,191,197,90,172,237,197,34,144,202,144,70,65,11,177,87,76,148,107,145,236,203,188,37,70,133,236,
238,133,229,237,221,89,152,251,102,103,103,199,36,81,18,173,48,49,179,61,224,46,145,159,119,96,8,156,75,106,250,144,196,60,10,7,128,18,143,41,112,20,124,74,202,46,64,192,51,96,193,111,125,4,192,39,240,
248,223,216,254,1,219,192,150,227,187,64,23,24,1,139,8,164,26,192,201,146,40,244,131,125,35,193,31,199,120,93,101,204,33,96,25,166,57,5,84,17,255,0,6,129,248,36,196,204,46,129,157,53,11,56,140,248,149,
164,183,154,69,9,243,64,218,43,120,3,84,222,103,238,28,168,128,182,95,48,255,22,152,217,61,176,63,167,138,190,63,205,127,179,119,128,77,183,126,45,233,120,177,43,125,29,56,165,121,12,19,160,147,243,8,
158,34,222,6,122,129,148,170,3,245,237,43,37,160,70,113,1,190,33,105,49,203,216,117,163,183,210,234,178,181,79,158,126,64,64,183,84,33,130,217,173,24,7,146,91,192,23,112,38,87,253,252,99,52,1,94,18,57,
14,77,233,133,164,91,111,104,148,226,18,248,6,2,197,124,75,53,239,143,19,0,0,0,0,73,69,78,68,174,66,96,130,0,0};

const char* PatchEditor::partName3_png = (const char*) resource_PatchEditor_partName3_png;
const int PatchEditor::partName3_pngSize = 434;

// JUCER_RESOURCE: partName4_png, 500, "../../Resources/LookAndFeel/PartName4.png"
static const unsigned char resource_PatchEditor_partName4_png[] = { 137,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,0,32,0,0,0,24,8,6,0,0,0,155,83,255,52,0,0,0,4,115,66,73,84,8,8,8,8,124,8,100,136,0,
0,0,9,112,72,89,115,0,0,22,37,0,0,22,37,1,73,82,36,240,0,0,0,25,116,69,88,116,83,111,102,116,119,97,114,101,0,119,119,119,46,105,110,107,115,99,97,112,101,46,111,114,103,155,238,60,26,0,0,1,113,73,68,
65,84,72,137,197,214,61,107,84,65,20,198,241,223,217,40,6,69,27,11,83,164,144,96,145,74,196,66,17,84,240,35,72,154,84,105,98,151,62,164,79,138,52,126,2,209,210,66,193,214,82,73,105,33,136,173,111,77,32,
118,18,2,9,104,56,41,118,179,108,54,59,215,205,102,146,125,96,154,123,102,230,249,115,159,115,103,110,100,166,113,234,66,237,13,35,98,2,207,176,140,43,13,83,31,102,230,55,153,89,109,224,9,190,32,135,24,
179,153,169,150,241,12,222,53,152,109,158,9,0,174,98,29,123,5,227,239,120,138,249,170,0,104,97,17,91,5,227,237,78,15,92,234,204,175,7,128,71,248,92,48,222,199,11,220,232,91,115,122,0,220,196,155,134,156,
63,226,78,97,237,232,0,218,159,210,26,118,11,198,63,48,247,159,61,78,14,128,192,66,161,131,15,115,94,57,204,185,42,0,30,224,83,67,206,175,48,117,130,248,134,3,192,20,94,55,228,188,129,187,35,52,110,17,
160,123,20,71,196,52,62,224,150,227,250,133,229,204,124,59,160,118,42,245,222,5,47,7,152,239,104,31,52,207,51,115,175,182,121,23,32,34,38,241,184,175,246,23,183,51,243,231,89,24,31,1,192,101,76,246,213,
46,226,125,68,252,169,224,115,189,88,233,105,148,175,134,187,197,106,141,217,204,212,234,97,89,210,126,237,231,170,110,19,102,230,70,68,220,199,42,238,225,90,69,159,150,118,164,199,53,202,109,88,243,28,
104,13,164,58,71,141,29,160,250,79,105,65,187,248,221,247,236,31,68,39,163,177,233,0,184,89,0,200,207,212,58,6,0,0,0,0,73,69,78,68,174,66,96,130,0,0};

const char* PatchEditor::partName4_png = (const char*) resource_PatchEditor_partName4_png;
const int PatchEditor::partName4_pngSize = 500;

// JUCER_RESOURCE: partName5_png, 381, "../../Resources/LookAndFeel/PartName5.png"
static const unsigned char resource_PatchEditor_partName5_png[] = { 137,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,0,32,0,0,0,24,8,6,0,0,0,155,83,255,52,0,0,0,4,115,66,73,84,8,8,8,8,124,8,100,136,0,
0,0,9,112,72,89,115,0,0,22,37,0,0,22,37,1,73,82,36,240,0,0,0,25,116,69,88,116,83,111,102,116,119,97,114,101,0,119,119,119,46,105,110,107,115,99,97,112,101,46,111,114,103,155,238,60,26,0,0,0,250,73,68,
65,84,72,137,237,149,61,106,66,65,20,133,191,27,148,4,69,176,75,21,200,10,130,157,11,176,183,118,35,238,193,210,210,141,184,133,144,42,144,144,29,8,162,8,138,141,60,94,115,172,70,238,27,30,166,121,243,
166,241,192,129,185,247,22,231,48,63,103,76,18,57,209,241,133,153,237,128,151,212,162,146,134,181,6,128,33,240,156,218,128,199,83,155,98,117,136,119,32,198,17,56,36,117,32,233,70,160,0,228,184,240,243,
20,204,126,4,15,3,230,131,200,204,10,170,207,112,11,108,26,208,41,129,95,96,37,233,175,50,249,231,18,54,205,2,152,86,52,91,54,32,96,7,244,130,102,156,3,41,162,120,0,244,92,253,10,140,128,79,136,130,72,
210,123,195,226,152,217,24,248,138,218,111,97,209,198,43,216,215,244,172,77,3,119,241,48,112,187,132,102,214,5,250,9,52,62,238,78,93,6,204,72,159,1,129,147,156,191,225,5,248,14,69,14,3,115,73,167,80,248,
32,42,129,115,34,209,18,248,1,150,146,214,126,80,249,13,115,224,10,104,94,253,44,227,37,218,84,0,0,0,0,73,69,78,68,174,66,96,130,0,0};

const char* PatchEditor::partName5_png = (const char*) resource_PatchEditor_partName5_png;
const int PatchEditor::partName5_pngSize = 381;

// JUCER_RESOURCE: partName6_png, 415, "../../Resources/LookAndFeel/PartName6.png"
static const unsigned char resource_PatchEditor_partName6_png[] = { 137,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,0,32,0,0,0,24,8,6,0,0,0,155,83,255,52,0,0,0,4,115,66,73,84,8,8,8,8,124,8,100,136,0,
0,0,9,112,72,89,115,0,0,22,37,0,0,22,37,1,73,82,36,240,0,0,0,25,116,69,88,116,83,111,102,116,119,97,114,101,0,119,119,119,46,105,110,107,115,99,97,112,101,46,111,114,103,155,238,60,26,0,0,1,28,73,68,65,
84,72,137,237,150,49,74,3,65,20,134,191,151,136,120,133,128,160,160,136,88,229,0,1,27,207,33,228,6,30,67,11,43,107,59,15,18,75,15,32,66,8,73,99,33,88,6,2,129,196,223,98,217,245,237,24,119,149,205,204,
54,254,48,176,59,111,225,251,153,159,121,251,76,18,109,106,39,220,48,179,33,112,9,156,0,221,72,220,129,164,9,0,146,138,5,220,2,74,176,78,11,166,131,247,129,143,212,6,124,4,231,128,5,71,53,7,22,127,59,
221,95,105,149,63,120,3,189,13,31,30,73,122,143,96,160,80,167,170,24,27,94,107,32,133,90,55,240,173,15,120,153,217,104,75,156,21,240,2,60,72,122,42,85,220,53,188,38,254,245,91,3,87,190,247,164,142,160,
3,220,152,217,113,190,81,25,1,176,220,2,180,27,112,118,129,11,96,82,107,64,210,94,83,186,153,237,3,179,128,117,144,63,68,143,64,210,43,89,246,37,95,201,12,212,233,223,64,93,35,58,3,166,13,25,135,85,28,
95,120,219,80,127,110,8,255,73,5,203,71,48,34,235,86,177,37,224,241,235,45,253,72,118,231,153,22,78,197,145,134,210,53,48,38,251,25,221,151,120,109,143,229,159,210,85,221,16,190,19,24,212,0,0,0,0,73,69,
78,68,174,66,96,130,0,0};

const char* PatchEditor::partName6_png = (const char*) resource_PatchEditor_partName6_png;
const int PatchEditor::partName6_pngSize = 415;

// JUCER_RESOURCE: partName7_png, 458, "../../Resources/LookAndFeel/PartName7.png"
static const unsigned char resource_PatchEditor_partName7_png[] = { 137,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,0,32,0,0,0,24,8,6,0,0,0,155,83,255,52,0,0,0,4,115,66,73,84,8,8,8,8,124,8,100,136,0,
0,0,9,112,72,89,115,0,0,22,37,0,0,22,37,1,73,82,36,240,0,0,0,25,116,69,88,116,83,111,102,116,119,97,114,101,0,119,119,119,46,105,110,107,115,99,97,112,101,46,111,114,103,155,238,60,26,0,0,1,71,73,68,65,
84,72,137,197,214,189,74,3,65,20,134,225,119,76,48,8,74,10,33,130,164,241,2,86,47,64,44,98,101,165,224,53,88,218,26,82,230,30,82,166,81,11,27,193,75,176,209,164,10,22,90,217,136,118,22,118,177,240,7,115,
44,76,66,126,206,236,238,236,238,172,7,6,134,101,230,60,31,203,97,89,35,34,252,103,21,71,27,99,76,0,220,228,228,238,136,200,195,84,0,160,0,148,115,10,80,24,109,22,114,2,173,53,249,6,62,128,199,140,251,
175,3,43,202,243,159,241,78,68,188,44,96,11,120,7,100,102,93,76,157,243,132,175,1,47,10,222,3,150,188,6,0,74,64,87,193,95,129,234,220,121,15,1,206,21,252,19,216,86,207,103,140,55,20,92,128,35,235,157,
12,241,3,96,160,224,173,208,123,25,225,155,64,95,193,175,129,162,215,0,64,197,50,241,79,192,106,228,253,148,120,9,232,40,120,31,8,98,245,72,25,224,76,193,7,192,97,236,30,41,240,186,101,226,155,78,125,
18,226,251,195,239,249,44,126,5,24,175,1,128,192,50,241,247,192,178,115,63,71,188,2,60,43,248,27,176,145,232,109,58,224,139,192,173,130,127,3,181,196,179,228,16,224,212,50,116,199,73,241,216,1,128,19,
11,222,78,131,139,200,223,196,134,149,49,102,23,184,100,226,63,110,88,119,192,158,136,124,133,54,136,168,200,0,190,235,23,170,109,86,234,6,19,168,208,0,0,0,0,73,69,78,68,174,66,96,130,0,0};

const char* PatchEditor::partName7_png = (const char*) resource_PatchEditor_partName7_png;
const int PatchEditor::partName7_pngSize = 458;


//[EndFile] You can add extra defines here...
//[/EndFile]
