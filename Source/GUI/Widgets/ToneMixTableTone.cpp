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
//[/Headers]

#include "ToneMixTableTone.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
ToneMixTableTone::ToneMixTableTone (const String &componentName, ToneLimitsConstrainer* toneLimitsConstrainer)
    : Component(componentName),
      m_toneLimitsConstrainer (toneLimitsConstrainer)
{
    addAndMakeVisible (m_resizableBorder = new ResizableBorderComponent (this, m_toneLimitsConstrainer));
    m_resizableBorder->setName ("resizableBorder");


    //[UserPreSize]
	m_resizableBorder->addMouseListener(this, true);
	setAlpha(0.5f);
	m_resizableBorder->setAlpha(0.0f);
	setMouseCursor(MouseCursor::UpDownLeftRightResizeCursor);

    //[/UserPreSize]

    setSize (600, 400);


    //[Constructor] You can add your own custom stuff here..
    //[/Constructor]
}

ToneMixTableTone::~ToneMixTableTone()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
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
	moved();
    //[/UserResized]
}

void ToneMixTableTone::moved()
{
    //[UserCode_moved] -- Add your code here...
	Rectangle<int> boundsInParent(getBoundsInParent());
	Point<float> lowKeyAndVelocity = m_toneLimitsConstrainer->transformCoordToKeyVelocity(Point<float>((float)boundsInParent.getX(), (float)boundsInParent.getBottom()));
	Point<float> upperKeyAndVelocity = m_toneLimitsConstrainer->transformCoordToKeyVelocity(Point<float>((float)boundsInParent.getRight() - 1, (float)boundsInParent.getY()));
	m_keyRangeLower = (uint8) lowKeyAndVelocity.getX();
	m_keyRangeUpper = (uint8) upperKeyAndVelocity.getX();
	m_velocityRangeUpper = (uint8) upperKeyAndVelocity.getY();
	m_velocityRangeLower = (uint8) lowKeyAndVelocity.getY();
	sendChangeMessage();
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
void ToneMixTableTone::setVelocityRangesSwitch(uint8 value)
{
	m_velocityRangesSwitch = value;
	setSize(getWidth(), getHeight());
	repaint();
}

void ToneMixTableTone::setVeloCrossfade(uint8 value)
{
	m_veloCrossfade = value;
	setSize(getWidth(), getHeight());
	repaint();
}

void ToneMixTableTone::setVelocityRangeLower(uint8 value)
{
	m_velocityRangeLower = value;
	Point<float> pUpper = m_toneLimitsConstrainer->transformKeyVelocityToCoord(0, (int)m_velocityRangeUpper + 1);
	Point<float> pLower = m_toneLimitsConstrainer->transformKeyVelocityToCoord(0, (int)m_velocityRangeLower);
	setTopLeftPosition((int)getX(), (int)pUpper.getY());
	setSize(getWidth(), (int)(pLower.getY() - pUpper.getY()));
	repaint();
}

void ToneMixTableTone::setVelocityRangeUpper(uint8 value)
{
	m_velocityRangeUpper = value;
	Point<float> pUpper = m_toneLimitsConstrainer->transformKeyVelocityToCoord(0, (int)m_velocityRangeUpper + 1);
	Point<float> pLower = m_toneLimitsConstrainer->transformKeyVelocityToCoord(0, (int)m_velocityRangeLower);
	setTopLeftPosition((int)getX(), (int)pUpper.getY());
	setSize(getWidth(), (int)(pLower.getY() - pUpper.getY()));
	repaint();
}

void ToneMixTableTone::setKeyRangeLower(uint8 value)
{
	m_keyRangeLower = value;
	Point<float> pLower = m_toneLimitsConstrainer->transformKeyVelocityToCoord((int)m_keyRangeLower, 0);
	Point<float> pUpper = m_toneLimitsConstrainer->transformKeyVelocityToCoord((int)m_keyRangeUpper + 1, 0);
	setTopLeftPosition((int)pLower.getX(), (int)getY());
	setSize((int)(pUpper.getX() - pLower.getX()), getHeight());
	repaint();
}

void ToneMixTableTone::setKeyRangeUpper(uint8 value)
{
	m_keyRangeUpper = value;
	Point<float> pLower = m_toneLimitsConstrainer->transformKeyVelocityToCoord((int)m_keyRangeLower, 0);
	Point<float> pUpper = m_toneLimitsConstrainer->transformKeyVelocityToCoord((int)m_keyRangeUpper + 1, 0);
	setTopLeftPosition((int)pLower.getX(), getY());
	setSize((int)(pUpper.getX() - pLower.getX()), getHeight());
	repaint();
}

void ToneMixTableTone::setToneLevel(uint8 value)
{
	m_toneLevel = value;
	setSize(getWidth(), getHeight());
	repaint();
}

void ToneMixTableTone::setBiasPointKey(uint8 value)
{
	m_biasPointKey = value;
	setSize(getWidth(), getHeight());
	repaint();
}

void ToneMixTableTone::setBiasDirection(uint8 value)
{
	m_biasDirection = value;
	setSize(getWidth(), getHeight());
	repaint();
}

void ToneMixTableTone::setBiasLevel(uint8 value)
{
	m_biasLevel = value;
	setSize(getWidth(), getHeight());
	repaint();
}
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Introjucer information section --

    This is where the Introjucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="ToneMixTableTone" componentName=""
                 parentClasses="public Component, public ChangeBroadcaster" constructorParams="const String &amp;componentName, ToneLimitsConstrainer* toneLimitsConstrainer"
                 variableInitialisers="Component(componentName),&#10;m_toneLimitsConstrainer (toneLimitsConstrainer)"
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
