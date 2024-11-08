#include "Stdafx.h"
#include "TimeManager.h"

HRESULT TimeManager::init(void)
{
	_timer = new Timer;
	_timer->init();

	return S_OK;
}

void TimeManager::release(void)
{
	if (_timer != nullptr)
	{
		SAFE_DELETE(_timer);
		_timer = nullptr;
	}
}

void TimeManager::update(float lock)
{
	if (_timer != nullptr)
	{
		_timer->tick(lock);
	}
}

void TimeManager::render(HDC hdc)
{
	char str[256];

	//SetBkMode(): 글자 배경 지워주는 함수
	SetBkMode(hdc, TRANSPARENT);
	SetTextColor(hdc, RGB(255, 255, 255));

	//_DEBUG 디버그 모드 일떄만 동작
	//ㄴ 개발을 하면서 테스트의 용도가 강하다.
	//ㄴ 유저들이 확인을 하면 안되는 정보를 패키지화 시킬때 편하다.

#ifdef _DEBUG
	if (_timer != nullptr)
	{
		//sprintf_s(str, "FramePerSec: %d", _timer->getFrameRate());
		//TextOut(hdc, 0, 0, str, strlen(str));

		//sprintf_s(str, "WorldTime: %f", _timer->getWorldTime());
		//TextOut(hdc, 0, 20, str, strlen(str));
		//
		//sprintf_s(str, "ElapsedTime: %f", _timer->getElapsedTime());
		//TextOut(hdc, 0, 40, str, strlen(str));
	}
#else //릴리즈모드
	if (_timer != nullptr)
	{
		sprintf_s(str, "FramePerSec: %d", _timer->getFrameRate());
		TextOut(hdc, 0, 0, str, strlen(str));
	}
#endif
}
