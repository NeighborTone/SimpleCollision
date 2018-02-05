#include "Joint.h"


void Tentacle::SetTentacle(int num_part, float speed, float limit, int num_loop)
{

}
void Tentacle::MoveTentacle(float x[], float y[],POS& target)
{
	//��[�ƍ��{�̍��W
	float hx = x[0], hy = y[0];
	float rx = x[num_part - 1], ry = y[num_part - 1];

	//�ڕW�Ɍ������Đ�[�𓮂���
	hx += (target.x >= hx + speed ? speed : (target.x <= hx - speed ? -speed : 0));
	hy += (target.y >= hy + speed ? speed : (target.y <= hy - speed ? -speed : 0));

	//��[�̈ړ��͈͂𐧌�����
	//���E�l�𒴂�����ړ��\�͈͓��ɖ߂�
	float dx = hx - rx, dy = hy - ry;
	float d = sqrt(dx*dx + dy*dy);
	if (d > limit)
	{
		hx = dx*limit / d + rx;
		hy = dy*limit / d + ry;
	}

	//���ԕ��̍��W�v�Z
	//�אڕ����Ƃ̕��όv�Z�B��[���獪�{
	//�K�v�ɉ����ĕ�����J��Ԃ�
	x[0] = hx;y[0] = hy;
	for (int i = 0;i < num_loop; ++i)
	{
		for (int j = 1;j < num_part - 1; ++j)
		{
			x[j] = (x[j - 1] + x[j + 1]) / 2;
			y[j] = (y[j - 1] + y[j + 1]) / 2;
		}
	}
}