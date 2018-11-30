#include "CBackground.h"



CBackground::CBackground()
{
	listtile = NULL;
}

bool IsNumber(char c)
{
	if (c >= '0' && c <= '9')
		return true;
	return false;
}
CBackground::CBackground(int level) {
	this->level = level;
	string filename;
	switch (level)
	{
	case 1:
	{
		filename = "Resources\\Maps\\lv2_1.txt";
		
	}
		break;
	default:
		break;
	}
	ifstream f(filename);
	if (f.is_open()) {
		f >> this->tilecount;
		f >> this->rowmap;
		f >> this->colmap;
		int id = 0;
		listtile = new std::map<int, Tile*>();

		for (int i = rowmap - 1; i > 0; i--)
		{
			for (int j = 0; j < colmap; j++)
			{
				int value;
				f >> value;
				int posX = (j * 32) + 16;
				int posY = (i * 32) - 16;
				id = i * colmap + j;
				listtile->insert(pair<int, Tile*>(id, new Tile(value, posX, posY)));
			}
		}

		f.close();
		bg_tt = new GTexture("Resources\\Maps\\lv2_1.png", tilecount, 1, tilecount);
		bg_sp = new GSprite(bg_tt, 1000);
	}

}
void CBackground::Draw(GCamera *camera) {
	
	map<int, Tile*>::iterator begin;
	for (begin = listtile->begin(); begin != listtile->end(); begin++) {
		Tile * obj = begin->second;
		D3DXVECTOR2 t = camera->Transform(obj->posX, obj->posY);
		bg_sp->DrawIndex(obj->ID,t.x, t.y);
	}
}



CBackground::~CBackground(void)
{
}
