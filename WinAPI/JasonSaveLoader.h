#pragma once
#include "SingletonBase.h"

#define DATA_FILE_NAME	"SaveData.json"

/*
�ܺ� ���̺귯��(SDK) �������� ���

1. ������Ʈ ��ü�� �ɾ��ش�
�� �������� ���̺귯���� ���������Ѵ�.
�� �ɾ����� ���ϴ� ���̺귯��: C++ �ν���(21 Gb), DX ���̺귯��, CoCos ��

2. ��μ���
*/

#pragma region ���̽�
/*
	STL �� ���� ����ϴ� ���� ȿ���� ����
	�� ���̽� (JSON (JavaScript Object Notation)

	- ���̽��� ��ü�� ������ �Ӽ��� �ؽ�Ʈ �������� �����ϱ� ���� ��ȵ� ����̴�.
	�� ���ͳݿ��� �ڷḦ �ְ� ���� �� �� �ڷḦ ǥ���ϴ� ������� �ַ� ����� �ȴ�.
	- �ڷ��� ������ ū ������ ������ Ư�� ��ǻ�� ���α׷��� �������� ǥ���ϴµ� �����ϴ�.
	- ���̽��� ������ �ڹ� ��ũ��Ʈ�� ���� ������ �������� ���α׷��� �� �÷����� �������̹Ƿ� 
	C, C++, C#, �ڹ�, �ڹ� ��ũ��Ʈ, ��, ���̽�, ��� ��� ���� ���� ����� �ǰ� �ִ�.
	- XML, HTTP, CSV(, �� �������� �߶� value �� Ȯ���ϴ� ���) ��� ���� "�Ϲ�����" ȯ�濡�� �� ������.


	�� ���̽� ���Ŀ��� ����ϴ� ��ȣ�� �ǹ̴� ������ ����.
	{}: ��ü
	Ű: ��-> ��ü�� ������ �Ӽ�
	"": ���ڿ� ������
	[]: �迭
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

