/*
  ==============================================================================

    AsciiWithNoteValuesTypeface.cpp
    Created: 10 Oct 2014 9:39:16pm
    Author:  Martin

  ==============================================================================
*/

#include "AsciiWithNoteValuesTypeface.h"

AsciiWithNoteValuesTypeface::AsciiWithNoteValuesTypeface() :
	CustomTypeface()
{
	// copy characteristics and ASCII glyphs from default font's typeface
	Typeface* defaultTypeFacePtr = Font().getTypeface();
	setCharacteristics(defaultTypeFacePtr->getName(), defaultTypeFacePtr->getStyle(), defaultTypeFacePtr->getAscent(), 0x32);
	addGlyphsFromOtherTypeface(*defaultTypeFacePtr, 32, 94);

	// array of all char codes
	juce_wchar glyphCodes[22] = { 
		NoteValue_64th_triplet, 
		NoteValue_64th, 
		NoteValue_32nd_triplet, 
		NoteValue_32nd, 
		NoteValue_16th_triplet, 
		NoteValue_32nd_dotted, 
		NoteValue_16th, 
		NoteValue_8th_triplet, 
		NoteValue_16th_dotted, 
		NoteValue_8th, 
		NoteValue_4th_triplet,
		NoteValue_8th_dotted, 
		NoteValue_4th, 
		NoteValue_half_triplet, 
		NoteValue_4th_dotted, 
		NoteValue_half, 
		NoteValue_whole_triplet, 
		NoteValue_half_dotted, 
		NoteValue_whole, 
		NoteValue_double_triplet, 
		NoteValue_whole_dotted, 
		NoteValue_double };

	HashMap<int32, String> glyphNamesByCode;
	glyphNamesByCode.set(NoteValue_64th_triplet, "64th_triplet");
	glyphNamesByCode.set(NoteValue_64th, "64th");
	glyphNamesByCode.set(NoteValue_32nd_triplet, "32nd_triplet");
	glyphNamesByCode.set(NoteValue_32nd, "32nd");
	glyphNamesByCode.set(NoteValue_16th_triplet, "16th_triplet");
	glyphNamesByCode.set(NoteValue_32nd_dotted, "32nd_dotted");
	glyphNamesByCode.set(NoteValue_16th, "16th");
	glyphNamesByCode.set(NoteValue_8th_triplet, "8th_triplet");
	glyphNamesByCode.set(NoteValue_16th_dotted, "16th_dotted");
	glyphNamesByCode.set(NoteValue_8th, "8th");
	glyphNamesByCode.set(NoteValue_4th_triplet, "4th_triplet");
	glyphNamesByCode.set(NoteValue_8th_dotted, "8th_dotted");
	glyphNamesByCode.set(NoteValue_4th, "4th");
	glyphNamesByCode.set(NoteValue_half_triplet, "half_triplet");
	glyphNamesByCode.set(NoteValue_4th_dotted, "4th_dotted");
	glyphNamesByCode.set(NoteValue_half, "half");
	glyphNamesByCode.set(NoteValue_whole_triplet, "whole_triplet");
	glyphNamesByCode.set(NoteValue_half_dotted, "half_dotted");
	glyphNamesByCode.set(NoteValue_whole, "whole");
	glyphNamesByCode.set(NoteValue_double_triplet, "double_triplet");
	glyphNamesByCode.set(NoteValue_whole_dotted, "whole_dotted");
	glyphNamesByCode.set(NoteValue_double, "double");
	// reversed:
	HashMap<String, int32> glyphCodesByName; for (int i = 0; i < 22; i++) { glyphCodesByName.set(glyphNamesByCode[glyphCodes[i]], glyphCodes[i]); }

	// load glyphs from svg resource
	XmlDocument svgDocument(String::createStringFromData(BinaryData::NoteValueGlyphs_svg, BinaryData::NoteValueGlyphs_svgSize));
	ScopedPointer<XmlElement> svg = svgDocument.getDocumentElement();
	// svg elements must not be deleted, they are jsut references to within the svg  element tree. at the end the whole svg element must be deleted (here: scoped pointer does it)
	XmlElement* group;
	// prepare and and glyphs
	for (group = svg->getChildByName("g"); group != nullptr; group = group->getNextElementWithTagName("g"))
	{
		if (XmlElement* svgGlyphPath = group->getChildByName("path"))
		{
			if (glyphCodesByName.contains(svgGlyphPath->getStringAttribute("id")))
			{
				long int code = glyphCodesByName[svgGlyphPath->getStringAttribute("id")];
				//DBG(String::toHexString(code).paddedLeft(' ', 4) + " " + glyphNamesByCode[code] + " " + svgGlyphPath->getStringAttribute("d"));
				Path p = Drawable::parseSVGPath(svgGlyphPath->getStringAttribute("d"));
				p.scaleToFit(0.0f, 0.0f, 1.3f, 1.0f, true);
				p.applyTransform(AffineTransform().translated(0.0f, -0.8f));
				addGlyph((juce_wchar)code, p, 1.3f);
			}
		}
	}
	// set kernings
	// for (int i = 0; i < 22; i++) for (int j = 0; j < 22; j++) addKerningPair(glyphCodes[i], glyphCodes[j], 0.2f);
}

String AsciiWithNoteValuesTypeface::getNoteString(NoteValue value)
{
	switch (value)
	{
	case AsciiWithNoteValuesTypeface::NoteValue_64th_triplet:
		return String(CharPointer_UTF8("\xee\x80\x80"));
	case AsciiWithNoteValuesTypeface::NoteValue_64th:
		return String(CharPointer_UTF8("\xee\x80\x81"));
	case AsciiWithNoteValuesTypeface::NoteValue_32nd_triplet:
		return String(CharPointer_UTF8("\xee\x80\x82"));
	case AsciiWithNoteValuesTypeface::NoteValue_32nd:
		return String(CharPointer_UTF8("\xee\x80\x83"));
	case AsciiWithNoteValuesTypeface::NoteValue_16th_triplet:
		return String(CharPointer_UTF8("\xee\x80\x84"));
	case AsciiWithNoteValuesTypeface::NoteValue_32nd_dotted:
		return String(CharPointer_UTF8("\xee\x80\x85"));
	case AsciiWithNoteValuesTypeface::NoteValue_16th:
		return String(CharPointer_UTF8("\xee\x80\x86"));
	case AsciiWithNoteValuesTypeface::NoteValue_8th_triplet:
		return String(CharPointer_UTF8("\xee\x80\x87"));
	case AsciiWithNoteValuesTypeface::NoteValue_16th_dotted:
		return String(CharPointer_UTF8("\xee\x80\x88"));
	case AsciiWithNoteValuesTypeface::NoteValue_8th:
		return String(CharPointer_UTF8("\xee\x80\x89"));
	case AsciiWithNoteValuesTypeface::NoteValue_4th_triplet:
		return String(CharPointer_UTF8("\xee\x80\x8A"));
	case AsciiWithNoteValuesTypeface::NoteValue_8th_dotted:
		return String(CharPointer_UTF8("\xee\x80\x8B"));
	case AsciiWithNoteValuesTypeface::NoteValue_4th:
		return String(CharPointer_UTF8("\xee\x80\x8C"));
	case AsciiWithNoteValuesTypeface::NoteValue_half_triplet:
		return String(CharPointer_UTF8("\xee\x80\x8D"));
	case AsciiWithNoteValuesTypeface::NoteValue_4th_dotted:
		return String(CharPointer_UTF8("\xee\x80\x8E"));
	case AsciiWithNoteValuesTypeface::NoteValue_half:
		return String(CharPointer_UTF8("\xee\x80\x8F"));
	case AsciiWithNoteValuesTypeface::NoteValue_whole_triplet:
		return String(CharPointer_UTF8("\xee\x80\x90"));
	case AsciiWithNoteValuesTypeface::NoteValue_half_dotted:
		return String(CharPointer_UTF8("\xee\x80\x91"));
	case AsciiWithNoteValuesTypeface::NoteValue_whole:
		return String(CharPointer_UTF8("\xee\x80\x92"));
	case AsciiWithNoteValuesTypeface::NoteValue_double_triplet:
		return String(CharPointer_UTF8("\xee\x80\x93"));
	case AsciiWithNoteValuesTypeface::NoteValue_whole_dotted:
		return String(CharPointer_UTF8("\xee\x80\x94"));
	case AsciiWithNoteValuesTypeface::NoteValue_double:
		return String(CharPointer_UTF8("\xee\x80\x95"));
	default:
		return String();
	}
}
