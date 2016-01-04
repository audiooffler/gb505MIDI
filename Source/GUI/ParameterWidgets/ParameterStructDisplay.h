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

#ifndef __JUCE_HEADER_D8C938B398B8DAE8__
#define __JUCE_HEADER_D8C938B398B8DAE8__

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
class ParameterStructDisplay  : public Slider,
                                public Slider::Listener,
                                public ChangeListener
{
public:
    //==============================================================================
    ParameterStructDisplay (const String &componentName, SynthParts part, bool s34=false);
    ~ParameterStructDisplay();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.

    // TODO: listener for parameters, to register in constructor (part dependet)

    void sliderValueChanged	(Slider* slider);
    void changeListenerCallback(ChangeBroadcaster *source);	// parameter changes of groovebox memory block

    //[/UserMethods]

    void paint (Graphics& g);
    void resized();

    // Binary resources:
    static const char* s12type1none_png;
    static const int s12type1none_pngSize;
    static const char* s12type1no2_png;
    static const int s12type1no2_pngSize;
    static const char* s12type1no1_png;
    static const int s12type1no1_pngSize;
    static const char* s12type1_png;
    static const int s12type1_pngSize;
    static const char* s12type2_png;
    static const int s12type2_pngSize;
    static const char* s12type3_png;
    static const int s12type3_pngSize;
    static const char* s12type4_png;
    static const int s12type4_pngSize;
    static const char* s12type5_png;
    static const int s12type5_pngSize;
    static const char* s12type6_png;
    static const int s12type6_pngSize;
    static const char* s12type7_png;
    static const int s12type7_pngSize;
    static const char* s12type8_png;
    static const int s12type8_pngSize;
    static const char* s12type9_png;
    static const int s12type9_pngSize;
    static const char* s12type10_png;
    static const int s12type10_pngSize;
    static const char* s34type1none_png;
    static const int s34type1none_pngSize;
    static const char* s34type1no4_png;
    static const int s34type1no4_pngSize;
    static const char* s34type1no3_png;
    static const int s34type1no3_pngSize;
    static const char* s34type1_png;
    static const int s34type1_pngSize;
    static const char* s34type2_png;
    static const int s34type2_pngSize;
    static const char* s34type3_png;
    static const int s34type3_pngSize;
    static const char* s34type4_png;
    static const int s34type4_pngSize;
    static const char* s34type5_png;
    static const int s34type5_pngSize;
    static const char* s34type6_png;
    static const int s34type6_pngSize;
    static const char* s34type7_png;
    static const int s34type7_pngSize;
    static const char* s34type8_png;
    static const int s34type8_pngSize;
    static const char* s34type9_png;
    static const int s34type9_pngSize;
    static const char* s34type10_png;
    static const int s34type10_pngSize;


private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    SynthParts m_part;
    bool m_s34; // if true use images for 3 and 4 instead of 1 and 2
	Parameter* m_paramStructTypePtr;
	Parameter* m_param1Or3OnPtr;
    Parameter* m_param2Or4OnPtr;

	Image cachedImage_s12type1none_png;
	Image cachedImage_s12type1no2_png;
	Image cachedImage_s12type1no1_png;
	Image cachedImage_s12type1_png;
	Image cachedImage_s12type2_png;
	Image cachedImage_s12type3_png;
	Image cachedImage_s12type4_png;
	Image cachedImage_s12type5_png;
	Image cachedImage_s12type6_png;
	Image cachedImage_s12type7_png;
	Image cachedImage_s12type8_png;
	Image cachedImage_s12type9_png;
	Image cachedImage_s12type10_png;
    //[/UserVariables]

    //==============================================================================


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (ParameterStructDisplay)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

#endif   // __JUCE_HEADER_D8C938B398B8DAE8__
