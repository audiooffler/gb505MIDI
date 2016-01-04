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

#ifndef __JUCE_HEADER_FF59C9425E920774__
#define __JUCE_HEADER_FF59C9425E920774__

//[Headers]     -- You can add your own extra header files here --
#include "JuceHeader.h"
#include "../../GrooveboxMemory/GrooveboxMemoryBlock.h"
#include "../ParameterWidgets/MicroParameterSlider.h"
#include "../ParameterWidgets/ParameterComboBox.h"
#include "../ParameterWidgets/Knob.h"
#include "../ParameterWidgets/KeyfollowMicroParameterSlider.h"
#include "../ParameterWidgets/ParameterEnvelopeSlider.h"
#include "../ParameterWidgets/ParameterVelCurveDisplay.h"
#include "../ParameterWidgets/TextWithArrowButton.h"
#include "LfoEditorAdvanced.h"
//[/Headers]

#include "../GroupWidgets/PanelGroupGrey.h"
#include "../ParameterWidgets/BlackToggle.h"


//==============================================================================
/**
                                                                    //[Comments]
An auto-generated component, created by the Introjucer.

Describe your class and how it works here!
                                                                    //[/Comments]
*/
class WaveEditor  : public Component,
                    public ChangeListener,
                    public ButtonListener,
                    public ComboBoxListener
{
public:
    //==============================================================================
    WaveEditor (const String &componentName, SynthParts part, Tone tone);
    ~WaveEditor();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
	void changeListenerCallback(ChangeBroadcaster *source);	// parameter changes of groovebox memory block
	class WaveFormDlgCallback : public ModalComponentManager::Callback
	{
	public:
		void modalStateFinished(int returnValue);
		int m_restorable32BitIntForWaveformDuringBrowserDialog;
		void setWaveformSelectParameters(Parameter* groupType, Parameter* groupId, Parameter* waveIndexInGroup)
		{
			m_groupType = groupType;
			m_groupId = groupId;
			m_waveIndexInGroup = waveIndexInGroup;
		}
	private:
		Parameter* m_groupType;
		Parameter* m_groupId;
		Parameter* m_waveIndexInGroup;
	};
    //[/UserMethods]

    void paint (Graphics& g);
    void resized();
    void buttonClicked (Button* buttonThatWasClicked);
    void comboBoxChanged (ComboBox* comboBoxThatHasChanged);

    // Binary resources:
    static const char* wave_png;
    static const int wave_pngSize;


private:
    //[UserVariables]   -- You can add your own custom variables in this section.
	SynthParts m_part;
	Tone m_tone;
	Parameter* m_waveGroupType;
	Parameter* m_waveGroupId;
	Parameter* m_waveNumber;
    //[/UserVariables]

    //==============================================================================
    ScopedPointer<PanelGroupGrey> m_fxmGrp;
    ScopedPointer<ImageButton> m_imageButton;
    ScopedPointer<TextButton> m_waveButton;
    ScopedPointer<Label> m_waveLabel;
    ScopedPointer<Label> m_onLabel2;
    ScopedPointer<BlackToggle> m_onToggle;
    ScopedPointer<Label> m_onLabel;
    ScopedPointer<ParameterComboBox> m_waveGainComboBox;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (WaveEditor)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

#endif   // __JUCE_HEADER_FF59C9425E920774__
