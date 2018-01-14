#include "Collision.h"
#include <math.h>
namespace MATH
{
	float Dot2D(POS v1, POS v2) 
	{				
		return v1.x * v2.x + v1.y * v2.y;
	}

	float Cross2D(POS v1, POS v2) 
	{			
		return v1.x * v2.y - v2.x * v1.y;
	}
	float Length(POS v)
	{  					
		return static_cast<float>(sqrt(v.x * v.x + v.y * v.y));
	}
	POS Normalize(POS v)
	{					
		POS temp = { v.x / Length(v),v.y / Length(v) };
		return temp;
	}
	POS Sub_vector(const POS& v1, const POS& v2)
	{
		POS ret;
		ret.x = v1.x - v2.x;
		ret.y = v1.y - v2.y;
		return ret;
	}
	float Radian(const float degree)
	{
		return degree * static_cast<float>(M_PI) / 180.f;
	}

	float Gravity(const float bym)
	{
		const float gra = 9.8f / 60 / 60;
		return gra * bym;
	}

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

	bool CircleAndSlopeCollision(const Circle& c, const Line& l)
	{
		// �����x�N�g���Ɖ~���S�ւ̃x�N�g���̊O�ςɂ�锻��
		if ((c.pos.x + c.r - l.p1.x) * (l.p2.y - l.p1.y) - (l.p2.x - l.p1.x) * (c.pos.y + c.r - l.p1.y) <= 0 &&
			!(c.pos.x <= l.p1.x) && !(c.pos.x >= l.p2.x))
		{
			return true;
		}
		else
			return false;
	}

	bool BoxAndSlopeCollision(const Box& b, const Line& l)
	{
		if ((b.x + b.w - l.p1.x) * (l.p2.y - l.p1.y) - (l.p2.x - l.p1.x) * (b.y + b.h - l.p1.y) <= 0 &&
			!(b.x + b.w <= l.p1.x) && !(b.x >= l.p2.x))
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

	bool CircleAndTriangleCollision(const Circle& c, const Triangle& t)
	{
		//�O�p�`������Ŕ���
		Line T_R(t.p1.x, t.p1.y, t.p2.x, t.p2.y);		//�ォ��E��
		Line T_L(t.p1.x, t.p1.y, t.p3.x, t.p3.y);		//�ォ�獶��
		Line L_R(t.p2.x, t.p2.y, t.p3.x, t.p3.y);		//���

		if (CirecleAndLineCollision(c, T_R))
		{
			return true;
		}
		if (CirecleAndLineCollision(c, T_L))
		{
			return true;
		}
		if (CirecleAndLineCollision(c, L_R))
		{
			return true;
		}

		//�����ɂ��邩�O�ςŔ���
		POS AB = Sub_vector(t.p3,t.p2);
		POS BP = Sub_vector(c.pos,t.p3);
		POS BC = Sub_vector(t.p1,t.p3);
		POS CP = Sub_vector(c.pos,t.p1);
		POS CA = Sub_vector(t.p2,t.p1);
		POS AP = Sub_vector(c.pos,t.p2);

		float c1 = Cross2D(AB, BP);
		float c2 = Cross2D(BC,CP);
		float c3 = Cross2D(CA, AP);

		if ((c1 >= 0 && c2 > 0 && c3 > 0) || (c1 < 0 && c2 < 0 && c3 < 0))
		{
			return true;
		}

		return false;
	}

	bool CirecleAndLineCollision(const Circle& c, const Line& l)
	{
		POS A = { c.pos.x - l.p1.x,c.pos.y - l.p1.y };	//�����̎n�_����~�̒��S�_�܂ł̃x�N�g��A
		POS B = { l.p2.x - l.p1.x,l.p2.y - l.p1.y };		//�����̎n�_��������̏I�_�܂ł̃x�N�g��B
		POS C = { c.pos.x - l.p2.x,c.pos.y - l.p2.y };	//�����̏I�_����~�̒��S�_�܂ł̃x�N�g��C

		//�~�̒��S�������̒��i�[�_�̊ԁj�ɓ����Ă���
		if (Dot2D(A, B)*Dot2D(B, C) <= 0)
		{
			//�����̃x�N�g���i�x�N�g��B�j��P�ʃx�N�g���ɕϊ�
			POS temp = Normalize(B);
			//�~�̒��S�Ɛ����̋������O�ς��g���Čv�Z
			float dist = Cross2D(A, temp);
			//�O�ς��}�C�i�X�l�������畄����ς���
			if (dist < 0) { dist *= -1; }
			//���a�Ƃ̔�r
			if (dist <= c.r)
			{
				return true;
			}
		}
		else 
		{
			//�[�_�Ƃ̋��������ꂼ��v�Z
			if (Length(A) <= c.r || Length(C) <= c.r)
			{
				return true;
			}	
		}
		return false;
	}

	bool BoxAndLineCollision(const Box& b, const Line& l)
	{
		//�l�p�`������Ŕ���
		Line L_U(b.x, b.y, b.x, b.y + b.h);						//����~����
		Line R_U(b.x + b.w, b.y, b.x + b.w, b.y + b.h);		//�E��~�E��
		Line L_D(b.x, b.y, b.x + b.w, b.y);						//����~�E��
		Line R_D(b.x, b.y + b.h, b.x + b.w, b.y + b.h);		//����~�E��
		
		if (LineCollision(L_U, l))
		{
			return true;
		}
		if (LineCollision(R_U, l))
		{
			return true;
		}
		if (LineCollision(L_D, l))
		{
			return true;
		}
		if (LineCollision(R_D, l))
		{
			return true;
		}

		


		return false;
	}
}
