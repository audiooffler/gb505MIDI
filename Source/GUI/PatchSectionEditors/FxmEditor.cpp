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

#include "FxmEditor.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
extern OverallMemoryBlock* grooveboxMemory;
//[/MiscUserDefs]

//==============================================================================
FxmEditor::FxmEditor (const String &componentName, SynthParts part, Tone tone)
    : Component (componentName), m_part(part), m_tone(tone)
{
    addAndMakeVisible (m_fxmGrp = new PanelGroupGrey ("FXMGrp","FXM"));
    addAndMakeVisible (m_fxmToggle = new BlackToggle());
    addAndMakeVisible (m_fxmOnLabel = new Label ("fxmOnLabel",
                                                 "ON"));
    m_fxmOnLabel->setFont (Font (12.00f, Font::bold));
    m_fxmOnLabel->setJustificationType (Justification::centredRight);
    m_fxmOnLabel->setEditable (false, false, false);
    m_fxmOnLabel->setColour (Label::textColourId, Colours::black);
    m_fxmOnLabel->setColour (TextEditor::textColourId, Colours::black);
    m_fxmOnLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_fxmColorLabel = new Label ("fxmColorLabel",
                                                    "COLOR"));
    m_fxmColorLabel->setFont (Font (12.00f, Font::bold));
    m_fxmColorLabel->setJustificationType (Justification::centredRight);
    m_fxmColorLabel->setEditable (false, false, false);
    m_fxmColorLabel->setColour (Label::textColourId, Colours::black);
    m_fxmColorLabel->setColour (TextEditor::textColourId, Colours::black);
    m_fxmColorLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_fxmDepthSlider = new MicroParameterSlider ("fxmDepthSlider"));
    m_fxmDepthSlider->setRange (0, 127, 1);
    m_fxmDepthSlider->setSliderStyle (Slider::LinearBar);
    m_fxmDepthSlider->setTextBoxStyle (Slider::TextBoxLeft, false, 40, 20);
    m_fxmDepthSlider->setColour (Slider::backgroundColourId, Colour (0xfff2f59b));
    m_fxmDepthSlider->setColour (Slider::thumbColourId, Colour (0xffc4c86d));
    m_fxmDepthSlider->addListener (this);

    addAndMakeVisible (m_fxmDepthLabel = new Label ("fxmDepthLabel",
                                                    "DEPTH"));
    m_fxmDepthLabel->setFont (Font (12.00f, Font::bold));
    m_fxmDepthLabel->setJustificationType (Justification::centredRight);
    m_fxmDepthLabel->setEditable (false, false, false);
    m_fxmDepthLabel->setColour (Label::textColourId, Colours::black);
    m_fxmDepthLabel->setColour (TextEditor::textColourId, Colours::black);
    m_fxmDepthLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_imageButton = new ImageButton ("new button"));
    m_imageButton->setButtonText (String());

    m_imageButton->setImages (false, true, true,
                              ImageCache::getFromMemory (fxm_png, fxm_pngSize), 1.000f, Colour (0x4340454a),
                              Image(), 1.000f, Colour (0x4340454a),
                              Image(), 1.000f, Colour (0x4340454a));
    addAndMakeVisible (m_fxmColorComboBox = new ParameterComboBox ("fxmColorComboBox"));
    m_fxmColorComboBox->setEditableText (false);
    m_fxmColorComboBox->setJustificationType (Justification::centred);
    m_fxmColorComboBox->setTextWhenNothingSelected ("0");
    m_fxmColorComboBox->setTextWhenNoChoicesAvailable ("(no choices)");
    m_fxmColorComboBox->addItem ("0", 1);
    m_fxmColorComboBox->addItem ("1", 2);
    m_fxmColorComboBox->addItem ("2", 3);
    m_fxmColorComboBox->addItem ("3", 4);
    m_fxmColorComboBox->addListener (this);


    //[UserPreSize]
    //[/UserPreSize]

    setSize (104, 92);


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
					m_fxmToggle->setParameter(tone->getParameter(0x06));
					m_fxmColorComboBox->setParameter(tone->getParameter(0x07));
					m_fxmDepthSlider->setParameter(tone->getParameter(0x08));
				}
			}
		}
	}
    //[/Constructor]
}

FxmEditor::~FxmEditor()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    m_fxmGrp = nullptr;
    m_fxmToggle = nullptr;
    m_fxmOnLabel = nullptr;
    m_fxmColorLabel = nullptr;
    m_fxmDepthSlider = nullptr;
    m_fxmDepthLabel = nullptr;
    m_imageButton = nullptr;
    m_fxmColorComboBox = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void FxmEditor::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
#ifdef JUCE_MSVC
	g;
#endif
    //[/UserPrePaint]

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void FxmEditor::resized()
{
    m_fxmGrp->setBounds (0, 0, getWidth() - 0, getHeight() - 0);
    m_fxmToggle->setBounds (48, 20, 25, 17);
    m_fxmOnLabel->setBounds (0, 20, 48, 16);
    m_fxmColorLabel->setBounds (0, 44, 48, 16);
    m_fxmDepthSlider->setBounds (48, 68, 50, 16);
    m_fxmDepthLabel->setBounds (0, 68, 48, 16);
    m_imageButton->setBounds (3, 1, 16, 16);
    m_fxmColorComboBox->setBounds (48, 44, 50, 16);
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void FxmEditor::sliderValueChanged (Slider* sliderThatWasMoved)
{
    //[UsersliderValueChanged_Pre]
    //[/UsersliderValueChanged_Pre]

    if (sliderThatWasMoved == m_fxmDepthSlider)
    {
        //[UserSliderCode_m_fxmDepthSlider] -- add your slider handling code here..
        //[/UserSliderCode_m_fxmDepthSlider]
    }

    //[UsersliderValueChanged_Post]
    //[/UsersliderValueChanged_Post]
}

void FxmEditor::comboBoxChanged (ComboBox* comboBoxThatHasChanged)
{
    //[UsercomboBoxChanged_Pre]
    //[/UsercomboBoxChanged_Pre]

    if (comboBoxThatHasChanged == m_fxmColorComboBox)
    {
        //[UserComboBoxCode_m_fxmColorComboBox] -- add your combo box handling code here..
        //[/UserComboBoxCode_m_fxmColorComboBox]
    }

    //[UsercomboBoxChanged_Post]
    //[/UsercomboBoxChanged_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Introjucer information section --

    This is where the Introjucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="FxmEditor" componentName=""
                 parentClasses="public Component" constructorParams="const String &amp;componentName, SynthParts part, Tone tone"
                 variableInitialisers="Component (componentName), m_part(part), m_tone(tone)"
                 snapPixels="4" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="1" initialWidth="104" initialHeight="92">
  <BACKGROUND backgroundColour="0"/>
  <JUCERCOMP name="fxmGrp" id="ae3eed65b8ca1538" memberName="m_fxmGrp" virtualName=""
             explicitFocusOrder="0" pos="0 0 0M 0M" sourceFile="../GroupWidgets/PanelGroupGrey.cpp"
             constructorParams="&quot;FXMGrp&quot;,&quot;FXM&quot;"/>
  <JUCERCOMP name="fxmToggle" id="4cb4ce270163d019" memberName="m_fxmToggle"
             virtualName="" explicitFocusOrder="0" pos="48 20 25 17" sourceFile="../ParameterWidgets/BlackToggle.cpp"
             constructorParams=""/>
  <LABEL name="fxmOnLabel" id="8003d288f01ddf16" memberName="m_fxmOnLabel"
         virtualName="" explicitFocusOrder="0" pos="0 20 48 16" textCol="ff000000"
         edTextCol="ff000000" edBkgCol="0" labelText="ON" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="12" bold="1" italic="0" justification="34"/>
  <LABEL name="fxmColorLabel" id="10469cfe4109278d" memberName="m_fxmColorLabel"
         virtualName="" explicitFocusOrder="0" pos="0 44 48 16" textCol="ff000000"
         edTextCol="ff000000" edBkgCol="0" labelText="COLOR" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="12" bold="1" italic="0" justification="34"/>
  <SLIDER name="fxmDepthSlider" id="c2a5b378e06cd22d" memberName="m_fxmDepthSlider"
          virtualName="MicroParameterSlider" explicitFocusOrder="0" pos="48 68 50 16"
          bkgcol="fff2f59b" thumbcol="ffc4c86d" min="0" max="127" int="1"
          style="LinearBar" textBoxPos="TextBoxLeft" textBoxEditable="1"
          textBoxWidth="40" textBoxHeight="20" skewFactor="1"/>
  <LABEL name="fxmDepthLabel" id="2589d92458f34088" memberName="m_fxmDepthLabel"
         virtualName="" explicitFocusOrder="0" pos="0 68 48 16" textCol="ff000000"
         edTextCol="ff000000" edBkgCol="0" labelText="DEPTH" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="12" bold="1" italic="0" justification="34"/>
  <IMAGEBUTTON name="new button" id="6edd918beb7645cb" memberName="m_imageButton"
               virtualName="" explicitFocusOrder="0" pos="3 1 16 16" buttonText=""
               connectedEdges="0" needsCallback="0" radioGroupId="0" keepProportions="1"
               resourceNormal="fxm_png" opacityNormal="1" colourNormal="4340454a"
               resourceOver="" opacityOver="1" colourOver="4340454a" resourceDown=""
               opacityDown="1" colourDown="4340454a"/>
  <COMBOBOX name="fxmColorComboBox" id="e8c10ecedfc6fd9e" memberName="m_fxmColorComboBox"
            virtualName="ParameterComboBox" explicitFocusOrder="0" pos="48 44 50 16"
            editable="0" layout="36" items="0&#10;1&#10;2&#10;3" textWhenNonSelected="0"
            textWhenNoItems="(no choices)"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif

//==============================================================================
// Binary resources - be careful not to edit any of these sections!

// JUCER_RESOURCE: fxm_png, 245, "../../../Resources/PatchEditSectionIcons/fxm.png"
static const unsigned char resource_FxmEditor_fxm_png[] = { 137,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,0,16,0,0,0,16,8,6,0,0,0,31,243,255,97,0,0,0,1,115,82,71,66,0,174,206,28,233,0,0,0,6,98,75,
71,68,0,255,0,255,0,255,160,189,167,147,0,0,0,9,112,72,89,115,0,0,11,19,0,0,11,19,1,0,154,156,24,0,0,0,7,116,73,77,69,7,223,1,1,22,32,36,27,76,85,62,0,0,0,117,73,68,65,84,56,203,165,83,201,13,192,48,8,
179,17,251,175,76,63,85,68,41,87,85,94,9,135,131,49,161,153,225,182,115,88,26,1,64,93,49,63,2,24,0,106,83,108,217,139,225,110,218,20,114,227,215,172,173,142,115,204,145,134,223,198,247,0,240,200,12,5,
101,76,7,153,170,121,96,162,176,54,153,116,78,232,148,0,62,49,170,81,198,100,144,108,242,189,134,200,191,139,20,23,102,213,1,139,13,228,246,51,97,154,116,55,167,11,191,94,32,54,196,68,2,59,0,0,0,0,73,
69,78,68,174,66,96,130,0,0};

const char* FxmEditor::fxm_png = (const char*) resource_FxmEditor_fxm_png;
const int FxmEditor::fxm_pngSize = 245;


//[EndFile] You can add extra defines here...
//[/EndFile]
