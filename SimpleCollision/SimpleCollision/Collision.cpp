#include "Collision.h"

bool CircleAndBoxCollision(const Circle& c, const Box& b)
{
	if (c.x + c.r <= b.x ||
		c.y + c.r <= b.y ||
		b.x + b.w <= c.x - c.r ||
		b.y + b.h <= c.y - c.r)
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
	if (((c1.x - c2.x) *(c1.x - c2.x)) + ((c1.y - c2.y) * (c1.y - c2.y)) <= (c1.r + c2.r) * (c1.r + c2.r))
	{
		return true;
	}
	return false;
}

bool CircleAndTriangleCollision(const Circle& c, const Triangle& t)
{
	//–¢ŽÀ‘•
	return false;
}

bool CircleAndSlopeCollision(const Circle& c, const Line& l)
{
	if((c.x + c.r - l.p1.x) * (l.p2.y - l.p1.y) - (l.p2.x - l.p1.x) * (c.y + c.r - l.p1.y) <= 0)
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