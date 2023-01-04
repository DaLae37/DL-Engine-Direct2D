#pragma once
#include "stdafx.h"

class InputManager
{
private :
	bool beforeKey[256], currentKey[256];
public :
	InputManager();
	~InputManager();

	void UpdateKeyState();
	int GetKeyState(int vk);
	D2D_POINT_2F GetMousePos();
};