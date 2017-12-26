#pragma once
#include "DxLib.h"
class POS
{
	
public:

	float x, y;
	POS(float _x, float _y);
	void SetPos(float _x, float _y);
	float GetPos();
};

class Box
{
public:
	int x, y, w, h;
	int color;							//�F()
	Box(int, int, int, int, int);		//������(x,y,w,h,color)
	void My_DrawBox(Box&, int&,bool);	//��`�ƐF�Ɠh��Ԃ�(�摜���g���ꍇ�͕s�v�ȃ��\�b�h)
};

class Circle
{
public:
	float r;
	float x, y;
	int color;
	Circle(float, float, float, int);			//������(x,y,r,color)
	void My_DrawCircle(Circle&, int&, bool);	//���W�Ɣ��a�Ɠh��Ԃ�(�摜���g���ꍇ�͕s�v�ȃ��\�b�h)
};




















