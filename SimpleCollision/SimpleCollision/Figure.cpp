#include "Figure.h"
#include "DxLib.h"
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
Box::Box()
{
	x = 0,
	y = 0,
	w = 0,
	h = 0,
	life = 0, 
	color = (GetColor(255, 255, 255));
}
Box::Box(int _x  ,int _y , int _w , int _h , int _l ,int _c )
{
	x = _x;
	y = _y;
	w = _w;
	h = _h;
	life = _l;
	switch (_c)
	{
		case 1: color = GetColor(255, 0, 0); break;		//1�͐�
		case 2: color = GetColor(0, 255, 0); break;		//2�͐�
		case 3: color = GetColor(0, 0, 255); break;		//3�͗�
		case 4: color = GetColor(0, 0, 255); break;		//4�͗�
		case 5: color = GetColor(0, 0, 255); break;		//5�͗�
		case 6: color = GetColor(0, 0, 255); break;		//6�͗�
		case 7: color = GetColor(0, 0, 255); break;		//7�͗�
		case 8: color = GetColor(0, 0, 255); break;		//8�͗�
		case 9: color = GetColor(0, 0, 255); break;		//9�͗�
		case 0: color = GetColor(255, 255, 255); break;	//0�͔�
		
	}


}

bool Box::BoxCollision(const Box& b1, const Box& b2)
{
	if (b1.x < b2.x + b2.w &&
		b2.x < b1.x + b1.w &&
		b1.y < b2.y + b2.h &&
		b2.y < b1.y + b1.h)
	{
		return true;
	}
	return false;
}

void Box::My_DrawBox(Box& b, int& c, bool f)
{
	c = color;
	DrawBox(b.x, b.y, b.x + b.w, b.y + b.h, c, f);
}

Circle::Circle()
{
	x = 0;
	y = 0;
	r = 0;
	color = GetColor(255, 255, 255);
}
Circle::Circle(float _x, float _y, float _r, int _c)
{
	x = _x;
	y = _y;
	r = _r;
	switch (_c)
	{
	case 1: color = GetColor(255, 0, 0); break;		//1�͐�
	case 2: color = GetColor(0, 255, 0); break;		//2�͐�
	case 3: color = GetColor(0, 0, 255); break;		//3�͗�
	case 0: color = GetColor(255, 255, 255); break;	//�f�t�H���g�͔�

	}
}
bool Circle::CircleCollision(const Circle& c1, const Circle& c2)
{
	if (((c1.x - c2.x) *(c1.x - c2.x)) + ((c1.y - c2.y) * (c1.y - c2.y)) <= (c1.r + c2.r) * (c1.r + c2.r))
	{
		return true;
	}
	return false;
}
bool Circle::CircleAndBoxCollision(const Circle& c, const Box& r)
{
	/*if ((b.x - c.x)       * (b.x - c.x)        + (b.y - c.y)       * (b.y - c.y)       < c.r * c.r ||
		(b.x + b.w - c.x) * (b.x + b.w - c.x)  + (b.y - c.y)       * (b.y - c.y)       < c.r * c.r ||
		(b.x - c.x)       * (b.x - c.x) + (b.y + b.h - c.y)        * (b.y + b.h - c.y) < c.r * c.r ||
		(b.x + b.w - c.x) * (b.x + b.w - c.x)  + (b.y + b.h - c.y) * (b.y + b.h - c.y) < c.r * c.r)*/
	if(c.x + c.r < r.x       ||
	   c.y + c.r < r.y       ||
	   r.x + r.w < c.x - c.r ||
	   r.y + r.h < c.y - c.r)
	return false;
	else
	return true;
}
void Circle::My_DrawCircle(Circle& b, int& c, bool f)
{
	c = color;
	DrawCircleAA(b.x, b.y, b.r,32, c, f);
}