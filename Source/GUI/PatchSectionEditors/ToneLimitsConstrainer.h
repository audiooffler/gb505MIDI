/*
  ==============================================================================

    ToneLimitsConstrainer.h
    Created: 29 Sep 2014 12:24:31pm
    Author:  Spindler

  ==============================================================================
*/

#ifndef TONELIMITSCONSTRAINER_H_INCLUDED
#define TONELIMITSCONSTRAINER_H_INCLUDED

#include "JuceHeader.h"

class ToneLimitsConstrainer : public ComponentBoundsConstrainer
	{
	public:
		ToneLimitsConstrainer(int width=0, int  height=0);
		void setSize(int width, int  height);
		int getHeight() { return m_height; }
		int getWidth() { return m_width; }

		/** This callback changes the given coordinates to impose whatever the current
		constraints are set to be.

		@param bounds               the target position that should be examined and adjusted
		@param previousBounds       the component's current size
		@param limits               the region in which the component can be positioned
		@param isStretchingTop      whether the top edge of the component is being resized
		@param isStretchingLeft     whether the left edge of the component is being resized
		@param isStretchingBottom   whether the bottom edge of the component is being resized
		@param isStretchingRight    whether the right edge of the component is being resized
		*/
		void checkBounds(Rectangle<int>& bounds,
			const Rectangle<int>& previousBounds,
			const Rectangle<int>& limits,
			bool isStretchingTop,
			bool isStretchingLeft,
			bool isStretchingBottom,
			bool isStretchingRight);

		float getKeyWidth() { return (float)m_width / 128.0f; }
		float getVelocityStepHeight() { return (float)m_height / 127.0f; }

		AffineTransform getAffineTransformValuesToPixelcoords() { return m_affineTransValuesToCoords; };

		void getValuesFromBoundingBox(const Rectangle<int>& boundingBox, int& keyLower, int& keyUpper, int &velLower, int &velUpper);
		Rectangle<int> getBoundingBoxFromValues(int keyLower, int keyUpper, int velLower, int velUpper);

		void setDragMoveMode(bool moveModeOn){ m_movingDragMode = moveModeOn; }

	private:
		int m_width, m_height;
		// transforms key/velocity value pairs to X / Y coordinates 
		AffineTransform m_affineTransValuesToCoords;
		bool m_movingDragMode;
		int snapX(int x);
		int snapY(int y);
	};



#endif  // TONELIMITSCONSTRAINER_H_INCLUDED
