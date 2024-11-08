#include "Stdafx.h"
#include "MainMenu.h"

HRESULT MainMenu::init(void)
{
	_mainMenu = IMAGEMANAGER->addFrameImage("���θ޴�", "Resources/Images/MainMenu/MainMenu1.bmp",
		WINSIZE_X * 3, WINSIZE_Y , 3, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("����", "Resources/Images/MainMenu/Start.bmp",
		WINSIZE_X, WINSIZE_Y, true, RGB(255, 0, 255));

	SOUNDMANAGER->addSound("���θ޴�����", "Resources/Sounds/���θ޴�.mp3", false, false);

	_button[0] = RectMake(311,448,160,70);
	_button[1] = RectMake(311, 510, 160, 70);

	MainScene = true;


	SOUNDMANAGER->play("���θ޴�����", 0.3f);
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
			SOUNDMANAGER->stop("���θ޴�����");
			SCENEMANAGER->changeScene("����");
		}
	}
	else _mainMenu->setFrameX(0);

	if (!MainScene && KEYMANAGER->isOnceKeyDown(VK_RBUTTON))
	{
		MainScene = true;
	}
	if (!MainScene && KEYMANAGER->isOnceKeyDown(VK_SPACE))
	{
		SCENEMANAGER->changeScene("���ӽ���");
		SOUNDMANAGER->stop("���θ޴�����");
	}
	
}

void MainMenu::render(void)
{
	if (MainScene)IMAGEMANAGER->frameRender("���θ޴�", getMemDC(), 0, 0);
	else IMAGEMANAGER->render("����", getMemDC(), 0, 0);


	//DrawRectMake(getMemDC(),_button[1]);
}
