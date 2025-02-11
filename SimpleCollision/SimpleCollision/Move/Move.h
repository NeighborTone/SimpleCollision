#pragma once
#include "../Input/Input.h"
#include "../Figure/Figure.h"
class Move
{
private:
	bool f_flag;
	bool j_flag;
	float jumpPow;
	float fallspeed;
	float angle;
	float speed;
	float dist;
	Pad pad;
	int inputDir;									//入力用の向きの情報格納用
	enum
	{
		non,
		up,
		down,
		left,
		right,
		up_right,
		up_left,
		down_right,
		down_left,

	};
	enum { Up_Down, sideways};		//縦方向、横方向
public:
	enum Dir { RIGHT, LEFT, UP, DOWN }dir;		//向きのステート 
	Move() { j_flag = false; f_flag = false; dir = RIGHT; };
	void InputArrow8(float &x, float &y, float speed);			//矢印キーで移動できる
	void InputArrow8(POS& p, float speed);
	void InputArrowLR(float &x, float speed);
	void InputArrowLR(POS& p, float speed);
	void InputFly(float& body_y, float pow, float fall = 0);										//1.飛翔するキャラクタのy座標,2.飛翔力,
	void InputJump(float& body_y,float pow, bool foothit,float fall = 0);							//1.ジャンプするキャラクタのy座標,2.ジャンプ力,3.当たり判定チェック
	void SetRota(float dist,float speed, float ang = 1);											//1.距離,2.速さ,3.複数ある場合の角度の間隔
	void Rotation(const POS p1, POS &p2);															//1,中心点.2,回したい物体の座標
	//使用非推奨
	void BackScroll(int dir,POS& start, float end, float speed, int handle);						//1.向き(0上下,1左右),2,スクロール開始点,3.終了点,4.速度,5.動かしたい画像のハンドル
	void BackScroll(int dir, float& startx, float& starty, float end, float speed, int handle);		//1.向き(0上下,1左右),2.スクロール開始点(x),3.スクロール開始点(y)4.終了点(画面サイズを想定),5.速度,6.動かしたい画像のハンドル
	//
	void CheckMoveDisp(POS& p,const int dispW,const int dispH,float help = 0);						//1.座標,2.3.画面サイズ,4.補正値
	void PadInputArrow8(POS& p, float speed);
	void SetDir(Dir);
	Dir GetDir();
};