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
	setMinimumOnscreenAmounts(0xffffff, 0xffffff, 0xffffff, 0xffffff);
	setSize(width, height);
	m_movingDragMode = false; 
}

void ToneLimitsConstrainer::setSize(int width, int  height)
{ 
	m_width = width; m_height = height;

	m_affineTransValuesToCoords = AffineTransform(
		(float)m_width / 128.0f,                    0.0f,                   0.0f,
		                    0.0f, -m_height / 127.0f, m_height * 128.0f / 127.0f);
}

int ToneLimitsConstrainer::snapX(int x)
{
	int grid = m_width / 128;
	return ((x + grid * 1024 + grid / 2) / grid - 1024) * grid;
}

int ToneLimitsConstrainer::snapY(int y)
{
	int grid = m_height / 127;
	return ((y + grid * 1024 + grid / 2) / grid - 1024) * grid;
}

// TODO: moving around seems to resize -> keep size! maybe the m_previousBoundsInParent is not sufficiently saving with and height?!
void ToneLimitsConstrainer::checkBounds(Rectangle<int>& bounds,
	const Rectangle<int>& previousBounds,
	const Rectangle<int>& /*limits*/,
	bool isStretchingTop,
	bool isStretchingLeft,
	bool isStretchingBottom,
	bool isStretchingRight)
{
	Rectangle<int> toneCoordLimits = m_movingDragMode ? getBoundingBoxFromValues(0, 127, 1, 127) : getBoundingBoxFromValues(0, 128, 1, 128);
	Rectangle<int> sanppedPrevbounds = Rectangle<int>(
		Point<int>(snapX(previousBounds.getX()), snapY(previousBounds.getY())),
		Point<int>(snapX(previousBounds.getRight()), snapY(previousBounds.getBottom())));
	ComponentBoundsConstrainer::checkBounds(bounds, sanppedPrevbounds, toneCoordLimits, isStretchingTop, isStretchingLeft, isStretchingBottom, isStretchingRight);

	// snap and check value constraints
	int keyLower, keyUpper, velLower, velUpper;
	bounds = Rectangle<int>(
		Point<int>(snapX(bounds.getX()), snapY(bounds.getY())), 
		Point<int>(snapX(bounds.getRight()), snapY(bounds.getBottom())));
	getValuesFromBoundingBox(bounds, keyLower, keyUpper, velLower, velUpper);

	bounds = getBoundingBoxFromValues(keyLower, keyUpper, velLower, velUpper);
}

void ToneLimitsConstrainer::getValuesFromBoundingBox(const Rectangle<int>& boundingBox, int& keyLower, int& keyUpper, int &velLower, int &velUpper)
{
	Rectangle<float> newValuesRectangle = boundingBox.toFloat().transformedBy(m_affineTransValuesToCoords.inverted());
	keyLower = (int)roundToInt(newValuesRectangle.getX());			// 0 .. keyUpper
	keyUpper = (int)roundToInt(newValuesRectangle.getRight()) - 1;	// keyLower .. 127 the -1 is because x for right key value is at 128
	velLower = (int)roundToInt(newValuesRectangle.getY());			// 1 .. velUpper
	velUpper = (int)roundToInt(newValuesRectangle.getBottom()) - 1; // velUpper .. 127 the -1 is because < for upper vel value is at 128
}

Rectangle<int> ToneLimitsConstrainer::getBoundingBoxFromValues(int keyLower, int keyUpper, int velLower, int velUpper)
{
	Point<int> newLowerKeyUpperVelocity = Point<float>((float)keyLower, (float)velUpper + 1.0f).transformedBy(m_affineTransValuesToCoords).roundToInt();
	Point<int> newUpperKeyLwerVelocity = Point<float>((float)keyUpper + 1.0f, (float)velLower).transformedBy(m_affineTransValuesToCoords).roundToInt();
	return Rectangle<int>(
		Point<int>((int)newLowerKeyUpperVelocity.getX(), (int)newLowerKeyUpperVelocity.getY()),
		Point<int>((int)newUpperKeyLwerVelocity.getX(), (int)newUpperKeyLwerVelocity.getY()));
}