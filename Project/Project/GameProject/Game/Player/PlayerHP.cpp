#include "PlayerHP.h"
#include"Player.h"

PlayerHp::PlayerHp(BaseType type, Player* player) :Base(type, 2)
{
		m_img = COPY_RESOURCE("Player1HP", CImage);
		m_player = player;
}

void PlayerHp::Draw() 
{
	m_img.SetRect(87, 226, 489, 287);//赤
	m_img.SetSize(270, 50);
	m_img.SetPos(95, 60);
	m_img.Draw();

		if (m_player)
		{
			float w = m_player->GetHp();//一回変数に入れて
			if (w <= 0)
			{
				m_player = NULL;
				return;//-になったら描画しない
			}
			m_img.SetRect(87, 393, 489, 454);//赤
			m_img.SetSize(w * 2.7, 50);
			m_img.SetPos(95, 60);
			m_img.Draw();
		}

		m_img.SetRect(11, 0, 535, 157);	//プレイヤーHP
		m_img.SetSize(400, 150);
		m_img.SetPos(0, 0);
		m_img.Draw();
}