#include "Base.h"

CVector2D Base::m_scroll(0, 0);

Base::Base(int id, int priority) : Task(id,priority)
	, m_pos(0,0,0),m_vec(0,0,0),m_jump(false),m_flip(false),m_rad(0)
{
	
}

Base::~Base()
{
}

void Base::Update()
{
}

void Base::Draw()
{
}

void Base::Draw3D()
{
	CVector2D pos2D(m_pos.x - m_scroll.x - m_pos.z / 8 , m_pos.y - m_scroll.y + m_pos.z / 2 + GROUND);
	m_img.SetPos(pos2D);
	m_img.SetFlipH(m_flip);
	m_img.Draw();


	//デバッグ用　矩形の表示
	CRect rect = CRect(
		m_pos.x + m_rect.m_left,
		m_pos.y + m_rect.m_top,
		m_pos.x + m_rect.m_right,
		m_pos.y + m_rect.m_bottom);
	/*
	Utility::DrawQuad(
		CVector2D(rect.m_left, rect.m_top) - m_scroll,
		CVector2D(rect.m_width, rect.m_height),
		CVector4D(1, 0, 0, 0.5f));
	*/
}


void Base::Collision(Base* b)
{
}

bool Base::CollisionCircle(Base* b1, Base* b2)
{
	//2点間の距離
	CVector3D v = b1->m_pos - b2->m_pos;
	float l = v.Length();
	//円同士の当たり判定
	if (l < b1->m_rad + b2->m_rad) {
		return true;
	}
	return false;
}