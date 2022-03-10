#include "EnemyHP.h"
#include"Enemy.h"

EnemyHp::EnemyHp(Enemy*enemy):Base(0,0)
{
	m_img = COPY_RESOURCE("HP", CImage);
	m_enemy = enemy;
	m_img.SetSize(m_enemy->GetHp(), 32);
}

void EnemyHp::Draw() {
	float w = m_enemy->GetHp();//ˆê‰ñ•Ï”‚É“ü‚ê‚Ä
	if (w < 0)return;//-‚É‚È‚Á‚½‚ç•`‰æ‚µ‚È‚¢
	m_img.SetSize(w, 32);

	
	Draw3D();
}



