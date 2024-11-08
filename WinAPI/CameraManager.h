#pragma once
#include "SingletonBase.h"

class CameraManager : public SingletonBase <CameraManager>
{
private:
	POINT _camera;
public:
	void init(void);

	POINT getCamera() { return _camera; }
	void setCamera(int x, int y);

	CameraManager() {}
	~CameraManager() {}
};

