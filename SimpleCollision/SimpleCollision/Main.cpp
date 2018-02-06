#include "DxLib.h"
#include "../Input/Input.h"
#include "../Figure/Figure.h"
#include "../Move/Move.h"
#include "../Collision/Collision.h"
#include "../MyDxSound/My_DxSound.h"
#include "../Easing/easing.hpp"
#include "../Joint/Joint.h"
#include "../MyMath/MyMath.h"
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


	const int MAX = 12;
	float x[MAX] = {0};
	float y[MAX] = {0};
	float rad[MAX];
	for(int i =0;i<MAX;++i)
		 rad[i] = MATH::Radian(10);
	x[MAX - 1] = 8;
	y[MAX - 1] = 300;
	Painter render;
	render.SetGraphic("resource/Graph/m.png");
	Tentacle tent;
	Move m;
	Circle me;
	me.SetCircle(100, 600, 20, Violet);
	while (Processloop() == 0)
	{
		Updata_Key();
		
		m.InputArrow8(me.pos.x,me.pos.y,5);
		me.My_DrawCircle();
		for (int i = 0; i < MAX;++i)
		{
		//	tent.MoveTentacle(x,y, me.pos.x,me.pos.y, MAX, 0.17f, 400, 500);
			tent.MoveJoint(MAX, x, y, rad, 0.001f, MATH::Radian(45), 10, me.pos);
			render.RenderRotaGraphic(x[i], y[i]);
		
		}
	
		DrawFormatString(0, 0, GetColor(255, 255, 255), "%.0f", x[0]);
	}
	DxLib_End();
	return 0;
}

