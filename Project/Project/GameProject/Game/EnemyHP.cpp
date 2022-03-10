#include "EnemyHP.h"
#include"Enemy.h"

EnemyHp::EnemyHp(Enemy*enemy):Base(0,0)
{
	m_img = COPY_RESOURCE("HP", CImage);
	m_enemy = enemy;
	m_img.SetSize(m_enemy->GetHp(), 32);
}

void EnemyHp::Draw() {
	float w = m_enemy->GetHp();//一回変数に入れて
	if (w < 0)return;//-になったら描画しない
	m_img.SetSize(w, 32);

	
	Draw3D();
}



