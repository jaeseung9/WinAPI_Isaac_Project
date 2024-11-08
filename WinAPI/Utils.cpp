#include "Stdafx.h"
#include "Utils.h"

namespace MY_UTIL
{
	float MY_UTIL::getDistance(float startX, float startY, float endX, float endY)
	{
		float x = endX - startX;
		float y = endY - startY;

		return sqrt(x * x + y * y);
	}

	float MY_UTIL::getAngle(float startX, float startY, float endX, float endY)
	{
		float x = endX - startX;
		float y = endY - startY;
		float d = sqrt(x * x + y * y);

		float angle = acos(x / d);

		if (y > 0) angle = PI_2 - angle;

		return angle;
	}

	float MY_UTIL::getAngle1(float startX, float startY, float endX, float endY)
	{
		float x = endX - startX;
		float y = endY - startY;

		float d = sqrt(x * x + y * y);

		float angle = acos(x / d);

		if (y > 0) angle = PI_2 - angle;

		return angle;
	}
}