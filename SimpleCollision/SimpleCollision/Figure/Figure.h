#pragma once
//=====================================
//====�ėp�I��2D�̐}�`�������N���X=======
//===2017/12/26�J�n====================
/*���ʂ������
@���W
@�F
@������
@�F�w��
@�`�恦DxLib�̋@�\�Ɉˑ��B�摜���g���ꍇ�͕s�v�ȃ��\�b�h
 �܂��ADxLib���g��Ȃ��Ƃ��̓R�����g������(���Ƃňˑ����Ȃ��̂����)
����`�̂ݍ��W�Ǘ���POS�^���g��Ȃ��i��Ԏg��ꂻ���Ȑ}�`�Ȃ̂ŁA�A�N�Z�X���y�ɂ���j
*/
#include "DxLib.h"
//�F�f�[�^
enum ColorData
{
	White = 0,
	Red = 1,
	Green = 2,
	Blue = 3,
	Magenta = 4,
	Cyan = 5,
	Yellow = 6,
	Pink = 7,
	Violet = 8,
	Emerald = 9,
	Gray = 10,
	Rainbow = 11,
};
//�F�N���X
class Color
{
private:
	int r, g, b;
	int rDelta, gDelta, bDelta;
	int color;
public:
	Color() { };
	//���C���{�[�p===================================
	void SetRGB(int r = 200, int g = 150, int b = 100);	//RGB�l���w��
	void SetDelta(int r = 1, int g = 1, int b = 1);		//�F�̕ω���
	//===========================================
	int  GetMyColor() const { return color; };			//�J���[�R�[�h��Ԃ�
	void SetColor(int color);							//�����ɃJ���[�R�[�h���w��
	void Print()
	{
		DrawFormatString(0, 300, GetColor(255, 255, 255), "%d  %d  %d", r, g, b);
	}
	~Color() {};
};

//���W�������N���X
class POS
{
public:
	float x, y;
	POS(float _x = 0, float _y = 0);
	void SetPos(float _x, float _y);
	POS operator + (const POS& p)   const { return POS({ x + p.x, y + p.y }); }
	POS operator - (const POS& p)   const { return POS({ x - p.x, y - p.y }); }
	POS operator * (const POS& p)   const { return POS({ x * p.x, y * p.y }); }
	~POS() {};


};

//�����������N���X
class Line
{
public:
	Color color;
	POS		 p1,																//�n�_
		  		 p2;															//�I�_
	explicit Line();															//�R���X�g���N�^
	explicit Line(float p1x, float p1y, float p2x, float p2y, int = White);		//�R���X�g���N�^
	explicit Line(POS p1, POS p2, int = 0);										//�R���X�g���N�^
	explicit Line(const Line& l);												//�R�s�[�R���X�g���N�^
	void SetLine(float p1x, float p1y, float p2x, float p2y, int = White);		//������
	void SetLine(POS p1,POS p2, int = 0);										//������													
	void My_DrawLine();															//�`��
	~Line() {};
};
//��`�������N���X
class Box
{
public:
	Color color;																					//�F
	float x, y, w, h;																				//���W�Ƒ傫��
	explicit Box();																				//�R���X�g���N�^
	explicit Box(float x, float y, float w, float h,  int = White);					//�R���X�g���N�^
	explicit Box(const Box& b);																//�R�s�[�R���X�g���N�^
	void SetBox(float x, float y, float w, float h, int = White);					//������ 
	void My_DrawBox(bool = true);															//�`��A�f�t�I���g�œh��Ԃ�
	Box &operator * (const float& f) { w *= f; h *= f; return (*this); }			//�T�C�Y��f�{�ɂ���
	~Box() {};
};
//�~�������N���X
class Circle
{
public:
	float     r;																			//���a
	Color color;																		//�F
	POS     pos;																			//���W
	explicit Circle();																//�R���X�g���N�^
	explicit Circle(float x, float y, float r, int = White);				//�R���X�g���N�^
	explicit Circle(POS pos, float r, int = White);							//�R���X�g���N�^
	explicit Circle(const Circle& c);											//�R�s�[�R���X�g���N�^
	void SetCircle(float x,float y,float r,int = White);					//������
	void SetCircle(POS pos, float r, int = White);							//������
	void My_DrawCircle(bool = true);											//�`��A�f�t�I���g�œh��Ԃ�
	Circle &operator * (const float& f) { r *= f; return (*this); }	//�T�C�Y��f�{�ɂ���
	~Circle() {};
};
//�O�p�`�������N���X(������)
class Triangle
{
public:
	Color color;	
	POS		 p1,																//3�̒��_
				 p2,
				 p3;
	explicit Triangle();
	explicit Triangle(float p1x, float p1y, float p2x, float p2y, float p3x, float p3y, int = White);
	explicit Triangle(POS p1, POS p2, POS p3, int = White);							
	void SetTriangle(float p1x, float p1y, float p2x, float p2y, float p3x, float p3y, int = White);
	void SetTriangle(POS p1, POS p2, POS p3, int = White);
	void My_DrawTriangle(bool = true);														
	~Triangle() {};
};