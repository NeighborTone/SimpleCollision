#include "DxLib.h"
#include "Input.h"
#include "Figure.h"
#include "Collision.h"

const int
SCREEN_WIDIH = 1280,
SCREEN_HEIGHT = 720;

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	//���O����
	SetOutApplicationLogValidFlag(FALSE);
	//�E�C���h�E�^�C�g����ύX
	SetMainWindowText("�R���W�����e�X�g");
	//��ʃT�C�Y�ύX
	SetGraphMode(SCREEN_WIDIH, SCREEN_HEIGHT, 32);
	//�E�B���h�E���[�h�ύX�Ə������Ɨ���ʐݒ�
	ChangeWindowMode(TRUE), DxLib_Init(), SetDrawScreen(DX_SCREEN_BACK);

	const int X_size = 10;
	Box box[X_size];
	for (int i = 0; i < X_size; ++i)
	{
		box[i].x = 50 * i;
		box[i].y = 50;
		box[i].w = 50;
		box[i].h = 50;
		box[i].life = 1;
		box[i].SetBoxColor(i);
	}
	POS p1(0,600), p2(1280,600);
	POS p3(0, 600), p4(1280, 400);
	Line line(p1, p2, Blue);
	Line line2(p3, p4,Red);
	Box Bar(100, 100, 100, 100,1,Red);
	Circle ball(600, 400, 20, Blue);
	Circle ball2(200, 300, 30, Green);
	POS t1(600,100), t2(500,300), t3(700,300);
	Triangle tri(t1,t2,t3,Pink);
	while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0)
	{
		Updata_Key();
		
		if (Key(KEY_INPUT_ESCAPE) == 1)
		{
			break;
		}
		if (Key(KEY_INPUT_RIGHT) >= 1)
		{
			ball.x += 5;
		}
		if (Key(KEY_INPUT_LEFT) >= 1)
		{
			ball.x -= 5;
		}
		if (Key(KEY_INPUT_UP) >= 1)
		{
			ball.y -= 5;
		}
		if (Key(KEY_INPUT_DOWN) >= 1)
		{
			ball.y += 5;
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
		for (int i = 0; i < X_size; ++i)
		{
			if (CircleAndBoxCollision(ball,box[i]) == true || BoxCollision(Bar,box[i]) == true)
			{
				box[i].life -= 1;
			}
			if (box[i].life > 0)
			{
				box[i].My_DrawBox(box[i],box[i].color ,true);
			}
			
		}
		if (CircleCollision(ball, ball2) == false)
		{
			ball2.My_DrawCircle(ball2, ball2.color, true);
		}
		if (CircleAndSlopeCollision(ball, line) == false )
		{
			line.My_DrawLine(line, line.color);
		}
		if (BoxAndSlopeCollision(Bar, line2) == false)
		{
			line2.My_DrawLine(line2, line2.color);
		}
		Bar.My_DrawBox(Bar, Bar.color, true);
		ball.My_DrawCircle(ball, ball.color,true);
		tri.My_DrawTriangle(tri, tri.color, true);
	}
	
	DxLib_End();
	return 0;
}