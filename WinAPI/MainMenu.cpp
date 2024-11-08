#include "Stdafx.h"
#include "MainMenu.h"

HRESULT MainMenu::init(void)
{
	_mainMenu = IMAGEMANAGER->addFrameImage("메인메뉴", "Resources/Images/MainMenu/MainMenu1.bmp",
		WINSIZE_X * 3, WINSIZE_Y , 3, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("시작", "Resources/Images/MainMenu/Start.bmp",
		WINSIZE_X, WINSIZE_Y, true, RGB(255, 0, 255));

	SOUNDMANAGER->addSound("메인메뉴사운드", "Resources/Sounds/메인메뉴.mp3", false, false);

	_button[0] = RectMake(311,448,160,70);
	_button[1] = RectMake(311, 510, 160, 70);

	MainScene = true;


	SOUNDMANAGER->play("메인메뉴사운드", 0.3f);
	return S_OK;
}

void MainMenu::release(void)
{
}

void MainMenu::update(void)
{
//	cout << _mainMenu->getFrameX() << endl;
	if (PtInRect(&_button[0], _ptMouse) )
	{
		_mainMenu->setFrameX(1);
		if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON) )
		{
			MainScene = false;

		}
	}
	else if (PtInRect(&_button[1], _ptMouse))
	{
		_mainMenu->setFrameX(2);
		if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
		{
			SOUNDMANAGER->stop("메인메뉴사운드");
			SCENEMANAGER->changeScene("맵툴");
		}
	}
	else _mainMenu->setFrameX(0);

	if (!MainScene && KEYMANAGER->isOnceKeyDown(VK_RBUTTON))
	{
		MainScene = true;
	}
	if (!MainScene && KEYMANAGER->isOnceKeyDown(VK_SPACE))
	{
		SCENEMANAGER->changeScene("게임시작");
		SOUNDMANAGER->stop("메인메뉴사운드");
	}
	
}

void MainMenu::render(void)
{
	if (MainScene)IMAGEMANAGER->frameRender("메인메뉴", getMemDC(), 0, 0);
	else IMAGEMANAGER->render("시작", getMemDC(), 0, 0);


	//DrawRectMake(getMemDC(),_button[1]);
}
