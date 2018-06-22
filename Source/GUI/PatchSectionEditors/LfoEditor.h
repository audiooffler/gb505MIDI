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

#ifndef __JUCE_HEADER_616DC4BDDC00A548__
#define __JUCE_HEADER_616DC4BDDC00A548__

//[Headers]     -- You can add your own extra header files here --
#include "JuceHeader.h"
#include "../../GrooveboxMemory/GrooveboxMemoryBlock.h"
#include "../ParameterWidgets/MicroParameterSlider.h"
#include "../ParameterWidgets/ParameterComboBox.h"
#include "../ParameterWidgets/TextWithArrowButton.h"
//[/Headers]

#include "../GroupWidgets/PanelGroupTransp.h"


//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Introjucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class LfoEditor  : public Component,
                   public ChangeListener,
                   public ComboBox::Listener,
                   public Slider::Listener,
                   public Button::Listener
{
public:
    //==============================================================================
    LfoEditor (const String &componentName, SynthParts part, Tone tone, bool lfo2);
    ~LfoEditor();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    void changeListenerCallback(ChangeBroadcaster *source) override;	// parameter changes of groovebox memory block
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
	Parameter* m_tempoSync;
    //[/UserVariables]

    //==============================================================================
    ScopedPointer<PanelGroupGrey> m_lfoGrp;
    ScopedPointer<Label> m_waveformLabel;
    ScopedPointer<ParameterComboBox> m_waveformComboBox;
    ScopedPointer<Label> m_portamentoModeLabel3;
    ScopedPointer<MicroParameterSlider> m_rateSlider;
    ScopedPointer<MicroParameterSlider> m_pitchSlider;
    ScopedPointer<MicroParameterSlider> m_ampSlider;
    ScopedPointer<MicroParameterSlider> m_filterSlider;
    ScopedPointer<MicroParameterSlider> m_panSlider;
    ScopedPointer<Label> m_pitchLabel;
    ScopedPointer<Label> m_filterLabel;
    ScopedPointer<Label> m_ampLabel;
    ScopedPointer<Label> m_panLabel;
    ScopedPointer<TextWithArrowButton> m_advancedButton;
    ScopedPointer<ImageButton> m_imageButton;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (LfoEditor)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

#endif   // __JUCE_HEADER_616DC4BDDC00A548__
