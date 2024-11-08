#include "Stdafx.h"
#include "MapTool.h"

HRESULT MapTool::init(void)
{
  

    _tileImg[0] = IMAGEMANAGER->addImage("�ٴ�Ÿ�ϱ׸�", "Resources/Images/Map/Ÿ�ϸ�1.bmp",
        208, 312, true, RGB(255, 0, 255));
    _tileImg[1] = IMAGEMANAGER->addImage("�ٴ�Ÿ�ϱ׸�1", "Resources/Images/Map/Ÿ�ϸ�2.bmp",
        208, 312, true, RGB(255, 0, 255));
    _tileImg[2] = IMAGEMANAGER->addImage("�ٴ�Ÿ�ϱ׸�2", "Resources/Images/Map/Ÿ�ϸ�3.bmp",
        208, 312, true, RGB(255, 0, 255));
    _tileImg[3] = IMAGEMANAGER->addImage("�ٴ�Ÿ�ϱ׸�3", "Resources/Images/Map/Ÿ�ϸ�4.bmp",
        208, 312, true, RGB(255, 0, 255));
    _tileImg[4] = IMAGEMANAGER->addImage("�ٴ�Ÿ�ϱ׸�4", "Resources/Images/Map/Ÿ�ϸ�5.bmp",
        208, 312, true, RGB(255, 0, 255));
    _tileImg[5] = IMAGEMANAGER->addImage("������Ʈ�׸�", "Resources/Images/Map/Door.bmp",
        208, 312, true, RGB(255, 0, 255));
    _tileImg[6] = IMAGEMANAGER->addImage("���ͱ׸�", "Resources/Images/Map/object.bmp",
        208, 312, true, RGB(255, 0, 255));
    _tileImg[7] = IMAGEMANAGER->addImage("����", "Resources/Images/Map/Monster.bmp",
        208, 312, true, RGB(255, 0, 255));
    _tileImg[8] = IMAGEMANAGER->addImage("����", "Resources/Images/Map/Boss.bmp",
        208, 312, true, RGB(255, 0, 255));
    _tileImg[9] = IMAGEMANAGER->addImage("���", "Resources/Images/Map/White.bmp",
        52, 52, true, RGB(255, 0, 255));


    _tileGround[0] = IMAGEMANAGER->addFrameImage("�ٴ�Ÿ��", "Resources/Images/Map/Ÿ�ϸ�1.bmp",
        208, 312, 4, 6, true, RGB(255, 0, 255));
    _tileGround[1] = IMAGEMANAGER->addFrameImage("�ٴ�Ÿ��1", "Resources/Images/Map/Ÿ�ϸ�2.bmp",
        208, 312, 4, 6, true, RGB(255, 0, 255));
    _tileGround[2] = IMAGEMANAGER->addFrameImage("�ٴ�Ÿ��2", "Resources/Images/Map/Ÿ�ϸ�3.bmp",
        208, 312, 4, 6, true, RGB(255, 0, 255));
    _tileGround[3] = IMAGEMANAGER->addFrameImage("�ٴ�Ÿ��3", "Resources/Images/Map/Ÿ�ϸ�4.bmp",
        208, 312, 4, 6, true, RGB(255, 0, 255));
    _tileGround[4] = IMAGEMANAGER->addFrameImage("�ٴ�Ÿ��4", "Resources/Images/Map/Ÿ�ϸ�5.bmp",
        208, 312, 4, 6, true, RGB(255, 0, 255));
    _tileGround[5] = IMAGEMANAGER->addFrameImage("������ƮŸ��", "Resources/Images/Map/Door.bmp",
        208, 312, 4, 6, true, RGB(255, 0, 255));
    _tileGround[6] = IMAGEMANAGER->addFrameImage("����Ÿ��", "Resources/Images/Map/object.bmp",
        208, 312, 4, 6, true, RGB(255, 0, 255));
    _tileGround[7] = IMAGEMANAGER->addFrameImage("����Ÿ��1", "Resources/Images/Map/Monster.bmp",
        208, 312, 4, 6, true, RGB(255, 0, 255));
    _tileGround[8] = IMAGEMANAGER->addFrameImage("����1", "Resources/Images/Map/Boss.bmp",
        208, 312, 4, 6, true, RGB(255, 0, 255));
    _tileGround[9] = IMAGEMANAGER->addImage("���", "Resources/Images/Map/White.bmp",
        52, 52, true, RGB(255, 0, 255));



    //��ư �̹���
    _button[0] = IMAGEMANAGER->addImage("�¹�ư", "Resources/Images/Map/LeftButton.bmp",
        12 * 3, 19 * 3, true, RGB(255, 0, 255));
    _button[1] = IMAGEMANAGER->addImage("���ư", "Resources/Images/Map/RightButton.bmp",
        15 * 3, 18 * 3, true, RGB(255, 0, 255));
    _button[2] = IMAGEMANAGER->addImage("�ڷΰ���", "Resources/Images/Map/Back.bmp",
        83, 74, true, RGB(255, 0, 255));
    _button[3] = IMAGEMANAGER->addImage("�޹��", "Resources/Images/Map/shading.bmp",
        442+25, 338 +25, true, RGB(255, 0, 255));



    IMAGEMANAGER->addImage("�����ʹڽ�", "Resources/Images/Map/Box2.bmp",
       270, 600, true, RGB(255, 0, 255));


    _butten2[0] = IMAGEMANAGER->addFrameImage("1��", "Resources/Images/Map/1��.bmp",
        100 , 50 , 2 , 1, true, RGB(255, 0, 255));
    _butten2[1] = IMAGEMANAGER->addFrameImage("2��", "Resources/Images/Map/2��.bmp",
        100 , 50 , 2, 1, true, RGB(255, 0, 255));
    _butten2[2] = IMAGEMANAGER->addFrameImage("3��", "Resources/Images/Map/3��.bmp",
        100 , 50 , 2, 1, true, RGB(255, 0, 255));
    _butten2[3] = IMAGEMANAGER->addFrameImage("4��", "Resources/Images/Map/4��.bmp",
        100 , 50 , 2, 1, true, RGB(255, 0, 255));


    IMAGEMANAGER->addImage("��������", "Resources/Images/Map/��������.bmp",
        300 / 4 , 150 / 4, true, RGB(255, 0, 255));
    IMAGEMANAGER->addImage("����", "Resources/Images/Map/����.bmp",
        300 / 4, 150 / 4, true, RGB(255, 0, 255));

    //526,0,WINSIZE_X,WINSIZE_Y

    for (int i = 0; i < MAX_MAP_SIZE; i++)
    {
        for (int j = 0; j < MAX_MAP_SIZE; j++)
        {
            _baseTileRC[i][j] = RectMake(sizeXY * j, sizeXY * i, sizeXY, sizeXY);
            _selecttile[i][j].draw = false;
            _selectdoor[i][j].draw = false;
        }
    }

    /*
    forX = (_moveValueX) / -16;
    forMaxX = (1280 + (_moveValueX * -1)) / 16;
    forY = (_moveValueY) / -16;
    forMaxY = (720 + (_moveValueY * -1)) / 16;
    */

    //_testPlayer = RectMakeCenter(598, 546, 10, 10);
    _testPlayer = RectMake(330, 250, 52, 52);

 

    //forX = forY = 5;
    //maxforX = forX + 14;
    //maxforY = forY + 12;

  //  cout << forX << ", " << maxforX << ", " << forY << ", " << maxforY << endl;

    for (int i = 0; i < 10; i++)
    {
        _imgSize[i] = 52;
        _imgLine[i] = 6;
    }
    _selectImg = _selectImgFrameX = _selectImgFrameY = 0;
    _tileClick = false;


    for (int i = 0; i < _imgLine[_selectImg]; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            _tileSelectRC[i * 4 + j] = RectMake(WINSIZE_X - 250 + 52 * j, 20 + _imgSize[_selectImg] * i, 52, _imgSize[_selectImg]);
        }
    }

    //_characterNum = _CharMapX = _CharMapY = 0;

    _nextButton = RectMake(WINSIZE_X - 60, WINSIZE_Y - 250, 50, 50);
    _prevButton = RectMake(WINSIZE_X - 120, WINSIZE_Y - 250, 50, 50);

    _saveRC = RectMake(WINSIZE_X - 240, WINSIZE_Y - 100, 100, 30);
    _loadRC = RectMake(WINSIZE_X - 240, WINSIZE_Y - 60, 100, 30);

    _mainMenu = RectMake(WINSIZE_X - 100, WINSIZE_Y - 100, 68, 70);


    _eraseTile = false;
    _savefileName[0] = "1floor.json";
    _savefileName[1] = "2floor.json";
    _savefileName[2] = "3floor.json";
    _savefileName[3] = "4floor.json";
    _fileNameCnt = 0;

    //��ư
    for (int i = 0; i < 4; i++)
    {
        _stage[i] = RectMake(540 + 60 * i, 410, 40, 40);
    }

    _buttonName[0] = "�κ��ư";
    _buttonName[1] = "1����������ư";
    _buttonName[2] = "2����������ư";
    _buttonName[3] = "��������������ư";

    _testPlayer.left += 937;
    _testPlayer.right += 937;
    _testPlayer.top += 730;
    _testPlayer.bottom += 730;
    return S_OK;
}

void MapTool::release(void)
{
}

void MapTool::update(void)
{
    if (KEYMANAGER->isOnceKeyDown(VK_RIGHT))
    {
        _testPlayer.left += 52;
        _testPlayer.right += 52;
    }
    if (KEYMANAGER->isOnceKeyDown(VK_LEFT))
    {
        _testPlayer.left -= 52;
        _testPlayer.right -= 52;
    }
    if (KEYMANAGER->isOnceKeyDown(VK_UP))
    {
        _testPlayer.top -= 52;
        _testPlayer.bottom -= 52;
    }
    if (KEYMANAGER->isOnceKeyDown(VK_DOWN))
    {
        _testPlayer.top += 52;
        _testPlayer.bottom += 52;
    }//27  //18 // 1404

    forX = (_testPlayer.left - 52 * 7) / 52;
    maxforX = (_testPlayer.right + 52 * 3) / 52;
    forY = (_testPlayer.top - 52 * 5) / 52;
    maxforY = (_testPlayer.bottom + 52 * 5) / 52;

    if (forX <= 0) forX = 0;
    if (maxforX >= MAX_MAP_SIZE) maxforX = MAX_MAP_SIZE;
    if (forY <= 0) forY = 0;
    if (maxforY >= MAX_MAP_SIZE) maxforY = MAX_MAP_SIZE;
   // cout << forX << ", " << maxforX << ", " << forY << ", " << maxforY << endl;

    CAMERAMANAGER->setCamera(_testPlayer.left + (_testPlayer.right - _testPlayer.left) / 2,
        _testPlayer.top + (_testPlayer.bottom - _testPlayer.top) / 2);

    //��Ʈ�� Ÿ�� ��Ƶα�
    for (int i = 0; i < MAX_MAP_SIZE; i++)
    {
        for (int j = 0; j < MAX_MAP_SIZE; j++)
        {
            _baseTileRC[i][j] = RectMake(sizeXY * j - CAMERAMANAGER->getCamera().x, sizeXY * i - CAMERAMANAGER->getCamera().y, sizeXY, sizeXY);
        }
    }

    //Ÿ�� ����
    if (_ptMouse.x >= 526 && !PtInRect(&_mainMenu, _ptMouse))
    {
        if (KEYMANAGER->isOnceKeyDown(MK_LBUTTON))
        {
            for (int i = 0; i < _imgLine[_selectImg]; i++)
            {
                for (int j = 0; j < 4; j++)
                {
                    if (PtInRect(&_tileSelectRC[4 * i + j], _ptMouse))
                    {
                        _eraseTile = false;
                        _tileClick = true;
                        //������ Ÿ�� ������ ����
                        _selectImgFrameX = j;
                        _selectImgFrameY = i;

                        _tileGround[_selectImg]->setFrameX(_selectImgFrameX);
                        _tileGround[_selectImg]->setFrameY(_selectImgFrameY);

                      
                        break;
                    }
                }
            }
            //�����׸���ư Ŭ��
            if (PtInRect(&_nextButton, _ptMouse))
            {
                if (_selectImg < 9)
                {
                    _eraseTile = false;
                    _selectImg++;
                    _tileClick = false;

                }
            }
            //�����׸���ư Ŭ��
            else if (PtInRect(&_prevButton, _ptMouse))
            {

                if (_selectImg > 0)
                {
                    _eraseTile = false;
                    _selectImg--;
                    _tileClick = false;

                }

            }
            else if (PtInRect(&_saveRC, _ptMouse))
            {
                _eraseTile = false;
                SaveMap();
            }
            else if (PtInRect(&_loadRC, _ptMouse))
            {
                _eraseTile = false;
                LoadMap();
            }
            else if (PtInRect(&_stage[0], _ptMouse))
            {
                _eraseTile = false;
                _tileClick = false;
                _fileNameCnt = 0;
                for (int i = 0; i < 4; i++)
                {

                    if (i == 0)  _butten2[i]->setFrameX(1);
                    else _butten2[i]->setFrameX(0);
                }
            }
            else if (PtInRect(&_stage[1], _ptMouse))
            {
                _eraseTile = false;
                _tileClick = false;
                _fileNameCnt = 1;
                for (int i = 0; i < 4; i++)
                {

                    if (i == 1)  _butten2[i]->setFrameX(1);
                    else _butten2[i]->setFrameX(0);
                }

            }
            else if (PtInRect(&_stage[2], _ptMouse))
            {
                _eraseTile = false;
                _tileClick = false;
                _fileNameCnt = 2;
                for (int i = 0; i < 4; i++)
                {

                    if (i == 2)  _butten2[i]->setFrameX(1);
                    else _butten2[i]->setFrameX(0);
                }

            }
            else if (PtInRect(&_stage[3], _ptMouse))
            {
                _eraseTile = false;
                _tileClick = false;
                _fileNameCnt = 3;
                for (int i = 0; i < 4; i++)
                {

                    if (i == 3)  _butten2[i]->setFrameX(1);
                    else _butten2[i]->setFrameX(0);
                }

            }
            else if (PtInRect(&_eraseRC, _ptMouse))
            {
                _tileClick = false;

                _eraseTile = true;

                cout << "adfa" << endl;
            }

           
        }
    }
    //Ÿ�� ���
    else
    {
        for (int i = 0; i < MAX_MAP_SIZE; i++)
        {
            for (int j = 0; j < MAX_MAP_SIZE; j++)
            {
                if (_tileClick && KEYMANAGER->isStayKeyDown(MK_LBUTTON) && PtInRect(&_baseTileRC[i][j], _ptMouse))
                {
                    MAKE_MAP mm;
                    ZeroMemory(&mm, sizeof(MAKE_MAP));
                    if (!_eraseTile)
                    {
                        //�ʱ�ȭ
                        mm.img = _tileGround[_selectImg];
                        mm.idx = i * MAX_MAP_SIZE + j;
                        mm.draw = true;
                        //�����ص� FrameX,Y Ÿ�Ͽ� ���
                        mm.frameX = _selectImgFrameX;
                        mm.frameY = _selectImgFrameY;
                        mm.keyNum = _selectImg;

                        if (_selectImg >= 0 && _selectImg < 5) _selecttile[i][j] = mm;
                        else if (_selectImg == 5) _selectdoor[i][j] = mm;
                        else if (_selectImg == 6) _selectobject[i][j] = mm;
                        else if (_selectImg >= 7)
                        {
                            _selectmonster[i][j] = mm;
                            //cout << "fdfsd" << endl;
                        }
                    }
                    else
                    {
                        _tileRC[i][j].draw = false;
                        _tileRC[i][j].frameX = 0;
                        _tileRC[i][j].frameY = 0;
                        _tileRC[i][j].idx = 0;
                        _tileRC[i][j].keyNum = 0;
                        _tileRC[i][j].img = IMAGEMANAGER->findImage("���");

                   
                    }

                    //cout << _selectImgFrameX << ", " << _selectImgFrameY << endl;
             

                }
            }
        }
    }

    if (KEYMANAGER->isOnceKeyDown('L'))
    {
        Json::Value root;
        Json::Value tile;
        Json::Value door;
        Json::Value object;
        Json::Value Monster;

        for (int i = 0; i < MAX_MAP_SIZE; i++)
        {
            for (int j = 0; j < MAX_MAP_SIZE; j++)
            {

                tile["idx"] = _selecttile[i][j].idx;
                tile["draw"] = _selecttile[i][j].draw;
                tile["frameX"] = _selecttile[i][j].frameX;
                tile["frameY"] = _selecttile[i][j].frameY;
                tile["keyNum"] = _selecttile[i][j].keyNum;
              
                root["Ÿ��"].append(tile);

                door["idx"] = _selectdoor[i][j].idx;
                door["draw"] = _selectdoor[i][j].draw;
                door["frameX"] = _selectdoor[i][j].frameX;
                door["frameY"] = _selectdoor[i][j].frameY;
                door["keyNum"] = _selectdoor[i][j].keyNum;
          

                root["��"].append(door);

                object["idx"] = _selectobject[i][j].idx;
                object["draw"] = _selectobject[i][j].draw;
                object["frameX"] = _selectobject[i][j].frameX;
                object["frameY"] = _selectobject[i][j].frameY;
                object["keyNum"] = _selectobject[i][j].keyNum;
             

                root["������Ʈ"].append(object);


                Monster["idx"] = _selectmonster[i][j].idx;
                Monster["draw"] = _selectmonster[i][j].draw;
                Monster["frameX"] = _selectmonster[i][j].frameX;
                Monster["frameY"] = _selectmonster[i][j].frameY;
                Monster["keyNum"] = _selectmonster[i][j].keyNum;
               

                root["����"].append(Monster);

            }
        }





        JSONDATAMANAGER->saveJsonFile("TileSave.json", root);
        cout << "����Ϸ�" << endl;


    }

    if (PtInRect(&_mainMenu, _ptMouse))
    {
        if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
        {
            SCENEMANAGER->changeScene("���θ޴�");
        }
    }



}

void MapTool::render(void)
{
   
    //for (int i = 0; i < MAX_MAP_SIZE; i++)
    //{
    //    for (int j = 0; j < MAX_MAP_SIZE; j++)
    for (int i = forY; i < maxforY; i++)
    {
        for (int j = forX; j < maxforX; j++)
        {
            DrawRectMake(getMemDC(), _baseTileRC[i][j]);

            //char s[128];
            //wsprintf(s, "%d", i * 50 + j);
            //TextOut(getMemDC(), sizeXY * j - CAMERAMANAGER->getCamera().x, sizeXY * i - CAMERAMANAGER->getCamera().y, s, strlen(s));

            if (_selecttile[i][j].draw)
            {
                _selecttile[i][j].img->frameRender(getMemDC(), _baseTileRC[i][j].left, _baseTileRC[i][j].top, _selecttile[i][j].frameX, _selecttile[i][j].frameY);
            }

            if (_selectdoor[i][j].draw)
            {
                _selectdoor[i][j].img->frameRender(getMemDC(), _baseTileRC[i][j].left, _baseTileRC[i][j].top , _selectdoor[i][j].frameX, _selectdoor[i][j].frameY);
            }

            if (_selectobject[i][j].draw)
            {
                _selectobject[i][j].img->frameRender(getMemDC(), _baseTileRC[i][j].left , _baseTileRC[i][j].top , _selectobject[i][j].frameX, _selectobject[i][j].frameY);
            }

            if (_selectmonster[i][j].draw)
            {
                _selectmonster[i][j].img->frameRender(getMemDC(), _baseTileRC[i][j].left, _baseTileRC[i][j].top , _selectmonster[i][j].frameX, _selectmonster[i][j].frameY);
            }
        }
    }

    //DrawRectMake(getMemDC(), { 526,0,WINSIZE_X,WINSIZE_Y });
    IMAGEMANAGER->render("�����ʹڽ�", getMemDC(), WINSIZE_X - 270, 0);
    // DrawRectMake(getMemDC(), _nextButton);
    // DrawRectMake(getMemDC(), _prevButton);
    //DrawRectMake(getMemDC(), _saveRC);
    //DrawRectMake(getMemDC(), _loadRC);
    //DrawRectMake(getMemDC(), _mainMenu);
    //DrawRectMake(getMemDC(), { _testPlayer.left - CAMERAMANAGER->getCamera().x,_testPlayer.top - CAMERAMANAGER->getCamera().y,_testPlayer.right - CAMERAMANAGER->getCamera().x,_testPlayer.bottom - CAMERAMANAGER->getCamera().y });

    _tileImg[_selectImg]->render(getMemDC(), WINSIZE_X - 250, 20);


    if (KEYMANAGER->isToggleKey(VK_F1))
    {
        for (int i = 0; i < _imgLine[_selectImg]; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                DrawRectMake(getMemDC(), _tileSelectRC[i * 4 + j]);
            }
        }
    }

    if (_tileClick) _tileGround[_selectImg]->frameRender(getMemDC(), _ptMouse.x - 24, _ptMouse.y - 24, _selectImgFrameX, _selectImgFrameY);
    IMAGEMANAGER->alphaRender("�޹��", getMemDC(), 3, 20, 100);
    IMAGEMANAGER->render("�¹�ư", getMemDC(), WINSIZE_X - 117, WINSIZE_Y - 250);
    IMAGEMANAGER->render("���ư", getMemDC(), WINSIZE_X - 58, WINSIZE_Y - 250);
    IMAGEMANAGER->render("�ڷΰ���", getMemDC(), WINSIZE_X -110, WINSIZE_Y-100);
    IMAGEMANAGER->render("��������", getMemDC(), _loadRC.left + 10, _loadRC.top - 3);
    IMAGEMANAGER->render("����", getMemDC(), _saveRC.left + 10, _saveRC.top - 3);

    for (int i = 0; i < 4; i++)
    {
        DrawRectMake(getMemDC(), _stage[i]);
        //IMAGEMANAGER->frameRender(_buttonName[i], getMemDC(), _stage[i].left, _stage[i].top, IMAGEMANAGER->findImage(_buttonName[i])->getFrameX(), IMAGEMANAGER->findImage(_buttonName[i])->getFrameY());

        _butten2[i]->frameRender(getMemDC(), _stage[i].left, _stage[i].top);

    }



}

void MapTool::LoadMap()
{
    memset(_selecttile, 0, sizeof(_selecttile));
    memset(_selectdoor, 0, sizeof(_selectdoor));
    memset(_selectobject, 0, sizeof(_selectobject));
    memset(_selectmonster, 0, sizeof(_selectmonster));

    Json::Value root = JSONDATAMANAGER->loadJsonFile(_savefileName[_fileNameCnt]);

    for (auto it = root["Ÿ��"].begin(); it != root["Ÿ��"].end(); it++)
    {
        if ((*it).isObject())
        {
            MAKE_MAP _tileInfo;
            _tileInfo.frameX = (*it)["frameX"].asInt();
            _tileInfo.frameY = (*it)["frameY"].asInt();
            _tileInfo.draw = (*it)["draw"].asBool();
            _tileInfo.idx = (*it)["idx"].asInt();
            _tileInfo.keyNum = (*it)["keyNum"].asInt();
            _tileInfo.img = _tileGround[_tileInfo.keyNum];

            int _fy = _tileInfo.idx / MAX_MAP_SIZE;
            int _fx = _tileInfo.idx % MAX_MAP_SIZE;
            if(_tileInfo.draw)
            _selecttile[_fy][_fx] = _tileInfo;
        }
    }
    for (auto it = root["��"].begin(); it != root["��"].end(); it++)
    {
        if ((*it).isObject())
        {
            MAKE_MAP _tileInfo;
            _tileInfo.frameX = (*it)["frameX"].asInt();
            _tileInfo.frameY = (*it)["frameY"].asInt();
            _tileInfo.draw = (*it)["draw"].asBool();
            _tileInfo.idx = (*it)["idx"].asInt();
            _tileInfo.keyNum = (*it)["keyNum"].asInt();
            _tileInfo.img = _tileGround[_tileInfo.keyNum];

            int _fy = _tileInfo.idx / MAX_MAP_SIZE;
            int _fx = _tileInfo.idx % MAX_MAP_SIZE;
            _selectdoor[_fy][_fx] = _tileInfo;
        }
    }
    for (auto it = root["������Ʈ"].begin(); it != root["������Ʈ"].end(); it++)
    {
        if ((*it).isObject())
        {
            MAKE_MAP _tileInfo;
            _tileInfo.frameX = (*it)["frameX"].asInt();
            _tileInfo.frameY = (*it)["frameY"].asInt();
            _tileInfo.draw = (*it)["draw"].asBool();
            _tileInfo.idx = (*it)["idx"].asInt();
            _tileInfo.keyNum = (*it)["keyNum"].asInt();
            _tileInfo.img = _tileGround[_tileInfo.keyNum];

            int _fy = _tileInfo.idx / MAX_MAP_SIZE;
            int _fx = _tileInfo.idx % MAX_MAP_SIZE;
            _selectobject[_fy][_fx] = _tileInfo;
        }
    }
    for (auto it = root["����"].begin(); it != root["����"].end(); it++)
    {
        if ((*it).isObject())
        {
            MAKE_MAP _tileInfo;
            _tileInfo.frameX = (*it)["frameX"].asInt();
            _tileInfo.frameY = (*it)["frameY"].asInt();
            _tileInfo.draw = (*it)["draw"].asBool();
            _tileInfo.idx = (*it)["idx"].asInt();
            _tileInfo.keyNum = (*it)["keyNum"].asInt();
            _tileInfo.img = _tileGround[_tileInfo.keyNum];

            int _fy = _tileInfo.idx / MAX_MAP_SIZE;
            int _fx = _tileInfo.idx % MAX_MAP_SIZE;
            _selectmonster[_fy][_fx] = _tileInfo;
        }
    }

}

void MapTool::SaveMap()
{
    Json::Value root;
    Json::Value tile;
    Json::Value wall;
    Json::Value object;
    Json::Value monster;

    for (int i = 0; i < MAX_MAP_SIZE; i++)
    {
        for (int j = 0; j < MAX_MAP_SIZE; j++)
        {
            tile["idx"] = _selecttile[i][j].idx;
            tile["draw"] = _selecttile[i][j].draw;
            tile["frameX"] = _selecttile[i][j].frameX;
            tile["frameY"] = _selecttile[i][j].frameY;
            tile["keyNum"] = _selecttile[i][j].keyNum;
            root["Ÿ��"].append(tile);

            wall["idx"] = _selectdoor[i][j].idx;
            wall["draw"] = _selectdoor[i][j].draw;
            wall["frameX"] = _selectdoor[i][j].frameX;
            wall["frameY"] = _selectdoor[i][j].frameY;
            wall["keyNum"] = _selectdoor[i][j].keyNum;
            root["��"].append(wall);

            object["idx"] = _selectobject[i][j].idx;
            object["draw"] = _selectobject[i][j].draw;
            object["frameX"] = _selectobject[i][j].frameX;
            object["frameY"] = _selectobject[i][j].frameY;
            object["keyNum"] = _selectobject[i][j].keyNum;
            root["������Ʈ"].append(object);

            monster["idx"] = _selectmonster[i][j].idx;
            monster["draw"] = _selectmonster[i][j].draw;
            monster["frameX"] = _selectmonster[i][j].frameX;
            monster["frameY"] = _selectmonster[i][j].frameY;
            monster["keyNum"] = _selectmonster[i][j].keyNum;
            root["����"].append(monster);

        }
    }

    //���̽��� ����
    JSONDATAMANAGER->saveJsonFile(_savefileName[_fileNameCnt], root);
    cout << "����Ϸ�" << endl;

}

//_nextButton = RectMake(WINSIZE_X - 60, WINSIZE_Y - 250, 50, 50);
//_prevButton = RectMake(WINSIZE_X - 120, WINSIZE_Y - 250, 50, 50);
//_eraseRC = RectMake(WINSIZE_X - 230, WINSIZE_Y - 120, 100, 30);
//_saveRC = RectMake(WINSIZE_X - 230, WINSIZE_Y - 80, 100, 30);
//_loadRC = RectMake(WINSIZE_X - 230, WINSIZE_Y - 40, 100, 30);
//_mainMenu = RectMake(WINSIZE_X - 100, WINSIZE_Y - 80, 100, 30);