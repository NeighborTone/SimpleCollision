#include "Collision.h"

bool CircleAndBoxCollision(const Circle& c, const Box& r)
{
	if (c.x + c.r <= r.x ||
		c.y + c.r <= r.y ||
		r.x + r.w <= c.x - c.r ||
		r.y + r.h <= c.y - c.r)
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