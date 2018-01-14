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

	bool CircleAndTriangleCollision(const Circle& c, const Triangle& t)
	{
		//������
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
		POS A = { b.x - l.p1.x, b.y - l.p1.y };				//�����̎n�_�����`�̍���_�܂ł̃x�N�g��A
		POS B = { b.x - l.p2.x, b.y - l.p2.y };				//�����̏I�_�����`�̍���_�܂ł̃x�N�g��B
		POS C = { l.p2.x - l.p1.x,l.p2.y - l.p1.y };		//�����̎n�_��������̏I�_�܂ł̃x�N�g��C
		POS D = { b.w - l.p1.x, b.h - l.p1.y };				//�����̎n�_�����`�̉E���_�܂ł̃x�N�g��D
		POS E = { b.w - l.p2.x, b.h - l.p2.y };				//�����̏I�_�����`�̉E���_�܂ł̃x�N�g��E

		//��`�̍��ォ��E���������̊Ԃɓ����Ă���
		if (Dot2D(A, C) * Dot2D(B, C) <= 0 &&
		     Dot2D(D, C) * Dot2D(E, C) <= 0)
		{
			//�x�N�g��C��P�ʃx�N�g����
			POS temp = Normalize(C);
			//�O�ςŋ������v�Z
			float dist_L = Cross2D(A, temp);
			float dist_R = Cross2D(D, temp);
			//�����ϊ�
			if (dist_L < 0) { dist_L *= -1; }
			if (dist_R < 0) { dist_R *= -1; }
			//��`�̍����Ƃ̔�r
			if(dist_L <= b.h || dist_R <= b.h)
			return true;

		}
		else
		{
			//���[�̌v�Z
			if (Length(A) <= b.h || Length(D) <= b.h)
			{
				return true;
			}
		}

		
		return false;
	}
}
