#pragma once
#include "../Figure/Figure.h"

namespace MATH
{
	typedef POS Vec;
	float Dot2D(Vec v1, Vec v2);											//�x�N�g���̓��ς�Ԃ�
	float Cross2D(Vec v1, Vec v2);										//�x�N�g���̊O�ς�Ԃ�
	float Length(Vec v);														//�x�N�g���̒�����Ԃ�
	Vec    Normalize(Vec v);												//�x�N�g���̐��K��
	Vec    Add_Vector(const Vec& v1, const Vec& v2);				//�x�N�g�������Z
	Vec    Sub_Vector(const Vec& v1, const Vec& v2);				//�x�N�g�������Z(v1 - v2)
	float Radian(const float degree);									//�x���p�x�����W�A���ɕϊ�
	float Gravity(const float bym);										//�d��
}

class Collision
{
private:
	typedef POS Vec;
public:
	bool  BoxAndLine(const Box& box, const Line& line);									//��`�Ɛ���
	bool  BoxAndSlope(const Box& box, const Line& line);									//��`�Ɛ���(�⓹)
	bool  BoxAndBox(const Box& box, const Box& box2);									//��`���m
	bool  LineAndLine(const Line& line, const Line& line2);								//�����Ɛ���
	bool  CirecleAndLine(const Circle& circle, const Line& line);					//�~�Ɛ���
	bool  CircleAndSlope(const Circle& circle, const Line& line);					//�~�Ɛ���(�⓹)
	bool  CircleAndCircle(const Circle& circle, const Circle& circle2);			//�~�Ɖ~
	bool  CircleAndBox(const Circle& circle, const Box& box);							//�~�Ƌ�`
	bool  CircleAndTriangle(const Circle& circle, const Triangle& tri);			//�~�ƎO�p�`
	bool  TriangleAndLine(const Triangle& tri, const Line& line);						//�O�p�`�Ɛ���
};
	

