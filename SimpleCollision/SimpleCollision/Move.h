#pragma once
#include "Input.h"
#include "Figure.h"
class Move
{
private:
	float angle;
	float speed;
	float dist;
	int dir;			//�����̏��i�[�p
	enum M_Type{A,B,C};	//���A�^�C�v�ɂ���čs�����ς��
public:
	void InputArrow8(float &x, float &y, float speed);
	void InputArrow8(POS& p, float speed);
	void SetRota(float dist,float speed, float ang = 1);
	void Rotation(const POS p1, POS &p2);		//1,���S�_.2,�񂵂������̂̍��W.
};