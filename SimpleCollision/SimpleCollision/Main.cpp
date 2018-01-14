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
		Triangle t;
		Move move;
	};
	Line line(100, 400, 400, 200, Green);
	Obj me;
	Collision col;

	me.t.SetTriangle(100, 0, 0, 100, 200, 100, Cyan);
	while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0)
	{
		me.move.InputArrow8(me.t.p1, 5);
		me.move.InputArrow8(me.t.p2, 5);
		me.move.InputArrow8(me.t.p3, 5);
		me.t.My_DrawTriangle();
		if (!col.TriangleAndLine(me.t, line))
		{
			line.My_DrawLine();
		}

	}

	DxLib_End();
	return 0;
}