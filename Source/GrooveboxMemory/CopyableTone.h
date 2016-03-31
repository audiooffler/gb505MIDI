/*
  ==============================================================================

    CopyableTone.h
    Created: 31 Mar 2016 9:20:30am
    Author:  Spindler

  ==============================================================================
*/

#ifndef COPYABLETONE_H_INCLUDED
#define COPYABLETONE_H_INCLUDED

#include "JuceHeader.h"
#include "RhythmSetBlock.h"
#include "SynthPatchesBlock.h"

class CopyableTone
{
public:
	CopyableTone();
	CopyableTone(PatchToneBlock* patchToneToCopyFrom);
	CopyableTone(RhythmNoteBlock* rhythmToneToCopyFrom);
	CopyableTone(const SyxMsg* sysExOfToneToLoad);
	~CopyableTone();
	// allowed toneNumber values are Tone1 = 0x1000, Tone2 = 0x1200, Tone3 = 0x1400, Tone4 = 0x1600 for synth parts or 35..98 for rhythm part
	void copyTo(AllParts part, int toneNumber);
	void swapWith(AllParts part, int toneNumber);
private:
	AllParts m_partOrigin;
	int m_toneNumberOrigin; // allowed values are Tone1 = 0x1000, Tone2 = 0x1200, Tone3 = 0x1400, Tone4 = 0x1600 for synth parts or 35..98 for rhythm part

	enum SynthToneAddressOffsets
	{
		A_PATCH_TONESWITCH = 0x00,
		A_PATCH_WAVEGROUPTYPE = 0x01,
		A_PATCH_WAVEGROUPID = 0x02,
		A_PATCH_WAVENUMBERMSB = 0x03,
		A_PATCH_WAVENUMBERLSB = 0x04,
		A_PATCH_WAVEGAIN = 0x05,
		A_PATCH_FXMSWITCH = 0x06,
		A_PATCH_FXMCOLOR = 0x07,
		A_PATCH_FXMDEPTH = 0x08,
		A_PATCH_JV2080DELAYMODE = 0x09,
		A_PATCH_JV2080DELAYTIME = 0x0A,
		A_PATCH_VELOCITYCROSSFADE = 0x0B,
		A_PATCH_VELOCITYRANGELOWER = 0x0C,
		A_PATCH_VELOCITYRANGEUPPER = 0x0D,
		A_PATCH_KEYBOARDRANGELOWER = 0x0E,
		A_PATCH_KEYBOARDRANGEUPPER = 0x0F,
		A_PATCH_JV2080REDAMPERCONTROLSWITCH = 0x10,
		A_PATCH_JV2080VOLUMECONTROLSWITCH = 0x11,
		A_PATCH_JV2080HOLD1CONTROLSWITCH = 0x12,
		A_PATCH_JV2080PITCHBENDCONTROLSWIT = 0x13,
		A_PATCH_JV2080PANCONTROLSWITCH = 0x14,
		A_PATCH_MODULATIONDESTINATION1 = 0x15,
		A_PATCH_MODULATIONDEPTH1 = 0x16,
		A_PATCH_MODULATIONDESTINATION2 = 0x17,
		A_PATCH_MODULATIONDEPTH2 = 0x18,
		A_PATCH_MODULATIONDESTINATION3 = 0x19,
		A_PATCH_MODULATIONDEPTH3 = 0x1A,
		A_PATCH_MODULATIONDESTINATION4 = 0x1B,
		A_PATCH_MODULATIONDEPTH4 = 0x1C,
		A_PATCH_PITCHBENDDESTINATION1 = 0x1D,
		A_PATCH_PITCHBENDDEPTH1 = 0x1E,
		A_PATCH_PITCHBENDDESTINATION2 = 0x1F,
		A_PATCH_PITCHBENDDEPTH2 = 0x20,
		A_PATCH_PITCHBENDDESTINATION3 = 0x21,
		A_PATCH_PITCHBENDDEPTH3 = 0x22,
		A_PATCH_PITCHBENDDESTINATION4 = 0x23,
		A_PATCH_PITCHBENDDEPTH4 = 0x24,
		A_PATCH_AFTERTOUCHDESTINATION1 = 0x25,
		A_PATCH_AFTERTOUCHDEPTH1 = 0x26,
		A_PATCH_AFTERTOUCHDESTINATION2 = 0x27,
		A_PATCH_AFTERTOUCHDEPTH2 = 0x28,
		A_PATCH_AFTERTOUCHDESTINATION3 = 0x29,
		A_PATCH_AFTERTOUCHDEPTH3 = 0x2A,
		A_PATCH_AFTERTOUCHDESTINATION4 = 0x2B,
		A_PATCH_AFTERTOUCHDEPTH4 = 0x2C,
		A_PATCH_LFO1WAVEFORM = 0x2D,
		A_PATCH_LFO1KEYSYNC = 0x2E,
		A_PATCH_LFO1RATE = 0x2F,
		A_PATCH_LFO1OFFSET = 0x30,
		A_PATCH_LFO1DELAYTIME = 0x31,
		A_PATCH_LFO1FADEMODE = 0x32,
		A_PATCH_LFO1FADETIME = 0x33,
		A_PATCH_LFO1TEMPOSYNC = 0x34,
		A_PATCH_LFO2WAVEFORM = 0x35,
		A_PATCH_LFO2KEYSYNC = 0x36,
		A_PATCH_LFO2RATE = 0x37,
		A_PATCH_LFO2OFFSET = 0x38,
		A_PATCH_LFO2DELAYTIME = 0x39,
		A_PATCH_LFO2FADEMODE = 0x3A,
		A_PATCH_LFO2FADETIME = 0x3B,
		A_PATCH_LFO2TEMPOSYNC = 0x3C,
		A_PATCH_COARSETUNE = 0x3D,
		A_PATCH_FINETUNE = 0x3E,
		A_PATCH_RANDOMPITCHDEPTH = 0x3F,
		A_PATCH_PITCHKEYFOLLOW = 0x40,
		A_PATCH_PITCHENVELOPEDEPTH = 0x41,
		A_PATCH_PITCHENVELOPEVELOCITYSENS = 0x42,
		A_PATCH_PITCHENVELOPEVELOCITYTIME1 = 0x43,
		A_PATCH_PITCHENVELOPEVELOCITYTIME4 = 0x44,
		A_PATCH_PITCHENVELOPETIMEKEYFOLLOW = 0x45,
		A_PATCH_PITCHENVELOPETIME1 = 0x46,
		A_PATCH_PITCHENVELOPETIME2 = 0x47,
		A_PATCH_PITCHENVELOPETIME3 = 0x48,
		A_PATCH_PITCHENVELOPETIME4 = 0x49,
		A_PATCH_PITCHENVELOPELEVEL1 = 0x4A,
		A_PATCH_PITCHENVELOPELEVEL2 = 0x4B,
		A_PATCH_PITCHENVELOPELEVEL3 = 0x4C,
		A_PATCH_PITCHENVELOPELEVEL4 = 0x4D,
		A_PATCH_PITCHLFO1DEPTH = 0x4E,
		A_PATCH_PITCHLFO2DEPTH = 0x4F,
		A_PATCH_FILTERTYPE = 0x50,
		A_PATCH_CUTOFFFREQUENCY = 0x51,
		A_PATCH_CUTOFFKEYFOLLOW = 0x52,
		A_PATCH_RESONANCE = 0x53,
		A_PATCH_RESONANCEVELOCITYSENS = 0x54,
		A_PATCH_FILTERENVELOPEDEPTH = 0x55,
		A_PATCH_FILTERENVELOPEVELOCITYCURVE = 0x56,
		A_PATCH_FILTERENVELOPEVELOCITYSENS = 0x57,
		A_PATCH_FILTERENVELOPEVELOCITYTIME1 = 0x58,
		A_PATCH_FILTERENVELOPEVELOCITYTIME4 = 0x59,
		A_PATCH_FILTERENVELOPETIMEKEYFOLLOW = 0x5A,
		A_PATCH_FILTERENVELOPETIME1 = 0x5B,
		A_PATCH_FILTERENVELOPETIME2 = 0x5C,
		A_PATCH_FILTERENVELOPETIME3 = 0x5D,
		A_PATCH_FILTERENVELOPETIME4 = 0x5E,
		A_PATCH_FILTERENVELOPELEVEL1 = 0x5F,
		A_PATCH_FILTERENVELOPELEVEL2 = 0x60,
		A_PATCH_FILTERENVELOPELEVEL3 = 0x61,
		A_PATCH_FILTERENVELOPELEVEL4 = 0x62,
		A_PATCH_FILTERLFO1DEPTH = 0x63,
		A_PATCH_FILTERLFO2DEPTH = 0x64,
		A_PATCH_TONELEVEL = 0x65,
		A_PATCH_BIASDIRECTION = 0x66,
		A_PATCH_BIASPOINT = 0x67,
		A_PATCH_BIASLEVEL = 0x68,
		A_PATCH_AMPENVELOPEVELOCITYCURVE = 0x69,
		A_PATCH_AMPENVELOPEVELOCITYSENS = 0x6A,
		A_PATCH_AMPENVELOPEVELOCITYTIME1 = 0x6B,
		A_PATCH_AMPENVELOPEVELOCITYTIME4 = 0x6C,
		A_PATCH_AMPENVELOPETIMEKEYFOLLOW = 0x6D,
		A_PATCH_AMPENVELOPETIME1 = 0x6E,
		A_PATCH_AMPENVELOPETIME2 = 0x6F,
		A_PATCH_AMPENVELOPETIME3 = 0x70,
		A_PATCH_AMPENVELOPETIME4 = 0x71,
		A_PATCH_AMPENVELOPELEVEL1 = 0x72,
		A_PATCH_AMPENVELOPELEVEL2 = 0x73,
		A_PATCH_AMPENVELOPELEVEL3 = 0x74,
		A_PATCH_AMPLFO1DEPTH = 0x75,
		A_PATCH_AMPLFO2DEPTH = 0x76,
		A_PATCH_TONEPAN = 0x77,
		A_PATCH_PANKEYFOLLOW = 0x78,
		A_PATCH_RANDOMPANSWITCH = 0x79,
		A_PATCH_ALTERNATEPANDEPTH = 0x7A,
		A_PATCH_PANLFO1DEPTH = 0x7B,
		A_PATCH_PANLFO2DEPTH = 0x7C,
		A_PATCH_JV2080OUTPUTASSIGN = 0x7D,
		A_PATCH_JV2080MIXEFXSENDLEVEL = 0x7E,
		A_PATCH_JV2080CHORUSSENDLEVEL = 0x7F,
		A_PATCH_JV2080REVERBSENDLEVEL = 0x80,
		A_PATCH_TOTAL_SIZE = 0x81
	};

	enum RhyToneAddressOffsets
	{
		A_RHY_TONESWITCH = 0x00,
		A_RHY_WAVEGROUPTYPE = 0x01,
		A_RHY_WAVEGROUPID = 0x02,
		A_RHY_WAVENUMBERMSB = 0x03,
		A_RHY_WAVENUMBERLSB = 0x04,
		A_RHY_WAVEGAIN = 0x05,
		A_RHY_BENDRANGE = 0x06,
		A_RHY_MUTEGROUP = 0x07,
		A_RHY_ENVELOPEMODE = 0x08,
		A_RHY_JV2080VOLUMECONTROLSWITCH = 0x09,
		A_RHY_JV2080HOLD1CONTROLSWITCH = 0x0A,
		A_RHY_JV2080PANCONTROLSWITCH = 0x0B,
		A_RHY_COARSETUNE = 0x0C,
		A_RHY_FINETUNE = 0x0D,
		A_RHY_RANDOMPITCHDEPTH = 0x0E,
		A_RHY_PITCHENVELOPEDEPTH = 0x0F,
		A_RHY_PITCHENVELOPEVELOCITYSENS = 0x10,
		A_RHY_PITCHENVELOPEVELOCITYTIME1 = 0x11,
		A_RHY_PITCHENVELOPETIME1 = 0x12,
		A_RHY_PITCHENVELOPETIME2 = 0x13,
		A_RHY_PITCHENVELOPETIME3 = 0x14,
		A_RHY_PITCHENVELOPETIME4 = 0x15,
		A_RHY_PITCHENVELOPELEVEL1 = 0x16,
		A_RHY_PITCHENVELOPELEVEL2 = 0x17,
		A_RHY_PITCHENVELOPELEVEL3 = 0x18,
		A_RHY_PITCHENVELOPELEVEL4 = 0x19,
		A_RHY_FILTERTYPE = 0x1A,
		A_RHY_CUTOFFFREQUENCY = 0x1B,
		A_RHY_RESONANCE = 0x1C,
		A_RHY_RESONANCEVELOCITYSENS = 0x1D,
		A_RHY_FILTERENVELOPEDEPTH = 0x1E,
		A_RHY_FILTERENVELOPEVELOCITYSENS = 0x1F,
		A_RHY_FILTERENVELOPEVELOCITYTIME1 = 0x20,
		A_RHY_FILTERENVELOPETIME1 = 0x21,
		A_RHY_FILTERENVELOPETIME2 = 0x22,
		A_RHY_FILTERENVELOPETIME3 = 0x23,
		A_RHY_FILTERENVELOPETIME4 = 0x24,
		A_RHY_FILTERENVELOPELEVEL1 = 0x25,
		A_RHY_FILTERENVELOPELEVEL2 = 0x23,
		A_RHY_FILTERENVELOPELEVEL3 = 0x27,
		A_RHY_FILTERENVELOPELEVEL4 = 0x28,
		A_RHY_TONELEVEL = 0x29,
		A_RHY_AMPENVELOPEVELOCITYSENS = 0x2A,
		A_RHY_AMPENVELOPEVELOCITYTIME1 = 0x2B,
		A_RHY_AMPENVELOPETIME1 = 0x2C,
		A_RHY_AMPENVELOPETIME2 = 0x2D,
		A_RHY_AMPENVELOPETIME3 = 0x2E,
		A_RHY_AMPENVELOPETIME4 = 0x2F,
		A_RHY_AMPENVELOPELEVEL1 = 0x30,
		A_RHY_AMPENVELOPELEVEL2 = 0x31,
		A_RHY_AMPENVELOPELEVEL3 = 0x32,
		A_RHY_TONEPAN = 0x33,
		A_RHY_RANDOMPANSWITCH = 0x34,
		A_RHY_ALTERNATEPANDEPTH = 0x35,
		A_RHY_MFXSWITCH = 0x36,
		A_RHY_JV2080MIXEFXSENDLEVEL = 0x37,
		A_RHY_DELAYSENDLEVEL = 0x38,
		A_RHY_REVERBSENDLEVEL = 0x39,
		A_RHY_TOTAL_SIZE = 0x3A
	};

#pragma region local values for Tone Parameters with defaults
	uint8 m_BendRange = 0;
	uint8 m_MuteGroup = 0;
	uint8 m_EnvelopeMode = 0;
	uint8 m_ToneSwitch = 1;
	uint8 m_WaveGroupType = 0;
	uint8 m_WaveGroupID = 1;
	uint8 m_WaveNumberMSB = 0;
	uint8 m_WaveNumberLSB = 0;
	uint8 m_WaveGain = 2;
	uint8 m_FXMSwitch = 0;
	uint8 m_FXMColor = 0;
	uint8 m_FXMDepth = 0;
	uint8 m_JV2080DelayMode = 0;
	uint8 m_JV2080DelayTime = 0;
	uint8 m_VelocityCrossFade = 0;
	uint8 m_VelocityRangeLower = 1;
	uint8 m_VelocityRangeUpper = 127;
	uint8 m_KeyboardRangeLower = 0;
	uint8 m_KeyboardRangeUpper = 127;
	uint8 m_JV2080RedamperControlSwitch = 1;
	uint8 m_JV2080VolumeControlSwitch = 1;
	uint8 m_JV2080Hold1ControlSwitch = 1;
	uint8 m_JV2080PitchBendControlSwit = 1;
	uint8 m_JV2080PanControlSwitch = 1;
	uint8 m_ModulationDestination1 = 0;
	uint8 m_ModulationDepth1 = 63;
	uint8 m_ModulationDestination2 = 0;
	uint8 m_ModulationDepth2 = 63;
	uint8 m_ModulationDestination3 = 0;
	uint8 m_ModulationDepth3 = 63;
	uint8 m_ModulationDestination4 = 0;
	uint8 m_ModulationDepth4 = 63;
	uint8 m_PitchBendDestination1 = 0;
	uint8 m_PitchBendDepth1 = 63;
	uint8 m_PitchBendDestination2 = 0;
	uint8 m_PitchBendDepth2 = 63;
	uint8 m_PitchBendDestination3 = 0;
	uint8 m_PitchBendDepth3 = 63;
	uint8 m_PitchBendDestination4 = 0;
	uint8 m_PitchBendDepth4 = 63;
	uint8 m_AftertouchDestination1 = 0;
	uint8 m_AftertouchDepth1 = 63;
	uint8 m_AftertouchDestination2 = 0;
	uint8 m_AftertouchDepth2 = 63;
	uint8 m_AftertouchDestination3 = 0;
	uint8 m_AftertouchDepth3 = 63;
	uint8 m_AftertouchDestination4 = 0;
	uint8 m_AftertouchDepth4 = 63;
	uint8 m_LFO1Waveform = 1;
	uint8 m_LFO1KeySync = 0;
	uint8 m_LFO1Rate = 100;
	uint8 m_LFO1Offset = 2;
	uint8 m_LFO1DelayTime = 10;
	uint8 m_LFO1FadeMode = 0;
	uint8 m_LFO1FadeTime = 0;
	uint8 m_LFO1TempoSync = 0;
	uint8 m_LFO2Waveform = 0;
	uint8 m_LFO2KeySync = 0;
	uint8 m_LFO2Rate = 92;
	uint8 m_LFO2Offset = 2;
	uint8 m_LFO2DelayTime = 0;
	uint8 m_LFO2FadeMode = 0;
	uint8 m_LFO2FadeTime = 0;
	uint8 m_LFO2TempoSync = 0;
	uint8 m_CoarseTune = 48;
	uint8 m_FineTune = 50;
	uint8 m_RandomPitchDepth = 0;
	uint8 m_PitchKeyfollow = 12;
	uint8 m_PitchEnvelopeDepth = 12;
	uint8 m_PitchEnvelopeVelocitySens = 50;
	uint8 m_PitchEnvelopeVelocityTime1 = 7;
	uint8 m_PitchEnvelopeVelocityTime4 = 7;
	uint8 m_PitchEnvelopeTimeKeyfollow = 7;
	uint8 m_PitchEnvelopeTime1 = 0;
	uint8 m_PitchEnvelopeTime2 = 0;
	uint8 m_PitchEnvelopeTime3 = 0;
	uint8 m_PitchEnvelopeTime4 = 0;
	uint8 m_PitchEnvelopeLevel1 = 63;
	uint8 m_PitchEnvelopeLevel2 = 63;
	uint8 m_PitchEnvelopeLevel3 = 63;
	uint8 m_PitchEnvelopeLevel4 = 63;
	uint8 m_PitchLFO1Depth = 0;
	uint8 m_PitchLFO2Depth = 0;
	uint8 m_FilterType = 1;
	uint8 m_CutoffFrequency = 127;
	uint8 m_CutoffKeyfollow = 5;
	uint8 m_Resonance = 0;
	uint8 m_ResonanceVelocitySens = 50;
	uint8 m_FilterEnvelopeDepth = 63;
	uint8 m_FilterEnvelopeVelocityCurve = 0;
	uint8 m_FilterEnvelopeVelocitySens = 50;
	uint8 m_FilterEnvelopeVelocityTime1 = 7;
	uint8 m_FilterEnvelopeVelocityTime4 = 7;
	uint8 m_FilterEnvelopeTimeKeyfollow = 7;
	uint8 m_FilterEnvelopeTime1 = 0;
	uint8 m_FilterEnvelopeTime2 = 0;
	uint8 m_FilterEnvelopeTime3 = 0;
	uint8 m_FilterEnvelopeTime4 = 0;
	uint8 m_FilterEnvelopeLevel1 = 127;
	uint8 m_FilterEnvelopeLevel2 = 127;
	uint8 m_FilterEnvelopeLevel3 = 127;
	uint8 m_FilterEnvelopeLevel4 = 127;
	uint8 m_FilterLFO1Depth = 0;
	uint8 m_FilterLFO2Depth = 0;
	uint8 m_ToneLevel = 127;
	uint8 m_BiasDirection = 3;
	uint8 m_BiasPoint = 60;
	uint8 m_BiasLevel = 7;
	uint8 m_AmpEnvelopeVelocityCurve = 0;
	uint8 m_AmpEnvelopeVelocitySens = 100;
	uint8 m_AmpEnvelopeVelocityTime1 = 7;
	uint8 m_AmpEnvelopeVelocityTime4 = 7;
	uint8 m_AmpEnvelopeTimeKeyfollow = 7;
	uint8 m_AmpEnvelopeTime1 = 0;
	uint8 m_AmpEnvelopeTime2 = 0;
	uint8 m_AmpEnvelopeTime3 = 0;
	uint8 m_AmpEnvelopeTime4 = 127;
	uint8 m_AmpEnvelopeLevel1 = 127;
	uint8 m_AmpEnvelopeLevel2 = 127;
	uint8 m_AmpEnvelopeLevel3 = 127;
	uint8 m_AmpLFO1Depth = 0;
	uint8 m_AmpLFO2Depth = 0;
	uint8 m_TonePan = 64;
	uint8 m_PanKeyfollow = 7;
	uint8 m_RandomPanSwitch = 0;
	uint8 m_AlternatePanDepth = 64;
	uint8 m_PanLFO1Depth = 0;
	uint8 m_PanLFO2Depth = 0;
	uint8 m_MFXSwitch = 0;
	uint8 m_JV2080MixEFXSendLevel = 127;
	uint8 m_DelaySendLevel = 0;
	uint8 m_ReverbSendLevel = 127;
#pragma endregion

	Array<uint8*> m_synthPatchToneValuePointers; // use synth patch tone address offset (0x00..0x80) as index to get the pointer to the parameter value, at best use SynthToneAddressOffsets
	Array<uint8*> m_rhyNoteTonePointers; // use rhyhtm note tone address offset (0x00..0x39) as index to get the pointer to the parameter value, at best use RhyToneAddressOffsets
	void initPointerArrays();

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(CopyableTone)
};



#endif  // COPYABLETONE_H_INCLUDED
