#include "stdafx.h"
#include "Console.h"
#include "Application.h"
#include "MainScene.h"

INT WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR, INT cmdShow) {
	srand(GetTickCount64());

	Console console;
	if (CONSOLE_ON) {
		console.OpenConsole();
	}
	
	Application app(hInstance, cmdShow);

	int msg = app.DoMainLoop(new MainScene());
	
	return msg;
}