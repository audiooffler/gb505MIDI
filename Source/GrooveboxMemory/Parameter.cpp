/*
  ==============================================================================

    Parameter.cpp
    Created: 17 Feb 2014 10:34:05pm
    Author:  Martin

  ==============================================================================
*/

#include "Parameter.h"
#include "QuickSysExBlock.h"
#include "PartInfoBlock.h"
#include "PartInfoBlock.h"
#include "SynthPatchesBlock.h"
#include "RhythmSetBlock.h"

extern MidiOutput* midiOutputDevice;

// careful when calculating with addresses or sizes, interpret as 4 x 7 bit instread of 4 x 8 bit!
// max must not exceed 127 if value is meant to be interpreted as 7 bit midi data. larger max values are used for msb/lsb nibbled 8bit values (0..255 as 2x4 bit in 2 7bit bytes)
Parameter::Parameter(GrooveboxMemoryBlock* parentBlockPtr, String name, uint16 addressOffset, uint8 min, uint8 max, uint8 default, StringArray displayedValues, String description, uint8 cc, bool ccIsMode2Only) :
m_parentBlockPtr(parentBlockPtr),
m_name(name),
m_addressOffset(addressOffset),
m_min(min > max ? max - 1 : min),
m_max(max),
m_default(default),
m_displayedValues(displayedValues),
m_description(description),
m_cc(cc),
m_ccIsMode2Only(ccIsMode2Only)
{
	// if none are given calculate simple text representations for min..max as int values to strings
	if (m_displayedValues.size() == 0)
	{
		// empty display for values below valid range
		for (uint8 i = 0; i < m_min; i++) m_displayedValues.add(String::empty);
		// add default value strings
		for (uint8 i = m_min; i <= m_max; i++)
		{
			m_displayedValues.add(*ScopedPointer<String>(new String(i)));
		}
		// [] operator already returns empty string for indexes above array size
	}
	setValue(default, Init);
}

// --- getter functions: ---

String Parameter::getName() { return m_name; }
uint16 Parameter::getAddressOffset() { return m_addressOffset; }
uint32 Parameter::getBlockAddress() { return m_parentBlockPtr->getAddress() & 0xFFFF0000; }
uint32 Parameter::getAddress() { return (m_parentBlockPtr->getAddress() & 0xFFFF0000) | m_addressOffset; }
uint8 Parameter::getMin() { return m_min; }
uint8 Parameter::getMax() { return m_max; }
uint8 Parameter::getDefault() { return m_default; }

// does not check if parameter address is within block array dimension, so be careful!
uint8 Parameter::getValue()
{
	//if (m_max > 127)
	//{
	//	int v = ((m_parentBlockPtr->m_data[m_addressOffset] & 0xF) << 4) | (m_parentBlockPtr->m_data[m_addressOffset + 1] & 0xF);
	//	DBG("\"" + String::toHexString(m_parentBlockPtr->m_data.getData(), 5) + "\"\t" + String::toHexString((
	//	m_parentBlockPtr->m_data[m_addressOffset] & 0xF) << 4 | (m_parentBlockPtr->m_data[m_addressOffset + 1] & 0xF)));
	//}
	return (m_max > 127) ?
		(m_parentBlockPtr->m_data[m_addressOffset] & 0xF) << 4 | m_parentBlockPtr->m_data[m_addressOffset + 1] & 0xF :	// nibbled 8-bit (0..255)
		m_parentBlockPtr->m_data[m_addressOffset] & 0x7F;																// simple 7-bit value (0..127)
}

StringArray Parameter::getDisplayedValues()
{
	return m_displayedValues;
}

String Parameter::getDisplayedValue()
{
	uint8 value(getValue());
	return (value >= m_min && value <= m_max) ? m_displayedValues[value] : String::empty;
}

String Parameter::getDisplayedValue(uint8 value)
{
	return (value >= m_min && value <= m_max) ? m_displayedValues[value] : String::empty;
}

String Parameter::getDescription() { return m_description; }

uint8 Parameter::getCC(){ return m_cc; }

bool Parameter::getCCisMode2Only() { return m_ccIsMode2Only; }

GrooveboxMemoryBlock* Parameter::getBlock(){ return m_parentBlockPtr; }

// sets the value, broadcasts change (to registered listeners like gui widgets) and send to midi out to groovebox and set plugin parameter value
// source may be LoadingFile, MidInFromGroovebox, MidiInOther, PluginParam or GuiWidget
// 2-byte values are set as one 8-bit bytes here.
void Parameter::setValue(uint8 value, ChangeSource source)
{
	// no value change, ignore
	if (value == this->getValue()) return;

	if (value > m_max) value = m_max;
	if (value < m_min) value = m_min;

	if (m_max > 127) // set as nibbled 8bit value
	{
		m_parentBlockPtr->m_data[m_addressOffset] = value >> 4;			// MS nibble
		m_parentBlockPtr->m_data[m_addressOffset + 1] = value & 0xF;	// LS nibble
	}
	else			 // single 7bit value
	{
		m_parentBlockPtr->m_data[m_addressOffset] = value;
	}

	// secial treating some parameters that change the desctription of other params in M-FX, Delay, and LFO (Rate by Tempo Sync Switch)
	//setupParameter("LFO1 Tempo Sync", 0x34, 0, 1, 0, switchOnOffStrings, lfoTempoSyncDescription);
	//m_parameters.set(addressOffset, new Parameter(this, name, addressOffset, min, max, default, displayedValues, description, cc, ccIsMode2Only), true);
	
	// wenn parent ein synthPatchesBlock und entspr. offset dann im parent paramet setup entsprechend durchführen
	PatchToneBlock* patchToneBlock = dynamic_cast<PatchToneBlock*>(m_parentBlockPtr);
	if (patchToneBlock != nullptr)
	{
		if (m_addressOffset == 0x34 || m_addressOffset == 0x3C)
		{
			StringArray arr;
			uint8 max(127);
			if (value > 0)
			{
				max = 21;
				arr.add(AsciiWithNoteValuesTypeface::getNoteString(AsciiWithNoteValuesTypeface::NoteValue_64th_triplet));
				arr.add(AsciiWithNoteValuesTypeface::getNoteString(AsciiWithNoteValuesTypeface::NoteValue_64th));
				arr.add(AsciiWithNoteValuesTypeface::getNoteString(AsciiWithNoteValuesTypeface::NoteValue_32nd_triplet));
				arr.add(AsciiWithNoteValuesTypeface::getNoteString(AsciiWithNoteValuesTypeface::NoteValue_32nd));
				arr.add(AsciiWithNoteValuesTypeface::getNoteString(AsciiWithNoteValuesTypeface::NoteValue_16th_triplet));
				arr.add(AsciiWithNoteValuesTypeface::getNoteString(AsciiWithNoteValuesTypeface::NoteValue_32nd_dotted));
				arr.add(AsciiWithNoteValuesTypeface::getNoteString(AsciiWithNoteValuesTypeface::NoteValue_16th));
				arr.add(AsciiWithNoteValuesTypeface::getNoteString(AsciiWithNoteValuesTypeface::NoteValue_8th_triplet));
				arr.add(AsciiWithNoteValuesTypeface::getNoteString(AsciiWithNoteValuesTypeface::NoteValue_16th_dotted));
				arr.add(AsciiWithNoteValuesTypeface::getNoteString(AsciiWithNoteValuesTypeface::NoteValue_8th));
				arr.add(AsciiWithNoteValuesTypeface::getNoteString(AsciiWithNoteValuesTypeface::NoteValue_4th_triplet));
				arr.add(AsciiWithNoteValuesTypeface::getNoteString(AsciiWithNoteValuesTypeface::NoteValue_8th_dotted));
				arr.add(AsciiWithNoteValuesTypeface::getNoteString(AsciiWithNoteValuesTypeface::NoteValue_4th));
				arr.add(AsciiWithNoteValuesTypeface::getNoteString(AsciiWithNoteValuesTypeface::NoteValue_half_triplet));
				arr.add(AsciiWithNoteValuesTypeface::getNoteString(AsciiWithNoteValuesTypeface::NoteValue_4th_dotted));
				arr.add(AsciiWithNoteValuesTypeface::getNoteString(AsciiWithNoteValuesTypeface::NoteValue_half));
				arr.add(AsciiWithNoteValuesTypeface::getNoteString(AsciiWithNoteValuesTypeface::NoteValue_whole_triplet));
				arr.add(AsciiWithNoteValuesTypeface::getNoteString(AsciiWithNoteValuesTypeface::NoteValue_half_dotted));
				arr.add(AsciiWithNoteValuesTypeface::getNoteString(AsciiWithNoteValuesTypeface::NoteValue_whole));
				arr.add(AsciiWithNoteValuesTypeface::getNoteString(AsciiWithNoteValuesTypeface::NoteValue_double_triplet));
				arr.add(AsciiWithNoteValuesTypeface::getNoteString(AsciiWithNoteValuesTypeface::NoteValue_whole_dotted));
				arr.add(AsciiWithNoteValuesTypeface::getNoteString(AsciiWithNoteValuesTypeface::NoteValue_double));
			}
			String lfoRateDescription(String("Adjusts the LFO modulation speed.\r\n") +
				"As this value is increased, the sound will be modulated more rapidly.As this value is decreased, the sound will be modulated more slowly.\r\n" +
				"When LFO Tempo Sync is \"ON\", you can specify this parameter in terms of a note value.\r\n" +
				"LFO Rate settings are common to PITCH (pitch), FILTER (brightness)and AMP(volume).The rate cannot be set independently for these three.");
			if (m_addressOffset == 0x34)
			{
				patchToneBlock->setupParameter("LFO1 Rate", 0x2F, 0, max, 0, arr, lfoRateDescription);
			}
			if (m_addressOffset == 0x3C)
			{
				patchToneBlock->setupParameter("LFO2 Rate", 0x37, 0, max, 0, arr, lfoRateDescription);
			}
		}
	}
	// send to midi if midioutput device is open
	// don't send if it's coming from the groovebox itself and also during init the parant block is not yet fully constructed, so obviously it can't generate sysex messages yet
	if (source != ChangeSource::MidiInFromGroovebox && source != ChangeSource::Init && midiOutputDevice != nullptr && getAddress()<0xF0000000)
	{
		int ccChannel(0);
		// send CC whenever defined but first get it's channel 
		if (m_cc != CC_NONE && !m_ccIsMode2Only)
		{
			// find channel for CC by parent block's part 
			if (PartInfoPartBlock* parent = dynamic_cast<PartInfoPartBlock*>(m_parentBlockPtr))
			{
				ccChannel = (parent->getPart() + 1);
			}
			else if (PatchCommonBlock* parent = dynamic_cast<PatchCommonBlock*>(m_parentBlockPtr))
			{
				ccChannel = (parent->getPart() + 1);
			}
			else if (PatchToneBlock* parent = dynamic_cast<PatchToneBlock*>(m_parentBlockPtr))
			{
				ccChannel = (parent->getPart() + 1);
			}
			else if (RhythmNoteBlock* parent = dynamic_cast<RhythmNoteBlock*>(m_parentBlockPtr))
			{
				ccChannel = 10;
			}
		}
		// send Midi Message
		if (ccChannel > 0)
		{
			midiOutputDevice->sendMessageNow(MidiMessage::controllerEvent(ccChannel, m_cc, getValue()));
			Logger::outputDebugString(
			//Logger::writeToLog(
				" > MIDI-OUT: "
				"Ch " + String(ccChannel).paddedLeft(' ', 2) + 
				", CC " + String(m_cc).paddedLeft(' ', 3) + 
				", Value " + String(getValue()).paddedLeft(' ', 3) +
				"(" + getName() + ")"
				);
		}
		else // if no cc was send
		{
			// Quick SysEx Sequencer (Mute Param)
			if (QuickSysExSequencerBlock* quickSeqBlock = dynamic_cast<QuickSysExSequencerBlock*>(m_parentBlockPtr))
			{
				ScopedPointer<SyxMsg> syx = quickSeqBlock->createMuteQuickSysExSendMsg(this);
				midiOutputDevice->sendMessageNow(syx->toMidiMessage());
				Logger::outputDebugString(
				//Logger::writeToLog(
					" > MIDI-OUT: "
					"Quick Sysex \""+
					syx->toString()+
					"\" ("+ getName()+ ")"
					);
			}
			// default: SysEx
			else
			{
				// create sysex of 1 byte to change (or 2 bytes for 8-bit parameters with max > 127)
				ScopedPointer<SyxMsg> syx = m_parentBlockPtr->createParameterSendMsg(this, (m_max > 127) ? 2 : 1);
				midiOutputDevice->sendMessageNow(syx->toMidiMessage());
				Logger::outputDebugString(
				//Logger::writeToLog(
					" > MIDI-OUT: "
					"Sysex \"" +
					syx->toString() +
					"\" (" + getName() + ")"
					);
			}
		}
	}
	if (source != ChangeSource::PluginParam)
	{
		// TODO: set plugin parameter notifying host in AudioProcessor
	}
	// always inform gui be careful in ChangeListener::changeListenerCallback to only take over changes that differ from the already displayed value
	// other gui elements may be connected to this param, they will all be refreshed
	sendChangeMessage();
}

void Parameter::setName(String name)
{
	if (name == m_name) return;
	m_name = name;
	sendChangeMessage();
}

void Parameter::setMin(uint8 min)
{
	if (min == m_min) return;
	m_min = min;
	sendChangeMessage();
}

void Parameter::setMax(uint8 max)
{
	if (max == m_max) return;
	m_max = max;
	sendChangeMessage();
}

void Parameter::setDefault(uint8 default)
{
	m_default = default;
}

void Parameter::setDisplayedValues(StringArray displayedValues)
{
	m_displayedValues = displayedValues;
	// if none are given calculate simple text representations for min..max as int values to strings
	if (m_displayedValues.size() == 0)
	{
		// empty display for values below valid range
		for (uint8 i = 0; i < m_min; i++) m_displayedValues.add(String::empty);
		// add default value strings
		for (uint8 i = m_min; i <= m_max; i++) m_displayedValues.add(String(i));
		// [] operator already returns empty string for indexes above array size
	}
}

void Parameter::setDescription(String description)
{
	if (m_description == description) return;
	m_description = description;
	sendChangeMessage();
}

void Parameter::setCC(uint8 cc)
{
	m_cc = cc;
}

void Parameter::setCCisMode2Only(bool ccIsMode2Only)
{
	m_ccIsMode2Only = ccIsMode2Only;
}