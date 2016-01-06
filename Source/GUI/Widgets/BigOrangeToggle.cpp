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

#include "BigOrangeToggle.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
BigOrangeToggle::BigOrangeToggle()
: ParameterToggle()
{
	cachedImage_bigOrangeToggleOff_png = ImageCache::getFromMemory(bigOrangeToggleOff_png, bigOrangeToggleOff_pngSize);
	cachedImage_bigOrangeToggleOn_png = ImageCache::getFromMemory(bigOrangeToggleOn_png, bigOrangeToggleOn_pngSize);
	setSize(27, 27);
}
//[/MiscUserDefs]

//==============================================================================
BigOrangeToggle::BigOrangeToggle (const String& componentName)
    : ParameterToggle(componentName)
{
    cachedImage_bigOrangeToggleOff_png = ImageCache::getFromMemory (bigOrangeToggleOff_png, bigOrangeToggleOff_pngSize);

    //[UserPreSize]
	cachedImage_bigOrangeToggleOn_png = ImageCache::getFromMemory(bigOrangeToggleOn_png, bigOrangeToggleOn_pngSize);
    //[/UserPreSize]

    setSize (27, 27);


    //[Constructor] You can add your own custom stuff here..
    //[/Constructor]
}

BigOrangeToggle::~BigOrangeToggle()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]



    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void BigOrangeToggle::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
	ToggleButton::paint(g);
    //[/UserPrePaint]

    g.setColour (Colours::black);
    g.drawImage (cachedImage_bigOrangeToggleOff_png,
                 (getWidth() / 2) - ((27) / 2), (getHeight() / 2) - ((27) / 2), 27, 27,
                 0, 0, cachedImage_bigOrangeToggleOff_png.getWidth(), cachedImage_bigOrangeToggleOff_png.getHeight());

    //[UserPaint] Add your own custom painting code here..
	if (getToggleState())
	{
		g.setColour(Colours::black);
		g.drawImage(cachedImage_bigOrangeToggleOn_png,
			(getWidth() / 2) - ((27) / 2), (getHeight() / 2) - ((27) / 2), 27, 27,
			0, 0, cachedImage_bigOrangeToggleOn_png.getWidth(), cachedImage_bigOrangeToggleOn_png.getHeight());
	}
    //[/UserPaint]
}

void BigOrangeToggle::resized()
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

<JUCER_COMPONENT documentType="Component" className="BigOrangeToggle" componentName=""
                 parentClasses="public ParameterToggle" constructorParams="const String&amp; componentName"
                 variableInitialisers="ParameterToggle(componentName)" snapPixels="8"
                 snapActive="1" snapShown="1" overlayOpacity="0.330" fixedSize="1"
                 initialWidth="27" initialHeight="27">
  <BACKGROUND backgroundColour="0">
    <IMAGE pos="0.5Cc 0.5Cc 27 27" resource="bigOrangeToggleOff_png" opacity="1"
           mode="0"/>
  </BACKGROUND>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif

//==============================================================================
// Binary resources - be careful not to edit any of these sections!

// JUCER_RESOURCE: bigOrangeToggleOff_png, 1786, "../../../Resources/LookAndFeel/BigOrangeToggleOff.png"
static const unsigned char resource_BigOrangeToggle_bigOrangeToggleOff_png[] = { 137,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,0,27,0,0,0,27,8,6,0,0,0,141,212,244,85,0,0,0,4,115,66,73,84,8,8,8,8,124,
8,100,136,0,0,0,9,112,72,89,115,0,0,10,97,0,0,10,97,1,252,204,74,37,0,0,0,25,116,69,88,116,83,111,102,116,119,97,114,101,0,119,119,119,46,105,110,107,115,99,97,112,101,46,111,114,103,155,238,60,26,0,0,
6,119,73,68,65,84,72,137,165,150,219,111,29,87,21,135,127,107,95,230,114,78,108,39,142,67,114,78,156,52,78,171,130,170,208,26,41,150,90,46,42,82,90,40,215,132,135,84,60,5,133,128,218,242,218,63,38,45,
47,144,136,34,222,2,5,169,72,16,81,129,148,68,184,73,92,34,120,162,56,205,197,185,212,246,177,231,204,204,158,217,183,197,195,113,172,208,166,148,134,121,27,237,61,251,219,223,172,181,247,90,196,204,248,
52,15,17,17,0,9,32,240,167,252,152,62,105,62,17,201,125,128,30,2,122,215,248,184,118,206,205,52,204,115,25,209,188,214,122,209,23,133,107,1,119,21,112,204,28,30,10,70,68,212,7,242,116,203,150,231,37,209,
203,157,110,119,54,114,220,30,124,80,91,183,109,227,187,119,238,144,20,194,75,41,151,141,49,11,17,120,205,27,243,199,37,192,124,156,241,3,97,68,36,123,192,228,216,196,196,107,82,169,35,79,63,251,44,237,
222,247,8,246,204,236,227,157,189,30,49,3,229,112,136,171,139,139,124,253,95,239,209,237,107,215,113,229,226,37,38,162,51,166,170,94,185,5,172,62,200,242,35,48,34,210,51,73,242,92,54,54,118,106,87,191,
63,121,244,196,113,122,244,241,207,138,169,169,41,8,41,193,49,194,24,131,98,125,13,166,174,193,12,40,173,177,112,241,98,60,115,234,52,215,101,185,218,148,229,177,107,33,156,101,102,247,177,48,34,146,51,
73,242,181,164,219,253,237,243,223,253,14,125,253,200,97,218,61,189,135,116,146,64,128,16,98,132,247,14,117,85,97,109,176,138,162,40,224,172,133,82,10,58,73,161,181,226,95,253,236,231,60,255,231,191,176,
111,154,111,95,11,225,15,247,27,170,15,197,104,91,62,62,118,234,171,223,252,6,125,235,232,81,209,239,247,145,36,41,152,35,66,8,136,193,35,134,0,2,32,132,64,244,30,166,174,1,0,73,154,34,203,115,250,254,
15,143,19,64,241,242,249,243,167,251,107,107,79,16,209,202,189,24,138,123,176,62,144,119,199,199,127,186,99,231,206,201,23,142,28,161,94,175,143,36,77,193,96,56,231,80,215,21,140,169,225,172,5,17,65,107,
13,33,8,109,99,48,44,10,148,195,2,85,89,162,174,42,188,248,131,99,148,229,249,100,214,237,190,222,7,242,123,12,177,97,37,116,158,31,18,82,30,126,241,71,39,168,191,123,154,116,162,193,145,97,155,6,195,
98,29,235,131,53,12,86,86,48,24,172,98,56,44,96,173,5,132,64,146,102,16,130,80,151,37,76,85,194,212,53,156,179,116,244,196,113,138,49,30,209,121,126,136,136,196,38,108,26,72,165,82,63,153,251,210,23,233,
11,7,231,68,146,36,32,0,206,89,84,101,137,245,181,53,20,235,107,40,55,22,51,166,134,109,91,16,8,105,154,34,203,114,104,173,97,234,26,173,49,104,155,6,79,28,248,188,248,220,83,79,146,32,122,101,26,72,55,
99,214,157,154,82,137,148,79,77,239,223,15,41,21,72,8,120,239,209,54,13,140,169,97,140,129,247,14,74,105,40,173,32,165,2,51,35,225,136,24,35,152,35,34,71,248,170,66,219,182,72,218,22,46,179,120,228,177,
199,112,237,159,239,205,38,157,142,218,52,83,214,106,102,158,218,251,232,126,22,82,128,99,132,247,1,193,123,56,107,17,67,128,148,10,105,150,34,239,116,209,233,118,145,119,58,200,243,14,178,44,67,146,164,
208,90,67,107,13,239,44,188,247,240,222,227,192,236,44,219,182,157,82,214,106,0,80,68,68,143,231,122,70,40,165,118,245,122,136,145,97,109,11,103,29,90,219,194,121,15,16,32,55,210,59,207,115,164,89,6,239,
71,71,200,57,7,169,70,182,66,136,141,172,13,136,49,98,247,158,61,228,172,85,33,198,25,34,26,40,0,210,178,156,219,185,117,130,125,8,212,212,21,188,115,104,27,3,231,44,108,107,17,57,130,8,32,34,144,16,80,
74,33,198,56,122,39,218,24,27,141,3,0,3,0,51,132,16,24,223,182,149,135,107,235,115,112,238,93,5,32,36,68,243,31,220,185,75,117,89,162,72,51,152,186,66,89,150,8,206,66,74,141,36,213,144,66,142,54,209,54,
136,49,32,134,8,231,44,130,247,27,54,163,248,9,33,32,132,0,9,1,102,70,49,88,35,17,227,60,128,160,152,153,15,76,76,44,50,224,223,191,186,40,199,198,198,201,24,3,83,85,168,234,10,157,60,71,228,28,36,4,132,
20,136,28,33,165,4,71,134,115,22,109,59,250,229,206,59,120,239,161,148,134,84,18,74,42,92,249,219,2,235,36,9,41,209,34,91,203,2,0,110,23,133,19,74,46,223,186,126,131,164,148,16,66,66,72,1,98,160,217,72,
229,198,24,152,170,70,85,150,168,134,67,148,229,16,117,57,58,232,109,211,192,182,45,156,181,208,105,130,68,167,80,90,227,198,226,85,74,210,116,217,39,137,219,76,253,28,240,141,105,22,150,111,222,122,97,
121,101,25,99,91,198,144,218,12,46,119,168,203,18,141,49,136,204,163,157,183,163,155,131,153,17,66,128,179,35,187,166,105,144,119,58,200,178,28,73,150,34,73,83,44,189,127,13,166,174,23,92,93,251,205,212,
191,1,180,0,78,190,115,238,28,223,186,121,35,102,121,142,172,211,65,167,211,69,167,187,5,62,4,212,85,53,178,42,135,40,135,67,148,195,18,213,176,68,85,85,48,117,141,44,203,144,119,186,200,242,17,240,242,
59,243,241,239,151,46,115,100,62,185,177,254,200,140,153,227,110,162,179,105,167,243,235,55,79,191,113,120,251,142,207,112,175,215,39,48,64,66,64,42,5,219,54,112,214,162,49,6,68,35,51,33,4,180,78,48,54,
62,129,52,203,70,103,175,211,197,242,242,7,252,230,47,126,201,68,244,27,87,215,103,153,57,254,199,173,191,4,152,126,93,191,180,178,178,242,149,43,23,254,186,93,126,249,25,218,181,179,7,169,36,180,214,
176,109,10,231,28,66,8,96,142,32,16,132,148,27,229,37,65,154,101,200,178,28,43,171,43,184,240,167,183,185,88,95,95,109,170,234,165,37,192,124,164,196,48,51,19,209,96,175,49,199,222,58,115,230,119,36,40,
210,51,79,147,144,146,38,39,183,195,89,11,239,29,98,8,184,87,3,133,24,193,84,162,81,20,5,6,107,107,188,112,238,60,191,253,214,239,57,180,237,177,37,96,112,127,139,240,192,74,189,87,202,67,42,203,78,79,
108,219,58,249,227,87,95,37,145,40,33,133,132,16,2,83,83,59,54,97,171,171,43,136,49,194,7,15,83,12,227,27,39,95,231,213,193,96,213,215,245,39,87,234,251,128,178,7,76,166,121,126,146,153,191,247,228,193,
131,52,59,55,135,222,222,105,222,190,99,7,69,102,48,51,150,239,220,229,59,75,55,233,31,151,223,197,165,11,23,88,8,113,166,169,235,255,189,7,185,15,72,125,32,87,121,254,28,98,124,89,39,201,108,12,97,42,
132,160,182,140,143,113,89,12,73,74,233,133,146,203,206,186,5,16,61,92,119,245,97,203,125,247,245,141,181,49,51,142,104,78,51,207,119,242,124,241,118,81,184,177,255,183,111,252,47,240,135,238,136,255,
13,130,190,224,251,218,26,219,165,0,0,0,0,73,69,78,68,174,66,96,130,0,0};

const char* BigOrangeToggle::bigOrangeToggleOff_png = (const char*) resource_BigOrangeToggle_bigOrangeToggleOff_png;
const int BigOrangeToggle::bigOrangeToggleOff_pngSize = 1786;

// JUCER_RESOURCE: bigOrangeToggleOn_png, 2038, "../../../Resources/LookAndFeel/BigOrangeToggleOn.png"
static const unsigned char resource_BigOrangeToggle_bigOrangeToggleOn_png[] = { 137,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,0,27,0,0,0,27,8,6,0,0,0,141,212,244,85,0,0,0,9,112,72,89,115,0,0,10,77,
0,0,10,77,1,181,147,228,198,0,0,7,168,73,68,65,84,72,199,165,214,91,168,231,85,21,192,241,239,218,251,119,251,223,207,255,204,185,206,229,28,231,98,216,140,142,229,101,156,204,70,83,73,210,74,73,66,163,
236,169,34,176,36,235,165,135,32,95,194,34,136,94,124,145,94,2,69,197,160,134,40,8,201,40,35,27,77,105,198,26,71,102,198,51,115,230,204,229,220,254,231,252,47,191,251,254,237,221,195,100,37,72,5,109,88,
79,27,214,90,172,135,181,62,226,156,227,93,239,250,123,228,228,214,95,169,227,77,244,174,83,248,197,86,66,25,18,181,66,194,162,70,160,18,60,229,33,214,224,156,166,18,161,40,125,242,44,33,55,29,178,106,
149,114,166,137,185,242,194,221,150,215,126,249,174,228,242,239,197,14,203,164,226,230,53,213,158,193,111,27,106,157,148,166,211,116,130,58,93,79,71,237,32,140,154,231,87,204,228,209,129,121,255,190,182,
57,177,45,48,203,198,17,27,199,208,88,250,64,127,195,50,28,148,164,237,51,20,23,23,38,170,135,167,148,91,90,94,118,0,30,192,246,233,105,121,226,177,21,153,221,137,54,219,8,189,140,86,187,164,219,108,235,
233,99,155,181,131,175,156,14,63,55,36,152,91,207,90,141,66,215,85,91,122,238,231,11,86,106,131,85,59,209,206,147,241,6,231,174,155,226,167,215,140,243,82,59,100,57,170,179,222,159,103,200,77,107,217,
19,135,48,219,167,167,89,90,94,118,226,156,227,176,76,170,217,47,174,233,252,20,181,166,71,167,211,150,153,134,31,205,61,125,178,254,232,209,108,246,230,91,247,212,216,187,115,90,102,118,111,103,162,25,
162,226,13,204,250,18,193,177,63,112,228,98,193,145,30,188,252,182,239,110,218,89,30,253,194,94,30,207,124,22,7,150,75,155,9,155,253,14,9,207,78,152,123,221,170,149,109,83,83,242,196,158,21,61,185,141,
168,182,65,119,34,100,219,233,180,121,203,207,46,180,190,83,159,152,105,124,233,211,215,203,204,220,78,92,88,7,231,176,113,66,213,191,128,93,121,155,218,250,18,97,53,64,137,48,90,58,203,55,95,196,225,
147,223,255,62,190,183,107,156,23,71,33,231,134,235,244,194,179,164,7,186,119,27,253,173,175,196,122,143,33,104,231,180,199,145,173,11,182,113,232,199,167,167,190,127,223,77,51,193,67,159,189,75,154,91,
175,192,122,17,38,78,40,251,235,148,27,171,148,189,85,100,115,13,61,26,33,165,193,101,16,76,116,248,212,190,150,140,250,3,239,169,191,120,183,238,232,218,243,59,60,46,149,138,60,130,114,48,123,178,210,
143,204,227,79,94,162,209,233,120,147,181,122,184,251,201,55,155,63,186,247,192,76,112,251,39,239,17,90,147,152,162,160,88,93,194,246,150,144,225,50,146,246,208,69,140,135,65,180,197,57,129,162,196,57,
5,78,177,255,170,46,82,246,228,215,111,113,240,142,221,252,214,87,36,105,135,172,55,164,84,141,101,124,21,210,8,141,153,122,234,68,244,245,176,51,211,184,237,227,119,138,107,140,83,198,35,202,11,11,200,
198,34,94,186,130,103,134,4,174,36,136,4,213,170,99,199,186,152,198,56,101,163,139,49,138,202,58,170,161,227,51,7,118,0,4,63,57,206,183,117,197,140,74,104,55,132,64,53,42,130,118,147,246,27,253,218,141,
175,141,38,110,249,242,253,251,69,58,83,152,178,160,90,191,136,196,23,241,170,17,190,15,97,45,32,28,11,9,219,17,81,35,34,104,214,81,221,38,213,216,24,85,171,67,101,192,42,135,51,194,15,111,71,142,44,248,
251,142,173,114,91,93,51,38,109,34,175,214,38,116,134,206,159,215,213,3,135,118,7,108,155,155,167,146,0,179,121,1,201,214,208,20,4,129,66,71,1,42,138,64,7,32,2,182,66,242,28,229,103,148,34,24,64,138,18,
201,71,136,64,109,251,21,220,186,243,140,188,190,206,131,87,79,242,2,16,121,126,65,24,5,210,222,44,131,221,119,93,81,19,23,54,177,85,137,20,67,148,77,241,124,193,139,2,164,209,68,162,26,18,4,136,82,184,
210,224,194,12,73,20,84,14,107,45,182,108,96,171,4,167,43,92,234,248,208,44,60,125,130,153,64,209,106,86,132,74,9,129,31,170,250,234,200,111,141,111,223,137,21,141,77,18,40,99,148,179,120,90,35,81,132,
68,53,84,171,133,106,119,144,214,24,170,213,70,106,13,36,168,163,162,16,29,122,88,63,194,73,136,205,5,23,194,7,58,176,182,166,2,79,168,99,8,84,233,227,45,245,212,120,108,2,61,221,242,112,241,128,42,238,
65,145,162,196,33,190,2,239,242,8,37,170,67,163,3,173,46,212,155,72,88,131,192,71,124,15,173,20,226,43,172,23,128,178,184,92,8,183,238,32,181,158,58,53,98,78,69,120,74,43,228,88,207,238,233,232,77,75,
210,199,172,46,82,173,158,135,116,0,84,8,130,136,128,40,208,26,130,8,106,77,240,125,68,41,80,234,242,159,40,80,128,6,103,213,229,101,27,122,76,180,11,119,162,199,94,169,16,175,178,184,253,147,213,169,
159,159,242,148,191,121,30,51,138,209,185,65,60,141,83,17,206,89,156,181,56,91,33,166,132,44,133,188,128,162,192,217,10,172,133,194,130,179,96,1,231,16,237,0,129,220,176,54,8,228,170,241,226,184,211,56,
207,47,49,227,13,214,235,217,160,50,111,191,161,235,179,123,40,83,168,198,218,184,202,195,86,21,170,42,112,73,134,83,30,98,44,120,10,87,148,184,44,189,92,212,149,84,165,133,194,160,170,2,49,14,105,65,
182,114,142,154,82,118,79,147,197,65,134,241,172,163,168,74,146,201,45,118,240,167,85,186,31,157,205,1,7,169,135,209,117,170,176,64,233,20,165,60,92,226,112,38,7,81,184,170,132,52,199,165,9,85,86,80,149,
5,146,231,72,86,32,145,32,86,113,116,13,38,38,108,97,28,9,30,133,42,3,242,82,49,236,214,56,245,234,57,156,202,29,202,3,29,199,168,60,198,164,5,38,43,176,241,0,59,120,39,250,184,193,0,27,15,49,89,66,153,
230,184,97,129,202,99,180,50,40,1,241,224,229,37,216,210,224,82,97,25,142,52,185,74,7,228,226,209,191,97,59,207,189,178,228,179,185,178,136,178,130,18,208,233,0,233,199,148,113,74,57,204,48,163,17,213,
176,143,29,110,98,70,67,202,56,161,24,102,216,81,138,26,13,46,55,232,20,170,130,108,233,12,191,91,240,221,117,91,120,246,31,135,53,211,15,238,66,107,131,154,107,144,110,20,118,231,115,111,48,127,223,181,
77,65,20,98,13,24,3,214,81,21,66,69,69,85,24,76,94,97,242,2,91,20,208,79,209,131,62,94,58,64,251,130,87,119,40,207,241,181,195,3,119,245,86,251,183,59,230,120,114,104,184,96,83,250,250,254,131,72,107,
3,209,17,114,227,20,39,95,90,230,19,235,241,48,248,224,124,87,176,32,101,133,164,9,98,11,200,202,203,81,228,168,52,65,134,49,58,27,224,145,226,249,224,105,80,158,226,249,35,139,44,172,83,60,114,128,111,
20,112,38,11,88,139,51,18,125,205,93,48,85,224,60,139,19,3,179,77,22,158,121,221,251,88,146,245,184,126,174,41,162,20,226,4,49,6,69,134,138,83,116,18,163,147,4,207,102,104,28,218,9,90,4,229,59,158,249,
253,34,207,31,243,220,3,215,218,199,187,1,175,245,12,151,130,101,134,99,227,20,250,173,211,83,220,25,196,46,24,199,186,4,59,91,103,115,215,132,125,243,133,51,124,248,240,209,97,112,235,214,190,212,199,
186,40,237,80,2,74,4,29,128,82,10,173,4,173,64,43,33,189,120,150,175,254,98,224,206,196,228,15,237,183,223,189,114,11,191,25,70,156,143,135,108,186,139,228,251,205,221,213,123,26,164,214,96,186,97,216,
254,212,9,30,125,101,209,255,200,193,249,146,27,166,145,131,227,208,216,182,3,234,26,138,138,244,194,57,142,172,195,171,231,225,143,103,125,119,112,190,60,250,208,213,255,193,32,206,185,127,233,234,7,
104,115,195,101,93,117,75,186,126,157,169,227,75,28,56,178,204,231,55,50,230,87,215,84,51,179,158,234,54,74,183,17,251,18,41,99,39,39,236,187,116,101,3,150,99,88,239,111,50,236,205,144,113,8,243,240,99,
83,238,159,186,250,111,110,20,143,49,223,210,210,62,245,165,33,147,127,221,96,223,222,49,78,236,168,179,2,36,239,184,49,243,233,167,33,195,193,250,123,187,81,254,95,17,231,150,66,71,255,155,136,255,14,
118,253,52,113,147,2,111,107,0,0,0,0,73,69,78,68,174,66,96,130,0,0};

const char* BigOrangeToggle::bigOrangeToggleOn_png = (const char*) resource_BigOrangeToggle_bigOrangeToggleOn_png;
const int BigOrangeToggle::bigOrangeToggleOn_pngSize = 2038;


//[EndFile] You can add extra defines here...
//[/EndFile]