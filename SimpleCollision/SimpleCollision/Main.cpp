#include "DxLib.h"
#include "Input.h"
#include "Figure.h"


const int
SCREEN_WIDIH = 960,
SCREEN_HEIGHT = 540;

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
		box[i].life = 1;
	}
	Box Bar(100, 100, 100, 100,1,1);
	

	while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0)
	{
		Updata_Key();
		
		if (Key(KEY_INPUT_ESCAPE) == 1)
		{
			break;
		}
		if (Key(KEY_INPUT_RIGHT) >= 1)
		{
			Bar.x += 5;
		}
		if (Key(KEY_INPUT_LEFT) >= 1)
		{
			Bar.x -= 5;
		}
		if (Key(KEY_INPUT_UP) >= 1)
		{
			Bar.y -= 5;
		}
		if (Key(KEY_INPUT_DOWN) >= 1)
		{
			Bar.y += 5;
		}

		Bar.My_DrawBox(Bar, Bar.color, true);
		for (int i = 0; i < X_size; ++i)
		{
			if (Bar.BoxCollision(box[i], Bar) == true)
			{
				box[i].life -= 1;
			}
			if (box[i].life > 0)
			{
				box[i].My_DrawBox(box[i], box[i].color, true);
			}
			
		}
		
	}

	DxLib_End();
	return 0;
}