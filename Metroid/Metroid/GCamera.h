#ifndef _CAMERA_H_
#define _CAMERA_H_

#include "Global.h"
#include "GSprite.h"

class GCamera
{
public:
	D3DXVECTOR2 viewport;		//Thiết lập tọa độ của camera	
	int _maxSize, _minSize;		//Thiết lập kích thước lớn nhất, nhỏ nhất của map

	GCamera();
	D3DXVECTOR3 CenterSprite(int x, int y);		//Tìm tọa độ center của sprite
	void UpdateCamera(int x);					//Camera di chuyển với vận tốc speed
	void UpdateCamera(float w, float h, float speed);	//Cập nhật camera
	void SetSizeMap(int _max, int _min);		//Thiết lập kích thước lớn nhất, nhỏ nhất cho map
	D3DXVECTOR2 Transform(int x, int y);		//Hàm transform, chuyển tọa độ viewport về tọa độ world
};

#endif