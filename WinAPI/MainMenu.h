#pragma once
#include "GameNode.h"
class MainMenu : public GameNode
{
private:

	RECT _button[3];
	GImage* _mainMenu;
	bool MainScene;

public:
	HRESULT init(void);
	void release(void);
	void update(void);
	void render(void);

};

