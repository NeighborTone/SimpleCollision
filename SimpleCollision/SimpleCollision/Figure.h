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
private:
	POS p1,
		p2,
		p3;
	
public:
	int color;
	Triangle();
	Triangle(POS, POS, POS, int);
	int  GetColorFromCode(int);
	void SetCircleColor(int);
	void My_DrawTriangle(Triangle&, int&, bool);
};