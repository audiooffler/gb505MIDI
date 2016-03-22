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

#ifndef __JUCE_HEADER_98A9EFBF46ECAA68__
#define __JUCE_HEADER_98A9EFBF46ECAA68__

//[Headers]     -- You can add your own extra header files here --
#include "JuceHeader.h"
#include "../../GrooveboxMemory/Waveforms.h"
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    Broadcasts a change event on selection
                                                                    //[/Comments]
*/
class RhySetKeyboardWithList  : public Component,
                                public TableListBoxModel,
                                public ChangeListener,
                                public ChangeBroadcaster
{
public:
    //==============================================================================
    RhySetKeyboardWithList ();
    ~RhySetKeyboardWithList();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
	int /*TableListBoxModel::*/getNumRows() override;
	void /*TableListBoxModel::*/paintRowBackground(Graphics& g, int rowNumber, int width, int height, bool rowIsSelected) override;
	void /*TableListBoxModel::*/paintCell(Graphics& g, int rowNumber, int columnId, int width, int height, bool rowIsSelected) override;
	void /*TableListBoxModel::*/selectedRowsChanged(int lastRowSelected) override;
	enum drumNamesTableColumnIds
	{
		NoteName = 1,
		KeyNo = 2,
		RhyGrp = 3,
		MuteGrp = 4,
		RhyWave = 5,
		GmDrum = 6
	};
	void changeListenerCallback(ChangeBroadcaster* source) override;
	int getSelectedRow() { return m_lastRowSelected; }
    //[/UserMethods]

    void paint (Graphics& g) override;
    void resized() override;



private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    MidiKeyboardState m_keyboardStateDummy;
	TableHeaderComponent* m_tableHeader;
	int m_lastRowSelected = 0;
    //[/UserVariables]

    //==============================================================================
    ScopedPointer<TableListBox> m_drumNamesTable;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (RhySetKeyboardWithList)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

#endif   // __JUCE_HEADER_98A9EFBF46ECAA68__
