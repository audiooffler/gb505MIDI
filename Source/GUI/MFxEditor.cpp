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
//[/Headers]

#include "MFxEditor.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
MFXEditor::MFXEditor ()
{
    addAndMakeVisible (m_paramSlider1 = new ParameterSlider ("paramSlider1"));
    m_paramSlider1->setRange (0, 127, 1);
    m_paramSlider1->setSliderStyle (Slider::LinearBar);
    m_paramSlider1->setTextBoxStyle (Slider::TextBoxLeft, false, 80, 20);
    m_paramSlider1->setColour (Slider::backgroundColourId, Colours::white);
    m_paramSlider1->addListener (this);

    addAndMakeVisible (m_paramLabel1 = new Label ("paramLabel1",
                                                  TRANS("M-FX Parameter 1")));
    m_paramLabel1->setFont (Font (15.00f, Font::plain));
    m_paramLabel1->setJustificationType (Justification::centredLeft);
    m_paramLabel1->setEditable (false, false, false);
    m_paramLabel1->setColour (TextEditor::textColourId, Colours::black);
    m_paramLabel1->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_paramSlider2 = new ParameterSlider ("paramSlider2"));
    m_paramSlider2->setRange (0, 127, 1);
    m_paramSlider2->setSliderStyle (Slider::LinearBar);
    m_paramSlider2->setTextBoxStyle (Slider::TextBoxLeft, false, 80, 20);
    m_paramSlider2->setColour (Slider::backgroundColourId, Colours::white);
    m_paramSlider2->addListener (this);

    addAndMakeVisible (m_paramLabel2 = new Label ("paramLabel2",
                                                  TRANS("M-FX Parameter 2")));
    m_paramLabel2->setFont (Font (15.00f, Font::plain));
    m_paramLabel2->setJustificationType (Justification::centredLeft);
    m_paramLabel2->setEditable (false, false, false);
    m_paramLabel2->setColour (TextEditor::textColourId, Colours::black);
    m_paramLabel2->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_paramSlider3 = new ParameterSlider ("paramSlider3"));
    m_paramSlider3->setRange (0, 127, 1);
    m_paramSlider3->setSliderStyle (Slider::LinearBar);
    m_paramSlider3->setTextBoxStyle (Slider::TextBoxLeft, false, 80, 20);
    m_paramSlider3->setColour (Slider::backgroundColourId, Colours::white);
    m_paramSlider3->addListener (this);

    addAndMakeVisible (m_paramLabel3 = new Label ("paramLabel3",
                                                  TRANS("M-FX Parameter 3")));
    m_paramLabel3->setFont (Font (15.00f, Font::plain));
    m_paramLabel3->setJustificationType (Justification::centredLeft);
    m_paramLabel3->setEditable (false, false, false);
    m_paramLabel3->setColour (TextEditor::textColourId, Colours::black);
    m_paramLabel3->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_paramSlider4 = new ParameterSlider ("paramSlider4"));
    m_paramSlider4->setRange (0, 127, 1);
    m_paramSlider4->setSliderStyle (Slider::LinearBar);
    m_paramSlider4->setTextBoxStyle (Slider::TextBoxLeft, false, 80, 20);
    m_paramSlider4->setColour (Slider::backgroundColourId, Colours::white);
    m_paramSlider4->addListener (this);

    addAndMakeVisible (m_paramLabel4 = new Label ("paramLabel4",
                                                  TRANS("M-FX Parameter 4")));
    m_paramLabel4->setFont (Font (15.00f, Font::plain));
    m_paramLabel4->setJustificationType (Justification::centredLeft);
    m_paramLabel4->setEditable (false, false, false);
    m_paramLabel4->setColour (TextEditor::textColourId, Colours::black);
    m_paramLabel4->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_paramSlider5 = new ParameterSlider ("paramSlider5"));
    m_paramSlider5->setRange (0, 127, 1);
    m_paramSlider5->setSliderStyle (Slider::LinearBar);
    m_paramSlider5->setTextBoxStyle (Slider::TextBoxLeft, false, 80, 20);
    m_paramSlider5->setColour (Slider::backgroundColourId, Colours::white);
    m_paramSlider5->addListener (this);

    addAndMakeVisible (m_paramLabel5 = new Label ("paramLabel5",
                                                  TRANS("M-FX Parameter 5")));
    m_paramLabel5->setFont (Font (15.00f, Font::plain));
    m_paramLabel5->setJustificationType (Justification::centredLeft);
    m_paramLabel5->setEditable (false, false, false);
    m_paramLabel5->setColour (TextEditor::textColourId, Colours::black);
    m_paramLabel5->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_paramSlider6 = new ParameterSlider ("paramSlider6"));
    m_paramSlider6->setRange (0, 127, 1);
    m_paramSlider6->setSliderStyle (Slider::LinearBar);
    m_paramSlider6->setTextBoxStyle (Slider::TextBoxLeft, false, 80, 20);
    m_paramSlider6->setColour (Slider::backgroundColourId, Colours::white);
    m_paramSlider6->addListener (this);

    addAndMakeVisible (m_paramLabel6 = new Label ("paramLabel6",
                                                  TRANS("M-FX Parameter 6")));
    m_paramLabel6->setFont (Font (15.00f, Font::plain));
    m_paramLabel6->setJustificationType (Justification::centredLeft);
    m_paramLabel6->setEditable (false, false, false);
    m_paramLabel6->setColour (TextEditor::textColourId, Colours::black);
    m_paramLabel6->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_paramSlider7 = new ParameterSlider ("paramSlider7"));
    m_paramSlider7->setRange (0, 127, 1);
    m_paramSlider7->setSliderStyle (Slider::LinearBar);
    m_paramSlider7->setTextBoxStyle (Slider::TextBoxLeft, false, 80, 20);
    m_paramSlider7->setColour (Slider::backgroundColourId, Colours::white);
    m_paramSlider7->addListener (this);

    addAndMakeVisible (m_paramLabel7 = new Label ("paramLabel7",
                                                  TRANS("M-FX Parameter 7")));
    m_paramLabel7->setFont (Font (15.00f, Font::plain));
    m_paramLabel7->setJustificationType (Justification::centredLeft);
    m_paramLabel7->setEditable (false, false, false);
    m_paramLabel7->setColour (TextEditor::textColourId, Colours::black);
    m_paramLabel7->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_paramSlider8 = new ParameterSlider ("paramSlider8"));
    m_paramSlider8->setRange (0, 127, 1);
    m_paramSlider8->setSliderStyle (Slider::LinearBar);
    m_paramSlider8->setTextBoxStyle (Slider::TextBoxLeft, false, 80, 20);
    m_paramSlider8->setColour (Slider::backgroundColourId, Colours::white);
    m_paramSlider8->addListener (this);

    addAndMakeVisible (m_paramLabel8 = new Label ("paramLabel8",
                                                  TRANS("M-FX Parameter 8")));
    m_paramLabel8->setFont (Font (15.00f, Font::plain));
    m_paramLabel8->setJustificationType (Justification::centredLeft);
    m_paramLabel8->setEditable (false, false, false);
    m_paramLabel8->setColour (TextEditor::textColourId, Colours::black);
    m_paramLabel8->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_paramSlider9 = new ParameterSlider ("paramSlider9"));
    m_paramSlider9->setRange (0, 127, 1);
    m_paramSlider9->setSliderStyle (Slider::LinearBar);
    m_paramSlider9->setTextBoxStyle (Slider::TextBoxLeft, false, 80, 20);
    m_paramSlider9->setColour (Slider::backgroundColourId, Colours::white);
    m_paramSlider9->addListener (this);

    addAndMakeVisible (m_paramLabel9 = new Label ("paramLabel9",
                                                  TRANS("M-FX Parameter 9")));
    m_paramLabel9->setFont (Font (15.00f, Font::plain));
    m_paramLabel9->setJustificationType (Justification::centredLeft);
    m_paramLabel9->setEditable (false, false, false);
    m_paramLabel9->setColour (TextEditor::textColourId, Colours::black);
    m_paramLabel9->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_paramSlider10 = new ParameterSlider ("paramSlider10"));
    m_paramSlider10->setRange (0, 127, 1);
    m_paramSlider10->setSliderStyle (Slider::LinearBar);
    m_paramSlider10->setTextBoxStyle (Slider::TextBoxLeft, false, 80, 20);
    m_paramSlider10->setColour (Slider::backgroundColourId, Colours::white);
    m_paramSlider10->addListener (this);

    addAndMakeVisible (m_paramLabel10 = new Label ("paramLabel10",
                                                   TRANS("M-FX Parameter 10")));
    m_paramLabel10->setFont (Font (15.00f, Font::plain));
    m_paramLabel10->setJustificationType (Justification::centredLeft);
    m_paramLabel10->setEditable (false, false, false);
    m_paramLabel10->setColour (TextEditor::textColourId, Colours::black);
    m_paramLabel10->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_paramSlider11 = new ParameterSlider ("paramSlider11"));
    m_paramSlider11->setRange (0, 127, 1);
    m_paramSlider11->setSliderStyle (Slider::LinearBar);
    m_paramSlider11->setTextBoxStyle (Slider::TextBoxLeft, false, 80, 20);
    m_paramSlider11->setColour (Slider::backgroundColourId, Colours::white);
    m_paramSlider11->addListener (this);

    addAndMakeVisible (m_paramLabel11 = new Label ("paramLabel11",
                                                   TRANS("M-FX Parameter 11")));
    m_paramLabel11->setFont (Font (15.00f, Font::plain));
    m_paramLabel11->setJustificationType (Justification::centredLeft);
    m_paramLabel11->setEditable (false, false, false);
    m_paramLabel11->setColour (TextEditor::textColourId, Colours::black);
    m_paramLabel11->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_MFXTypeComboBox = new ComboBox ("MFXTypeComboBox"));
    m_MFXTypeComboBox->setEditableText (false);
    m_MFXTypeComboBox->setJustificationType (Justification::centredLeft);
    m_MFXTypeComboBox->setTextWhenNothingSelected (String::empty);
    m_MFXTypeComboBox->setTextWhenNoChoicesAvailable (TRANS("(no choices)"));
    m_MFXTypeComboBox->addListener (this);

    addAndMakeVisible (m_MFXTypeLabel = new Label ("MFXTypeLabel",
                                                   TRANS("M-FX Type")));
    m_MFXTypeLabel->setFont (Font (15.00f, Font::plain));
    m_MFXTypeLabel->setJustificationType (Justification::centredLeft);
    m_MFXTypeLabel->setEditable (false, false, false);
    m_MFXTypeLabel->setColour (TextEditor::textColourId, Colours::black);
    m_MFXTypeLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_MFXTypeDescriptionTextEditor = new TextEditor ("MFXTypeDescriptionTextEditor"));
    m_MFXTypeDescriptionTextEditor->setMultiLine (true);
    m_MFXTypeDescriptionTextEditor->setReturnKeyStartsNewLine (true);
    m_MFXTypeDescriptionTextEditor->setReadOnly (true);
    m_MFXTypeDescriptionTextEditor->setScrollbarsShown (true);
    m_MFXTypeDescriptionTextEditor->setCaretVisible (false);
    m_MFXTypeDescriptionTextEditor->setPopupMenuEnabled (true);
    m_MFXTypeDescriptionTextEditor->setColour (TextEditor::backgroundColourId, Colour (0xffe0e0e0));
    m_MFXTypeDescriptionTextEditor->setText (String::empty);


    //[UserPreSize]
	for (int i = 0; i < getNumChildComponents(); i++)
	{
		getChildComponent(i)->setComponentID(getChildComponent(i)->getName());
	}

	m_partInfoCommonBlock = new PartInfoCommonBlock();
	Parameter* m_FX_Type(m_partInfoCommonBlock->getParameter(0x0D));
	for (uint8 i = m_FX_Type->getMin(); i <= m_FX_Type->getMax(); i++)
	{
		m_MFXTypeComboBox->addItem(String(i + 1) + ": " + m_FX_Type->getDisplayedValue(i), i + 1);
	}
    //[/UserPreSize]

    setSize (432, 488);


    //[Constructor] You can add your own custom stuff here..
    //[/Constructor]
}

MFXEditor::~MFXEditor()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    m_paramSlider1 = nullptr;
    m_paramLabel1 = nullptr;
    m_paramSlider2 = nullptr;
    m_paramLabel2 = nullptr;
    m_paramSlider3 = nullptr;
    m_paramLabel3 = nullptr;
    m_paramSlider4 = nullptr;
    m_paramLabel4 = nullptr;
    m_paramSlider5 = nullptr;
    m_paramLabel5 = nullptr;
    m_paramSlider6 = nullptr;
    m_paramLabel6 = nullptr;
    m_paramSlider7 = nullptr;
    m_paramLabel7 = nullptr;
    m_paramSlider8 = nullptr;
    m_paramLabel8 = nullptr;
    m_paramSlider9 = nullptr;
    m_paramLabel9 = nullptr;
    m_paramSlider10 = nullptr;
    m_paramLabel10 = nullptr;
    m_paramSlider11 = nullptr;
    m_paramLabel11 = nullptr;
    m_MFXTypeComboBox = nullptr;
    m_MFXTypeLabel = nullptr;
    m_MFXTypeDescriptionTextEditor = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void MFXEditor::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
	#ifdef JUCE_MSVC
	g;
	#endif
    //[/UserPrePaint]

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void MFXEditor::resized()
{
    m_paramSlider1->setBounds (184, 136, 240, 24);
    m_paramLabel1->setBounds (8, 136, 168, 24);
    m_paramSlider2->setBounds (184, 168, 240, 24);
    m_paramLabel2->setBounds (8, 168, 168, 24);
    m_paramSlider3->setBounds (184, 200, 240, 24);
    m_paramLabel3->setBounds (8, 200, 168, 24);
    m_paramSlider4->setBounds (184, 232, 240, 24);
    m_paramLabel4->setBounds (8, 232, 168, 24);
    m_paramSlider5->setBounds (184, 264, 240, 24);
    m_paramLabel5->setBounds (8, 264, 168, 24);
    m_paramSlider6->setBounds (184, 296, 240, 24);
    m_paramLabel6->setBounds (8, 296, 168, 24);
    m_paramSlider7->setBounds (184, 328, 240, 24);
    m_paramLabel7->setBounds (8, 328, 168, 24);
    m_paramSlider8->setBounds (184, 360, 240, 24);
    m_paramLabel8->setBounds (8, 360, 168, 24);
    m_paramSlider9->setBounds (184, 392, 240, 24);
    m_paramLabel9->setBounds (8, 392, 168, 24);
    m_paramSlider10->setBounds (184, 424, 240, 24);
    m_paramLabel10->setBounds (8, 424, 168, 24);
    m_paramSlider11->setBounds (184, 456, 240, 24);
    m_paramLabel11->setBounds (8, 456, 168, 24);
    m_MFXTypeComboBox->setBounds (184, 8, 240, 24);
    m_MFXTypeLabel->setBounds (8, 8, 168, 24);
    m_MFXTypeDescriptionTextEditor->setBounds (8, 40, 416, 88);
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void MFXEditor::sliderValueChanged (Slider* sliderThatWasMoved)
{
    //[UsersliderValueChanged_Pre]
    //[/UsersliderValueChanged_Pre]

    if (sliderThatWasMoved == m_paramSlider1)
    {
        //[UserSliderCode_m_paramSlider1] -- add your slider handling code here..
		Parameter* param = m_partInfoCommonBlock->getParameter(0x0E);
		String suffix (param->getDisplayedValue((uint8)m_paramSlider1->getValue()));
		sliderThatWasMoved->setTextValueSuffix(suffix);
        //[/UserSliderCode_m_paramSlider1]
    }
    else if (sliderThatWasMoved == m_paramSlider2)
    {
        //[UserSliderCode_m_paramSlider2] -- add your slider handling code here..
		Parameter* param = m_partInfoCommonBlock->getParameter(0x0F);
		String suffix(param->getDisplayedValue((uint8)m_paramSlider1->getValue()));
		sliderThatWasMoved->setTextValueSuffix(suffix);
        //[/UserSliderCode_m_paramSlider2]
    }
    else if (sliderThatWasMoved == m_paramSlider3)
    {
        //[UserSliderCode_m_paramSlider3] -- add your slider handling code here..
		Parameter* param = m_partInfoCommonBlock->getParameter(0x10);
		String suffix(param->getDisplayedValue((uint8)m_paramSlider1->getValue()));
		sliderThatWasMoved->setTextValueSuffix(suffix);
        //[/UserSliderCode_m_paramSlider3]
    }
    else if (sliderThatWasMoved == m_paramSlider4)
    {
        //[UserSliderCode_m_paramSlider4] -- add your slider handling code here..
		Parameter* param = m_partInfoCommonBlock->getParameter(0x11);
		String suffix(param->getDisplayedValue((uint8)m_paramSlider1->getValue()));
		sliderThatWasMoved->setTextValueSuffix(suffix);
        //[/UserSliderCode_m_paramSlider4]
    }
    else if (sliderThatWasMoved == m_paramSlider5)
    {
        //[UserSliderCode_m_paramSlider5] -- add your slider handling code here..
		Parameter* param = m_partInfoCommonBlock->getParameter(0x12);
		String suffix(param->getDisplayedValue((uint8)m_paramSlider1->getValue()));
		sliderThatWasMoved->setTextValueSuffix(suffix);
        //[/UserSliderCode_m_paramSlider5]
    }
    else if (sliderThatWasMoved == m_paramSlider6)
    {
        //[UserSliderCode_m_paramSlider6] -- add your slider handling code here..
		Parameter* param = m_partInfoCommonBlock->getParameter(0x13);
		String suffix(param->getDisplayedValue((uint8)m_paramSlider1->getValue()));
		sliderThatWasMoved->setTextValueSuffix(suffix);
        //[/UserSliderCode_m_paramSlider6]
    }
    else if (sliderThatWasMoved == m_paramSlider7)
    {
        //[UserSliderCode_m_paramSlider7] -- add your slider handling code here..
		Parameter* param = m_partInfoCommonBlock->getParameter(0x14);
		String suffix(param->getDisplayedValue((uint8)m_paramSlider1->getValue()));
		sliderThatWasMoved->setTextValueSuffix(suffix);
        //[/UserSliderCode_m_paramSlider7]
    }
    else if (sliderThatWasMoved == m_paramSlider8)
    {
        //[UserSliderCode_m_paramSlider8] -- add your slider handling code here..
		Parameter* param = m_partInfoCommonBlock->getParameter(0x15);
		String suffix(param->getDisplayedValue((uint8)m_paramSlider1->getValue()));
		sliderThatWasMoved->setTextValueSuffix(suffix);
        //[/UserSliderCode_m_paramSlider8]
    }
    else if (sliderThatWasMoved == m_paramSlider9)
    {
        //[UserSliderCode_m_paramSlider9] -- add your slider handling code here..
		Parameter* param = m_partInfoCommonBlock->getParameter(0x16);
		String suffix(param->getDisplayedValue((uint8)m_paramSlider1->getValue()));
		sliderThatWasMoved->setTextValueSuffix(suffix);
        //[/UserSliderCode_m_paramSlider9]
    }
    else if (sliderThatWasMoved == m_paramSlider10)
    {
        //[UserSliderCode_m_paramSlider10] -- add your slider handling code here..
		Parameter* param = m_partInfoCommonBlock->getParameter(0x17);
		String suffix(param->getDisplayedValue((uint8)m_paramSlider1->getValue()));
		sliderThatWasMoved->setTextValueSuffix(suffix);
        //[/UserSliderCode_m_paramSlider10]
    }
    else if (sliderThatWasMoved == m_paramSlider11)
    {
        //[UserSliderCode_m_paramSlider11] -- add your slider handling code here..
		Parameter* param = m_partInfoCommonBlock->getParameter(0x18);
		String suffix(param->getDisplayedValue((uint8)m_paramSlider1->getValue()));
		sliderThatWasMoved->setTextValueSuffix(suffix);
        //[/UserSliderCode_m_paramSlider11]
    }

    //[UsersliderValueChanged_Post]
    //[/UsersliderValueChanged_Post]
}

void MFXEditor::comboBoxChanged (ComboBox* comboBoxThatHasChanged)
{
    //[UsercomboBoxChanged_Pre]
    //[/UsercomboBoxChanged_Pre]

    if (comboBoxThatHasChanged == m_MFXTypeComboBox)
    {
        //[UserComboBoxCode_m_MFXTypeComboBox] -- add your combo box handling code here..
		m_partInfoCommonBlock->refreshParametersForMFXTypeValue((uint8)m_MFXTypeComboBox->getSelectedId()-1);
		m_MFXTypeDescriptionTextEditor->setText(m_partInfoCommonBlock->getEffectDescription(), dontSendNotification);

		for (uint8 i = 0; i < 11; i++)
		{
			Label* label = dynamic_cast<Label*>(findChildWithID("paramLabel" + String(i + 1)));
			if (ParameterSlider* slider = dynamic_cast<ParameterSlider*>(findChildWithID("paramSlider" + String(i + 1))))
			{
				Parameter* param = m_partInfoCommonBlock->getParameter(0x0E + i);
				if (param != nullptr && param->getName().isNotEmpty())
				{
					slider->setParameter(param);
					slider->setRange(param->getMin(), param->getMax(), 1.0);
					label->setVisible(true);
					slider->setVisible(true);
					label->setText(param->getName(), dontSendNotification);
					label->setTooltip(param->getDescription());
					slider->setTooltip(param->getDescription());
				}
			}
			else {
				label->setVisible(false);
				slider->setVisible(false);
			}
		}
        //[/UserComboBoxCode_m_MFXTypeComboBox]
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

<JUCER_COMPONENT documentType="Component" className="MFXEditor" componentName=""
                 parentClasses="public Component" constructorParams="" variableInitialisers=""
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="1" initialWidth="432" initialHeight="488">
  <BACKGROUND backgroundColour="f5f5f5"/>
  <SLIDER name="paramSlider1" id="d0a9513fc3a91caa" memberName="m_paramSlider1"
          virtualName="ParameterSlider" explicitFocusOrder="0" pos="184 136 240 24"
          bkgcol="ffffffff" min="0" max="127" int="1" style="LinearBar"
          textBoxPos="TextBoxLeft" textBoxEditable="1" textBoxWidth="80"
          textBoxHeight="20" skewFactor="1"/>
  <LABEL name="paramLabel1" id="26c4c7d87be07d4e" memberName="m_paramLabel1"
         virtualName="" explicitFocusOrder="0" pos="8 136 168 24" edTextCol="ff000000"
         edBkgCol="0" labelText="M-FX Parameter 1" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" bold="0" italic="0" justification="33"/>
  <SLIDER name="paramSlider2" id="4821e52736d929c5" memberName="m_paramSlider2"
          virtualName="ParameterSlider" explicitFocusOrder="0" pos="184 168 240 24"
          bkgcol="ffffffff" min="0" max="127" int="1" style="LinearBar"
          textBoxPos="TextBoxLeft" textBoxEditable="1" textBoxWidth="80"
          textBoxHeight="20" skewFactor="1"/>
  <LABEL name="paramLabel2" id="edfa2e3b40b60132" memberName="m_paramLabel2"
         virtualName="" explicitFocusOrder="0" pos="8 168 168 24" edTextCol="ff000000"
         edBkgCol="0" labelText="M-FX Parameter 2" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" bold="0" italic="0" justification="33"/>
  <SLIDER name="paramSlider3" id="71ed30aebc0bc355" memberName="m_paramSlider3"
          virtualName="ParameterSlider" explicitFocusOrder="0" pos="184 200 240 24"
          bkgcol="ffffffff" min="0" max="127" int="1" style="LinearBar"
          textBoxPos="TextBoxLeft" textBoxEditable="1" textBoxWidth="80"
          textBoxHeight="20" skewFactor="1"/>
  <LABEL name="paramLabel3" id="e5eb06fac533310b" memberName="m_paramLabel3"
         virtualName="" explicitFocusOrder="0" pos="8 200 168 24" edTextCol="ff000000"
         edBkgCol="0" labelText="M-FX Parameter 3" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" bold="0" italic="0" justification="33"/>
  <SLIDER name="paramSlider4" id="fc9e47aed2428f4f" memberName="m_paramSlider4"
          virtualName="ParameterSlider" explicitFocusOrder="0" pos="184 232 240 24"
          bkgcol="ffffffff" min="0" max="127" int="1" style="LinearBar"
          textBoxPos="TextBoxLeft" textBoxEditable="1" textBoxWidth="80"
          textBoxHeight="20" skewFactor="1"/>
  <LABEL name="paramLabel4" id="361e9773fe349ccb" memberName="m_paramLabel4"
         virtualName="" explicitFocusOrder="0" pos="8 232 168 24" edTextCol="ff000000"
         edBkgCol="0" labelText="M-FX Parameter 4" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" bold="0" italic="0" justification="33"/>
  <SLIDER name="paramSlider5" id="53736e6f644de3fa" memberName="m_paramSlider5"
          virtualName="ParameterSlider" explicitFocusOrder="0" pos="184 264 240 24"
          bkgcol="ffffffff" min="0" max="127" int="1" style="LinearBar"
          textBoxPos="TextBoxLeft" textBoxEditable="1" textBoxWidth="80"
          textBoxHeight="20" skewFactor="1"/>
  <LABEL name="paramLabel5" id="84b29f6843e70961" memberName="m_paramLabel5"
         virtualName="" explicitFocusOrder="0" pos="8 264 168 24" edTextCol="ff000000"
         edBkgCol="0" labelText="M-FX Parameter 5" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" bold="0" italic="0" justification="33"/>
  <SLIDER name="paramSlider6" id="40632b4ba9eba11" memberName="m_paramSlider6"
          virtualName="ParameterSlider" explicitFocusOrder="0" pos="184 296 240 24"
          bkgcol="ffffffff" min="0" max="127" int="1" style="LinearBar"
          textBoxPos="TextBoxLeft" textBoxEditable="1" textBoxWidth="80"
          textBoxHeight="20" skewFactor="1"/>
  <LABEL name="paramLabel6" id="c473e7af094036db" memberName="m_paramLabel6"
         virtualName="" explicitFocusOrder="0" pos="8 296 168 24" edTextCol="ff000000"
         edBkgCol="0" labelText="M-FX Parameter 6" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" bold="0" italic="0" justification="33"/>
  <SLIDER name="paramSlider7" id="fc59c3d4d89f8303" memberName="m_paramSlider7"
          virtualName="ParameterSlider" explicitFocusOrder="0" pos="184 328 240 24"
          bkgcol="ffffffff" min="0" max="127" int="1" style="LinearBar"
          textBoxPos="TextBoxLeft" textBoxEditable="1" textBoxWidth="80"
          textBoxHeight="20" skewFactor="1"/>
  <LABEL name="paramLabel7" id="9d09551f236443d9" memberName="m_paramLabel7"
         virtualName="" explicitFocusOrder="0" pos="8 328 168 24" edTextCol="ff000000"
         edBkgCol="0" labelText="M-FX Parameter 7" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" bold="0" italic="0" justification="33"/>
  <SLIDER name="paramSlider8" id="29a992b05c679b6d" memberName="m_paramSlider8"
          virtualName="ParameterSlider" explicitFocusOrder="0" pos="184 360 240 24"
          bkgcol="ffffffff" min="0" max="127" int="1" style="LinearBar"
          textBoxPos="TextBoxLeft" textBoxEditable="1" textBoxWidth="80"
          textBoxHeight="20" skewFactor="1"/>
  <LABEL name="paramLabel8" id="139e83611709d0de" memberName="m_paramLabel8"
         virtualName="" explicitFocusOrder="0" pos="8 360 168 24" edTextCol="ff000000"
         edBkgCol="0" labelText="M-FX Parameter 8" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" bold="0" italic="0" justification="33"/>
  <SLIDER name="paramSlider9" id="2d51feeac15453bd" memberName="m_paramSlider9"
          virtualName="ParameterSlider" explicitFocusOrder="0" pos="184 392 240 24"
          bkgcol="ffffffff" min="0" max="127" int="1" style="LinearBar"
          textBoxPos="TextBoxLeft" textBoxEditable="1" textBoxWidth="80"
          textBoxHeight="20" skewFactor="1"/>
  <LABEL name="paramLabel9" id="c976388ace30186f" memberName="m_paramLabel9"
         virtualName="" explicitFocusOrder="0" pos="8 392 168 24" edTextCol="ff000000"
         edBkgCol="0" labelText="M-FX Parameter 9" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" bold="0" italic="0" justification="33"/>
  <SLIDER name="paramSlider10" id="18f3dba27081936e" memberName="m_paramSlider10"
          virtualName="ParameterSlider" explicitFocusOrder="0" pos="184 424 240 24"
          bkgcol="ffffffff" min="0" max="127" int="1" style="LinearBar"
          textBoxPos="TextBoxLeft" textBoxEditable="1" textBoxWidth="80"
          textBoxHeight="20" skewFactor="1"/>
  <LABEL name="paramLabel10" id="67997801d93968ed" memberName="m_paramLabel10"
         virtualName="" explicitFocusOrder="0" pos="8 424 168 24" edTextCol="ff000000"
         edBkgCol="0" labelText="M-FX Parameter 10" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" bold="0" italic="0" justification="33"/>
  <SLIDER name="paramSlider11" id="cec491c6bcd28d25" memberName="m_paramSlider11"
          virtualName="ParameterSlider" explicitFocusOrder="0" pos="184 456 240 24"
          bkgcol="ffffffff" min="0" max="127" int="1" style="LinearBar"
          textBoxPos="TextBoxLeft" textBoxEditable="1" textBoxWidth="80"
          textBoxHeight="20" skewFactor="1"/>
  <LABEL name="paramLabel11" id="ffd78ecf192afd8" memberName="m_paramLabel11"
         virtualName="" explicitFocusOrder="0" pos="8 456 168 24" edTextCol="ff000000"
         edBkgCol="0" labelText="M-FX Parameter 11" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" bold="0" italic="0" justification="33"/>
  <COMBOBOX name="MFXTypeComboBox" id="310da11a3b4d1c0" memberName="m_MFXTypeComboBox"
            virtualName="" explicitFocusOrder="0" pos="184 8 240 24" editable="0"
            layout="33" items="" textWhenNonSelected="" textWhenNoItems="(no choices)"/>
  <LABEL name="MFXTypeLabel" id="46e1e88403b5ba1f" memberName="m_MFXTypeLabel"
         virtualName="" explicitFocusOrder="0" pos="8 8 168 24" edTextCol="ff000000"
         edBkgCol="0" labelText="M-FX Type" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         bold="0" italic="0" justification="33"/>
  <TEXTEDITOR name="MFXTypeDescriptionTextEditor" id="ef9484120a302f50" memberName="m_MFXTypeDescriptionTextEditor"
              virtualName="" explicitFocusOrder="0" pos="8 40 416 88" bkgcol="ffe0e0e0"
              initialText="" multiline="1" retKeyStartsLine="1" readonly="1"
              scrollbars="1" caret="0" popupmenu="1"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
