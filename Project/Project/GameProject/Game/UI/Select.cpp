#include "Select.h"
#include"../Global.h"
Select::Select(const CVector2D& pos, int k):Base(eType_Select,12)
{
	m_kind = k;
	m_pos = pos;
	switch (m_kind) {

	case 1:
		m_img = COPY_RESOURCE("Select", CImage);
		m_pos = pos;
		break;
	case 2:
		m_img = COPY_RESOURCE("HowTo", CImage);
		m_pos = pos;
		break;
	case 3:
		m_img = COPY_RESOURCE("Start", CImage);
		m_pos = pos;

		break;

	}
}
void Select::Update()
{
	if (m_kind == 1) {
		if (m_stop == false && PUSH(CInput::eDown)) {
			SOUND("SE_Select")->Play();
			m_pos.y -= 160;
			m_stop = true;
		}
		if (m_stop == true && PUSH(CInput::eUp)) {
			SOUND("SE_Select")->Play();
			m_pos.y += 160;
			m_stop = false;
		}
	}
	
}

void Select::Draw()
{
	m_img.SetPos(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);
	Draw3D();
}


