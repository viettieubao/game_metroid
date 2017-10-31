#include "CBackground.h"



CBackground::CBackground()
{
	listtile = NULL;
}

CBackground::CBackground(int level) {
	string filename;
	switch (level)
	{
	case 1:
		filename = "Resources\\Maps\\stage1\\Stage1_Map.txt";
		break;
	default:
		break;
	}
	ifstream map(filename);
	if (map.is_open()) {
		int posX, posY;
		int value;
		int col, row; //file cat
		int colmap, rowmap;//file map
		map >> col>>row;
		map >> colmap >> rowmap;
		if (level == 1) {
			bg_tt = new CTexture("Resources\\Maps\\stage1\\Stage1.png", col, row, col*row);
			bg_sp = new CSprite(bg_tt, 1000);
		}
		int id = 0;
		listtile = new std::map<int, Tile*>();
		Tile* obj;
		for (int i = colmap - 1; i > 0; i--) { //cot
			for (int j = 0; j < rowmap; j++)//hang
			{
				map >> value;
				posX = (j * 32); 
				posY = i * 32;
				id = i*colmap + j;
				Tile *tile = new Tile(value, posX, posY);
				listtile->insert(pair<int, Tile*>(id, tile));
			}

		}
		map.close();
	}
}
void CBackground::Draw(CCamera *camera) {
	map<int, Tile*>::iterator begin;
	for (begin = listtile->begin(); begin != listtile->end(); begin++) {
		Tile * obj = begin->second;
		D3DXVECTOR2 t = camera->Transform(obj->posX, obj->posY);
		bg_sp->DrawIndex(obj->ID, t.x, t.y);
	}
}

CBackground::~CBackground(void)
{
}
