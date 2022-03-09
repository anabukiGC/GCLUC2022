#pragma once
#include "../Base/Base.h"


class Boss : public Base
{
	enum {//�����ԍ���U��(0�`�j
		eIdle,
		eRun,
		eAttack1,
		eAttack2,
		eDamage,

	};

	//���
	int m_state;

	int m_cnt = 0;//���Ԕ��ʗp

	//�U���G�t�F�N�g�t���O
	bool m_attack_effect;
	//��ԕ���

	void StateIdle();//�����I�ȁi����I�ȁj�����Ȃ̂ł�₱�����Ȃ�Ȃ��悤�ɂ�������(void)
	void StateRun();
	void StateAttack1();
	void StateAttack2();
	void StateDamage();

public:
	Boss(const CVector3D& pos, int k); //k=��ޕ����ԍ�

	void Update();
	void Draw();
private:

};