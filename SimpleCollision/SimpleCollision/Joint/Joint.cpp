#include "Joint.h"
#include "DxLib.h"
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

