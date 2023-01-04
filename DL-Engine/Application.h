#pragma once
#include "stdafx.h"
#include "Scene.h"

class Application
{
private :
	LARGE_INTEGER beforeInterval, currentInterval, Frequency;
public :
	Application(HINSTANCE hInstance, INT cmdShow);
	~Application();

	static LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
	
	void InitWindow(HINSTANCE hInstance);
	HWND FloatWindow(HINSTANCE hInstance, int cmdShow);
	
	void InitManager();
	void DeleteManager();

	HRESULT InitDirect2D();	
	HRESULT CreateDeviceIndependentResources();
	HRESULT CreateDeviceResources();
	void ReleaseDirect2D();

	void InitDeltaTime();
	float getDeltaTime();

	int DoMainLoop(Scene* firstScene);
};