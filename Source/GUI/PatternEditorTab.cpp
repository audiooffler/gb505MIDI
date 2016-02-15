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
#include "../GrooveboxMemory/PatternBodyBlock.h"
#include "GrooveboxLookAndFeel.h"
//[/Headers]

#include "PatternEditorTab.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
extern MidiOutput* midiOutputDevice;
extern int preferredMidiOutId;
extern OverallMemoryBlock* grooveboxMemory;
//[/MiscUserDefs]

//==============================================================================
PatternEditorTab::PatternEditorTab ()
{
    //[Constructor_pre] You can add your own custom stuff here..
	PatternBodyBlock* patternBodyBlock = grooveboxMemory->getPatternBodyBlock();
	patternBodyBlock->addChangeListener(this);
	m_patternEventTableHeader = new TableHeaderComponent();
	m_patternEventTableHeader->addColumn(PatternBodyBlock::PATTERNTABLE_COLUMN_NAMES_FOR_IDS[PatternBodyBlock::Col_Position], PatternBodyBlock::Col_Position, 60);
	m_patternEventTableHeader->addColumn(PatternBodyBlock::PATTERNTABLE_COLUMN_NAMES_FOR_IDS[PatternBodyBlock::Col_Raw0], PatternBodyBlock::Col_Raw0, 30);
	m_patternEventTableHeader->addColumn(PatternBodyBlock::PATTERNTABLE_COLUMN_NAMES_FOR_IDS[PatternBodyBlock::Col_TicksInc], PatternBodyBlock::Col_TicksInc, 30);
	m_patternEventTableHeader->addColumn(PatternBodyBlock::PATTERNTABLE_COLUMN_NAMES_FOR_IDS[PatternBodyBlock::Col_Raw1], PatternBodyBlock::Col_Raw1, 30);
	m_patternEventTableHeader->addColumn(PatternBodyBlock::PATTERNTABLE_COLUMN_NAMES_FOR_IDS[PatternBodyBlock::Col_EventType], PatternBodyBlock::Col_EventType, 60);
	m_patternEventTableHeader->addColumn(PatternBodyBlock::PATTERNTABLE_COLUMN_NAMES_FOR_IDS[PatternBodyBlock::Col_Raw2], PatternBodyBlock::Col_Raw2, 30);
	m_patternEventTableHeader->addColumn(PatternBodyBlock::PATTERNTABLE_COLUMN_NAMES_FOR_IDS[PatternBodyBlock::Col_Raw3], PatternBodyBlock::Col_Raw3, 30);
	m_patternEventTableHeader->addColumn(PatternBodyBlock::PATTERNTABLE_COLUMN_NAMES_FOR_IDS[PatternBodyBlock::Col_Part], PatternBodyBlock::Col_Part, 60);
	m_patternEventTableHeader->addColumn(PatternBodyBlock::PATTERNTABLE_COLUMN_NAMES_FOR_IDS[PatternBodyBlock::Col_Raw4], PatternBodyBlock::Col_Raw4, 30);
	m_patternEventTableHeader->addColumn(PatternBodyBlock::PATTERNTABLE_COLUMN_NAMES_FOR_IDS[PatternBodyBlock::Col_Raw5], PatternBodyBlock::Col_Raw5, 30);
	m_patternEventTableHeader->addColumn(PatternBodyBlock::PATTERNTABLE_COLUMN_NAMES_FOR_IDS[PatternBodyBlock::Col_Raw6], PatternBodyBlock::Col_Raw6, 30);
	m_patternEventTableHeader->addColumn(PatternBodyBlock::PATTERNTABLE_COLUMN_NAMES_FOR_IDS[PatternBodyBlock::Col_Raw7], PatternBodyBlock::Col_Raw7, 30);
	m_patternEventTableHeader->addColumn(PatternBodyBlock::PATTERNTABLE_COLUMN_NAMES_FOR_IDS[PatternBodyBlock::Col_Value1], PatternBodyBlock::Col_Value1, 100);
	m_patternEventTableHeader->addColumn(PatternBodyBlock::PATTERNTABLE_COLUMN_NAMES_FOR_IDS[PatternBodyBlock::Col_Value2], PatternBodyBlock::Col_Value2, 100);
    //[/Constructor_pre]

    addAndMakeVisible (component3 = new RectangleDark());
    addAndMakeVisible (component4 = new RectangleGrey());
    addAndMakeVisible (component2 = new RectangleGrey());
    addAndMakeVisible (m_midiOutComboBox = new ComboBox ("midiOutComboBox"));
    m_midiOutComboBox->setEditableText (false);
    m_midiOutComboBox->setJustificationType (Justification::centredLeft);
    m_midiOutComboBox->setTextWhenNothingSelected (String());
    m_midiOutComboBox->setTextWhenNoChoicesAvailable (TRANS("(no choices)"));
    m_midiOutComboBox->addListener (this);

    addAndMakeVisible (m_midiOutLabel = new Label ("midiOutLabel",
                                                   TRANS("MIDI OUT:")));
    m_midiOutLabel->setFont (Font (12.00f, Font::bold));
    m_midiOutLabel->setJustificationType (Justification::centredRight);
    m_midiOutLabel->setEditable (false, false, false);
    m_midiOutLabel->setColour (Label::textColourId, Colours::white);
    m_midiOutLabel->setColour (TextEditor::textColourId, Colours::black);
    m_midiOutLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_panicButton = new TextButton ("panicButton"));
    m_panicButton->setButtonText (TRANS("MIDI Panic!"));
    m_panicButton->addListener (this);

    addAndMakeVisible (m_patternEventTable = new TableListBox ("patternEventTable"));

    addAndMakeVisible (m_noteRangeLowerSlider = new MicroParameterSlider ("noteRangeLowerSlider"));
    m_noteRangeLowerSlider->setRange (0, 127, 1);
    m_noteRangeLowerSlider->setSliderStyle (Slider::LinearBar);
    m_noteRangeLowerSlider->setTextBoxStyle (Slider::TextBoxLeft, false, 40, 20);
    m_noteRangeLowerSlider->setColour (Slider::backgroundColourId, Colour (0xfff2f59b));
    m_noteRangeLowerSlider->setColour (Slider::thumbColourId, Colour (0xffc4c86d));
    m_noteRangeLowerSlider->addListener (this);

    addAndMakeVisible (m_noteRangeUpperSlider = new MicroParameterSlider ("noteRangeUpperSlider"));
    m_noteRangeUpperSlider->setRange (0, 127, 1);
    m_noteRangeUpperSlider->setSliderStyle (Slider::LinearBar);
    m_noteRangeUpperSlider->setTextBoxStyle (Slider::TextBoxLeft, false, 40, 20);
    m_noteRangeUpperSlider->setColour (Slider::backgroundColourId, Colour (0xfff2f59b));
    m_noteRangeUpperSlider->setColour (Slider::thumbColourId, Colour (0xffc4c86d));
    m_noteRangeUpperSlider->addListener (this);

    addAndMakeVisible (m_fromLabel = new Label ("fromLabel",
                                                TRANS("FROM")));
    m_fromLabel->setFont (Font (12.00f, Font::bold));
    m_fromLabel->setJustificationType (Justification::centredRight);
    m_fromLabel->setEditable (false, false, false);
    m_fromLabel->setColour (TextEditor::textColourId, Colours::black);
    m_fromLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_ccRangeLowerSlider = new MicroParameterSlider ("ccRangeLowerSlider"));
    m_ccRangeLowerSlider->setRange (0, 127, 1);
    m_ccRangeLowerSlider->setSliderStyle (Slider::LinearBar);
    m_ccRangeLowerSlider->setTextBoxStyle (Slider::TextBoxLeft, false, 40, 20);
    m_ccRangeLowerSlider->setColour (Slider::backgroundColourId, Colour (0xfff2f59b));
    m_ccRangeLowerSlider->setColour (Slider::thumbColourId, Colour (0xffc4c86d));
    m_ccRangeLowerSlider->addListener (this);

    addAndMakeVisible (m_ccRangeUpperSlider = new MicroParameterSlider ("ccRangeUpperSlider"));
    m_ccRangeUpperSlider->setRange (0, 127, 1);
    m_ccRangeUpperSlider->setSliderStyle (Slider::LinearBar);
    m_ccRangeUpperSlider->setTextBoxStyle (Slider::TextBoxLeft, false, 40, 20);
    m_ccRangeUpperSlider->setColour (Slider::backgroundColourId, Colour (0xfff2f59b));
    m_ccRangeUpperSlider->setColour (Slider::thumbColourId, Colour (0xffc4c86d));
    m_ccRangeUpperSlider->addListener (this);

    addAndMakeVisible (m_PAftRangeLowerSlider = new MicroParameterSlider ("PAftRangeLowerSlider"));
    m_PAftRangeLowerSlider->setRange (0, 127, 1);
    m_PAftRangeLowerSlider->setSliderStyle (Slider::LinearBar);
    m_PAftRangeLowerSlider->setTextBoxStyle (Slider::TextBoxLeft, false, 40, 20);
    m_PAftRangeLowerSlider->setColour (Slider::backgroundColourId, Colour (0xfff2f59b));
    m_PAftRangeLowerSlider->setColour (Slider::thumbColourId, Colour (0xffc4c86d));
    m_PAftRangeLowerSlider->addListener (this);

    addAndMakeVisible (m_PAftRangeUpperSlider = new MicroParameterSlider ("PAftRangeUpperSlider"));
    m_PAftRangeUpperSlider->setRange (0, 127, 1);
    m_PAftRangeUpperSlider->setSliderStyle (Slider::LinearBar);
    m_PAftRangeUpperSlider->setTextBoxStyle (Slider::TextBoxLeft, false, 40, 20);
    m_PAftRangeUpperSlider->setColour (Slider::backgroundColourId, Colour (0xfff2f59b));
    m_PAftRangeUpperSlider->setColour (Slider::thumbColourId, Colour (0xffc4c86d));
    m_PAftRangeUpperSlider->addListener (this);

    addAndMakeVisible (m_viewPartToggleR = new BlackToggle());
    addAndMakeVisible (m_viewPartLabelR = new Label ("viewPartLabelR",
                                                     TRANS("R")));
    m_viewPartLabelR->setFont (Font (12.00f, Font::bold));
    m_viewPartLabelR->setJustificationType (Justification::centredRight);
    m_viewPartLabelR->setEditable (false, false, false);
    m_viewPartLabelR->setColour (Label::textColourId, Colours::black);
    m_viewPartLabelR->setColour (TextEditor::textColourId, Colours::black);
    m_viewPartLabelR->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_viewPartToggle1 = new BlackToggle());
    addAndMakeVisible (m_viewPartLabel1 = new Label ("viewPartLabel1",
                                                     TRANS("1")));
    m_viewPartLabel1->setFont (Font (12.00f, Font::bold));
    m_viewPartLabel1->setJustificationType (Justification::centredRight);
    m_viewPartLabel1->setEditable (false, false, false);
    m_viewPartLabel1->setColour (Label::textColourId, Colours::black);
    m_viewPartLabel1->setColour (TextEditor::textColourId, Colours::black);
    m_viewPartLabel1->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_viewPartToggle2 = new BlackToggle());
    addAndMakeVisible (m_viewPartLabel2 = new Label ("viewPartLabel2",
                                                     TRANS("2")));
    m_viewPartLabel2->setFont (Font (12.00f, Font::bold));
    m_viewPartLabel2->setJustificationType (Justification::centredRight);
    m_viewPartLabel2->setEditable (false, false, false);
    m_viewPartLabel2->setColour (Label::textColourId, Colours::black);
    m_viewPartLabel2->setColour (TextEditor::textColourId, Colours::black);
    m_viewPartLabel2->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_viewPartToggle3 = new BlackToggle());
    addAndMakeVisible (m_viewPartLabel3 = new Label ("viewPartLabel3",
                                                     TRANS("3")));
    m_viewPartLabel3->setFont (Font (12.00f, Font::bold));
    m_viewPartLabel3->setJustificationType (Justification::centredRight);
    m_viewPartLabel3->setEditable (false, false, false);
    m_viewPartLabel3->setColour (Label::textColourId, Colours::black);
    m_viewPartLabel3->setColour (TextEditor::textColourId, Colours::black);
    m_viewPartLabel3->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_viewPartToggle4 = new BlackToggle());
    addAndMakeVisible (m_viewPartLabel4 = new Label ("viewPartLabel4",
                                                     TRANS("4")));
    m_viewPartLabel4->setFont (Font (12.00f, Font::bold));
    m_viewPartLabel4->setJustificationType (Justification::centredRight);
    m_viewPartLabel4->setEditable (false, false, false);
    m_viewPartLabel4->setColour (Label::textColourId, Colours::black);
    m_viewPartLabel4->setColour (TextEditor::textColourId, Colours::black);
    m_viewPartLabel4->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_viewPartToggle5 = new BlackToggle());
    addAndMakeVisible (m_viewPartLabel5 = new Label ("viewPartLabel5",
                                                     TRANS("5")));
    m_viewPartLabel5->setFont (Font (12.00f, Font::bold));
    m_viewPartLabel5->setJustificationType (Justification::centredRight);
    m_viewPartLabel5->setEditable (false, false, false);
    m_viewPartLabel5->setColour (Label::textColourId, Colours::black);
    m_viewPartLabel5->setColour (TextEditor::textColourId, Colours::black);
    m_viewPartLabel5->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_viewPartToggle6 = new BlackToggle());
    addAndMakeVisible (m_viewPartLabel6 = new Label ("viewPartLabel6",
                                                     TRANS("6")));
    m_viewPartLabel6->setFont (Font (12.00f, Font::bold));
    m_viewPartLabel6->setJustificationType (Justification::centredRight);
    m_viewPartLabel6->setEditable (false, false, false);
    m_viewPartLabel6->setColour (Label::textColourId, Colours::black);
    m_viewPartLabel6->setColour (TextEditor::textColourId, Colours::black);
    m_viewPartLabel6->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_viewPartToggleMuteCtl = new BlackToggle());
    addAndMakeVisible (m_viewPartLabelMuteCtl = new Label ("viewPartLabelMuteCtl",
                                                           TRANS("MUTE-CTL")));
    m_viewPartLabelMuteCtl->setFont (Font (12.00f, Font::bold));
    m_viewPartLabelMuteCtl->setJustificationType (Justification::centredRight);
    m_viewPartLabelMuteCtl->setEditable (false, false, false);
    m_viewPartLabelMuteCtl->setColour (Label::textColourId, Colours::black);
    m_viewPartLabelMuteCtl->setColour (TextEditor::textColourId, Colours::black);
    m_viewPartLabelMuteCtl->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_viewPartsLabel = new Label ("viewPartsLabel",
                                                     TRANS("VIEW PARTS:")));
    m_viewPartsLabel->setFont (Font (12.00f, Font::bold));
    m_viewPartsLabel->setJustificationType (Justification::centredLeft);
    m_viewPartsLabel->setEditable (false, false, false);
    m_viewPartsLabel->setColour (Label::textColourId, Colours::black);
    m_viewPartsLabel->setColour (TextEditor::textColourId, Colours::black);
    m_viewPartsLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_viewEventsLabel2 = new Label ("viewEventsLabel",
                                                       TRANS("VIEW EVENTS:")));
    m_viewEventsLabel2->setFont (Font (12.00f, Font::bold));
    m_viewEventsLabel2->setJustificationType (Justification::centredLeft);
    m_viewEventsLabel2->setEditable (false, false, false);
    m_viewEventsLabel2->setColour (Label::textColourId, Colours::black);
    m_viewEventsLabel2->setColour (TextEditor::textColourId, Colours::black);
    m_viewEventsLabel2->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_viewTypeToggleNote = new BlackToggle());
    addAndMakeVisible (m_viewTypeNoteLabel = new Label ("viewTypeNoteLabel",
                                                        TRANS("NOTE")));
    m_viewTypeNoteLabel->setFont (Font (12.00f, Font::bold));
    m_viewTypeNoteLabel->setJustificationType (Justification::centredRight);
    m_viewTypeNoteLabel->setEditable (false, false, false);
    m_viewTypeNoteLabel->setColour (Label::textColourId, Colours::black);
    m_viewTypeNoteLabel->setColour (TextEditor::textColourId, Colours::black);
    m_viewTypeNoteLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_viewTypeTogglePc = new BlackToggle());
    addAndMakeVisible (m_viewTypePcLabel = new Label ("viewTypePcLabel",
                                                      TRANS("PC")));
    m_viewTypePcLabel->setFont (Font (12.00f, Font::bold));
    m_viewTypePcLabel->setJustificationType (Justification::centredRight);
    m_viewTypePcLabel->setEditable (false, false, false);
    m_viewTypePcLabel->setColour (Label::textColourId, Colours::black);
    m_viewTypePcLabel->setColour (TextEditor::textColourId, Colours::black);
    m_viewTypePcLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_viewTypeToggleCc = new BlackToggle());
    addAndMakeVisible (m_viewTypeCcLabel = new Label ("viewTypeCcLabel",
                                                      TRANS("CC")));
    m_viewTypeCcLabel->setFont (Font (12.00f, Font::bold));
    m_viewTypeCcLabel->setJustificationType (Justification::centredRight);
    m_viewTypeCcLabel->setEditable (false, false, false);
    m_viewTypeCcLabel->setColour (Label::textColourId, Colours::black);
    m_viewTypeCcLabel->setColour (TextEditor::textColourId, Colours::black);
    m_viewTypeCcLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_viewTypeToggleBend = new BlackToggle());
    addAndMakeVisible (m_viewTypeBendLabel = new Label ("viewTypeBendLabel",
                                                        TRANS("BEND")));
    m_viewTypeBendLabel->setFont (Font (12.00f, Font::bold));
    m_viewTypeBendLabel->setJustificationType (Justification::centredRight);
    m_viewTypeBendLabel->setEditable (false, false, false);
    m_viewTypeBendLabel->setColour (Label::textColourId, Colours::black);
    m_viewTypeBendLabel->setColour (TextEditor::textColourId, Colours::black);
    m_viewTypeBendLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_viewTypeTogglePAft = new BlackToggle());
    addAndMakeVisible (m_viewTypePAftLabel = new Label ("viewTypePAftLabel",
                                                        TRANS("P-AFT")));
    m_viewTypePAftLabel->setFont (Font (12.00f, Font::bold));
    m_viewTypePAftLabel->setJustificationType (Justification::centredRight);
    m_viewTypePAftLabel->setEditable (false, false, false);
    m_viewTypePAftLabel->setColour (Label::textColourId, Colours::black);
    m_viewTypePAftLabel->setColour (TextEditor::textColourId, Colours::black);
    m_viewTypePAftLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_viewTypeToggleCAft = new BlackToggle());
    addAndMakeVisible (m_viewTypeCAftLabel = new Label ("viewTypeCAftLabel",
                                                        TRANS("C-AFT")));
    m_viewTypeCAftLabel->setFont (Font (12.00f, Font::bold));
    m_viewTypeCAftLabel->setJustificationType (Justification::centredRight);
    m_viewTypeCAftLabel->setEditable (false, false, false);
    m_viewTypeCAftLabel->setColour (Label::textColourId, Colours::black);
    m_viewTypeCAftLabel->setColour (TextEditor::textColourId, Colours::black);
    m_viewTypeCAftLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_viewTypeToggleTempo = new BlackToggle());
    addAndMakeVisible (m_viewTypeTempoLabel = new Label ("viewTypeTempoLabel",
                                                         TRANS("TEMPO")));
    m_viewTypeTempoLabel->setFont (Font (12.00f, Font::bold));
    m_viewTypeTempoLabel->setJustificationType (Justification::centredRight);
    m_viewTypeTempoLabel->setEditable (false, false, false);
    m_viewTypeTempoLabel->setColour (Label::textColourId, Colours::black);
    m_viewTypeTempoLabel->setColour (TextEditor::textColourId, Colours::black);
    m_viewTypeTempoLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_viewTypeToggleMute = new BlackToggle());
    addAndMakeVisible (m_viewTypeMuteLabel = new Label ("viewTypeMuteLabel",
                                                        TRANS("MUTE")));
    m_viewTypeMuteLabel->setFont (Font (12.00f, Font::bold));
    m_viewTypeMuteLabel->setJustificationType (Justification::centredRight);
    m_viewTypeMuteLabel->setEditable (false, false, false);
    m_viewTypeMuteLabel->setColour (Label::textColourId, Colours::black);
    m_viewTypeMuteLabel->setColour (TextEditor::textColourId, Colours::black);
    m_viewTypeMuteLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_viewTypeToggleSysEx = new BlackToggle());
    addAndMakeVisible (m_viewTypeSysExLabel = new Label ("viewTypeSysExLabel",
                                                         TRANS("SYSEX")));
    m_viewTypeSysExLabel->setFont (Font (12.00f, Font::bold));
    m_viewTypeSysExLabel->setJustificationType (Justification::centredRight);
    m_viewTypeSysExLabel->setEditable (false, false, false);
    m_viewTypeSysExLabel->setColour (Label::textColourId, Colours::black);
    m_viewTypeSysExLabel->setColour (TextEditor::textColourId, Colours::black);
    m_viewTypeSysExLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_toLabel = new Label ("toLabel",
                                              TRANS("TO")));
    m_toLabel->setFont (Font (12.00f, Font::bold));
    m_toLabel->setJustificationType (Justification::centredRight);
    m_toLabel->setEditable (false, false, false);
    m_toLabel->setColour (TextEditor::textColourId, Colours::black);
    m_toLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_fromLabel2 = new Label ("fromLabel",
                                                 TRANS("FROM")));
    m_fromLabel2->setFont (Font (12.00f, Font::bold));
    m_fromLabel2->setJustificationType (Justification::centredRight);
    m_fromLabel2->setEditable (false, false, false);
    m_fromLabel2->setColour (TextEditor::textColourId, Colours::black);
    m_fromLabel2->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_toLabel2 = new Label ("toLabel",
                                               TRANS("TO")));
    m_toLabel2->setFont (Font (12.00f, Font::bold));
    m_toLabel2->setJustificationType (Justification::centredRight);
    m_toLabel2->setEditable (false, false, false);
    m_toLabel2->setColour (TextEditor::textColourId, Colours::black);
    m_toLabel2->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_fromLabel3 = new Label ("fromLabel",
                                                 TRANS("FROM")));
    m_fromLabel3->setFont (Font (12.00f, Font::bold));
    m_fromLabel3->setJustificationType (Justification::centredRight);
    m_fromLabel3->setEditable (false, false, false);
    m_fromLabel3->setColour (TextEditor::textColourId, Colours::black);
    m_fromLabel3->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_toLabel3 = new Label ("toLabel",
                                               TRANS("TO")));
    m_toLabel3->setFont (Font (12.00f, Font::bold));
    m_toLabel3->setJustificationType (Justification::centredRight);
    m_toLabel3->setEditable (false, false, false);
    m_toLabel3->setColour (TextEditor::textColourId, Colours::black);
    m_toLabel3->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_viewPartToggle7 = new BlackToggle());
    addAndMakeVisible (m_viewPartLabel7 = new Label ("viewPartLabel7",
                                                     TRANS("7")));
    m_viewPartLabel7->setFont (Font (12.00f, Font::bold));
    m_viewPartLabel7->setJustificationType (Justification::centredRight);
    m_viewPartLabel7->setEditable (false, false, false);
    m_viewPartLabel7->setColour (Label::textColourId, Colours::black);
    m_viewPartLabel7->setColour (TextEditor::textColourId, Colours::black);
    m_viewPartLabel7->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_viewAllPartsButton = new TextButton ("viewAllPartsButton"));
    m_viewAllPartsButton->setButtonText (TRANS("ALL"));
    m_viewAllPartsButton->addListener (this);

    addAndMakeVisible (m_viewNoPartsButton = new TextButton ("viewNoPartsButton"));
    m_viewNoPartsButton->setButtonText (TRANS("NONE"));
    m_viewNoPartsButton->addListener (this);

    addAndMakeVisible (m_viewAllEventsButton = new TextButton ("viewAllEventsButton"));
    m_viewAllEventsButton->setButtonText (TRANS("ALL"));
    m_viewAllEventsButton->addListener (this);

    addAndMakeVisible (m_viewNoEventsButton = new TextButton ("viewNoEventsButton"));
    m_viewNoEventsButton->setButtonText (TRANS("NONE"));
    m_viewNoEventsButton->addListener (this);


    //[UserPreSize]
	StringArray midiOutNames(MidiOutput::getDevices());
	m_midiOutComboBox->addItemList(MidiOutput::getDevices(), 1);
	m_midiOutComboBox->setTextWhenNothingSelected(midiOutNames[MidiOutput::getDefaultDeviceIndex() + 1]);

	m_patternEventTable->setColour(TableListBox::backgroundColourId, GrooveboxLookAndFeel::Mc307LcdBackground);
	m_patternEventTable->setModel(patternBodyBlock);
	m_patternEventTable->setHeader(m_patternEventTableHeader);
	m_patternEventTable->setHeaderHeight(24);
	changeListenerCallback(patternBodyBlock);
	patternBodyBlock->setTableSelectionMidiOutId( m_midiOutComboBox->getSelectedId() > 0 ? m_midiOutComboBox->getSelectedId() - 1 : -1);

	m_patternEventTable->setColour(TableListBox::outlineColourId, Colours::grey);
    //[/UserPreSize]

    setSize (600, 400);


    //[Constructor] You can add your own custom stuff here..
	m_viewPartToggle1->setParameter(patternBodyBlock->getPatternTableFilterParams()->getParameter(PatternBodyBlock::VirtualPatternTableFilterBlock::ViewPart1));
	m_viewPartToggle2->setParameter(patternBodyBlock->getPatternTableFilterParams()->getParameter(PatternBodyBlock::VirtualPatternTableFilterBlock::ViewPart2));
	m_viewPartToggle3->setParameter(patternBodyBlock->getPatternTableFilterParams()->getParameter(PatternBodyBlock::VirtualPatternTableFilterBlock::ViewPart3));
	m_viewPartToggle4->setParameter(patternBodyBlock->getPatternTableFilterParams()->getParameter(PatternBodyBlock::VirtualPatternTableFilterBlock::ViewPart4));
	m_viewPartToggle5->setParameter(patternBodyBlock->getPatternTableFilterParams()->getParameter(PatternBodyBlock::VirtualPatternTableFilterBlock::ViewPart5));
	m_viewPartToggle6->setParameter(patternBodyBlock->getPatternTableFilterParams()->getParameter(PatternBodyBlock::VirtualPatternTableFilterBlock::ViewPart6));
	m_viewPartToggle7->setParameter(patternBodyBlock->getPatternTableFilterParams()->getParameter(PatternBodyBlock::VirtualPatternTableFilterBlock::ViewPart7));
	m_viewPartToggleR->setParameter(patternBodyBlock->getPatternTableFilterParams()->getParameter(PatternBodyBlock::VirtualPatternTableFilterBlock::ViewPartR));
	m_viewPartToggleMuteCtl->setParameter(patternBodyBlock->getPatternTableFilterParams()->getParameter(PatternBodyBlock::VirtualPatternTableFilterBlock::ViewMuteCtrl));

	m_viewTypeToggleNote->setParameter(patternBodyBlock->getPatternTableFilterParams()->getParameter(0x10));
	m_noteRangeLowerSlider->setParameter(patternBodyBlock->getPatternTableFilterParams()->getParameter(0x11));
	m_noteRangeUpperSlider->setParameter(patternBodyBlock->getPatternTableFilterParams()->getParameter(0x12));
	m_viewTypeTogglePc->setParameter(patternBodyBlock->getPatternTableFilterParams()->getParameter(0x13));
	m_viewTypeToggleCc->setParameter(patternBodyBlock->getPatternTableFilterParams()->getParameter(0x14));
	m_ccRangeLowerSlider->setParameter(patternBodyBlock->getPatternTableFilterParams()->getParameter(0x15));
	m_ccRangeUpperSlider->setParameter(patternBodyBlock->getPatternTableFilterParams()->getParameter(0x16));
	m_viewTypeToggleBend->setParameter(patternBodyBlock->getPatternTableFilterParams()->getParameter(0x17));
	m_viewTypeTogglePAft->setParameter(patternBodyBlock->getPatternTableFilterParams()->getParameter(0x18));
	m_PAftRangeLowerSlider->setParameter(patternBodyBlock->getPatternTableFilterParams()->getParameter(0x19));
	m_PAftRangeUpperSlider->setParameter(patternBodyBlock->getPatternTableFilterParams()->getParameter(0x1A));
	m_viewTypeToggleCAft->setParameter(patternBodyBlock->getPatternTableFilterParams()->getParameter(0x1B));
	m_viewTypeToggleTempo->setParameter(patternBodyBlock->getPatternTableFilterParams()->getParameter(0x1C));
	m_viewTypeToggleMute->setParameter(patternBodyBlock->getPatternTableFilterParams()->getParameter(0x1D));
	m_viewTypeToggleSysEx->setParameter(patternBodyBlock->getPatternTableFilterParams()->getParameter(0x1E));

	patternBodyBlock->refreshFilteredContent();
    //[/Constructor]
}

PatternEditorTab::~PatternEditorTab()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
	grooveboxMemory->getPatternBodyBlock()->removeChangeListener(this);
    //[/Destructor_pre]

    component3 = nullptr;
    component4 = nullptr;
    component2 = nullptr;
    m_midiOutComboBox = nullptr;
    m_midiOutLabel = nullptr;
    m_panicButton = nullptr;
    m_patternEventTable = nullptr;
    m_noteRangeLowerSlider = nullptr;
    m_noteRangeUpperSlider = nullptr;
    m_fromLabel = nullptr;
    m_ccRangeLowerSlider = nullptr;
    m_ccRangeUpperSlider = nullptr;
    m_PAftRangeLowerSlider = nullptr;
    m_PAftRangeUpperSlider = nullptr;
    m_viewPartToggleR = nullptr;
    m_viewPartLabelR = nullptr;
    m_viewPartToggle1 = nullptr;
    m_viewPartLabel1 = nullptr;
    m_viewPartToggle2 = nullptr;
    m_viewPartLabel2 = nullptr;
    m_viewPartToggle3 = nullptr;
    m_viewPartLabel3 = nullptr;
    m_viewPartToggle4 = nullptr;
    m_viewPartLabel4 = nullptr;
    m_viewPartToggle5 = nullptr;
    m_viewPartLabel5 = nullptr;
    m_viewPartToggle6 = nullptr;
    m_viewPartLabel6 = nullptr;
    m_viewPartToggleMuteCtl = nullptr;
    m_viewPartLabelMuteCtl = nullptr;
    m_viewPartsLabel = nullptr;
    m_viewEventsLabel2 = nullptr;
    m_viewTypeToggleNote = nullptr;
    m_viewTypeNoteLabel = nullptr;
    m_viewTypeTogglePc = nullptr;
    m_viewTypePcLabel = nullptr;
    m_viewTypeToggleCc = nullptr;
    m_viewTypeCcLabel = nullptr;
    m_viewTypeToggleBend = nullptr;
    m_viewTypeBendLabel = nullptr;
    m_viewTypeTogglePAft = nullptr;
    m_viewTypePAftLabel = nullptr;
    m_viewTypeToggleCAft = nullptr;
    m_viewTypeCAftLabel = nullptr;
    m_viewTypeToggleTempo = nullptr;
    m_viewTypeTempoLabel = nullptr;
    m_viewTypeToggleMute = nullptr;
    m_viewTypeMuteLabel = nullptr;
    m_viewTypeToggleSysEx = nullptr;
    m_viewTypeSysExLabel = nullptr;
    m_toLabel = nullptr;
    m_fromLabel2 = nullptr;
    m_toLabel2 = nullptr;
    m_fromLabel3 = nullptr;
    m_toLabel3 = nullptr;
    m_viewPartToggle7 = nullptr;
    m_viewPartLabel7 = nullptr;
    m_viewAllPartsButton = nullptr;
    m_viewNoPartsButton = nullptr;
    m_viewAllEventsButton = nullptr;
    m_viewNoEventsButton = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void PatternEditorTab::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
#if JUCE_MSVC
	g;
#endif
    //[/UserPrePaint]

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void PatternEditorTab::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    component3->setBounds (0, 0, getWidth() - 0, getHeight() - 0);
    component4->setBounds (8, 72, 708, 80);
    component2->setBounds (8, 36, 708, 32);
    m_midiOutComboBox->setBounds (112, 8, 176, 20);
    m_midiOutLabel->setBounds (8, 8, 88, 20);
    m_panicButton->setBounds (296, 8, 150, 20);
    m_patternEventTable->setBounds (8, 160, 708, getHeight() - 168);
    m_noteRangeLowerSlider->setBounds (124, 104, 48, 16);
    m_noteRangeUpperSlider->setBounds (124, 128, 48, 16);
    m_fromLabel->setBounds (80, 104, 44, 16);
    m_ccRangeLowerSlider->setBounds (244, 104, 40, 16);
    m_ccRangeUpperSlider->setBounds (244, 128, 40, 16);
    m_PAftRangeLowerSlider->setBounds (372, 104, 48, 16);
    m_PAftRangeUpperSlider->setBounds (372, 128, 48, 16);
    m_viewPartToggleR->setBounds (112, 44, 25, 17);
    m_viewPartLabelR->setBounds (92, 44, 20, 16);
    m_viewPartToggle1->setBounds (160, 44, 25, 17);
    m_viewPartLabel1->setBounds (140, 44, 20, 16);
    m_viewPartToggle2->setBounds (208, 44, 25, 17);
    m_viewPartLabel2->setBounds (188, 44, 20, 16);
    m_viewPartToggle3->setBounds (256, 44, 25, 17);
    m_viewPartLabel3->setBounds (236, 44, 20, 16);
    m_viewPartToggle4->setBounds (304, 44, 25, 17);
    m_viewPartLabel4->setBounds (284, 44, 20, 16);
    m_viewPartToggle5->setBounds (352, 44, 25, 17);
    m_viewPartLabel5->setBounds (332, 44, 20, 16);
    m_viewPartToggle6->setBounds (400, 44, 25, 17);
    m_viewPartLabel6->setBounds (380, 44, 20, 16);
    m_viewPartToggleMuteCtl->setBounds (540, 44, 25, 17);
    m_viewPartLabelMuteCtl->setBounds (476, 44, 66, 16);
    m_viewPartsLabel->setBounds (12, 44, 84, 16);
    m_viewEventsLabel2->setBounds (12, 80, 92, 16);
    m_viewTypeToggleNote->setBounds (144, 80, 25, 17);
    m_viewTypeNoteLabel->setBounds (104, 80, 40, 16);
    m_viewTypeTogglePc->setBounds (200, 80, 25, 17);
    m_viewTypePcLabel->setBounds (176, 80, 24, 16);
    m_viewTypeToggleCc->setBounds (256, 80, 25, 17);
    m_viewTypeCcLabel->setBounds (232, 80, 24, 16);
    m_viewTypeToggleBend->setBounds (320, 80, 25, 17);
    m_viewTypeBendLabel->setBounds (280, 80, 42, 16);
    m_viewTypeTogglePAft->setBounds (392, 80, 25, 17);
    m_viewTypePAftLabel->setBounds (348, 80, 44, 16);
    m_viewTypeToggleCAft->setBounds (464, 80, 25, 17);
    m_viewTypeCAftLabel->setBounds (420, 80, 44, 16);
    m_viewTypeToggleTempo->setBounds (540, 80, 25, 17);
    m_viewTypeTempoLabel->setBounds (492, 80, 50, 16);
    m_viewTypeToggleMute->setBounds (540, 104, 25, 17);
    m_viewTypeMuteLabel->setBounds (492, 104, 50, 16);
    m_viewTypeToggleSysEx->setBounds (540, 128, 25, 17);
    m_viewTypeSysExLabel->setBounds (492, 128, 50, 16);
    m_toLabel->setBounds (80, 128, 44, 16);
    m_fromLabel2->setBounds (200, 104, 44, 16);
    m_toLabel2->setBounds (200, 128, 44, 16);
    m_fromLabel3->setBounds (328, 105, 44, 16);
    m_toLabel3->setBounds (328, 128, 44, 16);
    m_viewPartToggle7->setBounds (448, 44, 25, 17);
    m_viewPartLabel7->setBounds (428, 44, 20, 16);
    m_viewAllPartsButton->setBounds (604, 40, 52, 24);
    m_viewNoPartsButton->setBounds (660, 40, 52, 24);
    m_viewAllEventsButton->setBounds (604, 100, 52, 24);
    m_viewNoEventsButton->setBounds (660, 100, 52, 24);
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void PatternEditorTab::comboBoxChanged (ComboBox* comboBoxThatHasChanged)
{
    //[UsercomboBoxChanged_Pre]
    //[/UsercomboBoxChanged_Pre]

    if (comboBoxThatHasChanged == m_midiOutComboBox)
    {
        //[UserComboBoxCode_m_midiOutComboBox] -- add your combo box handling code here..
		grooveboxMemory->getPatternBodyBlock()->setTableSelectionMidiOutId(
			m_midiOutComboBox->getSelectedId() > 0 ?
			m_midiOutComboBox->getSelectedId() - 1 :
			-1);
        //[/UserComboBoxCode_m_midiOutComboBox]
    }

    //[UsercomboBoxChanged_Post]
    //[/UsercomboBoxChanged_Post]
}

void PatternEditorTab::buttonClicked (Button* buttonThatWasClicked)
{
    //[UserbuttonClicked_Pre]
	PatternBodyBlock* patternBodyBlock = grooveboxMemory->getPatternBodyBlock();
    //[/UserbuttonClicked_Pre]

    if (buttonThatWasClicked == m_panicButton)
    {
        //[UserButtonCode_m_panicButton] -- add your button handler code here..
		if (MidiOutput* midiOut = grooveboxMemory->getPatternBodyBlock()->getOpenTableSelectionMidiOut())
		{
			for (int i = 1; i < 17; i++)
			{
				midiOut->sendMessageNow(MidiMessage::allNotesOff(i));
				midiOut->sendMessageNow(MidiMessage::allSoundOff(i));
			}
		}
        //[/UserButtonCode_m_panicButton]
    }
    else if (buttonThatWasClicked == m_viewAllPartsButton)
    {
        //[UserButtonCode_m_viewAllPartsButton] -- add your button handler code here..
		m_viewNoPartsButton->setToggleState(false, dontSendNotification);
		m_viewAllPartsButton->setToggleState(false, dontSendNotification);
		patternBodyBlock->getPatternTableFilterParams()->getParameter(PatternBodyBlock::VirtualPatternTableFilterBlock::ViewPart1)->setValue(1, Parameter::GuiWidget);
		patternBodyBlock->getPatternTableFilterParams()->getParameter(PatternBodyBlock::VirtualPatternTableFilterBlock::ViewPart2)->setValue(1, Parameter::GuiWidget);
		patternBodyBlock->getPatternTableFilterParams()->getParameter(PatternBodyBlock::VirtualPatternTableFilterBlock::ViewPart3)->setValue(1, Parameter::GuiWidget);
		patternBodyBlock->getPatternTableFilterParams()->getParameter(PatternBodyBlock::VirtualPatternTableFilterBlock::ViewPart4)->setValue(1, Parameter::GuiWidget);
		patternBodyBlock->getPatternTableFilterParams()->getParameter(PatternBodyBlock::VirtualPatternTableFilterBlock::ViewPart5)->setValue(1, Parameter::GuiWidget);
		patternBodyBlock->getPatternTableFilterParams()->getParameter(PatternBodyBlock::VirtualPatternTableFilterBlock::ViewPart6)->setValue(1, Parameter::GuiWidget);
		patternBodyBlock->getPatternTableFilterParams()->getParameter(PatternBodyBlock::VirtualPatternTableFilterBlock::ViewPart7)->setValue(1, Parameter::GuiWidget);
		patternBodyBlock->getPatternTableFilterParams()->getParameter(PatternBodyBlock::VirtualPatternTableFilterBlock::ViewPartR)->setValue(1, Parameter::GuiWidget);
		patternBodyBlock->getPatternTableFilterParams()->getParameter(PatternBodyBlock::VirtualPatternTableFilterBlock::ViewMuteCtrl)->setValue(1, Parameter::GuiWidget);

		patternBodyBlock->refreshFilteredContent();
        //[/UserButtonCode_m_viewAllPartsButton]
    }
    else if (buttonThatWasClicked == m_viewNoPartsButton)
    {
        //[UserButtonCode_m_viewNoPartsButton] -- add your button handler code here..
		m_viewAllPartsButton->setToggleState(false, dontSendNotification);
		m_viewNoPartsButton->setToggleState(false, dontSendNotification);
		patternBodyBlock->getPatternTableFilterParams()->getParameter(PatternBodyBlock::VirtualPatternTableFilterBlock::ViewPart1)->setValue(0, Parameter::GuiWidget);
		patternBodyBlock->getPatternTableFilterParams()->getParameter(PatternBodyBlock::VirtualPatternTableFilterBlock::ViewPart2)->setValue(0, Parameter::GuiWidget);
		patternBodyBlock->getPatternTableFilterParams()->getParameter(PatternBodyBlock::VirtualPatternTableFilterBlock::ViewPart3)->setValue(0, Parameter::GuiWidget);
		patternBodyBlock->getPatternTableFilterParams()->getParameter(PatternBodyBlock::VirtualPatternTableFilterBlock::ViewPart4)->setValue(0, Parameter::GuiWidget);
		patternBodyBlock->getPatternTableFilterParams()->getParameter(PatternBodyBlock::VirtualPatternTableFilterBlock::ViewPart5)->setValue(0, Parameter::GuiWidget);
		patternBodyBlock->getPatternTableFilterParams()->getParameter(PatternBodyBlock::VirtualPatternTableFilterBlock::ViewPart6)->setValue(0, Parameter::GuiWidget);
		patternBodyBlock->getPatternTableFilterParams()->getParameter(PatternBodyBlock::VirtualPatternTableFilterBlock::ViewPart7)->setValue(0, Parameter::GuiWidget);
		patternBodyBlock->getPatternTableFilterParams()->getParameter(PatternBodyBlock::VirtualPatternTableFilterBlock::ViewPartR)->setValue(0, Parameter::GuiWidget);
		patternBodyBlock->getPatternTableFilterParams()->getParameter(PatternBodyBlock::VirtualPatternTableFilterBlock::ViewMuteCtrl)->setValue(0, Parameter::GuiWidget);

		patternBodyBlock->refreshFilteredContent();
        //[/UserButtonCode_m_viewNoPartsButton]
    }
    else if (buttonThatWasClicked == m_viewAllEventsButton)
    {
        //[UserButtonCode_m_viewAllEventsButton] -- add your button handler code here..
		patternBodyBlock->getPatternTableFilterParams()->getParameter(PatternBodyBlock::VirtualPatternTableFilterBlock::ViewNotes)->setValue(1, Parameter::GuiWidget);
		patternBodyBlock->getPatternTableFilterParams()->getParameter(PatternBodyBlock::VirtualPatternTableFilterBlock::ViewNotesMin)->setValue(0, Parameter::GuiWidget);
		patternBodyBlock->getPatternTableFilterParams()->getParameter(PatternBodyBlock::VirtualPatternTableFilterBlock::ViewNotesMax)->setValue(127, Parameter::GuiWidget);
		patternBodyBlock->getPatternTableFilterParams()->getParameter(PatternBodyBlock::VirtualPatternTableFilterBlock::ViewPC)->setValue(1, Parameter::GuiWidget);
		patternBodyBlock->getPatternTableFilterParams()->getParameter(PatternBodyBlock::VirtualPatternTableFilterBlock::ViewCC)->setValue(1, Parameter::GuiWidget);
		patternBodyBlock->getPatternTableFilterParams()->getParameter(PatternBodyBlock::VirtualPatternTableFilterBlock::ViewCCMin)->setValue(0, Parameter::GuiWidget);
		patternBodyBlock->getPatternTableFilterParams()->getParameter(PatternBodyBlock::VirtualPatternTableFilterBlock::ViewCCMax)->setValue(127, Parameter::GuiWidget);
		patternBodyBlock->getPatternTableFilterParams()->getParameter(PatternBodyBlock::VirtualPatternTableFilterBlock::ViewBend)->setValue(1, Parameter::GuiWidget);
		patternBodyBlock->getPatternTableFilterParams()->getParameter(PatternBodyBlock::VirtualPatternTableFilterBlock::ViewPAft)->setValue(1, Parameter::GuiWidget);
		patternBodyBlock->getPatternTableFilterParams()->getParameter(PatternBodyBlock::VirtualPatternTableFilterBlock::ViewPAftMin)->setValue(0, Parameter::GuiWidget);
		patternBodyBlock->getPatternTableFilterParams()->getParameter(PatternBodyBlock::VirtualPatternTableFilterBlock::ViewPAftMax)->setValue(127, Parameter::GuiWidget);
		patternBodyBlock->getPatternTableFilterParams()->getParameter(PatternBodyBlock::VirtualPatternTableFilterBlock::ViewCAft)->setValue(1, Parameter::GuiWidget);
		patternBodyBlock->getPatternTableFilterParams()->getParameter(PatternBodyBlock::VirtualPatternTableFilterBlock::ViewTempo)->setValue(1, Parameter::GuiWidget);
		patternBodyBlock->getPatternTableFilterParams()->getParameter(PatternBodyBlock::VirtualPatternTableFilterBlock::ViewMute)->setValue(1, Parameter::GuiWidget);
		patternBodyBlock->getPatternTableFilterParams()->getParameter(PatternBodyBlock::VirtualPatternTableFilterBlock::ViewSysEx)->setValue(1, Parameter::GuiWidget);

		patternBodyBlock->refreshFilteredContent();
        //[/UserButtonCode_m_viewAllEventsButton]
    }
    else if (buttonThatWasClicked == m_viewNoEventsButton)
    {
        //[UserButtonCode_m_viewNoEventsButton] -- add your button handler code here..
		patternBodyBlock->getPatternTableFilterParams()->getParameter(PatternBodyBlock::VirtualPatternTableFilterBlock::ViewNotes)->setValue(0, Parameter::GuiWidget);
		patternBodyBlock->getPatternTableFilterParams()->getParameter(PatternBodyBlock::VirtualPatternTableFilterBlock::ViewPC)->setValue(0, Parameter::GuiWidget);
		patternBodyBlock->getPatternTableFilterParams()->getParameter(PatternBodyBlock::VirtualPatternTableFilterBlock::ViewCC)->setValue(0, Parameter::GuiWidget);
		patternBodyBlock->getPatternTableFilterParams()->getParameter(PatternBodyBlock::VirtualPatternTableFilterBlock::ViewBend)->setValue(0, Parameter::GuiWidget);
		patternBodyBlock->getPatternTableFilterParams()->getParameter(PatternBodyBlock::VirtualPatternTableFilterBlock::ViewPAft)->setValue(0, Parameter::GuiWidget);
		patternBodyBlock->getPatternTableFilterParams()->getParameter(PatternBodyBlock::VirtualPatternTableFilterBlock::ViewCAft)->setValue(0, Parameter::GuiWidget);
		patternBodyBlock->getPatternTableFilterParams()->getParameter(PatternBodyBlock::VirtualPatternTableFilterBlock::ViewTempo)->setValue(0, Parameter::GuiWidget);
		patternBodyBlock->getPatternTableFilterParams()->getParameter(PatternBodyBlock::VirtualPatternTableFilterBlock::ViewMute)->setValue(0, Parameter::GuiWidget);
		patternBodyBlock->getPatternTableFilterParams()->getParameter(PatternBodyBlock::VirtualPatternTableFilterBlock::ViewSysEx)->setValue(0, Parameter::GuiWidget);

		patternBodyBlock->refreshFilteredContent();
        //[/UserButtonCode_m_viewNoEventsButton]
    }

    //[UserbuttonClicked_Post]
    //[/UserbuttonClicked_Post]
}

void PatternEditorTab::sliderValueChanged (Slider* sliderThatWasMoved)
{
    //[UsersliderValueChanged_Pre]
	PatternBodyBlock* patternBodyBlock = grooveboxMemory->getPatternBodyBlock();
    //[/UsersliderValueChanged_Pre]

    if (sliderThatWasMoved == m_noteRangeLowerSlider)
    {
        //[UserSliderCode_m_noteRangeLowerSlider] -- add your slider handling code here..
        //[/UserSliderCode_m_noteRangeLowerSlider]
    }
    else if (sliderThatWasMoved == m_noteRangeUpperSlider)
    {
        //[UserSliderCode_m_noteRangeUpperSlider] -- add your slider handling code here..
        //[/UserSliderCode_m_noteRangeUpperSlider]
    }
    else if (sliderThatWasMoved == m_ccRangeLowerSlider)
    {
        //[UserSliderCode_m_ccRangeLowerSlider] -- add your slider handling code here..
        //[/UserSliderCode_m_ccRangeLowerSlider]
    }
    else if (sliderThatWasMoved == m_ccRangeUpperSlider)
    {
        //[UserSliderCode_m_ccRangeUpperSlider] -- add your slider handling code here..
        //[/UserSliderCode_m_ccRangeUpperSlider]
    }
    else if (sliderThatWasMoved == m_PAftRangeLowerSlider)
    {
        //[UserSliderCode_m_PAftRangeLowerSlider] -- add your slider handling code here..
        //[/UserSliderCode_m_PAftRangeLowerSlider]
    }
    else if (sliderThatWasMoved == m_PAftRangeUpperSlider)
    {
        //[UserSliderCode_m_PAftRangeUpperSlider] -- add your slider handling code here..
        //[/UserSliderCode_m_PAftRangeUpperSlider]
    }

    //[UsersliderValueChanged_Post]
    //[/UsersliderValueChanged_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
void PatternEditorTab::changeListenerCallback (ChangeBroadcaster *source)
{
	if (source == grooveboxMemory->getPatternBodyBlock())
	{
		m_patternEventTable->updateContent();
	}
}

//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Introjucer information section --

    This is where the Introjucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="PatternEditorTab" componentName=""
                 parentClasses="public Component, public ChangeListener" constructorParams=""
                 variableInitialisers="" snapPixels="4" snapActive="1" snapShown="1"
                 overlayOpacity="0.330" fixedSize="0" initialWidth="600" initialHeight="400">
  <BACKGROUND backgroundColour="0"/>
  <JUCERCOMP name="" id="650b65151c744492" memberName="component3" virtualName=""
             explicitFocusOrder="0" pos="0 0 0M 0M" sourceFile="GroupWidgets/RectangleDark.cpp"
             constructorParams=""/>
  <JUCERCOMP name="" id="40ad76072b7c1e81" memberName="component4" virtualName=""
             explicitFocusOrder="0" pos="8 72 708 80" sourceFile="GroupWidgets/RectangleGrey.cpp"
             constructorParams=""/>
  <JUCERCOMP name="" id="aea56bab81242760" memberName="component2" virtualName=""
             explicitFocusOrder="0" pos="8 36 708 32" sourceFile="GroupWidgets/RectangleGrey.cpp"
             constructorParams=""/>
  <COMBOBOX name="midiOutComboBox" id="9b6d2ada3deafb58" memberName="m_midiOutComboBox"
            virtualName="" explicitFocusOrder="0" pos="112 8 176 20" editable="0"
            layout="33" items="" textWhenNonSelected="" textWhenNoItems="(no choices)"/>
  <LABEL name="midiOutLabel" id="b10a8e943634f13a" memberName="m_midiOutLabel"
         virtualName="" explicitFocusOrder="0" pos="8 8 88 20" textCol="ffffffff"
         edTextCol="ff000000" edBkgCol="0" labelText="MIDI OUT:" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="12" bold="1" italic="0" justification="34"/>
  <TEXTBUTTON name="panicButton" id="7514cd2cffbbc78c" memberName="m_panicButton"
              virtualName="" explicitFocusOrder="0" pos="296 8 150 20" buttonText="MIDI Panic!"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <GENERICCOMPONENT name="" id="6aebf3e3738962bd" memberName="m_patternEventTable"
                    virtualName="" explicitFocusOrder="0" pos="8 160 708 168M" class="TableListBox"
                    params="&quot;patternEventTable&quot;"/>
  <SLIDER name="noteRangeLowerSlider" id="b9d1900a1c3c44f7" memberName="m_noteRangeLowerSlider"
          virtualName="MicroParameterSlider" explicitFocusOrder="0" pos="124 104 48 16"
          bkgcol="fff2f59b" thumbcol="ffc4c86d" min="0" max="127" int="1"
          style="LinearBar" textBoxPos="TextBoxLeft" textBoxEditable="1"
          textBoxWidth="40" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="noteRangeUpperSlider" id="b55b7c90bb48008" memberName="m_noteRangeUpperSlider"
          virtualName="MicroParameterSlider" explicitFocusOrder="0" pos="124 128 48 16"
          bkgcol="fff2f59b" thumbcol="ffc4c86d" min="0" max="127" int="1"
          style="LinearBar" textBoxPos="TextBoxLeft" textBoxEditable="1"
          textBoxWidth="40" textBoxHeight="20" skewFactor="1"/>
  <LABEL name="fromLabel" id="9056d8c316152585" memberName="m_fromLabel"
         virtualName="" explicitFocusOrder="0" pos="80 104 44 16" edTextCol="ff000000"
         edBkgCol="0" labelText="FROM" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="12"
         bold="1" italic="0" justification="34"/>
  <SLIDER name="ccRangeLowerSlider" id="6eb2fec2472bcf65" memberName="m_ccRangeLowerSlider"
          virtualName="MicroParameterSlider" explicitFocusOrder="0" pos="244 104 40 16"
          bkgcol="fff2f59b" thumbcol="ffc4c86d" min="0" max="127" int="1"
          style="LinearBar" textBoxPos="TextBoxLeft" textBoxEditable="1"
          textBoxWidth="40" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="ccRangeUpperSlider" id="577e76cd8daa1c7" memberName="m_ccRangeUpperSlider"
          virtualName="MicroParameterSlider" explicitFocusOrder="0" pos="244 128 40 16"
          bkgcol="fff2f59b" thumbcol="ffc4c86d" min="0" max="127" int="1"
          style="LinearBar" textBoxPos="TextBoxLeft" textBoxEditable="1"
          textBoxWidth="40" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="PAftRangeLowerSlider" id="45a06c5048ed35ff" memberName="m_PAftRangeLowerSlider"
          virtualName="MicroParameterSlider" explicitFocusOrder="0" pos="372 104 48 16"
          bkgcol="fff2f59b" thumbcol="ffc4c86d" min="0" max="127" int="1"
          style="LinearBar" textBoxPos="TextBoxLeft" textBoxEditable="1"
          textBoxWidth="40" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="PAftRangeUpperSlider" id="797d73fef2e299f5" memberName="m_PAftRangeUpperSlider"
          virtualName="MicroParameterSlider" explicitFocusOrder="0" pos="372 128 48 16"
          bkgcol="fff2f59b" thumbcol="ffc4c86d" min="0" max="127" int="1"
          style="LinearBar" textBoxPos="TextBoxLeft" textBoxEditable="1"
          textBoxWidth="40" textBoxHeight="20" skewFactor="1"/>
  <JUCERCOMP name="viewPartToggleR" id="1d7902cb6f52a8a2" memberName="m_viewPartToggleR"
             virtualName="" explicitFocusOrder="0" pos="112 44 25 17" sourceFile="ParameterWidgets/BlackToggle.cpp"
             constructorParams=""/>
  <LABEL name="viewPartLabelR" id="bc5132eee7a0ee16" memberName="m_viewPartLabelR"
         virtualName="" explicitFocusOrder="0" pos="92 44 20 16" textCol="ff000000"
         edTextCol="ff000000" edBkgCol="0" labelText="R" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="12" bold="1" italic="0" justification="34"/>
  <JUCERCOMP name="viewPartToggle1" id="a18931839c0b8bc7" memberName="m_viewPartToggle1"
             virtualName="" explicitFocusOrder="0" pos="160 44 25 17" sourceFile="ParameterWidgets/BlackToggle.cpp"
             constructorParams=""/>
  <LABEL name="viewPartLabel1" id="ad4994c83a8227fe" memberName="m_viewPartLabel1"
         virtualName="" explicitFocusOrder="0" pos="140 44 20 16" textCol="ff000000"
         edTextCol="ff000000" edBkgCol="0" labelText="1" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="12" bold="1" italic="0" justification="34"/>
  <JUCERCOMP name="viewPartToggle2" id="cc67029767436e76" memberName="m_viewPartToggle2"
             virtualName="" explicitFocusOrder="0" pos="208 44 25 17" sourceFile="ParameterWidgets/BlackToggle.cpp"
             constructorParams=""/>
  <LABEL name="viewPartLabel2" id="40f4c0d942746fc2" memberName="m_viewPartLabel2"
         virtualName="" explicitFocusOrder="0" pos="188 44 20 16" textCol="ff000000"
         edTextCol="ff000000" edBkgCol="0" labelText="2" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="12" bold="1" italic="0" justification="34"/>
  <JUCERCOMP name="viewPartToggle3" id="f1d2259f5fdc632a" memberName="m_viewPartToggle3"
             virtualName="" explicitFocusOrder="0" pos="256 44 25 17" sourceFile="ParameterWidgets/BlackToggle.cpp"
             constructorParams=""/>
  <LABEL name="viewPartLabel3" id="c00f1c442319a709" memberName="m_viewPartLabel3"
         virtualName="" explicitFocusOrder="0" pos="236 44 20 16" textCol="ff000000"
         edTextCol="ff000000" edBkgCol="0" labelText="3" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="12" bold="1" italic="0" justification="34"/>
  <JUCERCOMP name="viewPartToggle4" id="19611dc9b01f2f43" memberName="m_viewPartToggle4"
             virtualName="" explicitFocusOrder="0" pos="304 44 25 17" sourceFile="ParameterWidgets/BlackToggle.cpp"
             constructorParams=""/>
  <LABEL name="viewPartLabel4" id="b2bba0a8be3d9218" memberName="m_viewPartLabel4"
         virtualName="" explicitFocusOrder="0" pos="284 44 20 16" textCol="ff000000"
         edTextCol="ff000000" edBkgCol="0" labelText="4" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="12" bold="1" italic="0" justification="34"/>
  <JUCERCOMP name="viewPartToggle5" id="78c5acd471a43391" memberName="m_viewPartToggle5"
             virtualName="" explicitFocusOrder="0" pos="352 44 25 17" sourceFile="ParameterWidgets/BlackToggle.cpp"
             constructorParams=""/>
  <LABEL name="viewPartLabel5" id="625a82943feb34fc" memberName="m_viewPartLabel5"
         virtualName="" explicitFocusOrder="0" pos="332 44 20 16" textCol="ff000000"
         edTextCol="ff000000" edBkgCol="0" labelText="5" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="12" bold="1" italic="0" justification="34"/>
  <JUCERCOMP name="viewPartToggle6" id="83663b51ab2a6441" memberName="m_viewPartToggle6"
             virtualName="" explicitFocusOrder="0" pos="400 44 25 17" sourceFile="ParameterWidgets/BlackToggle.cpp"
             constructorParams=""/>
  <LABEL name="viewPartLabel6" id="c5f2bc21f7910cd1" memberName="m_viewPartLabel6"
         virtualName="" explicitFocusOrder="0" pos="380 44 20 16" textCol="ff000000"
         edTextCol="ff000000" edBkgCol="0" labelText="6" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="12" bold="1" italic="0" justification="34"/>
  <JUCERCOMP name="viewPartToggleMuteCtl" id="c2ce082733354a5e" memberName="m_viewPartToggleMuteCtl"
             virtualName="" explicitFocusOrder="0" pos="540 44 25 17" sourceFile="ParameterWidgets/BlackToggle.cpp"
             constructorParams=""/>
  <LABEL name="viewPartLabelMuteCtl" id="ada9c424b62b9157" memberName="m_viewPartLabelMuteCtl"
         virtualName="" explicitFocusOrder="0" pos="476 44 66 16" textCol="ff000000"
         edTextCol="ff000000" edBkgCol="0" labelText="MUTE-CTL" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="12" bold="1" italic="0" justification="34"/>
  <LABEL name="viewPartsLabel" id="e1554e2573094d42" memberName="m_viewPartsLabel"
         virtualName="" explicitFocusOrder="0" pos="12 44 84 16" textCol="ff000000"
         edTextCol="ff000000" edBkgCol="0" labelText="VIEW PARTS:" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="12" bold="1" italic="0" justification="33"/>
  <LABEL name="viewEventsLabel" id="50edf174f403eee6" memberName="m_viewEventsLabel2"
         virtualName="" explicitFocusOrder="0" pos="12 80 92 16" textCol="ff000000"
         edTextCol="ff000000" edBkgCol="0" labelText="VIEW EVENTS:" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="12" bold="1" italic="0" justification="33"/>
  <JUCERCOMP name="viewTypeToggleNote" id="bda56df07703530" memberName="m_viewTypeToggleNote"
             virtualName="" explicitFocusOrder="0" pos="144 80 25 17" sourceFile="ParameterWidgets/BlackToggle.cpp"
             constructorParams=""/>
  <LABEL name="viewTypeNoteLabel" id="dec0e11bd8cac905" memberName="m_viewTypeNoteLabel"
         virtualName="" explicitFocusOrder="0" pos="104 80 40 16" textCol="ff000000"
         edTextCol="ff000000" edBkgCol="0" labelText="NOTE" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="12" bold="1" italic="0" justification="34"/>
  <JUCERCOMP name="viewTypeTogglePc" id="5e31f5d6526d433e" memberName="m_viewTypeTogglePc"
             virtualName="" explicitFocusOrder="0" pos="200 80 25 17" sourceFile="ParameterWidgets/BlackToggle.cpp"
             constructorParams=""/>
  <LABEL name="viewTypePcLabel" id="8351602a43355d7b" memberName="m_viewTypePcLabel"
         virtualName="" explicitFocusOrder="0" pos="176 80 24 16" textCol="ff000000"
         edTextCol="ff000000" edBkgCol="0" labelText="PC" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="12" bold="1" italic="0" justification="34"/>
  <JUCERCOMP name="viewTypeToggleCc" id="39fa258dcb4cb708" memberName="m_viewTypeToggleCc"
             virtualName="" explicitFocusOrder="0" pos="256 80 25 17" sourceFile="ParameterWidgets/BlackToggle.cpp"
             constructorParams=""/>
  <LABEL name="viewTypeCcLabel" id="82515de101e4d876" memberName="m_viewTypeCcLabel"
         virtualName="" explicitFocusOrder="0" pos="232 80 24 16" textCol="ff000000"
         edTextCol="ff000000" edBkgCol="0" labelText="CC" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="12" bold="1" italic="0" justification="34"/>
  <JUCERCOMP name="viewTypeToggleBend" id="36657f8d741a41be" memberName="m_viewTypeToggleBend"
             virtualName="" explicitFocusOrder="0" pos="320 80 25 17" sourceFile="ParameterWidgets/BlackToggle.cpp"
             constructorParams=""/>
  <LABEL name="viewTypeBendLabel" id="ab23ce03c4559ff7" memberName="m_viewTypeBendLabel"
         virtualName="" explicitFocusOrder="0" pos="280 80 42 16" textCol="ff000000"
         edTextCol="ff000000" edBkgCol="0" labelText="BEND" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="12" bold="1" italic="0" justification="34"/>
  <JUCERCOMP name="viewTypeTogglePAft" id="f145639779123e00" memberName="m_viewTypeTogglePAft"
             virtualName="" explicitFocusOrder="0" pos="392 80 25 17" sourceFile="ParameterWidgets/BlackToggle.cpp"
             constructorParams=""/>
  <LABEL name="viewTypePAftLabel" id="22549c0ebb305365" memberName="m_viewTypePAftLabel"
         virtualName="" explicitFocusOrder="0" pos="348 80 44 16" textCol="ff000000"
         edTextCol="ff000000" edBkgCol="0" labelText="P-AFT" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="12" bold="1" italic="0" justification="34"/>
  <JUCERCOMP name="viewTypeToggleCAft" id="8c5125e59845414e" memberName="m_viewTypeToggleCAft"
             virtualName="" explicitFocusOrder="0" pos="464 80 25 17" sourceFile="ParameterWidgets/BlackToggle.cpp"
             constructorParams=""/>
  <LABEL name="viewTypeCAftLabel" id="59ab991b4d754058" memberName="m_viewTypeCAftLabel"
         virtualName="" explicitFocusOrder="0" pos="420 80 44 16" textCol="ff000000"
         edTextCol="ff000000" edBkgCol="0" labelText="C-AFT" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="12" bold="1" italic="0" justification="34"/>
  <JUCERCOMP name="viewTypeToggleTempo" id="83c15bd47e82f57b" memberName="m_viewTypeToggleTempo"
             virtualName="" explicitFocusOrder="0" pos="540 80 25 17" sourceFile="ParameterWidgets/BlackToggle.cpp"
             constructorParams=""/>
  <LABEL name="viewTypeTempoLabel" id="abffb603f4cf52de" memberName="m_viewTypeTempoLabel"
         virtualName="" explicitFocusOrder="0" pos="492 80 50 16" textCol="ff000000"
         edTextCol="ff000000" edBkgCol="0" labelText="TEMPO" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="12" bold="1" italic="0" justification="34"/>
  <JUCERCOMP name="viewTypeToggleMute" id="c215c676900cf2f" memberName="m_viewTypeToggleMute"
             virtualName="" explicitFocusOrder="0" pos="540 104 25 17" sourceFile="ParameterWidgets/BlackToggle.cpp"
             constructorParams=""/>
  <LABEL name="viewTypeMuteLabel" id="3729b7e77e15eff7" memberName="m_viewTypeMuteLabel"
         virtualName="" explicitFocusOrder="0" pos="492 104 50 16" textCol="ff000000"
         edTextCol="ff000000" edBkgCol="0" labelText="MUTE" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="12" bold="1" italic="0" justification="34"/>
  <JUCERCOMP name="viewTypeToggleSysEx" id="48e8fca9153fa018" memberName="m_viewTypeToggleSysEx"
             virtualName="" explicitFocusOrder="0" pos="540 128 25 17" sourceFile="ParameterWidgets/BlackToggle.cpp"
             constructorParams=""/>
  <LABEL name="viewTypeSysExLabel" id="6094cd3de2bc8cd4" memberName="m_viewTypeSysExLabel"
         virtualName="" explicitFocusOrder="0" pos="492 128 50 16" textCol="ff000000"
         edTextCol="ff000000" edBkgCol="0" labelText="SYSEX" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="12" bold="1" italic="0" justification="34"/>
  <LABEL name="toLabel" id="462c369b4cc8d9c9" memberName="m_toLabel" virtualName=""
         explicitFocusOrder="0" pos="80 128 44 16" edTextCol="ff000000"
         edBkgCol="0" labelText="TO" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="12"
         bold="1" italic="0" justification="34"/>
  <LABEL name="fromLabel" id="27791d977542d319" memberName="m_fromLabel2"
         virtualName="" explicitFocusOrder="0" pos="200 104 44 16" edTextCol="ff000000"
         edBkgCol="0" labelText="FROM" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="12"
         bold="1" italic="0" justification="34"/>
  <LABEL name="toLabel" id="efd1bbf0b7ad6fd" memberName="m_toLabel2" virtualName=""
         explicitFocusOrder="0" pos="200 128 44 16" edTextCol="ff000000"
         edBkgCol="0" labelText="TO" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="12"
         bold="1" italic="0" justification="34"/>
  <LABEL name="fromLabel" id="b18cc35b97da47a7" memberName="m_fromLabel3"
         virtualName="" explicitFocusOrder="0" pos="328 105 44 16" edTextCol="ff000000"
         edBkgCol="0" labelText="FROM" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="12"
         bold="1" italic="0" justification="34"/>
  <LABEL name="toLabel" id="d8b71279d35fe3a9" memberName="m_toLabel3"
         virtualName="" explicitFocusOrder="0" pos="328 128 44 16" edTextCol="ff000000"
         edBkgCol="0" labelText="TO" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="12"
         bold="1" italic="0" justification="34"/>
  <JUCERCOMP name="viewPartToggle7" id="dedfac941a8fd441" memberName="m_viewPartToggle7"
             virtualName="" explicitFocusOrder="0" pos="448 44 25 17" sourceFile="ParameterWidgets/BlackToggle.cpp"
             constructorParams=""/>
  <LABEL name="viewPartLabel7" id="1259e0a46cb4feda" memberName="m_viewPartLabel7"
         virtualName="" explicitFocusOrder="0" pos="428 44 20 16" textCol="ff000000"
         edTextCol="ff000000" edBkgCol="0" labelText="7" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="12" bold="1" italic="0" justification="34"/>
  <TEXTBUTTON name="viewAllPartsButton" id="b8166a68e7f63c09" memberName="m_viewAllPartsButton"
              virtualName="" explicitFocusOrder="0" pos="604 40 52 24" buttonText="ALL"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="viewNoPartsButton" id="ad02355735c6a9f1" memberName="m_viewNoPartsButton"
              virtualName="" explicitFocusOrder="0" pos="660 40 52 24" buttonText="NONE"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="viewAllEventsButton" id="51d716105f5b4021" memberName="m_viewAllEventsButton"
              virtualName="" explicitFocusOrder="0" pos="604 100 52 24" buttonText="ALL"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="viewNoEventsButton" id="e2a123523e69342" memberName="m_viewNoEventsButton"
              virtualName="" explicitFocusOrder="0" pos="660 100 52 24" buttonText="NONE"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
