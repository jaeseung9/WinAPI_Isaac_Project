#pragma once

#pragma region 타이머
/*
	▶ 타이머

	 - 기존에 사용한 API 공용 함수 (게임 쪽으로는 효율이 아주 별로)
	  ㄴ GetTickCount();
	  ㄴ GetTickCount64();

	 - 시간을 측정하는 함수들은 기본적으로 윈도우가 시작된 이후 지난 시간을 밀리 세컨드 단위로 반환한다.
	 - 밀리 세컨드보다 좀 더 정밀한 타이머를 원한다면 고성능 타이머를 구현해야 한다.
	 - 보통 타이머를 구현할 때는 두 가지를 기억하자.
	 ★★★★★
	  ㄴ 1. 해상도
	  ㄴ 2. 클럭 (진동 수)

	   ▷ 해상도란?
	    - 다양한 시간 함수들은 시간을 측정하기 위한 Tick 계산 로직이 있다.
		 ㄴ 보통 1분을 기준으로 얼마나 많은 프레임으로 나눌 수 있는지 계산.
		- 1분 동안 얼마나 많은 Tick으로 나눠서 시간의 정확도를 높이느냐가
		고해상도와 저해상도의 차이점이자 판단 기준.

	   ▷ Clock
	    - 타이머에서 얘기하는 클럭은 보통 CPU Clock을 의미한다.
		
		- 클럭이란?
		 ㄴ 클럭은 디지털 회로의 전기적 진동 수이며 Hz 단위로 표기.
		 ㄴ ex) 1초에 1Hz면 신호를 한 번 준다. (0 또는 1). 
		 ㄴ 1Ghz는 10의 9제곱 -> 1초에 10억 번 비트를 옮긴다.

	    - 타이머 단위
		 ㄴ Milli Second
		 ㄴ 10 Milli Second
		 ㄴ 100 Milli Second

		 ※ 고성능 타이머의 경우 중첩을 시키면 중첩을 시킨 만큼 효율이 올라간다. ★★★★★★★★★★
		  ㄴ 다만, 하지 말아야 할 업계 관행. 거지같은 코드를 짜고 하드웨어 로드율을 강제로 올린다.
		  ㄴ 타이머는 CPU와 램에서만 동작하기에 CPU와 램은 로드율이 높고, GPU는 낮은 현상이 발생.


	 - 
*/
#pragma endregion

class Timer
{
private:
	float			_timeScale;			//경과시간 조절
	float			_timeElapsed;		//마지막 시간과 현재시간의 경과값
	bool			_isHardware;		//고성능 타이머 지원 여부
	
	//__ : 시동코드에서 동작은 하지만 정규식은 아니다
	/*
	- int vs long
	ㄴ 32비트 vs 64비트 -> 32bit 환경에서는 둘다 4바이트 : 21억
					   -> 64bit 환경에서는 long은 8바이트로 치환됨

	- __int64 vs long
	ㄴ __int64 는 32bit 환경에서도 64bit 로 작동하지만
	long은 32bit 환경에서는 32bit 로 작동된다.
	*/
	__int64			_curTime;			//현재 시간
	__int64			_lastTime;			//이전 시간
	__int64			_periodFrequency;	//시간 주기

	unsigned long	_frameRate;			//FPS (초당 프레임 수)
	unsigned long	_FPSFrameCount;		//FPS 카운트
	float			_FPSTimeElapsed;	//FPS 시간 경과량
	float			_worldTime;			//게임이 시작된 후 경과된 전체 시간

public:
	HRESULT init(void);
	void tick(float lockFPS = 0.0f);	//언리얼엔진을 모방했기 떄문에 update 대신 tick 사용

	//const 는 함수 뒤 혹은 인자에 붙으면 어려워진다
	//const가 함수의 뒤에 붙으면 멤버 함수의 상수화를 의미한다.
	//ㄴ 이 함수내에서 멤버 변수의 값 변경을 막는다. -> 전역적으로 사용해야하기때문에 값이 변경되면 안됨
	//ㄴ 멤버변수가 변경될 수 있는 기회를 주지 않으며 변수 역시 변경 불가
	//ㄴ 포인터 x
	//현재 FPS
	unsigned long getFrameRate(char* str = nullptr) const;
	//마지막 시간과 현재 시간의 경과량
	inline float getElapsedTime(void) const { return _timeElapsed; }
	//전체 경과 시간
	inline float getWorldTime(void) const { return _worldTime; }

	/*
	update() 는 코어 클래스에서는 절대 사용하면 안된다.
	ㄴ 이유. 프레임을 보장받을 수 없다. (60보다 높으면 상관없지만 낮을경우 문제 발생)
		ㄴ update()는 하드웨어의 영향을 굉장히 많이 받는다 -> 초당 60번 호출을 보장받을 수 없다.
		=> 프레임을 다시 실행시키는 시간을 고정시켜서 균일하게 뽑아낼 수 있게 만들어야 한다.
	*/



	Timer() {}
	~Timer() {}
};