#pragma once
#include "GSprite.h"
#include "GCamera.h"
#include <list>
#include "Enum.h"
using namespace std;
class GameObject
{
public:
	GSprite * sprite;
	float posX, posY;
	int width, height;
	float vX, vY;
	bool canMove;
	bool active;
	bool death;
	EnumID id;
	ObjectType type;

	virtual void Draw(GCamera*);
	virtual void Update(int);
	virtual void ProcessInput(LPDIRECT3DDEVICE9, int);
	virtual void Onkeydown(int);
	virtual void CreateSrpite();
	virtual void Remove();
	virtual void SetActive(float, float, EnumID){ }
	virtual void SetActive();


	GameObject();
	GameObject(float , float, EnumID);
	~GameObject();
};

