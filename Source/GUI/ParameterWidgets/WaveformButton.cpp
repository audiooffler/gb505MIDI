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
#include "../GrooveboxLookAndFeel.h"
//[/Headers]

#include "WaveformButton.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
extern Waveforms* waveForms;
//[/MiscUserDefs]

//==============================================================================
WaveformButton::WaveformButton ()
    : TextButton(String())
{

    //[UserPreSize]
	setClickingTogglesState(true);
	m_highlight = false;
    //[/UserPreSize]

    setSize (100, 20);


    //[Constructor] You can add your own custom stuff here..
    //[/Constructor]
}

WaveformButton::~WaveformButton()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]



    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void WaveformButton::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
	setColour(buttonColourId, m_highlight ? GrooveboxLookAndFeel::Mc307LcdBackground.brighter(1.0f) : GrooveboxLookAndFeel::Mc307LcdBackground);
	setColour(buttonOnColourId, m_highlight ? GrooveboxLookAndFeel::Mc307LcdThumb.brighter(1.0f) : GrooveboxLookAndFeel::Mc307LcdThumb);

	Colour baseColour(Colour(getToggleState() ? findColour(ColourIds::buttonOnColourId) : findColour(ColourIds::buttonColourId)).withMultipliedSaturation(hasKeyboardFocus(true) ? 1.3f : 0.9f)
		.withMultipliedAlpha(isEnabled() ? 0.9f : 0.5f));

	if (isDown() || isOver())
		baseColour = baseColour.contrasting(isDown() ? 0.2f : 0.1f);

	const bool flatOnLeft = isConnectedOnLeft();
	const bool flatOnRight = isConnectedOnRight();
	const bool flatOnTop = isConnectedOnTop();
	const bool flatOnBottom = isConnectedOnBottom();

	const float width = getWidth() - 1.0f;
	const float height = getHeight() - 1.0f;

	if (width > 0 && height > 0)
	{
		const float cornerSize = 4.0f;

		Path outline;
		outline.addRoundedRectangle(0.5f, 0.5f, width, height, cornerSize, cornerSize,
			!(flatOnLeft || flatOnTop),
			!(flatOnRight || flatOnTop),
			!(flatOnLeft || flatOnBottom),
			!(flatOnRight || flatOnBottom));

		//drawButtonShape(g, outline, baseColour, height);
		const float mainBrightness = baseColour.getBrightness();
		const float mainAlpha = baseColour.getFloatAlpha();

		g.setGradientFill(ColourGradient(baseColour.brighter(0.2f), 0.0f, 0.0f,
			baseColour.darker(0.25f), 0.0f, height, false));
		g.fillPath(outline);

		g.setColour(Colours::white.withAlpha(0.4f * mainAlpha * mainBrightness * mainBrightness));
		g.strokePath(outline, PathStrokeType(1.0f), AffineTransform::translation(0.0f, 1.0f)
			.scaled(1.0f, (height - 1.6f) / height));

		g.setColour(Colours::black.withAlpha(0.4f * mainAlpha));
		g.strokePath(outline, PathStrokeType(1.0f));
		if (getToggleState())
		{
			g.setColour(Colours::black);
			g.strokePath(outline, PathStrokeType(2.0f));
		}
	}

	Font font(jmin(10.8f, getHeight() * 0.6f));

	g.setFont(font);
	g.setColour(findColour(getToggleState() ? TextButton::textColourOnId
		: TextButton::textColourOffId)
		.withMultipliedAlpha(isEnabled() ? 1.0f : 0.5f));

	const int yIndent = jmin(4, proportionOfHeight(0.3f));
	const int cornerSize = jmin(getHeight(), getWidth()) / 10;

	const int fontHeight = roundToInt(font.getHeight() * 0.6f);
	const int leftIndent = jmin(fontHeight, 2 + cornerSize / (isConnectedOnLeft() ? 4 : 2));
	const int rightIndent = jmin(fontHeight, 2 + cornerSize / (isConnectedOnRight() ? 4 : 2));

	g.drawText(getButtonText(),
		leftIndent,
		yIndent,
		getWidth() - leftIndent - rightIndent,
		getHeight() - yIndent * 2,
		Justification::left, false);
    //[/UserPrePaint]

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void WaveformButton::resized()
{
    //[UserResized] Add your own custom resize handling here..
	Button::resized();
    //[/UserResized]
}

void WaveformButton::mouseEnter (const MouseEvent& e)
{
    //[UserCode_mouseEnter] -- Add your code here...
	#ifdef JUCE_MSVC
	e;
	#endif
	grabKeyboardFocus();
    //[/UserCode_mouseEnter]
}

void WaveformButton::mouseDoubleClick (const MouseEvent& e)
{
    //[UserCode_mouseDoubleClick] -- Add your code here...
	#ifdef JUCE_MSVC
	e;
	#endif
	// make editor select value, keep dialog open
    //[/UserCode_mouseDoubleClick]
}

bool WaveformButton::keyPressed (const KeyPress& key)
{
    //[UserCode_keyPressed] -- Add your code here...
	if (key.isKeyCode(KeyPress::spaceKey))
	{
		triggerClick();
		return true;
	}
    else return false;  // Return true if your handler uses this key event, or false to allow it to be passed-on.
    //[/UserCode_keyPressed]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
WaveformButton::WaveformButton(Waveforms::WaveGroup waveGroup, int waveformIndexInGroup)
	: TextButton(String()),
	m_group (waveGroup),
	m_numInGroup(waveformIndexInGroup)
{
	setButtonText(waveForms->getButtonText(waveGroup, waveformIndexInGroup));
	setTooltip(waveForms->getLongName(waveGroup,waveformIndexInGroup));
}

void WaveformButton::colourChanged()
{
	repaint();
}

void WaveformButton::setHighLight(bool highlight) {
	m_highlight = highlight;

	repaint();
}
bool WaveformButton::getHighLight() { return m_highlight; }
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Introjucer information section --

    This is where the Introjucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="WaveformButton" componentName=""
                 parentClasses="public TextButton" constructorParams="" variableInitialisers="TextButton(String())"
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="0" initialWidth="100" initialHeight="20">
  <METHODS>
    <METHOD name="mouseDoubleClick (const MouseEvent&amp; e)"/>
    <METHOD name="keyPressed (const KeyPress&amp; key)"/>
    <METHOD name="mouseEnter (const MouseEvent&amp; e)"/>
  </METHODS>
  <BACKGROUND backgroundColour="0"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
