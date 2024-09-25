#pragma once
#include "stdafx.h"

class TextureManager
{
private :
	std::mutex textureLoadMutex;
	std::vector<const wchar_t*> textures;
	std::unordered_map<const wchar_t*, ID2D1Bitmap *> textureMap;
public :
	explicit TextureManager();
	~TextureManager();

	ID2D1Bitmap* LoadTextureFromFile(const wchar_t* path);
};