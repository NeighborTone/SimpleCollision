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
		case 1: color = GetColor(255, 0, 0); break;		//1は赤
		case 2: color = GetColor(0, 255, 0); break;		//2は青
		case 3: color = GetColor(0, 0, 255); break;		//3は緑
		case 4: color = GetColor(0, 0, 255); break;		//4は緑
		case 5: color = GetColor(0, 0, 255); break;		//5は緑
		case 6: color = GetColor(0, 0, 255); break;		//6は緑
		case 7: color = GetColor(0, 0, 255); break;		//7は緑
		case 8: color = GetColor(0, 0, 255); break;		//8は緑
		case 9: color = GetColor(0, 0, 255); break;		//9は緑
		case 0: color = GetColor(255, 255, 255); break;	//0は白
		
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
	case 1: color = GetColor(255, 0, 0); break;		//1は赤
	case 2: color = GetColor(0, 255, 0); break;		//2は青
	case 3: color = GetColor(0, 0, 255); break;		//3は緑
	case 0: color = GetColor(255, 255, 255); break;	//デフォルトは白

	}
}
void Circle::My_DrawCircle(Circle& b, int& c, bool f)
{
	c = color;
	DrawCircleAA(b.x, b.y, b.r,32, c, f);
}
