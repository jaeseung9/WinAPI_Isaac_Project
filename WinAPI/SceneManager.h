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

	//�ε� ������ �Լ�
	friend DWORD CALLBACK loadingThread(LPVOID prc);
	//friend -> �ܹ��� ����
	//�� Ŭ������ ������ �����Ҷ� ������ ��Ӱ��踦 ���α׷��Ӱ� �𸣱� ������
	//�� Ȥ�� ��ӱ����� �߸��� ������ �׳� friend�� �հ� ���� CALLBACK���� OS�� �˷����
	//�� C++ ���� CALLBACK �� �� Delligate
	//LPVOID -> ���� ������ �𸣴� �ϴ� ���� �� �ְ� �غ� ���ְڴ�.
	//�� void* (� Ÿ�����ε� ��ȯ ����)

	void Set_IntroEnd(bool openingSkipAnyKey) { _openingSkipAnyKey = openingSkipAnyKey; }
	bool Get_OpeningSkipAnyKey(void) { return _openingSkipAnyKey; }

	SceneManager() {}
	~SceneManager() {}
};

