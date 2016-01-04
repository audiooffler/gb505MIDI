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

#ifndef __JUCE_HEADER_CA8BE5C963AF2628__
#define __JUCE_HEADER_CA8BE5C963AF2628__

//[Headers]     -- You can add your own extra header files here --
#include "JuceHeader.h"
#include "PatchToneEditorAbstract.h"
//[/Headers]

#include "PatchToneEditor.h"


//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Introjucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class PatchToneEditorOverview  : public PatchToneEditorAbstract
{
public:
    //==============================================================================
    PatchToneEditorOverview (SynthParts part);
    ~PatchToneEditorOverview();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    //[/UserMethods]

    void paint (Graphics& g);
    void resized();



private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    SynthParts m_part;
    //[/UserVariables]

    //==============================================================================
    ScopedPointer<PatchToneEditor> m_PatchTone1Editor;
    ScopedPointer<PatchToneEditor> m_PatchTone2Editor;
    ScopedPointer<PatchToneEditor> m_PatchTone3Editor;
    ScopedPointer<PatchToneEditor> m_PatchTone4Editor;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (PatchToneEditorOverview)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

#endif   // __JUCE_HEADER_CA8BE5C963AF2628__
