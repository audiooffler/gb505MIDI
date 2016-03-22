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
#include "../GrooveboxLookAndFeel.h"
//[/Headers]

#include "RhySetKeyboardWithList.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
extern OverallMemoryBlock* grooveboxMemory;
extern Waveforms* waveForms;
//[/MiscUserDefs]

//==============================================================================
RhySetKeyboardWithList::RhySetKeyboardWithList ()
{
    //[Constructor_pre] You can add your own custom stuff here..
	m_tableHeader = new TableHeaderComponent();
    //[/Constructor_pre]

    addAndMakeVisible (m_drumNamesTable = new TableListBox ("drumNamesTable", this));
    m_drumNamesTable->setName ("drumNamesTable");


    //[UserPreSize]
	int eachKeyRowHeight = 15;
	m_tableHeader->addColumn("", NoteName, 25, 25, 25, 1);
	m_tableHeader->addColumn("Key", KeyNo, 30, 30, 30, 1);
	m_tableHeader->addColumn("Rhy Group", RhyGrp, 80, 80, 80, 1);
	m_tableHeader->addColumn("Mut", MuteGrp, 27, 27, 27, 1);
	m_tableHeader->addColumn("Waveform", RhyWave, 140, 140, 140, 1);
	m_tableHeader->addColumn("GM Standard Drum", GmDrum, 130, 130, 130, 9);
	m_drumNamesTable->setHeader(m_tableHeader);
	m_drumNamesTable->setHeaderHeight(24);
	m_drumNamesTable->setRowHeight(eachKeyRowHeight);
	m_drumNamesTable->setOutlineThickness(1);
	m_drumNamesTable->getViewport()->setSingleStepSizes(0, eachKeyRowHeight);

	m_drumNamesTable->setColour(TableListBox::backgroundColourId, GrooveboxLookAndFeel::Mc307LcdBackground);
	m_drumNamesTable->setColour(TableListBox::outlineColourId, Colours::grey);
	m_drumNamesTable->selectRow(0);
    //[/UserPreSize]

    setSize (425, 622);


    //[Constructor] You can add your own custom stuff here..
	RhythmSetBlock* rhythmSetBlock = grooveboxMemory->getRhythmSetBlock();
	for (int key = 35; key <= 98; key++)
	{
		RhythmNoteBlock* rhythmNoteBlock = rhythmSetBlock->getRhythmNoteBlockPtr((uint8)key);
		Parameter* waveGroupId = rhythmNoteBlock->getParameter(0x02);
		Parameter* waveNumber = rhythmNoteBlock->getParameter(0x03);
		Parameter* muteGroup = rhythmNoteBlock->getParameter(0x07);
		waveGroupId->addChangeListener(this);
		waveNumber->addChangeListener(this);
		muteGroup->addChangeListener(this);
	}
    //[/Constructor]
}

RhySetKeyboardWithList::~RhySetKeyboardWithList()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    m_drumNamesTable = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void RhySetKeyboardWithList::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.setColour (Colours::black);
    g.drawRect (0, 0, getWidth() - 0, getHeight() - 0, 1);

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void RhySetKeyboardWithList::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    m_drumNamesTable->setBounds (0, 0, getWidth() - 0, getHeight() - 0);
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
int RhySetKeyboardWithList::getNumRows()
{
	return 64; // (35..98)
}

void RhySetKeyboardWithList::paintRowBackground(Graphics& g, int rowNumber, int width, int /*height*/, bool rowIsSelected)
{
	if (rowIsSelected)
	{
		g.fillAll(GrooveboxLookAndFeel::Mc307LcdThumb);
	}

	int key = rowNumber + 35;
	const Line<float> line(0.0f, 0.0f, (float)width, 0.0f);
	const float dashLengths[2] = { 2.0f, 1.0f };
	if (key % 12 == 0){
		g.drawDashedLine(Line<float>(0.0f, 0.0f, (float)width, 0.0f), dashLengths, 2);
	}
}

void RhySetKeyboardWithList::paintCell(Graphics& g, int rowNumber, int columnId, int width, int height, bool rowIsSelected)
{
	int key = rowNumber + 35;
	RhythmGroup rhyGroup = RhythmGroup::UNKNOWN;
	if ((key >= 35 && key <= 36) || (key >= 47 && key <= 48) || (key >= 95 && key <= 96)) rhyGroup = RhythmGroup::BD;
	else if (key == 38 || key == 40 || key == 50 || key == 52 || key == 97 || key == 98) rhyGroup = RhythmGroup::SD;
	else if (key == 39 || key == 51 || key == 94) rhyGroup = RhythmGroup::CLP;
	else if (key == 42 || key == 42 || key == 44 || key == 46 || key == 54 || key == 56 || key == 58) rhyGroup = RhythmGroup::HH;
	else if (key == 61 || key == 63 || key == 64 || key == 65 || key == 67 || key == 69 || key == 71) rhyGroup = RhythmGroup::CYM;
	else if (key == 37 || key == 41 || key == 43 || key == 45 || key == 41 || key == 49 || key == 41 || key == 53 || key == 55 || key == 57 || key == 59 || key == 60 || key == 62 || key == 66 || key == 68 || key == 70 || (key >= 72 && key <= 82)) rhyGroup = RhythmGroup::TOM_PERC;
	else if (key >= 83 && key <= 88) rhyGroup = RhythmGroup::HIT;
	else if (key >= 89 && key <= 93) rhyGroup = RhythmGroup::OTHERS;
	String rhyGrpString = (rhyGroup != RhythmGroup::UNKNOWN && rhyGroup !=RhythmGroup::ALL) ? RhythmNoteBlock::getRhythmGroupString(rhyGroup) : "";
	g.setColour(Colours::black);
	g.setFont(Font((float)m_drumNamesTable->getRowHeight()));
	bool isBlack = MidiMessage::isMidiNoteBlack(key);

	RhythmSetBlock* rhythmSetBlock = grooveboxMemory->getRhythmSetBlock();
	RhythmNoteBlock* rhythmNoteBlock = rhythmSetBlock->getRhythmNoteBlockPtr((uint8)key);
	Parameter* waveGroupId = rhythmNoteBlock->getParameter(0x02);
	Parameter* waveNumber = rhythmNoteBlock->getParameter(0x03);
	Parameter* muteGroup = rhythmNoteBlock->getParameter(0x07);
	String waveText = waveForms->getButtonText(waveForms->getGroupForId(waveGroupId->getValue()), waveNumber->getValue());

	switch (columnId)
	{
	case NoteName:
		if (key % 12 == 0) g.setFont(Font((float)m_drumNamesTable->getRowHeight(), Font::bold));
		g.drawText(MidiMessage::getMidiNoteName(key, true, true, 4), 2, 0, width - 2, height, Justification::centredLeft, false);
		g.drawRect((float)width - 1.0f, 0.0f, 0.5f, (float)height);
		break;
	case KeyNo:
		if (isBlack)
		{
			// center line between white keys up to black key
			g.drawRect(0.0f, height*0.5f, (float)width, 0.5f);
			// fill black, rounded at left site
			g.fillRoundedRectangle(width*0.3f, 0.0f, width*0.7f, (float)height, 2.0f);
			g.fillRect(width*0.3f + 3.0f, 0.0f, width*0.7f, (float)height);
			// switch to white for following text
			g.setColour(GrooveboxLookAndFeel::Mc307LcdBackground);
		}
		else
		{
			// between two white keys, but not between b and c (already dashed bg line)
			if (!MidiMessage::isMidiNoteBlack(key - 1) && key % 12 != 0)
			{
				g.drawRect(0.0f, 0.0f, (float)width, 0.5f);
			}
		}
		g.drawText(String(key), 0, 0, width-2, height, Justification::centredRight, false);
		g.drawRect((float)width-1.0f, 0.0f, 0.5f, (float)height);
		break;
	case RhyGrp:
		g.drawText(rhyGrpString, 4, 0, width-4, height, Justification::centred, false);
		break;
	case MuteGrp:
		g.drawText(muteGroup->getDisplayedValue().replace("OFF",""), 2, 0, width - 2, height, Justification::centred, false);
		break;
	case RhyWave:
		if (rowIsSelected) g.setFont(Font((float)m_drumNamesTable->getRowHeight(),Font::bold));
		g.drawText(waveText, 2, 0, width-2, height, Justification::centredLeft, false);
		break;
	case GmDrum: g.drawText(MidiMessage::getRhythmInstrumentName(key), 2, 0, width, height, Justification::centredLeft, false);
		break;
	}
}

void RhySetKeyboardWithList::selectedRowsChanged(int lastRowSelected)
{
	m_lastRowSelected = lastRowSelected;
    sendChangeMessage();
}

void RhySetKeyboardWithList::changeListenerCallback(ChangeBroadcaster* source)
{
	if (Parameter* param = dynamic_cast<Parameter*>(source))
	{
		if (RhythmNoteBlock* block = dynamic_cast<RhythmNoteBlock*>(param->getBlock()))
		{
			if (param->getAddressOffset() == 0x02 || param->getAddressOffset() == 0x03)
			{
				int key = block->getKey();
				int rowNumber = key - 35;
				repaint(m_drumNamesTable->getCellPosition(drumNamesTableColumnIds::RhyWave, rowNumber, true));
			}
			else if (param->getAddressOffset() == 0x07)
			{
				int key = block->getKey();
				int rowNumber = key - 35;
				repaint(m_drumNamesTable->getCellPosition(drumNamesTableColumnIds::MuteGrp, rowNumber, true));
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

<JUCER_COMPONENT documentType="Component" className="RhySetKeyboardWithList" componentName=""
                 parentClasses="public Component, public TableListBoxModel, public ChangeListener, public ChangeBroadcaster"
                 constructorParams="" variableInitialisers="" snapPixels="8" snapActive="1"
                 snapShown="1" overlayOpacity="0.330" fixedSize="1" initialWidth="425"
                 initialHeight="622">
  <BACKGROUND backgroundColour="0">
    <RECT pos="0 0 0M 0M" fill="solid: 0" hasStroke="1" stroke="1, mitered, butt"
          strokeColour="solid: ff000000"/>
  </BACKGROUND>
  <GENERICCOMPONENT name="drumNamesTable" id="92f14936e8fcfe4a" memberName="m_drumNamesTable"
                    virtualName="" explicitFocusOrder="0" pos="0 0 0M 0M" posRelativeH="46feacaa0f470177"
                    class="TableListBox" params="&quot;drumNamesTable&quot;, this"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
