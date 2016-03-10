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
#include "../../GrooveboxMemory/QuickSysExBlock.h"
//[/Headers]

#include "MixRhyTrack.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...

extern OverallMemoryBlock* grooveboxMemory;
extern QuickSysExBlock* quickSysEx;

//[/MiscUserDefs]

//==============================================================================
MixRhyTrack::MixRhyTrack ()
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    addAndMakeVisible (m_mfxLabel2 = new Label ("mfxLabel",
                                                TRANS("RHY")));
    m_mfxLabel2->setFont (Font (12.00f, Font::bold));
    m_mfxLabel2->setJustificationType (Justification::centredRight);
    m_mfxLabel2->setEditable (false, false, false);
    m_mfxLabel2->setColour (Label::textColourId, Colours::black);
    m_mfxLabel2->setColour (TextEditor::textColourId, Colours::black);
    m_mfxLabel2->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_mfxLabel = new Label ("mfxLabel",
                                               TRANS("MFX")));
    m_mfxLabel->setFont (Font (12.00f, Font::bold));
    m_mfxLabel->setJustificationType (Justification::centredLeft);
    m_mfxLabel->setEditable (false, false, false);
    m_mfxLabel->setColour (Label::textColourId, Colours::black);
    m_mfxLabel->setColour (TextEditor::textColourId, Colours::black);
    m_mfxLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_mfxGrab = new GrabSwitch ("0A"));
    addAndMakeVisible (m_mixLevel = new MixPartLevelFader ("06"));
    m_mixLevel->setRange (0, 127, 1);
    m_mixLevel->setSliderStyle (Slider::LinearVertical);
    m_mixLevel->setTextBoxStyle (Slider::TextBoxBelow, false, 32, 16);
    m_mixLevel->addListener (this);

    addAndMakeVisible (m_panSlider = new Knob ("07"));
    m_panSlider->setRange (-64, 63, 1);
    m_panSlider->setSliderStyle (Slider::RotaryHorizontalVerticalDrag);
    m_panSlider->setTextBoxStyle (Slider::NoTextBox, false, 48, 16);
    m_panSlider->addListener (this);

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

    addAndMakeVisible (m_keyShiftSlider = new MicroParameterSlider ("08"));
    m_keyShiftSlider->setRange (-48, 48, 1);
    m_keyShiftSlider->setSliderStyle (Slider::LinearBar);
    m_keyShiftSlider->setTextBoxStyle (Slider::TextBoxLeft, false, 64, 20);
    m_keyShiftSlider->setColour (Slider::backgroundColourId, Colour (0xfff2f59b));
    m_keyShiftSlider->setColour (Slider::thumbColourId, Colour (0xffc4c86d));
    m_keyShiftSlider->addListener (this);

    addAndMakeVisible (m_muteToggle = new BigOrangeToggle());
    addAndMakeVisible (imageButton = new ImageButton ("new button"));
    imageButton->addListener (this);

    imageButton->setImages (false, true, true,
                            ImageCache::getFromMemory (partNameR_png, partNameR_pngSize), 1.000f, Colours::white,
                            Image(), 1.000f, Colour (0x00000000),
                            Image(), 1.000f, Colour (0x00000000));
    addAndMakeVisible (m_panLabel = new Label ("panLabel",
                                               TRANS("PAN")));
    m_panLabel->setFont (Font (12.00f, Font::bold));
    m_panLabel->setJustificationType (Justification::centred);
    m_panLabel->setEditable (false, false, false);
    m_panLabel->setColour (Label::textColourId, Colours::black);
    m_panLabel->setColour (TextEditor::textColourId, Colours::black);
    m_panLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_keyShiftLabel = new Label ("keyShiftLabel",
                                                    TRANS("KEY SHIFT")));
    m_keyShiftLabel->setFont (Font (12.00f, Font::bold));
    m_keyShiftLabel->setJustificationType (Justification::centred);
    m_keyShiftLabel->setEditable (false, false, false);
    m_keyShiftLabel->setColour (Label::textColourId, Colours::black);
    m_keyShiftLabel->setColour (TextEditor::textColourId, Colours::black);
    m_keyShiftLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_reverbLabel = new Label ("reverbLabel",
                                                  TRANS("REVERB")));
    m_reverbLabel->setFont (Font (12.00f, Font::bold));
    m_reverbLabel->setJustificationType (Justification::centred);
    m_reverbLabel->setEditable (false, false, false);
    m_reverbLabel->setColour (Label::textColourId, Colours::black);
    m_reverbLabel->setColour (TextEditor::textColourId, Colours::black);
    m_reverbLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_delayLabel = new Label ("delayLabel",
                                                 TRANS("DELAY")));
    m_delayLabel->setFont (Font (12.00f, Font::bold));
    m_delayLabel->setJustificationType (Justification::centred);
    m_delayLabel->setEditable (false, false, false);
    m_delayLabel->setColour (Label::textColourId, Colours::black);
    m_delayLabel->setColour (TextEditor::textColourId, Colours::black);
    m_delayLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_patchNameEditor = new ParameterTextLabel ("patchNameEditor"));
    addAndMakeVisible (m_voiceResvSlider = new MicroParameterSlider ("voiceResvSlider"));
    m_voiceResvSlider->setRange (0, 64, 1);
    m_voiceResvSlider->setSliderStyle (Slider::LinearBar);
    m_voiceResvSlider->setTextBoxStyle (Slider::TextBoxLeft, false, 64, 20);
    m_voiceResvSlider->setColour (Slider::backgroundColourId, Colour (0xfff2f59b));
    m_voiceResvSlider->setColour (Slider::thumbColourId, Colour (0xffc4c86d));
    m_voiceResvSlider->addListener (this);

    addAndMakeVisible (m_voiceResvLabel = new Label ("voiceResvLabel",
                                                     TRANS("VOICE RESV")));
    m_voiceResvLabel->setFont (Font (12.00f, Font::bold));
    m_voiceResvLabel->setJustificationType (Justification::centred);
    m_voiceResvLabel->setEditable (false, false, false);
    m_voiceResvLabel->setColour (Label::textColourId, Colours::black);
    m_voiceResvLabel->setColour (TextEditor::textColourId, Colours::black);
    m_voiceResvLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_mfx_RHYtoggle = new SmallGreenToggle());

    //[UserPreSize]
	m_patchNameEditor->setParameter1(grooveboxMemory->getRhythmSetBlock()->getRhythmSetCommonBlockPtr()->getParameter(0x0));
	m_voiceResvSlider->setParameter(grooveboxMemory->getPartInfoBlock()->getPartInfoCommonBlockPtr()->getParameter(0x39));

	m_mfxGrab->addListener(this);
	m_mfx_RHYtoggle->addListener(this);
	imageButton->setVisible(false);
	if (grooveboxMemory != nullptr)
	{
		if (PartInfoPartBlock* p = grooveboxMemory->getPartInfoBlock()->getPartInfoPartBlockPtr(PartR))
		{
			m_mixLevel->setParameter(p->getParameter(0x06));
			m_panSlider->setParameter(p->getParameter((uint16)m_panSlider->getName().getHexValue32()));
			m_keyShiftSlider->setParameter(p->getParameter((uint16)m_keyShiftSlider->getName().getHexValue32()));
			m_delaySlider->setParameter(p->getParameter((uint16)m_delaySlider->getName().getHexValue32()));
			m_ReverbSlider->setParameter(p->getParameter((uint16)m_ReverbSlider->getName().getHexValue32()));
			p->getParameter(0x0A)->addChangeListener(this);
		}
		if (QuickSysExSequencerBlock* s = quickSysEx->getQuickSysExSequencerBlock())
		{
			m_muteToggle->setParameter(s->getParameter(PartR));
		}
	}
	m_mfx_RHYtoggle->setTooltip(TRANS("Switch M-FX for Rhythm Notes instead of the whole R-Part"));
    //[/UserPreSize]

    setSize (72, 620);


    //[Constructor] You can add your own custom stuff here..
    //[/Constructor]
}

MixRhyTrack::~MixRhyTrack()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    m_mfxLabel2 = nullptr;
    m_mfxLabel = nullptr;
    m_mfxGrab = nullptr;
    m_mixLevel = nullptr;
    m_panSlider = nullptr;
    m_delaySlider = nullptr;
    m_ReverbSlider = nullptr;
    m_keyShiftSlider = nullptr;
    m_muteToggle = nullptr;
    imageButton = nullptr;
    m_panLabel = nullptr;
    m_keyShiftLabel = nullptr;
    m_reverbLabel = nullptr;
    m_delayLabel = nullptr;
    m_patchNameEditor = nullptr;
    m_voiceResvSlider = nullptr;
    m_voiceResvLabel = nullptr;
    m_mfx_RHYtoggle = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void MixRhyTrack::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    //[UserPaint] Add your own custom painting code here..
    g.setColour (Colours::white);
    int y(getHeight()-55);
    int x(getWidth()/2-12);
    int w(24);
    int h(18);
	g.drawImageWithin(ImageCache::getFromMemory(partNameR_png, partNameR_pngSize), x, y, w, h, RectanglePlacement::centred | RectanglePlacement::onlyReduceInSize, true);

    //[/UserPaint]
}

void MixRhyTrack::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    m_mfxLabel2->setBounds ((getWidth() / 2) + 16 - (48 / 2), 150, 48, 12);
    m_mfxLabel->setBounds ((getWidth() / 2) + -14 - (36 / 2), 150, 36, 12);
    m_mfxGrab->setBounds ((getWidth() / 2) - (54 / 2), 156, 54, 49);
    m_mixLevel->setBounds ((getWidth() / 2) - (32 / 2), getHeight() - 64 - (getHeight() - 404), 32, getHeight() - 404);
    m_panSlider->setBounds ((getWidth() / 2) - (48 / 2), 288, 48, 48);
    m_delaySlider->setBounds ((getWidth() / 2) - (48 / 2), 94, 48, 48);
    m_ReverbSlider->setBounds ((getWidth() / 2) - (48 / 2), 34, 48, 48);
    m_keyShiftSlider->setBounds ((getWidth() / 2) - (56 / 2), 220, 56, 16);
    m_muteToggle->setBounds ((getWidth() / 2) - (27 / 2), getHeight() - 1 - 27, 27, 27);
    imageButton->setBounds ((getWidth() / 2) - (24 / 2), getHeight() - 55, 24, 18);
    m_panLabel->setBounds (0, 276, getWidth() - 0, 12);
    m_keyShiftLabel->setBounds (0, 207, getWidth() - 0, 12);
    m_reverbLabel->setBounds (0, 24, getWidth() - 0, 12);
    m_delayLabel->setBounds (0, 84, getWidth() - 0, 12);
    m_patchNameEditor->setBounds ((getWidth() / 2) - (72 / 2), 0, 72, 20);
    m_voiceResvSlider->setBounds ((getWidth() / 2) - (56 / 2), 256, 56, 16);
    m_voiceResvLabel->setBounds (-4, 242, getWidth() - -8, 12);
    m_mfx_RHYtoggle->setBounds (((getWidth() / 2) - (54 / 2)) + 54 - 7, 163, 12, 12);
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void MixRhyTrack::sliderValueChanged (Slider* sliderThatWasMoved)
{
    //[UsersliderValueChanged_Pre]
    //[/UsersliderValueChanged_Pre]

    if (sliderThatWasMoved == m_mixLevel)
    {
        //[UserSliderCode_m_mixLevel] -- add your slider handling code here..
        //[/UserSliderCode_m_mixLevel]
    }
    else if (sliderThatWasMoved == m_panSlider)
    {
        //[UserSliderCode_m_panSlider] -- add your slider handling code here..
        //[/UserSliderCode_m_panSlider]
    }
    else if (sliderThatWasMoved == m_delaySlider)
    {
        //[UserSliderCode_m_delaySlider] -- add your slider handling code here..
        //[/UserSliderCode_m_delaySlider]
    }
    else if (sliderThatWasMoved == m_ReverbSlider)
    {
        //[UserSliderCode_m_ReverbSlider] -- add your slider handling code here..
        //[/UserSliderCode_m_ReverbSlider]
    }
    else if (sliderThatWasMoved == m_keyShiftSlider)
    {
        //[UserSliderCode_m_keyShiftSlider] -- add your slider handling code here..
        //[/UserSliderCode_m_keyShiftSlider]
    }
    else if (sliderThatWasMoved == m_voiceResvSlider)
    {
        //[UserSliderCode_m_voiceResvSlider] -- add your slider handling code here..
        //[/UserSliderCode_m_voiceResvSlider]
    }

    //[UsersliderValueChanged_Post]
    //[/UsersliderValueChanged_Post]
}

void MixRhyTrack::buttonClicked (Button* buttonThatWasClicked)
{
    //[UserbuttonClicked_Pre]
    //[/UserbuttonClicked_Pre]

    if (buttonThatWasClicked == imageButton)
    {
        //[UserButtonCode_imageButton] -- add your button handler code here..
        //[/UserButtonCode_imageButton]
    }

    //[UserbuttonClicked_Post]
	else if (buttonThatWasClicked == m_mfxGrab || buttonThatWasClicked == m_mfx_RHYtoggle)
	{
		if (m_mfxGrab->getToggleState())
		{
			if (m_mfx_RHYtoggle->getToggleState())
			{
				grooveboxMemory->getPartInfoBlock()->getPartInfoPartBlockPtr(PartR)->getParameter(0x0A)->setValue(4,Parameter::GuiWidget);
			}
			else
			{
				grooveboxMemory->getPartInfoBlock()->getPartInfoPartBlockPtr(PartR)->getParameter(0x0A)->setValue(1, Parameter::GuiWidget);
			}
		}
		else
		{
			grooveboxMemory->getPartInfoBlock()->getPartInfoPartBlockPtr(PartR)->getParameter(0x0A)->setValue(0, Parameter::GuiWidget);
		}

	}
    //[/UserbuttonClicked_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
void MixRhyTrack::changeListenerCallback(ChangeBroadcaster* source)
{
	if (dynamic_cast<Parameter*>(source) == grooveboxMemory->getPartInfoBlock()->getPartInfoPartBlockPtr(PartR)->getParameter(0x0A))
	{
		uint8 v = grooveboxMemory->getPartInfoBlock()->getPartInfoPartBlockPtr(PartR)->getParameter(0x0A)->getValue();
		if (v == 0)
		{
			m_mfxGrab->setToggleState(false, dontSendNotification);
		}
		else if (v==1)
		{
			m_mfxGrab->setToggleState(true, dontSendNotification);
			m_mfx_RHYtoggle->setToggleState(false, dontSendNotification);
		}
		else if(v == 4)
		{
			m_mfxGrab->setToggleState(true, dontSendNotification);
			m_mfx_RHYtoggle->setToggleState(true, dontSendNotification);
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

<JUCER_COMPONENT documentType="Component" className="MixRhyTrack" componentName=""
                 parentClasses="public Component, public ChangeListener" constructorParams=""
                 variableInitialisers="" snapPixels="4" snapActive="1" snapShown="1"
                 overlayOpacity="0.330" fixedSize="1" initialWidth="72" initialHeight="620">
  <BACKGROUND backgroundColour="0"/>
  <LABEL name="mfxLabel" id="3b53bc579e5fcd0b" memberName="m_mfxLabel2"
         virtualName="" explicitFocusOrder="0" pos="16Cc 150 48 12" textCol="ff000000"
         edTextCol="ff000000" edBkgCol="0" labelText="RHY" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="12" bold="1" italic="0" justification="34"/>
  <LABEL name="mfxLabel" id="f7600c3cc150c941" memberName="m_mfxLabel"
         virtualName="" explicitFocusOrder="0" pos="-14Cc 150 36 12" textCol="ff000000"
         edTextCol="ff000000" edBkgCol="0" labelText="MFX" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="12" bold="1" italic="0" justification="33"/>
  <JUCERCOMP name="mfxGrab" id="3d47dada4f5d9d7f" memberName="m_mfxGrab" virtualName=""
             explicitFocusOrder="0" pos="0Cc 156 54 49" sourceFile="../ParameterWidgets/GrabSwitch.cpp"
             constructorParams="&quot;0A&quot;"/>
  <SLIDER name="06" id="1b5918ef3651954f" memberName="m_mixLevel" virtualName="MixPartLevelFader"
          explicitFocusOrder="0" pos="0Cc 64Rr 32 404M" min="0" max="127"
          int="1" style="LinearVertical" textBoxPos="TextBoxBelow" textBoxEditable="1"
          textBoxWidth="32" textBoxHeight="16" skewFactor="1"/>
  <SLIDER name="07" id="8f70d251e0e8426e" memberName="m_panSlider" virtualName="Knob"
          explicitFocusOrder="0" pos="0Cc 288 48 48" min="-64" max="63"
          int="1" style="RotaryHorizontalVerticalDrag" textBoxPos="NoTextBox"
          textBoxEditable="1" textBoxWidth="48" textBoxHeight="16" skewFactor="1"/>
  <SLIDER name="0C" id="b38e1510f0f1e212" memberName="m_delaySlider" virtualName="Knob"
          explicitFocusOrder="0" pos="0Cc 94 48 48" min="0" max="127" int="1"
          style="RotaryHorizontalVerticalDrag" textBoxPos="NoTextBox" textBoxEditable="1"
          textBoxWidth="48" textBoxHeight="16" skewFactor="1"/>
  <SLIDER name="0D" id="36532340fc1495b4" memberName="m_ReverbSlider" virtualName="Knob"
          explicitFocusOrder="0" pos="0Cc 34 48 48" min="0" max="127" int="1"
          style="RotaryHorizontalVerticalDrag" textBoxPos="NoTextBox" textBoxEditable="1"
          textBoxWidth="48" textBoxHeight="16" skewFactor="1"/>
  <SLIDER name="08" id="2b89b2c11e2ad524" memberName="m_keyShiftSlider"
          virtualName="MicroParameterSlider" explicitFocusOrder="0" pos="0Cc 220 56 16"
          bkgcol="fff2f59b" thumbcol="ffc4c86d" min="-48" max="48" int="1"
          style="LinearBar" textBoxPos="TextBoxLeft" textBoxEditable="1"
          textBoxWidth="64" textBoxHeight="20" skewFactor="1"/>
  <JUCERCOMP name="muteToggle" id="bb56ebeded4ccc44" memberName="m_muteToggle"
             virtualName="" explicitFocusOrder="0" pos="-0.5Cc 1Rr 27 27"
             sourceFile="../ParameterWidgets/BigOrangeToggle.cpp" constructorParams=""/>
  <IMAGEBUTTON name="new button" id="168089c13a9f22fd" memberName="imageButton"
               virtualName="" explicitFocusOrder="0" pos="0Cc 55R 24 18" buttonText="new button"
               connectedEdges="0" needsCallback="1" radioGroupId="0" keepProportions="1"
               resourceNormal="partNameR_png" opacityNormal="1" colourNormal="ffffffff"
               resourceOver="" opacityOver="1" colourOver="0" resourceDown=""
               opacityDown="1" colourDown="0"/>
  <LABEL name="panLabel" id="39a07dbc337265d" memberName="m_panLabel"
         virtualName="" explicitFocusOrder="0" pos="0 276 0M 12" textCol="ff000000"
         edTextCol="ff000000" edBkgCol="0" labelText="PAN" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="12" bold="1" italic="0" justification="36"/>
  <LABEL name="keyShiftLabel" id="2d5f9ed3d1da8b8d" memberName="m_keyShiftLabel"
         virtualName="" explicitFocusOrder="0" pos="0 207 0M 12" textCol="ff000000"
         edTextCol="ff000000" edBkgCol="0" labelText="KEY SHIFT" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="12" bold="1" italic="0" justification="36"/>
  <LABEL name="reverbLabel" id="88bae54666436ac4" memberName="m_reverbLabel"
         virtualName="" explicitFocusOrder="0" pos="0 24 0M 12" textCol="ff000000"
         edTextCol="ff000000" edBkgCol="0" labelText="REVERB" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="12" bold="1" italic="0" justification="36"/>
  <LABEL name="delayLabel" id="e3598cb93aa83446" memberName="m_delayLabel"
         virtualName="" explicitFocusOrder="0" pos="0 84 0M 12" textCol="ff000000"
         edTextCol="ff000000" edBkgCol="0" labelText="DELAY" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="12" bold="1" italic="0" justification="36"/>
  <JUCERCOMP name="" id="a7e0a63fcc688db0" memberName="m_patchNameEditor"
             virtualName="" explicitFocusOrder="0" pos="0Cc 0 72 20" sourceFile="../ParameterWidgets/ParameterTextLabel.cpp"
             constructorParams="&quot;patchNameEditor&quot;"/>
  <SLIDER name="voiceResvSlider" id="a048beb2c0778056" memberName="m_voiceResvSlider"
          virtualName="MicroParameterSlider" explicitFocusOrder="0" pos="0Cc 256 56 16"
          bkgcol="fff2f59b" thumbcol="ffc4c86d" min="0" max="64" int="1"
          style="LinearBar" textBoxPos="TextBoxLeft" textBoxEditable="1"
          textBoxWidth="64" textBoxHeight="20" skewFactor="1"/>
  <LABEL name="voiceResvLabel" id="6fc13f78eb63f1be" memberName="m_voiceResvLabel"
         virtualName="" explicitFocusOrder="0" pos="-4 242 -8M 12" textCol="ff000000"
         edTextCol="ff000000" edBkgCol="0" labelText="VOICE RESV" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="12" bold="1" italic="0" justification="36"/>
  <JUCERCOMP name="mfx_RHY" id="71afd96cb7e4d50f" memberName="m_mfx_RHYtoggle"
             virtualName="" explicitFocusOrder="0" pos="7R 163 12 12" posRelativeX="3d47dada4f5d9d7f"
             sourceFile="../ParameterWidgets/SmallGreenToggle.cpp" constructorParams=""/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif

//==============================================================================
// Binary resources - be careful not to edit any of these sections!

// JUCER_RESOURCE: partNameR_png, 423, "../../../Resources/LookAndFeel/PartNameR.png"
static const unsigned char resource_MixRhyTrack_partNameR_png[] = { 137,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,0,32,0,0,0,24,8,6,0,0,0,155,83,255,52,0,0,0,4,115,66,73,84,8,8,8,8,124,8,100,136,0,
0,0,9,112,72,89,115,0,0,22,38,0,0,22,38,1,228,235,5,157,0,0,0,25,116,69,88,116,83,111,102,116,119,97,114,101,0,119,119,119,46,105,110,107,115,99,97,112,101,46,111,114,103,155,238,60,26,0,0,1,36,73,68,
65,84,72,137,197,150,177,74,3,65,16,134,191,145,32,146,202,70,20,69,44,196,74,176,21,76,227,59,248,58,118,62,128,47,144,7,200,67,104,43,168,96,21,2,86,166,73,117,22,41,36,141,226,111,225,94,216,93,60,
171,219,217,129,225,152,127,224,230,191,153,217,255,214,36,81,211,6,0,102,246,12,28,22,172,211,0,15,192,181,164,38,201,132,14,204,1,57,248,2,216,145,68,235,27,133,190,184,203,246,129,155,24,24,132,231,
12,88,22,42,122,6,88,20,95,38,217,184,29,37,28,24,147,142,97,233,61,130,143,255,146,222,59,0,191,93,112,37,176,149,197,175,113,208,234,192,4,216,43,68,96,148,197,119,73,228,172,3,247,192,176,166,14,220,
74,90,197,128,73,194,204,230,192,81,132,127,3,159,61,20,220,36,213,128,21,112,46,105,186,70,58,70,48,233,73,3,14,128,247,236,221,99,183,17,72,90,144,47,29,92,153,217,186,43,30,59,240,148,197,219,192,105,
77,2,16,29,77,15,2,47,192,87,53,2,225,216,77,51,248,194,141,64,176,124,12,199,102,182,235,73,224,241,15,108,228,73,160,115,17,219,27,81,67,250,215,234,251,118,52,3,222,128,97,132,157,64,144,226,154,246,
3,162,3,35,71,135,173,101,129,0,0,0,0,73,69,78,68,174,66,96,130,0,0};

const char* MixRhyTrack::partNameR_png = (const char*) resource_MixRhyTrack_partNameR_png;
const int MixRhyTrack::partNameR_pngSize = 423;

// JUCER_RESOURCE: partName1_png, 277, "../../../Resources/LookAndFeel/PartName1.png"
static const unsigned char resource_MixRhyTrack_partName1_png[] = { 137,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,0,32,0,0,0,24,8,6,0,0,0,155,83,255,52,0,0,0,4,115,66,73,84,8,8,8,8,124,8,100,136,0,
0,0,9,112,72,89,115,0,0,22,37,0,0,22,37,1,73,82,36,240,0,0,0,25,116,69,88,116,83,111,102,116,119,97,114,101,0,119,119,119,46,105,110,107,115,99,97,112,101,46,111,114,103,155,238,60,26,0,0,0,146,73,68,
65,84,72,137,237,150,177,13,194,64,16,4,119,44,18,18,122,113,19,36,36,46,1,209,16,237,184,21,58,112,104,68,224,192,193,146,162,7,89,127,24,225,228,86,218,228,239,247,52,186,251,224,177,173,45,213,68,46,
3,39,96,44,60,0,61,112,252,138,192,118,181,37,117,146,188,224,75,164,159,237,216,4,42,116,5,246,145,64,20,224,33,233,246,226,169,168,31,36,181,161,142,209,145,21,43,57,235,125,13,221,63,87,48,174,204,
255,252,13,36,64,2,36,64,2,36,64,2,36,64,88,187,149,249,89,210,253,195,89,181,216,250,91,254,4,124,118,180,26,84,31,31,91,0,0,0,0,73,69,78,68,174,66,96,130,0,0};

const char* MixRhyTrack::partName1_png = (const char*) resource_MixRhyTrack_partName1_png;
const int MixRhyTrack::partName1_pngSize = 277;

// JUCER_RESOURCE: partName2_png, 409, "../../../Resources/LookAndFeel/PartName2.png"
static const unsigned char resource_MixRhyTrack_partName2_png[] = { 137,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,0,32,0,0,0,24,8,6,0,0,0,155,83,255,52,0,0,0,4,115,66,73,84,8,8,8,8,124,8,100,136,0,
0,0,9,112,72,89,115,0,0,22,37,0,0,22,37,1,73,82,36,240,0,0,0,25,116,69,88,116,83,111,102,116,119,97,114,101,0,119,119,119,46,105,110,107,115,99,97,112,101,46,111,114,103,155,238,60,26,0,0,1,22,73,68,65,
84,72,137,237,150,61,74,4,65,16,133,191,146,49,16,19,3,67,17,76,252,9,22,204,141,68,188,132,23,240,14,38,130,39,216,208,251,24,154,8,70,30,97,65,97,127,96,117,69,121,38,219,90,211,179,51,8,110,109,39,
62,40,168,174,154,225,189,238,106,30,109,146,40,137,42,37,102,214,3,238,130,120,38,192,61,112,35,233,161,214,145,196,252,20,142,1,5,199,59,112,154,56,37,177,22,180,227,54,172,3,183,190,80,185,252,13,120,
10,32,221,5,54,220,122,223,204,182,37,61,3,63,35,136,10,224,146,230,40,14,87,57,130,81,87,115,213,119,160,136,128,205,174,102,149,23,204,236,28,184,0,14,88,142,192,163,5,181,193,119,150,93,152,107,226,
189,224,177,198,153,25,209,103,48,249,12,56,241,2,252,8,206,104,30,249,199,92,212,95,145,172,248,42,183,98,47,96,103,193,79,123,146,94,150,32,160,21,126,199,150,245,166,209,228,185,128,34,248,23,208,48,
34,7,51,179,173,32,222,153,164,87,160,230,3,125,226,77,40,69,191,212,131,164,129,226,2,252,29,152,2,67,183,86,75,222,213,251,237,119,227,148,88,233,103,249,23,187,55,44,190,136,109,213,126,0,0,0,0,73,
69,78,68,174,66,96,130,0,0};

const char* MixRhyTrack::partName2_png = (const char*) resource_MixRhyTrack_partName2_png;
const int MixRhyTrack::partName2_pngSize = 409;

// JUCER_RESOURCE: partName3_png, 434, "../../../Resources/LookAndFeel/PartName3.png"
static const unsigned char resource_MixRhyTrack_partName3_png[] = { 137,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,0,32,0,0,0,24,8,6,0,0,0,155,83,255,52,0,0,0,4,115,66,73,84,8,8,8,8,124,8,100,136,0,
0,0,9,112,72,89,115,0,0,22,37,0,0,22,37,1,73,82,36,240,0,0,0,25,116,69,88,116,83,111,102,116,119,97,114,101,0,119,119,119,46,105,110,107,115,99,97,112,101,46,111,114,103,155,238,60,26,0,0,1,47,73,68,65,
84,72,137,197,150,177,74,67,65,16,69,207,104,2,242,72,175,8,162,85,10,171,124,66,90,11,75,59,191,192,239,16,191,197,90,172,237,197,34,144,202,144,70,65,11,177,87,76,148,107,145,236,203,188,37,70,133,236,
238,133,229,237,221,89,152,251,102,103,103,199,36,81,18,173,48,49,179,61,224,46,145,159,119,96,8,156,75,106,250,144,196,60,10,7,128,18,143,41,112,20,124,74,202,46,64,192,51,96,193,111,125,4,192,39,240,
248,223,216,254,1,219,192,150,227,187,64,23,24,1,139,8,164,26,192,201,146,40,244,131,125,35,193,31,199,120,93,101,204,33,96,25,166,57,5,84,17,255,0,6,129,248,36,196,204,46,129,157,53,11,56,140,248,149,
164,183,154,69,9,243,64,218,43,120,3,84,222,103,238,28,168,128,182,95,48,255,22,152,217,61,176,63,167,138,190,63,205,127,179,119,128,77,183,126,45,233,120,177,43,125,29,56,165,121,12,19,160,147,243,8,
158,34,222,6,122,129,148,170,3,245,237,43,37,160,70,113,1,190,33,105,49,203,216,117,163,183,210,234,178,181,79,158,126,64,64,183,84,33,130,217,173,24,7,146,91,192,23,112,38,87,253,252,99,52,1,94,18,57,
14,77,233,133,164,91,111,104,148,226,18,248,6,2,197,124,75,53,239,143,19,0,0,0,0,73,69,78,68,174,66,96,130,0,0};

const char* MixRhyTrack::partName3_png = (const char*) resource_MixRhyTrack_partName3_png;
const int MixRhyTrack::partName3_pngSize = 434;

// JUCER_RESOURCE: partName4_png, 500, "../../../Resources/LookAndFeel/PartName4.png"
static const unsigned char resource_MixRhyTrack_partName4_png[] = { 137,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,0,32,0,0,0,24,8,6,0,0,0,155,83,255,52,0,0,0,4,115,66,73,84,8,8,8,8,124,8,100,136,0,
0,0,9,112,72,89,115,0,0,22,37,0,0,22,37,1,73,82,36,240,0,0,0,25,116,69,88,116,83,111,102,116,119,97,114,101,0,119,119,119,46,105,110,107,115,99,97,112,101,46,111,114,103,155,238,60,26,0,0,1,113,73,68,
65,84,72,137,197,214,61,107,84,65,20,198,241,223,217,40,6,69,27,11,83,164,144,96,145,74,196,66,17,84,240,35,72,154,84,105,98,151,62,164,79,138,52,126,2,209,210,66,193,214,82,73,105,33,136,173,111,77,32,
118,18,2,9,104,56,41,118,179,108,54,59,215,205,102,146,125,96,154,123,102,230,249,115,159,115,103,110,100,166,113,234,66,237,13,35,98,2,207,176,140,43,13,83,31,102,230,55,153,89,109,224,9,190,32,135,24,
179,153,169,150,241,12,222,53,152,109,158,9,0,174,98,29,123,5,227,239,120,138,249,170,0,104,97,17,91,5,227,237,78,15,92,234,204,175,7,128,71,248,92,48,222,199,11,220,232,91,115,122,0,220,196,155,134,156,
63,226,78,97,237,232,0,218,159,210,26,118,11,198,63,48,247,159,61,78,14,128,192,66,161,131,15,115,94,57,204,185,42,0,30,224,83,67,206,175,48,117,130,248,134,3,192,20,94,55,228,188,129,187,35,52,110,17,
160,123,20,71,196,52,62,224,150,227,250,133,229,204,124,59,160,118,42,245,222,5,47,7,152,239,104,31,52,207,51,115,175,182,121,23,32,34,38,241,184,175,246,23,183,51,243,231,89,24,31,1,192,101,76,246,213,
46,226,125,68,252,169,224,115,189,88,233,105,148,175,134,187,197,106,141,217,204,212,234,97,89,210,126,237,231,170,110,19,102,230,70,68,220,199,42,238,225,90,69,159,150,118,164,199,53,202,109,88,243,28,
104,13,164,58,71,141,29,160,250,79,105,65,187,248,221,247,236,31,68,39,163,177,233,0,184,89,0,200,207,212,58,6,0,0,0,0,73,69,78,68,174,66,96,130,0,0};

const char* MixRhyTrack::partName4_png = (const char*) resource_MixRhyTrack_partName4_png;
const int MixRhyTrack::partName4_pngSize = 500;

// JUCER_RESOURCE: partName5_png, 381, "../../../Resources/LookAndFeel/PartName5.png"
static const unsigned char resource_MixRhyTrack_partName5_png[] = { 137,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,0,32,0,0,0,24,8,6,0,0,0,155,83,255,52,0,0,0,4,115,66,73,84,8,8,8,8,124,8,100,136,0,
0,0,9,112,72,89,115,0,0,22,37,0,0,22,37,1,73,82,36,240,0,0,0,25,116,69,88,116,83,111,102,116,119,97,114,101,0,119,119,119,46,105,110,107,115,99,97,112,101,46,111,114,103,155,238,60,26,0,0,0,250,73,68,
65,84,72,137,237,149,61,106,66,65,20,133,191,27,148,4,69,176,75,21,200,10,130,157,11,176,183,118,35,238,193,210,210,141,184,133,144,42,144,144,29,8,162,8,138,141,60,94,115,172,70,238,27,30,166,121,243,
166,241,192,129,185,247,22,231,48,63,103,76,18,57,209,241,133,153,237,128,151,212,162,146,134,181,6,128,33,240,156,218,128,199,83,155,98,117,136,119,32,198,17,56,36,117,32,233,70,160,0,228,184,240,243,
20,204,126,4,15,3,230,131,200,204,10,170,207,112,11,108,26,208,41,129,95,96,37,233,175,50,249,231,18,54,205,2,152,86,52,91,54,32,96,7,244,130,102,156,3,41,162,120,0,244,92,253,10,140,128,79,136,130,72,
210,123,195,226,152,217,24,248,138,218,111,97,209,198,43,216,215,244,172,77,3,119,241,48,112,187,132,102,214,5,250,9,52,62,238,78,93,6,204,72,159,1,129,147,156,191,225,5,248,14,69,14,3,115,73,167,80,248,
32,42,129,115,34,209,18,248,1,150,146,214,126,80,249,13,115,224,10,104,94,253,44,227,37,218,84,0,0,0,0,73,69,78,68,174,66,96,130,0,0};

const char* MixRhyTrack::partName5_png = (const char*) resource_MixRhyTrack_partName5_png;
const int MixRhyTrack::partName5_pngSize = 381;

// JUCER_RESOURCE: partName6_png, 415, "../../../Resources/LookAndFeel/PartName6.png"
static const unsigned char resource_MixRhyTrack_partName6_png[] = { 137,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,0,32,0,0,0,24,8,6,0,0,0,155,83,255,52,0,0,0,4,115,66,73,84,8,8,8,8,124,8,100,136,0,
0,0,9,112,72,89,115,0,0,22,37,0,0,22,37,1,73,82,36,240,0,0,0,25,116,69,88,116,83,111,102,116,119,97,114,101,0,119,119,119,46,105,110,107,115,99,97,112,101,46,111,114,103,155,238,60,26,0,0,1,28,73,68,65,
84,72,137,237,150,49,74,3,65,20,134,191,151,136,120,133,128,160,160,136,88,229,0,1,27,207,33,228,6,30,67,11,43,107,59,15,18,75,15,32,66,8,73,99,33,88,6,2,129,196,223,98,217,245,237,24,119,149,205,204,
54,254,48,176,59,111,225,251,153,159,121,251,76,18,109,106,39,220,48,179,33,112,9,156,0,221,72,220,129,164,9,0,146,138,5,220,2,74,176,78,11,166,131,247,129,143,212,6,124,4,231,128,5,71,53,7,22,127,59,
221,95,105,149,63,120,3,189,13,31,30,73,122,143,96,160,80,167,170,24,27,94,107,32,133,90,55,240,173,15,120,153,217,104,75,156,21,240,2,60,72,122,42,85,220,53,188,38,254,245,91,3,87,190,247,164,142,160,
3,220,152,217,113,190,81,25,1,176,220,2,180,27,112,118,129,11,96,82,107,64,210,94,83,186,153,237,3,179,128,117,144,63,68,143,64,210,43,89,246,37,95,201,12,212,233,223,64,93,35,58,3,166,13,25,135,85,28,
95,120,219,80,127,110,8,255,73,5,203,71,48,34,235,86,177,37,224,241,235,45,253,72,118,231,153,22,78,197,145,134,210,53,48,38,251,25,221,151,120,109,143,229,159,210,85,221,16,190,19,24,212,0,0,0,0,73,69,
78,68,174,66,96,130,0,0};

const char* MixRhyTrack::partName6_png = (const char*) resource_MixRhyTrack_partName6_png;
const int MixRhyTrack::partName6_pngSize = 415;

// JUCER_RESOURCE: partName7_png, 458, "../../../Resources/LookAndFeel/PartName7.png"
static const unsigned char resource_MixRhyTrack_partName7_png[] = { 137,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,0,32,0,0,0,24,8,6,0,0,0,155,83,255,52,0,0,0,4,115,66,73,84,8,8,8,8,124,8,100,136,0,
0,0,9,112,72,89,115,0,0,22,37,0,0,22,37,1,73,82,36,240,0,0,0,25,116,69,88,116,83,111,102,116,119,97,114,101,0,119,119,119,46,105,110,107,115,99,97,112,101,46,111,114,103,155,238,60,26,0,0,1,71,73,68,65,
84,72,137,197,214,189,74,3,65,20,134,225,119,76,48,8,74,10,33,130,164,241,2,86,47,64,44,98,101,165,224,53,88,218,26,82,230,30,82,166,81,11,27,193,75,176,209,164,10,22,90,217,136,118,22,118,177,240,7,115,
44,76,66,126,206,236,238,236,238,172,7,6,134,101,230,60,31,203,97,89,35,34,252,103,21,71,27,99,76,0,220,228,228,238,136,200,195,84,0,160,0,148,115,10,80,24,109,22,114,2,173,53,249,6,62,128,199,140,251,
175,3,43,202,243,159,241,78,68,188,44,96,11,120,7,100,102,93,76,157,243,132,175,1,47,10,222,3,150,188,6,0,74,64,87,193,95,129,234,220,121,15,1,206,21,252,19,216,86,207,103,140,55,20,92,128,35,235,157,
12,241,3,96,160,224,173,208,123,25,225,155,64,95,193,175,129,162,215,0,64,197,50,241,79,192,106,228,253,148,120,9,232,40,120,31,8,98,245,72,25,224,76,193,7,192,97,236,30,41,240,186,101,226,155,78,125,
18,226,251,195,239,249,44,126,5,24,175,1,128,192,50,241,247,192,178,115,63,71,188,2,60,43,248,27,176,145,232,109,58,224,139,192,173,130,127,3,181,196,179,228,16,224,212,50,116,199,73,241,216,1,128,19,
11,222,78,131,139,200,223,196,134,149,49,102,23,184,100,226,63,110,88,119,192,158,136,124,133,54,136,168,200,0,190,235,23,170,109,86,234,6,19,168,208,0,0,0,0,73,69,78,68,174,66,96,130,0,0};

const char* MixRhyTrack::partName7_png = (const char*) resource_MixRhyTrack_partName7_png;
const int MixRhyTrack::partName7_pngSize = 458;


//[EndFile] You can add extra defines here...
//[/EndFile]
