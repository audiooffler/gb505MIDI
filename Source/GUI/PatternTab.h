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

#ifndef __JUCE_HEADER_9B5F62AFEE9B83CA__
#define __JUCE_HEADER_9B5F62AFEE9B83CA__

//[Headers]     -- You can add your own extra header files here --
#include "JuceHeader.h"
#include "../MIDIConnection/GrooveboxConnector.h"
#include "../GrooveboxPattern.h"
#include "../GrooveboxMemory/GrooveboxMemoryBlock.h"
//[/Headers]

#include "MFxEditor.h"


//==============================================================================
/**
                                                                    //[Comments]
	The main component
                                                                    //[/Comments]
*/
class PatternTab  : public Component,
                    public ApplicationCommandManager,
                    public ApplicationCommandTarget,
                    public MenuBarModel,
                    public FileDragAndDropTarget,
                    public DragAndDropContainer,
                    public ComboBoxListener,
                    public ButtonListener
{
public:
    //==============================================================================
    PatternTab ();
    ~PatternTab();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.

	/* ApplicationCommandTarget implementation: */
	enum CommandIDs
	{
		fileOpenPattern = 0x1001,
		fileImportPattern = 0x1002,
		fileSavePattern = 0x1003,
		fileExportPattern = 0x1004,
		fileQuit = 0x100F,
		grooveBoxLoadPattern = 0x2001
	};
	ApplicationCommandTarget* getNextCommandTarget() override;
	void getAllCommands(Array <CommandID>& commands) override;
	void getCommandInfo(CommandID commandID, ApplicationCommandInfo& result) override;
	bool perform(const InvocationInfo& info) override;

	/* MenuBarModel implementation: */
	StringArray getMenuBarNames();
	PopupMenu getMenuForIndex(int topLevelMenuIndex, const String &menuName);
	void menuItemSelected(int menuItemID, int topLevelMenuIndex);

	/* FileDragAndDropTarget implementation: */
	bool isInterestedInFileDrag(const StringArray &files);
	void filesDropped(const StringArray &files, int x, int y);

	class SysExMessagesArrayListBoxModel : public ListBoxModel
	{
	public:
		SysExMessagesArrayListBoxModel(OwnedArray<SyxMsg, CriticalSection> *syxArrayToBeListed, ListBox* listBoxRef) : ListBoxModel(),
			m_syxArray(syxArrayToBeListed),
			m_listBoxRef(listBoxRef)
		{
		}

		int ListBoxModel::getNumRows()
		{
			return m_syxArray->size();
		}
		void ListBoxModel::paintListBoxItem(int rowNumber, Graphics &g, int width, int height, bool rowIsSelected)
		{
			if (rowIsSelected)
			{
				g.setColour(Colours::lightblue);
				g.fillAll();
			}
			// get sysex data as text
			uint8* syxDataPtr = nullptr;
			uint32 syxDataLength;
			SyxMsg* msgPtr = (*m_syxArray)[rowNumber];
			msgPtr->getAsSysExData(&syxDataPtr, syxDataLength);
			String text(String::toHexString(syxDataPtr, syxDataLength).toUpperCase());

			ScopedPointer<Font> font = new Font(Font::getDefaultMonospacedFontName(), 11.0f, Font::plain);
			minimumContentWidth = jmax(font->getStringWidth(text), minimumContentWidth);
			m_listBoxRef->setMinimumContentWidth(minimumContentWidth);
			g.setColour(msgPtr->isCheckSumOkay()?Colours::black:Colours::darkred);
			g.setFont(*font);
			g.drawText(text, 0, 0, width, height, Justification::centredLeft, false);
		}

	private:
		OwnedArray<SyxMsg, CriticalSection>* m_syxArray;
		ListBox* m_listBoxRef;
		int minimumContentWidth = 0;
	};

	void loadFromGroovebox();
	void loadFile(const File& file);
	void saveAsSysExFile();
	void exportAsMidiFile();

	bool m_draggingFileToExternalAppActive;

    //[/UserMethods]

    void paint (Graphics& g);
    void resized();
    void comboBoxChanged (ComboBox* comboBoxThatHasChanged);
    void buttonClicked (Button* buttonThatWasClicked);
    void mouseDrag (const MouseEvent& e);

    // Binary resources:
    static const char* audioxmidi_png;
    static const int audioxmidi_pngSize;


private:
    //[UserVariables]   -- You can add your own custom variables in this section.

	String m_decodedNonEmptyEventsString;

	ScopedPointer<MidiFile> m_patternFile;

	// for SysEx listbox
	ScopedPointer<SysExMessagesArrayListBoxModel> m_loadedMessagesListModel;
	OwnedArray<SyxMsg, CriticalSection> m_loadedMessagesListArray;

	ScopedPointer<Drawable> m_logoDrawable;

	ScopedPointer<Image> img_backgroundTexture;
	ScopedPointer<Image> img_mc505;
	ScopedPointer<Image> img_jx305;
	ScopedPointer<Image> img_mc307;
	ScopedPointer<Image> img_d2;
	ScopedPointer<Image> img_noConnection;

	ScopedPointer<GrooveboxPattern> m_currentPattern;

	bool m_afterConstructor;
    //[/UserVariables]

    //==============================================================================
    ScopedPointer<Label> m_receivedSysExLabel;
    ScopedPointer<Label> m_deviceIdLabel;
    ScopedPointer<ComboBox> m_midiInComboBox;
    ScopedPointer<Label> m_midiInLabel;
    ScopedPointer<ComboBox> m_midiOutComboBox;
    ScopedPointer<Label> m_midiOutLabel;
    ScopedPointer<Label> m_bpmLabel;
    ScopedPointer<TextEditor> m_bpmText;
    ScopedPointer<Label> m_measuresLabel;
    ScopedPointer<TextEditor> m_measuresText;
    ScopedPointer<Label> m_beatLabel;
    ScopedPointer<TextEditor> m_beatText;
    ScopedPointer<Label> m_measuresLabel3;
    ScopedPointer<Label> m_patternNameLabel;
    ScopedPointer<TextEditor> m_patternNameText;
    ScopedPointer<ListBox> m_receivedSysExList;
    ScopedPointer<ImageComponent> m_imageViewComponent;
    ScopedPointer<TextButton> m_searchDevicesButton;
    ScopedPointer<ComboBox> m_deviceToUseComboBox;
    ScopedPointer<TextButton> m_getPatternButton;
    ScopedPointer<TextButton> m_saveMidiFileButton;
    ScopedPointer<MenuBarComponent> m_menuBar;
    ScopedPointer<ImageButton> m_dragSmfImageButton;
    ScopedPointer<MFXEditor> component;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (PatternTab)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

#endif   // __JUCE_HEADER_9B5F62AFEE9B83CA__
