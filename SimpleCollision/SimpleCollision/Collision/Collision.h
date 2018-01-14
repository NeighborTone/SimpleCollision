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
	typedef Box B;
	typedef Circle C;
	typedef Line L;
	typedef Triangle T;
	typedef POS Vec;
public:
	bool  BoxAndLine(const B& box, const L& line);					//矩形と線分
	bool  BoxAndSlope(const B& box, const L& line);				//矩形と線分(坂道)
	bool  Box(const B& box, const B& box2);							//矩形同士
	bool  Line(const L& line, const L& line2);						//線分と線分
	bool  CirecleAndLine(const C& circle, const L& line);		//円と線分
	bool  CircleAndSlope(const C& circle, const L& line);		//円と線分(坂道)
	bool  Circle(const C& circle, const C& circle2);				//円と円
	bool  CircleAndBox(const C& circle, const B& box);			//円と矩形
	bool  CircleAndTriangle(const C& circle, const T& tri);		//円と三角形
	bool  TriangleAndLine(const T& tri, const L& line);			//三角形と線分
};
	

