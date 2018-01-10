#define _USE_MATH_DEFINES
#include "Move.h"
#include "DxLib.h"
#include "../Collision/Collision.h"
#include "../Input/Input.h"
#include <math.h>

void Move::InputArrow8(float &x, float &y,float speed)
{
	
	Updata_Key();
	if (CheckHitKey(KEY_INPUT_UP)     ==  0 ||
		 CheckHitKey(KEY_INPUT_DOWN)  ==  0 ||
		 CheckHitKey(KEY_INPUT_LEFT)  ==  0 ||
		 CheckHitKey(KEY_INPUT_RIGHT) ==  0)
	{
		dir = non;
	}
	if (Key(KEY_INPUT_UP) >= 1)
	{
		dir = up;
	}
	if (Key(KEY_INPUT_DOWN) >= 1)
	{
		dir = down;
	}
	if (Key(KEY_INPUT_LEFT) >= 1)
	{
		dir = left;
	}
	if (Key(KEY_INPUT_RIGHT) >= 1)
	{
		dir = right;
	}
	if (Key(KEY_INPUT_UP) >= 1 && Key(KEY_INPUT_RIGHT) >= 1)
	{
		dir = up_right;
	}
	if (Key(KEY_INPUT_UP) >= 1 && Key(KEY_INPUT_LEFT) >= 1)
	{
		dir = up_left;
	}
	if (Key(KEY_INPUT_DOWN) >= 1 && Key(KEY_INPUT_RIGHT) >= 1)
	{
		dir = down_right;
	}
	if (Key(KEY_INPUT_DOWN) >= 1 && Key(KEY_INPUT_LEFT) >= 1)
	{
		dir = down_left;
	}
	switch (dir)
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
		x += static_cast<float>(cos(M_PI / 180.0f * 45)) * speed;
		y -= static_cast<float>(sin(M_PI / 180.0f * 45)) * speed;
		break;
	case up_left:
		x -= static_cast<float>(cos(M_PI / 180.0f * 45)) * speed;
		y -= static_cast<float>(sin(M_PI / 180.0f * 45)) * speed;
		break;
	case down_right:
		x += static_cast<float>(cos(M_PI / 180.0f * 45)) * speed;
		y += static_cast<float>(sin(M_PI / 180.0f * 45)) * speed;
		break;
	case down_left:
		x -= static_cast<float>(cos(M_PI / 180.0f * 45)) * speed;
		y += static_cast<float>(sin(M_PI / 180.0f * 45)) * speed;
		break;
	default:
		dir = non;
		break;
	}
	
}

void Move::InputArrow8(POS &p, float speed)
{
	Updata_Key();
	if (CheckHitKey(KEY_INPUT_UP)    == 0 ||
		CheckHitKey(KEY_INPUT_DOWN)  == 0 ||
		CheckHitKey(KEY_INPUT_LEFT)  == 0 ||
		CheckHitKey(KEY_INPUT_RIGHT) == 0)
	{
		dir = non;
	}
	if (Key(KEY_INPUT_UP) >= 1)
	{
		dir = up;
	}
	if (Key(KEY_INPUT_DOWN) >= 1)
	{
		dir = down;
	}
	if (Key(KEY_INPUT_LEFT) >= 1)
	{
		dir = left;
	}
	if (Key(KEY_INPUT_RIGHT) >= 1)
	{
		dir = right;
	}
	if (Key(KEY_INPUT_UP) >= 1 && Key(KEY_INPUT_RIGHT) >= 1)
	{
		dir = up_right;
	}
	if (Key(KEY_INPUT_UP) >= 1 && Key(KEY_INPUT_LEFT) >= 1)
	{
		dir = up_left;
	}
	if (Key(KEY_INPUT_DOWN) >= 1 && Key(KEY_INPUT_RIGHT) >= 1)
	{
		dir = down_right;
	}
	if (Key(KEY_INPUT_DOWN) >= 1 && Key(KEY_INPUT_LEFT) >= 1)
	{
		dir = down_left;
	}
	switch (dir)
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
		p.x += static_cast<float>(cos(M_PI / 180.0f * 45)) * speed;
		p.y -= static_cast<float>(sin(M_PI / 180.0f * 45)) * speed;
		break;
	case up_left:
		p.x -= static_cast<float>(cos(M_PI / 180.0f * 45)) * speed;
		p.y -= static_cast<float>(sin(M_PI / 180.0f * 45)) * speed;
		break;
	case down_right:
		p.x += static_cast<float>(cos(M_PI / 180.0f * 45)) * speed;
		p.y += static_cast<float>(sin(M_PI / 180.0f * 45)) * speed;
		break;
	case down_left:
		p.x -= static_cast<float>(cos(M_PI / 180.0f * 45)) * speed;
		p.y += static_cast<float>(sin(M_PI / 180.0f * 45)) * speed;
		break;
	default:
		dir = non;
		break;
	}
}

void Move::InputArrowLR(float &x, float speed)
{
	Updata_Key();
	if (Key(KEY_INPUT_LEFT) >= 1)
	{
		x -= speed;
	}
	if (Key(KEY_INPUT_RIGHT) >= 1)
	{
		x += speed;
	}
}

void InputArrowLR(POS& p, float speed)
{
	Updata_Key();
	if (Key(KEY_INPUT_LEFT) >= 1)
	{
		p.x -= speed;
	}
	if (Key(KEY_INPUT_RIGHT) >= 1)
	{
		p.x += speed;
	}
}

void Move::SetRota(float d, float s, float ang)
{
	angle = ang;
	dist = d;
	speed = s;
	
}
void Move::Rotation(const POS p1, POS &p2)
{
	angle += float(M_PI) / 180.0f * speed;
	p2.SetPos(p1.x + static_cast<float>(cos(angle) * dist), p1.y + static_cast<float>(sin(angle) * dist));
}

