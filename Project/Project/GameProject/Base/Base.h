#pragma once
#include <GLLibrary.h>
#include <list>
#include "../TaskSystem/Task.h"

class Map;

#define GRAVITY (9.8f/60)
#define GROUND (500)//�n�ʂ̒���

class RectBox
{
public:
	float m_left;
	float m_top;
	float m_right;
	float m_bottom;
	float m_near;
	float m_far;
	RectBox():m_left(0), m_top(0), m_right(0), m_bottom(0),m_near(0),m_far(0)
	{

	}

	/**
	* @fn
	* �R���X�g���N�^�i��`�ݒ�j
	* @brief ��`��ݒ肷��
	* @param l	[in]�@��
	* @param t	[in]�@��
	* @param r	[in]�@�E
	* @param b	[in]�@��
	*/
	RectBox(float l, float t, float r, float b, float n, float f)
		: m_left(l), m_top(t), m_right(r), m_bottom(b), m_near(n), m_far(f)
	{

	}
};

class Base : public Task{
public:
	//��ޕ���
	BaseType m_type;
	//�摜�I�u�W�F�N�g
	CImage m_img;
	//���W�f�[�^
	CVector3D m_pos;
	//�ړ��x�N�g��
	CVector3D m_vec;
	//�W�����v�t���O
	bool m_jump;
	//���]�t���O
	bool m_flip;

	int kind = 0;//��ގ��ʗp
	//��`
	RectBox	m_rect;
	//�X�N���[���l
	static CVector2D m_scroll;
public:
	
	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	/// <param name="type">�I�u�W�F�N�g�̎��</param>
	/// <returns></returns>
	Base(int id, int priority);
	
	/// <summary>
	/// �f�X�g���N�^
	/// </summary>
	/// <returns></returns>
	virtual ~Base();


	/// <summary>
	/// �X�V
	/// </summary>
	virtual void Update();

	static  CVector2D Get2DPos(CVector3D pos);
	/// <summary>
	/// �`��
	/// </summary>
	virtual void Draw();
	
	virtual void Draw3D();
	
	/// <summary>
	/// �����蔻�茟��
	/// </summary>
	/// <param name="b">����ΏۃI�u�W�F�N�g</param>
	virtual void Collision(Base* b);
	
	/// <summary>
	/// ��`���m�̔���
	/// </summary>
	/// <param name="b1">����I�u�W�F�N�g�P</param>
	/// <param name="b2">����I�u�W�F�N�g�Q</param>
	/// <returns>true:�ڐG</returns>
	static bool CollisionRect(Base* b1, Base* b2);

	/// <summary>
	/// �I�u�W�F�N�g�̌���
	/// </summary>
	/// <param name="type">��������I�u�W�F�N�g�̎��</param>
	/// <returns>�������I�u�W�F�N�g�̃��X�g</returns>
	static std::list<Base*> FindObjects(BaseType type);
};