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


    //[UserPreSize]
	m_patternEventTable->setModel(patternBodyBlock);
	m_patternEventTable->setHeader(m_patternEventTableHeader);
	changeListenerCallback(patternBodyBlock);

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

    m_patternEventTable->setBounds (proportionOfWidth (0.5000f) - (700 / 2), 8, 700, getHeight() - 8);
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
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
                    virtualName="" explicitFocusOrder="0" pos="50%c 8 700 8M" class="TableListBox"
                    params="&quot;patternEventTable&quot;"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
