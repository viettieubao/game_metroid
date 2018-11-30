#include "CSamus.h"
#define SAMUS_FILE "Resources\\Samus.png"
#define Samus_SPEED_X 0.2f
#define Samus_SPEED_Y 0.2f

CSamus::CSamus():Object()
{
	GTObj = new GTexture(SAMUS_FILE, 3, 1, 3);
	GSObj = new GSprite(GTObj, 25);
	fX = 0;
	fY = 0;
	this->fVx = 3;
	this->fVy = 3;
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
	this->fVx = 3;
	this->fVy = 3;
	iState = 1;
	isMoving = 0;
	isFalling = 0;
	GTObj = new GTexture(SAMUS_FILE, 24, 1, 24);
	GSObj = new GSprite(GTObj, 25);  
}

void CSamus::Run(int t,GCamera *camera) {
	
	if (isMoving == 1) {
		this->GSObj->Update(t);
		if (this->isRoll == 1)
		{
			this->GSObj->_start = 5;
			this->GSObj->_end = 8;
			if (this->GSObj->GetIndex() < this->GSObj->_start || this->GSObj->GetIndex() >this->GSObj->_end) {
				this->GSObj->SelectIndex(this->GSObj->_start);
			}
		}
		else
		{
			this->GSObj->_start = 10;
			this->GSObj->_end = 12;
			if (this->GSObj->GetIndex() < this->GSObj->_start || this->GSObj->GetIndex() > this->GSObj->_end)
				this->GSObj->SelectIndex(this->GSObj->_start);
		}
		if (iState == 1) {
			this->fX = this->fX + 8;
		}else
		if (iState == -1) {
			this->fX = this->fX - 8;
		}
	}
}
void CSamus::Roll() {
	Object::Roll();
	//khi đứng 1 chỗ trạng thái lắn
	if (isRoll == 1) {
		this->GSObj->_start = 5;
		this->GSObj->_end = 8;
		this->GSObj->Update(this->GSObj->_timeAni);
	}else
	// nhảy cuộn tròn 
	if (this->isRoll == 1 && this->isMoving == 1 && this->isJumping==1) {
		this->GSObj->_start = 1;
		this->GSObj->_end = 4;
	}
	//lăn bình thường
	else if (this->isRoll == 1 && this->isMoving == 1 && this->isJumping == 0) {
		this->GSObj->_start = 5;
		this->GSObj->_end = 8;
	}
}

void CSamus::StandUp() {
	Object::StandUp();
	if (this->isMoving == 0 && this->isRoll == 0) {
		this->GSObj->SelectIndex(9);
	}else
		if (this->isMoving == 0 && this->isRoll == 1) {
			this->Roll();
		}

	
}

void CSamus::Jump() {

	if (fY < 113) {
		fY = 113;
		isJumping = 0;
		this->StandUp();
	}
	if (isJumping == 1) {
		//fY += 7;
		fVy = 10;
		GSObj->SelectIndex(0);
		Object::Jump();
	}
	else
	{
		this->StandUp();
	}
}

void CSamus::Fall() {

}

void CSamus::Update(int t, GCamera*camera) {
	if (isAttack == 1) {
		if (isRoll == 1) {

		}
		else {

		}
	}
	else {
		if (isMoving == 1) {
			this->Run(t,camera);
		}
		
		else if ( isJumping == 1) 
		{
			
		}
		else {
			iJump = 0;
			GSObj->SelectIndex(9);
		}
	}
}
void CSamus::Draw(GCamera *camera) {
	D3DXVECTOR2 pos = camera->Transform(this->fX, this->fY);
	if (getstate() == 1) GSObj->Draw(pos.x, pos.y); //di qua phai
	if (getstate() == -1) GSObj->DrawFlipX(pos.x, pos.y); // di qua trai
	cout << this->getx() << " " << this->gety() << endl;
}
CSamus::~CSamus()
{
}
