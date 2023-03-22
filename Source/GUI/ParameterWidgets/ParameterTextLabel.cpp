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

#include "ParameterTextLabel.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
ParameterTextLabel::ParameterTextLabel (const String &componentName)
    : Label(componentName, {})
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    cachedImage_mixerTapeLabel_png_1 = juce::ImageCache::getFromMemory (mixerTapeLabel_png, mixerTapeLabel_pngSize);

    //[UserPreSize]
    setFont(Font(Font::getDefaultSansSerifFontName(),11.0f,Font::italic));
	setJustificationType(Justification::centred);
    m_params.clear();
    //[/UserPreSize]

    setSize (72, 20);


    //[Constructor] You can add your own custom stuff here..
    //[/Constructor]
}

ParameterTextLabel::~ParameterTextLabel()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    for (int i = 0; i < m_params.size(); i++) if (m_params[i] != nullptr) m_params[i]->removeChangeListener(this);
    //[/Destructor_pre]



    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void ParameterTextLabel::paint (juce::Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    {
        int x = (getWidth() / 2) - (72 / 2), y = (getHeight() / 2) - (20 / 2), width = 72, height = 20;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (juce::Colours::black);
        g.drawImage (cachedImage_mixerTapeLabel_png_1,
                     x, y, width, height,
                     0, 0, cachedImage_mixerTapeLabel_png_1.getWidth(), cachedImage_mixerTapeLabel_png_1.getHeight());
    }

    //[UserPaint] Add your own custom painting code here..
    Label::paint(g);
    //[/UserPaint]
}

void ParameterTextLabel::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    Label::resized();
    //[/UserPreResize]

    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
void ParameterTextLabel::setParameter1(Parameter* paramPtr1)
{
	m_params.clear();
	m_params.add(paramPtr1);

	if (m_params[0] != nullptr)
	{
		setVisible(true);
		// register listener for first characters parameter
		m_params[0]->addChangeListener(this);
		GrooveboxMemoryBlock* block = m_params[0]->getBlock();
		bool findMoreCharacterParametersInARow = true;
		// register listener for other 11 parameters
		for (uint16 i = 1; findMoreCharacterParametersInARow == true && i < block->getTotalSizeRealValue(); i++)
		{
			if (Parameter* paramPtrI = block->getParameter(m_params[0]->getAddressOffset() + i))
			{
				if (paramPtrI->getMin() == paramPtr1->getMin() && paramPtrI->getMax() == paramPtr1->getMax())
				{
					m_params.add(paramPtrI);
					paramPtrI->addChangeListener(this);
				}
				else
				{
					findMoreCharacterParametersInARow = false;
					break;
				}
			}
		}
		// refresh text
		changeListenerCallback(m_params[0]);
	}
	else setVisible(false);
}

void ParameterTextLabel::changeListenerCallback(ChangeBroadcaster *source)
{
	// if cast to Parameter* successful
	if (Parameter* param = dynamic_cast<Parameter*>(source))
	{
		// rebuild gui display text
		String newText;
		int i = 0;
		char c = 0;
		for (i = 0; i < m_params.size(); i++)
		{
			c = m_params[i]->getValue();
			if (((uint8)c>31 && (uint8)c < 126))
			{
				newText += c;
			}
			else break;
		}
		setText(newText.trimEnd(), dontSendNotification);
		setTooltip(newText.trimEnd());
	}
}

//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="ParameterTextLabel" componentName=""
                 parentClasses="public Label, public ChangeListener" constructorParams="const String &amp;componentName"
                 variableInitialisers="Label(componentName, {})" snapPixels="8"
                 snapActive="1" snapShown="1" overlayOpacity="0.330" fixedSize="1"
                 initialWidth="72" initialHeight="20">
  <BACKGROUND backgroundColour="0">
    <IMAGE pos="0Cc 0Cc 72 20" resource="mixerTapeLabel_png" opacity="1.0"
           mode="0"/>
  </BACKGROUND>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif

//==============================================================================
// Binary resources - be careful not to edit any of these sections!

// JUCER_RESOURCE: mixerTapeLabel_png, 1246, "../../../Resources/LookAndFeel/MixerTapeLabel.png"
static const unsigned char resource_ParameterTextLabel_mixerTapeLabel_png[] = { 137,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,0,72,0,0,0,20,8,6,0,0,0,46,161,123,203,0,0,0,4,115,66,73,84,8,8,8,8,124,
8,100,136,0,0,0,9,112,72,89,115,0,0,3,232,0,0,3,232,1,181,123,82,107,0,0,0,25,116,69,88,116,83,111,102,116,119,97,114,101,0,119,119,119,46,105,110,107,115,99,97,112,101,46,111,114,103,155,238,60,26,0,
0,4,91,73,68,65,84,88,133,213,86,91,104,28,85,24,254,254,51,103,55,68,118,103,179,137,89,115,177,180,85,211,36,181,210,214,154,168,85,20,124,16,177,32,197,203,147,34,190,10,22,17,81,244,89,223,212,39,
161,138,224,147,138,15,62,40,109,133,6,90,197,7,65,130,52,109,44,177,77,19,75,40,37,77,66,82,109,178,51,59,183,115,124,152,217,217,185,238,110,182,89,109,127,118,216,115,206,127,57,255,247,205,57,31,67,
112,77,29,26,186,231,68,177,88,204,118,21,212,82,177,216,101,85,42,134,173,235,6,121,126,72,72,105,91,182,137,86,141,0,53,159,171,52,10,115,28,135,105,154,214,193,121,54,91,40,228,13,0,16,66,208,250,122,
57,155,205,102,58,84,53,103,17,145,4,0,41,37,45,45,173,216,106,62,167,104,186,110,27,166,97,39,22,149,181,65,65,205,119,40,92,1,99,204,8,58,43,21,147,27,134,161,100,56,207,46,45,175,26,25,174,44,110,108,
108,156,229,0,192,57,31,31,31,123,104,239,199,31,125,160,118,21,10,45,115,208,30,147,222,79,194,71,42,165,231,145,190,223,157,213,198,213,88,41,101,160,78,157,60,191,174,159,183,251,237,119,63,28,101,
0,96,219,246,169,159,126,254,229,219,217,217,57,159,235,255,199,92,16,82,10,239,113,32,133,227,254,87,31,111,46,164,237,142,69,220,23,159,219,117,124,78,98,29,203,50,113,225,226,220,13,238,117,214,55,
50,60,252,228,248,216,1,170,219,127,27,8,105,230,13,251,107,129,216,80,94,232,148,33,124,18,162,121,145,186,144,129,19,20,136,61,51,53,237,204,94,250,107,134,3,216,115,232,208,211,39,143,126,250,201,224,
150,98,143,89,148,140,64,195,13,64,37,93,177,36,80,233,87,172,137,188,72,15,119,15,148,148,130,154,239,227,0,50,163,35,195,106,169,212,187,37,52,52,5,42,70,198,102,64,85,179,26,228,69,123,104,248,66,16,
200,37,116,247,116,129,24,89,124,247,232,240,251,47,60,255,92,231,86,147,225,111,220,62,17,173,229,53,69,70,82,15,46,25,0,64,4,0,204,71,117,229,202,53,172,173,254,189,143,27,166,181,54,49,113,250,159,
125,123,31,232,217,28,25,77,128,10,53,82,79,55,194,177,155,210,155,216,21,107,76,6,8,160,0,25,254,186,199,20,1,24,186,111,7,6,7,251,111,240,181,181,235,223,44,47,175,28,78,35,228,86,21,209,152,78,33,122,
197,154,35,163,182,66,161,24,9,9,195,52,4,47,22,11,111,189,244,226,225,187,226,100,4,26,110,0,42,233,138,181,91,68,195,100,248,76,192,125,255,84,91,107,130,140,218,148,2,153,12,143,62,252,96,39,239,233,
41,238,26,31,223,239,126,7,164,146,177,25,80,213,172,6,121,41,87,172,89,17,117,49,7,201,8,0,167,48,216,36,162,18,253,84,27,159,153,58,143,227,63,158,94,227,3,125,125,12,82,120,173,165,129,170,2,170,163,
55,81,80,109,22,209,36,221,72,39,35,76,71,244,212,196,252,68,200,231,243,232,46,22,84,126,255,158,145,101,41,157,209,250,186,113,19,122,83,71,55,110,70,68,99,235,1,208,141,201,8,239,21,173,67,0,230,230,
23,44,173,172,159,96,215,87,87,75,177,79,241,58,159,240,34,41,54,245,19,190,94,172,71,14,1,68,204,123,200,253,7,243,28,12,8,174,19,243,218,103,158,143,60,191,23,3,119,92,93,71,112,29,181,58,161,92,184,
53,131,61,128,24,158,125,230,169,204,246,237,219,118,114,221,52,206,73,225,140,214,222,112,224,36,224,214,21,209,180,19,64,13,78,70,112,175,104,15,20,216,235,243,47,190,94,213,52,237,119,234,239,47,205,
78,254,122,108,72,85,243,109,16,209,4,176,129,230,227,87,165,69,50,82,64,83,147,100,132,123,4,166,255,152,17,175,190,246,230,209,249,203,11,71,184,170,230,38,175,94,93,28,202,231,238,184,173,68,52,186,
15,165,228,249,213,83,200,136,218,217,115,51,246,235,111,188,119,124,254,242,194,59,0,192,203,235,229,220,226,226,53,57,188,107,7,221,78,34,186,21,100,36,217,15,199,78,74,203,178,58,0,88,213,10,61,7,31,
217,63,241,253,119,159,29,224,92,65,50,25,201,199,180,37,221,104,137,140,218,94,209,30,234,93,149,86,108,250,252,133,149,206,206,236,169,151,95,57,114,239,159,23,47,61,70,0,50,189,189,221,95,61,241,248,
216,193,129,129,94,165,92,174,48,33,164,35,108,199,10,101,82,234,36,102,196,24,231,138,194,1,64,45,228,28,34,197,247,233,122,133,149,203,154,73,36,165,148,196,55,54,52,177,115,231,54,197,52,45,42,151,
53,104,154,174,11,41,179,82,8,157,103,184,8,239,202,240,95,152,148,130,126,155,156,186,211,50,204,47,255,5,89,174,37,44,206,250,20,73,0,0,0,0,73,69,78,68,174,66,96,130,0,0};

const char* ParameterTextLabel::mixerTapeLabel_png = (const char*) resource_ParameterTextLabel_mixerTapeLabel_png;
const int ParameterTextLabel::mixerTapeLabel_pngSize = 1246;


//[EndFile] You can add extra defines here...
//[/EndFile]

