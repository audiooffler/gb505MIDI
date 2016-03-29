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

#include "RhyAmpEditor.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
extern OverallMemoryBlock* grooveboxMemory;
//[/MiscUserDefs]

//==============================================================================
RhyAmpEditor::RhyAmpEditor (const String &componentName, int toneNumber)
    : Component (componentName), m_toneNumber(toneNumber)
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    addAndMakeVisible (m_ampGrp = new PanelGroupGrey ("ampGrp", getName()));
    addAndMakeVisible (m_ampEnvGrp = new PanelGroupGrey ("ampEnvGrp", getName().toUpperCase()+" ENVELOPE"));
    addAndMakeVisible (m_tonePanSlider = new Knob ("tonePanSlider"));
    m_tonePanSlider->setRange (0, 127, 1);
    m_tonePanSlider->setSliderStyle (Slider::RotaryHorizontalVerticalDrag);
    m_tonePanSlider->setTextBoxStyle (Slider::TextBoxBelow, false, 80, 16);
    m_tonePanSlider->setColour (Slider::textBoxBackgroundColourId, Colour (0xfff2f59b));
    m_tonePanSlider->addListener (this);

    addAndMakeVisible (m_tonePanLabel = new Label ("tonePanLabel",
                                                   TRANS("TONE PAN")));
    m_tonePanLabel->setFont (Font (12.00f, Font::bold));
    m_tonePanLabel->setJustificationType (Justification::centred);
    m_tonePanLabel->setEditable (false, false, false);
    m_tonePanLabel->setColour (Label::textColourId, Colours::black);
    m_tonePanLabel->setColour (TextEditor::textColourId, Colours::black);
    m_tonePanLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_ampEnv = new Envelope ((AllParts)PartR, m_toneNumber, EnvelopeTypes::Amp, false));
    addAndMakeVisible (m_ampVelocitySensSlider = new MicroParameterSlider ("ampVelocitySensSlider"));
    m_ampVelocitySensSlider->setRange (0, 127, 1);
    m_ampVelocitySensSlider->setSliderStyle (Slider::LinearBar);
    m_ampVelocitySensSlider->setTextBoxStyle (Slider::TextBoxLeft, false, 40, 20);
    m_ampVelocitySensSlider->setColour (Slider::backgroundColourId, Colour (0xfff2f59b));
    m_ampVelocitySensSlider->setColour (Slider::thumbColourId, Colour (0xffc4c86d));
    m_ampVelocitySensSlider->addListener (this);

    addAndMakeVisible (m_ampEnvVelocitySensLabel = new Label ("ampEnvVelocitySensLabel",
                                                              TRANS("VELO SENS ENVELOPE")));
    m_ampEnvVelocitySensLabel->setFont (Font (12.00f, Font::bold));
    m_ampEnvVelocitySensLabel->setJustificationType (Justification::centred);
    m_ampEnvVelocitySensLabel->setEditable (false, false, false);
    m_ampEnvVelocitySensLabel->setColour (Label::textColourId, Colours::black);
    m_ampEnvVelocitySensLabel->setColour (TextEditor::textColourId, Colours::black);
    m_ampEnvVelocitySensLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_ampEnvVelocityTime1Slider = new MicroParameterSlider ("ampEnvVelocityTime1Slider"));
    m_ampEnvVelocityTime1Slider->setRange (0, 127, 1);
    m_ampEnvVelocityTime1Slider->setSliderStyle (Slider::LinearBar);
    m_ampEnvVelocityTime1Slider->setTextBoxStyle (Slider::TextBoxLeft, false, 40, 20);
    m_ampEnvVelocityTime1Slider->setColour (Slider::backgroundColourId, Colour (0xfff2f59b));
    m_ampEnvVelocityTime1Slider->setColour (Slider::thumbColourId, Colour (0xffc4c86d));
    m_ampEnvVelocityTime1Slider->addListener (this);

    addAndMakeVisible (m_ampEnvVelocityTime1Label = new Label ("ampEnvVelocityTime1Label",
                                                               TRANS("VELO SENS ATTACK TIME")));
    m_ampEnvVelocityTime1Label->setFont (Font (12.00f, Font::bold));
    m_ampEnvVelocityTime1Label->setJustificationType (Justification::centred);
    m_ampEnvVelocityTime1Label->setEditable (false, false, false);
    m_ampEnvVelocityTime1Label->setColour (Label::textColourId, Colours::black);
    m_ampEnvVelocityTime1Label->setColour (TextEditor::textColourId, Colours::black);
    m_ampEnvVelocityTime1Label->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_panRandomToggle = new BlackToggle());
    addAndMakeVisible (m_panRandomLabel = new Label ("panRandomLabel",
                                                     TRANS("RND PAN")));
    m_panRandomLabel->setFont (Font (12.00f, Font::bold));
    m_panRandomLabel->setJustificationType (Justification::centred);
    m_panRandomLabel->setEditable (false, false, false);
    m_panRandomLabel->setColour (Label::textColourId, Colours::black);
    m_panRandomLabel->setColour (TextEditor::textColourId, Colours::black);
    m_panRandomLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_panAlternateSlider = new MicroParameterSlider ("panAlternateSlider"));
    m_panAlternateSlider->setRange (0, 127, 1);
    m_panAlternateSlider->setSliderStyle (Slider::LinearBar);
    m_panAlternateSlider->setTextBoxStyle (Slider::TextBoxLeft, false, 40, 20);
    m_panAlternateSlider->setColour (Slider::backgroundColourId, Colour (0xfff2f59b));
    m_panAlternateSlider->setColour (Slider::thumbColourId, Colour (0xffc4c86d));
    m_panAlternateSlider->addListener (this);

    addAndMakeVisible (m_panAlternateLabel = new Label ("panAlternateLabel",
                                                        TRANS("ALTERNATE PAN")));
    m_panAlternateLabel->setFont (Font (12.00f, Font::bold));
    m_panAlternateLabel->setJustificationType (Justification::centred);
    m_panAlternateLabel->setEditable (false, false, false);
    m_panAlternateLabel->setColour (Label::textColourId, Colours::black);
    m_panAlternateLabel->setColour (TextEditor::textColourId, Colours::black);
    m_panAlternateLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_imageButton = new ImageButton ("imageButton"));
    m_imageButton->setButtonText (String());

    m_imageButton->setImages (false, true, true,
                              ImageCache::getFromMemory (amp_png, amp_pngSize), 1.000f, Colour (0x4340454a),
                              Image(), 1.000f, Colour (0x4340454a),
                              Image(), 1.000f, Colour (0x4340454a));
    addAndMakeVisible (m_toneLevelSlider = new ParameterEnvelopeSlider ("toneLevelSlider"));
    m_toneLevelSlider->setRange (0, 127, 1);
    m_toneLevelSlider->setSliderStyle (Slider::LinearVertical);
    m_toneLevelSlider->setTextBoxStyle (Slider::TextBoxBelow, false, 56, 16);
    m_toneLevelSlider->setColour (Slider::backgroundColourId, Colour (0x00f2f59b));
    m_toneLevelSlider->setColour (Slider::textBoxBackgroundColourId, Colour (0xfff2f59b));
    m_toneLevelSlider->addListener (this);

    addAndMakeVisible (m_filterEnvelopeDepthLabel = new Label ("filterEnvelopeDepthLabel",
                                                               TRANS("\n"
                                                               "LEVEL")));
    m_filterEnvelopeDepthLabel->setFont (Font (12.00f, Font::bold));
    m_filterEnvelopeDepthLabel->setJustificationType (Justification::centred);
    m_filterEnvelopeDepthLabel->setEditable (false, false, false);
    m_filterEnvelopeDepthLabel->setColour (Label::textColourId, Colours::black);
    m_filterEnvelopeDepthLabel->setColour (TextEditor::textColourId, Colours::black);
    m_filterEnvelopeDepthLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));


    //[UserPreSize]
	setupParameters(toneNumber);
    //[/UserPreSize]

    setSize (334, 334);


    //[Constructor] You can add your own custom stuff here..
    //[/Constructor]
}

RhyAmpEditor::~RhyAmpEditor()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    m_ampGrp = nullptr;
    m_ampEnvGrp = nullptr;
    m_tonePanSlider = nullptr;
    m_tonePanLabel = nullptr;
    m_ampEnv = nullptr;
    m_ampVelocitySensSlider = nullptr;
    m_ampEnvVelocitySensLabel = nullptr;
    m_ampEnvVelocityTime1Slider = nullptr;
    m_ampEnvVelocityTime1Label = nullptr;
    m_panRandomToggle = nullptr;
    m_panRandomLabel = nullptr;
    m_panAlternateSlider = nullptr;
    m_panAlternateLabel = nullptr;
    m_imageButton = nullptr;
    m_toneLevelSlider = nullptr;
    m_filterEnvelopeDepthLabel = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void RhyAmpEditor::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
#ifdef JUCE_MSVC
	g;
#endif
    //[/UserPrePaint]

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void RhyAmpEditor::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    m_ampGrp->setBounds (0, 0, getWidth() - 0, getHeight() - 0);
    m_ampEnvGrp->setBounds (0, 104, getWidth() - 0, getHeight() - 104);
    m_tonePanSlider->setBounds (40, 36, 48, 60);
    m_tonePanLabel->setBounds (28, 20, 72, 16);
    m_ampEnv->setBounds (40, 120, 292, 156);
    m_ampVelocitySensSlider->setBounds (64, 304, 56, 16);
    m_ampEnvVelocitySensLabel->setBounds (24, 288, 136, 16);
    m_ampEnvVelocityTime1Slider->setBounds (216, 304, 56, 16);
    m_ampEnvVelocityTime1Label->setBounds (176, 288, 152, 16);
    m_panRandomToggle->setBounds (148, 48, 25, 17);
    m_panRandomLabel->setBounds (112, 20, 88, 16);
    m_panAlternateSlider->setBounds (228, 48, 56, 16);
    m_panAlternateLabel->setBounds (212, 20, 100, 16);
    m_imageButton->setBounds (3, 1, 16, 16);
    m_toneLevelSlider->setBounds (4, 132, 36, 116);
    m_filterEnvelopeDepthLabel->setBounds (-4, 120, 52, 16);
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void RhyAmpEditor::sliderValueChanged (Slider* sliderThatWasMoved)
{
    //[UsersliderValueChanged_Pre]
    //[/UsersliderValueChanged_Pre]

    if (sliderThatWasMoved == m_tonePanSlider)
    {
        //[UserSliderCode_m_tonePanSlider] -- add your slider handling code here..
        //[/UserSliderCode_m_tonePanSlider]
    }
    else if (sliderThatWasMoved == m_ampVelocitySensSlider)
    {
        //[UserSliderCode_m_ampVelocitySensSlider] -- add your slider handling code here..
        //[/UserSliderCode_m_ampVelocitySensSlider]
    }
    else if (sliderThatWasMoved == m_ampEnvVelocityTime1Slider)
    {
        //[UserSliderCode_m_ampEnvVelocityTime1Slider] -- add your slider handling code here..
        //[/UserSliderCode_m_ampEnvVelocityTime1Slider]
    }
    else if (sliderThatWasMoved == m_panAlternateSlider)
    {
        //[UserSliderCode_m_panAlternateSlider] -- add your slider handling code here..
        //[/UserSliderCode_m_panAlternateSlider]
    }
    else if (sliderThatWasMoved == m_toneLevelSlider)
    {
        //[UserSliderCode_m_toneLevelSlider] -- add your slider handling code here..
        //[/UserSliderCode_m_toneLevelSlider]
    }

    //[UsersliderValueChanged_Post]
    //[/UsersliderValueChanged_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
void RhyAmpEditor::setupParameters(int toneNumber)
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
					m_toneLevelSlider->setParameter(noteBlock->getParameter(0x29));
					m_ampVelocitySensSlider->setParameter(noteBlock->getParameter(0x2A));
					m_ampEnvVelocityTime1Slider->setParameter(noteBlock->getParameter(0x2B));
					m_tonePanSlider->setParameter(noteBlock->getParameter(0x33));
					m_panRandomToggle->setParameter(noteBlock->getParameter(0x34));
					m_panAlternateSlider->setParameter(noteBlock->getParameter(0x35));
					m_ampEnv->setupParameters(PartR, toneNumber);
					m_ampGrp->setText("AMP OF RHYTHM KEY " + String(m_toneNumber));
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

<JUCER_COMPONENT documentType="Component" className="RhyAmpEditor" componentName=""
                 parentClasses="public Component" constructorParams="const String &amp;componentName, int toneNumber"
                 variableInitialisers="Component (componentName), m_toneNumber(toneNumber)"
                 snapPixels="4" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="1" initialWidth="334" initialHeight="334">
  <BACKGROUND backgroundColour="0"/>
  <JUCERCOMP name="ampGrp" id="52e00682f746b888" memberName="m_ampGrp" virtualName="PanelGroupGrey"
             explicitFocusOrder="0" pos="0 0 0M 0M" sourceFile="../GroupWidgets/PanelGroupGrey.cpp"
             constructorParams="&quot;ampGrp&quot;, getName() "/>
  <JUCERCOMP name="ampEnvGrp" id="f94b4c6bc1e7a151" memberName="m_ampEnvGrp"
             virtualName="PanelGroupGrey" explicitFocusOrder="0" pos="0 104 0M 104M"
             sourceFile="../GroupWidgets/PanelGroupTransp.cpp" constructorParams="&quot;ampEnvGrp&quot;, getName().toUpperCase()+&quot; ENVELOPE&quot;"/>
  <SLIDER name="tonePanSlider" id="533842793459863a" memberName="m_tonePanSlider"
          virtualName="Knob" explicitFocusOrder="0" pos="40 36 48 60" textboxbkgd="fff2f59b"
          min="0" max="127" int="1" style="RotaryHorizontalVerticalDrag"
          textBoxPos="TextBoxBelow" textBoxEditable="1" textBoxWidth="80"
          textBoxHeight="16" skewFactor="1"/>
  <LABEL name="tonePanLabel" id="b464bd3cbdae27fd" memberName="m_tonePanLabel"
         virtualName="" explicitFocusOrder="0" pos="28 20 72 16" textCol="ff000000"
         edTextCol="ff000000" edBkgCol="0" labelText="TONE PAN" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="12" bold="1" italic="0" justification="36"/>
  <JUCERCOMP name="ampEnv" id="99a40d72d7ad1e22" memberName="m_ampEnv" virtualName=""
             explicitFocusOrder="0" pos="40 120 292 156" sourceFile="../PatchSectionEditors/Envelope.cpp"
             constructorParams="(AllParts)PartR, m_toneNumber, EnvelopeTypes::Amp, false"/>
  <SLIDER name="ampVelocitySensSlider" id="ce3036a9c9d2d09a" memberName="m_ampVelocitySensSlider"
          virtualName="MicroParameterSlider" explicitFocusOrder="0" pos="64 304 56 16"
          bkgcol="fff2f59b" thumbcol="ffc4c86d" min="0" max="127" int="1"
          style="LinearBar" textBoxPos="TextBoxLeft" textBoxEditable="1"
          textBoxWidth="40" textBoxHeight="20" skewFactor="1"/>
  <LABEL name="ampEnvVelocitySensLabel" id="da6b2f045679c497" memberName="m_ampEnvVelocitySensLabel"
         virtualName="" explicitFocusOrder="0" pos="24 288 136 16" textCol="ff000000"
         edTextCol="ff000000" edBkgCol="0" labelText="VELO SENS ENVELOPE"
         editableSingleClick="0" editableDoubleClick="0" focusDiscardsChanges="0"
         fontname="Default font" fontsize="12" bold="1" italic="0" justification="36"/>
  <SLIDER name="ampEnvVelocityTime1Slider" id="26e8b1e9ec956faf" memberName="m_ampEnvVelocityTime1Slider"
          virtualName="MicroParameterSlider" explicitFocusOrder="0" pos="216 304 56 16"
          bkgcol="fff2f59b" thumbcol="ffc4c86d" min="0" max="127" int="1"
          style="LinearBar" textBoxPos="TextBoxLeft" textBoxEditable="1"
          textBoxWidth="40" textBoxHeight="20" skewFactor="1"/>
  <LABEL name="ampEnvVelocityTime1Label" id="fcf555c7750e1905" memberName="m_ampEnvVelocityTime1Label"
         virtualName="" explicitFocusOrder="0" pos="176 288 152 16" textCol="ff000000"
         edTextCol="ff000000" edBkgCol="0" labelText="VELO SENS ATTACK TIME"
         editableSingleClick="0" editableDoubleClick="0" focusDiscardsChanges="0"
         fontname="Default font" fontsize="12" bold="1" italic="0" justification="36"/>
  <JUCERCOMP name="panRandomToggle" id="1dee3cc7cfd57bb1" memberName="m_panRandomToggle"
             virtualName="" explicitFocusOrder="0" pos="148 48 25 17" sourceFile="../ParameterWidgets/BlackToggle.cpp"
             constructorParams=""/>
  <LABEL name="panRandomLabel" id="1e3525d1a10dd56c" memberName="m_panRandomLabel"
         virtualName="" explicitFocusOrder="0" pos="112 20 88 16" textCol="ff000000"
         edTextCol="ff000000" edBkgCol="0" labelText="RND PAN" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="12" bold="1" italic="0" justification="36"/>
  <SLIDER name="panAlternateSlider" id="7aed98a67fac3fdb" memberName="m_panAlternateSlider"
          virtualName="MicroParameterSlider" explicitFocusOrder="0" pos="228 48 56 16"
          bkgcol="fff2f59b" thumbcol="ffc4c86d" min="0" max="127" int="1"
          style="LinearBar" textBoxPos="TextBoxLeft" textBoxEditable="1"
          textBoxWidth="40" textBoxHeight="20" skewFactor="1"/>
  <LABEL name="panAlternateLabel" id="674286f7173a73be" memberName="m_panAlternateLabel"
         virtualName="" explicitFocusOrder="0" pos="212 20 100 16" textCol="ff000000"
         edTextCol="ff000000" edBkgCol="0" labelText="ALTERNATE PAN" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="12" bold="1" italic="0" justification="36"/>
  <IMAGEBUTTON name="imageButton" id="f18ffef17196cb40" memberName="m_imageButton"
               virtualName="" explicitFocusOrder="0" pos="3 1 16 16" buttonText=""
               connectedEdges="0" needsCallback="0" radioGroupId="0" keepProportions="1"
               resourceNormal="amp_png" opacityNormal="1" colourNormal="4340454a"
               resourceOver="" opacityOver="1" colourOver="4340454a" resourceDown=""
               opacityDown="1" colourDown="4340454a"/>
  <SLIDER name="toneLevelSlider" id="b0bd5a61181f569c" memberName="m_toneLevelSlider"
          virtualName="ParameterEnvelopeSlider" explicitFocusOrder="0"
          pos="4 132 36 116" bkgcol="f2f59b" textboxbkgd="fff2f59b" min="0"
          max="127" int="1" style="LinearVertical" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="56" textBoxHeight="16" skewFactor="1"/>
  <LABEL name="filterEnvelopeDepthLabel" id="611da7e96f52143f" memberName="m_filterEnvelopeDepthLabel"
         virtualName="" explicitFocusOrder="0" pos="-4 120 52 16" textCol="ff000000"
         edTextCol="ff000000" edBkgCol="0" labelText="&#10;LEVEL" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="12" bold="1" italic="0" justification="36"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif

//==============================================================================
// Binary resources - be careful not to edit any of these sections!

// JUCER_RESOURCE: amp_png, 238, "../../../Resources/PatchEditSectionIcons/amp.png"
static const unsigned char resource_RhyAmpEditor_amp_png[] = { 137,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,0,16,0,0,0,16,8,6,0,0,0,31,243,255,97,0,0,0,1,115,82,71,66,0,174,206,28,233,0,0,0,6,98,
75,71,68,0,255,0,255,0,255,160,189,167,147,0,0,0,9,112,72,89,115,0,0,11,19,0,0,11,19,1,0,154,156,24,0,0,0,7,116,73,77,69,7,222,12,10,20,17,54,201,225,103,191,0,0,0,110,73,68,65,84,56,203,165,83,209,18,
192,48,4,195,249,255,95,182,151,185,51,19,166,203,75,175,218,68,84,49,221,48,51,163,5,152,153,233,148,252,224,76,100,11,168,206,100,101,181,128,160,140,113,223,137,40,202,234,34,78,70,34,50,217,71,245,
183,14,162,109,95,179,163,177,4,20,203,66,90,246,182,233,59,116,224,182,179,8,34,190,4,242,133,137,248,249,17,39,232,246,231,245,131,113,192,225,191,227,124,1,168,181,108,17,98,157,50,130,0,0,0,0,73,69,
78,68,174,66,96,130,0,0};

const char* RhyAmpEditor::amp_png = (const char*) resource_RhyAmpEditor_amp_png;
const int RhyAmpEditor::amp_pngSize = 238;


//[EndFile] You can add extra defines here...
//[/EndFile]
