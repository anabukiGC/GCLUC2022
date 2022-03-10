#include "EnemyHP.h"
#include"Enemy.h"

EnemyHp::EnemyHp(Enemy*enemy,int k):Base(0,0)
{
	kind = k;
	switch (kind) {

	case 1:
		m_img = COPY_RESOURCE("HP", CImage);
		m_enemy = enemy;
		m_img.SetSize(m_enemy->GetHp(), 32);
		break;

	case 2:
		m_img = COPY_RESOURCE("HP", CImage);
		m_enemy = enemy;
		m_img.SetSize(m_enemy->GetHp(), 32);
		break;
	}
}

void EnemyHp::Draw() {
	if(kind==1){
	float w = m_enemy->GetHp();//一回変数に入れて
	if (w < 0)return;//-になったら描画しない
	m_img.SetSize(w, 32);
}
	
	Draw3D();
}



