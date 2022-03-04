#include "Enemy.h"
#include "../Global.h"

Enemy::Enemy(const CVector3D& pos, int k) : Base(0, 0)/*今後タイプ分け*/
{
	switch (k) {
		
	case 1:

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

void Enemy::StateJump()
{
	const float jump_pow = 10.0f;
	m_img.ChangeAnimation(1, false);
	
	if (m_jump == false && m_img.GetIndex() >= 2) {
		 
		m_jump = true;
		
		m_vec.y += jump_pow;
		
		}
	
	
	
	if (m_img.CheckAnimationEnd()) {
		m_state = eRun;

	}
}

void Enemy::StateRun()
{

	const float speed = 3.0f;
	m_jump = false;
 	m_img.ChangeAnimation(0);

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
	case eJump:
		StateJump();
		break;
	case eAttack:
		StateAttack();
		break;
	case eDamage:
		StateDamage();
		break;
	}


	
	
	


	m_vec.y -= GRAVITY;
	m_pos.y += m_vec.y;

	
	if (m_pos.y <= 0) {//仮　地面用
		m_pos.y = 0;
		m_vec.y = 0;
		
	}

	if (m_pos.x <= 0) {/*跳ねかえる*/
		m_flip =false;
	}else if (m_pos.x >= SCREEN_WIDTH) {
		m_flip = true;
	}


	if (PUSH(CInput::eButton3)) {
		m_state = eJump;
	}
	m_img.UpdateAnimation();

}

void Enemy::Draw()
{
	Base::Draw3D();
}
