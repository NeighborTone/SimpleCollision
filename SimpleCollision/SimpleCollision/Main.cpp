#include "DxLib.h"
#include "Input.h"
#include "Figure.h"

extern const int
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


	Box box(0,0,100,100,1);
	Circle ball(SCREEN_WIDIH/2, SCREEN_HEIGHT/2, 10, 0);


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

		ball.My_DrawCircle(ball, ball.color, true);
		box.My_DrawBox(box, box.color, true);
	}

	DxLib_End();
	return 0;
}