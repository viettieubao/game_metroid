#pragma once
#include "GTexture.h"
#include "GSprite.h"
#include "GCamera.h"
#include <dinput.h>
class CSamus
{
public:
	float posX, posY;
	float vx, vy;
	float standWidth = 16;
	float standHeight = 40;
	GSprite *samusSprite;
	GTexture *samusTexture;
	bool isturnleft;

	void Update(int detatime);
	void Draw(GCamera*);
	CSamus();
	CSamus(float,float);
	~CSamus();
};

