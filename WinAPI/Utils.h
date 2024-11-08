#pragma once
//=====================================================
// # Utils (간소화 하고 싶거나 or 수학적 기능을 모아둔다.)
//=====================================================

// 디그리 1도의 라디안 값
// 사칙연산 중 나눗셈이 가장 느림. 반복이 돌아야 하기 때문.
#define DEG_TO_RAD		0.017453f
#define PI				3.141592654f
#define PI_2			6.283185308f
#define FLOAT_EPSILON	0.0001f
#define MAX_MAP_SIZE    50
// 실수를 정수형으로 변환(정확히는 업/다운 캐스팅이라고 함)
#define FLOAT_TO_INT(f1)		static_cast<int>(f1 + FLOAT_EPSILON)
// 두 실수가 같은지 비교
//  ㄴ fabs는 소수점 차의 절대값 반환
#define FLOAT_EQUAL(f1, f2)	(fabs(f1 - f2) <= FLOAT_EPSILON)

struct ItemList
{
	float hp;
	float atk;
	float speed;
	float attackSpeed;
	float intersection;
	int money;
	int bomb;
	int key;
	RECT rc;
	GImage* itemImage;
};


struct MAKE_MAP
{
	GImage* img;
	int idx;
	bool draw;
	int frameX;
	int frameY;
	int keyNum;
};

namespace MY_UTIL
{
	// 두 점 사이의 거리를 구한다.
	float getDistance(float startX, float startY, float endX, float endY);

	// start부터 end까지의 각을 라디안으로 구한다.
	float getAngle(float startX, float startY, float endX, float endY);
	float getAngle1(float startX, float startY, float endX, float endY);
}

#pragma region
/*
	▶ 엡실론 (Epsilon)

	 - 부동 소수점은 실수를 정확히 표현할 수 없는 문제를 가지고 있다.
	  ㄴ 왜냐하면 수학적으로 실수는 무한한데 이 실수를 유한한 비트로 표현하기
		 위해서는 컴퓨터가 어쩔 수 없이 근사치(근사값)로 표현해야 하기 때문.

	 - 이러한 구조적 문제로 발생하는 게 부동소수점 반올림 오차.

	 - 이러한 특성때문에 오차범위가 발생하는데 정확한 계산을 위해서 상수로 정의된 값을 사용한다.

	 - 2D는 크게 인식을 못하는 경우가 많지만, 3D 같은 경우는 결과값이 달라질 수 있다.
*/

/*
	▶ 캐스팅 연산자 종류

	 1. static_cast

	 2. const_cast
	  - const 상수 값 없앨 때 빼는 용도. (유저 이름 생성 및 변경 등)

	 3. dynamic_cast

	 4. reinterpret_cast
	  - 개념 정도만 알아도 됨. 자세히 알가 쉽지 않음.
*/
#pragma endregion