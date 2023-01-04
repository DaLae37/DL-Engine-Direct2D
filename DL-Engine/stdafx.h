#pragma once

//���α׷� ����
#define CONSOLE_ON true
#define SCREEN_WIDTH 1024
#define SCREEN_HEIGHT 768
#define PROGRAM_NAME TEXT("Engine")
#define CONSOLE_NAME TEXT("Console")
#define IS_FULL_SCREEN false

//���̺귯��
#pragma comment (lib,"WindowsCodecs.lib")
#pragma comment (lib,"d2d1.lib")
#pragma comment (lib,"dwrite.lib")

//������ ���
#include <Windows.h>
#include <wincodec.h>

//���̷�ƮX ���
#include <d2d1.h>
#include <d2d1helper.h>
#include <dwrite.h>

//����� ���
#include <iostream>
#include <io.h>
#include <fcntl.h>

//STL
#include <map>
#include <vector>
#include <list>

//���� �Ŵ��� ���
#include "TextureManager.h"
#include "SceneManager.h"
#include "InputManager.h"

//��� �� ��ũ�� �Լ�
#define KEY_NONE 0
#define KEY_UP 1
#define KEY_DOWN 2
#define KEY_ON 3

#define SAFE_RELEASE(p) {if(p) {p->Release(); (p) = nullptr;}}
#define SAFE_DELETE(p) {if(p) {delete (p); (p) = nullptr;}}
#define SAFE_DELETE_ARRAY(p) {if(p){delete [](p); (p) = nullptr;}}

//���� ����
extern ID2D1Factory* factory;
extern ID2D1HwndRenderTarget* renderTarget;
extern IWICImagingFactory* wicFactory;
extern HWND hWnd;
extern SceneManager* sceneManager;
extern TextureManager* textureManager;
extern InputManager* inputManager;