#include "Joint.h"
#include "../MyMath/MyMath.h"
#include <array>
#include <math.h>
Joint::Node::Node()
{
	c.pos.SetPos(0, 0);
	rad = 0;
}

/**
* 関節の移動(Inverse Kinematics)
* @param nodes    関節([0]根元)
* @param max		関節先端[max]
* @param vRad     関節の回転角度
* @param lRad     回転角度の限界値
* @param distance 関節間の距離
* @param x        目標座標(X)
* @param y        目標座標(Y)
*/
void Joint::MoveJoints(Node nodes[], int max, float vRad, float lRad, float distance, POS p)
{
	float cosine = static_cast<float>(cos(vRad));
	float sine = static_cast<float>(sin(vRad));
	//前半の処理(回転角度を変える)
	Node nTip = nodes[max-1];	//先端ノード
	//先端⇒根本
	for (int i = max - 1; i >= 0;--i)
	{
		Node n = nodes[i];
		//関節から目標座標へのベクトル計算
		float dx = p.x - n.c.pos.x;
		float dy = p.y - n.c.pos.y;
		//関節から先端へのベクトルと内積の計算
		JointVector jNode;
		jNode.pos = nTip.c.pos - n.c.pos;
		jNode.Dot(dx, dy);

		//右回りのベクトルの計算
		JointVector jRight;
		if (n.rad + vRad <= lRad)
		{
			jRight.pos.x = cosine*jNode.pos.x - sine*jNode.pos.y;
			jRight.pos.y = sine*jNode.pos.x + cosine*jNode.pos.y;
			jRight.Dot(dx, dy);
		}
		else
		{
			//限界を超えたので回せない
			jRight.Dot(dx, dy);
		}

		//左回りのベクトル計算
		JointVector jLeft;
		if (n.rad - vRad >= -lRad)
		{
			jLeft.pos.x = cosine*jNode.pos.x - sine*jNode.pos.y;
			jLeft.pos.y = -sine*jNode.pos.x + cosine*jNode.pos.y;
			jLeft.Dot(dx, dy);
		}
		else
		{
			//限界を超えたので回せない
			jLeft.Dot(dx, dy);
		}

		//回転方向の選択
		//内積を比較して、回転を3通りの中から選ぶ
		//先端を回転させて、新しい先端位置を決める
		if (jRight.dot_n > jNode.dot_n && jRight.dot_n > jLeft.dot_n)
		{
			//右回り
			n.rad += vRad;
			nTip.c.pos = n.c.pos + jRight.pos;
		}
		if (jLeft.dot_n > jNode.dot_n && jLeft.dot_n > jRight.dot_n)
		{
			//左回り
			n.rad -= vRad;
			nTip.c.pos = n.c.pos + jLeft.pos;
		}

	}
	//後半処理(座標を決める)
	float px = distance;
	float py = 0;
	//根本⇒先端
	//根本は移動しない
	for (int i = 1; i < max; ++i)
	{
		Node n1 = nodes[i-1];
		Node n2 = nodes[i];
		float cosine = static_cast<float>(cos(n1.rad));
		float sine = static_cast<float>(sin(n1.rad));
		float dx = cosine * px - sine * py;
		float dy = sine * px + cosine * py;
		n2.c.pos.x = n1.c.pos.x + dx;
		n2.c.pos.y = n1.c.pos.y + dy;
		px = dx;
		py = dy;
	}
}