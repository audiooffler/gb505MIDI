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

#ifndef __JUCE_HEADER_CFF0C7B8230D1F0C__
#define __JUCE_HEADER_CFF0C7B8230D1F0C__

//[Headers]     -- You can add your own extra header files here --
#include "JuceHeader.h"
#include "../../GrooveboxMemory/GrooveboxMemoryBlock.h"
#include "../ParameterWidgets/Knob.h"
#include "../ParameterWidgets/MixPartLevelFader.h"
#include "../ParameterWidgets/BigOrangeToggle.h"
#include "../ParameterWidgets/MicroParameterSlider.h"
//[/Headers]

#include "../ParameterWidgets/GrabSwitch.h"
#include "../ParameterWidgets/BigOrangeToggle.h"
#include "../ParameterWidgets/SmallGreenToggle.h"


//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Introjucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class MixRhyTrack  : public Component,
                     public SliderListener,
                     public ButtonListener
{
public:
    //==============================================================================
    MixRhyTrack (AllParts part);
    ~MixRhyTrack();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    //[/UserMethods]

    void paint (Graphics& g);
    void resized();
    void sliderValueChanged (Slider* sliderThatWasMoved);
    void buttonClicked (Button* buttonThatWasClicked);

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
    AllParts m_part;
    //[/UserVariables]

    //==============================================================================
    ScopedPointer<MicroParameterSlider> m_mfxHelper;
    ScopedPointer<MixPartLevelFader> m_mixLevel;
    ScopedPointer<Knob> m_panSlider;
    ScopedPointer<Knob> m_delaySlider;
    ScopedPointer<Knob> m_ReverbSlider;
    ScopedPointer<MicroParameterSlider> m_keyShiftSlider;
    ScopedPointer<GrabSwitch> m_mfxGrab;
    ScopedPointer<BigOrangeToggle> m_muteToggle;
    ScopedPointer<ImageButton> imageButton;
    ScopedPointer<SmallGreenToggle> m_mfx_RHYtoggle;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MixRhyTrack)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

#endif   // __JUCE_HEADER_CFF0C7B8230D1F0C__
