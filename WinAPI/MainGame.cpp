#include "Stdafx.h"
#include "MainGame.h"
#include "Intro.h"
#include "MainMenu.h"
#include "GameSystemManager.h"
#include "MapTool.h"
#include "Ending.h"
//#include "Monster.h"


HRESULT MainGame::init(void)
{
	GameNode::init(TRUE);

	

	SCENEMANAGER->addScene("��Ʈ��", new Intro);
	SCENEMANAGER->addScene("���θ޴�", new MainMenu);
	SCENEMANAGER->addScene("���ӽ���", new GameSystemManager);
	SCENEMANAGER->addScene("����", new MapTool);
	SCENEMANAGER->addScene("����", new Ending);
	

	SCENEMANAGER->changeScene("��Ʈ��");



	return S_OK;
}

void MainGame::release(void)
{
	GameNode::release();


}

void MainGame::update(void)
{
	GameNode::update();

	SCENEMANAGER->update();

	CAMERASHAKE->update();
}

void MainGame::render(void)
{
	PatBlt(getMemDC(), 0, 0, WINSIZE_X, WINSIZE_Y, BLACKNESS);
	
	SCENEMANAGER->render();
	TIMEMANAGER->render(getMemDC());

	//this->getBackBuffer()->render(getHDC());

	if(!SCENEMANAGER->Get_OpeningSkipAnyKey())this->getBackBuffer()->render(getHDC(),CAMERASHAKE->getShakeX(), CAMERASHAKE->getShakeY());
}