#pragma once
#define M_LEFT	0 	//マウス左
#define M_RIGHT	1	//マウス右
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
