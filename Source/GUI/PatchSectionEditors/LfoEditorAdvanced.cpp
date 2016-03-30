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

#include "LfoEditorAdvanced.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
extern OverallMemoryBlock* grooveboxMemory;
//[/MiscUserDefs]

//==============================================================================
LfoEditorAdvanced::LfoEditorAdvanced (const String &componentName, SynthParts part, Tone tone, bool lfo2)
    : Component (componentName), m_part(part), m_tone(tone), m_lfo2(lfo2)
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    addAndMakeVisible (m_lfoGrp = new PanelGroupGrey ("lfoGrp", getName ()));
    addAndMakeVisible (m_waveformLabel = new Label ("waveformLabel",
                                                    TRANS("WAVEFORM")));
    m_waveformLabel->setFont (Font (12.00f, Font::bold));
    m_waveformLabel->setJustificationType (Justification::centred);
    m_waveformLabel->setEditable (false, false, false);
    m_waveformLabel->setColour (Label::textColourId, Colours::black);
    m_waveformLabel->setColour (TextEditor::textColourId, Colours::black);
    m_waveformLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_waveformComboBox = new ParameterComboBox ("waveformComboBox"));
    m_waveformComboBox->setEditableText (false);
    m_waveformComboBox->setJustificationType (Justification::centred);
    m_waveformComboBox->setTextWhenNothingSelected (TRANS("TRI"));
    m_waveformComboBox->setTextWhenNoChoicesAvailable (TRANS("(no choices)"));
    m_waveformComboBox->addItem (TRANS("TRI"), 1);
    m_waveformComboBox->addItem (TRANS("SIN"), 2);
    m_waveformComboBox->addItem (TRANS("SAW"), 3);
    m_waveformComboBox->addItem (TRANS("SQR"), 4);
    m_waveformComboBox->addItem (TRANS("TRP"), 5);
    m_waveformComboBox->addItem (TRANS("S+H"), 6);
    m_waveformComboBox->addItem (TRANS("RND"), 7);
    m_waveformComboBox->addItem (TRANS("Chaos"), 8);
    m_waveformComboBox->addListener (this);

    addAndMakeVisible (m_tempoSyncToggle = new BlackToggle());
    addAndMakeVisible (m_offsetLabel = new Label ("offsetLabel",
                                                  TRANS("OFFSET")));
    m_offsetLabel->setFont (Font (12.00f, Font::bold));
    m_offsetLabel->setJustificationType (Justification::centred);
    m_offsetLabel->setEditable (false, false, false);
    m_offsetLabel->setColour (Label::textColourId, Colours::black);
    m_offsetLabel->setColour (TextEditor::textColourId, Colours::black);
    m_offsetLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_keySyncToggle = new BlackToggle());
    addAndMakeVisible (m_offsetSlider = new MicroParameterSlider ("offsetSlider"));
    m_offsetSlider->setRange (0, 1, 1);
    m_offsetSlider->setSliderStyle (Slider::LinearBar);
    m_offsetSlider->setTextBoxStyle (Slider::TextBoxLeft, false, 40, 20);
    m_offsetSlider->setColour (Slider::backgroundColourId, Colour (0xfff2f59b));
    m_offsetSlider->setColour (Slider::thumbColourId, Colour (0xffc4c86d));
    m_offsetSlider->addListener (this);

    addAndMakeVisible (m_fadeModeLabel = new Label ("fadeModeLabel",
                                                    TRANS("FADE MODE")));
    m_fadeModeLabel->setFont (Font (12.00f, Font::bold));
    m_fadeModeLabel->setJustificationType (Justification::centred);
    m_fadeModeLabel->setEditable (false, false, false);
    m_fadeModeLabel->setColour (Label::textColourId, Colours::black);
    m_fadeModeLabel->setColour (TextEditor::textColourId, Colours::black);
    m_fadeModeLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_fadeModeComboBox = new ParameterComboBox ("fadeModeComboBox"));
    m_fadeModeComboBox->setEditableText (false);
    m_fadeModeComboBox->setJustificationType (Justification::centred);
    m_fadeModeComboBox->setTextWhenNothingSelected (TRANS("On-In"));
    m_fadeModeComboBox->setTextWhenNoChoicesAvailable (TRANS("(no choices)"));
    m_fadeModeComboBox->addItem (TRANS("On-In"), 1);
    m_fadeModeComboBox->addItem (TRANS("On-Out"), 2);
    m_fadeModeComboBox->addItem (TRANS("Off-In"), 3);
    m_fadeModeComboBox->addItem (TRANS("Off-Out"), 4);
    m_fadeModeComboBox->addListener (this);

    addAndMakeVisible (m_delayTimeLabel = new Label ("delayTimeLabel",
                                                     TRANS("DELAY TIME")));
    m_delayTimeLabel->setFont (Font (12.00f, Font::bold));
    m_delayTimeLabel->setJustificationType (Justification::centred);
    m_delayTimeLabel->setEditable (false, false, false);
    m_delayTimeLabel->setColour (Label::textColourId, Colours::black);
    m_delayTimeLabel->setColour (TextEditor::textColourId, Colours::black);
    m_delayTimeLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_delayTimeSlider = new MicroParameterSlider ("delayTimeSlider"));
    m_delayTimeSlider->setRange (0, 1, 1);
    m_delayTimeSlider->setSliderStyle (Slider::LinearBar);
    m_delayTimeSlider->setTextBoxStyle (Slider::TextBoxLeft, false, 40, 20);
    m_delayTimeSlider->setColour (Slider::backgroundColourId, Colour (0xfff2f59b));
    m_delayTimeSlider->setColour (Slider::thumbColourId, Colour (0xffc4c86d));
    m_delayTimeSlider->addListener (this);

    addAndMakeVisible (m_fadeTimeLabel = new Label ("fadeTimeLabel",
                                                    TRANS("FADE\n"
                                                    "TIME")));
    m_fadeTimeLabel->setFont (Font (12.00f, Font::bold));
    m_fadeTimeLabel->setJustificationType (Justification::centred);
    m_fadeTimeLabel->setEditable (false, false, false);
    m_fadeTimeLabel->setColour (Label::textColourId, Colours::black);
    m_fadeTimeLabel->setColour (TextEditor::textColourId, Colours::black);
    m_fadeTimeLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_tempoLabel = new Label ("tempoLabel",
                                                 TRANS("TEMPO SYNC")));
    m_tempoLabel->setFont (Font (12.00f, Font::bold));
    m_tempoLabel->setJustificationType (Justification::centred);
    m_tempoLabel->setEditable (false, false, false);
    m_tempoLabel->setColour (Label::textColourId, Colours::black);
    m_tempoLabel->setColour (TextEditor::textColourId, Colours::black);
    m_tempoLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_keyLabel = new Label ("keyLabel",
                                               TRANS("KEY SYNC")));
    m_keyLabel->setFont (Font (12.00f, Font::bold));
    m_keyLabel->setJustificationType (Justification::centred);
    m_keyLabel->setEditable (false, false, false);
    m_keyLabel->setColour (Label::textColourId, Colours::black);
    m_keyLabel->setColour (TextEditor::textColourId, Colours::black);
    m_keyLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_rateSlider = new Knob ("rateSlider"));
    m_rateSlider->setRange (0, 127, 1);
    m_rateSlider->setSliderStyle (Slider::RotaryHorizontalVerticalDrag);
    m_rateSlider->setTextBoxStyle (Slider::TextBoxBelow, false, 80, 16);
    m_rateSlider->addListener (this);

    addAndMakeVisible (m_rateLabel = new Label ("rateLabel",
                                                TRANS("RATE")));
    m_rateLabel->setFont (Font (12.00f, Font::bold));
    m_rateLabel->setJustificationType (Justification::centred);
    m_rateLabel->setEditable (false, false, false);
    m_rateLabel->setColour (Label::textColourId, Colours::black);
    m_rateLabel->setColour (TextEditor::textColourId, Colours::black);
    m_rateLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_fadeTimeSlider = new Knob ("fadeTimeSlider"));
    m_fadeTimeSlider->setRange (0, 127, 1);
    m_fadeTimeSlider->setSliderStyle (Slider::RotaryHorizontalVerticalDrag);
    m_fadeTimeSlider->setTextBoxStyle (Slider::TextBoxBelow, false, 80, 16);
    m_fadeTimeSlider->addListener (this);

    addAndMakeVisible (m_line = new Label ("line",
                                           String()));
    m_line->setFont (Font (15.00f, Font::plain));
    m_line->setJustificationType (Justification::centredLeft);
    m_line->setEditable (false, false, false);
    m_line->setColour (Label::outlineColourId, Colours::black);
    m_line->setColour (TextEditor::textColourId, Colours::black);
    m_line->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_pitchSlider = new Knob ("pitchSlider"));
    m_pitchSlider->setRange (0, 127, 1);
    m_pitchSlider->setSliderStyle (Slider::RotaryHorizontalVerticalDrag);
    m_pitchSlider->setTextBoxStyle (Slider::TextBoxBelow, false, 80, 16);
    m_pitchSlider->addListener (this);

    addAndMakeVisible (m_pitchLabel = new Label ("pitchLabel",
                                                 TRANS("TO PITCH")));
    m_pitchLabel->setFont (Font (12.00f, Font::bold));
    m_pitchLabel->setJustificationType (Justification::centred);
    m_pitchLabel->setEditable (false, false, false);
    m_pitchLabel->setColour (Label::textColourId, Colours::black);
    m_pitchLabel->setColour (TextEditor::textColourId, Colours::black);
    m_pitchLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_filterSlider = new Knob ("filterSlider"));
    m_filterSlider->setRange (0, 127, 1);
    m_filterSlider->setSliderStyle (Slider::RotaryHorizontalVerticalDrag);
    m_filterSlider->setTextBoxStyle (Slider::TextBoxBelow, false, 80, 16);
    m_filterSlider->addListener (this);

    addAndMakeVisible (m_filterLabel = new Label ("pitchLabel",
                                                  TRANS("TO FILTER")));
    m_filterLabel->setFont (Font (12.00f, Font::bold));
    m_filterLabel->setJustificationType (Justification::centred);
    m_filterLabel->setEditable (false, false, false);
    m_filterLabel->setColour (Label::textColourId, Colours::black);
    m_filterLabel->setColour (TextEditor::textColourId, Colours::black);
    m_filterLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_ampSlider = new Knob ("ampSlider"));
    m_ampSlider->setRange (0, 127, 1);
    m_ampSlider->setSliderStyle (Slider::RotaryHorizontalVerticalDrag);
    m_ampSlider->setTextBoxStyle (Slider::TextBoxBelow, false, 80, 16);
    m_ampSlider->addListener (this);

    addAndMakeVisible (m_ampLabel = new Label ("ampLabel",
                                               TRANS("TO AMP")));
    m_ampLabel->setFont (Font (12.00f, Font::bold));
    m_ampLabel->setJustificationType (Justification::centred);
    m_ampLabel->setEditable (false, false, false);
    m_ampLabel->setColour (Label::textColourId, Colours::black);
    m_ampLabel->setColour (TextEditor::textColourId, Colours::black);
    m_ampLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_panSlider = new Knob ("panSlider"));
    m_panSlider->setRange (0, 127, 1);
    m_panSlider->setSliderStyle (Slider::RotaryHorizontalVerticalDrag);
    m_panSlider->setTextBoxStyle (Slider::TextBoxBelow, false, 80, 16);
    m_panSlider->addListener (this);

    addAndMakeVisible (m_panLabel = new Label ("panLabel",
                                               TRANS("TO PAN")));
    m_panLabel->setFont (Font (12.00f, Font::bold));
    m_panLabel->setJustificationType (Justification::centred);
    m_panLabel->setEditable (false, false, false);
    m_panLabel->setColour (Label::textColourId, Colours::black);
    m_panLabel->setColour (TextEditor::textColourId, Colours::black);
    m_panLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_imageButton = new ImageButton ("imageButton"));
    m_imageButton->setButtonText (String());
    m_imageButton->addListener (this);

    m_imageButton->setImages (false, true, true,
                              ImageCache::getFromMemory (lfo_png, lfo_pngSize), 1.000f, Colour (0x4340454a),
                              Image(), 1.000f, Colour (0x4340454a),
                              Image(), 1.000f, Colour (0x4340454a));

    //[UserPreSize]
	m_tempoSyncParam = nullptr;
    m_lfoGrp->setText("LFO " + String(lfo2 ? 2 : 1 ) + " OF PART "+ String(part+1) + " TONE "+ String(((tone-4096)/512)+1));
    //[/UserPreSize]

    setSize (304, 168);


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
					m_waveformComboBox->setParameter(tone->getParameter(lfo2 ? 0x35 : 0x2D));
					m_keySyncToggle->setParameter(tone->getParameter(lfo2 ? 0x36 : 0x2E));
					m_rateSlider->setParameter(tone->getParameter(lfo2 ? 0x37 : 0x2F));
					m_offsetSlider->setParameter(tone->getParameter(lfo2 ? 0x38 : 0x30));
					m_delayTimeSlider->setParameter(tone->getParameter(lfo2 ? 0x39 : 0x31));
					m_fadeModeComboBox->setParameter(tone->getParameter(lfo2 ? 0x3A : 0x32));
					m_fadeTimeSlider->setParameter(tone->getParameter(lfo2 ? 0x3B : 0x33));
					m_tempoSyncParam = tone->getParameter(lfo2 ? 0x3C : 0x34);
					m_tempoSyncToggle->setParameter(m_tempoSyncParam);
					m_tempoSyncParam->addChangeListener(this);
					m_pitchSlider->setParameter(tone->getParameter(lfo2 ? 0x4F : 0x4E));
					m_filterSlider->setParameter(tone->getParameter(lfo2 ? 0x64 : 0x63));
					m_ampSlider->setParameter(tone->getParameter(lfo2 ? 0x76 : 0x75));
					m_panSlider->setParameter(tone->getParameter(lfo2 ? 0x7C : 0x7B));
				}
			}
		}
	}
    //[/Constructor]
}

LfoEditorAdvanced::~LfoEditorAdvanced()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
	if (m_tempoSyncParam!=nullptr) m_tempoSyncParam->removeChangeListener(this);
    //[/Destructor_pre]

    m_lfoGrp = nullptr;
    m_waveformLabel = nullptr;
    m_waveformComboBox = nullptr;
    m_tempoSyncToggle = nullptr;
    m_offsetLabel = nullptr;
    m_keySyncToggle = nullptr;
    m_offsetSlider = nullptr;
    m_fadeModeLabel = nullptr;
    m_fadeModeComboBox = nullptr;
    m_delayTimeLabel = nullptr;
    m_delayTimeSlider = nullptr;
    m_fadeTimeLabel = nullptr;
    m_tempoLabel = nullptr;
    m_keyLabel = nullptr;
    m_rateSlider = nullptr;
    m_rateLabel = nullptr;
    m_fadeTimeSlider = nullptr;
    m_line = nullptr;
    m_pitchSlider = nullptr;
    m_pitchLabel = nullptr;
    m_filterSlider = nullptr;
    m_filterLabel = nullptr;
    m_ampSlider = nullptr;
    m_ampLabel = nullptr;
    m_panSlider = nullptr;
    m_panLabel = nullptr;
    m_imageButton = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void LfoEditorAdvanced::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
	#ifdef JUCE_MSVC
	g;
	#endif
    //[/UserPrePaint]

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void LfoEditorAdvanced::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    m_lfoGrp->setBounds (0, 0, getWidth() - 0, getHeight() - 0);
    m_waveformLabel->setBounds (-4, 16, 80, 16);
    m_waveformComboBox->setBounds (2, 32, 72, 16);
    m_tempoSyncToggle->setBounds (24, 72, 25, 17);
    m_offsetLabel->setBounds (132, 56, 56, 16);
    m_keySyncToggle->setBounds (147, 32, 25, 17);
    m_offsetSlider->setBounds (136, 72, 48, 16);
    m_fadeModeLabel->setBounds (188, 16, 76, 16);
    m_fadeModeComboBox->setBounds (192, 32, 68, 16);
    m_delayTimeLabel->setBounds (188, 56, 76, 16);
    m_delayTimeSlider->setBounds (202, 72, 48, 16);
    m_fadeTimeLabel->setBounds (264, 15, 40, 30);
    m_tempoLabel->setBounds (-2, 56, 78, 16);
    m_keyLabel->setBounds (128, 16, 60, 16);
    m_rateSlider->setBounds (76, 28, 48, 60);
    m_rateLabel->setBounds (76, 16, 48, 16);
    m_fadeTimeSlider->setBounds (268, 40, 32, 48);
    m_line->setBounds (4, 96, 296, 1);
    m_pitchSlider->setBounds (36, 116, 32, 48);
    m_pitchLabel->setBounds (8, 100, 88, 16);
    m_filterSlider->setBounds (104, 116, 32, 48);
    m_filterLabel->setBounds (76, 100, 88, 16);
    m_ampSlider->setBounds (172, 116, 32, 48);
    m_ampLabel->setBounds (144, 100, 88, 16);
    m_panSlider->setBounds (240, 116, 32, 48);
    m_panLabel->setBounds (212, 100, 88, 16);
    m_imageButton->setBounds (3, 1, 16, 16);
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void LfoEditorAdvanced::comboBoxChanged (ComboBox* comboBoxThatHasChanged)
{
    //[UsercomboBoxChanged_Pre]
    //[/UsercomboBoxChanged_Pre]

    if (comboBoxThatHasChanged == m_waveformComboBox)
    {
        //[UserComboBoxCode_m_waveformComboBox] -- add your combo box handling code here..
        //[/UserComboBoxCode_m_waveformComboBox]
    }
    else if (comboBoxThatHasChanged == m_fadeModeComboBox)
    {
        //[UserComboBoxCode_m_fadeModeComboBox] -- add your combo box handling code here..
        //[/UserComboBoxCode_m_fadeModeComboBox]
    }

    //[UsercomboBoxChanged_Post]
    //[/UsercomboBoxChanged_Post]
}

void LfoEditorAdvanced::sliderValueChanged (Slider* sliderThatWasMoved)
{
    //[UsersliderValueChanged_Pre]
    //[/UsersliderValueChanged_Pre]

    if (sliderThatWasMoved == m_offsetSlider)
    {
        //[UserSliderCode_m_offsetSlider] -- add your slider handling code here..
        //[/UserSliderCode_m_offsetSlider]
    }
    else if (sliderThatWasMoved == m_delayTimeSlider)
    {
        //[UserSliderCode_m_delayTimeSlider] -- add your slider handling code here..
        //[/UserSliderCode_m_delayTimeSlider]
    }
    else if (sliderThatWasMoved == m_rateSlider)
    {
        //[UserSliderCode_m_rateSlider] -- add your slider handling code here..
        //[/UserSliderCode_m_rateSlider]
    }
    else if (sliderThatWasMoved == m_fadeTimeSlider)
    {
        //[UserSliderCode_m_fadeTimeSlider] -- add your slider handling code here..
        //[/UserSliderCode_m_fadeTimeSlider]
    }
    else if (sliderThatWasMoved == m_pitchSlider)
    {
        //[UserSliderCode_m_pitchSlider] -- add your slider handling code here..
        //[/UserSliderCode_m_pitchSlider]
    }
    else if (sliderThatWasMoved == m_filterSlider)
    {
        //[UserSliderCode_m_filterSlider] -- add your slider handling code here..
        //[/UserSliderCode_m_filterSlider]
    }
    else if (sliderThatWasMoved == m_ampSlider)
    {
        //[UserSliderCode_m_ampSlider] -- add your slider handling code here..
        //[/UserSliderCode_m_ampSlider]
    }
    else if (sliderThatWasMoved == m_panSlider)
    {
        //[UserSliderCode_m_panSlider] -- add your slider handling code here..
        //[/UserSliderCode_m_panSlider]
    }

    //[UsersliderValueChanged_Post]
    //[/UsersliderValueChanged_Post]
}

void LfoEditorAdvanced::buttonClicked (Button* buttonThatWasClicked)
{
    //[UserbuttonClicked_Pre]
    //[/UserbuttonClicked_Pre]

    if (buttonThatWasClicked == m_imageButton)
    {
        //[UserButtonCode_m_imageButton] -- add your button handler code here..
        //[/UserButtonCode_m_imageButton]
    }

    //[UserbuttonClicked_Post]
    //[/UserbuttonClicked_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
void LfoEditorAdvanced::changeListenerCallback(ChangeBroadcaster *source)
{
	if (source == m_tempoSyncParam)
	{
		if (m_tempoSyncParam->getValue() > 0)
		{
			m_rateSlider->setParameter(m_rateSlider->getParamPtr());
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

<JUCER_COMPONENT documentType="Component" className="LfoEditorAdvanced" componentName=""
                 parentClasses="public Component, public ChangeListener" constructorParams="const String &amp;componentName, SynthParts part, Tone tone, bool lfo2"
                 variableInitialisers="Component (componentName), m_part(part), m_tone(tone), m_lfo2(lfo2)"
                 snapPixels="4" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="1" initialWidth="304" initialHeight="168">
  <BACKGROUND backgroundColour="0"/>
  <JUCERCOMP name="lfoGrp" id="52e00682f746b888" memberName="m_lfoGrp" virtualName="PanelGroupGrey"
             explicitFocusOrder="0" pos="0 0 0M 0M" sourceFile="../GroupWidgets/PanelGroupGrey.cpp"
             constructorParams="&quot;lfoGrp&quot;, getName () "/>
  <LABEL name="waveformLabel" id="c41c307042cbea72" memberName="m_waveformLabel"
         virtualName="" explicitFocusOrder="0" pos="-4 16 80 16" textCol="ff000000"
         edTextCol="ff000000" edBkgCol="0" labelText="WAVEFORM" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="12" bold="1" italic="0" justification="36"/>
  <COMBOBOX name="waveformComboBox" id="e8c10ecedfc6fd9e" memberName="m_waveformComboBox"
            virtualName="ParameterComboBox" explicitFocusOrder="0" pos="2 32 72 16"
            editable="0" layout="36" items="TRI&#10;SIN&#10;SAW&#10;SQR&#10;TRP&#10;S+H&#10;RND&#10;Chaos"
            textWhenNonSelected="TRI" textWhenNoItems="(no choices)"/>
  <JUCERCOMP name="tempoSyncToggle" id="1d7902cb6f52a8a2" memberName="m_tempoSyncToggle"
             virtualName="" explicitFocusOrder="0" pos="24 72 25 17" sourceFile="../ParameterWidgets/BlackToggle.cpp"
             constructorParams=""/>
  <LABEL name="offsetLabel" id="67da4218ada4e523" memberName="m_offsetLabel"
         virtualName="" explicitFocusOrder="0" pos="132 56 56 16" textCol="ff000000"
         edTextCol="ff000000" edBkgCol="0" labelText="OFFSET" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="12" bold="1" italic="0" justification="36"/>
  <JUCERCOMP name="keySyncToggle" id="1dee3cc7cfd57bb1" memberName="m_keySyncToggle"
             virtualName="" explicitFocusOrder="0" pos="147 32 25 17" sourceFile="../ParameterWidgets/BlackToggle.cpp"
             constructorParams=""/>
  <SLIDER name="offsetSlider" id="84957c0c6350e85e" memberName="m_offsetSlider"
          virtualName="MicroParameterSlider" explicitFocusOrder="0" pos="136 72 48 16"
          bkgcol="fff2f59b" thumbcol="ffc4c86d" min="0" max="1" int="1"
          style="LinearBar" textBoxPos="TextBoxLeft" textBoxEditable="1"
          textBoxWidth="40" textBoxHeight="20" skewFactor="1"/>
  <LABEL name="fadeModeLabel" id="f0c007fb3e925f50" memberName="m_fadeModeLabel"
         virtualName="" explicitFocusOrder="0" pos="188 16 76 16" textCol="ff000000"
         edTextCol="ff000000" edBkgCol="0" labelText="FADE MODE" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="12" bold="1" italic="0" justification="36"/>
  <COMBOBOX name="fadeModeComboBox" id="f8a25284f5ba2f4" memberName="m_fadeModeComboBox"
            virtualName="ParameterComboBox" explicitFocusOrder="0" pos="192 32 68 16"
            editable="0" layout="36" items="On-In&#10;On-Out&#10;Off-In&#10;Off-Out"
            textWhenNonSelected="On-In" textWhenNoItems="(no choices)"/>
  <LABEL name="delayTimeLabel" id="45e24fd99b0781ae" memberName="m_delayTimeLabel"
         virtualName="" explicitFocusOrder="0" pos="188 56 76 16" textCol="ff000000"
         edTextCol="ff000000" edBkgCol="0" labelText="DELAY TIME" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="12" bold="1" italic="0" justification="36"/>
  <SLIDER name="delayTimeSlider" id="1987a0054c48ed0" memberName="m_delayTimeSlider"
          virtualName="MicroParameterSlider" explicitFocusOrder="0" pos="202 72 48 16"
          bkgcol="fff2f59b" thumbcol="ffc4c86d" min="0" max="1" int="1"
          style="LinearBar" textBoxPos="TextBoxLeft" textBoxEditable="1"
          textBoxWidth="40" textBoxHeight="20" skewFactor="1"/>
  <LABEL name="fadeTimeLabel" id="f4fd2b773ca5f2b7" memberName="m_fadeTimeLabel"
         virtualName="" explicitFocusOrder="0" pos="264 15 40 30" textCol="ff000000"
         edTextCol="ff000000" edBkgCol="0" labelText="FADE&#10;TIME" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="12" bold="1" italic="0" justification="36"/>
  <LABEL name="tempoLabel" id="bc5132eee7a0ee16" memberName="m_tempoLabel"
         virtualName="" explicitFocusOrder="0" pos="-2 56 78 16" textCol="ff000000"
         edTextCol="ff000000" edBkgCol="0" labelText="TEMPO SYNC" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="12" bold="1" italic="0" justification="36"/>
  <LABEL name="keyLabel" id="1e3525d1a10dd56c" memberName="m_keyLabel"
         virtualName="" explicitFocusOrder="0" pos="128 16 60 16" textCol="ff000000"
         edTextCol="ff000000" edBkgCol="0" labelText="KEY SYNC" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="12" bold="1" italic="0" justification="36"/>
  <SLIDER name="rateSlider" id="8f8e60a31b2b5c80" memberName="m_rateSlider"
          virtualName="Knob" explicitFocusOrder="0" pos="76 28 48 60" min="0"
          max="127" int="1" style="RotaryHorizontalVerticalDrag" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="16" skewFactor="1"/>
  <LABEL name="rateLabel" id="42faca05c6457ae1" memberName="m_rateLabel"
         virtualName="" explicitFocusOrder="0" pos="76 16 48 16" textCol="ff000000"
         edTextCol="ff000000" edBkgCol="0" labelText="RATE" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="12" bold="1" italic="0" justification="36"/>
  <SLIDER name="fadeTimeSlider" id="85fde4b06133df0e" memberName="m_fadeTimeSlider"
          virtualName="Knob" explicitFocusOrder="0" pos="268 40 32 48"
          min="0" max="127" int="1" style="RotaryHorizontalVerticalDrag"
          textBoxPos="TextBoxBelow" textBoxEditable="1" textBoxWidth="80"
          textBoxHeight="16" skewFactor="1"/>
  <LABEL name="line" id="fd11227ac2737e03" memberName="m_line" virtualName=""
         explicitFocusOrder="0" pos="4 96 296 1" outlineCol="ff000000"
         edTextCol="ff000000" edBkgCol="0" labelText="" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" bold="0" italic="0" justification="33"/>
  <SLIDER name="pitchSlider" id="533842793459863a" memberName="m_pitchSlider"
          virtualName="Knob" explicitFocusOrder="0" pos="36 116 32 48"
          min="0" max="127" int="1" style="RotaryHorizontalVerticalDrag"
          textBoxPos="TextBoxBelow" textBoxEditable="1" textBoxWidth="80"
          textBoxHeight="16" skewFactor="1"/>
  <LABEL name="pitchLabel" id="b464bd3cbdae27fd" memberName="m_pitchLabel"
         virtualName="" explicitFocusOrder="0" pos="8 100 88 16" textCol="ff000000"
         edTextCol="ff000000" edBkgCol="0" labelText="TO PITCH" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="12" bold="1" italic="0" justification="36"/>
  <SLIDER name="filterSlider" id="acc477aca5e0813b" memberName="m_filterSlider"
          virtualName="Knob" explicitFocusOrder="0" pos="104 116 32 48"
          min="0" max="127" int="1" style="RotaryHorizontalVerticalDrag"
          textBoxPos="TextBoxBelow" textBoxEditable="1" textBoxWidth="80"
          textBoxHeight="16" skewFactor="1"/>
  <LABEL name="pitchLabel" id="3bedb05c3f174873" memberName="m_filterLabel"
         virtualName="" explicitFocusOrder="0" pos="76 100 88 16" textCol="ff000000"
         edTextCol="ff000000" edBkgCol="0" labelText="TO FILTER" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="12" bold="1" italic="0" justification="36"/>
  <SLIDER name="ampSlider" id="6534d8ea7631d779" memberName="m_ampSlider"
          virtualName="Knob" explicitFocusOrder="0" pos="172 116 32 48"
          min="0" max="127" int="1" style="RotaryHorizontalVerticalDrag"
          textBoxPos="TextBoxBelow" textBoxEditable="1" textBoxWidth="80"
          textBoxHeight="16" skewFactor="1"/>
  <LABEL name="ampLabel" id="2ac2d98efcdb127a" memberName="m_ampLabel"
         virtualName="" explicitFocusOrder="0" pos="144 100 88 16" textCol="ff000000"
         edTextCol="ff000000" edBkgCol="0" labelText="TO AMP" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="12" bold="1" italic="0" justification="36"/>
  <SLIDER name="panSlider" id="bdb529d5ee52d4d7" memberName="m_panSlider"
          virtualName="Knob" explicitFocusOrder="0" pos="240 116 32 48"
          min="0" max="127" int="1" style="RotaryHorizontalVerticalDrag"
          textBoxPos="TextBoxBelow" textBoxEditable="1" textBoxWidth="80"
          textBoxHeight="16" skewFactor="1"/>
  <LABEL name="panLabel" id="a8f7c8f8a2fb10a0" memberName="m_panLabel"
         virtualName="" explicitFocusOrder="0" pos="212 100 88 16" textCol="ff000000"
         edTextCol="ff000000" edBkgCol="0" labelText="TO PAN" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="12" bold="1" italic="0" justification="36"/>
  <IMAGEBUTTON name="imageButton" id="570f3b3b741de5e4" memberName="m_imageButton"
               virtualName="" explicitFocusOrder="0" pos="3 1 16 16" buttonText=""
               connectedEdges="0" needsCallback="1" radioGroupId="0" keepProportions="1"
               resourceNormal="lfo_png" opacityNormal="1" colourNormal="4340454a"
               resourceOver="" opacityOver="1" colourOver="4340454a" resourceDown=""
               opacityDown="1" colourDown="4340454a"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif

//==============================================================================
// Binary resources - be careful not to edit any of these sections!

// JUCER_RESOURCE: lfo_png, 235, "../../../Resources/PatchEditSectionIcons/lfo.png"
static const unsigned char resource_LfoEditorAdvanced_lfo_png[] = { 137,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,0,16,0,0,0,16,8,6,0,0,0,31,243,255,97,0,0,0,1,115,82,71,66,0,174,206,28,233,0,0,0,
6,98,75,71,68,0,255,0,255,0,255,160,189,167,147,0,0,0,9,112,72,89,115,0,0,11,19,0,0,11,19,1,0,154,156,24,0,0,0,7,116,73,77,69,7,222,12,10,20,17,26,251,57,11,92,0,0,0,107,73,68,65,84,56,203,165,83,91,14,
192,32,8,163,141,247,191,50,251,153,9,16,22,6,240,37,216,242,168,8,121,77,85,85,26,6,0,50,37,59,206,132,108,147,176,3,78,139,253,233,192,98,226,153,178,181,170,131,236,254,198,92,7,83,49,89,85,119,239,
157,236,192,153,140,106,19,208,6,163,194,23,24,201,214,103,119,125,163,86,231,11,144,205,158,9,205,172,74,36,87,254,234,51,97,251,157,31,197,207,111,229,235,115,88,252,0,0,0,0,73,69,78,68,174,66,96,130,
0,0};

const char* LfoEditorAdvanced::lfo_png = (const char*) resource_LfoEditorAdvanced_lfo_png;
const int LfoEditorAdvanced::lfo_pngSize = 235;


//[EndFile] You can add extra defines here...
//[/EndFile]
