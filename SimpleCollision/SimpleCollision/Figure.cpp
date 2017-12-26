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
//��`==================================================================================
Box::Box()
{
	x = 0,
	y = 0,
	w = 0,
	h = 0,
	life = 0, 
	color = (GetColor(255, 255, 255));
}

Box::Box(int _x, int _y, int _w, int _h, int _l, int _c)
{
	x = _x;
	y = _y;
	w = _w;
	h = _h;
	life = _l;
	color = GetColorFromCode(_c);
}

int Box::GetColorFromCode(int _c)
{
	switch (_c)
	{
	case 0: color = GetColor(255, 255, 255); break;	//0�͔�
	case 1: color = GetColor(255, 0, 0);	 break;	//1�͐�
	case 2: color = GetColor(0, 255, 0);	 break;	//2�͗�
	case 3: color = GetColor(0, 0, 255);	 break;	//3�͐�
	case 4: color = GetColor(255, 0, 255);	 break;	//4�͎�
	case 5: color = GetColor(0, 255, 255);	 break;	//5�͐��F
	case 6: color = GetColor(255, 255, 0); 	 break;	//6�͉��F
	case 7: color = GetColor(255, 145, 185); break;	//7�̓s���N
	case 8: color = GetColor(100, 50, 255);  break;	//8�͖��邢��
	case 9: color = GetColor(50, 255, 100);  break;	//9�͖��邢��
	}
	return color;
}

void Box::SetBoxColor(int _c)
{
	color = GetColorFromCode(_c);
}

void Box::My_DrawBox(Box& b, int& c, bool f)
{
	c = color;
	DrawBox(b.x, b.y, b.x + b.w, b.y + b.h, c, f);
}
//=====================================================================================
//�~===================================================================================
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
	color = GetColorFromCode(_c);
}

int Circle::GetColorFromCode(int _c)
{
	switch (_c)
	{
	case 0: color = GetColor(255, 255, 255); break;	//0�͔�
	case 1: color = GetColor(255, 0, 0);	 break;	//1�͐�
	case 2: color = GetColor(0, 255, 0);	 break;	//2�͗�
	case 3: color = GetColor(0, 0, 255);	 break;	//3�͐�
	case 4: color = GetColor(255, 0, 255);	 break;	//4�͎�
	case 5: color = GetColor(0, 255, 255);	 break;	//5�͐��F
	case 6: color = GetColor(255, 255, 0); 	 break;	//6�͉��F
	case 7: color = GetColor(255, 145, 185); break;	//7�̓s���N
	case 8: color = GetColor(100, 50, 255);  break;	//8�͖��邢��
	case 9: color = GetColor(50, 255, 100);  break;	//9�͖��邢��
	}
	return color;
}

void Circle::SetCircleColor(int _c)
{
	color = GetColorFromCode(_c);
}

void Circle::My_DrawCircle(Circle& b, int& c, bool f)
{
	c = color;
	DrawCircleAA(b.x, b.y, b.r,32, c, f);
}
//====================================================================================