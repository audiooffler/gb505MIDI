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
#include "../../GrooveboxMemory/Waveforms.h"
#include "WaveformButton.h"
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Introjucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class WaveformsGroup  : public Component,
                        public Button::Listener
{
public:
    //==============================================================================
    WaveformsGroup (Waveforms::WaveGroup group);
    ~WaveformsGroup() override;

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
	void buttonClicked(Button* buttonThatWasClicked);
    //[/UserMethods]

    void paint (juce::Graphics& g) override;
    void resized() override;



private:
    //[UserVariables]   -- You can add your own custom variables in this section.
	const int maxRows = 32;
	const int buttonWidth = 100;
	const int buttonHeight = 20;
	const int x0 = 4;
	const int y0 = 10;
	Waveforms::WaveGroup m_group;
	OwnedArray<WaveformButton> m_waveformButtons;
    //[/UserVariables]

    //==============================================================================


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (WaveformsGroup)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

