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

#ifndef __JUCE_HEADER_A109E6FBE9EB3756__
#define __JUCE_HEADER_A109E6FBE9EB3756__

//[Headers]     -- You can add your own extra header files here --
#include "JuceHeader.h"
#include "../../MIDIConnection/GrooveboxConnector.h"
#include "../../GrooveboxMemory/GrooveboxMemoryBlock.h"
//[/Headers]

#include "WaveformsGroup.h"


//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Introjucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class WaveformsAllGroups  : public Component,
                            public Button::Listener,
                            public ChangeListener,
                            public TextEditor::Listener
{
public:
    //==============================================================================
    WaveformsAllGroups (GrooveboxConnector::GrooveboxModel grooveboxModel, SynthParts part, Tone tone);
    ~WaveformsAllGroups();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
	void buttonClicked(Button* button);
	void changeListenerCallback(ChangeBroadcaster *source);	// parameter changes of groovebox memory block
	void addListenerToAllButtons(ButtonListener* listener);
	void textEditorTextChanged(TextEditor& textEditor); // highlightTextEditor
	void tryScrollToSelectedButton();
    //[/UserMethods]

    void paint (Graphics& g);
    void resized();
    void mouseDoubleClick (const MouseEvent& e);
    bool keyPressed (const KeyPress& key);



private:
    //[UserVariables]   -- You can add your own custom variables in this section.
	SynthParts m_part;
	Tone m_tone;
	Parameter* m_waveGroupType;
	Parameter* m_waveGroupId;
	Parameter* m_waveNumber;
	WaveformButton* getFocusedOrFirstWaveformButton();
	Array <WaveformButton*> allButtonReferences;
	WaveformButton* getNext(WaveformButton* buttonToStartFrom, int maxStepSizeWithinGroup = 1, bool tryScrollToGroup = false);	// skips 1 or n (e.g. 10, 32), but going to next group will get the first of the next group
	WaveformButton* getPrev(WaveformButton* buttonToStartFrom, int maxStepSizeWithinGroup = 1, bool tryScrollToGroup = false);  // skips 1 or n (e.g. 10, 32), but going to previous group will get the last of the previous group
	void tryScrollToButtonsGroup(WaveformButton* buttonToScrollTo);
	GrooveboxConnector::GrooveboxModel m_grooveboxModel;
	ScopedPointer<WaveformsGroup> m_waveformsGroupC;
	WaveformButton* select(Waveforms::WaveGroup group, int numInGroup);
    //[/UserVariables]

    //==============================================================================
    ScopedPointer<WaveformsGroup> m_waveformsGroupA;
    ScopedPointer<WaveformsGroup> m_waveformsGroupB;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (WaveformsAllGroups)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

#endif   // __JUCE_HEADER_A109E6FBE9EB3756__
