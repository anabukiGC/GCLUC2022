#include "PlayerHP.h"
#include"Player.h"

PlayerHp::PlayerHp(Player* player) :Base(0, 2)
{
	m_img = COPY_RESOURCE("Player2HP", CImage);
	m_player = player;
	m_img.SetCenter(0, 0);
	m_img.SetRect(54, 464, 644, 577);//青
	m_img.SetSize(m_player->GetHp(), 32);
}

void PlayerHp::Draw() 
{
	m_img.SetRect(11, 0, 535, 287);	//プレイヤーHP
	m_img.SetSize(500, 200);
	m_img.SetPos(0, 0);
	m_img.Draw();

	m_img.SetRect(87, 226, 489, 287);//赤
	m_img.SetSize(m_player->GetMaxHp() * 5, 200);
	m_img.SetPos(0, 0);
	m_img.Draw();
	
	if (m_player)
	{
		float w = m_player->GetHp();//一回変数に入れて
		if (w <= 0)
		{
			m_player = NULL;
			return;//-になったら描画しない
		}
		m_img.SetRect(87, 393, 489, 454);//青
		m_img.SetSize(w * 5, 32);
		m_img.SetPos(0, 0);
		m_img.Draw();
	}
}