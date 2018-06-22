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

#ifndef __JUCE_HEADER_612DA6871EF2384C__
#define __JUCE_HEADER_612DA6871EF2384C__

//[Headers]     -- You can add your own extra header files here --
#include "JuceHeader.h"
#include "ParameterComboBox.h"
#include "../../GrooveboxMemory/Waveforms.h"
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Introjucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class WaveformSearchComboBox  : public ParameterComboBox
{
public:
    //==============================================================================
    WaveformSearchComboBox (const String& componentName, AllParts part, int toneNumber, bool inTable);
    ~WaveformSearchComboBox();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
	WaveformSearchComboBox(const String& componentName, AllParts part, int toneNumber);
	void setupParameters(AllParts part, int toneNumber, bool calledDuringInit=false); // allowed toneNumber values are Tone1 = 0x1000, Tone2 = 0x1200, Tone3 = 0x1400, Tone4 = 0x1600 for synth parts or 35..98 for rhythm part
	void showPopup() override;
	void setParameter(Parameter* /*param*/) override { return; }
	Parameter* getParamPtr() override { return m_waveNumber; }
	void changeListenerCallback(ChangeBroadcaster *source) override;	// parameter changes of groovebox memory block
	void comboBoxChanged(ComboBox *comboBoxThatHasChanged) override; // gui combobox selection change
	String getTooltip() override { return ""; }
	void labelTextChanged();
	void mouseWheelMove(const MouseEvent& e, const MouseWheelDetails& d) override;
	void mouseDown(const MouseEvent &e) override;
	bool keyPressed(const KeyPress &) override;

    //[/UserMethods]

    void paint (Graphics& g) override;
    void resized() override;



private:
    //[UserVariables]   -- You can add your own custom variables in this section.
	AllParts m_part;
	int m_toneNumber; // allowed values are Tone1 = 0x1000, Tone2 = 0x1200, Tone3 = 0x1400, Tone4 = 0x1600 for synth parts or 35..98 for rhythm part
	Parameter* m_waveGroupType;
	Parameter* m_waveGroupId;
	Parameter* m_waveNumber;
	void populateComboboxItems(bool initAll=false);
	int waveGroupAndNumberToItemId(Waveforms::WaveGroup waveGroup, int waveNumber);
	void itemIdToWaveGroupAndNumber(int id, Waveforms::WaveGroup& waveGroup, int& waveNumber);
	bool m_isInTable = false;
    //[/UserVariables]

    //==============================================================================
    Path internalPath1;
    Path internalPath2;
    Path internalPath3;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (WaveformSearchComboBox)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

#endif   // __JUCE_HEADER_612DA6871EF2384C__
