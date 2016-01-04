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

//[Headers] You can add your own extra header files here...
//[/Headers]

#include "PatchToneEditorOverview.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
PatchToneEditorOverview::PatchToneEditorOverview (SynthParts part)
    : m_part (part)
{
    addAndMakeVisible (m_PatchTone1Editor = new PatchToneEditor (m_part, Tone1));
    addAndMakeVisible (m_PatchTone2Editor = new PatchToneEditor (m_part, Tone2));
    addAndMakeVisible (m_PatchTone3Editor = new PatchToneEditor (m_part, Tone3));
    addAndMakeVisible (m_PatchTone4Editor = new PatchToneEditor (m_part, Tone4));

    //[UserPreSize]
    //[/UserPreSize]

    setSize (1244, 572);


    //[Constructor] You can add your own custom stuff here..
    //[/Constructor]
}

PatchToneEditorOverview::~PatchToneEditorOverview()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    m_PatchTone1Editor = nullptr;
    m_PatchTone2Editor = nullptr;
    m_PatchTone3Editor = nullptr;
    m_PatchTone4Editor = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void PatchToneEditorOverview::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void PatchToneEditorOverview::resized()
{
    m_PatchTone1Editor->setBounds (0, 0, 304, 572);
    m_PatchTone2Editor->setBounds (312, 0, 304, 572);
    m_PatchTone3Editor->setBounds (628, 0, 304, 572);
    m_PatchTone4Editor->setBounds (940, 0, 304, 572);
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Introjucer information section --

    This is where the Introjucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="PatchToneEditorOverview"
                 componentName="" parentClasses="public PatchToneEditorAbstract"
                 constructorParams="SynthParts part" variableInitialisers="m_part (part)"
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="1" initialWidth="1244" initialHeight="572">
  <BACKGROUND backgroundColour="0"/>
  <JUCERCOMP name="PatchTone1Editor" id="c943eee91b0a45c0" memberName="m_PatchTone1Editor"
             virtualName="" explicitFocusOrder="0" pos="0 0 304 572" sourceFile="PatchToneEditor.cpp"
             constructorParams="m_part, Tone1"/>
  <JUCERCOMP name="PatchTone2Editor" id="d0849d42a1f5c148" memberName="m_PatchTone2Editor"
             virtualName="" explicitFocusOrder="0" pos="312 0 304 572" sourceFile="PatchToneEditor.cpp"
             constructorParams="m_part, Tone2"/>
  <JUCERCOMP name="PatchTone3Editor" id="6f4e6fd98fb60ba5" memberName="m_PatchTone3Editor"
             virtualName="" explicitFocusOrder="0" pos="628 0 304 572" sourceFile="PatchToneEditor.cpp"
             constructorParams="m_part, Tone3"/>
  <JUCERCOMP name="PatchTone4Editor" id="5cdf405cd9b26b65" memberName="m_PatchTone4Editor"
             virtualName="" explicitFocusOrder="0" pos="940 0 304 572" sourceFile="PatchToneEditor.cpp"
             constructorParams="m_part, Tone4"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
