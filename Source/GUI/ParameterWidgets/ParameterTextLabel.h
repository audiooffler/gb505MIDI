/*
  ==============================================================================

  This is an automatically generated GUI class created by the Projucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Projucer version: 7.0.2

  ------------------------------------------------------------------------------

  The Projucer is part of the JUCE library.
  Copyright (c) 2020 - Raw Material Software Limited.

  ==============================================================================
*/

#pragma once

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
class ParameterTextLabel  : public Label,
                            public ChangeListener
{
public:
    //==============================================================================
    ParameterTextLabel (const String &componentName);
    ~ParameterTextLabel() override;

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    void setParameter1(Parameter* paramPtr1);

	Parameter* getParamPtr(uint8 index) // 0 to 11, else null will be returned
	{
		return index < (uint8)m_params.size() ? m_params[index] : nullptr;
	}

	void changeListenerCallback(ChangeBroadcaster *source);	// parameter changes of groovebox memory block
    //[/UserMethods]

    void paint (juce::Graphics& g) override;
    void resized() override;

    // Binary resources:
    static const char* mixerTapeLabel_png;
    static const int mixerTapeLabel_pngSize;


private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    Array <Parameter*> m_params;
    //[/UserVariables]

    //==============================================================================
    juce::Image cachedImage_mixerTapeLabel_png_1;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (ParameterTextLabel)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

