#include "Debuff.h"

Debuff::Debuff(const CVector2D& pos) :Base(eType_UI, 11)
{
	m_pos = pos;
	m_img = COPY_RESOURCE("Debuff", CImage);
}
void Debuff::Update()
{
	
}

void Debuff::Draw()
{

	m_img.Draw();
}

