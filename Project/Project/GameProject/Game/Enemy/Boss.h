#pragma once
#include "Base.h"
#include"BossHP.h"
#include"Game.h"

class Boss : public Base
{
	enum {//�����ԍ���U��(0�`�j
		eIdle,
		eRun,
		eAttack1,
		eAttack2,
		eDamage,
		eDie,
	};

	//���
	int m_state;

	

	int m_hp = 0;
	int m_max_hp = 0;

	int m_cnt = 0;//���Ԕ��ʗp

	//�U���G�t�F�N�g�t���O
	bool m_attack_effect;
	//��ԕ���

	void StateIdle();//�����I�ȁi����I�ȁj�����Ȃ̂ł�₱�����Ȃ�Ȃ��悤�ɂ�������(void)
	void StateRun();
	void StateAttack1();
	void StateAttack2();
	void StateDamage();
	void StateDie();


	void Update();
	void Draw();

public:
	Boss(const CVector3D& pos, int k); //k=��ޕ����ԍ�
	int GetHp();//Hp�̎擾
	int GetMaxHp();//Hp�̎擾
	BossHp* m_b_hp;
	Game* m_game;
	void Collision(Task* t);
};