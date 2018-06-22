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

#include "SoloLegatoEditor.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
extern OverallMemoryBlock* grooveboxMemory;
//[/MiscUserDefs]

//==============================================================================
SoloLegatoEditor::SoloLegatoEditor (const String &componentName, SynthParts part)
    : Component (componentName), m_part(part)
{
    addAndMakeVisible (m_soloLegatoGrp = new PanelGroupGrey ("soloLegatoGrp", getName()));
    addAndMakeVisible (m_soloGrp = new PanelGroupGrey ("soloGrp","SOLO"));
    addAndMakeVisible (m_portamentoGrp = new PanelGroupGrey ("portamentoGrp","PORTAMENTO"));
    addAndMakeVisible (m_soloToggle = new BlackToggle());
    addAndMakeVisible (m_soloLabel = new Label ("soloLabel",
                                                TRANS("On:")));
    m_soloLabel->setFont (Font (13.00f, Font::plain));
    m_soloLabel->setJustificationType (Justification::centredRight);
    m_soloLabel->setEditable (false, false, false);
    m_soloLabel->setColour (Label::textColourId, Colours::black);
    m_soloLabel->setColour (TextEditor::textColourId, Colours::black);
    m_soloLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_legatoToggle = new BlackToggle());
    addAndMakeVisible (m_legatoLabel = new Label ("legatoLabel",
                                                  TRANS("Legato:")));
    m_legatoLabel->setFont (Font (13.00f, Font::plain));
    m_legatoLabel->setJustificationType (Justification::centredRight);
    m_legatoLabel->setEditable (false, false, false);
    m_legatoLabel->setColour (Label::textColourId, Colours::black);
    m_legatoLabel->setColour (TextEditor::textColourId, Colours::black);
    m_legatoLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_portamentoToggle = new BlackToggle());
    addAndMakeVisible (m_portamentoLabel = new Label ("portamentoLabel",
                                                      TRANS("On:")));
    m_portamentoLabel->setFont (Font (13.00f, Font::plain));
    m_portamentoLabel->setJustificationType (Justification::centredRight);
    m_portamentoLabel->setEditable (false, false, false);
    m_portamentoLabel->setColour (Label::textColourId, Colours::black);
    m_portamentoLabel->setColour (TextEditor::textColourId, Colours::black);
    m_portamentoLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_portamentoModeLabel = new Label ("portamentoModeLabel",
                                                          TRANS("Mode:")));
    m_portamentoModeLabel->setFont (Font (13.00f, Font::plain));
    m_portamentoModeLabel->setJustificationType (Justification::centredLeft);
    m_portamentoModeLabel->setEditable (false, false, false);
    m_portamentoModeLabel->setColour (Label::textColourId, Colours::black);
    m_portamentoModeLabel->setColour (TextEditor::textColourId, Colours::black);
    m_portamentoModeLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_portamentoTypeLabel = new Label ("portamentoTypeLabel",
                                                          TRANS("Type:\n")));
    m_portamentoTypeLabel->setFont (Font (13.00f, Font::plain));
    m_portamentoTypeLabel->setJustificationType (Justification::centredLeft);
    m_portamentoTypeLabel->setEditable (false, false, false);
    m_portamentoTypeLabel->setColour (Label::textColourId, Colours::black);
    m_portamentoTypeLabel->setColour (TextEditor::textColourId, Colours::black);
    m_portamentoTypeLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_portamentoStartLabel = new Label ("portamentoStartLabel",
                                                           TRANS("Start:")));
    m_portamentoStartLabel->setFont (Font (13.00f, Font::plain));
    m_portamentoStartLabel->setJustificationType (Justification::centredLeft);
    m_portamentoStartLabel->setEditable (false, false, false);
    m_portamentoStartLabel->setColour (Label::textColourId, Colours::black);
    m_portamentoStartLabel->setColour (TextEditor::textColourId, Colours::black);
    m_portamentoStartLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_portamentoTimeLabel = new Label ("portamentoTimeLabel",
                                                          TRANS("Time:\n")));
    m_portamentoTimeLabel->setFont (Font (13.00f, Font::plain));
    m_portamentoTimeLabel->setJustificationType (Justification::centredRight);
    m_portamentoTimeLabel->setEditable (false, false, false);
    m_portamentoTimeLabel->setColour (Label::textColourId, Colours::black);
    m_portamentoTimeLabel->setColour (TextEditor::textColourId, Colours::black);
    m_portamentoTimeLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_portamentoTimeSlider = new MicroParameterSlider ("portamentoTimeSlider"));
    m_portamentoTimeSlider->setRange (0, 127, 1);
    m_portamentoTimeSlider->setSliderStyle (Slider::LinearBar);
    m_portamentoTimeSlider->setTextBoxStyle (Slider::TextBoxLeft, false, 40, 20);
    m_portamentoTimeSlider->setColour (Slider::backgroundColourId, Colour (0xfff2f59b));
    m_portamentoTimeSlider->setColour (Slider::thumbColourId, Colour (0xffc4c86d));
    m_portamentoTimeSlider->addListener (this);

    addAndMakeVisible (m_portamentoModeToggle = new ParameterLedSwitch ("portamentoModeToggle"));
    addAndMakeVisible (m_portamentoStartToggle = new ParameterLedSwitch ("portamentoStartToggle"));
    addAndMakeVisible (m_portamentoTypeToggle = new ParameterLedSwitch ("portamentoTypeToggle"));
    addAndMakeVisible (m_imageButton1 = new ImageButton ("imageButton1"));
    m_imageButton1->setButtonText (String());
    m_imageButton1->addListener (this);

    m_imageButton1->setImages (false, true, true,
                               ImageCache::getFromMemory (solo_png, solo_pngSize), 1.000f, Colour (0x4340454a),
                               Image(), 1.000f, Colour (0x4340454a),
                               Image(), 1.000f, Colour (0x4340454a));
    addAndMakeVisible (m_imageButton2 = new ImageButton ("imageButton2"));
    m_imageButton2->setButtonText (String());
    m_imageButton2->addListener (this);

    m_imageButton2->setImages (false, true, true,
                               ImageCache::getFromMemory (portamento_png, portamento_pngSize), 1.000f, Colour (0x4340454a),
                               Image(), 1.000f, Colour (0x4340454a),
                               Image(), 1.000f, Colour (0x4340454a));

    //[UserPreSize]
	m_soloLegatoGrp->setText("SOLO / LEGATO OF PART " + String(part + 1));
    //[/UserPreSize]

    setSize (448, 108);


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
					m_soloToggle->setParameter(patchCommon->getParameter(0x33));
					m_legatoToggle->setParameter(patchCommon->getParameter(0x34));
					m_portamentoToggle->setParameter(patchCommon->getParameter(0x35));
					m_portamentoModeToggle->setParameter(patchCommon->getParameter(0x36));
					m_portamentoTypeToggle->setParameter(patchCommon->getParameter(0x37));
					m_portamentoStartToggle->setParameter(patchCommon->getParameter(0x38));
					m_portamentoTimeSlider->setParameter(patchCommon->getParameter(0x39));
				}
			}
		}
	}
    //[/Constructor]
}

SoloLegatoEditor::~SoloLegatoEditor()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    m_soloLegatoGrp = nullptr;
    m_soloGrp = nullptr;
    m_portamentoGrp = nullptr;
    m_soloToggle = nullptr;
    m_soloLabel = nullptr;
    m_legatoToggle = nullptr;
    m_legatoLabel = nullptr;
    m_portamentoToggle = nullptr;
    m_portamentoLabel = nullptr;
    m_portamentoModeLabel = nullptr;
    m_portamentoTypeLabel = nullptr;
    m_portamentoStartLabel = nullptr;
    m_portamentoTimeLabel = nullptr;
    m_portamentoTimeSlider = nullptr;
    m_portamentoModeToggle = nullptr;
    m_portamentoStartToggle = nullptr;
    m_portamentoTypeToggle = nullptr;
    m_imageButton1 = nullptr;
    m_imageButton2 = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void SoloLegatoEditor::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
	#ifdef JUCE_MSVC
	g;
	#endif
    //[/UserPrePaint]

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void SoloLegatoEditor::resized()
{
    m_soloLegatoGrp->setBounds (0, 0, getWidth() - 0, getHeight() - 0);
    m_soloGrp->setBounds (9, 22, 92, 76);
    m_portamentoGrp->setBounds (109, 22, 332, 76);
    m_soloToggle->setBounds (65, 46, 25, 17);
    m_soloLabel->setBounds (21, 42, 40, 24);
    m_legatoToggle->setBounds (65, 74, 25, 17);
    m_legatoLabel->setBounds (9, 70, 52, 24);
    m_portamentoToggle->setBounds (157, 46, 25, 17);
    m_portamentoLabel->setBounds (113, 42, 40, 24);
    m_portamentoModeLabel->setBounds (217, 42, 48, 24);
    m_portamentoTypeLabel->setBounds (297, 42, 47, 24);
    m_portamentoStartLabel->setBounds (365, 42, 48, 24);
    m_portamentoTimeLabel->setBounds (109, 70, 44, 24);
    m_portamentoTimeSlider->setBounds (157, 74, 56, 16);
    m_portamentoModeToggle->setBounds (229, 62, 72, 32);
    m_portamentoStartToggle->setBounds (377, 62, 60, 32);
    m_portamentoTypeToggle->setBounds (309, 62, 72, 32);
    m_imageButton1->setBounds (12, 23, 16, 16);
    m_imageButton2->setBounds (112, 23, 16, 16);
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void SoloLegatoEditor::sliderValueChanged (Slider* sliderThatWasMoved)
{
    //[UsersliderValueChanged_Pre]
    //[/UsersliderValueChanged_Pre]

    if (sliderThatWasMoved == m_portamentoTimeSlider)
    {
        //[UserSliderCode_m_portamentoTimeSlider] -- add your slider handling code here..
        //[/UserSliderCode_m_portamentoTimeSlider]
    }

    //[UsersliderValueChanged_Post]
    //[/UsersliderValueChanged_Post]
}

void SoloLegatoEditor::buttonClicked (Button* buttonThatWasClicked)
{
    //[UserbuttonClicked_Pre]
    //[/UserbuttonClicked_Pre]

    if (buttonThatWasClicked == m_imageButton1)
    {
        //[UserButtonCode_m_imageButton1] -- add your button handler code here..
        //[/UserButtonCode_m_imageButton1]
    }
    else if (buttonThatWasClicked == m_imageButton2)
    {
        //[UserButtonCode_m_imageButton2] -- add your button handler code here..
        //[/UserButtonCode_m_imageButton2]
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

<JUCER_COMPONENT documentType="Component" className="SoloLegatoEditor" componentName=""
                 parentClasses="public Component" constructorParams="const String &amp;componentName, SynthParts part"
                 variableInitialisers="Component (componentName), m_part(part)"
                 snapPixels="4" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="1" initialWidth="448" initialHeight="108">
  <BACKGROUND backgroundColour="0"/>
  <JUCERCOMP name="soloLegatoGrp" id="52e00682f746b888" memberName="m_soloLegatoGrp"
             virtualName="PanelGroupGrey" explicitFocusOrder="0" pos="0 0 0M 0M"
             sourceFile="../GroupWidgets/PanelGroupGrey.cpp" constructorParams="&quot;soloLegatoGrp&quot;, getName()"/>
  <JUCERCOMP name="soloGrp" id="2e9d58ccbfd35887" memberName="m_soloGrp" virtualName=""
             explicitFocusOrder="0" pos="9 22 92 76" sourceFile="../GroupWidgets/PanelGroupGrey.cpp"
             constructorParams="&quot;soloGrp&quot;,&quot;SOLO&quot;"/>
  <JUCERCOMP name="portamentoGrp" id="688c1bd4d751943e" memberName="m_portamentoGrp"
             virtualName="" explicitFocusOrder="0" pos="109 22 332 76" sourceFile="../GroupWidgets/PanelGroupGrey.cpp"
             constructorParams="&quot;portamentoGrp&quot;,&quot;PORTAMENTO&quot;"/>
  <JUCERCOMP name="soloToggle" id="b0e7322ed6fe4133" memberName="m_soloToggle"
             virtualName="" explicitFocusOrder="0" pos="65 46 25 17" sourceFile="../ParameterWidgets/BlackToggle.cpp"
             constructorParams=""/>
  <LABEL name="soloLabel" id="a5103dfa4b0cded3" memberName="m_soloLabel"
         virtualName="" explicitFocusOrder="0" pos="21 42 40 24" textCol="ff000000"
         edTextCol="ff000000" edBkgCol="0" labelText="On:" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="13" bold="0" italic="0" justification="34"/>
  <JUCERCOMP name="legatoToggle" id="101b6dfe21e47435" memberName="m_legatoToggle"
             virtualName="" explicitFocusOrder="0" pos="65 74 25 17" sourceFile="../ParameterWidgets/BlackToggle.cpp"
             constructorParams=""/>
  <LABEL name="legatoLabel" id="76a4d5a485328d10" memberName="m_legatoLabel"
         virtualName="" explicitFocusOrder="0" pos="9 70 52 24" textCol="ff000000"
         edTextCol="ff000000" edBkgCol="0" labelText="Legato:" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="13" bold="0" italic="0" justification="34"/>
  <JUCERCOMP name="portamentoToggle" id="1d7902cb6f52a8a2" memberName="m_portamentoToggle"
             virtualName="" explicitFocusOrder="0" pos="157 46 25 17" sourceFile="../ParameterWidgets/BlackToggle.cpp"
             constructorParams=""/>
  <LABEL name="portamentoLabel" id="15bb703d1743a96b" memberName="m_portamentoLabel"
         virtualName="" explicitFocusOrder="0" pos="113 42 40 24" textCol="ff000000"
         edTextCol="ff000000" edBkgCol="0" labelText="On:" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="13" bold="0" italic="0" justification="34"/>
  <LABEL name="portamentoModeLabel" id="c41c307042cbea72" memberName="m_portamentoModeLabel"
         virtualName="" explicitFocusOrder="0" pos="217 42 48 24" textCol="ff000000"
         edTextCol="ff000000" edBkgCol="0" labelText="Mode:" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="13" bold="0" italic="0" justification="33"/>
  <LABEL name="portamentoTypeLabel" id="1eee1fab7ef6feb4" memberName="m_portamentoTypeLabel"
         virtualName="" explicitFocusOrder="0" pos="297 42 47 24" textCol="ff000000"
         edTextCol="ff000000" edBkgCol="0" labelText="Type:&#10;" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="13" bold="0" italic="0" justification="33"/>
  <LABEL name="portamentoStartLabel" id="5d3759be3930cbf3" memberName="m_portamentoStartLabel"
         virtualName="" explicitFocusOrder="0" pos="365 42 48 24" textCol="ff000000"
         edTextCol="ff000000" edBkgCol="0" labelText="Start:" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="13" bold="0" italic="0" justification="33"/>
  <LABEL name="portamentoTimeLabel" id="36bd09dce45510d" memberName="m_portamentoTimeLabel"
         virtualName="" explicitFocusOrder="0" pos="109 70 44 24" textCol="ff000000"
         edTextCol="ff000000" edBkgCol="0" labelText="Time:&#10;" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="13" bold="0" italic="0" justification="34"/>
  <SLIDER name="portamentoTimeSlider" id="e251907fb7141880" memberName="m_portamentoTimeSlider"
          virtualName="MicroParameterSlider" explicitFocusOrder="0" pos="157 74 56 16"
          bkgcol="fff2f59b" thumbcol="ffc4c86d" min="0" max="127" int="1"
          style="LinearBar" textBoxPos="TextBoxLeft" textBoxEditable="1"
          textBoxWidth="40" textBoxHeight="20" skewFactor="1"/>
  <JUCERCOMP name="portamentoModeToggle" id="4908ea75bd365f13" memberName="m_portamentoModeToggle"
             virtualName="" explicitFocusOrder="0" pos="229 62 72 32" sourceFile="../ParameterWidgets/ParameterLedSwitch.cpp"
             constructorParams="&quot;portamentoModeToggle&quot;"/>
  <JUCERCOMP name="portamentoStartToggle" id="9a34427c7e76a132" memberName="m_portamentoStartToggle"
             virtualName="" explicitFocusOrder="0" pos="377 62 60 32" sourceFile="../ParameterWidgets/ParameterLedSwitch.cpp"
             constructorParams="&quot;portamentoStartToggle&quot;"/>
  <JUCERCOMP name="portamentoTypeToggle" id="1aa041db35c9f2f2" memberName="m_portamentoTypeToggle"
             virtualName="" explicitFocusOrder="0" pos="309 62 72 32" sourceFile="../ParameterWidgets/ParameterLedSwitch.cpp"
             constructorParams="&quot;portamentoTypeToggle&quot;"/>
  <IMAGEBUTTON name="imageButton1" id="b10a65e5bda82a98" memberName="m_imageButton1"
               virtualName="" explicitFocusOrder="0" pos="12 23 16 16" buttonText=""
               connectedEdges="0" needsCallback="1" radioGroupId="0" keepProportions="1"
               resourceNormal="solo_png" opacityNormal="1" colourNormal="4340454a"
               resourceOver="" opacityOver="1" colourOver="4340454a" resourceDown=""
               opacityDown="1" colourDown="4340454a"/>
  <IMAGEBUTTON name="imageButton2" id="b65b49f61860262f" memberName="m_imageButton2"
               virtualName="" explicitFocusOrder="0" pos="112 23 16 16" buttonText=""
               connectedEdges="0" needsCallback="1" radioGroupId="0" keepProportions="1"
               resourceNormal="portamento_png" opacityNormal="1" colourNormal="4340454a"
               resourceOver="" opacityOver="1" colourOver="4340454a" resourceDown=""
               opacityDown="1" colourDown="4340454a"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif

//==============================================================================
// Binary resources - be careful not to edit any of these sections!

// JUCER_RESOURCE: solo_png, 233, "../../../Resources/PatchEditSectionIcons/solo.png"
static const unsigned char resource_SoloLegatoEditor_solo_png[] = { 137,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,0,16,0,0,0,16,8,6,0,0,0,31,243,255,97,0,0,0,1,115,82,71,66,0,174,206,28,233,0,0,0,
6,98,75,71,68,0,255,0,255,0,255,160,189,167,147,0,0,0,9,112,72,89,115,0,0,11,19,0,0,11,19,1,0,154,156,24,0,0,0,7,116,73,77,69,7,222,12,10,20,19,7,170,9,5,7,0,0,0,105,73,68,65,84,56,203,181,83,65,14,128,
48,8,163,196,255,127,185,94,88,194,16,156,138,235,101,25,161,13,45,1,98,32,73,121,1,0,144,175,228,137,147,145,43,65,26,252,95,179,38,0,200,68,166,177,13,42,77,236,21,24,54,188,157,104,67,87,171,242,153,
100,185,232,147,244,163,160,175,29,49,253,223,50,24,98,241,45,5,170,221,111,95,227,37,184,187,41,202,222,206,49,161,123,206,39,14,54,103,229,37,165,45,72,0,0,0,0,73,69,78,68,174,66,96,130,0,0};

const char* SoloLegatoEditor::solo_png = (const char*) resource_SoloLegatoEditor_solo_png;
const int SoloLegatoEditor::solo_pngSize = 233;

// JUCER_RESOURCE: portamento_png, 224, "../../../Resources/PatchEditSectionIcons/portamento.png"
static const unsigned char resource_SoloLegatoEditor_portamento_png[] = { 137,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,0,16,0,0,0,16,8,6,0,0,0,31,243,255,97,0,0,0,1,115,82,71,66,0,174,206,28,233,
0,0,0,6,98,75,71,68,0,255,0,255,0,255,160,189,167,147,0,0,0,9,112,72,89,115,0,0,11,19,0,0,11,19,1,0,154,156,24,0,0,0,7,116,73,77,69,7,222,12,10,20,19,23,183,190,21,99,0,0,0,96,73,68,65,84,56,203,165,147,
73,14,192,48,8,3,177,213,255,127,153,94,90,137,44,45,134,248,26,205,196,68,4,246,196,221,221,10,1,0,235,194,3,211,129,163,132,29,40,94,202,207,106,127,181,67,88,154,119,243,128,60,129,83,193,11,207,144,
36,80,224,180,65,6,47,130,56,175,2,15,130,238,66,177,82,123,119,118,85,43,203,27,166,50,56,253,206,55,49,229,71,255,134,170,242,114,0,0,0,0,73,69,78,68,174,66,96,130,0,0};

const char* SoloLegatoEditor::portamento_png = (const char*) resource_SoloLegatoEditor_portamento_png;
const int SoloLegatoEditor::portamento_pngSize = 224;


//[EndFile] You can add extra defines here...
//[/EndFile]
