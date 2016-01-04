/*
  ==============================================================================

    ToneLimitsConstrainer.cpp
    Created: 29 Sep 2014 12:24:31pm
    Author:  Spindler

  ==============================================================================
*/

#include "ToneLimitsConstrainer.h"

ToneLimitsConstrainer::ToneLimitsConstrainer(int width, int  height) :
ComponentBoundsConstrainer()
{
	setSize(width, height);
}

void ToneLimitsConstrainer::setSize(int width, int  height)
{ 
	m_width = width; m_height = height;
	m_affineTransValuesToCoords = AffineTransform::fromTargetPoints(
		000.0f, 128.0f,			000.0f,			 000.0f,	// key   0 velocity 128 to upper  left corner
		128.0f, 128.0f, (float)m_width,			 000.0f,	// key 128 velocity 128 to upper right corner
		128.0f, 000.0f, (float)m_width, (float)m_height);	// key 128 velocity   0 to lower right corner
	m_affineTransCoordsToValues = AffineTransform::fromTargetPoints(
				000.0f,			 000.0f, 000.0f, 128.0f,	// upper  left corner to key   0 velocity 128
		(float)m_width,			 000.0f, 128.0f, 128.0f,	// upper right corner to key 128 velocity 128
		(float)m_width, (float)m_height, 128.0f, 000.0f);	// lower right corner to key 128 velocity   0
}

int ToneLimitsConstrainer::getHeight()
{
	return m_height;
}

int ToneLimitsConstrainer::getWidth()
{
	return m_width;
}

void ToneLimitsConstrainer::checkBounds(Rectangle<int>& bounds,
	const Rectangle<int>& previousBounds,
	const Rectangle<int>& ,
	bool isStretchingTop,
	bool isStretchingLeft,
	bool isStretchingBottom,
	bool isStretchingRight)
{
	// round positions to valid values
	// left as low key, bottom as low velocity
	Point<float> lowKeyAndVelocity = transformCoordToKeyVelocity(Point<float>((float)bounds.getX(), (float)bounds.getBottom()));
	// right border minus keywidth as upper key, top plus stepheight as upper velocity
	Point<float> upperKeyAndVelocity = transformCoordToKeyVelocity(Point<float>((float)bounds.getRight(), (float)bounds.getY()));
	int roundedLowerKey(roundFloatToInt(lowKeyAndVelocity.getX()));
	int roundedLowerVel(roundFloatToInt(lowKeyAndVelocity.getY()));
	int roundedUpperKey(roundFloatToInt(upperKeyAndVelocity.getX()) - 1);
	int roundedUpperVel(roundFloatToInt(upperKeyAndVelocity.getY()) - 1);
	// ranges including lower and upper
	int roundedKeyRangeWidth(roundedUpperKey - roundedLowerKey + 1);
	int roundedVelocityRangeHeight(roundedUpperVel - roundedLowerVel + 1);
	//DBG("rounded: Lwr Key " + String(roundedLowerKey).paddedLeft('0', 3) + ", Upper Key " + String(roundedUpperKey).paddedLeft('0', 3) + ", Lower Velocity " + String(roundedLowerVel).paddedLeft('0', 3) + ", Upper Velocity " + String(roundedUpperVel).paddedLeft('0', 3) + " - Width: " + String(roundedKeyRangeWidth).paddedLeft('0', 3) + ", Height: " + String(roundedVelocityRangeHeight).paddedLeft('0', 3));
	
	// moving: only move, don't resize no stretching)
	if (!isStretchingLeft && !isStretchingRight && !isStretchingTop && !isStretchingBottom)
	{
		// too far left
		if (roundedLowerKey < 0)
		{ 
			roundedUpperKey = (roundedUpperKey - roundedLowerKey);
			roundedLowerKey = 0;
		}
		// too far right
		else if (roundedUpperKey > 127)
		{
			roundedLowerKey = 127 - (roundedUpperKey - roundedLowerKey);
			roundedUpperKey = 127;
		}
		// too far down
		if (roundedLowerVel < 0)
		{
			roundedUpperVel = (roundedUpperVel - roundedLowerVel);
			roundedLowerVel = 0;
		}
		// too far up
		else if (roundedUpperVel > 127)
		{ 
			roundedLowerVel = 127 - (roundedUpperVel - roundedLowerVel);
			roundedUpperVel = 127; 
		}
		roundedKeyRangeWidth = roundedUpperKey - roundedLowerKey + 1;
		roundedVelocityRangeHeight = roundedUpperVel - roundedLowerVel + 1;
		//DBG("moved: Lwr Key " + String(roundedLowerKey).paddedLeft('0', 3) + ", Upper Key " + String(roundedUpperKey).paddedLeft('0', 3) + ", Lower Velocity " + String(roundedLowerVel).paddedLeft('0', 3) + ", Upper Velocity " + String(roundedUpperVel).paddedLeft('0', 3) + " - Width: " + String(roundedKeyRangeWidth).paddedLeft('0', 3) + ", Height: " + String(roundedVelocityRangeHeight).paddedLeft('0', 3));

		if (roundedLowerKey >= 0 && roundedUpperKey <= 127 &&
			roundedLowerVel >= 0 && roundedUpperVel <= 127)
		{
			Point<float> upperLeftPoint = transformKeyVelocityToCoord(roundedLowerKey, roundedUpperVel + 1);
			Point<float> lowerRightPoint = transformKeyVelocityToCoord(roundedUpperKey + 1, roundedLowerVel);
			bounds.setPosition(upperLeftPoint.toInt());
			bounds.setWidth((int)(lowerRightPoint.getX()-upperLeftPoint.getX()));
			bounds.setHeight((int)(lowerRightPoint.getY() - upperLeftPoint.getY()));
		}
	}
	else
	{
		// resizing
		if (isStretchingLeft)
		{
			if (roundedLowerKey < 0) roundedLowerKey = 0;
			if (roundedUpperKey > roundedLowerKey)
			{
				Point<float> coord = transformKeyVelocityToCoord(roundedLowerKey, 0);
				bounds.setLeft((int)coord.getX());
			}
			else 
			{
				roundedLowerKey = roundedUpperKey;
				bounds.setLeft((int)previousBounds.getX());
			}
		}
		if (isStretchingRight)
		{
			if (roundedUpperKey > 127) roundedUpperKey = 127;
			if (roundedUpperKey >= roundedLowerKey)
			{
				Point<float> coord = transformKeyVelocityToCoord(roundedUpperKey + 1, 0);
				bounds.setRight((int)coord.getX());
			}
			else
			{
				roundedUpperKey = roundedLowerKey;
				bounds.setWidth(previousBounds.getWidth());
			}
		}
		if (isStretchingTop)
		{
			if (roundedUpperVel > 127) roundedUpperVel = 127;
			if (roundedUpperVel>=roundedLowerVel)
			{
				Point<float> coord = transformKeyVelocityToCoord(0, roundedUpperVel + 1);
				bounds.setTop((int)coord.getY());
			}
			else 
			{
				roundedUpperVel = roundedLowerVel;
				bounds.setTop(previousBounds.getY());
			}
		}
		if (isStretchingBottom)
		{
			if (roundedLowerVel < 0) roundedLowerVel = 0;
			if (roundedUpperVel>=roundedLowerVel)
			{
				Point<float> coord = transformKeyVelocityToCoord(0, roundedLowerVel);
				bounds.setBottom((int)coord.getY());
			}
			else 
			{
				roundedLowerVel = roundedUpperVel;
				bounds.setHeight(previousBounds.getHeight());
			}
		}
		roundedKeyRangeWidth = roundedUpperKey - roundedLowerKey + 1;
		roundedVelocityRangeHeight = roundedUpperVel - roundedLowerVel + 1;
		//DBG("resized: Lwr Key " + String(roundedLowerKey).paddedLeft('0', 3) + ", Upper Key " + String(roundedUpperKey).paddedLeft('0', 3) + ", Lower Velocity " + String(roundedLowerVel).paddedLeft('0', 3) + ", Upper Velocity " + String(roundedUpperVel).paddedLeft('0', 3) + " - Width: " + String(roundedKeyRangeWidth).paddedLeft('0', 3) + ", Height: " + String(roundedVelocityRangeHeight).paddedLeft('0', 3));
	}
}

Point<float> ToneLimitsConstrainer::transformKeyVelocityToCoord(int key, int velocity)
{
	Point<float> result = Point<float>((float)key, (float)velocity);
	result.applyTransform(m_affineTransValuesToCoords);
	return result;
}

Point<float> ToneLimitsConstrainer::transformCoordToKeyVelocity(Point<float> coordinates)
{
	Point<float> result = coordinates.toFloat();
	result.applyTransform(m_affineTransCoordsToValues);
	return result;
}