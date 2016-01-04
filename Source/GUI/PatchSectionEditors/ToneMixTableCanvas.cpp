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

#include "ToneMixTableCanvas.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
ToneMixTableCanvas::ToneMixTableCanvas (const String &componentName, SynthParts part)
    : Component(componentName), m_dragTonesConstrainer (new ToneLimitsConstrainer()),
      m_part(part)
{

    //[UserPreSize]
	addAndMakeVisible(m_tone1 = new ToneMixTableTone("T1", m_dragTonesConstrainer, m_part, Tone::Tone1));
	addAndMakeVisible(m_tone2 = new ToneMixTableTone("T2", m_dragTonesConstrainer, m_part, Tone::Tone2));
	addAndMakeVisible(m_tone3 = new ToneMixTableTone("T3", m_dragTonesConstrainer, m_part, Tone::Tone3));
	addAndMakeVisible(m_tone4 = new ToneMixTableTone("T4", m_dragTonesConstrainer, m_part, Tone::Tone4));
	addAndMakeVisible(m_tone1XFade = new ToneMixTableToneVeloXFade("tone1XFade", m_tone1, m_dragTonesConstrainer, m_part, Tone::Tone1));
	addAndMakeVisible(m_tone2XFade = new ToneMixTableToneVeloXFade("tone2XFade", m_tone2, m_dragTonesConstrainer, m_part, Tone::Tone2));
	addAndMakeVisible(m_tone3XFade = new ToneMixTableToneVeloXFade("tone3XFade", m_tone3, m_dragTonesConstrainer, m_part, Tone::Tone3));
	addAndMakeVisible(m_tone4XFade = new ToneMixTableToneVeloXFade("tone4XFade", m_tone4, m_dragTonesConstrainer, m_part, Tone::Tone4));
	m_tone1->addMouseListener(this, true);
	m_tone2->addMouseListener(this, true);
	m_tone3->addMouseListener(this, true);
	m_tone4->addMouseListener(this, true);
	m_tone4->toFront(true);
	m_tone3->toFront(true);
	m_tone2->toFront(true);
	m_tone1->toFront(true);
    //[/UserPreSize]

    setSize (600, 400);


    //[Constructor] You can add your own custom stuff here..
    //[/Constructor]
}

ToneMixTableCanvas::~ToneMixTableCanvas()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
	m_tone1->removeMouseListener(this);
	m_tone2->removeMouseListener(this);
	m_tone3->removeMouseListener(this);
	m_tone4->removeMouseListener(this);
    //[/Destructor_pre]



    //[Destructor]. You can add your own custom destruction code here..
	m_tone1 = nullptr;
	m_tone2 = nullptr;
	m_tone3 = nullptr;
	m_tone4 = nullptr;
	m_tone1XFade = nullptr;
	m_tone2XFade = nullptr;
	m_tone3XFade = nullptr;
	m_tone4XFade = nullptr;
    //[/Destructor]
}

//==============================================================================
void ToneMixTableCanvas::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
	#ifdef JUCE_MSVC
	g;
	#endif
    //[/UserPrePaint]

    //[UserPaint] Add your own custom painting code here..
	g.setColour(Colours::black.withAlpha(0.125f));
	for (int key = 0; key <= 128; key+=12)
	{
		g.drawVerticalLine(roundToInt(Point<float>((float)key, 1.0f).transformedBy(m_dragTonesConstrainer->getAffineTransformValuesToPixelcoords()).getX()), 0.0f, (float)getHeight());
	}
	for (int vel = 0; vel <= 128; vel+=8)
	{
		g.drawHorizontalLine(roundToInt(Point<float>(1.0f, (float) vel).transformedBy(m_dragTonesConstrainer->getAffineTransformValuesToPixelcoords()).getY()), 0.0f, (float)getWidth());
	}
    //[/UserPaint]
}

void ToneMixTableCanvas::resized()
{
    //[UserResized] Add your own custom resize handling here..
	m_dragTonesConstrainer->setSize(getWidth(), getHeight());
	m_tone1XFade->setSize(getWidth(), getHeight());
	m_tone2XFade->setSize(getWidth(), getHeight());
	m_tone3XFade->setSize(getWidth(), getHeight());
	m_tone4XFade->setSize(getWidth(), getHeight());
    //[/UserResized]
}

void ToneMixTableCanvas::mouseDown (const MouseEvent& e)
{
    //[UserCode_mouseDown] -- Add your code here...
	//DBG("down " + e.eventComponent->getName());
	if (ToneMixTableTone* tone = dynamic_cast<ToneMixTableTone*>(e.eventComponent))
	{
		startDraggingComponent(tone, e);
	}
    //[/UserCode_mouseDown]
}

void ToneMixTableCanvas::mouseDrag (const MouseEvent& e)
{
    //[UserCode_mouseDrag] -- Add your code here...
	//DBG("dragging " + e.eventComponent->getName());
	if (ToneMixTableTone* tone = dynamic_cast<ToneMixTableTone*>(e.eventComponent))
	{
		dragComponent(tone, e, m_dragTonesConstrainer);
	}
    //[/UserCode_mouseDrag]
}

void ToneMixTableCanvas::mouseUp (const MouseEvent& e)
{
    //[UserCode_mouseUp] -- Add your code here...
	if (ToneMixTableTone* tone = dynamic_cast<ToneMixTableTone*>(e.eventComponent))
	{
		//DBG("stop dragging tone");
		tone->setDragMoveMode(false);
	}
    //[/UserCode_mouseUp]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
void ToneMixTableCanvas::startDraggingComponent(Component* componentToDrag, const MouseEvent &/*e*/)
{
	if (ToneMixTableTone* tone = dynamic_cast<ToneMixTableTone*>(componentToDrag))
	{
		//DBG("start dragging tone");
		tone->setDragMoveMode(true);
		Desktop::setMousePosition(tone->getScreenPosition());
	}
}
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Introjucer information section --

    This is where the Introjucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="ToneMixTableCanvas" componentName=""
                 parentClasses="public Component, public ComponentDragger" constructorParams="const String &amp;componentName, SynthParts part"
                 variableInitialisers="Component(componentName), m_dragTonesConstrainer (new ToneLimitsConstrainer()),&#10;m_part(part)"
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="0" initialWidth="600" initialHeight="400">
  <METHODS>
    <METHOD name="mouseDown (const MouseEvent&amp; e)"/>
    <METHOD name="mouseDrag (const MouseEvent&amp; e)"/>
    <METHOD name="mouseUp (const MouseEvent&amp; e)"/>
  </METHODS>
  <BACKGROUND backgroundColour="0"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
