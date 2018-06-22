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

#ifndef __JUCE_HEADER_4B6A11DC23F17AC8__
#define __JUCE_HEADER_4B6A11DC23F17AC8__

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
class ParameterLedSwitch  : public Component,
                            public KeyListener,
                            public ChangeListener,
                            public SettableTooltipClient,
                            public Button::Listener
{
public:
    //==============================================================================
    ParameterLedSwitch (const String& componentName);
    ~ParameterLedSwitch();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
	uint8 getValue();
	void setValue(uint8 v);
	bool keyPressed(const KeyPress &key, Component *originatingComponent);
	void changeListenerCallback(ChangeBroadcaster *source);
	void setTooltip(const String &newTooltip); // Assigns a new tooltip to this object.
	String getTooltip(); // Returns the tooltip assigned to this object.
	void setParameter(Parameter* param);
	Parameter* getParamPtr();
	void focusGained(FocusChangeType cause);
	void focusLost(FocusChangeType cause);
    //[/UserMethods]

    void paint (Graphics& g);
    void resized();
    void buttonClicked (Button* buttonThatWasClicked);



private:
    //[UserVariables]   -- You can add your own custom variables in this section.
	uint8 m_value;
	String m_tooltip;
	Parameter* m_paramPtr;
    //[/UserVariables]

    //==============================================================================
    ScopedPointer<ToggleButton> m_toggleButton1;
    ScopedPointer<ToggleButton> m_toggleButton2;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (ParameterLedSwitch)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

#endif   // __JUCE_HEADER_4B6A11DC23F17AC8__
