#pragma once

//경고 무시
// ㄴ 4005: DXGI 등 그래픽 인터페이스에서 매크로 관련하여 많이 출력되는 경고
#pragma warning(disable : 4005)

// 거의 사용되지 않는 내용을 Windows 헤더에서 제외
#define WIN32_LEAN_AND_MEAN
// GDI+를 사용하려면 헤더파일 꺼내와야 한다
// ㄴ <ole2.h>

//! Windows 헤더 파일
#include <windows.h>

//! 디버깅용 콘솔창
#pragma comment(linker, "/entry:WinMainCRTStartup /subsystem:console")

//! 라이브러리 링크
#pragma comment (lib, "msimg32.lib") //마이크로소프트(ms) 이미지(img) 32비트(32) 라이브러리

//12.21 추가
#pragma comment (lib, "winmm.lib")

//영상
#include <Vfw.h>
#pragma comment (lib, "Vfw32.lib")


#pragma comment (lib, "JasonCPP/lib_json/json_vc71_libmtd.lib")
//01.17 추가
//#pragma comment (lib, "lib/FMOD/fmodex_vc.lib")
#pragma comment (lib, "lib/FMOD/fmodex64_vc.lib")



//01.17 추가
//! 외부 헤더 파일
#include "inc\FMOD\fmod.hpp"


#include "JasonCPP\include\json\json.h"`


#include <SDKDDKVer.h>


// =====================
//! C 런타임 헤더 파일
// =====================
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <tchar.h>
#include <time.h>
//#include <assert.h> 더 가벼움

//12.21 추가
#include <MMSystem.h>


// =====================
//! C++ 런타임 헤더 파일
// =====================
#include <iostream>
#include <chrono>
#include <random>
#include <vector>
#include <map>
#include <unordered_map>
#include <string>
//bitset: 비트 연산을 좀 더 쉽게 관리해 주는 함수를 지원한다. (STL)
//ㄴ reset(), set(), flip(), all(), any(), size() 등등을 비트 연산에 한해 지원하고 있다.
#include <bitset>
#include <cassert>
// 람다와 친구들
#include <algorithm>
// 함수 포인터를 변수처럼 주고 받을 수 있다.
//  ㄴ 델리게이트를 구축하는 핵심이 될 수 있는 헤더
//  ㄴ Bind: 특정 인자에 대해서만 함수를 실행시키고 싶을 때 사용한다.
//			 특정 인자와 특정 함수를 묶을 수 있다.
#include <functional>

//01.19 추가
#include <fstream> // 파일 입출력 기능이 모아져있는 헤더파일
#include <queue> // STL 자료형

using namespace std;

//using std::vector;
//using std::bitset;



// =====================
//! 사용자 정의 헤더파일
// =====================
#include "CommonMacroFunction.h"  
#include "RandomFunction.h"
#include "KeyManager.h"
#include "ImageManager.h"
#include "FontManager.h"
#include "TempSoundManager.h"
#include "Utils.h"

//카메라 쉐이크
#include "CameraShake.h"

//12.21 추가
#include "TimeManager.h"

//12.28 추가
#include "SceneManager.h"

//01.17 추가
#include "SoundManager.h"

#include "CameraManager.h"
#include "JasonSaveLoader.h"
using namespace MY_UTIL;

// =====================
//! 싱글톤
// =====================
#define RND RandomFunction::getSingleton()
#define KEYMANAGER KeyManager::getSingleton()
#define IMAGEMANAGER ImageManager::getSingleton()
#define FONTMANAGER FontManager::getSingleton()
#define TEMPSOUNDMANAGER TempSoundManager::getSingleton()

//12.21 추가
#define TIMEMANAGER TimeManager::getSingleton()

//12.28 추가
#define SCENEMANAGER SceneManager::getSingleton()

//01.17 추가
#define SOUNDMANAGER SoundManager::getSingleton()

//카메라 매니저
#define CAMERAMANAGER CameraManager::getSingleton()

#define JSONDATAMANAGER JasonSaveLoader::getSingleton()

#define CAMERASHAKE CameraShake::getSingleton()
/*
! D2D/D3D 헤더 파일
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
// # 매크로 # (윈도우창 초기화)
//==============================

//! 전체 화면
//#define FULL_SCREEN

#ifdef FULL_SCREEN

#define WIN_NAME (LPSTR)(TEXT("WindowsAPI"))
#define WINSTART_X 0
#define WINSTART_Y 0
//GetSystemMetrics(): 인자로 전달되는 시스템 설정 정보를 반환한다.
	//ㄴ SM_CXSCREEN: 현재 화면 기준 해상도 x축 반환
	//ㄴ SM_CYSCREEN: 현재 화면 기준 해상도 y축 반환
#define WINSIZE_X GetSystemMetrics(SM_CXSCREEN)
#define WINSIZE_Y GetSystemMetrics(SM_CYSCREEN)
//WS_POPUPWINDOW: 팝업 윈도우 생성
// WS_MAXIMIZE: 윈도우 사이즈 최대화
#define WINSTYLE WS_POPUPWINDOW | WS_MAXIMIZE

#else

#define WIN_NAME (LPSTR)(TEXT("WindowsAPI"))
#define WINSTART_X 400
#define WINSTART_Y 100
#define WINSIZE_X 796
#define WINSIZE_Y 592
//==이 부분 바꾸면 mp3 형태로 만들 수 있음==
#define WINSTYLE WS_CAPTION | WS_SYSMENU
//========================================
#endif

//==============================
// # 매크로 함수 #
//==============================
#define SAFE_DELETE(p)       {if(p){delete(p); (p) = nullptr;}}   //안전하게 초기화
#define SAFE_DELETE_ARRAY(p) {if(p){delete[] (p); (p)=nullptr;}}  //복수 객체일 경우
#define SAFE_RELEASE(p)      {if(p) {(p)->release();(p)=nullptr;}

//==============================
// # 전역 변수 #
//==============================
// extern 키워드는 다른 헤더 or cpp에서 변수를 공유하기 위해 사용한다.
// ㄴ 전역 변수는 키워드를 생략해도 기본으로 extern화 되는 경우가 있다.(VS버전에 따라 다름)
extern HINSTANCE _hInstance;
extern HWND _hWnd;
//X좌표와 Y좌표를 평면의 좌표에 정의할 때 사용 -2D에서 좌표 표현 적합
extern POINT _ptMouse;

