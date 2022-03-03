#pragma once
#include <GLLibrary.h>
#include <list>
#include "../TaskSystem/Task.h"

class Map;

//��ނ̗�
enum  BaseType{
	eType_Field,
	eType_Player,
	eType_Enemy,
	eType_Bullet,
	eType_Effect,
	eType_UI,
};
#define GRAVITY (9.8f/60)
#define GROUND (500)
class Base : public Task{
public:
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
	//���a
	float m_rad;
	//��`
	CRect	m_rect;
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
	/// �~���m�̔���
	/// </summary>
	/// <param name="b1">����I�u�W�F�N�g�P</param>
	/// <param name="b2">����I�u�W�F�N�g�Q</param>
	/// <returns>true:�ڐG</returns>
	static bool CollisionCircle(Base* b1, Base* b2);
	
	/// <summary>
	/// �I�u�W�F�N�g�̌���
	/// </summary>
	/// <param name="type">��������I�u�W�F�N�g�̎��</param>
	/// <returns>�������I�u�W�F�N�g�̃��X�g</returns>
	static std::list<Base*> FindObjects(BaseType type);
};