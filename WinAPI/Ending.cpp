#include "Stdafx.h"
#include "Ending.h"

HRESULT Ending::init(void)
{
    hWndVideo = MCIWndCreate(_hWnd, NULL, MCIWNDF_NOPLAYBAR | WS_VISIBLE | WS_CHILD, "Resources/Bidio/Ending.wmv");
    MoveWindow(hWndVideo, 0, 0, WINSIZE_X, WINSIZE_Y, NULL);
    MCIWndPlay(hWndVideo);

    _openingSkipAnyKey = false;

    return S_OK;
}

void Ending::release(void)
{
}

void Ending::update(void)
{
    if (KEYMANAGER->isOnceKeyDown(VK_SPACE))
    {
        _openingSkipAnyKey = true;
    }

    if (MCIWndGetLength(hWndVideo) <= MCIWndGetPosition(hWndVideo) || _openingSkipAnyKey)
    {
        MCIWndClose(hWndVideo);
        MCIWndDestroy(hWndVideo);
        hWndVideo = 0;
        SCENEMANAGER->Set_IntroEnd(false);
        SCENEMANAGER->changeScene("메인메뉴");
    }
}
