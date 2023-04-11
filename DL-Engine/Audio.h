#pragma once
#include "stdafx.h"

class Audio
{
private :
	WAVEFORMATEXTENSIBLE wfx = { 0 };
	XAUDIO2_BUFFER buffer = { 0 };
public :
	Audio(const wchar_t* path);
	~Audio();

	HRESULT FindChunk(HANDLE hFile, DWORD fourcc, DWORD& dwChunkSize, DWORD& dwChunkDataPosition);
	HRESULT ReadChunkData(HANDLE hFile, void* buffer, DWORD buffersize, DWORD bufferoffset);

	WAVEFORMATEXTENSIBLE* getWFX();
	XAUDIO2_BUFFER* getBuffer();

	void LoadAudioFromFile(const wchar_t* path);
};