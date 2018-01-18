#include "MyMath.h"
#include <math.h>
namespace MATH
{
	float Dot2D(Vec v1, Vec v2)
	{
		return v1.x * v2.x + v1.y * v2.y;
	}

	float Cross2D(Vec v1, Vec v2)
	{
		return v1.x * v2.y - v2.x * v1.y;
	}
	float Length(Vec v)
	{
		return static_cast<float>(sqrt(v.x * v.x + v.y * v.y));
	}
	Vec Normalize(Vec v)
	{
		Vec temp = { v.x / Length(v),v.y / Length(v) };
		return temp;
	}
	Vec Add_Vector(const Vec& v1, const Vec& v2)
	{
		Vec ret;
		ret.x = v1.x + v2.x;
		ret.y = v1.y + v2.y;
		return ret;
	}
	Vec Sub_Vector(const Vec& v1, const Vec& v2)
	{
		Vec ret;
		ret.x = v1.x - v2.x;
		ret.y = v1.y - v2.y;
		return ret;
	}
	float Radian(const float degree)
	{
		return degree * (m_pi) / 180.f;
	}

	float Gravity(const float bym)
	{
		const float gra = 9.8f / 60 / 60;
		return gra * bym;
	}
}