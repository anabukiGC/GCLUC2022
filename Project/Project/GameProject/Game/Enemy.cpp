#include "Enemy.h"

Enemy::Enemy(const CVector3D& pos, int k) : Base(0, 0)/*今後タイプ分け*/
{
	switch (k) {
		m_pos = pos;
		m_flip = true;
		m_jump = false;
		m_attack_effect = false;
		m_state = eIdle;

	case 1:

		m_img = COPY_RESOURCE("Enemy2", CImage);
		m_img.ChangeAnimation(0);


		break;

	}

}

void Enemy::StateIdle()
{
}

void Enemy::StateJump()
{
	const float jump_pow = 10.0f;

	
	if (m_jump == false && PUSH(CInput::eButton3)) {
		m_vec.y += jump_pow;
		m_jump = true;
	}
}

void Enemy::StateRun()
{
	const float speed = 3.0f;

	if (m_flip == true) {
		m_pos.x -= speed;
	}
	else m_pos.x += speed;
}

void Enemy::StateAttack()
{
}

void Enemy::StateDamage()
{
}


void Enemy::Update()
{
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
	}


	m_img.UpdateAnimation();
	
	


	m_vec.y -= GRAVITY;
	m_pos.y += m_vec.y;

	
	if (m_pos.y <= -400) {//仮　地面用
		m_pos.y = -400;
		m_vec.y = 0;
		m_state = eRun;
		m_jump = false;

	}







}

void Enemy::Draw()
{
	Base::Draw3D();
}
