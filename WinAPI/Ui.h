#pragma once
#include "GameNode.h"

struct PlayerInformationT
{
	float hp;
	float atk;
	float speed;
	float attackSpeed;
	float intersection;
	int money;
	int bomb;
	int key;
	int skileGage;
};

class Ui : public GameNode
{
private:
	PlayerInformationT _playerInformation;
	int _oneNumber[3];
	bool _Information;
	GImage* _stats[7];
	bool _out;
	bool _die;

	bool _caricature[20];
public:
	HRESULT init(void);
	void release(void);
	void update(void);
	void render(void);

	//_playerInformation.speed = 1;
	//_playerInformation.attackSpeed = 1;
	//_playerInformation.intersection = 1;

	void Set_PlayerInformation(float hp,float speed,float attackSpeed,float atk,float intersection, int money, int bomb, int key, int skileGage)
	{
		_playerInformation.hp = hp;
		_playerInformation.money = money;
		_playerInformation.bomb = bomb;
		_playerInformation.key = key;

		_playerInformation.atk = atk;
		_playerInformation.speed = speed;
		_playerInformation.attackSpeed = attackSpeed;
		_playerInformation.intersection = intersection;
		_playerInformation.skileGage = skileGage;
	}

	bool Get_Information(void) { return _Information; }

	bool* Get_PlayerDie(void) { return &_die; }



	//아이템문구
	void Set_caricature(int idx, bool caricature) { _caricature[idx] = caricature; }
};

