#include "Joint.h"
#include "../MyMath/MyMath.h"
#include <array>
#include <math.h>
Joint::Node::Node()
{
	c.pos.SetPos(0, 0);
	rad = 0;
}

/**
* �֐߂̈ړ�(Inverse Kinematics)
* @param nodes    �֐�([0]����)
* @param max		�֐ߐ�[[max]
* @param vRad     �֐߂̉�]�p�x
* @param lRad     ��]�p�x�̌��E�l
* @param distance �֐ߊԂ̋���
* @param x        �ڕW���W(X)
* @param y        �ڕW���W(Y)
*/
void Joint::MoveJoints(Node nodes[], int max, float vRad, float lRad, float distance, POS p)
{
	float cosine = static_cast<float>(cos(vRad));
	float sine = static_cast<float>(sin(vRad));
	//�O���̏���(��]�p�x��ς���)
	Node nTip = nodes[max-1];	//��[�m�[�h
	//��[�ˍ��{
	for (int i = max - 1; i >= 0;--i)
	{
		Node n = nodes[i];
		//�֐߂���ڕW���W�ւ̃x�N�g���v�Z
		float dx = p.x - n.c.pos.x;
		float dy = p.y - n.c.pos.y;
		//�֐߂����[�ւ̃x�N�g���Ɠ��ς̌v�Z
		JointVector jNode;
		jNode.pos = nTip.c.pos - n.c.pos;
		jNode.Dot(dx, dy);

		//�E���̃x�N�g���̌v�Z
		JointVector jRight;
		if (n.rad + vRad <= lRad)
		{
			jRight.pos.x = cosine*jNode.pos.x - sine*jNode.pos.y;
			jRight.pos.y = sine*jNode.pos.x + cosine*jNode.pos.y;
			jRight.Dot(dx, dy);
		}
		else
		{
			//���E�𒴂����̂ŉ񂹂Ȃ�
			jRight.Dot(dx, dy);
		}

		//�����̃x�N�g���v�Z
		JointVector jLeft;
		if (n.rad - vRad >= -lRad)
		{
			jLeft.pos.x = cosine*jNode.pos.x - sine*jNode.pos.y;
			jLeft.pos.y = -sine*jNode.pos.x + cosine*jNode.pos.y;
			jLeft.Dot(dx, dy);
		}
		else
		{
			//���E�𒴂����̂ŉ񂹂Ȃ�
			jLeft.Dot(dx, dy);
		}

		//��]�����̑I��
		//���ς��r���āA��]��3�ʂ�̒�����I��
		//��[����]�����āA�V������[�ʒu�����߂�
		if (jRight.dot_n > jNode.dot_n && jRight.dot_n > jLeft.dot_n)
		{
			//�E���
			n.rad += vRad;
			nTip.c.pos = n.c.pos + jRight.pos;
		}
		if (jLeft.dot_n > jNode.dot_n && jLeft.dot_n > jRight.dot_n)
		{
			//�����
			n.rad -= vRad;
			nTip.c.pos = n.c.pos + jLeft.pos;
		}

	}
	//�㔼����(���W�����߂�)
	float px = distance;
	float py = 0;
	//���{�ː�[
	//���{�͈ړ����Ȃ�
	for (int i = 1; i < max; ++i)
	{
		Node n1 = nodes[i-1];
		Node n2 = nodes[i];
		float cosine = static_cast<float>(cos(n1.rad));
		float sine = static_cast<float>(sin(n1.rad));
		float dx = cosine * px - sine * py;
		float dy = sine * px + cosine * py;
		n2.c.pos.x = n1.c.pos.x + dx;
		n2.c.pos.y = n1.c.pos.y + dy;
		px = dx;
		py = dy;
	}
}