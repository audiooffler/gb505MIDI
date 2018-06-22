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

#ifndef __JUCE_HEADER_6DA29A8ED28DDE68__
#define __JUCE_HEADER_6DA29A8ED28DDE68__

//[Headers]     -- You can add your own extra header files here --
#include "JuceHeader.h"
#include "../../GrooveboxMemory/GrooveboxMemoryBlock.h"
#include "../ParameterWidgets/MicroParameterSlider.h"
#include "../ParameterWidgets/ParameterComboBox.h"
//[/Headers]

#include "../GroupWidgets/PanelGroupGrey.h"


//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Introjucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class PatchControllerMatrixEditor  : public Component,
                                     public ComboBox::Listener,
                                     public Slider::Listener
{
public:
    //==============================================================================
    PatchControllerMatrixEditor (const String &componentName, SynthParts part, Tone tone);
    ~PatchControllerMatrixEditor();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    //[/UserMethods]

    void paint (Graphics& g);
    void resized();
    void comboBoxChanged (ComboBox* comboBoxThatHasChanged);
    void sliderValueChanged (Slider* sliderThatWasMoved);

    // Binary resources:
    static const char* pitchBendLever_png;
    static const int pitchBendLever_pngSize;
    static const char* modulation_png;
    static const int modulation_pngSize;


private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    SynthParts m_part;
    Tone m_tone;
    //[/UserVariables]

    //==============================================================================
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
    ScopedPointer<Label> m_modulationLabel1;
    ScopedPointer<Label> m_modulationLabel2;
    ScopedPointer<Label> m_modulationLabel3;
    ScopedPointer<Label> m_modulationLabel4;
    ScopedPointer<Label> m_destLabel1;
    ScopedPointer<Label> m_depthLabel1;
    ScopedPointer<Label> m_destLabel2;
    ScopedPointer<Label> m_depthLabel2;
    ScopedPointer<Label> m_modulationLabel5;
    ScopedPointer<Label> m_modulationLabel6;
    ScopedPointer<Label> m_modulationLabel7;
    ScopedPointer<Label> m_modulationLabel8;
    ScopedPointer<Label> m_destLabel3;
    ScopedPointer<Label> m_depthLabel3;
    ScopedPointer<Label> m_modulationLabel9;
    ScopedPointer<Label> m_modulationLabel10;
    ScopedPointer<Label> m_modulationLabel11;
    ScopedPointer<Label> m_modulationLabel12;
    ScopedPointer<Label> m_bendUpLabel;
    ScopedPointer<Label> m_bendDownLabel;
    ScopedPointer<Label> m_bendCommonLabel;
    ScopedPointer<MicroParameterSlider> m_bendUpSlider;
    ScopedPointer<MicroParameterSlider> m_bendDownSlider;
    ScopedPointer<ImageButton> m_bendRangeImage;
    ScopedPointer<Label> m_line;
    ScopedPointer<Label> m_line2;
    ScopedPointer<ImageButton> imageButton4;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (PatchControllerMatrixEditor)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

#endif   // __JUCE_HEADER_6DA29A8ED28DDE68__
