#include "Shadow.h"

Shadow::Shadow(Base* b):Base(0,0)
{
	m_img = COPY_RESOURCE("Shadow", CImage);
	m_chara = b;
	m_img.SetCenter(16, 16);
	m_img.SetSize(32, 32);
}

void Shadow::Draw()
{
	if (m_chara) {//NULL�΍��p

		m_pos = m_chara->m_pos;//�Q�[�W�Ɏ����̍��W�����Ă��钲���\
		m_pos.y = 0;

	}
	Draw3D();
}
