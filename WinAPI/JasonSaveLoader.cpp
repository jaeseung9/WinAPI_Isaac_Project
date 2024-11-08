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
	//윈도우에서 부여한 고유 식별번호 체크할 file
	HANDLE file;
	WORD BOM = 0xFEFF; //BOM(Byte of Mark)
	DWORD dwBytes = 0;
	DWORD dwRead;
	/*
	▶ BOM (Byte Of(Order) Mark) - 바이트 순서 표시기
	
	- 0xFEFF: 저장을 할때 어떠한 형식으로 저장이 될지 알려줌 
	(우리는 빅엔디안 방식(UTF-8 인코딩 방식) - 왼쪽 -> 오른쪽 방향으로 데이터를 읽음)
	
	- 컴퓨터는 데이터를 메모리에 저장할 때 바이트 단위로 나눠서 저장을 한다.
	- 하지만 유니코드의 경우 인코딩 방식이나 엔디안 방식에 따라 BOM이 필요한 경우가 있다.
	
	※ 윈도우가 사용하는 방식은 UTF-16 (U+FEFF) -> BOM

	- 바이트가 저장되는 순서에 따라 빅 엔디안, 리틀 엔디안으로 나뉜다.
	ㄴ 빅 엔디안 (왼쪽 -> 오른쪽으로 데이터 저장)
	ㄴ 리틀 엔디안 (오른쪽 -> 왼쪽 데이터 저장)
		ㄴ 서버에서 많이 사용 ex: 유저들이 회원가입할때 많이 사용

		- 빅 엔디안 (Big-endian) 좌 -> 우
		ㄴ 빅 엔디안 방식은 낮은 주소에 데이터의 높은 바이트부터 저장하는 방식
		ㄴ 메모리에 순차적으로 저장되기 때문에 그대로 읽을 수가 있다.
			ㄴ 사람이 편하다.

		- 리틀 엔디안 (Little-endian) 좌 <- 우
		ㄴ 리틀 엔디안 방식은 낮은 주소에 데이터의 낮은 바이트를 저장하는 방식
		ㄴ 평소 사람이 읽는 방향의 반대로 읽어야 하기 때문에 접근성이 떨어진다.
		ㄴ 특정 조건에서 연산량이 줄기때문에 좋은점이 있다.

	- 보통 파일의 제일 앞쪽에 0xFEFF를 바이너리 형식으로 채택해서 (BOM) 이후에 나올 문자나 문자열을 읽어 들이게 하는 방식때문에 사용한다.
	*/
	
	/*
	CreateFile: 파일 입출력 장치를 만들거나 읽어온다.
				사용할 수 있는 Handle을 반환한다.

	인자: (3, 4 번은 게임에서 거의 고정)
	1. 생성하거나 열 파일의 이름
	2. 파일 접근 타입
	3. 열려진 파일의 공유 여부 (0 -> 공유 x)
	4. 자식에게 상속 여부
	5. 파일 생성 모드 세팅
	ㄴ CREATE_ALWAYS: 새로운 파일 생성 -> 동일한 파일 존재시 덮어쓰기
	6. 파일의 옵션값 설정 (읽기 전용 / 쓰기 전용 등등..)
	ㄴ FILE_ATTRIBUTE_NORMAL: 일반적인 속성을 사용한다.
	7. 파일에 대한 속성값 (새로 만들시)
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

	// INVALID_HANDLE_VALUE: 핸들 초기화에 사용한다.
	if (file == INVALID_HANDLE_VALUE) //파일이 생성되지 않았을떄
	{
		MessageBox(_hWnd, "생성 파일 에러", "에러", MB_OK);
	}

	else
	{
		//인자: CreateFile에서 할당된 핸들, 파일에 쓰고 싶은 스트링 값,
		//		얼마나 읽고 쓸것 인지에 대한 크기
		//		얼마나 읽고 쓸것 인지에 대한 반환값(주소)
		//WriteFile(file, &BOM, 2, &dwBytes, NULL); -> 상수값을 사용할수도 있지만 이렇게 작성하면 오류가 났을때 찾기가 어렵기때문에 아래방식을 사용
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

	//GENERIC_READ: 일반적인 읽기 형태 - 파일이 있든 없든 무조건 들어가서 읽어옴, 파일이 없을 경우 예외처리를 해야함
	//OPEN_EXISTING: 파일이 존재하면 연다.
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
		MessageBox(_hWnd, "생성 파일 에러", "에러", MB_OK);
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
	ios::in: 파일을 읽기만 가능한 모드로 개방하겠다.
	ios::out: 파일을 쓰기만 가능한 모드로 개방하겠다.
	ios::ate: 파일을 개방할 때 파일의 끝으로 파일 포인터를 이동 시킨다.
	ios::app: 해당 파일에 맨 끝에서부터 데이터를 추가한다.
	ios::trunc: 파일이 있으면 해당 파일의 모든 데이터를 비우고 연다.
	ios::binary: 바이너리 모드로 개방 (서버 전용)
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
		MessageBox(_hWnd, "데이터가 없다.", "경고", MB_OK);
		return NULL;
	}

	Json::Reader reader;
	Json::Value root;

	/*
	파싱: 특정 문서를 읽어 들여서 이를 다른 프로그램이나 서브 루틴이 사용할 수 있게 내부의 표현 방식으로 변환해 주는 것
	파서: 파싱을 해주는 프로세서
	*/
	bool parsingRet = reader.parse(jsonStr, root);

	if (!parsingRet)
	{
		string errMsg = reader.getFormatedErrorMessages();
		MessageBox(_hWnd, errMsg.c_str(), "오류", MB_OK);
		//PostMessage(0);
		PostQuitMessage(0);
	}

	return root;
}
