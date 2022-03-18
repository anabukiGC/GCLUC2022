#pragma once
#include "Base.h"
#include "PlayerHP.h"
#include "TaskManager.h"

class Player : public Base
{
public:
	Player(int kind, const CVector3D& pos, bool flip);
	void Collision(Task* t);
	int GetHp();//Hp�̎擾
	int GetMaxHp();//Hp�̎擾

	PlayerHp* m_p_hp;

	int m_hp = 0;
	int m_max_hp = 0;

	int m_kind;
	enum
	{
		eSword,
		eGun,
	};
private:
	void Update();
	void Draw();

	//�摜�T�C�Y�g�劄��
	float m_scale;

	//�e�̒e��ł����t���O
	bool Fire;

	//�W�����v�t���O
	bool m_jump;

	CVector2D m_key_dir;

	//���
	enum 
	{
		eState_Idle,
		eState_Jump,
		eState_JumpAttack,
		eState_SwordAttack1,
		eState_SwordAttack2,
		eState_SwordAttack3,
		eState_GunAttack1,
		eState_GunAttack2,
		eState_GunAttack3,
		eState_Damage,
		eState_Die,
	};


	//��ԕϐ�
	int m_state;

	//�U����ԕϐ�
	int m_state_attack;
	int m_state_attack2;
	int m_state_attack3;

	//�U���R���{�P�\����
	int m_secondAttackTime;
	//���n�t���O
	bool m_bound;

	//���G����
	int m_mutekiTime;
	//�W�����v�����n�n�_���W�擾
	float JumpPosition;
	//��x����Y���W���擾���邽�߂̃t���O
	bool GetY;
	//�W�����v����
	int JumpTime;

	//���E��Rect
	RectBox RectRight;
	RectBox RectLeft;

	//�e��Ԃł̋���
	void StateIdle();
	void StateJump();
	void StateJumpAttack();
	void StateSwordAttack1();
	void StateSwordAttack2();
	void StateSwordAttack3();
	void StateGunAttack1();
	void StateGunAttack2();
	void StateGunAttack3();
	void StateDamage();
	void StateDie();

	int time;

	int HoldTime;
};