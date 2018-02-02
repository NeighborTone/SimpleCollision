#include "DxLib.h"
#include "../Input/Input.h"
#include "../Figure/Figure.h"
#include "../Move/Move.h"
#include "../Collision/Collision.h"
#include "../MyDxSound/My_DxSound.h"
#include "../Easing/easing.hpp"
#include "../Joint/Joint.h"
#include "../DrawManager/Graphics.h"

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


	struct Me
	{
		Circle c;
		Move move;
		Painter render;
	}me;
	Painter raster;
	raster.SetGraphic("resource/Graph/back.png");
	me.c.SetCircle(0, 0, 32, Cyan);
	me.render.SetGraphic("resource/Graph/^^.png");
	while (Processloop() == 0)
	{
		Updata_Key();
		me.move.InputArrow8(me.c.pos, 5);
		me.render.RenderRotaGraphic(me.c.pos);
		raster.Raster_Scrool(1280/2,720/2,1000,300,10);
	}
	DxLib_End();
	return 0;
}

