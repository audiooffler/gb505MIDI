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

#ifndef __JUCE_HEADER_F564F45A41836806__
#define __JUCE_HEADER_F564F45A41836806__

//[Headers]     -- You can add your own extra header files here --
#include "JuceHeader.h"
#include "../../GrooveboxMemory/Waveforms.h"
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Introjucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class WaveformButton  : public TextButton
{
public:
    //==============================================================================
    WaveformButton ();
    ~WaveformButton();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
	WaveformButton(Waveforms::WaveGroup waveGroup, int waveformIndexInGroup);

	void colourChanged() override;

	Waveforms::WaveGroup getGroup() { return m_group; }
	int getIndexInGroup() { return m_numInGroup; }

	void setHighLight(bool highlight);
	bool getHighLight();
    //[/UserMethods]

    void paint (Graphics& g) override;
    void resized() override;
    void mouseEnter (const MouseEvent& e) override;
    void mouseDoubleClick (const MouseEvent& e) override;
    bool keyPressed (const KeyPress& key) override;



private:
    //[UserVariables]   -- You can add your own custom variables in this section.
	Waveforms::WaveGroup m_group;
	int m_numInGroup;
	bool m_highlight = false;
    //[/UserVariables]

    //==============================================================================


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (WaveformButton)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

#endif   // __JUCE_HEADER_F564F45A41836806__
