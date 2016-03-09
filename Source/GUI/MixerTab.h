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

#ifndef __JUCE_HEADER_126EEE97ABDC9308__
#define __JUCE_HEADER_126EEE97ABDC9308__

//[Headers]     -- You can add your own extra header files here --
#include "JuceHeader.h"
#include "../GrooveboxMemory/GrooveboxMemoryBlock.h"
#include "ParameterWidgets/MixPartLevelFader.h"
#include "GroupWidgets/PanelGroupDark.h"
#include "ParameterWidgets/BigGreenToggle.h"
//[/Headers]

#include "GroupWidgets/PanelGroupDark.h"
#include "GroupWidgets/RectangleGrey.h"
#include "MixerSectionsEditors/MixPartTrack.h"
#include "GroupWidgets/RectangleDark.h"
#include "MixerSectionsEditors/MixRhyTrack.h"
#include "ParameterWidgets/BigGreenToggle.h"
#include "MixerSectionsEditors/MFxEditor.h"
#include "MixerSectionsEditors/ReverbEditor.h"
#include "MixerSectionsEditors/DelayEditor.h"


//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Introjucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class MixerTab  : public Component
{
public:
    //==============================================================================
    MixerTab ();
    ~MixerTab();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    //[/UserMethods]

    void paint (Graphics& g) override;
    void resized() override;

    // Binary resources:
    static const char* partNameR_png;
    static const int partNameR_pngSize;
    static const char* partName1_png;
    static const int partName1_pngSize;
    static const char* partName2_png;
    static const int partName2_pngSize;
    static const char* partName3_png;
    static const int partName3_pngSize;
    static const char* partName4_png;
    static const int partName4_pngSize;
    static const char* partName5_png;
    static const int partName5_pngSize;
    static const char* partName6_png;
    static const int partName6_pngSize;
    static const char* partName7_png;
    static const int partName7_pngSize;


private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    //[/UserVariables]

    //==============================================================================
    ScopedPointer<PanelGroupDark> m_mixerGroup;
    ScopedPointer<RectangleGrey> component2;
    ScopedPointer<MixPartTrack> m_MixPart7;
    ScopedPointer<RectangleDark> m_blackStripePartNames;
    ScopedPointer<Label> m_labelBD;
    ScopedPointer<Label> m_labelSD;
    ScopedPointer<Label> m_labelHH;
    ScopedPointer<Label> m_labelCLP;
    ScopedPointer<Label> m_labelCYM;
    ScopedPointer<Label> m_labelTOMPERC;
    ScopedPointer<Label> m_labelHIT;
    ScopedPointer<Label> m_labelOTHERS;
    ScopedPointer<MixRhyTrack> m_MixPartR;
    ScopedPointer<MixPartTrack> m_MixPart1;
    ScopedPointer<MixPartTrack> m_MixPart2;
    ScopedPointer<MixPartTrack> m_MixPart3;
    ScopedPointer<MixPartTrack> m_MixPart4;
    ScopedPointer<MixPartTrack> m_MixPart5;
    ScopedPointer<MixPartTrack> m_MixPart6;
    ScopedPointer<Label> m_panLabel;
    ScopedPointer<Label> m_levelLabel;
    ScopedPointer<Label> m_panLabel2;
    ScopedPointer<Label> m_keyShiftLabel;
    ScopedPointer<Label> m_reverbLabel;
    ScopedPointer<Label> m_mFxLabel;
    ScopedPointer<BigGreenToggle> m_toggleBD;
    ScopedPointer<BigGreenToggle> m_toggleSD;
    ScopedPointer<BigGreenToggle> m_toggleHH;
    ScopedPointer<BigGreenToggle> m_toggleCLP;
    ScopedPointer<BigGreenToggle> m_toggleCYM;
    ScopedPointer<BigGreenToggle> m_toggleTOMPERC;
    ScopedPointer<BigGreenToggle> m_toggleHIT;
    ScopedPointer<BigGreenToggle> m_toggleOTHERS;
    ScopedPointer<RectangleDark> m_darkSepRect1;
    ScopedPointer<RectangleDark> m_darkSepRect2;
    ScopedPointer<RectangleDark> m_darkSepRect3;
    ScopedPointer<RectangleDark> m_darkSepRect4;
    ScopedPointer<RectangleDark> m_darkSepRect5;
    ScopedPointer<RectangleDark> m_darkSepRect6;
    ScopedPointer<RectangleDark> m_darkSepRect7;
    ScopedPointer<Label> m_dlyLabel;
    ScopedPointer<MFXEditor> m_mFxEditor;
    ScopedPointer<ReverbEditor> m_reverbEditor;
    ScopedPointer<DelayEditor> m_delayEditor;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MixerTab)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

#endif   // __JUCE_HEADER_126EEE97ABDC9308__
