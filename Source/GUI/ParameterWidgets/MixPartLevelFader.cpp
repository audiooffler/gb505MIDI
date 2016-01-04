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

#include "MixPartLevelFader.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
MixPartLevelFader::MixPartLevelFader (const String &componentName)
    : ParameterSlider (componentName)
{

    //[UserPreSize]
	m_lookAndFeel = new MixSliderLookAndFeel();
	setLookAndFeel(m_lookAndFeel);
	setPopupMenuEnabled(true);

    setRange (0, 127, 1);
    setSliderStyle (Slider::LinearVertical);
    setTextBoxStyle (Slider::TextBoxBelow, false, 80, 20);
	setColour(textBoxBackgroundColourId, GrooveboxLookAndFeel::Mc307LcdBackground);
    //[/UserPreSize]

    setSize (32, 188);


    //[Constructor] You can add your own custom stuff here..
    //[/Constructor]
}

MixPartLevelFader::~MixPartLevelFader()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]



    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void MixPartLevelFader::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    Slider::paint(g);
    //[/UserPrePaint]

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void MixPartLevelFader::resized()
{
    //[UserResized] Add your own custom resize handling here..
    Slider::resized();
    //[/UserResized]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
MixPartLevelFader::MixSliderLookAndFeel::MixSliderLookAndFeel()
	: LookAndFeel_V3()
{
	m_verticalHandleImg = ImageCache::getFromMemory(mixSliderThumb_png, mixSliderThumb_pngSize);
	m_horizontalHandleImg = Image(Image::ARGB, m_verticalHandleImg.getHeight(), m_verticalHandleImg.getWidth(),true);
	ScopedPointer<Graphics> g = new Graphics(m_horizontalHandleImg);
	g->drawImageTransformed(m_verticalHandleImg, AffineTransform().rotated(float_Pi*0.5f).translated((float)m_verticalHandleImg.getHeight(), 0.0f));
}

MixPartLevelFader::MixSliderLookAndFeel::~MixSliderLookAndFeel()
{

}
int MixPartLevelFader::MixSliderLookAndFeel::getSliderThumbRadius(Slider &)
{
	//return LookAndFeel_V3::getSliderThumbRadius(slider);
	//return jmax<int>(m_verticalHandleImg.getWidth(), m_verticalHandleImg.getHeight());
	return 17;
}

void MixPartLevelFader::MixSliderLookAndFeel::drawLinearSliderBackground(Graphics &g, int x, int y, int width, int height, float, float, float, const Slider::SliderStyle style, Slider &)
{
	if (style == Slider::SliderStyle::LinearVertical)
	{
		float horizontalCenter = (float)x + (float)width * 0.5f;
		float verticalCenter = (float)y + (float(height) * 0.5f);
		float slotThickness = 5.0f;

		// big markers
		g.setColour(Colours::black);
		float markerWidth = jmin<float>(32.0f, (float)width);
		float markLeft = horizontalCenter - markerWidth*0.5f;
		float markRight = horizontalCenter + markerWidth*0.5f;
		Path faderBigMarkings;
		faderBigMarkings.startNewSubPath(markLeft, (float)y);
		faderBigMarkings.lineTo(markRight, (float)y);
		faderBigMarkings.startNewSubPath(markLeft, verticalCenter);
		faderBigMarkings.lineTo(markRight, verticalCenter);
		faderBigMarkings.startNewSubPath(markLeft, (float)y + (float)height);
		faderBigMarkings.lineTo(markRight, (float)y + (float)height);
		faderBigMarkings.closeSubPath();
		g.strokePath(faderBigMarkings, PathStrokeType(2.5f));

		// thin markers
		if (height >= 64)
		{
			Path faderThinMarkings;
			for (int i = 1; i < 10; i++)
			{
				float markY = (float)y + ((float)height / 10)*i;
				if (i != 5)
				{
					faderThinMarkings.startNewSubPath(markLeft, markY);
					faderThinMarkings.lineTo(markRight, markY);
				}
			}
			faderThinMarkings.closeSubPath();
			g.strokePath(faderThinMarkings, PathStrokeType(1.0f));
		}
		// black slot
		g.setColour(Colours::black);
		Path faderSlot;
		faderSlot.clear();
		faderSlot.startNewSubPath(horizontalCenter, (float)y);
		faderSlot.lineTo(horizontalCenter, (float)(y + height));
		faderSlot.closeSubPath();
		g.strokePath(faderSlot, PathStrokeType(slotThickness, PathStrokeType::mitered, PathStrokeType::square));

		// light slot
		g.setColour(Colour(0xffa0a0a0));
		Path faderSlotLight;
		float right = horizontalCenter + ((slotThickness - 1.0f) / 2.0f) + 1.0f;
		float left = horizontalCenter - ((slotThickness - 1.0f) / 2.0f) + 1.0f;
		faderSlotLight.startNewSubPath(right, (float)y + 1.0f);
		faderSlotLight.lineTo(right, (float)y + (float)height + ((slotThickness - 1.0f) / 2.0f) + 1.0f);
		faderSlotLight.lineTo(left, (float)y + (float)height + (slotThickness - 1.0f) / 2.0f + 1.0f);
		g.strokePath(faderSlotLight, PathStrokeType(1.000f, PathStrokeType::mitered, PathStrokeType::square));
	}
	else if (style == Slider::LinearHorizontal)
	{
		float horizontalCenter = (float)x + (float)width * 0.5f;
		float verticalCenter = (float)y + (float(height) * 0.5f);
		float slotThickness = 5.0f;

		// big markers
		g.setColour(Colours::black);
		float markerHeight = jmin<float>(32.0f, (float)height);
		float markUp = verticalCenter - markerHeight*0.5f;
		float markDown = verticalCenter + markerHeight*0.5f;
		Path faderBigMarkings;
		faderBigMarkings.startNewSubPath((float)x, markUp);
		faderBigMarkings.lineTo((float)x, markDown);
		faderBigMarkings.startNewSubPath(horizontalCenter, markUp);
		faderBigMarkings.lineTo(horizontalCenter,markDown);
		faderBigMarkings.startNewSubPath((float)x + (float)width,markUp);
		faderBigMarkings.lineTo((float)x + (float)width, markDown);
		faderBigMarkings.closeSubPath();
		g.strokePath(faderBigMarkings, PathStrokeType(2.5f));

		// thin markers
		if (width >= 64)
		{
			Path faderThinMarkings;
			for (int i = 1; i < 10; i++)
			{
				float markX = (float)x + ((float)width / 10)*i;
				if (i != 5)
				{
					faderThinMarkings.startNewSubPath(markX, markUp);
					faderThinMarkings.lineTo(markX, markDown);
				}
			}
			faderThinMarkings.closeSubPath();
			g.strokePath(faderThinMarkings, PathStrokeType(1.0f));
		}
		// black slot
		g.setColour(Colours::black);
		Path faderSlot;
		faderSlot.clear();
		faderSlot.startNewSubPath((float)x,verticalCenter);
		faderSlot.lineTo((float)(x + width),verticalCenter);
		faderSlot.closeSubPath();
		g.strokePath(faderSlot, PathStrokeType(slotThickness, PathStrokeType::mitered, PathStrokeType::square));

		// light slot
		g.setColour(Colour(0xffa0a0a0));
		Path faderSlotLight;
		float up = verticalCenter - ((slotThickness - 1.0f) / 2.0f) + 1.0f;
		float down = verticalCenter + ((slotThickness - 1.0f) / 2.0f) + 1.0f;
		faderSlotLight.startNewSubPath((float)x + 1.0f,down);
		faderSlotLight.lineTo((float)x + (float)width + ((slotThickness - 1.0f) / 2.0f) + 1.0f,down);
		faderSlotLight.lineTo((float)x + (float)width + (slotThickness - 1.0f) / 2.0f + 1.0f, up);
		g.strokePath(faderSlotLight, PathStrokeType(1.000f, PathStrokeType::mitered, PathStrokeType::square));
	}
}

void MixPartLevelFader::MixSliderLookAndFeel::drawLinearSliderThumb(Graphics &g, int x, int y, int width, int height, float sliderPos, float minSliderPos, float maxSliderPos, const Slider::SliderStyle style, Slider &slider)
{
	if (style == Slider::SliderStyle::LinearVertical)
	{
		g.drawImage(m_verticalHandleImg,
			x + (width - m_verticalHandleImg.getWidth()) / 2, (int)sliderPos - m_verticalHandleImg.getHeight() / 2, m_verticalHandleImg.getWidth(), m_verticalHandleImg.getHeight(),
			0, 0, m_verticalHandleImg.getWidth(), m_verticalHandleImg.getHeight());
	}
	else if (style == Slider::SliderStyle::LinearHorizontal)
	{
		g.drawImage(m_horizontalHandleImg,
			(int)sliderPos - (m_horizontalHandleImg.getWidth() / 2), y + (height - m_horizontalHandleImg.getHeight()) / 2, m_horizontalHandleImg.getWidth(), m_horizontalHandleImg.getHeight(),
			0, 0, m_horizontalHandleImg.getWidth(), m_horizontalHandleImg.getHeight());
	}
	else
	{
		LookAndFeel_V3::drawLinearSliderThumb(g, x, y, width, height, sliderPos, minSliderPos, maxSliderPos, style, slider);
	}
}

void MixPartLevelFader::setTextBoxStyle(TextEntryBoxPosition newPosition, bool isReadOnly, int textEntryBoxWidth, int textEntryBoxHeight)
{
	((Slider*)this)->setTextBoxStyle(newPosition, isReadOnly, textEntryBoxWidth, textEntryBoxHeight);
	if (getTextBoxPosition() == Slider::NoTextBox || getTextBoxWidth() < 0 || getTextBoxHeight() < 0)
	{
		setPopupDisplayEnabled(true, nullptr);
	}
}
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Introjucer information section --

    This is where the Introjucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="MixPartLevelFader" componentName=""
                 parentClasses="public ParameterSlider" constructorParams="const String &amp;componentName"
                 variableInitialisers="ParameterSlider (componentName)" snapPixels="8"
                 snapActive="1" snapShown="1" overlayOpacity="0.330" fixedSize="1"
                 initialWidth="32" initialHeight="188">
  <BACKGROUND backgroundColour="0"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif

//==============================================================================
// Binary resources - be careful not to edit any of these sections!

// JUCER_RESOURCE: mixSliderThumb_png, 825, "../../../Resources/LookAndFeel/mixSliderThumb.png"
static const unsigned char resource_MixPartLevelFader_mixSliderThumb_png[] = { 137,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,0,26,0,0,0,35,8,6,0,0,0,138,63,26,171,0,0,0,4,115,66,73,84,8,8,8,8,124,
8,100,136,0,0,0,9,112,72,89,115,0,0,12,90,0,0,12,90,1,201,158,27,251,0,0,0,25,116,69,88,116,83,111,102,116,119,97,114,101,0,119,119,119,46,105,110,107,115,99,97,112,101,46,111,114,103,155,238,60,26,0,
0,2,182,73,68,65,84,72,137,181,151,219,110,211,64,16,134,191,217,181,147,52,33,66,84,112,5,21,16,78,111,128,120,8,46,250,84,133,219,62,15,23,112,219,23,0,4,69,156,138,148,158,75,81,227,214,222,221,225,
194,118,107,199,41,42,90,248,165,149,146,205,102,191,29,207,236,204,24,254,143,228,210,137,213,213,213,9,16,98,118,15,33,200,233,233,169,205,178,172,151,231,249,214,198,198,198,113,253,91,114,177,76,63,
100,89,86,56,231,124,12,12,16,208,222,120,124,237,21,240,156,234,240,73,115,197,247,239,91,131,233,116,26,201,129,193,96,192,147,39,143,175,3,41,112,214,2,169,42,198,24,142,142,142,162,65,227,241,24,231,
92,15,24,1,57,160,166,185,96,56,28,70,67,106,133,16,82,224,6,165,85,237,71,39,34,172,172,172,68,67,118,119,119,1,181,192,77,96,27,200,155,32,177,137,37,196,5,30,0,214,90,64,250,214,218,101,239,253,0,152,
181,64,189,180,135,185,228,207,87,149,49,6,107,45,34,98,40,125,180,4,152,38,72,173,53,210,239,247,35,81,212,183,83,40,93,51,104,129,234,168,115,206,69,49,140,49,160,45,100,10,200,92,48,24,66,80,98,164,
234,75,216,156,230,64,144,166,105,20,40,4,143,152,243,204,166,128,3,52,105,47,19,66,136,203,64,33,120,140,180,64,190,3,18,17,138,34,206,71,33,120,202,128,67,185,204,162,126,191,207,211,103,79,163,64,174,
40,248,248,225,83,253,117,177,69,203,203,203,172,173,173,69,129,102,217,140,23,47,95,240,254,237,187,26,212,181,40,47,114,94,191,121,29,5,2,152,78,183,235,143,129,69,22,29,28,28,178,190,190,30,5,201,102,
25,219,59,59,60,122,248,160,158,82,152,11,239,52,73,56,254,25,87,38,172,77,72,211,164,51,223,137,186,201,228,65,103,209,223,168,40,138,133,53,173,131,62,254,245,51,10,100,141,37,104,55,187,180,64,138,
178,191,183,31,5,90,90,26,46,204,151,231,32,41,197,221,123,247,162,64,70,12,91,63,126,156,111,219,1,65,153,193,139,34,143,2,165,73,218,109,234,104,91,132,115,142,175,95,190,70,129,70,163,17,33,40,170,
161,149,157,231,238,209,1,195,225,40,10,164,10,39,39,39,132,16,28,141,202,84,131,12,192,222,222,62,155,155,155,81,32,128,36,73,80,165,21,122,134,210,97,125,64,138,162,136,134,204,233,188,211,169,65,35,
40,47,219,191,82,85,146,10,230,90,98,19,130,47,38,147,251,249,157,59,183,227,251,45,72,207,206,242,207,34,50,163,74,170,194,133,69,143,172,181,19,224,58,92,185,235,18,46,28,174,213,233,181,178,228,151,
247,254,51,240,137,170,175,83,32,3,190,121,239,37,73,146,91,170,154,178,224,29,231,15,10,64,16,17,79,89,127,50,231,220,33,176,67,213,228,55,55,75,104,52,124,141,19,95,197,162,122,132,106,184,10,112,86,
91,57,191,145,52,198,223,104,81,143,166,205,249,223,178,103,23,65,170,170,128,140,0,0,0,0,73,69,78,68,174,66,96,130,0,0};

const char* MixPartLevelFader::mixSliderThumb_png = (const char*) resource_MixPartLevelFader_mixSliderThumb_png;
const int MixPartLevelFader::mixSliderThumb_pngSize = 825;


//[EndFile] You can add extra defines here...
//[/EndFile]
