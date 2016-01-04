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

#include "BlackToggle.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
BlackToggle::BlackToggle()
: ParameterToggle()
{
	cachedImage_blackToggleOff_png = ImageCache::getFromMemory(blackToggleOff_png, blackToggleOff_pngSize);
	cachedImage_blackToggleOn_png = ImageCache::getFromMemory(blackToggleOn_png, blackToggleOn_pngSize);
	setSize(25, 17);
}
//[/MiscUserDefs]

//==============================================================================
BlackToggle::BlackToggle (const String& componentName)
    : ParameterToggle(componentName)
{
    cachedImage_blackToggleOff_png = ImageCache::getFromMemory (blackToggleOff_png, blackToggleOff_pngSize);

    //[UserPreSize]
	cachedImage_blackToggleOn_png = ImageCache::getFromMemory(blackToggleOn_png, blackToggleOn_pngSize);
    //[/UserPreSize]

    setSize (25, 17);


    //[Constructor] You can add your own custom stuff here..
    //[/Constructor]
}

BlackToggle::~BlackToggle()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]



    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void BlackToggle::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
	//ToggleButton::paint(g);
    //[/UserPrePaint]

    g.setColour (Colours::black);
    g.drawImage (cachedImage_blackToggleOff_png,
                 (getWidth() / 2) - ((25) / 2), (getHeight() / 2) - ((17) / 2), 25, 17,
                 0, 0, cachedImage_blackToggleOff_png.getWidth(), cachedImage_blackToggleOff_png.getHeight());

    //[UserPaint] Add your own custom painting code here..
	if (getToggleState())
	{
		g.setColour(Colours::black);
		g.drawImage(cachedImage_blackToggleOn_png,
			(getWidth() / 2) - ((25) / 2), (getHeight() / 2) - ((17) / 2), 25, 17,
			0, 0, cachedImage_blackToggleOn_png.getWidth(), cachedImage_blackToggleOn_png.getHeight());
	}
    //[/UserPaint]
}

void BlackToggle::resized()
{
    //[UserResized] Add your own custom resize handling here..
	ToggleButton::resized();
    //[/UserResized]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Introjucer information section --

    This is where the Introjucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="BlackToggle" componentName=""
                 parentClasses="public ParameterToggle" constructorParams="const String&amp; componentName"
                 variableInitialisers="ParameterToggle(componentName)" snapPixels="8"
                 snapActive="1" snapShown="1" overlayOpacity="0.330" fixedSize="1"
                 initialWidth="25" initialHeight="17">
  <BACKGROUND backgroundColour="0">
    <IMAGE pos="0.5Cc 0.5Cc 25 17" resource="blackToggleOff_png" opacity="1"
           mode="0"/>
  </BACKGROUND>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif

//==============================================================================
// Binary resources - be careful not to edit any of these sections!

// JUCER_RESOURCE: blackToggleOff_png, 483, "../../../Resources/LookAndFeel/BlackToggleOff.png"
static const unsigned char resource_BlackToggle_blackToggleOff_png[] = { 137,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,0,25,0,0,0,17,8,6,0,0,0,40,186,7,14,0,0,0,4,115,66,73,84,8,8,8,8,124,8,100,136,
0,0,0,9,112,72,89,115,0,0,13,203,0,0,13,203,1,208,75,4,197,0,0,0,25,116,69,88,116,83,111,102,116,119,97,114,101,0,119,119,119,46,105,110,107,115,99,97,112,101,46,111,114,103,155,238,60,26,0,0,1,96,73,
68,65,84,56,141,181,149,177,106,27,65,16,134,191,25,221,220,158,192,4,44,165,179,73,19,252,8,22,121,144,52,121,56,227,144,42,149,95,34,164,82,161,7,72,151,94,17,9,232,124,167,245,236,166,145,206,151,35,
228,130,57,253,176,205,240,179,223,254,179,59,44,192,181,170,222,139,72,3,228,169,150,136,212,170,122,7,92,9,112,103,102,183,203,229,242,161,170,170,31,76,164,166,105,150,219,237,246,125,140,241,139,0,
205,98,177,248,106,102,63,167,2,156,116,56,28,46,119,187,221,187,2,8,102,118,49,155,205,202,129,225,85,219,182,55,102,38,99,155,185,123,54,179,111,101,89,254,234,215,203,178,44,129,170,0,80,213,75,17,
121,234,27,98,140,111,86,171,213,220,204,70,79,28,99,100,189,94,191,13,33,124,239,215,85,181,0,40,0,68,100,33,34,105,112,10,223,108,54,41,132,48,10,105,219,150,16,130,139,200,235,126,93,68,180,131,228,
156,29,248,3,18,66,168,83,74,143,57,231,209,118,85,85,149,85,53,15,235,57,231,220,65,142,0,31,154,84,117,52,197,255,232,4,241,99,154,179,168,159,36,253,203,248,66,73,7,57,166,152,60,201,241,74,186,36,
114,162,78,172,231,36,41,165,192,25,218,149,82,122,126,194,238,126,22,136,187,119,144,131,187,87,195,97,156,16,210,22,192,231,253,126,255,97,62,159,207,254,54,80,47,85,74,73,234,186,126,2,62,1,92,3,31,
129,150,9,255,19,160,1,238,129,171,223,218,12,171,46,208,176,195,97,0,0,0,0,73,69,78,68,174,66,96,130,0,0};

const char* BlackToggle::blackToggleOff_png = (const char*) resource_BlackToggle_blackToggleOff_png;
const int BlackToggle::blackToggleOff_pngSize = 483;

// JUCER_RESOURCE: blackToggleOn_png, 592, "../../../Resources/LookAndFeel/BlackToggleOn.png"
static const unsigned char resource_BlackToggle_blackToggleOn_png[] = { 137,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,0,25,0,0,0,17,8,6,0,0,0,40,186,7,14,0,0,0,4,115,66,73,84,8,8,8,8,124,8,100,136,
0,0,0,9,112,72,89,115,0,0,13,203,0,0,13,203,1,208,75,4,197,0,0,0,25,116,69,88,116,83,111,102,116,119,97,114,101,0,119,119,119,46,105,110,107,115,99,97,112,101,46,111,114,103,155,238,60,26,0,0,1,205,73,
68,65,84,56,141,221,148,61,79,27,65,16,134,159,185,91,118,99,12,40,242,89,39,133,34,255,194,210,153,210,149,165,212,72,16,255,60,164,248,71,80,7,10,254,2,109,130,37,127,31,113,124,123,31,187,41,192,103,
104,66,34,93,154,188,229,236,232,125,102,52,51,43,231,231,231,159,230,243,249,151,155,155,155,147,44,203,104,74,173,86,139,36,73,210,40,138,46,100,48,24,172,23,139,197,201,104,52,162,219,237,54,6,153,
78,167,92,93,93,17,199,241,74,140,49,126,56,28,210,233,116,0,56,170,114,140,47,49,85,201,59,95,96,92,201,1,142,208,59,2,60,120,15,34,56,132,74,2,114,2,108,160,176,114,128,13,21,115,117,88,131,102,179,
25,215,215,215,40,107,45,214,90,150,203,37,0,129,179,224,74,62,206,190,161,191,63,96,188,7,4,240,200,139,74,61,212,113,43,130,61,61,229,190,251,129,165,178,117,78,81,20,100,89,134,2,72,211,148,221,60,
180,179,136,84,180,39,19,46,183,150,214,179,221,239,180,17,97,60,121,96,107,218,172,164,172,227,121,158,3,60,65,214,235,53,74,169,39,136,148,84,226,248,169,53,227,210,113,244,7,144,31,8,91,163,89,166,
41,75,183,239,164,44,203,61,68,68,8,130,224,233,129,16,43,240,245,168,67,212,206,121,239,42,52,30,37,30,37,82,207,164,244,158,210,11,57,194,42,8,153,139,198,178,247,217,249,214,144,48,12,9,195,16,128,
148,144,244,57,233,158,67,8,223,108,228,149,94,166,59,231,246,144,32,8,94,85,208,148,118,158,255,25,196,123,143,247,111,111,209,223,106,231,169,0,182,219,109,189,110,77,170,40,138,61,36,203,178,127,2,
169,239,68,107,205,102,179,65,107,221,56,36,207,115,140,49,168,126,191,255,120,119,119,119,108,140,105,116,248,206,57,172,181,156,157,157,173,84,28,199,151,189,94,111,124,123,123,123,188,251,107,154,144,
49,134,36,73,30,163,40,250,252,11,179,124,209,202,121,12,197,43,0,0,0,0,73,69,78,68,174,66,96,130,0,0};

const char* BlackToggle::blackToggleOn_png = (const char*) resource_BlackToggle_blackToggleOn_png;
const int BlackToggle::blackToggleOn_pngSize = 592;


//[EndFile] You can add extra defines here...
//[/EndFile]
