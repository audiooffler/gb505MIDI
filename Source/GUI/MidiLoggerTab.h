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

#ifndef __JUCE_HEADER_FF2A5B01BAE21894__
#define __JUCE_HEADER_FF2A5B01BAE21894__

//[Headers]     -- You can add your own extra header files here --
#include "JuceHeader.h"
#include "../MIDIConnection/GrooveboxConnector.h"
//[/Headers]

#include "GrooveboxKeyboard.h"


//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Introjucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class MidiLoggerTab  : public Component,
                       public Logger
{
public:
    //==============================================================================
    MidiLoggerTab ();
    ~MidiLoggerTab();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
	void logMessage(const String &message);
    //[/UserMethods]

    void paint (Graphics& g);
    void resized();



private:
    //[UserVariables]   -- You can add your own custom variables in this section.
	MidiKeyboardState state;
    //[/UserVariables]

    //==============================================================================
    ScopedPointer<TextEditor> m_logTextEditor;
    ScopedPointer<GrooveboxKeyboard> m_grooveboxKeyboard;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MidiLoggerTab)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

#endif   // __JUCE_HEADER_FF2A5B01BAE21894__
