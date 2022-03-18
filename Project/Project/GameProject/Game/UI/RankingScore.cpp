#include "RankingScore.h"

RankingScore::RankingScore(int score, const CVector2D& pos, const float size):Task(eType_UI, 11)
{
	m_score = score;
	m_pos = pos;
	m_size = size;
	m_img = COPY_RESOURCE("ScoreTime", CImage);
}

void RankingScore::Draw()
{
	for (int i = 0, s = m_score; i < 4; i++, s /= 10) {
		int p = s % 10;
		m_img.SetRect(0 + p * 64, 0, 64 + p * 64, 64);
		m_img.SetPos((m_pos.x) - i * 64*m_size,m_pos.y);
		m_img.SetSize(64*m_size, 128*m_size);
		m_img.Draw();
	}
}
