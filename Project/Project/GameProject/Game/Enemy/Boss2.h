#pragma once
#include"Boss2HP.h"
#include"Game.h"

class Boss2 : public Base
{
	enum {//�����ԍ���U��(0�`�j
		eIdle,
		eRun,
		eAttack1,
		eAttack2,
		eDamage,
		eChange,
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
	void StateChange();
	void StateDie();


	void Update();
	void Draw();
	static const float speed;
	int m_second = 0;
	bool m_bound;//���˕Ԃ�p
	bool m_invin = false;//�U�����f�h�~
public:
	Boss2(const CVector3D& pos); //k=��ޕ����ԍ�
	int GetHp();//Hp�̎擾
	int GetMaxHp();//Hp�̎擾
	Boss2Hp* m_b2_hp;
	Game* m_game;
	void Collision(Task* t);
};