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
#include "../ParameterWidgets/WaveformSearchComboBox.h"
#include "../ParameterWidgets/MicroParameterSlider.h"
#include "../ParameterWidgets/SmallGreenToggle.h"
#include "../../GrooveboxMemory/CopyableTone.h"
//[/Headers]

#include "RhySetKeyboardWithList.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
extern OverallMemoryBlock* grooveboxMemory;
extern Waveforms* waveForms;
extern ApplicationCommandManager* applicationCommandManager;
extern CopyableTone* copyableToneClipboad;
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
	int eachKeyRowHeight = 17;
	m_tableHeader->addColumn("", NoteName, 32, 32, 32, 1);
	m_tableHeader->addColumn("Key", KeyNo, 32, 32, 32, 1);
	m_tableHeader->addColumn("Rhy Group", RhyGrp, 80, 80, 80, 1);
	m_tableHeader->addColumn("MutG", MuteGrp, 36, 36, 36, 1);
	m_tableHeader->addColumn("Waveform", RhyWave, 140, 140, 140, 1);
	m_tableHeader->addColumn("GM Standard Drum", GmDrum, 130, 130, 130, 9);
	m_tableHeader->addColumn("LEVEL", Level, 48, 48, 48, 1);
	m_tableHeader->addColumn("PAN", Pan, 48, 48, 48, 1);
	m_tableHeader->addColumn("REVERB", Rev, 48, 48, 48, 1);
	m_tableHeader->addColumn("DELAY", Dly, 48, 48, 48, 1);
	m_tableHeader->addColumn("M-FX", MFX, 30, 30, 30, 1);
	m_tableHeader->setColumnVisible(GmDrum, false);
	m_drumNamesTable->setHeader(m_tableHeader);
	m_drumNamesTable->setHeaderHeight(24);
	m_drumNamesTable->setRowHeight(eachKeyRowHeight);
	m_drumNamesTable->setOutlineThickness(1);
	m_drumNamesTable->getViewport()->setSingleStepSizes(0, eachKeyRowHeight);

	m_drumNamesTable->setColour(TableListBox::backgroundColourId, GrooveboxLookAndFeel::Mc307LcdBackground);
	m_drumNamesTable->setColour(TableListBox::outlineColourId, Colours::grey);
	m_drumNamesTable->selectRow(0);
	m_drumNamesTable->addMouseListener(this, true);
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

	applicationCommandManager->registerAllCommandsForTarget(this);
    //[/Constructor]
}

RhySetKeyboardWithList::~RhySetKeyboardWithList()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
	RhythmSetBlock* rhythmSetBlock = grooveboxMemory->getRhythmSetBlock();
	for (int key = 35; key <= 98; key++)
	{
		RhythmNoteBlock* rhythmNoteBlock = rhythmSetBlock->getRhythmNoteBlockPtr((uint8)key);
		Parameter* waveGroupId = rhythmNoteBlock->getParameter(0x02);
		Parameter* waveNumber = rhythmNoteBlock->getParameter(0x03);
		Parameter* muteGroup = rhythmNoteBlock->getParameter(0x07);
		waveGroupId->removeChangeListener(this);
		waveNumber->removeChangeListener(this);
		muteGroup->removeChangeListener(this);
	}
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

void RhySetKeyboardWithList::mouseMove (const MouseEvent& e)
{
    //[UserCode_mouseMove] -- Add your code here...
	if (dynamic_cast<WaveformSearchComboBox*>(e.eventComponent) || dynamic_cast<WaveformSearchComboBox*>(e.eventComponent->getParentComponent()))
	{
		if (getMouseCursor() != MouseCursor::PointingHandCursor && m_tableHeader->getColumnIdAtX(e.x) == RhyGrp)
		{
			e.eventComponent->setMouseCursor(MouseCursor::PointingHandCursor);
		}
		else if (getMouseCursor() == MouseCursor::PointingHandCursor && m_tableHeader->getColumnIdAtX(e.x) != RhyGrp)
		{
			e.eventComponent->setMouseCursor(MouseCursor::NormalCursor);
		}
	}
    //[/UserCode_mouseMove]
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
	RhythmGroup rhyGroup = RhythmNoteBlock::getRhythmGroup((uint8) key);
	String rhyGrpString = (rhyGroup != RhythmGroup::UNKNOWN && rhyGroup !=RhythmGroup::ALL) ? RhythmNoteBlock::getRhythmGroupString(rhyGroup) : "";
	g.setColour(Colours::black);
	g.setFont(Font(14.0f));
	bool isBlack = MidiMessage::isMidiNoteBlack(key);

	RhythmSetBlock* rhythmSetBlock = grooveboxMemory->getRhythmSetBlock();
	RhythmNoteBlock* rhythmNoteBlock = rhythmSetBlock->getRhythmNoteBlockPtr((uint8)key);
	Parameter* waveGroupId = rhythmNoteBlock->getParameter(0x02);
	Parameter* waveNumber = rhythmNoteBlock->getParameter(0x03);
	Parameter* muteGroup = rhythmNoteBlock->getParameter(0x07);
	String waveText = waveForms->getButtonText(waveForms->getGroupForId(waveGroupId->getValue()), waveNumber->getValue());

	String keyName = MidiMessage::getMidiNoteName(key, true, true, 4);
	if (!keyName.containsChar('#')) keyName = keyName.substring(0,1) + " " + keyName.substring(1);
	switch (columnId)
	{
	case NoteName:
		if (key % 12 == 0) g.setFont(Font(14.0f, Font::bold));
		g.setFont(Font(Font::getDefaultMonospacedFontName(),13.5,0));
		g.drawText(keyName, 0, 0, width, height, Justification::centred, false);
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
		g.drawText(String(key), 0, 0, width - 2, height, Justification::centredRight, false);
		g.drawRect((float)width - 1.0f, 0.0f, 0.5f, (float)height);
		break;
	case RhyGrp:
		g.drawText(rhyGrpString, 4, 0, width - 4, height, Justification::centredLeft, false);
		g.drawRect((float)width - 1.0f, 0.0f, 0.5f, (float)height);
		break;
	case MuteGrp:
		g.drawText(muteGroup->getDisplayedValue().replace("OFF", ""), 2, 0, width - 2, height, Justification::centred, false);
		g.drawRect((float)width - 1.0f, 0.0f, 0.5f, (float)height);
		break;
	case RhyWave:
		if (rowIsSelected) g.setFont(Font(14.0f, Font::bold));
		g.drawText(waveText, 2, 0, width - 2, height, Justification::centredLeft, false);
		g.drawRect((float)width - 1.0f, 0.0f, 0.5f, (float)height);
		break;
	case GmDrum:
		g.drawText(MidiMessage::getRhythmInstrumentName(key), 2, 0, width, height, Justification::centredLeft, false);
		g.drawRect((float)width - 1.0f, 0.0f, 0.5f, (float)height);
		break;
	case Level:
		g.drawRect((float)width - 1.0f, 0.0f, 0.5f, (float)height);
		break;
	case Pan:
		g.drawRect((float)width - 1.0f, 0.0f, 0.5f, (float)height);
		break;
	case Rev:
		g.drawRect((float)width - 1.0f, 0.0f, 0.5f, (float)height);
		break;
	case Dly:
		g.drawRect((float)width - 1.0f, 0.0f, 0.5f, (float)height);
		break;
	case MFX:
		g.drawRect((float)width - 1.0f, 0.0f, 0.5f, (float)height);
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

Component* RhySetKeyboardWithList::refreshComponentForCell(int rowNumber, int columnId, bool isRowSelected, Component *existingComponentToUpdate)
{
	RhythmSetBlock* rhythmSetBlock = grooveboxMemory->getRhythmSetBlock();
	RhythmNoteBlock* rhythmNoteBlock = rhythmSetBlock->getRhythmNoteBlockPtr((uint8)rowNumber + 35);
	if (columnId == drumNamesTableColumnIds::MuteGrp)
	{
		if (existingComponentToUpdate != nullptr)
		{
			if (MicroParameterSlider* existingSlider = static_cast<MicroParameterSlider*>(existingComponentToUpdate))
			{
				if (existingSlider->getParamPtr() != nullptr && existingSlider->getParamPtr()->getBlock() == rhythmNoteBlock)
				{
					if (isRowSelected) existingComponentToUpdate->grabKeyboardFocus();
					return existingComponentToUpdate;
				}
				else
				{
					existingSlider->setParameter(rhythmNoteBlock->getParameter(0x07));
					return existingSlider;
				}
			}
		}
		MicroParameterSlider* slider = new MicroParameterSlider("muteGrpSlider", true);
		slider->setParameter(rhythmNoteBlock->getParameter(0x07));
		return slider;
	}
	else if (columnId == drumNamesTableColumnIds::RhyWave)
	{
		if (existingComponentToUpdate != nullptr)
		{
			if (WaveformSearchComboBox* existingCombo = static_cast<WaveformSearchComboBox*>(existingComponentToUpdate))
			{
				if (existingCombo->getParamPtr() != nullptr && existingCombo->getParamPtr()->getBlock() == rhythmNoteBlock)
				{
					if (isRowSelected) existingComponentToUpdate->grabKeyboardFocus();
					return existingComponentToUpdate;
				}
				else
				{
					existingCombo->setupParameters(PartR, rowNumber + 35);
					return existingCombo;
				}
			}
		}
		WaveformSearchComboBox* newCombo = new WaveformSearchComboBox("waveformSearchComboBox", PartR, rowNumber + 35, true);
		newCombo->setColour(ComboBox::outlineColourId, Colours::transparentBlack);
		newCombo->setColour(ComboBox::backgroundColourId, Colours::transparentBlack);
		newCombo->setWantsKeyboardFocus(true);
		return newCombo;
	}
	else if (columnId == drumNamesTableColumnIds::Level)
	{
		if (existingComponentToUpdate != nullptr)
		{
			if (MicroParameterSlider* existingSlider = static_cast<MicroParameterSlider*>(existingComponentToUpdate))
			{
				if (existingSlider->getParamPtr() != nullptr && existingSlider->getParamPtr()->getBlock() == rhythmNoteBlock)
				{
					if (isRowSelected) existingComponentToUpdate->grabKeyboardFocus();
					return existingComponentToUpdate;
				}
				else
				{
					existingSlider->setParameter(rhythmNoteBlock->getParameter(0x29));
					return existingSlider;
				}
			}
		}
		MicroParameterSlider* slider = new MicroParameterSlider("levelSlider", true);
		slider->setParameter(rhythmNoteBlock->getParameter(0x29));
		return slider;
	}
	else if (columnId == drumNamesTableColumnIds::Pan)
	{
		if (existingComponentToUpdate != nullptr)
		{
			if (MicroParameterSlider* existingSlider = static_cast<MicroParameterSlider*>(existingComponentToUpdate))
			{
				if (existingSlider->getParamPtr() != nullptr && existingSlider->getParamPtr()->getBlock() == rhythmNoteBlock)
				{
					if (isRowSelected) existingComponentToUpdate->grabKeyboardFocus();
					return existingComponentToUpdate;
				}
				else
				{
					existingSlider->setParameter(rhythmNoteBlock->getParameter(0x33));
					return existingSlider;
				}
			}
		}
		MicroParameterSlider* slider = new MicroParameterSlider("panSlider", true);
		slider->setParameter(rhythmNoteBlock->getParameter(0x33));
		return slider;
	}
	else if (columnId == drumNamesTableColumnIds::Rev)
	{
		if (existingComponentToUpdate != nullptr)
		{
			if (MicroParameterSlider* existingSlider = static_cast<MicroParameterSlider*>(existingComponentToUpdate))
			{
				if (existingSlider->getParamPtr() != nullptr && existingSlider->getParamPtr()->getBlock() == rhythmNoteBlock)
				{
					if (isRowSelected) existingComponentToUpdate->grabKeyboardFocus();
					return existingComponentToUpdate;
				}
				else
				{
					existingSlider->setParameter(rhythmNoteBlock->getParameter(0x39));
					return existingSlider;
				}
			}
		}
		MicroParameterSlider* slider = new MicroParameterSlider("revSlider", true);
		slider->setParameter(rhythmNoteBlock->getParameter(0x39));
		return slider;
	}
	else if (columnId == drumNamesTableColumnIds::Dly)
	{
		if (existingComponentToUpdate != nullptr)
		{
			if (MicroParameterSlider* existingSlider = static_cast<MicroParameterSlider*>(existingComponentToUpdate))
			{
				if (existingSlider->getParamPtr() != nullptr && existingSlider->getParamPtr()->getBlock() == rhythmNoteBlock)
				{
					if (isRowSelected) existingComponentToUpdate->grabKeyboardFocus();
					return existingComponentToUpdate;
				}
				else
				{
					existingSlider->setParameter(rhythmNoteBlock->getParameter(0x38));
					return existingSlider;
				}
			}
		}
		MicroParameterSlider* slider = new MicroParameterSlider("dlySlider", true);
		slider->setParameter(rhythmNoteBlock->getParameter(0x38));
		return slider;
	}
	else if (columnId == drumNamesTableColumnIds::MFX)
	{
		if (existingComponentToUpdate != nullptr)
		{
			if (SmallGreenToggle* existingToggle = static_cast<SmallGreenToggle*>(existingComponentToUpdate))
			{
				if (existingToggle->getParamPtr() != nullptr && existingToggle->getParamPtr()->getBlock() == rhythmNoteBlock)
				{
					if (isRowSelected) existingComponentToUpdate->grabKeyboardFocus();
					return existingComponentToUpdate;
				}
				else
				{
					existingToggle->setParameter(rhythmNoteBlock->getParameter(0x36));
					return existingToggle;
				}
			}
		}
		SmallGreenToggle* toggle = new SmallGreenToggle("mfxToggle", true);
		toggle->setBounds(toggle->getBounds().withWidth(12));
		toggle->setParameter(rhythmNoteBlock->getParameter(0x36));
		return toggle;
	}
	else return nullptr;
}

void RhySetKeyboardWithList::cellClicked(int rowNumber, int columnId, const MouseEvent& e)
{
	if (columnId!=MuteGrp && columnId < Level && e.mods.isPopupMenu())
	{
		int keyNumber = rowNumber + 35;

		PopupMenu menu;
		menu.addCommandItem(applicationCommandManager, initialiseTone);
		menu.addSeparator();
		menu.addCommandItem(applicationCommandManager, copyTone);
		menu.addCommandItem(applicationCommandManager, pasteTone);
		menu.addCommandItem(applicationCommandManager, swapTone);
		Rectangle<int> area = m_drumNamesTable->getScreenBounds();
		Rectangle<int> cellPos = m_drumNamesTable->getCellPosition(columnId, rowNumber, true);
		area.setSize(0, 0);
		area.translate(0,cellPos.getY());
		area.translate((int)e.position.x, (int)e.position.y);
		menu.showMenuAsync(PopupMenu::Options().withTargetScreenArea(area), nullptr);
	}
}

ApplicationCommandTarget* RhySetKeyboardWithList::getNextCommandTarget()
{
	// this will return the next parent component that is an ApplicationCommandTarget (in this
	// case, there probably isn't one, but it's best to use this method in your own apps).
	if (ApplicationCommandTarget* foundTarget = findFirstTargetParentComponent())
	{
		return foundTarget;
	}
	else return dynamic_cast<ApplicationCommandTarget*>(JUCEApplication::getInstance());
}

void RhySetKeyboardWithList::getAllCommands(Array <CommandID>& commands)
{
	// this returns the set of all commands that this target can perform..
	const CommandID ids[] = { initialiseTone, copyTone, pasteTone, swapTone };
	commands.addArray(ids, numElementsInArray(ids));
}

void RhySetKeyboardWithList::getCommandInfo(CommandID commandID, ApplicationCommandInfo& result)
{
	const String category("tone management");
	switch (commandID)
	{
	case initialiseTone:
		result.setInfo("Initialise", "Resets all tone parameters.", category, 0);
		//result.addDefaultKeypress('i', ModifierKeys::commandModifier);
		//result.setActive(!grooveboxMemory->getPatternBodyBlock()->isPatternEmpty());
		break;
	case copyTone:
		result.setInfo("Copy", "Copies tone to clipboard.", category, 0);
		break;
	case pasteTone:
		result.setInfo("Paste", "Paste tone from clipboard", category, 0);
		result.setActive(copyableToneClipboad != nullptr);
		break;
	case swapTone:
		result.setInfo("Swap", "Swap with origin of copied tone.", category, 0);
		result.setActive(copyableToneClipboad!=nullptr);
		break;
	default: break;
	}
}

bool RhySetKeyboardWithList::perform(const InvocationInfo& info)
{
	switch (info.commandID)
	{
	case initialiseTone:
		break;
	case copyTone:
		if (RhythmSetBlock* rhythmSetBlock = grooveboxMemory->getRhythmSetBlock())
		{
			if (RhythmNoteBlock* rhythmNoteBlock = rhythmSetBlock->getRhythmNoteBlockPtr((uint8)m_lastRowSelected + 35))
			{
				if (copyableToneClipboad != nullptr) deleteAndZero(copyableToneClipboad);
				copyableToneClipboad = new CopyableTone(rhythmNoteBlock);
				return true;
			}
		}
		break;
	case pasteTone:
		if (copyableToneClipboad != nullptr)
		{ 
			copyableToneClipboad->copyTo(PartR, (uint8)m_lastRowSelected + 35);
			return true;
		}
		break;
	case swapTone:
		if (copyableToneClipboad != nullptr)
		{
			copyableToneClipboad->swapWith(PartR, (uint8)m_lastRowSelected + 35);
			return true;
		}
		break;
	default: break;
	}
	return false;
}
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Introjucer information section --

    This is where the Introjucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="RhySetKeyboardWithList" componentName=""
                 parentClasses="public Component, public TableListBoxModel, public ChangeListener, public ChangeBroadcaster, public ApplicationCommandTarget"
                 constructorParams="" variableInitialisers="" snapPixels="8" snapActive="1"
                 snapShown="1" overlayOpacity="0.330" fixedSize="1" initialWidth="425"
                 initialHeight="622">
  <METHODS>
    <METHOD name="mouseMove (const MouseEvent&amp; e)"/>
  </METHODS>
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
