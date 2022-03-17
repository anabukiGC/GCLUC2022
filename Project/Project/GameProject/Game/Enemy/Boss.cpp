#include "Boss.h"
#include"EnemyManager.h"
#include"Bullet.h"
Boss::Boss(const CVector3D& pos, int k) :Base(eType_Boss, 1)
{
	kind = k;
	switch (kind) {

	case EnemyData::eBoss:
		m_img = COPY_RESOURCE("Boss1", CImage);

		m_hp = 500;//変更用
		m_max_hp = 500;
		m_pos = pos;
		m_b_hp = new BossHp(this);//ポインター渡すのでthis
		m_flip = false;
		m_jump = false;
		m_attack_effect = false;
		m_state = eIdle;
		m_img.SetCenter(128*2, 256*2);
		m_rect = RectBox(-128*2, 256*2, 128*2, 0, 32, -32);

		break;

	}
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
}

void Boss::StateRun()
{
}

void Boss::StateAttack1()
{
	m_img.ChangeAnimation(1, false);//遠距離攻撃
	if (m_img.CheckAnimationEnd()) {
		m_state = eIdle;
		m_cnt = 0;
	}

}

void Boss::StateAttack2()
{
	
	m_img.ChangeAnimation(2, false);
	if (m_img.CheckAnimationEnd()) {
		m_state = eIdle;
	}
}

void Boss::StateDamage()
{
	m_img.ChangeAnimation(3, false);

	if (m_img.CheckAnimationEnd() && m_hp > 0) {
		
		m_hp -= 200;
		m_cnt = 0;
		m_state = eIdle;
	}
	if (m_img.CheckAnimationEnd() && m_hp <= 0) {
		m_state = eDie;
	}
}

void Boss::StateDie()
{
	m_img.ChangeAnimation(4, false);


	if (m_img.CheckAnimationEnd()) {
		Game* g = dynamic_cast<Game*>(TaskManager::GetInstance()->GetTask(eType_Scene));
		g->m_clear = true;

		
		SetKill();
		if (m_b_hp) {//ｈｐを持ってたら
			
			m_b_hp->SetKill();
			m_b_hp = NULL;//消えた時用
			
		}
	}
}


void Boss::Update()
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
	case eAttack1:
		StateAttack1();
		break;
	case eAttack2:
		StateAttack2();
		break;
	case eDamage:
		StateDamage();
		break;
	case eDie:
		StateDie();
		break;
	}






	if (m_pos.y <= 0) {//仮　地面用
		m_pos.y = 0;
		m_vec.y = 0;

	}

	if (kind == 1 && m_cnt == 180) {//秒数で状態遷移
		m_state = eAttack1;
	}


	if (m_hp <= 0) {
		m_state = eDie;

	}
	m_img.UpdateAnimation();
}

void Boss::Draw()
{
	if (m_b_hp) {//ｈｐを持ってたらNULL対策用

		m_b_hp->m_pos = CVector3D(m_pos.x-100,m_pos.y,m_pos.z);//ゲージに自分の座標を入れている調整可能

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
				m_state = eDamage;
			}
		}
		break;
	}
}
