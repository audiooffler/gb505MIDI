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

#ifndef __JUCE_HEADER_92E596E9AF51CD06__
#define __JUCE_HEADER_92E596E9AF51CD06__

//[Headers]     -- You can add your own extra header files here --
#include "JuceHeader.h"
//[/Headers]

#include "ToneMixTableBoard.h"


//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Introjucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class ToneMixTable  : public Component,
                              public ChangeListener,
                              public ButtonListener,
                              public SliderListener
{
public:
    //==============================================================================
    ToneMixTable ();
    ~ToneMixTable();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
	void changeListenerCallback(ChangeBroadcaster *source);
    //[/UserMethods]

    void paint (Graphics& g);
    void resized();
    void buttonClicked (Button* buttonThatWasClicked);
    void sliderValueChanged (Slider* sliderThatWasMoved);



private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    //[/UserVariables]

    //==============================================================================
    ScopedPointer<ToneMixTableBoard> m_toneMixTableBoard;
    ScopedPointer<ToggleButton> m_velocityRangeSwitch;
    ScopedPointer<Label> m_velocityCrossFadeLabel;
    ScopedPointer<Slider> m_velocityCrossFade1;
    ScopedPointer<Label> m_tone1Label;
    ScopedPointer<Slider> m_velocityCrossFade2;
    ScopedPointer<Label> m_tone2Label;
    ScopedPointer<Label> m_tone3Label;
    ScopedPointer<Label> m_tone4Label;
    ScopedPointer<Slider> m_velocityCrossFade3;
    ScopedPointer<Slider> m_velocityCrossFade4;
    ScopedPointer<Label> m_velocityRangeUpperLabel;
    ScopedPointer<Slider> m_velocityRangeUpper1;
    ScopedPointer<Slider> m_velocityRangeUpper2;
    ScopedPointer<Slider> m_velocityRangeUpper3;
    ScopedPointer<Slider> m_velocityRangeUpper4;
    ScopedPointer<Label> m_velocityRangeLowerLabel;
    ScopedPointer<Slider> m_velocityRangeLower1;
    ScopedPointer<Slider> m_velocityRangeLower2;
    ScopedPointer<Slider> m_velocityRangeLower3;
    ScopedPointer<Slider> m_velocityRangeLower4;
    ScopedPointer<Label> m_keyRangeLowerLabel;
    ScopedPointer<Slider> m_keyRangeLower1;
    ScopedPointer<Slider> m_keyRangeLower2;
    ScopedPointer<Slider> m_keyRangeLower3;
    ScopedPointer<Slider> m_keyRangeLower4;
    ScopedPointer<Label> m_keyRangeUpperLabel;
    ScopedPointer<Slider> m_keyRangeUpper1;
    ScopedPointer<Slider> m_keyRangeUpper2;
    ScopedPointer<Slider> m_keyRangeUpper3;
    ScopedPointer<Slider> m_keyRangeUpper4;
    ScopedPointer<Label> m_biasDirectionLabel;
    ScopedPointer<Slider> m_biasDirection1;
    ScopedPointer<Slider> m_biasDirection2;
    ScopedPointer<Slider> m_biasDirection3;
    ScopedPointer<Slider> m_biasDirection4;
    ScopedPointer<Label> m_toneLevelLabel;
    ScopedPointer<Slider> m_toneLevel1;
    ScopedPointer<Slider> m_toneLevel2;
    ScopedPointer<Slider> m_toneLevel3;
    ScopedPointer<Slider> m_toneLevel4;
    ScopedPointer<Label> m_biasPointLabel;
    ScopedPointer<Slider> m_biasPoint1;
    ScopedPointer<Slider> m_biasPoint2;
    ScopedPointer<Slider> m_biasPoint3;
    ScopedPointer<Slider> m_biasPoint4;
    ScopedPointer<Label> m_biasLevelLabel;
    ScopedPointer<Slider> m_biasLevel1;
    ScopedPointer<Slider> m_biasLevel2;
    ScopedPointer<Slider> m_biasLevel3;
    ScopedPointer<Slider> m_biasLevel4;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (ToneMixTable)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

#endif   // __JUCE_HEADER_92E596E9AF51CD06__
