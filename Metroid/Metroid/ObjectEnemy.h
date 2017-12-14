#pragma once
#include "Box.h"
class ObjectEnemy
{

protected:

	// position
	float x;
	float y;
	float vecX;
	float vecY;
	int Type;
	int id;
public:

	int Width;
	int Height;
	bool IsDie;
	int index;
	int turn;
	int temp;

	
	ObjectEnemy();
	ObjectEnemy(int id,int type, int x,int y,int width,int height);
	void SetObj(int id, int type, int x, int y, int width, int height);

	virtual void Update();


	int GetID() { return this->id; }
	int GetX() { return this->x; }
	int GetY() { return this->y; }
	int GetType() { return this->Type; }
	void SetX(int v) { this->x = v; }
	void SetY(int v) { this->y = v; }
	void SetVec(float vc, float vy) { this->vecX = vc; this->vecY = vy; }
	void SetVx(float vx) { this->vecX = vx; }
	void SetVy(float vy) { this->vecY = vy; }
	void SetType(int type) { this->Type = type; }

	virtual void Draw(){}
	
	virtual Box GetBox();
	~ObjectEnemy();
};

