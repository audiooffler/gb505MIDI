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

#ifndef __JUCE_HEADER_C1EE8D6F95D225A2__
#define __JUCE_HEADER_C1EE8D6F95D225A2__

//[Headers]     -- You can add your own extra header files here --
#include "JuceHeader.h"
#include "../../GrooveboxMemory/Waveforms.h"
#include "../../GrooveboxMemory/SynthPatchesBlock.h"
#include "WaveformsAllGroups.h"
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Introjucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class WaveformBrowser  : public Component,
                         public ButtonListener
{
public:
    //==============================================================================
    WaveformBrowser (SynthParts part, Tone tone, Waveforms::WaveGroup group, int waveIndexInGroup);
    ~WaveformBrowser();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
	WaveformsAllGroups* getWaveformsAllGroupsComponent();
    //[/UserMethods]

    void paint (Graphics& g);
    void resized();
    void buttonClicked (Button* buttonThatWasClicked);



private:
    //[UserVariables]   -- You can add your own custom variables in this section.
	SynthParts m_part;
	Tone m_tone;
	Waveforms::WaveGroup m_initialGroup;
	int m_initialIndexInGroup;
    //[/UserVariables]

    //==============================================================================
    ScopedPointer<Viewport> m_waveformsAllGroupsViewport;
    ScopedPointer<TextButton> m_cancelButton;
    ScopedPointer<TextButton> m_okButton;
    ScopedPointer<TextEditor> m_highlightTextEditor;
    ScopedPointer<Label> m_highlightLabel;
    ScopedPointer<Label> m_prevWaveformLabel;
    ScopedPointer<TextEditor> m_prevWaveformText;
    ScopedPointer<Label> m_prevWaveformLabel2;
    ScopedPointer<TextEditor> m_newWaveformText;
    Path internalPath1;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (WaveformBrowser)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

#endif   // __JUCE_HEADER_C1EE8D6F95D225A2__
