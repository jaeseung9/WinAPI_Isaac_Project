#include "Stdafx.h"
#include "Player.h"
#include "Item.h"
#include "GameSystemManager.h"

HRESULT Player::init(void)
{
	//사운드
	SOUNDMANAGER->addSound("플레이어 공격", "Resources/Sounds/플레이어 공격.mp3", false, false);
	SOUNDMANAGER->addSound("플레이어맞음", "Resources/Sounds/플레이어맞음.mp3", false, false);
	SOUNDMANAGER->addSound("플레이어공격 부딪힘", "Resources/Sounds/플레이어공격 부딪힘.mp3", false, false);
	SOUNDMANAGER->addSound("폭탄터짐", "Resources/Sounds/폭탄터짐.mp3", false, false);

	SOUNDMANAGER->addSound("혈사포", "Resources/Sounds/혈사포.wav", false, false);

	
	_playerImage[0] = IMAGEMANAGER->addFrameImage("머리", "Resources/Images/Player/Head4.bmp",
		504 * 1.5, 200 * 1.5, 9, 4, true, RGB(255, 0, 255));

	IMAGEMANAGER->addImage("몸통", "Resources/Images/Player/Stop.bmp", 20 * 1.5, 15 * 1.5,true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("만세", "Resources/Images/Player/Hooray.bmp", 26 * 1.5, 17 * 1.5, true, RGB(255, 0, 255));

	_playerImage[1] = IMAGEMANAGER->addFrameImage("왼쪽", "Resources/Images/Player/Left.bmp",
		180 * 1.5, 15 * 1.5, 10, 1, true, RGB(255, 0, 255));
	_playerImage[2] = IMAGEMANAGER->addFrameImage("오른쪽", "Resources/Images/Player/Right.bmp",
		180 * 1.5, 15 * 1.5, 10, 1, true, RGB(255, 0, 255));
	_playerImage[3] = IMAGEMANAGER->addFrameImage("위아래", "Resources/Images/Player/UpDown.bmp",
		200 * 1.5, 15 * 1.5, 10, 1, true, RGB(255, 0, 255));
	_playerImage[4] = IMAGEMANAGER->addFrameImage("공격", "Resources/Images/Player/Tears.bmp",
		768 * 1.25 , 64 * 1.25, 12, 1, true, RGB(255, 0, 255));


	_playerImage[5] = IMAGEMANAGER->addFrameImage("폭탄", "Resources/Images/Player/Bomb2.bmp",
	    16813, 240, 43, 1, true, RGB(255, 0, 255));
	_playerImage[6] = IMAGEMANAGER->addFrameImage("공격1", "Resources/Images/Player/Tears1.bmp",
		1408 , 128 , 11, 1, true, RGB(255, 0, 255));

	IMAGEMANAGER->addFrameImage("공격2", "Resources/Images/Player/ReadTears.bmp",
		768 * 1.25, 64 * 1.25, 12, 1, true, RGB(255, 0, 255));
	
	IMAGEMANAGER->addFrameImage("공격3", "Resources/Images/Player/ReadTears2.bmp",
		1408 , 128 , 11, 1, true, RGB(255, 0, 255));


	_star = IMAGEMANAGER->addFrameImage("스타", "Resources/Images/Player/Star.bmp",
		384 * 1.5, 32 * 1.5, 12, 1, true, RGB(255, 0, 255));

	IMAGEMANAGER->addImage("순교자의피", "Resources/Images/Player/Item0.bmp",
		32 * 1.5, 32 * 1.5, true, RGB(255, 0, 255));

	IMAGEMANAGER->addImage("그림자", "Resources/Images/Monster/Shadow.bmp",
		18 * 2.5, 8 * 2.5, true, RGB(255, 0, 255));


	IMAGEMANAGER->addImage("쉴드", "Resources/Images/Player/쉴드.bmp",
		144 / 2.2 , 144 / 2.2, true, RGB(255, 0, 255));

	//사탄
	IMAGEMANAGER->addFrameImage("악마머리", "Resources/Images/Player/플레이어악마.bmp",
		512 * 1.5, 256 * 1.5, 8, 4, true, RGB(255, 0, 255));

	IMAGEMANAGER->addFrameImage("악마몸통", "Resources/Images/Player/플레이어악마몸.bmp",
		320 * 1.5, 96 * 1.5, 10, 3, true, RGB(255, 0, 255));

	_satanAtkImage[0] = IMAGEMANAGER->addFrameImage("혈사포X", "Resources/Images/Player/혈사포X.bmp",
		7098 * 1.5, 86 * 1.5, 12, 2, true, RGB(255, 0, 255));

	_satanAtkImage[1] = IMAGEMANAGER->addFrameImage("혈사포Y", "Resources/Images/Player/혈사포Y.bmp",
		516 * 1.5, 1108 * 1.5, 12, 2, true, RGB(255, 0, 255));

	_flyImage[0] = IMAGEMANAGER->addFrameImage("파리떼이미지", "Resources/Images/Player/파리떼이미지.bmp",
		96 * 1.5, 32 * 1.5, 3, 1, true, RGB(255, 0, 255));

	_flyImage[1] = IMAGEMANAGER->addFrameImage("파리떼이미지1", "Resources/Images/Player/파리떼이미지.bmp",
		96 * 1.5, 32 * 1.5, 3, 1, true, RGB(255, 0, 255));


	_playerImage[0]->setX(WINSIZE_X / 2); 
	_playerImage[0]->setY(WINSIZE_Y / 2); 

	_playerMovement = 0;
	_time = 0;

	_playerInformation.hp = 3;
	_playerInformation.atk = 2;
	_playerInformation.speed = 1;
	_playerInformation.attackSpeed = 1;
	_playerInformation.intersection = 1;
	_playerInformation.bomb = 10;
	_playerInformation.key = 0;
	_playerInformation.money = 0;
	_playerInformation._invincibility = false;
	_playerInformation.skileGage = 6;

	_impact = false;

	for (int i = 0; i < 4; i++)
	{
		_sliding[i] = false;
		_slidingTime[i] = 0;
	}
	atkSpeed = 45;

	for (int i = 0; i < 20; i++)                                                    
	{
		_hooray[i] = false;
		_caricature[i] = false;
	}

	invincibilityTime = 0;

	_playerImage[0]->setFrameY(0);


	_tick = 0;
	shield = false;
	_playerOut = false;
	_plAtkImage = "공격";
	_plAtkImageRed = false;
	_playerAtkSound = false;
	_satan = false;
	_satanFrameX = 0;
	_satanFrameY = 0;
	_satanHeadFrameX = 0;
	_satanHeadFrameY = 0;
	_satanFrameXTime = 0;
	_satanHeadFrameXTime = 0;
	_satanAtkTime = 0;
	_satanAtk = false;
	_cameraImpactrc = RectMake(20, 100, 750, 480);

	//파리떼
	_fly = false;
	_flyFrameXTime = 0;
	_c = 0;
	
	return S_OK;
}

void Player::release(void)
{
}

void Player::update(void)
{
	if (_caricature[12])
	{
		_fly = true;
	}
	if (_caricature[11])
	{
		//if (!_satan)CAMERASHAKE->cameraRandomShake(5.0f, 1.0f);
		_satan = true;
	}
	//_satan = true;
	//돈 최대치 제한
	if (_playerInformation.money >= 100)
	{
		_playerInformation.money = 99;
	}
	//키 최대치 제한
	if (_playerInformation.key >= 100)
	{
		_playerInformation.key = 99;
	}

	if (_playerInformation.attackSpeed >= 2) atkSpeed = 30;
	if (_playerInformation.attackSpeed >= 3) atkSpeed = 25;
	if (_playerInformation.attackSpeed >= 4) atkSpeed = 20;
	if (_playerInformation.attackSpeed >= 5) atkSpeed = 15;
	if (_playerInformation.attackSpeed >= 6) atkSpeed = 10;

	//눈물공격 쏘기
	if (!_satan)
	{
		// 얼굴 방향
		if (KEYMANAGER->isStayKeyDown(VK_DOWN))
		{
			_time++;
			if (_time % 15 == 0)_playerImage[0]->setFrameX(0);
			if (_time % atkSpeed == 0)
			{
				_playerImage[0]->setFrameX(4);
			}

			if (_caricature[10])
			{
				_plAtkImageRed = true;
				_plAtkImage = "공격2";
			}
			if (_time % atkSpeed == 0)
			{
				if (!SOUNDMANAGER->isPlaySound("플레이어 공격"))
				{
					SOUNDMANAGER->play("플레이어 공격", 0.7f);

				}
				_bullet.push_back({ _playerImage[0]->getX() - 19,_playerImage[0]->getY() - 15,0,0,0,0,false,_plAtkImage
				   ,RectMake(_playerImage[0]->getX() + 12 ,_playerImage[0]->getY() + 21 ,17,17) });
			}
		}
		if (KEYMANAGER->isStayKeyDown(VK_LEFT))
		{
			_time++;
			if (_time % 15 == 0)_playerImage[0]->setFrameX(2);
			if (_time % atkSpeed == 0)_playerImage[0]->setFrameX(6);

			if (_caricature[10])
			{
				_plAtkImageRed = true;
				_plAtkImage = "공격2";
			}

			if (_time % atkSpeed == 0)
			{
				if (!SOUNDMANAGER->isPlaySound("플레이어 공격"))
				{
					SOUNDMANAGER->play("플레이어 공격", 0.7f);

				}
				_bullet.push_back({ _playerImage[0]->getX() - 19,_playerImage[0]->getY() - 15,1,0,0,0,false,_plAtkImage
				   ,RectMake(_playerImage[0]->getX() + 4 ,_playerImage[0]->getY() + 13 ,15,17) });
			}
		}
		if (KEYMANAGER->isStayKeyDown(VK_RIGHT))
		{
			_time++;
			if (_time % 15 == 0)_playerImage[0]->setFrameX(1);
			if (_time % atkSpeed == 0)_playerImage[0]->setFrameX(5);

			if (_caricature[10])
			{
				_plAtkImageRed = true;
				_plAtkImage = "공격2";
			}
			if (_time % atkSpeed == 0)
			{
				if (!SOUNDMANAGER->isPlaySound("플레이어 공격"))
				{
					SOUNDMANAGER->play("플레이어 공격", 0.7f);

				}
				_bullet.push_back({ _playerImage[0]->getX() - 13,_playerImage[0]->getY() - 15,2,0,0,0,false,_plAtkImage
				   ,RectMake(_playerImage[0]->getX() + 28 ,_playerImage[0]->getY() + 13 ,17,17) });
			}
		}
		if (KEYMANAGER->isStayKeyDown(VK_UP))
		{
			_time++;
			if (_time % 15 == 0)_playerImage[0]->setFrameX(3);
			if (_time % atkSpeed == 0)_playerImage[0]->setFrameX(7);

			if (_caricature[10])
			{
				_plAtkImageRed = true;
				_plAtkImage = "공격2";
			}
			if (_time % atkSpeed == 0)
			{
				if (!SOUNDMANAGER->isPlaySound("플레이어 공격"))
				{
					SOUNDMANAGER->play("플레이어 공격", 0.7f);

				}
				_bullet.push_back({ _playerImage[0]->getX() - 19,_playerImage[0]->getY() - 40,3,0,0,0,false,_plAtkImage
				   ,RectMake(_playerImage[0]->getX() + 12 ,_playerImage[0]->getY() - 10 ,17,17) });
			}
		}

		if (!KEYMANAGER->isStayKeyDown(VK_LEFT) && !KEYMANAGER->isStayKeyDown(VK_RIGHT)
			&& !KEYMANAGER->isStayKeyDown(VK_UP) && !KEYMANAGER->isStayKeyDown(VK_DOWN))
		{
			_playerImage[0]->setFrameX(0);
		}
	}

	//폭탄공격
	if (KEYMANAGER->isOnceKeyDown(VK_SHIFT))
	{
		if (_playerInformation.bomb > 0)
		{
			_playerInformation.bomb -= 1;
			_bomb.push_back({ _playerImage[0]->getX() -180 ,_playerImage[0]->getY() -100 ,0,0,
				RectMake(_playerImage[0]->getX()-50,_playerImage[0]->getY()-20,120,120),
				RectMake(_playerImage[0]->getX()+6,_playerImage[0]->getY()+42,28,20),false,0,4.5f,0,false,5 });
		}
	}
	for (vector<Bomb>::iterator iter = _bomb.begin(); iter != _bomb.end();)
	{
		iter->indexTime+= TIMEMANAGER->getElapsedTime();
		if (iter->index < 17 &&iter->indexTime > 0.13f)
		{
			if (iter->index > 5)
			{
				iter->impact = true;
			}
			iter->indexTime = 0;
			if(iter->index <= 43)iter->index++;
			else  ++iter;
		}
		else if (iter->index >= 17 && iter->indexTime > 0.08f)
		{
			iter->indexTime = 0;
			if (iter->index <= 43)iter->index++;
			else  ++iter;
		}
		else  ++iter;
	}
	//플레이어 폭탄 밀기
	for (int i = 0; i < _bomb.size(); i++)
	{
		RECT _rc;
		if (_bomb[i].index == 21)
		{
			SOUNDMANAGER->play("폭탄터짐", 0.3f);
			_bomb[i].index++;
		}
		if (_bomb[i].impact && _bomb[i].index < 29)
		{
			if (_bomb[i].smallRc.right - 5 < _playerInformation.rc.left && IntersectRect(&_rc, &_bomb[i].smallRc, &_playerInformation.rc))
			{
			
					_bomb[i].x -= 7;
					_bomb[i].smallRc.left -= 7;
					_bomb[i].smallRc.right -= 7;
					_bomb[i].rc.left -= 7;
					_bomb[i].rc.right -= 7;

					_bomb[i].impact2 = true;
					_bomb[i].direction = 0;
				
			}
			if (_bomb[i].smallRc.left > _playerInformation.rc.right - 5 && IntersectRect(&_rc, &_bomb[i].smallRc, &_playerInformation.rc))
			{
				
				_bomb[i].x += 7;
				_bomb[i].smallRc.left += 7;
				_bomb[i].smallRc.right += 7;
				_bomb[i].rc.left += 7;
				_bomb[i].rc.right += 7;
				_bomb[i].impact2 = true;
				_bomb[i].direction = 1;
				
			}
			if (_bomb[i].smallRc.top > _playerInformation.rc.bottom - 5 && IntersectRect(&_rc, &_bomb[i].smallRc, &_playerInformation.rc))
			{
			
				_bomb[i].y += 7;
				_bomb[i].smallRc.top += 7;
				_bomb[i].smallRc.bottom += 7;
				_bomb[i].rc.top += 7;
				_bomb[i].rc.bottom += 7;
				_bomb[i].impact2 = true;
				_bomb[i].direction = 2;
				
			}
			if (_bomb[i].smallRc.bottom - 5 < _playerInformation.rc.top && IntersectRect(&_rc, &_bomb[i].smallRc, &_playerInformation.rc))
			{
				
				_bomb[i].y -= 7;
				_bomb[i].smallRc.top -= 7;
				_bomb[i].smallRc.bottom -= 7;
				_bomb[i].rc.top -= 7;
				_bomb[i].rc.bottom -= 7;
				_bomb[i].impact2 = true;
				_bomb[i].direction = 3;
			}
		}

		if (_bomb[i].impact2&& _bomb[i].direction == 0)
		{
			
				_bomb[i].x -= _bomb[i].speed;
				_bomb[i].smallRc.left -= _bomb[i].speed;
				_bomb[i].smallRc.right -= _bomb[i].speed;
				_bomb[i].rc.left -= _bomb[i].speed;
				_bomb[i].rc.right -= _bomb[i].speed;
			
			_bomb[i].speed -= 0.1f;
			if (_bomb[i].speed <= 0)
			{
				_bomb[i].impact2 = false;
			}
		}

		if (_bomb[i].impact2 && _bomb[i].direction == 1)
		{
			_bomb[i].x += _bomb[i].speed;
			_bomb[i].smallRc.left += _bomb[i].speed;
			_bomb[i].smallRc.right += _bomb[i].speed;
			_bomb[i].rc.left += _bomb[i].speed;
			_bomb[i].rc.right += _bomb[i].speed;
			_bomb[i].speed -= 0.1f;
			if (_bomb[i].speed <= 0)
			{
				_bomb[i].impact2 = false;
			}
		}

		if (_bomb[i].impact2 && _bomb[i].direction == 2)
		{
			_bomb[i].y += _bomb[i].speed;
			_bomb[i].smallRc.top += _bomb[i].speed;
			_bomb[i].smallRc.bottom += _bomb[i].speed;
			_bomb[i].rc.top += _bomb[i].speed;
			_bomb[i].rc.bottom += _bomb[i].speed;
			_bomb[i].speed -= 0.1f;
			if (_bomb[i].speed <= 0)
			{
				_bomb[i].impact2 = false;
			}
		}

		if (_bomb[i].impact2 && _bomb[i].direction == 3)
		{

			_bomb[i].y -= _bomb[i].speed;
			_bomb[i].smallRc.top -= _bomb[i].speed;
			_bomb[i].smallRc.bottom -= _bomb[i].speed;
			_bomb[i].rc.top -= _bomb[i].speed;
			_bomb[i].rc.bottom -= _bomb[i].speed;
			_bomb[i].speed -= 0.1f;
			if (_bomb[i].speed <= 0)
			{
				_bomb[i].impact2 = false;
			}
		}

		if (_bomb[i].index == 34)
		{
			_bomb[i].x -= 10;
			_bomb[i].index = 35;
		}
	}

	//눈물공격
	for (vector<bullet>::iterator iter = _bullet.begin(); iter != _bullet.end();)
	{
		
		if (iter->direction == 0)
		{
			if (iter->distance <= 110 && !iter->impact)
			{
				iter->y += 3.5f;
				iter->rc.top += 3.5f;
				iter->rc.bottom += 3.5f;
			}
			iter->distance++;

			if (iter->y > 495)iter->impact = true;
			if (iter->index == 1)
			{
				SOUNDMANAGER->play("플레이어공격 부딪힘", 0.2f);
				iter->index++;
			}
			if (iter->impact)
			{
				if (_caricature[10])
				{
					if (iter->keyName == "공격")iter->keyName = "공격1";
					if (iter->keyName == "공격2") iter->keyName = "공격3";
				}
				else iter->keyName = "공격1";
				iter->indexTime += TIMEMANAGER->getElapsedTime();
				if (iter->indexTime > 0.1f)
				{
					iter->indexTime = 0;
					iter->index++;
					if (iter->index >= 11)
					{
						iter = _bullet.erase(iter);
					}
					else  ++iter;
				}
				else ++iter;
			}
			else if(iter->distance > 110)
			{
				iter->indexTime += TIMEMANAGER->getElapsedTime();
				if (iter->indexTime > 0.1f)
				{
					iter->indexTime = 0;
					iter->index++;
					if (iter->index >= 11)
					{
						iter = _bullet.erase(iter);
					}
					else  ++iter;
				}
				else ++iter;
			}
			else  ++iter;

		}
		else if (iter->direction == 2)
		{
			if (iter->distance <= 110 && !iter->impact)
			{
				iter->x += 3.5f;
				iter->rc.left += 3.5f;
				iter->rc.right += 3.5f;
			}
			if (iter->distance >= 95 && iter->distance <= 110 && !iter->impact)
			{
				iter->y += 1.5f;
				iter->rc.top += 2.0f;
				iter->rc.bottom += 2.0f;
			}
			iter->distance++;

			if (iter->x > 662)iter->impact = true;

			if (iter->index == 1)
			{
				SOUNDMANAGER->play("플레이어공격 부딪힘", 0.2f);
				iter->index++;
			}

			if (iter->impact)
			{
				if (_caricature[10])
				{
					if (iter->keyName == "공격")iter->keyName = "공격1";
					if (iter->keyName == "공격2") iter->keyName = "공격3";
				}
				else iter->keyName = "공격1";
				iter->indexTime += TIMEMANAGER->getElapsedTime();
				if (iter->indexTime > 0.1f)
				{
					iter->indexTime = 0;
					iter->index++;
					if (iter->index >= 11)
					{
						iter = _bullet.erase(iter);
					}
					else  ++iter;
				}
				else ++iter;
			}
			else if (iter->distance > 110)
			{
				iter->indexTime += TIMEMANAGER->getElapsedTime();
				if (iter->indexTime > 0.1f)
				{
					iter->indexTime = 0;
					iter->index++;
					if (iter->index >= 11)
					{
						iter = _bullet.erase(iter);
					}
					else  ++iter;
				}
				else ++iter;
			}
			else  ++iter;
		}
		else if (iter->direction == 1)
		{
			if (iter->distance <= 110 && !iter->impact)
			{
				iter->x -= 3.5f;
				iter->rc.left -= 2.9f;
				iter->rc.right -= 2.9f;
			}
			if (iter->distance >= 95 && iter->distance <= 110 && !iter->impact)
			{
				iter->y += 1.5f;
				iter->rc.top += 2.0f;
				iter->rc.bottom += 2.0f;
			}
			iter->distance++;

			if (iter->x < 52)iter->impact = true;

			if (iter->index == 1)
			{
				SOUNDMANAGER->play("플레이어공격 부딪힘", 0.2f);
				iter->index++;
			}
			if (iter->impact)
			{
				
				if (_caricature[10])
				{
					if (iter->keyName == "공격")iter->keyName = "공격1";
					if (iter->keyName == "공격2") iter->keyName = "공격3";
				}
				else iter->keyName = "공격1";
				iter->indexTime += TIMEMANAGER->getElapsedTime();
				if (iter->indexTime > 0.1f)
				{
					iter->indexTime = 0;
					iter->index++;
					if (iter->index >= 11)
					{
						iter = _bullet.erase(iter);
					}
					else  ++iter;
				}
				else ++iter;
			}
			else if (iter->distance > 110)
			{
				iter->indexTime += TIMEMANAGER->getElapsedTime();
				if (iter->indexTime > 0.1f)
				{
					iter->indexTime = 0;
					iter->index++;
					if (iter->index >= 11)
					{
						iter = _bullet.erase(iter);
					}
					else  ++iter;
				}
				else ++iter;
			}
			else  ++iter;
		}
		else if (iter->direction == 3)
		{
			if (iter->distance <= 110 && !iter->impact)
			{
				iter->y -= 3.5f;
				iter->rc.bottom -= 2.9f;
				iter->rc.top -= 2.9f;
			}
			iter->distance++;

			if (iter->index == 1)
			{
				SOUNDMANAGER->play("플레이어공격 부딪힘", 0.2f);
				iter->index++;
			}
			if (iter->y < 115)iter->impact = true;
			if (iter->impact)
			{
				
				if (_caricature[10])
				{
					if (iter->keyName == "공격")iter->keyName = "공격1";
					if (iter->keyName == "공격2") iter->keyName = "공격3";
				}
				else iter->keyName = "공격1";

				iter->indexTime += TIMEMANAGER->getElapsedTime();
				if (iter->indexTime > 0.1f)
				{
					iter->indexTime = 0;
					iter->index++;
					if (iter->index >= 11)
					{
						iter = _bullet.erase(iter);
					}
					else  ++iter;
				}
				else ++iter;
			}
			else if (iter->distance > 110)
			{
				iter->indexTime += TIMEMANAGER->getElapsedTime();
				if (iter->indexTime > 0.1f)
				{
					iter->indexTime = 0;
					iter->index++;
					if (iter->index >= 11)
					{
						iter = _bullet.erase(iter);
					}
					else  ++iter;
				}
				else ++iter;
			}
			else  ++iter;
		}
		else ++iter;
	}

	//이동 방향
	//사탄 X
	if (!_satan)
	{
		if (KEYMANAGER->isStayKeyDown('S'))
		{

			_playerMovement = 3;
			if (_playerImage[0]->getY() < 485)_playerImage[0]->setY(_playerImage[0]->getY() + 1.5f + _playerInformation.speed);

			_imageIndex++;

			if (_imageIndex % 3 == 0)_playerImage[3]->setFrameX(_playerImage[3]->getFrameX() + 1);

			if (_playerImage[3]->getFrameX() >= 9)
			{
				_playerImage[3]->setFrameX(0);
			}
		}
		if (KEYMANAGER->isStayKeyDown('W'))
		{

			_playerMovement = 3;

			if (_playerImage[0]->getY() > 115)_playerImage[0]->setY(_playerImage[0]->getY() - (1.5f + _playerInformation.speed));

			_imageIndex++;

			if (_imageIndex % 3 == 0)_playerImage[3]->setFrameX(_playerImage[3]->getFrameX() - 1);

			if (_playerImage[3]->getFrameX() <= 0)
			{
				_playerImage[3]->setFrameX(9);
			}
		}
		if (KEYMANAGER->isStayKeyDown('A'))
		{

			_playerMovement = 1;
			if (82 < _playerImage[0]->getX())_playerImage[0]->setX(_playerImage[0]->getX() - (1.5f + _playerInformation.speed));
			_imageIndex++;

			if (_imageIndex % 3 == 0)_playerImage[1]->setFrameX(_playerImage[1]->getFrameX() + 1);


			if (_playerImage[1]->getFrameX() >= 9)
			{
				_playerImage[1]->setFrameX(0);
			}
		}
		if (KEYMANAGER->isStayKeyDown('D'))
		{

			_playerMovement = 2;
			if (_playerImage[0]->getX() < 675)_playerImage[0]->setX(_playerImage[0]->getX() + 1.5f + _playerInformation.speed);

			_imageIndex++;

			if (_imageIndex % 3 == 0)_playerImage[2]->setFrameX(_playerImage[2]->getFrameX() + 1);


			if (_playerImage[2]->getFrameX() >= 9)
			{
				_playerImage[2]->setFrameX(0);
			}
		}
		if (!KEYMANAGER->isStayKeyDown('D') && !KEYMANAGER->isStayKeyDown('A') && !KEYMANAGER->isStayKeyDown('W') && !KEYMANAGER->isStayKeyDown('S'))
		{
			_playerMovement = 0;
		}
	}

	// 미끄러짐 표현
#pragma region 
	if (KEYMANAGER->isOnceKeyUp('D') )
	{
		_sliding[0] = true;
	}
	if (KEYMANAGER->isOnceKeyUp('W'))
	{
		_sliding[1] = true;
	}
	if (KEYMANAGER->isOnceKeyUp('A'))
	{
		_sliding[2] = true;
	}
	if (KEYMANAGER->isOnceKeyUp('S'))
	{
		_sliding[3] = true;
	}
	if (_sliding[0])
	{
		_slidingTime[0]++;
		if (_slidingTime[0] > 30)
		{
			_sliding[0] = false;
			_slidingTime[0] = 0;
		}
		if (_playerImage[0]->getX() < 675)_playerImage[0]->setX(_playerImage[0]->getX() + 0.5f);
	}
	if (_sliding[1])
	{
		_slidingTime[1]++;
		if (_slidingTime[1] > 30)
		{
			_sliding[1] = false;
			_slidingTime[1] = 0;
		}
		if (_playerImage[0]->getY() > 115)_playerImage[0]->setY(_playerImage[0]->getY() - 0.5f);
	}
	if (_sliding[2])
	{
		_slidingTime[2]++;
		if (_slidingTime[2] > 30)
		{
			_sliding[2] = false;
			_slidingTime[2] = 0;
		}
		if (82 < _playerImage[0]->getX())_playerImage[0]->setX(_playerImage[0]->getX() - 0.5f);
	}
	if (_sliding[3])
	{
		_slidingTime[3]++;
		if (_slidingTime[3] > 30)
		{
		_sliding[3] = false;
		_slidingTime[3] = 0;
	    }
		if(_playerImage[0]->getY() < 485)_playerImage[0]->setY(_playerImage[0]->getY() + 0.5f);
	}
#pragma endregion

	//충돌 확인용
	if (KEYMANAGER->isOnceKeyDown('P'))
	{
		if (!_impact)_impact = true;
		else _impact = false;
	}
	//플레이어 충돌 네모 //템먹기전
	//if (!_caricature[5])_playerInformation.rc = RectMake(_playerImage[0]->getX()+8, _playerImage[0]->getY()+20, 25,32);
	//else _playerInformation.rc = RectMake(_playerImage[0]->getX() + 8, _playerImage[0]->getY() +10, 25, 32); //템먹고나서
	_playerInformation.rc = RectMake(_playerImage[0]->getX() + 8, _playerImage[0]->getY() + 20, 25, 32);
    if (_getItem)_playerImage[0]->setFrameX(9);



	//아이템 획득 플레이어 이미지 변경
	if (_caricature[8] && _caricature[7]) _playerImage[0]->setFrameY(3);
	else if (_caricature[7]) _playerImage[0]->setFrameY(2);
	else if (_caricature[8]) _playerImage[0]->setFrameY(1);

	//쉴드사용
	if (_caricature[9] && KEYMANAGER->isOnceKeyDown(VK_SPACE)&& _playerInformation.skileGage==6)
	{
		shield = true;
		_playerInformation.skileGage = 0;
	}
	if (shield)
	{
		shieldTime += TIMEMANAGER->getElapsedTime();
		//무적 시간
		if (shieldTime > 6.0f)
		{
			shieldTime = 0;
			shield = false;
			_playerInformation._invincibility = false;
		}
	}

	//무적시간,쉴드 무적
	if (_playerInformation._invincibility && !shield)
	{
	 if (!SOUNDMANAGER->isPlaySound("플레이어맞음"))
	 {
		 if (!_playerAtkSound) SOUNDMANAGER->play("플레이어맞음", 1.0f);
		 _playerAtkSound = true;
	 }
	 _tick += TIMEMANAGER->getElapsedTime();
	 if (_tick>=0.1f)
	 {
		 _tick = 0;
		 if (invincibilityTime == 255)invincibilityTime = 100;
		 else invincibilityTime = 255;
	 }
	}
	else
	{
	 _playerAtkSound = false;
	 invincibilityTime = 255;
	}

	 //Max체력 고정
	 if (_playerInformation.hp > 4) _playerInformation.hp = 4;
	 
	 //치트
	 if (KEYMANAGER->isOnceKeyDown('V'))
	 {
		 _playerInformation.money = 24;
		 _playerInformation.bomb = 10;
		 _playerInformation.key = 98;
	 }
	 if (KEYMANAGER->isOnceKeyDown('B'))
	 {
		 _playerInformation.hp=3;
	 }
	 if (KEYMANAGER->isOnceKeyDown('N'))
	 {
		 _playerInformation.hp +=0.5f;
	 }


	 if (_satan)
	 {
		 if (KEYMANAGER->isStayKeyDown('S'))
		 {
			 if (_playerImage[0]->getY() < 485)_playerImage[0]->setY(_playerImage[0]->getY() + 1.5f + _playerInformation.speed);
			 _satanFrameY = 2;

			 _satanFrameXTime += TIMEMANAGER->getElapsedTime();
			 if (_satanFrameXTime > 0.1f)
			 {
				 _satanFrameXTime = 0;
				 _satanFrameX++;
				 if (_satanFrameX > 9)_satanFrameX = 0;
			 }
		 }
		 if (KEYMANAGER->isStayKeyDown('W'))
		 {
			 if (_playerImage[0]->getY() > 115)_playerImage[0]->setY(_playerImage[0]->getY() - (1.5f + _playerInformation.speed));
			 _satanFrameY = 2;
			 _satanFrameXTime += TIMEMANAGER->getElapsedTime();
			 if (_satanFrameXTime > 0.1f)
			 {
				 _satanFrameXTime = 0;
				 _satanFrameX++;
			 }
			 if (_satanFrameX > 9)_satanFrameX = 0;
		 }
		 if (KEYMANAGER->isStayKeyDown('A'))
		 {
			 if (82 < _playerImage[0]->getX())_playerImage[0]->setX(_playerImage[0]->getX() - (1.5f + _playerInformation.speed));
			 _satanFrameY = 1;
			 _satanFrameXTime += TIMEMANAGER->getElapsedTime();
			 if (_satanFrameXTime > 0.1f)
			 {
				 _satanFrameXTime = 0;
				 _satanFrameX++;
			 }
			 if (_satanFrameX > 9)_satanFrameX = 0;
		 }
		 if (KEYMANAGER->isStayKeyDown('D'))
		 {
			 if (_playerImage[0]->getX() < 675)_playerImage[0]->setX(_playerImage[0]->getX() + 1.5f + _playerInformation.speed);
			 _satanFrameY = 0;
			 _satanFrameXTime += TIMEMANAGER->getElapsedTime();
			 if (_satanFrameXTime > 0.1f)
			 {
				 _satanFrameXTime = 0;
				 _satanFrameX++;
			 }
			 if (_satanFrameX > 9)_satanFrameX = 0;
		 }
		 if (!KEYMANAGER->isStayKeyDown('D') && !KEYMANAGER->isStayKeyDown('W') &&
			 !KEYMANAGER->isStayKeyDown('S') && !KEYMANAGER->isStayKeyDown('A'))
		 {
			 _satanFrameY = 2;
			 _satanFrameX = 0;
		 }

		 if (KEYMANAGER->isStayKeyDown(VK_LEFT))
		 {
			 _satanHeadFrameY = 3;
			 _satanAtkImage[0]->setFrameY(0);
			 _satanHeadFrameXTime += TIMEMANAGER->getElapsedTime();
			 if (_satanHeadFrameXTime > 0.25f)
			 {
				 if (_satanHeadFrameX < 6)_satanHeadFrameX++;
				 _satanHeadFrameXTime = 0;
			 }
		 }
		 if (KEYMANAGER->isStayKeyDown(VK_RIGHT))
		 {
			 _satanHeadFrameY = 1;
			 _satanAtkImage[0]->setFrameY(1);
			 _satanHeadFrameXTime += TIMEMANAGER->getElapsedTime();
			 if (_satanHeadFrameXTime > 0.25f)
			 {
				 if (_satanHeadFrameX < 6) _satanHeadFrameX++;
				 _satanHeadFrameXTime = 0;
			 }
		 }
		 if (KEYMANAGER->isStayKeyDown(VK_UP))
		 {
			 _satanHeadFrameY = 2;
			 _satanAtkImage[1]->setFrameY(0);
			 _satanHeadFrameXTime += TIMEMANAGER->getElapsedTime();
			 if (_satanHeadFrameXTime > 0.25f)
			 {
				 if (_satanHeadFrameX < 6) _satanHeadFrameX++;
				 _satanHeadFrameXTime = 0;
			 }
		 }
		 if (KEYMANAGER->isStayKeyDown(VK_DOWN))
		 {
			 _satanHeadFrameY = 0;
			 _satanAtkImage[1]->setFrameY(1);
			 _satanHeadFrameXTime += TIMEMANAGER->getElapsedTime();
			 if (_satanHeadFrameXTime > 0.25f)
			 {
				 if(_satanHeadFrameX<6)_satanHeadFrameX++;
				 _satanHeadFrameXTime = 0;
			 }
		 }
		 if (KEYMANAGER->isOnceKeyUp(VK_DOWN) || KEYMANAGER->isOnceKeyUp(VK_UP) ||
			 KEYMANAGER->isOnceKeyUp(VK_RIGHT) || KEYMANAGER->isOnceKeyUp(VK_LEFT))
		 {
			 _satanHeadFrameX = 7;
			 _satanAtk = false;
			 SOUNDMANAGER->play("혈사포", 0.1f);
		 }

		 if (_satanHeadFrameX == 7)
		 {
			 _satanAtkTime += TIMEMANAGER->getElapsedTime();
			 if (_satanAtkTime > 0.15f)
			 {
				 _satanAtkTime = 0;
				 _satanAtkImage[1]->setFrameX(_satanAtkImage[1]->getFrameX() + 1);
				 _satanAtkImage[0]->setFrameX(_satanAtkImage[0]->getFrameX() + 1);
				 if (_satanAtkImage[0]->getFrameX() >= 11 || _satanAtkImage[1]->getFrameX() >= 11)
				 {
					 _satanAtkImage[1]->setFrameX(0);
					 _satanAtkImage[0]->setFrameX(0);

					 _satanHeadFrameX = 0;
					 _satanHeadFrameY = 0;
					 _satanAtk = true;
				 }
			 }
		 }
	 }

	 if (_fly)
	 {
		 _flyFrameXTime += TIMEMANAGER->getElapsedTime();
		 if (_flyFrameXTime > 0.15f)
		 {
			 _flyFrameXTime = 0;
			 _flyImage[0]->setFrameX(_flyImage[0]->getFrameX() + 1);
			 _flyImage[1]->setFrameX(_flyImage[1]->getFrameX() + 1);
			 if (_flyImage[0]->getFrameX() > 1)
			 {
				 _flyImage[0]->setFrameX(0);
				 _flyImage[1]->setFrameX(0);
			 }
		 }

		 _c++;

		 _flyImage[0]->setX(cosf((_c)* PI / 180.0f) * 50 + _playerImage[0]->getX());
		 _flyImage[0]->setY(sinf((_c)* PI / 180.0f) * 50 + _playerImage[0]->getY()+10);

		 _flyImage[1]->setX(cosf((_c + 180)*PI / 180.0f) * 50 + _playerImage[0]->getX());
		 _flyImage[1]->setY(sinf((_c + 180)*PI / 180.0f) * 50 + _playerImage[0]->getY()+10);

		 _flyRc[0] = RectMake(_flyImage[0]->getX() + 14, _flyImage[0]->getY() + 13, 20, 15);
		 _flyRc[1] = RectMake(_flyImage[1]->getX() + 14, _flyImage[1]->getY() + 13, 20, 15);

	 }
}

void Player::render(void)
{ 

	for (int i = 0; i < _bomb.size(); i++)
	{
		if (_bomb[i].index < 43)
		{
			if (_bomb[i].index <= 26)IMAGEMANAGER->alphaRender("그림자", getMemDC(), _bomb[i].x + 177, _bomb[i].y + 146, 40);
			IMAGEMANAGER->frameRender("폭탄", getMemDC(), _bomb[i].x, _bomb[i].y, _bomb[i].index, 0);
		}
	}
	
	if (!_playerOut)
	{
	    IMAGEMANAGER->alphaRender("그림자", getMemDC(), _playerImage[0]->getX()-1.5, _playerImage[0]->getY()+37, 40);

		if (!_satan)
		{
			if (!_getItem && !_caricature[5])
			{
				switch (_playerMovement)
				{
				case 0:
					IMAGEMANAGER->alphaRender("몸통", getMemDC(), _playerImage[0]->getX() + 6, _playerImage[0]->getY() + 31, invincibilityTime);
					break;
				case 1:
					IMAGEMANAGER->alphaFrameRender("왼쪽", getMemDC(), _playerImage[0]->getX() + 10, _playerImage[0]->getY() + 31,
						invincibilityTime, _playerImage[1]->getFrameX(), _playerImage[1]->getFrameY());
					break;
				case 2:
					IMAGEMANAGER->alphaFrameRender("오른쪽", getMemDC(), _playerImage[0]->getX() + 9, _playerImage[0]->getY() + 31,
						invincibilityTime, _playerImage[2]->getFrameX(), _playerImage[2]->getFrameY());
					break;
				case 3:
					IMAGEMANAGER->alphaFrameRender("위아래", getMemDC(), _playerImage[0]->getX() + 6, _playerImage[0]->getY() + 32,
						invincibilityTime, _playerImage[3]->getFrameX(), _playerImage[3]->getFrameY());
					break;
				}
			}
			IMAGEMANAGER->alphaFrameRender("머리", getMemDC(), _playerImage[0]->getX() - 21, _playerImage[0]->getY() - 37,
				invincibilityTime, _playerImage[0]->getFrameX(), _playerImage[0]->getFrameY());
			if (_caricature[0] && !_getItem)IMAGEMANAGER->alphaRender("순교자의피", getMemDC(), _playerImage[0]->getX() - 5, _playerImage[0]->getY() - 20, invincibilityTime);
		}
		else
		{
			if(!_caricature[5])IMAGEMANAGER->alphaFrameRender("악마몸통", getMemDC(), _playerImage[0]->getX()-3 , _playerImage[0]->getY()+13,
				invincibilityTime, _satanFrameX, _satanFrameY);
			IMAGEMANAGER->alphaFrameRender("악마머리", getMemDC(), _playerImage[0]->getX()-27, _playerImage[0]->getY()-31,
				invincibilityTime, _satanHeadFrameX, _satanHeadFrameY);

			if (_satanHeadFrameX == 7 && !_satanAtk)
			{
				if (_satanHeadFrameY == 0)
				{
					IMAGEMANAGER->alphaFrameRender("혈사포Y", getMemDC(), _playerImage[0]->getX() - 13, _playerImage[0]->getY() + 13, 200, _satanAtkImage[1]->getFrameX(), _satanAtkImage[1]->getFrameY());
					_satanAtkRc = RectMake(_playerImage[0]->getX() - 5, _playerImage[0]->getY() + 50, 48,_cameraImpactrc.bottom - _playerImage[0]->getY() - 90);
				}
				if (_satanHeadFrameY == 1)
				{
					IMAGEMANAGER->alphaFrameRender("혈사포X", getMemDC(), _playerImage[0]->getX() + 28 , _playerImage[0]->getY()-10, 200, _satanAtkImage[0]->getFrameX(), _satanAtkImage[0]->getFrameY());
					_satanAtkRc = RectMake(_playerImage[0]->getX() + 40, _playerImage[0]->getY() ,_cameraImpactrc.right - _playerImage[0]->getX()-100, 45);
				}
				if (_satanHeadFrameY == 2)
				{
					IMAGEMANAGER->alphaFrameRender("혈사포Y", getMemDC(), _playerImage[0]->getX() - 13, _playerImage[0]->getY() - 807, 200, _satanAtkImage[1]->getFrameX(), _satanAtkImage[1]->getFrameY());
					_satanAtkRc = RectMake(_playerImage[0]->getX() - 5, _cameraImpactrc.top + 40, 48, _playerImage[0]->getY() - _cameraImpactrc.top -40);
				}
				if (_satanHeadFrameY == 3)
				{
					IMAGEMANAGER->alphaFrameRender("혈사포X", getMemDC(), _playerImage[0]->getX() - 880, _playerImage[0]->getY() - 10, 200, _satanAtkImage[0]->getFrameX(), _satanAtkImage[0]->getFrameY());
					_satanAtkRc = RectMake(_cameraImpactrc.left + 70, _playerImage[0]->getY(), _playerImage[0]->getX()- _cameraImpactrc.left -70, 45);
				}
			}
			else
			{
				_satanAtkRc = RectMake(5000, 5000, 0, 0);
			}

		}
	}
	//if(!_satanAtk)DrawRectMake(getMemDC(), _satanAtkRc);
	// 
	//볼렛랜더
	for (int i = 0; i < _bullet.size(); i++)
	{
		
			if (_bullet[i].keyName == "공격")IMAGEMANAGER->frameRender(_bullet[i].keyName, getMemDC(), _bullet[i].x, _bullet[i].y, _bullet[i].index, 0);
			else if(_bullet[i].keyName == "공격1") IMAGEMANAGER->frameRender(_bullet[i].keyName, getMemDC(), _bullet[i].x - 25, _bullet[i].y - 23, _bullet[i].index, 0);
			else if(_bullet[i].keyName == "공격2")IMAGEMANAGER->frameRender(_bullet[i].keyName, getMemDC(), _bullet[i].x, _bullet[i].y, _bullet[i].index, 0);
			else if(_bullet[i].keyName == "공격3")IMAGEMANAGER->frameRender(_bullet[i].keyName, getMemDC(), _bullet[i].x - 25, _bullet[i].y - 25, _bullet[i].index, 0);
		
		
		if (_impact)
		{
			DrawRectMake(getMemDC(), _bullet[i].rc);
		}
	
	}

	//폭탄 랜더
	for (int i = 0; i < _bomb.size(); i++)
	{
		//if(_bomb[i].index <= 26)IMAGEMANAGER->alphaRender("그림자", getMemDC(), _bomb[i].x+177, _bomb[i].y+146, 40);
		if(_bomb[i].index <= 43 && _bomb[i].y + 110  > _playerImage[0]->getY())IMAGEMANAGER->frameRender("폭탄", getMemDC(), _bomb[i].x, _bomb[i].y, _bomb[i].index, 0);
		if (_impact)
		{
			DrawRectMake(getMemDC(), _bomb[i].smallRc);
			DrawRectMake(getMemDC(), _bomb[i].rc);

		}
	}


	//플레이어 렉트확인
	if (_impact)
	{
		DrawRectMake(getMemDC(), _playerInformation.rc);
	}


	//아이템획득시 이펙트
	if (_getItem)
	{
		_starTime += TIMEMANAGER->getElapsedTime();
		if (_starTime > 0.05f)
		{
			_starTime = 0;
			_star->setFrameX(_star->getFrameX() + 1);

			if (_star->getFrameX() >= 11)
			{
				_star->setFrameX(0);
			}

		}

		IMAGEMANAGER->alphaFrameRender("스타", getMemDC(), _playerImage[0]->getX()-3, _playerImage[0]->getY() - 43,
			100, _star->getFrameX(), _star->getFrameY());

		if (!_satan)IMAGEMANAGER->render("만세", getMemDC(), _playerImage[0]->getX() + 2, _playerImage[0]->getY() + 29);
	}

	//쉴드 이펙트
	if(shield && !_caricature[5])IMAGEMANAGER->alphaRender("쉴드", getMemDC(), _playerImage[0]->getX() -12, _playerImage[0]->getY()-9,120);
	if (shield && _caricature[5])IMAGEMANAGER->alphaRender("쉴드", getMemDC(), _playerImage[0]->getX() - 12, _playerImage[0]->getY() - 15, 120);


	if (_fly)
	{
		IMAGEMANAGER->frameRender("파리떼이미지", getMemDC(), _flyImage[0]->getX(), _flyImage[0]->getY());
		IMAGEMANAGER->frameRender("파리떼이미지1", getMemDC(), _flyImage[1]->getX(), _flyImage[1]->getY());
	}

	//파리렉트 확인
	//DrawRectMake(getMemDC(), _flyRc[0]);
	//DrawRectMake(getMemDC(), _flyRc[1]);

}

void Player::renderBoom(void)
{
	for (int i = 0; i < _bomb.size(); i++)
	{
		if (_bomb[i].index >= 43)IMAGEMANAGER->frameRender("폭탄", getMemDC(), _bomb[i].x, _bomb[i].y, _bomb[i].index, 0);
	}
}

void Player::Set_ItemList(int idx, Item* item)
{
	_playerInformation.hp += item->Get_ItemList(idx)->hp;
	_playerInformation.money += item->Get_ItemList(idx)->money;
	_playerInformation.bomb += item->Get_ItemList(idx)->bomb;
	_playerInformation.key += item->Get_ItemList(idx)->key;
	_playerInformation.atk += item->Get_ItemList(idx)->atk;
	_playerInformation.speed += item->Get_ItemList(idx)->speed;
	_playerInformation.attackSpeed += item->Get_ItemList(idx)->attackSpeed;
	_playerInformation.intersection += item->Get_ItemList(idx)->intersection;
}

