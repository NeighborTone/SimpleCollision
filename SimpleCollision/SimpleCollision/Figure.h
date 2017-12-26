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
	int x, y, w, h,life;
	int color;									//色
	Box() : x(0), y(0), w(0), h(0),life(0) {};
	Box(int, int, int, int,int, int);				//初期化(x,y,w,h,life,color)
	bool BoxCollision(const Box&, const Box&);	
	void My_DrawBox(Box&, int&,bool);			//矩形と色と塗りつぶし(画像を使う場合は不要なメソッド)
};

class Circle
{
public:
	float r;
	float x, y;
	int color;
	Circle(float, float, float, int);			//初期化(x,y,r,color)
	void My_DrawCircle(Circle&, int&, bool);	//座標と半径と塗りつぶし(画像を使う場合は不要なメソッド)
};




















