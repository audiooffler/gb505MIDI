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

#include "TextWithArrowButton.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
TextWithArrowButton::TextWithArrowButton ()
{

    //[UserPreSize]
    //[/UserPreSize]

    setSize (600, 400);


    //[Constructor] You can add your own custom stuff here..
    //[/Constructor]
}

TextWithArrowButton::~TextWithArrowButton()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]



    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void TextWithArrowButton::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    TextButton::paint(g);
    //[/UserPrePaint]

    //[UserPaint] Add your own custom painting code here..
	float height(jmin(getHeight() - 6.0f, 10.0f));
	float y(0.5f*(getHeight()-height));
	float width(height * 2.0f / 3.0f);
	float x(getWidth() - 5.0f);
	Path triangle;
	triangle.addTriangle(x - width, y, x - width, y+height, x, y+(height*0.5f));
	DropShadow(Colours::black.withAlpha(0.6f), isDown() ? 2 : 4, Point<int>(1,1)).drawForPath(g, triangle);
	g.setColour(Colours::black.withAlpha(0.75f));
	g.fillPath(triangle);
    //[/UserPaint]
}

void TextWithArrowButton::resized()
{
    //[UserResized] Add your own custom resize handling here..
    TextButton::resized();
    //[/UserResized]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
TextWithArrowButton::TextWithArrowButton(const String &buttonName)
    : TextButton(buttonName)
{
}

TextWithArrowButton::TextWithArrowButton(const String &buttonName, const String &toolTip)
    : TextButton(buttonName, toolTip)
{
}
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Introjucer information section --

    This is where the Introjucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="TextWithArrowButton" componentName=""
                 parentClasses="public TextButton" constructorParams="" variableInitialisers=""
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="0" initialWidth="600" initialHeight="400">
  <BACKGROUND backgroundColour="0"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
