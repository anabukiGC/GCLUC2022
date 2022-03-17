#include "Shadow.h"

Shadow::Shadow(Base* b):Base(0,2)
{
	m_img = COPY_RESOURCE("Shadow", CImage);
	m_chara = b;
	m_img.SetCenter(128, 128);
	m_img.SetSize(256, 256);
}

void Shadow::Draw()
{
	if (m_chara) {//NULL�΍��p

		m_pos = m_chara->m_pos;//�Q�[�W�Ɏ����̍��W�����Ă���B���W�����\
		m_pos.y = 0;

	}
	Draw3D();
}
