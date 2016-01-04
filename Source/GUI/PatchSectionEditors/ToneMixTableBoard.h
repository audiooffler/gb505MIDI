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

#ifndef __JUCE_HEADER_7B03BA48069593A0__
#define __JUCE_HEADER_7B03BA48069593A0__

//[Headers]     -- You can add your own extra header files here --
#include "JuceHeader.h"
//[/Headers]

#include "ToneMixTableCanvas.h"


//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Introjucer.

    Contained in ToneMixTable, draws the Keyboard (48px high), contains the canvas
                                                                    //[/Comments]
*/
class ToneMixTableBoard  : public Component
{
public:
    //==============================================================================
    ToneMixTableBoard (const String &componentName, SynthParts part);
    ~ToneMixTableBoard();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    ToneMixTableCanvas* getToneMixTableCanvasPtr() {return m_toneMixTableCanvas;}
	void paintOverChildren(Graphics &g);

    //[/UserMethods]

    void paint (Graphics& g);
    void resized();



private:
    //[UserVariables]   -- You can add your own custom variables in this section.
	SynthParts m_part;
    //[/UserVariables]

    //==============================================================================
    ScopedPointer<ToneMixTableCanvas> m_toneMixTableCanvas;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (ToneMixTableBoard)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

#endif   // __JUCE_HEADER_7B03BA48069593A0__
