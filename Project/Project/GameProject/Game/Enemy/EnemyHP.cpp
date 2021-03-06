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
	m_img.SetRect(22, 100, 200, 124);//赤
	m_img.SetSize(m_enemy->GetMaxHp(),32);
	Draw3D();
	
	float w = m_enemy->GetHp();//一回変数に入れて
	if (w < 0)return;//-になったら描画しない
	m_img.SetRect(22, 173, 200, 197);//青
	m_img.SetSize(w, 32);
	Draw3D();

	m_img.SetRect(20, 26, 202, 54);//枠
	m_img.SetSize(m_enemy->GetMaxHp(), 32);
	Draw3D();
}



