#pragma once
#include "../Input/Input.h"
#include "../Figure/Figure.h"
class Move
{
private:
	bool f_flag;
	bool j_flag;
	float jumpPow;
	float fallspeed;
	float angle;
	float speed;
	float dist;
	enum
	{
		non,
		up,
		down,
		left,
		right,
		up_right,
		up_left,
		down_right,
		down_left,

	};
	enum { portrait, sideways};		//�c�����A������
	int dir;									//�����̏��i�[�p
public:
	Move() { j_flag = false; f_flag = false; };
	void InputArrow8(float &x, float &y, float speed);			//���L�[�ňړ��ł���
	void InputArrow8(POS& p, float speed);
	void InputArrowLR(float &x, float speed);
	void InputArrowLR(POS& p, float speed);
	void InputFly(float& body_y, float pow, float fall = 0);								//1.���Ă���L�����N�^��y���W,2.���ė�,
	void InputJump(float& body_y,float pow, bool foothit,float fall = 0);				//1.�W�����v����L�����N�^��y���W,2.�W�����v��,3.�����蔻��`�F�b�N
	void SetRota(float dist,float speed, float ang = 1);										//1.����,2.����,3.��������ꍇ�̊p�x�̊Ԋu
	void Rotation(const POS p1, POS &p2);															//1,���S�_.2,�񂵂������̂̍��W
	void BackScroll(int dir,POS& start, float end, float speed, int handle);			//1.����(0�㉺,1���E),2,�X�N���[���J�n�_,3.�I���_,4.���x,5.�����������摜�̃n���h��
};