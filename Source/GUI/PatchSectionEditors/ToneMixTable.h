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

#ifndef __JUCE_HEADER_A93769E2B5E585A8__
#define __JUCE_HEADER_A93769E2B5E585A8__

//[Headers]     -- You can add your own extra header files here --
#include "JuceHeader.h"
#include "../../GrooveboxMemory/GrooveboxMemoryBlock.h"
#include "../ParameterWidgets/MicroParameterSlider.h"
#include "../ParameterWidgets/ParameterComboBox.h"
//[/Headers]

#include "../GroupWidgets/PanelGroupGrey.h"
#include "../GroupWidgets/PanelGroupTransp.h"
#include "ToneMixTableBoard.h"
#include "../ParameterWidgets/BlackToggle.h"


//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Introjucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class ToneMixTable  : public Component,
                      public ChangeListener,
                      public Slider::Listener,
                      public ComboBox::Listener,
                      public Button::Listener
{
public:
    //==============================================================================
    ToneMixTable (const String &componentName, SynthParts part);
    ~ToneMixTable();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
	void changeListenerCallback(ChangeBroadcaster* source);
    //[/UserMethods]

    void paint (Graphics& g);
    void resized();
    void sliderValueChanged (Slider* sliderThatWasMoved);
    void comboBoxChanged (ComboBox* comboBoxThatHasChanged);
    void buttonClicked (Button* buttonThatWasClicked);

    // Binary resources:
    static const char* tonemixtable_png;
    static const int tonemixtable_pngSize;


private:
    //[UserVariables]   -- You can add your own custom variables in this section.
	SynthParts m_part;
	Parameter* m_keyRangeLowerPtr1;
	Parameter* m_keyRangeUpperPtr1;
	Parameter* m_velocityLowerPtr1;
	Parameter* m_velocityUpperPtr1;
	Parameter* m_keyRangeLowerPtr2;
	Parameter* m_keyRangeUpperPtr2;
	Parameter* m_velocityLowerPtr2;
	Parameter* m_velocityUpperPtr2;
	Parameter* m_keyRangeLowerPtr3;
	Parameter* m_keyRangeUpperPtr3;
	Parameter* m_velocityLowerPtr3;
	Parameter* m_velocityUpperPtr3;
	Parameter* m_keyRangeLowerPtr4;
	Parameter* m_keyRangeUpperPtr4;
	Parameter* m_velocityLowerPtr4;
	Parameter* m_velocityUpperPtr4;

    //[/UserVariables]

    //==============================================================================
    ScopedPointer<PanelGroupGrey> m_grp;
    ScopedPointer<PanelGroupTransp> m_ampBiasGrp1;
    ScopedPointer<ToneMixTableBoard> m_toneMixTableBoard;
    ScopedPointer<BlackToggle> m_velocityRangeToggle;
    ScopedPointer<Label> m_velocityRangeLabel;
    ScopedPointer<PanelGroupTransp> m_keyRangeGrp1;
    ScopedPointer<PanelGroupTransp> m_veloRangeGrp1;
    ScopedPointer<MicroParameterSlider> m_velocityCrossFadeSlider1;
    ScopedPointer<Label> m_velocityCrossFadeLabel1;
    ScopedPointer<MicroParameterSlider> m_velocityRangeUpperSlider1;
    ScopedPointer<Label> m_velocityRangeUpperLabel1;
    ScopedPointer<Label> m_velocityRangeLowerLabel1;
    ScopedPointer<MicroParameterSlider> m_velocityRangeLowerSlider1;
    ScopedPointer<Label> m_keyRangeLowerLabel1;
    ScopedPointer<MicroParameterSlider> m_keyRangeLowerSlider1;
    ScopedPointer<MicroParameterSlider> m_keyRangeUpperSlider1;
    ScopedPointer<Label> m_keyRangeUpperLabel1;
    ScopedPointer<MicroParameterSlider> m_biasLevelSlider1;
    ScopedPointer<Label> m_biasLevelLabel1;
    ScopedPointer<Label> m_biasPointLabel1;
    ScopedPointer<MicroParameterSlider> m_biasPointSlider1;
    ScopedPointer<ParameterComboBox> m_biasDirectionComboBox1;
    ScopedPointer<Label> m_biasDirectionLabel1;
    ScopedPointer<Label> m_toneLevelLabel1;
    ScopedPointer<MixPartLevelFader> m_toneLevelSlider1;
    ScopedPointer<PanelGroupTransp> m_keyRangeGrp2;
    ScopedPointer<PanelGroupTransp> m_keyRangeGrp3;
    ScopedPointer<PanelGroupTransp> m_keyRangeGrp4;
    ScopedPointer<PanelGroupTransp> m_ampBiasGrp2;
    ScopedPointer<PanelGroupTransp> m_veloRangeGrp2;
    ScopedPointer<MicroParameterSlider> m_velocityCrossFadeSlider2;
    ScopedPointer<Label> m_velocityCrossFadeLabel2;
    ScopedPointer<MicroParameterSlider> m_velocityRangeUpperSlider2;
    ScopedPointer<Label> m_velocityRangeUpperLabel2;
    ScopedPointer<Label> m_velocityRangeLowerLabel2;
    ScopedPointer<MicroParameterSlider> m_velocityRangeLowerSlider2;
    ScopedPointer<Label> m_keyRangeLowerLabel2;
    ScopedPointer<MicroParameterSlider> m_keyRangeLowerSlider2;
    ScopedPointer<MicroParameterSlider> m_keyRangeUpperSlider2;
    ScopedPointer<Label> m_keyRangeUpperLabel2;
    ScopedPointer<MicroParameterSlider> m_biasLevelSlider2;
    ScopedPointer<Label> m_biasLevelLabel2;
    ScopedPointer<Label> m_biasPointLabel2;
    ScopedPointer<MicroParameterSlider> m_biasPointSlider2;
    ScopedPointer<ParameterComboBox> m_biasDirectionComboBox2;
    ScopedPointer<Label> m_biasDirectionLabel2;
    ScopedPointer<Label> m_toneLevelLabel2;
    ScopedPointer<MixPartLevelFader> m_toneLevelSlider2;
    ScopedPointer<PanelGroupTransp> m_ampBiasGrp3;
    ScopedPointer<PanelGroupTransp> m_veloRangeGrp3;
    ScopedPointer<MicroParameterSlider> m_velocityCrossFadeSlider3;
    ScopedPointer<Label> m_velocityCrossFadeLabel3;
    ScopedPointer<MicroParameterSlider> m_velocityRangeUpperSlider3;
    ScopedPointer<Label> m_velocityRangeUpperLabel3;
    ScopedPointer<Label> m_velocityRangeLowerLabel3;
    ScopedPointer<MicroParameterSlider> m_velocityRangeLowerSlider3;
    ScopedPointer<Label> m_keyRangeLowerLabel3;
    ScopedPointer<MicroParameterSlider> m_keyRangeLowerSlider3;
    ScopedPointer<MicroParameterSlider> m_keyRangeUpperSlider3;
    ScopedPointer<Label> m_keyRangeUpperLabel3;
    ScopedPointer<MicroParameterSlider> m_biasLevelSlider3;
    ScopedPointer<Label> m_biasLevelLabel3;
    ScopedPointer<Label> m_biasPointLabel3;
    ScopedPointer<MicroParameterSlider> m_biasPointSlider3;
    ScopedPointer<ParameterComboBox> m_biasDirectionComboBox3;
    ScopedPointer<Label> m_biasDirectionLabel3;
    ScopedPointer<Label> m_toneLevelLabel3;
    ScopedPointer<MixPartLevelFader> m_toneLevelSlider3;
    ScopedPointer<PanelGroupTransp> m_ampBiasGrp4;
    ScopedPointer<PanelGroupTransp> m_veloRangeGrp4;
    ScopedPointer<MicroParameterSlider> m_velocityCrossFadeSlider4;
    ScopedPointer<Label> m_velocityCrossFadeLabel4;
    ScopedPointer<MicroParameterSlider> m_velocityRangeUpperSlider4;
    ScopedPointer<Label> m_velocityRangeUpperLabel4;
    ScopedPointer<Label> m_velocityRangeLowerLabel4;
    ScopedPointer<MicroParameterSlider> m_velocityRangeLowerSlider4;
    ScopedPointer<Label> m_keyRangeLowerLabel4;
    ScopedPointer<MicroParameterSlider> m_keyRangeLowerSlider4;
    ScopedPointer<MicroParameterSlider> m_keyRangeUpperSlider4;
    ScopedPointer<Label> m_keyRangeUpperLabel4;
    ScopedPointer<MicroParameterSlider> m_biasLevelSlider4;
    ScopedPointer<Label> m_biasLevelLabel4;
    ScopedPointer<Label> m_biasPointLabel4;
    ScopedPointer<MicroParameterSlider> m_biasPointSlider4;
    ScopedPointer<ParameterComboBox> m_biasDirectionComboBox4;
    ScopedPointer<Label> m_biasDirectionLabel4;
    ScopedPointer<Label> m_toneLevelLabel4;
    ScopedPointer<MixPartLevelFader> m_toneLevelSlider4;
    ScopedPointer<ImageButton> imageButton3;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (ToneMixTable)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

#endif   // __JUCE_HEADER_A93769E2B5E585A8__
