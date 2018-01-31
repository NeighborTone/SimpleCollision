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
	Rect r;
	Move m;
	Collision coll;
	r.SetRect(0,50,50,0,100,50,50,100,Cyan);
	Obj me;
	me.body.SetCircle(100, 200, 20, Cyan);
	Back bg;
	Easing e;
	bg.handle = LoadGraph("./resource/Graph/back.png");
	me.handle = LoadGraph("./resource/Graph/^^.png");
	while (Processloop() == 0)
	{
		Updata_Key();
		m.InputArrow8(r.p1, 5);
		m.InputArrow8(r.p2, 5);
		m.InputArrow8(r.p3, 5);
		m.InputArrow8(r.p4, 5);
		r.My_DrawRect();
		bg.move.BackScroll(0,bg.pos, 720,5,bg.handle);
		if(coll.CircleAndRect(me.body,r)==false)
		me.body.My_DrawCircle();
		
	}

	DxLib_End();
	return 0;
}