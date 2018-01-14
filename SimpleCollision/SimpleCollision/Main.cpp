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
		Box hit;
		Box foot;
		Move move;
		float jump;
		float fall;
	};
	Sound sound;
	sound.SetSE("./resource/Sound/slashing01.ogg");
	sound.SetSE("./resource/Sound/slashing02.ogg");
	Obj me;
	me.hit.color.SetRBG();
	me.hit.color.SetDelta();
	me.jump = -10;
	me.fall = 0;
	me.hit.SetBox(50, 50, 100, 100, 1, Rainbow);
	Circle ball(300,0,30,Blue);
	Easing e;
	Box box(0,500,1280,120,1,Pink);
	Line line(300, 340, 700, 340, Cyan);
	Line line2(300, 240, 700, 240, Cyan);
	while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0)
	{
		me.foot.SetBox(me.hit.x, me.hit.y + me.hit.w, me.hit.w, Cyan);
		me.move.InputArrowLR(me.hit.x,5);
		if (MATH::BoxCollision(me.foot, box) == true)
		{
			me.fall = 0.0f;
		}
		else
		{
			me.fall += MATH::Gravity(32) * 3;	
		}
		if (Key(KEY_INPUT_Z) == 1) 
		{
			sound.PlaySE(1);
			if (MATH::BoxCollision(me.foot, box) == true)
			{
				me.fall = me.jump;
			
			}
		}
		if (Key(KEY_INPUT_X) == 1)
		{
			sound.DeleteSE();
		}
		
		sound.PrintID();
		me.hit.y += me.fall;
		me.hit.color.SetColor(11);
		me.hit.My_DrawBox();
		me.foot.My_DrawBox();
		box.My_DrawBox();

		if (MATH::CircleAndBoxCollision(ball, me.hit) == false)
		ball.pos.y = e.bounce.Out(e.Time(14), 0, 470, 14);
		if(MATH::CirecleAndLineCollision(ball,line) == false)
		line.My_DrawLine();
		if (MATH::CirecleAndLineCollision(ball, line2) == false)
		line2.My_DrawLine();
		ball.My_DrawCircle();
		DrawFormatString(0, 0, GetColor(255, 255, 255), "x:%.3f,y%.3f,w:%.3f,h:%.3f", me.hit.x, me.hit.y, me.hit.w, me.hit.h);
		DrawFormatString(0, 15, GetColor(255, 255, 255), "x:%.3f,y%.3f,w:%.3f,h:%.3f", me.foot.x, me.foot.y, me.foot.w, me.foot.h);
		DrawFormatString(100, 105, GetColor(255, 255, 255), "ball:%.3f", ball.pos.y);
	}

	DxLib_End();
	return 0;
}