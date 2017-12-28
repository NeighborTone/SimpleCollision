#include "Figure.h"
#include "DxLib.h"

POS::POS(float _x, float _y)
{
	x = _x;
	y = _y;
}
void POS::SetPos(float _x, float _y)
{
	x = _x;
	y = _y;
}

void Color::SetColor(int _c)
{
	switch (_c)
	{
	case 0:  color = GetColor(255, 255, 255); break;	//0は白
	case 1:  color = GetColor(255, 0, 0);	  break;	//1は赤
	case 2:  color = GetColor(0, 255, 0);	  break;	//2は緑
	case 3:  color = GetColor(0, 0, 255);	  break;	//3は青
	case 4:  color = GetColor(255, 0, 255);	  break;	//4は紅紫色
	case 5:  color = GetColor(0, 255, 255);	  break;	//5は水色
	case 6:  color = GetColor(255, 255, 0);   break;	//6は黄色
	case 7:  color = GetColor(255, 145, 185); break;	//7は桃色
	case 8:  color = GetColor(100, 50, 255);  break;	//8は青紫
	case 9:  color = GetColor(50, 255, 100);  break;	//9は翠色
	case 10: color = GetColor(128, 128, 128); break;	//10は灰色
	}
}

const int Color::GetMyColor()
{
	return color;
}
//線分==================================================================================
Line::Line()
{
	p1 = float((0, 0));
	p2 = float((0, 0));
	color.SetColor((GetColor(255, 255, 255)));
}

Line::Line(POS _p1, POS _p2, int _c)
{
	p1 = _p1;
	p2 = _p2;
	color.SetColor(_c);
}
Line::Line(float _p1x, float _p1y, float _p2x, float _p2y, int _c)
{
	p1.x = _p1x;
	p1.y = _p1y;
	p2.x = _p2x;
	p2.y = _p2y;
	color.SetColor(_c);
}
void Line::SetLine(POS _p1, POS _p2, int _c)
{
	p1 = _p1;
	p2 = _p2;
	color.SetColor(_c);
}
void Line::SetLine(float _p1x, float _p1y, float _p2x, float _p2y, int _c)
{
	p1.x = _p1x;
	p1.y = _p1y;
	p2.x = _p2x;
	p2.y = _p2y;
	color.SetColor(_c);
}


void Line::My_DrawLine(Line& l)
{
	DrawLineAA(l.p1.x, l.p1.y, l.p2.x, l.p2.y, this->color.GetMyColor());
}
//矩形==================================================================================
Box::Box()
{
	x = 0,
	y = 0,
	w = 0,
	h = 0,
	life = 0, 
	color.SetColor((GetColor(255, 255, 255)));
}

Box::Box(int _x, int _y, int _w, int _h, int _l, int _c)
{
	x = _x;
	y = _y;
	w = _w;
	h = _h;
	life = _l;
	color.SetColor(_c);
}
void Box::SetBox(int _x, int _y, int _w, int _h , int _l, int _c)
{
	x = _x,
	y = _y,
	w = _w,
	h = _h,
	life = _l,
	color.SetColor(_c);
}
void Box::SetLife(int _l)
{
		life = _l;
}
void Box::Addlife(unsigned int _l)
{
	life += _l;
}
void Box::Damage(signed int _l)
{
	life -= _l;
}
int Box::GetLife()
{
	return life;
}

void Box::My_DrawBox(Box& b, bool f)
{
	DrawBox(b.x, b.y, b.x + b.w, b.y + b.h, this->color.GetMyColor(), f);
}
//=====================================================================================
//円===================================================================================
Circle::Circle()
{
	pos = float((0,0));
	r = 0;
	color.SetColor((GetColor(255, 255, 255)));
}

Circle::Circle(float _x, float _y, float _r, int _c)
{
	pos.x = _x;
	pos.y = _y;
	r = _r;
	color.SetColor(_c);
}

Circle::Circle(POS _p, float _r, int _c)
{
	pos = _p;
	r = _r;
	color.SetColor(_c);
}
void Circle::SetCircle(float _x, float _y, float _r, int _c)
{
	pos.x = _x;
	pos.y = _y;
	r = _r;
	color.SetColor(_c);
}
void Circle::SetCircle(POS _p, float _r, int _c)
{
	pos = _p;
	r = _r;
	color.SetColor(_c);
}

void Circle::My_DrawCircle(Circle& c, bool f)
{
	DrawCircleAA(c.pos.x, c.pos.y, c.r,32, this->color.GetMyColor(), f);
}
//====================================================================================
//三角形===============================================================================
Triangle::Triangle()
{
	p1 = float((0, 0));
	p2 = float((0, 0));
	p3 = float((0, 0));
	color.SetColor((GetColor(255, 255, 255)));
}

Triangle::Triangle(POS _p1, POS _p2, POS _p3, int _c)
{
	p1 = _p1;
	p2 = _p2;
	p3 = _p3;
	color.SetColor(_c);
}

void Triangle::My_DrawTriangle(Triangle& t, bool f)
{
	DrawTriangleAA(t.p1.x, t.p1.y,
				   t.p2.x, t.p2.y,
				   t.p3.x, t.p3.y,
				   this->color.GetMyColor(), f);
}
