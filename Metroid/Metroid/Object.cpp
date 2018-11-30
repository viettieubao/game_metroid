#include "Object.h"



Object::Object()
{
	this->fSpeed = 0;
	this->fX = 0;
	this->fY = 0;
	this->fW = 0;
	this->fH = 0;
	this->fVx = 0;
	this->fVy = 0;
	this->iState = 1;
	this->isMoving = 0;
}


Object::~Object()
{
	delete GSObj;
	delete GTObj;
}

void Object::MoveLeft() {
	if (isJumping == 1) {
		isMoving = 0;
		return;
	}
	this->iJump = 4;
	fVx = (isAttack == 1) ? 0 : fSpeed;
	this->isMoving = 1;
	this->iState = -1;
}

void Object::MoveRight() {
	if (isJumping == 1) {
		isMoving == 0;
		return;
	}
	this->iJump = 3;
	fVx = (isAttack == 1) ? 0 : fSpeed;
	this->isMoving = 1;
	this->iState = 1;
}
void Object::Stop() {
	this->fVx = 0;
	this->isMoving = 0;

}
void Object::Move() {
	if (this->isMoving == 1)
	{
		if (iState == -1) this->MoveLeft();
		else
			this->MoveRight();
	}
}

void Object::Roll() {
	if (this->Status == 2) {
		this->isRoll = 1;
	}
	else {
		this->isRoll = 0;
	}

}

void Object::Jump() {
	isJumping = 1;
	Status = 3;
}

void Object::StandUp() {
	Status = 1;
}

void Object::Fall() {
	isFalling = 1;
}

void Object::Attack() {
	isAttack = 1;
	switch (Status)
	{
	case 1: break;
	case 2:break;
	case 3: break;
	default:
		break;
	}
}

