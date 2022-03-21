#include "Base.h"

CVector2D Base::m_scroll(0, 0);

Base::Base(int id, int priority) : Task(id,priority)
	, m_pos(0,0,0),m_vec(0,0,0),m_flip(false)
{
	
}

Base::~Base()
{
}

void Base::Update()
{
}

CVector2D Base::Get2DPos(CVector3D pos)
{
	CVector2D pos2D(pos.x - m_scroll.x - pos.z / 4, -pos.y - m_scroll.y + pos.z / 2 + GROUND);
	return pos2D;
}

void Base::Draw()
{
}

void Base::Draw3D()
{
	CVector2D pos2D = Get2DPos(m_pos);
	m_img.SetPos(pos2D);
	m_img.SetFlipH(m_flip);
	m_img.Draw();



	//ƒfƒoƒbƒO—p@‹éŒ`‚Ì•\Ž¦
	

	RectBox rect1 = RectBox(
		m_pos.x + m_rect.m_left,
		m_pos.y +m_rect.m_top,
		m_pos.x + m_rect.m_right,
		m_pos.y + m_rect.m_bottom,
		m_pos.z + m_rect.m_near,
		m_pos.z + m_rect.m_far);

	/*Œã–Ê*/
	CVector2D rect_ltf = Get2DPos(CVector3D(rect1.m_left, rect1.m_top, rect1.m_far));//‚RD‚ð‚QDÀ•W‚É•ÏŠ·
	CVector2D rect_rbf = Get2DPos(CVector3D(rect1.m_right, rect1.m_bottom, rect1.m_far));//‚RD‚ð‚QDÀ•W‚É•ÏŠ·


	CRect rect2 = CRect(
		rect_ltf.x, rect_ltf.y, rect_rbf.x, rect_rbf.y
	);
	
	Utility::DrawQuad(
		CVector2D(rect2.m_left, rect2.m_top),
		CVector2D(rect2.m_width, rect2.m_height),

		CVector4D(0, 0, 1, 0.5f));


	/*‘O–Ê*/
	CVector2D rect_ltn=Get2DPos(CVector3D(rect1.m_left,rect1.m_top,rect1.m_near));//‚RD‚ð‚QDÀ•W‚É•ÏŠ·
	CVector2D rect_rbn = Get2DPos(CVector3D(rect1.m_right, rect1.m_bottom, rect1.m_near));//‚RD‚ð‚QDÀ•W‚É•ÏŠ·


	CRect rect = CRect(
		rect_ltn.x, rect_ltn.y, rect_rbn.x, rect_rbn.y
	);

	Utility::DrawQuad(
		CVector2D(rect.m_left, rect.m_top),
		CVector2D(rect.m_width,rect.m_height),
	
		CVector4D(1, 0, 0, 0.5f));


}


void Base::Collision(Base* b)
{
}

bool Base::CollisionRect(Base* b1, Base* b2)
{
	//b1‚Ì‹éŒ`
	RectBox rect1 = RectBox(
		b1->m_pos.x + b1->m_rect.m_left,
		b1->m_pos.y + b1->m_rect.m_top,
		b1->m_pos.x + b1->m_rect.m_right,
		b1->m_pos.y + b1->m_rect.m_bottom,
		b1->m_pos.z + b1->m_rect.m_near,
		b1->m_pos.z + b1->m_rect.m_far);
	//b2‚Ì‹éŒ`
	RectBox rect2 = RectBox(
		b2->m_pos.x + b2->m_rect.m_left,
		b2->m_pos.y + b2->m_rect.m_top,
		b2->m_pos.x + b2->m_rect.m_right,
		b2->m_pos.y + b2->m_rect.m_bottom,
		b1->m_pos.z + b1->m_rect.m_near,
		b1->m_pos.z + b1->m_rect.m_far);

	//‹éŒ`“¯Žm‚Ì”»’è
	if (rect1.m_left <= rect2.m_right && rect1.m_right >= rect2.m_left &&
		rect1.m_top >= rect2.m_bottom && rect1.m_bottom <= rect2.m_top &&
		rect1.m_near >= rect2.m_far && rect1.m_far <= rect2.m_near)
		return true;

	return false;
}