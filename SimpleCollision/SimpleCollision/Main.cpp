#include "DxLib.h"
#include "Input.h"
#include "Figure.h"
#include "Move.h"
#include "Collision.h"
#include "My_DxSound.h"
#include <math.h>
#include <array>

using namespace MATH;
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
		Circle c;
		Move move;
	};
	Obj my;
	Obj you;
	my.c.SetCircle(100.f,100.f,50.f,White);
	you.c.SetCircle(300, 100, 50, Pink);
	you.move.SetRota(150, 5);
	while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0)
	{
		my.move.InputArrow8(my.c.pos, 5);
		you.move.Rotation(my.c.pos, you.c.pos);
		my.c.My_DrawCircle();
		you.c.My_DrawCircle();
		DrawFormatString(0, 0, GetColor(255, 255, 255), "x:%.3f\ny:%.3f", you.c.pos.x, you.c.pos.y);
	}
	
	DxLib_End();
	return 0;
}