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
#include "../../GrooveboxMemory/Waveforms.h"
#include "../ParameterWidgets/WaveformBrowser.h"
//[/Headers]

#include "WaveEditor.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
extern OverallMemoryBlock* grooveboxMemory;
extern Waveforms* waveForms;
//[/MiscUserDefs]

//==============================================================================
WaveEditor::WaveEditor (const String &componentName, AllParts part, int toneNumber)
    : Component (componentName), m_part(part), m_toneNumber(toneNumber)
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    addAndMakeVisible (m_fxmGrp = new PanelGroupGrey ("waveGrp","WAVE"));
    addAndMakeVisible (m_imageButton = new ImageButton ("new button"));
    m_imageButton->setButtonText (String());

    m_imageButton->setImages (false, true, true,
                              ImageCache::getFromMemory (wave_png, wave_pngSize), 1.000f, Colour (0x4340454a),
                              Image(), 1.000f, Colour (0x4340454a),
                              Image(), 1.000f, Colour (0x4340454a));
    addAndMakeVisible (m_waveButton = new TextButton ("new button"));
    m_waveButton->setButtonText (TRANS("A:001 Dist TB 303a"));
    m_waveButton->addListener (this);

    addAndMakeVisible (m_waveLabel = new Label ("waveLabel",
                                                TRANS("WAVEFORM")));
    m_waveLabel->setFont (Font (12.00f, Font::bold));
    m_waveLabel->setJustificationType (Justification::centredLeft);
    m_waveLabel->setEditable (false, false, false);
    m_waveLabel->setColour (Label::textColourId, Colours::black);
    m_waveLabel->setColour (TextEditor::textColourId, Colours::black);
    m_waveLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_onLabel2 = new Label ("onLabel",
                                               TRANS("GAIN")));
    m_onLabel2->setFont (Font (12.00f, Font::bold));
    m_onLabel2->setJustificationType (Justification::centredLeft);
    m_onLabel2->setEditable (false, false, false);
    m_onLabel2->setColour (Label::textColourId, Colours::black);
    m_onLabel2->setColour (TextEditor::textColourId, Colours::black);
    m_onLabel2->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_onToggle = new BlackToggle());
    addAndMakeVisible (m_onLabel = new Label ("onLabel",
                                              TRANS("ON")));
    m_onLabel->setFont (Font (12.00f, Font::bold));
    m_onLabel->setJustificationType (Justification::centredLeft);
    m_onLabel->setEditable (false, false, false);
    m_onLabel->setColour (Label::textColourId, Colours::black);
    m_onLabel->setColour (TextEditor::textColourId, Colours::black);
    m_onLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_waveGainComboBox = new ParameterComboBox ("waveGainComboBox"));
    m_waveGainComboBox->setEditableText (false);
    m_waveGainComboBox->setJustificationType (Justification::centredRight);
    m_waveGainComboBox->setTextWhenNothingSelected (TRANS("-6 dB"));
    m_waveGainComboBox->setTextWhenNoChoicesAvailable (TRANS("(no choices)"));
    m_waveGainComboBox->addItem (TRANS("-6dB"), 1);
    m_waveGainComboBox->addItem (TRANS("0dB"), 2);
    m_waveGainComboBox->addItem (TRANS("+6dB"), 3);
    m_waveGainComboBox->addItem (TRANS("+12dB"), 4);
    m_waveGainComboBox->addListener (this);

    addAndMakeVisible (m_envModeToggle = new ParameterLedSwitch ("envModeToggle"));
    addAndMakeVisible (m_envModeLabel = new Label ("envModeLabel",
                                                   TRANS("ENVELOPE MODE")));
    m_envModeLabel->setFont (Font (12.00f, Font::bold));
    m_envModeLabel->setJustificationType (Justification::centredRight);
    m_envModeLabel->setEditable (false, false, false);
    m_envModeLabel->setColour (TextEditor::textColourId, Colours::black);
    m_envModeLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_muteGrpSlider = new MicroParameterSlider ("muteGrpSlider"));
    m_muteGrpSlider->setRange (0, 31, 1);
    m_muteGrpSlider->setSliderStyle (Slider::LinearBar);
    m_muteGrpSlider->setTextBoxStyle (Slider::TextBoxLeft, false, 80, 20);
    m_muteGrpSlider->addListener (this);

    addAndMakeVisible (m_muteGrpLabel = new Label ("muteGrpLabel",
                                                   TRANS("MUTE GROUP")));
    m_muteGrpLabel->setFont (Font (12.00f, Font::bold));
    m_muteGrpLabel->setJustificationType (Justification::centredLeft);
    m_muteGrpLabel->setEditable (false, false, false);
    m_muteGrpLabel->setColour (TextEditor::textColourId, Colours::black);
    m_muteGrpLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_waveformSearchComboBox = new WaveformSearchComboBox ("waveformSearchComboBox", PartR, m_toneNumber, false));

    //[UserPreSize]
	m_waveGroupType = nullptr;
	m_waveGroupId = nullptr;
	m_waveNumber = nullptr;

	if (part != PartR)
	{
		m_muteGrpLabel->setVisible(false);
		m_muteGrpSlider->setVisible(false);
		m_envModeLabel->setVisible(false);
		m_envModeToggle->setVisible(false);
	}
    //[/UserPreSize]

    setSize (241, 152);


    //[Constructor] You can add your own custom stuff here..
	setupParameters(part, toneNumber);
    //[/Constructor]
}

WaveEditor::~WaveEditor()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
	if (m_waveGroupType != nullptr) m_waveGroupType->removeChangeListener(this);
	if (m_waveGroupId != nullptr) m_waveGroupId->removeChangeListener(this);
	if (m_waveNumber != nullptr) m_waveNumber->removeChangeListener(this);
    //[/Destructor_pre]

    m_fxmGrp = nullptr;
    m_imageButton = nullptr;
    m_waveButton = nullptr;
    m_waveLabel = nullptr;
    m_onLabel2 = nullptr;
    m_onToggle = nullptr;
    m_onLabel = nullptr;
    m_waveGainComboBox = nullptr;
    m_envModeToggle = nullptr;
    m_envModeLabel = nullptr;
    m_muteGrpSlider = nullptr;
    m_muteGrpLabel = nullptr;
    m_waveformSearchComboBox = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void WaveEditor::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
#ifdef JUCE_MSVC
	g;
#endif
    //[/UserPrePaint]

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void WaveEditor::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    m_fxmGrp->setBounds (0, 0, getWidth() - 0, getHeight() - 0);
    m_imageButton->setBounds (3, 1, 16, 16);
    m_waveButton->setBounds (8, 86, getWidth() - 12, 34);
    m_waveLabel->setBounds (0, 70, 104, 16);
    m_onLabel2->setBounds (0, 44, 42, 16);
    m_onToggle->setBounds (40, 20, 25, 17);
    m_onLabel->setBounds (0, 20, 42, 16);
    m_waveGainComboBox->setBounds (40, 44, 60, 17);
    m_envModeToggle->setBounds (168, 44, 80, 32);
    m_envModeLabel->setBounds (104, 44, 68, 32);
    m_muteGrpSlider->setBounds (192, 20, 43, 16);
    m_muteGrpLabel->setBounds (104, 20, 84, 16);
    m_waveformSearchComboBox->setBounds (4, 128, getWidth() - 8, 17);
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void WaveEditor::buttonClicked (Button* buttonThatWasClicked)
{
    //[UserbuttonClicked_Pre]
    //[/UserbuttonClicked_Pre]

    if (buttonThatWasClicked == m_waveButton)
    {
        //[UserButtonCode_m_waveButton] -- add your button handler code here..
		DialogWindow::LaunchOptions dialogLaunch;
		dialogLaunch.dialogTitle = "Select Waveform for PART " + String(m_part == PartR ? "R" : String((int)m_part + 1)) + ", TONE " + String(m_part == PartR ? String(m_toneNumber) : String((m_toneNumber - 0x1000) / 0x200 + 1));
		WaveformBrowser* waveformBrowser = new WaveformBrowser(m_part, m_toneNumber, waveForms->getGroupForId(m_waveGroupId->getValue()), m_waveNumber->getValue());
		WaveFormDlgCallback* callbackObject = new WaveFormDlgCallback();
		callbackObject->setWaveformSelectParameters(m_waveGroupType, m_waveGroupId, m_waveNumber);
		callbackObject->m_restorable32BitIntForWaveformDuringBrowserDialog =
			waveForms->get32BitIntForWaveform(m_waveGroupId->getValue(), m_waveNumber->getValue(), 0);
		dialogLaunch.content.set(waveformBrowser, true);
		dialogLaunch.escapeKeyTriggersCloseButton = true;
		dialogLaunch.useNativeTitleBar = true;
		dialogLaunch.resizable = false;
		DialogWindow* dw = dialogLaunch.launchAsync();
		ModalComponentManager::getInstance()->attachCallback(dw, callbackObject);
		waveformBrowser->getWaveformsAllGroupsComponent()->tryScrollToSelectedButton();
        //[/UserButtonCode_m_waveButton]
    }

    //[UserbuttonClicked_Post]
    //[/UserbuttonClicked_Post]
}

void WaveEditor::comboBoxChanged (ComboBox* comboBoxThatHasChanged)
{
    //[UsercomboBoxChanged_Pre]
    //[/UsercomboBoxChanged_Pre]

    if (comboBoxThatHasChanged == m_waveGainComboBox)
    {
        //[UserComboBoxCode_m_waveGainComboBox] -- add your combo box handling code here..
        //[/UserComboBoxCode_m_waveGainComboBox]
    }

    //[UsercomboBoxChanged_Post]
    //[/UsercomboBoxChanged_Post]
}

void WaveEditor::sliderValueChanged (Slider* sliderThatWasMoved)
{
    //[UsersliderValueChanged_Pre]
    //[/UsersliderValueChanged_Pre]

    if (sliderThatWasMoved == m_muteGrpSlider)
    {
        //[UserSliderCode_m_muteGrpSlider] -- add your slider handling code here..
        //[/UserSliderCode_m_muteGrpSlider]
    }

    //[UsersliderValueChanged_Post]
    //[/UsersliderValueChanged_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
// allowed toneNumber values are Tone1 = 0x1000, Tone2 = 0x1200, Tone3 = 0x1400, Tone4 = 0x1600 for synth parts or 35..98 for rhythm part
void WaveEditor::setupParameters(AllParts part, int toneNumber)
{
	if (grooveboxMemory == nullptr) return;

	m_part = part;

	if (part == AllParts::PartR)
	{
		if (toneNumber >= 35 && toneNumber <= 98)
		{
			if (grooveboxMemory != nullptr)
			{
				if (RhythmSetBlock* rhyhtmSet = grooveboxMemory->getRhythmSetBlock())
				{
					if (RhythmNoteBlock* noteBlock = rhyhtmSet->getRhythmNoteBlockPtr((uint8)toneNumber))
					{
						m_toneNumber = toneNumber;

						if (m_waveGroupType != nullptr) m_waveGroupType->removeChangeListener(this);
						if (m_waveGroupId != nullptr) m_waveGroupId->removeChangeListener(this);
						if (m_waveNumber != nullptr) m_waveNumber->removeChangeListener(this);

						m_onToggle->setParameter(noteBlock->getParameter(0x00));
						m_waveGroupType = noteBlock->getParameter(0x01);
						m_waveGroupId = noteBlock->getParameter(0x02);
						m_waveNumber = noteBlock->getParameter(0x03);
						changeListenerCallback(m_waveNumber);
						m_waveGroupType->addChangeListener(this);
						m_waveGroupId->addChangeListener(this);
						m_waveNumber->addChangeListener(this);
						m_waveGainComboBox->setParameter(noteBlock->getParameter(0x05));

						m_muteGrpSlider->setParameter(noteBlock->getParameter(0x07));
						m_envModeToggle->setParameter(noteBlock->getParameter(0x08));
						m_waveformSearchComboBox->setupParameters(m_part, m_toneNumber);
						m_fxmGrp->setText("WAVE OF KEY " + String(toneNumber));
					}
				}
			}
		}
	}
	else
	{
		if (SynthPatchesBlock* synthPatches = grooveboxMemory->getSynthPatchesBlock())
		{
			if (PatchPartBlock* patchPart = synthPatches->getPatchPartBlockPtr((SynthParts)m_part))
			{
				PatchToneBlock* tone = nullptr;
				int toneNumberLabel = 1;
				switch (toneNumber)
				{
				case Tone1:
					if (PatchToneBlock* tone1 = patchPart->getPatchToneBlockPtr(Tone1)) tone = tone1;
					toneNumberLabel = 1;
					break;
				case Tone2:
					if (PatchToneBlock* tone2 = patchPart->getPatchToneBlockPtr(Tone2)) tone = tone2;
					toneNumberLabel = 2;
					break;
				case Tone3:
					if (PatchToneBlock* tone3 = patchPart->getPatchToneBlockPtr(Tone3)) tone = tone3;
					toneNumberLabel = 3;
					break;
				case Tone4:
					if (PatchToneBlock* tone4 = patchPart->getPatchToneBlockPtr(Tone4)) tone = tone4;
					toneNumberLabel = 4;
					break;
				}
				if (tone != nullptr)
				{
					m_toneNumber = toneNumber;

					if (m_waveGroupType != nullptr) m_waveGroupType->removeChangeListener(this);
					if (m_waveGroupId != nullptr) m_waveGroupId->removeChangeListener(this);
					if (m_waveNumber != nullptr) m_waveNumber->removeChangeListener(this);

					m_onToggle->setParameter(tone->getParameter(0x00));
					m_waveGroupType = tone->getParameter(0x01);
					m_waveGroupId = tone->getParameter(0x02);
					m_waveNumber = tone->getParameter(0x03);
					changeListenerCallback(m_waveNumber);
					m_waveGroupType->addChangeListener(this);
					m_waveGroupId->addChangeListener(this);
					m_waveNumber->addChangeListener(this);
					m_waveGainComboBox->setParameter(tone->getParameter(0x05));
					m_waveformSearchComboBox->setupParameters(m_part, m_toneNumber);
					m_fxmGrp->setText("WAVE T" + String(toneNumberLabel));
				}
			}
		}
	}
}


void WaveEditor::WaveFormDlgCallback::modalStateFinished(int returnValue)
{
	uint8 groupType;
	uint8 groupId;
	uint8 waveIndexInGroup;
	if (returnValue == 0)	/* no valid group may result in value 0, so this indicates  a dialog abortian */
	{
		// restore old value:
		waveForms->getGroupAndIndexFrom32BitInt(m_restorable32BitIntForWaveformDuringBrowserDialog, groupType, groupId, waveIndexInGroup);
		this->m_groupType->setValue(groupType, Parameter::GuiWidget);
		this->m_groupId->setValue(groupId, Parameter::GuiWidget);
		this->m_waveIndexInGroup->setValue(waveIndexInGroup, Parameter::GuiWidget);
	}
	else /* reconstruct selection from return value of the dialog */
	{

	}
}

// parameter changes of groovebox memory block
void WaveEditor::changeListenerCallback(ChangeBroadcaster *source)
{
	if (Parameter* param = dynamic_cast<Parameter*>(source))
	{
		// if one of the parameters changed
		if (param == m_waveGroupType || param == m_waveGroupId ||param == m_waveNumber)
		{
			m_waveButton->setButtonText(waveForms->getButtonText(
				waveForms->getGroupForId(m_waveGroupId->getValue()),
				m_waveNumber->getValue()));
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

<JUCER_COMPONENT documentType="Component" className="WaveEditor" componentName=""
                 parentClasses="public Component, public ChangeListener" constructorParams="const String &amp;componentName, AllParts part, int toneNumber"
                 variableInitialisers="Component (componentName), m_part(part), m_toneNumber(toneNumber)"
                 snapPixels="4" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="1" initialWidth="241" initialHeight="152">
  <BACKGROUND backgroundColour="0"/>
  <JUCERCOMP name="fxmGrp" id="ae3eed65b8ca1538" memberName="m_fxmGrp" virtualName=""
             explicitFocusOrder="0" pos="0 0 0M 0M" sourceFile="../GroupWidgets/PanelGroupGrey.cpp"
             constructorParams="&quot;waveGrp&quot;,&quot;WAVE&quot;"/>
  <IMAGEBUTTON name="new button" id="6edd918beb7645cb" memberName="m_imageButton"
               virtualName="" explicitFocusOrder="0" pos="3 1 16 16" buttonText=""
               connectedEdges="0" needsCallback="0" radioGroupId="0" keepProportions="1"
               resourceNormal="wave_png" opacityNormal="1" colourNormal="4340454a"
               resourceOver="" opacityOver="1" colourOver="4340454a" resourceDown=""
               opacityDown="1" colourDown="4340454a"/>
  <TEXTBUTTON name="new button" id="603fab9f912b12cf" memberName="m_waveButton"
              virtualName="" explicitFocusOrder="0" pos="8 86 12M 34" buttonText="A:001 Dist TB 303a"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <LABEL name="waveLabel" id="77636cfe920d8c67" memberName="m_waveLabel"
         virtualName="" explicitFocusOrder="0" pos="0 70 104 16" textCol="ff000000"
         edTextCol="ff000000" edBkgCol="0" labelText="WAVEFORM" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="12" bold="1" italic="0" justification="33"/>
  <LABEL name="onLabel" id="622e567326097c53" memberName="m_onLabel2"
         virtualName="" explicitFocusOrder="0" pos="0 44 42 16" textCol="ff000000"
         edTextCol="ff000000" edBkgCol="0" labelText="GAIN" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="12" bold="1" italic="0" justification="33"/>
  <JUCERCOMP name="onToggle" id="b0e7322ed6fe4133" memberName="m_onToggle"
             virtualName="" explicitFocusOrder="0" pos="40 20 25 17" sourceFile="../ParameterWidgets/BlackToggle.cpp"
             constructorParams=""/>
  <LABEL name="onLabel" id="a5103dfa4b0cded3" memberName="m_onLabel" virtualName=""
         explicitFocusOrder="0" pos="0 20 42 16" textCol="ff000000" edTextCol="ff000000"
         edBkgCol="0" labelText="ON" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="12"
         bold="1" italic="0" justification="33"/>
  <COMBOBOX name="waveGainComboBox" id="1615d6307f31d1e" memberName="m_waveGainComboBox"
            virtualName="ParameterComboBox" explicitFocusOrder="0" pos="40 44 60 17"
            editable="0" layout="34" items="-6dB&#10;0dB&#10;+6dB&#10;+12dB"
            textWhenNonSelected="-6 dB" textWhenNoItems="(no choices)"/>
  <JUCERCOMP name="" id="6a490656457f331d" memberName="m_envModeToggle" virtualName=""
             explicitFocusOrder="0" pos="168 44 80 32" sourceFile="../ParameterWidgets/ParameterLedSwitch.cpp"
             constructorParams="&quot;envModeToggle&quot;"/>
  <LABEL name="envModeLabel" id="188a8fc929628232" memberName="m_envModeLabel"
         virtualName="" explicitFocusOrder="0" pos="104 44 68 32" edTextCol="ff000000"
         edBkgCol="0" labelText="ENVELOPE MODE" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="12" bold="1" italic="0" justification="34"/>
  <SLIDER name="muteGrpSlider" id="457081b73f98531d" memberName="m_muteGrpSlider"
          virtualName="MicroParameterSlider" explicitFocusOrder="0" pos="192 20 43 16"
          min="0" max="31" int="1" style="LinearBar" textBoxPos="TextBoxLeft"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <LABEL name="muteGrpLabel" id="9f4f0cd222ed55fb" memberName="m_muteGrpLabel"
         virtualName="" explicitFocusOrder="0" pos="104 20 84 16" edTextCol="ff000000"
         edBkgCol="0" labelText="MUTE GROUP" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="12"
         bold="1" italic="0" justification="33"/>
  <JUCERCOMP name="" id="db2be71c65eb8969" memberName="m_waveformSearchComboBox"
             virtualName="" explicitFocusOrder="0" pos="4 128 8M 17" sourceFile="../ParameterWidgets/WaveformSearchComboBox.cpp"
             constructorParams="&quot;waveformSearchComboBox&quot;, PartR, m_toneNumber, false"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif

//==============================================================================
// Binary resources - be careful not to edit any of these sections!

// JUCER_RESOURCE: wave_png, 229, "../../../Resources/PatchEditSectionIcons/wave.png"
static const unsigned char resource_WaveEditor_wave_png[] = { 137,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,0,16,0,0,0,16,8,6,0,0,0,31,243,255,97,0,0,0,1,115,82,71,66,0,174,206,28,233,0,0,0,6,98,75,
71,68,0,255,0,255,0,255,160,189,167,147,0,0,0,9,112,72,89,115,0,0,11,19,0,0,11,19,1,0,154,156,24,0,0,0,7,116,73,77,69,7,222,12,10,20,18,21,64,171,69,14,0,0,0,101,73,68,65,84,56,203,173,147,73,14,192,48,
8,3,49,234,255,191,60,189,164,82,211,146,149,248,134,144,141,17,70,86,0,96,11,144,36,219,37,87,156,22,121,70,20,192,45,9,95,157,218,21,24,238,27,12,57,183,2,128,36,81,208,115,242,238,95,189,27,71,214,
159,33,63,7,85,48,2,177,86,223,151,83,247,169,125,59,190,51,2,45,219,71,207,152,126,38,101,223,249,6,29,4,79,251,253,70,38,152,0,0,0,0,73,69,78,68,174,66,96,130,0,0};

const char* WaveEditor::wave_png = (const char*) resource_WaveEditor_wave_png;
const int WaveEditor::wave_pngSize = 229;


//[EndFile] You can add extra defines here...
//[/EndFile]
