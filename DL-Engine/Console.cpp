#include "stdafx.h"
#include "Console.h"

Console::Console() {
	
}

Console::~Console() {
	fclose(fp);
	FreeConsole();
}

void Console::OpenConsole() {
	AllocConsole();

	freopen_s(&fp, "CONOUT$", "w", stdout);

	SetConsoleTitle(CONSOLE_NAME);
}