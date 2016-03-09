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

#include "MixPartTrack.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...

extern OverallMemoryBlock* grooveboxMemory;
extern QuickSysExBlock* quickSysEx;

//[/MiscUserDefs]

//==============================================================================
MixPartTrack::MixPartTrack (AllParts part)
    : m_part(part)
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

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

    addAndMakeVisible (m_mfxLabel = new Label ("mfxLabel",
                                               TRANS("MFX")));
    m_mfxLabel->setFont (Font (12.00f, Font::bold));
    m_mfxLabel->setJustificationType (Justification::centredLeft);
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
    cachedImage_mixerTapeLabel_png_1 = ImageCache::getFromMemory (mixerTapeLabel_png, mixerTapeLabel_pngSize);

    //[UserPreSize]
	imageButton->setVisible(false);
	if (grooveboxMemory != nullptr)
	{
		if (PartInfoPartBlock* p = grooveboxMemory->getPartInfoBlock()->getPartInfoPartBlockPtr(m_part))
		{
			m_mixLevel->setParameter(p->getParameter((uint16)m_mixLevel->getName().getHexValue32()));
			m_panSlider->setParameter(p->getParameter((uint16)m_panSlider->getName().getHexValue32()));
			m_keyShiftSlider->setParameter(p->getParameter((uint16)m_keyShiftSlider->getName().getHexValue32()));
			m_delaySlider->setParameter(p->getParameter((uint16)m_delaySlider->getName().getHexValue32()));
			m_ReverbSlider->setParameter(p->getParameter((uint16)m_ReverbSlider->getName().getHexValue32()));
			m_mfxGrab->setParameter(p->getParameter((uint16)m_mfxGrab->getName().getHexValue32()));
		}
		if (QuickSysExSequencerBlock* s = quickSysEx->getQuickSysExSequencerBlock())
		{
			m_muteToggle->setParameter(s->getParameter(m_part));
		}
	}
    //[/UserPreSize]

    setSize (72, 620);


    //[Constructor] You can add your own custom stuff here..
    //[/Constructor]
}

MixPartTrack::~MixPartTrack()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    m_mixLevel = nullptr;
    m_panSlider = nullptr;
    m_delaySlider = nullptr;
    m_ReverbSlider = nullptr;
    m_keyShiftSlider = nullptr;
    m_muteToggle = nullptr;
    imageButton = nullptr;
    m_panLabel = nullptr;
    m_keyShiftLabel = nullptr;
    m_mfxLabel = nullptr;
    m_delayLabel = nullptr;
    m_reverbLabel = nullptr;
    m_mfxGrab = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void MixPartTrack::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.setColour (Colours::black);
    g.drawImage (cachedImage_mixerTapeLabel_png_1,
                 (getWidth() / 2) - (72 / 2), 0, 72, 20,
                 0, 0, cachedImage_mixerTapeLabel_png_1.getWidth(), cachedImage_mixerTapeLabel_png_1.getHeight());

    //[UserPaint] Add your own custom painting code here..
    g.setColour (Colours::white);
    int y(getHeight()-55);
    int x(getWidth()/2-12);
    int w(24);
    int h(18);
	switch (m_part)
	{
	case PartR:
		g.drawImageWithin(ImageCache::getFromMemory(partNameR_png, partNameR_pngSize), x, y, w, h, RectanglePlacement::centred | RectanglePlacement::onlyReduceInSize, true);
		break;
	case Part1:
		g.drawImageWithin(ImageCache::getFromMemory(partName1_png, partName1_pngSize), x, y, w, h, RectanglePlacement::centred | RectanglePlacement::onlyReduceInSize, true);
		break;
	case Part2:
		g.drawImageWithin(ImageCache::getFromMemory(partName2_png, partName2_pngSize), x, y, w, h, RectanglePlacement::centred | RectanglePlacement::onlyReduceInSize, true);
		break;
	case Part3:
		g.drawImageWithin(ImageCache::getFromMemory(partName3_png, partName3_pngSize), x, y, w, h, RectanglePlacement::centred | RectanglePlacement::onlyReduceInSize, true);
		break;
	case Part4:
		g.drawImageWithin(ImageCache::getFromMemory(partName4_png, partName4_pngSize), x, y, w, h, RectanglePlacement::centred | RectanglePlacement::onlyReduceInSize, true);
		break;
	case Part5:
		g.drawImageWithin(ImageCache::getFromMemory(partName5_png, partName5_pngSize), x, y, w, h, RectanglePlacement::centred | RectanglePlacement::onlyReduceInSize, true);
		break;
	case Part6:
		g.drawImageWithin(ImageCache::getFromMemory(partName6_png, partName6_pngSize), x, y, w, h, RectanglePlacement::centred | RectanglePlacement::onlyReduceInSize, true);
		break;
	case Part7:
		g.drawImageWithin(ImageCache::getFromMemory(partName7_png, partName7_pngSize), x, y, w, h, RectanglePlacement::centred | RectanglePlacement::onlyReduceInSize, true);
		break;
	default:
		break;
	}
    //[/UserPaint]
}

void MixPartTrack::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    m_mixLevel->setBounds ((getWidth() / 2) - (32 / 2), 304, 32, getHeight() - 368);
    m_panSlider->setBounds ((getWidth() / 2) - (48 / 2), 254, 48, 48);
    m_delaySlider->setBounds ((getWidth() / 2) - (48 / 2), 94, 48, 48);
    m_ReverbSlider->setBounds ((getWidth() / 2) - (48 / 2), 34, 48, 48);
    m_keyShiftSlider->setBounds ((getWidth() / 2) - (56 / 2), 220, 56, 16);
    m_muteToggle->setBounds ((getWidth() / 2) - (27 / 2), getHeight() - 1 - 27, 27, 27);
    imageButton->setBounds ((getWidth() / 2) - (24 / 2), getHeight() - 37 - 18, 24, 18);
    m_panLabel->setBounds (0, 244, getWidth() - 0, 12);
    m_keyShiftLabel->setBounds (0, 207, getWidth() - 0, 12);
    m_mfxLabel->setBounds ((getWidth() / 2) - (64 / 2), 150, 64, 12);
    m_delayLabel->setBounds (0, 84, getWidth() - 0, 12);
    m_reverbLabel->setBounds (0, 24, getWidth() - 0, 12);
    m_mfxGrab->setBounds ((getWidth() / 2) - (54 / 2), 156, 54, 49);
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void MixPartTrack::sliderValueChanged (Slider* sliderThatWasMoved)
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

    //[UsersliderValueChanged_Post]
    //[/UsersliderValueChanged_Post]
}

void MixPartTrack::buttonClicked (Button* buttonThatWasClicked)
{
    //[UserbuttonClicked_Pre]
    //[/UserbuttonClicked_Pre]

    if (buttonThatWasClicked == imageButton)
    {
        //[UserButtonCode_imageButton] -- add your button handler code here..
        //[/UserButtonCode_imageButton]
    }

    //[UserbuttonClicked_Post]
    //[/UserbuttonClicked_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Introjucer information section --

    This is where the Introjucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="MixPartTrack" componentName=""
                 parentClasses="public Component" constructorParams="AllParts part"
                 variableInitialisers="m_part(part)" snapPixels="4" snapActive="1"
                 snapShown="1" overlayOpacity="0.330" fixedSize="1" initialWidth="72"
                 initialHeight="620">
  <BACKGROUND backgroundColour="0">
    <IMAGE pos="0Cc 0 72 20" resource="mixerTapeLabel_png" opacity="1" mode="0"/>
  </BACKGROUND>
  <SLIDER name="06" id="1b5918ef3651954f" memberName="m_mixLevel" virtualName="MixPartLevelFader"
          explicitFocusOrder="0" pos="0Cc 304 32 368M" min="0" max="127"
          int="1" style="LinearVertical" textBoxPos="TextBoxBelow" textBoxEditable="1"
          textBoxWidth="32" textBoxHeight="16" skewFactor="1"/>
  <SLIDER name="07" id="8f70d251e0e8426e" memberName="m_panSlider" virtualName="Knob"
          explicitFocusOrder="0" pos="0Cc 254 48 48" min="-64" max="63"
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
               virtualName="" explicitFocusOrder="0" pos="0Cc 37Rr 24 18" buttonText="new button"
               connectedEdges="0" needsCallback="1" radioGroupId="0" keepProportions="1"
               resourceNormal="partNameR_png" opacityNormal="1" colourNormal="ffffffff"
               resourceOver="" opacityOver="1" colourOver="0" resourceDown=""
               opacityDown="1" colourDown="0"/>
  <LABEL name="panLabel" id="39a07dbc337265d" memberName="m_panLabel"
         virtualName="" explicitFocusOrder="0" pos="0 244 0M 12" textCol="ff000000"
         edTextCol="ff000000" edBkgCol="0" labelText="PAN" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="12" bold="1" italic="0" justification="36"/>
  <LABEL name="keyShiftLabel" id="2d5f9ed3d1da8b8d" memberName="m_keyShiftLabel"
         virtualName="" explicitFocusOrder="0" pos="0 207 0M 12" textCol="ff000000"
         edTextCol="ff000000" edBkgCol="0" labelText="KEY SHIFT" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="12" bold="1" italic="0" justification="36"/>
  <LABEL name="mfxLabel" id="f7600c3cc150c941" memberName="m_mfxLabel"
         virtualName="" explicitFocusOrder="0" pos="0Cc 150 64 12" textCol="ff000000"
         edTextCol="ff000000" edBkgCol="0" labelText="MFX" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="12" bold="1" italic="0" justification="33"/>
  <LABEL name="delayLabel" id="e3598cb93aa83446" memberName="m_delayLabel"
         virtualName="" explicitFocusOrder="0" pos="0 84 0M 12" textCol="ff000000"
         edTextCol="ff000000" edBkgCol="0" labelText="DELAY" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="12" bold="1" italic="0" justification="36"/>
  <LABEL name="reverbLabel" id="88bae54666436ac4" memberName="m_reverbLabel"
         virtualName="" explicitFocusOrder="0" pos="0 24 0M 12" textCol="ff000000"
         edTextCol="ff000000" edBkgCol="0" labelText="REVERB" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="12" bold="1" italic="0" justification="36"/>
  <JUCERCOMP name="0A" id="3d47dada4f5d9d7f" memberName="m_mfxGrab" virtualName="GrabSwitch"
             explicitFocusOrder="0" pos="0Cc 156 54 49" sourceFile="../ParameterWidgets/GrabSwitch.cpp"
             constructorParams="&quot;0A&quot;"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif

//==============================================================================
// Binary resources - be careful not to edit any of these sections!

// JUCER_RESOURCE: partNameR_png, 423, "Resources/LookAndFeel/PartNameR.png"
static const unsigned char resource_MixPartTrack_partNameR_png[] = { 137,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,0,32,0,0,0,24,8,6,0,0,0,155,83,255,52,0,0,0,4,115,66,73,84,8,8,8,8,124,8,100,136,
0,0,0,9,112,72,89,115,0,0,22,38,0,0,22,38,1,228,235,5,157,0,0,0,25,116,69,88,116,83,111,102,116,119,97,114,101,0,119,119,119,46,105,110,107,115,99,97,112,101,46,111,114,103,155,238,60,26,0,0,1,36,73,68,
65,84,72,137,197,150,177,74,3,65,16,134,191,145,32,146,202,70,20,69,44,196,74,176,21,76,227,59,248,58,118,62,128,47,144,7,200,67,104,43,168,96,21,2,86,166,73,117,22,41,36,141,226,111,225,94,216,93,60,
171,219,217,129,225,152,127,224,230,191,153,217,255,214,36,81,211,6,0,102,246,12,28,22,172,211,0,15,192,181,164,38,201,132,14,204,1,57,248,2,216,145,68,235,27,133,190,184,203,246,129,155,24,24,132,231,
12,88,22,42,122,6,88,20,95,38,217,184,29,37,28,24,147,142,97,233,61,130,143,255,146,222,59,0,191,93,112,37,176,149,197,175,113,208,234,192,4,216,43,68,96,148,197,119,73,228,172,3,247,192,176,166,14,220,
74,90,197,128,73,194,204,230,192,81,132,127,3,159,61,20,220,36,213,128,21,112,46,105,186,70,58,70,48,233,73,3,14,128,247,236,221,99,183,17,72,90,144,47,29,92,153,217,186,43,30,59,240,148,197,219,192,105,
77,2,16,29,77,15,2,47,192,87,53,2,225,216,77,51,248,194,141,64,176,124,12,199,102,182,235,73,224,241,15,108,228,73,160,115,17,219,27,81,67,250,215,234,251,118,52,3,222,128,97,132,157,64,144,226,154,246,
3,162,3,35,71,135,173,101,129,0,0,0,0,73,69,78,68,174,66,96,130,0,0};

const char* MixPartTrack::partNameR_png = (const char*) resource_MixPartTrack_partNameR_png;
const int MixPartTrack::partNameR_pngSize = 423;

// JUCER_RESOURCE: partName1_png, 277, "Resources/LookAndFeel/PartName1.png"
static const unsigned char resource_MixPartTrack_partName1_png[] = { 137,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,0,32,0,0,0,24,8,6,0,0,0,155,83,255,52,0,0,0,4,115,66,73,84,8,8,8,8,124,8,100,136,
0,0,0,9,112,72,89,115,0,0,22,37,0,0,22,37,1,73,82,36,240,0,0,0,25,116,69,88,116,83,111,102,116,119,97,114,101,0,119,119,119,46,105,110,107,115,99,97,112,101,46,111,114,103,155,238,60,26,0,0,0,146,73,68,
65,84,72,137,237,150,177,13,194,64,16,4,119,44,18,18,122,113,19,36,36,46,1,209,16,237,184,21,58,112,104,68,224,192,193,146,162,7,89,127,24,225,228,86,218,228,239,247,52,186,251,224,177,173,45,213,68,46,
3,39,96,44,60,0,61,112,252,138,192,118,181,37,117,146,188,224,75,164,159,237,216,4,42,116,5,246,145,64,20,224,33,233,246,226,169,168,31,36,181,161,142,209,145,21,43,57,235,125,13,221,63,87,48,174,204,
255,252,13,36,64,2,36,64,2,36,64,2,36,64,88,187,149,249,89,210,253,195,89,181,216,250,91,254,4,124,118,180,26,84,31,31,91,0,0,0,0,73,69,78,68,174,66,96,130,0,0};

const char* MixPartTrack::partName1_png = (const char*) resource_MixPartTrack_partName1_png;
const int MixPartTrack::partName1_pngSize = 277;

// JUCER_RESOURCE: partName2_png, 409, "Resources/LookAndFeel/PartName2.png"
static const unsigned char resource_MixPartTrack_partName2_png[] = { 137,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,0,32,0,0,0,24,8,6,0,0,0,155,83,255,52,0,0,0,4,115,66,73,84,8,8,8,8,124,8,100,136,
0,0,0,9,112,72,89,115,0,0,22,37,0,0,22,37,1,73,82,36,240,0,0,0,25,116,69,88,116,83,111,102,116,119,97,114,101,0,119,119,119,46,105,110,107,115,99,97,112,101,46,111,114,103,155,238,60,26,0,0,1,22,73,68,
65,84,72,137,237,150,61,74,4,65,16,133,191,146,49,16,19,3,67,17,76,252,9,22,204,141,68,188,132,23,240,14,38,130,39,216,208,251,24,154,8,70,30,97,65,97,127,96,117,69,121,38,219,90,211,179,51,8,110,109,
39,62,40,168,174,154,225,189,238,106,30,109,146,40,137,42,37,102,214,3,238,130,120,38,192,61,112,35,233,161,214,145,196,252,20,142,1,5,199,59,112,154,56,37,177,22,180,227,54,172,3,183,190,80,185,252,13,
120,10,32,221,5,54,220,122,223,204,182,37,61,3,63,35,136,10,224,146,230,40,14,87,57,130,81,87,115,213,119,160,136,128,205,174,102,149,23,204,236,28,184,0,14,88,142,192,163,5,181,193,119,150,93,152,107,
226,189,224,177,198,153,25,209,103,48,249,12,56,241,2,252,8,206,104,30,249,199,92,212,95,145,172,248,42,183,98,47,96,103,193,79,123,146,94,150,32,160,21,126,199,150,245,166,209,228,185,128,34,248,23,208,
48,34,7,51,179,173,32,222,153,164,87,160,230,3,125,226,77,40,69,191,212,131,164,129,226,2,252,29,152,2,67,183,86,75,222,213,251,237,119,227,148,88,233,103,249,23,187,55,44,190,136,109,213,126,0,0,0,0,
73,69,78,68,174,66,96,130,0,0};

const char* MixPartTrack::partName2_png = (const char*) resource_MixPartTrack_partName2_png;
const int MixPartTrack::partName2_pngSize = 409;

// JUCER_RESOURCE: partName3_png, 434, "Resources/LookAndFeel/PartName3.png"
static const unsigned char resource_MixPartTrack_partName3_png[] = { 137,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,0,32,0,0,0,24,8,6,0,0,0,155,83,255,52,0,0,0,4,115,66,73,84,8,8,8,8,124,8,100,136,
0,0,0,9,112,72,89,115,0,0,22,37,0,0,22,37,1,73,82,36,240,0,0,0,25,116,69,88,116,83,111,102,116,119,97,114,101,0,119,119,119,46,105,110,107,115,99,97,112,101,46,111,114,103,155,238,60,26,0,0,1,47,73,68,
65,84,72,137,197,150,177,74,67,65,16,69,207,104,2,242,72,175,8,162,85,10,171,124,66,90,11,75,59,191,192,239,16,191,197,90,172,237,197,34,144,202,144,70,65,11,177,87,76,148,107,145,236,203,188,37,70,133,
236,238,133,229,237,221,89,152,251,102,103,103,199,36,81,18,173,48,49,179,61,224,46,145,159,119,96,8,156,75,106,250,144,196,60,10,7,128,18,143,41,112,20,124,74,202,46,64,192,51,96,193,111,125,4,192,39,
240,248,223,216,254,1,219,192,150,227,187,64,23,24,1,139,8,164,26,192,201,146,40,244,131,125,35,193,31,199,120,93,101,204,33,96,25,166,57,5,84,17,255,0,6,129,248,36,196,204,46,129,157,53,11,56,140,248,
149,164,183,154,69,9,243,64,218,43,120,3,84,222,103,238,28,168,128,182,95,48,255,22,152,217,61,176,63,167,138,190,63,205,127,179,119,128,77,183,126,45,233,120,177,43,125,29,56,165,121,12,19,160,147,243,
8,158,34,222,6,122,129,148,170,3,245,237,43,37,160,70,113,1,190,33,105,49,203,216,117,163,183,210,234,178,181,79,158,126,64,64,183,84,33,130,217,173,24,7,146,91,192,23,112,38,87,253,252,99,52,1,94,18,
57,14,77,233,133,164,91,111,104,148,226,18,248,6,2,197,124,75,53,239,143,19,0,0,0,0,73,69,78,68,174,66,96,130,0,0};

const char* MixPartTrack::partName3_png = (const char*) resource_MixPartTrack_partName3_png;
const int MixPartTrack::partName3_pngSize = 434;

// JUCER_RESOURCE: partName4_png, 500, "Resources/LookAndFeel/PartName4.png"
static const unsigned char resource_MixPartTrack_partName4_png[] = { 137,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,0,32,0,0,0,24,8,6,0,0,0,155,83,255,52,0,0,0,4,115,66,73,84,8,8,8,8,124,8,100,136,
0,0,0,9,112,72,89,115,0,0,22,37,0,0,22,37,1,73,82,36,240,0,0,0,25,116,69,88,116,83,111,102,116,119,97,114,101,0,119,119,119,46,105,110,107,115,99,97,112,101,46,111,114,103,155,238,60,26,0,0,1,113,73,68,
65,84,72,137,197,214,61,107,84,65,20,198,241,223,217,40,6,69,27,11,83,164,144,96,145,74,196,66,17,84,240,35,72,154,84,105,98,151,62,164,79,138,52,126,2,209,210,66,193,214,82,73,105,33,136,173,111,77,32,
118,18,2,9,104,56,41,118,179,108,54,59,215,205,102,146,125,96,154,123,102,230,249,115,159,115,103,110,100,166,113,234,66,237,13,35,98,2,207,176,140,43,13,83,31,102,230,55,153,89,109,224,9,190,32,135,24,
179,153,169,150,241,12,222,53,152,109,158,9,0,174,98,29,123,5,227,239,120,138,249,170,0,104,97,17,91,5,227,237,78,15,92,234,204,175,7,128,71,248,92,48,222,199,11,220,232,91,115,122,0,220,196,155,134,156,
63,226,78,97,237,232,0,218,159,210,26,118,11,198,63,48,247,159,61,78,14,128,192,66,161,131,15,115,94,57,204,185,42,0,30,224,83,67,206,175,48,117,130,248,134,3,192,20,94,55,228,188,129,187,35,52,110,17,
160,123,20,71,196,52,62,224,150,227,250,133,229,204,124,59,160,118,42,245,222,5,47,7,152,239,104,31,52,207,51,115,175,182,121,23,32,34,38,241,184,175,246,23,183,51,243,231,89,24,31,1,192,101,76,246,213,
46,226,125,68,252,169,224,115,189,88,233,105,148,175,134,187,197,106,141,217,204,212,234,97,89,210,126,237,231,170,110,19,102,230,70,68,220,199,42,238,225,90,69,159,150,118,164,199,53,202,109,88,243,28,
104,13,164,58,71,141,29,160,250,79,105,65,187,248,221,247,236,31,68,39,163,177,233,0,184,89,0,200,207,212,58,6,0,0,0,0,73,69,78,68,174,66,96,130,0,0};

const char* MixPartTrack::partName4_png = (const char*) resource_MixPartTrack_partName4_png;
const int MixPartTrack::partName4_pngSize = 500;

// JUCER_RESOURCE: partName5_png, 381, "Resources/LookAndFeel/PartName5.png"
static const unsigned char resource_MixPartTrack_partName5_png[] = { 137,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,0,32,0,0,0,24,8,6,0,0,0,155,83,255,52,0,0,0,4,115,66,73,84,8,8,8,8,124,8,100,136,
0,0,0,9,112,72,89,115,0,0,22,37,0,0,22,37,1,73,82,36,240,0,0,0,25,116,69,88,116,83,111,102,116,119,97,114,101,0,119,119,119,46,105,110,107,115,99,97,112,101,46,111,114,103,155,238,60,26,0,0,0,250,73,68,
65,84,72,137,237,149,61,106,66,65,20,133,191,27,148,4,69,176,75,21,200,10,130,157,11,176,183,118,35,238,193,210,210,141,184,133,144,42,144,144,29,8,162,8,138,141,60,94,115,172,70,238,27,30,166,121,243,
166,241,192,129,185,247,22,231,48,63,103,76,18,57,209,241,133,153,237,128,151,212,162,146,134,181,6,128,33,240,156,218,128,199,83,155,98,117,136,119,32,198,17,56,36,117,32,233,70,160,0,228,184,240,243,
20,204,126,4,15,3,230,131,200,204,10,170,207,112,11,108,26,208,41,129,95,96,37,233,175,50,249,231,18,54,205,2,152,86,52,91,54,32,96,7,244,130,102,156,3,41,162,120,0,244,92,253,10,140,128,79,136,130,72,
210,123,195,226,152,217,24,248,138,218,111,97,209,198,43,216,215,244,172,77,3,119,241,48,112,187,132,102,214,5,250,9,52,62,238,78,93,6,204,72,159,1,129,147,156,191,225,5,248,14,69,14,3,115,73,167,80,248,
32,42,129,115,34,209,18,248,1,150,146,214,126,80,249,13,115,224,10,104,94,253,44,227,37,218,84,0,0,0,0,73,69,78,68,174,66,96,130,0,0};

const char* MixPartTrack::partName5_png = (const char*) resource_MixPartTrack_partName5_png;
const int MixPartTrack::partName5_pngSize = 381;

// JUCER_RESOURCE: partName6_png, 415, "Resources/LookAndFeel/PartName6.png"
static const unsigned char resource_MixPartTrack_partName6_png[] = { 137,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,0,32,0,0,0,24,8,6,0,0,0,155,83,255,52,0,0,0,4,115,66,73,84,8,8,8,8,124,8,100,136,
0,0,0,9,112,72,89,115,0,0,22,37,0,0,22,37,1,73,82,36,240,0,0,0,25,116,69,88,116,83,111,102,116,119,97,114,101,0,119,119,119,46,105,110,107,115,99,97,112,101,46,111,114,103,155,238,60,26,0,0,1,28,73,68,
65,84,72,137,237,150,49,74,3,65,20,134,191,151,136,120,133,128,160,160,136,88,229,0,1,27,207,33,228,6,30,67,11,43,107,59,15,18,75,15,32,66,8,73,99,33,88,6,2,129,196,223,98,217,245,237,24,119,149,205,204,
54,254,48,176,59,111,225,251,153,159,121,251,76,18,109,106,39,220,48,179,33,112,9,156,0,221,72,220,129,164,9,0,146,138,5,220,2,74,176,78,11,166,131,247,129,143,212,6,124,4,231,128,5,71,53,7,22,127,59,
221,95,105,149,63,120,3,189,13,31,30,73,122,143,96,160,80,167,170,24,27,94,107,32,133,90,55,240,173,15,120,153,217,104,75,156,21,240,2,60,72,122,42,85,220,53,188,38,254,245,91,3,87,190,247,164,142,160,
3,220,152,217,113,190,81,25,1,176,220,2,180,27,112,118,129,11,96,82,107,64,210,94,83,186,153,237,3,179,128,117,144,63,68,143,64,210,43,89,246,37,95,201,12,212,233,223,64,93,35,58,3,166,13,25,135,85,28,
95,120,219,80,127,110,8,255,73,5,203,71,48,34,235,86,177,37,224,241,235,45,253,72,118,231,153,22,78,197,145,134,210,53,48,38,251,25,221,151,120,109,143,229,159,210,85,221,16,190,19,24,212,0,0,0,0,73,69,
78,68,174,66,96,130,0,0};

const char* MixPartTrack::partName6_png = (const char*) resource_MixPartTrack_partName6_png;
const int MixPartTrack::partName6_pngSize = 415;

// JUCER_RESOURCE: partName7_png, 458, "Resources/LookAndFeel/PartName7.png"
static const unsigned char resource_MixPartTrack_partName7_png[] = { 137,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,0,32,0,0,0,24,8,6,0,0,0,155,83,255,52,0,0,0,4,115,66,73,84,8,8,8,8,124,8,100,136,
0,0,0,9,112,72,89,115,0,0,22,37,0,0,22,37,1,73,82,36,240,0,0,0,25,116,69,88,116,83,111,102,116,119,97,114,101,0,119,119,119,46,105,110,107,115,99,97,112,101,46,111,114,103,155,238,60,26,0,0,1,71,73,68,
65,84,72,137,197,214,189,74,3,65,20,134,225,119,76,48,8,74,10,33,130,164,241,2,86,47,64,44,98,101,165,224,53,88,218,26,82,230,30,82,166,81,11,27,193,75,176,209,164,10,22,90,217,136,118,22,118,177,240,
7,115,44,76,66,126,206,236,238,236,238,172,7,6,134,101,230,60,31,203,97,89,35,34,252,103,21,71,27,99,76,0,220,228,228,238,136,200,195,84,0,160,0,148,115,10,80,24,109,22,114,2,173,53,249,6,62,128,199,140,
251,175,3,43,202,243,159,241,78,68,188,44,96,11,120,7,100,102,93,76,157,243,132,175,1,47,10,222,3,150,188,6,0,74,64,87,193,95,129,234,220,121,15,1,206,21,252,19,216,86,207,103,140,55,20,92,128,35,235,
157,12,241,3,96,160,224,173,208,123,25,225,155,64,95,193,175,129,162,215,0,64,197,50,241,79,192,106,228,253,148,120,9,232,40,120,31,8,98,245,72,25,224,76,193,7,192,97,236,30,41,240,186,101,226,155,78,
125,18,226,251,195,239,249,44,126,5,24,175,1,128,192,50,241,247,192,178,115,63,71,188,2,60,43,248,27,176,145,232,109,58,224,139,192,173,130,127,3,181,196,179,228,16,224,212,50,116,199,73,241,216,1,128,
19,11,222,78,131,139,200,223,196,134,149,49,102,23,184,100,226,63,110,88,119,192,158,136,124,133,54,136,168,200,0,190,235,23,170,109,86,234,6,19,168,208,0,0,0,0,73,69,78,68,174,66,96,130,0,0};

const char* MixPartTrack::partName7_png = (const char*) resource_MixPartTrack_partName7_png;
const int MixPartTrack::partName7_pngSize = 458;

// JUCER_RESOURCE: mixerTapeLabel_png, 1246, "../../../Resources/LookAndFeel/MixerTapeLabel.png"
static const unsigned char resource_MixPartTrack_mixerTapeLabel_png[] = { 137,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,0,72,0,0,0,20,8,6,0,0,0,46,161,123,203,0,0,0,4,115,66,73,84,8,8,8,8,124,8,100,
136,0,0,0,9,112,72,89,115,0,0,3,232,0,0,3,232,1,181,123,82,107,0,0,0,25,116,69,88,116,83,111,102,116,119,97,114,101,0,119,119,119,46,105,110,107,115,99,97,112,101,46,111,114,103,155,238,60,26,0,0,4,91,
73,68,65,84,88,133,213,86,91,104,28,85,24,254,254,51,103,55,68,118,103,179,137,89,115,177,180,85,211,36,181,210,214,154,168,85,20,124,16,177,32,197,203,147,34,190,10,22,17,81,244,89,223,212,39,161,138,
224,147,138,15,62,40,109,133,6,90,197,7,65,130,52,109,44,177,77,19,75,40,37,77,66,82,109,178,51,59,183,115,124,152,217,217,185,238,110,182,89,109,127,118,216,115,206,127,57,255,247,205,57,31,67,112,77,
29,26,186,231,68,177,88,204,118,21,212,82,177,216,101,85,42,134,173,235,6,121,126,72,72,105,91,182,137,86,141,0,53,159,171,52,10,115,28,135,105,154,214,193,121,54,91,40,228,13,0,16,66,208,250,122,57,155,
205,102,58,84,53,103,17,145,4,0,41,37,45,45,173,216,106,62,167,104,186,110,27,166,97,39,22,149,181,65,65,205,119,40,92,1,99,204,8,58,43,21,147,27,134,161,100,56,207,46,45,175,26,25,174,44,110,108,108,
156,229,0,192,57,31,31,31,123,104,239,199,31,125,160,118,21,10,45,115,208,30,147,222,79,194,71,42,165,231,145,190,223,157,213,198,213,88,41,101,160,78,157,60,191,174,159,183,251,237,119,63,28,101,0,96,
219,246,169,159,126,254,229,219,217,217,57,159,235,255,199,92,16,82,10,239,113,32,133,227,254,87,31,111,46,164,237,142,69,220,23,159,219,117,124,78,98,29,203,50,113,225,226,220,13,238,117,214,55,50,60,
252,228,248,216,1,170,219,127,27,8,105,230,13,251,107,129,216,80,94,232,148,33,124,18,162,121,145,186,144,129,19,20,136,61,51,53,237,204,94,250,107,134,3,216,115,232,208,211,39,143,126,250,201,224,150,
98,143,89,148,140,64,195,13,64,37,93,177,36,80,233,87,172,137,188,72,15,119,15,148,148,130,154,239,227,0,50,163,35,195,106,169,212,187,37,52,52,5,42,70,198,102,64,85,179,26,228,69,123,104,248,66,16,200,
37,116,247,116,129,24,89,124,247,232,240,251,47,60,255,92,231,86,147,225,111,220,62,17,173,229,53,69,70,82,15,46,25,0,64,4,0,204,71,117,229,202,53,172,173,254,189,143,27,166,181,54,49,113,250,159,125,
123,31,232,217,28,25,77,128,10,53,82,79,55,194,177,155,210,155,216,21,107,76,6,8,160,0,25,254,186,199,20,1,24,186,111,7,6,7,251,111,240,181,181,235,223,44,47,175,28,78,35,228,86,21,209,152,78,33,122,197,
154,35,163,182,66,161,24,9,9,195,52,4,47,22,11,111,189,244,226,225,187,226,100,4,26,110,0,42,233,138,181,91,68,195,100,248,76,192,125,255,84,91,107,130,140,218,148,2,153,12,143,62,252,96,39,239,233,41,
238,26,31,223,239,126,7,164,146,177,25,80,213,172,6,121,41,87,172,89,17,117,49,7,201,8,0,167,48,216,36,162,18,253,84,27,159,153,58,143,227,63,158,94,227,3,125,125,12,82,120,173,165,129,170,2,170,163,55,
81,80,109,22,209,36,221,72,39,35,76,71,244,212,196,252,68,200,231,243,232,46,22,84,126,255,158,145,101,41,157,209,250,186,113,19,122,83,71,55,110,70,68,99,235,1,208,141,201,8,239,21,173,67,0,230,230,23,
44,173,172,159,96,215,87,87,75,177,79,241,58,159,240,34,41,54,245,19,190,94,172,71,14,1,68,204,123,200,253,7,243,28,12,8,174,19,243,218,103,158,143,60,191,23,3,119,92,93,71,112,29,181,58,161,92,184,53,
131,61,128,24,158,125,230,169,204,246,237,219,118,114,221,52,206,73,225,140,214,222,112,224,36,224,214,21,209,180,19,64,13,78,70,112,175,104,15,20,216,235,243,47,190,94,213,52,237,119,234,239,47,205,78,
254,122,108,72,85,243,109,16,209,4,176,129,230,227,87,165,69,50,82,64,83,147,100,132,123,4,166,255,152,17,175,190,246,230,209,249,203,11,71,184,170,230,38,175,94,93,28,202,231,238,184,173,68,52,186,15,
165,228,249,213,83,200,136,218,217,115,51,246,235,111,188,119,124,254,242,194,59,0,192,203,235,229,220,226,226,53,57,188,107,7,221,78,34,186,21,100,36,217,15,199,78,74,203,178,58,0,88,213,10,61,7,31,217,
63,241,253,119,159,29,224,92,65,50,25,201,199,180,37,221,104,137,140,218,94,209,30,234,93,149,86,108,250,252,133,149,206,206,236,169,151,95,57,114,239,159,23,47,61,70,0,50,189,189,221,95,61,241,248,216,
193,129,129,94,165,92,174,48,33,164,35,108,199,10,101,82,234,36,102,196,24,231,138,194,1,64,45,228,28,34,197,247,233,122,133,149,203,154,73,36,165,148,196,55,54,52,177,115,231,54,197,52,45,42,151,53,104,
154,174,11,41,179,82,8,157,103,184,8,239,202,240,95,152,148,130,126,155,156,186,211,50,204,47,255,5,89,174,37,44,206,250,20,73,0,0,0,0,73,69,78,68,174,66,96,130,0,0};

const char* MixPartTrack::mixerTapeLabel_png = (const char*) resource_MixPartTrack_mixerTapeLabel_png;
const int MixPartTrack::mixerTapeLabel_pngSize = 1246;


//[EndFile] You can add extra defines here...
//[/EndFile]
