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

#ifndef __JUCE_HEADER_9002020A4DD09B20__
#define __JUCE_HEADER_9002020A4DD09B20__

//[Headers]     -- You can add your own extra header files here --
#include "JuceHeader.h"
#include "TabbedComponentWithMenu.h"
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Introjucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class MainComponent  : public TabbedComponentWithMenu,
                       public ApplicationCommandTarget,
                       public Button::Listener
{
public:
    //==============================================================================
    MainComponent ();
    ~MainComponent();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.

	/* ApplicationCommandTarget implementation: */
	enum CommandIDs
	{
		createEmptyPattern = 0x20FF,
		fileOpenPattern = 0x2101,
		fileSavePattern = 0x2102,
		fileSavePatternBinFile = 0x2124,
		grooveBoxLoadPattern = 0x3101,
		grooveBoxRecvPatternBulk = 0x3102,
		grooveBoxSendPatternBulk = 0x3103,

		gotoPart1Tab = 0xF01,
		gotoPart2Tab = 0xF02,
		gotoPart3Tab = 0xF03,
		gotoPart4Tab = 0xF04,
		gotoPart5Tab = 0xF05,
		gotoPart6Tab = 0xF06,
		gotoPart7Tab = 0xF07,
		gotoPartRTab = 0xF10,
		gotoMixerTab = 0xF20,
		gotoSystemTab = 0xF30,
		gotoPatternEditorTab = 0xF31,
		showInfo = 0xF50
	};
	ApplicationCommandTarget* getNextCommandTarget() override;
	void getAllCommands(Array <CommandID>& commands) override;
	void getCommandInfo(CommandID commandID, ApplicationCommandInfo& result) override;
	bool perform(const InvocationInfo& info) override;
	Drawable* getDrawableForCommand(CommandID commandID, bool inactive=false);
	/* Button::Listener implementation for listening to menu button */
	void buttonClicked(Button* buttonThatWasClicked) override;

	class CustomViewport : public Viewport
	{
	public:
		CustomViewport(const String &componentName = String::empty) : Viewport(componentName) {}
		void paint(Graphics &g)
		{
			g.fillAll(Colour(0xff303030));
			/*g.fillAll(Colour(0xffb1afaf));

			g.setGradientFill(ColourGradient(Colour(0xffcdcccc),
				120.0f, 248.0f,
				Colour(0xff979797),
				224.0f, 720.0f,
				false));
			g.fillRect(0, 0, getWidth() - 0, getHeight() - 0);*/

			Viewport::paint(g);
		}

	};

    //[/UserMethods]

    void paint (Graphics& g) override;
    void resized() override;

    // Binary resources:
    static const char* new_png;
    static const int new_pngSize;
    static const char* open_png;
    static const int open_pngSize;
    static const char* save_png;
    static const int save_pngSize;
    static const char* midiIn_png;
    static const int midiIn_pngSize;
    static const char* midiOut_png;
    static const int midiOut_pngSize;
    static const char* info_png;
    static const int info_pngSize;
    static const char* quit_png;
    static const int quit_pngSize;


private:
    //[UserVariables]   -- You can add your own custom variables in this section.
	void showInfoDlg();
    //[/UserVariables]

    //==============================================================================


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainComponent)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

#endif   // __JUCE_HEADER_9002020A4DD09B20__
