#pragma once
#include <GLLibrary.h>
#include <list>

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
class Base {
public:
	//�I�u�W�F�N�g�̎��
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
	//���a
	float m_rad;
	//��`
	CRect	m_rect;
	//�폜�t���O
	bool m_kill;
	//�X�N���[���l
	static CVector2D m_scroll;
	//�R���e�i
	static std::list<Base*> m_list;
public:
	
	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	/// <param name="type">�I�u�W�F�N�g�̎��</param>
	/// <returns></returns>
	Base(BaseType type);
	
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
	/// �S�ẴI�u�W�F�N�g�̍X�V
	/// </summary>
	static void UpdateAll();

	/// <summary>
	/// �S�ẴI�u�W�F�N�g�̕`��
	/// </summary>
	static void DrawAll();

	/// <summary>
	/// �S�ẴI�u�W�F�N�g�̏Փ˃`�F�b�N
	/// </summary>
	static void CollisionAll();
	
	/// <summary>
	/// �S�ẴI�u�W�F�N�g�̍폜�`�F�b�N
	/// </summary>
	static void CheckKillAll();
	
	/// <summary>
	/// �~���m�̔���
	/// </summary>
	/// <param name="b1">����I�u�W�F�N�g�P</param>
	/// <param name="b2">����I�u�W�F�N�g�Q</param>
	/// <returns>true:�ڐG</returns>
	static bool CollisionCircle(Base* b1, Base* b2);
	/// <summary>
	/// �I�u�W�F�N�g�̒ǉ�
	/// </summary>
	/// <param name="b">�ǉ�����I�u�W�F�N�g</param>
	static void Add(Base* b);

	/// <summary>
	/// �I�u�W�F�N�g�̌���
	/// </summary>
	/// <param name="type">��������I�u�W�F�N�g�̎��</param>
	/// <returns>��ԏ��߂Ɍ������I�u�W�F�N�g�ւ̃|�C���^</returns>
	static Base* FindObject(BaseType type);
	
	/// <summary>
	/// �I�u�W�F�N�g�̌���
	/// </summary>
	/// <param name="type">��������I�u�W�F�N�g�̎��</param>
	/// <returns>�������I�u�W�F�N�g�̃��X�g</returns>
	static std::list<Base*> FindObjects(BaseType type);


};