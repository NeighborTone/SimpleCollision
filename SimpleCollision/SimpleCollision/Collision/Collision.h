#pragma once
#include "../Figure/Figure.h"

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
	

