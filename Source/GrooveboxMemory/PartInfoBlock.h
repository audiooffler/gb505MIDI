/*
  ==============================================================================

    PartInfoBlock.h
    Created: 15 Jan 2014 9:17:59pm
    Author:  Martin

  ==============================================================================
*/

#ifndef PARTINFOBLOCK_H_INCLUDED
#define PARTINFOBLOCK_H_INCLUDED

#include "GrooveboxMemoryBlock.h"
#include "../GUI/AsciiWithNoteValuesTypeface.h"

class PartInfoCommonBlock : public GrooveboxMemoryBlock, public ChangeListener
{
public:
	PartInfoCommonBlock();

	String getEffectDescription(){ return m_EffectDescription; }

	// typeIndex must by of 0..24
	void refreshParametersForMFXTypeValue(uint8 mFXTypeIndex);
	
	// delayType must by of 0..1 (short / long)
	void refreshParametersForDelayTypeValue(uint8 delayType);

	// for setup effects changed
	void changeListenerCallback(ChangeBroadcaster *source) override;
	
private:
	String m_EffectDescription;
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(PartInfoCommonBlock)
};

// 8 instances
// TODO Receive Switches in Pattern Setup too?
class PartInfoPartBlock : public GrooveboxMemoryBlock, public ChangeListener
{
public:
	PartInfoPartBlock::PartInfoPartBlock(AllParts part);

	AllParts getPart(){ return m_part; }

	// returns 8-bit value by combining two nibbles
	uint8 getPatchNumber() { return (uint8)(m_data[0x04] << 4 | m_data[0x05]); }

	// 8 bit value
	void setPatchNumber(uint8 patchNumber) { m_data[0x04] = patchNumber >> 4; m_data[0x05] = patchNumber & 0xF; }

	// patchGroupType may be 0 or 3, patchGroupId may be 1..9 for Part 1..7 or 1 | 3 |4 for Part R
	String getPatchGroupNameByTypeAndID(uint8 patchGroupType, uint8 patchGroupId);

	void getBankSelMSB_LSBforGroup(uint8 patchGroupType, uint8 patchGroupId, uint8& msb, uint8& lsb, GrooveboxConnector::GrooveboxModel model = GrooveboxConnector::Model_MC_307);

	void getGroupFromBankSelMSB_LSB(uint8 msb, uint8 lsb, uint8 &patchGroupType, uint8 &patchGroupId);

	void handleCC(uint8 channel, uint8 controllerType, uint8 value);

	// for setup part changed
	void changeListenerCallback(ChangeBroadcaster *source) override;

private:
	AllParts m_part;
	uint8 lastCC00BankMsbVal = 0;
	uint8 lastCC32BankLsbVal = 0;
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(PartInfoPartBlock)
};

class PartInfoBlock : public GrooveboxMemoryBlock
{
public:
	PartInfoBlock();

	PartInfoCommonBlock* getPartInfoCommonBlockPtr() { return dynamic_cast<PartInfoCommonBlock*>(getSubBlock(0)); }

	PartInfoPartBlock* getPartInfoPartBlockPtr(AllParts part);

private:
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(PartInfoBlock)
};



#endif  // PARTINFOBLOCK_H_INCLUDED
