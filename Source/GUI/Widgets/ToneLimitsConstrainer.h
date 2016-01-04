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

		enum VertivalGridCellPosition {Top, Mid, Bottom};
		enum HorizontalGridCellPosition { Left, Center, Right };

		ToneLimitsConstrainer(int width=0, int  height=0);
		void setSize(int width, int  height);
		int getHeight();
		int getWidth();

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
		float getVelocityStepHeight() { return (float)m_height / 128.0f; }

		Point<float> transformKeyVelocityToCoord(int key, int velocity);
		Point<float> transformCoordToKeyVelocity(Point<float> coordinates);

	private:
		int m_width, m_height;
		// transforms key/velocity value pairs to X / Y coordinates 
		AffineTransform m_affineTransValuesToCoords;
		// transforms X / Y coordinates to key/velocity value pairs
		AffineTransform m_affineTransCoordsToValues;
	};



#endif  // TONELIMITSCONSTRAINER_H_INCLUDED
