#include "Boss.h"
#include"EnemyManager.h"

Boss::Boss(const CVector3D& pos, int k) :Base(eType_Boss, 1)
{
	kind = k;
	switch (kind) {

	case EnemyData::eBoss:
		m_img = COPY_RESOURCE("Boss1", CImage);


		m_pos = pos;

		m_flip = false;
		m_jump = false;
		m_attack_effect = false;
		m_state = eIdle;
		m_img.SetCenter(128*2, 256*2);
		m_rect = RectBox(-128*2, 256*2, 128*2, 0, 32, -32);

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

void Boss::StateAttack1()
{
	m_img.ChangeAnimation(1, false);
	if (m_img.CheckAnimationEnd()) {
		m_state = eIdle;
		m_cnt = 0;
	}

}

void Boss::StateAttack2()
{
	
	m_img.ChangeAnimation(2, false);
	if (m_img.CheckAnimationEnd()) {
		m_state = eIdle;
		m_cnt = 181;
	}
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
	case eAttack1:
		StateAttack1();
		break;
	case eAttack2:
		StateAttack2();
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
		m_state = eAttack1;
	}
	if (kind == 1 && m_cnt == 360) {//ïbêîÇ≈èÛë‘ëJà⁄
		m_state = eAttack2;
	}
	m_img.UpdateAnimation();
}

void Boss::Draw()
{
	Base::Draw3D();
}
