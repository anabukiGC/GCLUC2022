#include "Enemy.h"
#include "../Global.h"

const float Enemy::speed = 3.0;//�ǂ��ł��g����悤��

Enemy::Enemy(const CVector3D& pos, int k) : Base(eType_Enemy, 1)/*����^�C�v����*/
{
	kind = k;
	switch (kind) {
		
	case 1:

		m_img = COPY_RESOURCE("Enemy2", CImage);
		
		m_hp = 100;//�ύX�p
		m_max_hp = 100;
		m_pos = pos;
		m_flip = true;
		m_bound = false;
		m_jump = false;
		m_e_hp = new EnemyHp(this);//�|�C���^�[�n���̂�this
		m_attack_effect = false;
		m_state = eRun;
		m_img.ChangeAnimation(0);
		m_img.SetCenter(128, 256);
		m_rect = RectBox(-128, 256, 128, 0, 32, -32);

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

void Enemy::StateIdle()
{
}

void Enemy::StateAttack()
{
	const float jump_pow = 10.0f;
	int jump_time = 10;

	m_img.ChangeAnimation(1, false);

	if (m_img.GetIndex() >= 2 ) {
		if (m_flip == true) {
			m_pos.x -= speed;
		}
		else m_pos.x += speed;
	}

	
	if (m_jump == false && m_img.GetIndex() >= 2) {
		
		m_jump = true;
		
		m_vec.y += jump_pow;
		
		
	
	
}
	//for (int i = 0; i <= jump_time; i++) {}
		
	
	
	if (m_img.CheckAnimationEnd()) {
		m_state = eRun;
		m_cnt = 0;
	}
}

void Enemy::StateRun()
{

	
	m_jump = false;
	m_img.ChangeAnimation(0);


	m_pos.x -= speed;
	if (m_bound == false) {
		m_pos.z -= speed;
	}
	else if (m_bound == true) {
		m_pos.z += speed;
	}

	if (m_pos.z <= -200) {//���˂�����
		m_bound = true;
	}
	else if (m_pos.z >= 500) {
		m_bound = false;
	}


}


void Enemy::StateDamage()
{
}


void Enemy::StateDie()
{
	m_img.ChangeAnimation(2, false);


	if (m_img.CheckAnimationEnd()) {
		SetKill();
		if (m_e_hp) {//�����������Ă���
			m_e_hp->SetKill();
			m_e_hp = NULL;//���������p
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

	


	if (kind==1 &&m_cnt==180) {//�b���ŏ�ԑJ��
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

void Enemy::Collision(Base* b)
{
	switch (b->m_type) {
	case eType_NomalBullet:
		if (Base::CollisionRect(this, b))
		{
			m_hp -= 10;
			

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

