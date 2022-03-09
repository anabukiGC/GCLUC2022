#include "Boss.h"


Boss::Boss(const CVector3D& pos, int k):Base(0,0)
{
	kind = k;
	switch (kind) {

	case 1:

		m_img = COPY_RESOURCE("Enemy1", CImage);


		m_pos = pos;
		m_img.SetSize(700, 700);
		m_flip = true;
		m_jump = false;
		m_attack_effect = false;
		m_state = eIdle;


		break;
	case 2:

		m_img = COPY_RESOURCE("Enemy2", CImage);


		m_pos = pos;
		m_flip = true;
		m_jump = false;
		m_attack_effect = false;
		m_state = eRun;


		break;
	}

}

void Boss::StateIdle()
{
	m_img.ChangeAnimation(0);
}

void Boss::StateRun()
{
}

void Boss::StateAttack()
{
}

void Boss::StateDamage()
{
}


void Boss::Update()
{
	m_cnt++;
	//èÛë‘Ç…ÇÊÇÈï™äÚêßå‰
	switch (m_state) {
	case eIdle:
		StateIdle();
		break;
	case eRun:
		StateRun();
		break;
	case eAttack:
		StateAttack();
		break;
	case eDamage:
		StateDamage();
		break;
	}






	if (m_pos.y <= 0) {//âºÅ@ínñ óp
		m_pos.y = 0;
		m_vec.y = 0;

	}

	if (kind == 1 && m_cnt == 180) {//ïbêîÇ≈èÛë‘ëJà⁄
		m_state = eAttack;
	}

	m_img.UpdateAnimation();
}

void Boss::Draw()
{
	Base::Draw3D();
}
