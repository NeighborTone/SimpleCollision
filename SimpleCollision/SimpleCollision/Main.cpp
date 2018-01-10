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
		Box hit;
		Box foot;
		Move move;
		float jump;
		float fall;
	};
	Sound sound;
	sound.SetSE("slashing01.ogg");
	sound.SetSE("slashing01.ogg");
	sound.SetSE("slashing01.ogg");
	sound.SetSE("slashing01.ogg");
	sound.SetSE("slashing01.ogg");
	Obj me;
	me.jump = -10;
	me.fall = 0;
	me.hit.SetBox(50, 50, 100, 100, 1, Cyan);
	me.foot.SetBox(me.hit.x, me.hit.y + me.hit.w, me.hit.w, 1);
	Box box(0,500,1280,120,1,Pink);
	while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0)
	{
		me.move.InputArrow8(me.hit.x,me.hit.y,5);
		if (MATH::BoxCollision(me.hit, box) == true || MATH::BoxCollision(me.hit, box) == true && MATH::BoxCollision(me.foot, box) == true)
		{
			me.fall = 0.0f;
		}
		else
		{
			me.fall += MATH::Gravity(32) * 3;	
		}
		if (Key(KEY_INPUT_Z) == 1) {
			if (MATH::BoxCollision(me.hit,box) == true || MATH::BoxCollision(me.hit, box) == true) {
				me.fall = me.jump;
				sound.PlaySE(0);
			}
		}
		if (Key(KEY_INPUT_X) == 1)
		{
			sound.DeleteSE();
		}
		sound.PrintID();
		me.hit.y += me.fall;
		me.hit.My_DrawBox();
		box.My_DrawBox();
	}

	DxLib_End();
	return 0;
}