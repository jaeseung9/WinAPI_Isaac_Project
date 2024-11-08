#include "Stdafx.h"
#include "SceneManager.h"
#include "GameNode.h"

//�Լ�ȣ���� ���ο� ������� �ʱ�ȭ
//���������̱⶧���� �߰����� ������ ���α׷��� ����Ǳ� ������ ����
GameNode* SceneManager::_currentScene = nullptr;
GameNode* SceneManager::_loadingScene = nullptr;
GameNode* SceneManager::_readyScene = nullptr;

/*
���������丵�� ���� �� CALLBACK �� ���� �ʾƼ� ������ ���� -> ����
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
    //this���� �Ǵµ� SceneManager�� ����� ����?
    //��ȣ���� ���ֱ� ����

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
    // 1��
    mapSceneIter miSceneList = _mSceneList.begin();
    for (; miSceneList != _mSceneList.end();)
    {
        // �۽�Ʈ���� Ű���� �ְ�
        // �����忡 ��� ������ �� �ֱ� ������ �����常 ����� ��
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

    // 2��
    //for each (auto scene in _mSceneList)
    //{
    //    scene.second->release();
    //    SAFE_DELETE(scene.second);
    //}

    /*
    - 2���� ����ϴ� ����� 100���� C# �ϴ� ���
    
    - C++������ 2�� �ڵ带 ����ϸ� �ȵȴ�.
    �� �ݺ����ٰ� ������ ���� ���� ������� ���� �ȵ���
    �� ���� �ڵ� �м� �ɷ����� �ذ����� ã�ƾ���

    - �������� 2���� ������ �ڵ��� �帧�� ���󰡱⿡�� 1���� �е������� ����

    - 2���� �������� ���� ����    
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
    //�� �� �ڵ尡 ������ ���� ���� ���ٰ� �ٽ� ó������ ���ư�

  

    if (SUCCEEDED(find->second->init()))
    {
        if (_currentScene != nullptr) _currentScene->release();
        _currentScene = find->second;
        return S_OK;
    }
 
    return E_FAIL;
}
