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
#include "../../GrooveboxMemory/OverallMemoryBlock.h"
//[/Headers]

#include "ToneDelayEditor.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
extern OverallMemoryBlock* grooveboxMemory;
//[/MiscUserDefs]

//==============================================================================
ToneDelayEditor::ToneDelayEditor (const String &componentName, SynthParts part, Tone tone)
    : Component (componentName), m_part(part), m_tone(tone)
{
    addAndMakeVisible (m_fxmGrp = new PanelGroupGrey ("ToneDlyGrp","DELAY"));
    addAndMakeVisible (m_toneDelayModeLabel = new Label ("toneDelayModeLabel",
                                                         "DELAY MODE"));
    m_toneDelayModeLabel->setFont (Font (12.00f, Font::bold));
    m_toneDelayModeLabel->setJustificationType (Justification::centred);
    m_toneDelayModeLabel->setEditable (false, false, false);
    m_toneDelayModeLabel->setColour (Label::textColourId, Colours::black);
    m_toneDelayModeLabel->setColour (TextEditor::textColourId, Colours::black);
    m_toneDelayModeLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_toneDelayTimeLabel = new Label ("toneDelayTimeLabel",
                                                         "DELAY TIME"));
    m_toneDelayTimeLabel->setFont (Font (12.00f, Font::bold));
    m_toneDelayTimeLabel->setJustificationType (Justification::centred);
    m_toneDelayTimeLabel->setEditable (false, false, false);
    m_toneDelayTimeLabel->setColour (Label::textColourId, Colours::black);
    m_toneDelayTimeLabel->setColour (TextEditor::textColourId, Colours::black);
    m_toneDelayTimeLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (imageButton2 = new ImageButton ("new button"));
    imageButton2->setButtonText (String());

    imageButton2->setImages (false, true, true,
                             ImageCache::getFromMemory (delay_png, delay_pngSize), 1.000f, Colour (0x4340454a),
                             Image(), 1.000f, Colour (0x4340454a),
                             Image(), 1.000f, Colour (0x4340454a));
    addAndMakeVisible (m_toneDelayModeComboBox = new ParameterComboBox ("toneDelayModeComboBox"));
    m_toneDelayModeComboBox->setEditableText (false);
    m_toneDelayModeComboBox->setJustificationType (Justification::centred);
    m_toneDelayModeComboBox->setTextWhenNothingSelected ("NORMAL");
    m_toneDelayModeComboBox->setTextWhenNoChoicesAvailable ("(no choices)");
    m_toneDelayModeComboBox->addItem ("NORMAL", 1);
    m_toneDelayModeComboBox->addItem ("HOLD", 2);
    m_toneDelayModeComboBox->addItem ("PLAYMATE", 3);
    m_toneDelayModeComboBox->addItem ("CLOCK-SYNC", 4);
    m_toneDelayModeComboBox->addItem ("TAP-SYNC", 5);
    m_toneDelayModeComboBox->addItem ("KEY-OFF-NORMAL", 6);
    m_toneDelayModeComboBox->addItem ("KEY-OFF-DECAY", 7);
    m_toneDelayModeComboBox->addItem ("TEMPO-SYNC", 8);
    m_toneDelayModeComboBox->addListener (this);

    addAndMakeVisible (m_toneDelayTimeSlider = new Knob ("toneDelayTimeSlider"));
    m_toneDelayTimeSlider->setRange (0, 127, 1);
    m_toneDelayTimeSlider->setSliderStyle (Slider::RotaryHorizontalVerticalDrag);
    m_toneDelayTimeSlider->setTextBoxStyle (Slider::TextBoxBelow, false, 80, 16);
    m_toneDelayTimeSlider->addListener (this);


    //[UserPreSize]
    //[/UserPreSize]

    setSize (104, 136);


    //[Constructor] You can add your own custom stuff here..
	if (grooveboxMemory != nullptr)
	{
		SynthPatchesBlock* synthPatches = grooveboxMemory->getSynthPatchesBlock();
		if (synthPatches != nullptr)
		{
			PatchPartBlock* patchPart = synthPatches->getPatchPartBlockPtr(m_part);
			if (patchPart != nullptr)
			{
				if (PatchCommonBlock* patchCommon = patchPart->getPatchCommonBlockPtr())
				{
				}
				PatchToneBlock* tone = nullptr;
				switch (m_tone)
				{
				case Tone1:
					if (PatchToneBlock* tone1 = patchPart->getPatchToneBlockPtr(Tone1)) tone = tone1;
					break;
				case Tone2:
					if (PatchToneBlock* tone2 = patchPart->getPatchToneBlockPtr(Tone2)) tone = tone2;
					break;
				case Tone3:
					if (PatchToneBlock* tone3 = patchPart->getPatchToneBlockPtr(Tone3)) tone = tone3;
					break;
				case Tone4:
					if (PatchToneBlock* tone4 = patchPart->getPatchToneBlockPtr(Tone4)) tone = tone4;
					break;
				}
				if (tone != nullptr)
				{
					m_toneDelayModeComboBox->setParameter(tone->getParameter(0x09));
					m_toneDelayTimeSlider->setParameter(tone->getParameter(0x0A));
				}
			}
		}
	}
    //[/Constructor]
}

ToneDelayEditor::~ToneDelayEditor()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    m_fxmGrp = nullptr;
    m_toneDelayModeLabel = nullptr;
    m_toneDelayTimeLabel = nullptr;
    imageButton2 = nullptr;
    m_toneDelayModeComboBox = nullptr;
    m_toneDelayTimeSlider = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void ToneDelayEditor::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
#ifdef JUCE_MSVC
	g;
#endif
    //[/UserPrePaint]

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void ToneDelayEditor::resized()
{
    m_fxmGrp->setBounds (0, 0, getWidth() - 0, getHeight() - 0);
    m_toneDelayModeLabel->setBounds (4, 16, 96, 16);
    m_toneDelayTimeLabel->setBounds (4, 52, 96, 16);
    imageButton2->setBounds (3, 1, 16, 16);
    m_toneDelayModeComboBox->setBounds (4, 32, 98, 16);
    m_toneDelayTimeSlider->setBounds (28, 68, 48, 60);
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void ToneDelayEditor::comboBoxChanged (ComboBox* comboBoxThatHasChanged)
{
    //[UsercomboBoxChanged_Pre]
    //[/UsercomboBoxChanged_Pre]

    if (comboBoxThatHasChanged == m_toneDelayModeComboBox)
    {
        //[UserComboBoxCode_m_toneDelayModeComboBox] -- add your combo box handling code here..
        //[/UserComboBoxCode_m_toneDelayModeComboBox]
    }

    //[UsercomboBoxChanged_Post]
    //[/UsercomboBoxChanged_Post]
}

void ToneDelayEditor::sliderValueChanged (Slider* sliderThatWasMoved)
{
    //[UsersliderValueChanged_Pre]
    //[/UsersliderValueChanged_Pre]

    if (sliderThatWasMoved == m_toneDelayTimeSlider)
    {
        //[UserSliderCode_m_toneDelayTimeSlider] -- add your slider handling code here..
        //[/UserSliderCode_m_toneDelayTimeSlider]
    }

    //[UsersliderValueChanged_Post]
    //[/UsersliderValueChanged_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Introjucer information section --

    This is where the Introjucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="ToneDelayEditor" componentName=""
                 parentClasses="public Component" constructorParams="const String &amp;componentName, SynthParts part, Tone tone"
                 variableInitialisers="Component (componentName), m_part(part), m_tone(tone)"
                 snapPixels="4" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="1" initialWidth="104" initialHeight="136">
  <BACKGROUND backgroundColour="0"/>
  <JUCERCOMP name="fxmGrp" id="ae3eed65b8ca1538" memberName="m_fxmGrp" virtualName=""
             explicitFocusOrder="0" pos="0 0 0M 0M" sourceFile="../GroupWidgets/PanelGroupGrey.cpp"
             constructorParams="&quot;ToneDlyGrp&quot;,&quot;DELAY&quot;"/>
  <LABEL name="toneDelayModeLabel" id="ebcfe4f1a9d25193" memberName="m_toneDelayModeLabel"
         virtualName="" explicitFocusOrder="0" pos="4 16 96 16" textCol="ff000000"
         edTextCol="ff000000" edBkgCol="0" labelText="DELAY MODE" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="12" bold="1" italic="0" justification="36"/>
  <LABEL name="toneDelayTimeLabel" id="d45412d60c3378d" memberName="m_toneDelayTimeLabel"
         virtualName="" explicitFocusOrder="0" pos="4 52 96 16" textCol="ff000000"
         edTextCol="ff000000" edBkgCol="0" labelText="DELAY TIME" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="12" bold="1" italic="0" justification="36"/>
  <IMAGEBUTTON name="new button" id="10a9edab841a05c0" memberName="imageButton2"
               virtualName="" explicitFocusOrder="0" pos="3 1 16 16" buttonText=""
               connectedEdges="0" needsCallback="0" radioGroupId="0" keepProportions="1"
               resourceNormal="delay_png" opacityNormal="1" colourNormal="4340454a"
               resourceOver="" opacityOver="1" colourOver="4340454a" resourceDown=""
               opacityDown="1" colourDown="4340454a"/>
  <COMBOBOX name="toneDelayModeComboBox" id="e8c10ecedfc6fd9e" memberName="m_toneDelayModeComboBox"
            virtualName="ParameterComboBox" explicitFocusOrder="0" pos="4 32 98 16"
            editable="0" layout="36" items="NORMAL&#10;HOLD&#10;PLAYMATE&#10;CLOCK-SYNC&#10;TAP-SYNC&#10;KEY-OFF-NORMAL&#10;KEY-OFF-DECAY&#10;TEMPO-SYNC"
            textWhenNonSelected="NORMAL" textWhenNoItems="(no choices)"/>
  <SLIDER name="toneDelayTimeSlider" id="85fde4b06133df0e" memberName="m_toneDelayTimeSlider"
          virtualName="Knob" explicitFocusOrder="0" pos="28 68 48 60" min="0"
          max="127" int="1" style="RotaryHorizontalVerticalDrag" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="16" skewFactor="1"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif

//==============================================================================
// Binary resources - be careful not to edit any of these sections!

// JUCER_RESOURCE: delay_png, 216, "../../../Resources/PatchEditSectionIcons/delay.png"
static const unsigned char resource_ToneDelayEditor_delay_png[] = { 137,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,0,16,0,0,0,16,8,6,0,0,0,31,243,255,97,0,0,0,1,115,82,71,66,0,174,206,28,233,0,0,0,
6,98,75,71,68,0,255,0,255,0,255,160,189,167,147,0,0,0,9,112,72,89,115,0,0,11,19,0,0,11,19,1,0,154,156,24,0,0,0,7,116,73,77,69,7,223,1,1,22,38,4,118,120,210,112,0,0,0,88,73,68,65,84,56,203,181,147,65,14,
0,33,8,3,25,226,255,191,140,151,61,184,70,205,82,220,158,153,98,77,193,30,69,68,88,66,0,166,194,47,70,129,71,19,183,162,238,25,100,162,140,179,174,64,82,4,128,149,73,251,178,229,52,211,182,229,216,192,
243,75,82,127,176,90,224,82,117,179,185,127,109,98,249,152,168,158,115,7,88,47,75,235,142,106,231,246,0,0,0,0,73,69,78,68,174,66,96,130,0,0};

const char* ToneDelayEditor::delay_png = (const char*) resource_ToneDelayEditor_delay_png;
const int ToneDelayEditor::delay_pngSize = 216;


//[EndFile] You can add extra defines here...
//[/EndFile]
