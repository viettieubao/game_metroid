#include "CText.h"

void CText::_initialize()
{
	_localTime = 0;
	_frameRate = FRAME_RATE;
	_isDrawAnimation = true;
}

CText::CText(LPDIRECT3DDEVICE9 d3ddev_, int size_, int screenWidth_, int screenHeight_)
{
	this->_initialize();
	_fontPosition.top = 0;
	_fontPosition.left = 0;
	_fontPosition.right = screenWidth_;
	_fontPosition.bottom = screenHeight_;
	D3DXFONT_DESC FontDesc = {
		size_,
		0,
		400,
		0,
		false,
		DEFAULT_CHARSET,
		OUT_TT_PRECIS,
		CLIP_DEFAULT_PRECIS,
		DEFAULT_PITCH, "Arial" };

	//create font
	D3DXCreateFontIndirect(d3ddev_, &FontDesc, &_font);
}
CText::~CText()
{
	if (_font != NULL)
	{
		_font->Release(); //release font
		_font = NULL;
	}
}

void CText::updateAnimation()
{
	_isDrawAnimation = !_isDrawAnimation;
}

void CText::render(char* text_, float x_, float y_)
{
	_render(text_, x_, y_, D3DCOLOR_ARGB(255, 255, 255, 255));
}

void CText::render(int number_, float x_, float y_)
{
	_render((char*)to_string(number_).c_str(), x_, y_, D3DCOLOR_ARGB(255, 255, 255, 255));
}

void CText::renderAnimation(char* text_, float x_, float y_, int deltaTime_)
{
	_localTime += deltaTime_;
	if (_localTime >= 1000 / _frameRate)
	{
		_localTime = 0;
		this->updateAnimation();
	}
	if (this->_isDrawAnimation)
		_render(text_, x_, y_, D3DCOLOR_ARGB(255, 255, 255, 255));

}
void CText::renderAnimation(int number_, float x_, float y_, int deltaTime_)
{
	_localTime += deltaTime_;
	if (_localTime >= 1000 / _frameRate)
	{
		_render((char*)to_string(number_).c_str(), x_, y_, D3DCOLOR_ARGB(255, 255, 255, 255));
		_localTime = 0;
	}
}

void CText::onLost()
{
	_font->OnLostDevice();
	_font->OnResetDevice();
}

void CText::_render(char* text, float x, float y, D3DCOLOR color)
{
	_fontPosition.left = x;
	_fontPosition.top = y;
	_font->DrawText(NULL,
		text,
		-1,
		&_fontPosition,
		NULL,
		color); //draw text
}
