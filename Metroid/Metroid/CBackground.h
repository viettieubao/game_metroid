#ifndef _QBACKGROUND_H_
#define _QBACKGROUND_H_

#include <map>
#include <list>
#include "GSprite.h"
#include "GTexture.h"
#include "Tile.h"
#include <string>
#include <sstream>
#include <fstream>
#include <iostream>
#include "GCamera.h"
using namespace std;

class CBackground
{
	int coltile; //so cot cua file tile .png
	int rowtile;
	int colmap;//so cot cua ma tran map
	int tilecount;
	int rowmap;
	int level;
public:
	GTexture *bg_tt;
	GSprite *bg_sp;
	map<int, Tile*> *listtile;
	CBackground(void);
	CBackground(int);
	void Draw(GCamera *);
	~CBackground();
};

#endif // !