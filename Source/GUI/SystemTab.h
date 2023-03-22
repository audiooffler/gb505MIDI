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

#ifndef __JUCE_HEADER_60336F829909A0F5__
#define __JUCE_HEADER_60336F829909A0F5__

//[Headers]     -- You can add your own extra header files here --
#include "JuceHeader.h"
#include "../MIDIConnection/GrooveboxConnector.h"
#include "../GrooveboxMemory/GrooveboxMemoryBlock.h"
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
	The main component
                                                                    //[/Comments]
*/
class SystemTab  : public Component,
                   public FileDragAndDropTarget,
                   public DragAndDropContainer,
                   public ComboBox::Listener,
                   public Button::Listener
{
public:
    //==============================================================================
    SystemTab ();
    ~SystemTab();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.

	/* FileDragAndDropTarget implementation: */
	bool isInterestedInFileDrag(const StringArray &files) override;
	void filesDropped(const StringArray &files, int x, int y) override;

	bool m_draggingFileToExternalAppActive;

    //[/UserMethods]

    void paint (Graphics& g) override;
    void resized() override;
    void comboBoxChanged (ComboBox* comboBoxThatHasChanged) override;
    void buttonClicked (Button* buttonThatWasClicked) override;
    void mouseDrag (const MouseEvent& e) override;

    // Binary resources:
    static const char* audioxmidi_png;
    static const int audioxmidi_pngSize;


private:
    //[UserVariables]   -- You can add your own custom variables in this section.

	String m_decodedNonEmptyEventsString;

    std::unique_ptr<Drawable> m_logoDrawable;

	ScopedPointer<Image> img_backgroundTexture;
	ScopedPointer<Image> img_mc505;
	ScopedPointer<Image> img_jx305;
	ScopedPointer<Image> img_mc307;
	ScopedPointer<Image> img_d2;
	ScopedPointer<Image> img_noConnection;

	bool m_afterConstructor;
    //[/UserVariables]

    //==============================================================================
    ScopedPointer<Label> m_deviceIdLabel;
    ScopedPointer<ComboBox> m_midiInComboBox;
    ScopedPointer<Label> m_midiInLabel;
    ScopedPointer<ComboBox> m_midiOutComboBox;
    ScopedPointer<Label> m_midiOutLabel;
    ScopedPointer<ImageComponent> m_imageViewComponent;
    ScopedPointer<TextButton> m_searchDevicesButton;
    ScopedPointer<ComboBox> m_deviceToUseComboBox;
    ScopedPointer<ImageButton> m_dragSmfImageButton;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (SystemTab)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

#endif   // __JUCE_HEADER_60336F829909A0F5__
