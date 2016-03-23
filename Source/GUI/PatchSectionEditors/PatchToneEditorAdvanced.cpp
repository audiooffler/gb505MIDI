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

//[Headers] You can add your own extra header files here...
//[/Headers]

#include "PatchToneEditorAdvanced.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
PatchToneEditorAdvanced::PatchToneEditorAdvanced (SynthParts part, Tone tone)
    : m_part (part),
      m_tone (tone)
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    addAndMakeVisible (m_amp = new AmpEditorAdvanced ("AMP", m_part, m_tone));
    addAndMakeVisible (m_filter = new FilterEditorAdvanced ("FILTER", m_part, m_tone));
    addAndMakeVisible (m_pitch = new PitchEditorAdvanced ("PITCH", m_part, m_tone));
    addAndMakeVisible (m_lfo1 = new LfoEditorAdvanced ("LFO", m_part, m_tone, false));
    addAndMakeVisible (m_lfo2 = new LfoEditorAdvanced ("LFO", m_part, m_tone, true));
    addAndMakeVisible (m_controlMatrix = new PatchControllerMatrixEditor ("CONTROL MATRIX", m_part, m_tone));
    addAndMakeVisible (m_fxm = new FxmEditor ("FXM", m_part, m_tone));
    addAndMakeVisible (m_delay = new ToneDelayEditor ("DELAY", m_part, m_tone));
    addAndMakeVisible (m_wave = new WaveEditor ("WAVE", (AllParts) m_part, m_tone));

    //[UserPreSize]
    //[/UserPreSize]

    setSize (1244, 572);


    //[Constructor] You can add your own custom stuff here..
    //[/Constructor]
}

PatchToneEditorAdvanced::~PatchToneEditorAdvanced()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    m_amp = nullptr;
    m_filter = nullptr;
    m_pitch = nullptr;
    m_lfo1 = nullptr;
    m_lfo2 = nullptr;
    m_controlMatrix = nullptr;
    m_fxm = nullptr;
    m_delay = nullptr;
    m_wave = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void PatchToneEditorAdvanced::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
	#ifdef JUCE_MSVC
	g;
	#endif
    //[/UserPrePaint]

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void PatchToneEditorAdvanced::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    m_amp->setBounds (868, 0, 376, 400);
    m_filter->setBounds (488, 0, 376, 400);
    m_pitch->setBounds (108, 0, 376, 400);
    m_lfo1->setBounds (108, 404, 304, 168);
    m_lfo2->setBounds (416, 404, 304, 168);
    m_controlMatrix->setBounds (724, 404, 520, 168);
    m_fxm->setBounds (0, 312, 104, 108);
    m_delay->setBounds (0, 424, 104, 148);
    m_wave->setBounds (0, 0, 104, 136);
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

<JUCER_COMPONENT documentType="Component" className="PatchToneEditorAdvanced"
                 componentName="" parentClasses="public PatchToneEditorAbstract"
                 constructorParams="SynthParts part, Tone tone" variableInitialisers="m_part (part),&#10;m_tone (tone)"
                 snapPixels="4" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="1" initialWidth="1244" initialHeight="572">
  <BACKGROUND backgroundColour="0"/>
  <JUCERCOMP name="amp" id="8967d26b44494c0c" memberName="m_amp" virtualName=""
             explicitFocusOrder="0" pos="868 0 376 400" sourceFile="AmpEditorAdvanced.cpp"
             constructorParams="&quot;AMP&quot;, m_part, m_tone"/>
  <JUCERCOMP name="filter" id="24ccf964906b3d92" memberName="m_filter" virtualName=""
             explicitFocusOrder="0" pos="488 0 376 400" sourceFile="FilterEditorAdvanced.cpp"
             constructorParams="&quot;FILTER&quot;, m_part, m_tone"/>
  <JUCERCOMP name="pitch" id="40e1a57b38902512" memberName="m_pitch" virtualName=""
             explicitFocusOrder="0" pos="108 0 376 400" sourceFile="PitchEditorAdvanced.cpp"
             constructorParams="&quot;PITCH&quot;, m_part, m_tone"/>
  <JUCERCOMP name="lfo1" id="bd92e80a5eddb70a" memberName="m_lfo1" virtualName=""
             explicitFocusOrder="0" pos="108 404 304 168" sourceFile="LfoEditorAdvanced.cpp"
             constructorParams="&quot;LFO&quot;, m_part, m_tone, false"/>
  <JUCERCOMP name="lfo2" id="f4e7393c36d04316" memberName="m_lfo2" virtualName=""
             explicitFocusOrder="0" pos="416 404 304 168" sourceFile="LfoEditorAdvanced.cpp"
             constructorParams="&quot;LFO&quot;, m_part, m_tone, true"/>
  <JUCERCOMP name="" id="8539adf5ee9f16e9" memberName="m_controlMatrix" virtualName=""
             explicitFocusOrder="0" pos="724 404 520 168" sourceFile="PatchControllerMatrixEditor.cpp"
             constructorParams="&quot;CONTROL MATRIX&quot;, m_part, m_tone"/>
  <JUCERCOMP name="fxm" id="137c15769c7a126a" memberName="m_fxm" virtualName=""
             explicitFocusOrder="0" pos="0 312 104 108" sourceFile="FxmEditor.cpp"
             constructorParams="&quot;FXM&quot;, m_part, m_tone"/>
  <JUCERCOMP name="delay" id="889ed3bbaa380bd0" memberName="m_delay" virtualName=""
             explicitFocusOrder="0" pos="0 424 104 148" sourceFile="ToneDelayEditor.cpp"
             constructorParams="&quot;DELAY&quot;, m_part, m_tone"/>
  <JUCERCOMP name="wave" id="18daa831771a006a" memberName="m_wave" virtualName=""
             explicitFocusOrder="0" pos="0 0 104 136" sourceFile="WaveEditor.cpp"
             constructorParams="&quot;WAVE&quot;, (AllParts) m_part, m_tone"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
