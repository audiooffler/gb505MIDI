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
#include "../MIDIConnection/GrooveboxConnector.h"
//[/Headers]

#include "WaveformBrowser.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
extern GrooveboxConnector* grooveboxConnector;
extern Waveforms* waveForms;
//[/MiscUserDefs]

//==============================================================================
WaveformBrowser::WaveformBrowser (SynthParts part, Tone tone, Waveforms::WaveGroup group, int waveIndexInGroup)
    : m_part (part), m_tone (tone), m_initialGroup(group), m_initialIndexInGroup(waveIndexInGroup)
{
    addAndMakeVisible (m_waveformsAllGroupsViewport = new Viewport ("waveformsAllGroupsViewport"));
    m_waveformsAllGroupsViewport->setScrollBarsShown (true, false);
    m_waveformsAllGroupsViewport->setViewedComponent (new WaveformsAllGroups (grooveboxConnector->getActiveConnectionGrooveboxModel(), m_part, m_tone));

    addAndMakeVisible (m_cancelButton = new TextButton ("cancelButton"));
    m_cancelButton->setTooltip (TRANS("Restore previously selected waveform and return."));
    m_cancelButton->setButtonText (TRANS("Cancel"));
    m_cancelButton->addListener (this);

    addAndMakeVisible (m_okButton = new TextButton ("okButton"));
    m_okButton->setTooltip (TRANS("Keep new selected waveform and return."));
    m_okButton->setButtonText (TRANS("OK"));
    m_okButton->addListener (this);

    addAndMakeVisible (m_highlightTextEditor = new TextEditor ("highlightTextEditor"));
    m_highlightTextEditor->setTooltip (TRANS("Enter whitespace or comma separated tags to look for. Waveforms that contain all entered tags in their name or tooltip description are highlighted immediatly."));
    m_highlightTextEditor->setMultiLine (false);
    m_highlightTextEditor->setReturnKeyStartsNewLine (false);
    m_highlightTextEditor->setReadOnly (false);
    m_highlightTextEditor->setScrollbarsShown (true);
    m_highlightTextEditor->setCaretVisible (true);
    m_highlightTextEditor->setPopupMenuEnabled (true);
    m_highlightTextEditor->setText (String::empty);

    addAndMakeVisible (m_highlightLabel = new Label ("highlightLabel",
                                                     TRANS("Find and Highlight Tags:")));
    m_highlightLabel->setFont (Font (15.00f, Font::plain));
    m_highlightLabel->setJustificationType (Justification::centredLeft);
    m_highlightLabel->setEditable (false, false, false);
    m_highlightLabel->setColour (TextEditor::textColourId, Colours::black);
    m_highlightLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_prevWaveformLabel = new Label ("prevWaveformLabel",
                                                        TRANS("Previously Selected Waveform:")));
    m_prevWaveformLabel->setFont (Font (15.00f, Font::plain));
    m_prevWaveformLabel->setJustificationType (Justification::centredLeft);
    m_prevWaveformLabel->setEditable (false, false, false);
    m_prevWaveformLabel->setColour (TextEditor::textColourId, Colours::black);
    m_prevWaveformLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_prevWaveformText = new TextEditor ("prevWaveformText"));
    m_prevWaveformText->setMultiLine (true);
    m_prevWaveformText->setReturnKeyStartsNewLine (true);
    m_prevWaveformText->setReadOnly (true);
    m_prevWaveformText->setScrollbarsShown (true);
    m_prevWaveformText->setCaretVisible (false);
    m_prevWaveformText->setPopupMenuEnabled (true);
    m_prevWaveformText->setColour (TextEditor::backgroundColourId, Colour (0xffe5e5e5));
    m_prevWaveformText->setText (String::empty);

    addAndMakeVisible (m_prevWaveformLabel2 = new Label ("prevWaveformLabel",
                                                         TRANS("New Selected Waveform:")));
    m_prevWaveformLabel2->setFont (Font (15.00f, Font::plain));
    m_prevWaveformLabel2->setJustificationType (Justification::centredLeft);
    m_prevWaveformLabel2->setEditable (false, false, false);
    m_prevWaveformLabel2->setColour (TextEditor::textColourId, Colours::black);
    m_prevWaveformLabel2->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_newWaveformText = new TextEditor ("newWaveformText"));
    m_newWaveformText->setMultiLine (true);
    m_newWaveformText->setReturnKeyStartsNewLine (true);
    m_newWaveformText->setReadOnly (true);
    m_newWaveformText->setScrollbarsShown (true);
    m_newWaveformText->setCaretVisible (false);
    m_newWaveformText->setPopupMenuEnabled (true);
    m_newWaveformText->setColour (TextEditor::backgroundColourId, Colour (0xffe5e5e5));
    m_newWaveformText->setText (String::empty);


    //[UserPreSize]
	m_waveformsAllGroupsViewport->setSingleStepSizes(0, 20);
    //[/UserPreSize]

    setSize (1070, 676);


    //[Constructor] You can add your own custom stuff here..
	m_waveformsAllGroupsViewport->grabKeyboardFocus();
	WaveformsAllGroups* waveformsAllGroups = dynamic_cast<WaveformsAllGroups*>(m_waveformsAllGroupsViewport->getViewedComponent());
	m_highlightTextEditor->addListener(waveformsAllGroups);
	waveformsAllGroups->addListenerToAllButtons(this);
	waveformsAllGroups->grabKeyboardFocus();
	waveformsAllGroups->tryScrollToSelectedButton();
	m_prevWaveformText->clear();
	m_prevWaveformText->setFont(Font());
	m_prevWaveformText->insertTextAtCaret(String::charToString(Waveforms::getGroupChar(m_initialGroup)) + String(m_initialIndexInGroup).paddedLeft('0', 3) + "\r\n");
	m_prevWaveformText->setFont(Font().boldened());
	m_prevWaveformText->insertTextAtCaret(waveForms->getName(m_initialGroup, m_initialIndexInGroup) + "\r\n");
	m_prevWaveformText->setFont(Font());
	m_prevWaveformText->insertTextAtCaret(waveForms->getLongName(m_initialGroup, m_initialIndexInGroup));
	m_newWaveformText->clear();
	m_newWaveformText->setFont(Font());
	m_newWaveformText->insertTextAtCaret(String::charToString(Waveforms::getGroupChar(m_initialGroup)) + String(m_initialIndexInGroup).paddedLeft('0', 3) + "\r\n");
	m_newWaveformText->setFont(Font().boldened());
	m_newWaveformText->insertTextAtCaret(waveForms->getName(m_initialGroup, m_initialIndexInGroup) + "\r\n");
	m_newWaveformText->setFont(Font());
	m_newWaveformText->insertTextAtCaret(waveForms->getLongName(m_initialGroup, m_initialIndexInGroup));
    //[/Constructor]
}

WaveformBrowser::~WaveformBrowser()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    m_waveformsAllGroupsViewport = nullptr;
    m_cancelButton = nullptr;
    m_okButton = nullptr;
    m_highlightTextEditor = nullptr;
    m_highlightLabel = nullptr;
    m_prevWaveformLabel = nullptr;
    m_prevWaveformText = nullptr;
    m_prevWaveformLabel2 = nullptr;
    m_newWaveformText = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void WaveformBrowser::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colour (0xffeeddff));

    g.setGradientFill (ColourGradient (Colour (0xffcdcccc),
                                       120.0f, 248.0f,
                                       Colour (0xff979797),
                                       224.0f, 720.0f,
                                       false));
    g.fillRect (0, 0, getWidth() - 0, getHeight() - 0);

    g.setColour (Colours::black);
    g.fillPath (internalPath1);

    //[UserPaint] Add your own custom painting code here..
	g.setColour(Colour(0xffECEEA5));
	g.fillRect(m_waveformsAllGroupsViewport->getBounds());
	g.setColour(Colours::black);
	g.drawRect(m_waveformsAllGroupsViewport->getX() - 1, m_waveformsAllGroupsViewport->getY() - 1, m_waveformsAllGroupsViewport->getWidth() + 2, m_waveformsAllGroupsViewport->getHeight() + 2);
    //[/UserPaint]
}

void WaveformBrowser::resized()
{
    m_waveformsAllGroupsViewport->setBounds (8, 8, 854, 660);
    m_cancelButton->setBounds (972, 640, 92, 24);
    m_okButton->setBounds (872, 640, 92, 24);
    m_highlightTextEditor->setBounds (872, 32, 192, 24);
    m_highlightLabel->setBounds (872, 8, 192, 24);
    m_prevWaveformLabel->setBounds (872, (getHeight() / 2) + -74, 192, 24);
    m_prevWaveformText->setBounds (872, (getHeight() / 2) + -46, 192, 52);
    m_prevWaveformLabel2->setBounds (872, (getHeight() / 2) + 38, 192, 24);
    m_newWaveformText->setBounds (872, (getHeight() / 2) + 70, 192, 52);
    internalPath1.clear();
    internalPath1.startNewSubPath (956.0f, static_cast<float> ((getHeight() / 2) + 14));
    internalPath1.lineTo (980.0f, static_cast<float> ((getHeight() / 2) + 14));
    internalPath1.lineTo (968.0f, static_cast<float> ((getHeight() / 2) + 34));
    internalPath1.closeSubPath();

    //[UserResized] Add your own custom resize handling here..

    // This is called when the MainContentComponent is resized.
    // If you add any child components, this is where you should
    // update their positions.

    //[/UserResized]
}

void WaveformBrowser::buttonClicked (Button* buttonThatWasClicked)
{
    //[UserbuttonClicked_Pre]
    //[/UserbuttonClicked_Pre]

    if (buttonThatWasClicked == m_cancelButton)
    {
        //[UserButtonCode_m_cancelButton] -- add your button handler code here..
		DialogWindow* dw = findParentComponentOfClass<DialogWindow>();
		if (dw != nullptr) dw->exitModalState(0);
        //[/UserButtonCode_m_cancelButton]
    }
    else if (buttonThatWasClicked == m_okButton)
    {
        //[UserButtonCode_m_okButton] -- add your button handler code here..
		DialogWindow* dw = findParentComponentOfClass<DialogWindow>();
		if (dw != nullptr) dw->exitModalState(1);
        //[/UserButtonCode_m_okButton]
    }

    //[UserbuttonClicked_Post]
	else if (WaveformButton* wf_button = dynamic_cast<WaveformButton*>(buttonThatWasClicked))
	{
		Waveforms::WaveGroup group(wf_button->getGroup());
		int index(wf_button->getIndexInGroup());
		m_newWaveformText->clear();
		m_newWaveformText->setFont(Font());
		m_newWaveformText->insertTextAtCaret(String::charToString(Waveforms::getGroupChar(group)) + String(index).paddedLeft('0', 3) + "\r\n");
		m_newWaveformText->setFont(Font().boldened());
		m_newWaveformText->insertTextAtCaret(waveForms->getName(group, index) + "\r\n");
		m_newWaveformText->setFont(Font());
		m_newWaveformText->insertTextAtCaret(wf_button->getTooltip());

	}
    //[/UserbuttonClicked_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
WaveformsAllGroups* WaveformBrowser::getWaveformsAllGroupsComponent()
{
	if (WaveformsAllGroups* waveformsAllGroups = dynamic_cast<WaveformsAllGroups*>(m_waveformsAllGroupsViewport->getViewedComponent()))
		return waveformsAllGroups;
	else return nullptr;
}
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Introjucer information section --

    This is where the Introjucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="WaveformBrowser" componentName=""
                 parentClasses="public Component" constructorParams="SynthParts part, Tone tone, Waveforms::WaveGroup group, int waveIndexInGroup"
                 variableInitialisers="m_part (part), m_tone (tone), m_initialGroup(group), m_initialIndexInGroup(waveIndexInGroup)"
                 snapPixels="2" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="1" initialWidth="1070" initialHeight="676">
  <BACKGROUND backgroundColour="ffeeddff">
    <RECT pos="0 0 0M 0M" fill="linear: 120 248, 224 720, 0=ffcdcccc, 1=ff979797"
          hasStroke="0"/>
    <PATH pos="0 0 100 100" fill="solid: ff000000" hasStroke="0" nonZeroWinding="1">s 956 14C l 980 14C l 968 34C x</PATH>
  </BACKGROUND>
  <VIEWPORT name="waveformsAllGroupsViewport" id="b754477d30b6b112" memberName="m_waveformsAllGroupsViewport"
            virtualName="" explicitFocusOrder="0" pos="8 8 854 660" vscroll="1"
            hscroll="0" scrollbarThickness="18" contentType="1" jucerFile="Widgets/WaveformsAllGroups.cpp"
            contentClass="" constructorParams="grooveboxConnector-&gt;getActiveConnectionGrooveboxModel(), m_part, m_tone"/>
  <TEXTBUTTON name="cancelButton" id="fec0b1aad7a3c673" memberName="m_cancelButton"
              virtualName="" explicitFocusOrder="0" pos="972 640 92 24" tooltip="Restore previously selected waveform and return."
              buttonText="Cancel" connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="okButton" id="b32c299c5ab03f5" memberName="m_okButton"
              virtualName="" explicitFocusOrder="0" pos="872 640 92 24" tooltip="Keep new selected waveform and return."
              buttonText="OK" connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTEDITOR name="highlightTextEditor" id="e94133dfb6142cba" memberName="m_highlightTextEditor"
              virtualName="" explicitFocusOrder="0" pos="872 32 192 24" tooltip="Enter whitespace or comma separated tags to look for. Waveforms that contain all entered tags in their name or tooltip description are highlighted immediatly."
              initialText="" multiline="0" retKeyStartsLine="0" readonly="0"
              scrollbars="1" caret="1" popupmenu="1"/>
  <LABEL name="highlightLabel" id="5682663423213b8d" memberName="m_highlightLabel"
         virtualName="" explicitFocusOrder="0" pos="872 8 192 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Find and Highlight Tags:" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" bold="0" italic="0" justification="33"/>
  <LABEL name="prevWaveformLabel" id="f8d175f5291f38f5" memberName="m_prevWaveformLabel"
         virtualName="" explicitFocusOrder="0" pos="872 -74C 192 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Previously Selected Waveform:" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" bold="0" italic="0" justification="33"/>
  <TEXTEDITOR name="prevWaveformText" id="13a3ca9aea270613" memberName="m_prevWaveformText"
              virtualName="" explicitFocusOrder="0" pos="872 -46C 192 52" bkgcol="ffe5e5e5"
              initialText="" multiline="1" retKeyStartsLine="1" readonly="1"
              scrollbars="1" caret="0" popupmenu="1"/>
  <LABEL name="prevWaveformLabel" id="cbb64f859d3f03a" memberName="m_prevWaveformLabel2"
         virtualName="" explicitFocusOrder="0" pos="872 38C 192 24" edTextCol="ff000000"
         edBkgCol="0" labelText="New Selected Waveform:" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" bold="0" italic="0" justification="33"/>
  <TEXTEDITOR name="newWaveformText" id="27cd1ff2aaa75c27" memberName="m_newWaveformText"
              virtualName="" explicitFocusOrder="0" pos="872 70C 192 52" bkgcol="ffe5e5e5"
              initialText="" multiline="1" retKeyStartsLine="1" readonly="1"
              scrollbars="1" caret="0" popupmenu="1"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
