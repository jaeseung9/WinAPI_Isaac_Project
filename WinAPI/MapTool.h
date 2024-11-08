#pragma once
#include "GameNode.h"



struct MapBSPLocation {
	int y1, x1, y2, x2;
	int y3, x3, y4, x4;
};

class MapTool : public GameNode
{
private:

	int _randomMap[MAX_MAP_SIZE][MAX_MAP_SIZE];

	MAKE_MAP _selecttile[MAX_MAP_SIZE][MAX_MAP_SIZE];
	MAKE_MAP _selectdoor[MAX_MAP_SIZE][MAX_MAP_SIZE];
	MAKE_MAP _selectobject[MAX_MAP_SIZE][MAX_MAP_SIZE];
	MAKE_MAP _selectmonster[MAX_MAP_SIZE][MAX_MAP_SIZE];


	int sizeXY = 52; // �׽�Ʈ�� Ÿ�� ũ�� ������ ���� Ÿ�� ������ : 24
	RECT _baseTileRC[MAX_MAP_SIZE][MAX_MAP_SIZE];

	RECT _testPlayer;
	GImage* _tileImg[11];
	GImage* _tileGround[11]; // Ÿ�ϼ���������� Ÿ���� �ش� �������� �̹��� ����
	int _selectImg;  // ���° Ÿ�� �׸��� ������ ������
	int _imgLine[11]; // Ÿ�� �׸��� line ��
	int _imgSize[11]; // Ÿ���� ũ��
	RECT _tileSelectRC[144]; // ���� �̹��� Ÿ��RC
	int _selectImgFrameX, _selectImgFrameY; // ����������� �ش� �̹����� ������ x,y
	bool _tileClick; //Ÿ���� �����ߴ��� ����

	//����ȭ
	int forX, forY;
	int maxforX, maxforY;

	RECT _nextButton, _prevButton;

	int _characterNum;
	int _CharMapX, _CharMapY;

	RECT _saveRC, _loadRC, _eraseRC;
	
	RECT _mainMenu;

	GImage* _button[4];
	GImage* _white;
	GImage* _butten2[4];

	//
	string _keyValue[9];
	MAKE_MAP _tileRC[MAX_MAP_SIZE][MAX_MAP_SIZE];

	//����
	bool _eraseTile;
	char* _savefileName[4];
	int _fileNameCnt;
	RECT  _stage[4];
	string _buttonName[4];

public:
	HRESULT init(void);
	void release(void);
	void update(void);
	void render(void);

	void LoadMap();
	void SaveMap();

	MapTool() {}
	~MapTool() {}
};

