#pragma once
#define M_LEFT	0 	//�}�E�X��
#define M_RIGHT	1	//�}�E�X�E
#include "DxLib.h"
#include <array>
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
enum ePad
{
	left, up, right, down, shot, needle, jump, brake,
};
class Pad final
{
private:

	bool inputFlag;
	int padInput;
	const static int PAD_KEY_NUM = 16;
	std::array<int, PAD_KEY_NUM>_idArray;	//�ǂ̃{�^�����ǂ̃{�^���Ɋ��蓖�����Ă��邩����
	std::array<int, PAD_KEY_NUM>_pad;			//16�{�^���̓��͊i�[
public:
	Pad();
	~Pad() = default;
	bool PadState();
	void Update();
	int GetPad(ePad eID) const;	//eID�̃{�^���擾

};