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
#include "MainWindow.h"
#include "../GrooveboxMemory/OverallMemoryBlock.h"
//[/Headers]

#include "PatternTab.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
extern ApplicationCommandManager*  applicationCommandManager;
extern ApplicationProperties* appProperties;
extern MidiInput* midiInputDevice;
extern MidiOutput* midiOutputDevice;
extern int preferredMidiInId;
extern int preferredMidiOutId;
extern GrooveboxConnector* grooveboxConnector;
extern OverallMemoryBlock* grooveboxMemory;

//[/MiscUserDefs]

//==============================================================================
PatternTab::PatternTab ()
{
    addAndMakeVisible (m_receivedSysExLabel = new Label ("receivedSysExLabel",
                                                         "Received SysEx (DT1):"));
    m_receivedSysExLabel->setFont (Font (15.00f, Font::plain));
    m_receivedSysExLabel->setJustificationType (Justification::centredLeft);
    m_receivedSysExLabel->setEditable (false, false, false);
    m_receivedSysExLabel->setColour (TextEditor::textColourId, Colours::black);
    m_receivedSysExLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_deviceIdLabel = new Label ("deviceIdLabel",
                                                    "connected groovebox:"));
    m_deviceIdLabel->setTooltip ("(17 .. 32, as shown on device display)");
    m_deviceIdLabel->setFont (Font (15.00f, Font::plain));
    m_deviceIdLabel->setJustificationType (Justification::centredLeft);
    m_deviceIdLabel->setEditable (false, false, false);
    m_deviceIdLabel->setColour (TextEditor::textColourId, Colours::black);
    m_deviceIdLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_midiInComboBox = new ComboBox ("midiInComboBox"));
    m_midiInComboBox->setEditableText (false);
    m_midiInComboBox->setJustificationType (Justification::centredLeft);
    m_midiInComboBox->setTextWhenNothingSelected (String::empty);
    m_midiInComboBox->setTextWhenNoChoicesAvailable ("(no choices)");
    m_midiInComboBox->addListener (this);

    addAndMakeVisible (m_midiInLabel = new Label ("midiInLabel",
                                                  "Midi In:"));
    m_midiInLabel->setFont (Font (15.00f, Font::plain));
    m_midiInLabel->setJustificationType (Justification::centredLeft);
    m_midiInLabel->setEditable (false, false, false);
    m_midiInLabel->setColour (TextEditor::textColourId, Colours::black);
    m_midiInLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_midiOutComboBox = new ComboBox ("midiOutComboBox"));
    m_midiOutComboBox->setEditableText (false);
    m_midiOutComboBox->setJustificationType (Justification::centredLeft);
    m_midiOutComboBox->setTextWhenNothingSelected (String::empty);
    m_midiOutComboBox->setTextWhenNoChoicesAvailable ("(no choices)");
    m_midiOutComboBox->addListener (this);

    addAndMakeVisible (m_midiOutLabel = new Label ("midiOutLabel",
                                                   "Midi Out:"));
    m_midiOutLabel->setFont (Font (15.00f, Font::plain));
    m_midiOutLabel->setJustificationType (Justification::centredLeft);
    m_midiOutLabel->setEditable (false, false, false);
    m_midiOutLabel->setColour (TextEditor::textColourId, Colours::black);
    m_midiOutLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_bpmLabel = new Label ("bpmLabel",
                                               "Tempo (BPM):"));
    m_bpmLabel->setTooltip ("(4 byte, hex, seperated by whitespace)");
    m_bpmLabel->setFont (Font (15.00f, Font::plain));
    m_bpmLabel->setJustificationType (Justification::centredLeft);
    m_bpmLabel->setEditable (false, false, false);
    m_bpmLabel->setColour (TextEditor::textColourId, Colours::black);
    m_bpmLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_bpmText = new TextEditor ("bpmText"));
    m_bpmText->setTooltip ("(4 byte, hex, seperated by whitespace)");
    m_bpmText->setMultiLine (false);
    m_bpmText->setReturnKeyStartsNewLine (false);
    m_bpmText->setReadOnly (true);
    m_bpmText->setScrollbarsShown (true);
    m_bpmText->setCaretVisible (false);
    m_bpmText->setPopupMenuEnabled (true);
    m_bpmText->setColour (TextEditor::backgroundColourId, Colour (0xffd0d0d0));
    m_bpmText->setColour (TextEditor::outlineColourId, Colour (0xb2808080));
    m_bpmText->setText ("120.0");

    addAndMakeVisible (m_measuresLabel = new Label ("measuresLabel",
                                                    "Length in Measures:"));
    m_measuresLabel->setTooltip ("(4 byte, hex, seperated by whitespace)");
    m_measuresLabel->setFont (Font (15.00f, Font::plain));
    m_measuresLabel->setJustificationType (Justification::centredLeft);
    m_measuresLabel->setEditable (false, false, false);
    m_measuresLabel->setColour (TextEditor::textColourId, Colours::black);
    m_measuresLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_measuresText = new TextEditor ("measuresText"));
    m_measuresText->setTooltip ("(4 byte, hex, seperated by whitespace)");
    m_measuresText->setMultiLine (false);
    m_measuresText->setReturnKeyStartsNewLine (false);
    m_measuresText->setReadOnly (true);
    m_measuresText->setScrollbarsShown (true);
    m_measuresText->setCaretVisible (false);
    m_measuresText->setPopupMenuEnabled (true);
    m_measuresText->setColour (TextEditor::backgroundColourId, Colour (0xffd0d0d0));
    m_measuresText->setColour (TextEditor::outlineColourId, Colour (0xb2808080));
    m_measuresText->setText ("4");

    addAndMakeVisible (m_beatLabel = new Label ("measuresLabel",
                                                "Beat:"));
    m_beatLabel->setTooltip ("(4 byte, hex, seperated by whitespace)");
    m_beatLabel->setFont (Font (15.00f, Font::plain));
    m_beatLabel->setJustificationType (Justification::centredLeft);
    m_beatLabel->setEditable (false, false, false);
    m_beatLabel->setColour (TextEditor::textColourId, Colours::black);
    m_beatLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_beatText = new TextEditor ("beatText"));
    m_beatText->setTooltip ("(4 byte, hex, seperated by whitespace)");
    m_beatText->setMultiLine (false);
    m_beatText->setReturnKeyStartsNewLine (false);
    m_beatText->setReadOnly (true);
    m_beatText->setScrollbarsShown (true);
    m_beatText->setCaretVisible (false);
    m_beatText->setPopupMenuEnabled (true);
    m_beatText->setColour (TextEditor::backgroundColourId, Colour (0xffd0d0d0));
    m_beatText->setColour (TextEditor::outlineColourId, Colour (0xb2808080));
    m_beatText->setText ("4/4");

    addAndMakeVisible (m_measuresLabel3 = new Label ("measuresLabel",
                                                     "Pattern Setup:"));
    m_measuresLabel3->setTooltip ("(4 byte, hex, seperated by whitespace)");
    m_measuresLabel3->setFont (Font (15.00f, Font::plain));
    m_measuresLabel3->setJustificationType (Justification::centredLeft);
    m_measuresLabel3->setEditable (false, false, false);
    m_measuresLabel3->setColour (TextEditor::textColourId, Colours::black);
    m_measuresLabel3->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_patternNameLabel = new Label ("patternNameLabel",
                                                       "Name:"));
    m_patternNameLabel->setTooltip ("(4 byte, hex, seperated by whitespace)");
    m_patternNameLabel->setFont (Font (15.00f, Font::plain));
    m_patternNameLabel->setJustificationType (Justification::centredLeft);
    m_patternNameLabel->setEditable (false, false, false);
    m_patternNameLabel->setColour (TextEditor::textColourId, Colours::black);
    m_patternNameLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (m_patternNameText = new TextEditor ("patternNameText"));
    m_patternNameText->setTooltip ("(4 byte, hex, seperated by whitespace)");
    m_patternNameText->setMultiLine (false);
    m_patternNameText->setReturnKeyStartsNewLine (false);
    m_patternNameText->setReadOnly (true);
    m_patternNameText->setScrollbarsShown (true);
    m_patternNameText->setCaretVisible (false);
    m_patternNameText->setPopupMenuEnabled (true);
    m_patternNameText->setColour (TextEditor::backgroundColourId, Colour (0xffd0d0d0));
    m_patternNameText->setColour (TextEditor::outlineColourId, Colour (0xb2808080));
    m_patternNameText->setText ("EMPTY PATTERN");

    addAndMakeVisible (m_receivedSysExList = new ListBox());
    m_receivedSysExList->setName ("receivedSysExList");

    addAndMakeVisible (m_imageViewComponent = new ImageComponent());
    m_imageViewComponent->setName ("imageViewComponent");

    addAndMakeVisible (m_searchDevicesButton = new TextButton ("searchDevicesButton"));
    m_searchDevicesButton->setButtonText ("Search");
    m_searchDevicesButton->addListener (this);

    addAndMakeVisible (m_deviceToUseComboBox = new ComboBox ("deviceIdConnectBox"));
    m_deviceToUseComboBox->setEditableText (false);
    m_deviceToUseComboBox->setJustificationType (Justification::centredLeft);
    m_deviceToUseComboBox->setTextWhenNothingSelected ("Select a device ID first");
    m_deviceToUseComboBox->setTextWhenNoChoicesAvailable ("(no compatible devices found)");
    m_deviceToUseComboBox->addListener (this);

    addAndMakeVisible (m_getPatternButton = new TextButton ("sendButton"));
    m_getPatternButton->setButtonText ("Request Temporary Pattern Data");
    m_getPatternButton->addListener (this);

    addAndMakeVisible (m_saveMidiFileButton = new TextButton ("saveMidiFileButton"));
    m_saveMidiFileButton->setButtonText ("Save MIDI File...");
    m_saveMidiFileButton->addListener (this);

    addAndMakeVisible (m_menuBar = new MenuBarComponent (this));
    m_menuBar->setName ("menuBar");

    addAndMakeVisible (m_dragSmfImageButton = new ImageButton ("dragSmfImageButton"));
    m_dragSmfImageButton->setTooltip ("Drag and Drop as Standard MIDI File (.mid)");
    m_dragSmfImageButton->setButtonText (String::empty);

    m_dragSmfImageButton->setImages (false, true, true,
                                     ImageCache::getFromMemory (audioxmidi_png, audioxmidi_pngSize), 0.700f, Colour (0x00000000),
                                     ImageCache::getFromMemory (audioxmidi_png, audioxmidi_pngSize), 1.000f, Colour (0x00000000),
                                     ImageCache::getFromMemory (audioxmidi_png, audioxmidi_pngSize), 1.000f, Colour (0x00000000));
    addAndMakeVisible (component = new MFXEditor());

    //[UserPreSize]

	m_dragSmfImageButton->setMouseCursor(MouseCursor::DraggingHandCursor);
	m_dragSmfImageButton->setVisible(false);
	m_dragSmfImageButton->addMouseListener(this,false);
	m_draggingFileToExternalAppActive = false;

	m_loadedMessagesListModel = nullptr;

	m_getPatternButton->setCommandToTrigger(applicationCommandManager, CommandIDs::grooveBoxLoadPattern, true);
	m_saveMidiFileButton->setCommandToTrigger(applicationCommandManager, CommandIDs::fileExportPattern, true);

	m_imageViewComponent->setImagePlacement(RectanglePlacement::fillDestination);

	// load graphics and images once
	m_logoDrawable = Drawable::createFromImageData(BinaryData::grooveboxLogo_svg, BinaryData::grooveboxLogo_svgSize);

	JPEGImageFormat jpegImgFormat;
	PNGImageFormat pngImgFormat;
	ScopedPointer<MemoryInputStream> memInputStream = new MemoryInputStream(BinaryData::brushedSteel_jpg, BinaryData::brushedSteel_jpgSize, false);
	img_backgroundTexture = new Image(jpegImgFormat.decodeImage(*memInputStream));
	memInputStream = new MemoryInputStream(BinaryData::noConnection_png, BinaryData::noConnection_pngSize, false);
	img_noConnection = new Image(pngImgFormat.decodeImage(*memInputStream));
	memInputStream = new MemoryInputStream(BinaryData::mc505_png, BinaryData::mc505_pngSize, false);
	img_mc505 = new Image(pngImgFormat.decodeImage(*memInputStream));
	memInputStream = new MemoryInputStream(BinaryData::jx305_png, BinaryData::jx305_pngSize, false);
	img_jx305 = new Image(pngImgFormat.decodeImage(*memInputStream));
	memInputStream = new MemoryInputStream(BinaryData::mc307_png, BinaryData::mc307_pngSize, false);
	img_mc307 = new Image(pngImgFormat.decodeImage(*memInputStream));
	memInputStream = new MemoryInputStream(BinaryData::d2_png, BinaryData::d2_pngSize, false);
	img_d2 = new Image(pngImgFormat.decodeImage(*memInputStream));

	m_decodedNonEmptyEventsString = String::empty;

	StringArray midiInNames(MidiInput::getDevices());
	m_midiInComboBox->addItemList(MidiInput::getDevices(),1);
	m_midiInComboBox->setTextWhenNothingSelected(midiInNames[MidiInput::getDefaultDeviceIndex() + 1]);

	StringArray midiOutNames(MidiOutput::getDevices());
	m_midiOutComboBox->addItemList(MidiOutput::getDevices(), 1);
	m_midiOutComboBox->setTextWhenNothingSelected(midiOutNames[MidiOutput::getDefaultDeviceIndex() + 1]);

    //[/UserPreSize]

    setSize (800, 640);


    //[Constructor] You can add your own custom stuff here..
	m_afterConstructor = false;
	if (preferredMidiInId >= 0) m_midiInComboBox->setSelectedItemIndex(preferredMidiInId, dontSendNotification);
	if (preferredMidiOutId >= 0) m_midiOutComboBox->setSelectedItemIndex(preferredMidiOutId, dontSendNotification);

	m_receivedSysExList->setColour(ListBox::outlineColourId, Colour(((uint32)0xB2 << 24) | ((uint32)0x80 << 16) | ((uint32)0x80 << 8) | (uint32)0x80));
	m_receivedSysExList->setOutlineThickness(1);
	m_receivedSysExList->setMinimumContentWidth(1600);

	m_currentPattern = nullptr;

	buttonClicked(m_searchDevicesButton);

	
	//commandManager.registerAllCommandsForTarget(JUCEApplication::getInstance());
	// this lets the command manager use keypresses that arrive in our window to send out commands
	addKeyListener(applicationCommandManager->getKeyMappings());

	// This registers all of our commands with the command manager but has to be done after the window has
	// been created so we can find the number of rendering engines available
	applicationCommandManager->registerAllCommandsForTarget(this);

	applicationCommandManager->setFirstCommandTarget(this);
	m_afterConstructor = true;
    //[/Constructor]
}

PatternTab::~PatternTab()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
	m_loadedMessagesListArray.clear(false);
	m_patternFile = nullptr;
    //[/Destructor_pre]

    m_receivedSysExLabel = nullptr;
    m_deviceIdLabel = nullptr;
    m_midiInComboBox = nullptr;
    m_midiInLabel = nullptr;
    m_midiOutComboBox = nullptr;
    m_midiOutLabel = nullptr;
    m_bpmLabel = nullptr;
    m_bpmText = nullptr;
    m_measuresLabel = nullptr;
    m_measuresText = nullptr;
    m_beatLabel = nullptr;
    m_beatText = nullptr;
    m_measuresLabel3 = nullptr;
    m_patternNameLabel = nullptr;
    m_patternNameText = nullptr;
    m_receivedSysExList = nullptr;
    m_imageViewComponent = nullptr;
    m_searchDevicesButton = nullptr;
    m_deviceToUseComboBox = nullptr;
    m_getPatternButton = nullptr;
    m_saveMidiFileButton = nullptr;
    m_menuBar = nullptr;
    m_dragSmfImageButton = nullptr;
    component = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void PatternTab::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colours::whitesmoke);

    //[UserPaint] Add your own custom painting code here..
	g.setTiledImageFill(*img_backgroundTexture, 0, 0, 0.5f);
	g.fillAll();
	m_logoDrawable->drawWithin(g, Rectangle<float>(16, 40, 248, 48), RectanglePlacement::fillDestination, 1.0f);
	g.setColour(Colours::white);
	g.fillRect(m_imageViewComponent->getBounds());
	g.setColour(Colours::darkgrey);
	g.drawRect(m_imageViewComponent->getBounds());
    //[/UserPaint]
}

void PatternTab::resized()
{
    m_receivedSysExLabel->setBounds (8, 304, 408, 24);
    m_deviceIdLabel->setBounds (getWidth() - 360 - 152, 120, 152, 24);
    m_midiInComboBox->setBounds (getWidth() - 288 - 176, 40, 176, 24);
    m_midiInLabel->setBounds (getWidth() - 464 - 72, 40, 72, 24);
    m_midiOutComboBox->setBounds (getWidth() - 288 - 176, 72, 176, 24);
    m_midiOutLabel->setBounds (getWidth() - 464 - 72, 72, 72, 24);
    m_bpmLabel->setBounds (640, 256, 96, 24);
    m_bpmText->setBounds (744, 256, 48, 24);
    m_measuresLabel->setBounds (448, 256, 136, 24);
    m_measuresText->setBounds (592, 256, 32, 24);
    m_beatLabel->setBounds (336, 256, 48, 24);
    m_beatText->setBounds (392, 256, 40, 24);
    m_measuresLabel3->setBounds (8, 256, 104, 24);
    m_patternNameLabel->setBounds (128, 256, 56, 24);
    m_patternNameText->setBounds (192, 256, 128, 24);
    m_receivedSysExList->setBounds (8, 328, getWidth() - 448, 392);
    m_imageViewComponent->setBounds (getWidth() - 8 - 264, 32, 264, 176);
    m_searchDevicesButton->setBounds (getWidth() - 290 - 62, 120, 62, 24);
    m_deviceToUseComboBox->setBounds (getWidth() - 288 - 224, 152, 224, 24);
    m_getPatternButton->setBounds (8, 224, 312, 24);
    m_saveMidiFileButton->setBounds (344, 224, 176, 24);
    m_menuBar->setBounds (0, 0, getWidth() - 0, 24);
    m_dragSmfImageButton->setBounds (getWidth() - 24 - 64, 128, 64, 64);
    component->setBounds (getWidth() - 432, 296, 432, 488);
    //[UserResized] Add your own custom resize handling here..
	m_logoDrawable->setBounds(16, 16, m_midiInLabel->getX() - 16, m_getPatternButton->getY() - 16);
	m_logoDrawable->setTransformToFit(m_logoDrawable->getBounds().toFloat(), RectanglePlacement::onlyReduceInSize);
    //[/UserResized]
}

void PatternTab::comboBoxChanged (ComboBox* comboBoxThatHasChanged)
{
    //[UsercomboBoxChanged_Pre]
    //[/UsercomboBoxChanged_Pre]

    if (comboBoxThatHasChanged == m_midiInComboBox)
    {
        //[UserComboBoxCode_m_midiInComboBox] -- add your combo box handling code here..
		preferredMidiInId = m_midiInComboBox->getSelectedId() > 0 ? m_midiInComboBox->getSelectedId() - 1 : MidiInput::getDefaultDeviceIndex();
		appProperties->getUserSettings()->setValue("MidiInId", preferredMidiInId);
		appProperties->saveIfNeeded();
        //[/UserComboBoxCode_m_midiInComboBox]
    }
    else if (comboBoxThatHasChanged == m_midiOutComboBox)
    {
        //[UserComboBoxCode_m_midiOutComboBox] -- add your combo box handling code here..
		preferredMidiOutId = m_midiOutComboBox->getSelectedId()>0 ? m_midiOutComboBox->getSelectedId() - 1 : MidiOutput::getDefaultDeviceIndex();
		appProperties->getUserSettings()->setValue("MidiOutId", preferredMidiOutId);
		appProperties->saveIfNeeded();
        //[/UserComboBoxCode_m_midiOutComboBox]
    }
    else if (comboBoxThatHasChanged == m_deviceToUseComboBox)
    {
        //[UserComboBoxCode_m_deviceToUseComboBox] -- add your combo box handling code here..
		grooveboxConnector->setActiveConnection((uint8)m_deviceToUseComboBox->getSelectedId());
		GrooveboxConnector::GrooveBoxConnectionEntry* connection = nullptr;
		if ((connection = grooveboxConnector->getActiveConnection()) != nullptr)
		{
			switch (connection->deviceFamilyNumberCode)
			{
			case GrooveboxConnector::Model_MC_505: m_imageViewComponent->setImage(*img_mc505); break;
			case GrooveboxConnector::Model_JX_305: m_imageViewComponent->setImage(*img_jx305); break;
			case GrooveboxConnector::Model_MC_307: m_imageViewComponent->setImage(*img_mc307); break;
			case GrooveboxConnector::Model_D2: m_imageViewComponent->setImage(*img_d2); break;
			default: m_imageViewComponent->setImage(*img_noConnection); break;
			}
		}
		else
		{
			m_imageViewComponent->setImage(*img_noConnection);
		}
        //[/UserComboBoxCode_m_deviceToUseComboBox]
    }

    //[UsercomboBoxChanged_Post]
    //[/UsercomboBoxChanged_Post]
}

void PatternTab::buttonClicked (Button* buttonThatWasClicked)
{
    //[UserbuttonClicked_Pre]
    //[/UserbuttonClicked_Pre]

    if (buttonThatWasClicked == m_searchDevicesButton)
    {
        //[UserButtonCode_m_searchDevicesButton] -- add your button handler code here..
		m_deviceToUseComboBox->clear();
		int id (grooveboxConnector->refreshConnections(m_afterConstructor));
		if (id > 0)
		{
			for (int i = 0; i < grooveboxConnector->getConnections().size(); i++)
			{
				m_deviceToUseComboBox->addItem(String(grooveboxConnector->getConnections()[i]->deviceId+1) + " " + grooveboxConnector->getConnections()[i]->getGrooveboxModelAsString(), grooveboxConnector->getConnections()[i]->deviceId);
			}
			if (m_deviceToUseComboBox->indexOfItemId(grooveboxConnector->getActiveDeviceId() >= 0))
			{
				m_deviceToUseComboBox->setSelectedId(grooveboxConnector->getActiveDeviceId(),sendNotification);
			}
		}
		else
		{
			m_imageViewComponent->setImage(*img_noConnection);
		}
		applicationCommandManager->commandStatusChanged();
        //[/UserButtonCode_m_searchDevicesButton]
    }
    else if (buttonThatWasClicked == m_getPatternButton)
    {
        //[UserButtonCode_m_getPatternButton] -- add your button handler code here..
		// not used any more... instead a command is triggered
        //[/UserButtonCode_m_getPatternButton]
    }
    else if (buttonThatWasClicked == m_saveMidiFileButton)
    {
        //[UserButtonCode_m_saveMidiFileButton] -- add your button handler code here..
		// not used any more... instead a command is triggered
        //[/UserButtonCode_m_saveMidiFileButton]
    }

    //[UserbuttonClicked_Post]
    //[/UserbuttonClicked_Post]
}

void PatternTab::mouseDrag (const MouseEvent& e)
{
    //[UserCode_mouseDrag] -- Add your code here...
	if (e.eventComponent == m_dragSmfImageButton)
	{
		//startDragging("Midi File", m_dragSmfImageButton);
		if (m_currentPattern != nullptr)
		{
			File selectedFile = File(appProperties->getUserSettings()->getFile().getParentDirectory().getFullPathName() + File::separatorString + m_currentPattern->getSetup()->getPatternName().trim() + ".mid");
			if (selectedFile.existsAsFile()) selectedFile.deleteFile();
			ScopedPointer<OutputStream> saveStream = selectedFile.createOutputStream();
			ScopedPointer<MidiFile> midiFile = m_currentPattern->convertToMidiFile();
			midiFile->writeTo(*saveStream);
			StringArray files;
			files.add(selectedFile.getFullPathName());
			m_draggingFileToExternalAppActive = true;
			performExternalDragDropOfFiles(files, false);
			m_draggingFileToExternalAppActive = false;
		}
	}
    //[/UserCode_mouseDrag]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...

//==============================================================================
// The following methods implement the ApplicationCommandTarget interface, allowing
// this window to publish a set of actions it can perform, and which can be mapped
// onto menus, keypresses, etc.

ApplicationCommandTarget* PatternTab::getNextCommandTarget()
{
	// this will return the next parent component that is an ApplicationCommandTarget (in this
	// case, there probably isn't one, but it's best to use this method in your own apps).
	return findFirstTargetParentComponent();
}

void PatternTab::getAllCommands(Array <CommandID>& commands)
{
	// this returns the set of all commands that this target can perform..
	const CommandID ids[] = {
		PatternTab::fileOpenPattern,
		PatternTab::fileImportPattern,
		PatternTab::fileSavePattern,
		PatternTab::fileExportPattern,
		PatternTab::fileQuit,
		PatternTab::grooveBoxLoadPattern
	};

	commands.addArray(ids, numElementsInArray(ids));
}

void PatternTab::getCommandInfo(CommandID commandID, ApplicationCommandInfo& result)
{
	const String fileCategory("File");

	switch (commandID)
	{
	case PatternTab::fileOpenPattern:
		result.setInfo("Open SysEx Pattern File...", "Opens a raw pattern file, either binary SysEx (.syx) or Hex SysEx text (.txt)", fileCategory, 0);
		result.addDefaultKeypress('o', ModifierKeys::commandModifier);
		break;
	case PatternTab::fileImportPattern:
		result.setInfo("Import Pattern from MIDI File", "Tries to extract pattern data from a Standard MIDI File (.mid)", fileCategory, 0);
		result.addDefaultKeypress('i', ModifierKeys::commandModifier);
		result.setActive(true);
		break;
	case PatternTab::fileSavePattern:
		result.setInfo("Save Pattern as SysEx...", "Saves a pattern file as raw data, either binary SysEx (.syx) or Hex SysEx text (.txt)", fileCategory, 0);
		result.addDefaultKeypress('s', ModifierKeys::commandModifier);
		result.setActive(m_currentPattern!=nullptr && m_currentPattern->isNotEmpty());
		break;
	case PatternTab::fileExportPattern:
		result.setInfo("Export Pattern as MIDI...", "Converts pattern to Standard MIDI File (.mid)", fileCategory, 0);
		result.addDefaultKeypress('e', ModifierKeys::commandModifier);
		if (m_currentPattern != nullptr && m_currentPattern->isNotEmpty())
		{
			result.setActive(true);
			m_dragSmfImageButton->setVisible(true);
		}
		else
		{
			result.setActive(false);
			m_dragSmfImageButton->setVisible(false);
		}
		break;
	case PatternTab::fileQuit:
		result.setInfo("Quit", "Close application.", fileCategory, 0);
		result.addDefaultKeypress(KeyPress::F4Key, ModifierKeys::altModifier);
		result.addDefaultKeypress('q', ModifierKeys::commandModifier);
		break;
	case PatternTab::grooveBoxLoadPattern:
		result.setInfo("Request Pattern", "Request temporary pattern data from groovebox.", fileCategory, 0);
		result.addDefaultKeypress('r', ModifierKeys::commandModifier);
		result.setActive(grooveboxConnector->getActiveConnection() != nullptr);
	default:
		break;
	}
}

bool PatternTab::perform(const InvocationInfo& info)
{
	FileChooser fileChooser("Open SysEx pattern file (Binary System Exclusive or Hex SysEx Text)", File::getSpecialLocation(File::userHomeDirectory), "*.syx;*.txt");
	switch (info.commandID)
	{
	case CommandIDs::fileOpenPattern:
		if (fileChooser.browseForFileToOpen())
		{
			loadFile(fileChooser.getResult());
		}
		break;
	case CommandIDs::fileImportPattern:
		// TODO: import from midi (convert midi to groovebox sysex)
		break;
	case CommandIDs::fileSavePattern:
		saveAsSysExFile();
		break;
	case CommandIDs::fileExportPattern:
		exportAsMidiFile();
		break;
	case CommandIDs::fileQuit:
		if (MainWindow* mainWindow = dynamic_cast<MainWindow*>(getTopLevelComponent()))
		{
			mainWindow->closeButtonPressed();
		}
		break;
	case CommandIDs::grooveBoxLoadPattern:
		loadFromGroovebox();
		break;
	default:
		return false;
	}
	return true;
}

//==============================================================================
// The following method implement the MenuBarModel interface.

StringArray PatternTab::getMenuBarNames()
{
	const char* const names[] = { "File", "groovebox", nullptr };

	return StringArray(names);
}

PopupMenu PatternTab::getMenuForIndex(int topLevelMenuIndex, const String &/*menuName*/)
{
	PopupMenu menu;

	if (topLevelMenuIndex == 0)
	{
		menu.addCommandItem(applicationCommandManager, CommandIDs::fileOpenPattern);
		menu.addCommandItem(applicationCommandManager, CommandIDs::fileSavePattern);
		menu.addSeparator();
		menu.addCommandItem(applicationCommandManager, CommandIDs::fileImportPattern);
		menu.addCommandItem(applicationCommandManager, CommandIDs::fileExportPattern);
		menu.addSeparator();
		menu.addCommandItem(applicationCommandManager, CommandIDs::fileQuit);
	}
	else if (topLevelMenuIndex == 1)
	{
		menu.addCommandItem(applicationCommandManager, CommandIDs::grooveBoxLoadPattern);
	}

	return menu;
}

void PatternTab::menuItemSelected(int /*menuItemID*/, int /*topLevelMenuIndex*/)
{
	// most of our menu items are invoked automatically as commands, but we can handle the
	// other special cases here..
}

//==============================================================================
// The following method implement the FileDragAndDropTarget interface.
bool PatternTab::isInterestedInFileDrag(const StringArray &files)
{
	if (!m_draggingFileToExternalAppActive && files.size() > 0)
	{
		if (files[0].endsWithIgnoreCase(".syx") || files[0].endsWithIgnoreCase(".txt") || files[0].endsWithIgnoreCase(".mid"))
			return true;
	}
	return false;
}

void PatternTab::filesDropped(const StringArray &files, int /*x*/, int /*y*/)
{
	if (files.size() > 0)
	{
		File draggedFile(files[0]);
		if (draggedFile.existsAsFile())
		{
			loadFile(draggedFile);
		}
	}
}
//==============================================================================

void PatternTab::loadFromGroovebox()
{
	if (grooveboxConnector->getActiveDeviceId() > 0)
	{
		// remove listBoxModel first
		m_loadedMessagesListArray.clear(false);
		m_receivedSysExList->setModel(m_loadedMessagesListModel = nullptr);
		// new pattern
		m_currentPattern = new GrooveboxPattern(grooveboxConnector->getActiveDeviceId());
		// load current pattern. if no success loading: show empty pattern
		if (!m_currentPattern->loadFromGroovebox())
		{
			m_patternNameText->setText("EMPTY PATTERN");
			m_beatText->setText("4/4");
			m_measuresText->setText("4");
			m_bpmText->setText("120.0");
			AlertWindow::showMessageBox(AlertWindow::WarningIcon, TRANS("Error getting pattern data"), TRANS("No pattern or pattern data was retrieved."));
		}
		else // if success
		{
			if (m_currentPattern->getSetup() != nullptr)
			{
				m_patternNameText->setText(m_currentPattern->getSetup()->getPatternName(), dontSendNotification);
				m_beatText->setText(String(m_currentPattern->getSetup()->getBeatNumerator()) + "/" + String(m_currentPattern->getSetup()->getBeatDenominator()), dontSendNotification);
				m_measuresText->setText(String(m_currentPattern->getSetup()->getNumMeasures()), dontSendNotification);
				m_bpmText->setText(String(m_currentPattern->getSetup()->getBPM(), 1), dontSendNotification);
			}
			// set list box model:
			m_loadedMessagesListArray.addArray(m_currentPattern->getSetup()->getSetupSysExMessages());
			m_loadedMessagesListArray.addArray(m_currentPattern->getSequenceSysExMessages());
			m_receivedSysExList->setModel(m_loadedMessagesListModel = new SysExMessagesArrayListBoxModel(&m_loadedMessagesListArray, m_receivedSysExList));
			m_receivedSysExList->setMinimumContentWidth(1600);
		}
	}
	else
	{
		AlertWindow::showMessageBox(AlertWindow::WarningIcon, TRANS("No groovebox connected"), TRANS("Please connect and switch on your groovebox first."));
	}
	applicationCommandManager->commandStatusChanged();
}

void PatternTab::loadFile(const File &file)
{
	if (file.getFileExtension().toLowerCase() != ".syx" && file.getFileExtension().toLowerCase() != ".txt")
	{
		AlertWindow::showMessageBox(AlertWindow::WarningIcon, "File extension not supported", "Only the folling file extensions are supported:\r\n" +
			String(CharPointer_UTF8("\xe2\x80\xa2")) + " .syx\t(Binary System Exclusive)\r\n" +
			String(CharPointer_UTF8("\xe2\x80\xa2")) + " .txt\t(Hex SysEx Text)\r\n" +
			String(CharPointer_UTF8("\xe2\x80\xa2")) + " .mid\t(Standard MIDI file)"
			);
	}
	else
	{
		// remove listBoxModel first
		m_loadedMessagesListArray.clear(false);
		m_receivedSysExList->setModel(m_loadedMessagesListModel = nullptr);
		// new pattern
		m_currentPattern = new GrooveboxPattern(grooveboxConnector->getActiveDeviceId());
		// AlertWindow::showMessageBox(AlertWindow::InfoIcon, "Load pattern file", "Load the following pattern file:\r\n" + String(CharPointer_UTF8("\xe2\x80\xa2")) + " " + file.getFullPathName());
		bool loadedSucessfully(false);
		if (file.getFileExtension().toLowerCase() == ".syx")
		{
			loadedSucessfully = m_currentPattern->loadBinarySysExFile(file);
			loadedSucessfully = grooveboxMemory->loadBinarySysExFile(file);
		}
		else if (file.getFileExtension().toLowerCase() == ".txt")
		{
			loadedSucessfully = m_currentPattern->loadHexTxtSysExFile(file);
			loadedSucessfully = grooveboxMemory->loadHexTxtSysExFile(file);
		}
		else if (file.getFileExtension().toLowerCase() == ".mid")
		{
			loadedSucessfully = m_currentPattern->loadStandardMidiFile(file);
		}
		// load current pattern. if no success loading: show empty pattern
		if (!loadedSucessfully)
		{
			m_patternNameText->setText("EMPTY PATTERN");
			m_beatText->setText("4/4");
			m_measuresText->setText("4");
			m_bpmText->setText("120.0");
			AlertWindow::showMessageBox(AlertWindow::WarningIcon, TRANS("Error getting pattern data"), TRANS("No pattern or pattern data was retrieved."));
		}
		else // if success
		{
			if (m_currentPattern->getSetup() != nullptr)
			{
				m_patternNameText->setText(m_currentPattern->getSetup()->getPatternName(), dontSendNotification);
				m_beatText->setText(String(m_currentPattern->getSetup()->getBeatNumerator()) + "/" + String(m_currentPattern->getSetup()->getBeatDenominator()), dontSendNotification);
				m_measuresText->setText(String(m_currentPattern->getSetup()->getNumMeasures()), dontSendNotification);
				m_bpmText->setText(String(m_currentPattern->getSetup()->getBPM(), 1), dontSendNotification);
			}
			// set list box model:
			m_loadedMessagesListArray.addArray(m_currentPattern->getSetup()->getSetupSysExMessages());
			m_loadedMessagesListArray.addArray(m_currentPattern->getSequenceSysExMessages());
			m_receivedSysExList->setModel(m_loadedMessagesListModel = new SysExMessagesArrayListBoxModel(&m_loadedMessagesListArray, m_receivedSysExList));
			m_receivedSysExList->setMinimumContentWidth(1600);
		}
		applicationCommandManager->commandStatusChanged();
	}
}

void PatternTab::saveAsSysExFile()
{
	if (m_currentPattern != nullptr)
	{
		File defaultFile = File(File::getSpecialLocation(File::userHomeDirectory).getFullPathName() + File::separatorString + m_currentPattern->getSetup()->getPatternName().trim() + ".syx");
		FileChooser myChooser(TRANS("Save pattern, either binary SysEx (.syx) or Hex SysEx text (.txt)"),
			defaultFile,
			"*.syx;*.txt");
		if (myChooser.browseForFileToSave(true))
		{
			File selectedFile(myChooser.getResult());
			if (selectedFile.existsAsFile()) selectedFile.deleteFile();
			ScopedPointer<OutputStream> saveStream = selectedFile.createOutputStream();
			uint8* currentSysExPtr;
			uint32 currentSysExLen;
			// write sequence data
			for (int i = 0; i < m_currentPattern->getSequenceSysExMessages().size(); i++)
			{
				m_currentPattern->getSequenceSysExMessages()[i]->getAsSysExData(&currentSysExPtr, currentSysExLen);
				//DBG("Write Sequence SysEx to file: " + String::toHexString(currentSysExPtr, currentSysExLen).toUpperCase());
				if (selectedFile.getFileExtension().equalsIgnoreCase(".txt"))
				{
					saveStream->writeText(String::toHexString(currentSysExPtr, currentSysExLen).toUpperCase() + "\r\n", false, false);
				}
				else saveStream->write(currentSysExPtr, currentSysExLen);
			}
			// write setup data
			for (int i = 0; m_currentPattern->getSetup() != nullptr && i < m_currentPattern->getSetup()->getSetupSysExMessages().size(); i++)
			{
				m_currentPattern->getSetup()->getSetupSysExMessages()[i]->getAsSysExData(&currentSysExPtr, currentSysExLen);
				//DBG("Write Setup SysEx to file: " + String::toHexString(currentSysExPtr, currentSysExLen).toUpperCase());
				if (selectedFile.getFileExtension().equalsIgnoreCase(".txt"))
				{
					saveStream->writeText(String::toHexString(currentSysExPtr, currentSysExLen).toUpperCase()+"\r\n",false,false);
				}
				else saveStream->write(currentSysExPtr, currentSysExLen);
			}
		}
	}
}

void PatternTab::exportAsMidiFile()
{
	if (m_currentPattern != nullptr)
	{
		File defaultFile = File(File::getSpecialLocation(File::userHomeDirectory).getFullPathName() + File::separatorString + m_currentPattern->getSetup()->getPatternName().trim() + ".mid");
		FileChooser myChooser(TRANS("Export as MIDI File"),
			defaultFile,
			"*.mid");
		if (myChooser.browseForFileToSave(true))
		{
			File selectedFile(myChooser.getResult());
			if (selectedFile.existsAsFile()) selectedFile.deleteFile();
			ScopedPointer<OutputStream> saveStream = selectedFile.createOutputStream();
			ScopedPointer<MidiFile> midiFile = m_currentPattern->convertToMidiFile();
			midiFile->writeTo(*saveStream);
		}
	}
}

//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Introjucer information section --

    This is where the Introjucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="PatternTab" componentName=""
                 parentClasses="public Component, public ApplicationCommandManager, public ApplicationCommandTarget, public MenuBarModel, public FileDragAndDropTarget, public DragAndDropContainer"
                 constructorParams="" variableInitialisers="" snapPixels="8" snapActive="1"
                 snapShown="1" overlayOpacity="0.330" fixedSize="0" initialWidth="800"
                 initialHeight="640">
  <METHODS>
    <METHOD name="mouseDrag (const MouseEvent&amp; e)"/>
  </METHODS>
  <BACKGROUND backgroundColour="fff5f5f5"/>
  <LABEL name="receivedSysExLabel" id="4737d9b1518cb0c2" memberName="m_receivedSysExLabel"
         virtualName="" explicitFocusOrder="0" pos="8 304 408 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Received SysEx (DT1):" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" bold="0" italic="0" justification="33"/>
  <LABEL name="deviceIdLabel" id="65b602092445c531" memberName="m_deviceIdLabel"
         virtualName="" explicitFocusOrder="0" pos="360Rr 120 152 24"
         tooltip="(17 .. 32, as shown on device display)" edTextCol="ff000000"
         edBkgCol="0" labelText="connected groovebox:" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" bold="0" italic="0" justification="33"/>
  <COMBOBOX name="midiInComboBox" id="917638ab10b9bff1" memberName="m_midiInComboBox"
            virtualName="" explicitFocusOrder="0" pos="288Rr 40 176 24" editable="0"
            layout="33" items="" textWhenNonSelected="" textWhenNoItems="(no choices)"/>
  <LABEL name="midiInLabel" id="1fb21c53016c00be" memberName="m_midiInLabel"
         virtualName="" explicitFocusOrder="0" pos="464Rr 40 72 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Midi In:" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         bold="0" italic="0" justification="33"/>
  <COMBOBOX name="midiOutComboBox" id="9b6d2ada3deafb58" memberName="m_midiOutComboBox"
            virtualName="" explicitFocusOrder="0" pos="288Rr 72 176 24" editable="0"
            layout="33" items="" textWhenNonSelected="" textWhenNoItems="(no choices)"/>
  <LABEL name="midiOutLabel" id="b10a8e943634f13a" memberName="m_midiOutLabel"
         virtualName="" explicitFocusOrder="0" pos="464Rr 72 72 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Midi Out:" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         bold="0" italic="0" justification="33"/>
  <LABEL name="bpmLabel" id="35ab1e98fdf77369" memberName="m_bpmLabel"
         virtualName="" explicitFocusOrder="0" pos="640 256 96 24" tooltip="(4 byte, hex, seperated by whitespace)"
         edTextCol="ff000000" edBkgCol="0" labelText="Tempo (BPM):" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" bold="0" italic="0" justification="33"/>
  <TEXTEDITOR name="bpmText" id="d621e92137923d8e" memberName="m_bpmText" virtualName=""
              explicitFocusOrder="0" pos="744 256 48 24" tooltip="(4 byte, hex, seperated by whitespace)"
              bkgcol="ffd0d0d0" outlinecol="b2808080" initialText="120.0" multiline="0"
              retKeyStartsLine="0" readonly="1" scrollbars="1" caret="0" popupmenu="1"/>
  <LABEL name="measuresLabel" id="c48296727a3f0042" memberName="m_measuresLabel"
         virtualName="" explicitFocusOrder="0" pos="448 256 136 24" tooltip="(4 byte, hex, seperated by whitespace)"
         edTextCol="ff000000" edBkgCol="0" labelText="Length in Measures:"
         editableSingleClick="0" editableDoubleClick="0" focusDiscardsChanges="0"
         fontname="Default font" fontsize="15" bold="0" italic="0" justification="33"/>
  <TEXTEDITOR name="measuresText" id="459fa482571aa848" memberName="m_measuresText"
              virtualName="" explicitFocusOrder="0" pos="592 256 32 24" tooltip="(4 byte, hex, seperated by whitespace)"
              bkgcol="ffd0d0d0" outlinecol="b2808080" initialText="4" multiline="0"
              retKeyStartsLine="0" readonly="1" scrollbars="1" caret="0" popupmenu="1"/>
  <LABEL name="measuresLabel" id="982dd1c0902bdcb6" memberName="m_beatLabel"
         virtualName="" explicitFocusOrder="0" pos="336 256 48 24" tooltip="(4 byte, hex, seperated by whitespace)"
         edTextCol="ff000000" edBkgCol="0" labelText="Beat:" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" bold="0" italic="0" justification="33"/>
  <TEXTEDITOR name="beatText" id="40b80ef540e69d5e" memberName="m_beatText"
              virtualName="" explicitFocusOrder="0" pos="392 256 40 24" tooltip="(4 byte, hex, seperated by whitespace)"
              bkgcol="ffd0d0d0" outlinecol="b2808080" initialText="4/4" multiline="0"
              retKeyStartsLine="0" readonly="1" scrollbars="1" caret="0" popupmenu="1"/>
  <LABEL name="measuresLabel" id="cd690b5f396110f4" memberName="m_measuresLabel3"
         virtualName="" explicitFocusOrder="0" pos="8 256 104 24" tooltip="(4 byte, hex, seperated by whitespace)"
         edTextCol="ff000000" edBkgCol="0" labelText="Pattern Setup:"
         editableSingleClick="0" editableDoubleClick="0" focusDiscardsChanges="0"
         fontname="Default font" fontsize="15" bold="0" italic="0" justification="33"/>
  <LABEL name="patternNameLabel" id="3adefa6b7c5bad59" memberName="m_patternNameLabel"
         virtualName="" explicitFocusOrder="0" pos="128 256 56 24" tooltip="(4 byte, hex, seperated by whitespace)"
         edTextCol="ff000000" edBkgCol="0" labelText="Name:" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" bold="0" italic="0" justification="33"/>
  <TEXTEDITOR name="patternNameText" id="f85a59ae1b778ae" memberName="m_patternNameText"
              virtualName="" explicitFocusOrder="0" pos="192 256 128 24" tooltip="(4 byte, hex, seperated by whitespace)"
              bkgcol="ffd0d0d0" outlinecol="b2808080" initialText="EMPTY PATTERN"
              multiline="0" retKeyStartsLine="0" readonly="1" scrollbars="1"
              caret="0" popupmenu="1"/>
  <GENERICCOMPONENT name="receivedSysExList" id="93c14b7479ff5d1e" memberName="m_receivedSysExList"
                    virtualName="" explicitFocusOrder="0" pos="8 328 448M 392" class="ListBox"
                    params=""/>
  <GENERICCOMPONENT name="imageViewComponent" id="4485472e5d29f5b8" memberName="m_imageViewComponent"
                    virtualName="" explicitFocusOrder="0" pos="8Rr 32 264 176" class="ImageComponent"
                    params=""/>
  <TEXTBUTTON name="searchDevicesButton" id="ebd8589c7189fa14" memberName="m_searchDevicesButton"
              virtualName="" explicitFocusOrder="0" pos="290Rr 120 62 24" buttonText="Search"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <COMBOBOX name="deviceIdConnectBox" id="b72d9dc6a1898892" memberName="m_deviceToUseComboBox"
            virtualName="" explicitFocusOrder="0" pos="288Rr 152 224 24"
            editable="0" layout="33" items="" textWhenNonSelected="Select a device ID first"
            textWhenNoItems="(no compatible devices found)"/>
  <TEXTBUTTON name="sendButton" id="dd1f3dc10a40b071" memberName="m_getPatternButton"
              virtualName="" explicitFocusOrder="0" pos="8 224 312 24" buttonText="Request Temporary Pattern Data"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="saveMidiFileButton" id="544c57a2d5d00d96" memberName="m_saveMidiFileButton"
              virtualName="" explicitFocusOrder="0" pos="344 224 176 24" buttonText="Save MIDI File..."
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <GENERICCOMPONENT name="menuBar" id="3fba78e08ffb4662" memberName="m_menuBar" virtualName=""
                    explicitFocusOrder="0" pos="0 0 0M 24" class="MenuBarComponent"
                    params="this"/>
  <IMAGEBUTTON name="dragSmfImageButton" id="6a5f2f0b4329ef02" memberName="m_dragSmfImageButton"
               virtualName="" explicitFocusOrder="0" pos="24Rr 128 64 64" tooltip="Drag and Drop as Standard MIDI File (.mid)"
               buttonText="" connectedEdges="0" needsCallback="0" radioGroupId="0"
               keepProportions="1" resourceNormal="audioxmidi_png" opacityNormal="0.69999998807907104"
               colourNormal="0" resourceOver="audioxmidi_png" opacityOver="1"
               colourOver="0" resourceDown="audioxmidi_png" opacityDown="1"
               colourDown="0"/>
  <JUCERCOMP name="" id="1c042851e92cf4e0" memberName="component" virtualName=""
             explicitFocusOrder="0" pos="0Rr 296 432 488" sourceFile="MFxEditor.cpp"
             constructorParams=""/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif

//==============================================================================
// Binary resources - be careful not to edit any of these sections!

// JUCER_RESOURCE: audioxmidi_png, 3650, "../Resources/Audio-x-midi.png"
static const unsigned char resource_PatternTab_audioxmidi_png[] = { 137,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,0,64,0,0,0,64,8,6,0,0,0,170,105,113,222,0,0,0,4,115,66,73,84,8,8,8,8,124,8,100,136,
0,0,0,9,112,72,89,115,0,0,18,116,0,0,18,116,1,222,102,31,120,0,0,0,25,116,69,88,116,83,111,102,116,119,97,114,101,0,119,119,119,46,105,110,107,115,99,97,112,101,46,111,114,103,155,238,60,26,0,0,0,20,116,
69,88,116,65,117,116,104,111,114,0,74,97,107,117,98,32,83,116,101,105,110,101,114,230,251,247,47,0,0,0,33,116,69,88,116,83,111,117,114,99,101,0,104,116,116,112,58,47,47,106,105,109,109,97,99,46,109,117,
115,105,99,104,97,108,108,46,99,122,105,102,227,94,0,0,13,114,73,68,65,84,120,156,237,154,91,140,28,85,122,199,127,167,170,171,186,167,111,238,185,122,60,99,123,124,97,108,140,28,27,45,102,19,103,215,
44,6,194,70,129,152,181,18,32,171,85,150,132,125,137,18,241,192,83,86,32,69,44,138,131,149,240,176,81,44,180,139,120,89,180,43,91,40,144,44,236,18,131,181,206,42,144,197,104,33,144,101,6,152,49,182,199,
99,247,140,61,76,79,207,76,223,166,186,171,234,228,161,47,174,238,169,234,174,238,49,241,67,242,151,74,85,125,206,169,115,190,239,59,223,245,116,9,41,37,255,151,161,220,104,2,110,52,254,95,0,55,154,128,
27,141,64,171,1,207,61,247,92,84,85,213,191,86,85,245,144,162,40,26,128,170,170,8,33,16,66,0,32,165,68,74,137,101,89,181,103,219,182,107,151,179,223,182,109,128,218,179,219,123,126,231,113,246,55,204,
99,151,74,165,83,182,109,63,243,226,139,47,206,173,73,0,66,136,239,69,34,145,199,246,239,223,175,5,2,129,26,211,213,123,21,78,103,234,246,220,120,119,10,174,217,59,110,253,94,125,213,187,105,154,188,252,
242,203,55,79,79,79,15,2,223,108,198,159,31,1,252,209,109,183,221,166,109,221,186,149,98,177,232,214,95,91,184,81,40,141,12,181,139,102,239,53,235,83,85,149,112,56,172,30,57,114,228,129,86,107,248,17,
128,174,170,42,150,101,49,51,51,83,167,246,0,93,93,93,148,74,165,58,130,26,5,209,234,119,171,246,118,32,165,164,187,187,155,64,32,0,62,248,107,57,192,141,177,234,189,106,207,85,45,232,132,241,118,152,
118,106,91,179,49,237,204,217,82,0,110,11,180,106,255,34,53,160,213,152,118,205,173,35,13,112,123,118,243,3,55,74,3,218,129,47,1,52,46,234,84,249,3,7,14,144,76,38,17,66,160,40,138,103,148,112,226,142,
59,238,224,249,231,159,231,196,137,19,60,245,212,83,0,12,15,15,115,250,244,105,158,125,246,89,94,120,225,5,95,196,63,244,208,67,60,253,244,211,28,59,118,140,99,199,142,1,176,119,239,94,78,158,60,233,235,
125,240,33,128,170,157,87,209,200,160,97,24,172,172,172,248,94,16,224,212,169,83,0,20,139,69,50,153,12,0,217,108,22,128,76,38,195,242,242,178,175,121,206,156,57,83,163,161,250,78,46,151,171,245,251,49,
135,142,157,160,95,91,19,66,16,14,135,201,231,243,171,230,114,19,110,40,20,34,30,143,215,181,155,166,137,105,154,88,150,133,101,89,181,246,98,177,184,230,200,209,118,42,220,204,198,31,123,236,49,46,93,
186,196,221,119,223,93,107,219,189,123,55,147,147,147,28,61,122,212,215,252,79,60,241,4,19,19,19,181,107,114,114,146,243,231,207,51,61,61,77,50,153,228,241,199,31,175,141,117,203,75,188,104,243,66,91,
38,208,140,121,0,93,215,17,66,160,105,218,181,5,202,241,24,93,215,87,17,232,230,91,170,59,13,160,40,74,221,92,80,206,59,170,48,12,163,237,176,215,136,150,26,224,229,4,221,16,12,6,235,238,0,154,166,173,
18,138,115,238,70,60,243,204,51,140,140,140,48,50,50,194,195,15,63,92,99,176,122,57,5,208,76,3,252,194,151,0,156,104,166,5,110,204,86,159,27,5,224,21,18,91,249,22,167,38,89,150,181,102,31,112,93,77,192,
77,3,170,5,84,213,20,156,112,155,195,185,158,91,118,233,116,130,215,35,41,242,173,1,110,204,55,18,80,205,3,20,69,89,53,214,217,86,109,119,75,148,156,68,23,10,133,85,244,152,166,89,123,110,44,203,59,129,
47,13,104,86,15,248,65,59,169,175,179,109,113,113,145,177,177,177,186,186,255,226,197,139,181,126,85,85,155,174,123,93,243,0,167,58,182,155,7,120,181,55,50,208,168,61,83,83,83,220,117,215,93,158,115,87,
53,96,45,104,105,2,141,26,224,132,223,220,222,75,77,221,204,170,209,84,154,161,234,116,189,214,186,238,153,32,64,58,157,198,52,77,6,6,6,0,216,183,111,31,155,54,109,2,96,112,112,16,128,237,219,183,179,
127,255,126,84,85,101,207,158,61,0,244,247,247,115,240,224,65,224,154,39,31,25,25,225,224,193,131,148,74,37,134,134,134,16,66,176,107,215,46,238,189,247,222,218,209,88,245,248,75,85,85,52,77,67,211,52,
116,93,71,211,52,238,187,239,62,0,70,71,71,107,243,236,218,181,203,147,118,55,136,86,131,142,28,57,50,115,248,240,225,13,163,163,163,204,205,205,49,49,49,193,192,192,0,131,131,131,228,243,121,194,225,
112,237,44,174,54,169,139,159,248,34,171,196,70,30,194,225,48,179,179,179,60,249,228,147,165,227,199,143,235,30,175,1,29,84,131,27,55,110,164,167,167,103,85,229,215,24,45,252,48,239,247,156,160,21,156,
239,121,157,77,122,161,237,106,48,26,141,122,102,96,205,152,255,223,210,0,47,97,120,161,109,31,208,136,70,6,219,97,254,139,214,0,63,104,41,0,183,204,203,121,32,226,252,237,70,84,39,166,224,213,230,5,41,
37,133,194,50,169,116,146,133,197,25,150,51,115,76,93,250,4,109,221,111,2,143,252,213,224,164,37,229,122,211,226,193,19,63,188,250,102,227,187,190,125,128,47,143,234,67,27,252,62,55,34,147,93,96,97,49,
89,102,50,61,67,106,97,154,207,23,46,144,90,72,146,94,156,163,100,22,233,238,238,165,183,167,143,68,34,78,44,22,225,27,135,15,138,88,44,49,250,209,216,71,197,247,63,120,247,102,160,115,1,180,98,178,89,
134,216,74,32,82,74,178,185,84,153,177,116,146,84,250,50,243,11,211,204,205,95,96,97,49,201,210,114,10,203,50,137,70,163,244,246,246,146,88,23,35,22,143,114,211,104,15,95,138,111,39,26,237,38,18,94,135,
162,168,20,75,89,138,197,37,140,82,249,10,71,186,9,6,131,54,96,53,210,229,75,0,141,78,176,74,188,91,161,210,138,105,55,230,231,230,47,240,119,255,248,13,108,219,36,18,233,34,190,46,74,119,34,70,44,22,
229,166,157,61,196,99,91,136,69,19,68,194,9,116,45,130,101,21,43,204,45,87,24,189,196,213,244,56,197,171,75,20,205,44,82,214,211,27,212,18,72,41,81,16,171,25,241,35,0,167,6,52,75,107,27,125,66,227,120,
175,182,84,58,201,134,193,13,60,112,232,126,116,45,142,162,4,86,237,226,98,246,18,87,211,75,24,197,101,44,219,240,164,85,17,42,161,96,47,33,189,155,96,176,155,144,222,77,72,79,32,237,25,36,116,38,0,55,
13,104,100,164,21,90,153,128,174,135,80,149,32,159,94,56,238,186,139,141,208,2,145,50,147,122,130,80,133,209,160,214,141,32,74,46,159,103,49,61,79,42,189,196,206,157,27,1,27,41,165,148,178,67,13,240,58,
21,110,197,100,187,62,193,150,38,70,233,218,105,176,162,4,8,106,235,86,237,102,80,239,198,50,21,150,51,105,210,233,20,87,46,47,49,63,63,206,220,220,44,150,93,162,175,103,152,145,77,183,242,239,111,191,
206,166,205,223,33,28,14,151,77,64,233,80,3,154,69,128,78,202,220,102,130,217,56,240,213,154,10,235,90,148,194,74,129,165,229,20,233,212,60,83,233,43,204,167,62,102,246,74,146,82,201,96,112,96,132,77,
27,118,179,105,248,43,124,121,207,14,134,6,71,9,5,163,64,185,214,120,235,204,137,242,58,128,109,219,82,226,174,202,29,157,8,121,149,195,94,137,141,223,240,216,223,189,151,247,254,235,151,92,186,124,149,
43,87,102,41,150,12,214,247,111,102,227,134,91,216,60,252,85,110,223,179,131,225,193,29,196,99,125,117,235,52,79,127,43,180,202,53,106,64,187,25,150,31,31,225,54,230,87,103,222,227,145,135,142,178,117,
228,86,122,18,67,158,165,180,91,104,118,141,76,213,205,18,226,250,132,193,106,121,90,45,105,91,169,118,59,190,161,194,5,191,181,235,78,66,161,104,83,186,220,210,95,215,140,20,5,137,183,19,108,251,76,112,
124,124,156,203,151,47,183,117,112,209,12,245,130,168,134,83,247,243,67,231,229,53,199,170,62,202,255,64,41,107,53,129,42,6,7,7,25,30,30,70,215,117,74,165,146,43,33,237,222,157,228,74,36,162,34,92,63,
137,86,179,221,175,76,89,230,161,83,39,232,44,134,0,214,175,95,143,16,130,66,161,208,210,41,54,35,220,109,167,0,144,18,69,81,155,238,106,121,88,189,102,86,237,223,213,9,218,18,233,17,6,59,250,103,200,
52,205,53,51,236,50,16,9,72,36,138,227,157,102,161,182,85,166,9,101,193,74,105,119,158,10,59,15,69,219,241,236,237,215,246,2,36,148,29,182,210,150,6,52,221,12,161,96,87,190,184,115,235,246,117,42,236,
92,208,115,157,14,132,83,199,100,131,9,180,154,215,207,238,215,230,181,37,29,167,194,101,154,188,153,239,52,222,187,12,42,175,69,243,162,202,73,147,115,247,155,57,65,91,74,16,150,107,30,224,91,3,58,65,
91,90,225,213,238,179,246,240,90,179,234,3,58,214,128,198,40,112,189,224,22,2,145,53,69,104,58,190,189,172,84,96,219,18,213,195,9,118,20,5,26,9,186,46,16,229,28,160,44,132,206,178,75,47,216,210,22,29,
135,193,181,152,128,27,60,85,26,1,142,36,168,157,119,91,161,156,8,173,49,21,254,226,209,250,152,173,83,72,41,81,58,245,1,94,38,176,150,15,160,189,194,149,45,175,121,243,86,21,224,138,145,227,227,137,183,
89,88,156,165,80,200,144,47,44,17,80,117,226,177,62,18,235,6,234,75,100,91,10,41,205,181,37,66,215,91,19,86,49,89,201,217,5,98,213,152,234,218,185,252,34,31,126,116,138,119,63,248,41,159,76,190,67,34,
17,99,160,191,135,120,188,135,80,40,68,33,151,101,106,102,133,108,46,71,124,157,78,64,187,150,91,220,144,40,224,182,147,185,252,18,153,108,138,128,26,160,191,111,179,67,176,215,10,33,231,71,216,80,254,
203,252,191,199,126,193,15,94,252,75,54,14,111,228,246,47,29,224,235,191,119,15,93,225,56,197,82,134,108,62,73,97,37,133,174,109,71,15,196,208,180,8,170,226,248,150,72,218,157,159,7,180,218,253,102,125,
70,49,207,167,103,255,147,15,198,78,114,246,252,25,50,153,69,44,219,170,157,37,72,9,209,72,130,222,222,238,242,206,87,230,202,231,243,117,2,248,112,236,13,94,122,245,123,60,252,224,55,217,62,242,219,20,
138,11,172,24,41,230,82,231,200,175,204,81,48,230,201,175,124,78,177,148,169,173,173,42,58,93,193,94,110,218,124,24,195,40,8,117,45,62,192,15,156,187,157,203,47,242,179,83,223,231,157,247,94,161,175,183,
135,145,173,253,220,125,207,62,186,19,67,196,163,235,145,210,164,100,230,89,89,201,145,201,230,8,6,213,74,24,180,17,136,154,0,0,230,23,46,242,227,127,254,46,143,124,251,47,232,73,244,51,183,240,33,129,
64,184,193,84,108,108,219,172,163,199,178,139,244,38,110,225,202,220,103,164,82,87,237,101,69,253,77,199,2,112,251,76,198,11,111,157,57,206,191,158,252,7,182,140,12,242,232,159,125,135,190,158,109,148,
204,28,249,149,171,100,243,51,156,79,190,143,105,21,208,2,17,180,64,24,77,143,160,168,97,150,115,211,132,2,67,32,234,53,96,242,220,175,217,190,125,59,241,120,140,139,179,167,8,4,194,168,138,142,109,155,
148,204,28,70,113,145,130,145,194,180,174,125,80,165,170,33,182,108,184,7,69,196,121,229,245,31,21,36,28,125,245,135,201,188,27,189,126,156,160,180,109,27,33,4,145,72,164,174,254,182,109,187,238,243,183,
211,111,255,136,55,126,249,79,28,126,224,247,25,221,122,128,108,97,150,212,226,56,0,166,85,192,52,11,8,161,96,154,5,86,140,133,186,117,250,187,247,144,181,108,186,66,49,12,227,218,159,31,115,243,23,136,
68,34,148,74,89,22,51,231,43,235,43,128,141,101,23,107,59,175,42,65,214,69,183,176,46,182,141,120,100,51,151,46,159,229,181,159,189,132,81,90,249,254,79,126,112,229,111,189,248,243,35,128,51,175,189,246,
218,3,91,183,110,85,157,204,86,5,81,253,86,224,220,212,251,252,203,235,127,207,159,126,235,17,194,225,46,102,230,207,160,5,162,132,187,214,99,89,6,182,81,81,81,41,177,101,189,186,70,195,195,12,246,126,
153,55,222,252,57,219,54,125,141,84,42,85,235,219,50,124,128,87,222,120,149,205,155,182,112,203,182,111,147,201,79,99,219,197,114,126,143,68,74,155,46,189,135,72,120,136,229,204,12,23,166,38,25,31,251,
5,11,169,44,75,115,67,103,95,121,233,157,39,127,252,156,55,127,45,63,145,185,255,254,251,119,105,154,118,220,52,205,189,205,198,233,209,36,191,243,181,94,14,252,238,157,92,152,57,73,164,107,3,186,22,69,
136,0,182,93,162,88,202,96,20,211,20,140,20,150,93,68,8,133,104,120,152,158,248,14,98,225,109,188,126,242,167,124,60,126,129,217,115,67,216,86,253,119,134,193,72,129,129,77,159,147,232,142,112,243,206,
157,132,35,26,193,144,138,148,80,42,66,58,189,196,185,243,159,177,188,156,193,46,69,40,44,247,98,27,3,23,242,249,194,163,167,79,159,126,27,48,61,255,219,240,235,228,14,29,58,212,103,89,86,157,198,216,
182,45,22,23,23,131,217,108,54,180,115,223,252,119,119,239,30,249,214,31,254,193,159,4,206,39,255,141,124,97,14,69,209,42,113,220,194,180,12,4,16,238,90,79,119,108,148,68,252,38,44,179,200,196,103,227,
242,157,95,253,218,186,60,189,240,217,127,188,89,248,185,85,146,86,133,38,75,148,67,87,81,8,81,20,66,24,91,118,104,195,3,27,212,145,112,84,36,186,194,74,63,66,26,197,21,113,209,178,68,210,44,42,211,201,
41,237,93,35,23,92,214,117,189,52,54,54,54,75,249,31,97,19,40,73,15,70,125,11,160,21,14,255,121,119,34,218,21,156,184,125,223,190,222,219,111,187,83,213,52,133,146,153,67,81,116,212,202,37,132,130,81,
202,49,125,233,19,62,157,24,51,39,39,47,218,133,188,61,245,209,251,185,151,39,199,242,231,40,27,183,168,92,118,133,248,34,96,84,238,43,64,30,40,84,218,76,199,101,53,252,174,107,147,30,127,56,94,55,1,0,
252,241,163,3,163,33,93,249,27,20,241,96,127,223,122,43,22,11,19,208,173,64,201,48,100,54,187,98,230,178,134,200,23,10,33,91,202,233,197,5,243,244,244,89,227,173,241,15,115,23,43,140,87,153,7,144,21,1,
88,14,38,108,199,179,215,221,75,16,107,55,1,191,16,66,4,190,242,245,104,79,127,159,126,171,20,202,102,85,97,163,45,133,105,24,214,213,124,70,94,185,60,101,36,207,125,146,95,2,84,199,165,52,92,78,84,133,
81,189,44,86,11,195,41,168,85,130,241,218,125,128,255,1,193,218,162,80,201,144,128,60,0,0,0,0,73,69,78,68,174,66,96,130,0,0};

const char* PatternTab::audioxmidi_png = (const char*) resource_PatternTab_audioxmidi_png;
const int PatternTab::audioxmidi_pngSize = 3650;


//[EndFile] You can add extra defines here...
//[/EndFile]
