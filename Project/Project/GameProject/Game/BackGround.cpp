#include "Background.h"

void BackGround::Update()
{

}

BackGround::BackGround() : Base(eType_Field,0)
{
	m_inFrontGround[0] = COPY_RESOURCE("BackGround1", CImage);
	m_inFrontGround[1] = COPY_RESOURCE("BackGround2", CImage);
	m_inFrontGround[2] = COPY_RESOURCE("BackGround3", CImage);
	m_backGround = COPY_RESOURCE("BackGround4", CImage);
	m_stage = COPY_RESOURCE("Stage1", CImage);
	m_stage.SetSize(1920, 500);
}

void BackGround::Draw()
{
	m_backGround.Draw();
	m_backGround.SetPos(0, 100);
	int fx = (int)m_scroll.x % (1920 * 3);
	for (int i = 0; i <= 3; i++)
	{
		m_inFrontGround[i % 3].SetPos(-fx + 1920 * i, 100);
		m_inFrontGround[i % 3].Draw();
	}
	int sx = (int)m_scroll.x % (1920 * 3);
	m_stage.SetRect(sx, 0, sx + 1920, 1080);
	m_stage.SetPos(0, 580);
	m_stage.Draw();
}
