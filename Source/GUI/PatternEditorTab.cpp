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

    addAndMakeVisible (m_patternEventTable = new TableListBox ("patternEventTable"));

    addAndMakeVisible (m_midiOutComboBox = new ComboBox ("midiOutComboBox"));
    m_midiOutComboBox->setEditableText (false);
    m_midiOutComboBox->setJustificationType (Justification::centredLeft);
    m_midiOutComboBox->setTextWhenNothingSelected (String());
    m_midiOutComboBox->setTextWhenNoChoicesAvailable (TRANS("(no choices)"));
    m_midiOutComboBox->addListener (this);

    addAndMakeVisible (m_midiOutLabel = new Label ("midiOutLabel",
                                                   TRANS("Midi Out:")));
    m_midiOutLabel->setFont (Font (15.00f, Font::plain));
    m_midiOutLabel->setJustificationType (Justification::centredLeft);
    m_midiOutLabel->setEditable (false, false, false);
    m_midiOutLabel->setColour (TextEditor::textColourId, Colours::black);
    m_midiOutLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_panicButton = new TextButton ("panicButton"));
    m_panicButton->setButtonText (TRANS("MIDI Panic!"));
    m_panicButton->addListener (this);


    //[UserPreSize]
	StringArray midiOutNames(MidiOutput::getDevices());
	m_midiOutComboBox->addItemList(MidiOutput::getDevices(), 1);
	m_midiOutComboBox->setTextWhenNothingSelected(midiOutNames[MidiOutput::getDefaultDeviceIndex() + 1]);

	m_patternEventTable->setModel(patternBodyBlock);
	m_patternEventTable->setHeader(m_patternEventTableHeader);
	changeListenerCallback(patternBodyBlock);
	patternBodyBlock->setTableSelectionMidiOutId( m_midiOutComboBox->getSelectedId() > 0 ? m_midiOutComboBox->getSelectedId() - 1 : -1);

	m_patternEventTable->setColour(TableListBox::outlineColourId, Colours::grey);
    //[/UserPreSize]

    setSize (600, 400);


    //[Constructor] You can add your own custom stuff here..
    //[/Constructor]
}

PatternEditorTab::~PatternEditorTab()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
	grooveboxMemory->getPatternBodyBlock()->removeChangeListener(this);
    //[/Destructor_pre]

    m_patternEventTable = nullptr;
    m_midiOutComboBox = nullptr;
    m_midiOutLabel = nullptr;
    m_panicButton = nullptr;


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

    m_patternEventTable->setBounds (8, 40, 700, getHeight() - 40);
    m_midiOutComboBox->setBounds (80, 8, 176, 24);
    m_midiOutLabel->setBounds (8, 8, 72, 24);
    m_panicButton->setBounds (264, 8, 150, 24);
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

    //[UserbuttonClicked_Post]
    //[/UserbuttonClicked_Post]
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
                 variableInitialisers="" snapPixels="8" snapActive="1" snapShown="1"
                 overlayOpacity="0.330" fixedSize="0" initialWidth="600" initialHeight="400">
  <BACKGROUND backgroundColour="0"/>
  <GENERICCOMPONENT name="" id="6aebf3e3738962bd" memberName="m_patternEventTable"
                    virtualName="" explicitFocusOrder="0" pos="8 40 700 40M" class="TableListBox"
                    params="&quot;patternEventTable&quot;"/>
  <COMBOBOX name="midiOutComboBox" id="9b6d2ada3deafb58" memberName="m_midiOutComboBox"
            virtualName="" explicitFocusOrder="0" pos="80 8 176 24" editable="0"
            layout="33" items="" textWhenNonSelected="" textWhenNoItems="(no choices)"/>
  <LABEL name="midiOutLabel" id="b10a8e943634f13a" memberName="m_midiOutLabel"
         virtualName="" explicitFocusOrder="0" pos="8 8 72 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Midi Out:" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         bold="0" italic="0" justification="33"/>
  <TEXTBUTTON name="panicButton" id="7514cd2cffbbc78c" memberName="m_panicButton"
              virtualName="" explicitFocusOrder="0" pos="264 8 150 24" buttonText="MIDI Panic!"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
