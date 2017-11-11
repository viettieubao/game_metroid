#pragma once
#include "GCamera.h"
#include "GSprite.h"
class Object
{
public:
	float fX;						//Vị trí giữa tâm nhân vật theo trục ox
	float fY;						//Vị trí giữa tâm nhân vật theo trục oy

	float fW;						//Chiều dài của box
	float fH;						//Chiều rộng của box

	float fVx;						//Vận tốc trên trục ox
	float fVy;						//Vận tốc trên trục oy
	float fSpeed;					//Tốc độ di chuyển của đối tượng

	int iState; // huong cua nhan vat 1 la ben trai 0 la ben phai;
	int isMoving;// dung yen =0, di chuyen =1
	int isSitting; // dung = 0 ngoi =1;
	int isJumping; // nhay =1;
	int iJump; // he so nhay
	int isFalling; //roi

	int Status; //nhan biet trang thai dung ngoi nhay : đứng =1; ngồi =2, nhảy bằng 3
	int isAttack; // danh =0 , khong danh =1;
	GTexture *GTObj;
	GSprite *GSObj;

	Object();
	~Object();

	float getx() { return this->fX; }
	float gety() { return this->fY; }
	float getvx() { return this->fVx; }
	float getvy() { return this->fVy; }
	float getw() { return this->fW; }
	float getH() { return this->fH; }
	float getspeed() { return this->fSpeed; }
	int getstate() { return this->iState; }
	int getmoving() { return this->isMoving; }
	int getsitting() { return this->isSitting; }
	int getattacking() { return this->isAttack; }

	void setx(float x1) { this->fX = x1; };
	void sety(float x1) { this->fY = x1; };
	void setvx(float x1) { this->fVx = x1; };
	void setvy(float x1) { this->fVy = x1; };
	void setW(float x1) { this->fW = x1; };
	void setH(float x1) { this->fH = x1; };
	void setspeed(float x1) { this->fSpeed = x1; };
	void setstate(int x1) { this->iState = x1; };
	void setmoving(int x1) { this->isMoving = x1; }
	void setsitting(int x1) { this->isSitting = x1; }
	
	void MoveLeft();
	void MoveRight();
	void Move();
	void Stop();
	void Sit();
	void StandUp();
	void Attack();
	void Jump();
	void Fall();

	virtual void Update(int t) {};
	virtual void Draw(GCamera *camera) {};
};

