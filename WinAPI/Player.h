#pragma once
#include "GameNode.h"
class Item;
class GameSystemManager;

struct bullet
{
	float x;
	float y;
	int direction;
	int index;
	int distance;
	float indexTime;
	bool impact;
	const char* keyName;
	RECT rc;
};

struct PlayerInformationP
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
	bool _invincibility;
	int skileGage;

};

struct Bomb
{
	float x;
	float y;
	int index;
	float indexTime;
	RECT rc;
	RECT smallRc;
	bool impact;
	int direction;
	float speed;
	int time;
	bool impact2;
	float atk;

};

struct ItemListP
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
	GImage* itemImage;
};

class Player : public GameNode
{
	GImage* _playerImage[7];

	vector<bullet> _bullet;
	vector<Bomb> _bomb;

	int _imageIndex;
	int _playerMovement;
	int _time;
	int _ptsd;
	int _slidingTime[4];
	bool _sliding[4];

	int atkSpeed;

	PlayerInformationP _playerInformation;

	//충돌확인네모출력
	bool _impact;
	bool _getItem;

	GImage* _star;

	ItemListP _item[20];

	float _starTime;

	// 아이템 장착확인 불값
	bool  _hooray[20];
	bool _caricature[20];

	int invincibilityTime;


	float _tick;

	bool shield;
	float shieldTime;
	float skileCool;

	bool _playerOut;

	char* _plAtkImage;
	bool _plAtkImageRed;
	bool _Item10;
	bool _playerAtkSound;

	//사탄
	bool _satan;
	int _satanFrameX;
	int _satanFrameY;
	int _satanHeadFrameX;
	int _satanHeadFrameY;
	float _satanFrameXTime;
	float _satanHeadFrameXTime;
	float _satanAtkTime;
	bool _satanAtk;
	RECT _satanAtkRc;
	GImage* _satanAtkImage[2];
	RECT _cameraImpactrc;


	//파리떼 획득
	bool _fly;
	float _flyFrameXTime;
	GImage* _flyImage[2];
	RECT _flyRc[2];
	float _c;
	

public:
	HRESULT init(void);
	void release(void);
	void update(void);
	void render(void);
	void renderBoom(void);

	//플레이어 정보 주고받기
	PlayerInformationP* Get_PlayerInformation(void) { return &_playerInformation; }

	//아이템 정보받기
	void Set_ItemList(int idx, Item* item);

	//아이템 획득정보
	void Set_GetItem(bool getItem) { _getItem = getItem; }

	//만세
	void Set_hooray(int idx, bool hooray) { _hooray[idx] = hooray; }

	//아이템문구
	void Set_caricature(int idx, bool caricature) { _caricature[idx] = caricature; }

	// 플레이어 공격 넘겨주기
	vector<bullet>* Get_Bullet(void) { return &_bullet; }

	vector<Bomb>* Get_Bomb(void) { return &_bomb; }

	bool* Get_Shield(void) { return &shield; }

	GImage** Get_Gimage(void) { return &_playerImage[0]; }

	bool* Get_PlayerOut(void) { return &_playerOut; }

	RECT* Get_SatanAtkRc(void) { return &_satanAtkRc; }

	RECT* Get_flyRect(int num) { return &_flyRc[num]; }
};

