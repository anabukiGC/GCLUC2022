#include "PlayerEffect.h"
#include "Debuff.h"
#include"Bullet.h"
#include "Boss2.h"
#include"TaskManager.h"
#include"Meteor.h"
#include "AttackObject.h"
#include "BossLaser.h"
#include "Laser.h"

const float Boss2::speed = 3.0;//どこでも使えるように
Boss2::Boss2(const CVector3D& pos) :Base(eType_Boss, ePriorityEnemy)
{
	SOUND("Boss")->Stop();
	SOUND("Boss2")->Play(true);
	m_img = COPY_RESOURCE("Boss2", CImage);
	m_max_hp = 3000;
	m_hp = m_max_hp;//変更用
	m_size = 512;
	m_pos = pos;
	m_shadow = new Shadow(this);//ポインター渡すのでthis
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
	if (m_bound == false) {//縦移動
		m_pos.z -= speed;
	}
	else if (m_bound == true) {
		m_pos.z += speed;
	}


	if (m_pos.z <= 0) {//跳ねかえるO〜500まで
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
	m_img.ChangeAnimation(1, false);//近接攻撃
	if (m_img.GetIndex() == 2 && Fire == false) {//移動
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
	m_img.ChangeAnimation(2, false);//近接攻撃
	if (m_img.GetIndex() == 3 && Fire == false) {//移動
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
	m_img.ChangeAnimation(3, false);//隕石攻撃
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
		m_b2_hp = new Boss2Hp(this);//ポインター渡すのでthis
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
		if (m_b2_hp) {//ｈｐを持ってたら

			m_b2_hp->SetKill();
			m_b2_hp = NULL;//消えた時用

		}
	}
}
void Boss2::Update()
{
	m_cnt++;
	m_second = m_cnt / 60;//秒数に変換
	//状態による分岐制御
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






	if (m_pos.y <= 0) {//仮　地面用
		m_pos.y = 0;
		m_vec.y = 0;

	}
	if (m_meteo) {//隕石処理
		m_meteo_time++;
			if (m_meteo_time > 30) {//隕石間隔
				new Meteor( CVector3D(
					Utility::Rand(m_pos.x-1800.0f, m_pos.x-0.0f),//X
					1200,//Y
					Utility::Rand(0.0f, 450.0f)));//Z
				m_meteo_time = 0;
			}
	}


	if (m_invin == false && m_second == 3) {//秒数で状態遷移
		Fire = false;
		m_state = eAttack1;
	}
	if (m_invin == false && m_second == 8) {//秒数で状態遷移
		Fire = false;
		m_state = eAttack2;
	}






	if (m_hp <= 0) {
		m_state = eDie;

	}
	m_img.UpdateAnimation();
	//優先度変更
	ChangePriority(ePriorityEnemy + m_pos.z);
}

void Boss2::Draw()
{
	if (m_b2_hp) {//ｈｐを持ってたらNULL対策用

		m_b2_hp->m_pos = CVector3D(m_pos.x - 100, m_pos.y, m_pos.z);//ゲージに自分の座標を入れている調整可能

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
