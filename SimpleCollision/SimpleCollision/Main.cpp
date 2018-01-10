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
	Sound sound;
	sound.SetBGM("./遊戯_drone.ogg");
	sound.SetSE("./slashing01.ogg");
	sound.SetSE("./slashing02.ogg");
	sound.SetSE("./slashing01.ogg");
	struct Obj
	{
		Circle center;
		Circle rota;
		Move move;
	};
	Obj me;
	Circle enemy(500, 500, 40, Blue);
	Line line(0, 720, 1280, 200, Cyan);
	me.center.SetCircle(100.f,100.f,50.f,White);
	me.rota.color.SetRBG(200,150,100);
	me.rota.color.SetDelta(1,2,1);
	me.rota.SetCircle(300, 100, 50, Pink);
	me.move.SetRota(150, 5);
	while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0)
	{
		sound.SinglePlayBGM_Loop();
		me.move.InputArrow8(me.center.pos, 5);
		me.move.Rotation(me.center.pos, me.rota.pos);
		me.center.My_DrawCircle();
		me.rota.My_DrawCircle();
		if (Key(KEY_INPUT_Z) == 1)
		{
			sound.PlaySE(0);
		}
		if (Key(KEY_INPUT_X) >= 1)
		{
			sound.PlaySE(2,true);
		}
		if (Key(KEY_INPUT_V) == 1)
		{
			sound.DeleteSE();
		}
		if (CircleCollision(me.rota, enemy) == false)
		{
			enemy.My_DrawCircle();
		}
		me.rota.color.SetColor(Rainbow);
		me.rota.color.Print();
		if (CircleCollision(me.rota, enemy) == true)
		{
			sound.PlaySE(1,true);
		}
		if(MATH::CirecleAndLineCollision(me.center,line) == false)
		line.My_DrawLine();
		DrawFormatString(0, 0, GetColor(255, 255, 255), "x:%.3f\ny:%.3f", me.rota.pos.x, me.rota.pos.y);
		sound.PrintID();
	}

	DxLib_End();
	return 0;
}