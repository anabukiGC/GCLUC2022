#pragma once
#include "../Base/Base.h"
#include "PlayerHP.h"
#include "../TaskSystem/TaskManager.h"

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

private:
	//���
	enum 
	{
		eState_Idle,
		eState_Jump,
		eState_Attack1,
		eState_Attack2,
		eState_Attack3,
	};


	//��ԕϐ�
	int m_state;

	//���n�t���O
	bool m_bound;

	//�W�����v�����n�n�_���W�擾
	float JumpPosition;
	//��x����Y���W���擾���邽�߂̃t���O
	bool GetY;
	//�W�����v����
	int JumpTime;


	//�e��Ԃł̋���
	void StateIdle();
	void StateJump();
	void StateAttack1();
	void StateAttack2();
	void StateAttack3();

	int time;
};