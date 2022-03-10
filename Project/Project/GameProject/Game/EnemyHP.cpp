#include "EnemyHP.h"
#include"Enemy.h"

EnemyHp::EnemyHp(Enemy*enemy):Base(0,0)
{
	
		m_img = COPY_RESOURCE("HP", CImage);
		m_enemy = enemy;
		m_img.SetCenter(0,0);
		m_img.SetRect(54, 464, 644, 577);//��
		m_img.SetSize(m_enemy->GetHp(), 32);
		
	
	
}

void EnemyHp::Draw() {
	/*m_img. SetRect(0, 260,645 , 373);//��
	m_img.SetSize(m_enemy->GetMaxHp(),32);
	Draw3D();*/

	
	
	float w = m_enemy->GetHp();//���ϐ��ɓ����
	if (w < 0)return;//-�ɂȂ�����`�悵�Ȃ�
	m_img.SetRect(54, 464, 644, 577);//��
	m_img.SetSize(w, 32);
	Draw3D();
}



