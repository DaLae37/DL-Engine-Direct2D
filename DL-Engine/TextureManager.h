#pragma once
#include "stdafx.h"

class TextureManager
{
private :
	std::map<const wchar_t*, ID2D1Bitmap *> textureMap;
public :
	TextureManager();
	~TextureManager();

	ID2D1Bitmap* LoadTextureFromFile(const wchar_t* path);
};