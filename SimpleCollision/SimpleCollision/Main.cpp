#include "DxLib.h"
#include "../Input/Input.h"
#include "../Figure/Figure.h"
#include "../Move/Move.h"
#include "../Collision/Collision.h"
#include "../MyDxSound/My_DxSound.h"
#include "../Easing/easing.hpp"
#include <math.h>
#include <array>

//=====================================
//===����m�F�p=========================
//=====================================
constexpr int
SCREEN_WIDIH = 1280,
SCREEN_HEIGHT = 720;

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	//���O����
	SetOutApplicationLogValidFlag(FALSE);
	//�E�C���h�E�^�C�g����ύX
	SetMainWindowText("�R���W�����e�X�g");
	//��ʃT�C�Y�ύX
	SetGraphMode(SCREEN_WIDIH, SCREEN_HEIGHT, 32);
	//�E�B���h�E���[�h�ύX�Ə������Ɨ���ʐݒ�
	ChangeWindowMode(TRUE), DxLib_Init(), SetDrawScreen(DX_SCREEN_BACK);

	struct Obj
	{
		int handle;
		Circle body;
		Move move;
	};
	struct Back
	{
		int handle;
		POS pos;
		Move move;
	};
	Obj me;
	me.body.SetCircle(100, 100, 20, Cyan);
	Back bg;
	bg.handle = LoadGraph("./resource/Graph/back.png");
	me.handle = LoadGraph("./resource/Graph/^^.png");
	while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0)
	{
		Updata_Key();
		me.move.InputArrowLR(me.body.pos.x,5);
		me.move.InputFly(me.body.pos.y, -5);
		bg.move.BackScroll(0,bg.pos, 720,5,bg.handle);
		DrawRotaGraphF(me.body.pos.x, me.body.pos.y, 1.0, 0, me.handle, true);
		
		
	}

	DxLib_End();
	return 0;
}