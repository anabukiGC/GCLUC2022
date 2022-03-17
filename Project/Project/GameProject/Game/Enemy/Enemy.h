#pragma once
#include "Base.h"
#include"EnemyHP.h"
#include"Shadow.h"
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
	int m_max_hp = 0;

	bool m_bound;

	//�W�����v�t���O
	bool m_jump;
	int kind = 0;//��ގ��ʗp

	static const float speed;

	//�U���G�t�F�N�g�t���O
	bool m_attack_effect;
	//��ԕ���
	
	void StateIdle();//�����I�ȁi����I�ȁj�����Ȃ̂ł�₱�����Ȃ�Ȃ��悤�ɂ�������(void)
	void StateRun();
	void StateAttack();
	void StateDamage();
	void StateDie();
	void Update();
	void Draw();
public:
	Enemy(const CVector3D& pos,int k); //k=��ޕ����ԍ�

	int GetHp();//Hp�̎擾
	int GetMaxHp();//Hp�̎擾

	void Collision(Task* t);
	EnemyHp* m_e_hp;
	Shadow* m_shadow;
};