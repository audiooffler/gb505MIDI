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
#include "LfoEditorAdvanced.h"
//[/Headers]

#include "LfoEditor.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
extern OverallMemoryBlock* grooveboxMemory;
//[/MiscUserDefs]

//==============================================================================
LfoEditor::LfoEditor (const String &componentName, SynthParts part, Tone tone, bool lfo2)
    : Component (componentName), m_part(part), m_tone(tone), m_lfo2(lfo2)
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    addAndMakeVisible (m_lfoGrp = new PanelGroupGrey ("lfoGrp", getName ()));
    addAndMakeVisible (m_waveformLabel = new Label ("waveformLabel",
                                                    TRANS("WAVE")));
    m_waveformLabel->setFont (Font (12.00f, Font::bold));
    m_waveformLabel->setJustificationType (Justification::centred);
    m_waveformLabel->setEditable (false, false, false);
    m_waveformLabel->setColour (Label::textColourId, Colours::black);
    m_waveformLabel->setColour (TextEditor::textColourId, Colours::black);
    m_waveformLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_waveformComboBox = new ParameterComboBox ("waveformComboBox"));
    m_waveformComboBox->setEditableText (false);
    m_waveformComboBox->setJustificationType (Justification::centred);
    m_waveformComboBox->setTextWhenNothingSelected (String());
    m_waveformComboBox->setTextWhenNoChoicesAvailable (TRANS("(no choices)"));
    m_waveformComboBox->addItem (TRANS("TRI"), 1);
    m_waveformComboBox->addItem (TRANS("SIN"), 2);
    m_waveformComboBox->addItem (TRANS("SAW"), 3);
    m_waveformComboBox->addItem (TRANS("SQR"), 4);
    m_waveformComboBox->addItem (TRANS("TRP"), 5);
    m_waveformComboBox->addItem (TRANS("S&H"), 6);
    m_waveformComboBox->addItem (TRANS("RND"), 7);
    m_waveformComboBox->addItem (TRANS("CHAOS"), 8);
    m_waveformComboBox->addListener (this);

    addAndMakeVisible (m_portamentoModeLabel3 = new Label ("portamentoModeLabel",
                                                           TRANS("RATE")));
    m_portamentoModeLabel3->setFont (Font (12.00f, Font::bold));
    m_portamentoModeLabel3->setJustificationType (Justification::centred);
    m_portamentoModeLabel3->setEditable (false, false, false);
    m_portamentoModeLabel3->setColour (Label::textColourId, Colours::black);
    m_portamentoModeLabel3->setColour (TextEditor::textColourId, Colours::black);
    m_portamentoModeLabel3->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_rateSlider = new MicroParameterSlider ("rateSlider"));
    m_rateSlider->setRange (0, 1, 1);
    m_rateSlider->setSliderStyle (Slider::LinearBar);
    m_rateSlider->setTextBoxStyle (Slider::TextBoxLeft, false, 40, 20);
    m_rateSlider->setColour (Slider::backgroundColourId, Colour (0xfff2f59b));
    m_rateSlider->setColour (Slider::thumbColourId, Colour (0xffc4c86d));
    m_rateSlider->addListener (this);

    addAndMakeVisible (m_pitchSlider = new MicroParameterSlider ("pitchSlider"));
    m_pitchSlider->setRange (0, 1, 1);
    m_pitchSlider->setSliderStyle (Slider::LinearBar);
    m_pitchSlider->setTextBoxStyle (Slider::TextBoxLeft, false, 40, 20);
    m_pitchSlider->setColour (Slider::backgroundColourId, Colour (0xfff2f59b));
    m_pitchSlider->setColour (Slider::thumbColourId, Colour (0xffc4c86d));
    m_pitchSlider->addListener (this);

    addAndMakeVisible (m_ampSlider = new MicroParameterSlider ("ampSlider"));
    m_ampSlider->setRange (0, 1, 1);
    m_ampSlider->setSliderStyle (Slider::LinearBar);
    m_ampSlider->setTextBoxStyle (Slider::TextBoxLeft, false, 40, 20);
    m_ampSlider->setColour (Slider::backgroundColourId, Colour (0xfff2f59b));
    m_ampSlider->setColour (Slider::thumbColourId, Colour (0xffc4c86d));
    m_ampSlider->addListener (this);

    addAndMakeVisible (m_filterSlider = new MicroParameterSlider ("filterSlider"));
    m_filterSlider->setRange (0, 1, 1);
    m_filterSlider->setSliderStyle (Slider::LinearBar);
    m_filterSlider->setTextBoxStyle (Slider::TextBoxLeft, false, 40, 20);
    m_filterSlider->setColour (Slider::backgroundColourId, Colour (0xfff2f59b));
    m_filterSlider->setColour (Slider::thumbColourId, Colour (0xffc4c86d));
    m_filterSlider->addListener (this);

    addAndMakeVisible (m_panSlider = new MicroParameterSlider ("panSlider"));
    m_panSlider->setRange (0, 1, 1);
    m_panSlider->setSliderStyle (Slider::LinearBar);
    m_panSlider->setTextBoxStyle (Slider::TextBoxLeft, false, 40, 20);
    m_panSlider->setColour (Slider::backgroundColourId, Colour (0xfff2f59b));
    m_panSlider->setColour (Slider::thumbColourId, Colour (0xffc4c86d));
    m_panSlider->addListener (this);

    addAndMakeVisible (m_pitchLabel = new Label ("pitchLabel",
                                                 TRANS("PITCH")));
    m_pitchLabel->setFont (Font (12.00f, Font::bold));
    m_pitchLabel->setJustificationType (Justification::centredLeft);
    m_pitchLabel->setEditable (false, false, false);
    m_pitchLabel->setColour (Label::textColourId, Colours::black);
    m_pitchLabel->setColour (TextEditor::textColourId, Colours::black);
    m_pitchLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_filterLabel = new Label ("filterLabel",
                                                  TRANS("FILTER")));
    m_filterLabel->setFont (Font (12.00f, Font::bold));
    m_filterLabel->setJustificationType (Justification::centredLeft);
    m_filterLabel->setEditable (false, false, false);
    m_filterLabel->setColour (Label::textColourId, Colours::black);
    m_filterLabel->setColour (TextEditor::textColourId, Colours::black);
    m_filterLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_ampLabel = new Label ("ampLabel",
                                               TRANS("AMP")));
    m_ampLabel->setFont (Font (12.00f, Font::bold));
    m_ampLabel->setJustificationType (Justification::centredLeft);
    m_ampLabel->setEditable (false, false, false);
    m_ampLabel->setColour (Label::textColourId, Colours::black);
    m_ampLabel->setColour (TextEditor::textColourId, Colours::black);
    m_ampLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_panLabel = new Label ("panLabel",
                                               TRANS("PAN")));
    m_panLabel->setFont (Font (12.00f, Font::bold));
    m_panLabel->setJustificationType (Justification::centredLeft);
    m_panLabel->setEditable (false, false, false);
    m_panLabel->setColour (Label::textColourId, Colours::black);
    m_panLabel->setColour (TextEditor::textColourId, Colours::black);
    m_panLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_advancedButton = new TextWithArrowButton ("new button"));
    m_advancedButton->setButtonText (TRANS("LFO"));
    m_advancedButton->addListener (this);

    addAndMakeVisible (m_imageButton = new ImageButton ("new button"));
    m_imageButton->setButtonText (String());
    m_imageButton->addListener (this);

    m_imageButton->setImages (false, true, true,
                              ImageCache::getFromMemory (lfo_png, lfo_pngSize), 1.000f, Colour (0x4340454a),
                              Image(), 1.000f, Colour (0x4a434045),
                              Image(), 1.000f, Colour (0x4a434045));

    //[UserPreSize]
	m_advancedButton->setButtonText(TRANS("LFO")+String(lfo2?" 2":" 1"));
	m_tempoSync = nullptr;
    //[/UserPreSize]

    setSize (147, 100);


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
					m_waveformComboBox->setName("waveFormComboPart" + String(m_part) + "Tone" + String(m_tone) + String(lfo2 ? "2" : "1"));
					m_waveformComboBox->setParameter(tone->getParameter(lfo2 ? 0x35 : 0x2D));
					m_rateSlider->setParameter(tone->getParameter(lfo2 ? 0x37 : 0x2F));
					m_pitchSlider->setParameter(tone->getParameter(lfo2 ? 0x4F : 0x4E));
					m_filterSlider->setParameter(tone->getParameter(lfo2 ? 0x64 : 0x63));
					m_ampSlider->setParameter(tone->getParameter(lfo2 ? 0x76 : 0x75));
					m_panSlider->setParameter(tone->getParameter(lfo2 ? 0x7C : 0x7B));
					m_tempoSync = tone->getParameter(lfo2 ? 0x3C : 0x34);
					m_tempoSync->addChangeListener(this);
				}
			}
		}
	}
    //[/Constructor]
}

LfoEditor::~LfoEditor()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    m_lfoGrp = nullptr;
    m_waveformLabel = nullptr;
    m_waveformComboBox = nullptr;
    m_portamentoModeLabel3 = nullptr;
    m_rateSlider = nullptr;
    m_pitchSlider = nullptr;
    m_ampSlider = nullptr;
    m_filterSlider = nullptr;
    m_panSlider = nullptr;
    m_pitchLabel = nullptr;
    m_filterLabel = nullptr;
    m_ampLabel = nullptr;
    m_panLabel = nullptr;
    m_advancedButton = nullptr;
    m_imageButton = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void LfoEditor::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
	#ifdef JUCE_MSVC
	g;
	#endif
    //[/UserPrePaint]

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void LfoEditor::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    m_lfoGrp->setBounds (0, 0, getWidth() - 0, getHeight() - 0);
    m_waveformLabel->setBounds (88, 16, 56, 16);
    m_waveformComboBox->setBounds (88, 29, 56, 16);
    m_portamentoModeLabel3->setBounds (88, 43, 56, 16);
    m_rateSlider->setBounds (88, 56, 56, 16);
    m_pitchSlider->setBounds (44, 18, 40, 16);
    m_ampSlider->setBounds (44, 58, 40, 16);
    m_filterSlider->setBounds (44, 38, 40, 16);
    m_panSlider->setBounds (44, 78, 40, 16);
    m_pitchLabel->setBounds (0, 18, 48, 16);
    m_filterLabel->setBounds (0, 38, 48, 16);
    m_ampLabel->setBounds (0, 58, 48, 16);
    m_panLabel->setBounds (0, 78, 48, 16);
    m_advancedButton->setBounds (88, 76, 58, 20);
    m_imageButton->setBounds (3, 1, 16, 16);
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void LfoEditor::comboBoxChanged (ComboBox* comboBoxThatHasChanged)
{
    //[UsercomboBoxChanged_Pre]
    //[/UsercomboBoxChanged_Pre]

    if (comboBoxThatHasChanged == m_waveformComboBox)
    {
        //[UserComboBoxCode_m_waveformComboBox] -- add your combo box handling code here..
        //[/UserComboBoxCode_m_waveformComboBox]
    }

    //[UsercomboBoxChanged_Post]
    //[/UsercomboBoxChanged_Post]
}

void LfoEditor::sliderValueChanged (Slider* sliderThatWasMoved)
{
    //[UsersliderValueChanged_Pre]
    //[/UsersliderValueChanged_Pre]

    if (sliderThatWasMoved == m_rateSlider)
    {
        //[UserSliderCode_m_rateSlider] -- add your slider handling code here..
        //[/UserSliderCode_m_rateSlider]
    }
    else if (sliderThatWasMoved == m_pitchSlider)
    {
        //[UserSliderCode_m_pitchSlider] -- add your slider handling code here..
        //[/UserSliderCode_m_pitchSlider]
    }
    else if (sliderThatWasMoved == m_ampSlider)
    {
        //[UserSliderCode_m_ampSlider] -- add your slider handling code here..
        //[/UserSliderCode_m_ampSlider]
    }
    else if (sliderThatWasMoved == m_filterSlider)
    {
        //[UserSliderCode_m_filterSlider] -- add your slider handling code here..
        //[/UserSliderCode_m_filterSlider]
    }
    else if (sliderThatWasMoved == m_panSlider)
    {
        //[UserSliderCode_m_panSlider] -- add your slider handling code here..
        //[/UserSliderCode_m_panSlider]
    }

    //[UsersliderValueChanged_Post]
    //[/UsersliderValueChanged_Post]
}

void LfoEditor::buttonClicked (Button* buttonThatWasClicked)
{
    //[UserbuttonClicked_Pre]
    //[/UserbuttonClicked_Pre]

    if (buttonThatWasClicked == m_advancedButton)
    {
        //[UserButtonCode_m_advancedButton] -- add your button handler code here..
		LfoEditorAdvanced* advancedLfoEditor = new LfoEditorAdvanced("LFO", m_part, m_tone, m_lfo2);
		CallOutBox::launchAsynchronously(advancedLfoEditor, m_advancedButton->getScreenBounds(), nullptr);
        //[/UserButtonCode_m_advancedButton]
    }
    else if (buttonThatWasClicked == m_imageButton)
    {
        //[UserButtonCode_m_imageButton] -- add your button handler code here..
        //[/UserButtonCode_m_imageButton]
    }

    //[UserbuttonClicked_Post]
    //[/UserbuttonClicked_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
void LfoEditor::changeListenerCallback(ChangeBroadcaster *source)
{
	if (source == m_tempoSync)
	{
		if (m_tempoSync->getValue() > 0)
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

<JUCER_COMPONENT documentType="Component" className="LfoEditor" componentName=""
                 parentClasses="public Component, public ChangeListener" constructorParams="const String &amp;componentName, SynthParts part, Tone tone, bool lfo2"
                 variableInitialisers="Component (componentName), m_part(part), m_tone(tone), m_lfo2(lfo2)"
                 snapPixels="4" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="1" initialWidth="147" initialHeight="100">
  <BACKGROUND backgroundColour="0"/>
  <JUCERCOMP name="lfoGrp" id="52e00682f746b888" memberName="m_lfoGrp" virtualName="PanelGroupGrey"
             explicitFocusOrder="0" pos="0 0 0M 0M" sourceFile="../GroupWidgets/PanelGroupTransp.cpp"
             constructorParams="&quot;lfoGrp&quot;, getName () "/>
  <LABEL name="waveformLabel" id="c41c307042cbea72" memberName="m_waveformLabel"
         virtualName="" explicitFocusOrder="0" pos="88 16 56 16" textCol="ff000000"
         edTextCol="ff000000" edBkgCol="0" labelText="WAVE" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="12" bold="1" italic="0" justification="36"/>
  <COMBOBOX name="waveformComboBox" id="e8c10ecedfc6fd9e" memberName="m_waveformComboBox"
            virtualName="ParameterComboBox" explicitFocusOrder="0" pos="88 29 56 16"
            editable="0" layout="36" items="TRI&#10;SIN&#10;SAW&#10;SQR&#10;TRP&#10;S&amp;H&#10;RND&#10;CHAOS"
            textWhenNonSelected="" textWhenNoItems="(no choices)"/>
  <LABEL name="portamentoModeLabel" id="2e9ce2d604148ca5" memberName="m_portamentoModeLabel3"
         virtualName="" explicitFocusOrder="0" pos="88 43 56 16" textCol="ff000000"
         edTextCol="ff000000" edBkgCol="0" labelText="RATE" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="12" bold="1" italic="0" justification="36"/>
  <SLIDER name="rateSlider" id="9856403d87a49ef3" memberName="m_rateSlider"
          virtualName="MicroParameterSlider" explicitFocusOrder="0" pos="88 56 56 16"
          bkgcol="fff2f59b" thumbcol="ffc4c86d" min="0" max="1" int="1"
          style="LinearBar" textBoxPos="TextBoxLeft" textBoxEditable="1"
          textBoxWidth="40" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="pitchSlider" id="bad7d39c44f1fb4d" memberName="m_pitchSlider"
          virtualName="MicroParameterSlider" explicitFocusOrder="0" pos="44 18 40 16"
          bkgcol="fff2f59b" thumbcol="ffc4c86d" min="0" max="1" int="1"
          style="LinearBar" textBoxPos="TextBoxLeft" textBoxEditable="1"
          textBoxWidth="40" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="ampSlider" id="35fa22b98edb0bd3" memberName="m_ampSlider"
          virtualName="MicroParameterSlider" explicitFocusOrder="0" pos="44 58 40 16"
          bkgcol="fff2f59b" thumbcol="ffc4c86d" min="0" max="1" int="1"
          style="LinearBar" textBoxPos="TextBoxLeft" textBoxEditable="1"
          textBoxWidth="40" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="filterSlider" id="95b23df8e07456fa" memberName="m_filterSlider"
          virtualName="MicroParameterSlider" explicitFocusOrder="0" pos="44 38 40 16"
          bkgcol="fff2f59b" thumbcol="ffc4c86d" min="0" max="1" int="1"
          style="LinearBar" textBoxPos="TextBoxLeft" textBoxEditable="1"
          textBoxWidth="40" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="panSlider" id="6de67d13665a6da0" memberName="m_panSlider"
          virtualName="MicroParameterSlider" explicitFocusOrder="0" pos="44 78 40 16"
          bkgcol="fff2f59b" thumbcol="ffc4c86d" min="0" max="1" int="1"
          style="LinearBar" textBoxPos="TextBoxLeft" textBoxEditable="1"
          textBoxWidth="40" textBoxHeight="20" skewFactor="1"/>
  <LABEL name="pitchLabel" id="d477ccb306ab61bc" memberName="m_pitchLabel"
         virtualName="" explicitFocusOrder="0" pos="0 18 48 16" textCol="ff000000"
         edTextCol="ff000000" edBkgCol="0" labelText="PITCH" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="12" bold="1" italic="0" justification="33"/>
  <LABEL name="filterLabel" id="5611b19fd2929b30" memberName="m_filterLabel"
         virtualName="" explicitFocusOrder="0" pos="0 38 48 16" textCol="ff000000"
         edTextCol="ff000000" edBkgCol="0" labelText="FILTER" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="12" bold="1" italic="0" justification="33"/>
  <LABEL name="ampLabel" id="79aeac1eadc88872" memberName="m_ampLabel"
         virtualName="" explicitFocusOrder="0" pos="0 58 48 16" textCol="ff000000"
         edTextCol="ff000000" edBkgCol="0" labelText="AMP" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="12" bold="1" italic="0" justification="33"/>
  <LABEL name="panLabel" id="be43113962c2383f" memberName="m_panLabel"
         virtualName="" explicitFocusOrder="0" pos="0 78 48 16" textCol="ff000000"
         edTextCol="ff000000" edBkgCol="0" labelText="PAN" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="12" bold="1" italic="0" justification="33"/>
  <TEXTBUTTON name="new button" id="9de90d61ee7dcce4" memberName="m_advancedButton"
              virtualName="TextWithArrowButton" explicitFocusOrder="0" pos="88 76 58 20"
              buttonText="LFO" connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <IMAGEBUTTON name="new button" id="570f3b3b741de5e4" memberName="m_imageButton"
               virtualName="" explicitFocusOrder="0" pos="3 1 16 16" buttonText=""
               connectedEdges="0" needsCallback="1" radioGroupId="0" keepProportions="1"
               resourceNormal="lfo_png" opacityNormal="1" colourNormal="4340454a"
               resourceOver="" opacityOver="1" colourOver="4a434045" resourceDown=""
               opacityDown="1" colourDown="4a434045"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif

//==============================================================================
// Binary resources - be careful not to edit any of these sections!

// JUCER_RESOURCE: lfo_png, 235, "../../../Resources/PatchEditSectionIcons/lfo.png"
static const unsigned char resource_LfoEditor_lfo_png[] = { 137,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,0,16,0,0,0,16,8,6,0,0,0,31,243,255,97,0,0,0,1,115,82,71,66,0,174,206,28,233,0,0,0,6,98,75,
71,68,0,255,0,255,0,255,160,189,167,147,0,0,0,9,112,72,89,115,0,0,11,19,0,0,11,19,1,0,154,156,24,0,0,0,7,116,73,77,69,7,222,12,10,20,17,26,251,57,11,92,0,0,0,107,73,68,65,84,56,203,165,83,91,14,192,32,
8,163,141,247,191,50,251,153,9,16,22,6,240,37,216,242,168,8,121,77,85,85,26,6,0,50,37,59,206,132,108,147,176,3,78,139,253,233,192,98,226,153,178,181,170,131,236,254,198,92,7,83,49,89,85,119,239,157,236,
192,153,140,106,19,208,6,163,194,23,24,201,214,103,119,125,163,86,231,11,144,205,158,9,205,172,74,36,87,254,234,51,97,251,157,31,197,207,111,229,235,115,88,252,0,0,0,0,73,69,78,68,174,66,96,130,0,0};

const char* LfoEditor::lfo_png = (const char*) resource_LfoEditor_lfo_png;
const int LfoEditor::lfo_pngSize = 235;


//[EndFile] You can add extra defines here...
//[/EndFile]
