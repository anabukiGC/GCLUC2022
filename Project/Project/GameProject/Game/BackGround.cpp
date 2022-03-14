#include "BackGround.h"

void BackGround::Update()
{

}

BackGround::BackGround() : Base(eType_Field,0)
{
	m_inFrontGround[0] = COPY_RESOURCE("BackGround1", CImage);
	m_inFrontGround[1] = COPY_RESOURCE("BackGround2", CImage);
	m_inFrontGround[2] = COPY_RESOURCE("BackGround3", CImage);
	m_backGround = COPY_RESOURCE("BackGround4", CImage);
	m_stage[0] = COPY_RESOURCE("Stage1", CImage);
	m_stage[1] = COPY_RESOURCE("Stage2", CImage);
	m_stage[0].SetSize(1920, 500);
	m_stage[1].SetSize(1920, 500);
}

void BackGround::Draw()
{
	m_backGround.Draw();
	int sx = (int)m_scroll.x % (1920 * 3);
	for (int i = 0; i <= 3; i++)
	{
		m_inFrontGround[i % 3].SetPos(-sx + 1920 * i, 0);
		m_inFrontGround[i % 3].Draw();
	}
	for (int i = 0; i <= 2; i++)
	{
		m_stage[i % 2].SetPos(-sx + 1920 * i, 500);
		m_stage[i % 2].Draw();
	}
}
