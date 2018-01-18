#include "../Figure/Figure.h"

namespace MATH
{
	constexpr float m_pi = 3.14159265358979323846f;
	typedef POS Vec;
	float Dot2D(Vec v1, Vec v2);											//ベクトルの内積を返す
	float Cross2D(Vec v1, Vec v2);										//ベクトルの外積を返す
	float Length(Vec v);														//ベクトルの長さを返す
	Vec    Normalize(Vec v);												//ベクトルの正規化
	Vec    Add_Vector(const Vec& v1, const Vec& v2);				//ベクトル足し算
	Vec    Sub_Vector(const Vec& v1, const Vec& v2);				//ベクトル引き算(v1 - v2)
	float Radian(const float degree);									//度数角度をラジアンに変換
	float Gravity(const float bym);										//重力
}