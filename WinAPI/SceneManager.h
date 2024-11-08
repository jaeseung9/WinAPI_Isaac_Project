#pragma once
#include "SingletonBase.h"

class GameNode;

class SceneManager : public SingletonBase <SceneManager>
{
private:
	typedef map<string, GameNode*> mapSceneList;
	typedef map<string, GameNode*>::iterator mapSceneIter;

private:
	static GameNode* _currentScene;
	static GameNode* _loadingScene;
	static GameNode* _readyScene;

	mapSceneList _mSceneList;
	mapSceneList _mLoadingSceneList;

private:
	bool _openingSkipAnyKey;

public:
	HRESULT init(void);
	void release(void);
	void update(void);
	void render(void);

	GameNode* addScene(string sceneName, GameNode* scene);
	GameNode* addLodingScene(string loadingScene, GameNode* scene);
	
	HRESULT changeScene(string sceneName);

	//로딩 스레드 함수
	friend DWORD CALLBACK loadingThread(LPVOID prc);
	//friend -> 단방향 참조
	//ㄴ 클래스가 여러개 존재할때 서로의 상속관계를 프로그래머가 모르기 때문에
	//ㄴ 혹시 상속구조가 발목을 잡으면 그냥 friend로 뚫고 들어가서 CALLBACK으로 OS에 알려줘라
	//ㄴ C++ 에서 CALLBACK 이 곧 Delligate
	//LPVOID -> 뭐가 들어올지 모르니 일단 들어올 수 있게 준비만 해주겠다.
	//ㄴ void* (어떤 타입으로도 변환 가능)

	void Set_IntroEnd(bool openingSkipAnyKey) { _openingSkipAnyKey = openingSkipAnyKey; }
	bool Get_OpeningSkipAnyKey(void) { return _openingSkipAnyKey; }

	SceneManager() {}
	~SceneManager() {}
};

