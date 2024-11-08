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


	int sizeXY = 52; // 테스트용 타일 크기 조절기 원래 타일 사이즈 : 24
	RECT _baseTileRC[MAX_MAP_SIZE][MAX_MAP_SIZE];

	RECT _testPlayer;
	GImage* _tileImg[11];
	GImage* _tileGround[11]; // 타일선택햇을경우 타일의 해당 프레임의 이미지 선택
	int _selectImg;  // 몇번째 타일 그림을 선택할 것인지
	int _imgLine[11]; // 타일 그림의 line 수
	int _imgSize[11]; // 타일의 크기
	RECT _tileSelectRC[144]; // 원본 이미지 타일RC
	int _selectImgFrameX, _selectImgFrameY; // 선택했을경우 해당 이미지의 프레임 x,y
	bool _tileClick; //타일을 선택했는지 여부

	//최적화
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

	//맵툴
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

