#pragma once
#define M_LEFT	0 	//マウス左
#define M_RIGHT	1	//マウス右
#include "DxLib.h"
#include <array>
/*キーの入力状態を更新,
  キー入力を有効にする場合、
  この関数を更新処理に呼び出す*/
void Updata_Key();

//引数のキーコードのキーの入力状態を返す
int Key(int keycode);

class Mouse_t
{
public:
	int x;
	int y;          //座標
	int WheelRotVol;//ホイールの回転量
	unsigned int Button[8];  //ボタンの押した状態
	int GetHitMouseStateAll_2(Mouse_t *Nezumi);
};
enum ePad
{
	left, up, right, down, shot, needle, jump, brake,
};
class Pad final
{
private:

	bool inputFlag;
	int padInput;
	const static int PAD_KEY_NUM = 16;
	std::array<int, PAD_KEY_NUM>_idArray;	//どのボタンがどのボタンに割り当たっているか示す
	std::array<int, PAD_KEY_NUM>_pad;			//16ボタンの入力格納
public:
	Pad();
	~Pad() = default;
	bool PadState();
	void Update();
	int GetPad(ePad eID) const;	//eIDのボタン取得

};