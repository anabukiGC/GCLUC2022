#include "UI.h"
#include "../Global.h"
#include "TaskManager.h"
#include "Player.h"
UI::UI(const CVector2D& pos, int k) : Base(eType_UI, 11)
{
	kind = k;
	switch (kind) {

	case 1://�X�R�A�p

		m_img = COPY_RESOURCE("ScoreTime", CImage);
		m_pos = pos;

		break;
	case 2://�^�C���p
		m_img = COPY_RESOURCE("ScoreTime", CImage);
		m_pos = pos;

		break;
	case 3://���U���g�p
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
	if (kind == 1) {//�X�R�A



		for (int i = 0, s = g_score; i < 4; i++, s /= 10) {
			int p = s % 10;
			m_img.SetRect(0 + p * 64, 0, 64 + p * 64, 64);
			m_img.SetPos((SCREEN_WIDTH - 64) - i * 64, 0);
			m_img.SetSize(32, 64);
			m_img.Draw();
		}
	}
	if (kind == 2) {//



		for (int i = 0, s = g_time/60; i < 4; i++, s /= 10) {
			int p = s % 10;
			m_img.SetRect(0 + p * 64, 0, 64 + p * 64, 64);
			m_img.SetPos((SCREEN_WIDTH - 64) - i * 64, 500);
			m_img.SetSize(32, 64);
			m_img.Draw();
		}
	}
	if (kind == 3) {//���U���g

		for (int i = 0, s = g_score; i < 4; i++, s /= 10) {
			int p = s % 10;
			m_img.SetRect(0 + p * 64, 0, 64 + p * 64, 64);
			m_img.SetPos((SCREEN_WIDTH/2-400) - i * 150, 700);
			m_img.SetSize(128, 256);
			m_img.Draw();
		}
	}
}