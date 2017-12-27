#include "Collision.h"
#include <math.h>
bool CircleAndBoxCollision(const Circle& c, const Box& b)
{
	if (c.pos.x + c.r <= b.x ||
		c.pos.y + c.r <= b.y ||
		b.x + b.w <= c.pos.x - c.r ||
		b.y + b.h <= c.pos.y - c.r)
		return false;
	else
		return true;

}

bool BoxCollision(const Box& b1, const Box& b2)
{
	if (b1.x < b2.x + b2.w &&
		b2.x < b1.x + b1.w &&
		b1.y < b2.y + b2.h &&
		b2.y < b1.y + b1.h)
	{
		return true;
	}
	return false;
}

bool CircleCollision(const Circle& c1, const Circle& c2)
{
	if (((c1.pos.x - c2.pos.x) *(c1.pos.x - c2.pos.x)) + ((c1.pos.y - c2.pos.y) * (c1.pos.y - c2.pos.y)) <= (c1.r + c2.r) * (c1.r + c2.r))
	{
		return true;
	}
	return false;
}

bool CircleAndTriangleCollision(const Circle& c, const Triangle& t)
{
	//������
	return false;
}

bool CircleAndSlopeCollision(const Circle& c, const Line& l)
{
	if((c.pos.x + c.r - l.p1.x) * (l.p2.y - l.p1.y) - (l.p2.x - l.p1.x) * (c.pos.y + c.r - l.p1.y) <= 0)
	{
		return true;
	}
	else
		return false;
}

bool BoxAndSlopeCollision(const Box& b, const Line& l)
{
	if ((b.x + b.w - l.p1.x) * (l.p2.y - l.p1.y) - (l.p2.x - l.p1.x) * (b.y + b.h - l.p1.y) <= 0)
	{
		return true;
	}
	else
		return false;
}

bool LineCollision(const Line& l1, const Line& l2)
{
	{
		const float baseX = l2.p2.x - l2.p1.x;
		const float baseY = l2.p2.y - l2.p1.y;
		const float sub1X = l1.p1.x - l2.p1.x;
		const float sub1Y = l1.p1.y - l2.p1.y;
		const float sub2X = l1.p2.x - l2.p1.x;
		const float sub2Y = l1.p2.y - l2.p1.y;

		const float bs1 = baseX * sub1Y - baseY * sub1X;
		const float bs2 = baseX * sub2Y - baseY * sub2X;
		const float re = bs1 * bs2;
		if (re > 0) 
		{
			return false;
		}
	}
	{
		const float baseX = l1.p2.x - l1.p1.x;
		const float baseY = l1.p2.y - l1.p1.y;
		const float sub1X = l2.p1.x - l1.p1.x;
		const float sub1Y = l2.p1.y - l1.p1.y;
		const float sub2X = l2.p2.x - l1.p1.x;
		const float sub2Y = l2.p2.y - l1.p1.y;

		const float bs1 = baseX * sub1Y - baseY * sub1X;
		const float bs2 = baseX * sub2Y - baseY * sub2X;
		const float re = bs1 * bs2;
		if (re > 0)
		{
			return false;
		}
	}
	return true;
}

bool CirecleAndLineCollision(const Circle& c, const Line& l)
{
	l.p1;//�n�_
	l.p2;//�I�_
	const POS S = l.p2 - l.p1;
	const POS A = c.pos - l.p1;
	


	return false;
}


//BOOL CollisionLC(Line L, Circle C) {
//	// �~�Ɛ����̓����蔻��֐�
//	if ((L.sx*(C.x - L.x) + L.sy*(C.y - L.y)) <= 0) {
//		// �n�_��ʂ餐����ɐ����Ȑ���u�����Ƃ���~�̒��S�������͈̔͊O�ɂ������Ƃ�
//		return (C.r*C.r >= (C.x - L.x)*(C.x - L.x) + (C.y - L.y)*(C.y - L.y));   // ������̎n�_����~�̒��S�܂ł̋����̂Q�棂Ƣ�~�̔��a�̂Q�棂Ƃ̔�r
//	}
//	else if (((-L.sx)*(C.x - (L.x + L.sx)) + (-L.sy)*(C.y - (L.y + L.sy))) <= 0) {
//		// �I�_��ʂ餐����ɐ����Ȑ���u�����Ƃ���~�̒��S�������͈̔͊O�ɂ������Ƃ�
//		return (C.r*C.r >= (C.x - (L.x + L.sx))*(C.x - (L.x + L.sx)) + (C.y - (L.y + L.sy))*(C.y - (L.y + L.sy)));   // ������̏I�_����~�̒��S�܂ł̋����̂Q�棂Ƣ�~�̔��a�̂Q�棂Ƃ̔�r
//	}
//	else {
//		// �����̎n�_�I�_�ɐ����������������Ƃ���~�̒��S�����͈͓̔��ɂ������Ƃ�
//		float e = sqrt(L.sx*L.sx + L.sy*L.sy);   // �����x,y����������ΒP�x�N�g���ɂȂ�
//		float c2 = (C.x - L.x)*(C.x - L.x) + (C.y - L.y)*(C.y - L.y);
//		float b = (C.x - L.x)*(L.sx / e) + (C.y - L.y)*(L.sy / e);   // ���ςŎZ�o������וӂ̒���
//		return (C.r*C.r >= c2 - b*b);
//	}
//}