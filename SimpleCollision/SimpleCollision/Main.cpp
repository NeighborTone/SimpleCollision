#include "DxLib.h"
#include "../Input/Input.h"
#include "../Figure/Figure.h"
#include "../Move/Move.h"
#include "../Collision/Collision.h"
#include "../MyDxSound/My_DxSound.h"
#include "../Easing/easing.hpp"
#include "../Joint/Joint.h"

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


	Joint::Node node[8];

	for (int i = 0; i < 8; ++i)
	{
		node[i].c.SetCircle(i * 20, i * 20, 10, Cyan);

	}
	Circle me(100,100,10,Red);
	Move m;
	while (Processloop() == 0)
	{
		Updata_Key();
		m.InputArrow8(me.pos, 5);
		for (int i = 0; i < 8; ++i)
		Joint::MoveJoints(node, 8, 30, 180, 10,me.pos);
		for (int i = 0; i < 8; ++i)
			node[i].c.My_DrawCircle();
		DrawFormatString(0, 0, GetColor(255, 255, 255), "%.0f", node[7].c.pos.x);
		me.My_DrawCircle();
	}

	DxLib_End();
	return 0;
}

