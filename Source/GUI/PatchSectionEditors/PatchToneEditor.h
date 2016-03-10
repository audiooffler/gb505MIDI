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

#ifndef __JUCE_HEADER_556DD75D784668D6__
#define __JUCE_HEADER_556DD75D784668D6__

//[Headers]     -- You can add your own extra header files here --
#include "JuceHeader.h"
#include "../../GrooveboxMemory/GrooveboxMemoryBlock.h"
#include "../ParameterWidgets/ParameterComboBox.h"
#include "../ParameterWidgets/TextWithArrowButton.h"
#include "../ParameterWidgets/ParameterEnvelopeSlider.h"
#include "../ParameterWidgets/KeyfollowMicroParameterSlider.h"
//[/Headers]

#include "../GroupWidgets/PanelGroupGrey.h"
#include "Envelope.h"
#include "../ParameterWidgets/BlackToggle.h"
#include "LfoEditor.h"
#include "../GroupWidgets/RectangleTransp.h"


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
    PatchToneEditor (SynthParts part, Tone tone);
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

    void paint (Graphics& g) override;
    void resized() override;
    void buttonClicked (Button* buttonThatWasClicked) override;
    void sliderValueChanged (Slider* sliderThatWasMoved) override;
    void comboBoxChanged (ComboBox* comboBoxThatHasChanged) override;

    // Binary resources:
    static const char* wave_png;
    static const int wave_pngSize;
    static const char* pitch_png;
    static const int pitch_pngSize;
    static const char* filter_png;
    static const int filter_pngSize;
    static const char* amp_png;
    static const int amp_pngSize;


private:
    //[UserVariables]   -- You can add your own custom variables in this section.
	SynthParts m_part;
	Tone m_tone;
	Parameter* m_waveGroupType;
	Parameter* m_waveGroupId;
	Parameter* m_waveNumber;
    //[/UserVariables]

    //==============================================================================
    ScopedPointer<PanelGroupGrey> m_ampGrp;
    ScopedPointer<PanelGroupGrey> m_filterGrp;
    ScopedPointer<Envelope> m_filterEnv;
    ScopedPointer<PanelGroupGrey> m_pitchGrp;
    ScopedPointer<PanelGroupGrey> m_waveGrp;
    ScopedPointer<Envelope> m_pitchEnv;
    ScopedPointer<Envelope> m_ampEnv;
    ScopedPointer<BlackToggle> m_onToggle;
    ScopedPointer<Label> m_onLabel;
    ScopedPointer<TextButton> m_waveButton;
    ScopedPointer<Label> m_waveLabel;
    ScopedPointer<Label> m_onLabel2;
    ScopedPointer<LfoEditor> m_lfo1;
    ScopedPointer<LfoEditor> m_lfo2;
    ScopedPointer<TextWithArrowButton> m_controlMatrixButton;
    ScopedPointer<MicroParameterSlider> m_coarseTuneSlider;
    ScopedPointer<MicroParameterSlider> m_fineTuneSlider;
    ScopedPointer<Label> m_coarseTuneLabel;
    ScopedPointer<Label> m_fineTuneLabel;
    ScopedPointer<MicroParameterSlider> m_pitchEnvelopeDepthSlider;
    ScopedPointer<Label> m_pitchEnvelopeDepthLabel;
    ScopedPointer<TextWithArrowButton> m_pitchAdvancedButton;
    ScopedPointer<MicroParameterSlider> m_filterEnvelopeDepthSlider;
    ScopedPointer<Label> m_filterEnvelopeDepthLabel;
    ScopedPointer<TextWithArrowButton> m_filterAdvancedButton;
    ScopedPointer<MicroParameterSlider> m_cutoffSlider;
    ScopedPointer<Label> m_cutoffLabel;
    ScopedPointer<Label> m_resonanceLabel;
    ScopedPointer<Label> m_filterTypeLabel;
    ScopedPointer<ParameterComboBox> m_filterTypeComboBox;
    ScopedPointer<MicroParameterSlider> m_resonanceSlider;
    ScopedPointer<TextWithArrowButton> m_ampAdvancedButton;
    ScopedPointer<MixPartLevelFader> m_toneLevelSlider;
    ScopedPointer<Label> m_toneLevelLabel;
    ScopedPointer<MicroParameterSlider> m_tonePanSlider;
    ScopedPointer<Label> m_tonePanLabel;
    ScopedPointer<TextWithArrowButton> m_fxmAdvancedButton;
    ScopedPointer<ImageButton> imageButton;
    ScopedPointer<ImageButton> imageButton4;
    ScopedPointer<ImageButton> imageButton5;
    ScopedPointer<ImageButton> imageButton6;
    ScopedPointer<TextWithArrowButton> m_delayAdvancedButton;
    ScopedPointer<ParameterComboBox> m_waveGainComboBox;
    ScopedPointer<RectangleTransp> component;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (PatchToneEditor)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

#endif   // __JUCE_HEADER_556DD75D784668D6__
