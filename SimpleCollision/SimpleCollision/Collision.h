#pragma once
#define _USE_MATH_DEFINES
#include "Figure.h"

namespace MATH
{
	float Dot2D(POS v1, POS v2);										//�x�N�g���̓��ς�Ԃ�
	float Cross2D(POS v1, POS v2);										//�x�N�g���̊O�ς�Ԃ�
	float Length(POS v);												//�x�N�g���̒�����Ԃ�
	POS   Normalize(POS v);												//�x�N�g���̐��K��
	float Radian(const float degree);									//�x���p�x�����W�A���ɕϊ�
	float Gravity(const float bym);										//�d��
	bool  CirecleAndLineCollision(const Circle&, const Line&);			//�~�Ɛ�
	bool  LineCollision(const Line&, const Line&);						//�����Ɛ���
	bool  CircleAndSlopeCollision(const Circle&, const Line&);			//�~�Ɛ���(�⓹)
	bool  BoxAndSlopeCollision(const Box&, const Line&);				//��`�Ɛ���(�⓹)
	bool  BoxCollision(const Box&, const Box&);							//��`���m
	bool  CircleCollision(const Circle&, const Circle&);				//�~�Ɖ~
	bool  CircleAndBoxCollision(const Circle&, const Box&);				//�~�Ƌ�`
	bool  CircleAndTriangleCollision(const Circle&, const Triangle&);	//�~�ƎO�p�`+++������

}
