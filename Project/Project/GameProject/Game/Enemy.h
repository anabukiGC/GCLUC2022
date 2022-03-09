#pragma once
#include "../Base/Base.h"


class Enemy : public Base
{
	enum {//�����ԍ���U��(0�`�j
		eIdle,
		eRun,
		eAttack,
		eDamage,
		eDie
		
	};

	//���
	int m_state;
	
	int m_cnt = 0;//���Ԕ��ʗp

	int m_hp = 0;

	bool m_bound;

	static const float speed;

	//�U���G�t�F�N�g�t���O
	bool m_attack_effect;
	//��ԕ���
	
	void StateIdle();//�����I�ȁi����I�ȁj�����Ȃ̂ł�₱�����Ȃ�Ȃ��悤�ɂ�������(void)
	void StateRun();
	void StateAttack();
	void StateDamage();
	void StateDie();

public:
	Enemy(const CVector3D& pos,int k); //k=��ޕ����ԍ�

	void Update();
	void Draw();
private:

};