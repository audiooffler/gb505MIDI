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

#ifndef __JUCE_HEADER_2DF612F061399104__
#define __JUCE_HEADER_2DF612F061399104__

//[Headers]     -- You can add your own extra header files here --
#include "JuceHeader.h"
#include "ParameterWidgets/ParameterSlider.h"
#include "ParameterWidgets/ParameterComboBox.h"
#include "../GrooveboxMemory/PartInfoBlock.h"
//[/Headers]

#include "GroupWidgets/PanelGroupGrey.h"


//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Introjucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class MFXEditor  : public Component,
                   public SliderListener,
                   public ComboBoxListener
{
public:
    //==============================================================================
    MFXEditor ();
    ~MFXEditor();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    //[/UserMethods]

    void paint (Graphics& g) override;
    void resized() override;
    void sliderValueChanged (Slider* sliderThatWasMoved) override;
    void comboBoxChanged (ComboBox* comboBoxThatHasChanged) override;



private:
    //[UserVariables]   -- You can add your own custom variables in this section.
	// for testing:
	ScopedPointer<PartInfoCommonBlock> m_partInfoCommonBlock;
    //[/UserVariables]

    //==============================================================================
    ScopedPointer<PanelGroupGrey> component;
    ScopedPointer<Label> m_paramLabel1;
    ScopedPointer<ParameterSlider> m_paramSlider1;
    ScopedPointer<ParameterSlider> m_paramSlider2;
    ScopedPointer<Label> m_paramLabel2;
    ScopedPointer<ParameterSlider> m_paramSlider3;
    ScopedPointer<Label> m_paramLabel3;
    ScopedPointer<ParameterSlider> m_paramSlider4;
    ScopedPointer<Label> m_paramLabel4;
    ScopedPointer<ParameterSlider> m_paramSlider5;
    ScopedPointer<Label> m_paramLabel5;
    ScopedPointer<ParameterSlider> m_paramSlider6;
    ScopedPointer<Label> m_paramLabel6;
    ScopedPointer<ParameterSlider> m_paramSlider7;
    ScopedPointer<Label> m_paramLabel7;
    ScopedPointer<ParameterSlider> m_paramSlider8;
    ScopedPointer<Label> m_paramLabel8;
    ScopedPointer<ParameterSlider> m_paramSlider9;
    ScopedPointer<Label> m_paramLabel9;
    ScopedPointer<ParameterSlider> m_paramSlider10;
    ScopedPointer<Label> m_paramLabel10;
    ScopedPointer<ParameterSlider> m_paramSlider11;
    ScopedPointer<Label> m_paramLabel11;
    ScopedPointer<ParameterComboBox> m_MFXTypeComboBox;
    ScopedPointer<Label> m_MFXTypeLabel;
    ScopedPointer<TextEditor> m_MFXTypeDescriptionTextEditor;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MFXEditor)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

#endif   // __JUCE_HEADER_2DF612F061399104__
