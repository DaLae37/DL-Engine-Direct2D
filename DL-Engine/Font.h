#pragma once
#include "Object.h"
class Font : public Object
{
public :
	Font(const wchar_t* text, const wchar_t* fontPath);
	~Font();
};