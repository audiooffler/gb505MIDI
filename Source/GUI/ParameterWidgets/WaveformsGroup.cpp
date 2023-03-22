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

//[Headers] You can add your own extra header files here...
//[/Headers]

#include "WaveformsGroup.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
extern Waveforms* waveForms;
//[/MiscUserDefs]

//==============================================================================
WaveformsGroup::WaveformsGroup (Waveforms::WaveGroup group)
    : m_group (group)
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]


    //[UserPreSize]
	m_waveformButtons.clear();
	// create buttons
	for (int i = 0; i < waveForms->getGroupSize(group);i++)
	{
		WaveformButton* m_waveformButton = new WaveformButton(m_group, i);
		m_waveformButton->setConnectedEdges(Button::ConnectedOnTop | Button::ConnectedOnBottom);
		m_waveformButton->addListener(this);
		m_waveformButton->setExplicitFocusOrder(Waveforms::getGroupId(m_group) + i);
		m_waveformButton->setSize(100, 20);
		m_waveformButton->setTopLeftPosition(
			(int)(i / maxRows)*buttonWidth + (int)(i / maxRows)*x0 + x0,
			(i*buttonHeight + y0) % (maxRows*buttonHeight)
			);
		m_waveformButtons.add(m_waveformButton);
		addAndMakeVisible(m_waveformButtons[i]);
	}

    //[/UserPreSize]

    setSize (836, 660);


    //[Constructor] You can add your own custom stuff here..
    //[/Constructor]
}

WaveformsGroup::~WaveformsGroup()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]



    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void WaveformsGroup::paint (juce::Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
	#ifdef JUCE_MSVC
	g;
	#endif
    //[/UserPrePaint]

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void WaveformsGroup::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
void WaveformsGroup::buttonClicked(Button* buttonThatWasClicked)
{
	if (WaveformButton* waveformButton = dynamic_cast <WaveformButton*>(buttonThatWasClicked)){
		if (m_waveformButtons.contains(waveformButton))
		{
			// ...
		}
	}
}

//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="WaveformsGroup" componentName=""
                 parentClasses="public Component, public Button::Listener" constructorParams="Waveforms::WaveGroup group"
                 variableInitialisers="m_group (group)" snapPixels="4" snapActive="1"
                 snapShown="1" overlayOpacity="0.330" fixedSize="1" initialWidth="836"
                 initialHeight="660">
  <BACKGROUND backgroundColour="0"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]

