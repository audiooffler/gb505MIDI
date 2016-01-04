/*
  ==============================================================================

    PatternSetupBlock.h
    Created: 15 Jan 2014 9:19:00pm
    Author:  Martin

  ==============================================================================
*/

#ifndef PATTERNSETUPBLOCK_H_INCLUDED
#define PATTERNSETUPBLOCK_H_INCLUDED

#include "GrooveboxMemoryBlock.h"

class PatternSetupBlock : public GrooveboxMemoryBlock
{
	// setup common1
	// setup common2
	// setup common3?
	// setups part1 .. part 7, part r
public:
	PatternSetupBlock() :
		GrooveboxMemoryBlock(0x30000000, "Pattern Setup Data", "1-5", 0x00000000)
	{
		m_name = "Pattern Setup";
		// no parameters, just big data block
	}

private:
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(PatternSetupBlock)
};



#endif  // PATTERNSETUPBLOCK_H_INCLUDED
