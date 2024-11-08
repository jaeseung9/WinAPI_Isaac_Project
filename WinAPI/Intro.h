#pragma once
#include "GameNode.h"


class Intro : public GameNode
{
	HWND hWndVideo;
	bool _openingSkipAnyKey;
public:
	HRESULT init(void);
	void release(void);
	void update(void);

	bool Get_OpeningSkipAnyKey(void) { return _openingSkipAnyKey; }

	Intro() {}
	~Intro() {}

};

