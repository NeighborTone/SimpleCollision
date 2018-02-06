#include "Joint.h"
#include "DxLib.h"
#include "../MyMath/MyMath.h"
void Tentacle::MoveTentacle(float x[], float y[], float tx, float ty, 
	int num_part, float v, float limit, int num_loop)
{
	float hx = x[0], hy = y[0];
	float rx = x[num_part - 1], ry = y[num_part - 1];

	// 目標の方向に先端を動かす
	hx += (tx >= hx + v ? v : (tx <= hx - v ? -v : 0));
	hy += (ty >= hy + v ? v : (ty <= hy - v ? -v : 0));

	// 先端の移動範囲を制限する：
	// 先端と根元との距離が限界値を超えていたら，
	// 移動可能範囲内に戻す。
	float dx = hx - rx, dy = hy - ry;
	float d = static_cast<float>(sqrt(dx*dx + dy*dy));
	if (d>limit) {
		hx = dx*limit / d + rx;
		hy = dy*limit / d + ry;
	}

	// 中間部分の座標を計算する：
	// 隣接部分の座標の平均をとる。
	// 計算は先端から根元に向かって行う。
	// 必要に応じて計算を複数回繰り返す。
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
	 //前半処理
	//先端から根元に向かって角度を決める

	c = (float)cos(vrad);
	s = (float)sin(vrad);
	for (i = 1; i < num_joint; ++i)
	{
		POS dt;	//関節から目標のベクトル
		POS dn;	//関節から先端へのベクトル
		POS dr(0, 0);	//右周りのベクトル
		POS dl(0,0);//左回りのベクトル
		float dpn, dpr, dpl; //内積

		//関節から目標へのベクトル
		dt.SetPos(t.x - x[i], t.y - y[i]);

		//関節から先端へのベクトルと内積
		dn.SetPos(x[0] - x[i], y[0] - y[i]);
		dpn = MATH::Dot2D(dt, dn);

		//右回り
		//限界を超えたら回転しない
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

		//左回り
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

		//回転方向の選択
		//内積の比較をし3方向から選ぶ
		//先端を回転させ新しい位置を決める
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

	//後半処理
	//根元から先端に向かって関節の位置を決定
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