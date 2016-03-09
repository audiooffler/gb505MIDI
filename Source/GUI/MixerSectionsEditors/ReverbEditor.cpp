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

#include "ReverbEditor.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
extern OverallMemoryBlock* grooveboxMemory;
//[/MiscUserDefs]

//==============================================================================
ReverbEditor::ReverbEditor ()
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    addAndMakeVisible (m_reverbEditorPanelGroup = new PanelGroupGrey ("reverbEditorPanelGroup","REVERB"));
    addAndMakeVisible (m_reverbTypeComboBox = new ParameterComboBox ("reverbTypeComboBox"));
    m_reverbTypeComboBox->setEditableText (false);
    m_reverbTypeComboBox->setJustificationType (Justification::centredLeft);
    m_reverbTypeComboBox->setTextWhenNothingSelected (String());
    m_reverbTypeComboBox->setTextWhenNoChoicesAvailable (TRANS("(no choices)"));
    m_reverbTypeComboBox->addListener (this);

    addAndMakeVisible (m_reverbTypeLabel = new Label ("reverbTypeLabel",
                                                      TRANS("TYPE")));
    m_reverbTypeLabel->setFont (Font (12.00f, Font::bold));
    m_reverbTypeLabel->setJustificationType (Justification::centred);
    m_reverbTypeLabel->setEditable (false, false, false);
    m_reverbTypeLabel->setColour (TextEditor::textColourId, Colours::black);
    m_reverbTypeLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

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

    addAndMakeVisible (m_dampSlider = new MicroParameterSlider ("dampSlider"));
    m_dampSlider->setRange (-48, 48, 1);
    m_dampSlider->setSliderStyle (Slider::LinearBar);
    m_dampSlider->setTextBoxStyle (Slider::TextBoxLeft, false, 64, 20);
    m_dampSlider->setColour (Slider::backgroundColourId, Colour (0xfff2f59b));
    m_dampSlider->setColour (Slider::thumbColourId, Colour (0xffc4c86d));
    m_dampSlider->addListener (this);


    //[UserPreSize]
	m_reverbTypeComboBox->setParameter(grooveboxMemory->getPartInfoBlock()->getPartInfoCommonBlockPtr()->getParameter(0x28));
	m_timeSlider->setParameter(grooveboxMemory->getPartInfoBlock()->getPartInfoCommonBlockPtr()->getParameter(0x2A));
	m_dampSlider->setParameter(grooveboxMemory->getPartInfoBlock()->getPartInfoCommonBlockPtr()->getParameter(0x2B));
	m_levelSlider->setParameter(grooveboxMemory->getPartInfoBlock()->getPartInfoCommonBlockPtr()->getParameter(0x29));
    //[/UserPreSize]

    setSize (344, 108);


    //[Constructor] You can add your own custom stuff here..
    //[/Constructor]
}

ReverbEditor::~ReverbEditor()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    m_reverbEditorPanelGroup = nullptr;
    m_reverbTypeComboBox = nullptr;
    m_reverbTypeLabel = nullptr;
    m_timeSlider = nullptr;
    m_timeLabel = nullptr;
    m_dampLabel = nullptr;
    m_levelSlider = nullptr;
    m_levelLabel = nullptr;
    m_dampSlider = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void ReverbEditor::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
#if JUCE_MSVC
	g;
#endif
    //[/UserPrePaint]

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void ReverbEditor::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    m_reverbEditorPanelGroup->setBounds (0, 0, getWidth() - 0, getHeight() - 0);
    m_reverbTypeComboBox->setBounds (8, 48, 72, 16);
    m_reverbTypeLabel->setBounds (8, 20, 72, 16);
    m_timeSlider->setBounds (88, 36, 48, 64);
    m_timeLabel->setBounds (88, 20, 48, 16);
    m_dampLabel->setBounds (216, 20, 56, 16);
    m_levelSlider->setBounds ((getWidth() / 2) + 140 - (48 / 2), 36, 48, 64);
    m_levelLabel->setBounds (288, 20, 48, 16);
    m_dampSlider->setBounds (212, 34, 64, 16);
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void ReverbEditor::comboBoxChanged (ComboBox* comboBoxThatHasChanged)
{
    //[UsercomboBoxChanged_Pre]
    //[/UsercomboBoxChanged_Pre]

    if (comboBoxThatHasChanged == m_reverbTypeComboBox)
    {
        //[UserComboBoxCode_m_reverbTypeComboBox] -- add your combo box handling code here..
        //[/UserComboBoxCode_m_reverbTypeComboBox]
    }

    //[UsercomboBoxChanged_Post]
    //[/UsercomboBoxChanged_Post]
}

void ReverbEditor::sliderValueChanged (Slider* sliderThatWasMoved)
{
    //[UsersliderValueChanged_Pre]
    //[/UsersliderValueChanged_Pre]

    if (sliderThatWasMoved == m_timeSlider)
    {
        //[UserSliderCode_m_timeSlider] -- add your slider handling code here..
        //[/UserSliderCode_m_timeSlider]
    }
    else if (sliderThatWasMoved == m_levelSlider)
    {
        //[UserSliderCode_m_levelSlider] -- add your slider handling code here..
        //[/UserSliderCode_m_levelSlider]
    }
    else if (sliderThatWasMoved == m_dampSlider)
    {
        //[UserSliderCode_m_dampSlider] -- add your slider handling code here..
        //[/UserSliderCode_m_dampSlider]
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

<JUCER_COMPONENT documentType="Component" className="ReverbEditor" componentName=""
                 parentClasses="public Component" constructorParams="" variableInitialisers=""
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="1" initialWidth="344" initialHeight="108">
  <BACKGROUND backgroundColour="0"/>
  <JUCERCOMP name="" id="a579193927439722" memberName="m_reverbEditorPanelGroup"
             virtualName="" explicitFocusOrder="0" pos="0 0 0M 0M" sourceFile="../GroupWidgets/PanelGroupGrey.cpp"
             constructorParams="&quot;reverbEditorPanelGroup&quot;,&quot;REVERB&quot;"/>
  <COMBOBOX name="reverbTypeComboBox" id="310da11a3b4d1c0" memberName="m_reverbTypeComboBox"
            virtualName="ParameterComboBox" explicitFocusOrder="0" pos="8 48 72 16"
            editable="0" layout="33" items="" textWhenNonSelected="" textWhenNoItems="(no choices)"/>
  <LABEL name="reverbTypeLabel" id="46e1e88403b5ba1f" memberName="m_reverbTypeLabel"
         virtualName="" explicitFocusOrder="0" pos="8 20 72 16" edTextCol="ff000000"
         edBkgCol="0" labelText="TYPE" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="12"
         bold="1" italic="0" justification="36"/>
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
  <SLIDER name="dampSlider" id="2b89b2c11e2ad524" memberName="m_dampSlider"
          virtualName="MicroParameterSlider" explicitFocusOrder="0" pos="212 34 64 16"
          bkgcol="fff2f59b" thumbcol="ffc4c86d" min="-48" max="48" int="1"
          style="LinearBar" textBoxPos="TextBoxLeft" textBoxEditable="1"
          textBoxWidth="64" textBoxHeight="20" skewFactor="1"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
