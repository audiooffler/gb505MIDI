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

#ifndef __JUCE_HEADER_6C09FC4A8E4119A6__
#define __JUCE_HEADER_6C09FC4A8E4119A6__

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
//[/Headers]

#include "../GroupWidgets/PanelGroupGrey.h"
#include "../ParameterWidgets/BlackToggle.h"
#include "../ParameterWidgets/ParameterLedSwitch.h"
#include "../ParameterWidgets/WaveformSearchComboBox.h"


//==============================================================================
/**
                                                                    //[Comments]
An auto-generated component, created by the Introjucer.

Describe your class and how it works here!
                                                                    //[/Comments]
*/
class RhyWaveEditor  : public Component,
                       public ChangeListener,
                       public ButtonListener,
                       public ComboBoxListener,
                       public SliderListener
{
public:
    //==============================================================================
    RhyWaveEditor (const String &componentName, AllParts part, int toneNumber);
    ~RhyWaveEditor();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
	void setupParameters(AllParts part, int toneNumber); // allowed toneNumber values are Tone1 = 0x1000, Tone2 = 0x1200, Tone3 = 0x1400, Tone4 = 0x1600 for synth parts or 35..98 for rhythm part
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

    void paint (Graphics& g) override;
    void resized() override;
    void buttonClicked (Button* buttonThatWasClicked) override;
    void comboBoxChanged (ComboBox* comboBoxThatHasChanged) override;
    void sliderValueChanged (Slider* sliderThatWasMoved) override;

    // Binary resources:
    static const char* wave_png;
    static const int wave_pngSize;


private:
    //[UserVariables]   -- You can add your own custom variables in this section.
	AllParts m_part;
	int m_toneNumber; // allowed values are Tone1 = 0x1000, Tone2 = 0x1200, Tone3 = 0x1400, Tone4 = 0x1600 for synth parts or 35..98 for rhythm part
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
    ScopedPointer<ParameterLedSwitch> m_envModeToggle;
    ScopedPointer<Label> m_envModeLabel;
    ScopedPointer<MicroParameterSlider> m_muteGrpSlider;
    ScopedPointer<Label> m_muteGrpLabel;
    ScopedPointer<WaveformSearchComboBox> m_waveformSearchComboBox;
    ScopedPointer<Label> label;
    ScopedPointer<Label> m_rhyGroupLabel;
    ScopedPointer<Label> label2;
    ScopedPointer<Label> m_rhyKeyNameLabel;
    ScopedPointer<Label> m_rhyKeyNumLabel;
    ScopedPointer<Label> label3;
    ScopedPointer<Label> m_rhyGmStandardDrumLabel;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (RhyWaveEditor)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

#endif   // __JUCE_HEADER_6C09FC4A8E4119A6__
