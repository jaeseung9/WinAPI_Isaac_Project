#pragma once
#include "SingletonBase.h"

class CameraShake : public SingletonBase<CameraShake>
{
private:
	int _shakeX;
	int _shakeY;

	float _shakePower;
	float _regen;

	float _regenTime;
	float _time;

	float _angle;

public:

	HRESULT init();
	void update();
	void release() {}

	void cameraRandomShake(float shakePower, float time);

	void setRegen(float regen) { _regen = regen; }

	int getShakeX() { return _shakeX; }
	int getShakeY() { return _shakeY; }


};