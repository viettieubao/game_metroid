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
		filename = "Resources\\Maps\\Stage1\\Stage1-MAP.txt";
		colmap = 160;
		rowmap = 15;
		
	}
		break;
	default:
		break;
	}
	fstream f;
	f.open(filename, ios::in);
	string line;
	string strtemp = "";
	getline(f, line);
	int temp[2];  
	for (int i = 0; i < line.length(); i++) {
		if (line[i] != '\t' && IsNumber(line[i])) {
			strtemp += line[i];
		}
		else {
			if (IsNumber(strtemp[0])) {
				coltile = atoi(strtemp.c_str());
				strtemp = "";
			}
		}
		if (i == line.length() - 1) {
			rowtile = atoi(strtemp.c_str());
		}
	}
	bg_tt = new GTexture("Resources\\Maps\\Stage1\\Stage1.png", coltile, rowtile, coltile*rowtile);
	bg_sp = new GSprite(bg_tt, 1000);
	getline(f, line);
	listtile = new std::map<int, Tile*>();
	int j = 14;// row index
	int id = 0; // id index listtile
	while (!f.eof()) {
		strtemp = "";
		getline(f, line);
		//if (line == "") break;
		int temp = 0;
		for (int i = 0; i < line.length(); i++) {
			if (line[i] != '\t') {
				strtemp += line[i];
			}
			else {
				int idtile = atoi(strtemp.c_str());
				int posX = temp * 32 ;
				int posY = j * 32;
				Tile *tile = new Tile(idtile, posX, posY);
				listtile->insert(pair<int, Tile*>(id, tile));
				temp++;
				strtemp = "";
				id++;
			}
		}
		j--;
	}

	f.close();

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
