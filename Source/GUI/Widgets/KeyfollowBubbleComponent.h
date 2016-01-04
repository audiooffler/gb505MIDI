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

#ifndef __JUCE_HEADER_299EA64664496AA6__
#define __JUCE_HEADER_299EA64664496AA6__

//[Headers]     -- You can add your own extra header files here --
#include "JuceHeader.h"
#include "ParameterSlider.h"
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Introjucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class KeyfollowBubbleComponent  : public BubbleComponent,
                                  public Slider::Listener
{
public:
    //==============================================================================
    KeyfollowBubbleComponent (ParameterSlider* s);
    ~KeyfollowBubbleComponent();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
	void sliderValueChanged(Slider *slider);

    //[/UserMethods]

    void paint (Graphics& g);
    void resized();



private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    ParameterSlider* m_owner;

    void getContentSize (int &width, int &height);
    void paintContent (Graphics &g, int width, int height);

	class IntArraySorter {
	public:
		int compareElements(int first, int second)
		{
			if (first < second)return -1;
			if (first > second)return 1;
			return 0;
		}
	};

	// creates a pre-rendered image (stored in m_preRenderedDiagram)
	void loadSvg();

	ScopedPointer<XmlElement> m_svgXmlElement;
	AffineTransform m_valueToSvgCoords;
	AffineTransform m_SvgCoordsToComponentCoords;
	Image m_preRenderedDiagram;
    //[/UserVariables]

    //==============================================================================


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (KeyfollowBubbleComponent)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

#endif   // __JUCE_HEADER_299EA64664496AA6__
