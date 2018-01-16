#pragma once
#include "../Figure/Figure.h"

namespace MATH
{
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

class Collision
{
private:
	typedef POS Vec;
public:
	bool  BoxAndLine(const Box& box, const Line& line);									//矩形と線分
	bool  BoxAndSlope(const Box& box, const Line& line);									//矩形と線分(坂道)
	bool  BoxAndBox(const Box& box, const Box& box2);									//矩形同士
	bool  LineAndLine(const Line& line, const Line& line2);								//線分と線分
	bool  CirecleAndLine(const Circle& circle, const Line& line);					//円と線分
	bool  CircleAndSlope(const Circle& circle, const Line& line);					//円と線分(坂道)
	bool  CircleAndCircle(const Circle& circle, const Circle& circle2);			//円と円
	bool  CircleAndBox(const Circle& circle, const Box& box);							//円と矩形
	bool  CircleAndTriangle(const Circle& circle, const Triangle& tri);			//円と三角形
	bool  TriangleAndLine(const Triangle& tri, const Line& line);						//三角形と線分
};
	

