#include "Joint.h"
#include "DxLib.h"
#include "../MyMath/MyMath.h"
void Tentacle::MoveTentacle(float x[], float y[], float tx, float ty, 
	int num_part, float v, float limit, int num_loop)
{
	float hx = x[0], hy = y[0];
	float rx = x[num_part - 1], ry = y[num_part - 1];

	// �ڕW�̕����ɐ�[�𓮂���
	hx += (tx >= hx + v ? v : (tx <= hx - v ? -v : 0));
	hy += (ty >= hy + v ? v : (ty <= hy - v ? -v : 0));

	// ��[�̈ړ��͈͂𐧌�����F
	// ��[�ƍ����Ƃ̋��������E�l�𒴂��Ă�����C
	// �ړ��\�͈͓��ɖ߂��B
	float dx = hx - rx, dy = hy - ry;
	float d = static_cast<float>(sqrt(dx*dx + dy*dy));
	if (d>limit) {
		hx = dx*limit / d + rx;
		hy = dy*limit / d + ry;
	}

	// ���ԕ����̍��W���v�Z����F
	// �אڕ����̍��W�̕��ς��Ƃ�B
	// �v�Z�͐�[���獪���Ɍ������čs���B
	// �K�v�ɉ����Čv�Z�𕡐���J��Ԃ��B
	x[0] = hx; y[0] = hy;
	for (int l = 0; l<num_loop; l++) {
		for (int i = 1; i<num_part - 1; i++) {
			x[i] = (x[i - 1] + x[i + 1]) / 2;
			y[i] = (y[i - 1] + y[i + 1]) / 2;
		}
	}

}

void Tentacle::MoveJoint(int num_joint, float x[], float y[], float rad[], float vrad, float lrad ,float dist, POS t)
{
	int i;
	float c, s;
	 //�O������
	//��[���獪���Ɍ������Ċp�x�����߂�

	c = (float)cos(vrad);
	s = (float)sin(vrad);
	for (i = 1; i < num_joint; ++i)
	{
		POS dt;	//�֐߂���ڕW�̃x�N�g��
		POS dn;	//�֐߂����[�ւ̃x�N�g��
		POS dr(0, 0);	//�E����̃x�N�g��
		POS dl(0,0);//�����̃x�N�g��
		float dpn, dpr, dpl; //����

		//�֐߂���ڕW�ւ̃x�N�g��
		dt.SetPos(t.x - x[i], t.y - y[i]);

		//�֐߂����[�ւ̃x�N�g���Ɠ���
		dn.SetPos(x[0] - x[i], y[0] - y[i]);
		dpn = MATH::Dot2D(dt, dn);

		//�E���
		//���E�𒴂������]���Ȃ�
		if (rad[i] + vrad <= lrad)
		{
			dr.SetPos(c*dn.x - s*dn.y,
						   s*dn.x + c*dn.y);
			dpr = MATH::Dot2D(dt, dr);
		}
		else
		{
			dpr = dpn;
		}

		//�����
		if (rad[i] - vrad >= -lrad)
		{
			dl.SetPos(c*dn.x + s*dn.y,
						   -s*dn.x + c*dn.y);
			dpl = MATH::Dot2D(dt, dl);
		}
		else
		{
			dpl = dpn;
		}

		//��]�����̑I��
		//���ς̔�r����3��������I��
		//��[����]�����V�����ʒu�����߂�
		if (dpr > dpn&&dpr > dpl)
		{
			rad[i] += vrad;
			x[0] = x[i] + dr.x;
			y[0] = y[i] + dr.y;
		}
		if (dpl > dpn&&dpl > dpr)
		{
			rad[i] -= vrad;
			x[0] = x[i] + dl.x;
			y[0] = y[i] + dl.y;
		}
	}

	//�㔼����
	//���������[�Ɍ������Ċ֐߂̈ʒu������
	float px = dist, py = 0;
	POS q;
	for (i = num_joint - 2; i >= 0; --i)
	{
		c = (float)cos(rad[i + 1]);
		s = (float)sin(rad[i + 1]);
		q.SetPos(c*px - s*py,
					  s*px + c + py);
		x[i] = x[i + 1] + q.x;
		y[i] = y[i + 1] + q.y;
		px = q.x;
		py = q.y;
	}
}