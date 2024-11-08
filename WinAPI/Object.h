#pragma once
#include "GameNode.h"

struct object
{
	float x;
	float y;
	int frameX;
	int frameY;
	bool impact;
	bool open;
	RECT rc;
	float objectHp;
	float alpha;
	float frameXTime;
	string Name;
};


class Object : public GameNode
{
private:

	vector<object> _vfire;
	vector<object> _vthorn;
	vector<object> _vston[4];
	vector<object> _vdoor[4];
	vector<object> _vbossDoor1;
	vector<object> _vshopLockeDoor[4];
	
public:
	HRESULT init(void);
	void release(void);
	void update(void);
	void render(void);


	vector<object>* Get_Object(void) { return &_vfire; }
	vector<object>* Get_ObjectThorn(void) { return &_vthorn; }
	vector<object>* Get_ObjectSton(int idx) { return &_vston[idx]; }
	vector<object>* Get_ObjectDoor(int idx) { return &_vdoor[idx]; }
	vector<object>* Get_ShopLockeDoor(int idx) { return &_vshopLockeDoor[idx]; }
	vector<object>* Get_ObjectBossDoor1(void) { return &_vbossDoor1; }
};
