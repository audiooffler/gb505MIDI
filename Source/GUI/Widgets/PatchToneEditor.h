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

#ifndef __JUCE_HEADER_556DD75D784668D6__
#define __JUCE_HEADER_556DD75D784668D6__

//[Headers]     -- You can add your own extra header files here --
#include "JuceHeader.h"
#include "../../GrooveboxMemory/GrooveboxMemoryBlock.h"
#include "ParameterComboBox.h"
//[/Headers]

#include "PanelGroupGrey.h"
#include "Envelope.h"
#include "BlackToggle.h"


//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Introjucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class PatchToneEditor  : public Component,
                         public ChangeListener,
                         public ButtonListener,
                         public SliderListener,
                         public ComboBoxListener
{
public:
    //==============================================================================
    PatchToneEditor (const String& labelText, SynthParts part, Tone tone);
    ~PatchToneEditor();

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
    void sliderValueChanged (Slider* sliderThatWasMoved);
    void comboBoxChanged (ComboBox* comboBoxThatHasChanged);



private:
    //[UserVariables]   -- You can add your own custom variables in this section.
	SynthParts m_part;
	Tone m_tone;
	Parameter* m_waveGroupType;
	Parameter* m_waveGroupId;
	Parameter* m_waveNumber;
    //[/UserVariables]

    //==============================================================================
    ScopedPointer<PanelGroupGrey> m_toneGrp;
    ScopedPointer<Envelope> m_pitchEnv;
    ScopedPointer<Envelope> m_filterEnv;
    ScopedPointer<Envelope> m_ampEnv;
    ScopedPointer<BlackToggle> m_onToggle;
    ScopedPointer<Label> m_onLabel;
    ScopedPointer<TextButton> m_waveButton;
    ScopedPointer<Label> m_waveLabel;
    ScopedPointer<PanelGroupGrey> m_fxmGrp;
    ScopedPointer<BlackToggle> m_fxmToggle;
    ScopedPointer<Label> m_fxmOnLabel;
    ScopedPointer<MicroParameterSlider> m_fxmColorSlider;
    ScopedPointer<Label> m_fxmColorLabel;
    ScopedPointer<MicroParameterSlider> m_fxmDepthSlider;
    ScopedPointer<Label> m_fxmDepthLabel;
    ScopedPointer<PanelGroupGrey> m_controllersGrp;
    ScopedPointer<Label> m_modulationLabel;
    ScopedPointer<ParameterComboBox> m_modDestComboBox1;
    ScopedPointer<ParameterComboBox> m_modDestComboBox2;
    ScopedPointer<ParameterComboBox> m_modDestComboBox3;
    ScopedPointer<ParameterComboBox> m_modDestComboBox4;
    ScopedPointer<Label> m_pitchbendLabel;
    ScopedPointer<Label> m_aftertouchLabel;
    ScopedPointer<MicroParameterSlider> m_modDestSlider1;
    ScopedPointer<MicroParameterSlider> m_modDestSlider2;
    ScopedPointer<MicroParameterSlider> m_modDestSlider3;
    ScopedPointer<MicroParameterSlider> m_modDestSlider4;
    ScopedPointer<ParameterComboBox> m_pitchbendDestComboBox1;
    ScopedPointer<MicroParameterSlider> m_pitchbendDestSlider1;
    ScopedPointer<ParameterComboBox> m_pitchbendDestComboBox2;
    ScopedPointer<MicroParameterSlider> m_pitchbendDestSlider2;
    ScopedPointer<ParameterComboBox> m_pitchbendDestComboBox3;
    ScopedPointer<MicroParameterSlider> m_pitchbendDestSlider3;
    ScopedPointer<ParameterComboBox> m_pitchbendDestComboBox4;
    ScopedPointer<MicroParameterSlider> m_pitchbendDestSlider4;
    ScopedPointer<ParameterComboBox> m_aftertouchDestComboBox1;
    ScopedPointer<MicroParameterSlider> m_aftertouchDestSlider1;
    ScopedPointer<ParameterComboBox> m_aftertouchDestComboBox2;
    ScopedPointer<MicroParameterSlider> m_aftertouchDestSlider2;
    ScopedPointer<ParameterComboBox> m_aftertouchDestComboBox3;
    ScopedPointer<MicroParameterSlider> m_aftertouchDestSlider3;
    ScopedPointer<ParameterComboBox> m_aftertouchDestComboBox4;
    ScopedPointer<MicroParameterSlider> m_aftertouchDestSlider4;
    ScopedPointer<Label> m_onLabel2;
    ScopedPointer<MicroParameterSlider> m_waveGainSlider;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (PatchToneEditor)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

#endif   // __JUCE_HEADER_556DD75D784668D6__
