#include "Stdafx.h"
#include "CameraManager.h"

void CameraManager::init(void)
{
	_camera.x = 0;
	_camera.y = 0;
}

void CameraManager::setCamera(int x, int y)
{
	_camera.x = x - WINSIZE_X / 2 + 40;
	_camera.y = y - WINSIZE_Y / 2;
}
