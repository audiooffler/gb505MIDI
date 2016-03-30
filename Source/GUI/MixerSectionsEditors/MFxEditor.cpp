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

#include "MFxEditor.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
extern OverallMemoryBlock* grooveboxMemory;
//[/MiscUserDefs]

//==============================================================================
MFXEditor::MFXEditor ()
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    addAndMakeVisible (component = new PanelGroupGrey ("mfxEditorPanelGroup","MULTI-EFFECTS (M-FX)"));
    addAndMakeVisible (m_paramLabel1 = new Label ("paramLabel1",
                                                  String()));
    m_paramLabel1->setFont (Font (12.00f, Font::bold));
    m_paramLabel1->setJustificationType (Justification::centredLeft);
    m_paramLabel1->setEditable (false, false, false);
    m_paramLabel1->setColour (TextEditor::textColourId, Colours::black);
    m_paramLabel1->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_paramSlider1 = new ParameterSlider ("paramSlider1"));
    m_paramSlider1->setRange (0, 127, 1);
    m_paramSlider1->setSliderStyle (Slider::LinearBar);
    m_paramSlider1->setTextBoxStyle (Slider::TextBoxLeft, false, 80, 20);
    m_paramSlider1->setColour (Slider::backgroundColourId, Colour (0xfff2f59b));
    m_paramSlider1->setColour (Slider::thumbColourId, Colour (0xffc4c86d));
    m_paramSlider1->addListener (this);

    addAndMakeVisible (m_paramSlider2 = new ParameterSlider ("paramSlider2"));
    m_paramSlider2->setRange (0, 127, 1);
    m_paramSlider2->setSliderStyle (Slider::LinearBar);
    m_paramSlider2->setTextBoxStyle (Slider::TextBoxLeft, false, 80, 20);
    m_paramSlider2->setColour (Slider::backgroundColourId, Colour (0xfff2f59b));
    m_paramSlider2->setColour (Slider::thumbColourId, Colour (0xffc4c86d));
    m_paramSlider2->addListener (this);

    addAndMakeVisible (m_paramLabel2 = new Label ("paramLabel2",
                                                  String()));
    m_paramLabel2->setFont (Font (12.00f, Font::bold));
    m_paramLabel2->setJustificationType (Justification::centredLeft);
    m_paramLabel2->setEditable (false, false, false);
    m_paramLabel2->setColour (TextEditor::textColourId, Colours::black);
    m_paramLabel2->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_paramSlider3 = new ParameterSlider ("paramSlider3"));
    m_paramSlider3->setRange (0, 127, 1);
    m_paramSlider3->setSliderStyle (Slider::LinearBar);
    m_paramSlider3->setTextBoxStyle (Slider::TextBoxLeft, false, 80, 20);
    m_paramSlider3->setColour (Slider::backgroundColourId, Colour (0xfff2f59b));
    m_paramSlider3->setColour (Slider::thumbColourId, Colour (0xffc4c86d));
    m_paramSlider3->addListener (this);

    addAndMakeVisible (m_paramLabel3 = new Label ("paramLabel3",
                                                  String()));
    m_paramLabel3->setFont (Font (12.00f, Font::bold));
    m_paramLabel3->setJustificationType (Justification::centredLeft);
    m_paramLabel3->setEditable (false, false, false);
    m_paramLabel3->setColour (TextEditor::textColourId, Colours::black);
    m_paramLabel3->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_paramSlider4 = new ParameterSlider ("paramSlider4"));
    m_paramSlider4->setRange (0, 127, 1);
    m_paramSlider4->setSliderStyle (Slider::LinearBar);
    m_paramSlider4->setTextBoxStyle (Slider::TextBoxLeft, false, 80, 20);
    m_paramSlider4->setColour (Slider::backgroundColourId, Colour (0xfff2f59b));
    m_paramSlider4->setColour (Slider::thumbColourId, Colour (0xffc4c86d));
    m_paramSlider4->addListener (this);

    addAndMakeVisible (m_paramLabel4 = new Label ("paramLabel4",
                                                  String()));
    m_paramLabel4->setFont (Font (12.00f, Font::bold));
    m_paramLabel4->setJustificationType (Justification::centredLeft);
    m_paramLabel4->setEditable (false, false, false);
    m_paramLabel4->setColour (TextEditor::textColourId, Colours::black);
    m_paramLabel4->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_paramSlider5 = new ParameterSlider ("paramSlider5"));
    m_paramSlider5->setRange (0, 127, 1);
    m_paramSlider5->setSliderStyle (Slider::LinearBar);
    m_paramSlider5->setTextBoxStyle (Slider::TextBoxLeft, false, 80, 20);
    m_paramSlider5->setColour (Slider::backgroundColourId, Colour (0xfff2f59b));
    m_paramSlider5->setColour (Slider::thumbColourId, Colour (0xffc4c86d));
    m_paramSlider5->addListener (this);

    addAndMakeVisible (m_paramLabel5 = new Label ("paramLabel5",
                                                  String()));
    m_paramLabel5->setFont (Font (12.00f, Font::bold));
    m_paramLabel5->setJustificationType (Justification::centredLeft);
    m_paramLabel5->setEditable (false, false, false);
    m_paramLabel5->setColour (TextEditor::textColourId, Colours::black);
    m_paramLabel5->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_paramSlider6 = new ParameterSlider ("paramSlider6"));
    m_paramSlider6->setRange (0, 127, 1);
    m_paramSlider6->setSliderStyle (Slider::LinearBar);
    m_paramSlider6->setTextBoxStyle (Slider::TextBoxLeft, false, 80, 20);
    m_paramSlider6->setColour (Slider::backgroundColourId, Colour (0xfff2f59b));
    m_paramSlider6->setColour (Slider::thumbColourId, Colour (0xffc4c86d));
    m_paramSlider6->addListener (this);

    addAndMakeVisible (m_paramLabel6 = new Label ("paramLabel6",
                                                  String()));
    m_paramLabel6->setFont (Font (12.00f, Font::bold));
    m_paramLabel6->setJustificationType (Justification::centredLeft);
    m_paramLabel6->setEditable (false, false, false);
    m_paramLabel6->setColour (TextEditor::textColourId, Colours::black);
    m_paramLabel6->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_paramSlider7 = new ParameterSlider ("paramSlider7"));
    m_paramSlider7->setRange (0, 127, 1);
    m_paramSlider7->setSliderStyle (Slider::LinearBar);
    m_paramSlider7->setTextBoxStyle (Slider::TextBoxLeft, false, 80, 20);
    m_paramSlider7->setColour (Slider::backgroundColourId, Colour (0xfff2f59b));
    m_paramSlider7->setColour (Slider::thumbColourId, Colour (0xffc4c86d));
    m_paramSlider7->addListener (this);

    addAndMakeVisible (m_paramLabel7 = new Label ("paramLabel7",
                                                  String()));
    m_paramLabel7->setFont (Font (12.00f, Font::bold));
    m_paramLabel7->setJustificationType (Justification::centredLeft);
    m_paramLabel7->setEditable (false, false, false);
    m_paramLabel7->setColour (TextEditor::textColourId, Colours::black);
    m_paramLabel7->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_paramSlider8 = new ParameterSlider ("paramSlider8"));
    m_paramSlider8->setRange (0, 127, 1);
    m_paramSlider8->setSliderStyle (Slider::LinearBar);
    m_paramSlider8->setTextBoxStyle (Slider::TextBoxLeft, false, 80, 20);
    m_paramSlider8->setColour (Slider::backgroundColourId, Colour (0xfff2f59b));
    m_paramSlider8->setColour (Slider::thumbColourId, Colour (0xffc4c86d));
    m_paramSlider8->addListener (this);

    addAndMakeVisible (m_paramLabel8 = new Label ("paramLabel8",
                                                  String()));
    m_paramLabel8->setFont (Font (12.00f, Font::bold));
    m_paramLabel8->setJustificationType (Justification::centredLeft);
    m_paramLabel8->setEditable (false, false, false);
    m_paramLabel8->setColour (TextEditor::textColourId, Colours::black);
    m_paramLabel8->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_paramSlider9 = new ParameterSlider ("paramSlider9"));
    m_paramSlider9->setRange (0, 127, 1);
    m_paramSlider9->setSliderStyle (Slider::LinearBar);
    m_paramSlider9->setTextBoxStyle (Slider::TextBoxLeft, false, 80, 20);
    m_paramSlider9->setColour (Slider::backgroundColourId, Colour (0xfff2f59b));
    m_paramSlider9->setColour (Slider::thumbColourId, Colour (0xffc4c86d));
    m_paramSlider9->addListener (this);

    addAndMakeVisible (m_paramLabel9 = new Label ("paramLabel9",
                                                  String()));
    m_paramLabel9->setFont (Font (12.00f, Font::bold));
    m_paramLabel9->setJustificationType (Justification::centredLeft);
    m_paramLabel9->setEditable (false, false, false);
    m_paramLabel9->setColour (TextEditor::textColourId, Colours::black);
    m_paramLabel9->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_paramSlider10 = new ParameterSlider ("paramSlider10"));
    m_paramSlider10->setRange (0, 127, 1);
    m_paramSlider10->setSliderStyle (Slider::LinearBar);
    m_paramSlider10->setTextBoxStyle (Slider::TextBoxLeft, false, 80, 20);
    m_paramSlider10->setColour (Slider::backgroundColourId, Colour (0xfff2f59b));
    m_paramSlider10->setColour (Slider::thumbColourId, Colour (0xffc4c86d));
    m_paramSlider10->addListener (this);

    addAndMakeVisible (m_paramLabel10 = new Label ("paramLabel10",
                                                   String()));
    m_paramLabel10->setFont (Font (12.00f, Font::bold));
    m_paramLabel10->setJustificationType (Justification::centredLeft);
    m_paramLabel10->setEditable (false, false, false);
    m_paramLabel10->setColour (TextEditor::textColourId, Colours::black);
    m_paramLabel10->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_paramSlider11 = new ParameterSlider ("paramSlider11"));
    m_paramSlider11->setRange (0, 127, 1);
    m_paramSlider11->setSliderStyle (Slider::LinearBar);
    m_paramSlider11->setTextBoxStyle (Slider::TextBoxLeft, false, 80, 20);
    m_paramSlider11->setColour (Slider::backgroundColourId, Colour (0xfff2f59b));
    m_paramSlider11->setColour (Slider::thumbColourId, Colour (0xffc4c86d));
    m_paramSlider11->addListener (this);

    addAndMakeVisible (m_paramLabel11 = new Label ("paramLabel11",
                                                   String()));
    m_paramLabel11->setFont (Font (12.00f, Font::bold));
    m_paramLabel11->setJustificationType (Justification::centredLeft);
    m_paramLabel11->setEditable (false, false, false);
    m_paramLabel11->setColour (TextEditor::textColourId, Colours::black);
    m_paramLabel11->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_MFXTypeComboBox = new ParameterComboBox ("MFXTypeComboBox"));
    m_MFXTypeComboBox->setEditableText (false);
    m_MFXTypeComboBox->setJustificationType (Justification::centredLeft);
    m_MFXTypeComboBox->setTextWhenNothingSelected (String());
    m_MFXTypeComboBox->setTextWhenNoChoicesAvailable (TRANS("(no choices)"));
    m_MFXTypeComboBox->addListener (this);

    addAndMakeVisible (m_MFXTypeLabel = new Label ("MFXTypeLabel",
                                                   TRANS("M-FX TYPE")));
    m_MFXTypeLabel->setFont (Font (12.00f, Font::bold));
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
    m_MFXTypeDescriptionTextEditor->setText (String());

    addAndMakeVisible (m_MFXSendLabel = new Label ("MFXSendLabel",
                                                   TRANS("M-FX SEND")));
    m_MFXSendLabel->setFont (Font (12.00f, Font::bold));
    m_MFXSendLabel->setJustificationType (Justification::centredLeft);
    m_MFXSendLabel->setEditable (false, false, false);
    m_MFXSendLabel->setColour (TextEditor::textColourId, Colours::black);
    m_MFXSendLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_sendToReverbSlider = new MicroParameterSlider ("sendToReverbSlider"));
    m_sendToReverbSlider->setRange (-48, 48, 1);
    m_sendToReverbSlider->setSliderStyle (Slider::LinearBar);
    m_sendToReverbSlider->setTextBoxStyle (Slider::TextBoxLeft, false, 64, 20);
    m_sendToReverbSlider->setColour (Slider::backgroundColourId, Colour (0xfff2f59b));
    m_sendToReverbSlider->setColour (Slider::thumbColourId, Colour (0xffc4c86d));
    m_sendToReverbSlider->addListener (this);

    addAndMakeVisible (m_sendToDelaySlider = new MicroParameterSlider ("sendToDelaySlider"));
    m_sendToDelaySlider->setRange (-48, 48, 1);
    m_sendToDelaySlider->setSliderStyle (Slider::LinearBar);
    m_sendToDelaySlider->setTextBoxStyle (Slider::TextBoxLeft, false, 64, 20);
    m_sendToDelaySlider->setColour (Slider::backgroundColourId, Colour (0xfff2f59b));
    m_sendToDelaySlider->setColour (Slider::thumbColourId, Colour (0xffc4c86d));
    m_sendToDelaySlider->addListener (this);

    addAndMakeVisible (m_toDelayLabel = new Label ("toDelayLabel",
                                                   TRANS("TO DELAY")));
    m_toDelayLabel->setFont (Font (12.00f, Font::bold));
    m_toDelayLabel->setJustificationType (Justification::centredRight);
    m_toDelayLabel->setEditable (false, false, false);
    m_toDelayLabel->setColour (TextEditor::textColourId, Colours::black);
    m_toDelayLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_toReverbLabel = new Label ("toReverbLabel",
                                                    TRANS("TO REVERB")));
    m_toReverbLabel->setFont (Font (12.00f, Font::bold));
    m_toReverbLabel->setJustificationType (Justification::centredRight);
    m_toReverbLabel->setEditable (false, false, false);
    m_toReverbLabel->setColour (TextEditor::textColourId, Colours::black);
    m_toReverbLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));


    //[UserPreSize]
	m_paramSlider1->setVisible(false);
	m_paramSlider2->setVisible(false);
	m_paramSlider3->setVisible(false);
	m_paramSlider4->setVisible(false);
	m_paramSlider5->setVisible(false);
	m_paramSlider6->setVisible(false);
	m_paramSlider7->setVisible(false);
	m_paramSlider8->setVisible(false);
	m_paramSlider9->setVisible(false);
	m_paramSlider10->setVisible(false);
	m_paramSlider11->setVisible(false);

	for (int i = 0; i < getNumChildComponents(); i++)
	{
		getChildComponent(i)->setComponentID(getChildComponent(i)->getName());
	}

	m_partInfoCommonBlock = grooveboxMemory->getPartInfoBlock()->getPartInfoCommonBlockPtr();
	Parameter* m_FX_Type(m_partInfoCommonBlock->getParameter(0x0D));
	//for (uint8 i = m_FX_Type->getMin(); i <= m_FX_Type->getMax(); i++)
	//{
	//	m_MFXTypeComboBox->addItem(String(i + 1) + ": " + m_FX_Type->getDisplayedValue(i), i + 1);
	//}
	m_MFXTypeComboBox->setParameter(m_FX_Type);
	m_FX_Type->addChangeListener(this);
	m_sendToReverbSlider->setParameter(m_partInfoCommonBlock->getParameter(0x1D));
	m_sendToDelaySlider->setParameter(m_partInfoCommonBlock->getParameter(0x1C));
	m_paramSlider1->setParameter(m_partInfoCommonBlock->getParameter(0x0E));
	m_paramSlider2->setParameter(m_partInfoCommonBlock->getParameter(0x0F));
	m_paramSlider3->setParameter(m_partInfoCommonBlock->getParameter(0x10));
	m_paramSlider4->setParameter(m_partInfoCommonBlock->getParameter(0x11));
	m_paramSlider5->setParameter(m_partInfoCommonBlock->getParameter(0x12));
	m_paramSlider6->setParameter(m_partInfoCommonBlock->getParameter(0x13));
	m_paramSlider7->setParameter(m_partInfoCommonBlock->getParameter(0x14));
	m_paramSlider8->setParameter(m_partInfoCommonBlock->getParameter(0x15));
	m_paramSlider9->setParameter(m_partInfoCommonBlock->getParameter(0x16));
	m_paramSlider10->setParameter(m_partInfoCommonBlock->getParameter(0x17));
	m_paramSlider11->setParameter(m_partInfoCommonBlock->getParameter(0x18));
	changeListenerCallback(m_FX_Type);
    //[/UserPreSize]

    setSize (344, 424);


    //[Constructor] You can add your own custom stuff here..
    //[/Constructor]
}

MFXEditor::~MFXEditor()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
	if (m_partInfoCommonBlock != nullptr && m_partInfoCommonBlock->getParameter(0x0D) != nullptr) m_partInfoCommonBlock->getParameter(0x0D)->removeChangeListener(this);
    //[/Destructor_pre]

    component = nullptr;
    m_paramLabel1 = nullptr;
    m_paramSlider1 = nullptr;
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
    m_MFXSendLabel = nullptr;
    m_sendToReverbSlider = nullptr;
    m_sendToDelaySlider = nullptr;
    m_toDelayLabel = nullptr;
    m_toReverbLabel = nullptr;


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
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    component->setBounds (0, 0, getWidth() - 0, getHeight() - 0);
    m_paramLabel1->setBounds (8, 160, 144, 16);
    m_paramSlider1->setBounds (152, 160, 184, 16);
    m_paramSlider2->setBounds (152, 184, 184, 16);
    m_paramLabel2->setBounds (8, 184, 144, 16);
    m_paramSlider3->setBounds (152, 208, 184, 16);
    m_paramLabel3->setBounds (8, 208, 144, 16);
    m_paramSlider4->setBounds (152, 232, 184, 16);
    m_paramLabel4->setBounds (8, 232, 144, 16);
    m_paramSlider5->setBounds (152, 256, 184, 16);
    m_paramLabel5->setBounds (8, 256, 144, 16);
    m_paramSlider6->setBounds (152, 280, 184, 16);
    m_paramLabel6->setBounds (8, 280, 144, 16);
    m_paramSlider7->setBounds (152, 304, 184, 16);
    m_paramLabel7->setBounds (8, 304, 144, 16);
    m_paramSlider8->setBounds (152, 328, 184, 16);
    m_paramLabel8->setBounds (8, 328, 144, 16);
    m_paramSlider9->setBounds (152, 352, 184, 16);
    m_paramLabel9->setBounds (8, 352, 144, 16);
    m_paramSlider10->setBounds (152, 376, 184, 16);
    m_paramLabel10->setBounds (8, 376, 144, 16);
    m_paramSlider11->setBounds (152, 400, 184, 16);
    m_paramLabel11->setBounds (8, 400, 144, 16);
    m_MFXTypeComboBox->setBounds (152, 48, 184, 16);
    m_MFXTypeLabel->setBounds (8, 48, 144, 16);
    m_MFXTypeDescriptionTextEditor->setBounds (8, 72, 328, 80);
    m_MFXSendLabel->setBounds (8, 24, 104, 16);
    m_sendToReverbSlider->setBounds (152, 24, 56, 16);
    m_sendToDelaySlider->setBounds (280, 24, 56, 16);
    m_toDelayLabel->setBounds (208, 24, 72, 16);
    m_toReverbLabel->setBounds (80, 24, 72, 16);
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
		//Parameter* param = m_partInfoCommonBlock->getParameter(0x0E);
		//String suffix (param->getDisplayedValue((uint8)m_paramSlider1->getValue()));
		//sliderThatWasMoved->setTextValueSuffix(suffix);
        //[/UserSliderCode_m_paramSlider1]
    }
    else if (sliderThatWasMoved == m_paramSlider2)
    {
        //[UserSliderCode_m_paramSlider2] -- add your slider handling code here..
		//Parameter* param = m_partInfoCommonBlock->getParameter(0x0F);
		//String suffix(param->getDisplayedValue((uint8)m_paramSlider1->getValue()));
		//sliderThatWasMoved->setTextValueSuffix(suffix);
        //[/UserSliderCode_m_paramSlider2]
    }
    else if (sliderThatWasMoved == m_paramSlider3)
    {
        //[UserSliderCode_m_paramSlider3] -- add your slider handling code here..
		//Parameter* param = m_partInfoCommonBlock->getParameter(0x10);
		//String suffix(param->getDisplayedValue((uint8)m_paramSlider1->getValue()));
		//sliderThatWasMoved->setTextValueSuffix(suffix);
        //[/UserSliderCode_m_paramSlider3]
    }
    else if (sliderThatWasMoved == m_paramSlider4)
    {
        //[UserSliderCode_m_paramSlider4] -- add your slider handling code here..
		//Parameter* param = m_partInfoCommonBlock->getParameter(0x11);
		//String suffix(param->getDisplayedValue((uint8)m_paramSlider1->getValue()));
		//sliderThatWasMoved->setTextValueSuffix(suffix);
        //[/UserSliderCode_m_paramSlider4]
    }
    else if (sliderThatWasMoved == m_paramSlider5)
    {
        //[UserSliderCode_m_paramSlider5] -- add your slider handling code here..
		//Parameter* param = m_partInfoCommonBlock->getParameter(0x12);
		//String suffix(param->getDisplayedValue((uint8)m_paramSlider1->getValue()));
		//sliderThatWasMoved->setTextValueSuffix(suffix);
        //[/UserSliderCode_m_paramSlider5]
    }
    else if (sliderThatWasMoved == m_paramSlider6)
    {
        //[UserSliderCode_m_paramSlider6] -- add your slider handling code here..
		//Parameter* param = m_partInfoCommonBlock->getParameter(0x13);
		//String suffix(param->getDisplayedValue((uint8)m_paramSlider1->getValue()));
		//sliderThatWasMoved->setTextValueSuffix(suffix);
        //[/UserSliderCode_m_paramSlider6]
    }
    else if (sliderThatWasMoved == m_paramSlider7)
    {
        //[UserSliderCode_m_paramSlider7] -- add your slider handling code here..
		//Parameter* param = m_partInfoCommonBlock->getParameter(0x14);
		//String suffix(param->getDisplayedValue((uint8)m_paramSlider1->getValue()));
		//sliderThatWasMoved->setTextValueSuffix(suffix);
        //[/UserSliderCode_m_paramSlider7]
    }
    else if (sliderThatWasMoved == m_paramSlider8)
    {
        //[UserSliderCode_m_paramSlider8] -- add your slider handling code here..
		//Parameter* param = m_partInfoCommonBlock->getParameter(0x15);
		//String suffix(param->getDisplayedValue((uint8)m_paramSlider1->getValue()));
		//sliderThatWasMoved->setTextValueSuffix(suffix);
        //[/UserSliderCode_m_paramSlider8]
    }
    else if (sliderThatWasMoved == m_paramSlider9)
    {
        //[UserSliderCode_m_paramSlider9] -- add your slider handling code here..
		//Parameter* param = m_partInfoCommonBlock->getParameter(0x16);
		//String suffix(param->getDisplayedValue((uint8)m_paramSlider1->getValue()));
		//sliderThatWasMoved->setTextValueSuffix(suffix);
        //[/UserSliderCode_m_paramSlider9]
    }
    else if (sliderThatWasMoved == m_paramSlider10)
    {
        //[UserSliderCode_m_paramSlider10] -- add your slider handling code here..
		//Parameter* param = m_partInfoCommonBlock->getParameter(0x17);
		//String suffix(param->getDisplayedValue((uint8)m_paramSlider1->getValue()));
		//sliderThatWasMoved->setTextValueSuffix(suffix);
        //[/UserSliderCode_m_paramSlider10]
    }
    else if (sliderThatWasMoved == m_paramSlider11)
    {
        //[UserSliderCode_m_paramSlider11] -- add your slider handling code here..
		//Parameter* param = m_partInfoCommonBlock->getParameter(0x18);
		//String suffix(param->getDisplayedValue((uint8)m_paramSlider1->getValue()));
		//sliderThatWasMoved->setTextValueSuffix(suffix);
        //[/UserSliderCode_m_paramSlider11]
    }
    else if (sliderThatWasMoved == m_sendToReverbSlider)
    {
        //[UserSliderCode_m_sendToReverbSlider] -- add your slider handling code here..
        //[/UserSliderCode_m_sendToReverbSlider]
    }
    else if (sliderThatWasMoved == m_sendToDelaySlider)
    {
        //[UserSliderCode_m_sendToDelaySlider] -- add your slider handling code here..
        //[/UserSliderCode_m_sendToDelaySlider]
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
        //[/UserComboBoxCode_m_MFXTypeComboBox]
    }

    //[UsercomboBoxChanged_Post]
    //[/UsercomboBoxChanged_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...

void MFXEditor::changeListenerCallback(ChangeBroadcaster* source)
{
	if (source == m_partInfoCommonBlock->getParameter(0x0D))
	{
		m_partInfoCommonBlock->refreshParametersForMFXTypeValue(m_partInfoCommonBlock->getParameter(0x0D)->getValue());
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
					label->setText(param->getName().toUpperCase(), dontSendNotification);
					label->setTooltip(param->getDescription());
					slider->setTooltip(param->getDescription());
				}
				else
				{
					label->setVisible(false);
					slider->setVisible(false);
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

<JUCER_COMPONENT documentType="Component" className="MFXEditor" componentName=""
                 parentClasses="public Component, public ChangeListener" constructorParams=""
                 variableInitialisers="" snapPixels="8" snapActive="1" snapShown="1"
                 overlayOpacity="0.330" fixedSize="1" initialWidth="344" initialHeight="424">
  <BACKGROUND backgroundColour="0"/>
  <JUCERCOMP name="" id="4b94c0a5a762f613" memberName="component" virtualName=""
             explicitFocusOrder="0" pos="0 0 0M 0M" sourceFile="../GroupWidgets/PanelGroupGrey.cpp"
             constructorParams="&quot;mfxEditorPanelGroup&quot;,&quot;MULTI-EFFECTS (M-FX)&quot;"/>
  <LABEL name="paramLabel1" id="26c4c7d87be07d4e" memberName="m_paramLabel1"
         virtualName="" explicitFocusOrder="0" pos="8 160 144 16" edTextCol="ff000000"
         edBkgCol="0" labelText="" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="12"
         bold="1" italic="0" justification="33"/>
  <SLIDER name="paramSlider1" id="d0a9513fc3a91caa" memberName="m_paramSlider1"
          virtualName="ParameterSlider" explicitFocusOrder="0" pos="152 160 184 16"
          bkgcol="fff2f59b" thumbcol="ffc4c86d" min="0" max="127" int="1"
          style="LinearBar" textBoxPos="TextBoxLeft" textBoxEditable="1"
          textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="paramSlider2" id="4821e52736d929c5" memberName="m_paramSlider2"
          virtualName="ParameterSlider" explicitFocusOrder="0" pos="152 184 184 16"
          bkgcol="fff2f59b" thumbcol="ffc4c86d" min="0" max="127" int="1"
          style="LinearBar" textBoxPos="TextBoxLeft" textBoxEditable="1"
          textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <LABEL name="paramLabel2" id="edfa2e3b40b60132" memberName="m_paramLabel2"
         virtualName="" explicitFocusOrder="0" pos="8 184 144 16" edTextCol="ff000000"
         edBkgCol="0" labelText="" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="12"
         bold="1" italic="0" justification="33"/>
  <SLIDER name="paramSlider3" id="71ed30aebc0bc355" memberName="m_paramSlider3"
          virtualName="ParameterSlider" explicitFocusOrder="0" pos="152 208 184 16"
          bkgcol="fff2f59b" thumbcol="ffc4c86d" min="0" max="127" int="1"
          style="LinearBar" textBoxPos="TextBoxLeft" textBoxEditable="1"
          textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <LABEL name="paramLabel3" id="e5eb06fac533310b" memberName="m_paramLabel3"
         virtualName="" explicitFocusOrder="0" pos="8 208 144 16" edTextCol="ff000000"
         edBkgCol="0" labelText="" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="12"
         bold="1" italic="0" justification="33"/>
  <SLIDER name="paramSlider4" id="fc9e47aed2428f4f" memberName="m_paramSlider4"
          virtualName="ParameterSlider" explicitFocusOrder="0" pos="152 232 184 16"
          bkgcol="fff2f59b" thumbcol="ffc4c86d" min="0" max="127" int="1"
          style="LinearBar" textBoxPos="TextBoxLeft" textBoxEditable="1"
          textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <LABEL name="paramLabel4" id="361e9773fe349ccb" memberName="m_paramLabel4"
         virtualName="" explicitFocusOrder="0" pos="8 232 144 16" edTextCol="ff000000"
         edBkgCol="0" labelText="" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="12"
         bold="1" italic="0" justification="33"/>
  <SLIDER name="paramSlider5" id="53736e6f644de3fa" memberName="m_paramSlider5"
          virtualName="ParameterSlider" explicitFocusOrder="0" pos="152 256 184 16"
          bkgcol="fff2f59b" thumbcol="ffc4c86d" min="0" max="127" int="1"
          style="LinearBar" textBoxPos="TextBoxLeft" textBoxEditable="1"
          textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <LABEL name="paramLabel5" id="84b29f6843e70961" memberName="m_paramLabel5"
         virtualName="" explicitFocusOrder="0" pos="8 256 144 16" edTextCol="ff000000"
         edBkgCol="0" labelText="" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="12"
         bold="1" italic="0" justification="33"/>
  <SLIDER name="paramSlider6" id="40632b4ba9eba11" memberName="m_paramSlider6"
          virtualName="ParameterSlider" explicitFocusOrder="0" pos="152 280 184 16"
          bkgcol="fff2f59b" thumbcol="ffc4c86d" min="0" max="127" int="1"
          style="LinearBar" textBoxPos="TextBoxLeft" textBoxEditable="1"
          textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <LABEL name="paramLabel6" id="c473e7af094036db" memberName="m_paramLabel6"
         virtualName="" explicitFocusOrder="0" pos="8 280 144 16" edTextCol="ff000000"
         edBkgCol="0" labelText="" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="12"
         bold="1" italic="0" justification="33"/>
  <SLIDER name="paramSlider7" id="fc59c3d4d89f8303" memberName="m_paramSlider7"
          virtualName="ParameterSlider" explicitFocusOrder="0" pos="152 304 184 16"
          bkgcol="fff2f59b" thumbcol="ffc4c86d" min="0" max="127" int="1"
          style="LinearBar" textBoxPos="TextBoxLeft" textBoxEditable="1"
          textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <LABEL name="paramLabel7" id="9d09551f236443d9" memberName="m_paramLabel7"
         virtualName="" explicitFocusOrder="0" pos="8 304 144 16" edTextCol="ff000000"
         edBkgCol="0" labelText="" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="12"
         bold="1" italic="0" justification="33"/>
  <SLIDER name="paramSlider8" id="29a992b05c679b6d" memberName="m_paramSlider8"
          virtualName="ParameterSlider" explicitFocusOrder="0" pos="152 328 184 16"
          bkgcol="fff2f59b" thumbcol="ffc4c86d" min="0" max="127" int="1"
          style="LinearBar" textBoxPos="TextBoxLeft" textBoxEditable="1"
          textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <LABEL name="paramLabel8" id="139e83611709d0de" memberName="m_paramLabel8"
         virtualName="" explicitFocusOrder="0" pos="8 328 144 16" edTextCol="ff000000"
         edBkgCol="0" labelText="" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="12"
         bold="1" italic="0" justification="33"/>
  <SLIDER name="paramSlider9" id="2d51feeac15453bd" memberName="m_paramSlider9"
          virtualName="ParameterSlider" explicitFocusOrder="0" pos="152 352 184 16"
          bkgcol="fff2f59b" thumbcol="ffc4c86d" min="0" max="127" int="1"
          style="LinearBar" textBoxPos="TextBoxLeft" textBoxEditable="1"
          textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <LABEL name="paramLabel9" id="c976388ace30186f" memberName="m_paramLabel9"
         virtualName="" explicitFocusOrder="0" pos="8 352 144 16" edTextCol="ff000000"
         edBkgCol="0" labelText="" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="12"
         bold="1" italic="0" justification="33"/>
  <SLIDER name="paramSlider10" id="18f3dba27081936e" memberName="m_paramSlider10"
          virtualName="ParameterSlider" explicitFocusOrder="0" pos="152 376 184 16"
          bkgcol="fff2f59b" thumbcol="ffc4c86d" min="0" max="127" int="1"
          style="LinearBar" textBoxPos="TextBoxLeft" textBoxEditable="1"
          textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <LABEL name="paramLabel10" id="67997801d93968ed" memberName="m_paramLabel10"
         virtualName="" explicitFocusOrder="0" pos="8 376 144 16" edTextCol="ff000000"
         edBkgCol="0" labelText="" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="12"
         bold="1" italic="0" justification="33"/>
  <SLIDER name="paramSlider11" id="cec491c6bcd28d25" memberName="m_paramSlider11"
          virtualName="ParameterSlider" explicitFocusOrder="0" pos="152 400 184 16"
          bkgcol="fff2f59b" thumbcol="ffc4c86d" min="0" max="127" int="1"
          style="LinearBar" textBoxPos="TextBoxLeft" textBoxEditable="1"
          textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <LABEL name="paramLabel11" id="ffd78ecf192afd8" memberName="m_paramLabel11"
         virtualName="" explicitFocusOrder="0" pos="8 400 144 16" edTextCol="ff000000"
         edBkgCol="0" labelText="" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="12"
         bold="1" italic="0" justification="33"/>
  <COMBOBOX name="MFXTypeComboBox" id="310da11a3b4d1c0" memberName="m_MFXTypeComboBox"
            virtualName="ParameterComboBox" explicitFocusOrder="0" pos="152 48 184 16"
            editable="0" layout="33" items="" textWhenNonSelected="" textWhenNoItems="(no choices)"/>
  <LABEL name="MFXTypeLabel" id="46e1e88403b5ba1f" memberName="m_MFXTypeLabel"
         virtualName="" explicitFocusOrder="0" pos="8 48 144 16" edTextCol="ff000000"
         edBkgCol="0" labelText="M-FX TYPE" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="12"
         bold="1" italic="0" justification="33"/>
  <TEXTEDITOR name="MFXTypeDescriptionTextEditor" id="ef9484120a302f50" memberName="m_MFXTypeDescriptionTextEditor"
              virtualName="" explicitFocusOrder="0" pos="8 72 328 80" bkgcol="ffe0e0e0"
              initialText="" multiline="1" retKeyStartsLine="1" readonly="1"
              scrollbars="1" caret="0" popupmenu="1"/>
  <LABEL name="MFXSendLabel" id="1f065e6555b4449e" memberName="m_MFXSendLabel"
         virtualName="" explicitFocusOrder="0" pos="8 24 104 16" edTextCol="ff000000"
         edBkgCol="0" labelText="M-FX SEND" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="12"
         bold="1" italic="0" justification="33"/>
  <SLIDER name="sendToReverbSlider" id="2b89b2c11e2ad524" memberName="m_sendToReverbSlider"
          virtualName="MicroParameterSlider" explicitFocusOrder="0" pos="152 24 56 16"
          bkgcol="fff2f59b" thumbcol="ffc4c86d" min="-48" max="48" int="1"
          style="LinearBar" textBoxPos="TextBoxLeft" textBoxEditable="1"
          textBoxWidth="64" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="sendToDelaySlider" id="d4cba3908f11c75d" memberName="m_sendToDelaySlider"
          virtualName="MicroParameterSlider" explicitFocusOrder="0" pos="280 24 56 16"
          bkgcol="fff2f59b" thumbcol="ffc4c86d" min="-48" max="48" int="1"
          style="LinearBar" textBoxPos="TextBoxLeft" textBoxEditable="1"
          textBoxWidth="64" textBoxHeight="20" skewFactor="1"/>
  <LABEL name="toDelayLabel" id="752b9cc2fdf14cbf" memberName="m_toDelayLabel"
         virtualName="" explicitFocusOrder="0" pos="208 24 72 16" edTextCol="ff000000"
         edBkgCol="0" labelText="TO DELAY" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="12"
         bold="1" italic="0" justification="34"/>
  <LABEL name="toReverbLabel" id="74a296cc00e0e05a" memberName="m_toReverbLabel"
         virtualName="" explicitFocusOrder="0" pos="80 24 72 16" edTextCol="ff000000"
         edBkgCol="0" labelText="TO REVERB" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="12"
         bold="1" italic="0" justification="34"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
