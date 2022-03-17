#include "Boss.h"
#include "Boss2.h"
#include"EnemyManager.h"
#include"Bullet.h"
#include"TaskManager.h"

const float Boss::speed = 3.0;//‚Ç‚±‚Å‚àg‚¦‚é‚æ‚¤‚É
Boss::Boss(const CVector3D& pos) :Base(eType_Boss, 1)
{

		m_img = COPY_RESOURCE("Boss1", CImage);

		m_hp = 5000;//•ÏX—p
		m_max_hp = 5000;
		m_pos = pos;
		m_b_hp = new BossHp(this);//ƒ|ƒCƒ“ƒ^[“n‚·‚Ì‚Åthis
		m_flip = false;
		m_attack_effect = false;
		m_state = eIdle;
		m_img.SetCenter(128*2, 256*2);
		m_rect = RectBox(-128*2, 256*2, 128*2, 0, 32, -32);

}

int Boss::GetHp()
{
	return m_hp;
}

int Boss::GetMaxHp()
{
	return m_max_hp;
}

void Boss::StateIdle()
{
	m_img.ChangeAnimation(0);

	if (m_bound == false) {//cˆÚ“®
		m_pos.z -= speed;
	}
	else if (m_bound == true) {
		m_pos.z += speed;
	}


	if (m_pos.z <= 0) {//’µ‚Ë‚©‚¦‚éO`GROUND‚Ü‚Å
		m_bound = true;
	}
	else if (m_pos.z >= GROUND) {
		m_bound = false;
	}

}




void Boss::StateRun()
{
}

void Boss::StateAttack1()
{
	m_invin= true;
	m_img.ChangeAnimation(1, false);//‰“‹——£UŒ‚
	if (m_img.CheckAnimationEnd()) {
		m_state = eIdle;
		m_invin = false;
		m_second=11;
	}

}

void Boss::StateAttack2()
{
	m_invin = true;
	m_img.ChangeAnimation(2, false);//‹ßÚUŒ‚
	if (m_img.CheckAnimationEnd()) {
		m_state = eIdle;
		m_invin = false;
		m_cnt = 0;
	}
}

void Boss::StateDamage()
{
	
	m_img.ChangeAnimation(3, false);

	if (m_img.CheckAnimationEnd() && m_hp > 0) {
		
		m_hp -= 200;
		m_state = eIdle;
	}
/*	if (m_img.CheckAnimationEnd() && m_hp <= 0) {
		m_state = eChange;
	}*/
	
}

void Boss::StateChange()
{
	m_invin = true;
	m_img.ChangeAnimation(4, false);


	if (m_img.CheckAnimationEnd()) {
		
		new Boss2(m_pos);
		SetKill();
		if (m_b_hp) {//‚ˆ‚‚ğ‚Á‚Ä‚½‚ç
			
			m_b_hp->SetKill();
			m_b_hp = NULL;//Á‚¦‚½—p
			
		}
	}
}


void Boss::Update()
{
	m_cnt++;
	m_second = m_cnt / 60;//•b”‚É•ÏŠ·
	//ó‘Ô‚É‚æ‚é•ªŠò§Œä
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
	case eChange:
		StateChange();
		break;
	}






	if (m_pos.y <= 0) {//‰¼@’n–Ê—p
		m_pos.y = 0;
		m_vec.y = 0;

	}

	





	if ( m_second==2) {//•b”‚Åó‘Ô‘JˆÚ
		
		m_state = eAttack1;
	}
	if ( m_second==6) {//•b”‚Åó‘Ô‘JˆÚ
		m_state = eAttack2;
	}


	if (m_hp <= 0) {
		m_state = eChange;

	}
	m_img.UpdateAnimation();
}

void Boss::Draw()
{
	if (m_b_hp) {//‚ˆ‚‚ğ‚Á‚Ä‚½‚çNULL‘Îô—p

		m_b_hp->m_pos = CVector3D(m_pos.x-100,m_pos.y,m_pos.z);//ƒQ[ƒW‚É©•ª‚ÌÀ•W‚ğ“ü‚ê‚Ä‚¢‚é’²®‰Â”\

	}
	Base::Draw3D();
}

void Boss::Collision(Task* t)
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
				}else
					m_hp -= 200;
				
			}
		}
		break;
	}
}
