#pragma once
#include "Input.h"
#include "Figure.h"

class Move
{
private:
	enum M_Type{A,B,C};	//���A�^�C�v�ɂ���čs�����ς��
public:
	void InputMove(POS& p,float speed);
	void LeftMove();
};