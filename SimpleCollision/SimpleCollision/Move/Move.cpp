#include "Move.h"
#include "DxLib.h"
#include "../MyMath/MyMath.h"
#include "../Input/Input.h"
#include <math.h>

void Move::PadInputArrow8(POS& p, float speed)
{
	pad.Update();
	if (!pad.PadState())
	{
		inputDir = non;
	}
	if (pad.GetPad(ePad::up) >= 1)
	{
		dir = UP;
		inputDir = up;
	}
	if (pad.GetPad(ePad::down) >= 1)
	{
		dir = DOWN;
		inputDir = down;
	}
	if (pad.GetPad(ePad::left) >= 1)
	{
		dir = LEFT;
		inputDir = left;
	}
	if (pad.GetPad(ePad::right) >= 1)
	{
		dir = RIGHT;
		inputDir = right;
	}
	if (pad.GetPad(ePad::up) >= 1 && pad.GetPad(ePad::right) >= 1)
	{
		dir = RIGHT;
		inputDir = up_right;
	}
	if (pad.GetPad(ePad::up) >= 1 && pad.GetPad(ePad::left) >= 1)
	{
		dir = LEFT;
		inputDir = up_left;
	}
	if (pad.GetPad(ePad::down) >= 1 && pad.GetPad(ePad::right) >= 1)
	{
		dir = RIGHT;
		inputDir = down_right;
	}
	if (pad.GetPad(ePad::down) >= 1 && pad.GetPad(ePad::left) >= 1)
	{
		dir = LEFT;
		inputDir = down_left;
	}
	switch (inputDir)
	{
	case up:
		p.y -= speed;
		break;
	case down:
		p.y += speed;
		break;
	case left:
		p.x -= speed;
		break;
	case right:
		p.x += speed;
		break;
	case up_right:
		p.x += static_cast<float>(cos(MATH::m_pi / 180.0f * 45)) * speed;
		p.y -= static_cast<float>(sin(MATH::m_pi / 180.0f * 45)) * speed;
		break;
	case up_left:
		p.x -= static_cast<float>(cos(MATH::m_pi / 180.0f * 45)) * speed;
		p.y -= static_cast<float>(sin(MATH::m_pi / 180.0f * 45)) * speed;
		break;
	case down_right:
		p.x += static_cast<float>(cos(MATH::m_pi / 180.0f * 45)) * speed;
		p.y += static_cast<float>(sin(MATH::m_pi / 180.0f * 45)) * speed;
		break;
	case down_left:
		p.x -= static_cast<float>(cos(MATH::m_pi / 180.0f * 45)) * speed;
		p.y += static_cast<float>(sin(MATH::m_pi / 180.0f * 45)) * speed;
		break;
	default:
		inputDir = non;
		break;
	}

}
void Move::InputArrow8(float &x, float &y,float speed)
{
	if (CheckHitKey(KEY_INPUT_UP)     ==  0 ||
		 CheckHitKey(KEY_INPUT_DOWN)  ==  0 ||
		 CheckHitKey(KEY_INPUT_LEFT)  ==  0 ||
		 CheckHitKey(KEY_INPUT_RIGHT) ==  0)
	{
		inputDir = non;
	}
	if (Key(KEY_INPUT_UP) >= 1)
	{
		dir = UP;
		inputDir = up;
	}
	if (Key(KEY_INPUT_DOWN) >= 1)
	{
		dir = DOWN;
		inputDir = down;
	}
	if (Key(KEY_INPUT_LEFT) >= 1)
	{
		dir = LEFT;
		inputDir = left;
	}
	if (Key(KEY_INPUT_RIGHT) >= 1)
	{
		dir = RIGHT;
		inputDir = right;
	}
	if (Key(KEY_INPUT_UP) >= 1 && Key(KEY_INPUT_RIGHT) >= 1)
	{
		dir = RIGHT;
		inputDir = up_right;
	}
	if (Key(KEY_INPUT_UP) >= 1 && Key(KEY_INPUT_LEFT) >= 1)
	{
		dir = LEFT;
		inputDir = up_left;
	}
	if (Key(KEY_INPUT_DOWN) >= 1 && Key(KEY_INPUT_RIGHT) >= 1)
	{
		dir = RIGHT;
		inputDir = down_right;
	}
	if (Key(KEY_INPUT_DOWN) >= 1 && Key(KEY_INPUT_LEFT) >= 1)
	{
		dir = LEFT;
		inputDir = down_left;
	}
	switch (inputDir)
	{
	case up:
		y -= speed;
		break;
	case down:
		y += speed;
		break;
	case left:
		x -= speed;
		break;
	case right:
		x += speed;
		break;
	case up_right:
		x += static_cast<float>(cos(MATH::m_pi / 180.0f * 45)) * speed;
		y -= static_cast<float>(sin(MATH::m_pi / 180.0f * 45)) * speed;
		break;
	case up_left:
		x -= static_cast<float>(cos(MATH::m_pi / 180.0f * 45)) * speed;
		y -= static_cast<float>(sin(MATH::m_pi / 180.0f * 45)) * speed;
		break;
	case down_right:
		x += static_cast<float>(cos(MATH::m_pi / 180.0f * 45)) * speed;
		y += static_cast<float>(sin(MATH::m_pi / 180.0f * 45)) * speed;
		break;
	case down_left:
		x -= static_cast<float>(cos(MATH::m_pi / 180.0f * 45)) * speed;
		y += static_cast<float>(sin(MATH::m_pi / 180.0f * 45)) * speed;
		break;
	default:
		inputDir = non;
		break;
	}
	
}

void Move::InputArrow8(POS &p, float speed)
{
	if (CheckHitKey(KEY_INPUT_UP)    == 0 ||
		CheckHitKey(KEY_INPUT_DOWN)  == 0 ||
		CheckHitKey(KEY_INPUT_LEFT)  == 0 ||
		CheckHitKey(KEY_INPUT_RIGHT) == 0)
	{
		inputDir = non;
	}
	if (Key(KEY_INPUT_UP) >= 1)
	{
		dir = UP;
		inputDir = up;
	}
	if (Key(KEY_INPUT_DOWN) >= 1)
	{
		dir = DOWN;
		inputDir = down;
	}
	if (Key(KEY_INPUT_LEFT) >= 1)
	{
		dir = LEFT;
		inputDir = left;
	}
	if (Key(KEY_INPUT_RIGHT) >= 1)
	{
		dir = RIGHT;
		inputDir = right;
	}
	if (Key(KEY_INPUT_UP) >= 1 && Key(KEY_INPUT_RIGHT) >= 1)
	{
		dir = RIGHT;
		inputDir = up_right;
	}
	if (Key(KEY_INPUT_UP) >= 1 && Key(KEY_INPUT_LEFT) >= 1)
	{
		dir = LEFT;
		inputDir = up_left;
	}
	if (Key(KEY_INPUT_DOWN) >= 1 && Key(KEY_INPUT_RIGHT) >= 1)
	{
		dir = RIGHT;
		inputDir = down_right;
	}
	if (Key(KEY_INPUT_DOWN) >= 1 && Key(KEY_INPUT_LEFT) >= 1)
	{
		dir = LEFT;
		inputDir = down_left;
	}
	switch (inputDir)
	{
	case up:
		p.y -= speed;
		break;
	case down:
		p.y += speed;
		break;
	case left:
		p.x -= speed;
		break;
	case right:
		p.x += speed;
		break;
	case up_right:
		p.x += static_cast<float>(cos(MATH::m_pi / 180.0f * 45)) * speed;
		p.y -= static_cast<float>(sin(MATH::m_pi / 180.0f * 45)) * speed;
		break;
	case up_left:
		p.x -= static_cast<float>(cos(MATH::m_pi / 180.0f * 45)) * speed;
		p.y -= static_cast<float>(sin(MATH::m_pi / 180.0f * 45)) * speed;
		break;
	case down_right:
		p.x += static_cast<float>(cos(MATH::m_pi / 180.0f * 45)) * speed;
		p.y += static_cast<float>(sin(MATH::m_pi / 180.0f * 45)) * speed;
		break;
	case down_left:
		p.x -= static_cast<float>(cos(MATH::m_pi / 180.0f * 45)) * speed;
		p.y += static_cast<float>(sin(MATH::m_pi / 180.0f * 45)) * speed;
		break;
	default:
		inputDir = non;
		break;
	}
}

void Move::InputArrowLR(float &x, float speed)
{
	if (Key(KEY_INPUT_LEFT) >= 1)
	{
		dir = LEFT;
		x -= speed;
	}
	if (Key(KEY_INPUT_RIGHT) >= 1)
	{
		dir = RIGHT;
		x += speed;
	}
}

void Move::InputArrowLR(POS& p, float speed)
{
	if (Key(KEY_INPUT_LEFT) >= 1)
	{
		dir = LEFT;
		p.x -= speed;
	}
	if (Key(KEY_INPUT_RIGHT) >= 1)
	{
		dir = RIGHT;
		p.x += speed;
	}
}
void Move::InputFly(float& y, float pow, float fall)
{
	if (!f_flag)	//1度だけ呼ばれる
	{
		jumpPow = pow;
		fallspeed = fall;
		f_flag = true;
	}
	if (Key(KEY_INPUT_Z) >= 1)
	{
			fallspeed = jumpPow;
	}
	else
	{
		fallspeed += MATH::Gravity(32) * 2;
	}
	y += fallspeed;
}
void Move::InputJump(float& y,float pow, bool hit,float fall)
{
	if (!j_flag)	//1度だけ呼ばれる
	{
		jumpPow = pow;
		fallspeed = fall;
		j_flag = true;
	}
	if (hit)//足元判定
	{
		fallspeed = 0.0f;
	}
	else
	{
		fallspeed += MATH::Gravity(32) * 3;
	}
	if (Key(KEY_INPUT_Z) == 1)
	{
		if (hit)//足元判定
		{
			fallspeed = jumpPow;
		}
	}
	y += fallspeed;
}

void Move::SetRota(float d, float s, float ang)
{
	angle = ang;
	dist = d;
	speed = s;
	
}
void Move::Rotation(const POS p1, POS &p2)
{
	angle += float(MATH::m_pi) / 180.0f * speed;
	p2.SetPos(p1.x + static_cast<float>(cos(angle) * dist), p1.y + static_cast<float>(sin(angle) * dist));
}

void Move::BackScroll(int dir,POS& start, float end, float speed,int handle)
{
	//縦方向スクロール
	if (dir == Up_Down)
	{
		start.y += speed;
		if (speed > 0)
		{
			if (start.y >= end)
			{
				start.y = 0;
			}
			DrawGraphF(start.x, start.y, handle, true);
			DrawGraphF(start.x, start.y - end, handle, true);
		}
		if (speed < 0)
		{
			if (start.y <= -end)
			{
				start.y = 0;
			}
			DrawGraphF(start.x, start.y, handle, true);
			DrawGraphF(start.x, start.y + end, handle, true);
		}
	}
	//横方向スクロール
	if (dir == sideways)
	{
		start.x += speed;
		if (speed < 0)
		{
			if (start.x <= -end)
			{
				start.x = 0;
			}
			DrawGraphF(start.x, start.y, handle, true);
			DrawGraphF(start.x + end, start.y, handle, true);
		}
		if (speed > 0)
		{
			if (start.x >= end)
			{
				start.x = 0;
			}
			DrawGraphF(start.x, start.y, handle, true);
			DrawGraphF(start.x - end, start.y, handle, true);
		}
	}
}

void Move::BackScroll(int dir, float& startx, float& starty, float end, float speed, int handle)
{
	//縦方向スクロール
	if (dir == Up_Down)
	{
		starty += speed;
		if (speed > 0)
		{
			if (starty >= end)
			{
				starty = 0;
			}
			DrawGraphF(startx, starty, handle, true);
			DrawGraphF(startx, starty - end, handle, true);
		}
		if (speed < 0)
		{
			if (starty <= -end)
			{
				starty = 0;
			}
			DrawGraphF(startx, starty, handle, true);
			DrawGraphF(startx, starty + end, handle, true);
		}
	}
	//横方向スクロール
	if (dir == sideways)
	{
		startx += speed;
		if (speed < 0)
		{
			if (startx <= -end)
			{
				startx = 0;
			}
			DrawGraphF(startx, starty, handle, true);
			DrawGraphF(startx + end, starty, handle, true);
		}
		if (speed > 0)
		{
			if (startx >= end)
			{
				startx = 0;
			}
			DrawGraphF(startx, starty, handle, true);
			DrawGraphF(startx - end, starty, handle, true);
		}
	}
}

void Move::CheckMoveDisp(POS& p, const int dispW, const int dispH, float help)
{
	if (p.x < dispW - dispW + help)
	{
		p.x = dispW - dispW + help;
	}
	if (p.x > dispW - help)
	{
		p.x = dispW - help;
	}
	if (p.y < dispH - dispH + help)
	{
		p.y = dispH - dispH + help;
	}
	if (p.y > dispH - help)
	{
		p.y = dispH - help;
	}
}
void Move::SetDir(Dir dir)
{
	this->dir = dir;
}
Move::Dir Move::GetDir()
{
	return dir;
}