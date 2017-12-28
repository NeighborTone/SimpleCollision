#pragma once
#define _USE_MATH_DEFINES
#include "Figure.h"

namespace MATH
{

	float Radian(const float degree);
	float Gravity(const float bym);
	bool CirecleAndLineCollision(const Circle&, const Line&);			//�~�Ɛ�+++������
	bool LineCollision(const Line&, const Line&);						//�����Ɛ���
	bool CircleAndSlopeCollision(const Circle&, const Line&);			//�~�Ɛ���(�⓹)
	bool BoxAndSlopeCollision(const Box&, const Line&);					//��`�Ɛ���(�⓹)
	bool BoxCollision(const Box&, const Box&);							//��`���m
	bool CircleCollision(const Circle&, const Circle&);					//�~�Ɖ~
	bool CircleAndBoxCollision(const Circle&, const Box&);				//�~�Ƌ�`
	bool CircleAndTriangleCollision(const Circle&, const Triangle&);	//�~�ƎO�p�`+++������

}
