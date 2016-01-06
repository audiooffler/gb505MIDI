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

#ifndef __JUCE_HEADER_BEFA5CC9E728741A__
#define __JUCE_HEADER_BEFA5CC9E728741A__

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
class ParameterToggle  : public ToggleButton,
                         public ChangeListener
{
public:
    //==============================================================================
    ParameterToggle (const String& componentName);
    ~ParameterToggle();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
	ParameterToggle(Parameter* paramPtr);
	ParameterToggle();
	void setParameter(Parameter* param);
	Parameter* getParamPtr();
	String getTooltip() override;
	void changeListenerCallback(ChangeBroadcaster *source);	// parameter changes of groovebox memory block
	void buttonStateChanged();
    //[/UserMethods]

    void paint (Graphics& g);
    void resized();



private:
    //[UserVariables]   -- You can add your own custom variables in this section.
	Parameter* m_paramPtr;
    //[/UserVariables]

    //==============================================================================


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (ParameterToggle)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

#endif   // __JUCE_HEADER_BEFA5CC9E728741A__
