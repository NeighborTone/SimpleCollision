#include "Input.h"
#include "DxLib.h"


static int key[256];	//�L�[�̓��͏�Ԃ��i�[����
static int mouse[8];
						//�L�[�̓��͏�Ԃ̍X�V
void Updata_Key()
{
	char tmpKey[256];
	GetHitKeyStateAll(tmpKey);	//���݂̃L�[�̏�Ԃ��i�[
	for (int i = 0; i < 256; ++i)
	{
		if (tmpKey[i] != 0)
		{
			++key[i];
		}
		else  //������Ă��Ȃ����
		{
			key[i] = 0;
		}
	}
}
//keycode�̃L�[�̓��͏�Ԃ��擾����
int Key(int keycode)
{
	return key[keycode];	//keycode�̓��͏�Ԃ�Ԃ�
}


int Mouse_t::GetHitMouseStateAll_2(Mouse_t *Nezumi)
{
	if (GetMousePoint(&Nezumi->x, &Nezumi->y) == -1)	//�}�E�X�̈ʒu�擾
	{ 
		return -1;
	}
	int MouseInput = GetMouseInput();						//�}�E�X�̉�������Ԏ擾
	for (int i = 0; i<8; i++)										//�}�E�X�̃L�[�͍ő�8�܂Ŋm�F�o����
	{          
		if ((MouseInput & 1 << i) != 0) Nezumi->Button[i]++;   //������Ă�����J�E���g�A�b�v
		else									 Nezumi->Button[i] = 0; //������ĂȂ�������0
	}
	Nezumi->WheelRotVol = GetMouseWheelRotVol();				//�z�C�[����]�ʎ擾
	return 0;
}