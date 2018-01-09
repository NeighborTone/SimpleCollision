#include "My_DxSound.h"

void Sound::DeleteBGM()
{
	for (unsigned int i = 0; i < BGM.size(); ++i)
	{
		DeleteSoundMem(BGM[i]);
	}
	std::vector<int>(BGM).swap(BGM);
	flag = false;
}

void Sound::DeleteSE()
{
	for (unsigned int i = 0; i < SE.size(); ++i)
	{
		DeleteSoundMem(SE[i]);
	}
	std::vector<int>(SE).swap(SE);		//swapãZñ@Ç…ÇÊÇÈÉÅÉÇÉääJï˙
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

void Sound::SinglePlayBGM_Back(int gain)
{
	if (flag == false)
	{
		ChangeVolumeSoundMem(255 * gain / 100, BGM[0]);
		PlaySoundMem(BGM[0], DX_PLAYTYPE_BACK);
		flag = true;
	}
	
}

void Sound::SinglePlayBGM_Loop(int gain)
{
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