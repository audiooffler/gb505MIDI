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
#include "../../GrooveboxMemory/OverallMemoryBlock.h"
//[/Headers]

#include "ToneMixTableTone.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
extern OverallMemoryBlock* grooveboxMemory;
//[/MiscUserDefs]

//==============================================================================
ToneMixTableTone::ToneMixTableTone (const String &componentName, ToneLimitsConstrainer* toneLimitsConstrainer, SynthParts part, Tone tone)
    : Component(componentName),
      m_toneLimitsConstrainer (toneLimitsConstrainer),
      m_part(part),
      m_tone(tone)
{
    addAndMakeVisible (m_resizableBorder = new ResizableBorderComponent (this, m_toneLimitsConstrainer));
    m_resizableBorder->setName ("resizableBorder");


    //[UserPreSize]
	m_changedByParameterValues = false;
	m_keyboardRangeUpperPrm = nullptr;
	m_keyboardRangeLowerPrm = nullptr;
	m_velocityRangeUpperPrm = nullptr;
	m_velocityRangeLowerPrm = nullptr;
	m_resizableBorder->addMouseListener(this, true);
	setAlpha(0.5f);
	m_resizableBorder->setAlpha(0.0f);
	setMouseCursor(MouseCursor::UpDownLeftRightResizeCursor);

	if (grooveboxMemory != nullptr)
	{
		SynthPatchesBlock* synthPatches = grooveboxMemory->getSynthPatchesBlock();
		if (synthPatches != nullptr)
		{
			PatchPartBlock* patchPart = synthPatches->getPatchPartBlockPtr(m_part);
			if (patchPart != nullptr)
			{
				PatchToneBlock* tone = nullptr;
				switch (m_tone)
				{
				case Tone1:
					if (PatchToneBlock* tone1 = patchPart->getPatchToneBlockPtr(Tone1)) tone = tone1;
					break;
				case Tone2:
					if (PatchToneBlock* tone2 = patchPart->getPatchToneBlockPtr(Tone2)) tone = tone2;
					break;
				case Tone3:
					if (PatchToneBlock* tone3 = patchPart->getPatchToneBlockPtr(Tone3)) tone = tone3;
					break;
				case Tone4:
					if (PatchToneBlock* tone4 = patchPart->getPatchToneBlockPtr(Tone4)) tone = tone4;
					break;
				}
				if (tone != nullptr)
				{
					m_velocityRangeLowerPrm = tone->getParameter(0x0C);
					m_velocityRangeUpperPrm = tone->getParameter(0x0D);
					m_keyboardRangeLowerPrm = tone->getParameter(0x0E);
					m_keyboardRangeUpperPrm = tone->getParameter(0x0F);
					m_velocityRangeLowerPrm->addChangeListener(this);
					m_velocityRangeUpperPrm->addChangeListener(this);
					m_keyboardRangeLowerPrm->addChangeListener(this);
					m_keyboardRangeUpperPrm->addChangeListener(this);
				}
			}
		}
	}

    //[/UserPreSize]

    setSize (600, 400);


    //[Constructor] You can add your own custom stuff here..
	// restore current values
	changeListenerCallback(m_keyboardRangeLowerPrm);
    //[/Constructor]
}

ToneMixTableTone::~ToneMixTableTone()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
	m_velocityRangeLowerPrm->removeChangeListener(this);
	m_velocityRangeUpperPrm->removeChangeListener(this);
	m_keyboardRangeLowerPrm->removeChangeListener(this);
	m_keyboardRangeUpperPrm->removeChangeListener(this);
	m_resizableBorder->removeMouseListener(this);
    //[/Destructor_pre]

    m_resizableBorder = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void ToneMixTableTone::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    //[UserPaint] Add your own custom painting code here..

	Rectangle<int> parentBounds(this->getParentComponent()->getBounds());
	Rectangle<int> boundsInParent(this->getBoundsInParent());

	g.setColour(Colours::black);

	// frame rectagle
	g.drawRect(0,0,getWidth(),getHeight());

	// text, "T1", "T2", "T3", or "T4"
	g.setFont(Font(13.00f, Font::plain));
	g.drawText(TRANS(getName()),
		2, 2, 16, 7,
		Justification::centredLeft, true);

    //[/UserPaint]
}

void ToneMixTableTone::resized()
{
    m_resizableBorder->setBounds (0, 0, getWidth() - 0, getHeight() - 0);
    //[UserResized] Add your own custom resize handling here..
	if (!m_changedByParameterValues) { triggerAsyncUpdate(); }
    //[/UserResized]
}

void ToneMixTableTone::moved()
{
    //[UserCode_moved] -- Add your code here...
	if (!m_changedByParameterValues) { triggerAsyncUpdate(); }
    //[/UserCode_moved]
}

void ToneMixTableTone::mouseMove (const MouseEvent& e)
{
    //[UserCode_mouseMove] -- Add your code here...
	#ifdef JUCE_MSVC
	e;
	#endif
	setAlpha(1.0f);
	m_resizableBorder->setAlpha(1.0f);
    //[/UserCode_mouseMove]
}

void ToneMixTableTone::mouseEnter (const MouseEvent& e)
{
    //[UserCode_mouseEnter] -- Add your code here...
	#ifdef JUCE_MSVC
	e;
	#endif

	setAlpha(1.0f);
	m_resizableBorder->setAlpha(1.0f);
	toFront(true);
    //[/UserCode_mouseEnter]
}

void ToneMixTableTone::mouseExit (const MouseEvent& e)
{
    //[UserCode_mouseExit] -- Add your code here...
	#ifdef JUCE_MSVC
	e;
	#endif
	m_resizableBorder->setAlpha(0.0f);
	setAlpha(0.5f);
    //[/UserCode_mouseExit]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
void ToneMixTableTone::setDragMoveMode(bool moveModeOn)
{
	// when starting to drag: stop listening to value changes
	if (moveModeOn)
	{
		m_velocityRangeLowerPrm->removeChangeListener(this);
		m_velocityRangeUpperPrm->removeChangeListener(this);
		m_keyboardRangeLowerPrm->removeChangeListener(this);
		m_keyboardRangeUpperPrm->removeChangeListener(this);
	}
	else
	{
		// listen to changes again
		m_velocityRangeLowerPrm->addChangeListener(this);
		m_velocityRangeUpperPrm->addChangeListener(this);
		m_keyboardRangeLowerPrm->addChangeListener(this);
		m_keyboardRangeUpperPrm->addChangeListener(this);
	}
	m_toneLimitsConstrainer->setDragMoveMode(moveModeOn);
}

void ToneMixTableTone::handleAsyncUpdate()
{
	int keyLower, keyUpper, velLower, velUpper;
	m_toneLimitsConstrainer->getValuesFromBoundingBox(getBoundsInParent(), keyLower, keyUpper, velLower, velUpper);
	m_keyboardRangeLowerPrm->setValue((uint8)roundToInt(keyLower), Parameter::GuiWidget);
	m_keyboardRangeUpperPrm->setValue((uint8)roundToInt(keyUpper), Parameter::GuiWidget);
	m_velocityRangeLowerPrm->setValue((uint8)roundToInt(velLower), Parameter::GuiWidget);
	m_velocityRangeUpperPrm->setValue((uint8)roundToInt(velUpper), Parameter::GuiWidget);
}

void ToneMixTableTone::changeListenerCallback(ChangeBroadcaster* source)
{
	if (source == m_keyboardRangeLowerPrm || source == m_keyboardRangeUpperPrm || source == m_velocityRangeLowerPrm || source == m_velocityRangeUpperPrm)
	{
		m_changedByParameterValues = true;
		Rectangle<int> newBounds = m_toneLimitsConstrainer->getBoundingBoxFromValues(
			m_keyboardRangeLowerPrm->getValue(),
			m_keyboardRangeUpperPrm->getValue(),
			m_velocityRangeLowerPrm->getValue(),
			m_velocityRangeUpperPrm->getValue()
			);
		{
			setBounds(newBounds);
		}
		m_changedByParameterValues = false;
	}
}
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Introjucer information section --

    This is where the Introjucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="ToneMixTableTone" componentName=""
                 parentClasses="public Component, public ChangeListener, public AsyncUpdater"
                 constructorParams="const String &amp;componentName, ToneLimitsConstrainer* toneLimitsConstrainer, SynthParts part, Tone tone"
                 variableInitialisers="Component(componentName),&#10;m_toneLimitsConstrainer (toneLimitsConstrainer),&#10;m_part(part),&#10;m_tone(tone)"
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="0" initialWidth="600" initialHeight="400">
  <METHODS>
    <METHOD name="mouseEnter (const MouseEvent&amp; e)"/>
    <METHOD name="mouseExit (const MouseEvent&amp; e)"/>
    <METHOD name="mouseMove (const MouseEvent&amp; e)"/>
    <METHOD name="moved()"/>
  </METHODS>
  <BACKGROUND backgroundColour="0"/>
  <GENERICCOMPONENT name="resizableBorder" id="284a7c6c696573b1" memberName="m_resizableBorder"
                    virtualName="" explicitFocusOrder="0" pos="0 0 0M 0M" class="ResizableBorderComponent"
                    params="this, m_toneLimitsConstrainer"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
