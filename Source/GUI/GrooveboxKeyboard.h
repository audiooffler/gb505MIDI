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

#ifndef __JUCE_HEADER_5B281920708C2348__
#define __JUCE_HEADER_5B281920708C2348__

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
class GrooveboxKeyboard  : public MidiKeyboardComponent
{
public:
    //==============================================================================
    GrooveboxKeyboard (MidiKeyboardState &state, Orientation orientation);
    ~GrooveboxKeyboard();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
	String getWhiteNoteText(const int /*midiNoteNumber*/) override;
	void drawWhiteNote(int midiNoteNumber, Graphics &g, Rectangle<float> area, bool isDown, bool isOver, Colour /*lineColour*/, Colour textColour) override;
	void drawBlackNote(int midiNoteNumber, Graphics &g, Rectangle<float> area, bool isDown, bool isOver, Colour /*noteFillColour*/) override;
	bool hitTest(int /*x*/, int y) override;
	Range<float> getKeyPosition(int midiNoteNumber, float keyWidth) const override;
	void mouseMove(const MouseEvent& e) override;
	void mouseDrag(const MouseEvent& e) override;
	void mouseDown(const MouseEvent& e) override;
	void mouseUp(const MouseEvent& e) override;
	void mouseEnter(const MouseEvent& e) override;
	void mouseExit(const MouseEvent& e) override;
	void mouseWheelMove(const MouseEvent& e, const MouseWheelDetails& details) override;
    //[/UserMethods]

    void paint (Graphics& g) override;
    void resized() override;

    // Binary resources:
    static const char* whiteKeyOff_png;
    static const int whiteKeyOff_pngSize;
    static const char* whiteKeyOn_png;
    static const int whiteKeyOn_pngSize;
    static const char* blackKeyOff_png;
    static const int blackKeyOff_pngSize;
    static const char* blackKeyOn_png;
    static const int blackKeyOn_pngSize;


private:
    //[UserVariables]   -- You can add your own custom variables in this section.
	Image cachedImage_whiteKeyOff_png;
	Image cachedImage_whiteKeyOn_png;
	Image cachedImage_blackKeyOff_png;
	Image cachedImage_blackKeyOn_png;
    //[/UserVariables]

    //==============================================================================


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (GrooveboxKeyboard)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

#endif   // __JUCE_HEADER_5B281920708C2348__
