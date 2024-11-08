#include "Stdafx.h"
#include "Monster.h"

HRESULT Monster::init(void)
{
	SOUNDMANAGER->addSound("보스방", "Resources/Sounds/보스방.wav", false, false);
	SOUNDMANAGER->addSound("보스방진입", "Resources/Sounds/보스방진입.mp3", false, false);

	_bossGimage[0] = IMAGEMANAGER->addFrameImage("1층보스시작", "Resources/Images/Monster/1층보스시작.bmp",
		WINSIZE_X * 25, WINSIZE_Y, 25, 1, true, RGB(255, 0, 255));

	_bossGimage[1] = IMAGEMANAGER->addFrameImage("2층보스시작", "Resources/Images/Monster/2층보스시작.bmp",
		WINSIZE_X * 25, WINSIZE_Y, 25, 1, true, RGB(255, 0, 255));

	_bossGimage[2] = IMAGEMANAGER->addFrameImage("3층보스시작", "Resources/Images/Monster/3층보스시작.bmp",
		WINSIZE_X * 25, WINSIZE_Y, 25, 1, true, RGB(255, 0, 255));

	_bossGimage[3] = IMAGEMANAGER->addFrameImage("4층보스시작", "Resources/Images/Monster/4층보스시작.bmp",
		WINSIZE_X * 25, WINSIZE_Y, 25, 1, true, RGB(255, 0, 255));

	IMAGEMANAGER->addFrameImage("점프몬스터", "Resources/Images/Monster/몬스터8.bmp",
		384 * 2.0, 32 * 2.5, 12, 1, true, RGB(255, 0, 255));

	IMAGEMANAGER->addFrameImage("몸만남은몬스터", "Resources/Images/Monster/몬스터1몸통만 남았을때.bmp",
		128 * 2.0, 64 * 2.5, 4, 2, true, RGB(255, 0, 255));

	IMAGEMANAGER->addFrameImage("날벌레", "Resources/Images/Monster/몬스터5.bmp",
		128 * 2.0, 32 * 2.0, 4, 1, true, RGB(255, 0, 255));

	IMAGEMANAGER->addFrameImage("지렁이", "Resources/Images/Monster/몬스터4.3.bmp",
		226 * 1.5, 64 * 1.5, 7, 2, true, RGB(255, 0, 255));

	IMAGEMANAGER->addFrameImage("얼굴달린몬스터", "Resources/Images/Monster/몬스터1얼굴.bmp",
		128 * 1.75, 32 * 1.75, 4, 1, true, RGB(255, 0, 255));

	IMAGEMANAGER->addFrameImage("얼굴달린몬스터몸", "Resources/Images/Monster/몬스터1몸2.bmp",
		256 * 1.75, 64 * 1.75, 8, 2, true, RGB(255, 0, 255));

	IMAGEMANAGER->addFrameImage("얼굴만남은몬스터", "Resources/Images/Monster/몬스터6.bmp",
		128 * 1.5, 32 * 1.5, 4, 1, true, RGB(255, 0, 255));

	IMAGEMANAGER->addFrameImage("방패몬스터", "Resources/Images/Monster/몬스터2.bmp",
		96 * 1.5, 64 * 1.5, 3, 1, true, RGB(255, 0, 255));

	IMAGEMANAGER->addFrameImage("모기몬스터", "Resources/Images/Monster/몬스터7.bmp",
		192 * 1.5, 64 * 1.5, 6, 2, true, RGB(255, 0, 255));


	IMAGEMANAGER->addFrameImage("boss0", "Resources/Images/Monster/boss01.bmp",
		320 * 1.5, 64 * 1.5, 4, 1, true, RGB(255, 0, 255));

	IMAGEMANAGER->addFrameImage("boss1", "Resources/Images/Monster/boss1.bmp",
		450 * 1.5, 49 * 1.5, 9, 1, true, RGB(255, 0, 255));

	IMAGEMANAGER->addFrameImage("boss1다리", "Resources/Images/Monster/boss1다리2.bmp",
		256 * 2.0, 32 * 2.0, 8, 1, true, RGB(255, 0, 255));

	IMAGEMANAGER->addFrameImage("보스1쫄", "Resources/Images/Monster/보스1쫄2.bmp",
		224 * 1.5, 58 * 1.5, 7, 2, true, RGB(255, 0, 255));

	IMAGEMANAGER->addFrameImage("보스2", "Resources/Images/Monster/Mask.bmp",
		256 * 1.5, 128 * 1.5, 4, 2, true, RGB(255, 0, 255));

	IMAGEMANAGER->addImage("Heart", "Resources/Images/Monster/Heart.bmp",
		64 * 1.5, 64 * 1.5, true, RGB(255, 0, 255));

	IMAGEMANAGER->addFrameImage("보스3", "Resources/Images/Monster/boss3.bmp",
		288 * 1.5, 65 * 1.5, 4, 1, true, RGB(255, 0, 255));



	IMAGEMANAGER->addImage("점", "Resources/Images/Monster/점.bmp",
		8 * 1.5, 8 * 1.5, true, RGB(255, 0, 255));


	IMAGEMANAGER->addFrameImage("몬스터피", "Resources/Images/Monster/MonsterDie.bmp",
		1200 /2, 200 /2, 10, 1, true, RGB(255, 0, 255));


	IMAGEMANAGER->addFrameImage("날벌레 사망", "Resources/Images/Monster/날벌레 사망.bmp",
		768 , 64 , 12, 1, true, RGB(255, 0, 255));

	IMAGEMANAGER->addFrameImage("몬스터피1", "Resources/Images/Monster/MonsterDie3.bmp",
		774, 112 , 9, 1, true, RGB(255, 0, 255));



	IMAGEMANAGER->addFrameImage("몬스터공격", "Resources/Images/Monster/MonsterAkt.bmp",
		896 * 1.5, 64 * 1.5, 14, 1, true, RGB(255, 0, 255));

	IMAGEMANAGER->addImage("그림자", "Resources/Images/Monster/Shadow.bmp",
		18 * 2.5, 8 * 2.5, true, RGB(255, 0, 255));

	IMAGEMANAGER->addImage("그림자1", "Resources/Images/Monster/Shadow.bmp",
		18 * 1.5, 8 * 1.5, true, RGB(255, 0, 255));

	IMAGEMANAGER->addImage("그림자1.5", "Resources/Images/Monster/Shadow.bmp",
		18 * 3.5, 8 * 3.5, true, RGB(255, 0, 255));

	IMAGEMANAGER->addImage("그림자2", "Resources/Images/Monster/Shadow.bmp",
		18 * 5.5, 8 * 5.5, true, RGB(255, 0, 255));


	IMAGEMANAGER->addImage("그림자3", "Resources/Images/Monster/Shadow.bmp",
		18 * 8.5, 8 * 8.5, true, RGB(255, 0, 255));

	IMAGEMANAGER->addImage("보스체력바", "Resources/Images/Monster/보스체력바.bmp",
		116 * 2.5, 18 * 2.5, true, RGB(255, 0, 255));

	IMAGEMANAGER->addImage("보스hp얼굴", "Resources/Images/Monster/보스hp얼굴.bmp",
		19 * 2.5, 18 * 2.5, true, RGB(255, 0, 255));

	IMAGEMANAGER->addImage("줄보스스타트", "Resources/Images/Monster/bossStart.bmp",
		WINSIZE_X, WINSIZE_Y, true, RGB(255, 0, 255));

	


	_map = RectMake(110, 180, 570, 330);

	_wall = RectMake(90, 150, 615, 387);


	_rcOk = false;

	C = 0;
	_bossHp = 0;

	for (int i = 0; i < 14; i++)
	{
		distansX[i] = 0;
		distansY[i] = 0;

	}
	_vMonster[1].push_back({ -5000000, -5000000000, 0, 0.5f, 6.0f, 0.5f,0,0,
		IMAGEMANAGER->findImage("몸만남은몬스터"),0,0,false,0 });


	cameraImpactrc = RectMake(20, 100, 750, 480);

	_bossStart = false;
	_frameTime = 0;

	for (int i = 0; i < 4; i++)
	{
		_bossEnd[i] = false;
	}

	_sound = false;

	return S_OK;
}

void Monster::release(void)
{
}

void Monster::update(void)
{
#pragma region 몬스터들 푸시백
	if (KEYMANAGER->isOnceKeyDown('1'))
	{
		_vMonster[0].push_back({ RND->getFromFloatTo(50,650), RND->getFromFloatTo(100,470), 0, 0.5f, 6.0f, 1.5f,0,0,
			IMAGEMANAGER->findImage("점프몬스터"),0,0,false,3 });
	}
	if (KEYMANAGER->isOnceKeyDown('2'))
	{
		_vMonster[1].push_back({ RND->getFromFloatTo(50,650), RND->getFromFloatTo(100,470), 0, 0.5f, 6.0f, 0.5f,0,0,
			IMAGEMANAGER->findImage("몸만남은몬스터"),0,0,false,0 });
	}
	if (KEYMANAGER->isOnceKeyDown('3'))
	{
		_vMonster[2].push_back({ RND->getFromFloatTo(50,650), RND->getFromFloatTo(100,470),  RND->getFromFloatTo(-1,1), 0.5f, 4.0f, 1.0f,0,0,
			IMAGEMANAGER->findImage("날벌레"),0,0,false,0 });
	}
	if (KEYMANAGER->isOnceKeyDown('4'))
	{
		_vMonster[3].push_back({ RND->getFromFloatTo(80,650), RND->getFromFloatTo(130,470),  RND->getFromFloatTo(-1,1), 0.5f, 5.0f, 0.5f,0,0,
			IMAGEMANAGER->findImage("지렁이"),0,0,false,0 });
	}
	if (KEYMANAGER->isOnceKeyDown('5'))
	{
		MonsterInformation monster5;

		monster5.angle = 0;
		monster5.atk = 0.5f;
		monster5.atkSpeed = 0.0f;
		monster5.direction = RND->getInt(4);
		monster5.frameTime = 0;
		monster5.frameX = 0;
		monster5.frameY = 0;
		monster5.hp = 8.0f;
		monster5.move = false;
		monster5.speed = 0.3f;
		monster5.x = RND->getFromFloatTo(80, 650);
		monster5.y = RND->getFromFloatTo(130, 470);
		monster5._monster = IMAGEMANAGER->findImage("얼굴달린몬스터몸");
		monster5.frameHerd = 0;
		monster5.impact = false;
		_vMonster[4].push_back({ monster5 });
	}
	if (KEYMANAGER->isOnceKeyDown('6'))
	{
		MonsterInformation monster6;

		monster6.angle = 0;
		monster6.atk = 0.5f;
		monster6.atkSpeed = 0.0f;
		monster6.direction = RND->getInt(4);
		monster6.frameTime = 0;
		monster6.frameX = 0;
		monster6.frameY = 0;
		monster6.hp = 8.0f;
		monster6.move = false;
		monster6.speed = 0.3f;
		monster6.x = RND->getFromFloatTo(80, 650);
		monster6.y = RND->getFromFloatTo(130, 470);
		monster6._monster = IMAGEMANAGER->findImage("얼굴만남은몬스터");
		monster6.frameHerd = 0;
		monster6.impact = false;
		monster6.rnd = 0;
		monster6.atktrue = false;
		_vMonster[5].push_back({ monster6 });
	}
	if (KEYMANAGER->isOnceKeyDown('7'))
	{
		MonsterInformation monster7;

		monster7.angle = 0;
		monster7.atk = 0.5f;
		monster7.atkSpeed = 0;
		monster7.direction = 0;
		monster7.frameTime = 0;
		monster7.frameX = 0;
		monster7.frameY = 0;
		monster7.hp = 8.0f;
		monster7.move = false;
		monster7.speed = RND->getFromFloatTo(2.55f, 4.75f);
		monster7.x = RND->getFromFloatTo(80, 650);
		monster7.y = RND->getFromFloatTo(130, 470);
		monster7._monster = IMAGEMANAGER->findImage("방패몬스터");
		monster7.frameHerd = 0;
		monster7.impact = false;
		monster7.rnd = 0;
		monster7.atktrue = false;
		_vMonster[6].push_back({ monster7 });
	}


	if (KEYMANAGER->isOnceKeyDown('8'))
	{
		MonsterInformation boss0;

		boss0.angle = 0;
		boss0.atk = 0.5f;
		boss0.atkSpeed = 0;
		boss0.direction = 0;
		boss0.frameTime = 6;
		boss0.frameX = 0;
		boss0.frameY = 0;
		boss0.hp = 60.0f;
		boss0.move = false;
		boss0.speed = RND->getFromFloatTo(1.5f, 2.5f);
		boss0.x = RND->getFromFloatTo(80, 650);
		boss0.y = RND->getFromFloatTo(130, 470);
		boss0._monster = IMAGEMANAGER->findImage("boss0");
		boss0.frameHerd = 0;
		boss0.impact = false;
		boss0.rnd = RND->getInt(4);
		boss0.atktrue = false;
		boss0.alpha = 255;
		boss0.a = 0;
		boss0.b = 0;
		boss0.die = false;
		_vMonster[7].push_back({ boss0 });
	}
	if (KEYMANAGER->isOnceKeyDown('9'))
	{
		MonsterInformation boss1;

		boss1.atk = 0.5f;
		boss1.atkSpeed = 0;
		boss1.direction = 0;
		boss1.frameTime = 0;
		boss1.frameX = 0;
		boss1.frameY = 0;
		boss1.hp = 60.0f;
		boss1.move = true;
		boss1.speed = 1.25f;
		boss1.x = RND->getFromFloatTo(80, 650);
		boss1.y = RND->getFromFloatTo(130, 470);
		boss1._monster = IMAGEMANAGER->findImage("boss1");
		boss1.frameHerd = 0;
		boss1.impact = false;
		boss1.rnd = RND->getInt(4);
		boss1.atktrue = false;
		boss1.alpha = 255;
		boss1.a = 0;
		boss1.b = 0;
		boss1.c = 0;
		boss1.die = false;
		boss1.angle = getAngle(boss1.x, boss1.y, (_playerInformation.rc.right + _playerInformation.rc.left) / 2 - 50,
			(_playerInformation.rc.bottom + _playerInformation.rc.top) / 2 - 50);
		_vMonster[8].push_back({ boss1 });

		MonsterInformation boss2;

		boss2.atk = 0.5f;
		boss2.atkSpeed = 0;
		boss2.direction = 0;
		boss2.frameTime = 6;
		boss2.frameX = 0;
		boss2.frameY = 0;
		boss2.hp = 60.0f;
		boss2.move = true;
		boss2.speed = 1.35f;
		boss2.x = _vMonster[8][0].x;
		boss2.y = _vMonster[8][0].y;
		boss2._monster = IMAGEMANAGER->findImage("보스1쫄");
		boss2.frameHerd = 0;
		boss2.impact = false;
		boss2.rnd = RND->getInt(4);
		boss2.atktrue = false;
		boss2.alpha = 255;
		boss2.a = 0;
		boss2.b = 0;
		boss2.c = 0;
		boss2.die = false;
		boss2.angle = 0;
		_vMonster[9].push_back({ boss2 });

	}
#pragma endregion


	if (KEYMANAGER->isOnceKeyDown('0'))
	{
		MonsterInformation boss3;

		boss3.angle = 0;
		boss3.atk = 0.5f;
		boss3.atkSpeed = 0;
		boss3.direction = 0;
		boss3.frameTime = 6;
		boss3.frameX = 0;
		boss3.frameY = 0;
		boss3.hp = 60.0f;
		boss3.move = false;
		boss3.speed =2.0f;
		boss3.x = RND->getFromFloatTo(80, 650);
		boss3.y = RND->getFromFloatTo(130, 470);
		boss3._monster = IMAGEMANAGER->findImage("보스2");
		boss3.frameHerd = 0;
		boss3.impact = false;
		boss3.rnd = RND->getInt(4);
		boss3.atktrue = false;
		boss3.alpha = 255;
		boss3.a = 0;
		boss3.b = 0;
		boss3.c = 0;
		boss3.die = false;
		_vMonster[10].push_back({ boss3 });

		MonsterInformation boss4;

		boss4.angle = 0;
		boss4.atk = 0.5f;
		boss4.atkSpeed = 0;
		boss4.direction = 0;
		boss4.frameTime = 6;
		boss4.frameX = 0;
		boss4.frameY = 0;
		boss4.hp = 60.0f;
		boss4.move = false;
		boss4.speed = 2.0f;
		boss4.x = RND->getFromFloatTo(80, 650);
		boss4.y = RND->getFromFloatTo(130, 470);
		boss4._monster = IMAGEMANAGER->findImage("Heart");
		boss4.frameHerd = 0;
		boss4.impact = false;
		boss4.rnd = RND->getInt(4);
		boss4.atktrue = false;
		boss4.alpha = 255;
		boss4.a = 0;
		boss4.b = 0;
		boss4.c = 0;
		boss4.die = false;
		_vMonster[11].push_back({ boss4 });
	}

	if (KEYMANAGER->isOnceKeyDown('F'))
	{
		MonsterInformation mogi;

	    mogi.atk = 0.5f;
	    mogi.atkSpeed = 0;
	    mogi.direction = 0;
	    mogi.frameTime = 6;
	    mogi.frameX = 0;
	    mogi.frameY = 0;
	    mogi.hp = 5.0f;
	    mogi.move = true;
	    mogi.speed = 1.35f;
	    mogi.x = _ptMouse.x;
	    mogi.y = _ptMouse.y;
	    mogi._monster = IMAGEMANAGER->findImage("모기몬스터");
	    mogi.frameHerd = 0;
	    mogi.impact = false;
	    mogi.rnd = RND->getInt(4);
	    mogi.atktrue = false;
	    mogi.alpha = 255;
	    mogi.a = 0;
	    mogi.b = 0;
	    mogi.c = 0;
	    mogi.die = false;
	    mogi.angle = 0;
		_vMonster[12].push_back({ mogi });
	}
	//보스3
	if (KEYMANAGER->isOnceKeyDown('G'))
	{
		MonsterInformation mogi;

		mogi.atk = 0.5f;
		mogi.atkSpeed = 0;
		mogi.direction = 0;
		mogi.frameTime = 6;
		mogi.frameX = 0;
		mogi.frameY = 0;
		mogi.hp = 60.0f;
		mogi.move = true;
		mogi.speed = 3.1f;
		mogi.x = _ptMouse.x;
		mogi.y = _ptMouse.y;
		mogi._monster = IMAGEMANAGER->findImage("보스3");
		mogi.frameHerd = 0;
		mogi.impact = false;
		mogi.rnd = 0;   /*RND->getInt(3)*/
		mogi.atktrue = false;
		mogi.alpha = 255;
		mogi.a = 0;
		mogi.b = 0;
		mogi.c = getAngle(mogi.x, mogi.y,
			(_playerInformation.rc.right + _playerInformation.rc.left) / 2 - 50, (_playerInformation.rc.bottom + _playerInformation.rc.top) / 2 - 50);;
		mogi.die = false;
		mogi.angle = 0;
		_vMonster[13].push_back({ mogi });
	}
#pragma region 몬스터들
	//점프몬스터
	for (int i = 0; i < _vMonster[0].size(); i++)
	{
		_vMonster[0][i].rc = RectMake(_vMonster[0][i].x+13, _vMonster[0][i].y+35, 42, 40);
		if (IntersectRect(&_impact, &cameraImpactrc, &_vMonster[0][i].rc))
		{
		if (_vMonster[0][i].move)
		{
			_vMonster[0][i].frameTime += TIMEMANAGER->getElapsedTime();

			if (_vMonster[0][i].frameTime > 0.12f)
			{
				_vMonster[0][i].frameTime = 0;

				_vMonster[0][i].frameX++;
				if (_vMonster[0][i].frameX >= 11)
				{
					_vMonster[0][i].frameX = 0;
					_vMonster[0][i].move = false;
				}
			}
		}

		if (!_vMonster[0][i].move)
		{
			_vMonster[0][i].frameTime += TIMEMANAGER->getElapsedTime();
			if (_vMonster[0][i].frameTime > 0.6f)
			{
				_vMonster[0][i].frameTime = 0;
				_vMonster[0][i].move = true;
			}
		}
		
		//몬스터들끼리 밀어냄
		for (int j = i+1; j < _vMonster[0].size(); j++)
		{
			if (IntersectRect(&_impact, &_vMonster[0][i].rc, &_vMonster[0][j].rc))
			{
				if ((_vMonster[0][i].rc.right + _vMonster[0][i].rc.left) / 2 > _vMonster[0][j].rc.left)
				{
					_vMonster[0][i].x += 3.0f;
					_vMonster[0][j].x -= 3.0f;
				}
				if ((_vMonster[0][i].rc.right + _vMonster[0][i].rc.left) / 2 < _vMonster[0][j].rc.right)
				{
					_vMonster[0][i].x -= 3.0f;
					_vMonster[0][j].x += 3.0f;
				}
				if ((_vMonster[0][i].rc.bottom + _vMonster[0][i].rc.top) / 2 > _vMonster[0][j].rc.top)
				{
					_vMonster[0][i].y += 3.0f;
					_vMonster[0][j].y -= 3.0f;
				}
				if ((_vMonster[0][i].rc.bottom + _vMonster[0][i].rc.top) / 2 < _vMonster[0][j].rc.bottom)
				{
					_vMonster[0][i].y -= 3.0f;
					_vMonster[0][j].y += 3.0f;
				}
			}
		}

		if (_vMonster[0][i].frameX > 5 && _vMonster[0][i].move)
		{
			if (_playerInformation.rc.left + _playerInformation.rc.right - _playerInformation.rc.left - 62 < _vMonster[0][i].x)
			{
				_vMonster[0][i].x -= _vMonster[0][i].speed;
			}
			else _vMonster[0][i].x += _vMonster[0][i].speed;

			if (_playerInformation.rc.top + _playerInformation.rc.bottom - _playerInformation.rc.top - 80 > _vMonster[0][i].y)
			{
				_vMonster[0][i].y += _vMonster[0][i].speed;
			}
			else _vMonster[0][i].y -= _vMonster[0][i].speed;
		}
	



		if (_vMonster[0][i].hp <= 0)
		{
			//죽은 몬스터피
			_blood.push_back({ _vMonster[0][i].x ,_vMonster[0][i].y,0 });

			_vMonster[0].erase(_vMonster[0].begin()+i);
		}

		}
		
	}

	//머리없는 몸통몬스터
	for (int i = 0; i < _vMonster[1].size(); i++)
	{	
		
		_vMonster[1][i].rc = RectMake(_vMonster[1][i].x + 18, _vMonster[1][i].y + 31, 28, 30);
		if (IntersectRect(&_impact, &cameraImpactrc, &_vMonster[1][i].rc))
		{
		    _vMonster[1][i].frameTime += TIMEMANAGER->getElapsedTime();
		    
		    _vMonster[1][i].atkSpeed += TIMEMANAGER->getElapsedTime();
		    if (_vMonster[1][i].atkSpeed >= 5.0f)
		    {
		    
		    	//몬스터 볼렛
		    	Monsterbullet ww;
		    	ww.atk = 0.5f;
		    	ww.x = _vMonster[1][i].x;
		    	ww.y = _vMonster[1][i].y;
		    	ww.frameXTime = 0;
		    	ww.frameX = 0;
		    	ww.atkTime = 0;
		    	ww.direction = RND->getInt(2);
		    	ww.impact = false;
		    	ww.impactTime = RND->getFromFloatTo(1.7f, 2.0f);
		    	ww.angle = 0;
		    	ww.angleRnd = RND->getFromFloatTo(20.0f, 50.0f);
		    
		    	_vMonster[1][i].atkSpeed = 0;
		    	_monsterbullet.push_back(ww);
		    }
		    
		    if (_vMonster[1][i].frameTime > 0.12f)
		    {			  
		    	_vMonster[1][i].frameTime = 0;
		    			  
		    	_vMonster[1][i].frameX++;
		    	if (_vMonster[1][i].frameX >= 4)_vMonster[1][i].frameX = 0;
		    }
		    
		    //몬스터들끼리 밀어냄
		    for (int j = i + 1; j < _vMonster[1].size(); j++)
		    {
		    	if (IntersectRect(&_impact, &_vMonster[1][i].rc, &_vMonster[1][j].rc))
		    	{
		    		if ((_vMonster[1][i].rc.right + _vMonster[1][i].rc.left) / 2 > _vMonster[1][j].rc.left)
		    		{
		    			_vMonster[1][j].x -= 3.0f;
		    		}
		    		if ((_vMonster[1][i].rc.right + _vMonster[1][i].rc.left) / 2 < _vMonster[1][j].rc.right)
		    		{
		    			_vMonster[1][j].x += 3.0f;
		    		}
		    		if ((_vMonster[1][i].rc.bottom + _vMonster[1][i].rc.top) / 2 > _vMonster[1][j].rc.top)
		    		{
		    			_vMonster[1][j].y -= 3.0f;
		    		}
		    		if ((_vMonster[1][i].rc.bottom + _vMonster[1][i].rc.top) / 2 < _vMonster[1][j].rc.bottom)
		    		{
		    			_vMonster[1][j].y += 3.0f;
		    		}
		    		_vMonster[1][i].direction = RND->getFromIntTo(0, 4);
		    	}
		    }
		    
		    _vMonster[1][i].angle += TIMEMANAGER->getElapsedTime();
		    
		    if (_vMonster[1][i].angle >= 2.0f)
		    {
		    	_vMonster[1][i].direction = RND->getFromIntTo(0, 4);
		    	_vMonster[1][i].angle = 0;
		    }
		    
		    if (_vMonster[1][i].direction == 0)
		    {
		    	_vMonster[1][i].frameY = 0;
		    	
		    	
		    	if(_map.right > _vMonster[1][i].rc.right)_vMonster[1][i].x += _vMonster[1][i].speed;
		    	if(_map.bottom > _vMonster[1][i].rc.bottom)_vMonster[1][i].y += _vMonster[1][i].speed;
		    	
		    }
		    if (_vMonster[1][i].direction == 1)
		    {
		    	_vMonster[1][i].frameY = 1;
		    	if (IntersectRect(&_impact, &_vMonster[1][i].rc, &_map))
		    	{
		    		if (_map.left < _vMonster[1][i].rc.left)  _vMonster[1][i].x -= _vMonster[1][i].speed;
		    		if (_map.top < _vMonster[1][i].rc.top)_vMonster[1][i].y -= _vMonster[1][i].speed;
		    	}
		    }
		    if (_vMonster[1][i].direction == 2)
		    {
		    	_vMonster[1][i].frameY = 1;
		    	if (IntersectRect(&_impact, &_vMonster[1][i].rc, &_map))
		    	{
		    		if (_map.left < _vMonster[1][i].rc.left)  _vMonster[1][i].x -= _vMonster[1][i].speed;
		    		if (_map.bottom > _vMonster[1][i].rc.bottom)_vMonster[1][i].y += _vMonster[1][i].speed;
		    	}
		    }
		    if (_vMonster[1][i].direction == 3)
		    {
		    	_vMonster[1][i].frameY = 0;
		    	if (IntersectRect(&_impact, &_vMonster[1][i].rc, &_map))
		    	{
		    		if (_map.right > _vMonster[1][i].rc.right)  _vMonster[1][i].x += _vMonster[1][i].speed;
		    		if (_map.top < _vMonster[1][i].rc.top)_vMonster[1][i].y -= _vMonster[1][i].speed;
		    	}
		    }
		    
		    
		    if (_vMonster[1][i].hp <= 0)
		    {
		    	//몬스터피
		    	_blood.push_back({ _vMonster[1][i].x ,_vMonster[1][i].y,0 });
		    
		    	_vMonster[1].erase(_vMonster[1].begin() + i);
		    }
		}

	}

	//날벌레
	for (int i = 0; i < _vMonster[2].size(); i++)
	{
		_vMonster[2][i].rc = RectMake(_vMonster[2][i].x + 24, _vMonster[2][i].y + 22, 15, 16);
		if (IntersectRect(&_impact, &cameraImpactrc, &_vMonster[2][i].rc))
		{
		    _vMonster[2][i].frameTime += TIMEMANAGER->getElapsedTime();
		    
		    if (_vMonster[2][i].frameTime > 0.12f)
		    {
		    	_vMonster[2][i].frameTime = 0;
		    
		    	_vMonster[2][i].frameX++;
		    	if (_vMonster[2][i].frameX >= 3)_vMonster[2][i].frameX = 0;
		    
		    }
		    
		    //몬스터들끼리 밀어냄
		    for (int j = i + 1; j < _vMonster[2].size(); j++)
		    {
		    	if (IntersectRect(&_impact, &_vMonster[2][i].rc, &_vMonster[2][j].rc))
		    	{
		    		if ((_vMonster[2][i].rc.right + _vMonster[2][i].rc.left) / 2 > _vMonster[2][j].rc.left)
		    		{
		    			_vMonster[2][i].x += 3.0f;
		    			_vMonster[2][j].x -= 3.0f;
		    		}
		    		if ((_vMonster[2][i].rc.right + _vMonster[2][i].rc.left) / 2 < _vMonster[2][j].rc.right)
		    		{
		    			_vMonster[2][i].x -= 3.0f;
		    			_vMonster[2][j].x += 3.0f;
		    		}
		    		if ((_vMonster[2][i].rc.bottom + _vMonster[2][i].rc.top) / 2 > _vMonster[2][j].rc.top)
		    		{
		    			_vMonster[2][i].y += 3.0f;
		    			_vMonster[2][j].y -= 3.0f;
		    		}
		    		if ((_vMonster[2][i].rc.bottom + _vMonster[2][i].rc.top) / 2 < _vMonster[2][j].rc.bottom)
		    		{
		    			_vMonster[2][i].y -= 3.0f;
		    			_vMonster[2][j].y += 3.0f;
		    		}
		    	}
		    }
		    
		    _vMonster[2][i].direction += TIMEMANAGER->getElapsedTime();
		    
		    if (_vMonster[2][i].direction > 2.0f)
		    {
		    	if (_playerInformation.rc.left + _playerInformation.rc.right - _playerInformation.rc.left - 43 < _vMonster[2][i].x)
		    	{
		    		_vMonster[2][i].x -= _vMonster[2][i].speed;
		    	}
		    	else _vMonster[2][i].x += _vMonster[2][i].speed;
		    
		    	if (_playerInformation.rc.top + _playerInformation.rc.bottom - _playerInformation.rc.top - 45 > _vMonster[2][i].y)
		    	{
		    		_vMonster[2][i].y += _vMonster[2][i].speed;
		    	}
		    	else _vMonster[2][i].y -= _vMonster[2][i].speed;
		    
		    	if (_vMonster[2][i].direction > 5)	_vMonster[2][i].direction = 0;
		    }
		    
		    
		    if (_vMonster[2][i].hp <= 0)
		    {
		    	//몬스터피
		    	_blood.push_back({ _vMonster[2][i].x ,_vMonster[2][i].y,0 });
		    
		    	_vMonster[2].erase(_vMonster[2].begin() + i);
		    }


		}
	}

	//지렁이
	for (int i = 0; i < _vMonster[3].size(); i++)
	{
		_vMonster[3][i].rc = RectMake(_vMonster[3][i].x + 9, _vMonster[3][i].y + 16, 30, 22);

		if (IntersectRect(&_impact, &cameraImpactrc, &_vMonster[3][i].rc))
		{
		    _vMonster[3][i].frameTime += TIMEMANAGER->getElapsedTime();
		    
		    if (_vMonster[3][i].frameTime > 0.35f)
		    {
		    	_vMonster[3][i].frameTime = 0;
		    	_vMonster[3][i].frameX++;
		    	if (_vMonster[3][i].frameX >= 7)_vMonster[3][i].frameX = 0;
		    }
		    
		    if (_vMonster[3][i].frameX <= 3)
		    {
		    	_vMonster[3][i].y -= 0.15f;
		    }
		    else _vMonster[3][i].y += 0.15f;
		    
		    //몬스터들끼리 밀어냄
		    for (int j = i + 1; j < _vMonster[3].size(); j++)
		    {
		    	if (IntersectRect(&_impact, &_vMonster[3][i].rc, &_vMonster[3][j].rc))
		    	{
		    		if ((_vMonster[3][i].rc.right + _vMonster[3][i].rc.left) / 2 > _vMonster[3][j].rc.left)
		    		{
		    			_vMonster[3][i].x += 3.0f;
		    			_vMonster[3][j].x -= 3.0f;
		    		}
		    		if ((_vMonster[3][i].rc.right + _vMonster[3][i].rc.left) / 2 < _vMonster[3][j].rc.right)
		    		{
		    			_vMonster[3][i].x -= 3.0f;
		    			_vMonster[3][j].x += 3.0f;
		    		}
		    		if ((_vMonster[3][i].rc.bottom + _vMonster[3][i].rc.top) / 2 > _vMonster[3][j].rc.top)
		    		{
		    			_vMonster[3][i].y += 3.0f;
		    			_vMonster[3][j].y -= 3.0f;
		    		}
		    		if ((_vMonster[3][i].rc.bottom + _vMonster[3][i].rc.top) / 2 < _vMonster[3][j].rc.bottom)
		    		{
		    			_vMonster[3][i].y -= 3.0f;
		    			_vMonster[3][j].y += 3.0f;
		    		}
		    		_vMonster[3][i].direction = RND->getFromIntTo(0, 4);
		    	}
		    }
		    
		    
		    if (_vMonster[3][i].frameX==0)
		    {
		    	_vMonster[3][i].direction = RND->getFromIntTo(0, 4);
		    	_vMonster[3][i].frameX = +1;
		    }
		    
		    if (_vMonster[3][i].direction == 0)
		    {
		    	_vMonster[3][i].frameY = 0;
		    
		    	if (_vMonster[3][i].frameX != 0 && IntersectRect(&_impact, &_vMonster[3][i].rc, &_map))
		    	{
		    		if (_map.right > _vMonster[3][i].rc.right)_vMonster[3][i].x += _vMonster[3][i].speed;
		    		if (_map.bottom > _vMonster[3][i].rc.bottom)_vMonster[3][i].y += _vMonster[3][i].speed;
		    	}
		    }
		    if (_vMonster[3][i].direction == 1)
		    {
		    	_vMonster[3][i].frameY = 1;
		    	if (_vMonster[3][i].frameX != 0 && IntersectRect(&_impact, &_vMonster[3][i].rc, &_map))
		    	{
		    		if (_map.left < _vMonster[3][i].rc.left)  _vMonster[3][i].x -= _vMonster[3][i].speed;
		    		if (_map.top < _vMonster[3][i].rc.top)_vMonster[3][i].y -= _vMonster[3][i].speed;
		    	}
		    }
		    if (_vMonster[3][i].direction == 2)
		    {
		    	_vMonster[3][i].frameY = 1;
		    	if (_vMonster[3][i].frameX != 0 && IntersectRect(&_impact, &_vMonster[3][i].rc, &_map))
		    	{
		    		if (_map.left < _vMonster[3][i].rc.left)  _vMonster[3][i].x -= _vMonster[3][i].speed;
		    		if (_map.bottom > _vMonster[3][i].rc.bottom)_vMonster[3][i].y += _vMonster[3][i].speed;
		    	}
		    }
		    if (_vMonster[3][i].direction == 3)
		    {
		    	_vMonster[3][i].frameY = 0;
		    	if (_vMonster[3][i].frameX != 0 && IntersectRect(&_impact, &_vMonster[3][i].rc, &_map))
		    	{
		    		if (_map.right > _vMonster[3][i].rc.right)  _vMonster[3][i].x += _vMonster[3][i].speed;
		    		if (_map.top < _vMonster[3][i].rc.top)_vMonster[3][i].y -= _vMonster[3][i].speed;
		    	}
		    }
		    
		    
		    if (_vMonster[3][i].hp <= 0)
		    {
		    	//몬스터피
		    	_blood.push_back({ _vMonster[3][i].x ,_vMonster[3][i].y,0 });
		    
		    	_vMonster[3].erase(_vMonster[3].begin() + i);
		    }

		}
	}

	//플레이어머리달린몬스터
	for (int i = 0; i < _vMonster[4].size(); i++)
	{
		_vMonster[4][i].rc = RectMake(_vMonster[4][i].x + 17, _vMonster[4][i].y - 10, 23, 45);
		if (IntersectRect(&_impact, &cameraImpactrc, &_vMonster[4][i].rc))
		{
			if (!_vMonster[4][i].impact)
			{

				if (_vMonster[4][i].move)
				{
					_vMonster[4][i].frameTime += TIMEMANAGER->getElapsedTime();

					if (_vMonster[4][i].frameTime > 0.12f)
					{
						_vMonster[4][i].frameTime = 0;

						_vMonster[4][i].frameX++;
						if (_vMonster[4][i].frameX >= 8)
						{
							_vMonster[4][i].frameX = 0;
							_vMonster[4][i].move = false;
						}
					}
				}

				if (!_vMonster[4][i].move)
				{
					_vMonster[4][i].frameTime += TIMEMANAGER->getElapsedTime();
					if (_vMonster[4][i].frameTime > 0.6f)
					{
						_vMonster[4][i].frameTime = 0;
						_vMonster[4][i].move = true;
					}
				}


				_vMonster[4][i].angle += TIMEMANAGER->getElapsedTime();

				if (_vMonster[4][i].angle >= 2.0f)
				{
					_vMonster[4][i].direction = RND->getFromIntTo(0, 4);
					_vMonster[4][i].angle = 0;
				}

				if (_vMonster[4][i].direction == 0)
				{
					_vMonster[4][i].frameY = 0;


					if (_map.right > _vMonster[4][i].rc.right)_vMonster[4][i].x += _vMonster[4][i].speed;
					if (_map.bottom > _vMonster[4][i].rc.bottom)_vMonster[4][i].y += _vMonster[4][i].speed;

				}
				if (_vMonster[4][i].direction == 1)
				{
					_vMonster[4][i].frameY = 1;
					if (IntersectRect(&_impact, &_vMonster[4][i].rc, &_map))
					{
						if (_map.left < _vMonster[4][i].rc.left)  _vMonster[4][i].x -= _vMonster[4][i].speed;
						if (_map.top < _vMonster[4][i].rc.top)_vMonster[4][i].y -= _vMonster[4][i].speed;
					}
				}
				if (_vMonster[4][i].direction == 2)
				{
					_vMonster[4][i].frameY = 1;
					if (IntersectRect(&_impact, &_vMonster[4][i].rc, &_map))
					{
						if (_map.left < _vMonster[4][i].rc.left)  _vMonster[4][i].x -= _vMonster[4][i].speed;
						if (_map.bottom > _vMonster[4][i].rc.bottom)_vMonster[4][i].y += _vMonster[4][i].speed;
					}
				}
				if (_vMonster[4][i].direction == 3)
				{
					_vMonster[4][i].frameY = 0;
					if (IntersectRect(&_impact, &_vMonster[4][i].rc, &_map))
					{
						if (_map.right > _vMonster[4][i].rc.right)  _vMonster[4][i].x += _vMonster[4][i].speed;
						if (_map.top < _vMonster[4][i].rc.top)_vMonster[4][i].y -= _vMonster[4][i].speed;
					}
				}
			}
			if (_vMonster[4][i].impact)
			{
				_vMonster[4][i].frameTime += TIMEMANAGER->getElapsedTime();

				if (_vMonster[4][i].frameTime > 0.2f)
				{
					_vMonster[4][i].frameTime = 0;

					if (_vMonster[4][i].frameHerd < 4)_vMonster[4][i].frameHerd++;

					_vMonster[4][i].frameX++;
					if (_vMonster[4][i].frameX >= 8)
					{
						_vMonster[4][i].frameX = 0;
						_vMonster[4][i].move = false;
					}
				}

				//플레이어 따라감
				if (_playerInformation.rc.left + _playerInformation.rc.right - _playerInformation.rc.left - 62 < _vMonster[4][i].x)
				{
					_vMonster[4][i].frameY = 1;
					_vMonster[4][i].x -= _vMonster[4][i].speed;
				}
				else
				{
					_vMonster[4][i].frameY = 0;
					_vMonster[4][i].x += _vMonster[4][i].speed;
				}
				if (_playerInformation.rc.top + _playerInformation.rc.bottom - _playerInformation.rc.top - 40 > _vMonster[4][i].y)
				{
					_vMonster[4][i].y += _vMonster[4][i].speed;
				}
				else _vMonster[4][i].y -= _vMonster[4][i].speed;

			}

			//몬스터들끼리 밀어냄
			for (int j = i + 1; j < _vMonster[4].size(); j++)
			{
				if (IntersectRect(&_impact, &_vMonster[4][i].rc, &_vMonster[4][j].rc))
				{
					if ((_vMonster[4][i].rc.right + _vMonster[4][i].rc.left) / 2 > _vMonster[4][j].rc.left)
					{
						_vMonster[4][i].x += 3.0f;
						_vMonster[4][j].x -= 3.0f;
					}
					if ((_vMonster[4][i].rc.right + _vMonster[4][i].rc.left) / 2 < _vMonster[4][j].rc.right)
					{
						_vMonster[4][i].x -= 3.0f;
						_vMonster[4][j].x += 3.0f;
					}
					if ((_vMonster[4][i].rc.bottom + _vMonster[4][i].rc.top) / 2 > _vMonster[4][j].rc.top)
					{
						_vMonster[4][i].y += 3.0f;
						_vMonster[4][j].y -= 3.0f;
					}
					if ((_vMonster[4][i].rc.bottom + _vMonster[4][i].rc.top) / 2 < _vMonster[4][j].rc.bottom)
					{
						_vMonster[4][i].y -= 3.0f;
						_vMonster[4][j].y += 3.0f;
					}
					_vMonster[4][i].direction = RND->getFromIntTo(0, 4);
				}
			}

			_vMonster[4][i].plrc = RectMakeCenter(_vMonster[4][i].x + 30, _vMonster[4][i].y + 5, 350, 300);
			if (_vMonster[4][i].hp <= 0)
			{
				//몬스터피
				_blood.push_back({ _vMonster[4][i].x ,_vMonster[4][i].y,0 });

				_vMonster[4][i].rnd = RND->getInt(10);

				if (_vMonster[4][i].rnd > 7)_vMonster[1].push_back({ _vMonster[4][i].x, _vMonster[4][i].y, 0, 0.5f, 6.0f, 0.5f,0,0,IMAGEMANAGER->findImage("몸만남은몬스터"),0,0,false,0 });

				_vMonster[4].erase(_vMonster[4].begin() + i);
			}
		}
	}
	

	//얼굴만 남은몬스터
	for (int i = 0; i < _vMonster[5].size(); i++)
	{

		_vMonster[5][i].rc = RectMake(_vMonster[5][i].x + 5, _vMonster[5][i].y +12, 38, 30);

		if (IntersectRect(&_impact, &cameraImpactrc, &_vMonster[5][i].rc))
		{

			if (!_vMonster[5][i].move)
			{
				_vMonster[5][i].direction += TIMEMANAGER->getElapsedTime();

				if (_vMonster[5][i].direction <= 0.1f)
				{
					_vMonster[5][i].x++;
				}
				else
				{
					_vMonster[5][i].x--;

					if (_vMonster[5][i].direction >= 0.16f)
					{
						_vMonster[5][i].direction = 0;

						if (_vMonster[5][i].atktrue)_vMonster[5][i].rnd++;

						if (_vMonster[5][i].rnd >= 10)
						{
							_vMonster[5][i].rnd = 0;
							_vMonster[5][i].move = true;
						}
					}
				}
			}
			if (_vMonster[5][i].move)
			{
				_vMonster[5][i].atkSpeed += TIMEMANAGER->getElapsedTime();
				if (_vMonster[5][i].atkSpeed > 0.12f)
				{
					_vMonster[5][i].atkSpeed = 0;
					_vMonster[5][i].frameX++;
					if (_vMonster[5][i].frameX >= 4)
					{
						_vMonster[5][i].move = false;
						_vMonster[5][i].impact = true;
					}
				}
			}

			if (_vMonster[5][i].impact)
			{
				_vMonster[5][i].impact = false;
				_vMonster[5][i].frameX = 0;

				Monsterbullet bul;
				bul.atk = 0.5f;
				bul.x = _vMonster[5][i].x - 22;
				bul.y = _vMonster[5][i].y - 15;
				bul.frameXTime = 0;
				bul.frameX = 0;
				bul.atkTime = 0;
				bul.direction = RND->getInt(2);
				bul.impact = false;
				bul.impactTime = RND->getFromFloatTo(1.7f, 2.0f);
				bul.angle = getAngle(bul.x, bul.y,
					(_playerInformation.rc.right + _playerInformation.rc.left) / 2 - 50, (_playerInformation.rc.bottom + _playerInformation.rc.top) / 2 - 50);

				bul.angleRnd = RND->getFromFloatTo(20.0f, 50.0f);

				_monsterbullet1.push_back(bul);

			}

			_vMonster[5][i].plrc = RectMakeCenter(_vMonster[5][i].x + 40, _vMonster[5][i].y + 35, 500, 480);
			if (_vMonster[5][i].hp <= 0)
			{
				//몬스터피
				_blood.push_back({ _vMonster[5][i].x ,_vMonster[5][i].y,0 });

				_vMonster[5].erase(_vMonster[5].begin() + i);
			}
		}
	}
	
	// 방패몬스터
	for (int i = 0; i < _vMonster[6].size(); i++)
	{
		if (_vMonster[6][i].frameX == 2)_vMonster[6][i].rc = RectMake(_vMonster[6][i].x + 5, _vMonster[6][i].y +40, 38, 60);
		else _vMonster[6][i].rc = RectMake(_vMonster[6][i].x + 5, _vMonster[6][i].y + 70, 38, 30);

		if (IntersectRect(&_impact, &cameraImpactrc, &_vMonster[6][i].rc))
		{

			if (_vMonster[6][i].frameX == 0)
			{
				_vMonster[6][i].atkSpeed += TIMEMANAGER->getElapsedTime();
				if (_vMonster[6][i].atkSpeed > _vMonster[6][i].speed)
				{
					_vMonster[6][i].speed = RND->getFromFloatTo(2.55f, 4.75f);
					if (_vMonster[6][i].impact)_vMonster[6][i].frameX = 1;
					if (_vMonster[6][i].impact)_vMonster[6][i].atktrue = true;
					_vMonster[6][i].atkSpeed = 0;
				}
			}

			if (_vMonster[6][i].atktrue)
			{
				_vMonster[6][i].impact = false;
				_vMonster[6][i].atktrue = false;

				Monsterbullet bu2;
				bu2.atk = 0.5f;
				bu2.x = _vMonster[6][i].x - 22;
				bu2.y = _vMonster[6][i].y - 15;
				bu2.frameXTime = 0;
				bu2.frameX = 0;
				bu2.atkTime = 0;
				bu2.direction = RND->getInt(2);
				bu2.impact = false;
				bu2.impactTime = RND->getFromFloatTo(1.7f, 2.0f);
				bu2.angle = getAngle(bu2.x, bu2.y,
					(_playerInformation.rc.right + _playerInformation.rc.left) / 2 - 50, (_playerInformation.rc.bottom + _playerInformation.rc.top) / 2 - 50);

				bu2.angleRnd = RND->getFromFloatTo(20.0f, 50.0f);

				_monsterbullet1.push_back(bu2);
			}

			if (_vMonster[6][i].frameX == 1)
			{
				_vMonster[6][i].frameTime += TIMEMANAGER->getElapsedTime();
				if (_vMonster[6][i].frameTime > 3.5f && _vMonster[6][i].frameX != 2)
				{
					_vMonster[6][i].frameX = 2;
				}
			}
			else if (_vMonster[6][i].frameX == 2)
			{
				_vMonster[6][i].frameTime += TIMEMANAGER->getElapsedTime();
				if (_vMonster[6][i].frameTime > 3.6f)
				{
					_vMonster[6][i].frameX = 0;
					_vMonster[6][i].frameTime = 0;
				}
			}

			_vMonster[6][i].plrc = RectMakeCenter(_vMonster[6][i].x + 40, _vMonster[6][i].y + 35, 500, 480);

			if (_vMonster[6][i].hp <= 0)
			{
				//몬스터피
				_blood.push_back({ _vMonster[6][i].x ,_vMonster[6][i].y,0 });

				_vMonster[6].erase(_vMonster[6].begin() + i);
			}
		}

	}


	//보스
	for (int i = 0; i < _vMonster[7].size(); i++)
	{
		_vMonster[7][i].rc = RectMake(_vMonster[7][i].x+18, _vMonster[7][i].y, 85, 90);
		if (IntersectRect(&_impact, &cameraImpactrc, &_vMonster[7][i].rc))
		{
			if (!_bossStart)
			{
				if (!_sound)
				{
					SOUNDMANAGER->play("보스방진입", 0.5f);
					_sound = true;
				}
				_bossEnd[1] = true;
				_frameTime += TIMEMANAGER->getElapsedTime();
				if (_frameTime > 0.12f)
				{
					_frameTime = 0;
					_bossGimage[1]->setFrameX(_bossGimage[1]->getFrameX() + 1);
					if (_bossGimage[1]->getFrameX() >= 24)
					{
						_bossStart = true;
						_bossEnd[1] = false;
						SOUNDMANAGER->play("보스방", 0.5f);
						_sound = false;
					}
				}
			}
			if (_bossStart)
			{
				_vMonster[7][i].direction += TIMEMANAGER->getElapsedTime();


				if (_vMonster[7][i].direction > 2.5f)
				{
					_vMonster[7][i].direction = 0;
					_vMonster[7][i].rnd = RND->getInt(4);
				}

				if (_vMonster[7][i].rnd == 0)
				{
					if (_map.left < _vMonster[7][i].rc.left)_vMonster[7][i].x -= 0.35f;
					if (_map.top < _vMonster[7][i].rc.top)_vMonster[7][i].y -= 0.35f;
				}
				if (_vMonster[7][i].rnd == 1)
				{
					if (_map.right > _vMonster[7][i].rc.right)_vMonster[7][i].x += 0.35f;
					if (_map.bottom > _vMonster[7][i].rc.bottom)_vMonster[7][i].y += 0.35f;
				}
				if (_vMonster[7][i].rnd == 2)
				{
					if (_map.left < _vMonster[7][i].rc.left)_vMonster[7][i].x -= 0.35f;
					if (_map.bottom > _vMonster[7][i].rc.bottom)_vMonster[7][i].y += 0.35f;
				}
				if (_vMonster[7][i].rnd == 3)
				{
					if (_map.right > _vMonster[7][i].rc.right)	_vMonster[7][i].x += 0.35f;
					if (_map.top < _vMonster[7][i].rc.top)_vMonster[7][i].y -= 0.35f;
				}


				if (_vMonster[7][i].frameX != 4)
				{
					_vMonster[7][i].frameTime += TIMEMANAGER->getElapsedTime();
					if (_vMonster[7][i].frameTime > 8.5f)
					{
						if (_vMonster[7][i].frameX == 0)_vMonster[7][i].frameX++;
						if (_vMonster[7][i].frameTime > 10.7f && _vMonster[7][i].frameX == 1)_vMonster[7][i].frameX++;
						if (_vMonster[7][i].frameTime > 11.5f && _vMonster[7][i].frameX == 2)_vMonster[7][i].frameX++;
						if (_vMonster[7][i].frameTime > 12.5f && _vMonster[7][i].frameX == 3)
						{
							_vMonster[7][i].frameX++;
							_vMonster[7][i].atktrue = true;
							_vMonster[7][i].rndFly = RND->getFromIntTo(2, 5);
						}
					}
				}

				if (_vMonster[7][i].atktrue)
				{
					_vMonster[7][i].atktrue = false;
					_vMonster[7][i].frameTime = 0;

					for (int f = 0; f < _vMonster[7][i].rndFly; f++)
					{
						MonsterInformation fly;

						fly.angle = RND->getFromFloatTo(78, 102);
						fly.angle2 = 0;
						fly.atk = 0.5f;
						fly.atkSpeed = 0;
						fly.direction = 0;
						fly.frameTime = 0;
						fly.frameX = 0;
						fly.frameY = 0;
						fly.hp = 6.0f;
						fly.move = false;
						fly.speed = 1.0f;
						fly.x = RND->getFromFloatTo(13, 20);
						fly.y = _vMonster[7][i].y + 25;
						fly._monster = IMAGEMANAGER->findImage("날벌레");
						fly.frameHerd = 0;
						fly.impact = false;
						fly.rnd = RND->getInt(4);
						fly.atktrue = false;
						fly.a = 0;
						fly.b = RND->getFromFloatTo(18, 25);

						_vMonster[29].push_back({ fly });
					}
				}
			}

			if (!_vMonster[7][i].atktrue && _vMonster[7][i].frameX == 4)
			{
				_vMonster[7][i].frameTime += TIMEMANAGER->getElapsedTime();
				if (_vMonster[7][i].frameTime > 1.5f)
				{
					_vMonster[7][i].frameX = 0;
				}
			}


			_vMonster[7][i].plrc = RectMakeCenter(_vMonster[7][i].x + 60, _vMonster[7][i].y + 40, 130, 130);



			if (_vMonster[7][i].impact)
			{
				_vMonster[7][i].a += TIMEMANAGER->getElapsedTime();

				_vMonster[7][i].atkSpeed += TIMEMANAGER->getElapsedTime();

				if (_vMonster[7][i].atkSpeed >= 0.1f)
				{
					_vMonster[7][i].atkSpeed = 0;
					if (_vMonster[7][i].alpha == 255)_vMonster[7][i].alpha = 100;
					else _vMonster[7][i].alpha = 255;
				}

				if (_vMonster[7][i].a > 0.3f)
				{
					_vMonster[7][i].impact = false;
				}
			}
			else _vMonster[7][i].alpha = 255;
		}
	}
	
	//보스몬스터 날파리
	for (int i = 0; i < _vMonster[29].size(); i++)
	{
		_vMonster[29][i].rc = RectMake(_vMonster[29][i].x + 15, _vMonster[29][i].y + 14, 20, 20);
		_vMonster[29][i].plrc = RectMakeCenter(_vMonster[29][i].x , _vMonster[29][i].y + 14, 350, 350);

		if (IntersectRect(&_impact, &cameraImpactrc, &_vMonster[29][i].rc))
		{
			_vMonster[29][i].frameTime += TIMEMANAGER->getElapsedTime();

			if (_vMonster[29][i].frameTime > 0.1f)
			{
				_vMonster[29][i].frameTime = 0;
				_vMonster[29][i].frameX++;
				if (_vMonster[29][i].frameX >= 3)_vMonster[29][i].frameX = 0;
			}



			if (!_vMonster[29][i].move && !_vMonster[29][i].impact)
			{
				_vMonster[29][i].atkSpeed += TIMEMANAGER->getElapsedTime();
				_vMonster[29][i].x = cosf((_vMonster[29][i].angle) * PI / 180.0f) * _vMonster[29][i].a + _vMonster[7][0].x + 20;
				_vMonster[29][i].y += 1.5;
				_vMonster[29][i].a++;

				if (_vMonster[29][i].a >= 50)
				{
					_vMonster[29][i].move = true;
					_vMonster[29][i].atkSpeed = 0;
				}
			}

			if (_vMonster[29][i].move)
			{
				_vMonster[29][i].angle2++;

				_vMonster[29][i].x += cosf((_vMonster[29][i].angle2 - _vMonster[29][i].angle) * PI / 180.0f) * 1.4;
				_vMonster[29][i].y += sinf((_vMonster[29][i].angle2 + _vMonster[29][i].angle) * PI / 180.0f) * 1.4;

				if (_vMonster[7][0].rnd == 0)
				{
					if (_map.left < _vMonster[7][0].rc.left) _vMonster[29][i].x -= 0.35f;
					if (_map.top < _vMonster[7][0].rc.top)_vMonster[29][i].y -= 0.35f;
				}
				if (_vMonster[7][0].rnd == 1)
				{
					if (_map.right > _vMonster[7][0].rc.right)_vMonster[29][i].x += 0.35f;
					if (_map.bottom > _vMonster[7][0].rc.bottom)_vMonster[29][i].y += 0.35f;
				}
				if (_vMonster[7][0].rnd == 2)
				{
					if (_map.left < _vMonster[7][0].rc.left)_vMonster[29][i].x -= 0.35f;
					if (_map.bottom > _vMonster[7][0].rc.bottom)_vMonster[29][i].y += 0.35f;
				}
				if (_vMonster[7][0].rnd == 3)
				{
					if (_map.right > _vMonster[7][0].rc.right)_vMonster[29][i].x += 0.35f;
					if (_map.top < _vMonster[7][0].rc.top)_vMonster[29][i].y -= 0.35f;
				}

				if (!IntersectRect(&_impact, &_vMonster[7][0].plrc, &_vMonster[29][i].rc))
				{
					if (_vMonster[7][0].plrc.right < _vMonster[29][i].rc.right)
					{
						_vMonster[29][i].x -= 1.0f;
					}
					if (_vMonster[7][0].plrc.left > _vMonster[29][i].rc.left)
					{
						_vMonster[29][i].x += 1.0f;
					}
					if (_vMonster[7][0].plrc.bottom < _vMonster[29][i].rc.bottom)
					{
						_vMonster[29][i].y -= 1.0f;
					}
					if (_vMonster[7][0].plrc.top > _vMonster[29][i].rc.top)
					{
						_vMonster[29][i].y += 1.0f;
					}
				}
				if (IntersectRect(&_impact, &_vMonster[7][0].rc, &_vMonster[29][i].rc))
				{
					if ((_vMonster[7][0].rc.right + _vMonster[7][0].rc.left) / 2 > _vMonster[29][i].rc.right)
					{
						_vMonster[29][i].x -= 1.0f;
					}
					if ((_vMonster[7][0].rc.right + _vMonster[7][0].rc.left) / 2 < _vMonster[29][i].rc.left)
					{
						_vMonster[29][i].x += 1.0f;
					}
					if ((_vMonster[7][0].rc.bottom + _vMonster[7][0].rc.top) / 2 > _vMonster[29][i].rc.bottom)
					{
						_vMonster[29][i].y -= 1.0f;
					}
					if ((_vMonster[7][0].rc.bottom + _vMonster[7][0].rc.top) / 2 < _vMonster[29][i].rc.top)
					{
						_vMonster[29][i].y += 1.0f;
					}
				}


				if (IntersectRect(&_impact, &_playerInformation.rc, &_vMonster[29][i].plrc)) // 플레이어와 몬스터의 충돌 영역을 확인
				{
						_vMonster[29][i].move = false; // 충돌 시 몬스터의 이동을 멈춤
						_vMonster[29][i].impact = true; // 충돌 상태를 true로 설정
				}
			}

			if (_vMonster[29][i].impact) // 플레이어가 몬스터의 사정거리 안에 들어왔을때
			{
				if (_playerInformation.rc.left + _playerInformation.rc.right - _playerInformation.rc.left - 42 < _vMonster[29][i].x)
				{
					_vMonster[29][i].x -= _vMonster[29][i].speed;
				}
				else
				{
					_vMonster[29][i].x += _vMonster[29][i].speed;
				}
				if (_playerInformation.rc.top + _playerInformation.rc.bottom - _playerInformation.rc.top - 40 > _vMonster[29][i].y)
				{
					_vMonster[29][i].y += _vMonster[29][i].speed;
				}
				else _vMonster[29][i].y -= _vMonster[29][i].speed;
			}

			for (int j = 0; j < _vMonster[29].size(); j++)
			{
				if (IntersectRect(&_impact, &_vMonster[29][i].rc, &_vMonster[29][j].rc))
				{
					if ((_vMonster[29][i].rc.right + _vMonster[29][i].rc.left) / 2 > _vMonster[29][j].rc.left)
					{
						_vMonster[29][i].x += 1.5f;
						_vMonster[29][j].x -= 1.5f;
					}
					if ((_vMonster[29][i].rc.right + _vMonster[29][i].rc.left) / 2 < _vMonster[29][j].rc.right)
					{
						_vMonster[29][i].x -= 1.5f;
						_vMonster[29][j].x += 1.5f;
					}
					if ((_vMonster[29][i].rc.bottom + _vMonster[29][i].rc.top) / 2 > _vMonster[29][j].rc.top)
					{
						_vMonster[29][i].y += 1.5f;
						_vMonster[29][j].y -= 1.5f;
					}
					if ((_vMonster[29][i].rc.bottom + _vMonster[29][i].rc.top) / 2 < _vMonster[29][j].rc.bottom)
					{
						_vMonster[29][i].y -= 1.5f;
						_vMonster[29][j].y += 1.5f;
					}
				}
			}

			if (_vMonster[29][i].hp <= 0)
			{
				//죽은 몬스터피
				_blood3.push_back({ _vMonster[29][i].x ,_vMonster[29][i].y,0 });

				_vMonster[29].erase(_vMonster[29].begin() + i);
			}
		}
	}

	//보스 죽으면 날파리들 다 죽음
	for (int i = 0; i < _vMonster[7].size(); i++)
	{
		if (_vMonster[7][i].hp <= 0)
		{
			//죽은 몬스터피
			_blood.push_back({ _vMonster[7][i].x ,_vMonster[7][i].y,0 });

			//보스 죽으면 날벌레 죽음
			for (int b = 0; b < _vMonster[29].size(); b++)
			{
				_blood3.push_back({ _vMonster[29][b].x - 5 ,_vMonster[29][b].y,0 });

				_vMonster[29].erase(_vMonster[29].begin() + b);
				b--;
			}
			_vMonster[7][i].die = true;

			_bossStart = false;
			_vMonster[7].erase(_vMonster[7].begin() + i);
		}
	}

	//날벌레 피 터짐
	for (int i = 0; i < _blood3.size(); i++)
	{
		_blood3[i].frameXTime += TIMEMANAGER->getElapsedTime();
		if (_blood3[i].frameXTime > 0.2f)
		{
			_blood3[i].frameXTime = 0;
			_blood3[i].frameX++;


			if (_blood3[i].frameX >= 12)
			{
				_blood3.erase(_blood3.begin() + i);
			}

		}
	}

	//보스1
	for (int i = 0; i < _vMonster[8].size(); i++)
	{
		_vMonster[8][i].rc = RectMake(_vMonster[8][i].x + 13, _vMonster[8][i].y + 15, 45, 58);
		
		if (IntersectRect(&_impact, &cameraImpactrc, &_vMonster[8][i].rc))
		{
			if (!_bossStart)
			{
				if (!_sound)
				{
					SOUNDMANAGER->play("보스방진입", 0.5f);
					_sound = true;
				}
				_bossEnd[0] = true;
				_frameTime += TIMEMANAGER->getElapsedTime();
				if (_frameTime > 0.12f)
				{
					_frameTime = 0;
					_bossGimage[0]->setFrameX(_bossGimage[0]->getFrameX() + 1);
					if (_bossGimage[0]->getFrameX() >= 24)
					{
						_bossStart = true;
						_bossEnd[0] = false;
						SOUNDMANAGER->play("보스방", 0.5f);
						_sound = false;
					}
				}
			}
			if (_bossStart)
			{
				if (_vMonster[8][i].move)
				{
					//몬스터위치 삼각함수

					_vMonster[8][i].angle = getAngle(_vMonster[8][i].x, _vMonster[8][i].y, (_playerInformation.rc.right + _playerInformation.rc.left) / 2 - 50,
						(_playerInformation.rc.bottom + _playerInformation.rc.top) / 2 - 50);

					//보스다리
					_vMonster[8][i].b += TIMEMANAGER->getElapsedTime();
					if (_vMonster[8][i].b > 0.1f)
					{
						_vMonster[8][i].b = 0;
						_vMonster[8][i].frameHerd++;
						if (_vMonster[8][i].frameHerd > 8)
						{
							_vMonster[8][i].frameHerd = 0;
						}
					}

					_vMonster[8][i].x += cosf(_vMonster[8][i].angle) * _vMonster[8][i].speed;
					_vMonster[8][i].y -= sinf(_vMonster[8][i].angle) * _vMonster[8][i].speed;

					_vMonster[8][i].frameTime += TIMEMANAGER->getElapsedTime();
					if (_vMonster[8][i].frameTime > 1.1f && _vMonster[8][i].frameX == 0)_vMonster[8][i].frameX = 1;
					if (_vMonster[8][i].frameTime > 3.4f && _vMonster[8][i].frameX == 1)_vMonster[8][i].frameX = 2;
					if (_vMonster[8][i].frameTime > 4.8f && _vMonster[8][i].frameX == 2)_vMonster[8][i].frameX = 3;
					if (_vMonster[8][i].frameTime > 5.2f && _vMonster[8][i].frameX == 3)_vMonster[8][i].frameX = 4;

					if (_vMonster[8][i].frameTime > 7.0f)
					{
						_vMonster[8][i].move = false;
						_vMonster[8][i].frameX = 5;
						_vMonster[8][i].frameTime = 0;
					}
				}
				if (!_vMonster[8][i].move)
				{
					_vMonster[8][i].frameTime += TIMEMANAGER->getElapsedTime();
					_vMonster[8][i].a += TIMEMANAGER->getElapsedTime();
					if (_vMonster[8][i].frameTime > 0.35f)
					{
						_vMonster[8][i].frameTime = 0;
						_vMonster[8][i].frameX++;
						if (_vMonster[8][i].frameX >= 8)
						{
							_vMonster[8][i].frameX = 5;
						}
					}
					if (_vMonster[8][i].a > 3.0f)
					{
						_vMonster[8][i].a = 0;
						_vMonster[8][i].frameTime = 0;
						_vMonster[8][i].frameX = 0;
						_vMonster[8][i].move = true;
					}
				}
			}

				if (_vMonster[8][i].impact)
				{
					_vMonster[8][i].c += TIMEMANAGER->getElapsedTime();

					_vMonster[8][i].atkSpeed += TIMEMANAGER->getElapsedTime();

					if (_vMonster[8][i].atkSpeed >= 0.1f)
					{
						_vMonster[8][i].atkSpeed = 0;
						if (_vMonster[8][i].alpha == 255)_vMonster[8][i].alpha = 100;
						else _vMonster[8][i].alpha = 255;
					}

					if (_vMonster[8][i].c > 0.3f)
					{
						_vMonster[8][i].impact = false;
					}
				}
				else _vMonster[8][i].alpha = 255;

				_vMonster[8][i].plrc = RectMakeCenter(_vMonster[8][i].x + +27, _vMonster[8][i].y + 24, 250, 250);

				for (int j = 0; j < _vMonster[9].size(); j++)
				{
					if (_vMonster[9][j].hp <= 30)
					{
						_vMonster[9][j].frameX = 4;
						_vMonster[9][j].atktrue = true;
						_vMonster[9][j].frameTime = 0;

						_blood.push_back({ _vMonster[8][i].x ,_vMonster[8][i].y,0 });
						_vMonster[8].erase(_vMonster[8].begin() + i);

					}
				}

			
		}

	}

	//보스작은애
	for (int i = 0; i < _vMonster[9].size(); i++)
	{

		_vMonster[9][i].rc = RectMake(_vMonster[9][i].x + 10, _vMonster[9][i].y + 6, 27, 27);

		if (IntersectRect(&_impact, &cameraImpactrc, &_vMonster[9][i].rc))
		{
			if (_bossStart)
			{
				if (!_vMonster[9][i].atktrue)
				{
					_vMonster[9][i].angle = getAngle(_vMonster[9][i].x, _vMonster[9][i].y, _vMonster[8][0].x, _vMonster[8][0].y);

					if (!IntersectRect(&_impact, &_vMonster[9][i].rc, &_vMonster[8][0].plrc))
					{
						_vMonster[9][i].x += cosf(_vMonster[9][i].angle) * _vMonster[9][i].speed;
						_vMonster[9][i].y -= sinf(_vMonster[9][i].angle) * _vMonster[9][i].speed;
					}

					_vMonster[9][i].frameTime += TIMEMANAGER->getElapsedTime();
					if (_vMonster[9][i].frameTime > 0.85f)
					{
						_vMonster[9][i].frameTime = 0;
						_vMonster[9][i].frameX++;
						if (_vMonster[9][i].frameX > 2)
						{

							Monsterbullet bul;
							bul.atk = 0.5f;
							bul.x = _vMonster[9][i].x - 22;
							bul.y = _vMonster[9][i].y - 15;
							bul.frameXTime = 0;
							bul.frameX = 0;
							bul.atkTime = 0;
							bul.direction = RND->getInt(2);
							bul.impact = false;
							bul.impactTime = RND->getFromFloatTo(1.7f, 2.0f);
							bul.angle = getAngle(bul.x, bul.y,
								(_playerInformation.rc.right + _playerInformation.rc.left) / 2 - 50, (_playerInformation.rc.bottom + _playerInformation.rc.top) / 2 - 50);

							bul.angleRnd = RND->getFromFloatTo(20.0f, 50.0f);

							_monsterbullet1.push_back(bul);

							_vMonster[9][i].frameX = 0;

						}
					}

				}
			}

				if ((_playerInformation.rc.left + _playerInformation.rc.right) / 2 > _vMonster[9][i].x)_vMonster[9][i].frameY = 0;
				if ((_playerInformation.rc.left + _playerInformation.rc.right) / 2 < _vMonster[9][i].x)_vMonster[9][i].frameY = 1;

				if (_vMonster[9][i].impact)
				{
					_vMonster[9][i].c += TIMEMANAGER->getElapsedTime();

					_vMonster[9][i].atkSpeed += TIMEMANAGER->getElapsedTime();

					if (_vMonster[9][i].atkSpeed >= 0.1f)
					{
						_vMonster[9][i].atkSpeed = 0;
						if (_vMonster[9][i].alpha == 255)_vMonster[9][i].alpha = 100;
						else _vMonster[9][i].alpha = 255;
					}

					if (_vMonster[9][i].c > 0.3f)
					{
						_vMonster[9][i].impact = false;
					}
				}
				else _vMonster[9][i].alpha = 255;




				if (_vMonster[9][i].atktrue)
				{
					_vMonster[9][i].frameTime += TIMEMANAGER->getElapsedTime();
					if (_vMonster[9][i].frameTime > 0.15f)
					{
						_vMonster[9][i].frameTime = 0;
						_vMonster[9][i].frameX++;
						if (_vMonster[9][i].frameX >= 6)
						{
							_vMonster[9][i].frameX = 3;
						}
					}
					_vMonster[9][i].angle = getAngle(_vMonster[9][i].x, _vMonster[9][i].y, (_playerInformation.rc.right + _playerInformation.rc.left) / 2 - 50,
						(_playerInformation.rc.bottom + _playerInformation.rc.top) / 2 - 50);

					_vMonster[9][i].x += cosf(_vMonster[9][i].angle) * _vMonster[9][i].speed;
					_vMonster[9][i].y -= sinf(_vMonster[9][i].angle) * _vMonster[9][i].speed;
				}
			

			if (_vMonster[8].size() > 0)
			{
				if (_vMonster[9][0].x < _vMonster[8][0].x && _vMonster[9][0].y < _vMonster[8][0].y)
				{
					//오른쪽밑
					for (int i = 0; i < 14; i++)
					{
						//8 큰애 9작은애
						distansX[i] = (_vMonster[8][0].x - _vMonster[9][0].x) / 14 * i + _vMonster[9][0].x + 21;
						distansY[i] = (_vMonster[8][0].y - _vMonster[9][0].y) / 14 * i + _vMonster[9][0].y + 13;
					}
				}
				else if (_vMonster[9][0].x > _vMonster[8][0].x && _vMonster[9][0].y > _vMonster[8][0].y)
				{
					//왼쪽위
					for (int i = 0; i < 14; i++)
					{
						distansX[i] = ((_vMonster[9][0].x - 8) - _vMonster[8][0].x) / 14 * i + _vMonster[8][0].x + 37;
						distansY[i] = (_vMonster[9][0].y - _vMonster[8][0].y) / 14 * i + _vMonster[8][0].y + 30;
					}
				}
				else if (_vMonster[9][0].x < _vMonster[8][0].x && _vMonster[9][0].y > _vMonster[8][0].y)
				{
					//오른쪽위
					for (int i = 0; i < 14; i++)
					{
						distansX[i] = (_vMonster[9][0].x - _vMonster[8][0].x) / 14 * i + _vMonster[8][0].x + 20;
						distansY[i] = (_vMonster[9][0].y - _vMonster[8][0].y) / 14 * i + _vMonster[8][0].y + 20;
					}
				}
				else if (_vMonster[9][0].x > _vMonster[8][0].x && _vMonster[9][0].y < _vMonster[8][0].y)
				{
					for (int i = 0; i < 14; i++)
					{
						distansX[i] = ((_vMonster[9][0].x - 5) - _vMonster[8][0].x) / 14 * i + _vMonster[8][0].x + 30;
						distansY[i] = ((_vMonster[9][0].y - 15) - _vMonster[8][0].y) / 14 * i + _vMonster[8][0].y + 30;
					}
				}
			}
			if (_vMonster[9][i].hp <= 0)
			{
				_bossStart = false;
				_blood.push_back({ _vMonster[9][i].x ,_vMonster[9][i].y,0 });
				_vMonster[9].erase(_vMonster[9].begin() + i);
			}
		}
	}
#pragma endregion
	
	for (int i = 0; i < _vMonster[10].size(); i++)
	{
		//플레이어 공격 충돌 Rc
		_vMonster[10][i].rc = RectMake(_vMonster[10][i].x + 13, _vMonster[10][i].y + 13, 70, 70);

		if (IntersectRect(&_impact, &cameraImpactrc, &_vMonster[10][i].rc))
		{
			if (!_bossStart)
			{
				if (!_sound)
				{
					SOUNDMANAGER->play("보스방진입", 0.5f);
					_sound = true;
				}
				_bossEnd[2] = true;
				_frameTime += TIMEMANAGER->getElapsedTime();
				if (_frameTime > 0.12f)
				{
					_frameTime = 0;
					_bossGimage[2]->setFrameX(_bossGimage[2]->getFrameX() + 1);
					if (_bossGimage[2]->getFrameX() >= 24)
					{
						_bossStart = true;
						_bossEnd[2] = false;
						SOUNDMANAGER->play("보스방", 0.5f);
						_sound = false;
					}
				}
			}

			if (_bossStart)
			{
				//플레이어 따라감
				if (!_vMonster[10][i].move)
				{
					if ((_playerInformation.rc.top + _playerInformation.rc.bottom - 110) / 2 < _vMonster[10][i].y)
					{
						_vMonster[10][i].frameX = 4;
						_vMonster[10][i].y -= _vMonster[10][i].speed;

					}
					if ((_playerInformation.rc.top + _playerInformation.rc.bottom - 110) / 2 > _vMonster[10][i].y)
					{
						_vMonster[10][i].frameX = 0;
						_vMonster[10][i].y += _vMonster[10][i].speed;
					}

					if (_vMonster[10][i].rc.top < _playerInformation.rc.top && _vMonster[10][i].rc.bottom  > _playerInformation.rc.bottom)
					{
						_vMonster[10][i].move = true;

						if ((_playerInformation.rc.left + _playerInformation.rc.right) / 2 < _vMonster[10][i].x)
						{
							_vMonster[10][i].frameX = 2;
							_vMonster[10][i].direction = 1;
							_vMonster[10][i].speed = 2.5f;
						}
						if ((_playerInformation.rc.left + _playerInformation.rc.right) / 2 > _vMonster[10][i].x)
						{
							_vMonster[10][i].frameX = 1;
							_vMonster[10][i].direction = 2;
							_vMonster[10][i].speed = 2.5f;
						}
					}
				}

				if (_vMonster[10][i].move)
				{

					if (_vMonster[10][i].direction == 1)
					{
						_vMonster[10][i].x -= _vMonster[10][i].speed;;

						if (_map.left > _vMonster[10][i].rc.left)
						{
							_vMonster[10][i].move = false;
							_vMonster[10][i].direction = 0;
							_vMonster[10][i].speed = 2.0f;
						}
					}
					if (_vMonster[10][i].direction == 2)
					{
						_vMonster[10][i].x += _vMonster[10][i].speed;;

						if (_map.right < _vMonster[10][i].rc.right)
						{
							_vMonster[10][i].move = false;
							_vMonster[10][i].direction = 0;
							_vMonster[10][i].speed = 2.0f;
						}
					}

				}
			}

			if (_vMonster[10][i].impact)
			{
				_vMonster[10][i].c += TIMEMANAGER->getElapsedTime();

				_vMonster[10][i].atkSpeed += TIMEMANAGER->getElapsedTime();

				if (_vMonster[10][i].atkSpeed >= 0.1f)
				{
					_vMonster[10][i].atkSpeed = 0;
					if (_vMonster[10][i].alpha == 255)_vMonster[10][i].alpha = 100;
					else _vMonster[10][i].alpha = 255;
				}

				if (_vMonster[10][i].c > 0.3f)
				{
					_vMonster[10][i].impact = false;
				}
			}
			else _vMonster[10][i].alpha = 255;

			//플레이어 타격점
			if (_vMonster[10][i].frameX == 1)_vMonster[10][i].plrc = RectMake(_vMonster[10][i].x + 5, _vMonster[10][i].y + 13, 30, 70);
			if (_vMonster[10][i].frameX == 2)_vMonster[10][i].plrc = RectMake(_vMonster[10][i].x + 65, _vMonster[10][i].y + 13, 30, 70);
			if (_vMonster[10][i].frameX <= 0)_vMonster[10][i].plrc = RectMake(_vMonster[10][i].x + 13, _vMonster[10][i].y + 13, 0, 0);
			if (_vMonster[10][i].frameX >= 3)_vMonster[10][i].plrc = RectMake(_vMonster[10][i].x + 43, _vMonster[10][i].y + 13, 0, 0);

			if (_vMonster[10][i].hp <= 0)
			{
				_bossStart = false;
				_blood.push_back({ _vMonster[10][i].x ,_vMonster[10][i].y,0 });

				_vMonster[10].erase(_vMonster[10].begin() + i);
			}
		}
	}


	for (int i = 0; i < _vMonster[11].size(); i++)
	{
		_vMonster[11][i].rc = RectMake(_vMonster[11][i].x + 27, _vMonster[11][i].y + 28, 50, 50);

		if (IntersectRect(&_impact, &cameraImpactrc, &_vMonster[11][i].rc))
		{

			_vMonster[11][i].angle = getAngle(_vMonster[11][i].x, _vMonster[11][i].y, (_playerInformation.rc.right + _playerInformation.rc.left) / 2 - 50,
				(_playerInformation.rc.bottom + _playerInformation.rc.top) / 2 - 50);

			_vMonster[11][i].x -= cosf(_vMonster[11][i].angle) * _vMonster[11][i].speed;
			_vMonster[11][i].y += sinf(_vMonster[11][i].angle) * _vMonster[11][i].speed;

				if (_vMonster[11][i].rc.right - 30 > _map.right)
				{
					_vMonster[11][i].x -= _vMonster[11][i].speed;
				}
				if (_vMonster[11][i].rc.left + 20 < _map.left)
				{
					_vMonster[11][i].x += _vMonster[11][i].speed;
				}
				if (_vMonster[11][i].rc.bottom - 20 > _map.bottom)
				{
					_vMonster[11][i].y -= _vMonster[11][i].speed;
				}
				if (_vMonster[11][i].rc.top < _map.top - 50)
				{
					_vMonster[11][i].y += _vMonster[11][i].speed;
				}
			
			if (_vMonster[11][i].impact)
			{
				_vMonster[11][i].c += TIMEMANAGER->getElapsedTime();

				_vMonster[11][i].atkSpeed += TIMEMANAGER->getElapsedTime();

				if (_vMonster[11][i].atkSpeed >= 0.1f)
				{
					_vMonster[11][i].atkSpeed = 0;
					if (_vMonster[11][i].alpha == 255)_vMonster[11][i].alpha = 100;
					else _vMonster[11][i].alpha = 255;
				}
				if (_vMonster[11][i].c > 0.3f)
				{
					_vMonster[11][i].impact = false;
				}
			}
			else _vMonster[11][i].alpha = 255;

			if (_vMonster[10][0].hp <= 30)
			{
				_vMonster[10][0].frameY = 1;

				_blood.push_back({ _vMonster[11][i].x ,_vMonster[11][i].y,0 });

				_vMonster[11].erase(_vMonster[11].begin() + i);
			}
		}
	}

	for (int i = 0; i < _vMonster[12].size(); i++)
	{

		_vMonster[12][i].rc = RectMake(_vMonster[12][i].x + 10, _vMonster[12][i].y + 6, 27, 27);
		_vMonster[12][i].plrc = RectMakeCenter((_vMonster[12][i].rc.left+ _vMonster[12][i].rc.right)/2,(_vMonster[12][i].rc.bottom + _vMonster[12][i].rc.top) / 2, 400, 400);

		if (IntersectRect(&_impact, &cameraImpactrc, &_vMonster[12][i].rc))
		{
			//플레이어 방향으로 보기
			if ((_playerInformation.rc.left + _playerInformation.rc.right) / 2 < _vMonster[12][i].rc.left)
			{
				_vMonster[12][i].frameY = 1;
			}
			else _vMonster[12][i].frameY = 0;

			if (IntersectRect(&_impact, &_playerInformation.rc, &_vMonster[12][i].plrc))
			{
				_vMonster[12][i].atktrue = true;
			}
			else _vMonster[12][i].atktrue = false;

			if (!_vMonster[12][i].atktrue)
			{
				_vMonster[12][i].frameTime += TIMEMANAGER->getElapsedTime();
				if (_vMonster[12][i].frameTime > 0.1f)
				{
					_vMonster[12][i].frameTime = 0;
					_vMonster[12][i].frameX++;
					if (_vMonster[12][i].frameX > 1)
					{
						_vMonster[12][i].frameX = 0;
					}
				}

				_vMonster[12][i].angle = getAngle(_vMonster[12][i].x, _vMonster[12][i].y, (_playerInformation.rc.right + _playerInformation.rc.left) / 2 - 50,
					(_playerInformation.rc.bottom + _playerInformation.rc.top) / 2 - 50);

				_vMonster[12][i].x += cosf(_vMonster[12][i].angle) * _vMonster[12][i].speed;
				_vMonster[12][i].y -= sinf(_vMonster[12][i].angle) * _vMonster[12][i].speed;
			}

			if (_vMonster[12][i].atktrue)
			{
				_vMonster[12][i].frameTime += TIMEMANAGER->getElapsedTime();
				if (_vMonster[12][i].frameTime > 0.3f)
				{
					_vMonster[12][i].frameTime = 0;
					_vMonster[12][i].frameX++;
					if (_vMonster[12][i].frameX > 6)
					{
						_vMonster[12][i].frameX = 0;
					}
					if (_vMonster[12][i].frameX == 5)
					{
						Monsterbullet bul;
						bul.atk = 0.5f;
						bul.x = _vMonster[12][i].x - 22;
						bul.y = _vMonster[12][i].y - 15;
						bul.frameXTime = 0;
						bul.frameX = 0;
						bul.atkTime = 0;
						bul.direction = RND->getInt(2);
						bul.impact = false;
						bul.impactTime = RND->getFromFloatTo(1.7f, 2.0f);
						bul.angle = getAngle(bul.x, bul.y,
							(_playerInformation.rc.right + _playerInformation.rc.left) / 2 - 50, (_playerInformation.rc.bottom + _playerInformation.rc.top) / 2 - 50);

						bul.angleRnd = RND->getFromFloatTo(20.0f, 50.0f);

						_monsterbullet1.push_back(bul);
					}
				}
			}
			
		}
		for (int j = 0; j < _vMonster[12].size(); j++)
		{
			if (IntersectRect(&_impact, &_vMonster[12][i].rc, &_vMonster[12][j].rc))
			{
				if ((_vMonster[12][i].rc.right + _vMonster[12][i].rc.left) / 2 > _vMonster[12][j].rc.left)
				{
					_vMonster[12][i].x += 1.5f;
					_vMonster[12][j].x -= 1.5f;
				}
				if ((_vMonster[12][i].rc.right + _vMonster[12][i].rc.left) / 2 < _vMonster[12][j].rc.right)
				{
					_vMonster[12][i].x -= 1.5f;
					_vMonster[12][j].x += 1.5f;
				}
				if ((_vMonster[12][i].rc.bottom + _vMonster[12][i].rc.top) / 2 > _vMonster[12][j].rc.top)
				{
					_vMonster[12][i].y += 1.5f;
					_vMonster[12][j].y -= 1.5f;
				}
				if ((_vMonster[12][i].rc.bottom + _vMonster[12][i].rc.top) / 2 < _vMonster[12][j].rc.bottom)
				{
					_vMonster[12][i].y -= 1.5f;
					_vMonster[12][j].y += 1.5f;
				}
			}
		}

		if (_vMonster[12][i].hp < 0)
		{
			_blood3.push_back({ _vMonster[12][i].x ,_vMonster[12][i].y,0 });

			_vMonster[12].erase(_vMonster[12].begin() + i);
		}

	}

	for (int i = 0; i < _vMonster[13].size(); i++)
	{


		_vMonster[13][i].rc = RectMake(_vMonster[13][i].x, _vMonster[13][i].y, 120, 100);

		if (IntersectRect(&_impact, &cameraImpactrc, &_vMonster[13][i].rc))
		{
			if (!_bossStart)
			{
				if (!_sound)
				{
					SOUNDMANAGER->play("보스방진입", 0.5f);
					_sound = true;
				}
				_bossEnd[3] = true;
				_frameTime += TIMEMANAGER->getElapsedTime();
				if (_frameTime > 0.12f)
				{
					_frameTime = 0;
					_bossGimage[3]->setFrameX(_bossGimage[3]->getFrameX() + 1);
					if (_bossGimage[3]->getFrameX() >= 24)
					{
						_bossStart = true;
						_bossEnd[3] = false;
						SOUNDMANAGER->play("보스방", 0.5f);
						_sound = false;
					}
				}
			}

			if (_bossStart)
			{
				if (!_vMonster[13][i].atktrue)
				{
					if (_vMonster[13][i].rnd == 0)
					{
						_vMonster[13][i].frameX = 1;

						_vMonster[13][i].atkSpeed += TIMEMANAGER->getElapsedTime();

						if (_vMonster[13][i].atkSpeed < 1)
						{
							if (_vMonster[13][i].atkSpeed < 0.5f)
							{
								_vMonster[13][i].y--;
							}
							if (_vMonster[13][i].atkSpeed > 0.5f)
							{
								_vMonster[13][i].y++;
							}
						}
						if (_vMonster[13][i].atkSpeed > 1)
						{
							CAMERASHAKE->cameraRandomShake(7.0f, 1.0f);
							for (int k = 0; k < 12; k++)
							{
								Monsterbullet bul;
								bul.atk = 0.5f;
								bul.x = _vMonster[13][i].x;
								bul.y = _vMonster[13][i].y - 15;
								bul.frameXTime = 0;
								bul.frameX = 0;
								bul.atkTime = 0;
								bul.direction = RND->getInt(2);
								bul.impact = false;
								bul.impactTime = RND->getFromFloatTo(1.7f, 2.0f);
								bul.angle = 30 * k;

								bul.angleRnd = RND->getFromFloatTo(20.0f, 50.0f);

								_monsterbullet2.push_back(bul);

							}

							_vMonster[13][i].atktrue = true;
							_vMonster[13][i].atkSpeed = 0;
							_vMonster[13][i].frameX = 0;
						}
					}
					if (_vMonster[13][i].rnd == 1)
					{
						_vMonster[13][i].atkSpeed += TIMEMANAGER->getElapsedTime();

						_vMonster[13][i].frameX = 3;

						_vMonster[13][i].x += cosf(_vMonster[13][i].c) * _vMonster[13][i].speed+1;
						_vMonster[13][i].y -= sinf(_vMonster[13][i].c) * _vMonster[13][i].speed+1;

						if (_vMonster[13][i].atkSpeed > 4.0f)
						{
							_vMonster[13][i].atktrue = true;
							_vMonster[13][i].speed = 3;
							_vMonster[13][i].atkSpeed = 0;
						}
					}

					if (_vMonster[13][i].rnd == 2)
					{
						_vMonster[13][i].frameX = 2;

						MonsterInformation mogi;
						mogi.atk = 0.5f;
						mogi.atkSpeed = 0;
						mogi.direction = 0;
						mogi.frameTime = 6;
						mogi.frameX = 0;
						mogi.frameY = 0;
						mogi.hp = 12.0f;
						mogi.move = true;
						mogi.speed = 1.35f;
						mogi.x = _vMonster[13][i].x - 15;
						mogi.y = _vMonster[13][i].y - 25;
						mogi._monster = IMAGEMANAGER->findImage("모기몬스터");
						mogi.frameHerd = 0;
						mogi.impact = false;
						mogi.rnd = RND->getInt(4);
						mogi.atktrue = false;
						mogi.alpha = 255;
						mogi.a = 0;
						mogi.b = 0;
						mogi.c = 0;
						mogi.die = false;
						mogi.angle = 0;
						_vMonster[12].push_back({ mogi });

						_vMonster[13][i].atktrue = true;
					}
				}
				if (_vMonster[13][i].rc.right > _map.right)
				{
					_vMonster[13][i].c = getAngle(_vMonster[13][i].x, _vMonster[13][i].y,
						(_playerInformation.rc.right + _playerInformation.rc.left) / 2 - 50, (_playerInformation.rc.bottom + _playerInformation.rc.top) / 2 - 50);
				}
				if (_vMonster[13][i].rc.left < _map.left)
				{
					_vMonster[13][i].c = getAngle(_vMonster[13][i].x, _vMonster[13][i].y,
						(_playerInformation.rc.right + _playerInformation.rc.left) / 2 - 50, (_playerInformation.rc.bottom + _playerInformation.rc.top) / 2 - 50);
				}
				if (_vMonster[13][i].rc.top < _map.top)
				{
					_vMonster[13][i].c = getAngle(_vMonster[13][i].x, _vMonster[13][i].y,
						(_playerInformation.rc.right + _playerInformation.rc.left) / 2 - 50, (_playerInformation.rc.bottom + _playerInformation.rc.top) / 2 - 50);
				}
				if (_vMonster[13][i].rc.bottom > _map.bottom)
				{
					_vMonster[13][i].c = getAngle(_vMonster[13][i].x, _vMonster[13][i].y,
						(_playerInformation.rc.right + _playerInformation.rc.left) / 2 - 50, (_playerInformation.rc.bottom + _playerInformation.rc.top) / 2 - 50);
				}
			}
				
			
		

			if (_vMonster[13][i].atktrue)
			{
				_vMonster[13][i].atkSpeed += TIMEMANAGER->getElapsedTime();
				if (_vMonster[13][i].atkSpeed > 3.0f)
				{
					_vMonster[13][i].atkSpeed = 0;
					_vMonster[13][i].rnd = RND->getInt(3);
					_vMonster[13][i].atktrue = false;

					_vMonster[13][i].c = getAngle(_vMonster[13][i].x, _vMonster[13][i].y,
						(_playerInformation.rc.right + _playerInformation.rc.left) / 2 - 50, (_playerInformation.rc.bottom + _playerInformation.rc.top) / 2 - 50);
				}
			}
		}

			

		
		for (int j = 0; j < _vMonster[12].size(); j++)
		{
			if (IntersectRect(&_impact, &_vMonster[13][i].rc, &_vMonster[12][j].rc))
			{
				if ((_vMonster[13][i].rc.right + _vMonster[13][i].rc.left) / 2 > _vMonster[12][j].rc.left)
				{
					//_vMonster[13][i].x += 1.5f;
					_vMonster[12][j].x -= 1.5f;
				}
				if ((_vMonster[13][i].rc.right + _vMonster[13][i].rc.left) / 2 < _vMonster[12][j].rc.right)
				{
					//_vMonster[13][i].x -= 1.5f;
					_vMonster[12][j].x += 1.5f;
				}
				if ((_vMonster[13][i].rc.bottom + _vMonster[13][i].rc.top) / 2 > _vMonster[12][j].rc.top)
				{
					//_vMonster[13][i].y += 1.5f;
					_vMonster[12][j].y -= 1.5f;
				}
				if ((_vMonster[13][i].rc.bottom + _vMonster[13][i].rc.top) / 2 < _vMonster[12][j].rc.bottom)
				{
					//_vMonster[13][i].y -= 1.5f;
					_vMonster[12][j].y += 1.5f;
				}
			}
		}

		if (_vMonster[13][i].impact)
		{
			_vMonster[13][i].c += TIMEMANAGER->getElapsedTime();

			_vMonster[13][i].b += TIMEMANAGER->getElapsedTime();

			if (_vMonster[13][i].b >= 0.1f)
			{
				_vMonster[13][i].b = 0;
				if (_vMonster[13][i].alpha == 255)_vMonster[13][i].alpha = 100;
				else _vMonster[13][i].alpha = 255;
			}
			if (_vMonster[13][i].c > 0.3f)
			{
				_vMonster[13][i].impact = false;
			}
		}
		else _vMonster[13][i].alpha = 255;

		if (_vMonster[13][i].hp <= 0)
		{
			_vMonster[13][i].die = true;
			_blood.push_back({ _vMonster[13][i].x ,_vMonster[13][i].y,0 });
			_vMonster[13].erase(_vMonster[13].begin() + i);
		}
	}
	
	//몬스터볼렛2
	for (int i = 0; i < _monsterbullet2.size(); i++)
	{
		if (!_monsterbullet2[i].impact)
		{
			_monsterbullet2[i].x += cosf((_monsterbullet2[i].angle) * PI / 180.0f) * 3;
			_monsterbullet2[i].y += sinf((_monsterbullet2[i].angle) * PI / 180.0f) * 3;
		}

		_monsterbullet2[i].rc = RectMake(_monsterbullet2[i].x + 37, _monsterbullet2[i].y + 37, 18, 18);

		if (_monsterbullet2[i].x >= _wall.right - 50 || _monsterbullet2[i].x <= _wall.left - 50 ||
			_monsterbullet2[i].y >= _wall.bottom - 50 || _monsterbullet2[i].y <= _wall.top - 50)
		{
			_monsterbullet2[i].impact = true;
		}

		//충돌
		if (_monsterbullet2[i].impact)
		{
			_monsterbullet2[i].frameXTime += TIMEMANAGER->getElapsedTime();
			if (_monsterbullet2[i].frameXTime >= 0.1f)
			{
				_monsterbullet2[i].frameXTime = 0;
				_monsterbullet2[i].frameX++;
				if (_monsterbullet2[i].frameX >= 14)
				{
					_monsterbullet2.erase(_monsterbullet2.begin() + i);
				}
			}
		}



	
	}


#pragma region 몬스터 피 볼렛 등등
	//몬스터 피 터짐
	for (int i = 0; i < _blood.size(); i++)
	{
		_blood[i].frameXTime += TIMEMANAGER->getElapsedTime();
		if (_blood[i].frameXTime > 0.05f)
		{
			_blood[i].frameXTime = 0;
			_blood[i].frameX++;

			if (_blood[i].frameX == 3)
			{
				_blood2.push_back({ _blood[i].x , _blood[i].y-10,0 });
			}
			if (_blood[i].frameX >= 10)
			{
				_blood.erase(_blood.begin() + i);
			}
			
		}
	}

	//몬스터 피 남음
	for (int i = 0; i < _blood2.size(); i++)
	{

		if (_blood2[i].frameX < 8)
		{
			_blood2[i].frameXTime += TIMEMANAGER->getElapsedTime();
			if (_blood2[i].frameXTime > 0.12f)
			{
				_blood2[i].frameXTime = 0;
				_blood2[i].frameX++;

			}
		}

	}

	//몬스터 볼렛 공격
	for (int i = 0; i < _monsterbullet.size(); i++)
	{
		
		if (!_monsterbullet[i].impact && _monsterbullet[i].direction)
		{
			_monsterbullet[i].angle++;
			_monsterbullet[i].x += 2.5f;
			_monsterbullet[i].y += sinf((-_monsterbullet[i].angleRnd + _monsterbullet[i].angle) * PI / 180.0f) * 7;

			_monsterbullet[i].impactTime+=TIMEMANAGER->getElapsedTime();
			if (_monsterbullet[i].impactTime >= 3.0f)
			{
				_monsterbullet[i].impact = true;

			}
		}
		else if (!_monsterbullet[i].impact && !_monsterbullet[i].direction)
		{
			_monsterbullet[i].angle++;
			_monsterbullet[i].x -= 2.5f;
			_monsterbullet[i].y += sinf((-_monsterbullet[i].angleRnd + _monsterbullet[i].angle) * PI / 180.0f) * 7;

			_monsterbullet[i].impactTime += TIMEMANAGER->getElapsedTime();
			if (_monsterbullet[i].impactTime >= 3.0f)
			{
				_monsterbullet[i].impact = true;

			}
		}

		if (_monsterbullet[i].x >= _wall.right -50 || _monsterbullet[i].x <= _wall.left -50 ||
			_monsterbullet[i].y >= _wall.bottom -50 || _monsterbullet[i].y <= _wall.top -50)
		{
			_monsterbullet[i].impact = true;
		}


		_monsterbullet[i].rc = RectMake(_monsterbullet[i].x+37, _monsterbullet[i].y+37, 18, 18);

		if (_monsterbullet[i].impact)
		{
			_monsterbullet[i].frameXTime += TIMEMANAGER->getElapsedTime();
			if (_monsterbullet[i].frameXTime >= 0.1f)
			{
				_monsterbullet[i].frameXTime = 0;
				_monsterbullet[i].frameX++;
				if (_monsterbullet[i].frameX >= 14)
				{
					_monsterbullet.erase(_monsterbullet.begin() + i);
				}
			}
		}
	}

	//플레이어 위치로 몬스터 공격
	for (int i = 0; i < _monsterbullet1.size(); i++)
	{
		//몬스터위치에서 플레이어 위치 각도

		if (!_monsterbullet1[i].impact)
		{
			_monsterbullet1[i].x += cosf(_monsterbullet1[i].angle) * 3;
			_monsterbullet1[i].y -= sinf(_monsterbullet1[i].angle) * 3;
		}

		if (_monsterbullet1[i].x >= _wall.right - 50 || _monsterbullet1[i].x <= _wall.left - 50 ||
			_monsterbullet1[i].y >= _wall.bottom - 50 || _monsterbullet1[i].y <= _wall.top - 50)
		{
			_monsterbullet1[i].impact = true;
		}


		_monsterbullet1[i].rc = RectMake(_monsterbullet1[i].x + 39, _monsterbullet1[i].y + 35, 18, 18);

		if (_monsterbullet1[i].impact)
		{
			_monsterbullet1[i].frameXTime += TIMEMANAGER->getElapsedTime();
			if (_monsterbullet1[i].frameXTime >= 0.1f)
			{
				_monsterbullet1[i].frameXTime = 0;
				_monsterbullet1[i].frameX++;
				if (_monsterbullet1[i].frameX >= 14)
				{
					_monsterbullet1.erase(_monsterbullet1.begin() + i);
				}
			}
		}

	}

	if (KEYMANAGER->isOnceKeyDown('R'))
	{
		if (!_rcOk)_rcOk = true;
		else _rcOk = false;
	}
#pragma endregion

}

void Monster::render(void)
{
	

	//점프몬스터
	for (int i = 0; i < _vMonster[0].size(); i++)
	{
		IMAGEMANAGER->alphaRender("그림자", getMemDC(), _vMonster[0][i].x +10, _vMonster[0][i].y + 60,40);
		_vMonster[0][i]._monster->frameRender(getMemDC(), _vMonster[0][i].x, _vMonster[0][i].y, _vMonster[0][i].frameX, 0);


		//DrawRectMake(getMemDC(), _vMonster[0][i].rc);
	}
	//몸만남은몬스텊
	for (int i = 0; i < _vMonster[1].size(); i++)
	{
		IMAGEMANAGER->alphaRender("그림자", getMemDC(), _vMonster[1][i].x + 11, _vMonster[1][i].y + 48, 40);
		_vMonster[1][i]._monster->frameRender(getMemDC(), _vMonster[1][i].x, _vMonster[1][i].y, _vMonster[1][i].frameX, _vMonster[1][i].frameY);
		//DrawRectMake(getMemDC(), _vMonster[1][i].rc);
	}
	//날벌레
	for (int i = 0; i < _vMonster[2].size(); i++)
	{
		IMAGEMANAGER->alphaRender("그림자1", getMemDC(), _vMonster[2][i].x + 18, _vMonster[2][i].y + 45, 40);
		_vMonster[2][i]._monster->frameRender(getMemDC(), _vMonster[2][i].x, _vMonster[2][i].y, _vMonster[2][i].frameX, _vMonster[2][i].frameY);
		//DrawRectMake(getMemDC(), _vMonster[2][i].rc);
	}
	//지렁이
	for (int i = 0; i < _vMonster[3].size(); i++)
	{
		IMAGEMANAGER->alphaRender("그림자", getMemDC(), _vMonster[3][i].x + 4, _vMonster[3][i].y + 34, 40);
		_vMonster[3][i]._monster->frameRender(getMemDC(), _vMonster[3][i].x, _vMonster[3][i].y, _vMonster[3][i].frameX, _vMonster[3][i].frameY);
		//DrawRectMake(getMemDC(), _vMonster[3][i].rc);
	}
	//얼굴달린몬스터
	for (int i = 0; i < _vMonster[4].size(); i++)
	{
		IMAGEMANAGER->alphaRender("그림자", getMemDC(), _vMonster[4][i].x+11, _vMonster[4][i].y +38, 40);
		_vMonster[4][i]._monster->frameRender(getMemDC(), _vMonster[4][i].x, _vMonster[4][i].y, _vMonster[4][i].frameX, _vMonster[4][i].frameY);
		IMAGEMANAGER->frameRender("얼굴달린몬스터", getMemDC(), _vMonster[4][i].x, _vMonster[4][i].y - 28, _vMonster[4][i].frameHerd, 0);
		//DrawRectMake(getMemDC(), _vMonster[4][i].rc);
		//if (_rcOk)DrawRectMake(getMemDC(), _vMonster[4][i].plrc);
	}
	//머리만있는 몬스터
	for (int i = 0; i < _vMonster[5].size(); i++)
	{
		IMAGEMANAGER->alphaRender("그림자", getMemDC(), _vMonster[5][i].x +2, _vMonster[5][i].y + 32, 40);
	    _vMonster[5][i]._monster->frameRender(getMemDC(), _vMonster[5][i].x, _vMonster[5][i].y, _vMonster[5][i].frameX, _vMonster[5][i].frameY);
		
		//if(_rcOk)DrawRectMake(getMemDC(), _vMonster[5][i].plrc);
		//DrawRectMake(getMemDC(), _vMonster[5][i].rc);
	}
	//방패 몬스터
	for (int i = 0; i < _vMonster[6].size(); i++)
	{
		IMAGEMANAGER->alphaRender("그림자", getMemDC(), _vMonster[6][i].x + 2, _vMonster[6][i].y + 80, 40);
		_vMonster[6][i]._monster->frameRender(getMemDC(), _vMonster[6][i].x, _vMonster[6][i].y, _vMonster[6][i].frameX, _vMonster[6][i].frameY);

		//if(_rcOk)DrawRectMake(getMemDC(), _vMonster[6][i].plrc);
		//if (_rcOk)DrawRectMake(getMemDC(), _vMonster[6][i].rc);
	}
	if (_vMonster[8].size() > 0)
	{
		for (int i = 0; i < 14; i++)
		{
			IMAGEMANAGER->render("점", getMemDC(), distansX[i], distansY[i]);
		}
	}
	//보스
	for (int i = 0; i < _vMonster[7].size(); i++)
	{
		IMAGEMANAGER->alphaRender("그림자2", getMemDC(), _vMonster[7][i].x + 10, _vMonster[7][i].y + 70, 40);
		_vMonster[7][i]._monster->alphaFrameRender(getMemDC(), _vMonster[7][i].x, _vMonster[7][i].y, _vMonster[7][i].alpha, _vMonster[7][i].frameX, _vMonster[7][i].frameY);


		if (IntersectRect(&_impact, &cameraImpactrc, &_vMonster[7][i].rc))
		{
			if (!_vMonster[7][i].die) IMAGEMANAGER->render("보스체력바", getMemDC(), 277, 100);
			if (!_vMonster[7][i].die)
			{
				HPEN hpen;
				HPEN hpenOld;
				HBRUSH hbr;
				HBRUSH hbrOld;
				hbr = CreateSolidBrush((RGB(255, 0, 0)));
				hbrOld = (HBRUSH)::SelectObject(getMemDC(), hbr);
				hpen = CreatePen(PS_SOLID, 3, RGB(0, 0, 0));
				hpenOld = (HPEN)::SelectObject(getMemDC(), (HGDIOBJ)hpen);
				_bossHp = _vMonster[7][i].hp * 9.1f;
				RECT bossHprc = RectMake(294, 111, _bossHp / 2, 28);
				DrawRectMake(getMemDC(), bossHprc);
				hbr = (HBRUSH)::SelectObject(getMemDC(), hbrOld);
				::DeleteObject(hbr);
				hpen = (HPEN)::SelectObject(getMemDC(), hpenOld);
				::DeleteObject(hpen);
			}
			if (!_vMonster[7][i].die) IMAGEMANAGER->render("보스hp얼굴", getMemDC(), 257, 100);
		}
		//if (_rcOk)DrawRectMake(getMemDC(), _vMonster[7][i].rc);
		//if (_rcOk)DrawRectMake(getMemDC(), _vMonster[7][i].plrc);
	}
	//보스 날벌레
	for (int i = 0; i < _vMonster[29].size(); i++)
	{
		IMAGEMANAGER->alphaRender("그림자1", getMemDC(), _vMonster[29][i].x + 18, _vMonster[29][i].y + 45, 40);
		_vMonster[29][i]._monster->frameRender(getMemDC(), _vMonster[29][i].x, _vMonster[29][i].y, _vMonster[29][i].frameX, _vMonster[29][i].frameY);
		//if (_rcOk)DrawRectMake(getMemDC(), _vMonster[29][i].rc);
		if (_rcOk)DrawRectMake(getMemDC(), _vMonster[29][i].plrc);
	}

	//보스1
	for (int i = 0; i < _vMonster[8].size(); i++)
	{
		IMAGEMANAGER->alphaRender("그림자", getMemDC(), _vMonster[8][i].x + 13, _vMonster[8][i].y + 62, 40);
		if (_vMonster[8][i].move)IMAGEMANAGER->alphaFrameRender("boss1다리", getMemDC(), _vMonster[8][i].x+5 , _vMonster[8][i].y + 17, _vMonster[8][i].alpha,
			_vMonster[8][i].frameHerd, 0);
		_vMonster[8][i]._monster->alphaFrameRender(getMemDC(), _vMonster[8][i].x, _vMonster[8][i].y, _vMonster[8][i].alpha,
			_vMonster[8][i].frameX,0);
	

		if (_rcOk)DrawRectMake(getMemDC(), _vMonster[8][i].rc);
		//if (_rcOk)DrawRectMake(getMemDC(), _vMonster[8][i].plrc);
	}

	for (int i = 0; i < _vMonster[9].size(); i++)
	{
		IMAGEMANAGER->alphaRender("그림자1", getMemDC(), _vMonster[9][i].x +8, _vMonster[9][i].y + 43, 40);
		_vMonster[9][i]._monster->alphaFrameRender(getMemDC(), _vMonster[9][i].x, _vMonster[9][i].y, _vMonster[9][i].alpha,
			_vMonster[9][i].frameX, _vMonster[9][i].frameY);

		if (IntersectRect(&_impact, &cameraImpactrc, &_vMonster[9][i].rc))
		{
			if (!_vMonster[9][i].die) IMAGEMANAGER->render("보스체력바", getMemDC(), 277, 100);
			if (!_vMonster[9][i].die)
			{
				HPEN hpen1;
				HPEN hpenOld1;
				HBRUSH hbr1;
				HBRUSH hbrOld1;
				hbr1 = CreateSolidBrush((RGB(255, 0, 0)));
				hbrOld1 = (HBRUSH)::SelectObject(getMemDC(), hbr1);
				hpen1 = CreatePen(PS_SOLID, 3, RGB(0, 0, 0));
				hpenOld1 = (HPEN)::SelectObject(getMemDC(), (HGDIOBJ)hpen1);
				_bossHp = _vMonster[9][i].hp * 9.1f;
				RECT bossHprc = RectMake(294, 111, _bossHp / 2, 28);
				DrawRectMake(getMemDC(), bossHprc);
				hbr1 = (HBRUSH)::SelectObject(getMemDC(), hbrOld1);
				::DeleteObject(hbr1);
				hpen1 = (HPEN)::SelectObject(getMemDC(), hpenOld1);
				::DeleteObject(hpen1);
			}

			if (!_vMonster[9][i].die) IMAGEMANAGER->render("보스hp얼굴", getMemDC(), 257, 100);
		}
		if (_rcOk)DrawRectMake(getMemDC(), _vMonster[9][i].rc);
		//if (_rcOk)DrawRectMake(getMemDC(), _vMonster[9][i].plrc);
	}
	//가면
	for (int i = 0; i < _vMonster[10].size(); i++)
	{
		IMAGEMANAGER->alphaRender("그림자1.5", getMemDC(), _vMonster[10][i].x + 15, _vMonster[10][i].y + 82, 40);
		_vMonster[10][i]._monster->alphaFrameRender(getMemDC(), _vMonster[10][i].x, _vMonster[10][i].y, _vMonster[10][i].alpha,
			_vMonster[10][i].frameX, _vMonster[10][i].frameY);


		if (_rcOk)DrawRectMake(getMemDC(), _vMonster[10][i].rc);
		if (_rcOk)DrawRectMake(getMemDC(), _vMonster[10][i].plrc);

		if (IntersectRect(&_impact, &cameraImpactrc, &_vMonster[10][i].rc))
		{
			if (!_vMonster[10][i].die) IMAGEMANAGER->render("보스체력바", getMemDC(), 277, 100);
			if (!_vMonster[10][i].die)
			{
				HPEN hpen1;
				HPEN hpenOld1;
				HBRUSH hbr1;
				HBRUSH hbrOld1;
				hbr1 = CreateSolidBrush((RGB(255, 0, 0)));
				hbrOld1 = (HBRUSH)::SelectObject(getMemDC(), hbr1);
				hpen1 = CreatePen(PS_SOLID, 3, RGB(0, 0, 0));
				hpenOld1 = (HPEN)::SelectObject(getMemDC(), (HGDIOBJ)hpen1);
				_bossHp = _vMonster[10][i].hp * 9.1f;
				RECT bossHprc = RectMake(294, 111, _bossHp / 2, 28);
				DrawRectMake(getMemDC(), bossHprc);
				hbr1 = (HBRUSH)::SelectObject(getMemDC(), hbrOld1);
				::DeleteObject(hbr1);
				hpen1 = (HPEN)::SelectObject(getMemDC(), hpenOld1);
				::DeleteObject(hpen1);
			}

			if (!_vMonster[10][i].die) IMAGEMANAGER->render("보스hp얼굴", getMemDC(), 257, 100);
		}
	}

	for (int i = 0; i < _vMonster[11].size(); i++)
	{
		IMAGEMANAGER->alphaRender("그림자1.5", getMemDC(), _vMonster[11][i].x + 20, _vMonster[11][i].y + 72, 40);
		_vMonster[11][i]._monster->alphaRender(getMemDC(), _vMonster[11][i].x, _vMonster[11][i].y, _vMonster[11][i].alpha);


		if (_rcOk)DrawRectMake(getMemDC(), _vMonster[11][i].rc);
		//if (_rcOk)DrawRectMake(getMemDC(), _vMonster[11][i].plrc);
	}

	for (int i = 0; i < _vMonster[12].size(); i++)
	{
		IMAGEMANAGER->alphaRender("그림자1", getMemDC(), _vMonster[12][i].x + 8, _vMonster[12][i].y + 45, 40);
		_vMonster[12][i]._monster->frameRender(getMemDC(), _vMonster[12][i].x, _vMonster[12][i].y, _vMonster[12][i].frameX, _vMonster[12][i].frameY);
		//DrawRectMake(getMemDC(), _vMonster[12][i].plrc);
	}

	//몬스터 피
	for (int i = 0; i < _blood.size(); i++)
	{
		IMAGEMANAGER->alphaFrameRender ("몬스터피", getMemDC(), _blood[i].x, _blood[i].y,120, _blood[i].frameX, 0);
	}

	//몬스터 피
	for (int i = 0; i < _blood3.size(); i++)
	{
		IMAGEMANAGER->alphaFrameRender("날벌레 사망", getMemDC(), _blood3[i].x, _blood3[i].y, 120, _blood3[i].frameX, 0);
	}

	//몬스터 공격
	for (int i = 0; i < _monsterbullet.size(); i++)
	{
		IMAGEMANAGER->frameRender("몬스터공격", getMemDC(), _monsterbullet[i].x, _monsterbullet[i].y, _monsterbullet[i].frameX, 0);

		//DrawRectMake(getMemDC(), _monsterbullet[i].rc);
	}

	//몬스터 공격
	for (int i = 0; i < _monsterbullet1.size(); i++)
	{
		IMAGEMANAGER->frameRender("몬스터공격", getMemDC(), _monsterbullet1[i].x, _monsterbullet1[i].y, _monsterbullet1[i].frameX, 0);

		//DrawRectMake(getMemDC(), _monsterbullet1[i].rc);
	}

	//몬스터 공격3
	 for (int i = 0; i < _monsterbullet2.size(); i++)
	{
		IMAGEMANAGER->frameRender("몬스터공격", getMemDC(), _monsterbullet2[i].x, _monsterbullet2[i].y, _monsterbullet2[i].frameX, 0);

		//DrawRectMake(getMemDC(), _monsterbullet2[i].rc);
	}
	//보스 3
	for (int i = 0; i < _vMonster[13].size(); i++)
	{
		IMAGEMANAGER->alphaRender("그림자3", getMemDC(), _vMonster[13][i].x -20, _vMonster[13][i].y + 40, 40);
		_vMonster[13][i]._monster->alphaFrameRender(getMemDC(), _vMonster[13][i].x, _vMonster[13][i].y, _vMonster[13][i].alpha, _vMonster[13][i].frameX, _vMonster[13][i].frameY);


		if (IntersectRect(&_impact, &cameraImpactrc, &_vMonster[13][i].rc))
		{
			if (!_vMonster[13][i].die) IMAGEMANAGER->render("보스체력바", getMemDC(), 277, 100);
			if (!_vMonster[13][i].die)
			{
				HPEN hpen;
				HPEN hpenOld;
				HBRUSH hbr;
				HBRUSH hbrOld;
				hbr = CreateSolidBrush((RGB(255, 0, 0)));
				hbrOld = (HBRUSH)::SelectObject(getMemDC(), hbr);
				hpen = CreatePen(PS_SOLID, 3, RGB(0, 0, 0));
				hpenOld = (HPEN)::SelectObject(getMemDC(), (HGDIOBJ)hpen);
				_bossHp = _vMonster[13][i].hp * 9.1f;
				RECT bossHprc = RectMake(294, 111, _bossHp / 2, 28);
				DrawRectMake(getMemDC(), bossHprc);
				hbr = (HBRUSH)::SelectObject(getMemDC(), hbrOld);
				::DeleteObject(hbr);
				hpen = (HPEN)::SelectObject(getMemDC(), hpenOld);
				::DeleteObject(hpen);
			}
			if (!_vMonster[13][i].die) IMAGEMANAGER->render("보스hp얼굴", getMemDC(), 257, 100);
		}
		//if (_rcOk)DrawRectMake(getMemDC(), _vMonster[13][i].rc);
		//if (_rcOk)DrawRectMake(getMemDC(), _vMonster[13][i].plrc);
	}

	//DrawRectMake(getMemDC(), _wall);
	//if (_rcOk)DrawRectMake(getMemDC(),_map);
	//if (_rcOk)DrawRectMake(getMemDC(), cameraImpactrc);


	
}

void Monster::bloodrender(void)
{
	//몬스터 남는피
	for (int i = 0; i < _blood2.size(); i++)
	{
		IMAGEMANAGER->alphaFrameRender("몬스터피1", getMemDC(), _blood2[i].x, _blood2[i].y, 120, _blood2[i].frameX, 0);
	}
}
