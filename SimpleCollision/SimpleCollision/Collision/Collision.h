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
	typedef Box B;
	typedef Circle C;
	typedef Line L;
	typedef Triangle T;
	typedef POS Vec;
public:
	bool  BoxAndLine(const B& box, const L& line);					//��`�Ɛ���
	bool  BoxAndSlope(const B& box, const L& line);				//��`�Ɛ���(�⓹)
	bool  Box(const B& box, const B& box2);							//��`���m
	bool  Line(const L& line, const L& line2);						//�����Ɛ���
	bool  CirecleAndLine(const C& circle, const L& line);		//�~�Ɛ���
	bool  CircleAndSlope(const C& circle, const L& line);		//�~�Ɛ���(�⓹)
	bool  Circle(const C& circle, const C& circle2);				//�~�Ɖ~
	bool  CircleAndBox(const C& circle, const B& box);			//�~�Ƌ�`
	bool  CircleAndTriangle(const C& circle, const T& tri);		//�~�ƎO�p�`
	bool  TriangleAndLine(const T& tri, const L& line);			//�O�p�`�Ɛ���
};
	

