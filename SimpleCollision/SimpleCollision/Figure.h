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
	int life;
	int color;
	Box();
	Box(int, int, int, int,int, int);				//������(x,y,w,h,life,color)
	int  GetColorFromCode(int);						//�����ŐF������Ă���
	void SetBoxColor(int);							//������F���Z�b�g(0~9)
	bool BoxCollision(const Box&, const Box&);		//��`���m�̔���
	void My_DrawBox(Box&, int&, bool);				//��`�ƐF�Ɠh��Ԃ�(�摜���g���ꍇ�͕s�v�ȃ��\�b�h)
};

class Circle
{
public:
	float r;
	float x, y;
	int color;
	Circle();
	Circle(float, float, float, int);						//������(x,y,r,color)
	int  GetColorFromCode(int);						//�����ŐF������Ă���
	void SetCircleColor(int);							//������F���Z�b�g(0~9)
	bool CircleCollision(const Circle&, const Circle&);		//�~�Ɖ~�̂����蔻��
	bool CircleAndBoxCollision(const Circle&, const Box&);	//�~�Ƌ�`
	void My_DrawCircle(Circle&, int&, bool);				//���W�Ɣ��a�Ɠh��Ԃ�(�摜���g���ꍇ�͕s�v�ȃ��\�b�h)
};
