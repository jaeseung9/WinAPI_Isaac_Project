#include "Stdafx.h"
#include "JasonSaveLoader.h"

HRESULT JasonSaveLoader::init(void)
{
	//! Do Nothing
	return S_OK;
}

void JasonSaveLoader::release(void)
{
	//! Do Nothing
}

void JasonSaveLoader::saveString(char* fileName, string data)
{
	TCHAR* buf = (TCHAR*)data.c_str();
	//�����쿡�� �ο��� ���� �ĺ���ȣ üũ�� file
	HANDLE file;
	WORD BOM = 0xFEFF; //BOM(Byte of Mark)
	DWORD dwBytes = 0;
	DWORD dwRead;
	/*
	�� BOM (Byte Of(Order) Mark) - ����Ʈ ���� ǥ�ñ�
	
	- 0xFEFF: ������ �Ҷ� ��� �������� ������ ���� �˷��� 
	(�츮�� �򿣵�� ���(UTF-8 ���ڵ� ���) - ���� -> ������ �������� �����͸� ����)
	
	- ��ǻ�ʹ� �����͸� �޸𸮿� ������ �� ����Ʈ ������ ������ ������ �Ѵ�.
	- ������ �����ڵ��� ��� ���ڵ� ����̳� ����� ��Ŀ� ���� BOM�� �ʿ��� ��찡 �ִ�.
	
	�� �����찡 ����ϴ� ����� UTF-16 (U+FEFF) -> BOM

	- ����Ʈ�� ����Ǵ� ������ ���� �� �����, ��Ʋ ��������� ������.
	�� �� ����� (���� -> ���������� ������ ����)
	�� ��Ʋ ����� (������ -> ���� ������ ����)
		�� �������� ���� ��� ex: �������� ȸ�������Ҷ� ���� ���

		- �� ����� (Big-endian) �� -> ��
		�� �� ����� ����� ���� �ּҿ� �������� ���� ����Ʈ���� �����ϴ� ���
		�� �޸𸮿� ���������� ����Ǳ� ������ �״�� ���� ���� �ִ�.
			�� ����� ���ϴ�.

		- ��Ʋ ����� (Little-endian) �� <- ��
		�� ��Ʋ ����� ����� ���� �ּҿ� �������� ���� ����Ʈ�� �����ϴ� ���
		�� ��� ����� �д� ������ �ݴ�� �о�� �ϱ� ������ ���ټ��� ��������.
		�� Ư�� ���ǿ��� ���귮�� �ٱ⶧���� �������� �ִ�.

	- ���� ������ ���� ���ʿ� 0xFEFF�� ���̳ʸ� �������� ä���ؼ� (BOM) ���Ŀ� ���� ���ڳ� ���ڿ��� �о� ���̰� �ϴ� ��Ķ����� ����Ѵ�.
	*/
	
	/*
	CreateFile: ���� ����� ��ġ�� ����ų� �о�´�.
				����� �� �ִ� Handle�� ��ȯ�Ѵ�.

	����: (3, 4 ���� ���ӿ��� ���� ����)
	1. �����ϰų� �� ������ �̸�
	2. ���� ���� Ÿ��
	3. ������ ������ ���� ���� (0 -> ���� x)
	4. �ڽĿ��� ��� ����
	5. ���� ���� ��� ����
	�� CREATE_ALWAYS: ���ο� ���� ���� -> ������ ���� ����� �����
	6. ������ �ɼǰ� ���� (�б� ���� / ���� ���� ���..)
	�� FILE_ATTRIBUTE_NORMAL: �Ϲ����� �Ӽ��� ����Ѵ�.
	7. ���Ͽ� ���� �Ӽ��� (���� �����)
	*/
	file = CreateFile
	(
		fileName,
		GENERIC_WRITE,
		0,
		NULL,
		CREATE_ALWAYS,
		FILE_ATTRIBUTE_NORMAL,
		NULL
	);

	// INVALID_HANDLE_VALUE: �ڵ� �ʱ�ȭ�� ����Ѵ�.
	if (file == INVALID_HANDLE_VALUE) //������ �������� �ʾ�����
	{
		MessageBox(_hWnd, "���� ���� ����", "����", MB_OK);
	}

	else
	{
		//����: CreateFile���� �Ҵ�� �ڵ�, ���Ͽ� ���� ���� ��Ʈ�� ��,
		//		�󸶳� �а� ���� ������ ���� ũ��
		//		�󸶳� �а� ���� ������ ���� ��ȯ��(�ּ�)
		//WriteFile(file, &BOM, 2, &dwBytes, NULL); -> ������� ����Ҽ��� ������ �̷��� �ۼ��ϸ� ������ ������ ã�Ⱑ ��Ʊ⶧���� �Ʒ������ ���
		WriteFile(file, buf, strlen(buf) * sizeof(TCHAR), &dwRead, NULL);

		CloseHandle(file);
	}
}

string JasonSaveLoader::loadString(char* fileName)
{
	TCHAR buf[8192];
	ZeroMemory(buf, sizeof(buf));

	HANDLE file;
	DWORD dwBytes;

	//GENERIC_READ: �Ϲ����� �б� ���� - ������ �ֵ� ���� ������ ���� �о��, ������ ���� ��� ����ó���� �ؾ���
	//OPEN_EXISTING: ������ �����ϸ� ����.
	file = CreateFile
	(
		fileName,
		GENERIC_READ,
		0,
		NULL,
		OPEN_EXISTING,
		FILE_ATTRIBUTE_NORMAL,
		NULL
	);	
	
	if (file == INVALID_HANDLE_VALUE) 
	{
		MessageBox(_hWnd, "���� ���� ����", "����", MB_OK);
		return "";
	}

	else
	{
		ReadFile(file, buf, 8192, &dwBytes, NULL);
		CloseHandle(file);
	}

	return string(buf);
}

void JasonSaveLoader::saveStringWithFileStream(char* fileName, string data)
{
	ofstream outFile(fileName);

	outFile << data << endl;

	outFile.close();
}

string JasonSaveLoader::loadStringWithFileStream(char* fileName)
{
	ifstream fileIn;

	/*
	ios::in: ������ �б⸸ ������ ���� �����ϰڴ�.
	ios::out: ������ ���⸸ ������ ���� �����ϰڴ�.
	ios::ate: ������ ������ �� ������ ������ ���� �����͸� �̵� ��Ų��.
	ios::app: �ش� ���Ͽ� �� ���������� �����͸� �߰��Ѵ�.
	ios::trunc: ������ ������ �ش� ������ ��� �����͸� ���� ����.
	ios::binary: ���̳ʸ� ���� ���� (���� ����)
	*/
	fileIn.open(fileName, ios::in);

	char data;
	string jsonStr;

	while (fileIn.get(data))
	{
		jsonStr += data;	
	}

	fileIn.close();

	return jsonStr;
}

void JasonSaveLoader::saveJsonFile(char* fileName, Json::Value root)
{
	Json::StyledWriter writer;
	string outputConfig = writer.write(root);
	
	saveStringWithFileStream(fileName, outputConfig);
}

Json::Value JasonSaveLoader::loadJsonFile(char* fileName)
{
	string jsonStr = loadStringWithFileStream(fileName);

	if (jsonStr == "")
	{
		MessageBox(_hWnd, "�����Ͱ� ����.", "���", MB_OK);
		return NULL;
	}

	Json::Reader reader;
	Json::Value root;

	/*
	�Ľ�: Ư�� ������ �о� �鿩�� �̸� �ٸ� ���α׷��̳� ���� ��ƾ�� ����� �� �ְ� ������ ǥ�� ������� ��ȯ�� �ִ� ��
	�ļ�: �Ľ��� ���ִ� ���μ���
	*/
	bool parsingRet = reader.parse(jsonStr, root);

	if (!parsingRet)
	{
		string errMsg = reader.getFormatedErrorMessages();
		MessageBox(_hWnd, errMsg.c_str(), "����", MB_OK);
		//PostMessage(0);
		PostQuitMessage(0);
	}

	return root;
}
