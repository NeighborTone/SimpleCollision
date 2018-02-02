#include "DxLib.h"
#include "../Input/Input.h"
#include "../Figure/Figure.h"
#include "../Move/Move.h"
#include "../Collision/Collision.h"
#include "../MyDxSound/My_DxSound.h"
#include "../Easing/easing.hpp"
#include "../Joint/Joint.h"
#include "../MyMath/MyMath.h"
#include "../DrawManager/Graphics.h"

//=====================================
//===����m�F�p=========================
//=====================================

int Processloop()
{
	if (ScreenFlip() != 0) return -1;
	if (ProcessMessage() != 0) return -1;
	if (ClearDrawScreen() != 0) return -1;
	if (DxLib_IsInit() == FALSE) return -1;
	return 0;
}
/*void CannonMove(Data p_, Data& c_, bool anim_, Data change_, int i, Task t_)
{
	if (p_.Y <= c_.Y)  //�}�E�X��Y���W����C�̏�ɍs������Œ�
	{
		p_.Y = c_.Y;
	}

	if (anim_ && c_.AnimTime < 39)  //�A�j���[�V����
	{
		++c_.AnimTime;
	}
	else
	{
		c_.AnimTime = 0;
	}

	if (t_ == Game && change.setPoint == 3 && i < 20)
	{
		if (c_.CntTime > 360)
		{
			c_.CntTime = 0;
		}
		else
		{
			++c_.CntTime;
		}
		if (i % 2)
		{
			c_.X += cos(ML::ToRadian(float(c_.CntTime))) * 2.f;
		}
		else
		{
			c_.X -= cos(ML::ToRadian(float(c_.CntTime))) * 2.f;
		}
	}

	c_.Rot = atan2(p_.Y - c_.Y, p_.X - c_.X);  //��C�̌X�����v�Z

	//��C�Ƌ@�̂̓����蔻��
	if (fighter[0].hitbase.Hit(c_.hitbase) && fighter[0].onoff)
	{
		FighterHit();
	}
}
*/
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	constexpr int
	SCREEN_WIDIH = 1280,
	SCREEN_HEIGHT = 720;

	//���O����
	SetOutApplicationLogValidFlag(FALSE);
	//�E�C���h�E�^�C�g����ύX
	SetMainWindowText("�R���W�����e�X�g");
	//��ʃT�C�Y�ύX
	SetGraphMode(SCREEN_WIDIH, SCREEN_HEIGHT, 32);
	//�E�B���h�E���[�h�ύX�Ə������Ɨ���ʐݒ�
	ChangeWindowMode(TRUE), DxLib_Init(), SetDrawScreen(DX_SCREEN_BACK);


	struct Obj
	{
		Circle c;
		Move move;
		Painter render;
	};
	Obj me;
	Obj you;
	Obj shimizu;
	Painter raster;
	raster.SetGraphic("resource/Graph/back.png");
	me.c.SetCircle(0, 0, 32, Cyan);
	you.c.SetCircle(1280 / 2, 720, 30, Pink);
	shimizu.c.SetCircle(0, 0, 32, Red);
	you.render.SetGraphic("resource/Graph/^^.png");
	me.render.SetGraphic("resource/Graph/^^.png");
	shimizu.render.SetGraphic("resource/Graph/^^.png");
	you.move.SetRota(100,5);
	shimizu.move.SetRota(100, 7);
	while (Processloop() == 0)
	{
		Updata_Key();
		me.move.InputArrow8(me.c.pos, 5);
		me.render.RenderRotaGraphic(me.c.pos);
		me.c.My_DrawCircle(false);
		you.move.Rotation(me.c.pos, you.c.pos);
		you.render.RenderRotaGraphic(you.c.pos);
		you.c.My_DrawCircle(false);
		shimizu.move.Rotation(you.c.pos,shimizu.c.pos);
		shimizu.render.RenderRotaGraphic(shimizu.c.pos);
		shimizu.c.My_DrawCircle(false);
		//you.render.RenderRotaGraphic(you.c.pos,atan2(me.c.pos.y - you.c.pos.y, me.c.pos.x - you.c.pos.x) + (MATH::m_pi/2));
		//raster.Raster_Scrool(1280/2,720/2,1000,300,10);
	}
	DxLib_End();
	return 0;
}

