#include "Debuff.h"

Debuff::Debuff(const CVector2D& pos) :Base(eType_UI, 11)
{
	m_pos = pos;
	m_img = COPY_RESOURCE("Debuff", CImage);
	m_img.SetSize(32,32);
	LifeTime = 300;
}
void Debuff::Update()
{
	LifeTime--;
	if (LifeTime == 0)
	{
		SetKill();
	}
}

void Debuff::Draw()
{
	CVector2D pos2D = Get2DPos(m_pos);
	m_img.SetPos(pos2D);
	m_img.Draw();
}

