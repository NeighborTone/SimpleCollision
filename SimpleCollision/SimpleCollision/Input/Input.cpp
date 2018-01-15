#include "Input.h"
#include "DxLib.h"


static int key[256];	//キーの入力状態を格納する
static int mouse[8];
						//キーの入力状態の更新
void Updata_Key()
{
	char tmpKey[256];
	GetHitKeyStateAll(tmpKey);	//現在のキーの状態を格納
	for (int i = 0; i < 256; ++i)
	{
		if (tmpKey[i] != 0)
		{
			++key[i];
		}
		else  //押されていなければ
		{
			key[i] = 0;
		}
	}
}
//keycodeのキーの入力状態を取得する
int Key(int keycode)
{
	return key[keycode];	//keycodeの入力状態を返す
}


int Mouse_t::GetHitMouseStateAll_2(Mouse_t *Nezumi)
{
	if (GetMousePoint(&Nezumi->x, &Nezumi->y) == -1)	//マウスの位置取得
	{ 
		return -1;
	}
	int MouseInput = GetMouseInput();						//マウスの押した状態取得
	for (int i = 0; i<8; i++)										//マウスのキーは最大8個まで確認出来る
	{          
		if ((MouseInput & 1 << i) != 0) Nezumi->Button[i]++;   //押されていたらカウントアップ
		else									 Nezumi->Button[i] = 0; //押されてなかったら0
	}
	Nezumi->WheelRotVol = GetMouseWheelRotVol();				//ホイール回転量取得
	return 0;
}