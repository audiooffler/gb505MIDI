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

#ifndef __JUCE_HEADER_AE186AF6A0B79024__
#define __JUCE_HEADER_AE186AF6A0B79024__

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
class FxmEditor  : public Component,
                   public SliderListener,
                   public ComboBoxListener
{
public:
    //==============================================================================
    FxmEditor (const String &componentName, SynthParts part, Tone tone);
    ~FxmEditor();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
	void changeListenerCallback(ChangeBroadcaster *source);	// parameter changes of groovebox memory block
    //[/UserMethods]

    void paint (Graphics& g);
    void resized();
    void sliderValueChanged (Slider* sliderThatWasMoved);
    void comboBoxChanged (ComboBox* comboBoxThatHasChanged);

    // Binary resources:
    static const char* fxm_png;
    static const int fxm_pngSize;


private:
    //[UserVariables]   -- You can add your own custom variables in this section.
	SynthParts m_part;
	Tone m_tone;
    //[/UserVariables]

    //==============================================================================
    ScopedPointer<PanelGroupGrey> m_fxmGrp;
    ScopedPointer<BlackToggle> m_fxmToggle;
    ScopedPointer<Label> m_fxmOnLabel;
    ScopedPointer<Label> m_fxmColorLabel;
    ScopedPointer<MicroParameterSlider> m_fxmDepthSlider;
    ScopedPointer<Label> m_fxmDepthLabel;
    ScopedPointer<ImageButton> m_imageButton;
    ScopedPointer<ParameterComboBox> m_fxmColorComboBox;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (FxmEditor)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

#endif   // __JUCE_HEADER_AE186AF6A0B79024__
