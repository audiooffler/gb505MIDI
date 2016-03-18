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
#include "../../GrooveboxMemory/PatternBodyBlock.h"
//[/Headers]

#include "RhySetKeyboardWithList.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
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
	m_tableHeader->addColumn("Octave C", OctaveC, 20,20);
	m_tableHeader->addColumn("Key#", KeyNo, 30);
	m_tableHeader->addColumn("Rhy Group", RhyGrp, 80);
	m_tableHeader->addColumn("Waveform", RhyWave, 60);
	m_tableHeader->addColumn("GM Drum", GmDrum, 120);
	m_drumNamesTable->setHeader(m_tableHeader);
	m_drumNamesTable->setHeaderHeight(0);
	m_drumNamesTable->setRowHeight(eachKeyRowHeight);
    //[/UserPreSize]

    setSize (600, 400);


    //[Constructor] You can add your own custom stuff here..
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

    m_drumNamesTable->setBounds (4, 4, 150, getHeight() - 8);
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
int RhySetKeyboardWithList::getNumRows()
{
	return 64; // (35..98)
}

void RhySetKeyboardWithList::paintRowBackground(Graphics& g, int rowNumber, int width, int height, bool rowIsSelected)
{
	//if (rowNumber = KeyNo)
	//{
	//	g.setColour(Colours::grey.withAlpha(0.5f));
	//	g.drawRect(0, 0, width, height);
	//}

}

void RhySetKeyboardWithList::paintCell(Graphics& g, int rowNumber, int columnId, int width, int height, bool rowIsSelected)
{
	int key = rowNumber + 35;
	PatternBodyBlock::RhythmGroup rhyGroup = PatternBodyBlock::Rhythm_Group_Unknown;
	if ((key >= 35 && key <= 36) || (key >= 47 && key <= 48) || (key >= 95 && key <= 96)) rhyGroup = PatternBodyBlock::Rhythm_Group_BD;
	else if (key == 38 || key == 40 || key == 50 || key == 52 || key == 97 || key == 98) rhyGroup = PatternBodyBlock::Rhythm_Group_SD;
	else if (key == 39 || key == 51 || key == 94) rhyGroup = PatternBodyBlock::Rhythm_Group_CLP;
	else if (key == 42 || key == 42 || key == 44 || key == 46 || key == 54 || key == 56 || key == 58) rhyGroup = PatternBodyBlock::Rhythm_Group_HH;
	else if (key == 61 || key == 63 || key == 64 || key == 65 || key == 67 || key == 69 || key == 71) rhyGroup = PatternBodyBlock::Rhythm_Group_CYM;
	else if (key == 37 || key == 41 || key == 43 || key == 45 || key == 41 || key == 49 || key == 41 || key == 53 || key == 55 || key == 57 || key == 59 || key == 60 || key == 62 || key == 66 || key == 68 || key == 70 || (key >= 72 && key <= 82)) rhyGroup = PatternBodyBlock::Rhythm_Group_TomPerc;
	else if (key >= 83 && key <= 88) rhyGroup = PatternBodyBlock::Rhythm_Group_Hit;
	else if (key >= 89 && key <= 93) rhyGroup = PatternBodyBlock::Rhythm_Group_Others;
	String rhyGrpString = rhyGroup == PatternBodyBlock::Rhythm_Group_Unknown ? "" : PatternBodyBlock::PatternEventData::getRhythmGroupString(rhyGroup);
	g.setColour(Colours::black);
	g.setFont(Font(m_drumNamesTable->getRowHeight()));
	bool isBlack = MidiMessage::isMidiNoteBlack(key);
	switch (columnId)
	{
	case OctaveC:
		if (key % 12 == 0) 
			g.drawText(MidiMessage::getMidiNoteName(key,false,true,4), 0, 0, width-2, height, Justification::centredRight, false);
		break;
	case KeyNo: 
		// left key front line
		g.drawRect(0.0f, 0.0f, 0.5f, (float)height-0.0f);
		if (isBlack)
		{
			// center line between white keys up to black key
			g.drawRect(0.0f, height*0.5f, (float)width, 0.5f);
			// fill black, rounded at left site
			g.fillRoundedRectangle(width*0.3f, 0.0f, width*0.7f, height, 2.0f);
			g.fillRect(width*0.3f + 3.0f, 0.0f, width*0.7f, (float)height);
			// switch to white for following text
			g.setColour(Colours::white);
		}
		else
		{
			// between two white leys
			if (!MidiMessage::isMidiNoteBlack(key - 1))
			{
				g.drawRect(1.0f, 0.0f, (float)width-1.0f, 0.5f);
			}
		}
		g.drawText(String(key), 0, 0, width-2, height, Justification::centredRight, false);
		break;
	case RhyGrp: 
		// left border
		g.drawRect(0.0f, 0.0f, 0.5f, (float)height);
		g.drawText(rhyGrpString, 2.0f, 0, width-4.0f, height, Justification::centredLeft, false);
		break;
	case RhyWave: g.drawText(String(key), 0, 0, width, height, Justification::centredRight, false);
		break;
	case GmDrum: g.drawText(MidiMessage::getRhythmInstrumentName(key), 0, 0, width, height, Justification::centredLeft, false);
		break;
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
                 parentClasses="public Component, public TableListBoxModel" constructorParams=""
                 variableInitialisers="" snapPixels="8" snapActive="1" snapShown="1"
                 overlayOpacity="0.330" fixedSize="0" initialWidth="600" initialHeight="400">
  <BACKGROUND backgroundColour="0">
    <RECT pos="0 0 0M 0M" fill="solid: 0" hasStroke="1" stroke="1, mitered, butt"
          strokeColour="solid: ff000000"/>
  </BACKGROUND>
  <GENERICCOMPONENT name="drumNamesTable" id="92f14936e8fcfe4a" memberName="m_drumNamesTable"
                    virtualName="" explicitFocusOrder="0" pos="4 4 150 8M" posRelativeH="46feacaa0f470177"
                    class="TableListBox" params="&quot;drumNamesTable&quot;, this"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
