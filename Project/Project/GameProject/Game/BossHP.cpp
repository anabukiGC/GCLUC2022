#include "BossHP.h"
#include"Boss.h"

BossHp::BossHp(Boss* boss) :Base(0, 0)
{
	m_img = COPY_RESOURCE("BossHP", CImage);
	m_boss = boss;
	m_img.SetCenter(0, 0);
	m_img.SetRect(54, 464, 644, 577);//青
	m_img.SetSize(m_boss->GetHp(), 50);
}

void BossHp::Draw()
{
	m_img.SetRect(54, 260, 645, 373);//赤
	m_img.SetSize(m_boss->GetMaxHp(), 50);
	Draw3D();

	float w = m_boss->GetHp();//一回変数に入れて
	if (w < 0)return;//-になったら描画しない
	m_img.SetRect(54, 464, 644, 577);//青
	m_img.SetSize(w, 50);
	Draw3D();

	m_img.SetRect(26, 15, 685, 192);//枠
	m_img.SetSize(m_boss->GetMaxHp(), 50);
	Draw3D();
}
