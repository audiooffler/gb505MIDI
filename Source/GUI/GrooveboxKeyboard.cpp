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

#include "GrooveboxKeyboard.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
GrooveboxKeyboard::GrooveboxKeyboard (MidiKeyboardState &state, Orientation orientation)
    : MidiKeyboardComponent(state, orientation)
{

    //[UserPreSize]
	cachedImage_whiteKeyOff_png = ImageCache::getFromMemory(whiteKeyOff_png, whiteKeyOff_pngSize);
	cachedImage_whiteKeyOn_png = ImageCache::getFromMemory(whiteKeyOn_png, whiteKeyOn_pngSize);
	cachedImage_blackKeyOff_png = ImageCache::getFromMemory(blackKeyOff_png, blackKeyOff_pngSize);
	cachedImage_blackKeyOn_png = ImageCache::getFromMemory(blackKeyOn_png, blackKeyOn_pngSize);

	setKeyWidth(30);
	setScrollButtonsVisible(true);
    //[/UserPreSize]

    setSize (120, 104);


    //[Constructor] You can add your own custom stuff here..
    //[/Constructor]
}

GrooveboxKeyboard::~GrooveboxKeyboard()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]



    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void GrooveboxKeyboard::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
	MidiKeyboardComponent::paint(g);
    //[/UserPrePaint]

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void GrooveboxKeyboard::resized()
{
    //[UserResized] Add your own custom resize handling here..
	MidiKeyboardComponent::resized();
    //[/UserResized]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
String GrooveboxKeyboard::getWhiteNoteText(const int /*midiNoteNumber*/)
{
	return String::empty;
}

void GrooveboxKeyboard::drawWhiteNote(int midiNoteNumber, Graphics &g, int x, int y, int w, int h, bool isDown, bool isOver, const Colour &/*lineColour*/, const Colour &textColour)
{
	//MidiKeyboardComponent::drawWhiteNote(midiNoteNumber, g, x, y, w, h, isDown, isOver, lineColour, textColour);
	g.setColour(Colours::black);
	g.drawImageWithin(isDown ? cachedImage_whiteKeyOn_png : cachedImage_whiteKeyOff_png, x, 0, 30, 35,RectanglePlacement::yTop, false);

	g.setColour(Colour(Colours::black).withAlpha(0.2f));
	if (isOver) g.fillRect(x, 0, 30, 104);

	g.setColour(Colours::black.withAlpha(0.5f));
	g.setFont(Font(jmin(12.0f, getKeyWidth() *0.9f)).withHorizontalScale(0.8f));
	g.drawFittedText(MidiMessage::getMidiNoteName(midiNoteNumber, true, true, 4), x, y+10, 30, 35-10, Justification::centred, 1);
	g.drawLine((float)x + 30.0f, (float)35.0f, (float)x + 30.0f, 104.0f);

	w = 30;
	h = 104;

	String name(MidiMessage::getRhythmInstrumentName(midiNoteNumber));
	if (name.isNotEmpty())
	{
		g.setColour(textColour);

		Justification justification(Justification::bottomLeft);
		if (getOrientation() == verticalKeyboardFacingLeft)
			justification = Justification::centredLeft;
		else if (getOrientation() == verticalKeyboardFacingRight)
			justification = Justification::centredRight;
		g.saveState();
		g.addTransform(AffineTransform::rotation(-0.5f*float_Pi, x+0.5f*(float)w, (float)y+(float)h-(float)0.5*(float)w));
		g.drawFittedText(name, x+4, (int)(y - 0.5*w + 6.0), h-40, h, justification, 1);
		g.restoreState();
	}
}

void GrooveboxKeyboard::drawBlackNote(int midiNoteNumber, Graphics &g, int x, int y, int w, int h, bool isDown, bool isOver, const Colour &/*noteFillColour*/)
{
	g.setColour(Colours::black);
	g.drawImageWithin(isDown ? cachedImage_blackKeyOn_png : cachedImage_blackKeyOff_png, x, 0, 30, 35, RectanglePlacement::yTop, false);

	g.setColour(Colour(Colours::white).withAlpha(0.2f));
	if (isOver) g.fillRect(x, 0, 30, 35);
	g.setColour(Colour(Colours::black).withAlpha(0.2f));
	if (isOver) g.fillRect(x, 35, 30, 104);

	g.setColour(Colour(Colours::white).withAlpha(0.5f));
	g.setFont(Font(jmin(12.0f, getKeyWidth() *0.9f)).withHorizontalScale(0.8f));
	g.drawFittedText(MidiMessage::getMidiNoteName(midiNoteNumber, true, true, 4), x, y+10, 30, 35-10, Justification::centred, 1);
	g.setColour(Colour(Colours::black).withAlpha(0.5f));
	g.drawLine((float)x + 30.0f, 35.0f, (float)x + 30.0f, 104.0f);

	w = 30;
	h = 104;

	String name(MidiMessage::getRhythmInstrumentName(midiNoteNumber));
	if (name.isNotEmpty())
	{
		g.setColour(Colours::black);

		Justification justification(Justification::bottomLeft);
		if (getOrientation() == verticalKeyboardFacingLeft)
			justification = Justification::centredLeft;
		else if (getOrientation() == verticalKeyboardFacingRight)
			justification = Justification::centredRight;
		g.saveState();
		g.addTransform(AffineTransform::rotation(-0.5f*float_Pi, (float)x + 0.5f*(float)w, (float)y + (float)h - 0.5f*(float)w));
		g.drawFittedText(name, x + 4, (int)(y - 0.5*w + 6), h-40, h, justification, 1);
		g.restoreState();
	}
}

void GrooveboxKeyboard::getKeyPosition(int midiNoteNumber, float keyWidth, int &x, int &w) const
{
	static const float notePos[] = {
		0.0f, 1.0f,
		2.0f, 3.0f,
		4.0f,
		5.0f, 6.0f,
		7.0f, 8.0f,
		9.0f, 10.0f,
		11.0f };

	const int octave = midiNoteNumber / 12;
	const int note = midiNoteNumber % 12;

	x = roundToInt(octave * 12.0f * keyWidth + notePos[note] * keyWidth);
	w = (int)keyWidth;
}

bool GrooveboxKeyboard::hitTest(int /*x*/, int y)
{
	if (y < 35) return true;
	else return false;
}

void GrooveboxKeyboard::mouseMove(const MouseEvent& e)
{
	if (e.getPosition().getY()<=35) MidiKeyboardComponent::mouseMove(e);
	else MidiKeyboardComponent::mouseExit(e);
}

void GrooveboxKeyboard::mouseDrag(const MouseEvent& e)
{
	if (e.getPosition().getY() <= 35) MidiKeyboardComponent::mouseDrag(e);
}

void GrooveboxKeyboard::mouseDown(const MouseEvent& e)
{
	if (e.getPosition().getY() <= 35) MidiKeyboardComponent::mouseDown(e);
}

void GrooveboxKeyboard::mouseUp(const MouseEvent& e)
{
	if (e.getPosition().getY() <= 35) MidiKeyboardComponent::mouseUp(e);
}

void GrooveboxKeyboard::mouseEnter(const MouseEvent& e)
{
	if (e.getPosition().getY() <= 35) MidiKeyboardComponent::mouseEnter(e);
}

void GrooveboxKeyboard::mouseExit(const MouseEvent& e)
{
	MidiKeyboardComponent::mouseExit(e);
}

void GrooveboxKeyboard::mouseWheelMove(const MouseEvent& e, const MouseWheelDetails& details)
{
	MidiKeyboardComponent::mouseWheelMove(e, details);
}

//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Introjucer information section --

    This is where the Introjucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="GrooveboxKeyboard" componentName=""
                 parentClasses="public MidiKeyboardComponent" constructorParams="MidiKeyboardState &amp;state, Orientation orientation"
                 variableInitialisers="MidiKeyboardComponent(state, orientation)"
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="1" initialWidth="120" initialHeight="104">
  <BACKGROUND backgroundColour="0"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif

//==============================================================================
// Binary resources - be careful not to edit any of these sections!

// JUCER_RESOURCE: whiteKeyOff_png, 946, "../../../../../Desktop/whiteKeyOff.png"
static const unsigned char resource_GrooveboxKeyboard_whiteKeyOff_png[] = { 137,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,0,30,0,0,0,35,8,6,0,0,0,131,212,186,209,0,0,0,4,115,66,73,84,8,8,8,8,124,8,
100,136,0,0,0,9,112,72,89,115,0,0,10,254,0,0,10,254,1,230,37,120,102,0,0,0,25,116,69,88,116,83,111,102,116,119,97,114,101,0,119,119,119,46,105,110,107,115,99,97,112,101,46,111,114,103,155,238,60,26,0,
0,3,47,73,68,65,84,88,133,181,87,65,78,236,48,12,125,73,91,70,176,235,72,69,156,0,137,21,103,225,16,112,35,46,192,22,46,132,216,193,10,208,72,5,58,76,155,54,201,95,124,156,73,82,39,29,164,255,45,69,77,
218,216,207,207,113,18,87,220,222,222,218,243,243,115,88,107,103,237,183,34,132,128,16,34,232,251,239,72,158,158,158,80,190,189,189,225,250,250,26,74,41,76,211,228,26,1,251,14,248,125,223,152,15,86,20,
5,138,162,64,85,85,40,203,210,53,223,198,253,253,61,196,217,217,153,125,126,126,70,223,247,14,212,24,19,176,206,177,247,65,233,89,150,101,0,92,85,149,251,62,142,35,154,166,129,124,125,125,117,64,198,24,
215,143,89,166,150,130,115,142,236,248,118,125,233,251,30,37,41,208,68,31,208,55,218,117,29,30,30,30,102,70,72,164,148,184,186,186,194,122,189,14,128,57,34,74,41,8,0,118,183,219,225,251,251,27,227,56,
206,0,169,127,115,115,131,182,109,81,20,5,11,108,140,193,201,201,9,238,238,238,220,90,87,85,21,52,0,80,74,97,181,90,65,198,33,229,198,214,90,92,94,94,98,24,6,40,165,216,54,142,35,46,46,46,2,135,83,172,
1,236,25,127,125,125,5,73,197,173,165,82,106,110,192,219,50,171,213,42,24,251,108,143,142,142,32,165,116,140,75,10,83,110,255,210,59,10,87,12,74,125,78,47,101,151,13,53,55,145,91,247,88,47,229,112,172,
239,128,83,202,57,144,67,79,183,212,246,43,1,62,76,41,7,232,153,211,73,69,199,23,9,32,185,55,115,14,44,129,46,125,151,217,89,255,81,178,107,204,201,210,178,44,201,65,201,21,3,230,182,14,55,47,55,119,49,
212,41,67,75,204,185,187,25,0,180,214,0,126,178,90,107,13,33,4,123,223,166,238,96,206,169,37,167,129,125,34,75,0,152,166,9,82,202,228,100,174,146,56,36,156,92,21,66,140,37,240,247,114,150,82,178,6,114,
44,99,112,110,156,5,30,134,97,118,221,229,234,167,92,162,165,230,210,188,105,154,246,192,125,223,7,140,15,77,38,46,121,72,164,148,174,249,223,119,187,221,30,88,41,133,162,40,102,225,230,234,169,28,99,
255,157,15,72,249,67,36,131,80,251,222,229,64,99,7,184,111,62,219,152,204,48,12,60,227,28,56,215,143,199,82,202,192,22,53,18,165,20,128,159,125,76,131,162,40,130,178,197,90,235,246,119,110,203,196,192,
41,80,107,173,11,181,171,64,140,49,110,34,57,64,147,151,14,19,234,47,177,53,198,56,146,238,172,166,189,76,138,169,100,75,29,36,244,7,65,186,212,124,25,199,209,245,221,191,197,118,187,69,93,215,176,214,
58,5,50,154,187,175,169,148,245,1,57,182,192,126,73,3,224,205,102,131,166,105,102,225,20,66,176,197,160,191,85,252,37,74,177,5,128,143,143,143,57,112,215,117,46,100,49,48,37,24,231,148,15,238,131,198,
201,104,173,197,102,179,153,3,107,173,209,182,45,234,186,158,25,151,82,186,112,199,140,57,224,56,196,0,240,249,249,233,78,173,0,248,244,244,212,110,183,91,49,12,3,154,166,65,85,85,48,198,64,107,237,50,
158,43,230,41,1,253,132,36,33,253,182,109,209,247,61,154,166,177,93,215,9,7,44,165,196,203,203,139,139,205,227,227,35,132,16,56,62,62,70,93,215,88,175,215,174,152,167,48,250,235,79,57,160,181,134,82,10,
239,239,239,104,219,54,200,98,242,149,222,9,0,191,255,245,255,7,242,7,36,191,171,214,20,255,162,238,0,0,0,0,73,69,78,68,174,66,96,130,0,0};

const char* GrooveboxKeyboard::whiteKeyOff_png = (const char*) resource_GrooveboxKeyboard_whiteKeyOff_png;
const int GrooveboxKeyboard::whiteKeyOff_pngSize = 946;

// JUCER_RESOURCE: whiteKeyOn_png, 1046, "../../../../../Desktop/whiteKeyOn.png"
static const unsigned char resource_GrooveboxKeyboard_whiteKeyOn_png[] = { 137,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,0,30,0,0,0,35,8,6,0,0,0,131,212,186,209,0,0,0,4,115,66,73,84,8,8,8,8,124,8,
100,136,0,0,0,9,112,72,89,115,0,0,10,229,0,0,10,229,1,38,2,65,164,0,0,0,25,116,69,88,116,83,111,102,116,119,97,114,101,0,119,119,119,46,105,110,107,115,99,97,112,101,46,111,114,103,155,238,60,26,0,0,3,
147,73,68,65,84,88,133,189,151,207,110,43,53,20,198,127,246,204,164,55,183,77,105,74,255,129,16,98,129,42,241,6,44,121,0,222,2,245,21,88,176,103,207,130,74,188,1,139,74,188,5,44,217,87,93,92,209,85,155,
70,85,210,38,105,198,241,31,22,115,237,122,38,158,73,42,33,142,100,101,38,62,62,223,249,62,31,123,108,113,121,121,233,206,207,207,113,206,173,181,183,154,16,2,33,68,237,57,254,207,219,205,205,13,249,104,
52,226,226,226,2,165,20,90,235,208,60,112,156,64,252,28,7,139,193,178,44,35,203,50,138,162,32,207,243,208,226,24,87,87,87,136,179,179,51,119,123,123,203,114,185,12,160,214,218,26,235,46,246,49,168,255,
205,243,188,6,92,20,69,232,183,214,114,120,120,72,126,127,127,31,128,172,181,225,57,88,57,71,106,5,203,25,66,45,16,171,18,97,86,96,77,21,76,102,144,21,184,94,31,118,222,195,206,46,118,240,105,45,150,181,
150,44,203,66,200,229,114,73,238,153,121,199,88,18,231,28,82,43,196,98,138,25,125,224,195,31,191,129,86,8,103,193,125,244,21,18,164,196,101,5,95,125,255,3,189,47,191,193,238,14,67,188,38,17,231,28,74,
41,130,248,177,83,141,177,94,33,116,201,95,191,252,200,183,189,9,61,153,150,220,56,248,243,215,159,248,238,231,223,67,188,182,66,117,206,85,192,109,157,0,14,112,66,112,244,217,23,252,253,207,156,157,22,
96,13,28,156,156,84,236,27,42,250,36,132,16,33,174,0,220,98,177,96,54,155,173,101,233,156,67,44,166,213,220,190,60,225,38,35,132,154,135,57,6,170,57,206,123,240,110,23,177,127,2,239,63,193,14,63,71,8,
65,81,20,161,245,122,61,164,148,104,173,171,194,139,25,167,152,219,254,62,238,221,0,246,79,113,39,95,215,250,90,215,109,164,90,91,92,153,146,186,83,250,132,111,155,117,249,181,204,88,58,129,77,201,117,
197,104,238,9,121,252,178,77,2,161,56,26,219,96,211,127,83,114,50,118,220,54,251,77,62,219,244,191,9,248,191,176,26,240,91,172,75,226,55,3,111,195,184,185,116,182,241,75,249,214,128,227,61,122,219,64,
155,152,167,214,120,140,21,170,58,222,206,226,192,109,223,224,84,82,155,146,6,48,166,218,241,36,128,214,26,41,101,171,115,234,36,209,37,103,106,92,147,177,4,88,173,86,72,41,147,1,186,88,54,193,83,239,
77,96,173,245,43,176,82,170,246,161,78,1,180,5,234,82,39,229,175,148,122,5,94,46,151,53,198,219,22,83,170,120,188,73,41,67,139,251,203,178,92,103,220,148,59,117,158,234,98,28,255,23,3,250,250,241,36,3,
112,89,150,181,236,186,64,155,9,164,250,98,182,77,50,53,96,165,84,210,177,139,85,74,98,15,234,213,139,155,55,63,199,121,252,146,101,89,237,216,18,175,239,174,37,211,4,110,3,141,25,231,80,173,45,99,76,
112,244,9,0,53,208,77,7,250,77,108,141,49,245,170,118,206,133,181,236,7,182,21,91,219,70,226,111,16,126,172,111,177,173,86,171,240,28,210,153,207,231,201,129,113,117,182,181,60,207,215,198,116,201,28,
164,6,120,124,124,228,244,244,116,77,78,33,68,242,140,28,47,149,120,138,218,216,2,76,38,147,117,224,249,124,30,36,75,73,219,60,125,196,125,41,224,212,231,48,9,108,140,97,60,30,115,124,124,188,22,92,74,
25,54,247,38,227,20,112,83,98,207,246,229,229,101,29,120,48,24,80,150,37,119,119,119,28,29,29,145,231,57,206,57,140,49,88,107,145,31,111,8,177,197,59,84,92,144,222,172,181,104,173,153,76,38,148,101,201,
222,222,30,179,217,236,21,248,249,249,153,162,40,24,143,199,0,92,95,95,35,132,160,223,239,51,28,14,57,56,56,8,87,205,120,78,157,115,225,46,109,140,9,23,178,135,135,7,166,211,105,173,138,189,61,61,61,85,
73,83,93,143,254,119,251,23,189,102,164,217,105,246,38,45,0,0,0,0,73,69,78,68,174,66,96,130,0,0};

const char* GrooveboxKeyboard::whiteKeyOn_png = (const char*) resource_GrooveboxKeyboard_whiteKeyOn_png;
const int GrooveboxKeyboard::whiteKeyOn_pngSize = 1046;

// JUCER_RESOURCE: blackKeyOff_png, 1026, "../../../../../Desktop/blackKeyOff.png"
static const unsigned char resource_GrooveboxKeyboard_blackKeyOff_png[] = { 137,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,0,30,0,0,0,35,8,6,0,0,0,131,212,186,209,0,0,0,4,115,66,73,84,8,8,8,8,124,8,
100,136,0,0,0,9,112,72,89,115,0,0,10,235,0,0,10,235,1,130,139,13,90,0,0,0,25,116,69,88,116,83,111,102,116,119,97,114,101,0,119,119,119,46,105,110,107,115,99,97,112,101,46,111,114,103,155,238,60,26,0,0,
3,127,73,68,65,84,88,133,181,151,75,78,235,48,20,134,127,63,98,39,21,85,85,70,136,13,192,156,97,55,199,86,96,7,12,153,178,9,38,237,128,17,66,168,2,74,218,58,137,31,119,112,101,215,113,30,109,117,117,45,
29,41,73,93,127,254,207,203,9,121,124,124,116,247,247,247,160,148,98,108,16,66,90,215,167,222,19,66,64,41,5,231,28,140,49,80,74,241,253,253,13,190,92,46,81,85,21,140,49,112,206,193,57,215,250,51,165,116,
208,252,66,125,215,177,73,41,49,159,207,49,159,207,193,24,195,211,211,19,232,195,195,3,174,174,174,96,173,237,152,115,174,115,223,103,0,122,175,189,53,77,131,166,105,160,181,198,118,187,197,251,251,59,
184,82,10,156,243,0,137,21,3,0,165,244,40,108,236,153,55,173,53,154,166,129,49,6,214,90,240,170,170,64,8,233,76,76,129,214,90,212,117,221,114,191,223,152,127,54,157,78,33,132,232,205,17,173,53,180,214,
193,123,188,174,235,86,98,121,72,156,40,206,57,212,117,141,219,219,91,48,198,122,23,182,214,98,181,90,225,250,250,122,80,177,49,38,204,231,85,85,117,22,73,93,231,199,219,219,27,56,231,173,185,62,36,206,
185,16,178,62,151,91,107,97,140,9,34,185,191,241,89,236,221,22,151,7,0,72,41,195,2,67,25,157,110,42,30,62,182,33,119,226,157,167,37,52,84,159,113,141,166,207,82,47,197,35,78,94,238,23,72,227,28,47,156,
94,199,46,142,71,10,236,115,183,31,1,28,171,77,193,41,164,15,122,202,136,225,29,197,113,98,197,191,157,178,137,83,54,228,231,112,15,139,213,166,224,49,59,7,234,89,29,197,105,23,58,166,250,152,23,198,18,
47,40,62,6,30,83,155,206,235,27,233,111,161,240,40,165,161,206,78,5,143,109,164,239,89,156,184,189,49,142,225,67,53,123,110,236,125,111,208,90,31,192,190,27,245,181,202,33,112,26,243,177,13,16,66,194,
217,92,215,245,1,108,140,1,99,172,213,89,210,204,62,166,186,47,166,241,127,60,184,165,88,107,29,78,157,115,192,231,168,230,156,131,82,26,78,40,14,0,74,41,48,198,6,79,165,62,248,208,193,210,103,254,0,33,
132,160,105,154,54,248,226,226,162,149,117,199,192,231,168,206,178,12,89,150,129,82,218,142,177,115,14,121,158,99,183,219,5,213,199,234,116,72,117,122,178,17,66,32,132,8,224,221,110,119,0,3,64,81,20,80,
74,245,54,144,127,81,205,57,135,16,2,66,8,16,66,160,148,58,128,253,132,190,94,61,164,250,20,56,165,20,82,202,0,142,67,24,20,159,3,78,55,16,191,240,197,150,101,25,164,148,1,94,85,213,225,213,39,86,236,
23,26,43,169,49,87,199,170,41,165,200,243,60,128,165,148,248,253,253,237,158,199,206,185,179,75,106,76,117,81,20,200,243,60,192,9,33,161,121,180,92,189,223,239,7,203,41,205,242,99,224,60,207,81,20,69,
128,75,41,1,0,219,237,182,11,94,175,215,152,205,102,157,111,168,83,98,28,195,61,48,54,0,216,237,118,248,250,250,234,130,141,49,152,78,167,216,108,54,131,174,30,3,51,198,90,74,39,147,9,138,162,8,201,84,
85,21,214,235,117,23,236,156,195,229,229,37,24,99,248,249,249,57,43,179,227,4,242,240,201,100,18,222,179,55,155,13,148,82,221,183,76,0,88,44,22,110,185,92,18,66,8,102,179,25,128,191,173,212,127,91,165,
96,198,24,56,231,200,178,12,66,136,22,220,90,139,178,44,81,215,53,154,166,193,231,231,39,140,49,88,44,22,238,229,229,133,4,240,205,205,13,158,159,159,59,61,50,203,178,240,93,43,132,104,181,67,224,240,
193,230,156,131,82,10,101,89,98,191,223,227,227,227,3,101,89,182,190,149,0,96,181,90,145,187,187,59,188,190,190,130,0,24,246,233,127,28,127,0,202,1,178,228,237,64,235,7,0,0,0,0,73,69,78,68,174,66,96,130,
0,0};

const char* GrooveboxKeyboard::blackKeyOff_png = (const char*) resource_GrooveboxKeyboard_blackKeyOff_png;
const int GrooveboxKeyboard::blackKeyOff_pngSize = 1026;

// JUCER_RESOURCE: blackKeyOn_png, 1040, "../../../../../Desktop/blackKeyOn.png"
static const unsigned char resource_GrooveboxKeyboard_blackKeyOn_png[] = { 137,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,0,30,0,0,0,35,8,6,0,0,0,131,212,186,209,0,0,0,4,115,66,73,84,8,8,8,8,124,8,
100,136,0,0,0,9,112,72,89,115,0,0,10,254,0,0,10,254,1,230,37,120,102,0,0,0,25,116,69,88,116,83,111,102,116,119,97,114,101,0,119,119,119,46,105,110,107,115,99,97,112,101,46,111,114,103,155,238,60,26,0,
0,3,141,73,68,65,84,88,133,181,151,219,110,227,54,16,134,127,14,79,146,176,46,234,54,190,41,176,79,147,203,190,84,94,37,185,234,117,176,143,209,62,65,3,228,166,64,224,32,64,28,175,19,91,18,15,189,240,
146,75,81,148,108,99,177,3,16,161,14,230,55,255,204,112,196,176,187,187,59,127,115,115,3,34,194,156,49,198,6,243,115,175,25,99,32,34,8,33,192,57,7,17,97,179,217,64,60,60,60,160,109,91,88,107,225,189,135,
247,126,240,99,34,154,28,97,161,210,60,29,90,107,44,151,75,44,151,75,16,17,238,239,239,33,110,111,111,209,52,13,222,222,222,70,96,34,130,115,110,160,36,188,147,14,0,197,121,24,125,223,163,239,123,24,99,
240,250,250,138,167,167,39,136,195,225,128,170,170,224,189,135,115,110,0,6,128,79,146,161,22,192,66,122,124,146,14,141,32,40,2,36,63,170,243,140,224,24,71,11,142,142,9,180,240,216,122,57,130,27,99,162,
3,206,57,136,182,109,139,74,136,8,222,123,40,6,252,194,29,62,107,143,235,223,123,104,98,32,6,80,200,41,99,176,30,176,32,252,211,253,138,255,12,176,245,114,84,35,198,24,24,99,96,173,61,130,187,174,139,
42,67,152,210,240,10,16,52,1,127,174,122,92,255,214,67,77,212,160,245,128,124,53,248,226,254,128,183,227,116,4,168,181,246,184,110,219,182,163,69,210,124,57,239,97,61,112,112,192,223,95,57,52,27,189,126,
4,131,193,130,195,78,228,217,57,23,11,24,0,132,181,54,86,112,90,201,33,199,157,3,118,134,225,175,39,133,149,2,22,138,65,115,6,201,143,239,120,70,48,32,28,192,241,230,20,222,125,57,36,33,196,33,154,34,
60,40,129,25,99,216,90,194,174,37,172,123,194,191,251,242,22,202,255,18,249,34,60,45,94,17,160,105,3,201,247,114,62,15,215,165,20,229,215,121,184,7,224,116,225,80,205,121,20,82,43,65,207,177,180,118,34,
56,40,78,31,6,72,26,250,57,39,206,113,104,20,234,84,109,14,158,27,151,64,71,224,160,56,111,131,167,84,159,138,66,233,249,197,224,57,181,249,123,37,203,159,13,170,218,57,23,219,231,57,224,57,71,74,247,
210,194,21,65,126,154,227,20,94,10,219,37,78,132,121,216,251,179,161,14,206,204,129,243,156,207,57,192,24,139,223,230,216,171,129,99,71,225,156,15,54,120,94,217,167,84,151,114,154,254,38,128,71,161,22,
66,12,128,231,128,47,81,45,132,0,17,149,21,151,66,61,5,207,161,115,78,132,51,23,99,108,8,182,214,142,146,127,10,124,137,106,41,37,164,148,99,197,97,129,180,192,78,237,211,41,213,97,164,247,149,82,17,220,
247,253,119,48,128,65,113,229,106,127,68,181,16,2,74,41,40,165,6,167,155,73,197,83,54,151,199,210,61,173,117,4,167,199,172,193,103,241,92,112,238,64,128,230,231,110,41,37,180,214,17,190,219,237,226,87,
80,228,139,164,93,171,180,165,230,66,157,170,38,34,84,85,21,193,90,107,236,118,187,113,168,67,158,47,217,82,115,170,235,186,70,85,85,17,206,24,67,122,176,140,161,54,198,64,74,89,132,230,85,126,10,92,85,
21,234,186,142,112,173,53,0,96,191,223,143,193,93,215,65,41,117,50,207,167,84,7,96,58,0,224,227,227,163,12,14,159,196,185,38,50,7,230,156,15,148,54,77,131,186,174,99,49,109,54,155,50,56,244,235,180,125,
78,89,14,79,11,40,192,155,166,137,253,255,229,229,5,235,245,58,251,15,229,155,173,86,171,152,167,208,214,242,70,159,130,57,231,16,66,64,74,9,165,212,0,238,156,195,243,243,51,222,223,223,209,182,109,44,
170,171,171,43,172,215,235,239,96,33,4,30,31,31,71,202,164,148,49,116,225,176,158,166,195,57,135,174,235,226,54,113,206,193,24,131,237,118,139,253,126,31,5,164,182,88,44,142,206,3,152,142,233,79,180,255,
1,98,10,141,20,209,215,174,191,0,0,0,0,73,69,78,68,174,66,96,130,0,0};

const char* GrooveboxKeyboard::blackKeyOn_png = (const char*) resource_GrooveboxKeyboard_blackKeyOn_png;
const int GrooveboxKeyboard::blackKeyOn_pngSize = 1040;


//[EndFile] You can add extra defines here...
//[/EndFile]
