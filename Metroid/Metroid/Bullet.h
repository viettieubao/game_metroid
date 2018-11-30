#pragma once
#include "ObjectEnemy.h"
#include "GCamera.h"
class Bullet:public ObjectEnemy
{
public:
	Bullet();
	void Update(int t, GCamera * camera);
	void Draw(GCamera*);
	~Bullet();
};

