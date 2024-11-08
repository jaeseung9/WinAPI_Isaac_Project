#include "Stdafx.h"
#include "Ui.h"

HRESULT Ui::init(void)
{
	IMAGEMANAGER->addImage("����", "Resources/Images/Ui/Ui.bmp", 794, 96, true, RGB(255, 0, 255));
	AddFontResource("Resources/font/inconsolata-bold.ttf");

	IMAGEMANAGER->addImage("ü��", "Resources/Images/Ui/hp.bmp", 31, 25, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("ü��1", "Resources/Images/Ui/hp1.bmp", 31, 25, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("ü��2", "Resources/Images/Ui/hp2.bmp", 31, 25, true, RGB(255, 0, 255));
    IMAGEMANAGER->addImage("����â", "Resources/Images/Ui/Information.bmp", 461, 331, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("������", "Resources/Images/Ui/Black.bmp", WINSIZE_X, WINSIZE_Y, true, RGB(255, 0, 255));

	IMAGEMANAGER->addImage("������", "Resources/Images/Ui/Exit.bmp", 235, 51, true, RGB(255, 0, 255));

	_stats[0] = IMAGEMANAGER->addFrameImage("�̵��ӵ�", "Resources/Images/Ui/MovingSpeed.bmp", 406, 25,7,1, true, RGB(255, 0, 255));
	_stats[1] = IMAGEMANAGER->addFrameImage("����", "Resources/Images/Ui/AttackSpeed.bmp",434, 22,7,1, true, RGB(255, 0, 255));
	_stats[2] = IMAGEMANAGER->addFrameImage("���ݷ�", "Resources/Images/Ui/Power.bmp", 434, 27,7,1, true, RGB(255, 0, 255));
	_stats[3] = IMAGEMANAGER->addFrameImage("��Ÿ�", "Resources/Images/Ui/Intersection.bmp", 455, 27,7,1, true, RGB(255, 0, 255));
	_stats[4] = IMAGEMANAGER->addFrameImage("���θ޴����ư���", "Resources/Images/Ui/GetOut.bmp", 1203, 195, 3, 1, true, RGB(255, 0, 255));

	_stats[5] = IMAGEMANAGER->addFrameImage("����޼���", "Resources/Images/Ui/DieWindow.bmp", 1671 , 540 ,3,1, true, RGB(255, 0, 255));

	_stats[6] = IMAGEMANAGER->addFrameImage("��ų������", "Resources/Images/Ui/SkileGage.bmp", 112, 78, 7, 1, true, RGB(255, 0, 255));


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
				SCENEMANAGER->changeScene("����");
				SCENEMANAGER->changeScene("���θ޴�");
				SCENEMANAGER->changeScene("���ӽ���");                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    
			}
		}
		else if (PtInRect(&rc1, _ptMouse))
		{
			_stats[5]->setFrameX(2);

			if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
			{
				SCENEMANAGER->changeScene("���θ޴�");
			}
		}
		else _stats[5]->setFrameX(0);
	}

	_stats[6]->setFrameX(_playerInformation.skileGage);
}

void Ui::render(void)
{
	IMAGEMANAGER->render("����", getMemDC());

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
			IMAGEMANAGER->render("ü��", getMemDC(), 569, 29);
			IMAGEMANAGER->render("ü��", getMemDC(), 604, 29);
			IMAGEMANAGER->render("ü��", getMemDC(), 640, 29);
			IMAGEMANAGER->render("ü��", getMemDC(), 676, 29);
		}
		else if (_playerInformation.hp == 3.5)
		{
			IMAGEMANAGER->render("ü��", getMemDC(), 569, 29);
			IMAGEMANAGER->render("ü��", getMemDC(), 604, 29);
			IMAGEMANAGER->render("ü��", getMemDC(), 640, 29);
			IMAGEMANAGER->render("ü��1", getMemDC(), 676, 29);
		}
	}

	if (_playerInformation.hp == 3)
	{
		IMAGEMANAGER->render("ü��", getMemDC(), 569, 29);
		IMAGEMANAGER->render("ü��", getMemDC(), 604, 29);
		IMAGEMANAGER->render("ü��", getMemDC(), 640, 29);
		if (_caricature[1])IMAGEMANAGER->render("ü��2", getMemDC(), 676, 29);
	}
	else if (_playerInformation.hp == 2.5)
	{
		IMAGEMANAGER->render("ü��", getMemDC(), 569, 29);
		IMAGEMANAGER->render("ü��", getMemDC(), 604, 29);
		IMAGEMANAGER->render("ü��1", getMemDC(), 640, 29);
		if (_caricature[1])IMAGEMANAGER->render("ü��2", getMemDC(), 676, 29);
	}
	else if (_playerInformation.hp == 2.0)
	{
		IMAGEMANAGER->render("ü��", getMemDC(), 569, 29);
		IMAGEMANAGER->render("ü��", getMemDC(), 604, 29);
		IMAGEMANAGER->render("ü��2", getMemDC(), 640, 29);
		if (_caricature[1])IMAGEMANAGER->render("ü��2", getMemDC(), 676, 29);
	}
	else if (_playerInformation.hp == 1.5)
	{
		IMAGEMANAGER->render("ü��", getMemDC(), 569, 29);
		IMAGEMANAGER->render("ü��1", getMemDC(), 604, 29);
		IMAGEMANAGER->render("ü��2", getMemDC(), 640, 29);
		if (_caricature[1])IMAGEMANAGER->render("ü��2", getMemDC(), 676, 29);
	}
	else if (_playerInformation.hp == 1)
	{
		IMAGEMANAGER->render("ü��", getMemDC(), 569, 29);
		IMAGEMANAGER->render("ü��2", getMemDC(), 604, 29);
		IMAGEMANAGER->render("ü��2", getMemDC(), 640, 29);
		if (_caricature[1])IMAGEMANAGER->render("ü��2", getMemDC(), 676, 29);
	}
	else if (_playerInformation.hp == 0.5)
	{
		IMAGEMANAGER->render("ü��1", getMemDC(), 569, 29);
		IMAGEMANAGER->render("ü��2", getMemDC(), 604, 29);
		IMAGEMANAGER->render("ü��2", getMemDC(), 640, 29);
		if (_caricature[1])IMAGEMANAGER->render("ü��2", getMemDC(), 676, 29);
	}
	else if (_playerInformation.hp == 0)
	{
		IMAGEMANAGER->render("ü��2", getMemDC(), 569, 29);
		IMAGEMANAGER->render("ü��2", getMemDC(), 604, 29);
		IMAGEMANAGER->render("ü��2", getMemDC(), 640, 29);
		if (_caricature[1])IMAGEMANAGER->render("ü��2", getMemDC(), 676, 29);
	}

	//UI
	if (_Information)
	{
		IMAGEMANAGER->alphaRender("������", getMemDC(), 150);
		IMAGEMANAGER->render("����â", getMemDC(), 170, 190);
		IMAGEMANAGER->frameRender("�̵��ӵ�", getMemDC(), 224, 248);
		IMAGEMANAGER->frameRender("����", getMemDC(), 338, 248);
		IMAGEMANAGER->frameRender("���ݷ�", getMemDC(), 443, 248);
		IMAGEMANAGER->frameRender("��Ÿ�", getMemDC(), 551, 248);

		RECT _exit = RectMake(273, 438, 265, 35);

		if (PtInRect(&_exit, _ptMouse) && !_out)
		{
			IMAGEMANAGER->render("������", getMemDC(), 308, 428);
			if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
			{
				_out = true;
			}
		}
	}
		
	if (_out)
	{
		IMAGEMANAGER->alphaRender("������", getMemDC(), 60);
		IMAGEMANAGER->frameRender("���θ޴����ư���", getMemDC(), 208, 228);
		RECT _exit1 = RectMake(275, 355, 88, 50);
		RECT _exit2 = RectMake(443, 348, 70, 50);


		if (PtInRect(&_exit1, _ptMouse))
		{
			_stats[4]->setFrameX(1);
			if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
			{
				SCENEMANAGER->changeScene("���θ޴�");
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
		IMAGEMANAGER->frameRender("����޼���", getMemDC(), 150, 30);

		//DrawRectMake(getMemDC(), rc);
		//DrawRectMake(getMemDC(), rc1);
	}

	IMAGEMANAGER->frameRender("��ų������", getMemDC(), 543, 6);



}
