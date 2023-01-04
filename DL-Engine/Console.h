#pragma once
#include "stdafx.h"

class Console
{
private :
	FILE* fp;
public :
	Console();
	~Console();

	void OpenConsole();
};