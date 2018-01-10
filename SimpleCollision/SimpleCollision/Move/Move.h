#pragma once
#include "../Input/Input.h"
#include "../Figure/Figure.h"
class Move
{
private:
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
	int dir;							//向きの情報格納用
	enum M_Type{A,B,C};	//仮、タイプによって行動が変わる
public:
	void InputArrow8(float &x, float &y, float speed);			//矢印キーで移動できる
	void InputArrow8(POS& p, float speed);
	void InputArrowLR(float &x, float speed);
	void InputArrowLR(POS& p, float speed);
	void SetRota(float dist,float speed, float ang = 1);		//1.距離,2.速さ,3.複数ある場合の角度の間隔
	void Rotation(const POS p1, POS &p2);						//1,中心点.2,回したい物体の座標
};