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
ToneMixTableCanvas::ToneMixTableCanvas (const String &componentName)
    : Component(componentName), m_dragTonesConstrainer (new ToneLimitsConstrainer())
{
    addAndMakeVisible (m_tone1 = new ToneMixTableTone ("T1", m_dragTonesConstrainer));
    addAndMakeVisible (m_tone2 = new ToneMixTableTone ("T2", m_dragTonesConstrainer));
    addAndMakeVisible (m_tone3 = new ToneMixTableTone ("T3", m_dragTonesConstrainer));
    addAndMakeVisible (m_tone4 = new ToneMixTableTone ("T4", m_dragTonesConstrainer));
    addAndMakeVisible (m_tone1XFade = new ToneMixTableToneVeloXFade ("tone1XFade", m_tone1));
    addAndMakeVisible (m_tone2XFade = new ToneMixTableToneVeloXFade ("tone2XFade", m_tone2));
    addAndMakeVisible (m_tone3XFade = new ToneMixTableToneVeloXFade ("tone3XFade", m_tone3));
    addAndMakeVisible (m_tone4XFade = new ToneMixTableToneVeloXFade ("tone4XFade", m_tone4));

    //[UserPreSize]
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
	//m_dragTonesConstrainer->setMinimumHeight((int)(((float)getHeight() - 48.0f) / 128.0f));
	//m_dragTonesConstrainer->setMinimumWidth((int)(((float)getWidth()) / 128.0f));
	//m_dragTonesConstrainer->setMinimumOnscreenAmounts(0xffffff, 0xffffff, 0xffffff, 0xffffff);
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

    m_tone1 = nullptr;
    m_tone2 = nullptr;
    m_tone3 = nullptr;
    m_tone4 = nullptr;
    m_tone1XFade = nullptr;
    m_tone2XFade = nullptr;
    m_tone3XFade = nullptr;
    m_tone4XFade = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void ToneMixTableCanvas::paint (Graphics& /*g*/)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void ToneMixTableCanvas::resized()
{
    m_tone1->setBounds (22, 15, 156, 96);
    m_tone2->setBounds (78, 71, 196, 56);
    m_tone3->setBounds (198, 39, 172, 56);
    m_tone4->setBounds (310, 15, 172, 80);
    m_tone1XFade->setBounds (80, 168, 90, 64);
    m_tone2XFade->setBounds (312, 184, 90, 64);
    m_tone3XFade->setBounds (528, 216, 90, 64);
    m_tone4XFade->setBounds (536, 344, 90, 64);
    //[UserResized] Add your own custom resize handling here..
	m_dragTonesConstrainer->setSize(getWidth(), getHeight());
	m_dragTonesConstrainer->checkComponentBounds(m_tone1);
	m_dragTonesConstrainer->checkComponentBounds(m_tone2);
	m_dragTonesConstrainer->checkComponentBounds(m_tone3);
	m_dragTonesConstrainer->checkComponentBounds(m_tone4);
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



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Introjucer information section --

    This is where the Introjucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="ToneMixTableCanvas" componentName=""
                 parentClasses="public Component, public ComponentDragger" constructorParams="const String &amp;componentName"
                 variableInitialisers="Component(componentName), m_dragTonesConstrainer (new ToneLimitsConstrainer())"
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="0" initialWidth="600" initialHeight="400">
  <METHODS>
    <METHOD name="mouseDown (const MouseEvent&amp; e)"/>
    <METHOD name="mouseDrag (const MouseEvent&amp; e)"/>
  </METHODS>
  <BACKGROUND backgroundColour="0"/>
  <JUCERCOMP name="tone1" id="510c3a47536dbf97" memberName="m_tone1" virtualName=""
             explicitFocusOrder="0" pos="22 15 156 96" sourceFile="ToneMixTableTone.cpp"
             constructorParams="&quot;T1&quot;, m_dragTonesConstrainer"/>
  <JUCERCOMP name="tone2" id="d15d907bba8a70a7" memberName="m_tone2" virtualName=""
             explicitFocusOrder="0" pos="78 71 196 56" sourceFile="ToneMixTableTone.cpp"
             constructorParams="&quot;T2&quot;, m_dragTonesConstrainer"/>
  <JUCERCOMP name="tone3" id="35aa73d392c31823" memberName="m_tone3" virtualName=""
             explicitFocusOrder="0" pos="198 39 172 56" sourceFile="ToneMixTableTone.cpp"
             constructorParams="&quot;T3&quot;, m_dragTonesConstrainer"/>
  <JUCERCOMP name="tone4" id="854d99619d9ff21" memberName="m_tone4" virtualName=""
             explicitFocusOrder="0" pos="310 15 172 80" sourceFile="ToneMixTableTone.cpp"
             constructorParams="&quot;T4&quot;, m_dragTonesConstrainer"/>
  <JUCERCOMP name="tone1XFade" id="e2650ead84ba9eb" memberName="m_tone1XFade"
             virtualName="" explicitFocusOrder="0" pos="80 168 90 64" sourceFile="ToneMixTableToneVeloXFade.cpp"
             constructorParams="&quot;tone1XFade&quot;, m_tone1"/>
  <JUCERCOMP name="tone2XFade" id="d49f21f8d7d044d6" memberName="m_tone2XFade"
             virtualName="" explicitFocusOrder="0" pos="312 184 90 64" sourceFile="ToneMixTableToneVeloXFade.cpp"
             constructorParams="&quot;tone2XFade&quot;, m_tone2"/>
  <JUCERCOMP name="tone3XFade" id="9bb46fc43adff0f7" memberName="m_tone3XFade"
             virtualName="" explicitFocusOrder="0" pos="528 216 90 64" sourceFile="ToneMixTableToneVeloXFade.cpp"
             constructorParams="&quot;tone3XFade&quot;, m_tone3"/>
  <JUCERCOMP name="tone4XFade" id="4c5ae2ea727f85ed" memberName="m_tone4XFade"
             virtualName="" explicitFocusOrder="0" pos="536 344 90 64" sourceFile="ToneMixTableToneVeloXFade.cpp"
             constructorParams="&quot;tone4XFade&quot;, m_tone4"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
