/*
  ==============================================================================

    AsciiWithNoteValuesTypeface.h
    Created: 10 Oct 2014 9:39:16pm
    Author:  Martin

  ==============================================================================
*/

#ifndef ASCIIWITHNOTEVALUESTYPEFACE_H_INCLUDED
#define ASCIIWITHNOTEVALUESTYPEFACE_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"

// a custom typeface containing note value glyphs
class AsciiWithNoteValuesTypeface : public CustomTypeface
{
public:
	AsciiWithNoteValuesTypeface();

	// enum of utf-8 character codes
	enum NoteValue
	{
		NoteValue_64th_triplet	= 0xE000,
		NoteValue_64th			= 0xE001,
		NoteValue_32nd_triplet	= 0xE002,
		NoteValue_32nd			= 0xE003,
		NoteValue_16th_triplet	= 0xE004,
		NoteValue_32nd_dotted	= 0xE005,
		NoteValue_16th			= 0xE006,
		NoteValue_8th_triplet	= 0xE007,
		NoteValue_16th_dotted	= 0xE008,
		NoteValue_8th			= 0xE009,
		NoteValue_4th_triplet	= 0xE00A,
		NoteValue_8th_dotted	= 0xE00B,
		NoteValue_4th			= 0xE00C,
		NoteValue_half_triplet	= 0xE00D,
		NoteValue_4th_dotted	= 0xE00E,
		NoteValue_half			= 0xE00F,
		NoteValue_whole_triplet = 0xE010,
		NoteValue_half_dotted	= 0xE011,
		NoteValue_whole			= 0xE012,
		NoteValue_double_triplet= 0xE013,
		NoteValue_whole_dotted	= 0xE014,
		NoteValue_double		= 0xE015
	};

	// UTF-8 String containing the character for the note value
	static String getNoteString(NoteValue value);

private:

};

#endif  // ASCIIWITHNOTEVALUESTYPEFACE_H_INCLUDED
