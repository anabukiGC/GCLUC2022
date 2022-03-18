

#include"Bullet.h"
#include "Boss2.h"
#include"TaskManager.h"
#include"Meteor.h"
const float Boss2::speed = 3.0;//�ǂ��ł��g����悤��
Boss2::Boss2(const CVector3D& pos) :Base(eType_Boss, 1)
{

	m_img = COPY_RESOURCE("Boss2", CImage);
	m_max_hp = 5000;
	m_hp = m_max_hp;//�ύX�p
	m_size = 512;
	m_pos = pos;
	m_shadow = new Shadow(this);//�|�C���^�[�n���̂�this
	m_meteo = false;
	m_invin = true;
	m_flip = false;
	m_attack_effect = false;
	m_state = eChange;
	m_img.SetCenter(128 * 2, 256 * 2);
	m_rect = RectBox(-128 * 2, 256 * 2, 128 * 2, 0, 32, -32);
	
}
void Boss2::StateIdle()
{
	m_img.ChangeAnimation(0);
	if (m_bound == false) {//�c�ړ�
		m_pos.z -= speed;
	}
	else if (m_bound == true) {
		m_pos.z += speed;
	}


	if (m_pos.z <= 0) {//���˂�����O�`500�܂�
		m_bound = true;
	}
	else if (m_pos.z >= 500) {
		m_bound = false;
	}
}

void Boss2::StateRun()
{

}

void Boss2::StateAttack1()
{
	
}

void Boss2::StateAttack2()
{
	m_img.ChangeAnimation(2, false);//�ߐڍU��
	if (m_img.CheckAnimationEnd()) {
	
	}
}
void Boss2::StateAttack3()
{
	
	m_img.ChangeAnimation(3, false);//覐΍U��
	if (m_img.CheckAnimationEnd()) {
		m_meteo = true;
		m_state = eIdle;
		m_invin = false;
	}
}
void Boss2::StateDamage()
{
	m_img.ChangeAnimation(4, false);

	if (m_img.CheckAnimationEnd() && m_hp > 0) {

		m_hp -= 200;
		m_cnt = 0;
		m_state = eIdle;
	}
	if (m_img.CheckAnimationEnd() && m_hp <= 0) {
		m_state = eDie;
	}
}

void Boss2::StateChange()
{
	
	m_img.ChangeAnimation(5, false);


	if (m_img.CheckAnimationEnd()) {
		m_b2_hp = new Boss2Hp(this);//�|�C���^�[�n���̂�this
		m_state = eAttack3;
		m_invin = false;
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
	case eAttack3:
		StateAttack3();
		break;
	case eDamage:
		StateDamage();
		break;
	case eChange:
		StateChange();
		break;
	case eDie:
		StateDie();
		break;
	}






	if (m_pos.y <= 0) {//���@�n�ʗp
		m_pos.y = 0;
		m_vec.y = 0;

	}
	if (m_meteo) {//覐Ώ���
		m_meteo_time++;
			if (m_meteo_time > 30) {
				new Meteor( CVector3D(
					Utility::Rand(m_pos.x-1800.0f, m_pos.x-0.0f),//X
					1200,//Y
					Utility::Rand(0.0f, 450.0f)));//Z
				m_meteo_time = 0;
			}
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
				if (m_invin == false) {
					m_state = eDamage;
				}
				else
					m_hp -= 200;
			}
		}
		break;
	}
}
