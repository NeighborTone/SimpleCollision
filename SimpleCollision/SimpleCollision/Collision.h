#pragma once
#include "Figure.h"

bool CircleAndSlopeCollision(const Circle&, const Line&);			//�~�Ɛ���(�⓹)
bool BoxAndSlopeCollision(const Box&, const Line&);					//��`�Ɛ���(�⓹)
bool BoxCollision(const Box&, const Box&);							//��`���m
bool CircleCollision(const Circle&, const Circle&);					//�~�Ɖ~
bool CircleAndBoxCollision(const Circle&, const Box&);				//�~�Ƌ�`
bool CircleAndTriangleCollision(const Circle&, const Triangle&);	//�~�ƎO�p�`