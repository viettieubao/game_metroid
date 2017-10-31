#pragma once
#include "CTexture.h"
#include "CSprite.h"
#include "CCamera.h"
#include <dinput.h>
class CSamus
{
public:
	float posX, posY;
	float vx, vy;
	float standWidth = 16;
	float standHeight = 40;
	CSprite *samusSprite;
	CTexture *samusTexture;
	bool isturnleft;

	void Update(int detatime);
	void Draw(CCamera*);
	CSamus();
	CSamus(float,float);
	~CSamus();
};

