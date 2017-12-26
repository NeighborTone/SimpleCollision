#include "Collision.h"
POS::POS(float _x = 0, float _y = 0)
{
	x = _x;
	y = _y;
}
void POS::SetPos(float _x = 0, float _y = 0)
{
	x = _x;
	y = _y;
}
float POS::GetPos()
{
	return x, y;
}

Box::Box(int _x = 0, int _y = 0, int _w = 0, int _h = 0, int _c = 0)
{
	x = _x;
	y = _y;
	w = _w;
	h = _h;
	if (_c == 0)
	{
		color = GetColor(255, 255, 255);	//デフォルトは白
	}
	
}
Box::Box(const Box& b)
{
	x = b.x;
	y = b.y;
	w = b.w;
	h = b.h;
	color = b.color;
}


void Box::My_DrawBox(Box& b, int& c, bool f)
{
	c = color;
	DrawBox(b.x, b.y, b.w, b.h, c, f);
}