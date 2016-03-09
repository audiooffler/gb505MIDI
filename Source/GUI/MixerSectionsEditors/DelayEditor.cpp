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

#include "DelayEditor.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
extern OverallMemoryBlock* grooveboxMemory;
//[/MiscUserDefs]

//==============================================================================
DelayEditor::DelayEditor ()
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    addAndMakeVisible (m_delayEditorPanelGroup = new PanelGroupGrey ("delayEditorPanelGroup","DELAY"));
    addAndMakeVisible (m_delayTypeLabel = new Label ("delayTypeLabel",
                                                     TRANS("TYPE")));
    m_delayTypeLabel->setFont (Font (12.00f, Font::bold));
    m_delayTypeLabel->setJustificationType (Justification::centred);
    m_delayTypeLabel->setEditable (false, false, false);
    m_delayTypeLabel->setColour (TextEditor::textColourId, Colours::black);
    m_delayTypeLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_delayTypeToggle = new ParameterLedSwitch ("delayTypeToggle"));
    addAndMakeVisible (m_timeSlider = new Knob ("pitchSlider"));
    m_timeSlider->setRange (0, 127, 1);
    m_timeSlider->setSliderStyle (Slider::RotaryHorizontalVerticalDrag);
    m_timeSlider->setTextBoxStyle (Slider::TextBoxBelow, false, 80, 16);
    m_timeSlider->addListener (this);

    addAndMakeVisible (m_timeLabel = new Label ("timeLabel",
                                                TRANS("TIME")));
    m_timeLabel->setFont (Font (12.00f, Font::bold));
    m_timeLabel->setJustificationType (Justification::centred);
    m_timeLabel->setEditable (false, false, false);
    m_timeLabel->setColour (Label::textColourId, Colours::black);
    m_timeLabel->setColour (TextEditor::textColourId, Colours::black);
    m_timeLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_dampLabel = new Label ("dampLabel",
                                                TRANS("DAMP")));
    m_dampLabel->setFont (Font (12.00f, Font::bold));
    m_dampLabel->setJustificationType (Justification::centred);
    m_dampLabel->setEditable (false, false, false);
    m_dampLabel->setColour (Label::textColourId, Colours::black);
    m_dampLabel->setColour (TextEditor::textColourId, Colours::black);
    m_dampLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_dampSlider = new MicroParameterSlider ("dampSlider"));
    m_dampSlider->setRange (-48, 48, 1);
    m_dampSlider->setSliderStyle (Slider::LinearBar);
    m_dampSlider->setTextBoxStyle (Slider::TextBoxLeft, false, 64, 20);
    m_dampSlider->setColour (Slider::backgroundColourId, Colour (0xfff2f59b));
    m_dampSlider->setColour (Slider::thumbColourId, Colour (0xffc4c86d));
    m_dampSlider->addListener (this);

    addAndMakeVisible (m_feedbackSlider = new Knob ("feedbackSlider"));
    m_feedbackSlider->setRange (0, 127, 1);
    m_feedbackSlider->setSliderStyle (Slider::RotaryHorizontalVerticalDrag);
    m_feedbackSlider->setTextBoxStyle (Slider::TextBoxBelow, false, 80, 16);
    m_feedbackSlider->addListener (this);

    addAndMakeVisible (m_feedbackLabel = new Label ("feedbackLabel",
                                                    TRANS("FEEDBACK")));
    m_feedbackLabel->setFont (Font (12.00f, Font::bold));
    m_feedbackLabel->setJustificationType (Justification::centred);
    m_feedbackLabel->setEditable (false, false, false);
    m_feedbackLabel->setColour (Label::textColourId, Colours::black);
    m_feedbackLabel->setColour (TextEditor::textColourId, Colours::black);
    m_feedbackLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_outputLabel = new Label ("outputLabel",
                                                  TRANS("OUTPUT")));
    m_outputLabel->setFont (Font (12.00f, Font::bold));
    m_outputLabel->setJustificationType (Justification::centred);
    m_outputLabel->setEditable (false, false, false);
    m_outputLabel->setColour (TextEditor::textColourId, Colours::black);
    m_outputLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_outputToggle = new ParameterLedSwitch ("outputToggle"));
    addAndMakeVisible (m_levelSlider = new Knob ("levelSlider"));
    m_levelSlider->setRange (0, 127, 1);
    m_levelSlider->setSliderStyle (Slider::RotaryHorizontalVerticalDrag);
    m_levelSlider->setTextBoxStyle (Slider::TextBoxBelow, false, 48, 16);
    m_levelSlider->addListener (this);

    addAndMakeVisible (m_levelLabel = new Label ("levelLabel",
                                                 TRANS("LEVEL")));
    m_levelLabel->setFont (Font (12.00f, Font::bold));
    m_levelLabel->setJustificationType (Justification::centred);
    m_levelLabel->setEditable (false, false, false);
    m_levelLabel->setColour (Label::textColourId, Colours::black);
    m_levelLabel->setColour (TextEditor::textColourId, Colours::black);
    m_levelLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));


    //[UserPreSize]
	m_delayTypeToggle->setParameter(grooveboxMemory->getPartInfoBlock()->getPartInfoCommonBlockPtr()->getParameter(0x23));
	m_timeSlider->setParameter(grooveboxMemory->getPartInfoBlock()->getPartInfoCommonBlockPtr()->getParameter(0x25));
	m_dampSlider->setParameter(grooveboxMemory->getPartInfoBlock()->getPartInfoCommonBlockPtr()->getParameter(0x24));
	m_feedbackSlider->setParameter(grooveboxMemory->getPartInfoBlock()->getPartInfoCommonBlockPtr()->getParameter(0x26));
	m_outputToggle->setParameter(grooveboxMemory->getPartInfoBlock()->getPartInfoCommonBlockPtr()->getParameter(0x27));
	m_levelSlider->setParameter(grooveboxMemory->getPartInfoBlock()->getPartInfoCommonBlockPtr()->getParameter(0x22));
    //[/UserPreSize]

    setSize (344, 108);


    //[Constructor] You can add your own custom stuff here..
    //[/Constructor]
}

DelayEditor::~DelayEditor()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    m_delayEditorPanelGroup = nullptr;
    m_delayTypeLabel = nullptr;
    m_delayTypeToggle = nullptr;
    m_timeSlider = nullptr;
    m_timeLabel = nullptr;
    m_dampLabel = nullptr;
    m_dampSlider = nullptr;
    m_feedbackSlider = nullptr;
    m_feedbackLabel = nullptr;
    m_outputLabel = nullptr;
    m_outputToggle = nullptr;
    m_levelSlider = nullptr;
    m_levelLabel = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void DelayEditor::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
#if JUCE_MSVC
	g;
#endif
    //[/UserPrePaint]

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void DelayEditor::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    m_delayEditorPanelGroup->setBounds (0, 0, getWidth() - 0, getHeight() - 0);
    m_delayTypeLabel->setBounds (8, 20, 58, 16);
    m_delayTypeToggle->setBounds (8, 40, 64, 32);
    m_timeSlider->setBounds (88, 36, 48, 64);
    m_timeLabel->setBounds (88, 20, 48, 16);
    m_dampLabel->setBounds (216, 20, 56, 16);
    m_dampSlider->setBounds (212, 34, 64, 16);
    m_feedbackSlider->setBounds (149, 36, 48, 64);
    m_feedbackLabel->setBounds (136, 20, 72, 16);
    m_outputLabel->setBounds (216, 54, 56, 16);
    m_outputToggle->setBounds (224, 71, 48, 32);
    m_levelSlider->setBounds ((getWidth() / 2) + 140 - (48 / 2), 36, 48, 64);
    m_levelLabel->setBounds (288, 20, 48, 16);
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void DelayEditor::sliderValueChanged (Slider* sliderThatWasMoved)
{
    //[UsersliderValueChanged_Pre]
    //[/UsersliderValueChanged_Pre]

    if (sliderThatWasMoved == m_timeSlider)
    {
        //[UserSliderCode_m_timeSlider] -- add your slider handling code here..
        //[/UserSliderCode_m_timeSlider]
    }
    else if (sliderThatWasMoved == m_dampSlider)
    {
        //[UserSliderCode_m_dampSlider] -- add your slider handling code here..
        //[/UserSliderCode_m_dampSlider]
    }
    else if (sliderThatWasMoved == m_feedbackSlider)
    {
        //[UserSliderCode_m_feedbackSlider] -- add your slider handling code here..
        //[/UserSliderCode_m_feedbackSlider]
    }
    else if (sliderThatWasMoved == m_levelSlider)
    {
        //[UserSliderCode_m_levelSlider] -- add your slider handling code here..
        //[/UserSliderCode_m_levelSlider]
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

<JUCER_COMPONENT documentType="Component" className="DelayEditor" componentName=""
                 parentClasses="public Component" constructorParams="" variableInitialisers=""
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="1" initialWidth="344" initialHeight="108">
  <BACKGROUND backgroundColour="0"/>
  <JUCERCOMP name="" id="a579193927439722" memberName="m_delayEditorPanelGroup"
             virtualName="" explicitFocusOrder="0" pos="0 0 0M 0M" sourceFile="../GroupWidgets/PanelGroupGrey.cpp"
             constructorParams="&quot;delayEditorPanelGroup&quot;,&quot;DELAY&quot;"/>
  <LABEL name="delayTypeLabel" id="46e1e88403b5ba1f" memberName="m_delayTypeLabel"
         virtualName="" explicitFocusOrder="0" pos="8 20 58 16" edTextCol="ff000000"
         edBkgCol="0" labelText="TYPE" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="12"
         bold="1" italic="0" justification="36"/>
  <JUCERCOMP name="delayTypeToggle" id="8cb46d1f8b5ba80d" memberName="m_delayTypeToggle"
             virtualName="" explicitFocusOrder="0" pos="8 40 64 32" sourceFile="../ParameterWidgets/ParameterLedSwitch.cpp"
             constructorParams="&quot;delayTypeToggle&quot;"/>
  <SLIDER name="pitchSlider" id="533842793459863a" memberName="m_timeSlider"
          virtualName="Knob" explicitFocusOrder="0" pos="88 36 48 64" min="0"
          max="127" int="1" style="RotaryHorizontalVerticalDrag" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="16" skewFactor="1"/>
  <LABEL name="timeLabel" id="b464bd3cbdae27fd" memberName="m_timeLabel"
         virtualName="" explicitFocusOrder="0" pos="88 20 48 16" textCol="ff000000"
         edTextCol="ff000000" edBkgCol="0" labelText="TIME" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="12" bold="1" italic="0" justification="36"/>
  <LABEL name="dampLabel" id="8a7b7bb4fabe32d6" memberName="m_dampLabel"
         virtualName="" explicitFocusOrder="0" pos="216 20 56 16" textCol="ff000000"
         edTextCol="ff000000" edBkgCol="0" labelText="DAMP" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="12" bold="1" italic="0" justification="36"/>
  <SLIDER name="dampSlider" id="2b89b2c11e2ad524" memberName="m_dampSlider"
          virtualName="MicroParameterSlider" explicitFocusOrder="0" pos="212 34 64 16"
          bkgcol="fff2f59b" thumbcol="ffc4c86d" min="-48" max="48" int="1"
          style="LinearBar" textBoxPos="TextBoxLeft" textBoxEditable="1"
          textBoxWidth="64" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="feedbackSlider" id="aefa34345eb310b8" memberName="m_feedbackSlider"
          virtualName="Knob" explicitFocusOrder="0" pos="149 36 48 64"
          min="0" max="127" int="1" style="RotaryHorizontalVerticalDrag"
          textBoxPos="TextBoxBelow" textBoxEditable="1" textBoxWidth="80"
          textBoxHeight="16" skewFactor="1"/>
  <LABEL name="feedbackLabel" id="7356116c9a00cfee" memberName="m_feedbackLabel"
         virtualName="" explicitFocusOrder="0" pos="136 20 72 16" textCol="ff000000"
         edTextCol="ff000000" edBkgCol="0" labelText="FEEDBACK" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="12" bold="1" italic="0" justification="36"/>
  <LABEL name="outputLabel" id="9068b2701e327378" memberName="m_outputLabel"
         virtualName="" explicitFocusOrder="0" pos="216 54 56 16" edTextCol="ff000000"
         edBkgCol="0" labelText="OUTPUT" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="12"
         bold="1" italic="0" justification="36"/>
  <JUCERCOMP name="outputToggle" id="efc9c7b62b9d1199" memberName="m_outputToggle"
             virtualName="" explicitFocusOrder="0" pos="224 71 48 32" sourceFile="../ParameterWidgets/ParameterLedSwitch.cpp"
             constructorParams="&quot;outputToggle&quot;"/>
  <SLIDER name="levelSlider" id="36532340fc1495b4" memberName="m_levelSlider"
          virtualName="Knob" explicitFocusOrder="0" pos="140Cc 36 48 64"
          min="0" max="127" int="1" style="RotaryHorizontalVerticalDrag"
          textBoxPos="TextBoxBelow" textBoxEditable="1" textBoxWidth="48"
          textBoxHeight="16" skewFactor="1"/>
  <LABEL name="levelLabel" id="88bae54666436ac4" memberName="m_levelLabel"
         virtualName="" explicitFocusOrder="0" pos="288 20 48 16" textCol="ff000000"
         edTextCol="ff000000" edBkgCol="0" labelText="LEVEL" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="12" bold="1" italic="0" justification="36"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
