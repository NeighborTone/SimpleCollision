#include "My_DxSound.h"

void Sound::DeleteBGM()
{
	for (unsigned int i = 0; i < BGM.size(); ++i)
	{
		DeleteSoundMem(BGM[i]);
	}
	BGM.clear();
	flag = false;
}

void Sound::DeleteSE()
{
	for (unsigned int i = 0; i < SE.size(); ++i)
	{
		DeleteSoundMem(SE[i]);

	}
	SE.clear();
	//std::vector<int>().swap(SE);		//swap技法によるメモリ開放,(古いやり方)
}

void Sound::SetBGM(const char *FileName)
{
	flag = false;
	BGM.push_back(LoadSoundMem(FileName));
}

void Sound::SetSE(const char *FileName)
{
	SE.push_back(LoadSoundMem(FileName));
}

void Sound::PlayBGM_Back(int gain)
{
	if (BGM.empty())
		return;
	if (flag == false)
	{
		ChangeVolumeSoundMem(255 * gain / 100, BGM[0]);
		PlaySoundMem(BGM[0], DX_PLAYTYPE_BACK);
		flag = true;
	}
	
}

void Sound::PlayBGM_Loop(int gain)
{
	if (BGM.empty())
		return;
	if (flag == false)
	{
		ChangeVolumeSoundMem(255 * gain / 100, BGM[0]);
		PlaySoundMem(BGM[0], DX_PLAYTYPE_LOOP);
		flag = true;
	}
}

void Sound::ChangeBGMVolume(int BGM_ID, int gain)
{
	ChangeVolumeSoundMem(255 * gain / 100, BGM[BGM_ID]);
}

void Sound::MultiPlayBGM_Loop()
{
	if (BGM.empty())
		return;
	if (flag == false)
	{
		for (unsigned int i = 0; i < BGM.size(); ++i)
		{
			PlaySoundMem(BGM[i], DX_PLAYTYPE_LOOP);
		}
		flag = true;
	}
	
}

void Sound::PlaySE(int SE_ID, bool _flag ,int gain)
{
	if (SE.empty())
		return;
	ChangeVolumeSoundMem(255 * gain / 100, SE[SE_ID]);
	if (_flag == true)
	{
		if (CheckSoundMem(SE[SE_ID]) == 0)
		{
			PlaySoundMem(SE[SE_ID], DX_PLAYTYPE_BACK);
		}
	}
	else
	{
		PlaySoundMem(SE[SE_ID], DX_PLAYTYPE_BACK);
	}
}
void Sound::PlayOneShotSE(int SE_ID, int gain)
{
	if (SE.empty())
		return;
	ChangeVolumeSoundMem(255 * gain / 100, SE[SE_ID]);
	if (seFlag == false)
	{
		PlaySoundMem(SE[SE_ID], DX_PLAYTYPE_BACK);
		seFlag = true;
	}
}
void Sound::SetOneShotSE()
{
	seFlag = true;
}
void Sound::PrintID()		//デバッグ用
{
	DrawFormatString(0, 100, GetColor(255, 255, 255), "%d", SE.size());
	DrawFormatString(0, 115, GetColor(255, 255, 255), "%d", BGM.size());
}