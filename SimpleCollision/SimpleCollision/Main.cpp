#include "DxLib.h"
#include "Input.h"
#include "Figure.h"
#include "Collision.h"
#include <math.h>
#include <array>
//=====================================
//===動作確認用=========================
//=====================================
constexpr int
SCREEN_WIDIH = 1280,
SCREEN_HEIGHT = 720;
struct Obj
{
	Circle c;
	float speed;
	float dist;
	float angle;
	bool flag;
};
std::array<Obj,12>cir;

void Ini(Obj& c,float ang)
{
	c.angle = ang;
	c.dist = 100.0f;
	c.c.SetCircleColor(Cyan);
	c.c.r = 10.f;
	c.speed = 0;
	c.flag = false;
	
}
void Up(Obj& c)
{
	c.angle += MATH::Radian(c.speed);
	c.c.pos.SetPos(740.f + static_cast<float>(cos(c.angle) * c.dist), 245.f + static_cast<float>(sin(c.angle)*c.dist));
	
	if(c.flag == false)
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
}
void Draw(Obj& c)
{
	c.c.My_DrawCircle(c.c,true);
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

	
	const int X_size = 10;
	Box box[X_size];
	for (int i = 0; i < X_size; ++i)
	{
		box[i].x = 50 * i;
		box[i].y = 50;
		box[i].w = 50;
		box[i].h = 50;
		box[i].SetLife(1);
		box[i].SetBoxColor(i);
	}
	POS p1(0, 720), p2(1280, 400);
	POS p3(0, 600), p4(1280, 400);
	POS p5(0, 500), p6(1280, 500);
	POS p7(float(SCREEN_WIDIH / 2), 0), p8(static_cast<float>(SCREEN_WIDIH), static_cast<float>(SCREEN_HEIGHT));
	Line line(p1, p2, Blue);
	Line line2(p3, p4,Red);
	Line line3(p5, p6, Cyan);
	Line line4(p7, p8, Yellow);
	Box Bar(100, 100, 100, 100,1,Red);
	POS cp(600, 400);
	Circle ball(cp, 20, Blue);
	Circle ball2(200,300, 30, Green);
	POS t1(600,100), t2(500,300), t3(700,300);
	Triangle tri(t1,t2,t3,Pink);
	for(int i = 0;i<12;++i)
	Ini(cir[i],MATH::Radian(i*30.f));
	while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0)
	{
		Updata_Key();
		for (int i = 0;i < 12;++i)
			Up(cir[i]);
		if (Key(KEY_INPUT_ESCAPE) == 1)
		{
			break;
		}
		if (Key(KEY_INPUT_RIGHT) >= 1)
		{
			ball.pos.x += 5;
		}
		if (Key(KEY_INPUT_LEFT) >= 1)
		{
			ball.pos.x -= 5;
		}
		if (Key(KEY_INPUT_UP) >= 1)
		{
			ball.pos.y -= 5;
		}
		if (Key(KEY_INPUT_DOWN) >= 1)
		{
			ball.pos.y += 5;
		}
		if (Key(KEY_INPUT_SPACE) >= 1)
		{
			ball.pos.SetPos(0,0);
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
		if (Key(KEY_INPUT_RETURN) >= 1)
		{
			box[9].Addlife(1);
		}
		for (int i = 0; i < X_size; ++i)
		{
			if (box[i].GetLife() > 0)
			{
				box[i].My_DrawBox(box[i], true);
			}
			if (CircleAndBoxCollision(ball,box[i]) == true || BoxCollision(Bar,box[i]) == true)
			{
				if (box[i].GetLife() < 0)
				{
					continue;
				}
				box[i].Damage(1);
			}
		}
		if (CircleCollision(ball, ball2) == false)
		{
			ball2.My_DrawCircle(ball2, true);
		}
		if (CircleAndSlopeCollision(ball, line) == false )
		{
			line.My_DrawLine(line);
		}
		if (BoxAndSlopeCollision(Bar, line2) == false)
		{
			line2.My_DrawLine(line2);
		}
		Bar.My_DrawBox(Bar, true);
		ball.My_DrawCircle(ball, true);
		tri.My_DrawTriangle(tri, true);

		if (LineCollision(line3, line4) == false)
		{
			
			line4.My_DrawLine(line4);
		}
		if (CirecleAndLineCollision(ball, line3) == false)
		{
			line3.My_DrawLine(line3);
		}
		for (int i = 0;i < 12;++i)
		{
			if (CircleCollision(ball, cir[i].c) == false)
			Draw(cir[i]);
		}
		DrawFormatString(0, 0, GetColor(255, 255, 255), "%f", cir[0].speed);
	}
	
	DxLib_End();
	return 0;
}