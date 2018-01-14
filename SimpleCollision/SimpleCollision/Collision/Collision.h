#pragma once
#define _USE_MATH_DEFINES
#include "../Figure/Figure.h"

namespace MATH
{
	float Dot2D(POS v1, POS v2);														//�x�N�g���̓��ς�Ԃ�
	float Cross2D(POS v1, POS v2);													//�x�N�g���̊O�ς�Ԃ�
	float Length(POS v);																	//�x�N�g���̒�����Ԃ�
	POS    Normalize(POS v);															//�x�N�g���̐��K��
	POS    Sub_vector(const POS& v1, const POS& v2);							//�x�N�g�������Z(v1 - v2)
	float Radian(const float degree);												//�x���p�x�����W�A���ɕϊ�
	float Gravity(const float bym);													//�d��
}

class Collision
{
private:
	typedef Box B;
	typedef Circle C;
	typedef Line L;
	typedef Triangle T;
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
	

