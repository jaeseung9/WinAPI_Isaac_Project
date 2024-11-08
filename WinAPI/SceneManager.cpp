#include "Stdafx.h"
#include "SceneManager.h"
#include "GameNode.h"

//함수호출의 여부와 상관없이 초기화
//정적변수이기때문에 추가하지 않으면 프로그램이 종료되기 전까지 유지
GameNode* SceneManager::_currentScene = nullptr;
GameNode* SceneManager::_loadingScene = nullptr;
GameNode* SceneManager::_readyScene = nullptr;

/*
빠른리펙토링을 했을 때 CALLBACK 을 하지 않아서 오류가 생김 -> 주의
DWORD loadingThread(LPVOID prc)
{
    return 0;
}
*/

DWORD CALLBACK loadingThread(LPVOID prc)
{
    SceneManager::_readyScene->init();
    SceneManager::_currentScene = SceneManager::_readyScene;

    SceneManager::_loadingScene->release();
    SceneManager::_loadingScene = nullptr;
    SceneManager::_readyScene = nullptr;
    //this여도 되는데 SceneManager를 사용한 이유?
    //모호함을 없애기 위함

    return 0;
}

HRESULT SceneManager::init(void)
{
    _currentScene = nullptr;
    _loadingScene = nullptr;
    _readyScene = nullptr;
    _openingSkipAnyKey = true;

    return S_OK;
}

void SceneManager::release(void)
{
    // 1번
    mapSceneIter miSceneList = _mSceneList.begin();
    for (; miSceneList != _mSceneList.end();)
    {
        // 퍼스트에는 키값이 있고
        // 세컨드에 노드 참조가 들어가 있기 때문에 세컨드만 지우면 됨
        if (miSceneList->second != nullptr) 
        {
            if (miSceneList->second == _currentScene)
            {
                miSceneList->second->release();
            }
            SAFE_DELETE(miSceneList->second);
            miSceneList = _mSceneList.erase(miSceneList);
        }
        else ++miSceneList;
    }
    _mSceneList.clear();

    // 2번
    //for each (auto scene in _mSceneList)
    //{
    //    scene.second->release();
    //    SAFE_DELETE(scene.second);
    //}

    /*
    - 2번을 사용하는 사람은 100프로 C# 하던 사람
    
    - C++에서는 2번 코드를 사용하면 안된다.
    ㄴ 반복돌다가 오류가 나면 값을 찍었을때 값이 안들어옴
    ㄴ 순수 코드 분석 능력으로 해결방안을 찾아야함

    - 가독성은 2번이 좋지만 코드의 흐름을 따라가기에는 1번이 압도적으로 좋음

    - 2번은 협업에서 좋지 않음    
    */
}

void SceneManager::update(void)
{
    if (_currentScene) _currentScene->update();

}

void SceneManager::render(void)
{
    if (_currentScene) _currentScene->render();
}

GameNode* SceneManager::addScene(string sceneName, GameNode* scene)
{
    if (!scene) return nullptr;

    _mSceneList.insert(make_pair(sceneName, scene));

    return scene;
}

GameNode* SceneManager::addLodingScene(string loadingScene, GameNode* scene)
{
    if (!scene) return nullptr;

    _mLoadingSceneList.insert(make_pair(loadingScene, scene));

    return scene;
}

HRESULT SceneManager::changeScene(string sceneName)
{
    mapSceneIter find = _mSceneList.find(sceneName);

    if (find == _mSceneList.end()) return E_FAIL;
    if (find->second == _currentScene) return S_OK; 
    //ㄴ 이 코드가 없으면 현재 씬이 돌다가 다시 처음으로 돌아감

  

    if (SUCCEEDED(find->second->init()))
    {
        if (_currentScene != nullptr) _currentScene->release();
        _currentScene = find->second;
        return S_OK;
    }
 
    return E_FAIL;
}
