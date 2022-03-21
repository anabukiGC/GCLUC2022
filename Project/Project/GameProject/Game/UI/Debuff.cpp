#include "Debuff.h"

Debuff::Debuff(const CVector2D& pos) :Base(eType_UI, 11)
{
	m_pos = pos;
	m_img = COPY_RESOURCE("Debuff", CImage);

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

	m_img.Draw();
}

