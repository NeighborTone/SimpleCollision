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
	//未実装
	return false;
}

bool CircleAndSlopeCollision(const Circle& c, const Line& l)
{
	// 線分ベクトルと円中心へのベクトルの外積による判定
	if((c.pos.x + c.r - l.p1.x) * (l.p2.y - l.p1.y) - (l.p2.x - l.p1.x) * (c.pos.y + c.r - l.p1.y) <= 0 &&
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

//ぬわあああああああああああああああああああああああああああああ
bool CirecleAndLineCollision(const Circle& c, const Line& l)
{
	l.p1;//始点
	l.p2;//終点
	const POS P = l.p1;
	const POS Q = l.p2;
	const POS R = c.pos;
	////始点と終点の判定
	//if ((l.p1.x - c.pos.x) * (l.p1.x - c.pos.x) + (l.p1.y - c.pos.y) * (l.p1.y - c.pos.y) <= c.r * c.r ||
	//	(l.p2.x - c.pos.x) * (l.p2.x - c.pos.x) + (l.p2.y - c.pos.y) * (l.p2.y - c.pos.y) <= c.r * c.r)
	//	return true;
	//線分の判定
	if ((c.pos.x + c.r - l.p1.x) * (l.p2.y - l.p1.y) - (l.p2.x - l.p1.x) * (c.pos.y + c.r - l.p1.y) <= 0 &&
		!(c.pos.x <= l.p1.x) && !(c.pos.x >= l.p2.x))
		return true;
	return false;
}


//BOOL CollisionLC(Line L, Circle C) {
//	// 円と線分の当たり判定関数
//	if ((L.sx*(C.x - L.x) + L.sy*(C.y - L.y)) <= 0) {
//		// 始点を通る､線分に垂直な線を置いたとき､円の中心が線分の範囲外にあったとき
//		return (C.r*C.r >= (C.x - L.x)*(C.x - L.x) + (C.y - L.y)*(C.y - L.y));   // ｢線分の始点から円の中心までの距離の２乗｣と｢円の半径の２乗｣との比較
//	}
//	else if (((-L.sx)*(C.x - (L.x + L.sx)) + (-L.sy)*(C.y - (L.y + L.sy))) <= 0) {
//		// 終点を通る､線分に垂直な線を置いたとき､円の中心が線分の範囲外にあったとき
//		return (C.r*C.r >= (C.x - (L.x + L.sx))*(C.x - (L.x + L.sx)) + (C.y - (L.y + L.sy))*(C.y - (L.y + L.sy)));   // ｢線分の終点から円の中心までの距離の２乗｣と｢円の半径の２乗｣との比較
//	}
//	else {
//		// 線分の始点終点に垂線を引っ張ったとき､円の中心がその範囲内にあったとき
//		float e = sqrt(L.sx*L.sx + L.sy*L.sy);   // これでx,y成分を割れば単ベクトルになる
//		float c2 = (C.x - L.x)*(C.x - L.x) + (C.y - L.y)*(C.y - L.y);
//		float b = (C.x - L.x)*(L.sx / e) + (C.y - L.y)*(L.sy / e);   // 内積で算出した､隣辺の長さ
//		return (C.r*C.r >= c2 - b*b);
//	}
//}