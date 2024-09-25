#pragma once
//프로젝트 세팅
#define LANGUAGE "kor" // std::locale parameter

//프로그램 세팅
#define CONSOLE_ON true
#define SCREEN_WIDTH 1024
#define SCREEN_HEIGHT 768
#define PROGRAM_NAME TEXT("Engine")
#define CONSOLE_NAME TEXT("Console")
#define IS_FULL_SCREEN true

//라이브러리
#pragma comment (lib,"WindowsCodecs.lib")
#pragma comment (lib,"winmm.lib")
#pragma comment (lib,"d2d1.lib")
#pragma comment (lib,"dwrite.lib")

//윈도우 헤더
#include <Windows.h>
#include <wincodec.h>
#include <xaudio2.h>

//다이렉트X 헤더
#include <d2d1.h>
#include <d2d1helper.h>
#include <dwrite.h>

//디버그 헤더
#include <iostream>
#include <io.h>
#include <fcntl.h>

//메모리
#include <memory>

//스레드
#include <thread>
#include <mutex>
#define THREAD_NUM 2

//STL
#include <map>
#include <unordered_map>
#include <vector>
#include <list>
#include <set>
#include <algorithm>

//게임 매니저 헤더
#include "TextureManager.h"
#include "SceneManager.h"
#include "InputManager.h"
#include "SoundManager.h"

//상수 및 매크로 함수
#define KEY_NONE 0
#define KEY_UP 1
#define KEY_DOWN 2
#define KEY_ON 3

#define SAFE_RELEASE(p) {if(p) {p->Release(); (p) = nullptr;}}
#define SAFE_DELETE(p) {if(p) {delete (p); (p) = nullptr;}}
#define SAFE_DELETE_ARRAY(p) {if(p){delete [](p); (p) = nullptr;}}

//전역 변수
extern ID2D1Factory* factory;
extern ID2D1HwndRenderTarget* renderTarget;
extern IWICImagingFactory* wicFactory;
extern HWND hWnd;
extern SceneManager* sceneManager;
extern TextureManager* textureManager;
extern InputManager* inputManager;
extern SoundManager* soundManager;

//색상
namespace Color {
	const D2D_COLOR_F red = { 1.0f, 0.0f, 0.0f, 1.0f };
	const D2D_COLOR_F green = { 0.0f, 1.0f, 0.0f, 1.0f };
	const D2D_COLOR_F blue = { 0.0f, 0.0f, 1.0f, 1.0f };
	const D2D_COLOR_F black = { 0.0f, 0.0f, 0.0f, 1.0f };
}