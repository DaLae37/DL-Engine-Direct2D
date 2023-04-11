#pragma once
#include "Audio.h"

class SoundManager
{
private :
	IXAudio2* xAudio2;
	IXAudio2MasteringVoice* masterVoice;

	float volume;
public :
	SoundManager();
	~SoundManager();

	void CreateDevice();
	void LoadAudioFromFile(const wchar_t* path);
	void SetVolume();
};