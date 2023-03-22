/*
  ==============================================================================

  This is an automatically generated GUI class created by the Projucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Projucer version: 7.0.2

  ------------------------------------------------------------------------------

  The Projucer is part of the JUCE library.
  Copyright (c) 2020 - Raw Material Software Limited.

  ==============================================================================
*/

#pragma once

//[Headers]     -- You can add your own extra header files here --
#include "JuceHeader.h"
#include "../../GrooveboxMemory/GrooveboxMemoryBlock.h"
#include "../ParameterWidgets/Knob.h"
#include "../ParameterWidgets/MixPartLevelFader.h"
#include "../ParameterWidgets/BigOrangeToggle.h"
#include "../ParameterWidgets/MicroParameterSlider.h"
#include "../ParameterWidgets/ParameterTextEditor.h"
//[/Headers]

#include "../ParameterWidgets/GrabSwitch.h"
#include "../ParameterWidgets/BigOrangeToggle.h"
#include "../ParameterWidgets/ParameterTextLabel.h"
#include "../ParameterWidgets/SmallGreenToggle.h"


//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Introjucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class MixRhyTrack  : public Component,
                     public ChangeListener,
                     public juce::Slider::Listener,
                     public juce::Button::Listener
{
public:
    //==============================================================================
    MixRhyTrack ();
    ~MixRhyTrack() override;

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
	void changeListenerCallback(ChangeBroadcaster* source) override;
    //[/UserMethods]

    void paint (juce::Graphics& g) override;
    void resized() override;
    void sliderValueChanged (juce::Slider* sliderThatWasMoved) override;
    void buttonClicked (juce::Button* buttonThatWasClicked) override;

    // Binary resources:
    static const char* partNameR_png;
    static const int partNameR_pngSize;
    static const char* partName1_png;
    static const int partName1_pngSize;
    static const char* partName2_png;
    static const int partName2_pngSize;
    static const char* partName3_png;
    static const int partName3_pngSize;
    static const char* partName4_png;
    static const int partName4_pngSize;
    static const char* partName5_png;
    static const int partName5_pngSize;
    static const char* partName6_png;
    static const int partName6_pngSize;
    static const char* partName7_png;
    static const int partName7_pngSize;


private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    //[/UserVariables]

    //==============================================================================
    std::unique_ptr<juce::Label> m_mfxLabel2;
    std::unique_ptr<juce::Label> m_mfxLabel;
    std::unique_ptr<GrabSwitch> m_mfxGrab;
    std::unique_ptr<MixPartLevelFader> m_mixLevel;
    std::unique_ptr<Knob> m_panSlider;
    std::unique_ptr<Knob> m_delaySlider;
    std::unique_ptr<Knob> m_ReverbSlider;
    std::unique_ptr<MicroParameterSlider> m_keyShiftSlider;
    std::unique_ptr<BigOrangeToggle> m_muteToggle;
    std::unique_ptr<juce::ImageButton> imageButton;
    std::unique_ptr<juce::Label> m_panLabel;
    std::unique_ptr<juce::Label> m_keyShiftLabel;
    std::unique_ptr<juce::Label> m_reverbLabel;
    std::unique_ptr<juce::Label> m_delayLabel;
    std::unique_ptr<ParameterTextLabel> m_patchNameEditor;
    std::unique_ptr<MicroParameterSlider> m_voiceResvSlider;
    std::unique_ptr<juce::Label> m_voiceResvLabel;
    std::unique_ptr<SmallGreenToggle> m_mfx_RHYtoggle;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MixRhyTrack)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

