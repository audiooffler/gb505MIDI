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

#ifndef __JUCE_HEADER_92D3C6058F64568A__
#define __JUCE_HEADER_92D3C6058F64568A__

//[Headers]     -- You can add your own extra header files here --
#include "JuceHeader.h"
#include "PatchToneEditorAbstract.h"
//[/Headers]

#include "AmpEditorAdvanced.h"
#include "FilterEditorAdvanced.h"
#include "PitchEditorAdvanced.h"
#include "LfoEditorAdvanced.h"
#include "PatchControllerMatrixEditor.h"
#include "FxmEditor.h"
#include "ToneDelayEditor.h"
#include "WaveEditor.h"


//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Introjucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class PatchToneEditorAdvanced  : public PatchToneEditorAbstract
{
public:
    //==============================================================================
    PatchToneEditorAdvanced (SynthParts part, Tone tone);
    ~PatchToneEditorAdvanced();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    //[/UserMethods]

    void paint (Graphics& g) override;
    void resized() override;



private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    SynthParts m_part;
	Tone m_tone;
    //[/UserVariables]

    //==============================================================================
    ScopedPointer<AmpEditorAdvanced> m_amp;
    ScopedPointer<FilterEditorAdvanced> m_filter;
    ScopedPointer<PitchEditorAdvanced> m_pitch;
    ScopedPointer<LfoEditorAdvanced> m_lfo1;
    ScopedPointer<LfoEditorAdvanced> m_lfo2;
    ScopedPointer<PatchControllerMatrixEditor> m_controlMatrix;
    ScopedPointer<FxmEditor> m_fxm;
    ScopedPointer<ToneDelayEditor> m_delay;
    ScopedPointer<WaveEditor> m_wave;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (PatchToneEditorAdvanced)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

#endif   // __JUCE_HEADER_92D3C6058F64568A__
