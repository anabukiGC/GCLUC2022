#include "AttackObject.h"

AttackObject::AttackObject(BaseType type, const CVector3D& p, const RectBox& rect):Base(type,1)
{
	m_pos = p;
	m_rect = rect;
}
void AttackObject::Update()
{
	SetKill();//1�t���[�������ł�
}

void AttackObject::Draw()
{
	//�f�o�b�O�p�@��`�̕\��

#if _DEBUG//�f�o�b�O���[�h�̂݋@�\����
	RectBox rect1 = RectBox(
		m_pos.x + m_rect.m_left,
		m_pos.y + m_rect.m_top,
		m_pos.x + m_rect.m_right,
		m_pos.y + m_rect.m_bottom,
		m_pos.z + m_rect.m_near,
		m_pos.z + m_rect.m_far);

	/*���*/
	CVector2D rect_ltf = Get2DPos(CVector3D(rect1.m_left, rect1.m_top, rect1.m_far));//�RD���QD���W�ɕϊ�
	CVector2D rect_rbf = Get2DPos(CVector3D(rect1.m_right, rect1.m_bottom, rect1.m_far));//�RD���QD���W�ɕϊ�


	CRect rect2 = CRect(
		rect_ltf.x, rect_ltf.y, rect_rbf.x, rect_rbf.y
	);
	/*
	Utility::DrawQuad(
		CVector2D(rect2.m_left, rect2.m_top),
		CVector2D(rect2.m_width, rect2.m_height),

		CVector4D(0, 0, 1, 0.5f));*/


		/*�O��*/
	CVector2D rect_ltn = Get2DPos(CVector3D(rect1.m_left, rect1.m_top, rect1.m_near));//�RD���QD���W�ɕϊ�
	CVector2D rect_rbn = Get2DPos(CVector3D(rect1.m_right, rect1.m_bottom, rect1.m_near));//�RD���QD���W�ɕϊ�


	CRect rect = CRect(
		rect_ltn.x, rect_ltn.y, rect_rbn.x, rect_rbn.y
	);

	/*Utility::DrawQuad(
		CVector2D(rect.m_left, rect.m_top),
		CVector2D(rect.m_width,rect.m_height),

		CVector4D(1, 0, 0, 0.5f));*/

#endif
}



void AttackObject::Collision(Task* t)
{
	switch (t->GetID())
	{
		
	case eType_Player:
		if(GetID()==eType_EnemyAttack1 || GetID() == eType_BossAttack1){
		if (Base* b = dynamic_cast<Base*>(t))
		{
			if (CollisionRect(b, this))
			{
				SetKill();
			}
		}
		}
		break;
	}
}
