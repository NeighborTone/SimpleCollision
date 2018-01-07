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
//===動作確認用=========================
//=====================================
constexpr int
SCREEN_WIDIH = 1280,
SCREEN_HEIGHT = 720;

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	//ログ消し
	SetOutApplicationLogValidFlag(FALSE);
	//ウインドウタイトルを変更
	SetMainWindowText("コリジョンテスト");
	//画面サイズ変更
	SetGraphMode(SCREEN_WIDIH, SCREEN_HEIGHT, 32);
	//ウィンドウモード変更と初期化と裏画面設定
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