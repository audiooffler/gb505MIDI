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

#ifndef __JUCE_HEADER_53B418B431C40686__
#define __JUCE_HEADER_53B418B431C40686__

//[Headers]     -- You can add your own extra header files here --
#include "JuceHeader.h"
#include "../../GrooveboxMemory/GrooveboxMemoryBlock.h"
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Introjucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class ParameterTextEditor  : public TextEditor,
                             public TextEditor::Listener,
                             public ChangeListener
{
public:
    //==============================================================================
    ParameterTextEditor (const String &componentName=String::empty);
    ~ParameterTextEditor();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
	void setParameter1(Parameter* paramPtr1);

	Parameter* getParamPtr(uint8 index) // 0 to 11, else null will be returned
	{
		return index < (uint8)m_params.size() ? m_params[index] : nullptr;
	}

	void changeListenerCallback(ChangeBroadcaster *source);	// parameter changes of groovebox memory block

	void textEditorTextChanged(TextEditor &textEditor);

    //[/UserMethods]

    void paint (Graphics& g);
    void resized();



private:
    //[UserVariables]   -- You can add your own custom variables in this section.
	Array <Parameter*> m_params;
    //[/UserVariables]

    //==============================================================================


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (ParameterTextEditor)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

#endif   // __JUCE_HEADER_53B418B431C40686__
