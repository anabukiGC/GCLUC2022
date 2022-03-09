#include "Enemy.h"
#include "../Global.h"

const float Enemy::speed = 3.0;//どこでも使えるように

Enemy::Enemy(const CVector3D& pos, int k) : Base(0, 0)/*今後タイプ分け*/
{
	kind = k;
	switch (kind) {
		
	case 1:

		m_img = COPY_RESOURCE("Enemy2", CImage);
		

		m_pos = pos;
		m_flip = true;
		m_bound = false;
		m_jump = false;
		m_hp = 100;
		m_attack_effect = false;
		m_state = eRun;
		

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

	if (m_pos.z <= -200) {//跳ねかえる
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
		m_kill = true;
	}
}

void Enemy::Update()
{

	m_cnt++;
	//状態による分岐制御
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


	
	
	


	m_vec.y -= GRAVITY;
	m_pos.y += m_vec.y;

	
	if (m_pos.y <= 0) {//仮　地面用
		m_pos.y = 0;
		m_vec.y = 0;
		
	}

	


	if (kind==1 &&m_cnt==180) {//秒数で状態遷移
		m_state = eAttack;
		//m_hp -= 100;
	}

	if (kind == 2 && m_cnt == 300) {//秒数で状態遷移
		m_state = eAttack;
	}


	if (m_hp <= 0) {
		m_state = eDie;
	}
	m_img.UpdateAnimation();
	
}

void Enemy::Draw()
{
	Base::Draw3D();
}

