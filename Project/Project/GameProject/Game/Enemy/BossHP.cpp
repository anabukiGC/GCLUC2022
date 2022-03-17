#include "BossHP.h"
#include"Boss.h"

BossHp::BossHp(Boss* boss) :Base(0, 3)
{
	m_img = COPY_RESOURCE("BossHP", CImage);
	m_boss = boss;
	m_img.SetCenter(0, 0);
	
}

void BossHp::Draw()
{
	const int bar_width = 500;
	m_img.SetRect(54, 260, 645, 373);//�_���[�W�\�L
	m_img.SetSize(bar_width, 50);
	Draw3D();

	float w = m_boss->GetHp();//���ϐ��ɓ����
	if (w < 0)return;//-�ɂȂ�����`�悵�Ȃ�
	
	m_img.SetRect(54, 464, 644, 577);//HP�\�L
	m_img.SetSize(bar_width *w/ m_boss->GetMaxHp(), 50);//�����\��
	Draw3D();

	//m_img.SetRect(26, 15, 685, 192);//�g
	m_img.SetRect(54, 53, 644, 172);//�g
	m_img.SetSize(bar_width, 50);
	Draw3D();
}
