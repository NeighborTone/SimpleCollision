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
		Box hit;
		Box foot;
		Move move;
	};

	Obj me;
	me.hit.SetBox(100, 0100, 100, 100, 1,Cyan);
	me.foot.SetBox(me.hit.x, me.hit.y + 100, me.hit.w, 1, 1, Green);
	Box box(0, 500, 1280, 500,1, Gray);
	Collision col;
	while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0)
	{
		me.foot.SetBox(me.hit.x, me.hit.y + 100, me.hit.w, 3, 1, Green);
		me.move.InputArrowLR(me.hit.x,5);
		me.move.Jump(me.hit.y, -10, col.Box(me.foot, box));
		me.hit.My_DrawBox();
		me.foot.My_DrawBox();
		box.My_DrawBox();

	}

	DxLib_End();
	return 0;
}