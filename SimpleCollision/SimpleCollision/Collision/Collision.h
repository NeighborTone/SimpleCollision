#pragma once
#define _USE_MATH_DEFINES
#include "../Figure/Figure.h"

namespace MATH
{
	float Dot2D(POS v1, POS v2);														//ベクトルの内積を返す
	float Cross2D(POS v1, POS v2);													//ベクトルの外積を返す
	float Length(POS v);																	//ベクトルの長さを返す
	POS    Normalize(POS v);															//ベクトルの正規化
	POS    Sub_vector(const POS& v1, const POS& v2);							//ベクトル引き算(v1 - v2)
	float Radian(const float degree);												//度数角度をラジアンに変換
	float Gravity(const float bym);													//重力
	bool  BoxAndLineCollision(const Box& b, const Line& l);					//矩形と線分
	bool  CirecleAndLineCollision(const Circle&, const Line&);			//円と線分
	bool  LineCollision(const Line&, const Line&);								//線分と線分
	bool  CircleAndSlopeCollision(const Circle&, const Line&);			//円と線分(坂道)
	bool  BoxAndSlopeCollision(const Box&, const Line&);					//矩形と線分(坂道)
	bool  BoxCollision(const Box&, const Box&);									//矩形同士
	bool  CircleCollision(const Circle&, const Circle&);						//円と円
	bool  CircleAndBoxCollision(const Circle&, const Box&);				//円と矩形
	bool  CircleAndTriangleCollision(const Circle&, const Triangle&);	//円と三角形(簡易)

}
