#pragma once
#include "DxLib.h"
#include <vector>
//DxLib�̃T�E���h�����������N���X�BID�̓��[�h��������0����U����B
class Sound
{
private:
	bool flag;															//BGM�Đ��t���O
	std::vector<int>BGM;												//BGM�f�[�^�i�[�p
	std::vector<int>SE;													//SE�f�[�^�i�[�p
public:
	int Volume;															//���ʊi�[�p
	Sound() { Volume = 0; };											//�R���X�g���N�^
	~Sound() {};														//�f�X�g���N�^
	void SetSE(const TCHAR *FileName);									//��������SE���̃p�X���w�肵���[�h����B�������[�h�ł��A�z��̌��Ɋi�[�����(0~)
	void SetBGM(const TCHAR *FileName);									//BGM�̃p�X���w�肵�ă��[�h���A�Đ��t���O�𗧂Ă�
	void SinglePlayBGM_Loop(int gain = 100);							//BGM�����[�v�Đ��B�����ɉ��ʂ��w��ł���(0~100)�f�t�H���g��100%
	void SinglePlayBGM_Back(int gain = 100);							//BGM�����[�v�Ȃ��ōĐ��B�����ɉ��ʂ��w��ł���(0~100)�f�t�H���g��100%
	void MultiPlayBGM_Loop();											//������BGM�𓯎����[�v�Đ�����
	void ChangeBGMVolume(int BGM_ID,int gain);							//�w�肵��BGM�̉��ʂ�ύX����
	void PlaySE(int SE_ID,int gain = 100);								//�������Ɋi�[���ꂽSE��ID���w�肵�Đ��A�����ɉ��ʂ��w��ł���(0~100)�f�t�H���g��100%
	void DeleteBGM();													//�i�[����BGM��������A�t���O���ăZ�b�g����
	void DeleteSE();													//�i�[����SE�����

};
