#include "Joint.h"


void Tentacle::SetTentacle(int num_part, float speed, float limit, int num_loop)
{

}
void Tentacle::MoveTentacle(float x[], float y[],POS& target)
{
	//先端と根本の座標
	float hx = x[0], hy = y[0];
	float rx = x[num_part - 1], ry = y[num_part - 1];

	//目標に向かって先端を動かす
	hx += (target.x >= hx + speed ? speed : (target.x <= hx - speed ? -speed : 0));
	hy += (target.y >= hy + speed ? speed : (target.y <= hy - speed ? -speed : 0));

	//先端の移動範囲を制限する
	//限界値を超えたら移動可能範囲内に戻す
	float dx = hx - rx, dy = hy - ry;
	float d = sqrt(dx*dx + dy*dy);
	if (d > limit)
	{
		hx = dx*limit / d + rx;
		hy = dy*limit / d + ry;
	}

	//中間部の座標計算
	//隣接部分との平均計算。先端から根本
	//必要に応じて複数回繰り返す
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