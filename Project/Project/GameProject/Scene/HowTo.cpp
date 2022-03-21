#include "HowTo.h"

HowTo::HowTo():Base(eType_Scene,13)
{
	m_img = COPY_RESOURCE("Title", CImage);
}

HowTo::~HowTo()
{
}

void HowTo::Update()
{
	if (PUSH(CInput::eButton3)) {//‚ ‚»‚Ñ‚©‚½
		SetKill();
	}
}

void HowTo::Draw()
{
	m_img.Draw();
}
