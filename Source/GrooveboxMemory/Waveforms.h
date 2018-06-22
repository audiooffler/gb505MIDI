/*
  ==============================================================================

    Waveforms.h
    Created: 18 Sep 2014 12:54:49pm
    Author:  Spindler

  ==============================================================================
*/

#ifndef WAVEFORMS_H_INCLUDED
#define WAVEFORMS_H_INCLUDED

#include "JuceHeader.h"
#include "../MIDIConnection/GrooveboxConnector.h"

class Waveforms
{
public:
	enum WaveGroup
	{
		WAVES_A,
		WAVES_B,
		WAVES_C_JX305,
		WAVES_C_MC307
	};
	
	Waveforms(GrooveboxConnector::GrooveboxModel groovebox_model);
	
	static String getGroupName(WaveGroup group)
	{
		switch (group)
		{
		case WAVES_A: return "WAVES_A";
		case WAVES_B: return "WAVES_B";
		case WAVES_C_JX305: return "WAVES_C_JX305";
		case WAVES_C_MC307: return "WAVES_C_MC307";
		default: return String();
		}
	}
	
	static String getGroupFileName(WaveGroup group)
	{
		String groupName(getGroupName(group));
		return groupName.isNotEmpty() ? groupName + ".txt" : String();
	}

	static uint8 getGroupId(WaveGroup group)
	{
		switch (group)
		{
		case WAVES_A: return 1;
		case WAVES_B: return 2;
		case WAVES_C_JX305: return 3;
		case WAVES_C_MC307: return 3;
		default: return 0;
		}
	}

	WaveGroup getGroupForId(uint8 id);

	static char getGroupChar(WaveGroup group)
	{
		switch (group)
		{
		case WAVES_A: return 'A';
		case WAVES_B: return 'B';
		case WAVES_C_JX305: return 'C';
		case WAVES_C_MC307: return 'C';
		default: return ' ';
		}
	}

	static uint8 getGroupType(WaveGroup /*group*/)
	{
		return 0;
	}

	String getName(WaveGroup group, int waveIndexInGroup);
	String getLongName(WaveGroup group, int waveIndexInGroup);
	String getButtonText(WaveGroup group, int waveIndexInGroup); // eg. "A:001 Dist TB 303a"

	int getGroupSize(WaveGroup group);

	bool isModelWithGroupC();

	void reloadForModel(GrooveboxConnector::GrooveboxModel groovebox_model);

	static int get32BitIntForWaveform(uint8 groupId, uint8 waveIndexInGroup, uint8 groupType=0);
	static void getGroupAndIndexFrom32BitInt(int thirtytwoBitInt, uint8 &groupType, uint8 &groupId, uint8 &waveIndexInGroup);


private:
	GrooveboxConnector::GrooveboxModel m_grooveboxModel;
	bool m_modelWithGroupC;
	StringArray m_aWaveNames, m_bWaveNames, m_cWaveNames;
	StringArray m_aWaveLongNames, m_bWaveLongNames, m_cWaveLongNames;

	void loadWaveforms(WaveGroup group);
};

#endif  // WAVEFORMS_H_INCLUDED
