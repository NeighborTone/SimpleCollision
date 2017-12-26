#pragma once
#include "DxLib.h"
enum ColorData
{
	White   = 0,
	Red     = 1,
	Green   = 2,
	Blue    = 3,
	Purple  = 4,
	Cyan    = 5,
	Yellow  = 6,
	Pink    = 7,
	Violet  = 8,
	Emerald = 9,
};
class POS
{
public:

	float x, y;
	POS(float _x, float _y);
	void SetPos(float _x, float _y);
	float GetPos();
	POS operator + (const POS& p) const
	{
		return POS({ x + p.x, y + p.y });
	}
	POS operator - (const POS& p) const
	{
		return POS({ x - p.x, y - p.y });
	}
	POS operator * (const POS& p) const
	{
		return POS({ x * p.x, y * p.y });
	}
	POS &operator += (const POS& p) 
	{
		x += p.x;
		y += p.y;
		return (*this);
	}
};
class Line
{
public:
	POS p1, p2;
	int color;
	Line();
	Line(POS, POS, int);
	int  GetColorFromCode(int);								
	void SetBoxColor(int);									
	void My_DrawLine(Line&, int&);
};
class Box
{
public:
	int x, y, w, h;
	int life;
	int color;
	Box();
	Box(int, int, int, int,int, int);						//������(x,y,w,h,life,color)
	int  GetColorFromCode(int);								//�����ŐF������Ă���
	void SetBoxColor(int);									//������F���Z�b�g(0~9)
	void My_DrawBox(Box&, int&, bool);						//��`�ƐF�Ɠh��Ԃ�(�摜���g���ꍇ�͕s�v�ȃ��\�b�h)
};

class Circle
{
public:
	float r;
	float x, y;
	int color;
	Circle();
	Circle(float, float, float, int);						//������(x,y,r,color)
	int  GetColorFromCode(int);								//�����ŐF������Ă���
	void SetCircleColor(int);								//������F���Z�b�g(0~9)
	void My_DrawCircle(Circle&, int&, bool);				//���W�Ɣ��a�Ɠh��Ԃ�(�摜���g���ꍇ�͕s�v�ȃ��\�b�h)
};

class Triangle
{
public:
	POS p1,
		p2,
		p3;
	int color;
	Triangle();
	Triangle(POS, POS, POS, int);
	int  GetColorFromCode(int);
	void SetCircleColor(int);
	void My_DrawTriangle(Triangle&, int&, bool);
};