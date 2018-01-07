#include "Move.h"
#include "DxLib.h"

void Move::InputMove(POS& p,float speed)
{
	Updata_Key();
	if (Key(KEY_INPUT_UP) >= 1)    { p.y -= speed; }
	if (Key(KEY_INPUT_DOWN) >= 1)  { p.y += speed; }
	if (Key(KEY_INPUT_LEFT) >= 1)  { p.x -= speed; }
	if (Key(KEY_INPUT_RIGHT) >= 1) { p.x += speed; }
}