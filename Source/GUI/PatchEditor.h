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

#ifndef __JUCE_HEADER_333CB9F29BD29B02__
#define __JUCE_HEADER_333CB9F29BD29B02__

//[Headers]     -- You can add your own extra header files here --
#include "JuceHeader.h"
#include "../GrooveboxMemory/GrooveboxMemoryBlock.h"
#include "ParameterWidgets/ParameterTextEditor.h"
#include "ParameterWidgets/ParameterStructDisplay.h"
#include "ParameterWidgets/ParameterComboBox.h"
#include "ParameterWidgets/MixPartLevelFader.h"
#include "PatchSectionEditors/PatchToneEditorAbstract.h"
#include "PatchSectionEditors/PatchToneEditorAdvanced.h"
#include "PatchSectionEditors/PatchToneEditorOverview.h"
//[/Headers]

#include "GroupWidgets/RectangleGrey.h"
#include "GroupWidgets/PanelGroupGrey.h"
#include "MixerSectionsEditors/MixPartTrack.h"
#include "ParameterWidgets/ParameterLedSwitch.h"
#include "ParameterWidgets/BlackToggle.h"


//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Introjucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class PatchEditor  : public Component,
                     public ButtonListener,
                     public ComboBoxListener
{
public:
    //==============================================================================
    PatchEditor (SynthParts part);
    ~PatchEditor();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    //[/UserMethods]

    void paint (Graphics& g);
    void resized();
    void buttonClicked (Button* buttonThatWasClicked);
    void comboBoxChanged (ComboBox* comboBoxThatHasChanged);

    // Binary resources:
    static const char* pitchBendLever_png;
    static const int pitchBendLever_pngSize;
    static const char* solo_png;
    static const int solo_pngSize;
    static const char* portamento_png;
    static const int portamento_pngSize;
    static const char* tonemixtable_png;
    static const int tonemixtable_pngSize;
    static const char* mixer_png;
    static const int mixer_pngSize;


private:
    //[UserVariables]   -- You can add your own custom variables in this section.
	SynthParts m_part;
	ScopedPointer<PatchToneEditorAbstract> m_toneEditor;
    //[/UserVariables]

    //==============================================================================
    ScopedPointer<RectangleGrey> m_commonGrp3;
    ScopedPointer<RectangleGrey> m_commonGrp2;
    ScopedPointer<PanelGroupGrey> m_mixGrp;
    ScopedPointer<MixPartTrack> m_mixPartTrack;
    ScopedPointer<RectangleGrey> m_commonGrp1;
    ScopedPointer<Label> m_patchNameLabel;
    ScopedPointer<ParameterTextEditor> m_patchNameEditor;
    ScopedPointer<Label> m_voicePriorityLabel;
    ScopedPointer<ParameterStructDisplay> m_struct12DisplaySlider;
    ScopedPointer<ParameterStructDisplay> m_struct34DisplaySlider;
    ScopedPointer<Label> m_struct12Label;
    ScopedPointer<Label> m_boost12Label;
    ScopedPointer<Label> m_struct34Label;
    ScopedPointer<Label> m_boost34Label;
    ScopedPointer<ParameterLedSwitch> m_voicePriorityToggle;
    ScopedPointer<TextWithArrowButton> m_soloLegatoEditButton;
    ScopedPointer<TextWithArrowButton> m_toneMixTableButton;
    ScopedPointer<Label> m_partNoLabel;
    ScopedPointer<ImageButton> imageButton2;
    ScopedPointer<ImageButton> imageButton3;
    ScopedPointer<BlackToggle> m_toneSelectToggle1;
    ScopedPointer<Label> m_toneSelectLabel1;
    ScopedPointer<BlackToggle> m_toneSelectToggle2;
    ScopedPointer<Label> m_toneSelectLabel2;
    ScopedPointer<BlackToggle> m_toneSelectToggle3;
    ScopedPointer<Label> m_toneSelectLabel3;
    ScopedPointer<BlackToggle> m_toneSelectToggle4;
    ScopedPointer<Label> m_toneSelectLabel4;
    ScopedPointer<BlackToggle> m_toneSwitchToggle1;
    ScopedPointer<Label> m_toneSwitchLabel1;
    ScopedPointer<BlackToggle> m_toneSwitchToggle2;
    ScopedPointer<Label> m_toneSwitchLabel2;
    ScopedPointer<BlackToggle> m_toneSwitchToggle3;
    ScopedPointer<Label> m_toneSwitchLabel3;
    ScopedPointer<BlackToggle> m_toneSwitchToggle4;
    ScopedPointer<Label> m_toneSwitchLabel4;
    ScopedPointer<Label> m_toneSelectMasterLabel;
    ScopedPointer<Label> m_toneSwitchLabel;
    ScopedPointer<ImageButton> imageButton4;
    ScopedPointer<ImageButton> imageButton5;
    ScopedPointer<TextButton> m_editOverviewButton;
    ScopedPointer<TextButton> m_editDetailButton;
    ScopedPointer<Label> m_editModeLabel;
    ScopedPointer<Label> m_editModeLabel2;
    ScopedPointer<ParameterComboBox> m_boost12ComboBox;
    ScopedPointer<ParameterComboBox> m_struct12ComboBox;
    ScopedPointer<ParameterComboBox> m_boost34ComboBox;
    ScopedPointer<ParameterComboBox> m_struct34ComboBox;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (PatchEditor)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

#endif   // __JUCE_HEADER_333CB9F29BD29B02__
