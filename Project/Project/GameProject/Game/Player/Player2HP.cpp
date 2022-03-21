#include "Player2Hp.h"
#include"Player.h"

Player2Hp::Player2Hp(BaseType type, Player* player) :Base(type, 2)
{
		m_img = COPY_RESOURCE("Player2HP", CImage);
		m_player2 = player;
		m_img.SetCenter(0, 0);
		m_img.SetRect(54, 464, 644, 577);//Â
		m_img.SetSize(m_player2->GetHp(), 32);
}

void Player2Hp::Draw()
{
	m_img.SetRect(87, 226, 489, 287);//Ô
	m_img.SetSize(270, 50);
	m_img.SetPos(595, 60);
	m_img.Draw();

	if (m_player2)
	{
		float w = m_player2->GetHp();//ˆê‰ñ•Ï”‚É“ü‚ê‚Ä
		if (w <= 0)
		{
			m_player2 = NULL;
			return;//-‚É‚È‚Á‚½‚ç•`‰æ‚µ‚È‚¢
		}
		m_img.SetRect(87, 393, 489, 454);//Ô
		m_img.SetSize(w * 2.7, 50);
		m_img.SetPos(595, 60);
		m_img.Draw();
	}

	m_img.SetRect(11, 0, 535, 157);	//ƒvƒŒƒCƒ„[HP
	m_img.SetSize(400, 150);
	m_img.SetPos(500, 0);
	m_img.Draw();
}