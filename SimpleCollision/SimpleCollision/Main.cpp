#include "DxLib.h"
#include "../Input/Input.h"
#include "../Figure/Figure.h"
#include "../Move/Move.h"
#include "../Collision/Collision.h"
#include "../MyDxSound/My_DxSound.h"
#include "../Easing/easing.hpp"
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
		Triangle t;
		Move move;
	};
	Circle c(100, 400, 10, Pink);
	Obj me;
	me.t.SetTriangle(100, 0, 0, 100, 200, 100, Cyan);
	while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0)
	{
		me.move.InputArrow8(me.t.p1, 5);
		me.move.InputArrow8(me.t.p2, 5);
		me.move.InputArrow8(me.t.p3, 5);
		me.t.My_DrawTriangle();
		if(!MATH::CircleAndTriangleCollision(c,me.t))
		c.My_DrawCircle();
	}

	DxLib_End();
	return 0;
}