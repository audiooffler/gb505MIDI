/*
  ==============================================================================

  This is an automatically generated GUI class created by the Projucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Projucer version: 7.0.2

  ------------------------------------------------------------------------------

  The Projucer is part of the JUCE library.
  Copyright (c) 2020 - Raw Material Software Limited.

  ==============================================================================
*/

//[Headers] You can add your own extra header files here...
//[/Headers]

#include "SmallGreenToggle.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
SmallGreenToggle::SmallGreenToggle()
	: ParameterToggle()
{
	cachedImage_smallOrangeToggleOff_png_1 = ImageCache::getFromMemory(smallOrangeToggleOff_png, smallOrangeToggleOff_pngSize);
	cachedImage_smallGreenToggleOn_png = ImageCache::getFromMemory(smallGreenToggleOn_png, smallGreenToggleOn_pngSize);
	setSize(12, 12);
}

SmallGreenToggle::SmallGreenToggle(const String& componentName, bool isInTable)
	:SmallGreenToggle(componentName)
{
	m_isInTable = isInTable;
}
//[/MiscUserDefs]

//==============================================================================
SmallGreenToggle::SmallGreenToggle (const String& componentName)
    : ParameterToggle(componentName)
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    cachedImage_smallOrangeToggleOff_png_1 = juce::ImageCache::getFromMemory (smallOrangeToggleOff_png, smallOrangeToggleOff_pngSize);

    //[UserPreSize]
	cachedImage_smallGreenToggleOn_png = ImageCache::getFromMemory(smallGreenToggleOn_png, smallGreenToggleOn_pngSize);
    //[/UserPreSize]

    setSize (12, 12);


    //[Constructor] You can add your own custom stuff here..
    //[/Constructor]
}

SmallGreenToggle::~SmallGreenToggle()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]



    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void SmallGreenToggle::paint (juce::Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
	//ToggleButton::paint(g);
    //[/UserPrePaint]

    {
        int x = (getWidth() / 2) - (12 / 2), y = (getHeight() / 2) - (12 / 2), width = 12, height = 12;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (juce::Colours::black);
        g.drawImage (cachedImage_smallOrangeToggleOff_png_1,
                     x, y, width, height,
                     0, 0, cachedImage_smallOrangeToggleOff_png_1.getWidth(), cachedImage_smallOrangeToggleOff_png_1.getHeight());
    }

    //[UserPaint] Add your own custom painting code here..
	if (getToggleState())
	{
		g.setColour(Colours::black);
		g.drawImage(cachedImage_smallGreenToggleOn_png,
			(getWidth() / 2) - ((12) / 2), (getHeight() / 2) - ((12) / 2), 12, 12,
			0, 0, cachedImage_smallGreenToggleOn_png.getWidth(), cachedImage_smallGreenToggleOn_png.getHeight());
	}
    //[/UserPaint]
}

void SmallGreenToggle::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    //[UserResized] Add your own custom resize handling here..
	ToggleButton::resized();
    //[/UserResized]
}

void SmallGreenToggle::mouseDown (const juce::MouseEvent& e)
{
    //[UserCode_mouseDown] -- Add your code here...
    if (m_isInTable) getParentComponent()->mouseDown(e);
	ParameterToggle::mouseDown(e);
    //[/UserCode_mouseDown]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="SmallGreenToggle" componentName=""
                 parentClasses="public ParameterToggle" constructorParams="const String&amp; componentName"
                 variableInitialisers="ParameterToggle(componentName)" snapPixels="8"
                 snapActive="1" snapShown="1" overlayOpacity="0.330" fixedSize="1"
                 initialWidth="12" initialHeight="12">
  <METHODS>
    <METHOD name="mouseDown (const MouseEvent&amp; e)"/>
  </METHODS>
  <BACKGROUND backgroundColour="0">
    <IMAGE pos="0Cc 0Cc 12 12" resource="smallOrangeToggleOff_png" opacity="1.0"
           mode="0"/>
  </BACKGROUND>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif

//==============================================================================
// Binary resources - be careful not to edit any of these sections!

// JUCER_RESOURCE: smallOrangeToggleOff_png, 637, "../../../Resources/LookAndFeel/SmallOrangeToggleOff.png"
static const unsigned char resource_SmallGreenToggle_smallOrangeToggleOff_png[] = { 137,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,0,12,0,0,0,12,8,6,0,0,0,86,117,92,231,0,0,0,4,115,66,73,84,8,8,8,8,
124,8,100,136,0,0,0,9,112,72,89,115,0,0,10,78,0,0,10,78,1,24,42,197,171,0,0,0,25,116,69,88,116,83,111,102,116,119,97,114,101,0,119,119,119,46,105,110,107,115,99,97,112,101,46,111,114,103,155,238,60,26,
0,0,1,250,73,68,65,84,40,145,85,146,205,79,19,65,0,71,127,51,59,59,221,37,28,148,10,105,40,85,172,81,99,76,84,48,86,69,73,76,250,7,40,23,129,68,15,28,224,208,152,24,211,155,127,129,222,245,82,227,71,140,
225,140,49,222,149,131,129,80,64,227,87,82,37,148,210,98,73,182,54,219,101,151,93,102,118,198,19,70,223,249,221,222,35,90,107,236,147,181,172,147,3,217,236,93,66,200,249,88,74,229,121,222,71,215,117,75,
85,223,95,221,119,136,214,26,132,16,122,225,232,145,135,167,206,14,77,221,154,153,78,166,51,25,56,142,131,149,165,37,148,231,231,157,242,194,226,92,183,227,20,202,90,11,162,181,198,185,116,250,193,76,
177,88,28,155,152,96,42,150,240,125,31,82,236,1,32,168,55,26,88,120,255,78,189,42,149,94,86,90,237,41,122,204,178,78,228,70,71,167,199,198,199,153,109,219,208,90,195,235,184,8,195,8,82,74,12,164,211,56,
61,52,76,115,35,87,175,15,118,117,141,208,100,127,255,244,141,201,201,30,165,98,68,225,46,162,40,66,20,69,16,98,15,82,10,196,113,140,76,230,48,46,231,175,29,52,45,171,192,24,99,185,193,108,22,187,65,128,
118,187,141,40,10,33,132,0,231,28,134,97,64,107,13,206,57,24,231,48,77,243,56,147,82,40,111,199,131,149,72,0,0,40,165,48,77,19,148,82,16,66,64,8,16,171,24,74,41,196,113,12,170,98,181,184,185,190,14,74,
41,24,99,224,156,131,243,4,76,147,195,48,24,40,53,208,113,93,164,250,82,80,74,253,48,236,48,172,53,234,245,155,87,242,249,110,219,74,128,82,3,134,97,128,49,6,198,24,252,32,192,183,47,159,241,252,209,227,
182,243,171,121,143,174,133,97,165,185,213,120,49,251,236,105,212,106,253,134,144,2,0,32,165,68,115,123,27,171,43,203,168,124,253,174,54,214,126,190,174,6,193,7,6,0,203,213,218,253,232,205,91,218,172,
109,222,62,115,233,98,42,217,219,11,106,80,244,245,28,194,108,233,137,179,85,221,152,59,224,118,10,127,75,255,187,6,181,237,59,132,144,97,0,68,43,245,73,10,241,223,26,127,0,7,194,241,24,87,226,122,90,
0,0,0,0,73,69,78,68,174,66,96,130,0,0};

const char* SmallGreenToggle::smallOrangeToggleOff_png = (const char*) resource_SmallGreenToggle_smallOrangeToggleOff_png;
const int SmallGreenToggle::smallOrangeToggleOff_pngSize = 637;

// JUCER_RESOURCE: smallGreenToggleOn_png, 660, "../../../Resources/LookAndFeel/SmallGreenToggleOn.png"
static const unsigned char resource_SmallGreenToggle_smallGreenToggleOn_png[] = { 137,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,0,12,0,0,0,12,8,6,0,0,0,86,117,92,231,0,0,0,4,115,66,73,84,8,8,8,8,124,
8,100,136,0,0,0,9,112,72,89,115,0,0,10,78,0,0,10,78,1,24,42,197,171,0,0,0,25,116,69,88,116,83,111,102,116,119,97,114,101,0,119,119,119,46,105,110,107,115,99,97,112,101,46,111,114,103,155,238,60,26,0,0,
2,17,73,68,65,84,40,145,53,210,61,79,19,97,0,7,240,255,221,243,92,123,244,104,185,214,43,87,222,45,182,161,12,162,209,24,19,98,36,12,110,234,86,103,88,89,248,6,198,79,225,228,208,89,70,99,162,11,36,200,
72,52,150,84,106,106,68,45,165,180,180,165,189,122,239,247,60,143,147,191,207,240,147,32,32,149,247,202,74,54,155,205,156,212,27,155,87,227,222,182,31,68,69,193,133,160,145,212,72,102,210,149,169,162,
121,112,101,99,80,123,177,23,74,229,183,229,24,185,65,22,170,71,245,215,75,146,190,177,112,207,140,39,19,49,56,18,129,118,74,241,222,255,234,185,93,231,112,118,197,220,25,37,58,77,178,254,114,221,248,
252,177,250,230,206,146,241,100,163,148,162,5,67,131,240,79,160,134,77,120,198,8,203,122,137,90,9,44,95,124,107,173,46,230,139,31,136,182,54,241,92,99,216,221,184,21,163,143,74,207,80,50,31,34,165,250,
16,104,67,225,1,92,222,69,65,220,149,234,236,114,110,220,247,170,178,213,117,182,215,102,104,124,114,138,65,85,2,104,49,192,76,74,152,215,21,100,39,9,116,26,97,152,108,98,126,113,94,181,47,6,91,20,33,
41,100,9,135,132,49,186,246,59,36,98,6,50,90,27,118,64,48,242,24,226,84,6,141,28,164,255,166,17,5,172,72,35,193,97,35,66,192,4,236,96,132,107,215,70,192,100,184,33,71,200,4,24,23,16,92,129,59,33,0,0,148,
41,81,163,23,51,243,147,78,27,61,69,2,231,2,10,149,224,4,2,3,135,193,242,56,88,108,26,238,77,11,228,88,110,208,217,172,89,249,249,67,126,172,231,117,149,99,8,203,231,160,178,4,63,226,24,121,28,67,165,
128,225,57,195,89,253,187,167,234,169,138,124,123,229,193,126,135,245,14,219,227,130,184,148,74,104,246,117,156,141,52,180,156,28,174,233,125,12,46,52,84,189,51,193,60,118,104,152,233,125,178,248,52,23,
206,228,230,142,142,27,95,86,127,91,227,57,95,76,83,226,229,240,39,34,104,153,46,170,159,106,158,219,177,15,204,188,177,227,116,251,29,233,127,13,91,67,230,215,233,249,166,213,234,111,177,144,21,5,4,72,
92,110,168,83,169,74,70,77,29,56,206,213,160,246,170,22,254,3,174,71,4,206,4,164,0,206,0,0,0,0,73,69,78,68,174,66,96,130,0,0};

const char* SmallGreenToggle::smallGreenToggleOn_png = (const char*) resource_SmallGreenToggle_smallGreenToggleOn_png;
const int SmallGreenToggle::smallGreenToggleOn_pngSize = 660;


//[EndFile] You can add extra defines here...
//[/EndFile]

