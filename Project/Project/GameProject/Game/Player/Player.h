#pragma once
#include "Base.h"
#include "PlayerHP.h"
#include "TaskManager.h"

class Player : public Base
{
public:
	Player(const CVector3D& pos, bool flip);

	void Update();
	void Draw();
	void Collision(Task* t);
	int GetHp();//Hp�̎擾
	int GetMaxHp();//Hp�̎擾

	PlayerHp* m_p_hp;

	int m_hp = 0;
	int m_max_hp = 0;

	//�e�̒e��ł����t���O
	bool Fire;

	//�W�����v�t���O
	bool m_jump;
private:
	//���
	enum 
	{
		eState_Idle,
		eState_Jump,
		eState_JumpAttack,
		eState_Attack1,
		eState_Attack2,
		eState_Attack3,
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
	void StateAttack1();
	void StateAttack2();
	void StateAttack3();

	int time;

	int HoldTime;
};