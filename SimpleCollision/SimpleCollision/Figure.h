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

//�F�f�[�^
enum ColorData
{
	White   = 0,
	Red     = 1,
	Green   = 2,
	Blue    = 3,
	Magenta = 4,
	Cyan    = 5,
	Yellow  = 6,
	Pink    = 7,
	Violet  = 8,
	Emerald = 9,
	Gray    = 10,
};
//�F�N���X
class Color
{
private:
	int color;
public:
	int  GetMyColor();
	void SetColor(int);

};
//���W�������N���X
class POS
{
public:
	float x, y;
	POS(float _x, float _y);
	void SetPos(float _x = 0, float _y = 0);
	POS operator + (const POS& p) const
	{
		return POS({ x + p.x, y + p.y });
	}
	POS operator - (const POS& p) const
	{
		return POS({ x - p.x, y - p.y });
	}
	POS operator * (const POS& p) const
	{
		return POS({ x * p.x, y * p.y });
	}
	POS &operator += (const POS& p) 
	{
		x += p.x;
		y += p.y;
		return (*this);
	}
	POS &operator -= (const POS& p)
	{
		x -= p.x;
		y -= p.y;
		return (*this);
	}
	~POS() {};
};

//�����������N���X
class Line
{
public:
	Color color;
	POS p1,													//�n�_
		p2;													//�I�_
	explicit Line();										//�R���X�g���N�^
	explicit Line(float, float, float, float, int);			//�R���X�g���N�^
	explicit Line(POS, POS, int);							//�R���X�g���N�^
	void SetLine(float, float, float, float, int);			//������
	void SetLine(POS,POS, int);								//������													
	void My_DrawLine(Line&);
	~Line() {};
};
//��`�������N���X
class Box
{
private:
	int life;
public:
	Color color;
	int x, y, w, h;
	explicit Box();												//�R���X�g���N�^
	explicit Box(int, int, int, int,int, int);					//�R���X�g���N�^(x,y,w,h,life,color)
	void SetBox(int,int,int,int,int _c = 0,int _l = 1);			//������ 
	void SetLife(int);											//�̗͂��Z�b�g
	void Addlife(unsigned int);									//�̗͂𑝂₷
	void Damage(signed int);									//�̗͂����炷
	int  GetLife();												//�̗͂��m�F����
	void My_DrawBox(Box&,bool);									//�C���X�^���X�Ɠh��Ԃ�
	~Box() {};
};
//�~�������N���X
class Circle
{
public:
	float r;													//���a
	Color color;
	POS pos;													//���W
	explicit Circle();											//�R���X�g���N�^
	explicit Circle(float, float, float, int);					//�R���X�g���N�^
	explicit Circle(POS, float, int);							//�R���X�g���N�^
	void SetCircle(float,float,float,int _c = 0, int _l = 1);	//������(x,y,w,h,color,life) 
	void SetCircle(POS, float, int _c = 0, int _l = 1);			//������(POS,r,color,life)
	void My_DrawCircle(Circle&, bool);							//�C���X�^���X�Ɠh��Ԃ�
	~Circle() {};
};
//�O�p�`�������N���X(������)
class Triangle
{
public:
	Color color;
	POS p1,
		p2,
		p3;
	explicit Triangle();
	explicit Triangle(POS, POS, POS, int);						//3�̒��_�ƐF���w��
	void My_DrawTriangle(Triangle&, bool);						//�C���X�^���X�Ɠh��Ԃ�
	~Triangle() {};
};