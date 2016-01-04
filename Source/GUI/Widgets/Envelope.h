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

#ifndef __JUCE_HEADER_C313BABE1D82994__
#define __JUCE_HEADER_C313BABE1D82994__

//[Headers]     -- You can add your own extra header files here --
#include "JuceHeader.h"
#include "MicroParameterSlider.h"
#include "PanelGroupTransp.h"
//[/Headers]

#include "PanelGroupGrey.h"


//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Introjucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class Envelope  : public Component,
                  public SliderListener
{
public:
    //==============================================================================
    Envelope (const String name, const float minLevel, const float maxLevel, const bool lev4Is0);
    ~Envelope();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    //[/UserMethods]

    void paint (Graphics& g);
    void resized();
    void sliderValueChanged (Slider* sliderThatWasMoved);



private:
    //[UserVariables]   -- You can add your own custom variables in this section.
	class EnvVis : public Component
	{
	public:
		EnvVis(Envelope* envPtr);
		~EnvVis();

		void paint(Graphics& g);
		void resized();
		void mouseMove(const MouseEvent& e);
		void mouseDrag(const MouseEvent& e);
		void mouseWheelMove(const MouseEvent &e, const MouseWheelDetails &wheel);
		void mouseUp(const MouseEvent& e);
		void refreshEnvVisShapes();
	private:
		Envelope* m_envPointer;
		Path m_keyOffVertical;
		Path m_zeroHorizonzal;
		Path m_envelopePath;
		enum MarkerNum
		{
			none = 0,
			m1 = 1,
			m2 = 2,
			m3 = 3,
			sustainKeyOff = 4,
			m4 = 5
		};
		MarkerNum m_highlightedMarker;
		MarkerNum m_draggedMarker;
		int m_dragStartMarkerTime;
		int m_dragStartMarkerLevel;
		float getMarkerX(MarkerNum m);
		float getMarkerY(MarkerNum m);
		float pixelToTime(float x);
		float pixelToLevel(float y);
		MarkerNum getNearMarker(float x, float y, float radius);
		JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(EnvVis)
	};
	String m_name;
	float m_minLevel;
	float m_maxLevel;
	bool m_level4Always0;
    //[/UserVariables]

    //==============================================================================
    ScopedPointer<PanelGroupGrey> m_envelopeGroup2;
    ScopedPointer<Label> m_level3Label;
    ScopedPointer<MicroParameterSlider> m_time1;
    ScopedPointer<Label> m_time1Label;
    ScopedPointer<MicroParameterSlider> m_level1;
    ScopedPointer<MicroParameterSlider> m_time2;
    ScopedPointer<MicroParameterSlider> m_level2;
    ScopedPointer<MicroParameterSlider> m_time3;
    ScopedPointer<Label> m_time3Label;
    ScopedPointer<MicroParameterSlider> m_level3;
    ScopedPointer<MicroParameterSlider> m_time4;
    ScopedPointer<Label> m_time4Label;
    ScopedPointer<MicroParameterSlider> m_level4;
    ScopedPointer<Label> m_timeLabel;
    ScopedPointer<Label> m_levelLabel;
    ScopedPointer<EnvVis> m_envVisComponent;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Envelope)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

#endif   // __JUCE_HEADER_C313BABE1D82994__
