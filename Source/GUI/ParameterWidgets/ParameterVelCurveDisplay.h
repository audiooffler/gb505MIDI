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

#ifndef __JUCE_HEADER_6F200A6DD85D7BEE__
#define __JUCE_HEADER_6F200A6DD85D7BEE__

//[Headers]     -- You can add your own extra header files here --
#include "JuceHeader.h"
#include "../../GrooveboxMemory/GrooveboxMemoryBlock.h"
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Introjucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class ParameterVelCurveDisplay  : public Slider,
                                  public Slider::Listener,
                                  public ChangeListener
{
public:
    //==============================================================================
    ParameterVelCurveDisplay (const String &componentName);
    ~ParameterVelCurveDisplay();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.

	void setParameter(Parameter* param);
	Parameter* getParamPtr() { return m_paramVelCurvePtr; }
    void sliderValueChanged	(Slider* slider);
    void changeListenerCallback(ChangeBroadcaster *source);	// parameter changes of groovebox memory block

    //[/UserMethods]

    void paint (Graphics& g);
    void resized();

    // Binary resources:
    static const char* velocityCurve1_png;
    static const int velocityCurve1_pngSize;
    static const char* velocityCurve2_png;
    static const int velocityCurve2_pngSize;
    static const char* velocityCurve3_png;
    static const int velocityCurve3_pngSize;
    static const char* velocityCurve4_png;
    static const int velocityCurve4_pngSize;
    static const char* velocityCurve5_png;
    static const int velocityCurve5_pngSize;
    static const char* velocityCurve6_png;
    static const int velocityCurve6_pngSize;
    static const char* velocityCurve7_png;
    static const int velocityCurve7_pngSize;


private:
    //[UserVariables]   -- You can add your own custom variables in this section.
	Parameter* m_paramVelCurvePtr;

	Image cachedImage_velocityCurve1_png;
	Image cachedImage_velocityCurve2_png;
	Image cachedImage_velocityCurve3_png;
	Image cachedImage_velocityCurve4_png;
	Image cachedImage_velocityCurve5_png;
	Image cachedImage_velocityCurve6_png;
	Image cachedImage_velocityCurve7_png;

    //[/UserVariables]

    //==============================================================================


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (ParameterVelCurveDisplay)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

#endif   // __JUCE_HEADER_6F200A6DD85D7BEE__
