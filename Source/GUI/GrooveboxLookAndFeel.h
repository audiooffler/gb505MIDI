/*
  ==============================================================================

    GrooveboxLookAndFeel.h
    Created: 9 Jan 2014 11:24:38pm
    Author:  Martin

  ==============================================================================
*/

#ifndef GROOVEBOXLOOKANDFEEL_H_INCLUDED
#define GROOVEBOXLOOKANDFEEL_H_INCLUDED

#include "JuceHeader.h"
#include "ParameterWidgets/MixPartLevelFader.h"
#include "ParameterWidgets/ParameterSlider.h"
#include "ParameterWidgets/BigOrangeToggle.h"
#include "ParameterWidgets/BigGreenToggle.h"
#include "GroupWidgets/PanelGroupGrey.h"
#include "GroupWidgets/PanelGroupTransp.h"
#include "GroupWidgets/PanelGroupDark.h"
#include "ParameterWidgets/ParameterLedSwitch.h"
#include "AsciiWithNoteValuesTypeface.h"

class GrooveboxLookAndFeel : public LookAndFeel_V3
{
public:
	static const Colour Mc307LcdBackground, Mc307LcdThumb;


	GrooveboxLookAndFeel()
		: LookAndFeel_V3()
	{
		m_knobFilmStripImage = new Image(ImageCache::getFromMemory(BinaryData::RotaryKnob48_png, BinaryData::RotaryKnob48_pngSize));
		m_knobFilmStripSmall = new Image(ImageCache::getFromMemory(BinaryData::RotaryKnob32_png, BinaryData::RotaryKnob32_pngSize));
		m_faderThumbImage = new Image(ImageCache::getFromMemory(BinaryData::mixSliderThumb_png, BinaryData::mixSliderThumb_pngSize));
		m_asciiWithNoteValuesTypeface = new AsciiWithNoteValuesTypeface();
		m_asciiWithNoteValuesFont = Font(m_asciiWithNoteValuesTypeface);
	}

	void drawRotarySlider(Graphics &g, int , int , int width, int height, float sliderPosProportional, float , float , Slider &)
	{
		uint8 frameIndex((uint8)(sliderPosProportional * 127));
		int outputSize(jmin(width, height));
		
		Image* img = (outputSize<33)?m_knobFilmStripSmall:m_knobFilmStripImage;
		int frameSize(img->getHeight());

		// center
		int posX((width - outputSize > 0) ? (width - outputSize) / 2 : 0);
		int posY(((height - outputSize) > 0) ? (height - outputSize) / 2 : 0);
		g.setOpacity(1.0f);
		g.drawImage(*img, posX, posY, outputSize, outputSize, frameIndex * frameSize, 0, frameSize, frameSize);
	}

	void drawGroupComponentOutline(Graphics& g, int width, int height, const String& text, const Justification& position, GroupComponent& group)
	{
		if (dynamic_cast<PanelGroupGrey*>(&group)!= nullptr ||
			dynamic_cast<PanelGroupTransp*>(&group) != nullptr ||
			dynamic_cast<PanelGroupDark*>(&group) != nullptr)
		{
			// text
			g.setColour(Colours::white);
			g.setFont(Font(12.00f, Font::bold));
			g.drawText(group.getText(), 8, 3, width - 16, 12, group.getTextLabelPosition(), true);
		}
		else LookAndFeel_V3::drawGroupComponentOutline(g, width, height, text, position, group);
	}

	Typeface* getAsciiWithNoteValuesTypeface() { return m_asciiWithNoteValuesTypeface; }

	Label* createSliderTextBox(Slider& slider)
	{
		Label* l = LookAndFeel_V3::createSliderTextBox(slider);
		if (l != nullptr) l->setFont(m_asciiWithNoteValuesFont);
		return l;
	}
	
	void drawToggleButton(Graphics& g, ToggleButton& button, bool isMouseOverButton, bool isButtonDown)
	{
		if (button.hasKeyboardFocus(true))
		{
			//g.setColour(button.findColour(TextEditor::focusedOutlineColourId));
			//g.drawRect(0, 0, button.getWidth(), button.getHeight());
		}

		float fontSize = jmin(15.0f, button.getHeight() * 0.75f);
		const float tickWidth = fontSize * 1.1f;

		drawTickBox(g, button, 4.0f, (button.getHeight() - tickWidth) * 0.5f,
			tickWidth, tickWidth,
			button.getToggleState(),
			button.isEnabled(),
			isMouseOverButton,
			isButtonDown);

		g.setColour(button.findColour(ToggleButton::textColourId));
		g.setFont(fontSize);

		if (!button.isEnabled())
			g.setOpacity(0.5f);

		const int textX = (int)tickWidth + 5;

		if (button.getButtonText().isNotEmpty() && button.getWidth() - textX - 2 > 0)
		{
			g.drawFittedText(button.getButtonText(),
				textX, 0,
				button.getWidth() - textX - 2, button.getHeight(),
				Justification::centredLeft, 10);
		}
	}


	void drawTickBox(Graphics &g,
		Component &c,
		float 	x,
		float 	y,
		float 	w,
		float 	h,
		bool 	ticked,
		bool 	isEnabled,
		bool 	isMouseOverButton,
		bool 	isButtonDown
		)
    {
        if (ParameterLedSwitch* ledSwitch = dynamic_cast<ParameterLedSwitch*>(c.getParentComponent()))
	{
		g.setColour(Colours::black);
		if (ticked)
		{
			Image cachedImage_ledOn_png = ImageCache::getFromMemory(BinaryData::ledOn_png, BinaryData::ledOn_pngSize);
			g.drawImage(cachedImage_ledOn_png,
				0, 0, 16, 16,
				0, 0, cachedImage_ledOn_png.getWidth(), cachedImage_ledOn_png.getHeight());
		}
		else
		{
			Image cachedImage_ledOff_png = ImageCache::getFromMemory(BinaryData::ledOff_png, BinaryData::ledOff_pngSize);
			g.drawImage(cachedImage_ledOff_png,
				0, 0, 16, 16,
				0, 0, cachedImage_ledOff_png.getWidth(), cachedImage_ledOff_png.getHeight());
		}
		if (isMouseOverButton)
		{
			g.setColour(Colours::white.withAlpha(0.5f));
			g.drawEllipse(3, 3, 10, 10, 1.5f);
		}
		return;
	}
	// else:
	LookAndFeel_V3::drawTickBox(g,c,x,y,w,h,ticked,isEnabled, isMouseOverButton, isButtonDown);
    }

	static TextLayout layoutTooltipText(const String& text, Colour colour) noexcept
	{
		const float tooltipFontSize = 13.0f;
		const int maxToolTipWidth = 400;

		AttributedString s;
		s.setJustification(Justification::left);
		s.append(text, Font(tooltipFontSize, Font::bold), colour);

		TextLayout tl;
		tl.createLayoutWithBalancedLineLengths(s, (float)maxToolTipWidth);
		return tl;
	}

	void drawTooltip(Graphics &g, const String &text, int width, int height)
	{
		g.fillAll(findColour(TooltipWindow::backgroundColourId));

		#if ! JUCE_MAC // The mac windows already have a non-optional 1 pix outline, so don't double it here..
		g.setColour(findColour(TooltipWindow::outlineColourId));
		g.drawRect(0, 0, width, height, 1);
		#endif

		layoutTooltipText(text, findColour(TooltipWindow::textColourId))
			.draw(g, Rectangle<float>(7.0f, 3.0f, (float)width, (float)height));
	}

	Rectangle<int> getTooltipBounds(const String& tipText, Point<int> screenPos, Rectangle<int> parentArea) override
	{
		const TextLayout tl(layoutTooltipText(tipText, Colours::black));

		int width = (int)(tl.getWidth() + 14.0f);
		int height = (int)(tl.getHeight() + 6.0f);
		return Rectangle<int>(screenPos.x, screenPos.y + 2, width, height);
	}

	//void getTooltipSize(const String& tipText, int& width, int& height)
	//{
	//	const TextLayout tl(layoutTooltipText(tipText, Colours::black));

	//	width = (int)(tl.getWidth() + 14.0f);
	//	height = (int)(tl.getHeight() + 6.0f);
	//}
	//
	private:
		ScopedPointer<Image> m_knobFilmStripImage;
		ScopedPointer<Image> m_knobFilmStripSmall;
		ScopedPointer<Image> m_faderThumbImage;
		AsciiWithNoteValuesTypeface* m_asciiWithNoteValuesTypeface = nullptr;	// // referece counted, don't delete manually
		Font m_asciiWithNoteValuesFont;
};



#endif  // GROOVEBOXLOOKANDFEEL_H_INCLUDED
