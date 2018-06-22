/*
  ==============================================================================

    Waveforms.cpp
    Created: 22 Sep 2014 8:38:14pm
    Author:  Martin

  ==============================================================================
*/

#include "Waveforms.h"

Waveforms::Waveforms(GrooveboxConnector::GrooveboxModel groovebox_model)
{
	reloadForModel(groovebox_model);
}

void Waveforms::reloadForModel(GrooveboxConnector::GrooveboxModel groovebox_model)
{
	m_grooveboxModel = groovebox_model;
	m_modelWithGroupC = false;
	loadWaveforms(WAVES_A);
	loadWaveforms(WAVES_B);
	if (m_grooveboxModel == GrooveboxConnector::Model_JX_305)
	{
		loadWaveforms(WAVES_C_JX305);
		m_modelWithGroupC = true;
	}
	else if (m_grooveboxModel == GrooveboxConnector::Model_MC_307)
	{
		loadWaveforms(WAVES_C_MC307);
		m_modelWithGroupC = true;
	}
}

void Waveforms::loadWaveforms(WaveGroup group)
{
	int sizeInBytes(0);
	const char* rawTextFile = nullptr;
	switch (group)
	{
	case Waveforms::WAVES_A:
		m_aWaveNames.clear();
		m_aWaveLongNames.clear();
		rawTextFile = BinaryData::WAVES_A_txt;
		sizeInBytes = BinaryData::WAVES_A_txtSize;
		break;
	case Waveforms::WAVES_B:
		m_bWaveNames.clear();
		m_bWaveLongNames.clear();
		rawTextFile = BinaryData::WAVES_B_txt;
		sizeInBytes = BinaryData::WAVES_B_txtSize;
		break;
	case Waveforms::WAVES_C_JX305:
		m_cWaveNames.clear();
		m_cWaveLongNames.clear();
		rawTextFile = BinaryData::WAVES_C_JX305_txt;
		sizeInBytes = BinaryData::WAVES_C_JX305_txtSize;
		break;
	case Waveforms::WAVES_C_MC307:
		m_cWaveNames.clear();
		m_cWaveLongNames.clear();
		rawTextFile = BinaryData::WAVES_C_MC307_txt;
		sizeInBytes = BinaryData::WAVES_C_MC307_txtSize;
		break;
	default:
		break;
	}
	if (rawTextFile != nullptr && sizeInBytes > 0)
	{
		// load waveform names
		StringArray lines = StringArray::fromLines(/*wavesFile.loadFileAsString()*/String(CharPointer_UTF8(rawTextFile)));
		StringArray line;
		for (int i = 0; i < lines.size(); i++)
		{
			line.clear();
			line = StringArray::fromTokens(lines[i], "\t", String());
			if (line.size() > 0)
			{
				if (group == WAVES_A) m_aWaveNames.add(line[0]);
				else if (group == WAVES_B) m_bWaveNames.add(line[0]);
				else if (group == WAVES_C_JX305 || group == WAVES_C_MC307) m_cWaveNames.add(line[0]);

				if (line.size() > 1)
				{
					if (group == WAVES_A) m_aWaveLongNames.add(line[1]);
					else if (group == WAVES_B) m_bWaveLongNames.add(line[1]);
					else if (group == WAVES_C_JX305 || group == WAVES_C_MC307) m_cWaveLongNames.add(line[1]);
				}
				else
				{
					// long name not specified, add empty string for long name to maintain correct indexing
					if (group == WAVES_A) m_aWaveLongNames.add(String());
					else if (group == WAVES_B) m_bWaveLongNames.add(String());
					else if (group == WAVES_C_JX305 || group == WAVES_C_MC307) m_cWaveLongNames.add(String());
				}
			}
			else // no readable name specified, add empty string for name and long name to maintain correct indexing
			{
				if (group == WAVES_A) m_aWaveNames.add(String());
				else if (group == WAVES_B) m_bWaveNames.add(String());
				else if (group == WAVES_C_JX305 || group == WAVES_C_MC307) m_cWaveNames.add(String());
				if (group == WAVES_A) m_aWaveLongNames.add(String());
				else if (group == WAVES_B) m_bWaveLongNames.add(String());
				else if (group == WAVES_C_JX305 || group == WAVES_C_MC307) m_cWaveLongNames.add(String());
			}
		}
	}
}

String Waveforms::getName(WaveGroup group, int waveIndexInGroup)
{
	if (waveIndexInGroup < 0)return String();

	if (group == WAVES_A && m_aWaveNames.size() >= waveIndexInGroup + 1) return m_aWaveNames[waveIndexInGroup];
	else if (group == WAVES_B && m_bWaveNames.size() >= waveIndexInGroup + 1) return m_bWaveNames[waveIndexInGroup];
	else if ((group == WAVES_C_JX305 || group==WAVES_C_MC307) && m_cWaveNames.size() >= waveIndexInGroup + 1) return m_cWaveNames[waveIndexInGroup];
	return String();
}

String Waveforms::getLongName(WaveGroup group, int waveIndexInGroup)
{
	if (waveIndexInGroup < 0)return String();

	if (group == WAVES_A && m_aWaveLongNames.size() >= waveIndexInGroup + 1) return m_aWaveLongNames[waveIndexInGroup];
	else if (group == WAVES_B && m_bWaveLongNames.size() >= waveIndexInGroup + 1) return m_bWaveLongNames[waveIndexInGroup];
	else if ((group == WAVES_C_JX305 || group == WAVES_C_MC307) && m_cWaveLongNames.size() >= waveIndexInGroup + 1) return m_cWaveLongNames[waveIndexInGroup];
	return String();
}

String Waveforms::getButtonText(WaveGroup group, int waveIndexInGroup)
{
	// eg. "A001 Dist TB 303a"
	return String::charToString(getGroupChar(group)) + String(waveIndexInGroup+1).paddedLeft('0', 3) + " " + getName(group, waveIndexInGroup);
}
; 

bool Waveforms::isModelWithGroupC()
{
	return m_modelWithGroupC;
}

int Waveforms::getGroupSize(WaveGroup group)
{
	if (group == WAVES_A) return m_aWaveLongNames.size();
	else if (group == WAVES_B) return m_bWaveLongNames.size();
	else if (group == WAVES_C_JX305 || group == WAVES_C_MC307) return m_cWaveLongNames.size();
	return 0;
}

Waveforms::WaveGroup Waveforms::getGroupForId(uint8 id)
{
	if (id == 1) return WAVES_A;
	else if (id == 2) return WAVES_B;
	else if (id == 3)
	{
		if (m_grooveboxModel == GrooveboxConnector::Model_JX_305) return WAVES_C_JX305;
		else if (m_grooveboxModel==GrooveboxConnector::Model_MC_307) return WAVES_C_MC307;
	}
	return WAVES_A;
}

int Waveforms::get32BitIntForWaveform(uint8 groupId, uint8 waveIndexInGroup, uint8 groupType)
{
	int waveformIndexInGroupHiNibble = (waveIndexInGroup >> 4) & 0xF;
	int waveformIndexInGroupLoNibble = waveIndexInGroup & 0xF;
	return
		(groupType << 24) +
		(groupId << 16) +
		(waveformIndexInGroupHiNibble << 8) +
		waveformIndexInGroupLoNibble;
}

void Waveforms::getGroupAndIndexFrom32BitInt(int thirtytwoBitInt, uint8 &groupType, uint8 &groupId, uint8 &waveIndexInGroup)
{
	groupType = (thirtytwoBitInt >> 24) & 0x7F;
	groupId = (thirtytwoBitInt >> 16) & 0x7F;
	uint8 waveformIndexInGroupHiNibble = (thirtytwoBitInt >> 8) & 0x7F;
	uint8 waveformIndexInGroupLoNibble = thirtytwoBitInt & 0x7F;
	waveIndexInGroup = (waveformIndexInGroupHiNibble << 4) + waveformIndexInGroupLoNibble;
}
