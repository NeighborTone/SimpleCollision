#pragma once
#include "Input.h"
#include "Figure.h"
class Move
{
private:
	float angle;
	float speed;
	float dist;
	int dir;			//向きの情報格納用
	enum M_Type{A,B,C};	//仮、タイプによって行動が変わる
public:
	void InputArrow8(float &x, float &y, float speed);
	void InputArrow8(POS& p, float speed);
	void SetRota(float dist,float speed, float ang = 1);
	void Rotation(const POS p1, POS &p2);		//1,中心点.2,回したい物体の座標.
};