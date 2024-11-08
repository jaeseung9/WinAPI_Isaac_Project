#include "Stdafx.h"
#include "TempSoundManager.h"

HRESULT TempSoundManager::init()
{
    return S_OK;
}

void TempSoundManager::addMp3FileWithKey(string key, string fileName)
{
    // mp3 파일 자체 내장으로, mp3 타입을 찾는 코드
    string first = "open \"";
    string end = "\" type mpegvideo alias ";
    string finalQuery = first + fileName + end + key;

    const char* str = finalQuery.c_str();

    // mciSendString(): 장치에 측정 명령어를 전송하여 구동시킨다.
    //  ㄴ 인자: 문자열 명령어, 반환값을 알려줄 문자열, 반환될 길이, 콜백 (핸들)
    // mp3 타입의 파일을 연다.
    mciSendString(str, NULL, 0, NULL);
}

void TempSoundManager::addWaveFileWithKey(string key, string fileName)
{
    string first = "open \"";
    string end = "\" type waveaudio alias ";
    string finalQuery = first + fileName + end + key;

    const char* str = finalQuery.c_str();

    mciSendString(str, NULL, 0, NULL);
}

void TempSoundManager::playEffectSoundWave(char* fileName)
{
    //PlaySound(): 사운드 재생 함수. 업계에서 테스트용으로 많이 쓰임. 빠르다.
    //  ㄴ 인자: 파일 이름(파일 경로), 리소스를 사용하면 해당 인스턴스 핸들, fdwSound( 옵션 | 옵션 | 옵션 )

    /*
       SND_ASYNC: 비동기 옵션. 재생하면서 다음 코드 실행 (비동기 플래그)
       SND_LOOP: 반복 재생
       SND_NODEFAULT: 지정 경로에 파일이 없어도 비프음(경고음) 재생 X.
    */

    PlaySound(fileName, NULL, SND_ASYNC);
}

void TempSoundManager::playSoundWithKey(string key)
{
    string first = "play ";
    string finalQuery = first + key;

    const char* str = finalQuery.c_str();
    mciSendString(str, NULL, 0, NULL);
}

void TempSoundManager::stopMp3WithKey(string key)
{
    string first = "stop ";
    string finalQuery = "";
    finalQuery = first + key;

    const char* str = finalQuery.c_str();
    mciSendString(str, NULL, 0, NULL);
}