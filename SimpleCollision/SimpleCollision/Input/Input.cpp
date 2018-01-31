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
Pad::Pad()
{
	inputFlag = false;
	_idArray[ePad::down] = 0;
	_idArray[ePad::left] = 1;
	_idArray[ePad::right] = 2;
	_idArray[ePad::up] = 3;
	_idArray[ePad::needle] = 7;
	_idArray[ePad::shot] = 5;
	_idArray[ePad::jump] = 4;
	_idArray[ePad::brake] = 6;
}

void Pad::Update()
{
	padInput = GetJoypadInputState(DX_INPUT_PAD1);	//パッドの入力状態
	for (int i = 0; i < 16; ++i)
	{
		if (padInput & (1 << i))
		{
			inputFlag = true;
			++_pad[i];
		}
		else
		{
			inputFlag = false;
			_pad[i] = 0;
		}
	}
}
int Pad::GetPad(ePad eID) const
{
	return _pad[_idArray[eID]];
}
bool Pad::PadState()
{
	return inputFlag;
}