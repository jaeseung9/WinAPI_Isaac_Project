#include "Stdafx.h"
#include "CameraShake.h"

HRESULT CameraShake::init()
{
    _shakeX = 0;
    _shakeY = 0;
    _regen = 0.5f;

    _shakePower = 0;

    _time = 0;

    _angle = 0;

    return S_OK;
}

void CameraShake::update()
{
    if (_time > 0)
    {
        _shakePower = _shakePower * (1 - 1 * TIMEMANAGER->getElapsedTime()) + 0.1 * 0;
        _time -= TIMEMANAGER->getElapsedTime();
        _angle = RND->getFromFloatTo(0, 2 * 3.141592f);
        _shakeX = _shakePower * cosf(_angle);
        _angle = RND->getFromFloatTo(0, 2 * 3.141592f);
        _shakeY = _shakePower * sinf(_angle);
    }
    else
    {
        _shakeX = 0;
        _shakeY = 0;
    }

}

void CameraShake::cameraRandomShake(float shakePower, float time)
{
    _shakePower = shakePower;
    _angle = RND->getFromFloatTo(0, 3.141592f);
    _shakeX *= cosf(_angle);
    _shakeY *= sinf(_angle);

    _time = time;
    _regenTime = 0.01;

    _regen = 1;


}
