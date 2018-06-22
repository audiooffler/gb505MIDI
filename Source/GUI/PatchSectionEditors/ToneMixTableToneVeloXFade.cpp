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
#include "ToneMixTableTone.h"
#include "ToneMixTableCanvas.h"
#include "ToneLimitsConstrainer.h"
#include "../../GrooveboxMemory/OverallMemoryBlock.h"
//[/Headers]

#include "ToneMixTableToneVeloXFade.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
extern OverallMemoryBlock* grooveboxMemory;
//[/MiscUserDefs]

//==============================================================================
ToneMixTableToneVeloXFade::ToneMixTableToneVeloXFade (const String &componentName, Component* componentToWatch, ToneLimitsConstrainer* toneLimitsConstrainer, SynthParts part, Tone tone)
    : Component(componentName), ComponentMovementWatcher(componentToWatch),
      m_toneLimitsConstrainer(toneLimitsConstrainer),
      m_part(part),
      m_tone(tone)
{

    //[UserPreSize]
	m_velocityXFadePrm = nullptr;
	setInterceptsMouseClicks(false, true);
	componentToWatch->addMouseListener(this,true);
	setAlpha(0.5f);
    //[/UserPreSize]

    setSize (600, 400);


    //[Constructor] You can add your own custom stuff here..
	if (grooveboxMemory != nullptr)
	{
		SynthPatchesBlock* synthPatches = grooveboxMemory->getSynthPatchesBlock();
		if (synthPatches != nullptr)
		{
			PatchPartBlock* patchPart = synthPatches->getPatchPartBlockPtr(m_part);
			if (patchPart != nullptr)
			{
				PatchToneBlock* tone = nullptr;
				switch (m_tone)
				{
				case Tone1:
					if (PatchToneBlock* tone1 = patchPart->getPatchToneBlockPtr(Tone1)) tone = tone1;
					break;
				case Tone2:
					if (PatchToneBlock* tone2 = patchPart->getPatchToneBlockPtr(Tone2)) tone = tone2;
					break;
				case Tone3:
					if (PatchToneBlock* tone3 = patchPart->getPatchToneBlockPtr(Tone3)) tone = tone3;
					break;
				case Tone4:
					if (PatchToneBlock* tone4 = patchPart->getPatchToneBlockPtr(Tone4)) tone = tone4;
					break;
				}
				if (tone != nullptr)
				{
					m_velocityXFadePrm = tone->getParameter(0x0B);
					m_toneLevelPrm = tone->getParameter(0x65);
					m_biasDirectionPrm = tone->getParameter(0x66);
					m_biasPointPrm = tone->getParameter(0x67);
					m_biasLevelPrm = tone->getParameter(0x68);
					m_velocityXFadePrm->addChangeListener(this);
					m_toneLevelPrm->addChangeListener(this);
					m_biasDirectionPrm->addChangeListener(this);
					m_biasPointPrm->addChangeListener(this);
					m_biasLevelPrm->addChangeListener(this);
				}
			}
		}
	}
    //[/Constructor]
}

ToneMixTableToneVeloXFade::~ToneMixTableToneVeloXFade()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
	m_velocityXFadePrm->removeChangeListener(this);
	m_toneLevelPrm->removeChangeListener(this);
	m_biasDirectionPrm->removeChangeListener(this);
	m_biasPointPrm->removeChangeListener(this);
	m_biasLevelPrm->removeChangeListener(this);
    //[/Destructor_pre]



    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void ToneMixTableToneVeloXFade::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
	if (ToneMixTableTone* toneWidget = dynamic_cast<ToneMixTableTone*>(getComponent()))
	{
		Rectangle<float> toneBounds(getComponent()->getBoundsInParent().toFloat());
		int keyLower, keyUpper, velLower, velUpper;
		m_toneLimitsConstrainer->getValuesFromBoundingBox(getComponent()->getBoundsInParent(), keyLower, keyUpper, velLower, velUpper);
		int upperVeloCrossfadeLimit = velUpper + m_velocityXFadePrm->getValue() + 1;
		int lowerVeloCrossfadeLimit = velLower - m_velocityXFadePrm->getValue(); 
		float y_upperVel = Point<float>((float)keyLower, (float)upperVeloCrossfadeLimit).transformedBy(m_toneLimitsConstrainer->getAffineTransformValuesToPixelcoords()).getY();
		float y_lowerVel = Point<float>((float)keyUpper, (float)lowerVeloCrossfadeLimit).transformedBy(m_toneLimitsConstrainer->getAffineTransformValuesToPixelcoords()).getY();
		float crossfadeHeight = y_lowerVel - y_upperVel;
		// paint gradient filling for upper velocity crossfade from transparent at crossfade range to opaque at velocity range upper 
		g.setGradientFill(ColourGradient(Colour(0x00c4c86d), toneBounds.getX(), y_upperVel,
										 Colour(0xffc4c86d), toneBounds.getX(), toneBounds.getY(),
										 false));
		g.fillRect(toneBounds.getX(), y_upperVel, toneBounds.getWidth(), toneBounds.getY()-y_upperVel);
		// paint filling for velocity range
		g.setFillType(Colour(0xffc4c86d));
		g.fillRect(toneBounds);
		// paint gradient filling for lower velocity crossfade
		g.setGradientFill(ColourGradient(Colour(0xffc4c86d), toneBounds.getX(), toneBounds.getBottom(),
										 Colour(0x00c4c86d), toneBounds.getX(), y_lowerVel,
									     false));
		g.fillRect(toneBounds.getX(), toneBounds.getBottom(), toneBounds.getWidth(), y_lowerVel - toneBounds.getBottom());
		// paint amp bias curves
		// draw bias point
		float biasSlope;
		switch (m_biasLevelPrm->getValue())
		{
			case  0: biasSlope = -100.0f; break;
			case  1: biasSlope = -70.0f; break;
			case  2: biasSlope = -50.0f; break;
			case  3: biasSlope = -40.0f; break;
			case  4: biasSlope = -30.0f; break;
			case  5: biasSlope = -20.0f; break;
			case  6: biasSlope = -10.0f; break;
			case  7: biasSlope =  0.0f; break;
			case  8: biasSlope = 10.0f; break;
			case  9: biasSlope = 20.0f; break;
			case 10: biasSlope = 30.0f; break;
			case 11: biasSlope = 40.0f; break;
			case 12: biasSlope = 50.0f; break;
			case 13: biasSlope = 70.0f; break;
			case 14: biasSlope = 100.0f; break;
			default: biasSlope = -100.0f; break;
		}
		
		ColourGradient gradient;
		if (m_velocityXFadePrm->getValue() == 0)
		{
			gradient = ColourGradient(Colours::black, 0.0f, 0.0f, Colours::black, 0.0f, (float)getHeight(), false);
		}
		else
		{
			gradient = ColourGradient(Colours::transparentBlack, 0.0f, y_upperVel, Colours::transparentBlack, 0.0f, y_lowerVel, false);
			gradient.addColour(jmax<float>(0.0f, (toneBounds.getY() - y_upperVel) / crossfadeHeight), Colours::black);
			gradient.addColour(jmin<float>(1.0f, (toneBounds.getBottom() - y_upperVel) / crossfadeHeight), Colours::black);
		}
		g.saveState();
		if (toneBounds.getX() > 0)
		{
			// dont draw left to tone bounds
			Rectangle<int> left = Rectangle<int>(0, 0, (int)toneBounds.getX(), getHeight());
			g.excludeClipRegion(left);
		}
		if (toneBounds.getRight() < getWidth())
		{
			// dont draw right to tone bounds
			Rectangle<int> right = Rectangle<int>((int)toneBounds.getRight(), 0, getWidth() - (int)toneBounds.getRight(), getHeight());
			g.excludeClipRegion(right);
		}
		if (m_velocityXFadePrm->getValue() == 0)
		{
			// dont draw above or below if no crossfade
			Rectangle<int> above = Rectangle<int>(0, 0, getWidth(), (int)toneBounds.getY());
			g.excludeClipRegion(above);
			Rectangle<int> below = Rectangle<int>(0, (int)toneBounds.getBottom(), getWidth(), getHeight() - (int)toneBounds.getBottom());
			g.excludeClipRegion(below);
		}
		g.setGradientFill(gradient);

		// bias point pos:
		int biasKey = m_biasPointPrm->getValue();
		int toneVel = m_toneLevelPrm->getValue();
		float leftBiasSlope(0.0f), rightBiasSlope(0.0f);
		float biasN(0.0f), biasNRight(0.0f);
		Point<float> from, to;
		AffineTransform halfstep = AffineTransform::translation(m_toneLimitsConstrainer->getKeyWidth()*0.5f, -m_toneLimitsConstrainer->getVelocityStepHeight()*0.5f);
		AffineTransform valuesToCoords = AffineTransform::translation(0.5f, 0.5f).followedBy(m_toneLimitsConstrainer->getAffineTransformValuesToPixelcoords());
		if (biasSlope == 0.0f)		// horizontal line
		{
			g.drawLine(
					toneBounds.getX(),
					Point<float>((float)keyLower, (float)toneVel).transformedBy(valuesToCoords).getY(),
					toneBounds.getRight(),
					Point<float>((float)keyUpper, (float)toneVel).transformedBy(valuesToCoords).getY()
			);
		}
		else switch (m_biasDirectionPrm->getValue())	//  0 - 3: LOWER, UPPER, LOW&UP, ALL
		{
		case 0:	// LOWER
			// slope is biasSlope (vel_diff) over one octave (12 keys)
			leftBiasSlope = -biasSlope / 12.0f;
			// n = vel - m key
			biasN = toneVel - (leftBiasSlope * biasKey);
			if (biasSlope > 0.0f)	// falling from upper ceiling to biasKey, toneVel
			{
				// \
				//  \
				//   \__________
				//
				// x = (y - n) / m
				from = Point<float>((127.5f - biasN) / leftBiasSlope, 127.5f).transformedBy(valuesToCoords);
				to = Point<float>((float)biasKey, (float)toneVel).transformedBy(valuesToCoords);
				g.drawLine(Line<float>(from, to));
			}
			else if (biasSlope < 0.0f)	// from bottom to biasKey, toneVel
			{
				//    __________
				//   /
				//  /
				// /
				//
				from = Point<float>((0.5f - biasN) / leftBiasSlope, 0.5f).transformedBy(valuesToCoords);
				to = Point<float>((float)biasKey, (float)toneVel).transformedBy(valuesToCoords);
				g.drawLine(Line<float>(from, to));
			}
			// horizontal upper
			from = Point<float>((float)biasKey, (float)toneVel).transformedBy(valuesToCoords);
			to = Point<float>(127.5f, (float)toneVel).transformedBy(valuesToCoords);
			g.drawLine(Line<float>(from, to));
			break;
		case 1: // UPPER
			// horizontal lower
			from = Point<float>(0.0f, (float)toneVel).transformedBy(m_toneLimitsConstrainer->getAffineTransformValuesToPixelcoords()).transformedBy(halfstep);
			to = Point<float>((float)biasKey, (float)toneVel).transformedBy(m_toneLimitsConstrainer->getAffineTransformValuesToPixelcoords()).transformedBy(halfstep);
			g.drawLine(Line<float>(from, to));

			rightBiasSlope = biasSlope / 12.0f;
			biasN = toneVel - (rightBiasSlope*biasKey);
			if (biasSlope < 0.0f)	// falling from biasKey/toneVel to bottom
			{
				// __________
				//           \
				//            \
				//             \
				//
				from = Point<float>((float)biasKey, (float)toneVel).transformedBy(m_toneLimitsConstrainer->getAffineTransformValuesToPixelcoords()).transformedBy(halfstep);
				to = Point<float>((0.5f - (float)biasN) / rightBiasSlope, 0.5f).transformedBy(m_toneLimitsConstrainer->getAffineTransformValuesToPixelcoords()).transformedBy(halfstep);
				g.drawLine(Line<float>(from, to));
			}
			else if (biasSlope > 0.0f)	// raising from biasKey/toneVel to upper ceiling
			{
				//             /
				//            /
				// __________/
				//
				from = Point<float>((float)biasKey, (float)toneVel).transformedBy(m_toneLimitsConstrainer->getAffineTransformValuesToPixelcoords()).transformedBy(halfstep);
				to = Point<float>((127.5f - (float)biasN) / (float)rightBiasSlope, 127.5f).transformedBy(m_toneLimitsConstrainer->getAffineTransformValuesToPixelcoords()).transformedBy(halfstep);
				g.drawLine(Line<float>(from, to));
			}
			break;
		case 2: // LOW&UP
			// lower keys
			leftBiasSlope = (toneVel - (toneVel + biasSlope)) / (biasKey - (biasKey - 6));
			biasN = toneVel - (leftBiasSlope*biasKey);
			// upper keys
			rightBiasSlope = ((toneVel + biasSlope) - toneVel) / ((biasKey + 6) - biasKey);
			biasNRight = toneVel - (rightBiasSlope*biasKey);
			if (biasSlope > 0.0f)	// falling from upper ceiling to biasKey/toneVel
			{
				// __________      ___________
				//           \    /
				//            \  /
				//             \/
				from = Point<float>((127.5f - (float)biasN) / (float)leftBiasSlope, 127.5f).transformedBy(m_toneLimitsConstrainer->getAffineTransformValuesToPixelcoords()).transformedBy(halfstep);
				to = Point<float>((float)biasKey, (float)toneVel).transformedBy(m_toneLimitsConstrainer->getAffineTransformValuesToPixelcoords()).transformedBy(halfstep);
				g.drawLine(Line<float>(from, to));
				from = Point<float>((float)biasKey, (float)toneVel).transformedBy(m_toneLimitsConstrainer->getAffineTransformValuesToPixelcoords()).transformedBy(halfstep);
				to = Point<float>((127.5f - (float)biasNRight) / (float)rightBiasSlope, 127.5f).transformedBy(m_toneLimitsConstrainer->getAffineTransformValuesToPixelcoords()).transformedBy(halfstep);
				g.drawLine(Line<float>(from, to));
			}
			else if (biasSlope < 0.0f)	// from bottom to biasKey/toneVel
			{
				//             /\
				//            /  \
				// __________/    \___________
				//
				from = Point<float>((0.5f - (float)biasN) / (float)leftBiasSlope, 0.5f).transformedBy(m_toneLimitsConstrainer->getAffineTransformValuesToPixelcoords()).transformedBy(halfstep);
				to = Point<float>((float)biasKey, (float)toneVel).transformedBy(m_toneLimitsConstrainer->getAffineTransformValuesToPixelcoords()).transformedBy(halfstep);
				g.drawLine(Line<float>(from, to));
				from = Point<float>((float)biasKey, (float)toneVel).transformedBy(m_toneLimitsConstrainer->getAffineTransformValuesToPixelcoords()).transformedBy(halfstep);
				to = Point<float>((0.5f - (float)biasNRight) / (float)rightBiasSlope, 0.5f).transformedBy(m_toneLimitsConstrainer->getAffineTransformValuesToPixelcoords()).transformedBy(halfstep);
				g.drawLine(Line<float>(from, to));
			}
			break;
		case 3: // ALL
			// lower keys
			leftBiasSlope = (toneVel - (toneVel - biasSlope)) / (biasKey - (biasKey - 6));
			biasN = toneVel - (leftBiasSlope*biasKey);
			// upper keys
			rightBiasSlope = ((toneVel + biasSlope) - toneVel) / ((biasKey + 6) - biasKey);
			biasNRight = toneVel - (rightBiasSlope*biasKey);
			if (biasSlope < 0.0f)	// falling from upper ceiling to biasKey/toneVel
			{
				from = Point<float>((127.5f - (float)biasN) / (float)leftBiasSlope, 127.5f).transformedBy(m_toneLimitsConstrainer->getAffineTransformValuesToPixelcoords()).transformedBy(halfstep);
				to = Point<float>((float)biasKey, (float)toneVel).transformedBy(m_toneLimitsConstrainer->getAffineTransformValuesToPixelcoords()).transformedBy(halfstep);
				g.drawLine(Line<float>(from, to));
				from = Point<float>((float)biasKey, (float)toneVel).transformedBy(m_toneLimitsConstrainer->getAffineTransformValuesToPixelcoords()).transformedBy(halfstep);
				to = Point<float>((0.5f - (float)biasNRight) / (float)rightBiasSlope, 0.5f).transformedBy(m_toneLimitsConstrainer->getAffineTransformValuesToPixelcoords()).transformedBy(halfstep);
				g.drawLine(Line<float>(from, to));
			}
			else if (biasSlope > 0.0f)	// from bottom to biasKey/toneVel
			{
				from = Point<float>((0.5f - (float)biasN) / (float)leftBiasSlope, 0.5f).transformedBy(m_toneLimitsConstrainer->getAffineTransformValuesToPixelcoords()).transformedBy(halfstep);
				to = Point<float>((float)biasKey, (float)toneVel).transformedBy(m_toneLimitsConstrainer->getAffineTransformValuesToPixelcoords()).transformedBy(halfstep);
				g.drawLine(Line<float>(from, to));
				from = Point<float>((float)biasKey, (float)toneVel).transformedBy(m_toneLimitsConstrainer->getAffineTransformValuesToPixelcoords()).transformedBy(halfstep);
				to = Point<float>((127.5f - (float)biasNRight) / (float)rightBiasSlope, 127.5f).transformedBy(m_toneLimitsConstrainer->getAffineTransformValuesToPixelcoords()).transformedBy(halfstep);
				g.drawLine(Line<float>(from, to));
			}
			break;
		default:
			break;
		}
		// draw pias point itself
		//g.drawEllipse(
		//	m_toneLimitsConstrainer->keyToXCoord(biasKey, ToneLimitsConstrainer::Center) - 3.0f,
		//	m_toneLimitsConstrainer->velToYCoord(toneVel, ToneLimitsConstrainer::Mid) - 3.0f,
		//	6.0f,
		//	6.0f,
		//	1.0f);

		// paint dashed line for bias key
		g.restoreState();
		g.setColour(Colours::black);
		float dashPattern[2] = { 2.0f, 2.0f };
		//if (getAlpha() == 1.0f)
		if ((m_velocityXFadePrm->getValue()==0&&(toneVel>=velLower && toneVel<=velUpper))
			|| (m_velocityXFadePrm->getValue() > 0 && (toneVel >= lowerVeloCrossfadeLimit && toneVel < upperVeloCrossfadeLimit)))
		{
			from = Point<float>((float)biasKey, (float)toneVel).transformedBy(m_toneLimitsConstrainer->getAffineTransformValuesToPixelcoords()).transformedBy(halfstep);
			to = Point<float>((float)biasKey, (float)0.0f).transformedBy(m_toneLimitsConstrainer->getAffineTransformValuesToPixelcoords()).transformedBy(halfstep);
			g.drawDashedLine(Line<float>(
				from.getX(),
				from.getY(),
				to.getX(),
				to.getY()),
				dashPattern, 2);
		}

		// paint dashed rectangle for crossfade area
		if (m_velocityXFadePrm->getValue() > 0)
		{
			g.drawDashedLine(Line<float>(toneBounds.getX() + 0.5f, y_upperVel + 0.5f, toneBounds.getRight() - 0.5f, y_upperVel + 0.5f), dashPattern, 2);
			g.drawDashedLine(Line<float>(toneBounds.getRight() - 0.5f, y_upperVel + 0.5f, toneBounds.getRight() - 0.5f, toneBounds.getY() - 0.5f), dashPattern, 2);
			g.drawDashedLine(Line<float>(toneBounds.getRight() - 0.5f, toneBounds.getBottom() + 0.5f, toneBounds.getRight() - 0.5f, y_lowerVel - 0.5f), dashPattern, 2);
			g.drawDashedLine(Line<float>(toneBounds.getRight() - 0.5f, y_lowerVel - 0.5f, toneBounds.getX() + 0.5f, y_lowerVel - 0.5f), dashPattern, 2);
			g.drawDashedLine(Line<float>(toneBounds.getX() + 0.5f, y_lowerVel - 0.5f, toneBounds.getX() + 0.5f, toneBounds.getBottom() + 0.5f), dashPattern, 2);
			g.drawDashedLine(Line<float>(toneBounds.getX() + 0.5f, toneBounds.getY() - 0.5f, toneBounds.getX() + 0.5f, y_upperVel + 0.5f), dashPattern, 2);
		}
	}
    //[/UserPrePaint]

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void ToneMixTableToneVeloXFade::resized()
{
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void ToneMixTableToneVeloXFade::mouseMove (const MouseEvent& e)
{
    //[UserCode_mouseMove] -- Add your code here...
	#ifdef JUCE_MSVC
	e;
	#endif
	setAlpha(1.0f);
    //[/UserCode_mouseMove]
}

void ToneMixTableToneVeloXFade::mouseEnter (const MouseEvent& e)
{
    //[UserCode_mouseEnter] -- Add your code here...
	#ifdef JUCE_MSVC
	e;
	#endif

	setAlpha(1.0f);
    //[/UserCode_mouseEnter]
}

void ToneMixTableToneVeloXFade::mouseExit (const MouseEvent& e)
{
    //[UserCode_mouseExit] -- Add your code here...
	#ifdef JUCE_MSVC
	e;
	#endif
	setAlpha(0.5f);
    //[/UserCode_mouseExit]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...

void ToneMixTableToneVeloXFade::componentMovedOrResized(bool /*wasMoved*/, bool /*wasResized*/)
{
	/*if (ToneMixTableTone* toneWidget = dynamic_cast<ToneMixTableTone*>(getComponent()))
	{
		Rectangle<int> toneWidgetBoundsInCanvas(toneWidget->getBoundsInParent());

		int keyLower, keyUpper, velLower, velUpper;
		m_toneLimitsConstrainer->getValuesFromBoundingBox(toneWidgetBoundsInCanvas, keyLower, keyUpper, velLower, velUpper);
		int upperVeloCrossfadeLimit = velUpper + m_velocityXFadePrm->getValue();
		int lowerVeloCrossfadeLimit = velLower - m_velocityXFadePrm->getValue();
		Point<float> upper = Point<float>(0.0f, (float)upperVeloCrossfadeLimit).transformedBy(m_toneLimitsConstrainer->getAffineTransformValuesToPixelcoords());
		Point<float> lower = Point<float>(0.0f, (float)lowerVeloCrossfadeLimit).transformedBy(m_toneLimitsConstrainer->getAffineTransformValuesToPixelcoords());
		this->setTopLeftPosition(
			toneWidgetBoundsInCanvas.getX(),
			(int)upper.getY());
		this->setSize(
			toneWidgetBoundsInCanvas.getWidth(),
			(int)lower.getY() - (int)upper.getY());
	}*/
	//repaint();
}

void ToneMixTableToneVeloXFade::changeListenerCallback(ChangeBroadcaster* source)
{
	if (source == m_velocityXFadePrm)
	{
		repaint();
	}
	else if (source == m_toneLevelPrm)
	{
		repaint();
	}
	else if (source == m_biasDirectionPrm)
	{
		repaint();
	}
	else if (source == m_biasPointPrm)
	{
		repaint();
	}
	else if (source == m_biasLevelPrm)
	{
		repaint();
	}
}

//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Introjucer information section --

    This is where the Introjucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="ToneMixTableToneVeloXFade"
                 componentName="" parentClasses="public Component, public ComponentMovementWatcher, public ChangeListener"
                 constructorParams="const String &amp;componentName, Component* componentToWatch, ToneLimitsConstrainer* toneLimitsConstrainer, SynthParts part, Tone tone"
                 variableInitialisers="Component(componentName), ComponentMovementWatcher(componentToWatch),&#10;m_part(part),&#10;m_tone(tone),&#10;m_toneLimitsConstrainer(toneLimitsConstrainer)"
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="0" initialWidth="600" initialHeight="400">
  <METHODS>
    <METHOD name="mouseMove (const MouseEvent&amp; e)"/>
    <METHOD name="mouseEnter (const MouseEvent&amp; e)"/>
    <METHOD name="mouseExit (const MouseEvent&amp; e)"/>
  </METHODS>
  <BACKGROUND backgroundColour="0"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
