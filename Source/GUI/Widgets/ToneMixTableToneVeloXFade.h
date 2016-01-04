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

#ifndef __JUCE_HEADER_29E94B385C927DD0__
#define __JUCE_HEADER_29E94B385C927DD0__

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
class ToneMixTableToneVeloXFade  : public Component,
                                   public ComponentMovementWatcher
{
public:
    //==============================================================================
    ToneMixTableToneVeloXFade (const String &componentName, Component* componentToWatch);
    ~ToneMixTableToneVeloXFade();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.

	// This callback happens when the component that is being watched is moved relative to its top - level peer window, or when it is resized.
	void componentMovedOrResized(bool wasMoved, bool wasResized);
	// This callback happens when the component's top-level peer is changed.
	void componentPeerChanged();
	// This callback happens when the component's visibility state changes, possibly due to one of its parents being made visible or invisible.
	void componentVisibilityChanged();

    //[/UserMethods]

    void paint (Graphics& g);
    void resized();
    void mouseMove (const MouseEvent& e);
    void mouseEnter (const MouseEvent& e);
    void mouseExit (const MouseEvent& e);



private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    //[/UserVariables]

    //==============================================================================


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (ToneMixTableToneVeloXFade)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

#endif   // __JUCE_HEADER_29E94B385C927DD0__
