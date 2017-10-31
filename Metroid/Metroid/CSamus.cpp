#include "CSamus.h"
#define SAMUS_FILE "E:\\HK7\\GAme\\Metroid\\Metroid\\Resources\\samusRun.png"


CSamus::CSamus()
{
	this->samusTexture = NULL;
	this->samusSprite = NULL;
}
CSamus::CSamus(float x, float y)
{
	this->samusTexture = new CTexture(SAMUS_FILE, 3, 1, 3);
	this->samusSprite = new CSprite(this->samusTexture,0);
	this->posX = x;
	this->posY = y;
	this->vx = 0;
	this->vy = 0;
	isturnleft = false;
}

void CSamus::Update(int detatime) {
	this->samusSprite->Update(detatime);
	if (!isturnleft)
		this->posX += vx;
	else
		this->posX -= vx;
}
void CSamus::Draw(CCamera *camera) {
	D3DXVECTOR2 pos = camera->Transform(this->posX, this->posY);
	if (!isturnleft)
		this->samusSprite->Draw(pos.x, pos.y);
	else
		this->samusSprite->DrawFlipX(pos.x, pos.y);
}
CSamus::~CSamus()
{
}
