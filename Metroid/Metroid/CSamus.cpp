#include "CSamus.h"
#define SAMUS_FILE "Resources\\samusRun.png"
#define Samus_SPEED_X 0.2f
#define Samus_SPEED_Y 0.2f

CSamus::CSamus():Object()
{
	GTObj = new GTexture(SAMUS_FILE, 3, 1, 3);
	GSObj = new GSprite(GTObj, 10);
	fX = 0;
	fY = 0;
	this->fVx = Samus_SPEED_X;
	this->fVy = Samus_SPEED_Y;
	fSpeed = 0;
	iState = 1;
	isMoving = 0;
	isJumping = 0;
	isFalling = 0;
}
CSamus::CSamus(float x =0, float y =0)
{
	this->fX = x;
	this->fY = y;
	this->fVx = Samus_SPEED_X;
	this->fVy = Samus_SPEED_Y;
	iState = 1;
	isMoving = 0;
	isFalling = 0;
	GTObj = new GTexture(SAMUS_FILE, 3, 1, 3);
	GSObj = new GSprite(GTObj, 10);  
}

void CSamus::Run(int t,GCamera *camera) {
	GSObj->Update(t);
	
	if (isMoving == 1) {
		if (this->fX <= 16) this->fX = 16;
		if (iState == 1) {
			this->fX = this->fX + fVx*t * 2;
		}
		if (iState == -1) {
			this->fX = this->fX - fVx*t * 2;
		}
	}
}
void CSamus::Sit() {
	if (isSitting == 0) {
		fY = fY - 17;
	}
	Object::Sit();
}

void CSamus::StandUp() {
	if (isSitting == 1) {
		fY = fY + 17;
	}
	Object::StandUp();
}

void CSamus::Jump() {
	if (isJumping == 0) {
		fY += 7;
		fVy = 10;
		GSObj->SelectIndex(1);
		Object::Jump();
	}
}

void CSamus::Fall() {

}

void CSamus::Update(int t, GCamera*camera) {
	if (isAttack == 1) {
		if (isSitting == 1) {

		}
		else {

		}
	}
	else {
		if (isMoving == 1) {
			this->Run(t,camera);
		}
		else if (isSitting == 1) GSObj->SelectIndex(3);
		else if (isJumping == 1) {
			this->fY += fVy;
			fVy = fVy - 1;
			GSObj->SelectIndex(3);
			if (fVy <= 0) {
				GSObj->SelectIndex(0);
				if (fY < 219) {
					fY = 219;
					isJumping = 0;
					this->StandUp();
				}
			}
		}
		else {
			iJump = 0;
			GSObj->SelectIndex(0);
		}
	}
}
void CSamus::Draw(GCamera *camera) {
	D3DXVECTOR2 pos = camera->Transform(this->fX, this->fY);
	if (getstate() == 1) GSObj->Draw(pos.x, pos.y); //di qua phai
	if (getstate() == -1) GSObj->DrawFlipX(pos.x, pos.y); // di qua trai
}
CSamus::~CSamus()
{
}
