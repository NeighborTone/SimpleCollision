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
/*void CannonMove(Data p_, Data& c_, bool anim_, Data change_, int i, Task t_)
{
	if (p_.Y <= c_.Y)  //マウスのY座標が大砲の上に行ったら固定
	{
		p_.Y = c_.Y;
	}

	if (anim_ && c_.AnimTime < 39)  //アニメーション
	{
		++c_.AnimTime;
	}
	else
	{
		c_.AnimTime = 0;
	}

	if (t_ == Game && change.setPoint == 3 && i < 20)
	{
		if (c_.CntTime > 360)
		{
			c_.CntTime = 0;
		}
		else
		{
			++c_.CntTime;
		}
		if (i % 2)
		{
			c_.X += cos(ML::ToRadian(float(c_.CntTime))) * 2.f;
		}
		else
		{
			c_.X -= cos(ML::ToRadian(float(c_.CntTime))) * 2.f;
		}
	}

	c_.Rot = atan2(p_.Y - c_.Y, p_.X - c_.X);  //大砲の傾きを計算

	//大砲と機体の当たり判定
	if (fighter[0].hitbase.Hit(c_.hitbase) && fighter[0].onoff)
	{
		FighterHit();
	}
}
*/
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
		Circle c;
		Move move;
		Painter render;
	};
	Obj me;
	Obj you;
	Obj shimizu;
	Painter raster;
	raster.SetGraphic("resource/Graph/back.png");
	me.c.SetCircle(0, 0, 32, Cyan);
	you.c.SetCircle(1280 / 2, 720, 30, Pink);
	shimizu.c.SetCircle(0, 0, 32, Red);
	you.render.SetGraphic("resource/Graph/^^.png");
	me.render.SetGraphic("resource/Graph/^^.png");
	shimizu.render.SetGraphic("resource/Graph/^^.png");
	you.move.SetRota(100,5);
	shimizu.move.SetRota(100, 7);
	while (Processloop() == 0)
	{
		Updata_Key();
		me.move.InputArrow8(me.c.pos, 5);
		me.render.RenderRotaGraphic(me.c.pos);
		me.c.My_DrawCircle(false);
		you.move.Rotation(me.c.pos, you.c.pos);
		you.render.RenderRotaGraphic(you.c.pos);
		you.c.My_DrawCircle(false);
		shimizu.move.Rotation(you.c.pos,shimizu.c.pos);
		shimizu.render.RenderRotaGraphic(shimizu.c.pos);
		shimizu.c.My_DrawCircle(false);
		//you.render.RenderRotaGraphic(you.c.pos,atan2(me.c.pos.y - you.c.pos.y, me.c.pos.x - you.c.pos.x) + (MATH::m_pi/2));
		//raster.Raster_Scrool(1280/2,720/2,1000,300,10);
	}
	DxLib_End();
	return 0;
}

