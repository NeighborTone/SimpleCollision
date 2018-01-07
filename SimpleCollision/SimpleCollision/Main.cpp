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

struct Obj
{
	Circle rota;
	float speed;
	float dist;
	float angle;
	bool flag;
	POS pos;

};
std::array<Obj, 12>cir;
Circle point;
bool f = false;
void Ini(Obj& c, float ang)
{
	c.angle = ang;
	c.dist = 100.0f;
	c.rota.color.SetColor(Cyan);
	c.rota.r = 10.f;
	c.speed = 0;
	c.flag = false;
	point.SetCircle(740.f, 245.f, 10.f, Pink);
}
void Up(Obj& c)
{
	c.angle += MATH::Radian(c.speed);
	c.rota.pos.SetPos(point.pos.x + static_cast<float>(cos(c.angle) * c.dist), point.pos.y + static_cast<float>(sin(c.angle)*c.dist));

	if (c.flag == false)
	{
		c.speed += 0.05f;
	}
	if (c.speed >= 20.f)
	{
		c.flag = true;
	}
	if (c.flag == true)
	{
		c.speed -= 0.05f;
	}
	if (c.speed <= -20.f)
	{
		c.flag = false;
	}

	if (f == false)
	{
		point.r += 0.09f;
	}
	if (point.r >= 140.f)
	{
		f = true;
	}
	if (f == true)
	{
		point.r -= 0.09f;
	}
	if (point.r <= 10.f)
	{
		f = false;
	}

	/*if (Key(KEY_INPUT_UP) >= 1) { point.pos.y -= 0.5f; }
	if (Key(KEY_INPUT_DOWN) >= 1) { point.pos.y += 0.5f; }
	if (Key(KEY_INPUT_LEFT) >= 1) { point.pos.x -= 0.5f; }
	if (Key(KEY_INPUT_RIGHT) >= 1) { point.pos.x += 0.5f; }*/

}
void Draw(Obj& c)
{
	point.My_DrawCircle(false);
	c.rota.My_DrawCircle();
}
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
	sound.SetBGM("./遊戯_Detection.ogg");
	sound.SetBGM("./遊戯_Chase.ogg");
	const int X_size = 10;
	Box box[X_size];
	for (int i = 0; i < X_size; ++i)
	{
		box[i].x = 50 * float(i);
		box[i].y = 50;
		box[i].w = 50;
		box[i].h = 50;
		box[i].SetLife(5);
		box[i].color.SetColor(i);
	}
	POS p1(0, 720), p2(1280, 400);
	POS p3(0, 600), p4(1280, 400);
	POS p5(0, 500), p6(1280, 500);
	POS p7(float(SCREEN_WIDIH / 2), 0), p8(static_cast<float>(SCREEN_WIDIH), static_cast<float>(SCREEN_HEIGHT));
	Line line(p1, p2, Blue);
	Line line2(p3, p4, Red);
	Line line3(p5, p6, Cyan);
	Line line4(p7, p8, Yellow);
	Box Bar(100, 100, 100, 100, 1, Red);
	Box Bar2(Bar);
	Bar2.color.SetColor(Green);
	Bar2 * 1.2f;
	POS cp(600, 400);
	Circle ball(cp, 20, Blue);
	Circle ball2(200, 300, 30, Green);
	POS t1(600, 100), t2(500, 300), t3(700, 300);
	Triangle tri(t1, t2, t3, Pink);
	struct My
	{
		Circle c;
		Move move;
	};
	My my;
	my.c.SetCircle(200, 200, 10, 100);

	for (int i = 0;i<12;++i)
		Ini(cir[i], MATH::Radian(i*30.f));
	int v = 0;
	int v2 = 0;
	while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0)
	{
		//Updata_Key();
		my.move.InputArrow8(my.c.pos, 5);
		my.c.My_DrawCircle();
		DrawFormatString(0, 300, GetColor(255, 255, 255), "探知%d   追跡%d", v, v2);
		if (Key(KEY_INPUT_Z) > 0 && v < 100)
		{
			v += 1;
		}
		if (Key(KEY_INPUT_X) > 0 && v2 < 100)
		{
			v2 += 1;
		}
		if (Key(KEY_INPUT_C) > 0 && v > 0)
		{
			v -= 1;
		}
		if (Key(KEY_INPUT_SPACE) > 0 && v2 > 0)
		{
			v2 -= 1;
		}
		sound.ChangeBGMVolume(1, v);
		sound.ChangeBGMVolume(2, v2);
		sound.MultiPlayBGM_Loop();

		for (int i = 0;i < 12;++i)
			Up(cir[i]);

		if (Key(KEY_INPUT_ESCAPE) >= 1)
		{
			break;
		}
		if (Key(KEY_INPUT_D) >= 1)
		{
			Bar.x += 5;
		}
		if (Key(KEY_INPUT_A) >= 1)
		{
			Bar.x -= 5;
		}
		if (Key(KEY_INPUT_W) >= 1)
		{
			Bar.y -= 5;
		}
		if (Key(KEY_INPUT_S) >= 1)
		{
			Bar.y += 5;
		}
		if (Key(KEY_INPUT_B) >= 1)
		{
			line3.p2.y -= 10;
		}
		if (Key(KEY_INPUT_V) >= 1)
		{
			line3.p2.y += 10;
		}
		if (Key(KEY_INPUT_RETURN) == 1)
		{
			for (int i = 0; i < X_size; ++i)
				box[i].Addlife(1);
		}
		for (int i = 0; i < X_size; ++i)
		{
			if (box[i].GetLife() > 0)
			{
				box[i].My_DrawBox();
			}
			for (int j = 0; j < 12; ++j)
			{
				if (CircleAndBoxCollision(ball, box[i]) == true ||
					BoxCollision(Bar, box[i]) == true ||
					CircleAndBoxCollision(cir[j].rota, box[i]) == true ||
					CircleAndBoxCollision(point, box[i]) == true)
				{
					if (box[i].GetLife() <= 0)
					{
						continue;
					}
					box[i].Damage(1);
				}
			}
		}
		if (CircleCollision(ball, ball2) == false)
		{
			ball2.My_DrawCircle();
		}
		if (CircleAndSlopeCollision(ball, line) == false)
		{
			line.My_DrawLine();
		}
		if (BoxAndSlopeCollision(Bar, line2) == false)
		{
			line2.My_DrawLine();
		}

		tri.My_DrawTriangle();

		if (LineCollision(line3, line4) == false)
		{

			line4.My_DrawLine();
		}

		if (CirecleAndLineCollision(ball, line3) == false)
		{
			line3.My_DrawLine();
		}
		for (int i = 0;i < 12;++i)
		{
			if (CircleCollision(ball, cir[i].rota) == false)
				Draw(cir[i]);
		}
		DrawFormatString(0, 0, GetColor(255, 255, 255), "%.5f", cir[0].speed);
		DrawFormatString(0, 15, GetColor(255, 255, 255), "%.5f", point.r);
		Bar2.My_DrawBox();
		Bar.My_DrawBox();
		ball.My_DrawCircle();
	}

	DxLib_End();
	return 0;
}