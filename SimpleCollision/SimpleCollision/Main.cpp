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
		Box hit;
		Box foot;
		Move move;
	};
	struct Back
	{
		int handle;
		POS pos;
		Move move;
	};
	Back bg;
	bg.handle = LoadGraph("./resource/Graph/back.png");
	Obj me;
	me.hit.SetBox(100, 0100, 100, 100, Cyan);
	me.foot.SetBox(me.hit.x, me.hit.y + 100, me.hit.w, 1,  Green);
	Box box(0, 500, 1280, 500, Gray);
	Collision col;
	Circle c;
	c.SetCircle(600, 0, 30, Violet);
	Easing ease;
	while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0)
	{
		me.foot.SetBox(me.hit.x, me.hit.y + 100, me.hit.w, 3, Green);
		me.move.InputArrowLR(me.hit.x,5);
		me.move.Jump(me.hit.y, -10, col.Box(me.foot, box));
		bg.move.BackScroll(0,bg.pos, 720,5,bg.handle);
		c.pos.y = ease.bounce.Out(ease.Time(14), 0, 470, 14);
		c.My_DrawCircle();
		me.hit.My_DrawBox();
		me.foot.My_DrawBox();
		box.My_DrawBox();
	}

	DxLib_End();
	return 0;
}