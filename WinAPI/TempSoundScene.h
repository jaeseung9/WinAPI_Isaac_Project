#pragma once
#include "GameNode.h"
class TempSoundScene : public GameNode
{
public:
	HRESULT init(void);
	void update(void);

	TempSoundScene() {}
	~TempSoundScene() {}
};

