#include "Stdafx.h"
#include "Object.h"

HRESULT Object::init(void)
{
	IMAGEMANAGER->addFrameImage("불", "Resources/Images/Object/fire.bmp",
		240 * 1.5, 50 * 1.5, 6, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("나무", "Resources/Images/Object/wood.bmp",
		32 * 1.5, 32 * 1.5,true,RGB(255,0,255));

	IMAGEMANAGER->addImage("Stone0", "Resources/Images/Object/Stone0.bmp",
		52 * 1.5, 52 * 1.5, true, RGB(255, 0, 255));

	IMAGEMANAGER->addImage("Stone1", "Resources/Images/Object/Stone1.bmp",
		52 * 1.5, 52 * 1.5, true, RGB(255, 0, 255));

	IMAGEMANAGER->addImage("Stone2", "Resources/Images/Object/Stone2.bmp",
		52 * 1.5, 52 * 1.5, true, RGB(255, 0, 255));

	IMAGEMANAGER->addImage("Stone3", "Resources/Images/Object/Stone3.bmp",
		52 * 1.5, 52 * 1.5, true, RGB(255, 0, 255));

	IMAGEMANAGER->addImage("가시", "Resources/Images/Object/thorn.bmp",
		45 , 52 , true, RGB(255, 0, 255));

	IMAGEMANAGER->addFrameImage("문", "Resources/Images/Object/door.bmp",
		98 * 1.5, 33 * 1.5, 2, 1, true, RGB(255, 0, 255));

	IMAGEMANAGER->addFrameImage("문1", "Resources/Images/Object/door1.bmp",
		98 * 1.5, 33 * 1.5, 2, 1, true, RGB(255, 0, 255));

	IMAGEMANAGER->addFrameImage("문2", "Resources/Images/Object/door2.bmp",
		33 * 1.5, 98 * 1.5, 1, 2, true, RGB(255, 0, 255));

	IMAGEMANAGER->addFrameImage("문3", "Resources/Images/Object/door3.bmp",
		33 * 1.5, 98 * 1.5, 1, 2, true, RGB(255, 0, 255));

	IMAGEMANAGER->addFrameImage("보스문", "Resources/Images/Object/bossDoor.bmp",
		112 * 1.5, 39 * 1.5, 2, 1, true, RGB(255, 0, 255));

	IMAGEMANAGER->addFrameImage("보스문1", "Resources/Images/Object/bossDoor1.bmp",
		112 * 1.5, 39 * 1.5, 2, 1, true, RGB(255, 0, 255));

	IMAGEMANAGER->addFrameImage("보스문2", "Resources/Images/Object/bossDoor2.bmp",
		39 * 1.5, 122 * 1.5, 1, 2, true, RGB(255, 0, 255));

	IMAGEMANAGER->addFrameImage("보스문3", "Resources/Images/Object/bossDoor3.bmp",
		39 * 1.5, 122 * 1.5, 1, 2, true, RGB(255, 0, 255));



	IMAGEMANAGER->addFrameImage("상점문", "Resources/Images/Object/ShopDoor.bmp",
		98 * 1.5, 38 * 1.5, 2, 1, true, RGB(255, 0, 255));

	IMAGEMANAGER->addFrameImage("상점문1", "Resources/Images/Object/ShopDoor1.bmp",
		98 * 1.5, 38 * 1.5, 2, 1, true, RGB(255, 0, 255));

	IMAGEMANAGER->addFrameImage("상점문2", "Resources/Images/Object/ShopDoor2.bmp",
		38 * 1.5, 98 * 1.5, 1, 2, true, RGB(255, 0, 255));

	IMAGEMANAGER->addFrameImage("상점문3", "Resources/Images/Object/ShopDoor3.bmp",
		38 * 1.5, 98 * 1.5, 1, 2, true, RGB(255, 0, 255));



	IMAGEMANAGER->addFrameImage("보스클리어문", "Resources/Images/Object/보스클리어문1.bmp",
		296 * 1.5, 57 * 1.5, 5, 1, true, RGB(255, 0, 255));

	IMAGEMANAGER->addFrameImage("잠긴문", "Resources/Images/Object/ShopLockeDoor.bmp",
		98 * 1.5, 38 * 1.5, 2, 1, true, RGB(255, 0, 255));

	IMAGEMANAGER->addFrameImage("잠긴문1", "Resources/Images/Object/ShopLockeDoor1.bmp",
		98 * 1.5, 38 * 1.5, 2, 1, true, RGB(255, 0, 255));

	IMAGEMANAGER->addFrameImage("잠긴문2", "Resources/Images/Object/ShopLockeDoor2.bmp",
		38 * 1.5, 98 * 1.5, 1, 2, true, RGB(255, 0, 255));

	IMAGEMANAGER->addFrameImage("잠긴문3", "Resources/Images/Object/ShopLockeDoor3.bmp",
		38 * 1.5, 98 * 1.5, 1, 2, true, RGB(255, 0, 255));

	return S_OK;
}

void Object::release(void)
{
}

void Object::update(void)
{
	if (KEYMANAGER->isStayKeyDown(VK_F1))
	{
		if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
		{
			object ob0;
			ob0.x = _ptMouse.x;
			ob0.y = _ptMouse.y;
			ob0.impact = false;
			ob0.frameX = 0;
			ob0.frameY = 0;
			ob0.open = false;
			ob0.alpha = 180;
			ob0.frameXTime = 0;
			_vfire.push_back(ob0);
		}
	}
	
	if (KEYMANAGER->isStayKeyDown(VK_F2))
	{
		if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
		{
			object ob1;
			ob1.x = _ptMouse.x;
			ob1.y = _ptMouse.y;
			ob1.impact = false;
			ob1.frameX = 0;
			ob1.frameY = 0;
			ob1.open = false;
			ob1.alpha = 0;
			ob1.frameXTime = 0;
			_vthorn.push_back(ob1);

		}
	}

	if (KEYMANAGER->isStayKeyDown(VK_F3))
	{
		if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
		{
			object ob2;
			ob2.x = _ptMouse.x;
			ob2.y = _ptMouse.y;
			ob2.impact = false;
			ob2.frameX = 0;
			ob2.frameY = 0;
			ob2.open = false;
			ob2.alpha = 0;
			ob2.frameXTime = 0;
			ob2.Name = "Stone0";
			_vston[0].push_back(ob2);

		}
	}
	if (KEYMANAGER->isStayKeyDown(VK_F4))
	{
		if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
		{
			object ob2;
			ob2.x = _ptMouse.x;
			ob2.y = _ptMouse.y;
			ob2.impact = false;
			ob2.frameX = 0;
			ob2.frameY = 0;
			ob2.open = false;
			ob2.alpha = 0;
			ob2.frameXTime = 0;
			ob2.Name = "Stone1";
			_vston[1].push_back(ob2);

		}
	}
	if (KEYMANAGER->isStayKeyDown(VK_F5))
	{
		if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
		{
			object ob2;
			ob2.x = _ptMouse.x;
			ob2.y = _ptMouse.y;
			ob2.impact = false;
			ob2.frameX = 0;
			ob2.frameY = 0;
			ob2.open = false;
			ob2.alpha = 0;
			ob2.frameXTime = 0;
			ob2.Name = "Stone2";
			_vston[2].push_back(ob2);

		}
	}
	if (KEYMANAGER->isStayKeyDown(VK_F6))
	{
		if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
		{
			object ob2;
			ob2.x = _ptMouse.x;
			ob2.y = _ptMouse.y;
			ob2.impact = false;
			ob2.frameX = 0;
			ob2.frameY = 0;
			ob2.open = false;
			ob2.alpha = 0;
			ob2.frameXTime = 0;
			ob2.Name = "Stone3";
			_vston[3].push_back(ob2);

		}
	}

	if (KEYMANAGER->isStayKeyDown(VK_F7))
	{
		if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
		{
			object ob3;
			ob3.x = _ptMouse.x;
			ob3.y = _ptMouse.y;
			ob3.impact = false;
			ob3.frameX = 0;
			ob3.frameY = 0;
			ob3.open = false;
			ob3.alpha = 0;
			ob3.frameXTime = 0;
			ob3.Name = "문";
			_vdoor[0].push_back(ob3);

		}
	}
	if (KEYMANAGER->isStayKeyDown(VK_F8))
	{
		if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
		{
			object ob3;
			ob3.x = _ptMouse.x;
			ob3.y = _ptMouse.y;
			ob3.impact = false;
			ob3.frameX = 0;
			ob3.frameY = 0;
			ob3.open = false;
			ob3.alpha = 0;
			ob3.frameXTime = 0;
			ob3.Name = "문1";
			//ob3.rc = RectMake(_ptMouse.x + 15, _ptMouse.y-15, 40, 65);
			_vdoor[1].push_back(ob3);

		}
	}

	if (KEYMANAGER->isStayKeyDown(VK_F9))
	{
		if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
		{
			object ob3;
			ob3.x = _ptMouse.x;
			ob3.y = _ptMouse.y;
			ob3.impact = false;
			ob3.frameX = 0;
			ob3.frameY = 0;
			ob3.open = false;
			ob3.alpha = 0;
			ob3.frameXTime = 0;
			ob3.Name = "문2";
			//ob3.rc = RectMake(_ptMouse.x , _ptMouse.y + 15, 64, 45);
			_vdoor[2].push_back(ob3);

		}
	}

	if (KEYMANAGER->isStayKeyDown(VK_F10))
	{
		if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
		{
			object ob3;
			ob3.x = _ptMouse.x;
			ob3.y = _ptMouse.y;
			ob3.impact = false;
			ob3.frameX = 0;
			ob3.frameY = 0;
			ob3.open = false;
			ob3.alpha = 0;
			ob3.frameXTime = 0;
			ob3.Name = "문3";
			//ob3.rc = RectMake(_ptMouse.x-15, _ptMouse.y + 15, 64, 45);
			_vdoor[3].push_back(ob3);

		}
	}

	//보스문

	if (KEYMANAGER->isStayKeyDown(VK_F1))
	{
		if (KEYMANAGER->isOnceKeyDown(VK_RBUTTON))
		{
			object ob3;
			ob3.x = _ptMouse.x;
			ob3.y = _ptMouse.y;
			ob3.impact = false;
			ob3.frameX = 0;
			ob3.frameY = 0;
			ob3.open = false;
			ob3.alpha = 0;
			ob3.frameXTime = 0;
			ob3.Name = "보스문";
			_vdoor[0].push_back(ob3);

		}
	}
	if (KEYMANAGER->isStayKeyDown(VK_F2))
	{
		if (KEYMANAGER->isOnceKeyDown(VK_RBUTTON))
		{
			object ob3;
			ob3.x = _ptMouse.x;
			ob3.y = _ptMouse.y;
			ob3.impact = false;
			ob3.frameX = 0;
			ob3.frameY = 0;
			ob3.open = false;
			ob3.alpha = 0;
			ob3.frameXTime = 0;
			ob3.Name = "보스문1";
			//ob3.rc = RectMake(_ptMouse.x + 15, _ptMouse.y-15, 40, 65);
			_vdoor[1].push_back(ob3);

		}
	}

	if (KEYMANAGER->isStayKeyDown(VK_F3))
	{
		if (KEYMANAGER->isOnceKeyDown(VK_RBUTTON))
		{
			object ob3;
			ob3.x = _ptMouse.x;
			ob3.y = _ptMouse.y;
			ob3.impact = false;
			ob3.frameX = 0;
			ob3.frameY = 0;
			ob3.open = false;
			ob3.alpha = 0;
			ob3.frameXTime = 0;
			ob3.Name = "보스문2";
			//ob3.rc = RectMake(_ptMouse.x , _ptMouse.y + 15, 64, 45);
			_vdoor[2].push_back(ob3);

		}
	}

	if (KEYMANAGER->isStayKeyDown(VK_F4))
	{
		if (KEYMANAGER->isOnceKeyDown(VK_RBUTTON))
		{
			object ob3;
			ob3.x = _ptMouse.x;
			ob3.y = _ptMouse.y;
			ob3.impact = false;
			ob3.frameX = 0;
			ob3.frameY = 0;
			ob3.open = false;
			ob3.alpha = 0;
			ob3.frameXTime = 0;
			ob3.Name = "보스문3";
			//ob3.rc = RectMake(_ptMouse.x-15, _ptMouse.y + 15, 64, 45);
			_vdoor[3].push_back(ob3);

		}
	}

	//상점문 

	if (KEYMANAGER->isStayKeyDown(VK_F5))
	{
		if (KEYMANAGER->isOnceKeyDown(VK_RBUTTON))
		{
			object ob3;
			ob3.x = _ptMouse.x;
			ob3.y = _ptMouse.y;
			ob3.impact = false;
			ob3.frameX = 0;
			ob3.frameY = 0;
			ob3.open = false;
			ob3.alpha = 0;
			ob3.frameXTime = 0;
			ob3.Name = "상점문";
			//ob3.rc = RectMake(_ptMouse.x + 15, _ptMouse.y, 40, 65);
			_vdoor[0].push_back(ob3);

		}
	}
	if (KEYMANAGER->isStayKeyDown(VK_F6))
	{
		if (KEYMANAGER->isOnceKeyDown(VK_RBUTTON))
		{
			object ob3;
			ob3.x = _ptMouse.x;
			ob3.y = _ptMouse.y;
			ob3.impact = false;
			ob3.frameX = 0;
			ob3.frameY = 0;
			ob3.open = false;
			ob3.alpha = 0;
			ob3.frameXTime = 0;
			ob3.Name = "상점문1";
			//ob3.rc = RectMake(_ptMouse.x + 15, _ptMouse.y-15, 40, 65);
			_vdoor[1].push_back(ob3);

		}
	}

	if (KEYMANAGER->isStayKeyDown(VK_F7))
	{
		if (KEYMANAGER->isOnceKeyDown(VK_RBUTTON))
		{
			object ob3;
			ob3.x = _ptMouse.x;
			ob3.y = _ptMouse.y;
			ob3.impact = false;
			ob3.frameX = 0;
			ob3.frameY = 0;
			ob3.open = false;
			ob3.alpha = 0;
			ob3.frameXTime = 0;
			ob3.Name = "상점문2";
			//ob3.rc = RectMake(_ptMouse.x , _ptMouse.y + 15, 64, 45);
			_vdoor[2].push_back(ob3);

		}
	}

	if (KEYMANAGER->isStayKeyDown(VK_F8))
	{
		if (KEYMANAGER->isOnceKeyDown(VK_RBUTTON))
		{
			object ob3;
			ob3.x = _ptMouse.x;
			ob3.y = _ptMouse.y;
			ob3.impact = false;
			ob3.frameX = 0;
			ob3.frameY = 0;
			ob3.open = false;
			ob3.alpha = 0;
			ob3.frameXTime = 0;
			ob3.Name = "상점문3";
			//ob3.rc = RectMake(_ptMouse.x-15, _ptMouse.y + 15, 64, 45);
			_vdoor[3].push_back(ob3);

		}
	}
	if (KEYMANAGER->isOnceKeyDown(VK_F11))
	{
		
			object ob4;
			ob4.x = _ptMouse.x;
			ob4.y = _ptMouse.y;
			ob4.impact = false;
			ob4.frameX = 0;
			ob4.frameY = 0;
			ob4.open = false;
			ob4.alpha = 0;
			ob4.frameXTime = 0;
			ob4.Name = "보스클리어문";
			_vbossDoor1.push_back(ob4);
		
	}
														
	for (int i = 0; i < _vbossDoor1.size(); i++)
	{
		_vbossDoor1[i].rc = RectMake(_vbossDoor1[i].x+19, _vbossDoor1[i].y+42, 50, 40);

		if (!_vbossDoor1[i].open) _vbossDoor1[i].frameXTime += TIMEMANAGER->getElapsedTime();

		if (_vbossDoor1[i].frameXTime > 2.0f)
		{
			if (_vbossDoor1[i].frameX == 0)_vbossDoor1[i].frameX++;
			_vbossDoor1[i].frameXTime = 0;
			_vbossDoor1[i].open = true;
		}
		
	}

	for (int k = 0; k < 4; k++)
	{
		for (int i = 0; i < _vston[k].size(); i++)
		{
			_vston[k][i].rc = RectMake(_vston[k][i].x + 18, _vston[k][i].y + 18, 37, 37);
		}
	}

	for (int k = 0; k < 4; k++)
	{
		for (int i = 0; i < _vdoor[k].size(); i++)
		{
			if (k == 0)_vdoor[k][i].rc = RectMake(_vdoor[k][i].x + 15, _vdoor[k][i].y , 40, 52);
			if (k == 1)_vdoor[k][i].rc = RectMake(_vdoor[k][i].x + 15, _vdoor[k][i].y, 40,55);
			if (k == 2)_vdoor[k][i].rc = RectMake(_vdoor[k][i].x + 5, _vdoor[k][i].y + 15, 55,45);
			if (k == 3)_vdoor[k][i].rc = RectMake(_vdoor[k][i].x - 3, _vdoor[k][i].y + 15, 55,45);
		}
	
	}

	for (int k = 0; k < 4; k++)
	{
		for (int i = 0; i < _vshopLockeDoor[k].size(); i++)
		{
			if (k == 0)_vshopLockeDoor[k][i].rc = RectMake(_vshopLockeDoor[k][i].x + 15, _vshopLockeDoor[k][i].y, 40, 55);
			if (k == 1)_vshopLockeDoor[k][i].rc = RectMake(_vshopLockeDoor[k][i].x + 15, _vshopLockeDoor[k][i].y - 5, 40, 55);
			if (k == 2)_vshopLockeDoor[k][i].rc = RectMake(_vshopLockeDoor[k][i].x + 5, _vshopLockeDoor[k][i].y + 15, 58, 45);
			if (k == 3)_vshopLockeDoor[k][i].rc = RectMake(_vshopLockeDoor[k][i].x - 7, _vshopLockeDoor[k][i].y + 15, 55, 45);
		}
	}


	for (int i = 0; i < _vfire.size(); i++)
	{
		_vfire[i].frameXTime += TIMEMANAGER->getElapsedTime();

		
		if (_vfire[i].frameXTime > 0.15f)
		{
			_vfire[i].frameXTime = 0;
			_vfire[i].frameX++;
			if (_vfire[i].frameX >= 6)
			{
				_vfire[i].frameX = 0;
			}
		
		}

		_vfire[i].rc = RectMake(_vfire[i].x + 6.5f, _vfire[i].y + 10, 45, 60);
	}

	for (int i = 0; i < _vthorn.size(); i++)
	{
		_vthorn[i].rc = RectMake(_vthorn[i].x, _vthorn[i].y +5, 45, 45);
	}


}

void Object::render(void)
{
	for (int i = 0; i < _vfire.size(); i++)
	{
		IMAGEMANAGER->render("나무", getMemDC(), _vfire[i].x +5, _vfire[i].y + 40);
		IMAGEMANAGER->alphaFrameRender("불", getMemDC(), _vfire[i].x, _vfire[i].y, _vfire[i].alpha, _vfire[i].frameX, _vfire[i].frameY);

		//DrawRectMake(getMemDC(), _vfire[i].rc);
	}

	for (int i = 0; i < _vthorn.size(); i++)
	{
		IMAGEMANAGER->render("가시", getMemDC(), _vthorn[i].x, _vthorn[i].y);
	//	DrawRectMake(getMemDC(), _vthorn[i].rc);
	}

	for (int k = 0; k < 4; k++)
	{
		for (int i = 0; i < _vston[k].size(); i++)
		{
			IMAGEMANAGER->render(_vston[k][i].Name, getMemDC(), _vston[k][i].x, _vston[k][i].y);
			//DrawRectMake(getMemDC(), _vston[k][i].rc);
		}
	}
	for (int k = 0; k < 4; k++)
	{
		for (int i = 0; i < _vdoor[k].size(); i++)
		{
			IMAGEMANAGER->frameRender(_vdoor[k][i].Name, getMemDC(), _vdoor[k][i].x, _vdoor[k][i].y, _vdoor[k][i].frameX, _vdoor[k][i].frameY);
			//DrawRectMake(getMemDC(), _vdoor[k][i].rc);
		}
	}

	for (int k = 0; k < 4; k++)
	{
		for (int i = 0; i < _vshopLockeDoor[k].size(); i++)
		{
			IMAGEMANAGER->frameRender(_vshopLockeDoor[k][i].Name, getMemDC(), _vshopLockeDoor[k][i].x, _vshopLockeDoor[k][i].y, _vshopLockeDoor[k][i].frameX, _vshopLockeDoor[k][i].frameY);
			//DrawRectMake(getMemDC(), _vshopLockeDoor[k][i].rc);
		}
	}

	for (int i = 0; i < _vbossDoor1.size(); i++)
	{
		IMAGEMANAGER->frameRender(_vbossDoor1[i].Name, getMemDC(), _vbossDoor1[i].x, _vbossDoor1[i].y, _vbossDoor1[i].frameX, _vbossDoor1[i].frameY);
		//DrawRectMake(getMemDC(), _vbossDoor1[i].rc);
	}	




}
