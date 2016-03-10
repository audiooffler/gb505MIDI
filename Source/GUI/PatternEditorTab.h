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

#ifndef __JUCE_HEADER_211612B4383A29A8__
#define __JUCE_HEADER_211612B4383A29A8__

//[Headers]     -- You can add your own extra header files here --
#include "JuceHeader.h"
#include "ParameterWidgets/MicroParameterSlider.h"
#include "ParameterWidgets/ParameterTextEditor.h"
#include "ParameterWidgets/ParameterComboBox.h"
//[/Headers]

#include "GroupWidgets/PanelGroupGrey.h"
#include "ParameterWidgets/BlackToggle.h"
#include "ParameterWidgets/SmallGreenToggle.h"


//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Introjucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class PatternEditorTab  : public Component,
                          public ChangeListener,
                          public ApplicationCommandTarget,
                          public ComboBoxListener,
                          public ButtonListener,
                          public SliderListener
{
public:
    //==============================================================================
    PatternEditorTab ();
    ~PatternEditorTab();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.

	// handling some parameter changes in pattern setup and refreshed pattern table content
	void changeListenerCallback (ChangeBroadcaster *source) override;

	enum CommandIDs
	{
		createEmptyPattern = 0x20FF,
		fileOpenPattern = 0x2101,
		fileSavePattern = 0x2102,
		fileSavePatternBinFile = 0x2124,
		grooveBoxLoadPattern = 0x3101,
		grooveBoxSendPatternBulk = 0x3102
	};
	// This must return the next target to try after this one.
	ApplicationCommandTarget* getNextCommandTarget() override;
	// This must return a complete list of commands that this target can handle.
	void getAllCommands(Array< CommandID > &commands) override;
	//This must provide details about one of the commands that this target can perform.
	void getCommandInfo(CommandID commandID, ApplicationCommandInfo &result) override;
	// This must actually perform the specified command.
	bool perform(const InvocationInfo &info) override;

	void loadPatternFile();
	void savePatternFile();
	void saveRawBinaryFile();
    //[/UserMethods]

    void paint (Graphics& g) override;
    void resized() override;
    void comboBoxChanged (ComboBox* comboBoxThatHasChanged) override;
    void buttonClicked (Button* buttonThatWasClicked) override;
    void sliderValueChanged (Slider* sliderThatWasMoved) override;



private:
    //[UserVariables]   -- You can add your own custom variables in this section.
	TableHeaderComponent* m_patternEventTableHeader; // will be owed by m_patternEventTable
    //[/UserVariables]

    //==============================================================================
    ScopedPointer<PanelGroupGrey> m_patternPanel;
    ScopedPointer<PanelGroupGrey> m_viewEventTypesPanel;
    ScopedPointer<PanelGroupGrey> m_viewPartsPanel;
    ScopedPointer<PanelGroupGrey> m_midiOutPanel;
    ScopedPointer<ParameterComboBox> m_midiOutComboBox;
    ScopedPointer<TextButton> m_panicButton;
    ScopedPointer<TableListBox> m_patternEventTable;
    ScopedPointer<MicroParameterSlider> m_noteRangeLowerSlider;
    ScopedPointer<MicroParameterSlider> m_noteRangeUpperSlider;
    ScopedPointer<Label> m_fromLabel;
    ScopedPointer<MicroParameterSlider> m_ccRangeLowerSlider;
    ScopedPointer<MicroParameterSlider> m_ccRangeUpperSlider;
    ScopedPointer<MicroParameterSlider> m_PAftRangeLowerSlider;
    ScopedPointer<MicroParameterSlider> m_PAftRangeUpperSlider;
    ScopedPointer<BlackToggle> m_viewPartToggleR;
    ScopedPointer<Label> m_viewPartLabelR;
    ScopedPointer<BlackToggle> m_viewPartToggle1;
    ScopedPointer<Label> m_viewPartLabel1;
    ScopedPointer<BlackToggle> m_viewPartToggle2;
    ScopedPointer<Label> m_viewPartLabel2;
    ScopedPointer<BlackToggle> m_viewPartToggle3;
    ScopedPointer<Label> m_viewPartLabel3;
    ScopedPointer<BlackToggle> m_viewPartToggle4;
    ScopedPointer<Label> m_viewPartLabel4;
    ScopedPointer<BlackToggle> m_viewPartToggle5;
    ScopedPointer<Label> m_viewPartLabel5;
    ScopedPointer<BlackToggle> m_viewPartToggle6;
    ScopedPointer<Label> m_viewPartLabel6;
    ScopedPointer<BlackToggle> m_viewPartToggleMuteCtl;
    ScopedPointer<Label> m_viewPartLabelMuteCtl;
    ScopedPointer<BlackToggle> m_viewTypeToggleNote;
    ScopedPointer<Label> m_viewTypeNoteLabel;
    ScopedPointer<BlackToggle> m_viewTypeTogglePc;
    ScopedPointer<Label> m_viewTypePcLabel;
    ScopedPointer<BlackToggle> m_viewTypeToggleCc;
    ScopedPointer<Label> m_viewTypeCcLabel;
    ScopedPointer<BlackToggle> m_viewTypeToggleBend;
    ScopedPointer<Label> m_viewTypeBendLabel;
    ScopedPointer<BlackToggle> m_viewTypeTogglePAft;
    ScopedPointer<Label> m_viewTypePAftLabel;
    ScopedPointer<BlackToggle> m_viewTypeToggleCAft;
    ScopedPointer<Label> m_viewTypeCAftLabel;
    ScopedPointer<BlackToggle> m_viewTypeToggleTempo;
    ScopedPointer<Label> m_viewTypeTempoLabel;
    ScopedPointer<BlackToggle> m_viewTypeToggleMute;
    ScopedPointer<Label> m_viewTypeMuteLabel;
    ScopedPointer<BlackToggle> m_viewTypeToggleSysEx;
    ScopedPointer<Label> m_viewTypeSysExLabel;
    ScopedPointer<Label> m_toLabel;
    ScopedPointer<Label> m_fromLabel2;
    ScopedPointer<Label> m_toLabel2;
    ScopedPointer<Label> m_fromLabel3;
    ScopedPointer<Label> m_toLabel3;
    ScopedPointer<BlackToggle> m_viewPartToggle7;
    ScopedPointer<Label> m_viewPartLabel7;
    ScopedPointer<TextButton> m_viewAllPartsButton;
    ScopedPointer<TextButton> m_viewNoPartsButton;
    ScopedPointer<TextButton> m_viewAllEventsButton;
    ScopedPointer<TextButton> m_viewNoEventsButton;
    ScopedPointer<SmallGreenToggle> m_viewSinglePartToggle;
    ScopedPointer<Label> m_viewSinglePartLabel;
    ScopedPointer<Label> m_patchNameLabel;
    ScopedPointer<ParameterTextEditor> m_patternNameEditor;
    ScopedPointer<ParameterComboBox> m_keySignatureComboBox;
    ScopedPointer<Label> m_timeSignatureLabel;
    ScopedPointer<Label> m_measuresLabel;
    ScopedPointer<MicroParameterSlider> m_measuresSlider;
    ScopedPointer<MicroParameterSlider> m_tempoSlider;
    ScopedPointer<Label> m_tempoLabel;
    ScopedPointer<Label> m_viewTypeNoteOffLabel;
    ScopedPointer<SmallGreenToggle> m_viewNoteOffToggle;
    ScopedPointer<BlackToggle> m_viewTypeToggleInc;
    ScopedPointer<Label> m_viewTypeIncLabel;
    ScopedPointer<TextButton> m_playButton;
    ScopedPointer<TextButton> m_stopButton;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (PatternEditorTab)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

#endif   // __JUCE_HEADER_211612B4383A29A8__
