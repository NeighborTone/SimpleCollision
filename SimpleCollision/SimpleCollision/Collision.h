#pragma once
#include "DxLib.h"
class POS
{
	
public:

	float x, y;
	POS(float _x, float _y);
	void SetPos(float _x, float _y);
	float GetPos();
};

class Box
{
public:
	int x, y, w, h;
	int color;
	Box(int, int, int, int, int);
	Box(const Box&);
	bool BoxCollision(const Box&);
	void My_DrawBox(Box&, int&,bool);	//‹éŒ`‚ÆF‚Æ“h‚è‚Â‚Ô‚µ
};






















