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

#ifndef __JUCE_HEADER_29173123C28440C4__
#define __JUCE_HEADER_29173123C28440C4__

//[Headers]     -- You can add your own extra header files here --
#include "JuceHeader.h"
#include "ToneLimitsConstrainer.h"
#include "../../GrooveboxMemory/GrooveboxMemoryBlock.h"
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Introjucer.

    Resizable, controlling / controlled by parameters
                                                                    //[/Comments]
*/
class ToneMixTableTone  : public Component,
                          public ChangeListener,
                          public AsyncUpdater
{
public:
    //==============================================================================
    ToneMixTableTone (const String &componentName, ToneLimitsConstrainer* toneLimitsConstrainer, SynthParts part, Tone tone);
    ~ToneMixTableTone();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
	void handleAsyncUpdate();
	void changeListenerCallback(ChangeBroadcaster* source);
	void setDragMoveMode(bool moveModeOn = true);
    //[/UserMethods]

    void paint (Graphics& g);
    void resized();
    void moved();
    void mouseMove (const MouseEvent& e);
    void mouseEnter (const MouseEvent& e);
    void mouseExit (const MouseEvent& e);



private:
    //[UserVariables]   -- You can add your own custom variables in this section.
	bool m_changedByParameterValues;
	ToneLimitsConstrainer* m_toneLimitsConstrainer;
	SynthParts m_part;
	Tone m_tone;
	Parameter* m_keyboardRangeUpperPrm;
	Parameter* m_keyboardRangeLowerPrm;
	Parameter* m_velocityRangeUpperPrm;
	Parameter* m_velocityRangeLowerPrm;
	//uint8 m_velocityRangesSwitch = 0;
	//uint8 m_veloCrossfade = 20;
	//uint8 m_velocityRangeLower=40;
	//uint8 m_velocityRangeUpper=100;
	//uint8 m_keyRangeLower=30;
	//uint8 m_keyRangeUpper=90;
	//uint8 m_toneLevel = 100; // 0 - 127
	//uint8 m_biasPointKey = 60; // 0 - 127 (C -1 ... G  9)
	//uint8 m_biasDirection = 2; // 0 - 3: LOWER, UPPER, LOW&UP, ALL
	//uint8 m_biasLevel = 2; // 0 - 14: -100, -70, -50, -40, -30, -20, -10, 0, +10, +20, +30, +40, +50, +70, +100
    //[/UserVariables]

    //==============================================================================
    ScopedPointer<ResizableBorderComponent> m_resizableBorder;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (ToneMixTableTone)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

#endif   // __JUCE_HEADER_29173123C28440C4__
