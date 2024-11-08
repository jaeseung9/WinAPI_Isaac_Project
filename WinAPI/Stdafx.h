#pragma once

//��� ����
// �� 4005: DXGI �� �׷��� �������̽����� ��ũ�� �����Ͽ� ���� ��µǴ� ���
#pragma warning(disable : 4005)

// ���� ������ �ʴ� ������ Windows ������� ����
#define WIN32_LEAN_AND_MEAN
// GDI+�� ����Ϸ��� ������� �����;� �Ѵ�
// �� <ole2.h>

//! Windows ��� ����
#include <windows.h>

//! ������ �ܼ�â
#pragma comment(linker, "/entry:WinMainCRTStartup /subsystem:console")

//! ���̺귯�� ��ũ
#pragma comment (lib, "msimg32.lib") //����ũ�μ���Ʈ(ms) �̹���(img) 32��Ʈ(32) ���̺귯��

//12.21 �߰�
#pragma comment (lib, "winmm.lib")

//����
#include <Vfw.h>
#pragma comment (lib, "Vfw32.lib")


#pragma comment (lib, "JasonCPP/lib_json/json_vc71_libmtd.lib")
//01.17 �߰�
//#pragma comment (lib, "lib/FMOD/fmodex_vc.lib")
#pragma comment (lib, "lib/FMOD/fmodex64_vc.lib")



//01.17 �߰�
//! �ܺ� ��� ����
#include "inc\FMOD\fmod.hpp"


#include "JasonCPP\include\json\json.h"`


#include <SDKDDKVer.h>


// =====================
//! C ��Ÿ�� ��� ����
// =====================
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <tchar.h>
#include <time.h>
//#include <assert.h> �� ������

//12.21 �߰�
#include <MMSystem.h>


// =====================
//! C++ ��Ÿ�� ��� ����
// =====================
#include <iostream>
#include <chrono>
#include <random>
#include <vector>
#include <map>
#include <unordered_map>
#include <string>
//bitset: ��Ʈ ������ �� �� ���� ������ �ִ� �Լ��� �����Ѵ�. (STL)
//�� reset(), set(), flip(), all(), any(), size() ����� ��Ʈ ���꿡 ���� �����ϰ� �ִ�.
#include <bitset>
#include <cassert>
// ���ٿ� ģ����
#include <algorithm>
// �Լ� �����͸� ����ó�� �ְ� ���� �� �ִ�.
//  �� ��������Ʈ�� �����ϴ� �ٽ��� �� �� �ִ� ���
//  �� Bind: Ư�� ���ڿ� ���ؼ��� �Լ��� �����Ű�� ���� �� ����Ѵ�.
//			 Ư�� ���ڿ� Ư�� �Լ��� ���� �� �ִ�.
#include <functional>

//01.19 �߰�
#include <fstream> // ���� ����� ����� ������ִ� �������
#include <queue> // STL �ڷ���

using namespace std;

//using std::vector;
//using std::bitset;



// =====================
//! ����� ���� �������
// =====================
#include "CommonMacroFunction.h"  
#include "RandomFunction.h"
#include "KeyManager.h"
#include "ImageManager.h"
#include "FontManager.h"
#include "TempSoundManager.h"
#include "Utils.h"

//ī�޶� ����ũ
#include "CameraShake.h"

//12.21 �߰�
#include "TimeManager.h"

//12.28 �߰�
#include "SceneManager.h"

//01.17 �߰�
#include "SoundManager.h"

#include "CameraManager.h"
#include "JasonSaveLoader.h"
using namespace MY_UTIL;

// =====================
//! �̱���
// =====================
#define RND RandomFunction::getSingleton()
#define KEYMANAGER KeyManager::getSingleton()
#define IMAGEMANAGER ImageManager::getSingleton()
#define FONTMANAGER FontManager::getSingleton()
#define TEMPSOUNDMANAGER TempSoundManager::getSingleton()

//12.21 �߰�
#define TIMEMANAGER TimeManager::getSingleton()

//12.28 �߰�
#define SCENEMANAGER SceneManager::getSingleton()

//01.17 �߰�
#define SOUNDMANAGER SoundManager::getSingleton()

//ī�޶� �Ŵ���
#define CAMERAMANAGER CameraManager::getSingleton()

#define JSONDATAMANAGER JasonSaveLoader::getSingleton()

#define CAMERASHAKE CameraShake::getSingleton()
/*
! D2D/D3D ��� ����
#include <D2D1.h>
#include <d2d1helper.h>
#include <d3dx9.h>
#include <D3DX11.h>
#include <d3d11shader.h>
#include <dinput.h>

#pragma comment(lib, "d2d1.lib")
#pragma comment(lib, "d3d9.lib")
#pragma comment(lib, "d3dx9.lib")
#pragma comment(lib, "d3d11.lib")
#pragma comment(lib, "d3dx11.lib")
#pragma comment(lib, "dinput8.lib")
#pragma comment(lib, "dxguid.lib")

ID2D1Factory* _ID2DFactory = nullptr;
ID2D1HwndRenderTarget* _ID2DRenderTarget = nullptr;
*/


//==============================
// # ��ũ�� # (������â �ʱ�ȭ)
//==============================

//! ��ü ȭ��
//#define FULL_SCREEN

#ifdef FULL_SCREEN

#define WIN_NAME (LPSTR)(TEXT("WindowsAPI"))
#define WINSTART_X 0
#define WINSTART_Y 0
//GetSystemMetrics(): ���ڷ� ���޵Ǵ� �ý��� ���� ������ ��ȯ�Ѵ�.
	//�� SM_CXSCREEN: ���� ȭ�� ���� �ػ� x�� ��ȯ
	//�� SM_CYSCREEN: ���� ȭ�� ���� �ػ� y�� ��ȯ
#define WINSIZE_X GetSystemMetrics(SM_CXSCREEN)
#define WINSIZE_Y GetSystemMetrics(SM_CYSCREEN)
//WS_POPUPWINDOW: �˾� ������ ����
// WS_MAXIMIZE: ������ ������ �ִ�ȭ
#define WINSTYLE WS_POPUPWINDOW | WS_MAXIMIZE

#else

#define WIN_NAME (LPSTR)(TEXT("WindowsAPI"))
#define WINSTART_X 400
#define WINSTART_Y 100
#define WINSIZE_X 796
#define WINSIZE_Y 592
//==�� �κ� �ٲٸ� mp3 ���·� ���� �� ����==
#define WINSTYLE WS_CAPTION | WS_SYSMENU
//========================================
#endif

//==============================
// # ��ũ�� �Լ� #
//==============================
#define SAFE_DELETE(p)       {if(p){delete(p); (p) = nullptr;}}   //�����ϰ� �ʱ�ȭ
#define SAFE_DELETE_ARRAY(p) {if(p){delete[] (p); (p)=nullptr;}}  //���� ��ü�� ���
#define SAFE_RELEASE(p)      {if(p) {(p)->release();(p)=nullptr;}

//==============================
// # ���� ���� #
//==============================
// extern Ű����� �ٸ� ��� or cpp���� ������ �����ϱ� ���� ����Ѵ�.
// �� ���� ������ Ű���带 �����ص� �⺻���� externȭ �Ǵ� ��찡 �ִ�.(VS������ ���� �ٸ�)
extern HINSTANCE _hInstance;
extern HWND _hWnd;
//X��ǥ�� Y��ǥ�� ����� ��ǥ�� ������ �� ��� -2D���� ��ǥ ǥ�� ����
extern POINT _ptMouse;

