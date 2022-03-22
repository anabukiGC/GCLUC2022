#pragma once

#include"BossHP.h"
#include"Shadow.h"
#include "Debuff.h"
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
	
	bool m_on;//�f�o�t�\���p
	float m_hp = 0;
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

	int m_second = 0;//�b��
	bool m_bound;//���˕Ԃ�p
	bool m_invin = false;//�U�����f�h�~
	bool Fire = false;//�U�����
	int m_debuffTime;
	bool m_debuff;
public:
	Boss(const CVector3D& pos); //k=��ޕ����ԍ�
	int GetHp();//Hp�̎擾
	int GetMaxHp();//Hp�̎擾
	BossHp* m_b_hp;
	Shadow* m_shadow;
	Debuff* m_b_debuff;
	void Collision(Task* t);
	
	CVector2D m_shadow_size;//�摜�T�C�Y�p
};