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

#ifndef __JUCE_HEADER_DE40BE4A0F656E90__
#define __JUCE_HEADER_DE40BE4A0F656E90__

//[Headers]     -- You can add your own extra header files here --
#include "JuceHeader.h"
//[/Headers]

#include "ToneMixTableTone.h"
#include "ToneMixTableToneVeloXFade.h"


//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Introjucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class ToneMixTableCanvas  : public Component,
                            public ComponentDragger
{
public:
    //==============================================================================
    ToneMixTableCanvas (const String &componentName);
    ~ToneMixTableCanvas();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
	ToneLimitsConstrainer* getToneLimitsConstrainerPtr() { return m_dragTonesConstrainer; };
	enum Tones {Tone1, Tone2, Tone3, Tone4 };
	ToneMixTableTone* getToneMixTableTone(Tones toneSelection) { return toneSelection==Tone1?m_tone1:(toneSelection==Tone2?m_tone2:(toneSelection==Tone3?m_tone3:m_tone4)); }
	ToneMixTableToneVeloXFade* getToneMixTableXFade(Tones toneSelection) { return toneSelection == Tone1 ? m_tone1XFade : (toneSelection == Tone2 ? m_tone2XFade : (toneSelection == Tone3 ? m_tone3XFade : m_tone4XFade)); }
    //[/UserMethods]

    void paint (Graphics& g);
    void resized();
    void mouseDown (const MouseEvent& e);
    void mouseDrag (const MouseEvent& e);



private:
    //[UserVariables]   -- You can add your own custom variables in this section.
	ScopedPointer<ToneLimitsConstrainer> m_dragTonesConstrainer;
    //[/UserVariables]

    //==============================================================================
    ScopedPointer<ToneMixTableTone> m_tone1;
    ScopedPointer<ToneMixTableTone> m_tone2;
    ScopedPointer<ToneMixTableTone> m_tone3;
    ScopedPointer<ToneMixTableTone> m_tone4;
    ScopedPointer<ToneMixTableToneVeloXFade> m_tone1XFade;
    ScopedPointer<ToneMixTableToneVeloXFade> m_tone2XFade;
    ScopedPointer<ToneMixTableToneVeloXFade> m_tone3XFade;
    ScopedPointer<ToneMixTableToneVeloXFade> m_tone4XFade;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (ToneMixTableCanvas)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

#endif   // __JUCE_HEADER_DE40BE4A0F656E90__
