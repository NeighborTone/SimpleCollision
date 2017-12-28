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

//色データ
enum ColorData
{
	White   = 0,
	Red     = 1,
	Green   = 2,
	Blue    = 3,
	Magenta = 4,
	Cyan    = 5,
	Yellow  = 6,
	Pink    = 7,
	Violet  = 8,
	Emerald = 9,
	Gray    = 10,
};
//色クラス
class Color
{
private:
	int color;
public:
	Color() {};
	const int  GetMyColor();
	void SetColor(int color);
	~Color() {};
};
//座標を扱うクラス
class POS
{
public:
	float x, y;
	POS(float _x = 0, float _y = 0);
	void SetPos(float _x, float _y);
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
	POS &operator -= (const POS& p)
	{
		x -= p.x;
		y -= p.y;
		return (*this);
	}
	~POS() {};
};

//線分を扱うクラス
class Line
{
public:
	Color color;
	POS		 p1,																//始点
		  	 p2;															    //終点
	explicit Line();															//コンストラクタ
	explicit Line(float p1x, float p1y, float p2x, float p2y, int = White);		//コンストラクタ
	explicit Line(POS p1, POS p2, int = 0);										//コンストラクタ
	void SetLine(float p1x, float p1y, float p2x, float p2y, int = White);		//初期化
	void SetLine(POS p1,POS p2, int = 0);										//初期化													
	void My_DrawLine(Line&);
	~Line() {};
};
//矩形を扱うクラス
class Box
{
private:
	int life;																	//このBoxには体力の概念があるぞ！！
public:
	Color color;
	int x, y, w, h;
	explicit Box();																//コンストラクタ
	explicit Box(int x, int y, int w, int h,int = 0, int = White);				//コンストラクタ
	void SetBox(int x,int y,int w,int h,int = 0,int = White);					//初期化 
	void SetLife(int life);														//体力をセット
	void Addlife(unsigned int life);											//体力を増やす
	void Damage(signed int damege);												//体力を減らす
	int  GetLife();																//体力を確認する
	void My_DrawBox(Box&,bool);													//インスタンスと塗りつぶし
	~Box() {};
};
//円を扱うクラス
class Circle
{
public:
	float     r;																//半径
	Color color;
	POS     pos;																//座標
	explicit Circle();															//コンストラクタ
	explicit Circle(float x, float y, float r, int = White);					//コンストラクタ
	explicit Circle(POS pos, float r, int = White);								//コンストラクタ
	void SetCircle(float x,float y,float r,int = White);						//初期化
	void SetCircle(POS pos, float r, int = White);								//初期化
	void My_DrawCircle(Circle&, bool);											//インスタンスと塗りつぶし
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
	explicit Triangle(POS p1, POS p2, POS p3, int = White);						//3つの頂点と色を指定
	void My_DrawTriangle(Triangle&, bool);										//インスタンスと塗りつぶし
	~Triangle() {};
};