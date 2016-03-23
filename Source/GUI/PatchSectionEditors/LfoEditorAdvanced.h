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

#ifndef __JUCE_HEADER_568653666DD60AAC__
#define __JUCE_HEADER_568653666DD60AAC__

//[Headers]     -- You can add your own extra header files here --
#include "JuceHeader.h"
#include "../../GrooveboxMemory/GrooveboxMemoryBlock.h"
#include "../ParameterWidgets/MicroParameterSlider.h"
#include "../ParameterWidgets/ParameterComboBox.h"
#include "../ParameterWidgets/Knob.h"
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
class LfoEditorAdvanced  : public Component,
                           public ChangeListener,
                           public ComboBoxListener,
                           public SliderListener,
                           public ButtonListener
{
public:
    //==============================================================================
    LfoEditorAdvanced (const String &componentName, SynthParts part, Tone tone, bool lfo2);
    ~LfoEditorAdvanced();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    void changeListenerCallback(ChangeBroadcaster *source);	// parameter changes of groovebox memory block
    //[/UserMethods]

    void paint (Graphics& g) override;
    void resized() override;
    void comboBoxChanged (ComboBox* comboBoxThatHasChanged) override;
    void sliderValueChanged (Slider* sliderThatWasMoved) override;
    void buttonClicked (Button* buttonThatWasClicked) override;

    // Binary resources:
    static const char* lfo_png;
    static const int lfo_pngSize;


private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    SynthParts m_part;
    Tone m_tone;
    bool m_lfo2;
	Parameter* m_tempoSyncParam;
    //[/UserVariables]

    //==============================================================================
    ScopedPointer<PanelGroupGrey> m_lfoGrp;
    ScopedPointer<Label> m_waveformLabel;
    ScopedPointer<ParameterComboBox> m_waveformComboBox;
    ScopedPointer<BlackToggle> m_tempoSyncToggle;
    ScopedPointer<Label> m_offsetLabel;
    ScopedPointer<BlackToggle> m_keySyncToggle;
    ScopedPointer<MicroParameterSlider> m_offsetSlider;
    ScopedPointer<Label> m_fadeModeLabel;
    ScopedPointer<ParameterComboBox> m_fadeModeComboBox;
    ScopedPointer<Label> m_delayTimeLabel;
    ScopedPointer<MicroParameterSlider> m_delayTimeSlider;
    ScopedPointer<Label> m_fadeTimeLabel;
    ScopedPointer<Label> m_tempoLabel;
    ScopedPointer<Label> m_keyLabel;
    ScopedPointer<Knob> m_rateSlider;
    ScopedPointer<Label> m_rateLabel;
    ScopedPointer<Knob> m_fadeTimeSlider;
    ScopedPointer<Label> m_line;
    ScopedPointer<Knob> m_pitchSlider;
    ScopedPointer<Label> m_pitchLabel;
    ScopedPointer<Knob> m_filterSlider;
    ScopedPointer<Label> m_filterLabel;
    ScopedPointer<Knob> m_ampSlider;
    ScopedPointer<Label> m_ampLabel;
    ScopedPointer<Knob> m_panSlider;
    ScopedPointer<Label> m_panLabel;
    ScopedPointer<ImageButton> m_imageButton;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (LfoEditorAdvanced)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

#endif   // __JUCE_HEADER_568653666DD60AAC__
