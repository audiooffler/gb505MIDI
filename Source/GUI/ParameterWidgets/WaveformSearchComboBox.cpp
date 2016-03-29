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
//[/Headers]

#include "WaveformSearchComboBox.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
extern OverallMemoryBlock* grooveboxMemory;
extern Waveforms* waveForms;
//[/MiscUserDefs]

//==============================================================================
WaveformSearchComboBox::WaveformSearchComboBox (const String& componentName, AllParts part, int toneNumber, bool inTable)
    : ParameterComboBox(componentName), m_part(part), m_toneNumber(toneNumber), m_isInTable(inTable)
{
    //[Constructor_pre] You can add your own custom stuff here..
	setEditableText(true);
	m_waveGroupType = nullptr;
	m_waveGroupId = nullptr;
	m_waveNumber = nullptr;
	setScrollWheelEnabled(true);
    //[/Constructor_pre]


    //[UserPreSize]
	setupParameters(part, toneNumber);
    //[/UserPreSize]

    setSize (128, 20);


    //[Constructor] You can add your own custom stuff here..
    //[/Constructor]
}

WaveformSearchComboBox::~WaveformSearchComboBox()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
	if (m_waveGroupType != nullptr) m_waveGroupType->removeChangeListener(this);
	if (m_waveGroupId != nullptr) m_waveGroupId->removeChangeListener(this);
	if (m_waveNumber != nullptr) m_waveNumber->removeChangeListener(this);
    //[/Destructor_pre]



    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void WaveformSearchComboBox::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.setColour (Colours::grey);
    g.strokePath (internalPath1, PathStrokeType (1.000f));

    g.setColour (Colours::grey);
    g.strokePath (internalPath2, PathStrokeType (1.000f));

    g.setColour (Colours::grey);
    g.strokePath (internalPath3, PathStrokeType (0.500f));

    //[UserPaint] Add your own custom painting code here..
    ParameterComboBox::paint(g);
    //[/UserPaint]
}

void WaveformSearchComboBox::resized()
{
    //[UserPreResize] Add your own custom resize code here..
	ParameterComboBox::resized();
    //[/UserPreResize]

    internalPath1.clear();
    internalPath1.startNewSubPath (0.0f, 0.0f);
    internalPath1.lineTo (0.0f, static_cast<float> (getHeight() - 20));
    internalPath1.lineTo (0.0f, static_cast<float> (getHeight()));
    internalPath1.closeSubPath();

    internalPath2.clear();
    internalPath2.startNewSubPath (static_cast<float> (getWidth()), 0.0f);
    internalPath2.lineTo (static_cast<float> (getWidth()), static_cast<float> (getHeight()));
    internalPath2.closeSubPath();

    internalPath3.clear();
    internalPath3.startNewSubPath (static_cast<float> (getWidth() - 12), 0.0f);
    internalPath3.lineTo (static_cast<float> (getWidth() - 12), static_cast<float> (getHeight()));
    internalPath3.closeSubPath();

    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
// allowed toneNumber values are Tone1 = 0x1000, Tone2 = 0x1200, Tone3 = 0x1400, Tone4 = 0x1600 for synth parts or 35..98 for rhythm part
void WaveformSearchComboBox::setupParameters(AllParts part, int toneNumber)
{
	if (grooveboxMemory == nullptr) return;

	if (part == AllParts::PartR)
	{
		if (toneNumber >= 35 && toneNumber <= 98)
		{
			if (grooveboxMemory != nullptr)
			{
				if (RhythmSetBlock* rhyhtmSet = grooveboxMemory->getRhythmSetBlock())
				{
					if (RhythmNoteBlock* noteBlock = rhyhtmSet->getRhythmNoteBlockPtr((uint8)toneNumber))
					{
						m_part = part;
						m_toneNumber = toneNumber;

						if (m_waveGroupType != nullptr) m_waveGroupType->removeChangeListener(this);
						if (m_waveGroupId != nullptr) m_waveGroupId->removeChangeListener(this);
						if (m_waveNumber != nullptr) m_waveNumber->removeChangeListener(this);

						m_waveGroupType = noteBlock->getParameter(0x01);
						m_waveGroupId = noteBlock->getParameter(0x02);
						m_waveNumber = noteBlock->getParameter(0x03);

						populateComboboxItems();
						setSelectedId(waveGroupAndNumberToItemId(waveForms->getGroupForId(m_waveGroupId->getValue()), m_waveNumber->getValue()), dontSendNotification);

						changeListenerCallback(m_waveNumber);
						m_waveGroupType->addChangeListener(this);
						m_waveGroupId->addChangeListener(this);
						m_waveNumber->addChangeListener(this);
					}
				}
			}
		}
	}
	else
	{
		if (SynthPatchesBlock* synthPatches = grooveboxMemory->getSynthPatchesBlock())
		{
			if (PatchPartBlock* patchPart = synthPatches->getPatchPartBlockPtr((SynthParts)part))
			{
				PatchToneBlock* tone = nullptr;
				int toneNumberLabel = 1;
				switch (toneNumber)
				{
				case Tone1:
					if (PatchToneBlock* tone1 = patchPart->getPatchToneBlockPtr(Tone1)) tone = tone1;
					toneNumberLabel = 1;
					break;
				case Tone2:
					if (PatchToneBlock* tone2 = patchPart->getPatchToneBlockPtr(Tone2)) tone = tone2;
					toneNumberLabel = 2;
					break;
				case Tone3:
					if (PatchToneBlock* tone3 = patchPart->getPatchToneBlockPtr(Tone3)) tone = tone3;
					toneNumberLabel = 3;
					break;
				case Tone4:
					if (PatchToneBlock* tone4 = patchPart->getPatchToneBlockPtr(Tone4)) tone = tone4;
					toneNumberLabel = 4;
					break;
				}
				if (tone != nullptr)
				{
					m_part = part;
					m_toneNumber = toneNumber;

					if (m_waveGroupType != nullptr) m_waveGroupType->removeChangeListener(this);
					if (m_waveGroupId != nullptr) m_waveGroupId->removeChangeListener(this);
					if (m_waveNumber != nullptr) m_waveNumber->removeChangeListener(this);

					m_waveGroupType = tone->getParameter(0x01);
					m_waveGroupId = tone->getParameter(0x02);
					m_waveNumber = tone->getParameter(0x03);

					populateComboboxItems();
					setSelectedId(waveGroupAndNumberToItemId(waveForms->getGroupForId(m_waveGroupId->getValue()), m_waveNumber->getValue()),dontSendNotification);

					changeListenerCallback(m_waveNumber);

					m_waveGroupType->addChangeListener(this);
					m_waveGroupId->addChangeListener(this);
					m_waveNumber->addChangeListener(this);
				}
			}
		}
	}
}

// parameter changes of groovebox memory block
void WaveformSearchComboBox::changeListenerCallback(ChangeBroadcaster *source)
{
	if (Parameter* param = dynamic_cast<Parameter*>(source))
	{
		// if one of the parameters changed
		if (param == m_waveGroupType || param == m_waveGroupId || param == m_waveNumber)
		{
			setSelectedId(waveGroupAndNumberToItemId(waveForms->getGroupForId(m_waveGroupId->getValue()), m_waveNumber->getValue()),dontSendNotification);
		}
	}
}

// gui combobox selection change
void WaveformSearchComboBox::comboBoxChanged(ComboBox *comboBoxThatHasChanged)
{
	if (comboBoxThatHasChanged == this)
	{
		if (getSelectedId() > 0)
		{
			Waveforms::WaveGroup waveGroup;
			int waveNumber;
			itemIdToWaveGroupAndNumber(getSelectedId(), waveGroup, waveNumber);
			m_waveGroupId->setValue(waveForms->getGroupId(waveGroup), Parameter::GuiWidget);
			m_waveNumber->setValue((uint8)waveNumber, Parameter::GuiWidget);
		}
	}
}

int WaveformSearchComboBox::waveGroupAndNumberToItemId(Waveforms::WaveGroup waveGroup, int waveNumber)
{
	return (waveForms->getGroupId(waveGroup) << 8) + waveNumber;
}

void WaveformSearchComboBox::itemIdToWaveGroupAndNumber(int id, Waveforms::WaveGroup& waveGroup, int& waveNumber)
{
	waveNumber = id & 0xFF;
	waveGroup = waveForms->getGroupForId((id >> 8) & 0x3);
}

void WaveformSearchComboBox::populateComboboxItems()
{
	clear(dontSendNotification);

	String searchText = getText();

	// split up search text by some more rules than whitespace: make each special char single, split if change number<->letter, split camel case
	juce_wchar current, predecessor;
	bool sucIsLower = false;
	for (int i = searchText.length(); i > 0; i--)
	{

		current = searchText[i];
		predecessor = searchText[i - 1];
		bool curIsSpecial = false, preIsSpecial = false, curIsSpace = false, preIsSpace = false, curIsNum = false, preIsNum = false, curIsLetter = false, preIsLetter = false, curIsUpper = false, preIsUpper = false, curIsLower = false, preIsLower = false;
		if (current >= 48 && current <= 57) curIsNum = true;
		else if (current >= 65 && current <= 90) { curIsUpper = true; curIsLetter = true; }
		else if (current >= 97 && current <= 122) { curIsLower = true; curIsLetter = true; }
		else { curIsSpecial = true; if (current == 32) curIsSpace = true; }
		if (predecessor >= 48 && predecessor <= 57) preIsNum = true;
		else if (predecessor >= 65 && predecessor <= 90){ preIsUpper = true; preIsLetter = true; }
		else if (predecessor >= 97 && predecessor <= 122){ preIsLower = true; preIsLetter = true; }
		else { preIsSpecial = true; if (predecessor == 32) preIsSpace = true; }

		if (!curIsSpace)
		{
			if (curIsSpecial ||				// insert space before special char
				curIsNum && !preIsNum ||	// at start of number
				curIsUpper && preIsLower || // camel case word start
				curIsLetter && !preIsLetter ||  // word of letters starts
				curIsUpper && preIsUpper && sucIsLower)

			{
				searchText = searchText.substring(0, i) + " " + searchText.substring(i, searchText.length());
			}
		}
		sucIsLower = curIsLower;
	}
	StringArray tags(StringArray::fromTokens(searchText.toLowerCase().replaceCharacters(",;|\t\r\n", "      "), " ,;|\t\r\n", "\""));
	tags.removeEmptyStrings();
	tags.removeDuplicates(true);
	String buttonName, buttonLongName;
	String waveName = "";
	String waveLongName = "";
	String displayedItemText = "";
	bool tagFound = false;
	bool noneFoundInGroupYet = true;
	int itemId = 0;
	for (uint8 g = 1; g <= (waveForms->isModelWithGroupC() ? 3 : 2); g++)
	{
		noneFoundInGroupYet = true;
		Waveforms::WaveGroup group = waveForms->getGroupForId(g);

		for (int i = 0; i < waveForms->getGroupSize(group); i++)
		{
			tagFound = false;
			waveName = waveForms->getName(group, i);
			waveLongName = waveForms->getLongName(group, i);

			if (tags.size() == 0 || searchText.trim().isEmpty()) tagFound = true;
			else for (int t = 0; t < tags.size(); t++)
			{
				if (waveName.toLowerCase().contains(tags[t]) || waveLongName.toLowerCase().contains(tags[t]))
				{
					tagFound = true;
					break;
				}
			}

			if (tagFound)
			{
				if (noneFoundInGroupYet)
				{
					if (g > 1)addSeparator();
					addSectionHeading(waveForms->getGroupName(group).replaceCharacter('_', ' '));
					noneFoundInGroupYet = false;
				}
				displayedItemText = waveForms->getGroupChar(group) + String(i+1).paddedLeft('0', 3) + " " + waveName;
				itemId = waveGroupAndNumberToItemId(group, i);
				addItem(displayedItemText, itemId);
			}
		}
	}
}

void WaveformSearchComboBox::showPopup()
{
	if (getSelectedId() == 0)
	{
		populateComboboxItems();
	}
	ParameterComboBox::showPopup();
}

void WaveformSearchComboBox::labelTextChanged(Label *label)
{
	ComboBox::labelTextChanged(label);
	showPopup();
}

void WaveformSearchComboBox::mouseWheelMove(const MouseEvent& e, const MouseWheelDetails& d)
{
	if (m_isInTable)
	{
		getParentComponent()->mouseWheelMove(e, d);
	}
	else ComboBox::mouseWheelMove(e, d);
}

void WaveformSearchComboBox::mouseDown(const MouseEvent& e)
{
	if (m_isInTable)
	{
		getParentComponent()->mouseDown(e);
	}
	ComboBox::mouseDown(e);
}

bool WaveformSearchComboBox::keyPressed(const KeyPress& k)
{
	if (m_isInTable && (k == KeyPress::upKey || k == KeyPress::downKey))
	{
		//getParentComponent()->keyPressed(k);
		return false;
	}
	else return ComboBox::keyPressed(k);
}

WaveformSearchComboBox::WaveformSearchComboBox(const String& componentName, AllParts part, int toneNumber) :
	WaveformSearchComboBox(componentName, part, toneNumber, false)
{

}

//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Introjucer information section --

    This is where the Introjucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="WaveformSearchComboBox" componentName=""
                 parentClasses="public ParameterComboBox" constructorParams="const String&amp; componentName, AllParts part, int toneNumber, bool inTable"
                 variableInitialisers="ParameterComboBox(componentName), m_part(part), m_toneNumber(toneNumber), m_isInTable(inTable) "
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="1" initialWidth="128" initialHeight="20">
  <BACKGROUND backgroundColour="0">
    <PATH pos="0 0 100 100" fill="solid: 0" hasStroke="1" stroke="1, mitered, butt"
          strokeColour="solid: ff808080" nonZeroWinding="1">s 0 0 l 0 20R l 0 0R x</PATH>
    <PATH pos="0 0 100 100" fill="solid: 0" hasStroke="1" stroke="1, mitered, butt"
          strokeColour="solid: ff808080" nonZeroWinding="1">s 0R 0 l 0R 0R x</PATH>
    <PATH pos="0 0 100 100" fill="solid: 0" hasStroke="1" stroke="0.5, mitered, butt"
          strokeColour="solid: ff808080" nonZeroWinding="1">s 12R 0 l 12R 0R x</PATH>
  </BACKGROUND>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
