#include "PlayerHP.h"
#include"Player.h"

PlayerHp::PlayerHp(BaseType type, Player* player) :Base(type, 2)
{
		m_img = COPY_RESOURCE("Player1HP", CImage);
		m_player = player;
}

void PlayerHp::Draw() 
{
	m_img.SetRect(87, 226, 489, 287);//Ô
	m_img.SetSize(270, 50);
	m_img.SetPos(95, 60);
	m_img.Draw();

		if (m_player)
		{
			float w = m_player->GetHp();//ˆê‰ñ•Ï”‚É“ü‚ê‚Ä
			if (w <= 0)
			{
				m_player = NULL;
				return;//-‚É‚È‚Á‚½‚ç•`‰æ‚µ‚È‚¢
			}
			m_img.SetRect(87, 393, 489, 454);//Ô
			m_img.SetSize(w * 2.7, 50);
			m_img.SetPos(95, 60);
			m_img.Draw();
		}

		m_img.SetRect(11, 0, 535, 157);	//ƒvƒŒƒCƒ„[HP
		m_img.SetSize(400, 150);
		m_img.SetPos(0, 0);
		m_img.Draw();
}