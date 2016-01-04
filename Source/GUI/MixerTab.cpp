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
#include "../GrooveboxMemory/OverallMemoryBlock.h"
#include "../GrooveboxMemory/QuickSysExBlock.h"
//[/Headers]

#include "MixerTab.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...

extern OverallMemoryBlock* grooveboxMemory;
extern QuickSysExBlock* quickSysEx;

//[/MiscUserDefs]

//==============================================================================
MixerTab::MixerTab ()
{
    addAndMakeVisible (m_mixerGroup = new PanelGroupDark ("partMixGrp","PART MIXER"));
    addAndMakeVisible (component2 = new RectangleGrey());
    addAndMakeVisible (component9 = new RectangleGrey());
    addAndMakeVisible (m_blackStripePartNames = new RectangleDark());
    addAndMakeVisible (m_labelBD = new Label ("labelBD",
                                              "BD"));
    m_labelBD->setFont (Font (12.00f, Font::bold));
    m_labelBD->setJustificationType (Justification::centred);
    m_labelBD->setEditable (false, false, false);
    m_labelBD->setColour (Label::textColourId, Colours::white);
    m_labelBD->setColour (TextEditor::textColourId, Colours::black);
    m_labelBD->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_labelSD = new Label ("labelSD",
                                              "SD"));
    m_labelSD->setFont (Font (12.00f, Font::bold));
    m_labelSD->setJustificationType (Justification::centred);
    m_labelSD->setEditable (false, false, false);
    m_labelSD->setColour (Label::textColourId, Colours::white);
    m_labelSD->setColour (TextEditor::textColourId, Colours::black);
    m_labelSD->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_labelHH = new Label ("labelHH",
                                              "HH"));
    m_labelHH->setFont (Font (12.00f, Font::bold));
    m_labelHH->setJustificationType (Justification::centred);
    m_labelHH->setEditable (false, false, false);
    m_labelHH->setColour (Label::textColourId, Colours::white);
    m_labelHH->setColour (TextEditor::textColourId, Colours::black);
    m_labelHH->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_labelCLP = new Label ("labelCLP",
                                               "CLP"));
    m_labelCLP->setFont (Font (12.00f, Font::bold));
    m_labelCLP->setJustificationType (Justification::centred);
    m_labelCLP->setEditable (false, false, false);
    m_labelCLP->setColour (Label::textColourId, Colours::white);
    m_labelCLP->setColour (TextEditor::textColourId, Colours::black);
    m_labelCLP->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_labelCYM = new Label ("labelCYM",
                                               "CYM"));
    m_labelCYM->setFont (Font (12.00f, Font::bold));
    m_labelCYM->setJustificationType (Justification::centred);
    m_labelCYM->setEditable (false, false, false);
    m_labelCYM->setColour (Label::textColourId, Colours::white);
    m_labelCYM->setColour (TextEditor::textColourId, Colours::black);
    m_labelCYM->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_labelTOMPERC = new Label ("labelTOMPERC",
                                                   "TOM/PERC"));
    m_labelTOMPERC->setFont (Font (12.00f, Font::bold));
    m_labelTOMPERC->setJustificationType (Justification::centred);
    m_labelTOMPERC->setEditable (false, false, false);
    m_labelTOMPERC->setColour (Label::textColourId, Colours::white);
    m_labelTOMPERC->setColour (TextEditor::textColourId, Colours::black);
    m_labelTOMPERC->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_labelHIT = new Label ("labelHIT",
                                               "HIT"));
    m_labelHIT->setFont (Font (12.00f, Font::bold));
    m_labelHIT->setJustificationType (Justification::centred);
    m_labelHIT->setEditable (false, false, false);
    m_labelHIT->setColour (Label::textColourId, Colours::white);
    m_labelHIT->setColour (TextEditor::textColourId, Colours::black);
    m_labelHIT->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_labelOTHERS = new Label ("labelOTHERS",
                                                  "OTHERS"));
    m_labelOTHERS->setFont (Font (12.00f, Font::bold));
    m_labelOTHERS->setJustificationType (Justification::centred);
    m_labelOTHERS->setEditable (false, false, false);
    m_labelOTHERS->setColour (Label::textColourId, Colours::white);
    m_labelOTHERS->setColour (TextEditor::textColourId, Colours::black);
    m_labelOTHERS->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_MixPartR = new MixRhyTrack (AllParts::PartR));
    addAndMakeVisible (m_MixPart1 = new MixPartTrack (AllParts::Part1));
    addAndMakeVisible (m_MixPart2 = new MixPartTrack (AllParts::Part2));
    addAndMakeVisible (m_MixPart3 = new MixPartTrack (AllParts::Part3));
    addAndMakeVisible (m_MixPart4 = new MixPartTrack (AllParts::Part4));
    addAndMakeVisible (m_MixPart5 = new MixPartTrack (AllParts::Part5));
    addAndMakeVisible (m_MixPart6 = new MixPartTrack (AllParts::Part6));
    addAndMakeVisible (m_MixPart7 = new MixPartTrack (AllParts::Part7));
    addAndMakeVisible (m_panLabel = new Label ("panLabel",
                                               "PAN"));
    m_panLabel->setFont (Font (12.00f, Font::bold));
    m_panLabel->setJustificationType (Justification::centredRight);
    m_panLabel->setEditable (false, false, false);
    m_panLabel->setColour (Label::textColourId, Colours::white);
    m_panLabel->setColour (TextEditor::textColourId, Colours::black);
    m_panLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_levelLabel = new Label ("levelLabel",
                                                 "LEVEL"));
    m_levelLabel->setFont (Font (12.00f, Font::bold));
    m_levelLabel->setJustificationType (Justification::centredRight);
    m_levelLabel->setEditable (false, false, false);
    m_levelLabel->setColour (Label::textColourId, Colours::white);
    m_levelLabel->setColour (TextEditor::textColourId, Colours::black);
    m_levelLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_panLabel2 = new Label ("panLabel",
                                                "MUTE"));
    m_panLabel2->setFont (Font (12.00f, Font::bold));
    m_panLabel2->setJustificationType (Justification::centredRight);
    m_panLabel2->setEditable (false, false, false);
    m_panLabel2->setColour (Label::textColourId, Colours::white);
    m_panLabel2->setColour (TextEditor::textColourId, Colours::black);
    m_panLabel2->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_keyShiftLabel = new Label ("keyShift",
                                                    "KEY\n"
                                                    "SHIFT"));
    m_keyShiftLabel->setFont (Font (12.00f, Font::bold));
    m_keyShiftLabel->setJustificationType (Justification::centredRight);
    m_keyShiftLabel->setEditable (false, false, false);
    m_keyShiftLabel->setColour (Label::textColourId, Colours::white);
    m_keyShiftLabel->setColour (TextEditor::textColourId, Colours::black);
    m_keyShiftLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_reverbLabel = new Label ("reverbLabel",
                                                  "REV DLY\n"
                                                  "SENDS"));
    m_reverbLabel->setFont (Font (12.00f, Font::bold));
    m_reverbLabel->setJustificationType (Justification::centredRight);
    m_reverbLabel->setEditable (false, false, false);
    m_reverbLabel->setColour (Label::textColourId, Colours::white);
    m_reverbLabel->setColour (TextEditor::textColourId, Colours::black);
    m_reverbLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_mFxLabel = new Label ("reverbLabel",
                                               "M-FX"));
    m_mFxLabel->setFont (Font (12.00f, Font::bold));
    m_mFxLabel->setJustificationType (Justification::centredRight);
    m_mFxLabel->setEditable (false, false, false);
    m_mFxLabel->setColour (Label::textColourId, Colours::white);
    m_mFxLabel->setColour (TextEditor::textColourId, Colours::black);
    m_mFxLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_toggleBD = new BigGreenToggle());
    addAndMakeVisible (m_toggleSD = new BigGreenToggle());
    addAndMakeVisible (m_toggleHH = new BigGreenToggle());
    addAndMakeVisible (m_toggleCLP = new BigGreenToggle());
    addAndMakeVisible (m_toggleCYM = new BigGreenToggle());
    addAndMakeVisible (m_toggleTOMPERC = new BigGreenToggle());
    addAndMakeVisible (m_toggleHIT = new BigGreenToggle());
    addAndMakeVisible (m_toggleOTHERS = new BigGreenToggle());
    addAndMakeVisible (m_darkSepRect1 = new RectangleDark());
    addAndMakeVisible (m_darkSepRect2 = new RectangleDark());
    addAndMakeVisible (m_darkSepRect3 = new RectangleDark());
    addAndMakeVisible (m_darkSepRect4 = new RectangleDark());
    addAndMakeVisible (m_darkSepRect5 = new RectangleDark());
    addAndMakeVisible (m_darkSepRect6 = new RectangleDark());
    addAndMakeVisible (m_darkSepRect7 = new RectangleDark());
    addAndMakeVisible (m_darkSepRect8 = new RectangleDark());

    //[UserPreSize]
	if (QuickSysExSequencerBlock* s = quickSysEx->getQuickSysExSequencerBlock())
	{
		m_toggleBD->setParameter(s->getParameter(RhythmGroup::BD));
		m_toggleSD->setParameter(s->getParameter(RhythmGroup::SD));
		m_toggleHH->setParameter(s->getParameter(RhythmGroup::HH));
		m_toggleCLP->setParameter(s->getParameter(RhythmGroup::CLP));
		m_toggleCYM->setParameter(s->getParameter(RhythmGroup::CYM));
		m_toggleTOMPERC->setParameter(s->getParameter(RhythmGroup::TOM_PERC));
		m_toggleHIT->setParameter(s->getParameter(RhythmGroup::HIT));
		m_toggleOTHERS->setParameter(s->getParameter(RhythmGroup::OTHERS));
	}
    //[/UserPreSize]

    setSize (600, 400);


    //[Constructor] You can add your own custom stuff here..
    //[/Constructor]
}

MixerTab::~MixerTab()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    m_mixerGroup = nullptr;
    component2 = nullptr;
    component9 = nullptr;
    m_blackStripePartNames = nullptr;
    m_labelBD = nullptr;
    m_labelSD = nullptr;
    m_labelHH = nullptr;
    m_labelCLP = nullptr;
    m_labelCYM = nullptr;
    m_labelTOMPERC = nullptr;
    m_labelHIT = nullptr;
    m_labelOTHERS = nullptr;
    m_MixPartR = nullptr;
    m_MixPart1 = nullptr;
    m_MixPart2 = nullptr;
    m_MixPart3 = nullptr;
    m_MixPart4 = nullptr;
    m_MixPart5 = nullptr;
    m_MixPart6 = nullptr;
    m_MixPart7 = nullptr;
    m_panLabel = nullptr;
    m_levelLabel = nullptr;
    m_panLabel2 = nullptr;
    m_keyShiftLabel = nullptr;
    m_reverbLabel = nullptr;
    m_mFxLabel = nullptr;
    m_toggleBD = nullptr;
    m_toggleSD = nullptr;
    m_toggleHH = nullptr;
    m_toggleCLP = nullptr;
    m_toggleCYM = nullptr;
    m_toggleTOMPERC = nullptr;
    m_toggleHIT = nullptr;
    m_toggleOTHERS = nullptr;
    m_darkSepRect1 = nullptr;
    m_darkSepRect2 = nullptr;
    m_darkSepRect3 = nullptr;
    m_darkSepRect4 = nullptr;
    m_darkSepRect5 = nullptr;
    m_darkSepRect6 = nullptr;
    m_darkSepRect7 = nullptr;
    m_darkSepRect8 = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void MixerTab::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    Component::paint(g);
    //[/UserPrePaint]

    g.fillAll (Colour (0xffb1afaf));

    g.setGradientFill (ColourGradient (Colour (0xffcdcccc),
                                       120.0f, 248.0f,
                                       Colour (0xff979797),
                                       224.0f, 720.0f,
                                       false));
    g.fillRect (0, 0, getWidth() - 0, getHeight() - 0);

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void MixerTab::resized()
{
    m_mixerGroup->setBounds (0, 0, 668, 504);
    component2->setBounds (60, 24, 604, 476);
    component9->setBounds (60, 440, 604, 60);
    m_blackStripePartNames->setBounds (132, 440, 532, 4);
    m_labelBD->setBounds (60, 448, 71, 20);
    m_labelSD->setBounds (136, 448, 72, 20);
    m_labelHH->setBounds (212, 448, 72, 20);
    m_labelCLP->setBounds (288, 448, 72, 20);
    m_labelCYM->setBounds (364, 448, 72, 20);
    m_labelTOMPERC->setBounds (440, 448, 72, 20);
    m_labelHIT->setBounds (516, 448, 72, 20);
    m_labelOTHERS->setBounds (592, 448, 72, 20);
    m_MixPartR->setBounds (60, 24, 72, 416);
    m_MixPart1->setBounds (136, 24, 72, 416);
    m_MixPart2->setBounds (212, 24, 72, 416);
    m_MixPart3->setBounds (288, 24, 72, 416);
    m_MixPart4->setBounds (364, 24, 72, 416);
    m_MixPart5->setBounds (440, 24, 72, 416);
    m_MixPart6->setBounds (516, 24, 72, 416);
    m_MixPart7->setBounds (592, 24, 72, 416);
    m_panLabel->setBounds (0, 136, 56, 48);
    m_levelLabel->setBounds (0, 184, 56, 192);
    m_panLabel2->setBounds (0, 408, 56, 72);
    m_keyShiftLabel->setBounds (0, 108, 56, 24);
    m_reverbLabel->setBounds (-4, 28, 60, 32);
    m_mFxLabel->setBounds (-8, 72, 64, 32);
    m_toggleBD->setBounds (80, 468, 31, 27);
    m_toggleSD->setBounds (156, 468, 31, 27);
    m_toggleHH->setBounds (232, 468, 31, 27);
    m_toggleCLP->setBounds (308, 468, 31, 27);
    m_toggleCYM->setBounds (384, 468, 31, 27);
    m_toggleTOMPERC->setBounds (460, 468, 31, 27);
    m_toggleHIT->setBounds (536, 468, 31, 27);
    m_toggleOTHERS->setBounds (612, 468, 31, 27);
    m_darkSepRect1->setBounds (132, 24, 4, (416) - 0);
    m_darkSepRect2->setBounds (208, 24, 4, (416) - 0);
    m_darkSepRect3->setBounds (284, 24, 4, (416) - 0);
    m_darkSepRect4->setBounds (360, 24, 4, (416) - 0);
    m_darkSepRect5->setBounds (436, 24, 4, (416) - 0);
    m_darkSepRect6->setBounds (512, 24, 4, (416) - 0);
    m_darkSepRect7->setBounds (588, 24, 4, (416) - 0);
    m_darkSepRect8->setBounds ((136) + -4, (24) + (416) - -4 - 4, 536, 4);
    //[UserResized] Add your own custom resize handling here..
    Component::resized();
    //[/UserResized]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Introjucer information section --

    This is where the Introjucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="MixerTab" componentName=""
                 parentClasses="public Component" constructorParams="" variableInitialisers=""
                 snapPixels="4" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="0" initialWidth="600" initialHeight="400">
  <BACKGROUND backgroundColour="ffb1afaf">
    <RECT pos="0 0 0M 0M" fill="linear: 120 248, 224 720, 0=ffcdcccc, 1=ff979797"
          hasStroke="0"/>
  </BACKGROUND>
  <JUCERCOMP name="" id="d78f1e5774ca8458" memberName="m_mixerGroup" virtualName=""
             explicitFocusOrder="0" pos="0 0 668 504" sourceFile="GroupWidgets/PanelGroupDark.cpp"
             constructorParams="&quot;partMixGrp&quot;,&quot;PART MIXER&quot;"/>
  <JUCERCOMP name="" id="e14c4fa2a949f949" memberName="component2" virtualName=""
             explicitFocusOrder="0" pos="60 24 604 476" sourceFile="GroupWidgets/RectangleGrey.cpp"
             constructorParams=""/>
  <JUCERCOMP name="" id="774804a2ff473afa" memberName="component9" virtualName=""
             explicitFocusOrder="0" pos="60 440 604 60" sourceFile="GroupWidgets/RectangleGrey.cpp"
             constructorParams=""/>
  <JUCERCOMP name="" id="7847d426b3778105" memberName="m_blackStripePartNames"
             virtualName="" explicitFocusOrder="0" pos="132 440 532 4" sourceFile="GroupWidgets/RectangleDark.cpp"
             constructorParams=""/>
  <LABEL name="labelBD" id="c0d4aaf48f2e8a91" memberName="m_labelBD" virtualName=""
         explicitFocusOrder="0" pos="60 448 71 20" textCol="ffffffff"
         edTextCol="ff000000" edBkgCol="0" labelText="BD" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="12" bold="1" italic="0" justification="36"/>
  <LABEL name="labelSD" id="334a7978723dda88" memberName="m_labelSD" virtualName=""
         explicitFocusOrder="0" pos="136 448 72 20" textCol="ffffffff"
         edTextCol="ff000000" edBkgCol="0" labelText="SD" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="12" bold="1" italic="0" justification="36"/>
  <LABEL name="labelHH" id="d5330474f55352b1" memberName="m_labelHH" virtualName=""
         explicitFocusOrder="0" pos="212 448 72 20" textCol="ffffffff"
         edTextCol="ff000000" edBkgCol="0" labelText="HH" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="12" bold="1" italic="0" justification="36"/>
  <LABEL name="labelCLP" id="9be8ef3ea8ba86fc" memberName="m_labelCLP"
         virtualName="" explicitFocusOrder="0" pos="288 448 72 20" textCol="ffffffff"
         edTextCol="ff000000" edBkgCol="0" labelText="CLP" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="12" bold="1" italic="0" justification="36"/>
  <LABEL name="labelCYM" id="5d882c3577085443" memberName="m_labelCYM"
         virtualName="" explicitFocusOrder="0" pos="364 448 72 20" textCol="ffffffff"
         edTextCol="ff000000" edBkgCol="0" labelText="CYM" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="12" bold="1" italic="0" justification="36"/>
  <LABEL name="labelTOMPERC" id="9ef35206c0a6da32" memberName="m_labelTOMPERC"
         virtualName="" explicitFocusOrder="0" pos="440 448 72 20" textCol="ffffffff"
         edTextCol="ff000000" edBkgCol="0" labelText="TOM/PERC" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="12" bold="1" italic="0" justification="36"/>
  <LABEL name="labelHIT" id="9469ea515dac4f19" memberName="m_labelHIT"
         virtualName="" explicitFocusOrder="0" pos="516 448 72 20" textCol="ffffffff"
         edTextCol="ff000000" edBkgCol="0" labelText="HIT" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="12" bold="1" italic="0" justification="36"/>
  <LABEL name="labelOTHERS" id="b2e2868c6a2abd03" memberName="m_labelOTHERS"
         virtualName="" explicitFocusOrder="0" pos="592 448 72 20" textCol="ffffffff"
         edTextCol="ff000000" edBkgCol="0" labelText="OTHERS" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="12" bold="1" italic="0" justification="36"/>
  <JUCERCOMP name="" id="83fd3ebb8d9abefe" memberName="m_MixPartR" virtualName=""
             explicitFocusOrder="0" pos="60 24 72 416" sourceFile="MixerSectionsEditors/MixRhyTrack.cpp"
             constructorParams="AllParts::PartR"/>
  <JUCERCOMP name="" id="156795e5be1d9d51" memberName="m_MixPart1" virtualName=""
             explicitFocusOrder="0" pos="136 24 72 416" sourceFile="MixerSectionsEditors/MixPartTrack.cpp"
             constructorParams="AllParts::Part1"/>
  <JUCERCOMP name="" id="f33cd4fc656357ea" memberName="m_MixPart2" virtualName=""
             explicitFocusOrder="0" pos="212 24 72 416" sourceFile="MixerSectionsEditors/MixPartTrack.cpp"
             constructorParams="AllParts::Part2"/>
  <JUCERCOMP name="" id="823c0a7ac0f938f9" memberName="m_MixPart3" virtualName=""
             explicitFocusOrder="0" pos="288 24 72 416" sourceFile="MixerSectionsEditors/MixPartTrack.cpp"
             constructorParams="AllParts::Part3"/>
  <JUCERCOMP name="" id="8767896e8751884f" memberName="m_MixPart4" virtualName=""
             explicitFocusOrder="0" pos="364 24 72 416" sourceFile="MixerSectionsEditors/MixPartTrack.cpp"
             constructorParams="AllParts::Part4"/>
  <JUCERCOMP name="" id="a6071b0c55a79fd5" memberName="m_MixPart5" virtualName=""
             explicitFocusOrder="0" pos="440 24 72 416" sourceFile="MixerSectionsEditors/MixPartTrack.cpp"
             constructorParams="AllParts::Part5"/>
  <JUCERCOMP name="" id="479168b76adef9d" memberName="m_MixPart6" virtualName=""
             explicitFocusOrder="0" pos="516 24 72 416" sourceFile="MixerSectionsEditors/MixPartTrack.cpp"
             constructorParams="AllParts::Part6"/>
  <JUCERCOMP name="" id="ed229350a70faf33" memberName="m_MixPart7" virtualName=""
             explicitFocusOrder="0" pos="592 24 72 416" sourceFile="MixerSectionsEditors/MixPartTrack.cpp"
             constructorParams="AllParts::Part7"/>
  <LABEL name="panLabel" id="ed38016865dd30d8" memberName="m_panLabel"
         virtualName="" explicitFocusOrder="0" pos="0 136 56 48" textCol="ffffffff"
         edTextCol="ff000000" edBkgCol="0" labelText="PAN" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="12" bold="1" italic="0" justification="34"/>
  <LABEL name="levelLabel" id="4de070007710033a" memberName="m_levelLabel"
         virtualName="" explicitFocusOrder="0" pos="0 184 56 192" textCol="ffffffff"
         edTextCol="ff000000" edBkgCol="0" labelText="LEVEL" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="12" bold="1" italic="0" justification="34"/>
  <LABEL name="panLabel" id="23443e2ef9174f81" memberName="m_panLabel2"
         virtualName="" explicitFocusOrder="0" pos="0 408 56 72" textCol="ffffffff"
         edTextCol="ff000000" edBkgCol="0" labelText="MUTE" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="12" bold="1" italic="0" justification="34"/>
  <LABEL name="keyShift" id="d6ccdb805c997011" memberName="m_keyShiftLabel"
         virtualName="" explicitFocusOrder="0" pos="0 108 56 24" textCol="ffffffff"
         edTextCol="ff000000" edBkgCol="0" labelText="KEY&#10;SHIFT" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="12" bold="1" italic="0" justification="34"/>
  <LABEL name="reverbLabel" id="440467d4712aa20" memberName="m_reverbLabel"
         virtualName="" explicitFocusOrder="0" pos="-4 28 60 32" textCol="ffffffff"
         edTextCol="ff000000" edBkgCol="0" labelText="REV DLY&#10;SENDS"
         editableSingleClick="0" editableDoubleClick="0" focusDiscardsChanges="0"
         fontname="Default font" fontsize="12" bold="1" italic="0" justification="34"/>
  <LABEL name="reverbLabel" id="fd0f7b7681452bfd" memberName="m_mFxLabel"
         virtualName="" explicitFocusOrder="0" pos="-8 72 64 32" textCol="ffffffff"
         edTextCol="ff000000" edBkgCol="0" labelText="M-FX" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="12" bold="1" italic="0" justification="34"/>
  <JUCERCOMP name="toggleBD" id="64b544053d530afc" memberName="m_toggleBD"
             virtualName="" explicitFocusOrder="0" pos="80 468 31 27" sourceFile="ParameterWidgets/BigGreenToggle.cpp"
             constructorParams=""/>
  <JUCERCOMP name="toggleSD" id="908a8bc326de0c3" memberName="m_toggleSD"
             virtualName="" explicitFocusOrder="0" pos="156 468 31 27" sourceFile="ParameterWidgets/BigGreenToggle.cpp"
             constructorParams=""/>
  <JUCERCOMP name="toggleHH" id="138c01d5348cc45c" memberName="m_toggleHH"
             virtualName="" explicitFocusOrder="0" pos="232 468 31 27" sourceFile="ParameterWidgets/BigGreenToggle.cpp"
             constructorParams=""/>
  <JUCERCOMP name="toggleCLP" id="96c607149f8f920d" memberName="m_toggleCLP"
             virtualName="" explicitFocusOrder="0" pos="308 468 31 27" sourceFile="ParameterWidgets/BigGreenToggle.cpp"
             constructorParams=""/>
  <JUCERCOMP name="toggleCYM" id="10910759dc54046b" memberName="m_toggleCYM"
             virtualName="" explicitFocusOrder="0" pos="384 468 31 27" sourceFile="ParameterWidgets/BigGreenToggle.cpp"
             constructorParams=""/>
  <JUCERCOMP name="toggleTOMPERC" id="5ad0f74af50bac33" memberName="m_toggleTOMPERC"
             virtualName="" explicitFocusOrder="0" pos="460 468 31 27" sourceFile="ParameterWidgets/BigGreenToggle.cpp"
             constructorParams=""/>
  <JUCERCOMP name="toggleHIT" id="e7f0f449c90695f2" memberName="m_toggleHIT"
             virtualName="" explicitFocusOrder="0" pos="536 468 31 27" sourceFile="ParameterWidgets/BigGreenToggle.cpp"
             constructorParams=""/>
  <JUCERCOMP name="toggleTOMPERC" id="ee75aa8cb42083be" memberName="m_toggleOTHERS"
             virtualName="" explicitFocusOrder="0" pos="612 468 31 27" sourceFile="ParameterWidgets/BigGreenToggle.cpp"
             constructorParams=""/>
  <JUCERCOMP name="" id="51afc631a0bcf51b" memberName="m_darkSepRect1" virtualName=""
             explicitFocusOrder="0" pos="132 24 4 0M" posRelativeH="156795e5be1d9d51"
             sourceFile="GroupWidgets/RectangleDark.cpp" constructorParams=""/>
  <JUCERCOMP name="" id="6c6ee884dfae1577" memberName="m_darkSepRect2" virtualName=""
             explicitFocusOrder="0" pos="208 24 4 0M" posRelativeH="156795e5be1d9d51"
             sourceFile="GroupWidgets/RectangleDark.cpp" constructorParams=""/>
  <JUCERCOMP name="" id="77b4980e551944b" memberName="m_darkSepRect3" virtualName=""
             explicitFocusOrder="0" pos="284 24 4 0M" posRelativeH="156795e5be1d9d51"
             sourceFile="GroupWidgets/RectangleDark.cpp" constructorParams=""/>
  <JUCERCOMP name="" id="d6b032252490b451" memberName="m_darkSepRect4" virtualName=""
             explicitFocusOrder="0" pos="360 24 4 0M" posRelativeH="156795e5be1d9d51"
             sourceFile="GroupWidgets/RectangleDark.cpp" constructorParams=""/>
  <JUCERCOMP name="" id="545c2762874df9aa" memberName="m_darkSepRect5" virtualName=""
             explicitFocusOrder="0" pos="436 24 4 0M" posRelativeH="156795e5be1d9d51"
             sourceFile="GroupWidgets/RectangleDark.cpp" constructorParams=""/>
  <JUCERCOMP name="" id="7ce9749e8dc44007" memberName="m_darkSepRect6" virtualName=""
             explicitFocusOrder="0" pos="512 24 4 0M" posRelativeH="156795e5be1d9d51"
             sourceFile="GroupWidgets/RectangleDark.cpp" constructorParams=""/>
  <JUCERCOMP name="" id="f004f120f1909e38" memberName="m_darkSepRect7" virtualName=""
             explicitFocusOrder="0" pos="588 24 4 0M" posRelativeH="156795e5be1d9d51"
             sourceFile="GroupWidgets/RectangleDark.cpp" constructorParams=""/>
  <JUCERCOMP name="" id="f0a137b00e3e6f03" memberName="m_darkSepRect8" virtualName=""
             explicitFocusOrder="0" pos="-4 -4Rr 536 4" posRelativeX="156795e5be1d9d51"
             posRelativeY="156795e5be1d9d51" sourceFile="GroupWidgets/RectangleDark.cpp"
             constructorParams=""/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif

//==============================================================================
// Binary resources - be careful not to edit any of these sections!

// JUCER_RESOURCE: partNameR_png, 423, "../../Resources/LookAndFeel/PartNameR.png"
static const unsigned char resource_MixerTab_partNameR_png[] = { 137,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,0,32,0,0,0,24,8,6,0,0,0,155,83,255,52,0,0,0,4,115,66,73,84,8,8,8,8,124,8,100,136,0,0,
0,9,112,72,89,115,0,0,22,38,0,0,22,38,1,228,235,5,157,0,0,0,25,116,69,88,116,83,111,102,116,119,97,114,101,0,119,119,119,46,105,110,107,115,99,97,112,101,46,111,114,103,155,238,60,26,0,0,1,36,73,68,65,
84,72,137,197,150,177,74,3,65,16,134,191,145,32,146,202,70,20,69,44,196,74,176,21,76,227,59,248,58,118,62,128,47,144,7,200,67,104,43,168,96,21,2,86,166,73,117,22,41,36,141,226,111,225,94,216,93,60,171,
219,217,129,225,152,127,224,230,191,153,217,255,214,36,81,211,6,0,102,246,12,28,22,172,211,0,15,192,181,164,38,201,132,14,204,1,57,248,2,216,145,68,235,27,133,190,184,203,246,129,155,24,24,132,231,12,
88,22,42,122,6,88,20,95,38,217,184,29,37,28,24,147,142,97,233,61,130,143,255,146,222,59,0,191,93,112,37,176,149,197,175,113,208,234,192,4,216,43,68,96,148,197,119,73,228,172,3,247,192,176,166,14,220,74,
90,197,128,73,194,204,230,192,81,132,127,3,159,61,20,220,36,213,128,21,112,46,105,186,70,58,70,48,233,73,3,14,128,247,236,221,99,183,17,72,90,144,47,29,92,153,217,186,43,30,59,240,148,197,219,192,105,
77,2,16,29,77,15,2,47,192,87,53,2,225,216,77,51,248,194,141,64,176,124,12,199,102,182,235,73,224,241,15,108,228,73,160,115,17,219,27,81,67,250,215,234,251,118,52,3,222,128,97,132,157,64,144,226,154,246,
3,162,3,35,71,135,173,101,129,0,0,0,0,73,69,78,68,174,66,96,130,0,0};

const char* MixerTab::partNameR_png = (const char*) resource_MixerTab_partNameR_png;
const int MixerTab::partNameR_pngSize = 423;

// JUCER_RESOURCE: partName1_png, 277, "../../Resources/LookAndFeel/PartName1.png"
static const unsigned char resource_MixerTab_partName1_png[] = { 137,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,0,32,0,0,0,24,8,6,0,0,0,155,83,255,52,0,0,0,4,115,66,73,84,8,8,8,8,124,8,100,136,0,0,
0,9,112,72,89,115,0,0,22,37,0,0,22,37,1,73,82,36,240,0,0,0,25,116,69,88,116,83,111,102,116,119,97,114,101,0,119,119,119,46,105,110,107,115,99,97,112,101,46,111,114,103,155,238,60,26,0,0,0,146,73,68,65,
84,72,137,237,150,177,13,194,64,16,4,119,44,18,18,122,113,19,36,36,46,1,209,16,237,184,21,58,112,104,68,224,192,193,146,162,7,89,127,24,225,228,86,218,228,239,247,52,186,251,224,177,173,45,213,68,46,3,
39,96,44,60,0,61,112,252,138,192,118,181,37,117,146,188,224,75,164,159,237,216,4,42,116,5,246,145,64,20,224,33,233,246,226,169,168,31,36,181,161,142,209,145,21,43,57,235,125,13,221,63,87,48,174,204,255,
252,13,36,64,2,36,64,2,36,64,2,36,64,88,187,149,249,89,210,253,195,89,181,216,250,91,254,4,124,118,180,26,84,31,31,91,0,0,0,0,73,69,78,68,174,66,96,130,0,0};

const char* MixerTab::partName1_png = (const char*) resource_MixerTab_partName1_png;
const int MixerTab::partName1_pngSize = 277;

// JUCER_RESOURCE: partName2_png, 409, "../../Resources/LookAndFeel/PartName2.png"
static const unsigned char resource_MixerTab_partName2_png[] = { 137,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,0,32,0,0,0,24,8,6,0,0,0,155,83,255,52,0,0,0,4,115,66,73,84,8,8,8,8,124,8,100,136,0,0,
0,9,112,72,89,115,0,0,22,37,0,0,22,37,1,73,82,36,240,0,0,0,25,116,69,88,116,83,111,102,116,119,97,114,101,0,119,119,119,46,105,110,107,115,99,97,112,101,46,111,114,103,155,238,60,26,0,0,1,22,73,68,65,
84,72,137,237,150,61,74,4,65,16,133,191,146,49,16,19,3,67,17,76,252,9,22,204,141,68,188,132,23,240,14,38,130,39,216,208,251,24,154,8,70,30,97,65,97,127,96,117,69,121,38,219,90,211,179,51,8,110,109,39,
62,40,168,174,154,225,189,238,106,30,109,146,40,137,42,37,102,214,3,238,130,120,38,192,61,112,35,233,161,214,145,196,252,20,142,1,5,199,59,112,154,56,37,177,22,180,227,54,172,3,183,190,80,185,252,13,120,
10,32,221,5,54,220,122,223,204,182,37,61,3,63,35,136,10,224,146,230,40,14,87,57,130,81,87,115,213,119,160,136,128,205,174,102,149,23,204,236,28,184,0,14,88,142,192,163,5,181,193,119,150,93,152,107,226,
189,224,177,198,153,25,209,103,48,249,12,56,241,2,252,8,206,104,30,249,199,92,212,95,145,172,248,42,183,98,47,96,103,193,79,123,146,94,150,32,160,21,126,199,150,245,166,209,228,185,128,34,248,23,208,48,
34,7,51,179,173,32,222,153,164,87,160,230,3,125,226,77,40,69,191,212,131,164,129,226,2,252,29,152,2,67,183,86,75,222,213,251,237,119,227,148,88,233,103,249,23,187,55,44,190,136,109,213,126,0,0,0,0,73,
69,78,68,174,66,96,130,0,0};

const char* MixerTab::partName2_png = (const char*) resource_MixerTab_partName2_png;
const int MixerTab::partName2_pngSize = 409;

// JUCER_RESOURCE: partName3_png, 434, "../../Resources/LookAndFeel/PartName3.png"
static const unsigned char resource_MixerTab_partName3_png[] = { 137,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,0,32,0,0,0,24,8,6,0,0,0,155,83,255,52,0,0,0,4,115,66,73,84,8,8,8,8,124,8,100,136,0,0,
0,9,112,72,89,115,0,0,22,37,0,0,22,37,1,73,82,36,240,0,0,0,25,116,69,88,116,83,111,102,116,119,97,114,101,0,119,119,119,46,105,110,107,115,99,97,112,101,46,111,114,103,155,238,60,26,0,0,1,47,73,68,65,
84,72,137,197,150,177,74,67,65,16,69,207,104,2,242,72,175,8,162,85,10,171,124,66,90,11,75,59,191,192,239,16,191,197,90,172,237,197,34,144,202,144,70,65,11,177,87,76,148,107,145,236,203,188,37,70,133,236,
238,133,229,237,221,89,152,251,102,103,103,199,36,81,18,173,48,49,179,61,224,46,145,159,119,96,8,156,75,106,250,144,196,60,10,7,128,18,143,41,112,20,124,74,202,46,64,192,51,96,193,111,125,4,192,39,240,
248,223,216,254,1,219,192,150,227,187,64,23,24,1,139,8,164,26,192,201,146,40,244,131,125,35,193,31,199,120,93,101,204,33,96,25,166,57,5,84,17,255,0,6,129,248,36,196,204,46,129,157,53,11,56,140,248,149,
164,183,154,69,9,243,64,218,43,120,3,84,222,103,238,28,168,128,182,95,48,255,22,152,217,61,176,63,167,138,190,63,205,127,179,119,128,77,183,126,45,233,120,177,43,125,29,56,165,121,12,19,160,147,243,8,
158,34,222,6,122,129,148,170,3,245,237,43,37,160,70,113,1,190,33,105,49,203,216,117,163,183,210,234,178,181,79,158,126,64,64,183,84,33,130,217,173,24,7,146,91,192,23,112,38,87,253,252,99,52,1,94,18,57,
14,77,233,133,164,91,111,104,148,226,18,248,6,2,197,124,75,53,239,143,19,0,0,0,0,73,69,78,68,174,66,96,130,0,0};

const char* MixerTab::partName3_png = (const char*) resource_MixerTab_partName3_png;
const int MixerTab::partName3_pngSize = 434;

// JUCER_RESOURCE: partName4_png, 500, "../../Resources/LookAndFeel/PartName4.png"
static const unsigned char resource_MixerTab_partName4_png[] = { 137,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,0,32,0,0,0,24,8,6,0,0,0,155,83,255,52,0,0,0,4,115,66,73,84,8,8,8,8,124,8,100,136,0,0,
0,9,112,72,89,115,0,0,22,37,0,0,22,37,1,73,82,36,240,0,0,0,25,116,69,88,116,83,111,102,116,119,97,114,101,0,119,119,119,46,105,110,107,115,99,97,112,101,46,111,114,103,155,238,60,26,0,0,1,113,73,68,65,
84,72,137,197,214,61,107,84,65,20,198,241,223,217,40,6,69,27,11,83,164,144,96,145,74,196,66,17,84,240,35,72,154,84,105,98,151,62,164,79,138,52,126,2,209,210,66,193,214,82,73,105,33,136,173,111,77,32,118,
18,2,9,104,56,41,118,179,108,54,59,215,205,102,146,125,96,154,123,102,230,249,115,159,115,103,110,100,166,113,234,66,237,13,35,98,2,207,176,140,43,13,83,31,102,230,55,153,89,109,224,9,190,32,135,24,179,
153,169,150,241,12,222,53,152,109,158,9,0,174,98,29,123,5,227,239,120,138,249,170,0,104,97,17,91,5,227,237,78,15,92,234,204,175,7,128,71,248,92,48,222,199,11,220,232,91,115,122,0,220,196,155,134,156,63,
226,78,97,237,232,0,218,159,210,26,118,11,198,63,48,247,159,61,78,14,128,192,66,161,131,15,115,94,57,204,185,42,0,30,224,83,67,206,175,48,117,130,248,134,3,192,20,94,55,228,188,129,187,35,52,110,17,160,
123,20,71,196,52,62,224,150,227,250,133,229,204,124,59,160,118,42,245,222,5,47,7,152,239,104,31,52,207,51,115,175,182,121,23,32,34,38,241,184,175,246,23,183,51,243,231,89,24,31,1,192,101,76,246,213,46,
226,125,68,252,169,224,115,189,88,233,105,148,175,134,187,197,106,141,217,204,212,234,97,89,210,126,237,231,170,110,19,102,230,70,68,220,199,42,238,225,90,69,159,150,118,164,199,53,202,109,88,243,28,104,
13,164,58,71,141,29,160,250,79,105,65,187,248,221,247,236,31,68,39,163,177,233,0,184,89,0,200,207,212,58,6,0,0,0,0,73,69,78,68,174,66,96,130,0,0};

const char* MixerTab::partName4_png = (const char*) resource_MixerTab_partName4_png;
const int MixerTab::partName4_pngSize = 500;

// JUCER_RESOURCE: partName5_png, 381, "../../Resources/LookAndFeel/PartName5.png"
static const unsigned char resource_MixerTab_partName5_png[] = { 137,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,0,32,0,0,0,24,8,6,0,0,0,155,83,255,52,0,0,0,4,115,66,73,84,8,8,8,8,124,8,100,136,0,0,
0,9,112,72,89,115,0,0,22,37,0,0,22,37,1,73,82,36,240,0,0,0,25,116,69,88,116,83,111,102,116,119,97,114,101,0,119,119,119,46,105,110,107,115,99,97,112,101,46,111,114,103,155,238,60,26,0,0,0,250,73,68,65,
84,72,137,237,149,61,106,66,65,20,133,191,27,148,4,69,176,75,21,200,10,130,157,11,176,183,118,35,238,193,210,210,141,184,133,144,42,144,144,29,8,162,8,138,141,60,94,115,172,70,238,27,30,166,121,243,166,
241,192,129,185,247,22,231,48,63,103,76,18,57,209,241,133,153,237,128,151,212,162,146,134,181,6,128,33,240,156,218,128,199,83,155,98,117,136,119,32,198,17,56,36,117,32,233,70,160,0,228,184,240,243,20,
204,126,4,15,3,230,131,200,204,10,170,207,112,11,108,26,208,41,129,95,96,37,233,175,50,249,231,18,54,205,2,152,86,52,91,54,32,96,7,244,130,102,156,3,41,162,120,0,244,92,253,10,140,128,79,136,130,72,210,
123,195,226,152,217,24,248,138,218,111,97,209,198,43,216,215,244,172,77,3,119,241,48,112,187,132,102,214,5,250,9,52,62,238,78,93,6,204,72,159,1,129,147,156,191,225,5,248,14,69,14,3,115,73,167,80,248,32,
42,129,115,34,209,18,248,1,150,146,214,126,80,249,13,115,224,10,104,94,253,44,227,37,218,84,0,0,0,0,73,69,78,68,174,66,96,130,0,0};

const char* MixerTab::partName5_png = (const char*) resource_MixerTab_partName5_png;
const int MixerTab::partName5_pngSize = 381;

// JUCER_RESOURCE: partName6_png, 415, "../../Resources/LookAndFeel/PartName6.png"
static const unsigned char resource_MixerTab_partName6_png[] = { 137,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,0,32,0,0,0,24,8,6,0,0,0,155,83,255,52,0,0,0,4,115,66,73,84,8,8,8,8,124,8,100,136,0,0,
0,9,112,72,89,115,0,0,22,37,0,0,22,37,1,73,82,36,240,0,0,0,25,116,69,88,116,83,111,102,116,119,97,114,101,0,119,119,119,46,105,110,107,115,99,97,112,101,46,111,114,103,155,238,60,26,0,0,1,28,73,68,65,
84,72,137,237,150,49,74,3,65,20,134,191,151,136,120,133,128,160,160,136,88,229,0,1,27,207,33,228,6,30,67,11,43,107,59,15,18,75,15,32,66,8,73,99,33,88,6,2,129,196,223,98,217,245,237,24,119,149,205,204,
54,254,48,176,59,111,225,251,153,159,121,251,76,18,109,106,39,220,48,179,33,112,9,156,0,221,72,220,129,164,9,0,146,138,5,220,2,74,176,78,11,166,131,247,129,143,212,6,124,4,231,128,5,71,53,7,22,127,59,
221,95,105,149,63,120,3,189,13,31,30,73,122,143,96,160,80,167,170,24,27,94,107,32,133,90,55,240,173,15,120,153,217,104,75,156,21,240,2,60,72,122,42,85,220,53,188,38,254,245,91,3,87,190,247,164,142,160,
3,220,152,217,113,190,81,25,1,176,220,2,180,27,112,118,129,11,96,82,107,64,210,94,83,186,153,237,3,179,128,117,144,63,68,143,64,210,43,89,246,37,95,201,12,212,233,223,64,93,35,58,3,166,13,25,135,85,28,
95,120,219,80,127,110,8,255,73,5,203,71,48,34,235,86,177,37,224,241,235,45,253,72,118,231,153,22,78,197,145,134,210,53,48,38,251,25,221,151,120,109,143,229,159,210,85,221,16,190,19,24,212,0,0,0,0,73,69,
78,68,174,66,96,130,0,0};

const char* MixerTab::partName6_png = (const char*) resource_MixerTab_partName6_png;
const int MixerTab::partName6_pngSize = 415;

// JUCER_RESOURCE: partName7_png, 458, "../../Resources/LookAndFeel/PartName7.png"
static const unsigned char resource_MixerTab_partName7_png[] = { 137,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,0,32,0,0,0,24,8,6,0,0,0,155,83,255,52,0,0,0,4,115,66,73,84,8,8,8,8,124,8,100,136,0,0,
0,9,112,72,89,115,0,0,22,37,0,0,22,37,1,73,82,36,240,0,0,0,25,116,69,88,116,83,111,102,116,119,97,114,101,0,119,119,119,46,105,110,107,115,99,97,112,101,46,111,114,103,155,238,60,26,0,0,1,71,73,68,65,
84,72,137,197,214,189,74,3,65,20,134,225,119,76,48,8,74,10,33,130,164,241,2,86,47,64,44,98,101,165,224,53,88,218,26,82,230,30,82,166,81,11,27,193,75,176,209,164,10,22,90,217,136,118,22,118,177,240,7,115,
44,76,66,126,206,236,238,236,238,172,7,6,134,101,230,60,31,203,97,89,35,34,252,103,21,71,27,99,76,0,220,228,228,238,136,200,195,84,0,160,0,148,115,10,80,24,109,22,114,2,173,53,249,6,62,128,199,140,251,
175,3,43,202,243,159,241,78,68,188,44,96,11,120,7,100,102,93,76,157,243,132,175,1,47,10,222,3,150,188,6,0,74,64,87,193,95,129,234,220,121,15,1,206,21,252,19,216,86,207,103,140,55,20,92,128,35,235,157,
12,241,3,96,160,224,173,208,123,25,225,155,64,95,193,175,129,162,215,0,64,197,50,241,79,192,106,228,253,148,120,9,232,40,120,31,8,98,245,72,25,224,76,193,7,192,97,236,30,41,240,186,101,226,155,78,125,
18,226,251,195,239,249,44,126,5,24,175,1,128,192,50,241,247,192,178,115,63,71,188,2,60,43,248,27,176,145,232,109,58,224,139,192,173,130,127,3,181,196,179,228,16,224,212,50,116,199,73,241,216,1,128,19,
11,222,78,131,139,200,223,196,134,149,49,102,23,184,100,226,63,110,88,119,192,158,136,124,133,54,136,168,200,0,190,235,23,170,109,86,234,6,19,168,208,0,0,0,0,73,69,78,68,174,66,96,130,0,0};

const char* MixerTab::partName7_png = (const char*) resource_MixerTab_partName7_png;
const int MixerTab::partName7_pngSize = 458;


//[EndFile] You can add extra defines here...
//[/EndFile]
