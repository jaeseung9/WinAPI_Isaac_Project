#pragma once
#include "SingletonBase.h"

#define DATA_FILE_NAME	"SaveData.json"

/*
외부 라이브러리(SDK) 가져오는 방법

1. 프로젝트 자체에 심어준다
ㄴ 가져오는 라이브러리가 가벼워야한다.
ㄴ 심어주지 못하는 라이브러리: C++ 부스터(21 Gb), DX 라이브러리, CoCos 등

2. 경로설정
*/

#pragma region 제이슨
/*
	STL 과 같이 사용하는 것이 효율이 좋음
	▶ 제이슨 (JSON (JavaScript Object Notation)

	- 제이슨은 객체의 구조와 속성을 텍스트 형식으로 전달하기 위해 고안된 방식이다.
	ㄴ 인터넷에서 자료를 주고 받을 때 그 자료를 표현하는 방법으로 주로 사용이 된다.
	- 자료의 종류에 큰 제한은 없으며 특히 컴퓨터 프로그램의 변수값을 표현하는데 적합하다.
	- 제이슨의 형식은 자바 스크립트의 구문 형식을 따르지만 프로그래밍 언어나 플랫폼에 독립적이므로 
	C, C++, C#, 자바, 자바 스크립트, 펄, 파이썬, 루비 등등 많은 언어에서 사용이 되고 있다.
	- XML, HTTP, CSV(, 를 기준으로 잘라서 value 를 확인하는 기법) 등등 보다 "일반적인" 환경에서 더 빠르다.


	＊ 제이슨 형식에서 사용하는 기호의 의미는 다음과 같다.
	{}: 객체
	키: 값-> 객체가 가지는 속성
	"": 문자열 데이터
	[]: 배열
*/
#pragma endregion

class JasonSaveLoader : public SingletonBase <JasonSaveLoader>
{
private:
	void saveString(char* fileName, string data);
	void saveStringWithFileStream(char* fileName, string data);

	string loadString(char* fileName);
	string loadStringWithFileStream(char* fileName);

public:
	HRESULT init(void);
	void release(void);
	void saveJsonFile(char* fileName, Json::Value root);

	Json::Value loadJsonFile(char* fileName);


	JasonSaveLoader() {}
	~JasonSaveLoader() {}
};

