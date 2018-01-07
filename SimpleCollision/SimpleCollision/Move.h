#pragma once
#include "Input.h"
#include "Figure.h"

class Move
{
private:
	enum M_Type{A,B,C};	//仮、タイプによって行動が変わる
public:
	void InputMove(POS& p,float speed);
	void LeftMove();
};