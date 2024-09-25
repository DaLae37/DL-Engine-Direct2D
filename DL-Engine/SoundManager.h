#pragma once
#include "Audio.h"

class SoundManager
{
private :
	IXAudio2* xAudio2;
	IXAudio2MasteringVoice* masterVoice;

	float volume;
public :
	explicit SoundManager();
	~SoundManager();

	void CreateDevice();
	void LoadAudioFromFile(const wchar_t* path);
	void SetVolume();
};