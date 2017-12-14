#include "ObjectEnemy.h"



ObjectEnemy::ObjectEnemy()
{
	x = 0;
	y = 0;
	Type = 0;
	id = 0;
	Width = 0;
	Height = 0;
	vecX = 0;
	vecY = 0;
	turn = 1;
	index = 0;
	IsDie = false;
}


ObjectEnemy::~ObjectEnemy()
{
}


ObjectEnemy::ObjectEnemy(int id, int type, int x, int y, int width, int height)
{
	this->id = id;
	this->Type = type;
	this->x = x;
	this->y = y;
	this->Width = width;
	this->Height = height;
	this -> vecX = 0;
	this->vecY = 0;
	this->turn = 1;
	this->index = 0;
	IsDie = false;
}

void ObjectEnemy::SetObj(int id, int type, int x, int y, int width, int height) {
	this->x = x;
	this->y = y;
	this->Type = type;
	this->id = id;
	this->Width = width;
	this->Height = height;
	this->vecX = 0;
	this->vecX = 0;
	this->turn = 1;
	this->index = 0;
	this->IsDie = false;
}

void ObjectEnemy::Update() {
	x += vecX;
	y += vecY;
}

Box ObjectEnemy::GetBox() {
	Box result;
	result.x = x;
	result.y = y;
	result.w = Width;
	result.h = this->Height;
	result.vx = this->vecX;
	result.vy = this->vecY;
	return result;
}
