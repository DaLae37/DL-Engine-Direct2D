#include "stdafx.h"
#include "InputManager.h"

InputManager::InputManager() {
	for (int i = 0; i < 256; i++) {
		beforeKey[i] = false;
		currentKey[i] = false;
	}
}

InputManager::~InputManager() {

}

void InputManager::UpdateKeyState() {
	for (int i = 0; i < 256; i++) {
		beforeKey[i] = currentKey[i];
		currentKey[i] = GetAsyncKeyState(i)
			& 0x8000;
	}
}

int InputManager::GetKeyState(int vk) {
	if (beforeKey[vk] && currentKey[vk]) {
		return KEY_ON;
	}
	else if (!beforeKey[vk] && currentKey[vk]) {
		return KEY_DOWN;
	}
	else if (beforeKey[vk] && !currentKey[vk]) {
		return KEY_UP;
	}
	else {
		return KEY_NONE;
	}
}

D2D_POINT_2F InputManager::GetMousePos() {
	POINT p;
	GetCursorPos(&p);
	ScreenToClient(hWnd, &p);

	return D2D_POINT_2F{ (float)p.x, (float)p.y };
}