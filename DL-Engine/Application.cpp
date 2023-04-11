#include "stdafx.h"
#include "Application.h"

ID2D1Factory* factory;
ID2D1HwndRenderTarget* renderTarget;
IWICImagingFactory* wicFactory;
HWND hWnd;

SceneManager* sceneManager;
TextureManager* textureManager;
InputManager* inputManager;
SoundManager* soundManager;

Application::Application(HINSTANCE hInstance, INT cmdShow) {
	InitWindow(hInstance);
	FloatWindow(hInstance, cmdShow);

	InitDirect2D();
	InitDeltaTime();
	InitManager();

	QueryPerformanceCounter(&beforeInterval);
	QueryPerformanceCounter(&currentInterval);
	QueryPerformanceFrequency(&Frequency);
}

Application::~Application() {
	
}

HRESULT Application::InitDirect2D() {
	if (FAILED(CreateDeviceIndependentResources())) {
		return E_FAIL;
	}
	if (FAILED(CreateDeviceResources())) {
		return E_FAIL;
	}

	return S_OK;
}

HRESULT Application::CreateDeviceIndependentResources() {
	HRESULT hr = S_OK;
	const D2D1_FACTORY_OPTIONS opts = { D2D1_DEBUG_LEVEL_INFORMATION };

	hr = CoCreateInstance(CLSID_WICImagingFactory, nullptr, CLSCTX_INPROC_SERVER, IID_PPV_ARGS(&wicFactory));
	
	if (SUCCEEDED(hr)) {
		hr = D2D1CreateFactory(D2D1_FACTORY_TYPE_SINGLE_THREADED, &factory);
	}
	
	return hr;
}

HRESULT Application::CreateDeviceResources() {
	HRESULT hr = S_OK;

	if (renderTarget == nullptr) {
		RECT rect;
		GetClientRect(hWnd, &rect);

		D2D1_SIZE_U size;

		if (!IS_FULL_SCREEN) {
			size = D2D1::SizeU(rect.right - rect.left, rect.bottom - rect.top);
		}
		else {
			size = D2D1::SizeU(SCREEN_WIDTH, SCREEN_HEIGHT);
		}

		hr = factory->CreateHwndRenderTarget(D2D1::RenderTargetProperties(), D2D1::HwndRenderTargetProperties(hWnd, size, D2D1_PRESENT_OPTIONS_IMMEDIATELY), &renderTarget);
		
		return hr;
	}
}

void Application::InitWindow(HINSTANCE hInstance) {
	WNDCLASS wndClass;

	wndClass.cbClsExtra = 0;
	wndClass.cbWndExtra = 0;
	wndClass.hbrBackground = (HBRUSH)GetStockObject(
		WHITE_BRUSH
		);
	wndClass.hCursor = LoadCursor(nullptr, IDC_ARROW);
	wndClass.hIcon = LoadIcon(nullptr, IDI_APPLICATION);
	wndClass.hInstance = hInstance;
	wndClass.lpfnWndProc = WndProc;
	wndClass.lpszClassName = PROGRAM_NAME;
	wndClass.lpszMenuName = nullptr;
	wndClass.style = CS_HREDRAW | CS_VREDRAW;
	RegisterClass(&wndClass);
}

void Application::InitManager() {
	sceneManager = new SceneManager();
	textureManager = new TextureManager();
	inputManager = new InputManager();
	soundManager = new SoundManager();
}

void Application::InitDeltaTime() {
	QueryPerformanceCounter(&beforeInterval);
	QueryPerformanceFrequency(&Frequency);
}

LRESULT CALLBACK Application::WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam) {
	switch (iMessage) {
	case WM_DESTROY :
		PostQuitMessage(0);
		return 0;
	}

	return DefWindowProc(hWnd, iMessage, wParam, lParam);
}

HWND Application::FloatWindow(HINSTANCE hInstance, int cmdShow) {
	hWnd = CreateWindow(PROGRAM_NAME, PROGRAM_NAME,
		WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT,
		SCREEN_WIDTH, SCREEN_HEIGHT,
		nullptr, (HMENU)nullptr, hInstance, nullptr);
	ShowWindow(hWnd, cmdShow);
	return hWnd;
}

int Application::DoMainLoop(Scene* firstScene) {

	sceneManager->ChangeScene(firstScene);

	MSG Message = { 0, };

	while (Message.message != WM_QUIT) {
		if (PeekMessage(&Message, nullptr, 0, 0, PM_REMOVE)) {
			TranslateMessage(&Message);
			DispatchMessage(&Message);
		}

		if (inputManager->GetKeyState('A') == KEY_DOWN) {
			DWORD dwStyle = GetWindowLong(hWnd, GWL_STYLE);
			WINDOWPLACEMENT m_wpPrev;
			if (dwStyle & WS_OVERLAPPEDWINDOW)
			{

				m_wpPrev.length = sizeof(WINDOWPLACEMENT);
				MONITORINFO mi = { sizeof(MONITORINFO) };
				if (GetWindowPlacement(hWnd, &m_wpPrev) &&
					GetMonitorInfo(MonitorFromWindow(hWnd, MONITOR_DEFAULTTOPRIMARY), &mi))
				{
					SetWindowLong(hWnd, GWL_STYLE,
						dwStyle & ~WS_OVERLAPPEDWINDOW);
					SetWindowPos(hWnd, HWND_TOP,
						mi.rcMonitor.left, mi.rcMonitor.top,
						mi.rcMonitor.right - mi.rcMonitor.left,
						mi.rcMonitor.bottom - mi.rcMonitor.top,
						SWP_NOOWNERZORDER | SWP_FRAMECHANGED);
				}
			}
			else
			{
				SetWindowLong(hWnd, GWL_STYLE, dwStyle | WS_OVERLAPPEDWINDOW);
				SetWindowPlacement(hWnd, &m_wpPrev);
				SetWindowPos(hWnd, NULL, 0, 0, 0, 0,
					SWP_NOMOVE | SWP_NOSIZE | SWP_NOZORDER |
					SWP_NOOWNERZORDER | SWP_FRAMECHANGED);
			}
		}

		D2D_MATRIX_3X2_F identity = { 1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f };
		D2D_COLOR_F backgroundColor = { 1.0f, 1.0f, 1.0f, 1.0f };
		renderTarget->BeginDraw();
		renderTarget->SetTransform(&identity);
		renderTarget->Clear(&backgroundColor);

		sceneManager->Render();

		renderTarget->EndDraw(nullptr, nullptr);

		inputManager->UpdateKeyState();
		sceneManager->Update(getDeltaTime());
	}
	
	DeleteManager();
	ReleaseDirect2D();

	return (int)Message.wParam;
}

void Application::DeleteManager() {
	SAFE_DELETE(sceneManager);
	SAFE_DELETE(textureManager);
	SAFE_DELETE(inputManager);
	SAFE_DELETE(soundManager);
}

void Application::ReleaseDirect2D() {
	wicFactory = NULL;
	factory = NULL;
	renderTarget = NULL;
}

float Application::getDeltaTime() {
	QueryPerformanceCounter(&currentInterval);

	LONGLONG interval = (currentInterval.QuadPart - beforeInterval.QuadPart);
	float dTime = (float)interval / (float)Frequency.QuadPart;
	beforeInterval = currentInterval;

	return dTime;
}