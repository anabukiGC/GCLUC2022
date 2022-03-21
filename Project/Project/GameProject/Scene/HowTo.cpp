#include "HowTo.h"
#include "Title.h"
HowTo::HowTo():Base(eType_Scene,13)
{
	m_img = COPY_RESOURCE("HowTo2", CImage);
}

HowTo::~HowTo()
{
	new Title();
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
