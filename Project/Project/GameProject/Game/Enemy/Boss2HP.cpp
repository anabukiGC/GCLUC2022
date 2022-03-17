#include "Boss2HP.h"
#include"Boss2.h"

Boss2Hp::Boss2Hp(Boss2* boss2) :Base(0, 3)
{
	m_img = COPY_RESOURCE("BossHP", CImage);
	m_boss2 = boss2;
	m_img.SetCenter(0, 0);

}

void Boss2Hp::Draw()
{
	m_img.SetRect(54, 260, 645, 373);//�_���[�W�\�L
	m_img.SetSize(m_boss2->GetMaxHp(), 50);
	Draw3D();

	float w = m_boss2->GetHp();//���ϐ��ɓ����
	if (w < 0)return;//-�ɂȂ�����`�悵�Ȃ�
	m_img.SetRect(54, 464, 644, 577);//HP�\�L
	m_img.SetSize(w, 50);
	Draw3D();

	//m_img.SetRect(26, 15, 685, 192);//�g
	m_img.SetRect(54, 53, 644, 172);//�g
	m_img.SetSize(m_boss2->GetMaxHp(), 50);
	Draw3D();
}
