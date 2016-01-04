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

#ifndef __JUCE_HEADER_205EF2E16857CF8A__
#define __JUCE_HEADER_205EF2E16857CF8A__

//[Headers]     -- You can add your own extra header files here --
#include "JuceHeader.h"
#include "ParameterSlider.h"
#include "../../GrooveboxMemory/GrooveboxMemoryBlock.h"
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Introjucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class MixPartLevelFader  : public ParameterSlider
{
public:
    //==============================================================================
    MixPartLevelFader (const String &componentName);
    ~MixPartLevelFader();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
	class MixSliderLookAndFeel : public LookAndFeel_V3
	{
	public:
		MixSliderLookAndFeel();
		~MixSliderLookAndFeel();
		int getSliderThumbRadius(Slider &slider) override;
		void drawLinearSliderBackground(Graphics &g, int x, int y, int width, int height, float, float, float, const Slider::SliderStyle, Slider &) override;
		void drawLinearSliderThumb(Graphics &g, int x, int y, int width, int height, float sliderPos, float minSliderPos, float maxSliderPos, const Slider::SliderStyle style, Slider &slider) override;
	private:
		Image m_verticalHandleImg;
		Image m_horizontalHandleImg;
	};
	// hiding original function (but calling that by using ((Slider*)this)->setTextBoxStyle)
	void setTextBoxStyle(TextEntryBoxPosition newPosition, bool isReadOnly, int textEntryBoxWidth, int textEntryBoxHeight);
    //[/UserMethods]

    void paint (Graphics& g);
    void resized();

    // Binary resources:
    static const char* mixSliderThumb_png;
    static const int mixSliderThumb_pngSize;


private:
    //[UserVariables]   -- You can add your own custom variables in this section.
	ScopedPointer<MixSliderLookAndFeel> m_lookAndFeel;
    //[/UserVariables]

    //==============================================================================


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MixPartLevelFader)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

#endif   // __JUCE_HEADER_205EF2E16857CF8A__
