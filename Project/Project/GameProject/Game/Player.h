#pragma once
#include "../Base/Base.h"
#include "../TaskSystem/TaskManager.h"

class Player : public Base
{
public:
	Player(const CVector3D& pos, bool flip);

	void Update();
	void Draw();
	void Collision(Task* t);


private:
	//���
	enum 
	{
		eState_Idle,
		eState_Jump,
		eState_Attack,
	};

	//��ԕϐ�
	int m_state;

	//���n�t���O
	bool	m_is_ground;

	//�W�����v�����n�n�_���W�擾
	float JumpPosition;
	//��x����Y���W���擾���邽�߂̃t���O
	bool GetY;
	//�W�����v����
	int JumpTime;


	//�e��Ԃł̋���
	void StateIdle();
	void StateJump();
	void StateAttack();

	int time;
};