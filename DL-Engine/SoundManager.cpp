#include "stdafx.h"
#include "SoundManager.h"

SoundManager::SoundManager() {
	xAudio2 = nullptr;
	masterVoice = nullptr;

	volume = 1.0f;

	CreateDevice();
}

SoundManager::~SoundManager() {

}

void SoundManager::CreateDevice() {
	XAudio2Create(&xAudio2, 0, XAUDIO2_DEFAULT_PROCESSOR);
	xAudio2->CreateMasteringVoice(&masterVoice);
}

void SoundManager::LoadAudioFromFile(const wchar_t* path) {
	Audio *audio = new Audio(path);
	IXAudio2SourceVoice* sourceVoice;
	HRESULT hr = xAudio2->CreateSourceVoice(&sourceVoice, (WAVEFORMATEX*)audio->getWFX());
	if (hr == S_OK) {
		sourceVoice->SubmitSourceBuffer(audio->getBuffer());
		sourceVoice->Start(0);
	}
}

void SoundManager::SetVolume() {
	
}