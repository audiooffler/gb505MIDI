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

#ifndef __JUCE_HEADER_2F50A866A034E23C__
#define __JUCE_HEADER_2F50A866A034E23C__

//[Headers]     -- You can add your own extra header files here --
#include "JuceHeader.h"
#include "../../GrooveboxMemory/GrooveboxMemoryBlock.h"
#include "../GrooveboxLookAndFeel.h"
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Introjucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class ParameterComboBox  : public ComboBox,
                           public ChangeListener,
                           public ComboBox::Listener
{
public:
    //==============================================================================
    ParameterComboBox (const String& componentName);
    ~ParameterComboBox();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
	ParameterComboBox(Parameter* paramPtr = nullptr);
	void setParameter(Parameter* param);
	Parameter* getParamPtr();
	String getTooltip() override;
	void changeListenerCallback(ChangeBroadcaster *source);	// parameter changes of groovebox memory block
	void comboBoxChanged(ComboBox *comboBoxThatHasChanged);
    //[/UserMethods]

    void paint (Graphics& g);
    void resized();



private:
    //[UserVariables]   -- You can add your own custom variables in this section.
	Parameter* m_paramPtr;
	SharedResourcePointer<GrooveboxLookAndFeel> m_comboBoxlookAndFeel;
    //[/UserVariables]

    //==============================================================================


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (ParameterComboBox)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

#endif   // __JUCE_HEADER_2F50A866A034E23C__
