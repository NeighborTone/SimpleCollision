#pragma once
//=====================================
//====汎用的な2Dの図形を扱うクラス=======
//===2017/12/26開始====================
/*共通するもの
@座標
@色
@初期化
@色指定
@描画※DxLibの機能に依存。画像を使う場合は不要なメソッド
 また、DxLibを使わないときはコメント化する(あとで依存しないのを作る)
※矩形のみ座標管理にPOS型を使わない（一番使われそうな図形なので、アクセスを楽にする）
*/
#include "DxLib.h"
//色データ
enum ColorData
{
	White = 0,
	Red = 1,
	Green = 2,
	Blue = 3,
	Magenta = 4,
	Cyan = 5,
	Yellow = 6,
	Pink = 7,
	Violet = 8,
	Emerald = 9,
	Gray = 10,
	Rainbow = 11,
};
//色クラス
class Color
{
private:
	int r, g, b;
	int rDelta, gDelta, bDelta;
	int color;
public:
	Color() { };
	//レインボー用===================================
	void SetRGB(int r = 200, int g = 150, int b = 100);	//RGB値を指定
	void SetDelta(int r = 1, int g = 1, int b = 1);		//色の変化量
	//===========================================
	int  GetMyColor() const { return color; };			//カラーコードを返す
	void SetColor(int color);							//引数にカラーコードを指定
	void Print()
	{
		DrawFormatString(0, 300, GetColor(255, 255, 255), "%d  %d  %d", r, g, b);
	}
	~Color() {};
};

//座標を扱うクラス
class POS
{
public:
	float x, y;
	POS(float _x = 0, float _y = 0);
	void SetPos(float _x, float _y);
	POS operator + (const POS& p)   const { return POS({ x + p.x, y + p.y }); }
	POS operator - (const POS& p)   const { return POS({ x - p.x, y - p.y }); }
	POS operator * (const POS& p)   const { return POS({ x * p.x, y * p.y }); }
	~POS() {};


};

//線分を扱うクラス
class Line
{
public:
	Color color;
	POS		 p1,																//始点
		  		 p2;															//終点
	explicit Line();															//コンストラクタ
	explicit Line(float p1x, float p1y, float p2x, float p2y, int = White);		//コンストラクタ
	explicit Line(POS p1, POS p2, int = 0);										//コンストラクタ
	explicit Line(const Line& l);												//コピーコンストラクタ
	void SetLine(float p1x, float p1y, float p2x, float p2y, int = White);		//初期化
	void SetLine(POS p1,POS p2, int = 0);										//初期化													
	void My_DrawLine();															//描画
	~Line() {};
};
//矩形を扱うクラス
class Box
{
public:
	Color color;																					//色
	float x, y, w, h;																				//座標と大きさ
	explicit Box();																				//コンストラクタ
	explicit Box(float x, float y, float w, float h,  int = White);					//コンストラクタ
	explicit Box(const Box& b);																//コピーコンストラクタ
	void SetBox(float x, float y, float w, float h, int = White);					//初期化 
	void My_DrawBox(bool = true);															//描画、デフオルトで塗りつぶし
	Box &operator * (const float& f) { w *= f; h *= f; return (*this); }			//サイズをf倍にする
	~Box() {};
};
//円を扱うクラス
class Circle
{
public:
	float     r;																			//半径
	Color color;																		//色
	POS     pos;																			//座標
	explicit Circle();																//コンストラクタ
	explicit Circle(float x, float y, float r, int = White);				//コンストラクタ
	explicit Circle(POS pos, float r, int = White);							//コンストラクタ
	explicit Circle(const Circle& c);											//コピーコンストラクタ
	void SetCircle(float x,float y,float r,int = White);					//初期化
	void SetCircle(POS pos, float r, int = White);							//初期化
	void My_DrawCircle(bool = true);											//描画、デフオルトで塗りつぶし
	Circle &operator * (const float& f) { r *= f; return (*this); }	//サイズをf倍にする
	~Circle() {};
};
//三角形を扱うクラス(未完成)
class Triangle
{
public:
	Color color;	
	POS		 p1,																//3つの頂点
				 p2,
				 p3;
	explicit Triangle();
	explicit Triangle(float p1x, float p1y, float p2x, float p2y, float p3x, float p3y, int = White);
	explicit Triangle(POS p1, POS p2, POS p3, int = White);							
	void SetTriangle(float p1x, float p1y, float p2x, float p2y, float p3x, float p3y, int = White);
	void SetTriangle(POS p1, POS p2, POS p3, int = White);
	void My_DrawTriangle(bool = true);														
	~Triangle() {};
};