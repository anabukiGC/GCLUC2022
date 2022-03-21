#include "UI.h"
#include "../Global.h"
#include "TaskManager.h"
#include "Player.h"
#include "Ranking.h"


UI::UI(const CVector2D& pos, int k) : Base(eType_UI, 11)
{
	kind = k;
	switch (kind) {

	case 1://スコア用

		m_img = COPY_RESOURCE("ScoreTime", CImage);
		m_pos = pos;

		break;
	case 2://タイム用
		m_img = COPY_RESOURCE("ScoreTime", CImage);
		m_pos = pos;

		break;

	}
}

void UI::Update()
{
	
}

void UI::Draw()
{
	if (kind == 1) {//スコア

		m_img.SetRect(25, 75, 529, 187);
		m_img.SetPos((SCREEN_WIDTH - 64*4-12), 0);
		m_img.SetSize(32 * 8, 64);
		m_img.Draw();

		for (int i = 0, s = g_score; i < 4; i++, s /= 10) {
			int p = s % 10;
			m_img.SetRect(0 + p * 64, 0, 64 + p * 64, 64);
			m_img.SetPos((SCREEN_WIDTH - 64) - i * 64, 0);
			m_img.SetSize(32, 64);
			m_img.Draw();
		}
		
	}
	if (kind == 2) {//

		m_img.SetRect(30, 277, 344, 392);
		m_img.SetPos((SCREEN_WIDTH - 64 * 4 - 12), 100);
		m_img.SetSize(32 * 8, 64);
		m_img.Draw();

		for (int i = 0, s = g_time/60; i < 4; i++, s /= 10) {
			int p = s % 10;
			m_img.SetRect(0+ p * 64, 204, 64 + p * 64, 263);
			m_img.SetPos((SCREEN_WIDTH - 64) - i * 64, 100);
			m_img.SetSize(32, 64);
			m_img.Draw();
		}
	}
	
}
