#include "Base.h"

CVector2D Base::m_scroll(0, 0);

Base::Base(int id, int priority) : Task(id,priority)
	, m_pos(0,0,0),m_vec(0,0,0),m_jump(false),m_flip(false)
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
	CVector2D pos2D(m_pos.x - m_scroll.x - m_pos.z / 8 , -m_pos.y - m_scroll.y + m_pos.z / 2 + GROUND);
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

bool Base::CollisionRect(Base* b1, Base* b2)
{
	//b1の矩形
	RectBox rect1 = RectBox(
		b1->m_pos.x + b1->m_rect.m_left,
		b1->m_pos.y + b1->m_rect.m_top,
		b1->m_pos.x + b1->m_rect.m_right,
		b1->m_pos.y + b1->m_rect.m_bottom,
		b1->m_pos.z + b1->m_rect.m_near,
		b1->m_pos.z + b1->m_rect.m_far);
	//b2の矩形
	RectBox rect2 = RectBox(
		b2->m_pos.x + b2->m_rect.m_left,
		b2->m_pos.y + b2->m_rect.m_top,
		b2->m_pos.x + b2->m_rect.m_right,
		b2->m_pos.y + b2->m_rect.m_bottom,
		b1->m_pos.z + b1->m_rect.m_near,
		b1->m_pos.z + b1->m_rect.m_far);

	//矩形同士の判定
	if (rect1.m_left <= rect2.m_right && rect1.m_right >= rect2.m_left &&
		rect1.m_top <= rect2.m_bottom && rect1.m_bottom >= rect2.m_top &&
		rect1.m_near >= rect2.m_far && rect1.m_far <= rect2.m_near)
		return true;

	return false;
}