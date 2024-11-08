#pragma once
#include "GameNode.h"


struct PlayerInformationM
{
	float hp;
	float atk;
	float speed;
	float attackSpeed;
	float intersection;
	int money;
	int bomb;
	int key;
	RECT rc;
};


struct MonsterInformation
{
	float x;
	float y;
	float direction;
	float atk;
	float hp;
	float speed;
	float angle;
	float frameTime;
	GImage* _monster;
	int frameX;
	int frameY;
	bool move;
	float atkSpeed;
	RECT rc;
	int frameHerd;
	RECT plrc;
	bool impact;
	int rnd;
	bool atktrue;
	int alpha;
	float angle2;
	int rndFly;
	bool die;
	float a;
	float b;
	float c;
};

struct Blood
{
	float x;
	float y;
	int frameX;
	float frameXTime;
};

struct Monsterbullet
{
	float x;
	float y;
	int frameX;
	float frameXTime;
	float atk;
	float atkTime;
	bool direction;
	bool impact;
	float impactTime;
	float angle;
	float angleRnd;
	RECT rc;

};



class Monster :public GameNode
{
private:

	vector<MonsterInformation>_vMonster[30];
	PlayerInformationM _playerInformation;
	vector<Blood> _blood;
	vector<Blood> _blood2;
	vector<Blood> _blood3;
	vector<Monsterbullet> _monsterbullet;
	vector<Monsterbullet> _monsterbullet1;
	vector<Monsterbullet> _monsterbullet2;

	RECT _map;
	RECT _wall;
	RECT _impact;
	RECT cameraImpactrc;


	GImage* _bossGimage[4]; 

	float distansX[14];
	float distansY[14];


	int C;
	float Cx;
	float Cy;
	float _frameTime;
	float _bossHp;



	bool _bossStart;
	bool _bossEnd[4];
	bool _rcOk;

	bool _sound;


public:
	HRESULT init(void);
	void release(void);
	void update(void);
	void render(void);
	void bloodrender(void);

	//플레이어 정보 받아오기
	void Set_PlayerInformation(float hp, float speed, float attackSpeed, float atk, float intersection, int money, int bomb, int key, RECT rc )
	{
		_playerInformation.hp = hp;
		_playerInformation.money = money;
		_playerInformation.bomb = bomb;
		_playerInformation.key = key;
		_playerInformation.atk = atk;
		_playerInformation.speed = speed;
		_playerInformation.attackSpeed = attackSpeed;
		_playerInformation.intersection = intersection;
		_playerInformation.rc = rc;
	}

	vector<MonsterInformation>* Get_MonsterInformation(int idx) { return &_vMonster[idx]; }
	vector<Monsterbullet>* Get_MonsterBullet(void) { return &_monsterbullet; }
	vector<Monsterbullet>* Get_MonsterBullet1(void) { return &_monsterbullet1; }
	vector<Monsterbullet>* Get_MonsterBullet2(void) { return &_monsterbullet2; }
	vector<Blood>* Get_MonsterBlood(void) { return &_blood2; }


	GImage** Get_bossGImage(int idx) {return &_bossGimage[idx];}
	bool* Get_bossEnd(int idx) { return &_bossEnd[idx]; }
	//RECT* Get_CameraImpactrc(void) { return &cameraImpactrc; }

};

;