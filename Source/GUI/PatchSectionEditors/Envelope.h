/*
  ==============================================================================

  This is an automatically generated GUI class created by the Projucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Projucer version: 7.0.2

  ------------------------------------------------------------------------------

  The Projucer is part of the JUCE library.
  Copyright (c) 2020 - Raw Material Software Limited.

  ==============================================================================
*/

#pragma once

//[Headers]     -- You can add your own extra header files here --
#include "JuceHeader.h"
#include "../ParameterWidgets/MicroParameterSlider.h"
#include "../../GrooveboxMemory/SynthPatchesBlock.h"
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Introjucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class Envelope  : public Component,
                  public ChangeListener,
                  public juce::Slider::Listener
{
public:
    //==============================================================================
    Envelope (AllParts part, int toneNumber, EnvelopeTypes type, bool fullSize);
    ~Envelope() override;

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
	void changeListenerCallback(ChangeBroadcaster *source) override;
	void setupParameters(AllParts part, int toneNumber); // allowed toneNumber values are Tone1 = 0x1000, Tone2 = 0x1200, Tone3 = 0x1400, Tone4 = 0x1600 for synth parts or 35..98 for rhythm part
    //[/UserMethods]

    void paint (juce::Graphics& g) override;
    void resized() override;
    void sliderValueChanged (juce::Slider* sliderThatWasMoved) override;



private:
    //[UserVariables]   -- You can add your own custom variables in this section.
	class EnvVis : public Component
	{
	public:
		EnvVis(Envelope* envPtr, EnvelopeTypes type);
		~EnvVis();

		void paint(Graphics& g);
		void resized();
		void mouseMove(const MouseEvent& e);
		void mouseDrag(const MouseEvent& e);
		void mouseWheelMove(const MouseEvent &e, const MouseWheelDetails &wheel);
		void mouseUp(const MouseEvent& e);
		void refreshEnvVisShapes();
	private:
		EnvelopeTypes m_type;
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
	bool m_fullSize;
	float m_minLevel;
	float m_maxLevel;
	bool m_level4Always0;
	AllParts m_part;
	//Tone m_tone;
	int m_toneNumber;
	EnvelopeTypes m_type;
	Parameter* m_timePrm1;
	Parameter* m_timePrm2;
	Parameter* m_timePrm3;
	Parameter* m_timePrm4;
	Parameter* m_levelPrm1;
	Parameter* m_levelPrm2;
	Parameter* m_levelPrm3;
	Parameter* m_levelPrm4;
    //[/UserVariables]

    //==============================================================================
    std::unique_ptr<juce::Label> m_level3Label;
    std::unique_ptr<MicroParameterSlider> m_time1;
    std::unique_ptr<juce::Label> m_time1Label;
    std::unique_ptr<MicroParameterSlider> m_level1;
    std::unique_ptr<MicroParameterSlider> m_time2;
    std::unique_ptr<MicroParameterSlider> m_level2;
    std::unique_ptr<MicroParameterSlider> m_time3;
    std::unique_ptr<juce::Label> m_time3Label;
    std::unique_ptr<MicroParameterSlider> m_level3;
    std::unique_ptr<MicroParameterSlider> m_time4;
    std::unique_ptr<juce::Label> m_time4Label;
    std::unique_ptr<MicroParameterSlider> m_level4;
    std::unique_ptr<juce::Label> m_timeLabel;
    std::unique_ptr<juce::Label> m_levelLabel;
    std::unique_ptr<EnvVis> m_envVisComponent;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Envelope)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

