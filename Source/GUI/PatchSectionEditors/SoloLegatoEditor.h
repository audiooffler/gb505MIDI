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

#ifndef __JUCE_HEADER_1A1EAD6C3EDAEAB8__
#define __JUCE_HEADER_1A1EAD6C3EDAEAB8__

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


//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Introjucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class SoloLegatoEditor  : public Component,
                          public SliderListener,
                          public ButtonListener
{
public:
    //==============================================================================
    SoloLegatoEditor (const String &componentName, SynthParts part);
    ~SoloLegatoEditor();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    void changeListenerCallback(ChangeBroadcaster *source);	// parameter changes of groovebox memory block
    //[/UserMethods]

    void paint (Graphics& g);
    void resized();
    void sliderValueChanged (Slider* sliderThatWasMoved);
    void buttonClicked (Button* buttonThatWasClicked);

    // Binary resources:
    static const char* solo_png;
    static const int solo_pngSize;
    static const char* portamento_png;
    static const int portamento_pngSize;


private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    SynthParts m_part;
    //[/UserVariables]

    //==============================================================================
    ScopedPointer<PanelGroupGrey> m_soloLegatoGrp;
    ScopedPointer<PanelGroupGrey> m_soloGrp;
    ScopedPointer<PanelGroupGrey> m_portamentoGrp;
    ScopedPointer<BlackToggle> m_soloToggle;
    ScopedPointer<Label> m_soloLabel;
    ScopedPointer<BlackToggle> m_legatoToggle;
    ScopedPointer<Label> m_legatoLabel;
    ScopedPointer<BlackToggle> m_portamentoToggle;
    ScopedPointer<Label> m_portamentoLabel;
    ScopedPointer<Label> m_portamentoModeLabel;
    ScopedPointer<Label> m_portamentoTypeLabel;
    ScopedPointer<Label> m_portamentoStartLabel;
    ScopedPointer<Label> m_portamentoTimeLabel;
    ScopedPointer<MicroParameterSlider> m_portamentoTimeSlider;
    ScopedPointer<ParameterLedSwitch> m_portamentoModeToggle;
    ScopedPointer<ParameterLedSwitch> m_portamentoStartToggle;
    ScopedPointer<ParameterLedSwitch> m_portamentoTypeToggle;
    ScopedPointer<ImageButton> m_imageButton1;
    ScopedPointer<ImageButton> m_imageButton2;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (SoloLegatoEditor)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

#endif   // __JUCE_HEADER_1A1EAD6C3EDAEAB8__
