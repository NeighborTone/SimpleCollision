#pragma once
#define _USE_MATH_DEFINES
#include <math.h>
class Easing
{
private:
	float cnt;
public:
	Easing() { cnt = 0; };
	//イージング用カウンタ
	float Time(float duration)
	{
		if (cnt <= duration)
		{
			cnt += 0.1f;
		}
		return cnt;
	}

	//t = 時間 d = 始点 c = 終点-始点 d = 経過時間
	class Linear
	{
	public:
		float None(float t, float b, float c, float d)
		{
			return c*t / d + b;
		}
		float In(float t, float b, float c, float d)
		{
			return c*t / d + b;
		}
		float Out(float t, float b, float c, float d)
		{
			return c*t / d + b;
		}
		float InOut(float t, float b, float c, float d)
		{
			return c*t / d + b;
		}
	}linear;

	class Back
	{
	public:
		float In(float t, float b, float c, float d)
		{
			float s = 1.70158f;
			float postFix = t /= d;
			return c*(postFix)*t*((s + 1)*t - s) + b;
		}
		float Out(float t, float b, float c, float d)
		{

			float s = 1.70158f;

			return c*((t = t / d - 1)*t*((s + 1)*t + s) + 1) + b;
		}
		float InOut(float t, float b, float c, float d)
		{
			float s = 1.70158f;
			if ((t /= d / 2) < 1) return c / 2 * (t*t*(((s *= (1.525f)) + 1)*t - s)) + b;
			float postFix = t -= 2;
			return c / 2 * ((postFix)*t*(((s *= (1.525f)) + 1)*t + s) + 2) + b;
		}
	}back;
	

	class Bounce
	{
	public:
		float Out(float t, float b, float c, float d)
		{

			if ((t /= d) < (1 / 2.75f))
			{
				return c*(7.5625f*t*t) + b;
			}
			else if (t < (2 / 2.75f))
			{
				float postFix = t -= (1.5f / 2.75f);
				return c*(7.5625f*(postFix)*t + .75f) + b;
			}
			else if (t < (2.5 / 2.75))
			{
				float postFix = t -= (2.25f / 2.75f);
				return c*(7.5625f*(postFix)*t + .9375f) + b;
			}
			else
			{
				float postFix = t -= (2.625f / 2.75f);
				return c*(7.5625f*(postFix)*t + .984375f) + b;
			}
		}
		float In(float t, float b, float c, float d)
		{
			return c - Out(d - t, 0, c, d) + b;
		}
		float InOut(float t, float b, float c, float d)
		{
			if (t < d / 2) return In(t * 2, 0, c, d) * .5f + b;
			else return Out(t * 2 - d, 0, c, d) * .5f + c*.5f + b;
		}
	}bounce;
	
	class Circ
	{
	public:
		float In(float t, float b, float c, float d)	//バグあり
		{
			return -c * (sqrt(1 - (t /= d)*t) - 1) + b;
		}
		float Out(float t, float b, float c, float d)
		{
			return c * sqrt(1 - (t = t / d - 1)*t) + b;
		}
		float InOut(float t, float b, float c, float d)
		{
			if ((t /= d / 2) < 1) return -c / 2 * (sqrt(1 - t*t) - 1) + b;
			return c / 2 * (sqrt(1 - t*(t -= 2)) + 1) + b;
		}
	}circ;
	
	class Cubic
	{
	public:
		float In(float t, float b, float c, float d)
		{
			return c*(t /= d)*t*t + b;
		}
		float Out(float t, float b, float c, float d)
		{
			return c*((t = t / d - 1)*t*t + 1) + b;
		}
		float InOut(float t, float b, float c, float d)
		{
			if ((t /= d / 2) < 1) return c / 2 * t*t*t + b;
			return c / 2 * ((t -= 2)*t*t + 2) + b;
		}
	}cubic;
	
	class Elastic
	{
	public:
		float In(float t, float b, float c, float d)
		{
			if (t == 0) return b;  if ((t /= d) == 1) return b + c;
			float p = d*.3f;
			float a = c;
			float s = p / 4;
			float postFix = static_cast<float>(a*pow(2, 10 * (t -= 1)));
			return -(postFix * sin((t*d - s)*(2 * static_cast<float>(M_PI)) / p)) + b;
		}

		float Out(float t, float b, float c, float d)
		{
			if (t == 0) return b;  if ((t /= d) == 1) return b + c;
			float p = d*.3f;
			float a = c;
			float s = p / 4;
			return (static_cast<float>(a*pow(2, -10 * t) * sin((t*d - s)*(2 * static_cast<float>(M_PI)) / p) + c + b));
		}

		float InOut(float t, float b, float c, float d)
		{
			if (t == 0) return b;  if ((t /= d / 2) == 2) return b + c;
			float p = d*(.3f*1.5f);
			float a = c;
			float s = p / 4;

			if (t < 1) {
				float postFix = static_cast<float>(a*pow(2, 10 * (t -= 1)));
				return -.5f*(postFix* sin((t*d - s)*(2 * static_cast<float>(M_PI)) / p)) + b;
			}
			float postFix = static_cast<float>(a*pow(2, -10 * (t -= 1)));
			return static_cast<float>(postFix * sin((t*d - s)*(2 * static_cast<float>(M_PI)) / p)*.5f + c + b);
		}
	}elastic;

	class Expo
	{
	public:
		float In(float t, float b, float c, float d)
		{
			return (t == 0) ? b : c * static_cast<float>(pow(2, 10 * (t / d - 1)) + b);
		}
		float Out(float t, float b, float c, float d)
		{
			return (t == d) ? b + c : c * (static_cast<float>(-pow(2, -10 * t / d) + 1)) + b;
		}
		float InOut(float t, float b, float c, float d)
		{
			if (t == 0) return b;
			if (t == d) return b + c;
			if ((t /= d / 2) < 1) return c / 2 * static_cast<float>(pow(2, 10 * (t - 1))) + b;
			return c / 2 * (static_cast<float>(-pow(2, -10 * --t) + 2)) + b;
		}
	}expo;
	
	class Quad
	{
	public:
		float In(float t, float b, float c, float d)
		{
			return c*(t /= d)*t + b;
		}
		float Out(float t, float b, float c, float d)
		{
			return -c *(t /= d)*(t - 2) + b;
		}
		float InOut(float t, float b, float c, float d)
		{
			if ((t /= d / 2) < 1) return ((c / 2)*(t*t)) + b;
			return -c / 2 * (((t - 2)*(--t)) - 1) + b;
		}
	}quad;

	class Quart
	{
	public:
		float In(float t, float b, float c, float d)
		{
			return c*(t /= d)*t*t*t + b;
		}
		float Out(float t, float b, float c, float d)
		{
			return -c * ((t = t / d - 1)*t*t*t - 1) + b;
		}
		float InOut(float t, float b, float c, float d)
		{
			if ((t /= d / 2) < 1) return c / 2 * t*t*t*t + b;
			return -c / 2 * ((t -= 2)*t*t*t - 2) + b;
		}
	}quart;

	class Quint
	{
	public:
		float In(float t, float b, float c, float d)
		{
			return c*(t /= d)*t*t*t*t + b;
		}
		float Out(float t, float b, float c, float d)
		{
			return c*((t = t / d - 1)*t*t*t*t + 1) + b;
		}
		float InOut(float t, float b, float c, float d)
		{
			if ((t /= d / 2) < 1) return c / 2 * t*t*t*t*t + b;
			return c / 2 * ((t -= 2)*t*t*t*t + 2) + b;
		}
	}quint;
	
	class Sine
	{
	public:
		float In(float t, float b, float c, float d)
		{
			return -c * static_cast<float>(cos(t / d * (M_PI / 2))) + c + b;
		}
		float Out(float t, float b, float c, float d)
		{
			return c * static_cast<float>(sin(t / d * (M_PI / 2))) + b;
		}

		float InOut(float t, float b, float c, float d)
		{
			return -c / 2 * static_cast<float>((cos(M_PI*t / d) - 1)) + b;
		}
	}sine;
	
};