

#include"Bullet.h"
#include "Boss2.h"
#include"TaskManager.h"

Boss2::Boss2(const CVector3D& pos) :Base(eType_Boss, 1)
{

	m_img = COPY_RESOURCE("Boss1", CImage);

	m_hp = 500;//�ύX�p
	m_max_hp = 500;
	m_pos = pos;
	m_b2_hp = new Boss2Hp(this);//�|�C���^�[�n���̂�this
	m_flip = false;
	m_attack_effect = false;
	m_state = eIdle;
	m_img.SetCenter(128 * 2, 256 * 2);
	m_rect = RectBox(-128 * 2, 256 * 2, 128 * 2, 0, 32, -32);

}
void Boss2::StateIdle()
{
	m_img.ChangeAnimation(0);
}

void Boss2::StateRun()
{

}

void Boss2::StateAttack1()
{
	m_img.ChangeAnimation(1, false);//�������U��
	if (m_img.CheckAnimationEnd()) {
		m_state = eIdle;
		m_cnt = 181;
	}
}

void Boss2::StateAttack2()
{
	m_img.ChangeAnimation(2, false);//�ߐڍU��
	if (m_img.CheckAnimationEnd()) {
		m_state = eIdle;
		m_cnt = 0;
	}
}

void Boss2::StateDamage()
{
	m_img.ChangeAnimation(3, false);

	if (m_img.CheckAnimationEnd() && m_hp > 0) {

		m_hp -= 200;
		m_cnt = 0;
		m_state = eIdle;
	}
	if (m_img.CheckAnimationEnd() && m_hp <= 0) {
		m_state = eDie;
	}
}

void Boss2::StateDie()
{
	m_img.ChangeAnimation(4, false);


	if (m_img.CheckAnimationEnd()) {
		Game* g = dynamic_cast<Game*>(TaskManager::GetInstance()->GetTask(eType_Scene));
		g->m_clear = true;


		SetKill();
		if (m_b2_hp) {//�����������Ă���

			m_b2_hp->SetKill();
			m_b2_hp = NULL;//���������p

		}
	}
}

void Boss2::Update()
{
	m_cnt++;
	//��Ԃɂ�镪�򐧌�
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
	case eDie:
		StateDie();
		break;
	}






	if (m_pos.y <= 0) {//���@�n�ʗp
		m_pos.y = 0;
		m_vec.y = 0;

	}

	if (m_cnt == 180) {//�b���ŏ�ԑJ��
		m_state = eAttack1;
	}
	if (m_cnt == 360) {//�b���ŏ�ԑJ��
		m_state = eAttack2;
	}


	if (m_hp <= 0) {
		m_state = eDie;

	}
	m_img.UpdateAnimation();
}

void Boss2::Draw()
{
	if (m_b2_hp) {//�����������Ă���NULL�΍��p

		m_b2_hp->m_pos = CVector3D(m_pos.x - 100, m_pos.y, m_pos.z);//�Q�[�W�Ɏ����̍��W�����Ă��钲���\

	}
	Base::Draw3D();
}


int Boss2::GetHp()
{
	return m_hp;
}

int Boss2::GetMaxHp()
{
	return m_max_hp;
}

void Boss2::Collision(Task* t)
{
	switch (t->GetID())
	{
	case eType_NomalBullet:
		if (Bullet* bullet = dynamic_cast<Bullet*>(t))
		{
			if (CollisionRect(bullet, this))
			{
				m_state = eDamage;
			}
		}
		break;
	}
}
