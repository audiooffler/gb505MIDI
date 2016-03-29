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

#include "RhyPitchEditor.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
extern OverallMemoryBlock* grooveboxMemory;
//[/MiscUserDefs]

//==============================================================================
RhyPitchEditor::RhyPitchEditor (const String &componentName, int toneNumber)
    : Component (componentName),  m_toneNumber(toneNumber)
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    addAndMakeVisible (m_pitchGrp = new PanelGroupGrey ("pitchGrp", getName()));
    addAndMakeVisible (m_pitchGrp2 = new PanelGroupGrey ("pitchEnvGrp", getName().toUpperCase()+" ENVELOPE"));
    addAndMakeVisible (m_coarseTuneSlider = new Knob ("coarseTuneSlider"));
    m_coarseTuneSlider->setRange (0, 127, 1);
    m_coarseTuneSlider->setSliderStyle (Slider::RotaryHorizontalVerticalDrag);
    m_coarseTuneSlider->setTextBoxStyle (Slider::TextBoxBelow, false, 80, 16);
    m_coarseTuneSlider->setColour (Slider::textBoxBackgroundColourId, Colour (0xfff2f59b));
    m_coarseTuneSlider->addListener (this);

    addAndMakeVisible (m_coarseTuneLabel = new Label ("coarseTuneLabel",
                                                      TRANS("COARSE")));
    m_coarseTuneLabel->setFont (Font (12.00f, Font::bold));
    m_coarseTuneLabel->setJustificationType (Justification::centred);
    m_coarseTuneLabel->setEditable (false, false, false);
    m_coarseTuneLabel->setColour (Label::textColourId, Colours::black);
    m_coarseTuneLabel->setColour (TextEditor::textColourId, Colours::black);
    m_coarseTuneLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_pitchEnv = new Envelope (PartR, m_toneNumber, EnvelopeTypes::Pitch, false));
    addAndMakeVisible (m_randomPitchDepthSlider = new MicroParameterSlider ("randomPitchDepthLabel"));
    m_randomPitchDepthSlider->setRange (0, 127, 1);
    m_randomPitchDepthSlider->setSliderStyle (Slider::LinearBar);
    m_randomPitchDepthSlider->setTextBoxStyle (Slider::TextBoxLeft, false, 40, 20);
    m_randomPitchDepthSlider->setColour (Slider::backgroundColourId, Colour (0xfff2f59b));
    m_randomPitchDepthSlider->setColour (Slider::thumbColourId, Colour (0xffc4c86d));
    m_randomPitchDepthSlider->addListener (this);

    addAndMakeVisible (m_randomPitchDepthLabel = new Label ("randomPitchDepthLabel",
                                                            TRANS("RANDOMNESS")));
    m_randomPitchDepthLabel->setFont (Font (12.00f, Font::bold));
    m_randomPitchDepthLabel->setJustificationType (Justification::centred);
    m_randomPitchDepthLabel->setEditable (true, true, false);
    m_randomPitchDepthLabel->setColour (Label::textColourId, Colours::black);
    m_randomPitchDepthLabel->setColour (TextEditor::textColourId, Colours::black);
    m_randomPitchDepthLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));
    m_randomPitchDepthLabel->addListener (this);

    addAndMakeVisible (m_pitchEnvelopeDepthSlider = new ParameterEnvelopeSlider ("pitchEnvelopeDepthSlider"));
    m_pitchEnvelopeDepthSlider->setRange (0, 127, 1);
    m_pitchEnvelopeDepthSlider->setSliderStyle (Slider::LinearVertical);
    m_pitchEnvelopeDepthSlider->setTextBoxStyle (Slider::TextBoxBelow, false, 56, 16);
    m_pitchEnvelopeDepthSlider->setColour (Slider::backgroundColourId, Colour (0x00f2f59b));
    m_pitchEnvelopeDepthSlider->setColour (Slider::textBoxBackgroundColourId, Colour (0xfff2f59b));
    m_pitchEnvelopeDepthSlider->addListener (this);

    addAndMakeVisible (m_pitchEnvelopeDepthLabel = new Label ("pitchEnvelopeDepthLabel",
                                                              TRANS("DEPTH")));
    m_pitchEnvelopeDepthLabel->setFont (Font (12.00f, Font::bold));
    m_pitchEnvelopeDepthLabel->setJustificationType (Justification::centred);
    m_pitchEnvelopeDepthLabel->setEditable (false, false, false);
    m_pitchEnvelopeDepthLabel->setColour (Label::textColourId, Colours::black);
    m_pitchEnvelopeDepthLabel->setColour (TextEditor::textColourId, Colours::black);
    m_pitchEnvelopeDepthLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_pitchVelocitySensSlider = new MicroParameterSlider ("pitchVelocitySensSlider"));
    m_pitchVelocitySensSlider->setRange (0, 127, 1);
    m_pitchVelocitySensSlider->setSliderStyle (Slider::LinearBar);
    m_pitchVelocitySensSlider->setTextBoxStyle (Slider::TextBoxLeft, false, 40, 20);
    m_pitchVelocitySensSlider->setColour (Slider::backgroundColourId, Colour (0xfff2f59b));
    m_pitchVelocitySensSlider->setColour (Slider::thumbColourId, Colour (0xffc4c86d));
    m_pitchVelocitySensSlider->addListener (this);

    addAndMakeVisible (m_pitchEnvVelocitySensLabel = new Label ("pitchEnvVelocitySensLabel",
                                                                TRANS("VELO SENS ENVELOPE")));
    m_pitchEnvVelocitySensLabel->setFont (Font (12.00f, Font::bold));
    m_pitchEnvVelocitySensLabel->setJustificationType (Justification::centred);
    m_pitchEnvVelocitySensLabel->setEditable (false, false, false);
    m_pitchEnvVelocitySensLabel->setColour (Label::textColourId, Colours::black);
    m_pitchEnvVelocitySensLabel->setColour (TextEditor::textColourId, Colours::black);
    m_pitchEnvVelocitySensLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_pitchEnvVelocityTime1Slider = new MicroParameterSlider ("pitchEnvVelocityTime1Slider"));
    m_pitchEnvVelocityTime1Slider->setRange (0, 127, 1);
    m_pitchEnvVelocityTime1Slider->setSliderStyle (Slider::LinearBar);
    m_pitchEnvVelocityTime1Slider->setTextBoxStyle (Slider::TextBoxLeft, false, 40, 20);
    m_pitchEnvVelocityTime1Slider->setColour (Slider::backgroundColourId, Colour (0xfff2f59b));
    m_pitchEnvVelocityTime1Slider->setColour (Slider::thumbColourId, Colour (0xffc4c86d));
    m_pitchEnvVelocityTime1Slider->addListener (this);

    addAndMakeVisible (m_pitchEnvVelocityTime1Label = new Label ("pitchEnvVelocityTime1Label",
                                                                 TRANS("VELO SENS ATTACK TIME")));
    m_pitchEnvVelocityTime1Label->setFont (Font (12.00f, Font::bold));
    m_pitchEnvVelocityTime1Label->setJustificationType (Justification::centred);
    m_pitchEnvVelocityTime1Label->setEditable (false, false, false);
    m_pitchEnvVelocityTime1Label->setColour (Label::textColourId, Colours::black);
    m_pitchEnvVelocityTime1Label->setColour (TextEditor::textColourId, Colours::black);
    m_pitchEnvVelocityTime1Label->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_fineTuneSlider = new Knob ("fineTuneSlider"));
    m_fineTuneSlider->setRange (0, 127, 1);
    m_fineTuneSlider->setSliderStyle (Slider::RotaryHorizontalVerticalDrag);
    m_fineTuneSlider->setTextBoxStyle (Slider::TextBoxBelow, false, 80, 16);
    m_fineTuneSlider->setColour (Slider::textBoxBackgroundColourId, Colour (0xfff2f59b));
    m_fineTuneSlider->addListener (this);

    addAndMakeVisible (m_fineTuneLabel = new Label ("fineTuneLabel",
                                                    TRANS("FINE TUNE")));
    m_fineTuneLabel->setFont (Font (12.00f, Font::bold));
    m_fineTuneLabel->setJustificationType (Justification::centred);
    m_fineTuneLabel->setEditable (false, false, false);
    m_fineTuneLabel->setColour (Label::textColourId, Colours::black);
    m_fineTuneLabel->setColour (TextEditor::textColourId, Colours::black);
    m_fineTuneLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_bendRangeSlider = new MicroParameterSlider ("bendRangeSlider"));
    m_bendRangeSlider->setRange (0, 127, 1);
    m_bendRangeSlider->setSliderStyle (Slider::LinearBar);
    m_bendRangeSlider->setTextBoxStyle (Slider::TextBoxLeft, false, 40, 20);
    m_bendRangeSlider->setColour (Slider::backgroundColourId, Colour (0xfff2f59b));
    m_bendRangeSlider->setColour (Slider::thumbColourId, Colour (0xffc4c86d));
    m_bendRangeSlider->addListener (this);

    addAndMakeVisible (m_stretchTuneDepthLabel2 = new Label ("stretchTuneDepthLabel",
                                                             TRANS("BEND RANGE")));
    m_stretchTuneDepthLabel2->setFont (Font (12.00f, Font::bold));
    m_stretchTuneDepthLabel2->setJustificationType (Justification::centred);
    m_stretchTuneDepthLabel2->setEditable (false, false, false);
    m_stretchTuneDepthLabel2->setColour (Label::textColourId, Colours::black);
    m_stretchTuneDepthLabel2->setColour (TextEditor::textColourId, Colours::black);
    m_stretchTuneDepthLabel2->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (imageButton5 = new ImageButton ("new button"));
    imageButton5->setButtonText (String());

    imageButton5->setImages (false, true, true,
                             ImageCache::getFromMemory (pitch_png, pitch_pngSize), 1.000f, Colour (0x4340454a),
                             Image(), 1.000f, Colour (0x4340454a),
                             Image(), 1.000f, Colour (0x4340454a));

    //[UserPreSize]
    setupParameters(toneNumber);
    //[/UserPreSize]

    setSize (334, 334);


    //[Constructor] You can add your own custom stuff here..
    //[/Constructor]
}

RhyPitchEditor::~RhyPitchEditor()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
	if (m_coarseTuneSlider->getParamPtr() != nullptr)m_coarseTuneSlider->getParamPtr()->removeChangeListener(m_coarseTuneSlider);
	if (m_fineTuneSlider->getParamPtr() != nullptr)m_fineTuneSlider->getParamPtr()->removeChangeListener(m_fineTuneSlider);
	if (m_randomPitchDepthSlider->getParamPtr() != nullptr)m_randomPitchDepthSlider->getParamPtr()->removeChangeListener(m_randomPitchDepthSlider);
	if (m_pitchEnvelopeDepthSlider->getParamPtr() != nullptr)m_pitchEnvelopeDepthSlider->getParamPtr()->removeChangeListener(m_pitchEnvelopeDepthSlider);
	if (m_pitchVelocitySensSlider->getParamPtr() != nullptr)m_pitchVelocitySensSlider->getParamPtr()->removeChangeListener(m_pitchVelocitySensSlider);
	if (m_pitchEnvVelocityTime1Slider->getParamPtr() != nullptr)m_pitchEnvVelocityTime1Slider->getParamPtr()->removeChangeListener(m_pitchEnvVelocityTime1Slider);
    //[/Destructor_pre]

    m_pitchGrp = nullptr;
    m_pitchGrp2 = nullptr;
    m_coarseTuneSlider = nullptr;
    m_coarseTuneLabel = nullptr;
    m_pitchEnv = nullptr;
    m_randomPitchDepthSlider = nullptr;
    m_randomPitchDepthLabel = nullptr;
    m_pitchEnvelopeDepthSlider = nullptr;
    m_pitchEnvelopeDepthLabel = nullptr;
    m_pitchVelocitySensSlider = nullptr;
    m_pitchEnvVelocitySensLabel = nullptr;
    m_pitchEnvVelocityTime1Slider = nullptr;
    m_pitchEnvVelocityTime1Label = nullptr;
    m_fineTuneSlider = nullptr;
    m_fineTuneLabel = nullptr;
    m_bendRangeSlider = nullptr;
    m_stretchTuneDepthLabel2 = nullptr;
    imageButton5 = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void RhyPitchEditor::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
	#ifdef JUCE_MSVC
	g;
	#endif
    //[/UserPrePaint]

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void RhyPitchEditor::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    m_pitchGrp->setBounds (0, 0, getWidth() - 0, getHeight() - 0);
    m_pitchGrp2->setBounds (0, 104, getWidth() - 0, getHeight() - 104);
    m_coarseTuneSlider->setBounds (16, 36, 48, 60);
    m_coarseTuneLabel->setBounds (-4, 20, 88, 16);
    m_pitchEnv->setBounds (40, 120, 292, 156);
    m_randomPitchDepthSlider->setBounds (172, 80, 56, 16);
    m_randomPitchDepthLabel->setBounds (156, 60, 88, 16);
    m_pitchEnvelopeDepthSlider->setBounds (4, 132, 36, 116);
    m_pitchEnvelopeDepthLabel->setBounds (-4, 120, 52, 16);
    m_pitchVelocitySensSlider->setBounds (64, 304, 56, 16);
    m_pitchEnvVelocitySensLabel->setBounds (24, 288, 136, 16);
    m_pitchEnvVelocityTime1Slider->setBounds (216, 304, 56, 16);
    m_pitchEnvVelocityTime1Label->setBounds (176, 288, 152, 16);
    m_fineTuneSlider->setBounds (99, 36, 48, 60);
    m_fineTuneLabel->setBounds (79, 20, 88, 16);
    m_bendRangeSlider->setBounds (260, 80, 56, 16);
    m_stretchTuneDepthLabel2->setBounds (244, 60, 88, 16);
    imageButton5->setBounds (3, 1, 16, 16);
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void RhyPitchEditor::sliderValueChanged (Slider* sliderThatWasMoved)
{
    //[UsersliderValueChanged_Pre]
    //[/UsersliderValueChanged_Pre]

    if (sliderThatWasMoved == m_coarseTuneSlider)
    {
        //[UserSliderCode_m_coarseTuneSlider] -- add your slider handling code here..
        //[/UserSliderCode_m_coarseTuneSlider]
    }
    else if (sliderThatWasMoved == m_randomPitchDepthSlider)
    {
        //[UserSliderCode_m_randomPitchDepthSlider] -- add your slider handling code here..
        //[/UserSliderCode_m_randomPitchDepthSlider]
    }
    else if (sliderThatWasMoved == m_pitchEnvelopeDepthSlider)
    {
        //[UserSliderCode_m_pitchEnvelopeDepthSlider] -- add your slider handling code here..
        //[/UserSliderCode_m_pitchEnvelopeDepthSlider]
    }
    else if (sliderThatWasMoved == m_pitchVelocitySensSlider)
    {
        //[UserSliderCode_m_pitchVelocitySensSlider] -- add your slider handling code here..
        //[/UserSliderCode_m_pitchVelocitySensSlider]
    }
    else if (sliderThatWasMoved == m_pitchEnvVelocityTime1Slider)
    {
        //[UserSliderCode_m_pitchEnvVelocityTime1Slider] -- add your slider handling code here..
        //[/UserSliderCode_m_pitchEnvVelocityTime1Slider]
    }
    else if (sliderThatWasMoved == m_fineTuneSlider)
    {
        //[UserSliderCode_m_fineTuneSlider] -- add your slider handling code here..
        //[/UserSliderCode_m_fineTuneSlider]
    }
    else if (sliderThatWasMoved == m_bendRangeSlider)
    {
        //[UserSliderCode_m_bendRangeSlider] -- add your slider handling code here..
        //[/UserSliderCode_m_bendRangeSlider]
    }

    //[UsersliderValueChanged_Post]
    //[/UsersliderValueChanged_Post]
}

void RhyPitchEditor::labelTextChanged (Label* labelThatHasChanged)
{
    //[UserlabelTextChanged_Pre]
    //[/UserlabelTextChanged_Pre]

    if (labelThatHasChanged == m_randomPitchDepthLabel)
    {
        //[UserLabelCode_m_randomPitchDepthLabel] -- add your label text handling code here..
        //[/UserLabelCode_m_randomPitchDepthLabel]
    }

    //[UserlabelTextChanged_Post]
    //[/UserlabelTextChanged_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
void RhyPitchEditor::setupParameters(int toneNumber)
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
					m_bendRangeSlider->setParameter(noteBlock->getParameter(0x06));
					m_coarseTuneSlider->setParameter(noteBlock->getParameter(0x0C));
					m_fineTuneSlider->setParameter(noteBlock->getParameter(0x0D));
					m_randomPitchDepthSlider->setParameter(noteBlock->getParameter(0x0E));
					m_pitchEnvelopeDepthSlider->setParameter(noteBlock->getParameter(0x0F));
					m_pitchVelocitySensSlider->setParameter(noteBlock->getParameter(0x10));
					m_pitchEnvVelocityTime1Slider->setParameter(noteBlock->getParameter(0x11));
					m_pitchEnv->setupParameters(PartR, toneNumber);
					m_pitchGrp->setText("PITCH OF RHYTHM KEY " + String(m_toneNumber));
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

<JUCER_COMPONENT documentType="Component" className="RhyPitchEditor" componentName=""
                 parentClasses="public Component" constructorParams="const String &amp;componentName, int toneNumber"
                 variableInitialisers="Component (componentName),  m_toneNumber(toneNumber)"
                 snapPixels="4" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="1" initialWidth="334" initialHeight="334">
  <BACKGROUND backgroundColour="0"/>
  <JUCERCOMP name="pitchGrp" id="52e00682f746b888" memberName="m_pitchGrp"
             virtualName="PanelGroupGrey" explicitFocusOrder="0" pos="0 0 0M 0M"
             sourceFile="../GroupWidgets/PanelGroupGrey.cpp" constructorParams="&quot;pitchGrp&quot;, getName() "/>
  <JUCERCOMP name="pitchGrp" id="f94b4c6bc1e7a151" memberName="m_pitchGrp2"
             virtualName="PanelGroupGrey" explicitFocusOrder="0" pos="0 104 0M 104M"
             sourceFile="../GroupWidgets/PanelGroupTransp.cpp" constructorParams="&quot;pitchEnvGrp&quot;, getName().toUpperCase()+&quot; ENVELOPE&quot;"/>
  <SLIDER name="coarseTuneSlider" id="533842793459863a" memberName="m_coarseTuneSlider"
          virtualName="Knob" explicitFocusOrder="0" pos="16 36 48 60" textboxbkgd="fff2f59b"
          min="0" max="127" int="1" style="RotaryHorizontalVerticalDrag"
          textBoxPos="TextBoxBelow" textBoxEditable="1" textBoxWidth="80"
          textBoxHeight="16" skewFactor="1"/>
  <LABEL name="coarseTuneLabel" id="b464bd3cbdae27fd" memberName="m_coarseTuneLabel"
         virtualName="" explicitFocusOrder="0" pos="-4 20 88 16" textCol="ff000000"
         edTextCol="ff000000" edBkgCol="0" labelText="COARSE" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="12" bold="1" italic="0" justification="36"/>
  <JUCERCOMP name="pitchEnv" id="99a40d72d7ad1e22" memberName="m_pitchEnv"
             virtualName="" explicitFocusOrder="0" pos="40 120 292 156" sourceFile="../PatchSectionEditors/Envelope.cpp"
             constructorParams="PartR, m_toneNumber, EnvelopeTypes::Pitch, false"/>
  <SLIDER name="randomPitchDepthLabel" id="579dec6fe706db7d" memberName="m_randomPitchDepthSlider"
          virtualName="MicroParameterSlider" explicitFocusOrder="0" pos="172 80 56 16"
          bkgcol="fff2f59b" thumbcol="ffc4c86d" min="0" max="127" int="1"
          style="LinearBar" textBoxPos="TextBoxLeft" textBoxEditable="1"
          textBoxWidth="40" textBoxHeight="20" skewFactor="1"/>
  <LABEL name="randomPitchDepthLabel" id="cd360160053c8317" memberName="m_randomPitchDepthLabel"
         virtualName="" explicitFocusOrder="0" pos="156 60 88 16" textCol="ff000000"
         edTextCol="ff000000" edBkgCol="0" labelText="RANDOMNESS" editableSingleClick="1"
         editableDoubleClick="1" focusDiscardsChanges="0" fontname="Default font"
         fontsize="12" bold="1" italic="0" justification="36"/>
  <SLIDER name="pitchEnvelopeDepthSlider" id="b0bd5a61181f569c" memberName="m_pitchEnvelopeDepthSlider"
          virtualName="ParameterEnvelopeSlider" explicitFocusOrder="0"
          pos="4 132 36 116" bkgcol="f2f59b" textboxbkgd="fff2f59b" min="0"
          max="127" int="1" style="LinearVertical" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="56" textBoxHeight="16" skewFactor="1"/>
  <LABEL name="pitchEnvelopeDepthLabel" id="611da7e96f52143f" memberName="m_pitchEnvelopeDepthLabel"
         virtualName="" explicitFocusOrder="0" pos="-4 120 52 16" textCol="ff000000"
         edTextCol="ff000000" edBkgCol="0" labelText="DEPTH" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="12" bold="1" italic="0" justification="36"/>
  <SLIDER name="pitchVelocitySensSlider" id="ce3036a9c9d2d09a" memberName="m_pitchVelocitySensSlider"
          virtualName="MicroParameterSlider" explicitFocusOrder="0" pos="64 304 56 16"
          bkgcol="fff2f59b" thumbcol="ffc4c86d" min="0" max="127" int="1"
          style="LinearBar" textBoxPos="TextBoxLeft" textBoxEditable="1"
          textBoxWidth="40" textBoxHeight="20" skewFactor="1"/>
  <LABEL name="pitchEnvVelocitySensLabel" id="da6b2f045679c497" memberName="m_pitchEnvVelocitySensLabel"
         virtualName="" explicitFocusOrder="0" pos="24 288 136 16" textCol="ff000000"
         edTextCol="ff000000" edBkgCol="0" labelText="VELO SENS ENVELOPE"
         editableSingleClick="0" editableDoubleClick="0" focusDiscardsChanges="0"
         fontname="Default font" fontsize="12" bold="1" italic="0" justification="36"/>
  <SLIDER name="pitchEnvVelocityTime1Slider" id="26e8b1e9ec956faf" memberName="m_pitchEnvVelocityTime1Slider"
          virtualName="MicroParameterSlider" explicitFocusOrder="0" pos="216 304 56 16"
          bkgcol="fff2f59b" thumbcol="ffc4c86d" min="0" max="127" int="1"
          style="LinearBar" textBoxPos="TextBoxLeft" textBoxEditable="1"
          textBoxWidth="40" textBoxHeight="20" skewFactor="1"/>
  <LABEL name="pitchEnvVelocityTime1Label" id="fcf555c7750e1905" memberName="m_pitchEnvVelocityTime1Label"
         virtualName="" explicitFocusOrder="0" pos="176 288 152 16" textCol="ff000000"
         edTextCol="ff000000" edBkgCol="0" labelText="VELO SENS ATTACK TIME"
         editableSingleClick="0" editableDoubleClick="0" focusDiscardsChanges="0"
         fontname="Default font" fontsize="12" bold="1" italic="0" justification="36"/>
  <SLIDER name="fineTuneSlider" id="323e25f12b9bcb4d" memberName="m_fineTuneSlider"
          virtualName="Knob" explicitFocusOrder="0" pos="99 36 48 60" textboxbkgd="fff2f59b"
          min="0" max="127" int="1" style="RotaryHorizontalVerticalDrag"
          textBoxPos="TextBoxBelow" textBoxEditable="1" textBoxWidth="80"
          textBoxHeight="16" skewFactor="1"/>
  <LABEL name="fineTuneLabel" id="4a6481529e07d2e7" memberName="m_fineTuneLabel"
         virtualName="" explicitFocusOrder="0" pos="79 20 88 16" textCol="ff000000"
         edTextCol="ff000000" edBkgCol="0" labelText="FINE TUNE" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="12" bold="1" italic="0" justification="36"/>
  <SLIDER name="bendRangeSlider" id="c55451f652b9879b" memberName="m_bendRangeSlider"
          virtualName="MicroParameterSlider" explicitFocusOrder="0" pos="260 80 56 16"
          bkgcol="fff2f59b" thumbcol="ffc4c86d" min="0" max="127" int="1"
          style="LinearBar" textBoxPos="TextBoxLeft" textBoxEditable="1"
          textBoxWidth="40" textBoxHeight="20" skewFactor="1"/>
  <LABEL name="stretchTuneDepthLabel" id="492759f4bd90a4a3" memberName="m_stretchTuneDepthLabel2"
         virtualName="" explicitFocusOrder="0" pos="244 60 88 16" textCol="ff000000"
         edTextCol="ff000000" edBkgCol="0" labelText="BEND RANGE" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="12" bold="1" italic="0" justification="36"/>
  <IMAGEBUTTON name="new button" id="547857ffe69caa20" memberName="imageButton5"
               virtualName="" explicitFocusOrder="0" pos="3 1 16 16" buttonText=""
               connectedEdges="0" needsCallback="0" radioGroupId="0" keepProportions="1"
               resourceNormal="pitch_png" opacityNormal="1" colourNormal="4340454a"
               resourceOver="" opacityOver="1" colourOver="4340454a" resourceDown=""
               opacityDown="1" colourDown="4340454a"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif

//==============================================================================
// Binary resources - be careful not to edit any of these sections!

// JUCER_RESOURCE: pitch_png, 225, "../../../Resources/PatchEditSectionIcons/pitch.png"
static const unsigned char resource_RhyPitchEditor_pitch_png[] = { 137,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,0,16,0,0,0,16,8,6,0,0,0,31,243,255,97,0,0,0,1,115,82,71,66,0,174,206,28,233,0,0,0,6,
98,75,71,68,0,255,0,255,0,255,160,189,167,147,0,0,0,9,112,72,89,115,0,0,11,19,0,0,11,19,1,0,154,156,24,0,0,0,7,116,73,77,69,7,222,12,10,20,19,38,230,96,21,89,0,0,0,97,73,68,65,84,56,203,165,147,75,14,
0,33,8,67,41,153,251,95,185,110,152,68,141,40,159,110,205,171,80,0,98,34,73,73,8,0,164,10,47,204,11,166,201,123,211,23,188,148,122,144,70,74,189,153,104,42,172,140,65,52,88,173,246,238,26,236,240,109,
10,161,22,96,242,76,180,26,222,175,239,4,206,191,205,149,164,211,142,108,105,123,140,237,99,66,247,156,7,144,160,99,229,152,124,254,63,0,0,0,0,73,69,78,68,174,66,96,130,0,0};

const char* RhyPitchEditor::pitch_png = (const char*) resource_RhyPitchEditor_pitch_png;
const int RhyPitchEditor::pitch_pngSize = 225;


//[EndFile] You can add extra defines here...
//[/EndFile]
