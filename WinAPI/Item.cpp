#include "Stdafx.h"
#include "Item.h"

HRESULT Item::init(void)
{
	//순교자의 피
	_item[0].atk = 1;
	_item[0].attackSpeed = 0;
	_item[0].bomb = 0;
	_item[0].hp = 0;
	_item[0].intersection = 0;
	_item[0].key = 0;
	_item[0].money = 0;
	_item[0].speed = 0;
	_item[0].itemImage = IMAGEMANAGER->addImage
	("순교자의피", "Resources/Images/Item/Item0.bmp", 32 * 1.5, 32 * 1.5, true, RGB(255, 0, 255));

	//심장
	_item[1].atk = 0;
	_item[1].attackSpeed = 0;
	_item[1].bomb = 0;
	_item[1].hp = 4;
	_item[1].intersection = 0;
	_item[1].key = 0;
	_item[1].money = 0;
	_item[1].speed = 0;
	_item[1].itemImage = IMAGEMANAGER->addImage
	("심장", "Resources/Images/Item/Item1.bmp", 32 * 1.5, 32 * 1.5, true, RGB(255, 0, 255));

	//해골 열쇠
	_item[2].atk = 0;
	_item[2].attackSpeed = 0;
	_item[2].bomb = 0;
	_item[2].hp = 0;
	_item[2].intersection = 0;
	_item[2].key = 99;
	_item[2].money = 0;
	_item[2].speed = 0;
	_item[2].itemImage = IMAGEMANAGER->addImage
	("해골 열쇠", "Resources/Images/Item/Item2.bmp", 32 * 1.5, 32 * 1.5, true, RGB(255, 0, 255));

	//1달러
	_item[3].atk = 0;
	_item[3].attackSpeed = 0;
	_item[3].bomb = 0;
	_item[3].hp = 0;
	_item[3].intersection = 0;
	_item[3].key = 0;
	_item[3].money = 100;
	_item[3].speed = 0;
	_item[3].itemImage = IMAGEMANAGER->addImage
	("1달러", "Resources/Images/Item/Item3.bmp", 32 * 1.5, 32 * 1.5, true, RGB(255, 0, 255));


	//폭탄
	_item[4].atk = 0;
	_item[4].attackSpeed = 0;
	_item[4].bomb = 10;
	_item[4].hp = 0;
	_item[4].intersection = 0;
	_item[4].key = 0;
	_item[4].money = 0;
	_item[4].speed = 0;
	_item[4].itemImage = IMAGEMANAGER->addImage
	("Boom", "Resources/Images/Item/Item4.bmp", 32 * 1.5, 32 * 1.5, true, RGB(255, 0, 255));

	//초월
	_item[5].atk = 0;
	_item[5].attackSpeed = 0;
	_item[5].bomb = 0;
	_item[5].hp = 0;
	_item[5].intersection = 0;
	_item[5].key = 0;
	_item[5].money = 0;
	_item[5].speed = 0;
	_item[5].itemImage = IMAGEMANAGER->addImage
	("초월", "Resources/Images/Item/Item5.bmp", 32 * 1.5, 32 * 1.5, true, RGB(255, 0, 255));

	//벨트
	_item[6].atk = 0;
	_item[6].attackSpeed = 0;
	_item[6].bomb = 0;
	_item[6].hp = 0;
	_item[6].intersection = 0;
	_item[6].key = 0;
	_item[6].money = 0;
	_item[6].speed = 0.5f;
	_item[6].itemImage = IMAGEMANAGER->addFrameImage
	("벨트", "Resources/Images/Item/Item6.1.bmp", 64 / 1.5, 180 / 1.5, 1, 2, true, RGB(255, 0, 255));

	//철제옷걸이
	_item[7].atk = 0;
	_item[7].attackSpeed = 1.0f;
	_item[7].bomb = 0;
	_item[7].hp = 0;
	_item[7].intersection = 0;
	_item[7].key = 0;
	_item[7].money = 0;
	_item[7].speed = 0;
	_item[7].itemImage = IMAGEMANAGER->addFrameImage
	("철제옷걸이", "Resources/Images/Item/Item7.1.bmp", 64 / 1.5, 180 / 1.5, 1, 2, true, RGB(255, 0, 255));


	//스티븐
	_item[8].atk = 1.0f;
	_item[8].attackSpeed = 0;
	_item[8].bomb = 0;
	_item[8].hp = 0;
	_item[8].intersection = 0;
	_item[8].key = 0;
	_item[8].money = 0;
	_item[8].speed = 0;
	_item[8].itemImage = IMAGEMANAGER->addImage
	("스티븐", "Resources/Images/Item/Item8.bmp", 32 * 1.5, 32 * 1.5, true, RGB(255, 0, 255));

	//쉴드 액티브 아이템
	_item[9].atk = 0;
	_item[9].attackSpeed = 0;
	_item[9].bomb = 0;
	_item[9].hp = 0;
	_item[9].intersection = 0;
	_item[9].key = 0;
	_item[9].money = 0;
	_item[9].speed = 0;
	_item[9].itemImage = IMAGEMANAGER->addFrameImage
	("book", "Resources/Images/Item/book1.bmp", 64 / 1.5, 180 / 1.5, 1, 2 , true, RGB(255, 0, 255));

	//눈물공격
	_item[10].atk = 1;
	_item[10].attackSpeed = 0;
	_item[10].bomb = 0;
	_item[10].hp = 0;
	_item[10].intersection = 0;
	_item[10].key = 0;
	_item[10].money = 0;
	_item[10].speed = 0;
	_item[10].itemImage = IMAGEMANAGER->addImage
	("눈알공격", "Resources/Images/Item/Item10.bmp", 32 * 1.5, 32 * 1.5,true, RGB(255, 0, 255));

	//악마변신 무기 혈사포변경
	_item[11].atk = 1;
	_item[11].attackSpeed = 0;
	_item[11].bomb = 0;
	_item[11].hp = 0;
	_item[11].intersection = 0;
	_item[11].key = 0;
	_item[11].money = 0;
	_item[11].speed = 0;
	_item[11].itemImage = IMAGEMANAGER->addImage
	("사탄", "Resources/Images/Item/사탄.bmp", 32 * 1.5, 32 * 1.5, true, RGB(255, 0, 255));


	//캐릭터 주변 파리
	_item[11].atk = 0;
	_item[11].attackSpeed = 0;
	_item[11].bomb = 0;
	_item[11].hp = 0;
	_item[11].intersection = 0;
	_item[11].key = 0;
	_item[11].money = 0;
	_item[11].speed = 0;
	_item[11].itemImage = IMAGEMANAGER->addImage
	("파리떼아이템", "Resources/Images/Item/파리떼아이템.bmp", 32 * 1.5, 32 * 1.5, true, RGB(255, 0, 255));

	_item[0].rc = RectMake(207000, 210 - 417, 40, 41);
	_item[1].rc = RectMake(250007, 210000, 30, 41);
	_item[2].rc = RectMake(-1187, -207, 30, 41);
	_item[3].rc = RectMake(35700, 21000, 30, 41);
	_item[4].rc = RectMake(400007, 210000, 30, 41);
	_item[5].rc = RectMake(45700, 21000, 30, 41);
	_item[8].rc = RectMake(600007, 210000, 30, 41);
	_item[10].rc = RectMake(20700, 21000, 30, 30);
	_item[6].rc = RectMake(1892, -187, 30, 30);
	_item[7].rc = RectMake(1972, -187, 30, 41);
	_item[9].rc = RectMake(2052, -187, 30, 41);
	_item[11].rc = RectMake(10007, 21000, 30, 30);
	_item[12].rc = RectMake(10700, 26000, 30, 30);

	//_item[11].rc = RectMake(107, 410, 30, 30);
	//_item[12].rc = RectMake(107, 460, 30, 30);
	//_item[10].rc = RectMake(157, 410, 30, 30);
	//_item[0].rc = RectMake(207, 410, 30, 30);
	//_item[1].rc = RectMake(257, 410, 30, 30);
	//_item[2].rc = RectMake(307, 410, 30, 30);
	//_item[3].rc = RectMake(357, 410, 30, 30);
	//_item[4].rc = RectMake(407, 410, 30, 30);
	//_item[5].rc = RectMake(457, 410, 30, 30);
	//_item[6].rc = RectMake(507, 410, 30, 30);
	//_item[7].rc = RectMake(557, 410, 30, 30);
	//_item[8].rc = RectMake(607, 410, 30, 30);
	//_item[9].rc = RectMake(657, 410, 30, 30);

	return S_OK;
}

void Item::release(void)
{
}

void Item::update(void)
{

}

void Item::render(void)
{
	IMAGEMANAGER->render("순교자의피", getMemDC(), _item[0].rc.left - 11, _item[0].rc.top - 14);
	IMAGEMANAGER->render("심장", getMemDC(), _item[1].rc.left - 11, _item[1].rc.top - 14);
	IMAGEMANAGER->render("해골 열쇠", getMemDC(), _item[2].rc.left - 11, _item[2].rc.top - 14);
	IMAGEMANAGER->render("1달러", getMemDC(), _item[3].rc.left - 15, _item[3].rc.top - 14);
	IMAGEMANAGER->render("Boom", getMemDC(), _item[4].rc.left - 5, _item[4].rc.top - 14);
	IMAGEMANAGER->render("초월", getMemDC(), _item[5].rc.left - 11, _item[5].rc.top - 14);
	IMAGEMANAGER->frameRender("벨트", getMemDC(), _item[6].rc.left - 11, _item[6].rc.top - 14, 0, _item[6].itemImage->getFrameY());
	IMAGEMANAGER->frameRender("철제옷걸이", getMemDC(), _item[7].rc.left - 11, _item[7].rc.top - 14, 0, _item[7].itemImage->getFrameY());
	IMAGEMANAGER->render("스티븐", getMemDC(), _item[8].rc.left - 11, _item[8].rc.top - 14);
	IMAGEMANAGER->frameRender("book", getMemDC(), _item[9].rc.left - 11, _item[9].rc.top - 14, 0, _item[9].itemImage->getFrameY());
	IMAGEMANAGER->render("눈알공격", getMemDC(), _item[10].rc.left - 11, _item[10].rc.top - 14);
	IMAGEMANAGER->render("사탄", getMemDC(), _item[11].rc.left - 11, _item[11].rc.top - 14);
	IMAGEMANAGER->render("파리떼아이템", getMemDC(), _item[12].rc.left - 11, _item[12].rc.top - 14);

	for (int i = 0; i < 10; i++)
	{
		//DrawRectMake(getMemDC(),_item[i].rc);
	}
}
