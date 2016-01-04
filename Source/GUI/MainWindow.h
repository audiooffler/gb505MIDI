/*
  ==============================================================================

    MainWindow.h
    Created: 1 Jan 2014 4:01:05pm
    Author:  Martin

  ==============================================================================
*/

#ifndef MAINWINDOW_H_INCLUDED
#define MAINWINDOW_H_INCLUDED

#include "JuceHeader.h"
#include "MainComponent.h"

extern ApplicationProperties* appProperties;

//==============================================================================
/*
This class implements the desktop window that contains an instance of
our MainContentComponent class.
*/
class MainWindow : public DocumentWindow
{
public:
	MainWindow() : DocumentWindow("Roland MC-307 SysEx",
		Colours::lightgrey,
		DocumentWindow::allButtons)
	{
		int desktopCenterX(Desktop::getInstance().getDisplays().getMainDisplay().userArea.getCentreX());
		int desktopCenterY(Desktop::getInstance().getDisplays().getMainDisplay().userArea.getCentreY());
		int defaultWidth(640);
		int defaultHeight(480);
		Rectangle<int> posAndSize(Rectangle<int>::fromString(
			appProperties->getUserSettings()->getValue("MainWindow.PositionAndSize", String(desktopCenterX - defaultWidth / 2) + " " + String(desktopCenterY - defaultHeight / 2) + " " + String(defaultWidth) + " " + String(defaultHeight))
			));
		//initTask;
		setContentOwned(new MainComponent(), true);
		setUsingNativeTitleBar(true);
		setBounds(posAndSize);
		setVisible(true);
		grabKeyboardFocus();
	}

	void closeButtonPressed()
	{
		// This is called when the user tries to close this window. Here, we'll just
		// ask the app to quit when this happens, but you can change this to do
		// whatever you need.
		JUCEApplication::getInstance()->systemRequestedQuit();
	}

	/* Note: Be careful if you override any DocumentWindow methods - the base
	class uses a lot of them, so by overriding you might break its functionality.
	It's best to do all your work in your content component instead, but if
	you really have to override any DocumentWindow methods, make sure your
	subclass also calls the superclass's method.
	*/

	void resized()
	{
		DocumentWindow::resized();
		appProperties->getUserSettings()->setValue("MainWindow.PositionAndSize", getBounds().toString());
	}

	void moved()
	{
		DocumentWindow::moved();
		appProperties->getUserSettings()->setValue("MainWindow.PositionAndSize", getBounds().toString());
	}

private:

	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(MainWindow)
};




#endif  // MAINWINDOW_H_INCLUDED
