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
#include "../../GrooveboxMemory/OverallMemoryBlock.h"
//[/Headers]

#include "RhyFxSendEditor.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
extern OverallMemoryBlock* grooveboxMemory;
//[/MiscUserDefs]

//==============================================================================
RhyFxSendEditor::RhyFxSendEditor (const String &componentName, int toneNumber)
    : Component (componentName),  m_toneNumber(toneNumber)
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    addAndMakeVisible (m_fxGrp = new PanelGroupGrey ("fxGrp", getName()));
    addAndMakeVisible (m_mfxLabel = new Label ("mfxLabel",
                                               TRANS("MFX")));
    m_mfxLabel->setFont (Font (12.00f, Font::bold));
    m_mfxLabel->setJustificationType (Justification::centred);
    m_mfxLabel->setEditable (false, false, false);
    m_mfxLabel->setColour (Label::textColourId, Colours::black);
    m_mfxLabel->setColour (TextEditor::textColourId, Colours::black);
    m_mfxLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_delayLabel = new Label ("delayLabel",
                                                 TRANS("DELAY")));
    m_delayLabel->setFont (Font (12.00f, Font::bold));
    m_delayLabel->setJustificationType (Justification::centred);
    m_delayLabel->setEditable (false, false, false);
    m_delayLabel->setColour (Label::textColourId, Colours::black);
    m_delayLabel->setColour (TextEditor::textColourId, Colours::black);
    m_delayLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_reverbLabel = new Label ("reverbLabel",
                                                  TRANS("REVERB")));
    m_reverbLabel->setFont (Font (12.00f, Font::bold));
    m_reverbLabel->setJustificationType (Justification::centred);
    m_reverbLabel->setEditable (false, false, false);
    m_reverbLabel->setColour (Label::textColourId, Colours::black);
    m_reverbLabel->setColour (TextEditor::textColourId, Colours::black);
    m_reverbLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_mfxGrab = new GrabSwitch ("0A"));
    addAndMakeVisible (m_delaySlider = new Knob ("0C"));
    m_delaySlider->setRange (0, 127, 1);
    m_delaySlider->setSliderStyle (Slider::RotaryHorizontalVerticalDrag);
    m_delaySlider->setTextBoxStyle (Slider::NoTextBox, false, 48, 16);
    m_delaySlider->addListener (this);

    addAndMakeVisible (m_ReverbSlider = new Knob ("0D"));
    m_ReverbSlider->setRange (0, 127, 1);
    m_ReverbSlider->setSliderStyle (Slider::RotaryHorizontalVerticalDrag);
    m_ReverbSlider->setTextBoxStyle (Slider::NoTextBox, false, 48, 16);
    m_ReverbSlider->addListener (this);

    addAndMakeVisible (m_imageButton = new ImageButton ("imageButton"));
    m_imageButton->setButtonText (String());

    m_imageButton->setImages (false, true, true,
                              ImageCache::getFromMemory (mixer_png, mixer_pngSize), 1.000f, Colour (0x4340454a),
                              Image(), 1.000f, Colour (0x4340454a),
                              Image(), 1.000f, Colour (0x4340454a));

    //[UserPreSize]
    setupParameters(toneNumber);
    //[/UserPreSize]

    setSize (84, 332);


    //[Constructor] You can add your own custom stuff here..
    //[/Constructor]
}

RhyFxSendEditor::~RhyFxSendEditor()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    m_fxGrp = nullptr;
    m_mfxLabel = nullptr;
    m_delayLabel = nullptr;
    m_reverbLabel = nullptr;
    m_mfxGrab = nullptr;
    m_delaySlider = nullptr;
    m_ReverbSlider = nullptr;
    m_imageButton = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void RhyFxSendEditor::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
#if JUCE_MSVC
	g;
#endif
    //[/UserPrePaint]

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void RhyFxSendEditor::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    m_fxGrp->setBounds (0, 0, getWidth() - 0, getHeight() - 0);
    m_mfxLabel->setBounds ((getWidth() / 2) - (54 / 2), 168, 54, 12);
    m_delayLabel->setBounds ((getWidth() / 2) - (64 / 2), 96, 64, 12);
    m_reverbLabel->setBounds ((getWidth() / 2) - (64 / 2), 24, 64, 12);
    m_mfxGrab->setBounds ((getWidth() / 2) - (54 / 2), 176, 54, 49);
    m_delaySlider->setBounds ((getWidth() / 2) - (48 / 2), 108, 48, 48);
    m_ReverbSlider->setBounds ((getWidth() / 2) - (48 / 2), 36, 48, 48);
    m_imageButton->setBounds (3, 1, 16, 16);
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void RhyFxSendEditor::sliderValueChanged (Slider* sliderThatWasMoved)
{
    //[UsersliderValueChanged_Pre]
    //[/UsersliderValueChanged_Pre]

    if (sliderThatWasMoved == m_delaySlider)
    {
        //[UserSliderCode_m_delaySlider] -- add your slider handling code here..
        //[/UserSliderCode_m_delaySlider]
    }
    else if (sliderThatWasMoved == m_ReverbSlider)
    {
        //[UserSliderCode_m_ReverbSlider] -- add your slider handling code here..
        //[/UserSliderCode_m_ReverbSlider]
    }

    //[UsersliderValueChanged_Post]
    //[/UsersliderValueChanged_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
void RhyFxSendEditor::setupParameters(int toneNumber)
{
	if (grooveboxMemory == nullptr) return;
	if (toneNumber >= 35 && toneNumber <= 98)
	{
		if (grooveboxMemory != nullptr)
		{
			if (RhythmSetBlock* rhyhtmSet = grooveboxMemory->getRhythmSetBlock())
			{
				if (RhythmNoteBlock* noteBlock = rhyhtmSet->getRhythmNoteBlockPtr((uint8)toneNumber))
				{
					m_toneNumber = toneNumber;
					m_ReverbSlider->setParameter(noteBlock->getParameter(0x39));
					m_delaySlider->setParameter(noteBlock->getParameter(0x38));
					m_mfxGrab->setParameter(noteBlock->getParameter(0x36));
				}
			}
		}
	}
}
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Introjucer information section --

    This is where the Introjucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="RhyFxSendEditor" componentName=""
                 parentClasses="public Component" constructorParams="const String &amp;componentName, int toneNumber"
                 variableInitialisers="Component (componentName),  m_toneNumber(toneNumber)"
                 snapPixels="4" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="1" initialWidth="84" initialHeight="332">
  <BACKGROUND backgroundColour="0"/>
  <JUCERCOMP name="fxGrp" id="52e00682f746b888" memberName="m_fxGrp" virtualName="PanelGroupGrey"
             explicitFocusOrder="0" pos="0 0 0M 0M" sourceFile="../GroupWidgets/PanelGroupGrey.cpp"
             constructorParams="&quot;fxGrp&quot;, getName() "/>
  <LABEL name="mfxLabel" id="f7600c3cc150c941" memberName="m_mfxLabel"
         virtualName="" explicitFocusOrder="0" pos="0Cc 168 54 12" textCol="ff000000"
         edTextCol="ff000000" edBkgCol="0" labelText="MFX" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="12" bold="1" italic="0" justification="36"/>
  <LABEL name="delayLabel" id="e3598cb93aa83446" memberName="m_delayLabel"
         virtualName="" explicitFocusOrder="0" pos="0Cc 96 64 12" textCol="ff000000"
         edTextCol="ff000000" edBkgCol="0" labelText="DELAY" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="12" bold="1" italic="0" justification="36"/>
  <LABEL name="reverbLabel" id="88bae54666436ac4" memberName="m_reverbLabel"
         virtualName="" explicitFocusOrder="0" pos="0Cc 24 64 12" textCol="ff000000"
         edTextCol="ff000000" edBkgCol="0" labelText="REVERB" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="12" bold="1" italic="0" justification="36"/>
  <JUCERCOMP name="0A" id="3d47dada4f5d9d7f" memberName="m_mfxGrab" virtualName="GrabSwitch"
             explicitFocusOrder="0" pos="0Cc 176 54 49" sourceFile="../ParameterWidgets/GrabSwitch.cpp"
             constructorParams="&quot;0A&quot;"/>
  <SLIDER name="0C" id="b38e1510f0f1e212" memberName="m_delaySlider" virtualName="Knob"
          explicitFocusOrder="0" pos="0Cc 108 48 48" min="0" max="127"
          int="1" style="RotaryHorizontalVerticalDrag" textBoxPos="NoTextBox"
          textBoxEditable="1" textBoxWidth="48" textBoxHeight="16" skewFactor="1"/>
  <SLIDER name="0D" id="36532340fc1495b4" memberName="m_ReverbSlider" virtualName="Knob"
          explicitFocusOrder="0" pos="0Cc 36 48 48" min="0" max="127" int="1"
          style="RotaryHorizontalVerticalDrag" textBoxPos="NoTextBox" textBoxEditable="1"
          textBoxWidth="48" textBoxHeight="16" skewFactor="1"/>
  <IMAGEBUTTON name="imageButton" id="f18ffef17196cb40" memberName="m_imageButton"
               virtualName="" explicitFocusOrder="0" pos="3 1 16 16" buttonText=""
               connectedEdges="0" needsCallback="0" radioGroupId="0" keepProportions="1"
               resourceNormal="mixer_png" opacityNormal="1" colourNormal="4340454a"
               resourceOver="" opacityOver="1" colourOver="4340454a" resourceDown=""
               opacityDown="1" colourDown="4340454a"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif

//==============================================================================
// Binary resources - be careful not to edit any of these sections!

// JUCER_RESOURCE: mixer_png, 237, "../../../Resources/PatchEditSectionIcons/mixer.png"
static const unsigned char resource_RhyFxSendEditor_mixer_png[] = { 137,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,0,16,0,0,0,16,8,6,0,0,0,31,243,255,97,0,0,0,1,115,82,71,66,0,174,206,28,233,0,0,0,
6,98,75,71,68,0,255,0,255,0,255,160,189,167,147,0,0,0,9,112,72,89,115,0,0,11,19,0,0,11,19,1,0,154,156,24,0,0,0,7,116,73,77,69,7,223,1,3,21,23,50,215,208,54,137,0,0,0,109,73,68,65,84,56,203,173,83,65,14,
192,32,8,107,9,255,255,114,119,217,140,58,117,64,70,98,148,3,180,208,74,73,184,163,61,130,65,0,240,174,152,201,6,2,64,43,22,63,12,100,139,174,187,92,221,105,97,85,228,106,131,215,168,182,160,171,15,228,
97,103,254,39,3,78,183,34,254,240,130,246,3,160,5,232,242,100,182,170,140,165,17,122,253,183,42,48,153,195,102,103,101,63,147,175,236,153,217,197,5,106,27,26,44,105,0,198,59,0,0,0,0,73,69,78,68,174,66,
96,130,0,0};

const char* RhyFxSendEditor::mixer_png = (const char*) resource_RhyFxSendEditor_mixer_png;
const int RhyFxSendEditor::mixer_pngSize = 237;


//[EndFile] You can add extra defines here...
//[/EndFile]
