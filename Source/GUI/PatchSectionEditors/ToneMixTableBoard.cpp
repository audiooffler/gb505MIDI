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

#include "ToneMixTableBoard.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
ToneMixTableBoard::ToneMixTableBoard (const String &componentName, SynthParts part)
    : Component(componentName),
      m_part(part)
{
    addAndMakeVisible (m_toneMixTableCanvas = new ToneMixTableCanvas ("toneMixTableCanvas", m_part));

    //[UserPreSize]
    //[/UserPreSize]

    setSize (600, 400);


    //[Constructor] You can add your own custom stuff here..
    //[/Constructor]
}

ToneMixTableBoard::~ToneMixTableBoard()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    m_toneMixTableCanvas = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void ToneMixTableBoard::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colour (0xfff2f59b));

    g.setColour (Colours::black);
    g.drawRect (0, 0, getWidth() - 0, getHeight() - 0, 1);

    g.setColour (Colours::black);
    g.drawRect (0, getHeight() - 48, getWidth() - 0, 48, 1);

    //[UserPaint] Add your own custom painting code here..
	// KEYBOARD in lower 48 pixels

	g.setColour(Colour(0xfff2f59b));
	g.fillRect(0, getHeight() - 48, getWidth(), getHeight());
	// draw black keys and separators
	float keyWidth = (float)getWidth() / 128.0f;
	int keyInOctave(0);
	int x(0), nextX(0), xMiddle(0);
	bool blackKey(false), nextIsBlack(true), whiteKey(true), nextIsWhite(false);
	for (int i = 0; i <= 128; i++)
	{
		x = (int)(i * keyWidth);
		nextX = (int)((i + 1) * keyWidth);
		xMiddle = (int)(((float)nextX + (float)x) / 2.0f);
		keyInOctave = i % 12;
		blackKey = (keyInOctave == 1 || keyInOctave == 3 || keyInOctave == 6 || keyInOctave == 8 || keyInOctave == 10);
		nextIsBlack = (keyInOctave == 0 || keyInOctave == 2 || keyInOctave == 5 || keyInOctave == 7 || keyInOctave == 9);
		whiteKey = !blackKey;
		nextIsWhite = !nextIsBlack;
		// separate between white keys
		g.setColour(Colours::black);
		if (whiteKey && nextIsWhite)
		{
			g.fillRect(nextX, getHeight() - 48, 1, 48);
		}
		else if (blackKey)
		{
			g.fillRect(xMiddle, getHeight() - 16, 1, 16);
		}
		// draw black keys
		if (blackKey)
		{
			g.fillRect((int)x, getHeight() - 48, (int)keyWidth, 32);
			g.setColour(Colour(0xfff2f59b));
			g.drawRect((int)x + 1.0f, getHeight() - 46.0f, 1.0f, 28.0f, 1.0f);
			g.drawRect((int)x + 2.0f, getHeight() - 18.0f, (int)keyWidth - 4.0f, 1.0f, 1.0f);
		}
		// write text
		if (keyInOctave == 0)
		{
			g.setColour(Colours::black);
			g.setFont(Font(11.00f, Font::plain));
			g.drawText("C",
				xMiddle + 2 - (16 / 2), getHeight() - 22, 16, 16,
				Justification::centred, true);
			int octNumber = (int)(i / 12) - 1;
			g.drawText(String(octNumber),
				xMiddle + 2 - (16 / 2), getHeight() - 14, 16, 16,
				Justification::centred, true);
		}
	}
	// END KEYBOARD in lower 48 pixels
    //[/UserPaint]
}

void ToneMixTableBoard::resized()
{
    m_toneMixTableCanvas->setBounds (0, 0, getWidth() - 0, getHeight() - 48);
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
void ToneMixTableBoard::paintOverChildren(Graphics &g)
{
	g.setColour(Colours::black);
	g.drawRect(0, 0, getWidth() - 0, getHeight() - 0, 1);

	g.setColour(Colours::black);
	g.drawRect(0, getHeight() - 48, getWidth() - 0, 48, 1);
}
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Introjucer information section --

    This is where the Introjucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="ToneMixTableBoard" componentName=""
                 parentClasses="public Component" constructorParams="const String &amp;componentName, SynthParts part"
                 variableInitialisers="Component(componentName),&#10;m_part(part)"
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="0" initialWidth="600" initialHeight="400">
  <BACKGROUND backgroundColour="fff2f59b">
    <RECT pos="0 0 0M 0M" fill="solid: 0" hasStroke="1" stroke="1, mitered, butt"
          strokeColour="solid: ff000000"/>
    <RECT pos="0 0Rr 0M 48" fill="solid: 0" hasStroke="1" stroke="1, mitered, butt"
          strokeColour="solid: ff000000"/>
  </BACKGROUND>
  <JUCERCOMP name="toneMixTableCanvas" id="248d075c13b046c1" memberName="m_toneMixTableCanvas"
             virtualName="" explicitFocusOrder="0" pos="0 0 0M 48M" sourceFile="ToneMixTableCanvas.cpp"
             constructorParams="&quot;toneMixTableCanvas&quot;, m_part"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
