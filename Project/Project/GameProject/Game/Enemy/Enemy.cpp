#include "Enemy.h"
#include"../Game/Bullet.h"
#include"EnemyManager.h"
#include"../Global.h"

const float Enemy::speed = 3.0;//�ǂ��ł��g����悤��

Enemy::Enemy(const CVector3D& pos, int k) : Base(eType_Enemy, 1)/*����^�C�v����*/
{
	kind = k;
	switch (kind) {
		
	case EnemyData::eEnemy1:

		m_img = COPY_RESOURCE("Enemy2", CImage);
		
		m_hp = 200;//�ύX�p
		m_max_hp = 200;
		m_pos = pos;
		m_flip = true;
		m_bound = false;
		m_jump = false;
		m_e_hp = new EnemyHp(this);//�|�C���^�[�n���̂�this
		m_shadow = new Shadow(this);//�|�C���^�[�n���̂�this
		m_attack_effect = false;
		m_state = eRun;
		m_img.ChangeAnimation(0);
		m_img.SetCenter(128, 256);
		m_rect = RectBox(-128, 256, 128, 0, 32, -32);

		break;
	case EnemyData::eEnemy2:

		m_img = COPY_RESOURCE("Enemy2", CImage);


		m_pos = pos;
		m_flip = true;
		m_jump = false;
		m_attack_effect = false;
		m_state = eRun;


		break;
	}

}

void Enemy::StateIdle()
{
}

void Enemy::StateAttack()
{
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
		m_state = eRun;
		m_cnt = 0;
	}
}

void Enemy::StateRun()
{

	
	m_jump = false;
	m_img.ChangeAnimation(0);

	if (m_flip == true) {//�ړ�
		m_pos.x -= speed;
	}
	else m_pos.x += speed;

	
	if (m_bound == false) {//�W�O�U�O�ړ�
		m_pos.z -= speed;
	}
	else if (m_bound == true) {
		m_pos.z += speed;
	}

	if (m_pos.z <= 600) {//���˂�����O�`�T�O�O�܂łŗǂ�
		m_bound = true;
	}
	else if (m_pos.z >= 1000) {
		m_bound = false;
	}

	if (m_scroll.x > m_pos.x) {
		m_flip = false;
	}
	else if (m_scroll.x + 1900 < m_pos.x) {
		m_flip = true;
	}



}


void Enemy::StateDamage()
{
	m_img.ChangeAnimation(2, false);

	if (m_img.CheckAnimationEnd() && m_hp > 0) {
		m_state = eRun;
		m_hp -= 200;
		m_cnt = 0;
	}
	if (m_img.CheckAnimationEnd() && m_hp <= 0) {
		m_state = eDie;
	}
}


void Enemy::StateDie()
{
	m_img.ChangeAnimation(3, false);


	if (m_img.CheckAnimationEnd()) {
		SetKill();
		g_score += 100;
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
	case eDie:
		StateDie();
		break;
	}


	if (m_cnt % 60 == 0) {
		m_hp -= 10;
	}
	
	


	m_vec.y -= GRAVITY;
	m_pos.y += m_vec.y;

	
	if (m_pos.y <= 0) {//���@�n�ʗp
		m_pos.y = 0;
		m_vec.y = 0;
		
	}

	


	if (kind== EnemyData::eEnemy1 &&m_cnt==180) {//�b���ŏ�ԑJ��
		m_state = eAttack;
		//m_hp -= 100;
	}

	if (kind == 2 && m_cnt == 300) {//�b���ŏ�ԑJ��
		m_state = eAttack;
	}


	if (m_hp <= 0) {
		m_state = eDie;

	}
	m_img.UpdateAnimation();
	
}

void Enemy::Collision(Task* t)
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
void Enemy::Draw()
{
	if (m_e_hp) {//�����������Ă���NULL�΍��p
	
		m_e_hp->m_pos = m_pos;//�Q�[�W�Ɏ����̍��W�����Ă��钲���\
		
	}
	Base::Draw3D();
}

