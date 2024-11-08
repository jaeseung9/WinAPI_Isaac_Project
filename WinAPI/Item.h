#pragma once
#include "GameNode.h"




class Item : public GameNode
{
private:
	ItemList _item[20];

public:
	HRESULT init(void);
	void release(void);
	void update(void);
	void render(void);


	ItemList* Get_ItemList(int idx) { return &_item[idx]; }

	
	
};