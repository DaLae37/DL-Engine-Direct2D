#include "stdafx.h"
#include "Console.h"
#include "Application.h"
#include "MainScene.h"

INT WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR, INT cmdShow) {
	srand(GetTickCount64());

	std::unique_ptr<Console> console = std::make_unique<Console>();
	if (CONSOLE_ON) {
		console->OpenConsole();
	}
	
	std::unique_ptr<Application> app = std::make_unique<Application>(hInstance, cmdShow);

	INT msg = app->DoMainLoop(new MainScene());
	
	return msg;
}