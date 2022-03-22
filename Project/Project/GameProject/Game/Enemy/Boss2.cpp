#include "PlayerEffect.h"
#include "Debuff.h"
#include"Bullet.h"
#include "Boss2.h"
#include"TaskManager.h"
#include"Meteor.h"
#include "AttackObject.h"
#include "BossLaser.h"
#include "Laser.h"

const float Boss2::speed = 3.0;//Ç«Ç±Ç≈Ç‡égÇ¶ÇÈÇÊÇ§Ç…
Boss2::Boss2(const CVector3D& pos) :Base(eType_Boss, ePriorityEnemy)
{
	SOUND("Boss")->Stop();
	SOUND("Boss2")->Play(true);
	m_img = COPY_RESOURCE("Boss2", CImage);
	m_max_hp = 3000;
	m_hp = m_max_hp;//ïœçXóp
	m_size = 512;
	m_pos = pos;
	m_shadow = new Shadow(this);//É|ÉCÉìÉ^Å[ìnÇ∑ÇÃÇ≈this
	m_meteo = false;
	m_invin = true;
	m_flip = false;
	m_attack_effect = false;
	m_img.ChangeAnimation(0);
	m_state = eChange;
	m_img.SetCenter(128 * 2, 256 * 2);
	m_rect = RectBox(-128 * 2, 256 * 2, 128 * 2, 0, 32, -32);
	
	m_debuffTime = 0; 
	m_debuff = false;
}
void Boss2::StateIdle()
{
	m_img.ChangeAnimation(0);
	if (m_bound == false) {//ècà⁄ìÆ
		m_pos.z -= speed;
	}
	else if (m_bound == true) {
		m_pos.z += speed;
	}


	if (m_pos.z <= 0) {//íµÇÀÇ©Ç¶ÇÈOÅ`500Ç‹Ç≈
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
	m_invin = true;
	m_img.ChangeAnimation(1, false);//ãﬂê⁄çUåÇ
	if (m_img.GetIndex() == 2 && Fire == false) {//à⁄ìÆ
		new AttackObject(eType_BossAttack1, CVector3D(m_pos.x - 500, m_pos.y, m_pos.z), m_rect);
		Fire = true;
	}
	if (m_img.CheckAnimationEnd()) {
		m_invin = false;
		m_cnt = 240;
		m_second = 4;
		m_state = eIdle;
	}
}

void Boss2::StateAttack2()
{
	m_invin = true;
	m_img.ChangeAnimation(2, false);//ãﬂê⁄çUåÇ
	if (m_img.GetIndex() == 3 && Fire == false) {//à⁄ìÆ
		new BossLaser(CVector3D(m_pos.x - 500, m_pos.y + 300, m_pos.z));
		Fire = true;
	}
	if (m_img.CheckAnimationEnd()) {
		m_invin = false;
		m_cnt = 0;
		m_second = 0;
		m_state = eIdle;
	}
}
void Boss2::StateAttack3()
{
	m_invin = true;
	m_img.ChangeAnimation(3, false);//Ë¶êŒçUåÇ
	if (m_img.CheckAnimationEnd()) {
		m_meteo = true;
		m_second = 0;
		m_invin = false;
		m_state = eIdle;
		
	}
}
void Boss2::StateDamage()
{
	m_img.ChangeAnimation(4, false);

	if (m_img.CheckAnimationEnd() && m_hp > 0) {

	
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
		m_b2_hp = new Boss2Hp(this);//É|ÉCÉìÉ^Å[ìnÇ∑ÇÃÇ≈this
		m_state = eAttack3;
		
	}
}
void Boss2::StateDie()
{
	m_invin = true;
	m_img.ChangeAnimation(6, false);


	if (m_img.CheckAnimationEnd()) {
		Game* g = dynamic_cast<Game*>(TaskManager::GetInstance()->GetTask(eType_Scene));
		g->m_clear = true;


		SetKill();
		if (m_b2_hp) {//ÇàÇêÇéùÇ¡ÇƒÇΩÇÁ

			m_b2_hp->SetKill();
			m_b2_hp = NULL;//è¡Ç¶ÇΩéûóp

		}
	}
}
void Boss2::Update()
{
	m_cnt++;
	m_second = m_cnt / 60;//ïbêîÇ…ïœä∑
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






	if (m_pos.y <= 0) {//âºÅ@ínñ óp
		m_pos.y = 0;
		m_vec.y = 0;

	}
	if (m_meteo) {//Ë¶êŒèàóù
		m_meteo_time++;
			if (m_meteo_time > 30) {//Ë¶êŒä‘äu
				new Meteor( CVector3D(
					Utility::Rand(m_pos.x-1800.0f, m_pos.x-0.0f),//X
					1200,//Y
					Utility::Rand(0.0f, 450.0f)));//Z
				m_meteo_time = 0;
			}
	}


	if (m_invin == false && m_second == 3) {//ïbêîÇ≈èÛë‘ëJà⁄
		Fire = false;
		m_state = eAttack1;
	}
	if (m_invin == false && m_second == 8) {//ïbêîÇ≈èÛë‘ëJà⁄
		Fire = false;
		m_state = eAttack2;
	}






	if (m_hp <= 0) {
		m_state = eDie;

	}
	m_img.UpdateAnimation();
	//óDêÊìxïœçX
	ChangePriority(ePriorityEnemy + m_pos.z);
}

void Boss2::Draw()
{
	if (m_b2_hp) {//ÇàÇêÇéùÇ¡ÇƒÇΩÇÁNULLëŒçÙóp

		m_b2_hp->m_pos = CVector3D(m_pos.x - 100, m_pos.y, m_pos.z);//ÉQÅ[ÉWÇ…é©ï™ÇÃç¿ïWÇì¸ÇÍÇƒÇ¢ÇÈí≤êÆâ¬î\

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

		if (Bullet* bullet = dynamic_cast<Bullet*>(t)) {
			if (CollisionRect(bullet, this))
			{
				if (m_invin == false) {
					m_state = eDamage;
				}
				m_hp -= 20;

			}
		}
		break;
	case eType_NomalBullet2:

		if (Bullet* bullet = dynamic_cast<Bullet*>(t)) {
			if (CollisionRect(bullet, this))
			{
				if (m_invin == false) {
					m_state = eDamage;
				}
				m_hp -= 15;

			}
		}
		break;
	case eType_ChargeBullet:

		if (Bullet* bullet = dynamic_cast<Bullet*>(t)) {
			if (CollisionRect(bullet, this))
			{
				if (m_invin == false) {
					m_state = eDamage;
				}
				if (m_debuff)
				{
					m_hp -= 40;
				}
				else if (!m_debuff)
				{
					m_hp -= 100;
				}
			}
		}
		break;
	case eType_Laser:

		if (Laser* bullet = dynamic_cast<Laser*>(t)) {
			if (CollisionRect(bullet, this))
			{
				if (m_invin == false) {
					m_state = eDamage;
				}
				if (m_debuff)
				{
					m_hp -= 4.0;
				}
				else if (!m_debuff)
				{
					m_hp -= 2.0;
				}
			}
		}
		break;
	case eType_PlayerEffect1:
		if (PlayerEffect* player = dynamic_cast<PlayerEffect*>(t)) {
			if (CollisionRect(player, this))
			{
				if (m_invin == false) {
					m_state = eDamage;
				}
				m_hp -= 20;

			}
		}
		break;
	case eType_PlayerEffect2:
		if (PlayerEffect* player = dynamic_cast<PlayerEffect*>(t)) {
			if (CollisionRect(player, this))
			{
				if (m_invin == false) {
					m_state = eDamage;
				}
				m_hp -= 30;
			}
		}
		break;
	case eType_PlayerEffect3:
		if (PlayerEffect* player = dynamic_cast<PlayerEffect*>(t)) {
			if (CollisionRect(player, this))
			{
				if (m_invin == false) {
					m_state = eDamage;
				}
				m_hp -= 50;
				new Debuff(CVector2D(this->m_pos.x, this->m_pos.y));
				m_debuffTime = 300;
			}
		}
		break;
	}
}
