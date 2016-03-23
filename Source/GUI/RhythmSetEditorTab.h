/*
  ==============================================================================

  This is an automatically generated GUI class created by the Introjucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Introjucer version: 4.1.0

  ------------------------------------------------------------------------------

  The Introjucer is part of the JUCE library - "Jules' Utility Class Extensions"
  Copyright (c) 2015 - ROLI Ltd.

  ==============================================================================
*/

#ifndef __JUCE_HEADER_350181E3DEFC17E4__
#define __JUCE_HEADER_350181E3DEFC17E4__

//[Headers]     -- You can add your own extra header files here --
#include "JuceHeader.h"
//[/Headers]

#include "GroupWidgets/RectangleGrey.h"
#include "PatchSectionEditors/WaveEditor.h"
#include "RhythmSectionEditors/RhyPitchEditor.h"
#include "RhythmSectionEditors/RhyFilterEditor.h"
#include "RhythmSectionEditors/RhyAmpEditor.h"
#include "RhythmSectionEditors/RhySetKeyboardWithList.h"
#include "GroupWidgets/RectangleDark.h"
#include "GroupWidgets/PanelGroupGrey.h"
#include "MixerSectionsEditors/MixRhyTrack.h"


//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Introjucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class RhythmSetEditorTab  : public Component,
                            public ChangeListener,
                            public ButtonListener
{
public:
    //==============================================================================
    RhythmSetEditorTab ();
    ~RhythmSetEditorTab();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    void changeListenerCallback(ChangeBroadcaster* source) override;
    //[/UserMethods]

    void paint (Graphics& g) override;
    void resized() override;
    void buttonClicked (Button* buttonThatWasClicked) override;

    // Binary resources:
    static const char* mixer_png;
    static const int mixer_pngSize;


private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    uint8 m_currentKey=35;
    //[/UserVariables]

    //==============================================================================
    ScopedPointer<RectangleGrey> m_commonGrp4;
    ScopedPointer<Label> m_partNoLabel;
    ScopedPointer<Label> m_patchNameLabel;
    ScopedPointer<ParameterTextEditor> m_patchNameEditor;
    ScopedPointer<Label> m_selectKeyLabel;
    ScopedPointer<WaveEditor> m_wave;
    ScopedPointer<RhyPitchEditor> m_rhyPitchEditor;
    ScopedPointer<RhyFilterEditor> m_rhyFilterEditor;
    ScopedPointer<RhyAmpEditor> m_rhyAmpEditor;
    ScopedPointer<RhySetKeyboardWithList> m_rhySetKeyboardWithList;
    ScopedPointer<RectangleDark> m_darkSepRect3;
    ScopedPointer<PanelGroupGrey> m_mixGrp;
    ScopedPointer<MixRhyTrack> m_mixRhyTrack;
    ScopedPointer<ImageButton> imageButton5;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (RhythmSetEditorTab)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

#endif   // __JUCE_HEADER_350181E3DEFC17E4__
