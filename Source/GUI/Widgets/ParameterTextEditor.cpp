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
//[/Headers]

#include "ParameterTextEditor.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
ParameterTextEditor::ParameterTextEditor (const String &componentName)
    : TextEditor(componentName)
{

    //[UserPreSize]
	setInputRestrictions(12, " !\"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`abcdefghijklmnopqrstuvwxyz{|}");
	setFont(Font(Font::getDefaultMonospacedFontName(),13.0f,Font::plain));
    //[/UserPreSize]

    setSize (150, 24);


    //[Constructor] You can add your own custom stuff here..
	addListener(this);
    //[/Constructor]
}

ParameterTextEditor::~ParameterTextEditor()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]



    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void ParameterTextEditor::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    TextEditor::paint(g);
    //[/UserPrePaint]

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void ParameterTextEditor::resized()
{
    //[UserResized] Add your own custom resize handling here..
    TextEditor::resized();
    //[/UserResized]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
void ParameterTextEditor::setParameter1(Parameter* paramPtr1)
{
	m_params[0] = paramPtr1;

	if (m_params[0] != nullptr)
	{
		setVisible(true);
		setTooltip(TRANS("Press [Enter] to apply the new name."));
		// register listener for first param of 12
		m_params[0]->addChangeListener(this);
		GrooveboxMemoryBlock* block = m_params[0]->getBlock();
		// register listener for other 11 parameters
		for (uint16 i = 1; i < 12; i++)
		{
			m_params[i] = block->getParameter(m_params[0]->getAddressOffset() + i);
			m_params[i]->addChangeListener(this);
		}
	}
	else setVisible(false);
}

void ParameterTextEditor::changeListenerCallback(ChangeBroadcaster *source)
{
	// if cast to Parameter* successful
	if (Parameter* param = dynamic_cast<Parameter*>(source))
	{
		// rebuild gui display text
		String newText(String::empty);
		int i = 0;
		char c = 0;
		for (i = 0; i < 12; i++)
		{
			c = m_params[i]->getValue();
			if (((uint8)c>31 && (uint8)c < 126))
			{
				newText += c;
			}
			else break;
		}
		setText(newText.trimEnd(), dontSendNotification);
	}
}

void ParameterTextEditor::textEditorTextChanged(TextEditor &textEditor)
{
	if (&textEditor == (TextEditor*)this)
	{
		String text(getText());
		const char* rawText = text.toRawUTF8();
		int i = 0;
		if (text.isEmpty())
		{
			// eventually clear text with spaces
			for (i = 0; i < 12; i++) /*if (m_params[i]->getValue() != 32)*/ m_params[i]->setValue(32, Parameter::GuiWidget);
		}
		else
		{
			for (i = 0; i < 12; i++)
			{
				char rawChar = i < text.length() ? rawText[i] : 32;
				uint8 rawCharValue = (uint8)rawChar;
				/*if (rawCharValue>31 && rawCharValue < 126)
				{*/
				/*if (m_params[i]->getValue() != rawCharValue)*/ m_params[i]->setValue(rawCharValue, Parameter::GuiWidget);
				//}
				//else
				//{
				//	// set rest (unused characters) to space
				//	if (m_params[i]->getValue() != 32) m_params[i]->setValue(32, Parameter::GuiWidget);
				//}
			}
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

<JUCER_COMPONENT documentType="Component" className="ParameterTextEditor" componentName=""
                 parentClasses="public TextEditor, public TextEditor::Listener, public ChangeListener"
                 constructorParams="const String &amp;componentName=String::empty"
                 variableInitialisers="TextEditor(componentName)" snapPixels="8"
                 snapActive="1" snapShown="1" overlayOpacity="0.330" fixedSize="0"
                 initialWidth="150" initialHeight="24">
  <BACKGROUND backgroundColour="0"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
