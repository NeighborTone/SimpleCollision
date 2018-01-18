#include "../Figure/Figure.h"

namespace MATH
{
	constexpr float m_pi = 3.14159265358979323846f;
	typedef POS Vec;
	float Dot2D(Vec v1, Vec v2);											//�x�N�g���̓��ς�Ԃ�
	float Cross2D(Vec v1, Vec v2);										//�x�N�g���̊O�ς�Ԃ�
	float Length(Vec v);														//�x�N�g���̒�����Ԃ�
	Vec    Normalize(Vec v);												//�x�N�g���̐��K��
	Vec    Add_Vector(const Vec& v1, const Vec& v2);				//�x�N�g�������Z
	Vec    Sub_Vector(const Vec& v1, const Vec& v2);				//�x�N�g�������Z(v1 - v2)
	float Radian(const float degree);									//�x���p�x�����W�A���ɕϊ�
	float Gravity(const float bym);										//�d��
}