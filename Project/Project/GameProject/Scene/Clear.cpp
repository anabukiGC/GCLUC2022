#include "Clear.h"
#include "Title.h"
Clear::Clear() : Base(eType_Scene, 10)
{
	m_img = COPY_RESOURCE("Clear", CImage);
}

Clear::~Clear()
{
	new Title();
}

void Clear::Update()
{
	if (PUSH(CInput::eButton3)) {
		SetKill();
	}
}

void Clear::Draw()
{
	
		m_img.Draw();
}
