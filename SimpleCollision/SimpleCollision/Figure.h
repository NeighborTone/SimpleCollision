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
	Box(int, int, int, int,int, int);						//初期化(x,y,w,h,life,color)
	int  GetColorFromCode(int);								//ここで色を作っている
	void SetBoxColor(int);									//作った色をセット(0~9)
	void My_DrawBox(Box&, int&, bool);						//矩形と色と塗りつぶし(画像を使う場合は不要なメソッド)
};

class Circle
{
public:
	float r;
	float x, y;
	int color;
	Circle();
	Circle(float, float, float, int);						//初期化(x,y,r,color)
	int  GetColorFromCode(int);								//ここで色を作っている
	void SetCircleColor(int);								//作った色をセット(0~9)
	void My_DrawCircle(Circle&, int&, bool);				//座標と半径と塗りつぶし(画像を使う場合は不要なメソッド)
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