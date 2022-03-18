#pragma once
#include "Base.h"
class RankingScore : public Task {
private:
	CImage m_img;
	int m_score;
	CVector2D m_pos;
	float m_size;

public:
	RankingScore(int score, const CVector2D& pos,const float size);
	void Draw();
};