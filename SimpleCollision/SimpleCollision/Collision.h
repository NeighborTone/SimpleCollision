#pragma once
#include "Figure.h"

bool BoxCollision(const Box&, const Box&);				//��`���m�̔���
bool CircleCollision(const Circle&, const Circle&);		//�~�Ɖ~�̂����蔻��
bool CircleAndBoxCollision(const Circle&, const Box&);	//�~�Ƌ�`