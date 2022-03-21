#include "Enemy.h"
#include"Bullet.h"
#include"PlayerEffect.h"
#include"EnemyManager.h"
#include"../Global.h"
#include "AttackObject.h"
#include "Debuff.h"
#include "Laser.h"
#include "EnemyBullet.h"

const float Enemy::speed = 3.0;//�ǂ��ł��g����悤��

Enemy::Enemy(const CVector3D& pos, int k, bool flip) : Base(eType_Enemy, 1)/*����^�C�v����*/
{
	
	kind = k;
	switch (kind) {
		
	case EnemyData::eEnemy1:
		m_flip = flip;//�����ύX
		m_img = COPY_RESOURCE("Enemy2", CImage);
		m_max_hp = 200;//�ύX�p
		m_hp = m_max_hp;
		
		m_shadow_size = CVector2D(256,256);//�摜�T�C�Y�p
		m_pos = pos;
		m_bound = false;
		m_jump = false;
		m_e_hp = new EnemyHp(this);//�|�C���^�[�n���̂�this
		m_shadow = new Shadow(this,m_shadow_size);//�|�C���^�[�n���̂�this
		m_attack_effect = false;
		m_state = eRun;
		m_img.ChangeAnimation(0);
		m_img.SetCenter(128, 256);
		m_rect = RectBox(-88, 226, 98, 0, 32, -32);

		break;
	case EnemyData::eEnemy2:

		m_img = COPY_RESOURCE("Enemy1", CImage);

		m_flip = flip;//�����ύX
		m_hp = 200;//�ύX�p
		m_max_hp = 200;
		m_shadow_size = CVector2D(256, 256);//�摜�T�C�Y�p
		m_pos = pos;
		m_bound = false;
		m_jump = false;
		m_e_hp = new EnemyHp(this);//�|�C���^�[�n���̂�this
		m_shadow = new Shadow(this, m_shadow_size);//�|�C���^�[�n���̂�this
		m_attack_effect = false;
		m_state = eRun;
		m_img.ChangeAnimation(0);
		m_img.SetCenter(128, 256);
		m_rect = RectBox(-88, 226, 98, 0, 32, -32);

		break;
	
	case EnemyData::eEnemy3:

		m_img = COPY_RESOURCE("Bonus", CImage);

		m_flip = flip;//�����ύX
		m_hp = 200;//�ύX�p
		m_max_hp = 200;
		m_shadow_size = CVector2D(256, 256);//�摜�T�C�Y�p
		m_pos = pos;
		m_bound = false;
		m_e_hp = new EnemyHp(this);//�|�C���^�[�n���̂�this
		m_shadow = new Shadow(this, m_shadow_size);//�|�C���^�[�n���̂�this
		m_attack_effect = false;
		m_state = eRun;
		m_img.ChangeAnimation(0);
		m_img.SetCenter(128, 256);
		m_rect = RectBox(-88, 226, 98, 0, 32, -32);

		break;
}
	m_debuff = false;
	m_debuffTime = 0;
	Fire = false;
}

void Enemy::StateAway()
{
	m_invin = true;
	m_img.ChangeAnimation(4,false);
	if (m_img.CheckAnimationEnd()) {
		SetKill();
		if (m_e_hp) {//�����������Ă���
			m_e_hp->SetKill();
			m_e_hp = NULL;//���������p

		}
		if (m_shadow) {//�����������Ă���
			m_shadow->SetKill();
			m_shadow = NULL;//���������p

		}
		m_invin = false;
	}

}

void Enemy::StateAttack()
{
	if(kind== EnemyData::eEnemy1){
	m_invin = true;
	const float jump_pow = 10.0f;
	int jump_time = 10;

	m_img.ChangeAnimation(1, false);

	if (m_img.GetIndex() >= 2 ) {//�ړ�
		if (m_flip == true) {
			m_pos.x -= speed;
		}
		else m_pos.x += speed;
	}

	
	if (m_jump == false && m_img.GetIndex() >= 2) {
		
		m_jump = true;
		
		m_vec.y += jump_pow;
		
		
	
	
}
	
	
	if (m_img.CheckAnimationEnd()) {
		new AttackObject(eType_EnemyAttack1, CVector3D(m_pos.x - 200, m_pos.y, m_pos.z), RectBox(-64, 128, 64, 0, 16, -16));
		new AttackObject(eType_EnemyAttack1, CVector3D(m_pos.x + 200, m_pos.y, m_pos.z), RectBox(-64, 128, 64, 0, 16, -16));
		m_state = eRun;
		m_invin = false;
		m_cnt = 0;
	}
	}
	if (kind == EnemyData::eEnemy2) {//�������G
		m_invin = true;

		m_img.ChangeAnimation(1, false);
		if (m_img.GetIndex() >= 2)
		{
			if (!Fire)
			{
				if (m_flip)
					new EnemyBullet(eType_EnemyBullet, CVector3D(m_pos.x + 100, m_pos.y + 100, m_pos.z), m_flip);
				else
					new EnemyBullet(eType_EnemyBullet, CVector3D(m_pos.x - 100, m_pos.y + 100, m_pos.z), m_flip);
			}
			Fire = true;
		}
		if (m_img.CheckAnimationEnd()) {
		
			m_state = eRun;
			m_invin = false;
			m_cnt = 0;
		}
	}
	if (kind == EnemyData::eEnemy3) {//�{�[�i�X�G
		m_invin = true;

		m_img.ChangeAnimation(1, false);
		if (m_img.CheckAnimationEnd()) {

			m_state = eRun;
			m_invin = false;
			m_cnt = 0;
			m_bonus++;

		}
	}
}

void Enemy::StateRun()
{

	
	m_jump = false;
	m_img.ChangeAnimation(0);
	if(kind==EnemyData::eEnemy1){
	if (m_flip == true) {//�ړ�
		m_pos.x -= speed;
	}
	else m_pos.x += speed;

	if (m_scroll.x > m_pos.x) {
		m_flip = false;
	}
	else if (m_scroll.x + 1900 < m_pos.x) {
		m_flip = true;
	}
}//�G�P
	if (kind == EnemyData::eEnemy3) {
		if (m_flip == true) {//�ړ�
			m_pos.x -= speed*2;
		}
		else m_pos.x += speed*2;

		if (m_scroll.x > m_pos.x) {
			m_flip = false;
		}
		else if (m_scroll.x + 1900 < m_pos.x) {
			m_flip = true;
		}
	}//�G3


	if (m_bound == false) {//�W�O�U�O�ړ�
		m_pos.z -= speed;
	}
	else if (m_bound == true) {
		m_pos.z += speed;
	}

	if (m_pos.z <= 0) {//���˂�����O�`�T�O�O�܂łŗǂ�
		m_bound = true;
	}
	else if (m_pos.z >= GROUND) {
		m_bound = false;
	}





}


void Enemy::StateDamage()
{
	m_img.ChangeAnimation(2, false);

	if (m_img.CheckAnimationEnd() && m_hp > 0) {
		m_state = eRun;
		m_cnt = 0;
	}
	if (m_img.CheckAnimationEnd() && m_hp <= 0) {
		m_state = eDie;
	}
}


void Enemy::StateDie()
{
	m_invin = true;
	m_img.ChangeAnimation(3, false);

	
	if (m_img.CheckAnimationEnd()) {
		m_invin = false;
		SetKill();
		if (kind == EnemyData::eEnemy1 || kind == EnemyData::eEnemy2) {
			g_score += 100;
		}else g_score += 2000;


		if (m_e_hp) {//�����������Ă���
			m_e_hp->SetKill();
			m_e_hp = NULL;//���������p

		}
		if (m_shadow) {//�����������Ă���
			m_shadow->SetKill();
			m_shadow = NULL;//���������p

		}
	}
}

int Enemy::GetHp()
{
	return m_hp;
	

}

int Enemy::GetMaxHp()
{
	return m_max_hp;


}
void Enemy::Update()
{

	m_cnt++;
	//��Ԃɂ�镪�򐧌�
	switch (m_state) {
	case eAway:
		StateAway();
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
	case eDie:
		StateDie();
		break;
	}


	/*if (m_cnt % 60 == 0) {
		m_hp -= 10;
	}*/
	
	


	m_vec.y -= GRAVITY;
	m_pos.y += m_vec.y;

	
	if (m_pos.y <= 0) {//���@�n�ʗp
		m_pos.y = 0;
		m_vec.y = 0;
		
	}

	

	if (kind == EnemyData::eEnemy3 && m_cnt == 120) {//�b���ŏ�ԑJ��
		m_state = eAttack;
		//m_hp -= 100;
	}

	if (kind== EnemyData::eEnemy1 &&m_cnt==180) {//�b���ŏ�ԑJ��
		m_state = eAttack;
		//m_hp -= 100;
	}

	if (kind == EnemyData::eEnemy2 && m_cnt == 240) {//�b���ŏ�ԑJ��
		m_state = eAttack;
		Fire = false;
	}
	 
	if (kind == EnemyData::eEnemy3 && m_bonus == 4) {
		m_state = eAway;
	}

	if (m_hp <= 0) {
		m_state = eDie;

	}
	m_img.UpdateAnimation();

	if (m_debuffTime < 0)
	{
		m_debuff = true;
	}
	else
	{
		m_debuff = false;
	}
}

void Enemy::Collision(Task* t)
{
	switch (t->GetID())
	{
	case eType_NomalBullet:

		if (Bullet* bullet = dynamic_cast<Bullet*>(t)){
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
					m_hp -= 4;
				}
				else if (!m_debuff)
				{
					m_hp -= 2;
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
void Enemy::Draw()
{
	if (m_e_hp) {//�����������Ă���NULL�΍��p
	
		m_e_hp->m_pos = m_pos;//�Q�[�W�Ɏ����̍��W�����Ă��钲���\
		
	}
	Base::Draw3D();
}

