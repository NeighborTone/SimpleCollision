#pragma once
#include "DxLib.h"
//=====================================
//====�ėp�I��2D�̐}�`�������N���X=======
//===2017/12/26�J�n====================
/*���ʂ������
@���W
@�F
@������
@�F�w��
@���`���DxLib�̋@�\�Ɉˑ��B�摜���g���ꍇ�͕s�v�ȃ��\�b�h
*/


//�F�f�[�^
enum ColorData
{
	White   = 0,
	Red     = 1,
	Green   = 2,
	Blue    = 3,
	Purple  = 4,
	Cyan    = 5,
	Yellow  = 6,
	Pink    = 7,
	Violet  = 8,
	Emerald = 9,
};
//���W�������N���X
class POS
{
public:

	float x, y;
	POS(float _x, float _y);
	void SetPos(float _x, float _y);
	float GetPos();
	POS operator + (const POS& p) const
	{
		return POS({ x + p.x, y + p.y });
	}
	POS operator - (const POS& p) const
	{
		return POS({ x - p.x, y - p.y });
	}
	POS operator * (const POS& p) const
	{
		return POS({ x * p.x, y * p.y });
	}
	POS &operator += (const POS& p) 
	{
		x += p.x;
		y += p.y;
		return (*this);
	}
};
//�����������N���X
class Line
{
public:
	POS p1, p2;
	int color;
	Line();
	Line(POS, POS, int);
	int  GetColorFromCode(int);								
	void SetLineColor(int);									
	void My_DrawLine(Line&, int&);
};
//��`�������N���X
class Box
{
public:
	int x, y, w, h;
	int life;
	int color;
	Box();
	Box(int, int, int, int,int, int);						//������(x,y,w,h,life,color)
	int  GetColorFromCode(int);								//�F�̏��𓾂�
	void SetBoxColor(int);									//������F���Z�b�g(0~9)
	void My_DrawBox(Box&, int&, bool);						//�C���X�^���X�ƐF�Ɠh��Ԃ�
};
//�~�������N���X
class Circle
{
public:
	float r;
	float x, y;
	int color;
	Circle();
	Circle(float, float, float, int);						//������(x,y,r,color)
	int  GetColorFromCode(int);								//�F�̏��𓾂�
	void SetCircleColor(int);								//������F���Z�b�g(0~9)
	void My_DrawCircle(Circle&, int&, bool);				//�C���X�^���X�ƐF�Ɠh��Ԃ�
};
//�O�p�`�������N���X
class Triangle
{
public:
	POS p1,
		p2,
		p3;
	int color;
	Triangle();
	Triangle(POS, POS, POS, int);						//3�̒��_�ƐF���w��
	int  GetColorFromCode(int);							//�F�̏��𓾂�
	void SetTriangleColor(int);							//�F���Z�b�g����(0~9)
	void My_DrawTriangle(Triangle&, int&, bool);		//�C���X�^���X�ƐF�Ɠh��Ԃ�
};