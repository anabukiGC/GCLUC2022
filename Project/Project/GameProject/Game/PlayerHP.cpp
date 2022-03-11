#include "PlayerHP.h"
#include"Player.h"

PlayerHp::PlayerHp(Player* player) :Base(0, 0)
{
	m_img = COPY_RESOURCE("HP", CImage);
	m_player = player;
	m_img.SetCenter(0, 0);
	m_img.SetRect(54, 464, 644, 577);//Â
	m_img.SetSize(m_player->GetHp(), 32);
}

void PlayerHp::Draw() {
	m_img.SetRect(54, 260, 645, 373);//Ô
	m_img.SetSize(m_player->GetMaxHp(), 32);
	m_img.SetPos(0, 0);
	m_img.Draw();
	
	if (m_player)
	{
		float w = m_player->GetHp();//ˆê‰ñ•Ï”‚É“ü‚ê‚Ä
		if (w <= 0)
		{
			m_player = NULL;
			return;//-‚É‚È‚Á‚½‚ç•`‰æ‚µ‚È‚¢
		}
		m_img.SetRect(54, 464, 644, 577);//Â
		m_img.SetSize(w, 32);
		m_img.SetPos(0, 0);
		m_img.Draw();
	}
}