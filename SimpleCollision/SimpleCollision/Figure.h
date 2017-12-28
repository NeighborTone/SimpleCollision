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
	Color() {};
	const int  GetMyColor();
	void SetColor(int color);
	~Color() {};
};
//���W�������N���X
class POS
{
public:
	float x, y;
	POS(float _x = 0, float _y = 0);
	void SetPos(float _x, float _y);
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
	POS		 p1,																//�n�_
		  	 p2;															    //�I�_
	explicit Line();															//�R���X�g���N�^
	explicit Line(float p1x, float p1y, float p2x, float p2y, int = White);		//�R���X�g���N�^
	explicit Line(POS p1, POS p2, int = 0);										//�R���X�g���N�^
	void SetLine(float p1x, float p1y, float p2x, float p2y, int = White);		//������
	void SetLine(POS p1,POS p2, int = 0);										//������													
	void My_DrawLine(Line&);
	~Line() {};
};
//��`�������N���X
class Box
{
private:
	int life;																	//����Box�ɂ̗͑͂̊T�O�����邼�I�I
public:
	Color color;
	int x, y, w, h;
	explicit Box();																//�R���X�g���N�^
	explicit Box(int x, int y, int w, int h,int = 0, int = White);				//�R���X�g���N�^
	void SetBox(int x,int y,int w,int h,int = 0,int = White);					//������ 
	void SetLife(int life);														//�̗͂��Z�b�g
	void Addlife(unsigned int life);											//�̗͂𑝂₷
	void Damage(signed int damege);												//�̗͂����炷
	int  GetLife();																//�̗͂��m�F����
	void My_DrawBox(Box&,bool);													//�C���X�^���X�Ɠh��Ԃ�
	~Box() {};
};
//�~�������N���X
class Circle
{
public:
	float     r;																//���a
	Color color;
	POS     pos;																//���W
	explicit Circle();															//�R���X�g���N�^
	explicit Circle(float x, float y, float r, int = White);					//�R���X�g���N�^
	explicit Circle(POS pos, float r, int = White);								//�R���X�g���N�^
	void SetCircle(float x,float y,float r,int = White);						//������
	void SetCircle(POS pos, float r, int = White);								//������
	void My_DrawCircle(Circle&, bool);											//�C���X�^���X�Ɠh��Ԃ�
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
	explicit Triangle(POS p1, POS p2, POS p3, int = White);						//3�̒��_�ƐF���w��
	void My_DrawTriangle(Triangle&, bool);										//�C���X�^���X�Ɠh��Ԃ�
	~Triangle() {};
};