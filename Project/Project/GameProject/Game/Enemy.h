#pragma once
#include "../Base/Base.h"


class Enemy : public Base
{
	enum {//�����ԍ���U��(0�`�j
		eIdle,
		eJump,
		eRun,
		eAttack,
		eDamage,
		
	};

	//���
	int m_state;

	//�U���G�t�F�N�g�t���O
	bool m_attack_effect;
	//��ԕ���
	
	void StateIdle();//�����I�ȁi����I�ȁj�����Ȃ̂ł�₱�����Ȃ�Ȃ��悤�ɂ�������(void)
	void StateJump();
	void StateRun();
	void StateAttack();
	void StateDamage();

public:
	Enemy(const CVector3D& pos,int k); //k=��ޕ����ԍ�

	void Update();
	void Draw();
private:

};