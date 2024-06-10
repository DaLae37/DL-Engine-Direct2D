#pragma once
#include "stdafx.h"

class FontManager
{
private :
	std::map<const wchar_t*, IDWriteFont> fontMap;
};