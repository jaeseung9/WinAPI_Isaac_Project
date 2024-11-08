#include "Stdafx.h"
#include "GameNode.h"

HRESULT GameNode::init(void)
{
	return S_OK;
}

HRESULT GameNode::init(bool managerInit)
{
    _hdc = GetDC(_hWnd);
    _managerInit = managerInit;

    if (managerInit)
    {
        //로케일 설정
        //ㄴ 어떤 언어를 기반으로 인코딩 / 문자, 열 출력을 결정할 것인지에 대해 설정해주는 함수
        //LC_ALL: 프로그램 전반에 대해서 적용하겠다.
        setlocale(LC_ALL, "Korean");

        SetTimer(_hWnd, 1, 10, NULL);

        RND->init();
        KEYMANAGER->init();
        IMAGEMANAGER->init();
        TEMPSOUNDMANAGER->init();
        TIMEMANAGER->init();
        SCENEMANAGER->init();
        SOUNDMANAGER->init();
        CAMERAMANAGER->init();
        JSONDATAMANAGER->init();
        CAMERASHAKE->init();
    }

    return S_OK;
}

void GameNode::release(void)
{
    if (_managerInit)
    {
        KillTimer(_hWnd, 1);

        RND->releaseSingleton();
        KEYMANAGER->releaseSingleton();
        IMAGEMANAGER->release();
        IMAGEMANAGER->releaseSingleton();
        FONTMANAGER->releaseSingleton();
        TEMPSOUNDMANAGER->releaseSingleton();
        TIMEMANAGER->release();
        TIMEMANAGER->releaseSingleton();
        SCENEMANAGER->release();
        SCENEMANAGER->releaseSingleton();
        SOUNDMANAGER->release();
        SOUNDMANAGER->releaseSingleton();
        JSONDATAMANAGER->release();
        JSONDATAMANAGER->releaseSingleton();
        CAMERASHAKE->release();
        CAMERASHAKE->releaseSingleton();
    }

    ReleaseDC(_hWnd, _hdc);

}

void GameNode::update(void)
{
	// 버퍼링 처리와 타이머가 없기 때문에 기본 함수 사용
	// 새로고침
	//InvalidateRect(_hWnd, NULL, false);
}

void GameNode::render(void)
{
}

LRESULT GameNode::MainProc(HWND hWnd, UINT IMessage, WPARAM wParam, LPARAM lParam)
{
    HDC hdc;
    PAINTSTRUCT ps;

    switch (IMessage)
    {
    case WM_TIMER:
        this->update();
        break;

    case WM_PAINT:             
        hdc = BeginPaint(hWnd, &ps);
        this->render();
        EndPaint(hWnd, &ps);
        break;

    case WM_MOUSEMOVE:
        _ptMouse.x = LOWORD(lParam);
        _ptMouse.y = HIWORD(lParam);
        break;

    case WM_LBUTTONDOWN:
   
        break;

    case WM_RBUTTONDOWN:
        break;

    case WM_KEYDOWN:
        switch (wParam)
        {
        case VK_LEFT:
            break;

        case VK_RIGHT:
            break;

        case VK_ESCAPE:
            PostMessage(hWnd, WM_DESTROY, 0, 0);
            break;
        }
        break;

    case WM_DESTROY: 
        PostQuitMessage(0);
        return 0;
    }

    return (DefWindowProc(hWnd, IMessage, wParam, lParam));
}
