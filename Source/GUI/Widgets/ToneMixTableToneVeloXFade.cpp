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
//[/Headers]

#include "ToneMixTableToneVeloXFade.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
ToneMixTableToneVeloXFade::ToneMixTableToneVeloXFade (const String &componentName, Component* componentToWatch)
    : Component(componentName), ComponentMovementWatcher(componentToWatch)
{

    //[UserPreSize]
	setInterceptsMouseClicks(false, true);
	componentToWatch->addMouseListener(this,true);
	setAlpha(0.5f);
    //[/UserPreSize]

    setSize (600, 400);


    //[Constructor] You can add your own custom stuff here..
    //[/Constructor]
}

ToneMixTableToneVeloXFade::~ToneMixTableToneVeloXFade()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
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
		if (ToneMixTableCanvas* canvas = dynamic_cast<ToneMixTableCanvas*>(getParentComponent()))
		{
			ToneLimitsConstrainer* constrainer = canvas->getToneLimitsConstrainerPtr();
			float y_upperVel (constrainer->transformKeyVelocityToCoord(0, toneWidget->getVelocityRangeUpper() - 1).getY()-getY());
			float y_lowerVel(constrainer->transformKeyVelocityToCoord(0, toneWidget->getVelocityRangeLower()).getY() - getY());

			// paint gradient filling for upper velocity crossfade
			g.setGradientFill(ColourGradient(Colour(0x00ffffff),
				0.0f, 0.0f,
				Colours::white,
				0.0f, y_upperVel,
				false));
			g.fillRect(0.0f, 0.0f, (float) getWidth(), y_upperVel);

			// paint filling for velocity range
			g.setFillType(Colour(Colours::white));
			g.fillRect(0.0f, y_upperVel, (float)getWidth(), y_lowerVel - y_upperVel);
			// paint gradient filling for lower velocity crossfade
			g.setGradientFill(ColourGradient(Colours::white,
				0.0f, y_lowerVel,
				Colour(0x00ffffff),
				0.0f, (float)getHeight(),
				false));
			g.fillRect(0.0f, y_lowerVel, (float)getWidth(), (float)getHeight()-y_lowerVel);

			// paint amp bias curves
			// draw bias point
			float biasSlope;
			switch (toneWidget->getBiasLevel())
			{
			case  0: biasSlope = -100.0f; break;
			case  1: biasSlope = -70.0f; break;
			case  2: biasSlope = -50.0f; break;
			case  3: biasSlope = -40.0f; break;
			case  4: biasSlope = -30.0f; break;
			case  5: biasSlope = -20.0f; break;
			case  6: biasSlope = -10.0f; break;
			case  7: biasSlope = -0.0f; break;
			case  8: biasSlope = 10.0f; break;
			case  9: biasSlope = 20.0f; break;
			case 10: biasSlope = 30.0f; break;
			case 11: biasSlope = 40.0f; break;
			case 12: biasSlope = 50.0f; break;
			case 13: biasSlope = 70.0f; break;
			case 14: biasSlope = 100.0f; break;
			default: biasSlope = -100.0f; break;
			}

			g.setColour(Colours::black);
			ColourGradient gradient;
			if (getHeight()>0)
			{
				gradient = ColourGradient(Colour(0x00000000),
					0.0f,
					0.0f,
					toneWidget->getVelocityRangeLower()>0 ? Colour(0x00000000) : Colour(0xff000000),
					0.0f,
					(float)getHeight(),
					false);
				gradient.addColour(y_upperVel / getHeight(), Colour(0xff000000));
				gradient.addColour(y_lowerVel / getHeight(), Colour(0xff000000));
			}
			else
			{
				gradient = ColourGradient(Colour(0xff000000),
					0.0f,
					0.0f,
					toneWidget->getVelocityRangeLower()>0 ? Colour(0x00000000) : Colour(0xff000000),
					0.0f,
					(float)getHeight(),
					false);
			}
			g.setGradientFill(gradient);
			// bias point pos:
			int biasKey = toneWidget->getBiasPointKey();
			int biasVel = toneWidget->getToneLevel();
			float leftBiasSlope(0.0f), rightBiasSlope(0.0f);
			float biasN(0.0f);
			Point<float> from, to;
			if (biasSlope == 0.0f)		// horizontal line
			{
				g.drawLine(
					(float) 0 - getX(),
					(float)	constrainer->transformKeyVelocityToCoord(0, biasVel).getY() - getY(),
					(float) constrainer->getWidth() - getX(),
					(float) constrainer->transformKeyVelocityToCoord(0, biasVel).getY() - getY());
			}
			else switch (toneWidget->getBiasDirection())	//  0 - 3: LOWER, UPPER, LOW&UP, ALL
			{
				case 0:	// LOWER
					leftBiasSlope = (biasVel - (biasVel + biasSlope)) / (biasKey - (biasKey - 12));
					biasN = biasVel - (leftBiasSlope*biasKey);
					if (biasSlope > 0.0f)	// falling from upper ceiling to biasKey/biasVel
					{
						from = constrainer->transformKeyVelocityToCoord((int)((127.0f - biasN) / leftBiasSlope), 127).translated(constrainer->getKeyWidth()*0.5f,-constrainer->getVelocityStepHeight()*0.5f);
						to = constrainer->transformKeyVelocityToCoord(biasKey, biasVel).translated(constrainer->getKeyWidth()*0.5f, -constrainer->getVelocityStepHeight()*0.5f);
						// slope y = m*x+n => x = (y-n)/m
						g.drawLine(
							(float) from.getX() - getX(),
							(float) from.getY() - getY(),
							(float) to.getX() - getX(),
							(float) to.getY()  - getY());

					}
					else if (biasSlope < 0.0f)	// from bottom to biasKey/biasVel
					{
						// slope y = m*x+n => x = (y-n)/m
						from = constrainer->transformKeyVelocityToCoord((int)((0.0f - biasN) / leftBiasSlope), 0).translated(constrainer->getKeyWidth()*0.5f, -constrainer->getVelocityStepHeight()*0.5f);
						to = constrainer->transformKeyVelocityToCoord(biasKey, biasVel).translated(constrainer->getKeyWidth()*0.5f, -constrainer->getVelocityStepHeight()*0.5f);
						g.drawLine(
							(float)from.getX() - getX(),
							(float)from.getY() - getY(),
							(float)to.getX() - getX(),
							(float)to.getY() - getY());
					}
					// horizontal upper
					from = constrainer->transformKeyVelocityToCoord(biasKey, biasVel).translated(constrainer->getKeyWidth()*0.5f, -constrainer->getVelocityStepHeight()*0.5f);
					to = constrainer->transformKeyVelocityToCoord(127, biasVel).translated(constrainer->getKeyWidth()*0.5f, -constrainer->getVelocityStepHeight()*0.5f);
					g.drawLine(
						(float)from.getX() - getX(),
						(float)from.getY() - getY(),
						(float)to.getX() - getX(),
						(float)to.getY() - getY());
					break;
				case 1: // UPPER
					// horizontal lower
					from = constrainer->transformKeyVelocityToCoord(0, biasVel).translated(constrainer->getKeyWidth()*0.5f, -constrainer->getVelocityStepHeight()*0.5f);
					to = constrainer->transformKeyVelocityToCoord(biasKey, biasVel).translated(constrainer->getKeyWidth()*0.5f, -constrainer->getVelocityStepHeight()*0.5f);
					g.drawLine(
						(float)from.getX() - getX(),
						(float)from.getY() - getY(),
						(float)to.getX() - getX(),
						(float)to.getY() - getY());
					rightBiasSlope = ((biasVel + biasSlope) - biasVel) / ((biasKey + 12) - biasKey);
					biasN = biasVel - (rightBiasSlope*biasKey);
					if (biasSlope < 0.0f)	// falling from biasKey/biasVel to bottom
					{
						from = constrainer->transformKeyVelocityToCoord(biasKey, biasVel).translated(constrainer->getKeyWidth()*0.5f, -constrainer->getVelocityStepHeight()*0.5f);
						to = constrainer->transformKeyVelocityToCoord((int)((0.0f - biasN) / rightBiasSlope), 0).translated(constrainer->getKeyWidth()*0.5f, -constrainer->getVelocityStepHeight()*0.5f);
						// slope y = m*x+n => x = (y-n)/m
						g.drawLine(
							(float)from.getX() - getX(),
							(float)from.getY() - getY(),
							(float)to.getX() - getX(),
							(float)to.getY() - getY());
					}
					else if (biasSlope > 0.0f)	// raising from biasKey/biasVel to upper ceiling
					{
						from = constrainer->transformKeyVelocityToCoord(biasKey, biasVel).translated(constrainer->getKeyWidth()*0.5f, -constrainer->getVelocityStepHeight()*0.5f);
						to = constrainer->transformKeyVelocityToCoord((int)((127.0f - biasN) / rightBiasSlope), 127).translated(constrainer->getKeyWidth()*0.5f, -constrainer->getVelocityStepHeight()*0.5f);
						// slope y = m*x+n => x = (y-n)/m
						g.drawLine(
							(float)from.getX() - getX(),
							(float)from.getY() - getY(),
							(float)to.getX() - getX(),
							(float)to.getY() - getY());
					}
					break;
				case 2: // LOW&UP
					// lower
					leftBiasSlope = (biasVel - (biasVel + biasSlope)) / (biasKey - (biasKey - 6));
					biasN = biasVel - (leftBiasSlope*biasKey);
					if (biasSlope > 0.0f)	// falling from upper ceiling to biasKey/biasVel
					{
						from = constrainer->transformKeyVelocityToCoord((int)((127.0f - biasN) / leftBiasSlope), 127).translated(constrainer->getKeyWidth()*0.5f, -constrainer->getVelocityStepHeight()*0.5f);
						to = constrainer->transformKeyVelocityToCoord(biasKey, biasVel).translated(constrainer->getKeyWidth()*0.5f, -constrainer->getVelocityStepHeight()*0.5f);
						// slope y = m*x+n => x = (y-n)/m
						g.drawLine(
							(float)from.getX() - getX(),
							(float)from.getY() - getY(),
							(float)to.getX() - getX(),
							(float)to.getY() - getY());

					}
					else if (biasSlope < 0.0f)	// from bottom to biasKey/biasVel
					{
						// slope y = m*x+n => x = (y-n)/m
						from = constrainer->transformKeyVelocityToCoord((int)((0 - biasN) / leftBiasSlope), 0).translated(constrainer->getKeyWidth()*0.5f, -constrainer->getVelocityStepHeight()*0.5f);
						to = constrainer->transformKeyVelocityToCoord(biasKey, biasVel).translated(constrainer->getKeyWidth()*0.5f, -constrainer->getVelocityStepHeight()*0.5f);
						g.drawLine(
							(float)from.getX() - getX(),
							(float)from.getY() - getY(),
							(float)to.getX() - getX(),
							(float)to.getY() - getY());
					}
					// upper
					rightBiasSlope = ((biasVel + biasSlope) - biasVel) / ((biasKey + 6) - biasKey);
					biasN = biasVel - (rightBiasSlope*biasKey);
					if (biasSlope < 0.0f)	// falling from biasKey/biasVel to bottom
					{
						from = constrainer->transformKeyVelocityToCoord(biasKey, biasVel).translated(constrainer->getKeyWidth()*0.5f, -constrainer->getVelocityStepHeight()*0.5f);
						to = constrainer->transformKeyVelocityToCoord((int)((0.0f - biasN) / rightBiasSlope), 0).translated(constrainer->getKeyWidth()*0.5f, -constrainer->getVelocityStepHeight()*0.5f);
						// slope y = m*x+n => x = (y-n)/m
						g.drawLine(
							(float)from.getX() - getX(),
							(float)from.getY() - getY(),
							(float)to.getX() - getX(),
							(float)to.getY() - getY());
					}
					else if (biasSlope > 0.0f)	// raising from biasKey/biasVel to upper ceiling
					{
						from = constrainer->transformKeyVelocityToCoord(biasKey, biasVel).translated(constrainer->getKeyWidth()*0.5f, -constrainer->getVelocityStepHeight()*0.5f);
						to = constrainer->transformKeyVelocityToCoord((int)((127.0 - biasN) / rightBiasSlope), 127).translated(constrainer->getKeyWidth()*0.5f, -constrainer->getVelocityStepHeight()*0.5f);
						// slope y = m*x+n => x = (y-n)/m
						g.drawLine(
							(float)from.getX() - getX(),
							(float)from.getY() - getY(),
							(float)to.getX() - getX(),
							(float)to.getY() - getY());
					}
					break;
				case 3: // ALL
					// lower
					leftBiasSlope = (biasVel - (biasVel - biasSlope)) / (biasKey - (biasKey - 6));
					biasN = biasVel - (leftBiasSlope*biasKey);
					if (biasSlope < 0.0f)	// falling from upper ceiling to biasKey/biasVel
					{
						from = constrainer->transformKeyVelocityToCoord((int)((127.0 - biasN) / leftBiasSlope), 127).translated(constrainer->getKeyWidth()*0.5f, -constrainer->getVelocityStepHeight()*0.5f);
						to = constrainer->transformKeyVelocityToCoord(biasKey, biasVel).translated(constrainer->getKeyWidth()*0.5f, -constrainer->getVelocityStepHeight()*0.5f);
						// slope y = m*x+n => x = (y-n)/m
						g.drawLine(
							(float)from.getX() - getX(),
							(float)from.getY() - getY(),
							(float)to.getX() - getX(),
							(float)to.getY() - getY());

					}
					else if (biasSlope > 0.0f)	// from bottom to biasKey/biasVel
					{
						from = constrainer->transformKeyVelocityToCoord((int)((0.0f - biasN) / leftBiasSlope), 0).translated(constrainer->getKeyWidth()*0.5f, -constrainer->getVelocityStepHeight()*0.5f);
						to = constrainer->transformKeyVelocityToCoord(biasKey, biasVel).translated(constrainer->getKeyWidth()*0.5f, -constrainer->getVelocityStepHeight()*0.5f);
						// slope y = m*x+n => x = (y-n)/m
						g.drawLine(
							(float)from.getX() - getX(),
							(float)from.getY() - getY(),
							(float)to.getX() - getX(),
							(float)to.getY() - getY());
					}
					// upper
					rightBiasSlope = ((biasVel + biasSlope) - biasVel) / ((biasKey + 6) - biasKey);
					biasN = biasVel - (rightBiasSlope*biasKey);
					if (biasSlope < 0.0f)	// falling from biasKey/biasVel to bottom
					{
						from = constrainer->transformKeyVelocityToCoord(biasKey, biasVel).translated(constrainer->getKeyWidth()*0.5f, -constrainer->getVelocityStepHeight()*0.5f);
						to = constrainer->transformKeyVelocityToCoord((int)((0.0f - biasN) / rightBiasSlope), 0).translated(constrainer->getKeyWidth()*0.5f, -constrainer->getVelocityStepHeight()*0.5f);
						// slope y = m*x+n => x = (y-n)/m
						g.drawLine(
							(float)from.getX() - getX(),
							(float)from.getY() - getY(),
							(float)to.getX() - getX(),
							(float)to.getY() - getY());
					}
					else if (biasSlope > 0.0f)	// raising from biasKey/biasVel to upper ceiling
					{
						from = constrainer->transformKeyVelocityToCoord(biasKey, biasVel).translated(constrainer->getKeyWidth()*0.5f, -constrainer->getVelocityStepHeight()*0.5f);
						to = constrainer->transformKeyVelocityToCoord((int)((127.0f - biasN) / rightBiasSlope), 127).translated(constrainer->getKeyWidth()*0.5f, -constrainer->getVelocityStepHeight()*0.5f);
						// slope y = m*x+n => x = (y-n)/m
						g.drawLine(
							(float)from.getX() - getX(),
							(float)from.getY() - getY(),
							(float)to.getX() - getX(),
							(float)to.getY() - getY());
					}
					break;
				default:
					break;
			}

			// draw pias point itself
			//g.drawEllipse(
			//	constrainer->keyToXCoord(biasKey, ToneLimitsConstrainer::Center) - getX() - 3.0f,
			//	constrainer->velToYCoord(biasVel, ToneLimitsConstrainer::Mid) - getY() - 3.0f,
			//	6.0f,
			//	6.0f,
			//	1.0f);

			// paint dashed line for bias key
			g.setColour(Colours::black);
			float dashPattern[2] = { 2.0f, 1.0f };
			if (getAlpha() == 1.0f)
			{
				from = constrainer->transformKeyVelocityToCoord(biasKey, biasVel).translated(constrainer->getKeyWidth()*0.5f, -constrainer->getVelocityStepHeight()*0.5f);
				to = constrainer->transformKeyVelocityToCoord(biasKey, 0).translated(constrainer->getKeyWidth()*0.5f, -constrainer->getVelocityStepHeight()*0.5f);
				g.drawDashedLine(Line<float>(
					(float)from.getX() - getX(),
					(float)from.getY() - getY(),
					(float)to.getX() - getX(),
					(float)to.getY() - getY()),
					dashPattern,2);
			}

			// paint dashed rectangle for crossfade area
			g.drawDashedLine(Line<float>(0.0f, 0.0f, (float)getWidth(), 0.0f), dashPattern, 2);
			g.drawDashedLine(Line<float>((float)getWidth(), 0.0f, (float)getWidth(), (float)getHeight()), dashPattern, 2);
			g.drawDashedLine(Line<float>((float)getWidth(), (float)getHeight(), 0.0f, (float)getHeight()), dashPattern, 2);
			g.drawDashedLine(Line<float>(0.0f, (float)getHeight(), 0.0f, 0.0f), dashPattern, 2);
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
	if (ToneMixTableTone* toneWidget = dynamic_cast<ToneMixTableTone*>(getComponent()))
	{
		Rectangle<int> toneWidgetBoundsInCanvas(toneWidget->getBoundsInParent());

		if (ToneMixTableCanvas* canvas = dynamic_cast<ToneMixTableCanvas*>(getParentComponent()))
		{
			ToneLimitsConstrainer* constrainer = canvas->getToneLimitsConstrainerPtr();
			if (constrainer != nullptr)
			{
				int upperVeloCrossfadeLimit = toneWidget->getVelocityRangeUpper() + toneWidget->getVeloCrossfade();
				int lowerVeloCrossfadeLimit = toneWidget->getVelocityRangeLower() - toneWidget->getVeloCrossfade();
				Point<float> upper = constrainer->transformKeyVelocityToCoord(0, upperVeloCrossfadeLimit);
				Point<float> lower = constrainer->transformKeyVelocityToCoord(0, lowerVeloCrossfadeLimit);
				this->setTopLeftPosition(
					toneWidgetBoundsInCanvas.getX(),
					(int)upper.getY());
				this->setSize(
					toneWidgetBoundsInCanvas.getWidth(),
					(int)lower.getY() - (int)upper.getY());
			}
		}
	}
}

void ToneMixTableToneVeloXFade::componentPeerChanged()
{

}

void ToneMixTableToneVeloXFade::componentVisibilityChanged()
{

}

//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Introjucer information section --

    This is where the Introjucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="ToneMixTableToneVeloXFade"
                 componentName="" parentClasses="public Component, public ComponentMovementWatcher"
                 constructorParams="const String &amp;componentName, Component* componentToWatch"
                 variableInitialisers="Component(componentName), ComponentMovementWatcher(componentToWatch)"
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
