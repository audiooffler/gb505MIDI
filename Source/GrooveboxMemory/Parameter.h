/*
  ==============================================================================

    Parameter.h
    Created: 15 Jan 2014 9:16:57pm
    Author:  Martin

  ==============================================================================
*/

#ifndef PARAMETER_H_INCLUDED
#define PARAMETER_H_INCLUDED

#include "JuceHeader.h"
#include "GrooveboxMemoryBlock.h"

class GrooveboxMemoryBlock;

// maps data from addressBlock to a parameter for interpretation of memory blocks according to the groovebox manual section 'Parameter address map'
// the actual value is kept in the parent's block array as uint8  // (0..127 or 0..255 for parameters parsed from 2 sysex bytes)
class Parameter : public ChangeBroadcaster, public ActionBroadcaster
{
public:

	static const int CC_NONE = 102;	// 102 (0x66) is 'undefined' (default) 

	// careful when calculating with addresses or sizes, interpret as 4 x 7 bit instread of 4 x 8 bit!
	// max must not exceed 127 if value is meant to be interpreted as 7 bit midi data. larger max values are used for msb/lsb nibbled 8bit values (0..255 as 2x4 bit in 2 7bit bytes)
	Parameter(GrooveboxMemoryBlock* parentBlockPtr, String name, uint16 addressOffset, uint8 min, uint8 max, uint8 default, StringArray displayedValues, String description, uint8 cc = CC_NONE, bool ccIsMode2Only = false);

	// --- getter functions: ---

	String getName();
	uint16 getAddressOffset();
	uint32 getBlockAddress();
	uint32 getAddress();
	uint8 getMin();
	uint8 getMax();
	uint8 getDefault();
	// does not check if parameter address is within block array dimension, so be careful!
	uint8 getValue();

	StringArray getDisplayedValues();

	String getDisplayedValue();

	String getDisplayedValue(uint8 value);

	String getDescription();

	uint8 getCC();

	bool getCCisMode2Only();

	GrooveboxMemoryBlock* getBlock();

	enum ChangeSource
	{
		Init,
		LoadingFile,
		MidiInOther,
		MidiInFromGroovebox,
		PluginParam,
		GuiWidget
	};

	// --- setter functions: ---

	// sets the value, broadcasts change (to registered listeners like gui widgets) and send to midi out to groovebox and set plugin parameter value
	// source may be LoadingFile, MidInFromGroovebox, MidiInOther, PluginParam or GuiWidget
	void setValue(uint8 value, ChangeSource source);
	void setName(String name);
	void setMin(uint8 min);
	void setMax(uint8 max);
	void setDefault(uint8 default);
	void resetToDefault();
	void setDisplayedValues(StringArray displayedValues);
	void setDescription(String description);
	void setCC(uint8 cc = CC_NONE);	// leave empty to delete cc (sets to CC_NONE), else set parameter CC number
	void setCCisMode2Only(bool ccIsMode2Only);

private:
	String m_name;  // compulsory, descriptive
	uint16 m_addressOffset; // compulsory, careful when calculating: interpret as 4 x 7 bit instead of 4 x 8	
	uint8 m_min; // compulsory (0..255, 128-255 for parameters parsed from 2 sysex bytes)
	uint8 m_max; // compulsory (0..255, 128-255 for parameters parsed from 2 sysex bytes)
	uint8 m_default; 
	StringArray m_displayedValues; // set optional, will default to automatic generation from m_8bitValueMin to m_8bitValueMax 
	String m_description; // set optional, descriptive
	uint8 m_cc;	// the parameter can be controlled by the groovebox this controller number (more performant than SysEx) // CC_NONE = 102 (0x66) is 'undefined' (default) 
	bool m_ccIsMode2Only; // the parameter's cc can is not handled in mode 2
	GrooveboxMemoryBlock* m_parentBlockPtr;
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(Parameter)
};

#endif  // PARAMETER_H_INCLUDED
