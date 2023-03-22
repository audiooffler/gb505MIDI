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

#include "KeyfollowBubbleComponent.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
KeyfollowBubbleComponent::KeyfollowBubbleComponent (ParameterSlider* s)
    : BubbleComponent(), m_owner(s)
{

    //[UserPreSize]
	m_svgXmlElement = nullptr;
	m_valueToSvgCoords = AffineTransform();
	m_SvgCoordsToComponentCoords = AffineTransform();
	m_preRenderedDiagram = Image();
	loadSvg();
	setColour(backgroundColourId, GrooveboxLookAndFeel::Mc307LcdBackground);
    //[/UserPreSize]

    setSize (64, 64);


    //[Constructor] You can add your own custom stuff here..
	m_owner->addListener(this);
    setAlwaysOnTop (true);
	//setAllowedPlacement(BubblePlacement::right);
	setLookAndFeel(&(m_owner->getLookAndFeel()));
    //[/Constructor]
}

KeyfollowBubbleComponent::~KeyfollowBubbleComponent()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
	m_owner->removeListener(this);
    //[/Destructor_pre]



    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void KeyfollowBubbleComponent::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    //[UserPaint] Add your own custom painting code here..
    BubbleComponent::paint(g);
    //[/UserPaint]
}

void KeyfollowBubbleComponent::resized()
{
    //[UserResized] Add your own custom resize handling here..
    BubbleComponent::resized();
    //[/UserResized]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...

void KeyfollowBubbleComponent::loadSvg()
{
	m_svgXmlElement = XmlDocument::parse(String::createStringFromData(BinaryData::KeyFollow_svg, BinaryData::KeyFollow_svgSize));
	// analyze svg:
	Array<int> groupsToDelete;
	for (int i = 0; i < m_svgXmlElement->getNumChildElements(); i++)
	{
		XmlElement* g = m_svgXmlElement->getChildElement(i);
		if (g != nullptr && g->getTagName() == "g")
		{
			if (g->hasAttribute("id"))
			{
				String id = g->getStringAttribute("id");
				// load affine transform from refrence points
				if (id == "referenceCoordinates")
				{
					XmlElement* center = nullptr;
					XmlElement* minus3minus3 = nullptr;
					XmlElement* plus3plus3 = nullptr;
					for (int i = 0; i < g->getNumChildElements(); i++)
					{
						if (g->getChildElement(i)->getTagName() == "path" && g->getChildElement(i)->getStringAttribute("id") == "center") center = g->getChildElement(i);
						if (g->getChildElement(i)->getTagName() == "path" && g->getChildElement(i)->getStringAttribute("id") == "minus3minus3") minus3minus3 = g->getChildElement(i);
						if (g->getChildElement(i)->getTagName() == "path" && g->getChildElement(i)->getStringAttribute("id") == "plus3plus3") plus3plus3 = g->getChildElement(i);
					}
					if (minus3minus3 != nullptr && center != nullptr && plus3plus3 != nullptr)
					{
						String d = minus3minus3->getStringAttribute("d");
						String reducedD = d.substring(d.indexOfAnyOf("mM") + 1).trim();
						//float x_minus3 = reducedD.substring(0, reducedD.indexOf(",")).getFloatValue();
						//float y_minus3 = reducedD.substring(reducedD.indexOf(",") + 1, reducedD.indexOf(" ")).getFloatValue();
						d = center->getStringAttribute("d");
						reducedD = d.substring(d.indexOfAnyOf("mM") + 1).trim();
						float x_center = reducedD.substring(0, reducedD.indexOf(",")).getFloatValue();
						float y_center = reducedD.substring(reducedD.indexOf(",") + 1, reducedD.indexOf(" ")).getFloatValue();
						d = plus3plus3->getStringAttribute("d");
						reducedD = d.substring(d.indexOfAnyOf("mM") + 1).trim();
						float x_plus3 = reducedD.substring(0, reducedD.indexOf(",")).getFloatValue();
						float y_plus3 = reducedD.substring(reducedD.indexOf(",") + 1, reducedD.indexOf(" ")).getFloatValue();
						AffineTransform trans = AffineTransform::fromTargetPoints(0.0f, 0.0f, x_center, y_center,
							0.0f, 3.0f, x_center, y_plus3,
							3.0f, 3.0f, x_plus3, y_plus3);
						m_valueToSvgCoords = trans;
					}
				}
				// if parameter is not PITCH: KEY FOLLOW or FILTER : CUTOFF KF than delete yAxisLabels layer
				if (id == "yAxisLabels")
				{
					Parameter* param = m_owner->getParamPtr();
					if (param != nullptr)
					{
						uint16 offset = param->getAddressOffset();
						if (!(offset == 0x40 || offset == 0x52))
						{
							groupsToDelete.add(i);
						}
					}
				}
			}
			// delete hidden layers;
			if (g->hasAttribute("style"))
			{
				String style = g->getStringAttribute("style");
				if (style.contains("display:none"))
				{
					groupsToDelete.add(i);
				}
			}
		}
	}
	IntArraySorter sorter;
	groupsToDelete.sort(sorter);
	for (int i = groupsToDelete.size() - 1; i > 0; i--) m_svgXmlElement->removeChildElement(m_svgXmlElement->getChildElement(groupsToDelete[i]), true);

	int width(0), height(0);
	getContentSize(width, height);

	std::unique_ptr<Drawable> drawableDiagram = Drawable::createFromSVG(*m_svgXmlElement);
	Rectangle<float> destArea(Rectangle<float>(4.0f, 4.0f, (float)width - 8.0f, (float)height - 8.0f));
	m_SvgCoordsToComponentCoords = RectanglePlacement(RectanglePlacement::fillDestination).getTransformToFit(drawableDiagram->getDrawableBounds(), destArea);
	m_preRenderedDiagram = Image(Image::ARGB, width - 4, height - 4, true);
	Graphics g(m_preRenderedDiagram);
	drawableDiagram->draw(g, 1.0f, m_SvgCoordsToComponentCoords);
}

void KeyfollowBubbleComponent::getContentSize (int &width, int &height)
{
    /*
    w = font.getStringWidth (text) + 18;
    h = (int) (font.getHeight() * 1.6f);
    */
	width = 240+8;
	height = 198+8;
}

void KeyfollowBubbleComponent::paintContent (Graphics &g, int /*width*/, int /*height*/)
{
	g.setColour(Colours::black);
	if (Parameter* param = m_owner->getParamPtr())
	{
		float value = (float) param->getDisplayedValue().getIntValue();
		// calc value line
		float m = value / 100.0f;
		float y_min(-3.0f), y_max(3.0f), x_min(-3.0f), x_max(3.0f);
		if (m == 0.0f)
		{
			y_min = 0.0f; y_max = 0.0f;
			x_max = -3.0f; x_max = 3.0f;
		}
		else if (fabs(m) >= 1.0f)
		{
			y_min = -3.0f; y_max = 3.0f;
			x_min = y_min / m;
			x_max = y_max / m;
		}
		else if (fabs(m) < 1.0f)
		{
			x_min = -3.0f; x_max = 3.0f;
			y_min = m * x_min;
			y_max = m * x_max;
		}
		Line<float> line = Line<float>(x_min, y_min, x_max, y_max);
		line.applyTransform(m_valueToSvgCoords);
		line.applyTransform(m_SvgCoordsToComponentCoords);
		/*
		// update
		if (m_svgXmlElement->getChildElement(m_svgXmlElement->getNumChildElements() - 1)->getStringAttribute("id") == "valueLinePath")
		{
			m_svgXmlElement->getChildElement(m_svgXmlElement->getNumChildElements() - 1)->setAttribute("d", "M " + String(line.getStartX()) + "," + String(line.getStartY()) + " " + String(line.getEndX()) + "," + String(line.getEndY()));
		}
		else // new
		{
			XmlElement* valueLinePath = new XmlElement("path");
			valueLinePath->setAttribute("id", "valueLinePath");
			valueLinePath->setAttribute("style", "fill:none;stroke:#000000;stroke-width:0.5;stroke-linecap:butt;stroke-opacity:1");
			valueLinePath->setAttribute("d", "M " + String(line.getStartX()) + "," + String(line.getStartY()) + " " + String(line.getEndX()) + "," + String(line.getEndY()));
			m_svgXmlElement->insertChildElement(valueLinePath, -1);
		}
		//ScopedPointer<XmlElement> copy = new XmlElement(*svgXmlElement);
		ScopedPointer<Drawable> drawableDiagram = Drawable::createFromSVG(*m_svgXmlElement);
		Rectangle<float> destArea(Rectangle<float>(4.0f, 4.0f, (float)width - 8.0f, (float)height - 8.0f));
		m_SvgCoordsToComponentCoords = RectanglePlacement(RectanglePlacement::fillDestination).getTransformToFit(drawableDiagram->getDrawableBounds(), destArea);
		drawableDiagram->draw(g, 1.0f, m_SvgCoordsToComponentCoords);
		*/
		g.drawImageAt(m_preRenderedDiagram, 0, 0);
		g.setColour(Colours::black);
		g.drawLine(line, 1.5f);
	}
	// TODO: speed up rendering by precalculating the image, just adding a line before outputting
}

void KeyfollowBubbleComponent::sliderValueChanged(Slider* /*slider*/)
{
	repaint();
}
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Introjucer information section --

    This is where the Introjucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="KeyfollowBubbleComponent"
                 componentName="" parentClasses="public BubbleComponent, public Slider::Listener"
                 constructorParams="ParameterSlider* s" variableInitialisers="BubbleComponent(), m_owner(s)"
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="0" initialWidth="64" initialHeight="64">
  <BACKGROUND backgroundColour="0"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
