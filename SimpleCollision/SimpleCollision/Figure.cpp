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
//矩形==================================================================================
Box::Box()
{
	x = 0,
	y = 0,
	w = 0,
	h = 0,
	life = 0, 
	color = (GetColor(255, 255, 255));
}
int Box::GetColorFromCode(int _c)
{
	switch (_c)
	{
	case 0: color = GetColor(255, 255, 255); break;	//0は白
	case 1: color = GetColor(255, 0, 0);	 break;	//1は赤
	case 2: color = GetColor(0, 255, 0);	 break;	//2は緑
	case 3: color = GetColor(0, 0, 255);	 break;	//3は青
	case 4: color = GetColor(255, 0, 255);	 break;	//4は紫
	case 5: color = GetColor(0, 255, 255);	 break;	//5は水色
	case 6: color = GetColor(255, 255, 0); 	 break;	//6は黄色
	case 7: color = GetColor(255, 145, 185); break;	//7はピンク
	case 8: color = GetColor(100, 50, 255);  break;	//8は明るい青
	case 9: color = GetColor(50, 255, 100);  break;	//9は明るい緑
	}
	return color;
}
void Box::SetBoxColor(int _c)
{
	color = GetColorFromCode(_c);
}
Box::Box(int _x  ,int _y , int _w , int _h , int _l ,int _c )
{
	x = _x;
	y = _y;
	w = _w;
	h = _h;
	life = _l;
	color = GetColorFromCode(_c);
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
//====================================================================================
//円===================================================================================
Circle::Circle()
{
	x = 0;
	y = 0;
	r = 0;
	color = GetColor(255, 255, 255);
}
int Circle::GetColorFromCode(int _c)
{
	switch (_c)
	{
	case 0: color = GetColor(255, 255, 255); break;	//0は白
	case 1: color = GetColor(255, 0, 0);	 break;	//1は赤
	case 2: color = GetColor(0, 255, 0);	 break;	//2は緑
	case 3: color = GetColor(0, 0, 255);	 break;	//3は青
	case 4: color = GetColor(255, 0, 255);	 break;	//4は紫
	case 5: color = GetColor(0, 255, 255);	 break;	//5は水色
	case 6: color = GetColor(255, 255, 0); 	 break;	//6は黄色
	case 7: color = GetColor(255, 145, 185); break;	//7はピンク
	case 8: color = GetColor(100, 50, 255);  break;	//8は明るい青
	case 9: color = GetColor(50, 255, 100);  break;	//9は明るい緑
	}
	return color;
}
void Circle::SetCircleColor(int _c)
{
	color = GetColorFromCode(_c);
}
Circle::Circle(float _x, float _y, float _r, int _c)
{
	x = _x;
	y = _y;
	r = _r;
	color = GetColorFromCode(_c);
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
	if(c.x + c.r <= r.x       ||
	   c.y + c.r <= r.y       ||
	   r.x + r.w <= c.x - c.r ||
	   r.y + r.h <= c.y - c.r)
	return false;
	else
	return true;
}
void Circle::My_DrawCircle(Circle& b, int& c, bool f)
{
	c = color;
	DrawCircleAA(b.x, b.y, b.r,32, c, f);
}
//====================================================================================