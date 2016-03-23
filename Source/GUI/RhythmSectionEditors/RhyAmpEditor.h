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

#ifndef __JUCE_HEADER_D3FBCA4D9A6B8E88__
#define __JUCE_HEADER_D3FBCA4D9A6B8E88__

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
#include "../GroupWidgets/PanelGroupTransp.h"
#include "../PatchSectionEditors/Envelope.h"
#include "../ParameterWidgets/BlackToggle.h"
#include "../ParameterWidgets/GrabSwitch.h"


//==============================================================================
/**
                                                                    //[Comments]
An auto-generated component, created by the Introjucer.

Describe your class and how it works here!
                                                                    //[/Comments]
*/
class RhyAmpEditor  : public Component,
                      public SliderListener
{
public:
    //==============================================================================
    RhyAmpEditor (const String &componentName, int toneNumber);
    ~RhyAmpEditor();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    void setupParameters(int toneNumber);
    //[/UserMethods]

    void paint (Graphics& g) override;
    void resized() override;
    void sliderValueChanged (Slider* sliderThatWasMoved) override;

    // Binary resources:
    static const char* amp_png;
    static const int amp_pngSize;


private:
    //[UserVariables]   -- You can add your own custom variables in this section.
	int m_toneNumber;
    //[/UserVariables]

    //==============================================================================
    ScopedPointer<PanelGroupGrey> m_ampGrp;
    ScopedPointer<PanelGroupGrey> m_sendFXGrp;
    ScopedPointer<PanelGroupGrey> m_ampEnvGrp;
    ScopedPointer<Knob> m_tonePanSlider;
    ScopedPointer<Label> m_tonePanLabel;
    ScopedPointer<Envelope> m_ampEnv;
    ScopedPointer<MicroParameterSlider> m_ampVelocitySensSlider;
    ScopedPointer<Label> m_ampEnvVelocitySensLabel;
    ScopedPointer<MicroParameterSlider> m_ampEnvVelocityTime1Slider;
    ScopedPointer<Label> m_ampEnvVelocityTime1Label;
    ScopedPointer<BlackToggle> m_panRandomToggle;
    ScopedPointer<Label> m_panRandomLabel;
    ScopedPointer<MicroParameterSlider> m_panAlternateSlider;
    ScopedPointer<Label> m_panAlternateLabel;
    ScopedPointer<ImageButton> m_imageButton;
    ScopedPointer<ParameterEnvelopeSlider> m_toneLevelSlider;
    ScopedPointer<Label> m_filterEnvelopeDepthLabel;
    ScopedPointer<Knob> m_delaySlider;
    ScopedPointer<Knob> m_ReverbSlider;
    ScopedPointer<Label> m_mfxLabel;
    ScopedPointer<Label> m_delayLabel;
    ScopedPointer<Label> m_reverbLabel;
    ScopedPointer<GrabSwitch> m_mfxGrab;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (RhyAmpEditor)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

#endif   // __JUCE_HEADER_D3FBCA4D9A6B8E88__
