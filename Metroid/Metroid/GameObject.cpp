#include "GameObject.h"



GameObject::GameObject()
{
	posX = 0;
	posY = 0;
	width = 0;
	height = 0;
	canMove = false;
}


GameObject::GameObject(float posX, float posY, EnumID id) {
	this->posX = posX;
	this->posY = posY;
	this->vX = 0;
	this->vY = 0;
	this->id = id;
	this->canMove = false;
	this->type = ObjectType::None_Type;
	this->CreateSrpite();
	if (this->sprite != NULL) {
		this->width = this->sprite->_texture->FrameWidth;
		this->height = this->sprite->_texture->FrameHeight;
	}
}
void GameObject::SetActive() {
	if (!active)
		active = true;
}


GameObject::~GameObject()
{
}

void GameObject::Draw(GCamera * camera) {

}
void GameObject::Update(int dt) {

}

void GameObject::ProcessInput(LPDIRECT3DDEVICE9 d3ddv, int t) {

}

void GameObject::Onkeydown(int keycode) {

}

void GameObject::CreateSrpite() {

}

void GameObject::Remove() {

}