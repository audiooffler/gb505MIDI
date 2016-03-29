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

    addAndMakeVisible (m_wave = new RhyWaveEditor ("WAVE", AllParts::PartR, m_currentKey));
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
    addAndMakeVisible (m_rhyFxSendEditor = new RhyFxSendEditor ("FX", m_currentKey));
    addAndMakeVisible (m_partNoLabel = new ImageButton ("partNoLabel"));
    m_partNoLabel->setButtonText (TRANS("new button"));
    m_partNoLabel->addListener (this);

    m_partNoLabel->setImages (false, true, true,
                              ImageCache::getFromMemory (partNameR_png, partNameR_pngSize), 1.000f, Colours::white,
                              Image(), 1.000f, Colour (0x00000000),
                              Image(), 1.000f, Colour (0x00000000));

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
    m_rhyFxSendEditor = nullptr;
    m_partNoLabel = nullptr;


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

    m_commonGrp4->setBounds (0, 0, 654, 675);
    m_patchNameLabel->setBounds (88, 4, 120, 24);
    m_patchNameEditor->setBounds (88, 24, 116, 22);
    m_selectKeyLabel->setBounds (228, 30, 140, 24);
    m_wave->setBounds (656, 4, 244, 332);
    m_rhyPitchEditor->setBounds (656, 340, 334, 334);
    m_rhyFilterEditor->setBounds (992, 340, 336, 334);
    m_rhyAmpEditor->setBounds (904, 4, 336, 332);
    m_rhySetKeyboardWithList->setBounds (88, 52, 562, getHeight() - 59);
    m_darkSepRect3->setBounds (0, 100, 84, 575);
    m_mixGrp->setBounds (0, 103, 80, 572);
    m_mixRhyTrack->setBounds (4, 124, 72, 548);
    imageButton5->setBounds (3, 104, 16, 16);
    m_rhyFxSendEditor->setBounds (1244, 4, 84, 332);
    m_partNoLabel->setBounds (40 - (24 / 2), 25, 24, 18);
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
    else if (buttonThatWasClicked == m_partNoLabel)
    {
        //[UserButtonCode_m_partNoLabel] -- add your button handler code here..
        //[/UserButtonCode_m_partNoLabel]
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
		uint8 key = (uint8)row + 35;
		if (key >= 35 && key <= 98)
		{
			m_currentKey = (uint8)key;
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
             virtualName="" explicitFocusOrder="0" pos="0 0 654 675" sourceFile="GroupWidgets/RectangleGrey.cpp"
             constructorParams=""/>
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
             explicitFocusOrder="0" pos="656 4 244 332" sourceFile="RhythmSectionEditors/RhyWaveEditor.cpp"
             constructorParams="&quot;WAVE&quot;, AllParts::PartR, m_currentKey"/>
  <JUCERCOMP name="rhyPitchEditor" id="d20a8b4840ab1ef4" memberName="m_rhyPitchEditor"
             virtualName="" explicitFocusOrder="0" pos="656 340 334 334" sourceFile="RhythmSectionEditors/RhyPitchEditor.cpp"
             constructorParams="&quot;PITCH&quot;, m_currentKey"/>
  <JUCERCOMP name="rhyFilterEditor" id="2ab70c00d446197a" memberName="m_rhyFilterEditor"
             virtualName="" explicitFocusOrder="0" pos="992 340 336 334" sourceFile="RhythmSectionEditors/RhyFilterEditor.cpp"
             constructorParams="&quot;FILTER&quot;, m_currentKey"/>
  <JUCERCOMP name="rhyAmpEditor" id="ace1a038c1b06814" memberName="m_rhyAmpEditor"
             virtualName="" explicitFocusOrder="0" pos="904 4 336 332" sourceFile="RhythmSectionEditors/RhyAmpEditor.cpp"
             constructorParams="&quot;AMP&quot;, m_currentKey"/>
  <JUCERCOMP name="rhySetKeyboardWithList" id="3c1035db3aaf52f0" memberName="m_rhySetKeyboardWithList"
             virtualName="" explicitFocusOrder="0" pos="88 52 562 59M" sourceFile="RhythmSectionEditors/RhySetKeyboardWithList.cpp"
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
  <JUCERCOMP name="" id="490b911b10d37175" memberName="m_rhyFxSendEditor"
             virtualName="" explicitFocusOrder="0" pos="1244 4 84 332" sourceFile="RhythmSectionEditors/RhyFxSendEditor.cpp"
             constructorParams="&quot;FX&quot;, m_currentKey"/>
  <IMAGEBUTTON name="partNoLabel" id="168089c13a9f22fd" memberName="m_partNoLabel"
               virtualName="" explicitFocusOrder="0" pos="40c 25 24 18" buttonText="new button"
               connectedEdges="0" needsCallback="1" radioGroupId="0" keepProportions="1"
               resourceNormal="partNameR_png" opacityNormal="1" colourNormal="ffffffff"
               resourceOver="" opacityOver="1" colourOver="0" resourceDown=""
               opacityDown="1" colourDown="0"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif

//==============================================================================
// Binary resources - be careful not to edit any of these sections!

// JUCER_RESOURCE: partNameR_png, 423, "../../Resources/LookAndFeel/PartNameR.png"
static const unsigned char resource_RhythmSetEditorTab_partNameR_png[] = { 137,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,0,32,0,0,0,24,8,6,0,0,0,155,83,255,52,0,0,0,4,115,66,73,84,8,8,8,8,124,8,100,
136,0,0,0,9,112,72,89,115,0,0,22,38,0,0,22,38,1,228,235,5,157,0,0,0,25,116,69,88,116,83,111,102,116,119,97,114,101,0,119,119,119,46,105,110,107,115,99,97,112,101,46,111,114,103,155,238,60,26,0,0,1,36,
73,68,65,84,72,137,197,150,177,74,3,65,16,134,191,145,32,146,202,70,20,69,44,196,74,176,21,76,227,59,248,58,118,62,128,47,144,7,200,67,104,43,168,96,21,2,86,166,73,117,22,41,36,141,226,111,225,94,216,
93,60,171,219,217,129,225,152,127,224,230,191,153,217,255,214,36,81,211,6,0,102,246,12,28,22,172,211,0,15,192,181,164,38,201,132,14,204,1,57,248,2,216,145,68,235,27,133,190,184,203,246,129,155,24,24,132,
231,12,88,22,42,122,6,88,20,95,38,217,184,29,37,28,24,147,142,97,233,61,130,143,255,146,222,59,0,191,93,112,37,176,149,197,175,113,208,234,192,4,216,43,68,96,148,197,119,73,228,172,3,247,192,176,166,14,
220,74,90,197,128,73,194,204,230,192,81,132,127,3,159,61,20,220,36,213,128,21,112,46,105,186,70,58,70,48,233,73,3,14,128,247,236,221,99,183,17,72,90,144,47,29,92,153,217,186,43,30,59,240,148,197,219,192,
105,77,2,16,29,77,15,2,47,192,87,53,2,225,216,77,51,248,194,141,64,176,124,12,199,102,182,235,73,224,241,15,108,228,73,160,115,17,219,27,81,67,250,215,234,251,118,52,3,222,128,97,132,157,64,144,226,154,
246,3,162,3,35,71,135,173,101,129,0,0,0,0,73,69,78,68,174,66,96,130,0,0};

const char* RhythmSetEditorTab::partNameR_png = (const char*) resource_RhythmSetEditorTab_partNameR_png;
const int RhythmSetEditorTab::partNameR_pngSize = 423;

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
