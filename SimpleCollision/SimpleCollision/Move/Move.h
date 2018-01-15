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
	enum { portrait, sideways};		//縦方向、横方向
	int dir;									//向きの情報格納用
public:
	Move() { j_flag = false; f_flag = false; };
	void InputArrow8(float &x, float &y, float speed);			//矢印キーで移動できる
	void InputArrow8(POS& p, float speed);
	void InputArrowLR(float &x, float speed);
	void InputArrowLR(POS& p, float speed);
	void InputFly(float& body_y, float pow, float fall = 0);								//1.飛翔するキャラクタのy座標,2.飛翔力,
	void InputJump(float& body_y,float pow, bool foothit,float fall = 0);				//1.ジャンプするキャラクタのy座標,2.ジャンプ力,3.当たり判定チェック
	void SetRota(float dist,float speed, float ang = 1);										//1.距離,2.速さ,3.複数ある場合の角度の間隔
	void Rotation(const POS p1, POS &p2);															//1,中心点.2,回したい物体の座標
	void BackScroll(int dir,POS& start, float end, float speed, int handle);			//1.向き(0上下,1左右),2,スクロール開始点,3.終了点,4.速度,5.動かしたい画像のハンドル
};