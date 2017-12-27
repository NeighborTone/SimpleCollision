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
private:
	int life;
	int color;
public:
	int x, y, w, h;
	Box();
	Box(int, int, int, int,int, int);						//������(x,y,w,h,life,color)
	void SetLife(int);										//�̗͂��Z�b�g
	void Addlife(unsigned int);								//�̗͂𑝂₷
	void Damage(signed int);								//�̗͂����炷
	int  GetLife();											//�̗͂��m�F����
	int  GetColorFromCode(int);								//�F�̏��𓾂�
	void SetBoxColor(int);									//������F���Z�b�g(0~9)
	void My_DrawBox(Box&,bool);								//�C���X�^���X�Ɠh��Ԃ�
};
//�~�������N���X
class Circle
{
private:
	int color;
public:
	float r;
	float x, y;
	POS pos;
	Circle();
	Circle(float, float, float, int);
	Circle(POS, float, int);								//������
	int  GetColorFromCode(int);								//�F�̏��𓾂�
	void SetCircleColor(int);								//������F���Z�b�g(0~9)
	void My_DrawCircle(Circle&, bool);						//�C���X�^���X�Ɠh��Ԃ�
};
//�O�p�`�������N���X
class Triangle
{
private:
	int color;
public:
	POS p1,
		p2,
		p3;
	Triangle();
	Triangle(POS, POS, POS, int);						//3�̒��_�ƐF���w��
	int  GetColorFromCode(int);							//�F�̏��𓾂�
	void SetTriangleColor(int);							//�F���Z�b�g����(0~9)
	void My_DrawTriangle(Triangle&, bool);		        //�C���X�^���X�Ɠh��Ԃ�
};