#ifndef _QBACKGROUND_H_
#define _QBACKGROUND_H_

#include <map>
#include <list>
#include "CSprite.h"
#include "CTexture.h"
#include "Tile.h"
#include <string>
#include <sstream>
#include <fstream>
#include <iostream>
#include "CCamera.h"
using namespace std;

class CBackground
{
public:
	CTexture *bg_tt;
	CSprite *bg_sp;
	map<int, Tile*> *listtile;
	CBackground(void);
	CBackground(int);
	void Draw(CCamera *);
	~CBackground();
};

#endif // !