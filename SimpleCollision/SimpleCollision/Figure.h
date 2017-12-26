#pragma once
#include "DxLib.h"
//=====================================
//====汎用的な2Dの図形を扱うクラス=======
//===2017/12/26開始====================
/*共通するもの
@座標
@色
@初期化
@色指定
@※描画はDxLibの機能に依存。画像を使う場合は不要なメソッド
*/


//色データ
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
//座標を扱うクラス
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
//線分を扱うクラス
class Line
{
public:
	POS p1, p2;
	int color;
	Line();
	Line(POS, POS, int);
	int  GetColorFromCode(int);								
	void SetLineColor(int);									
	void My_DrawLine(Line&, int&);
};
//矩形を扱うクラス
class Box
{
public:
	int x, y, w, h;
	int life;
	int color;
	Box();
	Box(int, int, int, int,int, int);						//初期化(x,y,w,h,life,color)
	int  GetColorFromCode(int);								//色の情報を得る
	void SetBoxColor(int);									//作った色をセット(0~9)
	void My_DrawBox(Box&, int&, bool);						//インスタンスと色と塗りつぶし
};
//円を扱うクラス
class Circle
{
public:
	float r;
	float x, y;
	int color;
	Circle();
	Circle(float, float, float, int);						//初期化(x,y,r,color)
	int  GetColorFromCode(int);								//色の情報を得る
	void SetCircleColor(int);								//作った色をセット(0~9)
	void My_DrawCircle(Circle&, int&, bool);				//インスタンスと色と塗りつぶし
};
//三角形を扱うクラス
class Triangle
{
public:
	POS p1,
		p2,
		p3;
	int color;
	Triangle();
	Triangle(POS, POS, POS, int);						//3つの頂点と色を指定
	int  GetColorFromCode(int);							//色の情報を得る
	void SetTriangleColor(int);							//色をセットする(0~9)
	void My_DrawTriangle(Triangle&, int&, bool);		//インスタンスと色と塗りつぶし
};