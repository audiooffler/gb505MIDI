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
#include "../GrooveboxMemory/OverallMemoryBlock.h"
#include "../GrooveboxMemory/QuickSysExBlock.h"
//[/Headers]

#include "RhythmSetEditorTab.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
extern OverallMemoryBlock* grooveboxMemory;
extern QuickSysExBlock* quickSysEx;
//[/MiscUserDefs]

//==============================================================================
RhythmSetEditorTab::RhythmSetEditorTab ()
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    addAndMakeVisible (m_commonGrp4 = new RectangleGrey());
    addAndMakeVisible (m_partNoLabel = new Label ("partNoLabel",
                                                  TRANS("PART R")));
    m_partNoLabel->setFont (Font (12.00f, Font::bold));
    m_partNoLabel->setJustificationType (Justification::centredLeft);
    m_partNoLabel->setEditable (false, false, false);
    m_partNoLabel->setColour (Label::textColourId, Colours::black);
    m_partNoLabel->setColour (TextEditor::textColourId, Colours::black);
    m_partNoLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_patchNameLabel = new Label ("patchNameLabel",
                                                     TRANS("RHYTHM SET NAME")));
    m_patchNameLabel->setFont (Font (12.00f, Font::bold));
    m_patchNameLabel->setJustificationType (Justification::centredLeft);
    m_patchNameLabel->setEditable (false, false, false);
    m_patchNameLabel->setColour (Label::textColourId, Colours::black);
    m_patchNameLabel->setColour (TextEditor::textColourId, Colours::black);
    m_patchNameLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_patchNameEditor = new ParameterTextEditor ("patchNameEditor"));
    m_patchNameEditor->setMultiLine (false);
    m_patchNameEditor->setReturnKeyStartsNewLine (false);
    m_patchNameEditor->setReadOnly (false);
    m_patchNameEditor->setScrollbarsShown (false);
    m_patchNameEditor->setCaretVisible (true);
    m_patchNameEditor->setPopupMenuEnabled (true);
    m_patchNameEditor->setColour (TextEditor::textColourId, Colours::black);
    m_patchNameEditor->setColour (TextEditor::backgroundColourId, Colour (0xfff2f59b));
    m_patchNameEditor->setColour (TextEditor::outlineColourId, Colours::grey);
    m_patchNameEditor->setText (String());

    addAndMakeVisible (m_selectKeyLabel = new Label ("selectKeyLabel",
                                                     TRANS("SELECT KEY TO EDIT:")));
    m_selectKeyLabel->setFont (Font (12.00f, Font::bold));
    m_selectKeyLabel->setJustificationType (Justification::centred);
    m_selectKeyLabel->setEditable (false, false, false);
    m_selectKeyLabel->setColour (Label::textColourId, Colours::black);
    m_selectKeyLabel->setColour (TextEditor::textColourId, Colours::black);
    m_selectKeyLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_wave = new WaveEditor ("WAVE", AllParts::PartR, m_currentKey));
    addAndMakeVisible (m_rhyPitchEditor = new RhyPitchEditor ("PITCH", m_currentKey));
    addAndMakeVisible (m_rhyFilterEditor = new RhyFilterEditor ("FILTER", m_currentKey));
    addAndMakeVisible (m_rhyAmpEditor = new RhyAmpEditor ("AMP", m_currentKey));
    addAndMakeVisible (m_rhySetKeyboardWithList = new RhySetKeyboardWithList());
    addAndMakeVisible (m_darkSepRect3 = new RectangleDark());
    addAndMakeVisible (m_mixGrp = new PanelGroupGrey ("mixerGrp","PART R"));
    addAndMakeVisible (m_mixRhyTrack = new MixRhyTrack());
    addAndMakeVisible (imageButton5 = new ImageButton ("new button"));
    imageButton5->setButtonText (String());
    imageButton5->addListener (this);

    imageButton5->setImages (false, true, true,
                             ImageCache::getFromMemory (mixer_png, mixer_pngSize), 1.000f, Colour (0x4340454a),
                             ImageCache::getFromMemory (mixer_png, mixer_pngSize), 1.000f, Colour (0x4340454a),
                             ImageCache::getFromMemory (mixer_png, mixer_pngSize), 1.000f, Colour (0x4340454a));

    //[UserPreSize]
	if (grooveboxMemory != nullptr)
	{
		if (RhythmSetBlock* rhythmSetBlock = grooveboxMemory->getRhythmSetBlock())
		{
			if (RhythmCommonBlock* rhythmCommon = rhythmSetBlock->getRhythmSetCommonBlockPtr())
			{
				m_patchNameEditor->setParameter1(rhythmCommon->getParameter(0x0));
			}
		}
	}
	m_rhySetKeyboardWithList->addChangeListener(this);
    //[/UserPreSize]

    setSize (1328, 675);


    //[Constructor] You can add your own custom stuff here..
    //[/Constructor]
}

RhythmSetEditorTab::~RhythmSetEditorTab()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    m_commonGrp4 = nullptr;
    m_partNoLabel = nullptr;
    m_patchNameLabel = nullptr;
    m_patchNameEditor = nullptr;
    m_selectKeyLabel = nullptr;
    m_wave = nullptr;
    m_rhyPitchEditor = nullptr;
    m_rhyFilterEditor = nullptr;
    m_rhyAmpEditor = nullptr;
    m_rhySetKeyboardWithList = nullptr;
    m_darkSepRect3 = nullptr;
    m_mixGrp = nullptr;
    m_mixRhyTrack = nullptr;
    imageButton5 = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void RhythmSetEditorTab::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
#if JUCE_MSVC
	g;
#endif
    //[/UserPrePaint]

    g.fillAll (Colour (0xff303030));

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void RhythmSetEditorTab::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    m_commonGrp4->setBounds (0, 0, 552, 675);
    m_partNoLabel->setBounds (4, 4, 72, 24);
    m_patchNameLabel->setBounds (88, 4, 120, 24);
    m_patchNameEditor->setBounds (88, 24, 116, 22);
    m_selectKeyLabel->setBounds (228, 30, 140, 24);
    m_wave->setBounds (560, 20, 244, 156);
    m_rhyPitchEditor->setBounds (944, 20, 376, 324);
    m_rhyFilterEditor->setBounds (560, 351, 376, 324);
    m_rhyAmpEditor->setBounds (944, 351, 376, 324);
    m_rhySetKeyboardWithList->setBounds (92, 52, 452, getHeight() - 59);
    m_darkSepRect3->setBounds (0, 100, 84, 575);
    m_mixGrp->setBounds (0, 103, 80, 572);
    m_mixRhyTrack->setBounds (4, 124, 72, 548);
    imageButton5->setBounds (3, 104, 16, 16);
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void RhythmSetEditorTab::buttonClicked (Button* buttonThatWasClicked)
{
    //[UserbuttonClicked_Pre]
    //[/UserbuttonClicked_Pre]

    if (buttonThatWasClicked == imageButton5)
    {
        //[UserButtonCode_imageButton5] -- add your button handler code here..
        //[/UserButtonCode_imageButton5]
    }

    //[UserbuttonClicked_Post]
    //[/UserbuttonClicked_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
void RhythmSetEditorTab::changeListenerCallback(ChangeBroadcaster* source)
{
	if (source == m_rhySetKeyboardWithList)
	{
		int row = m_rhySetKeyboardWithList->getSelectedRow();
		if (row < 64)
		{
			m_currentKey = (uint8)row + 35;
			m_wave->setupParameters(AllParts::PartR, m_currentKey);
			m_rhyPitchEditor->setupParameters(m_currentKey);
			m_rhyFilterEditor->setupParameters(m_currentKey);
			m_rhyAmpEditor->setupParameters(m_currentKey);
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

<JUCER_COMPONENT documentType="Component" className="RhythmSetEditorTab" componentName=""
                 parentClasses="public Component, public ChangeListener" constructorParams=""
                 variableInitialisers="" snapPixels="4" snapActive="1" snapShown="1"
                 overlayOpacity="0.330" fixedSize="1" initialWidth="1328" initialHeight="675">
  <BACKGROUND backgroundColour="ff303030"/>
  <JUCERCOMP name="commonGrp1" id="b95f1f3b55f39c2b" memberName="m_commonGrp4"
             virtualName="" explicitFocusOrder="0" pos="0 0 552 675" sourceFile="GroupWidgets/RectangleGrey.cpp"
             constructorParams=""/>
  <LABEL name="partNoLabel" id="51143029c4acb8f6" memberName="m_partNoLabel"
         virtualName="" explicitFocusOrder="0" pos="4 4 72 24" textCol="ff000000"
         edTextCol="ff000000" edBkgCol="0" labelText="PART R" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="12" bold="1" italic="0" justification="33"/>
  <LABEL name="patchNameLabel" id="2ec0efd8ffa587b" memberName="m_patchNameLabel"
         virtualName="" explicitFocusOrder="0" pos="88 4 120 24" textCol="ff000000"
         edTextCol="ff000000" edBkgCol="0" labelText="RHYTHM SET NAME"
         editableSingleClick="0" editableDoubleClick="0" focusDiscardsChanges="0"
         fontname="Default font" fontsize="12" bold="1" italic="0" justification="33"/>
  <TEXTEDITOR name="patchNameEditor" id="9686a2e1612f5756" memberName="m_patchNameEditor"
              virtualName="ParameterTextEditor" explicitFocusOrder="0" pos="88 24 116 22"
              textcol="ff000000" bkgcol="fff2f59b" outlinecol="ff808080" initialText=""
              multiline="0" retKeyStartsLine="0" readonly="0" scrollbars="0"
              caret="1" popupmenu="1"/>
  <LABEL name="selectKeyLabel" id="95b01f3ab5adc3ba" memberName="m_selectKeyLabel"
         virtualName="" explicitFocusOrder="0" pos="228 30 140 24" textCol="ff000000"
         edTextCol="ff000000" edBkgCol="0" labelText="SELECT KEY TO EDIT:"
         editableSingleClick="0" editableDoubleClick="0" focusDiscardsChanges="0"
         fontname="Default font" fontsize="12" bold="1" italic="0" justification="36"/>
  <JUCERCOMP name="wave" id="18daa831771a006a" memberName="m_wave" virtualName=""
             explicitFocusOrder="0" pos="560 20 244 156" sourceFile="PatchSectionEditors/WaveEditor.cpp"
             constructorParams="&quot;WAVE&quot;, AllParts::PartR, m_currentKey"/>
  <JUCERCOMP name="rhyPitchEditor" id="d20a8b4840ab1ef4" memberName="m_rhyPitchEditor"
             virtualName="" explicitFocusOrder="0" pos="944 20 376 324" sourceFile="RhythmSectionEditors/RhyPitchEditor.cpp"
             constructorParams="&quot;PITCH&quot;, m_currentKey"/>
  <JUCERCOMP name="rhyFilterEditor" id="2ab70c00d446197a" memberName="m_rhyFilterEditor"
             virtualName="" explicitFocusOrder="0" pos="560 351 376 324" sourceFile="RhythmSectionEditors/RhyFilterEditor.cpp"
             constructorParams="&quot;FILTER&quot;, m_currentKey"/>
  <JUCERCOMP name="rhyAmpEditor" id="ace1a038c1b06814" memberName="m_rhyAmpEditor"
             virtualName="" explicitFocusOrder="0" pos="944 351 376 324" sourceFile="RhythmSectionEditors/RhyAmpEditor.cpp"
             constructorParams="&quot;AMP&quot;, m_currentKey"/>
  <JUCERCOMP name="rhySetKeyboardWithList" id="3c1035db3aaf52f0" memberName="m_rhySetKeyboardWithList"
             virtualName="" explicitFocusOrder="0" pos="92 52 452 59M" sourceFile="RhythmSectionEditors/RhySetKeyboardWithList.cpp"
             constructorParams=""/>
  <JUCERCOMP name="" id="7b14f61a14009b5d" memberName="m_darkSepRect3" virtualName=""
             explicitFocusOrder="0" pos="0 100 84 575" posRelativeH="156795e5be1d9d51"
             sourceFile="GroupWidgets/RectangleDark.cpp" constructorParams=""/>
  <JUCERCOMP name="mixGrp" id="46883b20b70a0a85" memberName="m_mixGrp" virtualName=""
             explicitFocusOrder="0" pos="0 103 80 572" sourceFile="GroupWidgets/PanelGroupGrey.cpp"
             constructorParams="&quot;mixerGrp&quot;,&quot;PART R&quot;"/>
  <JUCERCOMP name="mixRhyTrack" id="83fd3ebb8d9abefe" memberName="m_mixRhyTrack"
             virtualName="" explicitFocusOrder="0" pos="4 124 72 548" sourceFile="MixerSectionsEditors/MixRhyTrack.cpp"
             constructorParams=""/>
  <IMAGEBUTTON name="new button" id="941a767f4267791c" memberName="imageButton5"
               virtualName="" explicitFocusOrder="0" pos="3 104 16 16" buttonText=""
               connectedEdges="0" needsCallback="1" radioGroupId="0" keepProportions="1"
               resourceNormal="mixer_png" opacityNormal="1" colourNormal="4340454a"
               resourceOver="mixer_png" opacityOver="1" colourOver="4340454a"
               resourceDown="mixer_png" opacityDown="1" colourDown="4340454a"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif

//==============================================================================
// Binary resources - be careful not to edit any of these sections!

// JUCER_RESOURCE: mixer_png, 237, "../../Resources/PatchEditSectionIcons/mixer.png"
static const unsigned char resource_RhythmSetEditorTab_mixer_png[] = { 137,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,0,16,0,0,0,16,8,6,0,0,0,31,243,255,97,0,0,0,1,115,82,71,66,0,174,206,28,233,0,0,
0,6,98,75,71,68,0,255,0,255,0,255,160,189,167,147,0,0,0,9,112,72,89,115,0,0,11,19,0,0,11,19,1,0,154,156,24,0,0,0,7,116,73,77,69,7,223,1,3,21,23,50,215,208,54,137,0,0,0,109,73,68,65,84,56,203,173,83,65,
14,192,32,8,107,9,255,255,114,119,217,140,58,117,64,70,98,148,3,180,208,74,73,184,163,61,130,65,0,240,174,152,201,6,2,64,43,22,63,12,100,139,174,187,92,221,105,97,85,228,106,131,215,168,182,160,171,15,
228,97,103,254,39,3,78,183,34,254,240,130,246,3,160,5,232,242,100,182,170,140,165,17,122,253,183,42,48,153,195,102,103,101,63,147,175,236,153,217,197,5,106,27,26,44,105,0,198,59,0,0,0,0,73,69,78,68,174,
66,96,130,0,0};

const char* RhythmSetEditorTab::mixer_png = (const char*) resource_RhythmSetEditorTab_mixer_png;
const int RhythmSetEditorTab::mixer_pngSize = 237;


//[EndFile] You can add extra defines here...
//[/EndFile]
