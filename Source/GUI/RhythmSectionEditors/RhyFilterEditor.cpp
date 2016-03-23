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

#include "RhyFilterEditor.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
extern OverallMemoryBlock* grooveboxMemory;
//[/MiscUserDefs]

//==============================================================================
RhyFilterEditor::RhyFilterEditor (const String &componentName, int toneNumber)
    : Component (componentName),  m_toneNumber(toneNumber)
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    addAndMakeVisible (m_filterGrp = new PanelGroupGrey ("filterGrp", getName()));
    addAndMakeVisible (m_filterGrp2 = new PanelGroupGrey ("filterEnvGrp", getName().toUpperCase()+" ENVELOPE"));
    addAndMakeVisible (m_cutoffSlider = new Knob ("cutoffSlider"));
    m_cutoffSlider->setRange (0, 127, 1);
    m_cutoffSlider->setSliderStyle (Slider::RotaryHorizontalVerticalDrag);
    m_cutoffSlider->setTextBoxStyle (Slider::TextBoxBelow, false, 80, 16);
    m_cutoffSlider->setColour (Slider::textBoxBackgroundColourId, Colour (0xfff2f59b));
    m_cutoffSlider->addListener (this);

    addAndMakeVisible (m_cutoffLabel = new Label ("cutoffLabel",
                                                  TRANS("CUTOFF")));
    m_cutoffLabel->setFont (Font (12.00f, Font::bold));
    m_cutoffLabel->setJustificationType (Justification::centred);
    m_cutoffLabel->setEditable (false, false, false);
    m_cutoffLabel->setColour (Label::textColourId, Colours::black);
    m_cutoffLabel->setColour (TextEditor::textColourId, Colours::black);
    m_cutoffLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_filterEnv = new Envelope ((AllParts)PartR, m_toneNumber, EnvelopeTypes::Filter, false));
    addAndMakeVisible (m_filterEnvelopeDepthSlider = new ParameterEnvelopeSlider ("filterEnvelopeDepthSlider"));
    m_filterEnvelopeDepthSlider->setRange (0, 127, 1);
    m_filterEnvelopeDepthSlider->setSliderStyle (Slider::LinearVertical);
    m_filterEnvelopeDepthSlider->setTextBoxStyle (Slider::TextBoxBelow, false, 56, 16);
    m_filterEnvelopeDepthSlider->setColour (Slider::backgroundColourId, Colour (0x00f2f59b));
    m_filterEnvelopeDepthSlider->setColour (Slider::textBoxBackgroundColourId, Colour (0xfff2f59b));
    m_filterEnvelopeDepthSlider->addListener (this);

    addAndMakeVisible (m_filterEnvelopeDepthLabel = new Label ("filterEnvelopeDepthLabel",
                                                               TRANS("DEPTH")));
    m_filterEnvelopeDepthLabel->setFont (Font (12.00f, Font::bold));
    m_filterEnvelopeDepthLabel->setJustificationType (Justification::centred);
    m_filterEnvelopeDepthLabel->setEditable (false, false, false);
    m_filterEnvelopeDepthLabel->setColour (Label::textColourId, Colours::black);
    m_filterEnvelopeDepthLabel->setColour (TextEditor::textColourId, Colours::black);
    m_filterEnvelopeDepthLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_filterVelocitySensSlider = new MicroParameterSlider ("filterVelocitySensSlider"));
    m_filterVelocitySensSlider->setRange (0, 127, 1);
    m_filterVelocitySensSlider->setSliderStyle (Slider::LinearBar);
    m_filterVelocitySensSlider->setTextBoxStyle (Slider::TextBoxLeft, false, 40, 20);
    m_filterVelocitySensSlider->setColour (Slider::backgroundColourId, Colour (0xfff2f59b));
    m_filterVelocitySensSlider->setColour (Slider::thumbColourId, Colour (0xffc4c86d));
    m_filterVelocitySensSlider->addListener (this);

    addAndMakeVisible (m_filterEnvVelocitySensLabel = new Label ("filterEnvVelocitySensLabel",
                                                                 TRANS("VELO SENS")));
    m_filterEnvVelocitySensLabel->setFont (Font (12.00f, Font::bold));
    m_filterEnvVelocitySensLabel->setJustificationType (Justification::centred);
    m_filterEnvVelocitySensLabel->setEditable (false, false, false);
    m_filterEnvVelocitySensLabel->setColour (Label::textColourId, Colours::black);
    m_filterEnvVelocitySensLabel->setColour (TextEditor::textColourId, Colours::black);
    m_filterEnvVelocitySensLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_filterEnvVelocityTime1Slider = new MicroParameterSlider ("filterEnvVelocityTime1Slider"));
    m_filterEnvVelocityTime1Slider->setRange (0, 127, 1);
    m_filterEnvVelocityTime1Slider->setSliderStyle (Slider::LinearBar);
    m_filterEnvVelocityTime1Slider->setTextBoxStyle (Slider::TextBoxLeft, false, 40, 20);
    m_filterEnvVelocityTime1Slider->setColour (Slider::backgroundColourId, Colour (0xfff2f59b));
    m_filterEnvVelocityTime1Slider->setColour (Slider::thumbColourId, Colour (0xffc4c86d));
    m_filterEnvVelocityTime1Slider->addListener (this);

    addAndMakeVisible (m_filterEnvVelocityTime1Label = new Label ("filterEnvVelocityTime1Label",
                                                                  TRANS("VELO SENS ATTACK TIME")));
    m_filterEnvVelocityTime1Label->setFont (Font (12.00f, Font::bold));
    m_filterEnvVelocityTime1Label->setJustificationType (Justification::centred);
    m_filterEnvVelocityTime1Label->setEditable (false, false, false);
    m_filterEnvVelocityTime1Label->setColour (Label::textColourId, Colours::black);
    m_filterEnvVelocityTime1Label->setColour (TextEditor::textColourId, Colours::black);
    m_filterEnvVelocityTime1Label->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_resonanceSlider = new Knob ("resonanceSlider"));
    m_resonanceSlider->setRange (0, 127, 1);
    m_resonanceSlider->setSliderStyle (Slider::RotaryHorizontalVerticalDrag);
    m_resonanceSlider->setTextBoxStyle (Slider::TextBoxBelow, false, 80, 16);
    m_resonanceSlider->setColour (Slider::textBoxBackgroundColourId, Colour (0xfff2f59b));
    m_resonanceSlider->addListener (this);

    addAndMakeVisible (m_resonanceLabel = new Label ("resonanceLabel",
                                                     TRANS("RESONANCE")));
    m_resonanceLabel->setFont (Font (12.00f, Font::bold));
    m_resonanceLabel->setJustificationType (Justification::centred);
    m_resonanceLabel->setEditable (false, false, false);
    m_resonanceLabel->setColour (Label::textColourId, Colours::black);
    m_resonanceLabel->setColour (TextEditor::textColourId, Colours::black);
    m_resonanceLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_resonanceVelocitySensLabel = new Label ("resonanceVelocitySensLabel",
                                                                 TRANS("RESONANCE\n"
                                                                 "VELOCITY SENS")));
    m_resonanceVelocitySensLabel->setFont (Font (12.00f, Font::bold));
    m_resonanceVelocitySensLabel->setJustificationType (Justification::centred);
    m_resonanceVelocitySensLabel->setEditable (false, false, false);
    m_resonanceVelocitySensLabel->setColour (Label::textColourId, Colours::black);
    m_resonanceVelocitySensLabel->setColour (TextEditor::textColourId, Colours::black);
    m_resonanceVelocitySensLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_resonanceVelocitySensSlider = new MicroParameterSlider ("resonanceVelocitySensSlider"));
    m_resonanceVelocitySensSlider->setRange (0, 127, 1);
    m_resonanceVelocitySensSlider->setSliderStyle (Slider::LinearBar);
    m_resonanceVelocitySensSlider->setTextBoxStyle (Slider::TextBoxLeft, false, 40, 20);
    m_resonanceVelocitySensSlider->setColour (Slider::backgroundColourId, Colour (0xfff2f59b));
    m_resonanceVelocitySensSlider->setColour (Slider::thumbColourId, Colour (0xffc4c86d));
    m_resonanceVelocitySensSlider->addListener (this);

    addAndMakeVisible (m_filterTypeLabel = new Label ("filterTypeLabel",
                                                      TRANS("FILTER TYPE")));
    m_filterTypeLabel->setFont (Font (12.00f, Font::bold));
    m_filterTypeLabel->setJustificationType (Justification::centred);
    m_filterTypeLabel->setEditable (false, false, false);
    m_filterTypeLabel->setColour (Label::textColourId, Colours::black);
    m_filterTypeLabel->setColour (TextEditor::textColourId, Colours::black);
    m_filterTypeLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_filterTypeComboBox = new ParameterComboBox ("filterTypeComboBox"));
    m_filterTypeComboBox->setEditableText (false);
    m_filterTypeComboBox->setJustificationType (Justification::centred);
    m_filterTypeComboBox->setTextWhenNothingSelected (String());
    m_filterTypeComboBox->setTextWhenNoChoicesAvailable (TRANS("(no choices)"));
    m_filterTypeComboBox->addListener (this);

    addAndMakeVisible (m_imageButton = new ImageButton ("imageButton"));
    m_imageButton->setButtonText (String());

    m_imageButton->setImages (false, true, true,
                              ImageCache::getFromMemory (filter_png, filter_pngSize), 1.000f, Colour (0x4340454a),
                              Image(), 1.000f, Colour (0x4340454a),
                              Image(), 1.000f, Colour (0x4340454a));

    //[UserPreSize]
    setupParameters(toneNumber);
    //[/UserPreSize]

    setSize (376, 324);


    //[Constructor] You can add your own custom stuff here..
    //[/Constructor]
}

RhyFilterEditor::~RhyFilterEditor()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
	if (m_filterTypeComboBox->getParamPtr() != nullptr)m_filterTypeComboBox->getParamPtr()->removeChangeListener(m_filterTypeComboBox);
	if (m_cutoffSlider->getParamPtr() != nullptr)m_cutoffSlider->getParamPtr()->removeChangeListener(m_cutoffSlider);
	if (m_resonanceSlider->getParamPtr() != nullptr)m_resonanceSlider->getParamPtr()->removeChangeListener(m_resonanceSlider);
	if (m_resonanceVelocitySensSlider->getParamPtr() != nullptr)m_resonanceVelocitySensSlider->getParamPtr()->removeChangeListener(m_resonanceVelocitySensSlider);
	if (m_filterEnvelopeDepthSlider->getParamPtr() != nullptr)m_filterEnvelopeDepthSlider->getParamPtr()->removeChangeListener(m_filterEnvelopeDepthSlider);
	if (m_filterVelocitySensSlider->getParamPtr() != nullptr)m_filterVelocitySensSlider->getParamPtr()->removeChangeListener(m_filterVelocitySensSlider);
	if (m_filterEnvVelocityTime1Slider->getParamPtr() != nullptr)m_filterEnvVelocityTime1Slider->getParamPtr()->removeChangeListener(m_filterEnvVelocityTime1Slider);
    //[/Destructor_pre]

    m_filterGrp = nullptr;
    m_filterGrp2 = nullptr;
    m_cutoffSlider = nullptr;
    m_cutoffLabel = nullptr;
    m_filterEnv = nullptr;
    m_filterEnvelopeDepthSlider = nullptr;
    m_filterEnvelopeDepthLabel = nullptr;
    m_filterVelocitySensSlider = nullptr;
    m_filterEnvVelocitySensLabel = nullptr;
    m_filterEnvVelocityTime1Slider = nullptr;
    m_filterEnvVelocityTime1Label = nullptr;
    m_resonanceSlider = nullptr;
    m_resonanceLabel = nullptr;
    m_resonanceVelocitySensLabel = nullptr;
    m_resonanceVelocitySensSlider = nullptr;
    m_filterTypeLabel = nullptr;
    m_filterTypeComboBox = nullptr;
    m_imageButton = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void RhyFilterEditor::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
	#ifdef JUCE_MSVC
	g;
	#endif
    //[/UserPrePaint]

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void RhyFilterEditor::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    m_filterGrp->setBounds (0, 0, getWidth() - 0, getHeight() - 0);
    m_filterGrp2->setBounds (0, 104, getWidth() - 0, 220);
    m_cutoffSlider->setBounds (112, 36, 48, 60);
    m_cutoffLabel->setBounds (108, 20, 56, 16);
    m_filterEnv->setBounds (72, 120, 296, 156);
    m_filterEnvelopeDepthSlider->setBounds (8, 132, 56, 116);
    m_filterEnvelopeDepthLabel->setBounds (12, 120, 48, 16);
    m_filterVelocitySensSlider->setBounds (8, 270, 56, 16);
    m_filterEnvVelocitySensLabel->setBounds (0, 254, 72, 16);
    m_filterEnvVelocityTime1Slider->setBounds (124, 296, 56, 16);
    m_filterEnvVelocityTime1Label->setBounds (84, 280, 152, 16);
    m_resonanceSlider->setBounds (204, 36, 48, 60);
    m_resonanceLabel->setBounds (188, 20, 80, 16);
    m_resonanceVelocitySensLabel->setBounds (268, 48, 100, 28);
    m_resonanceVelocitySensSlider->setBounds (292, 80, 48, 16);
    m_filterTypeLabel->setBounds (4, 20, 84, 16);
    m_filterTypeComboBox->setBounds (8, 48, 76, 16);
    m_imageButton->setBounds (3, 1, 16, 16);
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void RhyFilterEditor::sliderValueChanged (Slider* sliderThatWasMoved)
{
    //[UsersliderValueChanged_Pre]
    //[/UsersliderValueChanged_Pre]

    if (sliderThatWasMoved == m_cutoffSlider)
    {
        //[UserSliderCode_m_cutoffSlider] -- add your slider handling code here..
        //[/UserSliderCode_m_cutoffSlider]
    }
    else if (sliderThatWasMoved == m_filterEnvelopeDepthSlider)
    {
        //[UserSliderCode_m_filterEnvelopeDepthSlider] -- add your slider handling code here..
        //[/UserSliderCode_m_filterEnvelopeDepthSlider]
    }
    else if (sliderThatWasMoved == m_filterVelocitySensSlider)
    {
        //[UserSliderCode_m_filterVelocitySensSlider] -- add your slider handling code here..
        //[/UserSliderCode_m_filterVelocitySensSlider]
    }
    else if (sliderThatWasMoved == m_filterEnvVelocityTime1Slider)
    {
        //[UserSliderCode_m_filterEnvVelocityTime1Slider] -- add your slider handling code here..
        //[/UserSliderCode_m_filterEnvVelocityTime1Slider]
    }
    else if (sliderThatWasMoved == m_resonanceSlider)
    {
        //[UserSliderCode_m_resonanceSlider] -- add your slider handling code here..
        //[/UserSliderCode_m_resonanceSlider]
    }
    else if (sliderThatWasMoved == m_resonanceVelocitySensSlider)
    {
        //[UserSliderCode_m_resonanceVelocitySensSlider] -- add your slider handling code here..
        //[/UserSliderCode_m_resonanceVelocitySensSlider]
    }

    //[UsersliderValueChanged_Post]
    //[/UsersliderValueChanged_Post]
}

void RhyFilterEditor::comboBoxChanged (ComboBox* comboBoxThatHasChanged)
{
    //[UsercomboBoxChanged_Pre]
    //[/UsercomboBoxChanged_Pre]

    if (comboBoxThatHasChanged == m_filterTypeComboBox)
    {
        //[UserComboBoxCode_m_filterTypeComboBox] -- add your combo box handling code here..
        //[/UserComboBoxCode_m_filterTypeComboBox]
    }

    //[UsercomboBoxChanged_Post]
    //[/UsercomboBoxChanged_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
void RhyFilterEditor::setupParameters(int toneNumber)
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
					m_filterTypeComboBox->setParameter(noteBlock->getParameter(0x1A));
					m_cutoffSlider->setParameter(noteBlock->getParameter(0x1B));
					m_resonanceSlider->setParameter(noteBlock->getParameter(0x1C));
					m_resonanceVelocitySensSlider->setParameter(noteBlock->getParameter(0x1D));
					m_filterEnvelopeDepthSlider->setParameter(noteBlock->getParameter(0x1E));
					m_filterVelocitySensSlider->setParameter(noteBlock->getParameter(0x1F));
					m_filterEnvVelocityTime1Slider->setParameter(noteBlock->getParameter(0x20));
					m_filterEnv->setupParameters(PartR, toneNumber);
					m_filterGrp->setText("FILTER OF RHYTHM KEY " + String(m_toneNumber));
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

<JUCER_COMPONENT documentType="Component" className="RhyFilterEditor" componentName=""
                 parentClasses="public Component" constructorParams="const String &amp;componentName, int toneNumber"
                 variableInitialisers="Component (componentName),  m_toneNumber(toneNumber)"
                 snapPixels="4" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="1" initialWidth="376" initialHeight="324">
  <BACKGROUND backgroundColour="0"/>
  <JUCERCOMP name="filterGrp" id="52e00682f746b888" memberName="m_filterGrp"
             virtualName="PanelGroupGrey" explicitFocusOrder="0" pos="0 0 0M 0M"
             sourceFile="../GroupWidgets/PanelGroupGrey.cpp" constructorParams="&quot;filterGrp&quot;, getName() "/>
  <JUCERCOMP name="filterGrp" id="f94b4c6bc1e7a151" memberName="m_filterGrp2"
             virtualName="PanelGroupGrey" explicitFocusOrder="0" pos="0 104 0M 220"
             sourceFile="../GroupWidgets/PanelGroupTransp.cpp" constructorParams="&quot;filterEnvGrp&quot;, getName().toUpperCase()+&quot; ENVELOPE&quot;"/>
  <SLIDER name="cutoffSlider" id="533842793459863a" memberName="m_cutoffSlider"
          virtualName="Knob" explicitFocusOrder="0" pos="112 36 48 60"
          textboxbkgd="fff2f59b" min="0" max="127" int="1" style="RotaryHorizontalVerticalDrag"
          textBoxPos="TextBoxBelow" textBoxEditable="1" textBoxWidth="80"
          textBoxHeight="16" skewFactor="1"/>
  <LABEL name="cutoffLabel" id="b464bd3cbdae27fd" memberName="m_cutoffLabel"
         virtualName="" explicitFocusOrder="0" pos="108 20 56 16" textCol="ff000000"
         edTextCol="ff000000" edBkgCol="0" labelText="CUTOFF" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="12" bold="1" italic="0" justification="36"/>
  <JUCERCOMP name="filterEnv" id="99a40d72d7ad1e22" memberName="m_filterEnv"
             virtualName="" explicitFocusOrder="0" pos="72 120 296 156" sourceFile="../PatchSectionEditors/Envelope.cpp"
             constructorParams="(AllParts)PartR, m_toneNumber, EnvelopeTypes::Filter, false"/>
  <SLIDER name="filterEnvelopeDepthSlider" id="b0bd5a61181f569c" memberName="m_filterEnvelopeDepthSlider"
          virtualName="ParameterEnvelopeSlider" explicitFocusOrder="0"
          pos="8 132 56 116" bkgcol="f2f59b" textboxbkgd="fff2f59b" min="0"
          max="127" int="1" style="LinearVertical" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="56" textBoxHeight="16" skewFactor="1"/>
  <LABEL name="filterEnvelopeDepthLabel" id="611da7e96f52143f" memberName="m_filterEnvelopeDepthLabel"
         virtualName="" explicitFocusOrder="0" pos="12 120 48 16" textCol="ff000000"
         edTextCol="ff000000" edBkgCol="0" labelText="DEPTH" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="12" bold="1" italic="0" justification="36"/>
  <SLIDER name="filterVelocitySensSlider" id="ce3036a9c9d2d09a" memberName="m_filterVelocitySensSlider"
          virtualName="MicroParameterSlider" explicitFocusOrder="0" pos="8 270 56 16"
          bkgcol="fff2f59b" thumbcol="ffc4c86d" min="0" max="127" int="1"
          style="LinearBar" textBoxPos="TextBoxLeft" textBoxEditable="1"
          textBoxWidth="40" textBoxHeight="20" skewFactor="1"/>
  <LABEL name="filterEnvVelocitySensLabel" id="da6b2f045679c497" memberName="m_filterEnvVelocitySensLabel"
         virtualName="" explicitFocusOrder="0" pos="0 254 72 16" textCol="ff000000"
         edTextCol="ff000000" edBkgCol="0" labelText="VELO SENS" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="12" bold="1" italic="0" justification="36"/>
  <SLIDER name="filterEnvVelocityTime1Slider" id="26e8b1e9ec956faf" memberName="m_filterEnvVelocityTime1Slider"
          virtualName="MicroParameterSlider" explicitFocusOrder="0" pos="124 296 56 16"
          bkgcol="fff2f59b" thumbcol="ffc4c86d" min="0" max="127" int="1"
          style="LinearBar" textBoxPos="TextBoxLeft" textBoxEditable="1"
          textBoxWidth="40" textBoxHeight="20" skewFactor="1"/>
  <LABEL name="filterEnvVelocityTime1Label" id="fcf555c7750e1905" memberName="m_filterEnvVelocityTime1Label"
         virtualName="" explicitFocusOrder="0" pos="84 280 152 16" textCol="ff000000"
         edTextCol="ff000000" edBkgCol="0" labelText="VELO SENS ATTACK TIME"
         editableSingleClick="0" editableDoubleClick="0" focusDiscardsChanges="0"
         fontname="Default font" fontsize="12" bold="1" italic="0" justification="36"/>
  <SLIDER name="resonanceSlider" id="323e25f12b9bcb4d" memberName="m_resonanceSlider"
          virtualName="Knob" explicitFocusOrder="0" pos="204 36 48 60"
          textboxbkgd="fff2f59b" min="0" max="127" int="1" style="RotaryHorizontalVerticalDrag"
          textBoxPos="TextBoxBelow" textBoxEditable="1" textBoxWidth="80"
          textBoxHeight="16" skewFactor="1"/>
  <LABEL name="resonanceLabel" id="4a6481529e07d2e7" memberName="m_resonanceLabel"
         virtualName="" explicitFocusOrder="0" pos="188 20 80 16" textCol="ff000000"
         edTextCol="ff000000" edBkgCol="0" labelText="RESONANCE" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="12" bold="1" italic="0" justification="36"/>
  <LABEL name="resonanceVelocitySensLabel" id="cd7bd760659858dc" memberName="m_resonanceVelocitySensLabel"
         virtualName="" explicitFocusOrder="0" pos="268 48 100 28" textCol="ff000000"
         edTextCol="ff000000" edBkgCol="0" labelText="RESONANCE&#10;VELOCITY SENS"
         editableSingleClick="0" editableDoubleClick="0" focusDiscardsChanges="0"
         fontname="Default font" fontsize="12" bold="1" italic="0" justification="36"/>
  <SLIDER name="resonanceVelocitySensSlider" id="e85bd80388f15147" memberName="m_resonanceVelocitySensSlider"
          virtualName="MicroParameterSlider" explicitFocusOrder="0" pos="292 80 48 16"
          bkgcol="fff2f59b" thumbcol="ffc4c86d" min="0" max="127" int="1"
          style="LinearBar" textBoxPos="TextBoxLeft" textBoxEditable="1"
          textBoxWidth="40" textBoxHeight="20" skewFactor="1"/>
  <LABEL name="filterTypeLabel" id="c41c307042cbea72" memberName="m_filterTypeLabel"
         virtualName="" explicitFocusOrder="0" pos="4 20 84 16" textCol="ff000000"
         edTextCol="ff000000" edBkgCol="0" labelText="FILTER TYPE" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="12" bold="1" italic="0" justification="36"/>
  <COMBOBOX name="filterTypeComboBox" id="e8c10ecedfc6fd9e" memberName="m_filterTypeComboBox"
            virtualName="ParameterComboBox" explicitFocusOrder="0" pos="8 48 76 16"
            editable="0" layout="36" items="" textWhenNonSelected="" textWhenNoItems="(no choices)"/>
  <IMAGEBUTTON name="imageButton" id="fe0600a05b8279fe" memberName="m_imageButton"
               virtualName="" explicitFocusOrder="0" pos="3 1 16 16" buttonText=""
               connectedEdges="0" needsCallback="0" radioGroupId="0" keepProportions="1"
               resourceNormal="filter_png" opacityNormal="1" colourNormal="4340454a"
               resourceOver="" opacityOver="1" colourOver="4340454a" resourceDown=""
               opacityDown="1" colourDown="4340454a"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif

//==============================================================================
// Binary resources - be careful not to edit any of these sections!

// JUCER_RESOURCE: filter_png, 216, "../../../Resources/PatchEditSectionIcons/filter.png"
static const unsigned char resource_RhyFilterEditor_filter_png[] = { 137,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,0,16,0,0,0,16,8,6,0,0,0,31,243,255,97,0,0,0,1,115,82,71,66,0,174,206,28,233,0,0,0,
6,98,75,71,68,0,255,0,255,0,255,160,189,167,147,0,0,0,9,112,72,89,115,0,0,11,19,0,0,11,19,1,0,154,156,24,0,0,0,7,116,73,77,69,7,222,12,10,20,17,41,68,233,106,74,0,0,0,88,73,68,65,84,56,203,205,147,59,
14,0,32,8,67,121,198,251,95,25,23,7,52,198,240,113,144,145,208,166,180,41,50,71,85,85,2,3,32,89,240,130,201,128,45,73,247,170,88,36,31,165,120,37,111,187,230,5,3,156,72,90,216,241,12,193,245,205,104,10,
246,62,228,65,233,133,167,30,236,105,124,144,66,181,76,84,235,60,0,71,153,87,223,168,164,70,56,0,0,0,0,73,69,78,68,174,66,96,130,0,0};

const char* RhyFilterEditor::filter_png = (const char*) resource_RhyFilterEditor_filter_png;
const int RhyFilterEditor::filter_pngSize = 216;


//[EndFile] You can add extra defines here...
//[/EndFile]
