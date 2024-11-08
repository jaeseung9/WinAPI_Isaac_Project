#pragma once
#include "GameNode.h"
#include "Player.h"
#include "Ui.h"
#include "Monster.h"
#include "Item.h"
#include "Object.h"


class GameSystemManager : public GameNode 
{
private:
	Player* _player;
	Ui* _ui;
	Monster* _monster;
	Item* _item;
	Object* _object;

	bool _Information;
	string _keyValue[9];

	MAKE_MAP _tileRC[MAX_MAP_SIZE][MAX_MAP_SIZE];
	MAKE_MAP _doorRC[MAX_MAP_SIZE][MAX_MAP_SIZE];
	MAKE_MAP _monsterRc[MAX_MAP_SIZE][MAX_MAP_SIZE];
	RECT _baseTileRC[MAX_MAP_SIZE][MAX_MAP_SIZE];

	GImage* _tileImg[9];
	GImage* _tileGround[9];

	bool _getItem;
	float animTime;
	bool _hooray[20];
	bool _caricature[20];
	float _invincibilityTime;

	RECT _impact;
	RECT _map;
	RECT cameraImpactrc;


	int _monsterNum;
	int _survivalMonster;
	float x;
	float y;
	float _mapMoveX;
	float _mapMoveY;
	float _mapX;
	float _mapY;

	//맵 변환
	char* _mapName;

	//보스 클리어
	GImage* _bossClear[5];
	float _frameTime;
	bool _bossClearVideo[4];
	bool _bossClearVideoEnd;
	int _bossIndex;
	
	GImage* _operationkey;

	bool _shild;
	bool _soundStart;
	bool _itemMoney[3];
	//미니맵용 랙트

	RECT _miniMap;

	int _MapM;

public:
	HRESULT init(void);
	void release(void);
	void update(void);
	void render(void);

	void Set_Information(bool Information) { _Information = Information; }



	void LodeMap();



};

