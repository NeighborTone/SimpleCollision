#include "DxLib.h"
#include "../Input/Input.h"
#include "../Figure/Figure.h"
#include "../Move/Move.h"
#include "../Collision/Collision.h"
#include "../MyDxSound/My_DxSound.h"
#include "../Easing/easing.hpp"


//=====================================
//===動作確認用=========================
//=====================================

int Processloop()
{
	if (ScreenFlip() != 0) return -1;
	if (ProcessMessage() != 0) return -1;
	if (ClearDrawScreen() != 0) return -1;
	if (DxLib_IsInit() == FALSE) return -1;
	return 0;
}
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	constexpr int
	SCREEN_WIDIH = 1280,
	SCREEN_HEIGHT = 720;

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
	me.body.SetCircle(100, 0, 20, Cyan);
	Back bg;
	Easing e;
	bg.handle = LoadGraph("./resource/Graph/back.png");
	me.handle = LoadGraph("./resource/Graph/^^.png");
	while (Processloop() == 0)
	{
		Updata_Key();
		me.move.InputArrow8(me.body.pos, 5);
		if (me.move.dir == me.move.RIGHT)
			me.body.color.SetColor(Pink);
		if (me.move.dir == me.move.LEFT)
			me.body.color.SetColor(Cyan);
		if (me.move.dir == me.move.UP)
			me.body.color.SetColor(Violet);
		if (me.move.dir == me.move.DOWN)
			me.body.color.SetColor(Gray);
		bg.move.BackScroll(0,bg.pos, 720,5,bg.handle);
		me.body.My_DrawCircle();
	}

	DxLib_End();
	return 0;
}