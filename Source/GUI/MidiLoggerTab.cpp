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

//[Headers] You can add your own extra header files here...
//[/Headers]

#include "MidiLoggerTab.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
extern MidiInput* midiInputDevice;
extern MidiOutput* midiOutputDevice;
extern int preferredMidiInId;
extern int preferredMidiOutId;
extern GrooveboxConnector* grooveboxConnector;
//[/MiscUserDefs]

//==============================================================================
MidiLoggerTab::MidiLoggerTab ()
{
    addAndMakeVisible (m_logTextEditor = new TextEditor ("logTextEditor"));
    m_logTextEditor->setMultiLine (true);
    m_logTextEditor->setReturnKeyStartsNewLine (false);
    m_logTextEditor->setReadOnly (true);
    m_logTextEditor->setScrollbarsShown (true);
    m_logTextEditor->setCaretVisible (false);
    m_logTextEditor->setPopupMenuEnabled (true);
    m_logTextEditor->setColour (TextEditor::outlineColourId, Colours::grey);
    m_logTextEditor->setText (String());

    addAndMakeVisible (m_grooveboxKeyboard = new GrooveboxKeyboard (state, MidiKeyboardComponent::horizontalKeyboard));

    //[UserPreSize]
	m_logTextEditor->setFont(Font(Font::getDefaultMonospacedFontName(), 13.0f, Font::plain));
    //[/UserPreSize]

    setSize (600, 400);


    //[Constructor] You can add your own custom stuff here..
    //[/Constructor]
}

MidiLoggerTab::~MidiLoggerTab()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
	Logger::setCurrentLogger(nullptr);
    //[/Destructor_pre]

    m_logTextEditor = nullptr;
    m_grooveboxKeyboard = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void MidiLoggerTab::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
	#ifdef JUCE_MSVC
	g;
	#endif
    //[/UserPrePaint]

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void MidiLoggerTab::resized()
{
    m_logTextEditor->setBounds (8, 8, getWidth() - 16, getHeight() - 128);
    m_grooveboxKeyboard->setBounds (8, getHeight() - 8 - 104, getWidth() - 16, 104);
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
void MidiLoggerTab::logMessage(const String &message)
{
	m_logTextEditor->setText(m_logTextEditor->getText() + "\r\n" + message);
}
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Introjucer information section --

    This is where the Introjucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="MidiLoggerTab" componentName=""
                 parentClasses="public Component, public Logger" constructorParams=""
                 variableInitialisers="" snapPixels="8" snapActive="1" snapShown="1"
                 overlayOpacity="0.330" fixedSize="0" initialWidth="600" initialHeight="400">
  <BACKGROUND backgroundColour="0"/>
  <TEXTEDITOR name="logTextEditor" id="8ece3c9585594494" memberName="m_logTextEditor"
              virtualName="" explicitFocusOrder="0" pos="8 8 16M 128M" outlinecol="ff808080"
              initialText="" multiline="1" retKeyStartsLine="0" readonly="1"
              scrollbars="1" caret="0" popupmenu="1"/>
  <JUCERCOMP name="grooveboxKeyboard" id="5fae6d0d0fb694e5" memberName="m_grooveboxKeyboard"
             virtualName="" explicitFocusOrder="0" pos="8 8Rr 16M 104" sourceFile="GrooveboxKeyboard.cpp"
             constructorParams="state, MidiKeyboardComponent::horizontalKeyboard"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
