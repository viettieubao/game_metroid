#pragma once
#include "GTexture.h"
#include "GSprite.h"
#include "GCamera.h"
#include <dinput.h>
#include "Object.h"
#include <iostream>
using namespace std;
class CSamus :public Object
{
public:
	void Update(int t, GCamera * camera);
	void Draw(GCamera*);

	void Run(int t, GCamera* camera);
	void Roll();
	void StandUp();
	void Jump();
	void Fall();

	CSamus();
	CSamus(float,float);
	~CSamus();
};

