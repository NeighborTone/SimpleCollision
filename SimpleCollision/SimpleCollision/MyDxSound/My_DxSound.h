#pragma once
#include "DxLib.h"
#include <vector>

//DxLib�̃T�E���h�����������N���X�BID�̓��[�h��������0����U����B
class Sound
{
private:
	bool seFlag;																	//�����V���b�gSE�p
	bool flag;																		//BGM�Đ��t���O
	std::vector<int>BGM;															//BGM�f�[�^�i�[�p
	std::vector<int>SE;															//SE�f�[�^�i�[�p
public:
	int Volume;																		//���ʗp�i����܂�Ӗ��Ȃ�����...�j
	Sound() { Volume = 0;seFlag = false; };								//�R���X�g���N�^
	~Sound() {};																	//�f�X�g���N�^
	void SetSE(const char *FileName);										//��������SE���̃p�X���w�肵���[�h����B�������[�h�ł��A�z��̌��Ɋi�[�����(0~)
	void SetBGM(const char *FileName);										//BGM�̃p�X���w�肵�ă��[�h���A�Đ��t���O�𗧂Ă�
	void PlayBGM_Loop(int gain = 100);										//BGM�����[�v�Đ��B�����ɉ��ʂ��w��ł���(0~100)�f�t�H���g��100%
	void PlayBGM_Back(int gain = 100);										//BGM�����[�v�Ȃ��ōĐ��B�����ɉ��ʂ��w��ł���(0~100)�f�t�H���g��100%
	void MultiPlayBGM_Loop();													//������BGM�𓯎����[�v�Đ�����B��ɃC���^���N�e�B�u��BGM�Ɏg��
	void ChangeBGMVolume(int BGM_ID,int gain);							//�w�肵��BGM�̉��ʂ�ύX����
	void PlaySE(int SE_ID,  int gain = 100, bool flag = false);		//�������Ɋi�[���ꂽSE��ID���w�肵�Đ��A�������ɏd�����Č��ʉ���炷���ǂ����̎w��A��O�����ɉ��ʂ��w��ł���(0~100)�f�t�H���g��100%
	void PlayOneShotSE(int SE_ID, int gain = 100);						//��x����SE��炷
	void SetOneShotSE();															//�����V���b�gSE���ăZ�b�g
	void DeleteBGM();																//�i�[����BGM��������A�t���O���ăZ�b�g����
	void DeleteSE();																//�i�[����SE�����
	void PrintID();																//�i�[���Ă���ID�̐����o�͂���
};
