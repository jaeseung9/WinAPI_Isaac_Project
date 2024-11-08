#include "Stdafx.h"
#include "GameSystemManager.h"

HRESULT GameSystemManager::init(void)
{
	//����
	SOUNDMANAGER->addSound("������ȹ��", "Resources/Sounds/������ȹ��.mp3", false, false);

	SOUNDMANAGER->addSound("��乮", "Resources/Sounds/��乮.wav", false, false);

	SOUNDMANAGER->addSound("�ΰ��ӻ���", "Resources/Sounds/�ΰ��ӻ���.mp3", true, true);
	
    IMAGEMANAGER->addFrameImage
    ("book", "Resources/Images/Item/book1.bmp", 64 / 1.5, 180 / 1.5, 1, 2, true, RGB(255, 0, 255));
 
    _operationkey = IMAGEMANAGER->addImage("����Ű", "Resources/Images/Ui/����Ű.bmp",
 	661 / 1.25, 200 / 1.25, true, RGB(255, 0, 255));
 
    _operationkey->setX(137);
    _operationkey->setY(180);
 
       IMAGEMANAGER->addFrameImage("1����������", "Resources/Images/Monster/1����������.bmp",
 	WINSIZE_X * 25, WINSIZE_Y, 25, 1, true, RGB(255, 0, 255));
 
    IMAGEMANAGER->addFrameImage("2����������", "Resources/Images/Monster/2����������.bmp",
 	   WINSIZE_X * 25, WINSIZE_Y, 25, 1, true, RGB(255, 0, 255));
 
    IMAGEMANAGER->addFrameImage("3����������", "Resources/Images/Monster/3����������.bmp",
 	   WINSIZE_X * 25, WINSIZE_Y, 25, 1, true, RGB(255, 0, 255));
 
    IMAGEMANAGER->addFrameImage("4����������", "Resources/Images/Monster/4����������.bmp",
 	   WINSIZE_X * 25, WINSIZE_Y, 25, 1, true, RGB(255, 0, 255));
 
    _bossClear[0] = IMAGEMANAGER->addFrameImage("1��Ŭ����", "Resources/Images/Monster/1��Ŭ����.bmp",
 	   WINSIZE_X * 46, WINSIZE_Y, 46, 1, true, RGB(255, 0, 255));
 
    _bossClear[1] = IMAGEMANAGER->addFrameImage("2��Ŭ����", "Resources/Images/Monster/2��Ŭ����.bmp",
 	   WINSIZE_X * 46, WINSIZE_Y, 46, 1, true, RGB(255, 0, 255));
    
    _bossClear[2] = IMAGEMANAGER->addFrameImage("3��Ŭ����", "Resources/Images/Monster/3��Ŭ����.bmp",
 	   WINSIZE_X * 46, WINSIZE_Y, 46, 1, true, RGB(255, 0, 255));


#pragma region �̹���
	_tileImg[0] = IMAGEMANAGER->addImage("�ٴ�Ÿ�ϱ׸�", "Resources/Images/Map/Ÿ�ϸ�1.bmp",
		208, 312, true, RGB(255, 0, 255));
	_tileImg[1] = IMAGEMANAGER->addImage("�ٴ�Ÿ�ϱ׸�1", "Resources/Images/Map/Ÿ�ϸ�2.bmp",
		208, 312, true, RGB(255, 0, 255));
	_tileImg[2] = IMAGEMANAGER->addImage("�ٴ�Ÿ�ϱ׸�2", "Resources/Images/Map/Ÿ�ϸ�3.bmp",
		208, 312, true, RGB(255, 0, 255));
	_tileImg[3] = IMAGEMANAGER->addImage("�ٴ�Ÿ�ϱ׸�3", "Resources/Images/Map/Ÿ�ϸ�4.bmp",
		208, 312, true, RGB(255, 0, 255));
	_tileImg[4] = IMAGEMANAGER->addImage("�ٴ�Ÿ�ϱ׸�4", "Resources/Images/Map/Ÿ�ϸ�5.bmp",
		208, 312, true, RGB(255, 0, 255));
	_tileImg[5] = IMAGEMANAGER->addImage("������Ʈ�׸�", "Resources/Images/Map/Door.bmp",
		208, 312, true, RGB(255, 0, 255));
	_tileImg[6] = IMAGEMANAGER->addImage("���ͱ׸�", "Resources/Images/Map/object.bmp",
		208, 312, true, RGB(255, 0, 255));
	_tileImg[7] = IMAGEMANAGER->addImage("����", "Resources/Images/Map/Monster.bmp",
		208, 312, true, RGB(255, 0, 255));
	_tileImg[8] = IMAGEMANAGER->addImage("����", "Resources/Images/Map/Boss.bmp",
		208, 312, true, RGB(255, 0, 255));


	_tileGround[0] = IMAGEMANAGER->addFrameImage("�ٴ�Ÿ��", "Resources/Images/Map/Ÿ�ϸ�1.bmp",
		208, 312, 4, 6, true, RGB(255, 0, 255));
	_tileGround[1] = IMAGEMANAGER->addFrameImage("�ٴ�Ÿ��1", "Resources/Images/Map/Ÿ�ϸ�2.bmp",
		208, 312, 4, 6, true, RGB(255, 0, 255));
	_tileGround[2] = IMAGEMANAGER->addFrameImage("�ٴ�Ÿ��2", "Resources/Images/Map/Ÿ�ϸ�3.bmp",
		208, 312, 4, 6, true, RGB(255, 0, 255));
	_tileGround[3] = IMAGEMANAGER->addFrameImage("�ٴ�Ÿ��3", "Resources/Images/Map/Ÿ�ϸ�4.bmp",
		208, 312, 4, 6, true, RGB(255, 0, 255));
	_tileGround[4] = IMAGEMANAGER->addFrameImage("�ٴ�Ÿ��4", "Resources/Images/Map/Ÿ�ϸ�5.bmp",
		208, 312, 4, 6, true, RGB(255, 0, 255));
	_tileGround[5] = IMAGEMANAGER->addFrameImage("������ƮŸ��", "Resources/Images/Map/Door.bmp",
		208, 312, 4, 6, true, RGB(255, 0, 255));
	_tileGround[6] = IMAGEMANAGER->addFrameImage("����Ÿ��", "Resources/Images/Map/object.bmp",
		208, 312, 4, 6, true, RGB(255, 0, 255));
	_tileGround[7] = IMAGEMANAGER->addFrameImage("����Ÿ��1", "Resources/Images/Map/Monster.bmp",
		208, 312, 4, 6, true, RGB(255, 0, 255));
	_tileGround[8] = IMAGEMANAGER->addFrameImage("����1", "Resources/Images/Map/Boss.bmp",
		208, 312, 4, 6, true, RGB(255, 0, 255));


	IMAGEMANAGER->addImage("����0", "Resources/Images/Ui/Item0Name.bmp", 901 / 2, 197 / 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("����1", "Resources/Images/Ui/Item1Name.bmp", 901 / 2, 197 / 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("����2", "Resources/Images/Ui/Item2Name.bmp", 901 / 2, 197 / 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("����3", "Resources/Images/Ui/Item3Name.bmp", 901 / 2, 197 / 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("����4", "Resources/Images/Ui/Item4Name.bmp", 901 / 2, 197 / 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("����5", "Resources/Images/Ui/Item5Name.bmp", 901 / 2, 197 / 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("����6", "Resources/Images/Ui/Item6Name.bmp", 901 / 2, 197 / 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("����7", "Resources/Images/Ui/Item7Name.bmp", 901 / 2, 197 / 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("����8", "Resources/Images/Ui/Item8Name.bmp", 901 / 2, 197 / 2, true, RGB(255, 0, 255));

	//�̴ϸ� �̹���
	IMAGEMANAGER->addImage("1������", "Resources/Images/Map/1������.bmp", 350, 160, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("2������", "Resources/Images/Map/2������.bmp", 350, 160, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("3������", "Resources/Images/Map/3������.bmp", 350, 160, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("4������", "Resources/Images/Map/4������.bmp", 350, 160, true, RGB(255, 0, 255));

#pragma endregion

	_player = new Player;
	_player->init();
	_ui = new Ui;
	_ui->init();
	_monster = new Monster;
	_monster->init();
	_item = new Item;
	_item->init();
	_object = new Object;
	_object->init();


	_keyValue[0] = "�ٴ�Ÿ��";
	_keyValue[1] = "�ٴ�Ÿ��1";
	_keyValue[2] = "�ٴ�Ÿ��2";
	_keyValue[3] = "�ٴ�Ÿ��3";
	_keyValue[4] = "�ٴ�Ÿ��4";
	_keyValue[5] = "������ƮŸ��";
	_keyValue[6] = "����Ÿ��";
	_keyValue[7] = "����Ÿ��1";
	_keyValue[8] = "����1";


	for (int i = 0; i < MAX_MAP_SIZE; i++)
	{
		for (int j = 0; j < MAX_MAP_SIZE; j++)
		{
			_baseTileRC[i][j] = RectMake((88 * j) - 87 - 468, 75 + 77 * i, 88, 77);
		}
	}

	_MapM = 0;



	_getItem = false;
	animTime = 0;
	for (int i = 0; i < 20; i++)
	{
		_caricature[i] = false;
	    _hooray[i] = false;
    }

	_invincibilityTime = 0;

	
	_map = RectMake(120, 180, 550, 330);


	_monster->update();
	_item->update();
	
	x = 0;
	y = 0;

	_monsterNum = 0;

	_mapMoveY = 539;
	_mapMoveX = 792;
	//540

	_mapX = 1583;
	_mapY = 1080;

	_frameTime = 0;
	for (int i = 0; i < 4; i++)
	{
		_bossClearVideo[i] = false;
	}
	_bossClearVideoEnd = false;
	_bossIndex = 0;
	// x ��ĭ�� 791
	// y ��ĭ�� -540

	_mapName = "1floor.json";
    //_mapName = "2floor.json";
	//_mapName = "3floor.json";

	LodeMap();

	_shild = false;
	_soundStart = false;

	_miniMap = RectMake(141, 41, 29, 10);
	_itemMoney[0] = false;
	_itemMoney[1] = false;
	_itemMoney[2] = false;

	return S_OK;
}

void GameSystemManager::release(void)
{
}

void GameSystemManager::update(void)
{
	if (!_soundStart)
	{
		_soundStart = true;
		SOUNDMANAGER->play("�ΰ��ӻ���", 1.0f);
	}
	// ����â ������ ���� �÷��̾� ����


	//�÷��̾� ���� Ui�� ����
	_ui->Set_PlayerInformation(_player->Get_PlayerInformation()->hp, _player->Get_PlayerInformation()->speed,
		                       _player->Get_PlayerInformation()->attackSpeed,_player->Get_PlayerInformation()->atk,
		                       _player->Get_PlayerInformation()->intersection,_player->Get_PlayerInformation()->money,
		                       _player->Get_PlayerInformation()->bomb, _player->Get_PlayerInformation()->key,_player->Get_PlayerInformation()->skileGage);

	//�÷��̾� ���� ���Ϳ� ����
	_monster->Set_PlayerInformation(_player->Get_PlayerInformation()->hp, _player->Get_PlayerInformation()->speed,
		                       _player->Get_PlayerInformation()->attackSpeed, _player->Get_PlayerInformation()->atk,
		                       _player->Get_PlayerInformation()->intersection, _player->Get_PlayerInformation()->money,
		                       _player->Get_PlayerInformation()->bomb, _player->Get_PlayerInformation()->key,
		                       _player->Get_PlayerInformation()->rc);

	// UI ���� Ȯ�� ���� �ޱ�
	Set_Information(_ui->Get_Information());

	_ui->update();


	if (!_Information)
	{
		_player->update();
		_monster->update();
		_item->update();
		_object->update();
	}
	
	
	//������ ȹ���� �÷��̾� �̹��� ��ȯ �Ұ�
	if (_getItem)
	{
		animTime += TIMEMANAGER->getElapsedTime();
		if (animTime > 2.0f)
		{
			_getItem = false;
			animTime = 0;
			
		}
	}


	//�÷��̾����� �Ұ� �Ѱ��ֱ�
	_player->Set_GetItem(_getItem);


	//�÷��̾����� ����������Ȯ�� �Ұ� �Ѱ��ֱ�
	for (int i = 0; i < 20; i++)
	{
		_player->Set_hooray(i, _hooray[i]);
		_player->Set_caricature(i, _caricature[i]);

		//����Ȯ�� ui���� �Ѱ��ֱ�
		_ui->Set_caricature(i, _caricature[i]);
	}

	//���ͼ�
	for (int k = 0; k < 30; k++)
	{
		//���� �÷��̾� �ǰ�����
		for (int i = 0; i < _monster->Get_MonsterInformation(k)->size(); i++)
		{
			if (IntersectRect(&_impact, &_monster->Get_MonsterInformation(k)[0][i].rc, &_player->Get_PlayerInformation()->rc) &&
				!_player->Get_PlayerInformation()->_invincibility)
			{
				_player->Get_PlayerInformation()->hp -= _monster->Get_MonsterInformation(k)[0][i].atk;
				_player->Get_PlayerInformation()->_invincibility = true;
			}
		}

		//������¸��� ū��Ʈ �浹
		for (int i = 0; i < _monster->Get_MonsterInformation(4)->size(); i++)
		{
			if (IntersectRect(&_impact, &_monster->Get_MonsterInformation(4)[0][i].plrc, &_player->Get_PlayerInformation()->rc)&&
				!_monster->Get_MonsterInformation(4)[0][i].impact)
			{
				_monster->Get_MonsterInformation(4)[0][i].impact = true;
				_monster->Get_MonsterInformation(4)[0][i].speed = 1.0f;
				_monster->Get_MonsterInformation(4)[0][i].frameTime = 0;
			}
		}
		//�󱼸� �ִ� ���� �Ÿ�����
		for (int i = 0; i < _monster->Get_MonsterInformation(5)->size(); i++)
		{
			if (IntersectRect(&_impact, &_monster->Get_MonsterInformation(5)[0][i].plrc, &_player->Get_PlayerInformation()->rc))
			{
				_monster->Get_MonsterInformation(5)[0][i].atktrue = true;
			}
			else _monster->Get_MonsterInformation(5)[0][i].atktrue = false;
		}
		//�󱼸� �ִ� ���� �Ÿ�����
		for (int i = 0; i < _monster->Get_MonsterInformation(6)->size(); i++)
		{
			if (IntersectRect(&_impact, &_monster->Get_MonsterInformation(6)[0][i].plrc, &_player->Get_PlayerInformation()->rc))
			{
				_monster->Get_MonsterInformation(6)[0][i].impact = true;
			}
		}

		for (int i = 0; i < _monster->Get_MonsterInformation(k)->size(); i++)
		{
			if(IntersectRect(&_impact, &_monster->Get_MonsterInformation(k)[0][i].rc, &_player->Get_PlayerInformation()->rc))
			{
				if ((_player->Get_PlayerInformation()->rc.right + _player->Get_PlayerInformation()->rc.left) / 2 < _monster->Get_MonsterInformation(k)[0][i].rc.left)
				{
					(*_player->Get_Gimage())->setX((*_player->Get_Gimage())->getX() - 1);
					_monster->Get_MonsterInformation(k)[0][i].x += 1.0f;
				}
				if ((_player->Get_PlayerInformation()->rc.right + _player->Get_PlayerInformation()->rc.left) / 2 > _monster->Get_MonsterInformation(k)[0][i].rc.right)
				{
					(*_player->Get_Gimage())->setX((*_player->Get_Gimage())->getX() + 1);
					_monster->Get_MonsterInformation(k)[0][i].x -= 1.0f;
				}
				if ((_player->Get_PlayerInformation()->rc.top + _player->Get_PlayerInformation()->rc.bottom) / 2 < _monster->Get_MonsterInformation(k)[0][i].rc.bottom)
				{
					(*_player->Get_Gimage())->setY((*_player->Get_Gimage())->getY() + 1);
					_monster->Get_MonsterInformation(k)[0][i].y -= 1.0f;
				}
				if ((_player->Get_PlayerInformation()->rc.top + _player->Get_PlayerInformation()->rc.bottom) / 2 > _monster->Get_MonsterInformation(k)[0][i].rc.top)
				{
					(*_player->Get_Gimage())->setY((*_player->Get_Gimage())->getY() - 1);
					_monster->Get_MonsterInformation(k)[0][i].y += 1.0f;
				}
			}
		}


	}

	//����Ÿ��
	if (_player->Get_PlayerInformation()->_invincibility)
	{
		_invincibilityTime += TIMEMANAGER->getElapsedTime();

		if (_invincibilityTime > 3)
		{
			_player->Get_PlayerInformation()->_invincibility = false;
			_invincibilityTime = 0;
		}
	}

	//�÷��̾� ���� �浹 ����
	for (int i = 0; i < _player->Get_Bullet()->size(); i++)
	{
		//������
		for (int j = 0; j < _monster->Get_MonsterInformation(0)->size(); j++)
		{
			if (IntersectRect(&_impact, &_player->Get_Bullet()[0][i].rc, &_monster->Get_MonsterInformation(0)[0][j].rc))
			{
				if (!_player->Get_Bullet()[0][i].impact)_monster->Get_MonsterInformation(0)[0][j].hp -= _player->Get_PlayerInformation()->atk;
				_player->Get_Bullet()[0][i].impact = true;

				if (_monster->Get_MonsterInformation(0)[0][j].hp <= 0)
				{
					_player->Get_PlayerInformation()->skileGage++;
					if (_player->Get_PlayerInformation()->skileGage > 6)_player->Get_PlayerInformation()->skileGage = 6;
				}
			}
		}
		//�Ӹ�����
		for (int j = 0; j < _monster->Get_MonsterInformation(1)->size(); j++)
		{

			if (IntersectRect(&_impact, &_player->Get_Bullet()[0][i].rc, &_monster->Get_MonsterInformation(1)[0][j].rc))
			{
				if (!_player->Get_Bullet()[0][i].impact)_monster->Get_MonsterInformation(1)[0][j].hp -= _player->Get_PlayerInformation()->atk;
				_player->Get_Bullet()[0][i].impact = true;

				if (_monster->Get_MonsterInformation(1)[0][j].hp <= 0)
				{
					_player->Get_PlayerInformation()->skileGage++;
					if (_player->Get_PlayerInformation()->skileGage > 6)_player->Get_PlayerInformation()->skileGage = 6;
				}
			}
		}
		//������
		for (int j = 0; j < _monster->Get_MonsterInformation(2)->size(); j++)
		{
			if (IntersectRect(&_impact, &_player->Get_Bullet()[0][i].rc, &_monster->Get_MonsterInformation(2)[0][j].rc))
			{
				if (!_player->Get_Bullet()[0][i].impact)_monster->Get_MonsterInformation(2)[0][j].hp -= _player->Get_PlayerInformation()->atk;
				_player->Get_Bullet()[0][i].impact = true;

				if (_monster->Get_MonsterInformation(2)[0][j].hp <= 0)
				{
					_player->Get_PlayerInformation()->skileGage++;
					if (_player->Get_PlayerInformation()->skileGage > 6)_player->Get_PlayerInformation()->skileGage = 6;
				}

			}
		}
		//������
		for (int j = 0; j < _monster->Get_MonsterInformation(3)->size(); j++)
		{
			if (IntersectRect(&_impact, &_player->Get_Bullet()[0][i].rc, &_monster->Get_MonsterInformation(3)[0][j].rc))
			{
				if (!_player->Get_Bullet()[0][i].impact)_monster->Get_MonsterInformation(3)[0][j].hp -= _player->Get_PlayerInformation()->atk;
				_player->Get_Bullet()[0][i].impact = true;

				if (_monster->Get_MonsterInformation(3)[0][j].hp <= 0)
				{
					_player->Get_PlayerInformation()->skileGage++;
					if (_player->Get_PlayerInformation()->skileGage > 6)_player->Get_PlayerInformation()->skileGage = 6;
				}

			}
		}
		//�󱼴޸�����
		for (int j = 0; j < _monster->Get_MonsterInformation(4)->size(); j++)
		{
			if (IntersectRect(&_impact, &_player->Get_Bullet()[0][i].rc, &_monster->Get_MonsterInformation(4)[0][j].rc))
			{
				if (!_player->Get_Bullet()[0][i].impact)_monster->Get_MonsterInformation(4)[0][j].hp -= _player->Get_PlayerInformation()->atk;
				_player->Get_Bullet()[0][i].impact = true;

				if (_monster->Get_MonsterInformation(4)[0][j].hp <= 0)
				{
					_player->Get_PlayerInformation()->skileGage++;
					if (_player->Get_PlayerInformation()->skileGage > 6)_player->Get_PlayerInformation()->skileGage = 6;
				}

			}
		}
		//�󱼸��ִ¸���
		for (int j = 0; j < _monster->Get_MonsterInformation(5)->size(); j++)
		{
			if (IntersectRect(&_impact, &_player->Get_Bullet()[0][i].rc, &_monster->Get_MonsterInformation(5)[0][j].rc))
			{
				if (!_player->Get_Bullet()[0][i].impact)_monster->Get_MonsterInformation(5)[0][j].hp -= _player->Get_PlayerInformation()->atk;
				_player->Get_Bullet()[0][i].impact = true;

				if (_monster->Get_MonsterInformation(5)[0][j].hp <= 0)
				{
					_player->Get_PlayerInformation()->skileGage++;
					if (_player->Get_PlayerInformation()->skileGage > 6)_player->Get_PlayerInformation()->skileGage = 6;
				}

			}
		}
		//���и���
		for (int j = 0; j < _monster->Get_MonsterInformation(6)->size(); j++)
		{
			if (IntersectRect(&_impact, &_player->Get_Bullet()[0][i].rc, &_monster->Get_MonsterInformation(6)[0][j].rc))
			{
				if (!_player->Get_Bullet()[0][i].impact && _monster->Get_MonsterInformation(6)[0][j].frameX == 1)
				{
					_monster->Get_MonsterInformation(6)[0][j].hp -= _player->Get_PlayerInformation()->atk;
				}

				_player->Get_Bullet()[0][i].impact = true;

				if (_monster->Get_MonsterInformation(6)[0][j].hp <= 0)
				{
					_player->Get_PlayerInformation()->skileGage++;
					if (_player->Get_PlayerInformation()->skileGage > 6)_player->Get_PlayerInformation()->skileGage = 6;
				}
			}
		}
		//����
		for (int j = 0; j < _monster->Get_MonsterInformation(7)->size(); j++)
		{
			if (IntersectRect(&_impact, &_player->Get_Bullet()[0][i].rc, &_monster->Get_MonsterInformation(7)[0][j].rc))
			{
				_monster->Get_MonsterInformation(7)[0][j].impact = true;

				if (!_player->Get_Bullet()[0][i].impact)_monster->Get_MonsterInformation(7)[0][j].hp -= _player->Get_PlayerInformation()->atk-0.9;
				_player->Get_Bullet()[0][i].impact = true;

				if (_monster->Get_MonsterInformation(7)[0][j].hp <= 0)
				{
					_player->Get_PlayerInformation()->skileGage++;
					if (_player->Get_PlayerInformation()->skileGage > 6)_player->Get_PlayerInformation()->skileGage = 6;


					object ob2;
					ob2.x = (_map.left + _map.right) / 2 - 25;
					ob2.y = (_map.top + _map.bottom) / 2 - 25 + 60;
					ob2.impact = false;
					ob2.frameX = 0;
					ob2.frameY = 0;
					ob2.open = false;
					ob2.alpha = 0;
					ob2.frameXTime = 0;
					ob2.Name = "Stone3";
					_object->Get_ObjectSton(3)[0].push_back(ob2);

					_item->Get_ItemList(5)->rc.left = (_map.left + _map.right) / 2 - 25 + 27;
					_item->Get_ItemList(5)->rc.right = (_map.left + _map.right) / 2 - 25 + 57;
					_item->Get_ItemList(5)->rc.top = (_map.top + _map.bottom) / 2 - 25 + 60;
					_item->Get_ItemList(5)->rc.bottom = (_map.top + _map.bottom) / 2 - 25 + 30 + 90;

					object ob4;
					ob4.x = (_map.left + _map.right) / 2 - 30;
					ob4.y = (_map.top + _map.bottom) / 2 - 25 - 160;
					ob4.impact = false;
					ob4.frameX = 0;
					ob4.frameY = 0;
					ob4.open = false;
					ob4.alpha = 0;
					ob4.frameXTime = 0;
					ob4.Name = "����Ŭ���";
					(*_object->Get_ObjectBossDoor1()).push_back(ob4);

					_mapName = "3floor.json";

					_item->Get_ItemList(0)->rc.bottom = -107;
					_item->Get_ItemList(0)->rc.top = -227;
					_item->Get_ItemList(0)->rc.left = -1190;
					_item->Get_ItemList(0)->rc.right = -1167;

			
					_bossIndex = 1;
				}

			}
		}
		//�������ĸ�
		for (int j = 0; j < _monster->Get_MonsterInformation(29)->size(); j++)
		{
			if (IntersectRect(&_impact, &_player->Get_Bullet()[0][i].rc, &_monster->Get_MonsterInformation(29)[0][j].rc))
			{
				if (!_player->Get_Bullet()[0][i].impact)_monster->Get_MonsterInformation(29)[0][j].hp -= _player->Get_PlayerInformation()->atk;
				_player->Get_Bullet()[0][i].impact = true;

				if (_monster->Get_MonsterInformation(29)[0][j].hp <= 0)
				{
					_player->Get_PlayerInformation()->skileGage++;
					if (_player->Get_PlayerInformation()->skileGage > 6)_player->Get_PlayerInformation()->skileGage = 6;
				}

			}
		}
		//����1
			for (int j = 0; j < _monster->Get_MonsterInformation(8)->size(); j++)
			{
				if (IntersectRect(&_impact, &_player->Get_Bullet()[0][i].rc, &_monster->Get_MonsterInformation(8)[0][j].rc))
				{
					_monster->Get_MonsterInformation(8)[0][j].impact = true;

					if (!_player->Get_Bullet()[0][i].impact)_monster->Get_MonsterInformation(9)[0][0].hp -= _player->Get_PlayerInformation()->atk-0.9;
					_player->Get_Bullet()[0][i].impact = true;

					if (_monster->Get_MonsterInformation(8)[0][j].hp <= 0)
					{
						_player->Get_PlayerInformation()->skileGage++;
						if (_player->Get_PlayerInformation()->skileGage > 6)_player->Get_PlayerInformation()->skileGage = 6;
					}
				}
			}
		
		//����1��
		for (int j = 0; j < _monster->Get_MonsterInformation(9)->size(); j++)
		{
			if (IntersectRect(&_impact, &_player->Get_Bullet()[0][i].rc, &_monster->Get_MonsterInformation(9)[0][j].rc))
			{
				_monster->Get_MonsterInformation(9)[0][j].impact = true;

				if (!_player->Get_Bullet()[0][i].impact)_monster->Get_MonsterInformation(9)[0][j].hp -= _player->Get_PlayerInformation()->atk - 0.9;
					_player->Get_Bullet()[0][i].impact = true;
				
				if (_monster->Get_MonsterInformation(9)[0][j].hp <= 0)
				{
					_player->Get_PlayerInformation()->skileGage++;
					if (_player->Get_PlayerInformation()->skileGage > 6)_player->Get_PlayerInformation()->skileGage = 6;

				}
			}
		}

		//����
		for (int j = 0; j < _monster->Get_MonsterInformation(10)->size(); j++)
		{
			if (IntersectRect(&_impact, &_player->Get_Bullet()[0][i].rc, &_monster->Get_MonsterInformation(10)[0][j].rc))
			{
				_player->Get_Bullet()[0][i].impact = true;	
			}

			if (IntersectRect(&_impact, &_player->Get_Bullet()[0][i].rc, &_monster->Get_MonsterInformation(10)[0][j].plrc))
			{
				if (_monster->Get_MonsterInformation(10)[0][j].frameY == 1)
				{
					if (!_player->Get_Bullet()[0][i].impact)_monster->Get_MonsterInformation(10)[0][j].impact = true;
					if (!_player->Get_Bullet()[0][i].impact)_monster->Get_MonsterInformation(10)[0][j].hp -= _player->Get_PlayerInformation()->atk - 0.9;
					_player->Get_Bullet()[0][i].impact = true;
				}
			}

			if (_monster->Get_MonsterInformation(10)[0][j].hp <= 0)
			{
				_player->Get_PlayerInformation()->skileGage++;
				if (_player->Get_PlayerInformation()->skileGage > 6)_player->Get_PlayerInformation()->skileGage = 6;

				object ob2;
				ob2.x = (_map.left + _map.right) / 2 - 25;
				ob2.y = (_map.top + _map.bottom) / 2 - 25 + 60;
				ob2.impact = false;
				ob2.frameX = 0;
				ob2.frameY = 0;
				ob2.open = false;
				ob2.alpha = 0;
				ob2.frameXTime = 0;
				ob2.Name = "Stone3";
				_object->Get_ObjectSton(3)[0].push_back(ob2);

				object ob3;
				ob3.x = (_map.left + _map.right) / 2 - 25 + 60;
				ob3.y = (_map.top + _map.bottom) / 2 - 25 + 60;
				ob3.impact = false;
				ob3.frameX = 0;
				ob3.frameY = 0;
				ob3.open = false;
				ob3.alpha = 0;
				ob3.frameXTime = 0;
				ob3.Name = "Stone3";
				_object->Get_ObjectSton(3)[0].push_back(ob3);

				object ob4;
				ob4.x = (_map.left + _map.right) / 2 - 25 - 60;
				ob4.y = (_map.top + _map.bottom) / 2 - 25 + 60;
				ob4.impact = false;
				ob4.frameX = 0;
				ob4.frameY = 0;
				ob4.open = false;
				ob4.alpha = 0;
				ob4.frameXTime = 0;
				ob4.Name = "Stone3";
				_object->Get_ObjectSton(3)[0].push_back(ob4);

				object ob5;
				ob5.x = (_map.left + _map.right) / 2 - 25 + 120;
				ob5.y = (_map.top + _map.bottom) / 2 - 25 + 60;
				ob5.impact = false;
				ob5.frameX = 0;
				ob5.frameY = 0;
				ob5.open = false;
				ob5.alpha = 0;
				ob5.frameXTime = 0;
				ob5.Name = "Stone3";
				_object->Get_ObjectSton(3)[0].push_back(ob5);

				_item->Get_ItemList(1)->rc.left = (_map.left + _map.right) / 2 - 25 + 27 -60;
				_item->Get_ItemList(1)->rc.right = (_map.left + _map.right) / 2 - 25 + 57 -60;
				_item->Get_ItemList(1)->rc.top = (_map.top + _map.bottom) / 2 - 25 + 60;
				_item->Get_ItemList(1)->rc.bottom = (_map.top + _map.bottom) / 2 - 25 + 30 + 90;

				_item->Get_ItemList(4)->rc.left = (_map.left + _map.right) / 2 - 25 + 27;
				_item->Get_ItemList(4)->rc.right = (_map.left + _map.right) / 2 - 25 + 57;
				_item->Get_ItemList(4)->rc.top = (_map.top + _map.bottom) / 2 - 25 + 60;
				_item->Get_ItemList(4)->rc.bottom = (_map.top + _map.bottom) / 2 - 25 + 30 + 90;

				_item->Get_ItemList(8)->rc.left = (_map.left + _map.right) / 2 - 25 + 27 + 60;
				_item->Get_ItemList(8)->rc.right = (_map.left + _map.right) / 2 - 25 + 57 + 60;
				_item->Get_ItemList(8)->rc.top = (_map.top + _map.bottom) / 2 - 25 + 60;
				_item->Get_ItemList(8)->rc.bottom = (_map.top + _map.bottom) / 2 - 25 + 30 + 90;

				_item->Get_ItemList(11)->rc.left = (_map.left + _map.right) / 2 - 25 + 27 + 120;
				_item->Get_ItemList(11)->rc.right = (_map.left + _map.right) / 2 - 25 + 57 + 120;
				_item->Get_ItemList(11)->rc.top = (_map.top + _map.bottom) / 2 - 25 + 60;
				_item->Get_ItemList(11)->rc.bottom = (_map.top + _map.bottom) / 2 - 25 + 30 + 90;



				object ob6;
				ob6.x = (_map.left + _map.right) / 2 - 30;
				ob6.y = (_map.top + _map.bottom) / 2 - 25 - 160;
				ob6.impact = false;
				ob6.frameX = 0;
				ob6.frameY = 0;
				ob6.open = false;
				ob6.alpha = 0;
				ob6.frameXTime = 0;
				ob6.Name = "����Ŭ���";
				(*_object->Get_ObjectBossDoor1()).push_back(ob6);

				_mapName = "4floor.json";

				_bossIndex = 2;
			}
		}

		//����
		for (int j = 0; j < _monster->Get_MonsterInformation(11)->size(); j++)
		{
			if (IntersectRect(&_impact, &_player->Get_Bullet()[0][i].rc, &_monster->Get_MonsterInformation(11)[0][j].rc))
			{
			    _monster->Get_MonsterInformation(11)[0][j].impact = true;
			    if (!_player->Get_Bullet()[0][i].impact)_monster->Get_MonsterInformation(10)[0][0].hp -= _player->Get_PlayerInformation()->atk - 0.9;

				_player->Get_Bullet()[0][i].impact = true;

				if (_monster->Get_MonsterInformation(11)[0][j].hp <= 0)
				{
					_player->Get_PlayerInformation()->skileGage++;
					if (_player->Get_PlayerInformation()->skileGage > 6)_player->Get_PlayerInformation()->skileGage = 6;
				}
			}
		}
		//������
		for (int j = 0; j < _monster->Get_MonsterInformation(12)->size(); j++)
		{
			if (IntersectRect(&_impact, &_player->Get_Bullet()[0][i].rc, &_monster->Get_MonsterInformation(12)[0][j].rc))
			{
				
					_monster->Get_MonsterInformation(12)[0][j].hp -= _player->Get_PlayerInformation()->atk;
				

				_player->Get_Bullet()[0][i].impact = true;

				if (_monster->Get_MonsterInformation(12)[0][j].hp <= 0)
				{
					_player->Get_PlayerInformation()->skileGage++;
					if (_player->Get_PlayerInformation()->skileGage > 6)_player->Get_PlayerInformation()->skileGage = 6;
				}
				
			}
		}
		//�˰��λ��亸��
		for (int j = 0; j < _monster->Get_MonsterInformation(13)->size(); j++)
		{
			if (IntersectRect(&_impact, &_player->Get_Bullet()[0][i].rc, &_monster->Get_MonsterInformation(13)[0][j].rc))
			{
				_monster->Get_MonsterInformation(13)[0][j].impact = true;

				if (!_player->Get_Bullet()[0][i].impact)_monster->Get_MonsterInformation(13)[0][0].hp -= _player->Get_PlayerInformation()->atk - 0.9;
				_player->Get_Bullet()[0][i].impact = true;

				if (_monster->Get_MonsterInformation(13)[0][j].hp <= 0)
				{
					SCENEMANAGER->changeScene("����");
					_player->Get_PlayerInformation()->skileGage++;
					if (_player->Get_PlayerInformation()->skileGage > 6)_player->Get_PlayerInformation()->skileGage = 6;
				}
			}
		}

	}

	//�÷��̾� �ǽ��
	for (int j = 0; j < _monster->Get_MonsterInformation(0)->size(); j++)
	{
		if (IntersectRect(&_impact, _player->Get_SatanAtkRc(), &_monster->Get_MonsterInformation(0)[0][j].rc))
		{
			_monster->Get_MonsterInformation(0)[0][j].hp -= 0.2f;

			if (_monster->Get_MonsterInformation(0)[0][j].hp <= 0)
			{
				_player->Get_PlayerInformation()->skileGage++;
				if (_player->Get_PlayerInformation()->skileGage > 6)_player->Get_PlayerInformation()->skileGage = 6;
			}
		}
	}
	//�Ӹ�����
	for (int j = 0; j < _monster->Get_MonsterInformation(1)->size(); j++)
	{

		if (IntersectRect(&_impact, _player->Get_SatanAtkRc(), &_monster->Get_MonsterInformation(1)[0][j].rc))
		{
			_monster->Get_MonsterInformation(1)[0][j].hp -= 0.2f;

			if (_monster->Get_MonsterInformation(1)[0][j].hp <= 0)
			{
				_player->Get_PlayerInformation()->skileGage++;
				if (_player->Get_PlayerInformation()->skileGage > 6)_player->Get_PlayerInformation()->skileGage = 6;
			}
		}
	}
	//������
	for (int j = 0; j < _monster->Get_MonsterInformation(2)->size(); j++)
	{
		if (IntersectRect(&_impact, _player->Get_SatanAtkRc(), &_monster->Get_MonsterInformation(2)[0][j].rc))
		{
			_monster->Get_MonsterInformation(2)[0][j].hp -= 0.2f;

			if (_monster->Get_MonsterInformation(2)[0][j].hp <= 0)
			{
				_player->Get_PlayerInformation()->skileGage++;
				if (_player->Get_PlayerInformation()->skileGage > 6)_player->Get_PlayerInformation()->skileGage = 6;
			}

		}
	}
	//������
	for (int j = 0; j < _monster->Get_MonsterInformation(3)->size(); j++)
	{
		if (IntersectRect(&_impact, _player->Get_SatanAtkRc(), &_monster->Get_MonsterInformation(3)[0][j].rc))
		{
			_monster->Get_MonsterInformation(3)[0][j].hp -= 0.2f;

			if (_monster->Get_MonsterInformation(3)[0][j].hp <= 0)
			{
				_player->Get_PlayerInformation()->skileGage++;
				if (_player->Get_PlayerInformation()->skileGage > 6)_player->Get_PlayerInformation()->skileGage = 6;
			}

		}
	}
	//�󱼴޸�����
	for (int j = 0; j < _monster->Get_MonsterInformation(4)->size(); j++)
	{
		if (IntersectRect(&_impact, _player->Get_SatanAtkRc(), &_monster->Get_MonsterInformation(4)[0][j].rc))
		{
			_monster->Get_MonsterInformation(4)[0][j].hp -= 0.2f;

			if (_monster->Get_MonsterInformation(4)[0][j].hp <= 0)
			{
				_player->Get_PlayerInformation()->skileGage++;
				if (_player->Get_PlayerInformation()->skileGage > 6)_player->Get_PlayerInformation()->skileGage = 6;
			}

		}
	}
	//�󱼸��ִ¸���
	for (int j = 0; j < _monster->Get_MonsterInformation(5)->size(); j++)
	{
		if (IntersectRect(&_impact, _player->Get_SatanAtkRc(), &_monster->Get_MonsterInformation(5)[0][j].rc))
		{
			_monster->Get_MonsterInformation(5)[0][j].hp -= 0.2f;

			if (_monster->Get_MonsterInformation(5)[0][j].hp <= 0)
			{
				_player->Get_PlayerInformation()->skileGage++;
				if (_player->Get_PlayerInformation()->skileGage > 6)_player->Get_PlayerInformation()->skileGage = 6;
			}

		}
	}
	//���и���
	for (int j = 0; j < _monster->Get_MonsterInformation(6)->size(); j++)
	{
		if (IntersectRect(&_impact, _player->Get_SatanAtkRc(), &_monster->Get_MonsterInformation(6)[0][j].rc))
		{
			if (_monster->Get_MonsterInformation(6)[0][j].frameX == 1)
			{
				_monster->Get_MonsterInformation(6)[0][j].hp -= 0.2f;
			}

			if (_monster->Get_MonsterInformation(6)[0][j].hp <= 0)
			{
				_player->Get_PlayerInformation()->skileGage++;
				if (_player->Get_PlayerInformation()->skileGage > 6)_player->Get_PlayerInformation()->skileGage = 6;
			}
		}
	}
	//����
	for (int j = 0; j < _monster->Get_MonsterInformation(7)->size(); j++)
	{
		if (IntersectRect(&_impact, _player->Get_SatanAtkRc(), &_monster->Get_MonsterInformation(7)[0][j].rc))
		{
			_monster->Get_MonsterInformation(7)[0][j].impact = true;

			_monster->Get_MonsterInformation(7)[0][j].hp -= 0.2f;

			if (_monster->Get_MonsterInformation(7)[0][j].hp <= 0)
			{
				_player->Get_PlayerInformation()->skileGage++;
				if (_player->Get_PlayerInformation()->skileGage > 6)_player->Get_PlayerInformation()->skileGage = 6;


				object ob2;
				ob2.x = (_map.left + _map.right) / 2 - 25;
				ob2.y = (_map.top + _map.bottom) / 2 - 25 + 60;
				ob2.impact = false;
				ob2.frameX = 0;
				ob2.frameY = 0;
				ob2.open = false;
				ob2.alpha = 0;
				ob2.frameXTime = 0;
				ob2.Name = "Stone3";
				_object->Get_ObjectSton(3)[0].push_back(ob2);

				_item->Get_ItemList(5)->rc.left = (_map.left + _map.right) / 2 - 25 + 27;
				_item->Get_ItemList(5)->rc.right = (_map.left + _map.right) / 2 - 25 + 57;
				_item->Get_ItemList(5)->rc.top = (_map.top + _map.bottom) / 2 - 25 + 60;
				_item->Get_ItemList(5)->rc.bottom = (_map.top + _map.bottom) / 2 - 25 + 30 + 90;

				object ob4;
				ob4.x = (_map.left + _map.right) / 2 - 30;
				ob4.y = (_map.top + _map.bottom) / 2 - 25 - 160;
				ob4.impact = false;
				ob4.frameX = 0;
				ob4.frameY = 0;
				ob4.open = false;
				ob4.alpha = 0;
				ob4.frameXTime = 0;
				ob4.Name = "����Ŭ���";
				(*_object->Get_ObjectBossDoor1()).push_back(ob4);

				_mapName = "3floor.json";

				_item->Get_ItemList(0)->rc.bottom = -107;
				_item->Get_ItemList(0)->rc.top = -227;
				_item->Get_ItemList(0)->rc.left = -1190;
				_item->Get_ItemList(0)->rc.right = -1167;


				_bossIndex = 1;
			}

		}
	}
	//�������ĸ�
	for (int j = 0; j < _monster->Get_MonsterInformation(29)->size(); j++)
	{
		if (IntersectRect(&_impact, _player->Get_SatanAtkRc(), &_monster->Get_MonsterInformation(29)[0][j].rc))
		{
			_monster->Get_MonsterInformation(29)[0][j].hp -= 0.2f;

			if (_monster->Get_MonsterInformation(29)[0][j].hp <= 0)
			{
				_player->Get_PlayerInformation()->skileGage++;
				if (_player->Get_PlayerInformation()->skileGage > 6)_player->Get_PlayerInformation()->skileGage = 6;
			}

		}
	}
	//����1
	for (int j = 0; j < _monster->Get_MonsterInformation(8)->size(); j++)
	{
		if (IntersectRect(&_impact, _player->Get_SatanAtkRc(), &_monster->Get_MonsterInformation(8)[0][j].rc))
		{
			_monster->Get_MonsterInformation(8)[0][j].impact = true;

			_monster->Get_MonsterInformation(9)[0][j].hp -= 0.2f;

			if (_monster->Get_MonsterInformation(8)[0][j].hp <= 0)
			{
				_player->Get_PlayerInformation()->skileGage++;
				if (_player->Get_PlayerInformation()->skileGage > 6)_player->Get_PlayerInformation()->skileGage = 6;
			}
		}
	}

	//����1��
	for (int j = 0; j < _monster->Get_MonsterInformation(9)->size(); j++)
	{
		if (IntersectRect(&_impact, _player->Get_SatanAtkRc(), &_monster->Get_MonsterInformation(9)[0][j].rc))
		{
			_monster->Get_MonsterInformation(9)[0][j].impact = true;

			_monster->Get_MonsterInformation(9)[0][j].hp -= 0.2f;

			if (_monster->Get_MonsterInformation(9)[0][j].hp <= 0)
			{
				_player->Get_PlayerInformation()->skileGage++;
				if (_player->Get_PlayerInformation()->skileGage > 6)_player->Get_PlayerInformation()->skileGage = 6;

			}
		}
	}

	//����
	for (int j = 0; j < _monster->Get_MonsterInformation(10)->size(); j++)
	{
		if (IntersectRect(&_impact, _player->Get_SatanAtkRc(), &_monster->Get_MonsterInformation(10)[0][j].plrc))
		{
			if (_monster->Get_MonsterInformation(10)[0][j].frameY == 1)
			{
				_monster->Get_MonsterInformation(10)[0][j].hp -= 0.2f;
			}
		}

		if (_monster->Get_MonsterInformation(10)[0][j].hp <= 0)
		{
			_player->Get_PlayerInformation()->skileGage++;
			if (_player->Get_PlayerInformation()->skileGage > 6)_player->Get_PlayerInformation()->skileGage = 6;

			object ob2;
			ob2.x = (_map.left + _map.right) / 2 - 25;
			ob2.y = (_map.top + _map.bottom) / 2 - 25 + 60;
			ob2.impact = false;
			ob2.frameX = 0;
			ob2.frameY = 0;
			ob2.open = false;
			ob2.alpha = 0;
			ob2.frameXTime = 0;
			ob2.Name = "Stone3";
			_object->Get_ObjectSton(3)[0].push_back(ob2);

			object ob3;
			ob3.x = (_map.left + _map.right) / 2 - 25 + 60;
			ob3.y = (_map.top + _map.bottom) / 2 - 25 + 60;
			ob3.impact = false;
			ob3.frameX = 0;
			ob3.frameY = 0;
			ob3.open = false;
			ob3.alpha = 0;
			ob3.frameXTime = 0;
			ob3.Name = "Stone3";
			_object->Get_ObjectSton(3)[0].push_back(ob3);

			object ob4;
			ob4.x = (_map.left + _map.right) / 2 - 25 - 60;
			ob4.y = (_map.top + _map.bottom) / 2 - 25 + 60;
			ob4.impact = false;
			ob4.frameX = 0;
			ob4.frameY = 0;
			ob4.open = false;
			ob4.alpha = 0;
			ob4.frameXTime = 0;
			ob4.Name = "Stone3";
			_object->Get_ObjectSton(3)[0].push_back(ob4);

			object ob5;
			ob5.x = (_map.left + _map.right) / 2 - 25 + 120;
			ob5.y = (_map.top + _map.bottom) / 2 - 25 + 60;
			ob5.impact = false;
			ob5.frameX = 0;
			ob5.frameY = 0;
			ob5.open = false;
			ob5.alpha = 0;
			ob5.frameXTime = 0;
			ob5.Name = "Stone3";
			_object->Get_ObjectSton(3)[0].push_back(ob5);

			_item->Get_ItemList(1)->rc.left = (_map.left + _map.right) / 2 - 25 + 27 - 60;
			_item->Get_ItemList(1)->rc.right = (_map.left + _map.right) / 2 - 25 + 57 - 60;
			_item->Get_ItemList(1)->rc.top = (_map.top + _map.bottom) / 2 - 25 + 60;
			_item->Get_ItemList(1)->rc.bottom = (_map.top + _map.bottom) / 2 - 25 + 30 + 90;

			_item->Get_ItemList(4)->rc.left = (_map.left + _map.right) / 2 - 25 + 27;
			_item->Get_ItemList(4)->rc.right = (_map.left + _map.right) / 2 - 25 + 57;
			_item->Get_ItemList(4)->rc.top = (_map.top + _map.bottom) / 2 - 25 + 60;
			_item->Get_ItemList(4)->rc.bottom = (_map.top + _map.bottom) / 2 - 25 + 30 + 90;

			_item->Get_ItemList(8)->rc.left = (_map.left + _map.right) / 2 - 25 + 27 + 60;
			_item->Get_ItemList(8)->rc.right = (_map.left + _map.right) / 2 - 25 + 57 + 60;
			_item->Get_ItemList(8)->rc.top = (_map.top + _map.bottom) / 2 - 25 + 60;
			_item->Get_ItemList(8)->rc.bottom = (_map.top + _map.bottom) / 2 - 25 + 30 + 90;

			_item->Get_ItemList(11)->rc.left = (_map.left + _map.right) / 2 - 25 + 27 + 120;
			_item->Get_ItemList(11)->rc.right = (_map.left + _map.right) / 2 - 25 + 57 + 120;
			_item->Get_ItemList(11)->rc.top = (_map.top + _map.bottom) / 2 - 25 + 60;
			_item->Get_ItemList(11)->rc.bottom = (_map.top + _map.bottom) / 2 - 25 + 30 + 90;


			object ob6;
			ob6.x = (_map.left + _map.right) / 2 - 30;
			ob6.y = (_map.top + _map.bottom) / 2 - 25 - 160;
			ob6.impact = false;
			ob6.frameX = 0;
			ob6.frameY = 0;
			ob6.open = false;
			ob6.alpha = 0;
			ob6.frameXTime = 0;
			ob6.Name = "����Ŭ���";
			(*_object->Get_ObjectBossDoor1()).push_back(ob6);

			_mapName = "4floor.json";

			_bossIndex = 2;
		}
	}

	//����
	for (int j = 0; j < _monster->Get_MonsterInformation(11)->size(); j++)
	{
		if (IntersectRect(&_impact, _player->Get_SatanAtkRc(), &_monster->Get_MonsterInformation(11)[0][j].rc))
		{
			_monster->Get_MonsterInformation(11)[0][j].impact = true;
			_monster->Get_MonsterInformation(10)[0][j].hp -= 0.2f;


			if (_monster->Get_MonsterInformation(11)[0][j].hp <= 0)
			{
				_player->Get_PlayerInformation()->skileGage++;
				if (_player->Get_PlayerInformation()->skileGage > 6)_player->Get_PlayerInformation()->skileGage = 6;
			}
		}
	}
	//������
	for (int j = 0; j < _monster->Get_MonsterInformation(12)->size(); j++)
	{
		if (IntersectRect(&_impact, _player->Get_SatanAtkRc(), &_monster->Get_MonsterInformation(12)[0][j].rc))
		{

			_monster->Get_MonsterInformation(12)[0][j].hp -= 0.2f;

			if (_monster->Get_MonsterInformation(12)[0][j].hp <= 0)
			{
				_player->Get_PlayerInformation()->skileGage++;
				if (_player->Get_PlayerInformation()->skileGage > 6)_player->Get_PlayerInformation()->skileGage = 6;
			}

		}
	}
	//�˰��λ��亸��
	for (int j = 0; j < _monster->Get_MonsterInformation(13)->size(); j++)
	{
		if (IntersectRect(&_impact, _player->Get_SatanAtkRc(), &_monster->Get_MonsterInformation(13)[0][j].rc))
		{
			_monster->Get_MonsterInformation(13)[0][j].impact = true;

			_monster->Get_MonsterInformation(13)[0][j].hp -= 0.2f;
			if (_monster->Get_MonsterInformation(13)[0][j].hp <= 0)
			{
				SCENEMANAGER->changeScene("����");
				_player->Get_PlayerInformation()->skileGage++;
				if (_player->Get_PlayerInformation()->skileGage > 6)_player->Get_PlayerInformation()->skileGage = 6;
			}
		}
	}

	//��ź ���� �浹
	for (int i = 0; i < _player->Get_Bomb()->size(); i++)
	{
		//������
		for (int j = 0; j < _monster->Get_MonsterInformation(0)->size(); j++)
		{
			if (IntersectRect(&_impact, &_player->Get_Bomb()[0][i].rc, &_monster->Get_MonsterInformation(0)[0][j].rc))
			{
				if (_player->Get_Bomb()[0][i].index == 26)_monster->Get_MonsterInformation(0)[0][j].hp -= _player->Get_Bomb()[0][i].atk;

				if (_monster->Get_MonsterInformation(0)[0][j].hp <= 0)
				{
					_player->Get_PlayerInformation()->skileGage++;
					if (_player->Get_PlayerInformation()->skileGage > 6)_player->Get_PlayerInformation()->skileGage = 6;
				}
			}
		}
		//�Ӹ�����
		for (int j = 0; j < _monster->Get_MonsterInformation(1)->size(); j++)
		{
			if (IntersectRect(&_impact, &_player->Get_Bomb()[0][i].rc, &_monster->Get_MonsterInformation(1)[0][j].rc))
			{
				if (_player->Get_Bomb()[0][i].index == 26)_monster->Get_MonsterInformation(1)[0][j].hp -= _player->Get_Bomb()[0][i].atk;

				if (_monster->Get_MonsterInformation(1)[0][j].hp <= 0)
				{
					_player->Get_PlayerInformation()->skileGage++;
					if (_player->Get_PlayerInformation()->skileGage > 6)_player->Get_PlayerInformation()->skileGage = 6;
				}
			}
		}
		//������
		for (int j = 0; j < _monster->Get_MonsterInformation(2)->size(); j++)
		{
			if (IntersectRect(&_impact, &_player->Get_Bomb()[0][i].rc, &_monster->Get_MonsterInformation(2)[0][j].rc))
			{
				if (_player->Get_Bomb()[0][i].index == 26)_monster->Get_MonsterInformation(2)[0][j].hp -= _player->Get_Bomb()[0][i].atk;

				if (_monster->Get_MonsterInformation(2)[0][j].hp <= 0)
				{
					_player->Get_PlayerInformation()->skileGage++;
					if (_player->Get_PlayerInformation()->skileGage > 6)_player->Get_PlayerInformation()->skileGage = 6;
				}
			}
		}
		//������
		for (int j = 0; j < _monster->Get_MonsterInformation(3)->size(); j++)
		{
			if (IntersectRect(&_impact, &_player->Get_Bomb()[0][i].rc, &_monster->Get_MonsterInformation(3)[0][j].rc))
			{
				if (_player->Get_Bomb()[0][i].index == 26)_monster->Get_MonsterInformation(3)[0][j].hp -= _player->Get_Bomb()[0][i].atk;

				if (_monster->Get_MonsterInformation(3)[0][j].hp <= 0)
				{
					_player->Get_PlayerInformation()->skileGage++;
					if (_player->Get_PlayerInformation()->skileGage > 6)_player->Get_PlayerInformation()->skileGage = 6;
				}
			}
		}
		//�󱼴޸�����
		for (int j = 0; j < _monster->Get_MonsterInformation(4)->size(); j++)
		{
			if (IntersectRect(&_impact, &_player->Get_Bomb()[0][i].rc, &_monster->Get_MonsterInformation(4)[0][j].rc))
			{
				if (_player->Get_Bomb()[0][i].index == 26)_monster->Get_MonsterInformation(4)[0][j].hp -= _player->Get_Bomb()[0][i].atk;

				if (_monster->Get_MonsterInformation(4)[0][j].hp <= 0)
				{
					_player->Get_PlayerInformation()->skileGage++;
					if (_player->Get_PlayerInformation()->skileGage > 6)_player->Get_PlayerInformation()->skileGage = 6;
				}
			}
		}

		//�󱼸� �ִ� ����
		for (int j = 0; j < _monster->Get_MonsterInformation(5)->size(); j++)
		{
			if (IntersectRect(&_impact, &_player->Get_Bomb()[0][i].rc, &_monster->Get_MonsterInformation(5)[0][j].rc))
			{
				if (_player->Get_Bomb()[0][i].index == 26)_monster->Get_MonsterInformation(5)[0][j].hp -= _player->Get_Bomb()[0][i].atk;

				if (_monster->Get_MonsterInformation(5)[0][j].hp <= 0)
				{
					_player->Get_PlayerInformation()->skileGage++;
					if (_player->Get_PlayerInformation()->skileGage > 6)_player->Get_PlayerInformation()->skileGage = 6;
				}
			}
		}
		
		//���� ����
		for (int j = 0; j < _monster->Get_MonsterInformation(6)->size(); j++)
		{
			if (IntersectRect(&_impact, &_player->Get_Bomb()[0][i].rc, &_monster->Get_MonsterInformation(6)[0][j].rc))
			{
				if (_player->Get_Bomb()[0][i].index == 26)_monster->Get_MonsterInformation(6)[0][j].hp -= _player->Get_Bomb()[0][i].atk;

				if (_monster->Get_MonsterInformation(6)[0][j].hp <= 0)
				{
					_player->Get_PlayerInformation()->skileGage++;
					if (_player->Get_PlayerInformation()->skileGage > 6)_player->Get_PlayerInformation()->skileGage = 6;
				}
			}
		}

		//����
		for (int j = 0; j < _monster->Get_MonsterInformation(7)->size(); j++)
		{
			if (IntersectRect(&_impact, &_player->Get_Bomb()[0][i].rc, &_monster->Get_MonsterInformation(7)[0][j].rc))
			{
				if (_player->Get_Bomb()[0][i].index == 26 && !_monster->Get_MonsterInformation(7)[0][j].impact)
				{
					_monster->Get_MonsterInformation(7)[0][j].impact = true;
					_monster->Get_MonsterInformation(7)[0][j].hp -= _player->Get_Bomb()[0][i].atk - 0.5f ;
				}
			
				if (_monster->Get_MonsterInformation(7)[0][j].hp <= 0)
				{
					_player->Get_PlayerInformation()->skileGage++;
					if (_player->Get_PlayerInformation()->skileGage > 6)_player->Get_PlayerInformation()->skileGage = 6;
				}
			}
		}
		//�������ĸ�
		for (int j = 0; j < _monster->Get_MonsterInformation(29)->size(); j++)
		{
			if (IntersectRect(&_impact, &_player->Get_Bomb()[0][i].rc, &_monster->Get_MonsterInformation(29)[0][j].rc))
			{
				if (_player->Get_Bomb()[0][i].index == 26)_monster->Get_MonsterInformation(29)[0][j].hp -= _player->Get_Bomb()[0][i].atk;

				if (_monster->Get_MonsterInformation(29)[0][j].hp <= 0)
				{
					_player->Get_PlayerInformation()->skileGage++;
					if (_player->Get_PlayerInformation()->skileGage > 6)_player->Get_PlayerInformation()->skileGage = 6;
				}
			}
		}
		//����1
		for (int j = 0; j < _monster->Get_MonsterInformation(8)->size(); j++)
		{
			if (IntersectRect(&_impact, &_player->Get_Bomb()[0][i].rc, &_monster->Get_MonsterInformation(8)[0][j].rc))
			{
				if (_player->Get_Bomb()[0][i].index == 26 && !_monster->Get_MonsterInformation(8)[0][j].impact)
				{
					_monster->Get_MonsterInformation(8)[0][j].impact = true;
					_monster->Get_MonsterInformation(9)[0][0].hp -= _player->Get_Bomb()[0][i].atk - 0.5f;
				}

				if (_monster->Get_MonsterInformation(8)[0][j].hp <= 0)
				{
					_player->Get_PlayerInformation()->skileGage++;
					if (_player->Get_PlayerInformation()->skileGage > 6)_player->Get_PlayerInformation()->skileGage = 6;
				}
			}
		}
		//����1��
		for (int j = 0; j < _monster->Get_MonsterInformation(9)->size(); j++)
		{
			if (IntersectRect(&_impact, &_player->Get_Bomb()[0][i].rc, &_monster->Get_MonsterInformation(9)[0][j].rc))
			{
				if (_player->Get_Bomb()[0][i].index == 26 && !_monster->Get_MonsterInformation(9)[0][j].impact)
				{
					_monster->Get_MonsterInformation(9)[0][j].impact = true;
					_monster->Get_MonsterInformation(9)[0][j].hp -= _player->Get_Bomb()[0][i].atk - 0.5f;
				}

				if (_monster->Get_MonsterInformation(9)[0][j].hp <= 0)
				{
					_player->Get_PlayerInformation()->skileGage++;
					if (_player->Get_PlayerInformation()->skileGage > 6)_player->Get_PlayerInformation()->skileGage = 6;
				}
			}
		}
		//����
		for (int j = 0; j < _monster->Get_MonsterInformation(10)->size(); j++)
		{
			if (IntersectRect(&_impact, &_player->Get_Bomb()[0][i].rc, &_monster->Get_MonsterInformation(10)[0][j].rc))
			{
				if (_monster->Get_MonsterInformation(10)[0][j].frameX == 1)
				{
					if (_player->Get_Bomb()[0][i].index == 26 && !_monster->Get_MonsterInformation(10)[0][j].impact)
					{
						_monster->Get_MonsterInformation(10)[0][j].impact = true;
						_monster->Get_MonsterInformation(10)[0][j].hp -= _player->Get_Bomb()[0][i].atk - 0.5f;
					}
				}
			
				if (_monster->Get_MonsterInformation(10)[0][j].hp <= 0)
				{
					_player->Get_PlayerInformation()->skileGage++;
					if (_player->Get_PlayerInformation()->skileGage > 6)_player->Get_PlayerInformation()->skileGage = 6;
				}
			}
		}
		//�������
		for (int j = 0; j < _monster->Get_MonsterInformation(11)->size(); j++)
		{
			if (IntersectRect(&_impact, &_player->Get_Bomb()[0][i].rc, &_monster->Get_MonsterInformation(11)[0][j].rc))
			{
				if (_player->Get_Bomb()[0][i].index == 26 && !_monster->Get_MonsterInformation(11)[0][j].impact)
				{
					_monster->Get_MonsterInformation(11)[0][j].impact = true;
					_monster->Get_MonsterInformation(10)[0][0].hp -= _player->Get_Bomb()[0][i].atk - 0.5f;
				}

				if (_monster->Get_MonsterInformation(11)[0][j].hp <= 0)
				{
					_player->Get_PlayerInformation()->skileGage++;
					if (_player->Get_PlayerInformation()->skileGage > 6)_player->Get_PlayerInformation()->skileGage = 6;
				}
			}
		}
		//��� ����
		for (int j = 0; j < _monster->Get_MonsterInformation(12)->size(); j++)
		{
			if (IntersectRect(&_impact, &_player->Get_Bomb()[0][i].rc, &_monster->Get_MonsterInformation(12)[0][j].rc))
			{
				if (_player->Get_Bomb()[0][i].index == 26)_monster->Get_MonsterInformation(12)[0][j].hp -= _player->Get_Bomb()[0][i].atk;

				if (_monster->Get_MonsterInformation(12)[0][j].hp <= 0)
				{
					_player->Get_PlayerInformation()->skileGage++;
					if (_player->Get_PlayerInformation()->skileGage > 6)_player->Get_PlayerInformation()->skileGage = 6;
				}
			}
		}
		//����
		for (int j = 0; j < _monster->Get_MonsterInformation(13)->size(); j++)
		{
			if (IntersectRect(&_impact, &_player->Get_Bomb()[0][i].rc, &_monster->Get_MonsterInformation(13)[0][j].rc))
			{
				if (_player->Get_Bomb()[0][i].index == 26 && !_monster->Get_MonsterInformation(13)[0][j].impact)
				{
					_monster->Get_MonsterInformation(13)[0][j].impact = true;
					_monster->Get_MonsterInformation(13)[0][0].hp -= _player->Get_Bomb()[0][i].atk - 0.5f;
				}

				if (_monster->Get_MonsterInformation(13)[0][j].hp <= 0)
				{
					_player->Get_PlayerInformation()->skileGage++;
					if (_player->Get_PlayerInformation()->skileGage > 6)_player->Get_PlayerInformation()->skileGage = 6;
				}
			}
		}
		

		//�÷��̾� ��ź �浹
		if (IntersectRect(&_impact, &_player->Get_Bomb()[0][i].rc, &_player->Get_PlayerInformation()->rc))
		{
			if (_player->Get_Bomb()[0][i].index == 26 && !_player->Get_PlayerInformation()->_invincibility)
			{
				_player->Get_PlayerInformation()->hp -= 1.0f;
				_player->Get_PlayerInformation()->_invincibility = true;
			}
		}
	}




	//���� �Ѿ� �÷��̾� �Ѿ� �浹 ����
	for (int i = 0; i < _monster->Get_MonsterBullet()[0].size(); i++)
	{
		if (IntersectRect(&_impact, &_player->Get_PlayerInformation()->rc, &_monster->Get_MonsterBullet()[0][i].rc)&&
			!_player->Get_PlayerInformation()->_invincibility&& _monster->Get_MonsterBullet()[0][i].frameX==0)
		{
			_player->Get_PlayerInformation()->hp -= _monster->Get_MonsterBullet()[0][i].atk;
			_player->Get_PlayerInformation()->_invincibility = true;
			_monster->Get_MonsterBullet()[0][i].impact = true;
		}
	}

	//�÷��̾� ��ġ�� ���� �Ѿ� �߻�
	for (int i = 0; i < _monster->Get_MonsterBullet1()[0].size(); i++)
	{
		if (IntersectRect(&_impact, &_player->Get_PlayerInformation()->rc, &_monster->Get_MonsterBullet1()[0][i].rc) &&
			!_player->Get_PlayerInformation()->_invincibility && _monster->Get_MonsterBullet1()[0][i].frameX == 0)
		{
			_player->Get_PlayerInformation()->hp -= _monster->Get_MonsterBullet1()[0][i].atk;
			_player->Get_PlayerInformation()->_invincibility = true;
			_monster->Get_MonsterBullet1()[0][i].impact = true;
		}
	}

	//���׶��� �Ѿ� �߻�
	for (int i = 0; i < _monster->Get_MonsterBullet2()[0].size(); i++)
	{
		if (IntersectRect(&_impact, &_player->Get_PlayerInformation()->rc, &_monster->Get_MonsterBullet2()[0][i].rc) &&
			!_player->Get_PlayerInformation()->_invincibility && _monster->Get_MonsterBullet2()[0][i].frameX == 0)
		{
			_player->Get_PlayerInformation()->hp -= _monster->Get_MonsterBullet2()[0][i].atk;
			_player->Get_PlayerInformation()->_invincibility = true;
			_monster->Get_MonsterBullet2()[0][i].impact = true;
		}
	}


	//�����϶� ����
	if (*_player->Get_Shield())
	{
		_player->Get_PlayerInformation()->_invincibility = true;
	}

	//������Ʈ �� ���� ��ȣ�ۿ�
	for (int i = 0; i < 30; i++)
	{

		for (int j = 0; j < _monster->Get_MonsterInformation(i)->size(); j++)
		{
			for (int k = 0; k < _object->Get_Object()->size(); k++)
			{
				if (IntersectRect(&_impact, &_object->Get_Object()[0][k].rc, &_monster->Get_MonsterInformation(i)[0][j].rc))
				{

					if ((_object->Get_Object()[0][k].rc.right + _object->Get_Object()[0][k].rc.left) / 2 > _monster->Get_MonsterInformation(i)[0][j].rc.left)
					{
						_monster->Get_MonsterInformation(i)[0][j].x -= 1.5f;
					}
					if ((_object->Get_Object()[0][k].rc.right + _object->Get_Object()[0][k].rc.left) / 2 < _monster->Get_MonsterInformation(i)[0][j].rc.right)
					{
						_monster->Get_MonsterInformation(i)[0][j].x += 1.5f;
					}
					if ((_object->Get_Object()[0][k].rc.bottom + _object->Get_Object()[0][k].rc.top) / 2 < _monster->Get_MonsterInformation(i)[0][j].rc.top)
					{
						_monster->Get_MonsterInformation(i)[0][j].y += 1.5f;
					}
					if ((_object->Get_Object()[0][k].rc.bottom + _object->Get_Object()[0][k].rc.top) / 2 > _monster->Get_MonsterInformation(i)[0][j].rc.bottom)
					{
						_monster->Get_MonsterInformation(i)[0][j].y -= 1.5f;
					}
				    _monster->Get_MonsterInformation(i)[0][j].hp -= 0.5f;
				
				}
			}
		}
	}

	//�÷��̾� �� ������Ʈ ��ȣ�ۿ�
	for (int k = 0; k < _object->Get_Object()->size(); k++)
	{
		if (IntersectRect(&_impact, &_object->Get_Object()[0][k].rc, &_player->Get_PlayerInformation()->rc))
		{

			if ((_object->Get_Object()[0][k].rc.right + _object->Get_Object()[0][k].rc.left) / 2 > _player->Get_PlayerInformation()->rc.left)
			{
				(*_player->Get_Gimage())->setX((*_player->Get_Gimage())->getX() - 1.0f);
			}
			if ((_object->Get_Object()[0][k].rc.right + _object->Get_Object()[0][k].rc.left) / 2 < _player->Get_PlayerInformation()->rc.right)
			{
				(*_player->Get_Gimage())->setX((*_player->Get_Gimage())->getX() + 1.0f);
			}
			if ((_object->Get_Object()[0][k].rc.bottom + _object->Get_Object()[0][k].rc.top) / 2 < _player->Get_PlayerInformation()->rc.top)
			{
				(*_player->Get_Gimage())->setY((*_player->Get_Gimage())->getY() + 1.0f);
			}
			if ((_object->Get_Object()[0][k].rc.bottom + _object->Get_Object()[0][k].rc.top) / 2 > _player->Get_PlayerInformation()->rc.bottom)
			{
				(*_player->Get_Gimage())->setY((*_player->Get_Gimage())->getY() - 1.0f);
			}

		    if(!_player->Get_PlayerInformation()->_invincibility)_player->Get_PlayerInformation()->hp -= 0.5f;
			_player->Get_PlayerInformation()->_invincibility = true;
		}
	}

	//���� �÷��̾� ��ȣ�ۿ�
	if (!_caricature[5])
	{
		for (int k = 0; k < _object->Get_ObjectThorn()->size(); k++)
		{
			if (IntersectRect(&_impact, &_object->Get_ObjectThorn()[0][k].rc, &_player->Get_PlayerInformation()->rc))
			{

				if ((_object->Get_ObjectThorn()[0][k].rc.right + _object->Get_ObjectThorn()[0][k].rc.left) / 2 > _player->Get_PlayerInformation()->rc.left)
				{
					(*_player->Get_Gimage())->setX((*_player->Get_Gimage())->getX() - 1.0f);
				}
				if ((_object->Get_ObjectThorn()[0][k].rc.right + _object->Get_ObjectThorn()[0][k].rc.left) / 2 < _player->Get_PlayerInformation()->rc.right)
				{
					(*_player->Get_Gimage())->setX((*_player->Get_Gimage())->getX() + 1.0f);
				}
				if ((_object->Get_ObjectThorn()[0][k].rc.bottom + _object->Get_ObjectThorn()[0][k].rc.top) / 2 < _player->Get_PlayerInformation()->rc.top)
				{
					(*_player->Get_Gimage())->setY((*_player->Get_Gimage())->getY() + 1.0f);
				}
				if ((_object->Get_ObjectThorn()[0][k].rc.bottom + _object->Get_ObjectThorn()[0][k].rc.top) / 2 > _player->Get_PlayerInformation()->rc.bottom)
				{
					(*_player->Get_Gimage())->setY((*_player->Get_Gimage())->getY() - 1.0f);
				}

				if (!_player->Get_PlayerInformation()->_invincibility)_player->Get_PlayerInformation()->hp -= 0.5f;
				_player->Get_PlayerInformation()->_invincibility = true;
			}
		}
	}
	//������Ʈ ���� ��ȣ�ۿ� ����
	for (int i = 0; i < 30; i++)
	{
		if (i == 2 || i == 9 || i == 29 || i == 12) continue;

		for (int j = 0; j < _monster->Get_MonsterInformation(i)->size(); j++)
		{
			for (int k = 0; k < _object->Get_ObjectThorn()->size(); k++)
			{
				if (IntersectRect(&_impact, &_object->Get_ObjectThorn()[0][k].rc, &_monster->Get_MonsterInformation(i)[0][j].rc))
				{

					if ((_object->Get_ObjectThorn()[0][k].rc.right + _object->Get_ObjectThorn()[0][k].rc.left) / 2 > _monster->Get_MonsterInformation(i)[0][j].rc.left)
					{
						_monster->Get_MonsterInformation(i)[0][j].x -= 1.5f;
					}
					if ((_object->Get_ObjectThorn()[0][k].rc.right + _object->Get_ObjectThorn()[0][k].rc.left) / 2 < _monster->Get_MonsterInformation(i)[0][j].rc.right)
					{
						_monster->Get_MonsterInformation(i)[0][j].x += 1.5f;
					}
					if ((_object->Get_ObjectThorn()[0][k].rc.bottom + _object->Get_ObjectThorn()[0][k].rc.top) / 2 < _monster->Get_MonsterInformation(i)[0][j].rc.top)
					{
						_monster->Get_MonsterInformation(i)[0][j].y += 1.5f;
					}
					if ((_object->Get_ObjectThorn()[0][k].rc.bottom + _object->Get_ObjectThorn()[0][k].rc.top) / 2 > _monster->Get_MonsterInformation(i)[0][j].rc.bottom)
					{
						_monster->Get_MonsterInformation(i)[0][j].y -= 1.5f;
					}
					_monster->Get_MonsterInformation(i)[0][j].hp -= 0.25f;

				}
			}
		}
	}


	//������Ʈ ���� �� ��ȣ�ۿ�
	for (int i = 0; i < 30; i++)
	{
		if (i == 2 || i == 9 || i == 29 || i == 12) continue;

		for (int j = 0; j < _monster->Get_MonsterInformation(i)->size(); j++)
		{
			for(int m=0; m<4; m++)
			{ 
				for (int k = 0; k < _object->Get_ObjectSton(m)->size(); k++)
				{
					if (IntersectRect(&_impact, &_object->Get_ObjectSton(m)[0][k].rc, &_monster->Get_MonsterInformation(i)[0][j].rc))
					{

						if ((_object->Get_ObjectSton(m)[0][k].rc.right + _object->Get_ObjectSton(m)[0][k].rc.left) / 2 > _monster->Get_MonsterInformation(i)[0][j].rc.left)
						{
							_monster->Get_MonsterInformation(i)[0][j].x -= _monster->Get_MonsterInformation(i)[0][j].speed;
						}

						if ((_object->Get_ObjectSton(m)[0][k].rc.right + _object->Get_ObjectSton(m)[0][k].rc.left) / 2 < _monster->Get_MonsterInformation(i)[0][j].rc.right)
						{
							_monster->Get_MonsterInformation(i)[0][j].x += _monster->Get_MonsterInformation(i)[0][j].speed;
						}

						if ((_object->Get_ObjectSton(m)[0][k].rc.bottom + _object->Get_ObjectSton(m)[0][k].rc.top) / 2 > _monster->Get_MonsterInformation(i)[0][j].rc.top)
						{
							_monster->Get_MonsterInformation(i)[0][j].y -= _monster->Get_MonsterInformation(i)[0][j].speed;
						}

						if ((_object->Get_ObjectSton(m)[0][k].rc.bottom + _object->Get_ObjectSton(m)[0][k].rc.top) / 2 < _monster->Get_MonsterInformation(i)[0][j].rc.bottom)
						{
							_monster->Get_MonsterInformation(i)[0][j].y += _monster->Get_MonsterInformation(i)[0][j].speed;
						}

					}
				}
			}
		}
	}

						
	cameraImpactrc = RectMake(20 , 100 , 750, 500);

	
	//�濡 ���Ͱ� ������ �湮����
	_monsterNum = 0;
	for (int k = 0; k < 30; k++)
	{
		for (int i = 0; i < _monster->Get_MonsterInformation(k)->size(); i++)
		{
			if (IntersectRect(&_impact, &cameraImpactrc, &_monster->Get_MonsterInformation(k)[0][i].rc))
			{
				_monsterNum++;
			}
		}
	}
	if (_monsterNum == 0)
	{
		for (int j = 0; j < 4; j++)
		{
			for (int f = 0; f < _object->Get_ObjectDoor(j)->size(); f++)
			{
				if (IntersectRect(&_impact, &cameraImpactrc, &_object->Get_ObjectDoor(j)[0][f].rc))
				{
					if (j == 0)
					{
						_object->Get_ObjectDoor(j)[0][f].frameX = 1;
					}
					if (j == 1)
					{
						_object->Get_ObjectDoor(j)[0][f].frameX = 1;
					}
					if (j == 2)
					{
						_object->Get_ObjectDoor(j)[0][f].frameY = 1;
					}
					if (j == 3)
					{
						_object->Get_ObjectDoor(j)[0][f].frameY = 1;
					}
				}
			}
		}
	}


	// �÷��̾� ���浹 
	for (int j = 0; j < 4; j++)
	{
		for (int f = 0; f < _object->Get_ObjectDoor(j)->size(); f++)
		{
			if (IntersectRect(&_impact, &_player->Get_PlayerInformation()->rc, &_object->Get_ObjectDoor(j)[0][f].rc))
			{
				if (j == 0 && _object->Get_ObjectDoor(j)[0][f].frameX == 1)
				{
					y += _mapMoveY;

					(*_player->Get_Gimage())->setY((*_player->Get_Gimage())->getY() + 350);

					for (int p = 0; p < 4; p++)
					{
						for (int o = 0; o < _object->Get_ObjectDoor(p)->size(); o++)
						{
							_object->Get_ObjectDoor(p)[0][o].y += _mapMoveY;
						}
					}
					for (int p = 0; p < 4; p++)
					{
						for (int o = 0; o < _object->Get_ShopLockeDoor(p)->size(); o++)
						{
							_object->Get_ShopLockeDoor(p)[0][o].y += _mapMoveY;
						}
					}
					for (int p = 0; p < 20; p++)
					{
					    _item->Get_ItemList(p)->rc.bottom += _mapMoveY;
						_item->Get_ItemList(p)->rc.top += _mapMoveY;

				
					}
					for (int p = 0; p < _player->Get_Bomb()->size(); p++)
					{
						_player->Get_Bomb()[0][p].y += _mapMoveY;
					}
					for (int l = 0; l < 30; l++)
					{
						for (int m = 0; m < _monster->Get_MonsterInformation(l)[0].size(); m++)
						{
							_monster->Get_MonsterInformation(l)[0][m].y += _mapMoveY;
						}
					}

					for (int l = 0; l < _player->Get_Bomb()->size(); l++)
					{
						_player->Get_Bomb()[0][l].y += _mapMoveY;
					}
					for (int l = 0; l < 4; l++)
					{
						for (int m = 0; m <_object->Get_ObjectSton(l)->size(); m++)
						{
							_object->Get_ObjectSton(l)[0][m].y += _mapMoveY;
						}
					}
					for (int l = 0; l < _object->Get_Object()->size(); l++)
					{
						_object->Get_Object()[0][l].y += _mapMoveY;
					}
					for (int l = 0; l < _object->Get_ObjectThorn()->size(); l++)
					{
						_object->Get_ObjectThorn()[0][l].y += _mapMoveY;
					}
					for (int l = 0; l < _monster->Get_MonsterBlood()->size(); l++)
					{
						_monster->Get_MonsterBlood()[0][l].y += _mapMoveY;
					}
					for (int l = 0; l < _player->Get_Bullet()->size(); l++)
					{
						_player->Get_Bullet()[0][l].y -= 5000;
					}
					for (int l = 0; l < _object->Get_ObjectBossDoor1()->size(); l++)
					{
						_object->Get_ObjectBossDoor1()[0][l].y += _mapMoveY;
					}
					
					_operationkey->setY(_operationkey->getY()+ _mapMoveY);

					_miniMap.top -= 12;
					_miniMap.bottom -= 12;
				}
				if (j == 1 && _object->Get_ObjectDoor(j)[0][f].frameX == 1)
				{
					y -= _mapMoveY;

					(*_player->Get_Gimage())->setY((*_player->Get_Gimage())->getY() - 350);

					for (int p = 0; p < 4; p++)
					{
						for (int o = 0; o < _object->Get_ObjectDoor(p)->size(); o++)
						{
							_object->Get_ObjectDoor(p)[0][o].y -= _mapMoveY;
						}
					}
					for (int p = 0; p < 4; p++)
					{
						for (int o = 0; o < _object->Get_ShopLockeDoor(p)->size(); o++)
						{
							_object->Get_ShopLockeDoor(p)[0][o].y -= _mapMoveY;
						}
					}
					for (int p = 0; p < 20; p++)
					{
						_item->Get_ItemList(p)->rc.bottom -= _mapMoveY;
						_item->Get_ItemList(p)->rc.top -= _mapMoveY;
					}
					for (int p = 0; p < _player->Get_Bomb()->size(); p++)
					{
						_player->Get_Bomb()[0][p].y -= _mapMoveY;
					}
					for (int l = 0; l < 30; l++)
					{
						for (int m = 0; m < _monster->Get_MonsterInformation(l)[0].size(); m++)
						{
							_monster->Get_MonsterInformation(l)[0][m].y -= _mapMoveY;
						}
					}
					for (int l = 0; l < _player->Get_Bomb()->size(); l++)
					{
						_player->Get_Bomb()[0][l].y -= _mapMoveY;
					}
					for (int l = 0; l < 4; l++)
					{
						for (int m = 0; m < _object->Get_ObjectSton(l)->size(); m++)
						{
							_object->Get_ObjectSton(l)[0][m].y -= _mapMoveY;
						}
					}
					for (int l = 0; l < _object->Get_Object()->size(); l++)
					{
						_object->Get_Object()[0][l].y -= _mapMoveY;
					}
					for (int l = 0; l < _object->Get_ObjectThorn()->size(); l++)
					{
						_object->Get_ObjectThorn()[0][l].y -= _mapMoveY;
					}
					for (int l = 0; l < _monster->Get_MonsterBlood()->size(); l++)
					{
						_monster->Get_MonsterBlood()[0][l].y -= _mapMoveY;
					}
					for (int l = 0; l < _player->Get_Bullet()->size(); l++)
					{
						_player->Get_Bullet()[0][l].y += 5000;
					}
					for (int l = 0; l < _object->Get_ObjectBossDoor1()->size(); l++)
					{
						_object->Get_ObjectBossDoor1()[0][l].y -= _mapMoveY;
					}
					_operationkey->setY(_operationkey->getY() - _mapMoveY);

					_miniMap.top += 12;
					_miniMap.bottom += 12;
				}
				if (j == 2 && _object->Get_ObjectDoor(j)[0][f].frameY==1)
				{
					x += _mapMoveX;

					(*_player->Get_Gimage())->setX((*_player->Get_Gimage())->getX() + 580);

					for (int p = 0; p < 4; p++)
					{
						for (int o = 0; o < _object->Get_ObjectDoor(p)->size(); o++)
						{
								_object->Get_ObjectDoor(p)[0][o].x += _mapMoveX;
						}
					}
					for (int p = 0; p < 4; p++)
					{
						for (int o = 0; o < _object->Get_ShopLockeDoor(p)->size(); o++)
						{
							_object->Get_ShopLockeDoor(p)[0][o].x += _mapMoveX;
						}
					}
					for (int p = 0; p < 20; p++)
					{
						_item->Get_ItemList(p)->rc.left += _mapMoveX;
						_item->Get_ItemList(p)->rc.right += _mapMoveX;
					}
					for (int p = 0; p < _player->Get_Bomb()->size(); p++)
					{
						_player->Get_Bomb()[0][p].x += _mapMoveX;
					}
					for (int l = 0; l < 30; l++)
					{
						for (int m = 0; m < _monster->Get_MonsterInformation(l)[0].size(); m++)
						{
							_monster->Get_MonsterInformation(l)[0][m].x += _mapMoveX;
						}
					}
					for (int l = 0; l < _player->Get_Bomb()->size(); l++)
					{
						_player->Get_Bomb()[0][l].x += _mapMoveX;
					}
					for (int l = 0; l < 4; l++)
					{
						for (int m = 0; m < _object->Get_ObjectSton(l)->size(); m++)
						{
							_object->Get_ObjectSton(l)[0][m].	x += _mapMoveX;
						}
					}
					for (int l = 0; l < _object->Get_Object()->size(); l++)
					{
						_object->Get_Object()[0][l].x += _mapMoveX;
					}
					for (int l = 0; l < _object->Get_ObjectThorn()->size(); l++)
					{
						_object->Get_ObjectThorn()[0][l].x += _mapMoveX;
					}
					for (int l = 0; l < _monster->Get_MonsterBlood()->size(); l++)
					{
						_monster->Get_MonsterBlood()[0][l].x += _mapMoveX;
					}
					for (int l = 0; l < _player->Get_Bullet()->size(); l++)
					{
						_player->Get_Bullet()[0][l].x -= 5000;
					}
					for (int l = 0; l < _object->Get_ObjectBossDoor1()->size(); l++)
					{
						_object->Get_ObjectBossDoor1()[0][l].x += _mapMoveX;
					}
					_operationkey->setX(_operationkey->getX() + _mapMoveX);

					_miniMap.left -= 31;
					_miniMap.right -= 31;
				}
				if (j == 3 && _object->Get_ObjectDoor(j)[0][f].frameY==1)
				{
					x -= _mapMoveX;

					(*_player->Get_Gimage())->setX((*_player->Get_Gimage())->getX() - 575);

					for (int p = 0; p < 4; p++)
					{
						for (int o = 0; o < _object->Get_ObjectDoor(p)->size(); o++)
						{
								_object->Get_ObjectDoor(p)[0][o].x -= _mapMoveX;
						}
					}
					for (int p = 0; p < 4; p++)
					{
						for (int o = 0; o < _object->Get_ShopLockeDoor(p)->size(); o++)
						{
							_object->Get_ShopLockeDoor(p)[0][o].x -= _mapMoveX;
						}
					}
					for (int p = 0; p < 20; p++)
					{
						_item->Get_ItemList(p)->rc.left -= _mapMoveX;
						_item->Get_ItemList(p)->rc.right -= _mapMoveX;
					}
					for (int p = 0; p < _player->Get_Bomb()->size(); p++)
					{
						_player->Get_Bomb()[0][p].x -= _mapMoveX;
					}
					for (int l = 0; l < 30; l++)
					{
						for (int m = 0; m < _monster->Get_MonsterInformation(l)[0].size(); m++)
						{
							_monster->Get_MonsterInformation(l)[0][m].x -= _mapMoveX;
						}
					}
					for (int l = 0; l < _player->Get_Bomb()->size(); l++)
					{
						_player->Get_Bomb()[0][l].x -= _mapMoveX;
					}
					for (int l = 0; l < 4; l++)
					{
						for (int m = 0; m < _object->Get_ObjectSton(l)->size(); m++)
						{
							_object->Get_ObjectSton(l)[0][m].x -= _mapMoveX;
						}
					}
					for (int l = 0; l < _object->Get_Object()->size(); l++)
					{
						_object->Get_Object()[0][l].x -= _mapMoveX;
					}
					for (int l = 0; l < _object->Get_ObjectThorn()->size(); l++)
					{
						_object->Get_ObjectThorn()[0][l].x -= _mapMoveX;
					}
					for (int l = 0; l < _monster->Get_MonsterBlood()->size(); l++)
					{
						_monster->Get_MonsterBlood()[0][l].x -= _mapMoveX;
					}
					for (int l = 0; l < _player->Get_Bullet()->size(); l++)
					{
						_player->Get_Bullet()[0][l].x += 5000;
					}
					for (int l = 0; l < _object->Get_ObjectBossDoor1()->size(); l++)
					{
						_object->Get_ObjectBossDoor1()[0][l].x -= _mapMoveX;
					}
					_operationkey->setX(_operationkey->getX() - _mapMoveX);

					_miniMap.left += 31;
					_miniMap.right += 31;
				}
			}
		}
	}


	_survivalMonster = 0;
	for (int k = 0; k < 30; k++)
	{
		for (int i = 0; i < _monster->Get_MonsterInformation(k)->size(); i++)
		{
			if (IntersectRect(&_impact, &cameraImpactrc, &_monster->Get_MonsterInformation(k)[0][i].rc))
			{
				//�� �ȿ� ���Ͱ� �Ѹ����� ������++
				_survivalMonster++;
			}
		}
	}
	// ��ȿ� ���Ͱ� ������ �� ����
	if (_survivalMonster == 0)
	{
		for (int j = 0; j < 4; j++)
		{
			for (int f = 0; f < _object->Get_ShopLockeDoor(j)->size(); f++)
			{
				//����� ī�޶� �浹�ϴ� ��
				if (IntersectRect(&_impact, &cameraImpactrc, &_object->Get_ShopLockeDoor(j)[0][f].rc) &&
					IntersectRect(&_impact, &_player->Get_PlayerInformation()->rc, &_object->Get_ShopLockeDoor(j)[0][f].rc)&&
					_player->Get_PlayerInformation()->key > 0)
				{
					if(!_object->Get_ShopLockeDoor(j)[0][f].open)_player->Get_PlayerInformation()->key -= 1;
					_object->Get_ShopLockeDoor(j)[0][f].open = true;

					//�� �̹��� ����
					if (j == 0)_object->Get_ShopLockeDoor(j)[0][f].frameX = 1;
					if (j == 1)_object->Get_ShopLockeDoor(j)[0][f].frameX = 1;
					if (j == 2)_object->Get_ShopLockeDoor(j)[0][f].frameY = 1;
					if (j == 3)_object->Get_ShopLockeDoor(j)[0][f].frameY = 1;
				}
			}
		}
	}

	// ��乮���� 
	for (int j = 0; j < 4; j++)
	{
		for (int f = 0; f < _object->Get_ShopLockeDoor(j)->size(); f++)
		{
			if (IntersectRect(&_impact, &_player->Get_PlayerInformation()->rc, &_object->Get_ShopLockeDoor(j)[0][f].rc))
			{
				if (j == 0 && _object->Get_ShopLockeDoor(j)[0][f].frameX == 1)
				{
					y += _mapMoveY;

					SOUNDMANAGER->play("��乮", 1.0f);
					(*_player->Get_Gimage())->setY((*_player->Get_Gimage())->getY() + 350);

					for (int p = 0; p < 4; p++)
					{
						for (int o = 0; o < _object->Get_ObjectDoor(p)->size(); o++)
						{
							_object->Get_ObjectDoor(p)[0][o].y += _mapMoveY;
						}
					}
					for (int p = 0; p < 4; p++)
					{
						for (int o = 0; o < _object->Get_ShopLockeDoor(p)->size(); o++)
						{
							_object->Get_ShopLockeDoor(p)[0][o].y += _mapMoveY;
						}
					}
					for (int p = 0; p < 20; p++)
					{
						_item->Get_ItemList(p)->rc.bottom += _mapMoveY;
						_item->Get_ItemList(p)->rc.top += _mapMoveY;


					}
					for (int p = 0; p < _player->Get_Bomb()->size(); p++)
					{
						_player->Get_Bomb()[0][p].y += _mapMoveY;
					}
					for (int l = 0; l < 30; l++)
					{
						for (int m = 0; m < _monster->Get_MonsterInformation(l)[0].size(); m++)
						{
							_monster->Get_MonsterInformation(l)[0][m].y += _mapMoveY;
						}
					}

					for (int l = 0; l < _player->Get_Bomb()->size(); l++)
					{
						_player->Get_Bomb()[0][l].y += _mapMoveY;
					}
					for (int l = 0; l < 4; l++)
					{
						for (int m = 0; m < _object->Get_ObjectSton(l)->size(); m++)
						{
							_object->Get_ObjectSton(l)[0][m].y += _mapMoveY;
						}
					}
					for (int l = 0; l < _object->Get_Object()->size(); l++)
					{
						_object->Get_Object()[0][l].y += _mapMoveY;
					}
					for (int l = 0; l < _object->Get_ObjectThorn()->size(); l++)
					{
						_object->Get_ObjectThorn()[0][l].y += _mapMoveY;
					}
					for (int l = 0; l < _monster->Get_MonsterBlood()->size(); l++)
					{
						_monster->Get_MonsterBlood()[0][l].y += _mapMoveY;
					}
					for (int l = 0; l < _player->Get_Bullet()->size(); l++)
					{
						_player->Get_Bullet()[0][l].y -= 5000;
					}
					for (int l = 0; l < _object->Get_ObjectBossDoor1()->size(); l++)
					{
						_object->Get_ObjectBossDoor1()[0][l].y += _mapMoveY;
					}
					_operationkey->setY(_operationkey->getY() + _mapMoveY);
					_miniMap.top -= 12;
					_miniMap.bottom -= 12;
				}
				if (j == 1 && _object->Get_ShopLockeDoor(j)[0][f].frameX == 1)
				{
					y -= _mapMoveY;
					SOUNDMANAGER->play("��乮", 1.0f);
					(*_player->Get_Gimage())->setY((*_player->Get_Gimage())->getY() - 350);

					for (int p = 0; p < 4; p++)
					{
						for (int o = 0; o < _object->Get_ObjectDoor(p)->size(); o++)
						{
							_object->Get_ObjectDoor(p)[0][o].y -= _mapMoveY;
						}
					}
					for (int p = 0; p < 4; p++)
					{
						for (int o = 0; o < _object->Get_ShopLockeDoor(p)->size(); o++)
						{
							_object->Get_ShopLockeDoor(p)[0][o].y -= _mapMoveY;
						}
					}
					for (int p = 0; p < 20; p++)
					{
						_item->Get_ItemList(p)->rc.bottom -= _mapMoveY;
						_item->Get_ItemList(p)->rc.top -= _mapMoveY;
					}
					for (int p = 0; p < _player->Get_Bomb()->size(); p++)
					{
						_player->Get_Bomb()[0][p].y -= _mapMoveY;
					}
					for (int l = 0; l < 30; l++)
					{
						for (int m = 0; m < _monster->Get_MonsterInformation(l)[0].size(); m++)
						{
							_monster->Get_MonsterInformation(l)[0][m].y -= _mapMoveY;
						}
					}
					for (int l = 0; l < _player->Get_Bomb()->size(); l++)
					{
						_player->Get_Bomb()[0][l].y -= _mapMoveY;
					}
					for (int l = 0; l < 4; l++)
					{
						for (int m = 0; m < _object->Get_ObjectSton(l)->size(); m++)
						{
							_object->Get_ObjectSton(l)[0][m].y -= _mapMoveY;
						}
					}
					for (int l = 0; l < _object->Get_Object()->size(); l++)
					{
						_object->Get_Object()[0][l].y -= _mapMoveY;
					}
					for (int l = 0; l < _object->Get_ObjectThorn()->size(); l++)
					{
						_object->Get_ObjectThorn()[0][l].y -= _mapMoveY;
					}
					for (int l = 0; l < _monster->Get_MonsterBlood()->size(); l++)
					{
						_monster->Get_MonsterBlood()[0][l].y -= _mapMoveY;
					}
					for (int l = 0; l < _player->Get_Bullet()->size(); l++)
					{
						_player->Get_Bullet()[0][l].y += 5000;
					}
					for (int l = 0; l < _object->Get_ObjectBossDoor1()->size(); l++)
					{
						_object->Get_ObjectBossDoor1()[0][l].y -= _mapMoveY;
					}
					_operationkey->setY(_operationkey->getY() - _mapMoveY);
					_miniMap.top += 12;
					_miniMap.bottom += 12;
				}
				if (j == 2 && _object->Get_ShopLockeDoor(j)[0][f].frameY == 1)
				{
					x += _mapMoveX;
					SOUNDMANAGER->play("��乮", 1.0f);
					(*_player->Get_Gimage())->setX((*_player->Get_Gimage())->getX() + 580);

					for (int p = 0; p < 4; p++)
					{
						for (int o = 0; o < _object->Get_ObjectDoor(p)->size(); o++)
						{
							_object->Get_ObjectDoor(p)[0][o].x += _mapMoveX;
						}
					}
					for (int p = 0; p < 4; p++)
					{
						for (int o = 0; o < _object->Get_ShopLockeDoor(p)->size(); o++)
						{
							_object->Get_ShopLockeDoor(p)[0][o].x += _mapMoveX;
						}
					}
					for (int p = 0; p < 20; p++)
					{
						_item->Get_ItemList(p)->rc.left += _mapMoveX;
						_item->Get_ItemList(p)->rc.right += _mapMoveX;
					}
					for (int p = 0; p < _player->Get_Bomb()->size(); p++)
					{
						_player->Get_Bomb()[0][p].x += _mapMoveX;
					}
					for (int l = 0; l < 30; l++)
					{
						for (int m = 0; m < _monster->Get_MonsterInformation(l)[0].size(); m++)
						{
							_monster->Get_MonsterInformation(l)[0][m].x += _mapMoveX;
						}
					}
					for (int l = 0; l < _player->Get_Bomb()->size(); l++)
					{
						_player->Get_Bomb()[0][l].x += _mapMoveX;
					}
					for (int l = 0; l < 4; l++)
					{
						for (int m = 0; m < _object->Get_ObjectSton(l)->size(); m++)
						{
							_object->Get_ObjectSton(l)[0][m].x += _mapMoveX;
						}
					}
					for (int l = 0; l < _object->Get_Object()->size(); l++)
					{
						_object->Get_Object()[0][l].x += _mapMoveX;
					}
					for (int l = 0; l < _object->Get_ObjectThorn()->size(); l++)
					{
						_object->Get_ObjectThorn()[0][l].x += _mapMoveX;
					}
					for (int l = 0; l < _monster->Get_MonsterBlood()->size(); l++)
					{
						_monster->Get_MonsterBlood()[0][l].x += _mapMoveX;
					}
					for (int l = 0; l < _player->Get_Bullet()->size(); l++)
					{
						_player->Get_Bullet()[0][l].x -= 5000;
					}
					for (int l = 0; l < _object->Get_ObjectBossDoor1()->size(); l++)
					{
						_object->Get_ObjectBossDoor1()[0][l].x += _mapMoveX;
					}
					_operationkey->setX(_operationkey->getX() + _mapMoveX);

					_miniMap.left -= 31;
					_miniMap.right -= 31;
				}
				if (j == 3 && _object->Get_ShopLockeDoor(j)[0][f].frameY == 1)
				{
					x -= _mapMoveX;
					SOUNDMANAGER->play("��乮", 1.0f);
					(*_player->Get_Gimage())->setX((*_player->Get_Gimage())->getX() - 580);

					for (int p = 0; p < 4; p++)
					{
						for (int o = 0; o < _object->Get_ObjectDoor(p)->size(); o++)
						{
							_object->Get_ObjectDoor(p)[0][o].x -= _mapMoveX;
						}
					}
					for (int p = 0; p < 4; p++)
					{
						for (int o = 0; o < _object->Get_ShopLockeDoor(p)->size(); o++)
						{
							_object->Get_ShopLockeDoor(p)[0][o].x -= _mapMoveX;
						}
					}
					for (int p = 0; p < 20; p++)
					{
						_item->Get_ItemList(p)->rc.left -= _mapMoveX;
						_item->Get_ItemList(p)->rc.right -= _mapMoveX;
					}
					for (int p = 0; p < _player->Get_Bomb()->size(); p++)
					{
						_player->Get_Bomb()[0][p].x -= _mapMoveX;
					}
					for (int l = 0; l < 30; l++)
					{
						for (int m = 0; m < _monster->Get_MonsterInformation(l)[0].size(); m++)
						{
							_monster->Get_MonsterInformation(l)[0][m].x -= _mapMoveX;
						}
					}
					for (int l = 0; l < _player->Get_Bomb()->size(); l++)
					{
						_player->Get_Bomb()[0][l].x -= _mapMoveX;
					}
					for (int l = 0; l < 4; l++)
					{
						for (int m = 0; m < _object->Get_ObjectSton(l)->size(); m++)
						{
							_object->Get_ObjectSton(l)[0][m].x -= _mapMoveX;
						}
					}
					for (int l = 0; l < _object->Get_Object()->size(); l++)
					{
						_object->Get_Object()[0][l].x -= _mapMoveX;
					}
					for (int l = 0; l < _object->Get_ObjectThorn()->size(); l++)
					{
						_object->Get_ObjectThorn()[0][l].x -= _mapMoveX;
					}
					for (int l = 0; l < _monster->Get_MonsterBlood()->size(); l++)
					{
						_monster->Get_MonsterBlood()[0][l].x -= _mapMoveX;
					}
					for (int l = 0; l < _player->Get_Bullet()->size(); l++)
					{
						_player->Get_Bullet()[0][l].x += 5000;
					}
					for (int l = 0; l < _object->Get_ObjectBossDoor1()->size(); l++)
					{
						_object->Get_ObjectBossDoor1()[0][l].x -= _mapMoveX;
					}
					_operationkey->setX(_operationkey->getX() - _mapMoveX);

					_miniMap.left += 31;
					_miniMap.right += 31;
				}
			}
		}
	}

	//�ڿ� ���� �̵�
	for (int i = 0; i < MAX_MAP_SIZE; i++)
	{
		for (int j = 0; j < MAX_MAP_SIZE; j++)
		{
			_baseTileRC[i][j] = RectMake((88 * j) - 87 + x - _mapX, 75 + 77 * i  + y - _mapY, 88, 77);
		}
	}

	// x ��ĭ�� 793
	// y ��ĭ�� -540
	//_baseTileRC[i][j] = RectMake((88 * j) - 87 + x, 75 + 77 * i  + y, 88, 77);


	//�÷��̾� ���� �� ��ȣ�ۿ�
	for (int i = 0; i < _player->Get_Bullet()->size(); i++)
	{
		for (int m = 0; m < 4; m++)
		{
			for (int k = 0; k < _object->Get_ObjectSton(m)->size(); k++)
			{
				if (IntersectRect(&_impact, &_player->Get_Bullet()[0][i].rc, &_object->Get_ObjectSton(m)[0][k].rc))
				{
					_player->Get_Bullet()[0][i].impact = true;
				}
			}
		}
	}
	//�÷��̾� ���� �� ��ȣ�ۿ�
	for (int i = 0; i < _player->Get_Bullet()->size(); i++)
	{
		for (int k = 0; k < _object->Get_Object()->size(); k++)
		{
			if (IntersectRect(&_impact, &_player->Get_Bullet()[0][i].rc, &_object->Get_Object()[0][k].rc))
			{
				_player->Get_Bullet()[0][i].impact = true;
			}
		}
	}


	// �� �÷��̾� ��ȣ�ۿ�
	if (!_caricature[5])
	{
		for (int m = 0; m < 4; m++)
		{
			for (int k = 0; k < _object->Get_ObjectSton(m)->size(); k++)
			{
				if (IntersectRect(&_impact, &_player->Get_PlayerInformation()->rc, &_object->Get_ObjectSton(m)[0][k].rc))
				{
					if ((_object->Get_ObjectSton(m)[0][k].rc.left + _object->Get_ObjectSton(m)[0][k].rc.right) / 2 > _player->Get_PlayerInformation()->rc.left)
					{
						(*_player->Get_Gimage())->setX((*_player->Get_Gimage())->getX() - 5.0f);
					}
					if ((_object->Get_ObjectSton(m)[0][k].rc.left + _object->Get_ObjectSton(m)[0][k].rc.right) / 2 < _player->Get_PlayerInformation()->rc.right)
					{
						(*_player->Get_Gimage())->setX((*_player->Get_Gimage())->getX() + 5.0f);
					}
					if ((_object->Get_ObjectSton(m)[0][k].rc.bottom + _object->Get_ObjectSton(m)[0][k].rc.top) / 2 > _player->Get_PlayerInformation()->rc.top)
					{
						(*_player->Get_Gimage())->setY((*_player->Get_Gimage())->getY() - 5.0f);
					}
					if ((_object->Get_ObjectSton(m)[0][k].rc.bottom + _object->Get_ObjectSton(m)[0][k].rc.top) / 2 < _player->Get_PlayerInformation()->rc.bottom)
					{
						(*_player->Get_Gimage())->setY((*_player->Get_Gimage())->getY() + 5.0f);
					}
				}
			}
		}
	}
	//���� ���� �� �浹����
	for (int i = 0; i < _monster->Get_MonsterBullet()->size(); i++)
	{
		for(int k=0; k<4; k++)
		{ 
		    for (int j = 0; j < _object->Get_ObjectSton(k)->size(); j++)
		    {
				if (IntersectRect(&_impact, &_monster->Get_MonsterBullet()[0][i].rc, &_object->Get_ObjectSton(k)[0][j].rc))
				{
					_monster->Get_MonsterBullet()[0][i].impact = true;
				}
		    }
		}
	}
	//���� ���� �� �浹����
	for (int i = 0; i < _monster->Get_MonsterBullet1()->size(); i++)
	{
		for (int k = 0; k < 4; k++)
		{
			for (int j = 0; j < _object->Get_ObjectSton(k)->size(); j++)
			{
				if (IntersectRect(&_impact, &_monster->Get_MonsterBullet1()[0][i].rc, &_object->Get_ObjectSton(k)[0][j].rc))
				{
					_monster->Get_MonsterBullet1()[0][i].impact = true;
				}
			}
		}
	}
	//���� ���� �� �浹����
	for (int i = 0; i < _monster->Get_MonsterBullet2()->size(); i++)
	{
		for (int k = 0; k < 4; k++)
		{
			for (int j = 0; j < _object->Get_ObjectSton(k)->size(); j++)
			{
				if (IntersectRect(&_impact, &_monster->Get_MonsterBullet2()[0][i].rc, &_object->Get_ObjectSton(k)[0][j].rc))
				{
					_monster->Get_MonsterBullet2()[0][i].impact = true;
				}
			}
		}
	}

	//���� �����鼭 ������ ��ȯ 
	for (int j = 0; j < _monster->Get_MonsterInformation(9)->size(); j++)
	{
		if (_monster->Get_MonsterInformation(9)[0][j].hp <= 0)
		{
			_player->Get_PlayerInformation()->skileGage++;
			if (_player->Get_PlayerInformation()->skileGage > 6)_player->Get_PlayerInformation()->skileGage = 6;

			object ob2;
			ob2.x = (_map.left + _map.right) / 2 - 50;
			ob2.y = (_map.top + _map.bottom) / 2 - 25 + 60;
			ob2.impact = false;
			ob2.frameX = 0;
			ob2.frameY = 0;
			ob2.open = false;
			ob2.alpha = 0;
			ob2.frameXTime = 0;
			ob2.Name = "Stone3";
			_object->Get_ObjectSton(3)[0].push_back(ob2);

			object ob3;
			ob3.x = (_map.left + _map.right) / 2 ;
			ob3.y = (_map.top + _map.bottom) / 2 - 25 + 60;
			ob3.impact = false;
			ob3.frameX = 0;
			ob3.frameY = 0;
			ob3.open = false;
			ob3.alpha = 0;
			ob3.frameXTime = 0;
			ob3.Name = "Stone3";
			_object->Get_ObjectSton(3)[0].push_back(ob3);

			_item->Get_ItemList(3)->rc.left = (_map.left + _map.right) / 2 - 25 + 2;
			_item->Get_ItemList(3)->rc.right = (_map.left + _map.right) / 2 - 25 + 22;
			_item->Get_ItemList(3)->rc.top = (_map.top + _map.bottom) / 2 - 25 + 60;
			_item->Get_ItemList(3)->rc.bottom = (_map.top + _map.bottom) / 2 - 25 + 30 + 90;

			_item->Get_ItemList(12)->rc.left = (_map.left + _map.right) / 2 - 25 + 52;
			_item->Get_ItemList(12)->rc.right = (_map.left + _map.right) / 2 - 25 + 82;
			_item->Get_ItemList(12)->rc.top = (_map.top + _map.bottom) / 2 - 25 + 60;
			_item->Get_ItemList(12)->rc.bottom = (_map.top + _map.bottom) / 2 - 25 + 30 + 90;

			object ob4;
			ob4.x = (_map.left + _map.right) / 2 - 30;
			ob4.y = (_map.top + _map.bottom) / 2 - 25 - 160;
			ob4.impact = false;
			ob4.frameX = 0;
			ob4.frameY = 0;
			ob4.open = false;
			ob4.alpha = 0;
			ob4.frameXTime = 0;
			ob4.Name = "����Ŭ���";
			(*_object->Get_ObjectBossDoor1()).push_back(ob4);

			_bossIndex = 0;
			_mapName = "2floor.json";
		}
	}

	for (int i = 0; i < _object->Get_ObjectBossDoor1()->size(); i++)
	{
		if (IntersectRect(&_impact, &_object->Get_ObjectBossDoor1()[0][i].rc, &_player->Get_PlayerInformation()->rc)&& !(*_player->Get_PlayerOut()))
		{
			(*_player->Get_PlayerOut()) = true;
		}

		if ((*_player->Get_PlayerOut()))
		{
			_object->Get_ObjectBossDoor1()[0][i].frameXTime += TIMEMANAGER->getElapsedTime();

			if (_object->Get_ObjectBossDoor1()[0][i].frameXTime > 0.2f)
			{
				_object->Get_ObjectBossDoor1()[0][i].frameXTime = 0;
				_object->Get_ObjectBossDoor1()[0][i].frameX++;
				if (_object->Get_ObjectBossDoor1()[0][i].frameX > 5)
				{
					_object->Get_ObjectBossDoor1()[0][i].frameX = 5;
				}

			}

			if (_object->Get_ObjectBossDoor1()[0][i].frameX == 5)
			{
				_bossClearVideo[_bossIndex] = true;
				_frameTime += TIMEMANAGER->getElapsedTime();
				if (_frameTime > 0.2f)
				{
					_frameTime = 0;
					_bossClear[_bossIndex]->setFrameX(_bossClear[_bossIndex]->getFrameX() + 1);

					if (_bossClear[_bossIndex]->getFrameX() >= 45)
					{
						_frameTime = 0;
						_bossClearVideo[_bossIndex] = false;
						_bossClearVideoEnd = true;
					}
				}
			}

			if (_bossClearVideoEnd)
			{
				if (_mapName == "2floor.json")
				{
					_item->Get_ItemList(10)->rc.bottom = -157;
					_item->Get_ItemList(10)->rc.top = -207;
					_item->Get_ItemList(10)->rc.left = -395;
					_item->Get_ItemList(10)->rc.right = -345;
				}
				x = 0;
				y = 0;
				LodeMap();
				(*_player->Get_PlayerOut()) = false;
				_object->Get_ObjectBossDoor1()->erase(_object->Get_ObjectBossDoor1()->begin() + i);

				(*_player->Get_Gimage())->setX(WINSIZE_X / 2);
				(*_player->Get_Gimage())->setY(WINSIZE_Y / 2);

				_bossClearVideoEnd = false;

						
			}
		}
	}
	for (int i = 0; i < 20; i++)
	{
		if (IntersectRect(&_impact, &_item->Get_ItemList(i)->rc, &_player->Get_PlayerInformation()->rc))
		{
			if (i == 6 && _player->Get_PlayerInformation()->money < 15) continue;
			else if (i == 6) _player->Get_PlayerInformation()->money -= 15;

			if (i == 7 && _player->Get_PlayerInformation()->money < 15) continue;
			else if (i == 7) _player->Get_PlayerInformation()->money -= 15;

			if (i == 9 && _player->Get_PlayerInformation()->money < 5) continue;
			else if (i == 9) _player->Get_PlayerInformation()->money -= 5;
			SOUNDMANAGER->play("������ȹ��", 1.0f);
		}
	}

	if (KEYMANAGER->isOnceKeyDown('Z'))
	{
		_MapM++;
	}
	
}

void GameSystemManager::render(void)
{
	

	for (int i = 0; i < MAX_MAP_SIZE; i++)
	{
		for (int j = 0; j < MAX_MAP_SIZE; j++)
		{
			if (_tileRC[i][j].draw)
			{
				_tileRC[i][j].img->frameRender(getMemDC(),
					_baseTileRC[i][j].left, _baseTileRC[i][j].top, _tileRC[i][j].frameX, _tileRC[i][j].frameY,1.7,1.5);


				//cout << _baseTileRC[i][j].left << endl;
				//cout << _baseTileRC[i][j].top << endl;
			}
			if (_doorRC[i][j].draw)
			{
				_doorRC[i][j].img->frameRender(getMemDC(),
					_baseTileRC[i][j].left, _baseTileRC[i][j].top, _doorRC[i][j].frameX, _doorRC[i][j].frameY, 1.7, 1.5);


				//cout << _baseTileRC[i][j].left << endl;
				//cout << _baseTileRC[i][j].top << endl;
			}
		}
	}
	if (_MapM == 0)IMAGEMANAGER->render("����Ű", getMemDC(), _operationkey->getX(), _operationkey->getY());

	for (int i = 0; i < 20; i++)
	{
		RECT _rc;
		if (IntersectRect(&_rc, &_item->Get_ItemList(i)->rc,&_player->Get_PlayerInformation()->rc))
		{
			if (i == 6 && _player->Get_PlayerInformation()->money < 15) continue;

			if (i == 7 && _player->Get_PlayerInformation()->money < 15) continue;

			if (i == 9 && _player->Get_PlayerInformation()->money < 5) continue;

			_player->Set_ItemList(i, _item);
			cout << "������ ȹ��" << endl;

			_getItem = true;
			_hooray[i] = true;
			_caricature[i] = true;

			if (i == 6 && !_itemMoney[0])
			{
				_player->Get_PlayerInformation()->money = 84;
				_itemMoney[0] = true;
			}
			if (i == 7 && !_itemMoney[1])
			{
				_player->Get_PlayerInformation()->money = 69;
				_itemMoney[1] = true;
			}
			if (i == 9 && !_itemMoney[2])
			{
				_player->Get_PlayerInformation()->money = 64;
				_itemMoney[2] = true;
			}
		}

		if (_hooray[i])
		{
			if (_getItem)
			{
				if (i == 9)_item->Get_ItemList(i)->itemImage->setFrameY(1);
				if (i == 7)_item->Get_ItemList(i)->itemImage->setFrameY(1);
			    if (i == 6)_item->Get_ItemList(i)->itemImage->setFrameY(1);

				_item->Get_ItemList(i)->rc.top = _player->Get_PlayerInformation()->rc.top - 40;
				_item->Get_ItemList(i)->rc.bottom = _player->Get_PlayerInformation()->rc.bottom - 40;
				_item->Get_ItemList(i)->rc.left = _player->Get_PlayerInformation()->rc.left ;
				_item->Get_ItemList(i)->rc.right = _player->Get_PlayerInformation()->rc.right ;
			}
			else
			{
				if(i != 9)_item->Get_ItemList(i)->rc.left += 50000;
				if(i != 9)_item->Get_ItemList(i)->rc.right += 50000;
				if (i == 9)
				{
					_item->Get_ItemList(i)->rc.left = 500;
					_item->Get_ItemList(i)->rc.right = 520;
					_item->Get_ItemList(i)->rc.top = 45;
					_item->Get_ItemList(i)->rc.bottom = 75;
					_shild = true;
				}

				_hooray[i] = false;
			}
		}
		
	}

	if (_caricature[9] && !_hooray[9])
	{
		_shild = true;
		_item->Get_ItemList(9)->rc.left = 500;
		_item->Get_ItemList(9)->rc.right = 520;
		_item->Get_ItemList(9)->rc.top = 45;
		_item->Get_ItemList(9)->rc.bottom = 75;
	}

	_monster->bloodrender();
	_player->renderBoom();
	_object->render();
	_monster->render();
	_player->render();
	_item->render();
	_ui->render();

	if (_shild)
	{
		IMAGEMANAGER->frameRender("book", getMemDC(), 485, 35, 0, 1);
	}

	if (_hooray[0])IMAGEMANAGER->alphaRender("����0", getMemDC(), 185, 100, 240);
	if (_hooray[1])IMAGEMANAGER->alphaRender("����1", getMemDC(), 185, 100, 240);
	if (_hooray[2])IMAGEMANAGER->alphaRender("����2", getMemDC(), 185, 100, 240);
	if (_hooray[3])IMAGEMANAGER->alphaRender("����3", getMemDC(), 185, 100, 240);
	if (_hooray[4])IMAGEMANAGER->alphaRender("����4", getMemDC(), 185, 100, 240);
	if (_hooray[5])IMAGEMANAGER->alphaRender("����5", getMemDC(), 185, 100, 240);
	if (_hooray[6])IMAGEMANAGER->alphaRender("����6", getMemDC(), 185, 100, 240);
	if (_hooray[7])IMAGEMANAGER->alphaRender("����7", getMemDC(), 185, 100, 240);
	if (_hooray[8])IMAGEMANAGER->alphaRender("����8", getMemDC(), 185, 100, 240);

	//if (_mapName == "1floor.json")
	//{
	//	IMAGEMANAGER->render("1������", getMemDC(), -20, -34);
	//}
	//else if (_mapName == "2floor.json")
	//{
	//	IMAGEMANAGER->render("2������", getMemDC(), -20, -34);
	//}
	//else if (_mapName == "3floor.json")
	//{
	//	IMAGEMANAGER->render("3������", getMemDC(), -20, -34);
	//}
	//else if (_mapName == "4floor.json")
	//{
	//	IMAGEMANAGER->render("4������", getMemDC(), -20, -34);
	//}
	if (_MapM == 0)
	{
		IMAGEMANAGER->render("1������", getMemDC(), -20, -34);
	}
	else if (_MapM == 1)
	{
		IMAGEMANAGER->render("2������", getMemDC(), -20, -34);
	}
	else if (_MapM == 2)
	{
		IMAGEMANAGER->render("3������", getMemDC(), -20, -34);
	}
	else if (_MapM == 3)
	{
		IMAGEMANAGER->render("4������", getMemDC(), -20, -34);
	}
	

	DrawRectMake(getMemDC(), _miniMap);

	if (*(_monster->Get_bossEnd(0)))
	{
		IMAGEMANAGER->frameRender("1����������", getMemDC(), 0, 0,(*_monster->Get_bossGImage(0))->getFrameX(),0);
	}
	if (*(_monster->Get_bossEnd(1)))
	{
		IMAGEMANAGER->frameRender("2����������", getMemDC(), 0, 0, (*_monster->Get_bossGImage(1))->getFrameX(), 0);
	}
	if (*(_monster->Get_bossEnd(2)))
	{
		IMAGEMANAGER->frameRender("3����������", getMemDC(), 0, 0, (*_monster->Get_bossGImage(2))->getFrameX(), 0);
	}
	if (*(_monster->Get_bossEnd(3)))
	{
		IMAGEMANAGER->frameRender("4����������", getMemDC(), 0, 0, (*_monster->Get_bossGImage(3))->getFrameX(), 0);
	}

	if (_bossClearVideo[0])
	{
		IMAGEMANAGER->frameRender("1��Ŭ����", getMemDC(), 0, 0, _bossClear[0]->getFrameX(), 0);
	}

	if (_bossClearVideo[1])
	{
		IMAGEMANAGER->frameRender("2��Ŭ����", getMemDC(), 0, 0, _bossClear[1]->getFrameX(), 0);
	}

	if (_bossClearVideo[2])
	{
		IMAGEMANAGER->frameRender("3��Ŭ����", getMemDC(), 0, 0, _bossClear[2]->getFrameX(), 0);
	}

	//DrawRectMake(getMemDC(), _map);
	//DrawRectMake(getMemDC(), cameraImpactrc);



	//�ĸ��� ���� ���� �浹
	for (int i = 0; i < _monster->Get_MonsterBullet()->size(); i++)
	{
		for (int j = 0; j < 2; j++)
		{
			if (IntersectRect(&_impact, _player->Get_flyRect(j), &_monster->Get_MonsterBullet()[0][i].rc))
			{
				_monster->Get_MonsterBullet()[0][i].impact = true;
			}
		}
	}

	for (int i = 0; i < _monster->Get_MonsterBullet1()->size(); i++)
	{
		for (int j = 0; j < 2; j++)
		{
			if (IntersectRect(&_impact, _player->Get_flyRect(j), &_monster->Get_MonsterBullet1()[0][i].rc))
			{
				_monster->Get_MonsterBullet1()[0][i].impact = true;
			}
		}
	}

	for (int i = 0; i < _monster->Get_MonsterBullet2()->size(); i++)
	{
		for (int j = 0; j < 2; j++)
		{
			if (IntersectRect(&_impact, _player->Get_flyRect(j), &_monster->Get_MonsterBullet2()[0][i].rc))
			{
				_monster->Get_MonsterBullet2()[0][i].impact = true;
			}
		}
	}

}

void GameSystemManager::LodeMap()
{
	_miniMap = RectMake(142, 41, 27, 10);
	memset(_tileRC, 0, sizeof(_tileRC));
	memset(_doorRC, 0, sizeof(_doorRC));
	memset(_monsterRc, 0, sizeof(_monsterRc));

	for (int p = 0; p < 4; p++)
	{
		_object->Get_ObjectDoor(p)->clear();
	}
	for (int p = 0; p < 4; p++)
	{
		_object->Get_ShopLockeDoor(p)->clear();
	}
	_player->Get_Bomb()->clear();
	for (int l = 0; l < 30; l++)
	{
		_monster->Get_MonsterInformation(l)[0].clear();
	}
	_player->Get_Bomb()->clear();
	for (int l = 0; l < 4; l++)
	{
		_object->Get_ObjectSton(l)->clear();
	}
	_object->Get_Object()->clear();
	_object->Get_ObjectThorn()->clear();
	_monster->Get_MonsterBlood()->clear();
	_player->Get_Bullet()->clear();
	//_object->Get_ObjectBossDoor1()->clear();
	

	Json::Value root = JSONDATAMANAGER->loadJsonFile(_mapName);

	int countX = 0;
	int countY = 0;
	for (auto it = root["Ÿ��"].begin(); it != root["Ÿ��"].end(); it++)
	{

		if ((*it).isObject())
		{
			MAKE_MAP _tileInfo;
			_tileInfo.frameX = (*it)["frameX"].asInt();
			_tileInfo.frameY = (*it)["frameY"].asInt();
			_tileInfo.draw = (*it)["draw"].asBool();
			_tileInfo.idx = (*it)["idx"].asInt();
			_tileInfo.keyNum = (*it)["keyNum"].asInt();
			_tileInfo.img = IMAGEMANAGER->findImage(_keyValue[_tileInfo.keyNum]);

			countX++;
			if (countX >= MAX_MAP_SIZE)
			{
				countX = 0;
				countY++;

			}
			_tileRC[countY][countX] = _tileInfo;
		}
	}
	int countX1 = 0;
	int countY1 = 0;
	for (auto it = root["��"].begin(); it != root["��"].end(); it++)
	{

		if ((*it).isObject())
		{
			MAKE_MAP _tileInfo;
			_tileInfo.frameX = (*it)["frameX"].asInt();
			_tileInfo.frameY = (*it)["frameY"].asInt();
			_tileInfo.draw = (*it)["draw"].asBool();
			_tileInfo.idx = (*it)["idx"].asInt();
			_tileInfo.keyNum = (*it)["keyNum"].asInt();
			_tileInfo.img = IMAGEMANAGER->findImage(_keyValue[_tileInfo.keyNum]);

			countX1++;
			if (countX1 >= MAX_MAP_SIZE)
			{
				countX1 = 0;
				countY1++;

			}

			/*int _fy = _tileInfo.idx / MAX_MAP_SIZE;
			int _fx = _tileInfo.idx % MAX_MAP_SIZE;
			*/////cout << _fy << ", " << _fx << endl;
			//_doorRC[countY1][countX1] = _tileInfo;
			//_tileRC[_fy][_fx].img = IMAGEMANAGER->findImage(_tileImgName[_tileInfo.keyNumber]);

			if (_tileInfo.draw)
			{
				if (_tileInfo.frameX == 0 && _tileInfo.frameY == 0)
				{
					//_mapX = 1583;
					//_mapY = 1080;

					object ob3;
					ob3.x = countX1 * 88 -78   - _mapX;
					ob3.y = countY1 * 77 + 102 - _mapY;

					ob3.impact = false;
					ob3.frameX = 0;
					ob3.frameY = 0;
					ob3.open = false;
					ob3.alpha = 0;
					ob3.frameXTime = 0;
					ob3.Name = "��";
					_object->Get_ObjectDoor(0)->push_back(ob3);
				}
				if (_tileInfo.frameX == 1 && _tileInfo.frameY == 0)
				{
					object ob3;
					ob3.x = countX1 * 88 - 78 - _mapX;
					ob3.y = countY1 * 77 + 75 - _mapY;
					ob3.impact = false;
					ob3.frameX = 0;
					ob3.frameY = 0;
					ob3.open = false;
					ob3.alpha = 0;
					ob3.frameXTime = 0;
					ob3.Name = "��1";
					_object->Get_ObjectDoor(1)->push_back(ob3);
				}
				if (_tileInfo.frameX == 2 && _tileInfo.frameY == 0)
				{
					object ob3;
					ob3.x = countX1 * 88 - 85 - _mapX;
					ob3.y = countY1 * 77 + 77 - _mapY;
					ob3.impact = false;
					ob3.frameX = 0;
					ob3.frameY = 0;
					ob3.open = false;
					ob3.alpha = 0;
					ob3.frameXTime = 0;
					ob3.Name = "��3";
					_object->Get_ObjectDoor(3)->push_back(ob3);
				}
				if (_tileInfo.frameX == 3 && _tileInfo.frameY == 0)
				{
					object ob3;
					ob3.x = countX1 * 88 - 47 - _mapX;
					ob3.y = countY1 * 77 + 77 - _mapY;
					ob3.impact = false;
					ob3.frameX = 0;
					ob3.frameY = 0;
					ob3.open = false;
					ob3.alpha = 0;
					ob3.frameXTime = 0;
					ob3.Name = "��2";
					_object->Get_ObjectDoor(2)->push_back(ob3);
				}
				if (_tileInfo.frameX == 0 && _tileInfo.frameY == 4)
				{
					object ob3;
					ob3.x = countX1 * 88 - 78 - _mapX;
					ob3.y = countY1 * 77 + 93 - _mapY;

					ob3.impact = false;
					ob3.frameX = 0;
					ob3.frameY = 0;
					ob3.open = false;
					ob3.alpha = 0;
					ob3.frameXTime = 0;
					ob3.Name = "������";
					_object->Get_ObjectDoor(0)->push_back(ob3);
				}
				if (_tileInfo.frameX == 1 && _tileInfo.frameY == 4)
				{
					object ob3;
					ob3.x = countX1 * 88 - 77 - _mapX;
					ob3.y = countY1 * 77 + 77 - _mapY;
					ob3.impact = false;
					ob3.frameX = 0;
					ob3.frameY = 0;
					ob3.open = false;
					ob3.alpha = 0;
					ob3.frameXTime = 0;
					ob3.Name = "������1";
					_object->Get_ObjectDoor(1)->push_back(ob3);
				}
				if (_tileInfo.frameX == 2 && _tileInfo.frameY == 4)
				{
					object ob3;
					ob3.x = countX1 * 88 - 85 - _mapX;
					ob3.y = countY1 * 77 + 77 - _mapY;
					ob3.impact = false;
					ob3.frameX = 0;
					ob3.frameY = 0;
					ob3.open = false;
					ob3.alpha = 0;
					ob3.frameXTime = 0;
					ob3.Name = "������3";
					_object->Get_ObjectDoor(3)->push_back(ob3);
				}
				if (_tileInfo.frameX == 3 && _tileInfo.frameY == 4)
				{
					object ob3;
					ob3.x = countX1 * 88 - 58 - _mapX;
					ob3.y = countY1 * 77 + 77 - _mapY;
					ob3.impact = false;
					ob3.frameX = 0;
					ob3.frameY = 0;
					ob3.open = false;
					ob3.alpha = 0;
					ob3.frameXTime = 0;
					ob3.Name = "������2";
					_object->Get_ObjectDoor(2)->push_back(ob3);
				}
				//�Ʒ����� ��
				if (_tileInfo.frameX == 0 && _tileInfo.frameY == 3)
				{

					object ob3;
					ob3.x = countX1 * 88 - 73 - _mapX;
					ob3.y = countY1 * 77 + 95 - _mapY;

					ob3.impact = false;
					ob3.frameX = 0;
					ob3.frameY = 0;
					ob3.open = false;
					ob3.alpha = 0;
					ob3.frameXTime = 0;
					ob3.Name = "������";
					_object->Get_ObjectDoor(0)->push_back(ob3);
				}
				//������ �Ʒ�
				if (_tileInfo.frameX == 1 && _tileInfo.frameY == 3)
				{
					object ob3;
					ob3.x = countX1 * 88 - 78 - _mapX;
					ob3.y = countY1 * 77 + 75 - _mapY;
					ob3.impact = false;
					ob3.frameX = 0;
					ob3.frameY = 0;
					ob3.open = false;
					ob3.alpha = 0;
					ob3.frameXTime = 0;
					ob3.Name = "������1";
					_object->Get_ObjectDoor(1)->push_back(ob3);
				}
				//���ʿ��� ������
				if (_tileInfo.frameX == 2 && _tileInfo.frameY == 3)
				{
					object ob3;
					ob3.x = countX1 * 88 - 85 - _mapX;
					ob3.y = countY1 * 77 + 77 - _mapY;
					ob3.impact = false;
					ob3.frameX = 0;
					ob3.frameY = 0;
					ob3.open = false;
					ob3.alpha = 0;
					ob3.frameXTime = 0;
					ob3.Name = "������3";
					_object->Get_ObjectDoor(3)->push_back(ob3);
				}
				//�����ʿ��� ����
				if (_tileInfo.frameX == 3 && _tileInfo.frameY == 3)
				{
					object ob3;
					ob3.x = countX1 * 88 - 55 - _mapX;
					ob3.y = countY1 * 77 + 77 - _mapY;
					ob3.impact = false;
					ob3.frameX = 0;
					ob3.frameY = 0;
					ob3.open = false;
					ob3.alpha = 0;
					ob3.frameXTime = 0;
					ob3.Name = "������2";
					_object->Get_ObjectDoor(2)->push_back(ob3);
				}

				//�Ʒ����� ��
				if (_tileInfo.frameX == 0 && _tileInfo.frameY == 2)
				{

					object ob3;
					ob3.x = countX1 * 88 - 73 - _mapX;
					ob3.y = countY1 * 77 + 95 - _mapY;

					ob3.impact = false;
					ob3.frameX = 0;
					ob3.frameY = 0;
					ob3.open = false;
					ob3.alpha = 0;
					ob3.frameXTime = 0;
					ob3.Name = "��乮";
					_object->Get_ShopLockeDoor(0)->push_back(ob3);
				}
				//������ �Ʒ�
				if (_tileInfo.frameX == 1 && _tileInfo.frameY == 2)
				{
					object ob3;
					ob3.x = countX1 * 88 - 78 - _mapX;
					ob3.y = countY1 * 77 + 75 - _mapY;
					ob3.impact = false;
					ob3.frameX = 0;
					ob3.frameY = 0;
					ob3.open = false;
					ob3.alpha = 0;
					ob3.frameXTime = 0;
					ob3.Name = "��乮1";
					_object->Get_ShopLockeDoor(1)->push_back(ob3);
				}
				//���ʿ��� ������
				if (_tileInfo.frameX == 2 && _tileInfo.frameY == 2)
				{
					object ob3;
					ob3.x = countX1 * 88 - 85 - _mapX;
					ob3.y = countY1 * 77 + 77 - _mapY;
					ob3.impact = false;
					ob3.frameX = 0;
					ob3.frameY = 0;
					ob3.open = false;
					ob3.alpha = 0;
					ob3.frameXTime = 0;
					ob3.Name = "��乮3";
					_object->Get_ShopLockeDoor(3)->push_back(ob3);
				}
				//�����ʿ��� ����
				if (_tileInfo.frameX == 3 && _tileInfo.frameY == 2)
				{
					object ob3;
					ob3.x = countX1 * 88 - 55 - _mapX;
					ob3.y = countY1 * 77 + 77 - _mapY;
					ob3.impact = false;
					ob3.frameX = 0;
					ob3.frameY = 0;
					ob3.open = false;
					ob3.alpha = 0;
					ob3.frameXTime = 0;
					ob3.Name = "��乮2";
					_object->Get_ShopLockeDoor(2)->push_back(ob3);
				}
			}

		}

	}

	int countX2 = 0;
	int countY2 = 0;
	for (auto it = root["����"].begin(); it != root["����"].end(); it++)
	{

		if ((*it).isObject())
		{
			MAKE_MAP _tileInfo;
			_tileInfo.frameX = (*it)["frameX"].asInt();
			_tileInfo.frameY = (*it)["frameY"].asInt();
			_tileInfo.draw = (*it)["draw"].asBool();
			_tileInfo.idx = (*it)["idx"].asInt();
			_tileInfo.keyNum = (*it)["keyNum"].asInt();
			_tileInfo.img = IMAGEMANAGER->findImage(_keyValue[_tileInfo.keyNum]);

			countX2++;
			if (countX2 >= MAX_MAP_SIZE)
			{
				countX2 = 0;
				countY2++;

			}


			//_monsterRc[countY2][countX2] = _tileInfo;

			if (_tileInfo.draw)
			{
				//�󱼴޸� ����
				if (_tileInfo.frameX == 0 && _tileInfo.frameY == 0)
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
					monster5.x = countX2 * 88 - 70 - _mapX;
					monster5.y = countY2 * 77 + 100 - _mapY;
					monster5._monster = IMAGEMANAGER->findImage("�󱼴޸����͸�");
					monster5.frameHerd = 0;
					monster5.impact = false;


					_monster->Get_MonsterInformation(4)->push_back({ monster5 });
				}

				//�󱼸� �ִ� ����
				if (_tileInfo.frameX == 1 && _tileInfo.frameY == 0)
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
					monster6.x = countX2 * 88 -68 - _mapX;
					monster6.y = countY2 * 77 + 90 - _mapY;
					monster6._monster = IMAGEMANAGER->findImage("�󱼸���������");
					monster6.frameHerd = 0;
					monster6.impact = false;
					monster6.rnd = 0;
					monster6.atktrue = false;
					_monster->Get_MonsterInformation(5)->push_back({ monster6 });
				}
				//�ĸ�
				if (_tileInfo.frameX == 2 && _tileInfo.frameY == 1)
				{
					_monster->Get_MonsterInformation(2)->push_back({ (float)countX2 * 88 - 75 - _mapX, (float)countY2 * 77 + 80 - _mapY,  RND->getFromFloatTo(-1,1), 0.5f, 4.0f, 1.0f,0,0,
			        IMAGEMANAGER->findImage("������"),0,0,false,0 });
				}

				//���� ����
				if (_tileInfo.frameX == 3 && _tileInfo.frameY == 1)
				{
					_monster->Get_MonsterInformation(0)->push_back({ (float)countX2 * 88 - 75 - _mapX, (float)countY2 * 77 + 60 - _mapY, 0, 0.5f, 6.0f, 1.5f,0,0,
					IMAGEMANAGER->findImage("��������"),0,0,false,3 });
				}

				//���� ����
				if (_tileInfo.frameX == 1 && _tileInfo.frameY == 3)
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
					monster7.x = countX2 * 88 -  65 - _mapX;
					monster7.y = countY2 * 77 + 35  - _mapY;
					monster7._monster = IMAGEMANAGER->findImage("���и���");
					monster7.frameHerd = 0;
					monster7.impact = false;
					monster7.rnd = 0;
					monster7.atktrue = false;
					_monster->Get_MonsterInformation(6)->push_back({ monster7 });
				}

				//������
				if (_tileInfo.frameX == 3 && _tileInfo.frameY == 3)
				{
					_monster->Get_MonsterInformation(3)->push_back({ (float)countX2 * 88 - 65 - _mapX, (float)countY2 * 77 + 80 - _mapY,  RND->getFromFloatTo(-1,1), 0.5f, 5.0f, 0.5f,0,0,
					IMAGEMANAGER->findImage("������"),0,0,false,0 });
				}

				//���� �ִ� ����
				if (_tileInfo.frameX == 2 && _tileInfo.frameY == 0)
				{
					_monster->Get_MonsterInformation(1)->push_back({ (float)countX2 * 88 - 75 - _mapX, (float)countY2 * 77 + 85 - _mapY, 0, 0.5f, 6.0f, 0.5f,0,0,
					IMAGEMANAGER->findImage("������������"),0,0,false,0 });
				}
				//���
				if (_tileInfo.frameX == 3 && _tileInfo.frameY == 0)
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
					mogi.x = countX2 * 88 - 75 - _mapX;
					mogi.y = countY2 * 77 + 85 - _mapY;
					mogi._monster = IMAGEMANAGER->findImage("������");
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
					_monster->Get_MonsterInformation(12)->push_back({ mogi });
				}
				//���� 1
				if (_tileInfo.frameX == 0 && _tileInfo.frameY == 5)
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
					boss0.x = countX2 * 88 - 75 - _mapX;
					boss0.y = countY2 * 77 + 80 - _mapY;
					boss0._monster = IMAGEMANAGER->findImage("boss0");
					boss0.frameHerd = 0;
					boss0.impact = false;
					boss0.rnd = RND->getInt(4);
					boss0.atktrue = false;
					boss0.alpha = 255;
					boss0.a = 0;
					boss0.b = 0;
					boss0.die = false;
					_monster->Get_MonsterInformation(7)->push_back({ boss0 });
				}

				//���� 2
				if (_tileInfo.frameX == 1 && _tileInfo.frameY == 5)
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
					boss1.x = countX2 * 88 - 75 - _mapX;
					boss1.y = countY2 * 77 + 80 - _mapY;
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
					boss1.angle = getAngle(boss1.x, boss1.y, (_player->Get_PlayerInformation()->rc.left + _player->Get_PlayerInformation()->rc.right) / 2,
						(_player->Get_PlayerInformation()->rc.bottom + _player->Get_PlayerInformation()->rc.top) / 2 - 50);
					_monster->Get_MonsterInformation(8)->push_back({ boss1 });

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
					boss2.x = boss1.x;
					boss2.y = boss1.y;
					boss2._monster = IMAGEMANAGER->findImage("����1��");
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
					_monster->Get_MonsterInformation(9)->push_back({ boss2 });
				}

				//����3
				if (_tileInfo.frameX == 2 && _tileInfo.frameY == 5)
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
					boss3.speed = 2.0f;
					boss3.x = countX2 * 88 - 75 - _mapX;
					boss3.y = countY2 * 77 + 80 - _mapY;
					boss3._monster = IMAGEMANAGER->findImage("����2");
					boss3.frameHerd = 0;
					boss3.impact = false;
					boss3.rnd = RND->getInt(4);
					boss3.atktrue = false;
					boss3.alpha = 255;
					boss3.a = 0;
					boss3.b = 0;
					boss3.c = 0;
					boss3.die = false;
					_monster->Get_MonsterInformation(10)->push_back({ boss3 });

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
					boss4.x = countX2 * 88 - 75 - _mapX;
					boss4.y = countY2 * 77 + 80 - _mapY;
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
					_monster->Get_MonsterInformation(11)->push_back({ boss4 });
				}

				//����4
				if (_tileInfo.frameX == 3 && _tileInfo.frameY == 4)
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
					mogi.x = countX2 * 88 - 75 - _mapX;
					mogi.y = countY2 * 77 - 30 - _mapY;
					mogi._monster = IMAGEMANAGER->findImage("����3");
					mogi.frameHerd = 0;
					mogi.impact = false;
					mogi.rnd = 0;   /*RND->getInt(3)*/
					mogi.atktrue = false;
					mogi.alpha = 255;
					mogi.a = 0;
					mogi.b = 0;
					mogi.c = getAngle(mogi.x, mogi.y,
						(_player->Get_PlayerInformation()->rc.left + _player->Get_PlayerInformation()->rc.left) / 2 - 50, (_player->Get_PlayerInformation()->rc.bottom + _player->Get_PlayerInformation()->rc.top) / 2 - 50);;
					mogi.die = false;
					mogi.angle = 0;
					_monster->Get_MonsterInformation(13)->push_back({ mogi });
				}
			}

		}

	}

	int countX3 = 0;
	int countY3 = 0;
	for (auto it = root["������Ʈ"].begin(); it != root["������Ʈ"].end(); it++)
	{

		if ((*it).isObject())
		{
			MAKE_MAP _tileInfo;
			_tileInfo.frameX = (*it)["frameX"].asInt();
			_tileInfo.frameY = (*it)["frameY"].asInt();
			_tileInfo.draw = (*it)["draw"].asBool();
			_tileInfo.idx = (*it)["idx"].asInt();
			_tileInfo.keyNum = (*it)["keyNum"].asInt();
			_tileInfo.img = IMAGEMANAGER->findImage(_keyValue[_tileInfo.keyNum]);

			countX3++;
			if (countX3 >= MAX_MAP_SIZE)
			{
				countX3 = 0;
				countY3++;

			}

			if (_tileInfo.draw)
			{
				if (_tileInfo.frameX == 1 && _tileInfo.frameY == 0)
				{
					object ob2;
					ob2.x = countX3 * 88  -70 - _mapX;
					ob2.y = countY3 * 77 + 80 - _mapY;
					ob2.impact = false;
					ob2.frameX = 0;
					ob2.frameY = 0;
					ob2.open = false;
					ob2.alpha = 0;
					ob2.frameXTime = 0;
					ob2.Name = "Stone0";
					_object->Get_ObjectSton(0)[0].push_back(ob2);

				}
				if (_tileInfo.frameX == 2 && _tileInfo.frameY == 0)
				{
					object ob2;
					ob2.x = countX3 * 88 - 70 - _mapX;
					ob2.y = countY3 * 77 + 80 - _mapY;
					ob2.impact = false;
					ob2.frameX = 0;
					ob2.frameY = 0;
					ob2.open = false;
					ob2.alpha = 0;
					ob2.frameXTime = 0;
					ob2.Name = "Stone1";
					_object->Get_ObjectSton(1)[0].push_back(ob2);

				}
				if (_tileInfo.frameX == 3 && _tileInfo.frameY == 0)
				{
					object ob2;
					ob2.x = countX3 * 88 - 70 - _mapX;
					ob2.y = countY3 * 77 + 80 - _mapY;
					ob2.impact = false;
					ob2.frameX = 0;
					ob2.frameY = 0;
					ob2.open = false;
					ob2.alpha = 0;
					ob2.frameXTime = 0;
					ob2.Name = "Stone2";
					_object->Get_ObjectSton(2)[0].push_back(ob2);

				}
				if (_tileInfo.frameX == 3 && _tileInfo.frameY == 1)
				{
					object ob2;
					ob2.x = countX3 * 88 - 70 - _mapX;
					ob2.y = countY3 * 77 + 80 - _mapY;
					ob2.impact = false;
					ob2.frameX = 0;
					ob2.frameY = 0;
					ob2.open = false;
					ob2.alpha = 0;
					ob2.frameXTime = 0;
					ob2.Name = "Stone3";
					_object->Get_ObjectSton(3)[0].push_back(ob2);

				}
				if (_tileInfo.frameX == 2 && _tileInfo.frameY == 1)
				{
					object ob0;
					ob0.x = countX3 * 88 - 73 - _mapX;
					ob0.y = countY3 * 77 + 80 - _mapY;
					ob0.impact = false;
					ob0.frameX = 0;
					ob0.frameY = 0;
					ob0.open = false;
					ob0.alpha = 180;
					ob0.frameXTime = 0;
					(*_object->Get_Object()).push_back(ob0);

				}
				if (_tileInfo.frameX == 1 && _tileInfo.frameY == 1)
				{
					object ob1;
					ob1.x = countX3 * 88 - 60 - _mapX;
					ob1.y = countY3 * 77 + 90 - _mapY;
					ob1.impact = false;
					ob1.frameX = 0;
					ob1.frameY = 0;
					ob1.open = false;
					ob1.alpha = 0;
					ob1.frameXTime = 0;
					(*_object->Get_ObjectThorn()).push_back(ob1);

				}
			}

		}
	}
		cout << "�ҷ����� �Ϸ�" << endl;
}
