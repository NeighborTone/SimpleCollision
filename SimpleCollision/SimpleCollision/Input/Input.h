#pragma once
#define M_LEFT	0 	//�}�E�X��
#define M_RIGHT	1	//�}�E�X�E
/*�L�[�̓��͏�Ԃ��X�V,
  �L�[���͂�L���ɂ���ꍇ�A
  ���̊֐����X�V�����ɌĂяo��*/
void Updata_Key();

//�����̃L�[�R�[�h�̃L�[�̓��͏�Ԃ�Ԃ�
int Key(int keycode);

class Mouse_t
{
public:
	int x;
	int y;          //���W
	int WheelRotVol;//�z�C�[���̉�]��
	unsigned int Button[8];  //�{�^���̉��������
	int GetHitMouseStateAll_2(Mouse_t *Nezumi);
};
