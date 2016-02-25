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
	PatternSetupBlock* patternSetupBlock = grooveboxMemory->getPatternSetupBlock();
	patternBodyBlock->addChangeListener(this);
	m_patternEventTableHeader = new TableHeaderComponent();
	m_patternEventTableHeader->addColumn(PatternBodyBlock::PATTERNTABLE_COLUMN_NAMES_FOR_IDS[PatternBodyBlock::Col_Position], PatternBodyBlock::Col_Position, 70);
	m_patternEventTableHeader->addColumn(PatternBodyBlock::PATTERNTABLE_COLUMN_NAMES_FOR_IDS[PatternBodyBlock::Col_Raw0], PatternBodyBlock::Col_Raw0, 30);
	m_patternEventTableHeader->addColumn(PatternBodyBlock::PATTERNTABLE_COLUMN_NAMES_FOR_IDS[PatternBodyBlock::Col_TicksInc], PatternBodyBlock::Col_TicksInc, 30);
	m_patternEventTableHeader->addColumn(PatternBodyBlock::PATTERNTABLE_COLUMN_NAMES_FOR_IDS[PatternBodyBlock::Col_Raw1], PatternBodyBlock::Col_Raw1, 30);
	m_patternEventTableHeader->addColumn(PatternBodyBlock::PATTERNTABLE_COLUMN_NAMES_FOR_IDS[PatternBodyBlock::Col_EventType], PatternBodyBlock::Col_EventType, 70);
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

    addAndMakeVisible (m_patternPanel = new PanelGroupGrey ("patternPanel", "PATTERN"));
    addAndMakeVisible (m_viewEventTypesPanel = new PanelGroupGrey ("viewEventTypesPanel", "VIEW EVENTS"));
    addAndMakeVisible (m_viewPartsPanel = new PanelGroupGrey ("viewPartsPanel", "VIEW PARTS"));
    addAndMakeVisible (m_midiOutPanel = new PanelGroupGrey ("midiOutPanel", "MIDI OUT"));
    addAndMakeVisible (m_midiOutComboBox = new ParameterComboBox ("midiOutComboBox"));
    m_midiOutComboBox->setEditableText (false);
    m_midiOutComboBox->setJustificationType (Justification::centredLeft);
    m_midiOutComboBox->setTextWhenNothingSelected (String());
    m_midiOutComboBox->setTextWhenNoChoicesAvailable (TRANS("(no choices)"));
    m_midiOutComboBox->addListener (this);

    addAndMakeVisible (m_panicButton = new TextButton ("panicButton"));
    m_panicButton->setButtonText (TRANS("Panic!"));
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
    m_viewPartLabelR->setJustificationType (Justification::centred);
    m_viewPartLabelR->setEditable (false, false, false);
    m_viewPartLabelR->setColour (Label::textColourId, Colours::black);
    m_viewPartLabelR->setColour (TextEditor::textColourId, Colours::black);
    m_viewPartLabelR->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_viewPartToggle1 = new BlackToggle());
    addAndMakeVisible (m_viewPartLabel1 = new Label ("viewPartLabel1",
                                                     TRANS("1")));
    m_viewPartLabel1->setFont (Font (12.00f, Font::bold));
    m_viewPartLabel1->setJustificationType (Justification::centred);
    m_viewPartLabel1->setEditable (false, false, false);
    m_viewPartLabel1->setColour (Label::textColourId, Colours::black);
    m_viewPartLabel1->setColour (TextEditor::textColourId, Colours::black);
    m_viewPartLabel1->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_viewPartToggle2 = new BlackToggle());
    addAndMakeVisible (m_viewPartLabel2 = new Label ("viewPartLabel2",
                                                     TRANS("2")));
    m_viewPartLabel2->setFont (Font (12.00f, Font::bold));
    m_viewPartLabel2->setJustificationType (Justification::centred);
    m_viewPartLabel2->setEditable (false, false, false);
    m_viewPartLabel2->setColour (Label::textColourId, Colours::black);
    m_viewPartLabel2->setColour (TextEditor::textColourId, Colours::black);
    m_viewPartLabel2->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_viewPartToggle3 = new BlackToggle());
    addAndMakeVisible (m_viewPartLabel3 = new Label ("viewPartLabel3",
                                                     TRANS("3")));
    m_viewPartLabel3->setFont (Font (12.00f, Font::bold));
    m_viewPartLabel3->setJustificationType (Justification::centred);
    m_viewPartLabel3->setEditable (false, false, false);
    m_viewPartLabel3->setColour (Label::textColourId, Colours::black);
    m_viewPartLabel3->setColour (TextEditor::textColourId, Colours::black);
    m_viewPartLabel3->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_viewPartToggle4 = new BlackToggle());
    addAndMakeVisible (m_viewPartLabel4 = new Label ("viewPartLabel4",
                                                     TRANS("4")));
    m_viewPartLabel4->setFont (Font (12.00f, Font::bold));
    m_viewPartLabel4->setJustificationType (Justification::centred);
    m_viewPartLabel4->setEditable (false, false, false);
    m_viewPartLabel4->setColour (Label::textColourId, Colours::black);
    m_viewPartLabel4->setColour (TextEditor::textColourId, Colours::black);
    m_viewPartLabel4->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_viewPartToggle5 = new BlackToggle());
    addAndMakeVisible (m_viewPartLabel5 = new Label ("viewPartLabel5",
                                                     TRANS("5")));
    m_viewPartLabel5->setFont (Font (12.00f, Font::bold));
    m_viewPartLabel5->setJustificationType (Justification::centred);
    m_viewPartLabel5->setEditable (false, false, false);
    m_viewPartLabel5->setColour (Label::textColourId, Colours::black);
    m_viewPartLabel5->setColour (TextEditor::textColourId, Colours::black);
    m_viewPartLabel5->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_viewPartToggle6 = new BlackToggle());
    addAndMakeVisible (m_viewPartLabel6 = new Label ("viewPartLabel6",
                                                     TRANS("6")));
    m_viewPartLabel6->setFont (Font (12.00f, Font::bold));
    m_viewPartLabel6->setJustificationType (Justification::centred);
    m_viewPartLabel6->setEditable (false, false, false);
    m_viewPartLabel6->setColour (Label::textColourId, Colours::black);
    m_viewPartLabel6->setColour (TextEditor::textColourId, Colours::black);
    m_viewPartLabel6->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_viewPartToggleMuteCtl = new BlackToggle());
    addAndMakeVisible (m_viewPartLabelMuteCtl = new Label ("viewPartLabelMuteCtl",
                                                           TRANS("MUTE-CTL")));
    m_viewPartLabelMuteCtl->setFont (Font (12.00f, Font::bold));
    m_viewPartLabelMuteCtl->setJustificationType (Justification::centred);
    m_viewPartLabelMuteCtl->setEditable (false, false, false);
    m_viewPartLabelMuteCtl->setColour (Label::textColourId, Colours::black);
    m_viewPartLabelMuteCtl->setColour (TextEditor::textColourId, Colours::black);
    m_viewPartLabelMuteCtl->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

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
    m_viewPartLabel7->setJustificationType (Justification::centred);
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

    addAndMakeVisible (m_viewSinglePartToggle = new SmallGreenToggle());
    addAndMakeVisible (m_viewSinglePartLabel = new Label ("viewSinglePartLabel",
                                                          TRANS("SINGLE")));
    m_viewSinglePartLabel->setFont (Font (12.00f, Font::bold));
    m_viewSinglePartLabel->setJustificationType (Justification::centredRight);
    m_viewSinglePartLabel->setEditable (false, false, false);
    m_viewSinglePartLabel->setColour (Label::textColourId, Colours::black);
    m_viewSinglePartLabel->setColour (TextEditor::textColourId, Colours::black);
    m_viewSinglePartLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_patchNameLabel = new Label ("patchNameLabel",
                                                     TRANS("PATTERN NAME")));
    m_patchNameLabel->setFont (Font (12.00f, Font::bold));
    m_patchNameLabel->setJustificationType (Justification::centred);
    m_patchNameLabel->setEditable (false, false, false);
    m_patchNameLabel->setColour (Label::textColourId, Colours::black);
    m_patchNameLabel->setColour (TextEditor::textColourId, Colours::black);
    m_patchNameLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_patternNameEditor = new ParameterTextEditor ("patternNameEditor"));
    m_patternNameEditor->setMultiLine (false);
    m_patternNameEditor->setReturnKeyStartsNewLine (false);
    m_patternNameEditor->setReadOnly (false);
    m_patternNameEditor->setScrollbarsShown (false);
    m_patternNameEditor->setCaretVisible (true);
    m_patternNameEditor->setPopupMenuEnabled (true);
    m_patternNameEditor->setColour (TextEditor::textColourId, Colours::black);
    m_patternNameEditor->setColour (TextEditor::backgroundColourId, Colour (0xfff2f59b));
    m_patternNameEditor->setColour (TextEditor::outlineColourId, Colours::grey);
    m_patternNameEditor->setText (TRANS("EMPTY PATTERN"));

    addAndMakeVisible (m_keySignatureComboBox = new ParameterComboBox ("keySignatureComboBox"));
    m_keySignatureComboBox->setEditableText (false);
    m_keySignatureComboBox->setJustificationType (Justification::centred);
    m_keySignatureComboBox->setTextWhenNothingSelected (TRANS("4/4"));
    m_keySignatureComboBox->setTextWhenNoChoicesAvailable (TRANS("(no choices)"));
    m_keySignatureComboBox->addItem (TRANS("2/4"), 1);
    m_keySignatureComboBox->addItem (TRANS("3/4"), 2);
    m_keySignatureComboBox->addItem (TRANS("4/4"), 3);
    m_keySignatureComboBox->addItem (TRANS("5/4"), 4);
    m_keySignatureComboBox->addItem (TRANS("6/4"), 5);
    m_keySignatureComboBox->addItem (TRANS("7/4"), 6);
    m_keySignatureComboBox->addItem (TRANS("5/8"), 7);
    m_keySignatureComboBox->addItem (TRANS("6/8"), 8);
    m_keySignatureComboBox->addItem (TRANS("7/8"), 9);
    m_keySignatureComboBox->addItem (TRANS("9/8"), 10);
    m_keySignatureComboBox->addItem (TRANS("12/8"), 11);
    m_keySignatureComboBox->addItem (TRANS("9/16"), 12);
    m_keySignatureComboBox->addItem (TRANS("11/16"), 13);
    m_keySignatureComboBox->addItem (TRANS("13/16"), 14);
    m_keySignatureComboBox->addItem (TRANS("15/16"), 15);
    m_keySignatureComboBox->addItem (TRANS("17/16"), 16);
    m_keySignatureComboBox->addItem (TRANS("19/16"), 17);
    m_keySignatureComboBox->addListener (this);

    addAndMakeVisible (m_timeSignatureLabel = new Label ("timeSignatureLabel",
                                                         TRANS("TIME SIGNATURE")));
    m_timeSignatureLabel->setFont (Font (12.00f, Font::bold));
    m_timeSignatureLabel->setJustificationType (Justification::centred);
    m_timeSignatureLabel->setEditable (false, false, false);
    m_timeSignatureLabel->setColour (Label::textColourId, Colours::black);
    m_timeSignatureLabel->setColour (TextEditor::textColourId, Colours::black);
    m_timeSignatureLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_measuresLabel = new Label ("measuresLabel",
                                                    TRANS("MEASURES")));
    m_measuresLabel->setFont (Font (12.00f, Font::bold));
    m_measuresLabel->setJustificationType (Justification::centred);
    m_measuresLabel->setEditable (false, false, false);
    m_measuresLabel->setColour (Label::textColourId, Colours::black);
    m_measuresLabel->setColour (TextEditor::textColourId, Colours::black);
    m_measuresLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_measuresSlider = new MicroParameterSlider ("measuresSlider"));
    m_measuresSlider->setRange (1, 32, 1);
    m_measuresSlider->setSliderStyle (Slider::LinearBar);
    m_measuresSlider->setTextBoxStyle (Slider::TextBoxLeft, false, 40, 20);
    m_measuresSlider->setColour (Slider::backgroundColourId, Colour (0xfff2f59b));
    m_measuresSlider->setColour (Slider::thumbColourId, Colour (0xffc4c86d));
    m_measuresSlider->addListener (this);

    addAndMakeVisible (m_tempoSlider = new MicroParameterSlider ("tempoSlider"));
    m_tempoSlider->setRange (20, 240, 0.1);
    m_tempoSlider->setSliderStyle (Slider::LinearBar);
    m_tempoSlider->setTextBoxStyle (Slider::TextBoxLeft, false, 40, 20);
    m_tempoSlider->setColour (Slider::backgroundColourId, Colour (0xfff2f59b));
    m_tempoSlider->setColour (Slider::thumbColourId, Colour (0xffc4c86d));
    m_tempoSlider->addListener (this);

    addAndMakeVisible (m_tempoLabel = new Label ("tempoLabel",
                                                 TRANS("TEMPO")));
    m_tempoLabel->setFont (Font (12.00f, Font::bold));
    m_tempoLabel->setJustificationType (Justification::centred);
    m_tempoLabel->setEditable (false, false, false);
    m_tempoLabel->setColour (Label::textColourId, Colours::black);
    m_tempoLabel->setColour (TextEditor::textColourId, Colours::black);
    m_tempoLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_viewTypeNoteOffLabel = new Label ("viewTypeNoteOffLabel",
                                                           TRANS("NOTE-OFF")));
    m_viewTypeNoteOffLabel->setFont (Font (12.00f, Font::bold));
    m_viewTypeNoteOffLabel->setJustificationType (Justification::centredRight);
    m_viewTypeNoteOffLabel->setEditable (false, false, false);
    m_viewTypeNoteOffLabel->setColour (Label::textColourId, Colours::black);
    m_viewTypeNoteOffLabel->setColour (TextEditor::textColourId, Colours::black);
    m_viewTypeNoteOffLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_viewNoteOffToggle = new SmallGreenToggle());
    addAndMakeVisible (m_viewTypeToggleInc = new BlackToggle());
    addAndMakeVisible (m_viewTypeIncLabel = new Label ("viewTypeIncLabel",
                                                       TRANS("INC")));
    m_viewTypeIncLabel->setFont (Font (12.00f, Font::bold));
    m_viewTypeIncLabel->setJustificationType (Justification::centredRight);
    m_viewTypeIncLabel->setEditable (false, false, false);
    m_viewTypeIncLabel->setColour (Label::textColourId, Colours::black);
    m_viewTypeIncLabel->setColour (TextEditor::textColourId, Colours::black);
    m_viewTypeIncLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));


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

	m_viewSinglePartToggle->addListener(this);

	m_patternNameEditor->setParameter1(patternSetupBlock->getPatternSetupConfigBlockPtr()->getParameter(0x00));
	patternSetupBlock->getPatternSetupConfigBlockPtr()->getParameter(0x10)->addChangeListener(this);
	patternSetupBlock->getPatternSetupConfigBlockPtr()->getParameter(0x11)->addChangeListener(this);

	patternSetupBlock->getPatternSetupConfigBlockPtr()->getParameter(0x13)->addChangeListener(this);
	patternSetupBlock->getPatternSetupConfigBlockPtr()->getParameter(0x14)->addChangeListener(this);
	patternSetupBlock->getPatternSetupConfigBlockPtr()->getParameter(0x15)->addChangeListener(this);
	patternSetupBlock->getPatternSetupConfigBlockPtr()->getParameter(0x16)->addChangeListener(this);
	m_tempoSlider->setValue(120.0, dontSendNotification);

	m_measuresSlider->setParameter(patternSetupBlock->getPatternSetupConfigBlockPtr()->getParameter(0x12));

	m_keySignatureComboBox->setSelectedId(3, dontSendNotification);
    //[/UserPreSize]

    setSize (1060, 400);


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

	m_viewSinglePartToggle->setParameter(patternBodyBlock->getPatternTableFilterParams()->getParameter(PatternBodyBlock::VirtualPatternTableFilterBlock::ViewSingeParts));

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
	m_viewNoteOffToggle->setParameter(patternBodyBlock->getPatternTableFilterParams()->getParameter(0x1F));
	m_viewTypeToggleInc->setParameter(patternBodyBlock->getPatternTableFilterParams()->getParameter(0x20));

	patternBodyBlock->refreshFilteredContent();
    //[/Constructor]
}

PatternEditorTab::~PatternEditorTab()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
	grooveboxMemory->getPatternBodyBlock()->removeChangeListener(this);
    //[/Destructor_pre]

    m_patternPanel = nullptr;
    m_viewEventTypesPanel = nullptr;
    m_viewPartsPanel = nullptr;
    m_midiOutPanel = nullptr;
    m_midiOutComboBox = nullptr;
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
    m_viewSinglePartToggle = nullptr;
    m_viewSinglePartLabel = nullptr;
    m_patchNameLabel = nullptr;
    m_patternNameEditor = nullptr;
    m_keySignatureComboBox = nullptr;
    m_timeSignatureLabel = nullptr;
    m_measuresLabel = nullptr;
    m_measuresSlider = nullptr;
    m_tempoSlider = nullptr;
    m_tempoLabel = nullptr;
    m_viewTypeNoteOffLabel = nullptr;
    m_viewNoteOffToggle = nullptr;
    m_viewTypeToggleInc = nullptr;
    m_viewTypeIncLabel = nullptr;


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

    g.fillAll (Colour (0xff303030));

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void PatternEditorTab::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    m_patternPanel->setBounds (4, 4, 716, getHeight() - 8);
    m_viewEventTypesPanel->setBounds (724, 168, 332, 188);
    m_viewPartsPanel->setBounds (724, 64, 332, 100);
    m_midiOutPanel->setBounds (724, 4, 332, 56);
    m_midiOutComboBox->setBounds (732, 24, 256, 22);
    m_panicButton->setBounds (996, 24, 52, 22);
    m_patternEventTable->setBounds (8, 68, 708, getHeight() - 76);
    m_noteRangeLowerSlider->setBounds (848, 188, 48, 16);
    m_noteRangeUpperSlider->setBounds (924, 188, 48, 16);
    m_fromLabel->setBounds (808, 188, 44, 16);
    m_ccRangeLowerSlider->setBounds (848, 216, 48, 16);
    m_ccRangeUpperSlider->setBounds (924, 216, 48, 16);
    m_PAftRangeLowerSlider->setBounds (848, 244, 48, 16);
    m_PAftRangeUpperSlider->setBounds (924, 244, 48, 16);
    m_viewPartToggleR->setBounds (732, 100, 25, 17);
    m_viewPartLabelR->setBounds (732, 84, 25, 16);
    m_viewPartToggle1->setBounds (772, 100, 25, 17);
    m_viewPartLabel1->setBounds (772, 84, 25, 16);
    m_viewPartToggle2->setBounds (804, 100, 25, 17);
    m_viewPartLabel2->setBounds (804, 84, 25, 16);
    m_viewPartToggle3->setBounds (836, 100, 25, 17);
    m_viewPartLabel3->setBounds (836, 84, 25, 16);
    m_viewPartToggle4->setBounds (868, 100, 25, 17);
    m_viewPartLabel4->setBounds (868, 84, 25, 16);
    m_viewPartToggle5->setBounds (900, 100, 25, 17);
    m_viewPartLabel5->setBounds (900, 84, 25, 16);
    m_viewPartToggle6->setBounds (932, 100, 25, 17);
    m_viewPartLabel6->setBounds (932, 84, 25, 16);
    m_viewPartToggleMuteCtl->setBounds (1008, 100, 25, 17);
    m_viewPartLabelMuteCtl->setBounds (990, 84, 66, 16);
    m_viewTypeToggleNote->setBounds (776, 188, 25, 17);
    m_viewTypeNoteLabel->setBounds (732, 188, 44, 16);
    m_viewTypeTogglePc->setBounds (850, 272, 25, 17);
    m_viewTypePcLabel->setBounds (808, 272, 42, 16);
    m_viewTypeToggleCc->setBounds (776, 216, 25, 17);
    m_viewTypeCcLabel->setBounds (732, 216, 44, 16);
    m_viewTypeToggleBend->setBounds (924, 272, 25, 17);
    m_viewTypeBendLabel->setBounds (880, 272, 44, 16);
    m_viewTypeTogglePAft->setBounds (776, 244, 25, 17);
    m_viewTypePAftLabel->setBounds (732, 244, 44, 16);
    m_viewTypeToggleCAft->setBounds (776, 272, 25, 17);
    m_viewTypeCAftLabel->setBounds (730, 272, 46, 16);
    m_viewTypeToggleTempo->setBounds (776, 300, 25, 17);
    m_viewTypeTempoLabel->setBounds (726, 300, 50, 16);
    m_viewTypeToggleMute->setBounds (850, 300, 25, 17);
    m_viewTypeMuteLabel->setBounds (806, 300, 44, 16);
    m_viewTypeToggleSysEx->setBounds (924, 300, 25, 17);
    m_viewTypeSysExLabel->setBounds (874, 300, 50, 16);
    m_toLabel->setBounds (900, 188, 28, 16);
    m_fromLabel2->setBounds (808, 216, 44, 16);
    m_toLabel2->setBounds (900, 216, 28, 16);
    m_fromLabel3->setBounds (808, 245, 44, 16);
    m_toLabel3->setBounds (900, 244, 28, 16);
    m_viewPartToggle7->setBounds (964, 100, 25, 17);
    m_viewPartLabel7->setBounds (964, 84, 25, 16);
    m_viewAllPartsButton->setBounds (936, 136, 52, 20);
    m_viewNoPartsButton->setBounds (996, 136, 52, 20);
    m_viewAllEventsButton->setBounds (936, 328, 52, 20);
    m_viewNoEventsButton->setBounds (996, 328, 52, 20);
    m_viewSinglePartToggle->setBounds (852, 140, 12, 12);
    m_viewSinglePartLabel->setBounds (797, 140, 55, 12);
    m_patchNameLabel->setBounds (12, 24, 128, 16);
    m_patternNameEditor->setBounds (12, 40, 128, 22);
    m_keySignatureComboBox->setBounds (164, 40, 64, 22);
    m_timeSignatureLabel->setBounds (136, 24, 116, 16);
    m_measuresLabel->setBounds (244, 24, 76, 16);
    m_measuresSlider->setBounds (264, 40, 36, 20);
    m_tempoSlider->setBounds (324, 40, 56, 20);
    m_tempoLabel->setBounds (324, 24, 56, 16);
    m_viewTypeNoteOffLabel->setBounds (975, 188, 64, 16);
    m_viewNoteOffToggle->setBounds (1036, 190, 12, 12);
    m_viewTypeToggleInc->setBounds (998, 273, 25, 17);
    m_viewTypeIncLabel->setBounds (966, 272, 32, 16);
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
    else if (comboBoxThatHasChanged == m_keySignatureComboBox)
    {
        //[UserComboBoxCode_m_keySignatureComboBox] -- add your combo box handling code here..
		int selected = m_keySignatureComboBox->getSelectedId();
		if (selected > 0)
		{
			String text = m_keySignatureComboBox->getItemText(m_keySignatureComboBox->getSelectedItemIndex());
			StringArray signatureStrings = StringArray::fromTokens(text, "/", "");
			if (signatureStrings.size() > 1)
			{
				uint8 numerator = (uint8)signatureStrings[0].getIntValue();
				uint8 denominator = (uint8)signatureStrings[1].getIntValue();
				PatternSetupConfigBlock* patternSetupConfigBlock = grooveboxMemory->getPatternSetupBlock()->getPatternSetupConfigBlockPtr();
				patternSetupConfigBlock->setBeatSignature(numerator, denominator);
				grooveboxMemory->getPatternBodyBlock()->setBeatSignature(BeatSignature(numerator, denominator));
			}
		}
        //[/UserComboBoxCode_m_keySignatureComboBox]
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
		m_viewSinglePartToggle->setToggleState(false, sendNotification);

		m_viewNoPartsButton->setToggleState(false, dontSendNotification);
		m_viewAllPartsButton->setToggleState(false, dontSendNotification);
		patternBodyBlock->getPatternTableFilterParams()->getParameter(PatternBodyBlock::VirtualPatternTableFilterBlock::ViewPart1)->setValue(1, Parameter::Init);
		patternBodyBlock->getPatternTableFilterParams()->getParameter(PatternBodyBlock::VirtualPatternTableFilterBlock::ViewPart2)->setValue(1, Parameter::Init);
		patternBodyBlock->getPatternTableFilterParams()->getParameter(PatternBodyBlock::VirtualPatternTableFilterBlock::ViewPart3)->setValue(1, Parameter::Init);
		patternBodyBlock->getPatternTableFilterParams()->getParameter(PatternBodyBlock::VirtualPatternTableFilterBlock::ViewPart4)->setValue(1, Parameter::Init);
		patternBodyBlock->getPatternTableFilterParams()->getParameter(PatternBodyBlock::VirtualPatternTableFilterBlock::ViewPart5)->setValue(1, Parameter::Init);
		patternBodyBlock->getPatternTableFilterParams()->getParameter(PatternBodyBlock::VirtualPatternTableFilterBlock::ViewPart6)->setValue(1, Parameter::Init);
		patternBodyBlock->getPatternTableFilterParams()->getParameter(PatternBodyBlock::VirtualPatternTableFilterBlock::ViewPart7)->setValue(1, Parameter::Init);
		patternBodyBlock->getPatternTableFilterParams()->getParameter(PatternBodyBlock::VirtualPatternTableFilterBlock::ViewPartR)->setValue(1, Parameter::Init);
		patternBodyBlock->getPatternTableFilterParams()->getParameter(PatternBodyBlock::VirtualPatternTableFilterBlock::ViewMuteCtrl)->setValue(1, Parameter::Init);

		patternBodyBlock->refreshFilteredContent();
        //[/UserButtonCode_m_viewAllPartsButton]
    }
    else if (buttonThatWasClicked == m_viewNoPartsButton)
    {
        //[UserButtonCode_m_viewNoPartsButton] -- add your button handler code here..
		m_viewAllPartsButton->setToggleState(false, dontSendNotification);
		m_viewNoPartsButton->setToggleState(false, dontSendNotification);
		patternBodyBlock->getPatternTableFilterParams()->getParameter(PatternBodyBlock::VirtualPatternTableFilterBlock::ViewPart1)->setValue(0, Parameter::Init);
		patternBodyBlock->getPatternTableFilterParams()->getParameter(PatternBodyBlock::VirtualPatternTableFilterBlock::ViewPart2)->setValue(0, Parameter::Init);
		patternBodyBlock->getPatternTableFilterParams()->getParameter(PatternBodyBlock::VirtualPatternTableFilterBlock::ViewPart3)->setValue(0, Parameter::Init);
		patternBodyBlock->getPatternTableFilterParams()->getParameter(PatternBodyBlock::VirtualPatternTableFilterBlock::ViewPart4)->setValue(0, Parameter::Init);
		patternBodyBlock->getPatternTableFilterParams()->getParameter(PatternBodyBlock::VirtualPatternTableFilterBlock::ViewPart5)->setValue(0, Parameter::Init);
		patternBodyBlock->getPatternTableFilterParams()->getParameter(PatternBodyBlock::VirtualPatternTableFilterBlock::ViewPart6)->setValue(0, Parameter::Init);
		patternBodyBlock->getPatternTableFilterParams()->getParameter(PatternBodyBlock::VirtualPatternTableFilterBlock::ViewPart7)->setValue(0, Parameter::Init);
		patternBodyBlock->getPatternTableFilterParams()->getParameter(PatternBodyBlock::VirtualPatternTableFilterBlock::ViewPartR)->setValue(0, Parameter::Init);
		patternBodyBlock->getPatternTableFilterParams()->getParameter(PatternBodyBlock::VirtualPatternTableFilterBlock::ViewMuteCtrl)->setValue(0, Parameter::Init);

		patternBodyBlock->refreshFilteredContent();
        //[/UserButtonCode_m_viewNoPartsButton]
    }
    else if (buttonThatWasClicked == m_viewAllEventsButton)
    {
        //[UserButtonCode_m_viewAllEventsButton] -- add your button handler code here..
		patternBodyBlock->getPatternTableFilterParams()->getParameter(PatternBodyBlock::VirtualPatternTableFilterBlock::ViewNotes)->setValue(1, Parameter::Init);
		patternBodyBlock->getPatternTableFilterParams()->getParameter(PatternBodyBlock::VirtualPatternTableFilterBlock::ViewNotesMin)->setValue(0, Parameter::Init);
		patternBodyBlock->getPatternTableFilterParams()->getParameter(PatternBodyBlock::VirtualPatternTableFilterBlock::ViewNotesMax)->setValue(127, Parameter::Init);
		patternBodyBlock->getPatternTableFilterParams()->getParameter(PatternBodyBlock::VirtualPatternTableFilterBlock::ViewPC)->setValue(1, Parameter::Init);
		patternBodyBlock->getPatternTableFilterParams()->getParameter(PatternBodyBlock::VirtualPatternTableFilterBlock::ViewCC)->setValue(1, Parameter::Init);
		patternBodyBlock->getPatternTableFilterParams()->getParameter(PatternBodyBlock::VirtualPatternTableFilterBlock::ViewCCMin)->setValue(0, Parameter::Init);
		patternBodyBlock->getPatternTableFilterParams()->getParameter(PatternBodyBlock::VirtualPatternTableFilterBlock::ViewCCMax)->setValue(127, Parameter::Init);
		patternBodyBlock->getPatternTableFilterParams()->getParameter(PatternBodyBlock::VirtualPatternTableFilterBlock::ViewBend)->setValue(1, Parameter::Init);
		patternBodyBlock->getPatternTableFilterParams()->getParameter(PatternBodyBlock::VirtualPatternTableFilterBlock::ViewPAft)->setValue(1, Parameter::Init);
		patternBodyBlock->getPatternTableFilterParams()->getParameter(PatternBodyBlock::VirtualPatternTableFilterBlock::ViewPAftMin)->setValue(0, Parameter::Init);
		patternBodyBlock->getPatternTableFilterParams()->getParameter(PatternBodyBlock::VirtualPatternTableFilterBlock::ViewPAftMax)->setValue(127, Parameter::Init);
		patternBodyBlock->getPatternTableFilterParams()->getParameter(PatternBodyBlock::VirtualPatternTableFilterBlock::ViewCAft)->setValue(1, Parameter::Init);
		patternBodyBlock->getPatternTableFilterParams()->getParameter(PatternBodyBlock::VirtualPatternTableFilterBlock::ViewTempo)->setValue(1, Parameter::Init);
		patternBodyBlock->getPatternTableFilterParams()->getParameter(PatternBodyBlock::VirtualPatternTableFilterBlock::ViewMute)->setValue(1, Parameter::Init);
		patternBodyBlock->getPatternTableFilterParams()->getParameter(PatternBodyBlock::VirtualPatternTableFilterBlock::ViewSysEx)->setValue(1, Parameter::Init);
		patternBodyBlock->getPatternTableFilterParams()->getParameter(PatternBodyBlock::VirtualPatternTableFilterBlock::ViewInc)->setValue(1, Parameter::Init);

		patternBodyBlock->refreshFilteredContent();
        //[/UserButtonCode_m_viewAllEventsButton]
    }
    else if (buttonThatWasClicked == m_viewNoEventsButton)
    {
        //[UserButtonCode_m_viewNoEventsButton] -- add your button handler code here..
		patternBodyBlock->getPatternTableFilterParams()->getParameter(PatternBodyBlock::VirtualPatternTableFilterBlock::ViewNotes)->setValue(0, Parameter::Init);
		patternBodyBlock->getPatternTableFilterParams()->getParameter(PatternBodyBlock::VirtualPatternTableFilterBlock::ViewPC)->setValue(0, Parameter::Init);
		patternBodyBlock->getPatternTableFilterParams()->getParameter(PatternBodyBlock::VirtualPatternTableFilterBlock::ViewCC)->setValue(0, Parameter::Init);
		patternBodyBlock->getPatternTableFilterParams()->getParameter(PatternBodyBlock::VirtualPatternTableFilterBlock::ViewBend)->setValue(0, Parameter::Init);
		patternBodyBlock->getPatternTableFilterParams()->getParameter(PatternBodyBlock::VirtualPatternTableFilterBlock::ViewPAft)->setValue(0, Parameter::Init);
		patternBodyBlock->getPatternTableFilterParams()->getParameter(PatternBodyBlock::VirtualPatternTableFilterBlock::ViewCAft)->setValue(0, Parameter::Init);
		patternBodyBlock->getPatternTableFilterParams()->getParameter(PatternBodyBlock::VirtualPatternTableFilterBlock::ViewTempo)->setValue(0, Parameter::Init);
		patternBodyBlock->getPatternTableFilterParams()->getParameter(PatternBodyBlock::VirtualPatternTableFilterBlock::ViewMute)->setValue(0, Parameter::Init);
		patternBodyBlock->getPatternTableFilterParams()->getParameter(PatternBodyBlock::VirtualPatternTableFilterBlock::ViewSysEx)->setValue(0, Parameter::Init);
		patternBodyBlock->getPatternTableFilterParams()->getParameter(PatternBodyBlock::VirtualPatternTableFilterBlock::ViewInc)->setValue(0, Parameter::Init);

		patternBodyBlock->refreshFilteredContent();
        //[/UserButtonCode_m_viewNoEventsButton]
    }

    //[UserbuttonClicked_Post]
	else if (buttonThatWasClicked == m_viewSinglePartToggle)
	{
		//m_viewAllPartsButton->setEnabled(!m_viewSinglePartToggle->getToggleState());
	}
    //[/UserbuttonClicked_Post]
}

void PatternEditorTab::sliderValueChanged (Slider* sliderThatWasMoved)
{
    //[UsersliderValueChanged_Pre]
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
    else if (sliderThatWasMoved == m_measuresSlider)
    {
        //[UserSliderCode_m_measuresSlider] -- add your slider handling code here..
		grooveboxMemory->getPatternBodyBlock()->setLengthInMeasures((uint8)m_measuresSlider->getValue());
        //[/UserSliderCode_m_measuresSlider]
    }
    else if (sliderThatWasMoved == m_tempoSlider)
    {
        //[UserSliderCode_m_tempoSlider] -- add your slider handling code here..
		grooveboxMemory->getPatternSetupBlock()->getPatternSetupConfigBlockPtr()->setTempoBpm((float)m_tempoSlider->getValue());
        //[/UserSliderCode_m_tempoSlider]
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
		m_patternEventTable->repaint();
	}
	else if (Parameter* param = dynamic_cast<Parameter*>(source))
	{
		if (param == grooveboxMemory->getPatternSetupBlock()->getPatternSetupConfigBlockPtr()->getParameter(0x10) ||
			param == grooveboxMemory->getPatternSetupBlock()->getPatternSetupConfigBlockPtr()->getParameter(0x11))
		{
			BeatSignature sig = grooveboxMemory->getPatternSetupBlock()->getPatternSetupConfigBlockPtr()->getBeatSignature();
			m_keySignatureComboBox->setText(sig.toString(),dontSendNotification);
			grooveboxMemory->getPatternBodyBlock()->setBeatSignature(sig);
			m_patternEventTable->updateContent();
			m_patternEventTable->repaint();
		}
		else if (param == grooveboxMemory->getPatternSetupBlock()->getPatternSetupConfigBlockPtr()->getParameter(0x13) ||
			param == grooveboxMemory->getPatternSetupBlock()->getPatternSetupConfigBlockPtr()->getParameter(0x14) ||
			param == grooveboxMemory->getPatternSetupBlock()->getPatternSetupConfigBlockPtr()->getParameter(0x15) ||
			param == grooveboxMemory->getPatternSetupBlock()->getPatternSetupConfigBlockPtr()->getParameter(0x16))
		{
			m_tempoSlider->setValue(grooveboxMemory->getPatternSetupBlock()->getPatternSetupConfigBlockPtr()->getTempoBpm(), dontSendNotification);
		}
	}
}

// This must return the next target to try after this one.
ApplicationCommandTarget* PatternEditorTab::getNextCommandTarget()
{
	// this will return the next parent component that is an ApplicationCommandTarget (in this
	// case, there probably isn't one, but it's best to use this method in your own apps).
	return findFirstTargetParentComponent();
}

// This must return a complete list of commands that this target can handle.
void PatternEditorTab::getAllCommands(Array< CommandID > &commands)
{
	// this returns the set of all commands that this target can perform..
	const CommandID ids[] = {
		createEmptyPattern,
		/* ---------------------- */
		fileOpenPatternSyxFile,
		fileSavePatternSyxFile,
		/* ---------------------- */
		fileImportPatternSmfFile,
		fileExportPatternSmfFile,
		/* ---------------------- */
		grooveBoxLoadPattern
	};
	commands.addArray(ids, numElementsInArray(ids));
}

//This must provide details about one of the commands that this target can perform.
void PatternEditorTab::getCommandInfo(CommandID commandID, ApplicationCommandInfo &result)
{
	const String category("Pattern");

	switch (commandID)
	{
	case createEmptyPattern:
		result.setInfo("New empty pattern", "Clears the pattern data", category, 0);
		result.addDefaultKeypress('n', ModifierKeys::commandModifier);
		break;
	case fileOpenPatternSyxFile:
		result.setInfo("Open SysEx Pattern File...", "Opens a raw pattern file, either binary SysEx (.syx) or Hex SysEx text (.txt)", category, 0);
		result.addDefaultKeypress('o', ModifierKeys::commandModifier);
		break;
	case fileImportPatternSmfFile:
		result.setInfo("Import Pattern from MIDI File", "Tries to extract pattern data from a Standard MIDI File (.mid)", category, 0);
		result.addDefaultKeypress('i', ModifierKeys::commandModifier);
		result.setActive(true);
		break;
	case fileSavePatternSyxFile:
		result.setInfo("Save Pattern as SysEx...", "Saves a pattern file as raw data, either binary SysEx (.syx) or Hex SysEx text (.txt)", category, 0);
		result.addDefaultKeypress('s', ModifierKeys::commandModifier);
		result.setActive(!grooveboxMemory->getPatternBodyBlock()->isPatternEmpty());
		break;
	case fileExportPatternSmfFile:
		result.setInfo("Export Pattern as MIDI...", "Converts pattern to Standard MIDI File (.mid)", category, 0);
		result.addDefaultKeypress('s', ModifierKeys::commandModifier | ModifierKeys::shiftModifier);
		result.setActive(!grooveboxMemory->getPatternBodyBlock()->isPatternEmpty());
		break;
	case grooveBoxLoadPattern:
		result.setInfo("Send Pattern Request SysEx", "Request temporary pattern data from groovebox.", category, 0);
		result.addDefaultKeypress('r', ModifierKeys::commandModifier);
		result.setActive(grooveboxConnector->getActiveConnection() != nullptr);
	default:
		break;
	}
}

// This must actually perform the specified command.
bool PatternEditorTab::perform(const InvocationInfo &info)
{
	switch (info.commandID)
	{
	case CommandIDs::createEmptyPattern:
		grooveboxMemory->getPatternBodyBlock()->clearPattern();
		return true;
	case CommandIDs::fileOpenPatternSyxFile:
		loadSysExFile();
		return true;
	case CommandIDs::fileImportPatternSmfFile:
		// TODO: import from midi (convert midi to groovebox sysex)
		return true;
	case CommandIDs::fileSavePatternSyxFile:
		saveSysExFile();
		return true;
	case CommandIDs::fileExportPatternSmfFile:
		exportAsMidiFile();
		return true;
	case CommandIDs::grooveBoxLoadPattern:
		//loadFromGroovebox();
		return true;
	default:
		return false;
	}
}

void PatternEditorTab::loadSysExFile()
{
	FileChooser fileChooser("Open SysEx pattern file (Binary System Exclusive or Hex SysEx Text)", File::getSpecialLocation(File::userHomeDirectory), "*.syx;*.txt");
	if (fileChooser.browseForFileToOpen())
	{
		File file = fileChooser.getResult();
		if (file.getFileExtension().toLowerCase() != ".syx" && file.getFileExtension().toLowerCase() != ".txt")
		{
			AlertWindow::showMessageBox(AlertWindow::WarningIcon, "File extension not supported", "Only the folling file extensions are supported:\r\n" +
				String(CharPointer_UTF8("\xe2\x80\xa2")) + " .syx\t(Binary System Exclusive)\r\n" +
				String(CharPointer_UTF8("\xe2\x80\xa2")) + " .txt\t(Hex SysEx Text)");
		}
		else
		{
			bool loadedSucessfully(false);
			if (file.getFileExtension().toLowerCase() == ".syx")
			{
				loadedSucessfully = grooveboxMemory->loadBinarySysExFile(file);
			}
			else if (file.getFileExtension().toLowerCase() == ".txt")
			{
				loadedSucessfully = grooveboxMemory->loadHexTxtSysExFile(file);
			}
			// load current pattern. if no success loading: show empty pattern
			if (!loadedSucessfully)
			{
				AlertWindow::showMessageBox(AlertWindow::WarningIcon, TRANS("Error getting pattern data"), TRANS("No pattern or pattern data was retrieved."));
			}
		}
	}
}

void PatternEditorTab::saveSysExFile()
{
	FileChooser fileChooser("Save SysEx pattern file (Binary System Exclusive or Hex SysEx Text)", File::getSpecialLocation(File::userHomeDirectory), "*.syx;*.txt");
	if (fileChooser.browseForFileToSave(true))
	{
		File file = fileChooser.getResult();
		if (file.getFileExtension().toLowerCase() != ".syx" && file.getFileExtension().toLowerCase() != ".txt")
		{
			AlertWindow::showMessageBox(AlertWindow::WarningIcon, "File extension not supported", "Only the folling file extensions are supported:\r\n" +
				String(CharPointer_UTF8("\xe2\x80\xa2")) + " .syx\t(Binary System Exclusive)\r\n" +
				String(CharPointer_UTF8("\xe2\x80\xa2")) + " .txt\t(Hex SysEx Text)");
		}
		else
		{
			bool writtenSucessfully(false);
			if (file.getFileExtension().toLowerCase() == ".syx")
			{
				writtenSucessfully = grooveboxMemory->saveBinarySysExFile(file);
			}
			else if (file.getFileExtension().toLowerCase() == ".txt")
			{
				writtenSucessfully = grooveboxMemory->saveHexTextSysExFile(file);
			}
			// load current pattern. if no success loading: show empty pattern
			if (!writtenSucessfully)
			{
				AlertWindow::showMessageBox(AlertWindow::WarningIcon, TRANS("Error writing pattern data"), TRANS("No pattern or pattern data was written."));
			}
		}
	}
}

void PatternEditorTab::exportAsMidiFile()
{
	File defaultFile = File(File::getSpecialLocation(File::userHomeDirectory).getFullPathName() + File::separatorString + grooveboxMemory->getPatternSetupBlock()->getPatternSetupConfigBlockPtr()->getPatternName().trim() + ".mid");
	FileChooser myChooser(TRANS("Export as MIDI File"),
		defaultFile,
		"*.mid");
	if (myChooser.browseForFileToSave(true))
	{
		File selectedFile(myChooser.getResult());
		if (selectedFile.existsAsFile()) selectedFile.deleteFile();
		ScopedPointer<OutputStream> saveStream = selectedFile.createOutputStream();
		ScopedPointer<MidiFile> midiFile = grooveboxMemory->getPatternBodyBlock()->convertToMidiFile();
		midiFile->writeTo(*saveStream);
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
                 parentClasses="public Component, public ChangeListener, public ApplicationCommandTarget"
                 constructorParams="" variableInitialisers="" snapPixels="4" snapActive="1"
                 snapShown="1" overlayOpacity="0.330" fixedSize="0" initialWidth="1060"
                 initialHeight="400">
  <BACKGROUND backgroundColour="ff303030"/>
  <JUCERCOMP name="patternPanel" id="b3dca965d9e5cad6" memberName="m_patternPanel"
             virtualName="" explicitFocusOrder="0" pos="4 4 716 8M" sourceFile="GroupWidgets/PanelGroupGrey.cpp"
             constructorParams="&quot;patternPanel&quot;, &quot;PATTERN&quot;"/>
  <JUCERCOMP name="viewEventTypesPanel" id="b5b48c285ffdb1de" memberName="m_viewEventTypesPanel"
             virtualName="" explicitFocusOrder="0" pos="724 168 332 188" sourceFile="GroupWidgets/PanelGroupGrey.cpp"
             constructorParams="&quot;viewEventTypesPanel&quot;, &quot;VIEW EVENTS&quot;"/>
  <JUCERCOMP name="viewPartsPanel" id="5a83783acf8f7721" memberName="m_viewPartsPanel"
             virtualName="" explicitFocusOrder="0" pos="724 64 332 100" sourceFile="GroupWidgets/PanelGroupGrey.cpp"
             constructorParams="&quot;viewPartsPanel&quot;, &quot;VIEW PARTS&quot;"/>
  <JUCERCOMP name="midiOutPanel" id="60dfadf25f2b4251" memberName="m_midiOutPanel"
             virtualName="" explicitFocusOrder="0" pos="724 4 332 56" sourceFile="GroupWidgets/PanelGroupGrey.cpp"
             constructorParams="&quot;midiOutPanel&quot;, &quot;MIDI OUT&quot;"/>
  <COMBOBOX name="midiOutComboBox" id="9b6d2ada3deafb58" memberName="m_midiOutComboBox"
            virtualName="ParameterComboBox" explicitFocusOrder="0" pos="732 24 256 22"
            editable="0" layout="33" items="" textWhenNonSelected="" textWhenNoItems="(no choices)"/>
  <TEXTBUTTON name="panicButton" id="7514cd2cffbbc78c" memberName="m_panicButton"
              virtualName="" explicitFocusOrder="0" pos="996 24 52 22" buttonText="Panic!"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <GENERICCOMPONENT name="" id="6aebf3e3738962bd" memberName="m_patternEventTable"
                    virtualName="" explicitFocusOrder="0" pos="8 68 708 76M" class="TableListBox"
                    params="&quot;patternEventTable&quot;"/>
  <SLIDER name="noteRangeLowerSlider" id="b9d1900a1c3c44f7" memberName="m_noteRangeLowerSlider"
          virtualName="MicroParameterSlider" explicitFocusOrder="0" pos="848 188 48 16"
          bkgcol="fff2f59b" thumbcol="ffc4c86d" min="0" max="127" int="1"
          style="LinearBar" textBoxPos="TextBoxLeft" textBoxEditable="1"
          textBoxWidth="40" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="noteRangeUpperSlider" id="b55b7c90bb48008" memberName="m_noteRangeUpperSlider"
          virtualName="MicroParameterSlider" explicitFocusOrder="0" pos="924 188 48 16"
          bkgcol="fff2f59b" thumbcol="ffc4c86d" min="0" max="127" int="1"
          style="LinearBar" textBoxPos="TextBoxLeft" textBoxEditable="1"
          textBoxWidth="40" textBoxHeight="20" skewFactor="1"/>
  <LABEL name="fromLabel" id="9056d8c316152585" memberName="m_fromLabel"
         virtualName="" explicitFocusOrder="0" pos="808 188 44 16" edTextCol="ff000000"
         edBkgCol="0" labelText="FROM" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="12"
         bold="1" italic="0" justification="34"/>
  <SLIDER name="ccRangeLowerSlider" id="6eb2fec2472bcf65" memberName="m_ccRangeLowerSlider"
          virtualName="MicroParameterSlider" explicitFocusOrder="0" pos="848 216 48 16"
          bkgcol="fff2f59b" thumbcol="ffc4c86d" min="0" max="127" int="1"
          style="LinearBar" textBoxPos="TextBoxLeft" textBoxEditable="1"
          textBoxWidth="40" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="ccRangeUpperSlider" id="577e76cd8daa1c7" memberName="m_ccRangeUpperSlider"
          virtualName="MicroParameterSlider" explicitFocusOrder="0" pos="924 216 48 16"
          bkgcol="fff2f59b" thumbcol="ffc4c86d" min="0" max="127" int="1"
          style="LinearBar" textBoxPos="TextBoxLeft" textBoxEditable="1"
          textBoxWidth="40" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="PAftRangeLowerSlider" id="45a06c5048ed35ff" memberName="m_PAftRangeLowerSlider"
          virtualName="MicroParameterSlider" explicitFocusOrder="0" pos="848 244 48 16"
          bkgcol="fff2f59b" thumbcol="ffc4c86d" min="0" max="127" int="1"
          style="LinearBar" textBoxPos="TextBoxLeft" textBoxEditable="1"
          textBoxWidth="40" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="PAftRangeUpperSlider" id="797d73fef2e299f5" memberName="m_PAftRangeUpperSlider"
          virtualName="MicroParameterSlider" explicitFocusOrder="0" pos="924 244 48 16"
          bkgcol="fff2f59b" thumbcol="ffc4c86d" min="0" max="127" int="1"
          style="LinearBar" textBoxPos="TextBoxLeft" textBoxEditable="1"
          textBoxWidth="40" textBoxHeight="20" skewFactor="1"/>
  <JUCERCOMP name="viewPartToggleR" id="1d7902cb6f52a8a2" memberName="m_viewPartToggleR"
             virtualName="" explicitFocusOrder="0" pos="732 100 25 17" sourceFile="ParameterWidgets/BlackToggle.cpp"
             constructorParams=""/>
  <LABEL name="viewPartLabelR" id="bc5132eee7a0ee16" memberName="m_viewPartLabelR"
         virtualName="" explicitFocusOrder="0" pos="732 84 25 16" textCol="ff000000"
         edTextCol="ff000000" edBkgCol="0" labelText="R" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="12" bold="1" italic="0" justification="36"/>
  <JUCERCOMP name="viewPartToggle1" id="a18931839c0b8bc7" memberName="m_viewPartToggle1"
             virtualName="" explicitFocusOrder="0" pos="772 100 25 17" sourceFile="ParameterWidgets/BlackToggle.cpp"
             constructorParams=""/>
  <LABEL name="viewPartLabel1" id="ad4994c83a8227fe" memberName="m_viewPartLabel1"
         virtualName="" explicitFocusOrder="0" pos="772 84 25 16" textCol="ff000000"
         edTextCol="ff000000" edBkgCol="0" labelText="1" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="12" bold="1" italic="0" justification="36"/>
  <JUCERCOMP name="viewPartToggle2" id="cc67029767436e76" memberName="m_viewPartToggle2"
             virtualName="" explicitFocusOrder="0" pos="804 100 25 17" sourceFile="ParameterWidgets/BlackToggle.cpp"
             constructorParams=""/>
  <LABEL name="viewPartLabel2" id="40f4c0d942746fc2" memberName="m_viewPartLabel2"
         virtualName="" explicitFocusOrder="0" pos="804 84 25 16" textCol="ff000000"
         edTextCol="ff000000" edBkgCol="0" labelText="2" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="12" bold="1" italic="0" justification="36"/>
  <JUCERCOMP name="viewPartToggle3" id="f1d2259f5fdc632a" memberName="m_viewPartToggle3"
             virtualName="" explicitFocusOrder="0" pos="836 100 25 17" sourceFile="ParameterWidgets/BlackToggle.cpp"
             constructorParams=""/>
  <LABEL name="viewPartLabel3" id="c00f1c442319a709" memberName="m_viewPartLabel3"
         virtualName="" explicitFocusOrder="0" pos="836 84 25 16" textCol="ff000000"
         edTextCol="ff000000" edBkgCol="0" labelText="3" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="12" bold="1" italic="0" justification="36"/>
  <JUCERCOMP name="viewPartToggle4" id="19611dc9b01f2f43" memberName="m_viewPartToggle4"
             virtualName="" explicitFocusOrder="0" pos="868 100 25 17" sourceFile="ParameterWidgets/BlackToggle.cpp"
             constructorParams=""/>
  <LABEL name="viewPartLabel4" id="b2bba0a8be3d9218" memberName="m_viewPartLabel4"
         virtualName="" explicitFocusOrder="0" pos="868 84 25 16" textCol="ff000000"
         edTextCol="ff000000" edBkgCol="0" labelText="4" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="12" bold="1" italic="0" justification="36"/>
  <JUCERCOMP name="viewPartToggle5" id="78c5acd471a43391" memberName="m_viewPartToggle5"
             virtualName="" explicitFocusOrder="0" pos="900 100 25 17" sourceFile="ParameterWidgets/BlackToggle.cpp"
             constructorParams=""/>
  <LABEL name="viewPartLabel5" id="625a82943feb34fc" memberName="m_viewPartLabel5"
         virtualName="" explicitFocusOrder="0" pos="900 84 25 16" textCol="ff000000"
         edTextCol="ff000000" edBkgCol="0" labelText="5" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="12" bold="1" italic="0" justification="36"/>
  <JUCERCOMP name="viewPartToggle6" id="83663b51ab2a6441" memberName="m_viewPartToggle6"
             virtualName="" explicitFocusOrder="0" pos="932 100 25 17" sourceFile="ParameterWidgets/BlackToggle.cpp"
             constructorParams=""/>
  <LABEL name="viewPartLabel6" id="c5f2bc21f7910cd1" memberName="m_viewPartLabel6"
         virtualName="" explicitFocusOrder="0" pos="932 84 25 16" textCol="ff000000"
         edTextCol="ff000000" edBkgCol="0" labelText="6" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="12" bold="1" italic="0" justification="36"/>
  <JUCERCOMP name="viewPartToggleMuteCtl" id="c2ce082733354a5e" memberName="m_viewPartToggleMuteCtl"
             virtualName="" explicitFocusOrder="0" pos="1008 100 25 17" sourceFile="ParameterWidgets/BlackToggle.cpp"
             constructorParams=""/>
  <LABEL name="viewPartLabelMuteCtl" id="ada9c424b62b9157" memberName="m_viewPartLabelMuteCtl"
         virtualName="" explicitFocusOrder="0" pos="990 84 66 16" textCol="ff000000"
         edTextCol="ff000000" edBkgCol="0" labelText="MUTE-CTL" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="12" bold="1" italic="0" justification="36"/>
  <JUCERCOMP name="viewTypeToggleNote" id="bda56df07703530" memberName="m_viewTypeToggleNote"
             virtualName="" explicitFocusOrder="0" pos="776 188 25 17" sourceFile="ParameterWidgets/BlackToggle.cpp"
             constructorParams=""/>
  <LABEL name="viewTypeNoteLabel" id="dec0e11bd8cac905" memberName="m_viewTypeNoteLabel"
         virtualName="" explicitFocusOrder="0" pos="732 188 44 16" textCol="ff000000"
         edTextCol="ff000000" edBkgCol="0" labelText="NOTE" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="12" bold="1" italic="0" justification="34"/>
  <JUCERCOMP name="viewTypeTogglePc" id="5e31f5d6526d433e" memberName="m_viewTypeTogglePc"
             virtualName="" explicitFocusOrder="0" pos="850 272 25 17" sourceFile="ParameterWidgets/BlackToggle.cpp"
             constructorParams=""/>
  <LABEL name="viewTypePcLabel" id="8351602a43355d7b" memberName="m_viewTypePcLabel"
         virtualName="" explicitFocusOrder="0" pos="808 272 42 16" textCol="ff000000"
         edTextCol="ff000000" edBkgCol="0" labelText="PC" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="12" bold="1" italic="0" justification="34"/>
  <JUCERCOMP name="viewTypeToggleCc" id="39fa258dcb4cb708" memberName="m_viewTypeToggleCc"
             virtualName="" explicitFocusOrder="0" pos="776 216 25 17" sourceFile="ParameterWidgets/BlackToggle.cpp"
             constructorParams=""/>
  <LABEL name="viewTypeCcLabel" id="82515de101e4d876" memberName="m_viewTypeCcLabel"
         virtualName="" explicitFocusOrder="0" pos="732 216 44 16" textCol="ff000000"
         edTextCol="ff000000" edBkgCol="0" labelText="CC" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="12" bold="1" italic="0" justification="34"/>
  <JUCERCOMP name="viewTypeToggleBend" id="36657f8d741a41be" memberName="m_viewTypeToggleBend"
             virtualName="" explicitFocusOrder="0" pos="924 272 25 17" sourceFile="ParameterWidgets/BlackToggle.cpp"
             constructorParams=""/>
  <LABEL name="viewTypeBendLabel" id="ab23ce03c4559ff7" memberName="m_viewTypeBendLabel"
         virtualName="" explicitFocusOrder="0" pos="880 272 44 16" textCol="ff000000"
         edTextCol="ff000000" edBkgCol="0" labelText="BEND" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="12" bold="1" italic="0" justification="34"/>
  <JUCERCOMP name="viewTypeTogglePAft" id="f145639779123e00" memberName="m_viewTypeTogglePAft"
             virtualName="" explicitFocusOrder="0" pos="776 244 25 17" sourceFile="ParameterWidgets/BlackToggle.cpp"
             constructorParams=""/>
  <LABEL name="viewTypePAftLabel" id="22549c0ebb305365" memberName="m_viewTypePAftLabel"
         virtualName="" explicitFocusOrder="0" pos="732 244 44 16" textCol="ff000000"
         edTextCol="ff000000" edBkgCol="0" labelText="P-AFT" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="12" bold="1" italic="0" justification="34"/>
  <JUCERCOMP name="viewTypeToggleCAft" id="8c5125e59845414e" memberName="m_viewTypeToggleCAft"
             virtualName="" explicitFocusOrder="0" pos="776 272 25 17" sourceFile="ParameterWidgets/BlackToggle.cpp"
             constructorParams=""/>
  <LABEL name="viewTypeCAftLabel" id="59ab991b4d754058" memberName="m_viewTypeCAftLabel"
         virtualName="" explicitFocusOrder="0" pos="730 272 46 16" textCol="ff000000"
         edTextCol="ff000000" edBkgCol="0" labelText="C-AFT" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="12" bold="1" italic="0" justification="34"/>
  <JUCERCOMP name="viewTypeToggleTempo" id="83c15bd47e82f57b" memberName="m_viewTypeToggleTempo"
             virtualName="" explicitFocusOrder="0" pos="776 300 25 17" sourceFile="ParameterWidgets/BlackToggle.cpp"
             constructorParams=""/>
  <LABEL name="viewTypeTempoLabel" id="abffb603f4cf52de" memberName="m_viewTypeTempoLabel"
         virtualName="" explicitFocusOrder="0" pos="726 300 50 16" textCol="ff000000"
         edTextCol="ff000000" edBkgCol="0" labelText="TEMPO" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="12" bold="1" italic="0" justification="34"/>
  <JUCERCOMP name="viewTypeToggleMute" id="c215c676900cf2f" memberName="m_viewTypeToggleMute"
             virtualName="" explicitFocusOrder="0" pos="850 300 25 17" sourceFile="ParameterWidgets/BlackToggle.cpp"
             constructorParams=""/>
  <LABEL name="viewTypeMuteLabel" id="3729b7e77e15eff7" memberName="m_viewTypeMuteLabel"
         virtualName="" explicitFocusOrder="0" pos="806 300 44 16" textCol="ff000000"
         edTextCol="ff000000" edBkgCol="0" labelText="MUTE" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="12" bold="1" italic="0" justification="34"/>
  <JUCERCOMP name="viewTypeToggleSysEx" id="48e8fca9153fa018" memberName="m_viewTypeToggleSysEx"
             virtualName="" explicitFocusOrder="0" pos="924 300 25 17" sourceFile="ParameterWidgets/BlackToggle.cpp"
             constructorParams=""/>
  <LABEL name="viewTypeSysExLabel" id="6094cd3de2bc8cd4" memberName="m_viewTypeSysExLabel"
         virtualName="" explicitFocusOrder="0" pos="874 300 50 16" textCol="ff000000"
         edTextCol="ff000000" edBkgCol="0" labelText="SYSEX" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="12" bold="1" italic="0" justification="34"/>
  <LABEL name="toLabel" id="462c369b4cc8d9c9" memberName="m_toLabel" virtualName=""
         explicitFocusOrder="0" pos="900 188 28 16" edTextCol="ff000000"
         edBkgCol="0" labelText="TO" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="12"
         bold="1" italic="0" justification="34"/>
  <LABEL name="fromLabel" id="27791d977542d319" memberName="m_fromLabel2"
         virtualName="" explicitFocusOrder="0" pos="808 216 44 16" edTextCol="ff000000"
         edBkgCol="0" labelText="FROM" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="12"
         bold="1" italic="0" justification="34"/>
  <LABEL name="toLabel" id="efd1bbf0b7ad6fd" memberName="m_toLabel2" virtualName=""
         explicitFocusOrder="0" pos="900 216 28 16" edTextCol="ff000000"
         edBkgCol="0" labelText="TO" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="12"
         bold="1" italic="0" justification="34"/>
  <LABEL name="fromLabel" id="b18cc35b97da47a7" memberName="m_fromLabel3"
         virtualName="" explicitFocusOrder="0" pos="808 245 44 16" edTextCol="ff000000"
         edBkgCol="0" labelText="FROM" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="12"
         bold="1" italic="0" justification="34"/>
  <LABEL name="toLabel" id="d8b71279d35fe3a9" memberName="m_toLabel3"
         virtualName="" explicitFocusOrder="0" pos="900 244 28 16" edTextCol="ff000000"
         edBkgCol="0" labelText="TO" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="12"
         bold="1" italic="0" justification="34"/>
  <JUCERCOMP name="viewPartToggle7" id="dedfac941a8fd441" memberName="m_viewPartToggle7"
             virtualName="" explicitFocusOrder="0" pos="964 100 25 17" sourceFile="ParameterWidgets/BlackToggle.cpp"
             constructorParams=""/>
  <LABEL name="viewPartLabel7" id="1259e0a46cb4feda" memberName="m_viewPartLabel7"
         virtualName="" explicitFocusOrder="0" pos="964 84 25 16" textCol="ff000000"
         edTextCol="ff000000" edBkgCol="0" labelText="7" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="12" bold="1" italic="0" justification="36"/>
  <TEXTBUTTON name="viewAllPartsButton" id="b8166a68e7f63c09" memberName="m_viewAllPartsButton"
              virtualName="" explicitFocusOrder="0" pos="936 136 52 20" buttonText="ALL"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="viewNoPartsButton" id="ad02355735c6a9f1" memberName="m_viewNoPartsButton"
              virtualName="" explicitFocusOrder="0" pos="996 136 52 20" buttonText="NONE"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="viewAllEventsButton" id="51d716105f5b4021" memberName="m_viewAllEventsButton"
              virtualName="" explicitFocusOrder="0" pos="936 328 52 20" buttonText="ALL"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="viewNoEventsButton" id="e2a123523e69342" memberName="m_viewNoEventsButton"
              virtualName="" explicitFocusOrder="0" pos="996 328 52 20" buttonText="NONE"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <JUCERCOMP name="viewSinglePartToggle" id="71afd96cb7e4d50f" memberName="m_viewSinglePartToggle"
             virtualName="" explicitFocusOrder="0" pos="852 140 12 12" sourceFile="ParameterWidgets/SmallGreenToggle.cpp"
             constructorParams=""/>
  <LABEL name="viewSinglePartLabel" id="bedb99fb622fc099" memberName="m_viewSinglePartLabel"
         virtualName="" explicitFocusOrder="0" pos="797 140 55 12" textCol="ff000000"
         edTextCol="ff000000" edBkgCol="0" labelText="SINGLE" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="12" bold="1" italic="0" justification="34"/>
  <LABEL name="patchNameLabel" id="2ec0efd8ffa587b" memberName="m_patchNameLabel"
         virtualName="" explicitFocusOrder="0" pos="12 24 128 16" textCol="ff000000"
         edTextCol="ff000000" edBkgCol="0" labelText="PATTERN NAME" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="12" bold="1" italic="0" justification="36"/>
  <TEXTEDITOR name="patternNameEditor" id="9686a2e1612f5756" memberName="m_patternNameEditor"
              virtualName="ParameterTextEditor" explicitFocusOrder="0" pos="12 40 128 22"
              textcol="ff000000" bkgcol="fff2f59b" outlinecol="ff808080" initialText="EMPTY PATTERN"
              multiline="0" retKeyStartsLine="0" readonly="0" scrollbars="0"
              caret="1" popupmenu="1"/>
  <COMBOBOX name="keySignatureComboBox" id="e8c10ecedfc6fd9e" memberName="m_keySignatureComboBox"
            virtualName="ParameterComboBox" explicitFocusOrder="0" pos="164 40 64 22"
            editable="0" layout="36" items="2/4&#10;3/4&#10;4/4&#10;5/4&#10;6/4&#10;7/4&#10;5/8&#10;6/8&#10;7/8&#10;9/8&#10;12/8&#10;9/16&#10;11/16&#10;13/16&#10;15/16&#10;17/16&#10;19/16"
            textWhenNonSelected="4/4" textWhenNoItems="(no choices)"/>
  <LABEL name="timeSignatureLabel" id="ebaeb767998e3a96" memberName="m_timeSignatureLabel"
         virtualName="" explicitFocusOrder="0" pos="136 24 116 16" textCol="ff000000"
         edTextCol="ff000000" edBkgCol="0" labelText="TIME SIGNATURE"
         editableSingleClick="0" editableDoubleClick="0" focusDiscardsChanges="0"
         fontname="Default font" fontsize="12" bold="1" italic="0" justification="36"/>
  <LABEL name="measuresLabel" id="d10f06f6186af7d8" memberName="m_measuresLabel"
         virtualName="" explicitFocusOrder="0" pos="244 24 76 16" textCol="ff000000"
         edTextCol="ff000000" edBkgCol="0" labelText="MEASURES" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="12" bold="1" italic="0" justification="36"/>
  <SLIDER name="measuresSlider" id="e1f3179b8260be26" memberName="m_measuresSlider"
          virtualName="MicroParameterSlider" explicitFocusOrder="0" pos="264 40 36 20"
          bkgcol="fff2f59b" thumbcol="ffc4c86d" min="1" max="32" int="1"
          style="LinearBar" textBoxPos="TextBoxLeft" textBoxEditable="1"
          textBoxWidth="40" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="tempoSlider" id="2a8599a78b9bce37" memberName="m_tempoSlider"
          virtualName="MicroParameterSlider" explicitFocusOrder="0" pos="324 40 56 20"
          bkgcol="fff2f59b" thumbcol="ffc4c86d" min="20" max="240" int="0.10000000000000001"
          style="LinearBar" textBoxPos="TextBoxLeft" textBoxEditable="1"
          textBoxWidth="40" textBoxHeight="20" skewFactor="1"/>
  <LABEL name="tempoLabel" id="49fd6aecaa8ba93e" memberName="m_tempoLabel"
         virtualName="" explicitFocusOrder="0" pos="324 24 56 16" textCol="ff000000"
         edTextCol="ff000000" edBkgCol="0" labelText="TEMPO" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="12" bold="1" italic="0" justification="36"/>
  <LABEL name="viewTypeNoteOffLabel" id="6dbe23427d97287f" memberName="m_viewTypeNoteOffLabel"
         virtualName="" explicitFocusOrder="0" pos="975 188 64 16" textCol="ff000000"
         edTextCol="ff000000" edBkgCol="0" labelText="NOTE-OFF" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="12" bold="1" italic="0" justification="34"/>
  <JUCERCOMP name="viewNoteOffToggle" id="766f9a90956bc85" memberName="m_viewNoteOffToggle"
             virtualName="" explicitFocusOrder="0" pos="1036 190 12 12" sourceFile="ParameterWidgets/SmallGreenToggle.cpp"
             constructorParams=""/>
  <JUCERCOMP name="viewTypeToggleInc" id="31a55b08317fd402" memberName="m_viewTypeToggleInc"
             virtualName="" explicitFocusOrder="0" pos="998 273 25 17" sourceFile="ParameterWidgets/BlackToggle.cpp"
             constructorParams=""/>
  <LABEL name="viewTypeIncLabel" id="13ce0f7478d2cfa1" memberName="m_viewTypeIncLabel"
         virtualName="" explicitFocusOrder="0" pos="966 272 32 16" textCol="ff000000"
         edTextCol="ff000000" edBkgCol="0" labelText="INC" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="12" bold="1" italic="0" justification="34"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
