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

#include "Envelope.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
Envelope::EnvVis::EnvVis(Envelope* envPtr)
	: m_envPointer(envPtr),
	  m_highlightedMarker(none),
	  m_draggedMarker(none)
{
	setSize(256, 64);
}

Envelope::EnvVis::~EnvVis()
{
}
void Envelope::EnvVis::paint(Graphics& g)
{
	// background
	g.setColour(Colour(0xfff2f99b));
	g.fillAll();

	g.setColour(Colour(0xffc4c86d));
	//zeroHorizonzal
	g.strokePath(m_zeroHorizonzal, PathStrokeType(1));
	//zeroHorizonzal
	g.strokePath(m_keyOffVertical, PathStrokeType(1));

	g.setColour(Colour(0xff707070));
	// envelope curve
	g.strokePath(m_envelopePath, PathStrokeType(1));

	// circles for time/level markers
	Path::Iterator it(m_envelopePath);
	int count = 0;
	while (it.next())
	{
		if (it.elementType == it.lineTo)
		{
			count++;
			if (count == 1 || count == 2 || count == 3 || count == 5)
			{
				if ((int)m_highlightedMarker == count)
					g.setColour(Colour(0xffc4c86d));
				else g.setColour(Colour(0xfff2f99b));
				g.fillEllipse(it.x1 - 3.0f, it.y1 - 3.0f, 6.0f, 6.0f);
				g.setColour(Colour(0xff707070));
				g.drawEllipse(it.x1 - 3.0f, it.y1 - 3.0f, 6.0f, 6.0f, 1.0f);
			}
		}
	}

	// border
	g.setColour(Colours::silver);
	g.drawRect(-1.0f, -1.0f, (float)getWidth() + 2.0f, (float)getHeight() + 2.0f);
}

void Envelope::EnvVis::resized()
{
	refreshEnvVisShapes();
}

float Envelope::EnvVis::getMarkerX(MarkerNum m)
{
	int envWidth(getWidth());
	float timeMaxWidth = (float)((56.0 / 256.0) * envWidth);
	float sustainWidth = (float)((32.0 / 256.0) * envWidth);
	switch (m)
	{
	case MarkerNum::m1:
		return
			(float)m_envPointer->m_time1->getValue() * timeMaxWidth / 127.0f;
		break;
	case MarkerNum::m2:
		return
			(float)m_envPointer->m_time1->getValue() * timeMaxWidth / 127.0f +
			(float)m_envPointer->m_time2->getValue() * timeMaxWidth / 127.0f;
		break;
	case MarkerNum::m3:
		return
			(float)m_envPointer->m_time1->getValue() * timeMaxWidth / 127.0f +
			(float)m_envPointer->m_time2->getValue() * timeMaxWidth / 127.0f +
			(float)m_envPointer->m_time3->getValue() * timeMaxWidth / 127.0f;
		break;
	case MarkerNum::sustainKeyOff:
		return
			(float)m_envPointer->m_time1->getValue() * timeMaxWidth / 127.0f +
			(float)m_envPointer->m_time2->getValue() * timeMaxWidth / 127.0f +
			(float)m_envPointer->m_time3->getValue() * timeMaxWidth / 127.0f +
			(float)sustainWidth;
		break;
	case MarkerNum::m4:
		return
			(float)m_envPointer->m_time1->getValue() * timeMaxWidth / 127.0f +
			(float)m_envPointer->m_time2->getValue() * timeMaxWidth / 127.0f +
			(float)m_envPointer->m_time3->getValue() * timeMaxWidth / 127.0f +
			(float)sustainWidth +
			(float)m_envPointer->m_time4->getValue() * timeMaxWidth / 127.0f;
		break;
	default:
		return 0.0f;
		break;
	}
}

float Envelope::EnvVis::getMarkerY(MarkerNum m)
{
	float height((float)getHeight());
	switch (m)
	{
	case MarkerNum::m1:
		return height - (((float)m_envPointer->m_level1->getValue() - m_envPointer->m_minLevel) / (m_envPointer->m_maxLevel - m_envPointer->m_minLevel) * height);
		break;
	case MarkerNum::m2:
		return height - (((float)m_envPointer->m_level2->getValue() - m_envPointer->m_minLevel) / (m_envPointer->m_maxLevel - m_envPointer->m_minLevel) * height);
		break;
	case MarkerNum::m3:
		return height - (((float)m_envPointer->m_level3->getValue() - m_envPointer->m_minLevel) / (m_envPointer->m_maxLevel - m_envPointer->m_minLevel) * height);
		break;
	case MarkerNum::sustainKeyOff:
		return height - (((float)m_envPointer->m_level3->getValue() - m_envPointer->m_minLevel) / (m_envPointer->m_maxLevel - m_envPointer->m_minLevel) * height);
		break;
	case MarkerNum::m4:
		return height - (((m_envPointer->m_level4Always0 ? 0 : (float)m_envPointer->m_level4->getValue()) - m_envPointer->m_minLevel) / (m_envPointer->m_maxLevel - m_envPointer->m_minLevel) * height);
		break;
	default:
		return 0.0f;
		break;
	}
}
void Envelope::EnvVis::refreshEnvVisShapes()
{
	PathStrokeType dashedStroke(1.0);
	float dashes[2]{ 3.0f, 3.0f };

	m_keyOffVertical.clear();
	m_keyOffVertical.startNewSubPath(getMarkerX(sustainKeyOff), 0.0f);
	m_keyOffVertical.lineTo(getMarkerX(sustainKeyOff), (float)getHeight());
	dashedStroke.createDashedStroke(m_keyOffVertical, m_keyOffVertical, dashes, 2);

	m_zeroHorizonzal.clear();
	if (m_envPointer->m_minLevel != 0.0f)
	{
		float zero((float)getHeight() - ((0.0f - m_envPointer->m_minLevel) / (m_envPointer->m_maxLevel - m_envPointer->m_minLevel) * (float)getHeight()));
		m_zeroHorizonzal.startNewSubPath(0, zero);
		m_zeroHorizonzal.lineTo((float)getWidth(), zero);
		dashedStroke.createDashedStroke(m_zeroHorizonzal, m_zeroHorizonzal, dashes, 2);
	}

	m_envelopePath.clear();
	m_envelopePath.startNewSubPath(0, (float)getHeight());
	m_envelopePath.lineTo(getMarkerX(m1), getMarkerY(m1));
	m_envelopePath.lineTo(getMarkerX(m2), getMarkerY(m2));
	m_envelopePath.lineTo(getMarkerX(m3), getMarkerY(m3));
	m_envelopePath.lineTo(getMarkerX(sustainKeyOff), getMarkerY(sustainKeyOff));
	m_envelopePath.lineTo(getMarkerX(m4), getMarkerY(m4));
	m_envelopePath.lineTo((float)getWidth(), getMarkerY(m4));
}

float Envelope::EnvVis::pixelToTime(float x)
{
	return x * (256.0f * 127.0f) / (56.0f * (float)getWidth());
}
float Envelope::EnvVis::pixelToLevel(float y)
{
	return (((float)getHeight() - y)*(m_envPointer->m_maxLevel - m_envPointer->m_minLevel) / (float)getHeight()) + m_envPointer->m_minLevel;
}

Envelope::EnvVis::MarkerNum Envelope::EnvVis::getNearMarker(float x, float y, float radius)
{
	float m4x = getMarkerX(m4);
	float m4y = getMarkerY(m4);
	if (fabs(m4x - x) <= radius && fabs(m4y - y) <= radius) return m4;

	float m3x = getMarkerX(m3);
	float m3y = getMarkerY(m3);
	if (fabs(m3x - x) <= radius && fabs(m3y - y) <= radius) return m3;

	float m2x = getMarkerX(m2);
	float m2y = getMarkerY(m2);
	if (fabs(m2x - x) <= radius && fabs(m2y - y) <= radius) return m2;

	float m1x = getMarkerX(m1);
	float m1y = getMarkerY(m1);
	if (fabs(m1x - x) <= radius && fabs(m1y - y) <= radius) return m1;

	return none;
}

void Envelope::EnvVis::mouseMove(const MouseEvent& e)
{
	MarkerNum near(getNearMarker((float)e.x, (float)e.y, 4.0f));
	switch (near)
	{
	case Envelope::EnvVis::none:
		if (m_highlightedMarker != none)
		{
			m_highlightedMarker = none;
			repaint();
		}
		else m_highlightedMarker = none;
		break;
	case Envelope::EnvVis::m1:
		if (m_highlightedMarker != m1)
		{
			m_highlightedMarker = m1;
			repaint();
		}
		return;
	case Envelope::EnvVis::m2:
		if (m_highlightedMarker != m2)
		{
			m_highlightedMarker = m2;
			repaint();
		}
		break;
	case Envelope::EnvVis::m3:
		if (m_highlightedMarker != m3)
		{
			m_highlightedMarker = m3;
			repaint();
		}
		break;
	case Envelope::EnvVis::sustainKeyOff:
		if (m_highlightedMarker != none)
		{
			m_highlightedMarker = none;
			repaint();
		}
		else m_highlightedMarker = none;
		break;
	case Envelope::EnvVis::m4:
		if (m_highlightedMarker != m4)
		{
			m_highlightedMarker = m4;
			repaint();
		}
		break;
	default:
		if (m_highlightedMarker != none)
		{
			m_highlightedMarker = none;
			repaint();
		}
		break;
	}
}

void Envelope::EnvVis::mouseDrag(const MouseEvent& e)
{
	if (m_draggedMarker == none)
	{
		m_draggedMarker = m_highlightedMarker;

		switch (m_draggedMarker)
		{
		case Envelope::EnvVis::none:
			break;
		case Envelope::EnvVis::m1:
			m_dragStartMarkerTime = (int)m_envPointer->m_time1->getValue();
			m_dragStartMarkerLevel = (int)m_envPointer->m_level1->getValue();
			break;
		case Envelope::EnvVis::m2:
			m_dragStartMarkerTime = (int)m_envPointer->m_time2->getValue();
			m_dragStartMarkerLevel = (int)m_envPointer->m_level2->getValue();
			break;
		case Envelope::EnvVis::m3:
			m_dragStartMarkerTime = (int)m_envPointer->m_time3->getValue();
			m_dragStartMarkerLevel = (int)m_envPointer->m_level3->getValue();
			break;
		case Envelope::EnvVis::sustainKeyOff:
			break;
		case Envelope::EnvVis::m4:
			m_dragStartMarkerTime = (int)m_envPointer->m_time4->getValue();
			m_dragStartMarkerLevel = (int)m_envPointer->m_level4->getValue();
			break;
		default:
			break;
		}
	}
	float distx ((float)e.getDistanceFromDragStartX()*127/127);
	float disty (-(float)e.getDistanceFromDragStartY()*127/127);
	switch (m_draggedMarker)
	{
	case Envelope::EnvVis::none:
		break;
	case Envelope::EnvVis::m1:
		if (e.mods.isCommandDown() || !e.mods.isShiftDown()) m_envPointer->m_time1->setValue(m_dragStartMarkerTime + distx, sendNotification);
		if (!e.mods.isCommandDown() || e.mods.isShiftDown()) m_envPointer->m_level1->setValue(m_dragStartMarkerLevel + disty, sendNotification);
		break;
	case Envelope::EnvVis::m2:
		if (e.mods.isCommandDown() || !e.mods.isShiftDown()) m_envPointer->m_time2->setValue(m_dragStartMarkerTime + distx, sendNotification);
		if (!e.mods.isCommandDown() || e.mods.isShiftDown()) m_envPointer->m_level2->setValue(m_dragStartMarkerLevel + disty, sendNotification);
		break;
	case Envelope::EnvVis::m3:
		if (e.mods.isCommandDown() || !e.mods.isShiftDown()) m_envPointer->m_time3->setValue(m_dragStartMarkerTime + distx, sendNotification);
		if (!e.mods.isCommandDown() || e.mods.isShiftDown()) m_envPointer->m_level3->setValue(m_dragStartMarkerLevel + disty, sendNotification);
		break;
	case Envelope::EnvVis::sustainKeyOff:
		break;
	case Envelope::EnvVis::m4:
		if (e.mods.isCommandDown() || !e.mods.isShiftDown()) m_envPointer->m_time4->setValue(m_dragStartMarkerTime + distx, sendNotification);
		if (!e.mods.isCommandDown() || e.mods.isShiftDown()) m_envPointer->m_level4->setValue(m_dragStartMarkerLevel + disty, sendNotification);
		break;
	default:
		break;
	}
}

void Envelope::EnvVis::mouseWheelMove(const MouseEvent &e, const MouseWheelDetails &wheel)
{
	if (m_draggedMarker == none && m_highlightedMarker!=none)
	{
		switch (m_highlightedMarker)
		{
		case Envelope::EnvVis::none:
			break;
		case Envelope::EnvVis::m1:
			m_dragStartMarkerTime = (int)m_envPointer->m_time1->getValue();
			m_dragStartMarkerLevel = (int)m_envPointer->m_level1->getValue();
			break;
		case Envelope::EnvVis::m2:
			m_dragStartMarkerTime = (int)m_envPointer->m_time2->getValue();
			m_dragStartMarkerLevel = (int)m_envPointer->m_level2->getValue();
			break;
		case Envelope::EnvVis::m3:
			m_dragStartMarkerTime = (int)m_envPointer->m_time3->getValue();
			m_dragStartMarkerLevel = (int)m_envPointer->m_level3->getValue();
			break;
		case Envelope::EnvVis::sustainKeyOff:
			break;
		case Envelope::EnvVis::m4:
			m_dragStartMarkerTime = (int)m_envPointer->m_time4->getValue();
			m_dragStartMarkerLevel = (int)m_envPointer->m_level4->getValue();
			break;
		default:
			break;
		}
	}
	float dist(wheel.deltaY*5.0f*(wheel.isReversed ? 1 : -1));
	switch (m_highlightedMarker)
	{
	case Envelope::EnvVis::none:
		break;
	case Envelope::EnvVis::m1:
		if (e.mods.isCommandDown()) m_envPointer->m_time1->setValue(m_dragStartMarkerTime + dist, sendNotification);
		else m_envPointer->m_level1->setValue(m_dragStartMarkerLevel - dist, sendNotification);
		Desktop::setMousePosition(getScreenPosition() + Point<int>((int)getMarkerX(m_highlightedMarker), (int)getMarkerY(m_highlightedMarker)));
		break;
	case Envelope::EnvVis::m2:
		if (e.mods.isCommandDown()) m_envPointer->m_time2->setValue(m_dragStartMarkerTime + dist, sendNotification);
		else m_envPointer->m_level2->setValue(m_dragStartMarkerLevel - dist, sendNotification);
		Desktop::setMousePosition(getScreenPosition() + Point<int>((int)getMarkerX(m_highlightedMarker), (int)getMarkerY(m_highlightedMarker)));
		break;
	case Envelope::EnvVis::m3:
		if (e.mods.isCommandDown()) m_envPointer->m_time3->setValue(m_dragStartMarkerTime + dist, sendNotification);
		else m_envPointer->m_level3->setValue(m_dragStartMarkerLevel - dist, sendNotification);
		Desktop::setMousePosition(getScreenPosition() + Point<int>((int)getMarkerX(m_highlightedMarker), (int)getMarkerY(m_highlightedMarker)));
		break;
	case Envelope::EnvVis::sustainKeyOff:
		break;
	case Envelope::EnvVis::m4:
		if (e.mods.isCommandDown()) m_envPointer->m_time4->setValue(m_dragStartMarkerTime + dist, sendNotification);
		else m_envPointer->m_level4->setValue(m_dragStartMarkerLevel - dist, sendNotification);
		Desktop::setMousePosition(getScreenPosition() + Point<int>((int)getMarkerX(m_highlightedMarker), (int)getMarkerY(m_highlightedMarker)));
		break;
	default:
		break;
	}
}

void Envelope::EnvVis::mouseUp(const MouseEvent& e)
{
	m_draggedMarker = none;
	mouseMove(e);	// refreshes highlight
}
//[/MiscUserDefs]

//==============================================================================
Envelope::Envelope (const String name, const float minLevel, const float maxLevel, const bool lev4Is0)
    : m_name(name),
      m_minLevel(minLevel),
      m_maxLevel(maxLevel),
      m_level4Always0(lev4Is0)
{
    addAndMakeVisible (m_envelopeGroup2 = new PanelGroupGrey ("envGrp", m_name));
    addAndMakeVisible (m_level3Label = new Label ("level3Label",
                                                  "S"));
    m_level3Label->setFont (Font (13.00f, Font::plain));
    m_level3Label->setJustificationType (Justification::centred);
    m_level3Label->setEditable (false, false, false);
    m_level3Label->setColour (TextEditor::textColourId, Colours::black);
    m_level3Label->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_time1 = new MicroParameterSlider ("time1"));
    m_time1->setRange (0, 127, 1);
    m_time1->setSliderStyle (Slider::LinearBar);
    m_time1->setTextBoxStyle (Slider::TextBoxLeft, false, 64, 20);
    m_time1->setColour (Slider::backgroundColourId, Colour (0xfff2f59b));
    m_time1->setColour (Slider::thumbColourId, Colour (0xffc4c86d));
    m_time1->addListener (this);

    addAndMakeVisible (m_time1Label = new Label ("time1Label",
                                                 "A"));
    m_time1Label->setFont (Font (13.00f, Font::plain));
    m_time1Label->setJustificationType (Justification::centred);
    m_time1Label->setEditable (false, false, false);
    m_time1Label->setColour (TextEditor::textColourId, Colours::black);
    m_time1Label->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_level1 = new MicroParameterSlider ("level1"));
    m_level1->setRange (0, 127, 1);
    m_level1->setSliderStyle (Slider::LinearBar);
    m_level1->setTextBoxStyle (Slider::TextBoxLeft, false, 64, 20);
    m_level1->setColour (Slider::backgroundColourId, Colour (0xfff2f59b));
    m_level1->setColour (Slider::thumbColourId, Colour (0xffc4c86d));
    m_level1->addListener (this);

    addAndMakeVisible (m_time2 = new MicroParameterSlider ("time2"));
    m_time2->setRange (0, 127, 1);
    m_time2->setSliderStyle (Slider::LinearBar);
    m_time2->setTextBoxStyle (Slider::TextBoxLeft, false, 64, 20);
    m_time2->setColour (Slider::backgroundColourId, Colour (0xfff2f59b));
    m_time2->setColour (Slider::thumbColourId, Colour (0xffc4c86d));
    m_time2->addListener (this);

    addAndMakeVisible (m_level2 = new MicroParameterSlider ("level2"));
    m_level2->setRange (0, 127, 1);
    m_level2->setSliderStyle (Slider::LinearBar);
    m_level2->setTextBoxStyle (Slider::TextBoxLeft, false, 64, 20);
    m_level2->setColour (Slider::backgroundColourId, Colour (0xfff2f59b));
    m_level2->setColour (Slider::thumbColourId, Colour (0xffc4c86d));
    m_level2->addListener (this);

    addAndMakeVisible (m_time3 = new MicroParameterSlider ("time3"));
    m_time3->setRange (0, 127, 1);
    m_time3->setSliderStyle (Slider::LinearBar);
    m_time3->setTextBoxStyle (Slider::TextBoxLeft, false, 64, 20);
    m_time3->setColour (Slider::backgroundColourId, Colour (0xfff2f59b));
    m_time3->setColour (Slider::thumbColourId, Colour (0xffc4c86d));
    m_time3->addListener (this);

    addAndMakeVisible (m_time3Label = new Label ("time3Label",
                                                 "D"));
    m_time3Label->setFont (Font (13.00f, Font::plain));
    m_time3Label->setJustificationType (Justification::centred);
    m_time3Label->setEditable (false, false, false);
    m_time3Label->setColour (TextEditor::textColourId, Colours::black);
    m_time3Label->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_level3 = new MicroParameterSlider ("level3"));
    m_level3->setRange (0, 127, 1);
    m_level3->setSliderStyle (Slider::LinearBar);
    m_level3->setTextBoxStyle (Slider::TextBoxLeft, false, 64, 20);
    m_level3->setColour (Slider::backgroundColourId, Colour (0xfff2f59b));
    m_level3->setColour (Slider::thumbColourId, Colour (0xffc4c86d));
    m_level3->addListener (this);

    addAndMakeVisible (m_time4 = new MicroParameterSlider ("time4"));
    m_time4->setRange (0, 127, 1);
    m_time4->setSliderStyle (Slider::LinearBar);
    m_time4->setTextBoxStyle (Slider::TextBoxLeft, false, 64, 20);
    m_time4->setColour (Slider::backgroundColourId, Colour (0xfff2f59b));
    m_time4->setColour (Slider::thumbColourId, Colour (0xffc4c86d));
    m_time4->addListener (this);

    addAndMakeVisible (m_time4Label = new Label ("time4Label",
                                                 "R"));
    m_time4Label->setFont (Font (13.00f, Font::plain));
    m_time4Label->setJustificationType (Justification::centred);
    m_time4Label->setEditable (false, false, false);
    m_time4Label->setColour (TextEditor::textColourId, Colours::black);
    m_time4Label->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_level4 = new MicroParameterSlider ("level4"));
    m_level4->setRange (0, 127, 1);
    m_level4->setSliderStyle (Slider::LinearBar);
    m_level4->setTextBoxStyle (Slider::TextBoxLeft, false, 64, 20);
    m_level4->setColour (Slider::backgroundColourId, Colour (0xfff2f59b));
    m_level4->setColour (Slider::thumbColourId, Colour (0xffc4c86d));
    m_level4->addListener (this);

    addAndMakeVisible (m_timeLabel = new Label ("timeLabel",
                                                "Time:"));
    m_timeLabel->setFont (Font (13.00f, Font::plain));
    m_timeLabel->setJustificationType (Justification::centredRight);
    m_timeLabel->setEditable (false, false, false);
    m_timeLabel->setColour (TextEditor::textColourId, Colours::black);
    m_timeLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_levelLabel = new Label ("levelLabel",
                                                 "Level:"));
    m_levelLabel->setFont (Font (13.00f, Font::plain));
    m_levelLabel->setJustificationType (Justification::centredRight);
    m_levelLabel->setEditable (false, false, false);
    m_levelLabel->setColour (TextEditor::textColourId, Colours::black);
    m_levelLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_envVisComponent = new EnvVis (this));
    m_envVisComponent->setName ("envVisComponent");


    //[UserPreSize]
	m_envelopeGroup2->setTextLabelPosition(Justification::left);
	m_level1->setRange(m_minLevel, m_maxLevel, 1.0);
	m_level2->setRange(m_minLevel, m_maxLevel, 1.0);
	m_level3->setRange(m_minLevel, m_maxLevel, 1.0);
	m_level4->setRange(m_minLevel, m_maxLevel, 1.0);
	if (m_level4Always0)
	{
		m_level4->setRange(0, 0, 0.0);
		m_level4->setVisible(false);
	}
    //[/UserPreSize]

    setSize (288, 152);


    //[Constructor] You can add your own custom stuff here..
    //[/Constructor]
}

Envelope::~Envelope()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    m_envelopeGroup2 = nullptr;
    m_level3Label = nullptr;
    m_time1 = nullptr;
    m_time1Label = nullptr;
    m_level1 = nullptr;
    m_time2 = nullptr;
    m_level2 = nullptr;
    m_time3 = nullptr;
    m_time3Label = nullptr;
    m_level3 = nullptr;
    m_time4 = nullptr;
    m_time4Label = nullptr;
    m_level4 = nullptr;
    m_timeLabel = nullptr;
    m_levelLabel = nullptr;
    m_envVisComponent = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void Envelope::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
	#if JUCE_MSVC
	g;
	#endif
    //[/UserPrePaint]

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void Envelope::resized()
{
    m_envelopeGroup2->setBounds (0, 0, getWidth() - 0, getHeight() - 0);
    m_level3Label->setBounds (170, getHeight() - 20 - 16, 48, 16);
    m_time1->setBounds (46, getHeight() - 34 - 16, 56, 16);
    m_time1Label->setBounds (50, getHeight() - 48 - 16, 48, 16);
    m_level1->setBounds (46, getHeight() - 6 - 16, 56, 16);
    m_time2->setBounds (106, getHeight() - 34 - 16, 56, 16);
    m_level2->setBounds (106, getHeight() - 6 - 16, 56, 16);
    m_time3->setBounds (166, getHeight() - 34 - 16, 56, 16);
    m_time3Label->setBounds (170, getHeight() - 48 - 16, 48, 16);
    m_level3->setBounds (166, getHeight() - 6 - 16, 56, 16);
    m_time4->setBounds (226, getHeight() - 34 - 16, 56, 16);
    m_time4Label->setBounds (230, getHeight() - 48 - 16, 48, 16);
    m_level4->setBounds (226, getHeight() - 6 - 16, 56, 16);
    m_timeLabel->setBounds (0, getHeight() - 34 - 16, 44, 16);
    m_levelLabel->setBounds (0, getHeight() - 6 - 16, 44, 16);
    m_envVisComponent->setBounds (4, 18, 280, 72);
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void Envelope::sliderValueChanged (Slider* sliderThatWasMoved)
{
    //[UsersliderValueChanged_Pre]
    //[/UsersliderValueChanged_Pre]

    if (sliderThatWasMoved == m_time1)
    {
        //[UserSliderCode_m_time1] -- add your slider handling code here..
        //[/UserSliderCode_m_time1]
    }
    else if (sliderThatWasMoved == m_level1)
    {
        //[UserSliderCode_m_level1] -- add your slider handling code here..
        //[/UserSliderCode_m_level1]
    }
    else if (sliderThatWasMoved == m_time2)
    {
        //[UserSliderCode_m_time2] -- add your slider handling code here..
        //[/UserSliderCode_m_time2]
    }
    else if (sliderThatWasMoved == m_level2)
    {
        //[UserSliderCode_m_level2] -- add your slider handling code here..
        //[/UserSliderCode_m_level2]
    }
    else if (sliderThatWasMoved == m_time3)
    {
        //[UserSliderCode_m_time3] -- add your slider handling code here..
        //[/UserSliderCode_m_time3]
    }
    else if (sliderThatWasMoved == m_level3)
    {
        //[UserSliderCode_m_level3] -- add your slider handling code here..
        //[/UserSliderCode_m_level3]
    }
    else if (sliderThatWasMoved == m_time4)
    {
        //[UserSliderCode_m_time4] -- add your slider handling code here..
        //[/UserSliderCode_m_time4]
    }
    else if (sliderThatWasMoved == m_level4)
    {
        //[UserSliderCode_m_level4] -- add your slider handling code here..
        //[/UserSliderCode_m_level4]
    }

    //[UsersliderValueChanged_Post]
	m_envVisComponent->refreshEnvVisShapes();
	m_envVisComponent->repaint();
    //[/UsersliderValueChanged_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...

//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Introjucer information section --

    This is where the Introjucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="Envelope" componentName=""
                 parentClasses="public Component" constructorParams="const String name, const float minLevel, const float maxLevel, const bool lev4Is0"
                 variableInitialisers="m_name(name),&#10;m_minLevel(minLevel),&#10;m_maxLevel(maxLevel),&#10;m_level4Always0(lev4Is0)"
                 snapPixels="2" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="1" initialWidth="288" initialHeight="152">
  <BACKGROUND backgroundColour="ffffff"/>
  <JUCERCOMP name="envelopeGroup" id="52e00682f746b888" memberName="m_envelopeGroup2"
             virtualName="PanelGroupGrey" explicitFocusOrder="0" pos="0 0 0M 0M"
             sourceFile="PanelGroupGrey.cpp" constructorParams="&quot;envGrp&quot;, m_name"/>
  <LABEL name="level3Label" id="3bad768bd7aaf71e" memberName="m_level3Label"
         virtualName="" explicitFocusOrder="0" pos="170 20Rr 48 16" edTextCol="ff000000"
         edBkgCol="0" labelText="S" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="13"
         bold="0" italic="0" justification="36"/>
  <SLIDER name="time1" id="2b89b2c11e2ad524" memberName="m_time1" virtualName="MicroParameterSlider"
          explicitFocusOrder="0" pos="46 34Rr 56 16" bkgcol="fff2f59b"
          thumbcol="ffc4c86d" min="0" max="127" int="1" style="LinearBar"
          textBoxPos="TextBoxLeft" textBoxEditable="1" textBoxWidth="64"
          textBoxHeight="20" skewFactor="1"/>
  <LABEL name="time1Label" id="18f640a804ccc217" memberName="m_time1Label"
         virtualName="" explicitFocusOrder="0" pos="50 48Rr 48 16" edTextCol="ff000000"
         edBkgCol="0" labelText="A" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="13"
         bold="0" italic="0" justification="36"/>
  <SLIDER name="level1" id="3dafcb7ace1815c1" memberName="m_level1" virtualName="MicroParameterSlider"
          explicitFocusOrder="0" pos="46 6Rr 56 16" bkgcol="fff2f59b" thumbcol="ffc4c86d"
          min="0" max="127" int="1" style="LinearBar" textBoxPos="TextBoxLeft"
          textBoxEditable="1" textBoxWidth="64" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="time2" id="1cc14093ff75920c" memberName="m_time2" virtualName="MicroParameterSlider"
          explicitFocusOrder="0" pos="106 34Rr 56 16" bkgcol="fff2f59b"
          thumbcol="ffc4c86d" min="0" max="127" int="1" style="LinearBar"
          textBoxPos="TextBoxLeft" textBoxEditable="1" textBoxWidth="64"
          textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="level2" id="dd578938f7654389" memberName="m_level2" virtualName="MicroParameterSlider"
          explicitFocusOrder="0" pos="106 6Rr 56 16" bkgcol="fff2f59b"
          thumbcol="ffc4c86d" min="0" max="127" int="1" style="LinearBar"
          textBoxPos="TextBoxLeft" textBoxEditable="1" textBoxWidth="64"
          textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="time3" id="2678b83fffabda5f" memberName="m_time3" virtualName="MicroParameterSlider"
          explicitFocusOrder="0" pos="166 34Rr 56 16" bkgcol="fff2f59b"
          thumbcol="ffc4c86d" min="0" max="127" int="1" style="LinearBar"
          textBoxPos="TextBoxLeft" textBoxEditable="1" textBoxWidth="64"
          textBoxHeight="20" skewFactor="1"/>
  <LABEL name="time3Label" id="eda22862a10f1fab" memberName="m_time3Label"
         virtualName="" explicitFocusOrder="0" pos="170 48Rr 48 16" edTextCol="ff000000"
         edBkgCol="0" labelText="D" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="13"
         bold="0" italic="0" justification="36"/>
  <SLIDER name="level3" id="cdaf309610cf03e9" memberName="m_level3" virtualName="MicroParameterSlider"
          explicitFocusOrder="0" pos="166 6Rr 56 16" bkgcol="fff2f59b"
          thumbcol="ffc4c86d" min="0" max="127" int="1" style="LinearBar"
          textBoxPos="TextBoxLeft" textBoxEditable="1" textBoxWidth="64"
          textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="time4" id="5110947541e3217e" memberName="m_time4" virtualName="MicroParameterSlider"
          explicitFocusOrder="0" pos="226 34Rr 56 16" bkgcol="fff2f59b"
          thumbcol="ffc4c86d" min="0" max="127" int="1" style="LinearBar"
          textBoxPos="TextBoxLeft" textBoxEditable="1" textBoxWidth="64"
          textBoxHeight="20" skewFactor="1"/>
  <LABEL name="time4Label" id="ee6a791ad2fe125" memberName="m_time4Label"
         virtualName="" explicitFocusOrder="0" pos="230 48Rr 48 16" edTextCol="ff000000"
         edBkgCol="0" labelText="R" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="13"
         bold="0" italic="0" justification="36"/>
  <SLIDER name="level4" id="84174e1eb072d650" memberName="m_level4" virtualName="MicroParameterSlider"
          explicitFocusOrder="0" pos="226 6Rr 56 16" bkgcol="fff2f59b"
          thumbcol="ffc4c86d" min="0" max="127" int="1" style="LinearBar"
          textBoxPos="TextBoxLeft" textBoxEditable="1" textBoxWidth="64"
          textBoxHeight="20" skewFactor="1"/>
  <LABEL name="timeLabel" id="2b5a8ff5555917df" memberName="m_timeLabel"
         virtualName="" explicitFocusOrder="0" pos="0 34Rr 44 16" edTextCol="ff000000"
         edBkgCol="0" labelText="Time:" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="13"
         bold="0" italic="0" justification="34"/>
  <LABEL name="levelLabel" id="1f0cf42ee7f140e4" memberName="m_levelLabel"
         virtualName="" explicitFocusOrder="0" pos="0 6Rr 44 16" edTextCol="ff000000"
         edBkgCol="0" labelText="Level:" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="13"
         bold="0" italic="0" justification="34"/>
  <GENERICCOMPONENT name="envVisComponent" id="3dcfd7ac420d53cd" memberName="m_envVisComponent"
                    virtualName="" explicitFocusOrder="0" pos="4 18 280 72" class="EnvVis"
                    params="this"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
