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

#include "ParameterEnvelopeSlider.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
ParameterEnvelopeSlider::ParameterEnvelopeSlider (const String &componentName)
    : ParameterSlider (componentName)
{

    //[UserPreSize]
	m_lookAndFeel = new EnvSliderLookAndFeel();
	setLookAndFeel(m_lookAndFeel);
	setPopupMenuEnabled(true);
    //[/UserPreSize]

    setSize (600, 400);


    //[Constructor] You can add your own custom stuff here..
    //[/Constructor]
}

ParameterEnvelopeSlider::~ParameterEnvelopeSlider()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]



    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void ParameterEnvelopeSlider::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    Slider::paint(g);
    //[/UserPrePaint]

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void ParameterEnvelopeSlider::resized()
{
    //[UserResized] Add your own custom resize handling here..
    Slider::resized();
    //[/UserResized]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
ParameterEnvelopeSlider::EnvSliderLookAndFeel::EnvSliderLookAndFeel()
	: LookAndFeel_V3()
{
	m_verticalHandleImg = ImageCache::getFromMemory(envSliderHandle_png, envSliderHandle_pngSize);
	m_horizontalHandleImg = Image(Image::ARGB, m_verticalHandleImg.getHeight(), m_verticalHandleImg.getWidth(),true);
	ScopedPointer<Graphics> g = new Graphics(m_horizontalHandleImg);
	g->drawImageTransformed(m_verticalHandleImg, AffineTransform().rotated(-float_Pi / 2.0f).translated(0.0f, (float)m_verticalHandleImg.getWidth()));
}

ParameterEnvelopeSlider::EnvSliderLookAndFeel::~EnvSliderLookAndFeel()
{

}
int ParameterEnvelopeSlider::EnvSliderLookAndFeel::getSliderThumbRadius(Slider &slider)
{
	return LookAndFeel_V3::getSliderThumbRadius(slider);
	//return 18;
}

void ParameterEnvelopeSlider::EnvSliderLookAndFeel::drawLinearSliderBackground(Graphics &g, int x, int y, int width, int height, float, float, float, const Slider::SliderStyle style, Slider &)
{
	if (style == Slider::SliderStyle::LinearVertical)
	{
		float horizontalCenter = (float)x + (float)width * 0.5f;
		float verticalCenter = (float)y + (float(height) * 0.5f);
		float slotThickness = 3.0f;

		// big markers
		g.setColour(Colour(Colours::whitesmoke));
		float markerWidth = jmin<float>(24.0f, (float)width);
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
		g.setColour(Colour(Colours::whitesmoke));
		float markerHeight = jmin<float>(32.0f, (float)height);
		float markUp = verticalCenter - markerHeight*0.5f;
		float markDown = verticalCenter + markerHeight*0.5f;
		Path faderBigMarkings;
		faderBigMarkings.startNewSubPath((float)x, markUp);
		faderBigMarkings.lineTo((float)x, markDown);
		faderBigMarkings.startNewSubPath(horizontalCenter, markUp);
		faderBigMarkings.lineTo(horizontalCenter, markDown);
		faderBigMarkings.startNewSubPath((float)x + (float)width, markUp);
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
		faderSlot.startNewSubPath((float)x, verticalCenter);
		faderSlot.lineTo((float)(x + width), verticalCenter);
		faderSlot.closeSubPath();
		g.strokePath(faderSlot, PathStrokeType(slotThickness, PathStrokeType::mitered, PathStrokeType::square));

		// light slot
		g.setColour(Colour(0xffa0a0a0));
		Path faderSlotLight;
		float up = verticalCenter - ((slotThickness - 1.0f) / 2.0f) + 1.0f;
		float down = verticalCenter + ((slotThickness - 1.0f) / 2.0f) + 1.0f;
		faderSlotLight.startNewSubPath((float)x + 1.0f, down);
		faderSlotLight.lineTo((float)x + (float)width + ((slotThickness - 1.0f) / 2.0f) + 1.0f, down);
		faderSlotLight.lineTo((float)x + (float)width + (slotThickness - 1.0f) / 2.0f + 1.0f, up);
		g.strokePath(faderSlotLight, PathStrokeType(1.000f, PathStrokeType::mitered, PathStrokeType::square));
	}
}

void ParameterEnvelopeSlider::EnvSliderLookAndFeel::drawLinearSliderThumb(Graphics &g, int x, int y, int width, int height, float sliderPos, float minSliderPos, float maxSliderPos, const Slider::SliderStyle style, Slider &slider)
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

void ParameterEnvelopeSlider::setTextBoxStyle(TextEntryBoxPosition newPosition, bool isReadOnly, int textEntryBoxWidth, int textEntryBoxHeight)
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

<JUCER_COMPONENT documentType="Component" className="ParameterEnvelopeSlider"
                 componentName="" parentClasses="public ParameterSlider" constructorParams="const String &amp;componentName"
                 variableInitialisers="ParameterSlider (componentName)" snapPixels="8"
                 snapActive="1" snapShown="1" overlayOpacity="0.330" fixedSize="0"
                 initialWidth="600" initialHeight="400">
  <BACKGROUND backgroundColour="0"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif

//==============================================================================
// Binary resources - be careful not to edit any of these sections!

// JUCER_RESOURCE: envSliderHandle_png, 703, "../Resources/EnvSliderHandle.png"
static const unsigned char resource_ParameterEnvelopeSlider_envSliderHandle_png[] = { 137,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,0,12,0,0,0,18,8,6,0,0,0,111,169,63,12,0,0,0,6,98,75,71,68,0,255,
0,255,0,255,160,189,167,147,0,0,0,9,112,72,89,115,0,0,4,22,0,0,4,22,1,208,52,206,58,0,0,0,7,116,73,77,69,7,222,10,24,6,1,41,100,217,101,177,0,0,2,76,73,68,65,84,40,207,93,144,189,78,21,81,20,133,215,222,
103,159,159,48,119,40,140,33,65,32,132,70,19,26,169,164,160,180,225,25,168,237,109,124,3,43,19,124,3,173,44,109,236,124,14,18,155,43,21,137,65,130,132,185,220,59,195,157,57,115,206,217,54,64,208,149,172,
238,251,138,181,8,255,198,17,209,155,170,170,94,169,170,237,186,238,7,128,79,0,254,220,3,244,8,126,189,181,181,245,237,224,224,128,235,186,198,229,229,37,166,211,169,157,78,167,86,85,223,1,248,8,0,114,
7,191,92,95,95,255,186,191,191,31,54,54,54,196,57,135,24,35,38,147,9,172,181,136,49,30,3,184,4,240,133,1,192,90,251,97,109,109,77,66,8,102,115,115,19,187,187,187,168,235,26,222,123,88,107,65,68,0,240,
25,0,177,49,102,34,34,47,68,36,120,239,105,111,111,15,135,135,135,112,206,65,68,96,140,1,51,195,24,99,137,104,157,153,249,25,51,147,136,24,102,70,8,1,206,57,48,51,136,8,34,130,149,149,21,168,42,136,232,
185,132,16,12,17,25,239,61,141,227,136,147,147,19,52,77,131,190,239,145,115,70,8,1,222,251,18,99,156,169,170,136,115,78,75,41,92,85,149,222,222,222,210,217,217,25,46,46,46,208,117,29,98,140,96,102,120,
239,117,185,92,206,135,97,16,17,17,211,247,125,229,156,227,229,114,137,235,235,107,88,107,49,159,207,31,164,186,174,137,153,13,128,44,170,170,57,103,110,219,22,49,198,135,177,77,211,160,235,58,244,125,
15,107,45,167,148,106,85,37,73,41,149,24,99,117,117,117,133,148,210,253,35,104,154,6,139,197,2,195,48,96,177,88,32,165,100,75,41,69,134,97,80,0,93,219,182,147,190,239,9,0,140,49,152,205,102,152,205,102,
32,34,228,156,161,170,122,247,166,48,17,205,140,49,213,124,62,167,113,28,193,204,104,219,22,41,37,132,16,64,68,217,90,123,147,82,34,89,93,93,237,219,182,109,141,49,185,148,194,77,211,0,0,82,74,0,0,17,
129,136,168,181,118,30,66,184,226,211,211,211,179,82,74,79,68,17,0,198,113,196,56,142,80,85,0,64,206,25,57,103,141,49,250,163,163,163,159,80,85,218,217,217,121,191,189,189,253,59,132,48,2,208,199,53,198,
168,247,62,50,243,133,170,26,196,24,121,24,134,39,147,201,228,59,51,47,255,23,152,89,137,40,158,159,159,63,45,165,48,84,149,134,97,112,170,42,68,244,22,192,175,71,194,13,128,99,85,149,82,138,3,128,191,
182,92,56,86,122,157,137,249,0,0,0,0,73,69,78,68,174,66,96,130,0,0};

const char* ParameterEnvelopeSlider::envSliderHandle_png = (const char*) resource_ParameterEnvelopeSlider_envSliderHandle_png;
const int ParameterEnvelopeSlider::envSliderHandle_pngSize = 703;


//[EndFile] You can add extra defines here...
//[/EndFile]
