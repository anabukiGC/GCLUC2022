#pragma once

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
		eChange,
	};

	//���
	int m_state;

	

	int m_hp = 0;
	int m_max_hp = 0;

	int m_cnt = 0;//���Ԕ��ʗp

	static const float speed;
	//�U���G�t�F�N�g�t���O
	bool m_attack_effect;
	//��ԕ���

	void StateIdle();//�����I�ȁi����I�ȁj�����Ȃ̂ł�₱�����Ȃ�Ȃ��悤�ɂ�������(void)
	void StateRun();
	void StateAttack1();
	void StateAttack2();
	void StateDamage();
	void StateChange();


	void Update();
	void Draw();

	int m_second = 0;
	bool m_bound;//���˕Ԃ�p
	bool m_invin = false;//�U�����f�h�~
public:
	Boss(const CVector3D& pos); //k=��ޕ����ԍ�
	int GetHp();//Hp�̎擾
	int GetMaxHp();//Hp�̎擾
	BossHp* m_b_hp;
	Game* m_game;
	void Collision(Task* t);


};