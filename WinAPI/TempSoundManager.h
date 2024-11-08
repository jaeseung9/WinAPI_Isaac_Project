#pragma once
#include "SingletonBase.h"

//윈도우 내장 재생 라이브러리
//PlaySound()를 사용하기 위해
#include <mmsystem.h>

//MCI(Media Control Interface): 컴퓨터에 장착된 멀티미디어 장치
//mciSendString()를 사용하기 위해
#include <mciapi.h>

// Winmm: 윈도우 멀티미디어
#pragma comment(lib, "Winmm.lib")

class TempSoundManager : public SingletonBase<TempSoundManager>
{
public:
	HRESULT init();
	void addMp3FileWithKey(string key, string fileName);
	void addWaveFileWithKey(string key, string fileName);
	void playEffectSoundWave(char* fileName);
	void playSoundWithKey(string key);
	void stopMp3WithKey(string key);

	TempSoundManager() {}
	~TempSoundManager() {}
};

