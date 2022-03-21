#include "EnemyHP.h"
#include"Enemy.h"

EnemyHp::EnemyHp(Enemy*enemy):Base(0,3)
{
	m_img = COPY_RESOURCE("EnemyHP", CImage);
	m_enemy = enemy;
	m_img.SetCenter(0,0);
}

void EnemyHp::Draw() 
{
	m_img.SetRect(22, 100, 200, 124);//Ô
	m_img.SetSize(m_enemy->GetMaxHp(),32);
	Draw3D();
	
	float w = m_enemy->GetHp();//ˆê‰ñ•Ï”‚É“ü‚ê‚Ä
	if (w < 0)return;//-‚É‚È‚Á‚½‚ç•`‰æ‚µ‚È‚¢
	m_img.SetRect(22, 173, 200, 197);//Â
	m_img.SetSize(w, 32);
	Draw3D();

	m_img.SetRect(20, 26, 202, 54);//˜g
	m_img.SetSize(m_enemy->GetMaxHp(), 32);
	Draw3D();
}



