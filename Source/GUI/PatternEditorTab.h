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

#ifndef __JUCE_HEADER_211612B4383A29A8__
#define __JUCE_HEADER_211612B4383A29A8__

//[Headers]     -- You can add your own extra header files here --
#include "JuceHeader.h"
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Introjucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class PatternEditorTab  : public Component,
                          public ChangeListener,
                          public ComboBoxListener,
                          public ButtonListener
{
public:
    //==============================================================================
    PatternEditorTab ();
    ~PatternEditorTab();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    void changeListenerCallback (ChangeBroadcaster *source) override;
    //[/UserMethods]

    void paint (Graphics& g) override;
    void resized() override;
    void comboBoxChanged (ComboBox* comboBoxThatHasChanged) override;
    void buttonClicked (Button* buttonThatWasClicked) override;



private:
    //[UserVariables]   -- You can add your own custom variables in this section.
	TableHeaderComponent* m_patternEventTableHeader; // will be owed by m_patternEventTable
    //[/UserVariables]

    //==============================================================================
    ScopedPointer<TableListBox> m_patternEventTable;
    ScopedPointer<ComboBox> m_midiOutComboBox;
    ScopedPointer<Label> m_midiOutLabel;
    ScopedPointer<TextButton> m_panicButton;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (PatternEditorTab)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

#endif   // __JUCE_HEADER_211612B4383A29A8__
