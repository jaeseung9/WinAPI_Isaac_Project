#include "Stdafx.h"
#include "Ui.h"

HRESULT Ui::init(void)
{
	IMAGEMANAGER->addImage("정보", "Resources/Images/Ui/Ui.bmp", 794, 96, true, RGB(255, 0, 255));
	AddFontResource("Resources/font/inconsolata-bold.ttf");

	IMAGEMANAGER->addImage("체력", "Resources/Images/Ui/hp.bmp", 31, 25, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("체력1", "Resources/Images/Ui/hp1.bmp", 31, 25, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("체력2", "Resources/Images/Ui/hp2.bmp", 31, 25, true, RGB(255, 0, 255));
    IMAGEMANAGER->addImage("정보창", "Resources/Images/Ui/Information.bmp", 461, 331, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("검은색", "Resources/Images/Ui/Black.bmp", WINSIZE_X, WINSIZE_Y, true, RGB(255, 0, 255));

	IMAGEMANAGER->addImage("나가기", "Resources/Images/Ui/Exit.bmp", 235, 51, true, RGB(255, 0, 255));

	_stats[0] = IMAGEMANAGER->addFrameImage("이동속도", "Resources/Images/Ui/MovingSpeed.bmp", 406, 25,7,1, true, RGB(255, 0, 255));
	_stats[1] = IMAGEMANAGER->addFrameImage("공속", "Resources/Images/Ui/AttackSpeed.bmp",434, 22,7,1, true, RGB(255, 0, 255));
	_stats[2] = IMAGEMANAGER->addFrameImage("공격력", "Resources/Images/Ui/Power.bmp", 434, 27,7,1, true, RGB(255, 0, 255));
	_stats[3] = IMAGEMANAGER->addFrameImage("사거리", "Resources/Images/Ui/Intersection.bmp", 455, 27,7,1, true, RGB(255, 0, 255));
	_stats[4] = IMAGEMANAGER->addFrameImage("메인메뉴돌아가기", "Resources/Images/Ui/GetOut.bmp", 1203, 195, 3, 1, true, RGB(255, 0, 255));

	_stats[5] = IMAGEMANAGER->addFrameImage("사망메세지", "Resources/Images/Ui/DieWindow.bmp", 1671 , 540 ,3,1, true, RGB(255, 0, 255));

	_stats[6] = IMAGEMANAGER->addFrameImage("스킬게이지", "Resources/Images/Ui/SkileGage.bmp", 112, 78, 7, 1, true, RGB(255, 0, 255));


	_out = false;
	_die = false;
	_Information = false;
	return S_OK;
}

void Ui::release(void)
{
}

void Ui::update(void)
{
	if (KEYMANAGER->isOnceKeyDown('Q') && !_out)
	{
		if (!_Information) _Information = true;
		else _Information = false;
	}

    _stats[0]->setFrameX(_playerInformation.speed);
    _stats[1]->setFrameX(_playerInformation.attackSpeed);
    _stats[2]->setFrameX(_playerInformation.atk);
    _stats[3]->setFrameX(_playerInformation.intersection);


	if (_playerInformation.hp <= 0)
	{
		_die = true;
	}
	if (_die)
	{
		RECT rc, rc1;

		rc = RectMake(550, 380, 110, 50);
		rc1 = RectMake(567, 437, 120, 50);

		if (PtInRect(&rc, _ptMouse))
		{
			_stats[5]->setFrameX(1);
			if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
			{
				SCENEMANAGER->changeScene("맵툴");
				SCENEMANAGER->changeScene("메인메뉴");
				SCENEMANAGER->changeScene("게임시작");                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    
			}
		}
		else if (PtInRect(&rc1, _ptMouse))
		{
			_stats[5]->setFrameX(2);

			if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
			{
				SCENEMANAGER->changeScene("메인메뉴");
			}
		}
		else _stats[5]->setFrameX(0);
	}

	_stats[6]->setFrameX(_playerInformation.skileGage);
}

void Ui::render(void)
{
	IMAGEMANAGER->render("정보", getMemDC());

	string strMoney = to_string(_playerInformation.money);
	string strBomb = to_string(_playerInformation.bomb);
	string strKey = to_string(_playerInformation.key);

	if (_playerInformation.money < 10)strMoney.insert(0, "0");
	if (_playerInformation.bomb < 10)strBomb.insert(0, "0");
	if (_playerInformation.key < 10)strKey.insert(0, "0");

	FONTMANAGER->drawText(getMemDC(), 350, 12, "inconsolata", 20, FW_EXTRABOLD, strMoney, strMoney.size(), RGB(255, 255, 255));
	FONTMANAGER->drawText(getMemDC(), 350, 38, "inconsolata", 20, FW_EXTRABOLD, strBomb, strBomb.size(), RGB(255, 255, 255));
	FONTMANAGER->drawText(getMemDC(), 350, 64, "inconsolata", 20, FW_EXTRABOLD, strKey, strKey.size(), RGB(255, 255, 255));



	if (_caricature[1])
	{
		if (_playerInformation.hp >= 4)
		{
			_playerInformation.hp = 4;
		}
		if (_playerInformation.hp == 4)
		{
			IMAGEMANAGER->render("체력", getMemDC(), 569, 29);
			IMAGEMANAGER->render("체력", getMemDC(), 604, 29);
			IMAGEMANAGER->render("체력", getMemDC(), 640, 29);
			IMAGEMANAGER->render("체력", getMemDC(), 676, 29);
		}
		else if (_playerInformation.hp == 3.5)
		{
			IMAGEMANAGER->render("체력", getMemDC(), 569, 29);
			IMAGEMANAGER->render("체력", getMemDC(), 604, 29);
			IMAGEMANAGER->render("체력", getMemDC(), 640, 29);
			IMAGEMANAGER->render("체력1", getMemDC(), 676, 29);
		}
	}

	if (_playerInformation.hp == 3)
	{
		IMAGEMANAGER->render("체력", getMemDC(), 569, 29);
		IMAGEMANAGER->render("체력", getMemDC(), 604, 29);
		IMAGEMANAGER->render("체력", getMemDC(), 640, 29);
		if (_caricature[1])IMAGEMANAGER->render("체력2", getMemDC(), 676, 29);
	}
	else if (_playerInformation.hp == 2.5)
	{
		IMAGEMANAGER->render("체력", getMemDC(), 569, 29);
		IMAGEMANAGER->render("체력", getMemDC(), 604, 29);
		IMAGEMANAGER->render("체력1", getMemDC(), 640, 29);
		if (_caricature[1])IMAGEMANAGER->render("체력2", getMemDC(), 676, 29);
	}
	else if (_playerInformation.hp == 2.0)
	{
		IMAGEMANAGER->render("체력", getMemDC(), 569, 29);
		IMAGEMANAGER->render("체력", getMemDC(), 604, 29);
		IMAGEMANAGER->render("체력2", getMemDC(), 640, 29);
		if (_caricature[1])IMAGEMANAGER->render("체력2", getMemDC(), 676, 29);
	}
	else if (_playerInformation.hp == 1.5)
	{
		IMAGEMANAGER->render("체력", getMemDC(), 569, 29);
		IMAGEMANAGER->render("체력1", getMemDC(), 604, 29);
		IMAGEMANAGER->render("체력2", getMemDC(), 640, 29);
		if (_caricature[1])IMAGEMANAGER->render("체력2", getMemDC(), 676, 29);
	}
	else if (_playerInformation.hp == 1)
	{
		IMAGEMANAGER->render("체력", getMemDC(), 569, 29);
		IMAGEMANAGER->render("체력2", getMemDC(), 604, 29);
		IMAGEMANAGER->render("체력2", getMemDC(), 640, 29);
		if (_caricature[1])IMAGEMANAGER->render("체력2", getMemDC(), 676, 29);
	}
	else if (_playerInformation.hp == 0.5)
	{
		IMAGEMANAGER->render("체력1", getMemDC(), 569, 29);
		IMAGEMANAGER->render("체력2", getMemDC(), 604, 29);
		IMAGEMANAGER->render("체력2", getMemDC(), 640, 29);
		if (_caricature[1])IMAGEMANAGER->render("체력2", getMemDC(), 676, 29);
	}
	else if (_playerInformation.hp == 0)
	{
		IMAGEMANAGER->render("체력2", getMemDC(), 569, 29);
		IMAGEMANAGER->render("체력2", getMemDC(), 604, 29);
		IMAGEMANAGER->render("체력2", getMemDC(), 640, 29);
		if (_caricature[1])IMAGEMANAGER->render("체력2", getMemDC(), 676, 29);
	}

	//UI
	if (_Information)
	{
		IMAGEMANAGER->alphaRender("검은색", getMemDC(), 150);
		IMAGEMANAGER->render("정보창", getMemDC(), 170, 190);
		IMAGEMANAGER->frameRender("이동속도", getMemDC(), 224, 248);
		IMAGEMANAGER->frameRender("공속", getMemDC(), 338, 248);
		IMAGEMANAGER->frameRender("공격력", getMemDC(), 443, 248);
		IMAGEMANAGER->frameRender("사거리", getMemDC(), 551, 248);

		RECT _exit = RectMake(273, 438, 265, 35);

		if (PtInRect(&_exit, _ptMouse) && !_out)
		{
			IMAGEMANAGER->render("나가기", getMemDC(), 308, 428);
			if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
			{
				_out = true;
			}
		}
	}
		
	if (_out)
	{
		IMAGEMANAGER->alphaRender("검은색", getMemDC(), 60);
		IMAGEMANAGER->frameRender("메인메뉴돌아가기", getMemDC(), 208, 228);
		RECT _exit1 = RectMake(275, 355, 88, 50);
		RECT _exit2 = RectMake(443, 348, 70, 50);


		if (PtInRect(&_exit1, _ptMouse))
		{
			_stats[4]->setFrameX(1);
			if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
			{
				SCENEMANAGER->changeScene("메인메뉴");
			}
		}
		else if (PtInRect(&_exit2, _ptMouse))
		{
			_stats[4]->setFrameX(2);
			if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
			{
				_out = false;
			}
		}
		else
		{
			_stats[4]->setFrameX(0);
		}
	}


	if (_die)
	{
		IMAGEMANAGER->frameRender("사망메세지", getMemDC(), 150, 30);

		//DrawRectMake(getMemDC(), rc);
		//DrawRectMake(getMemDC(), rc1);
	}

	IMAGEMANAGER->frameRender("스킬게이지", getMemDC(), 543, 6);



}
