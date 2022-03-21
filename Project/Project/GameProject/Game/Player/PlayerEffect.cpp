#include "PlayerEffect.h"
#include "Player.h"

PlayerEffect::PlayerEffect(BaseType type, const CVector3D& pos, bool flip): Base(type, ePriorityPlayerEffect)
{
	Player* p = Player::GetPlayer(Player::eSword);

	m_img = COPY_RESOURCE("PlayerEffect", CImage);
	m_img.SetSize(40, 40);
	m_img.SetCenter(0, 0);
	m_rect = RectBox(0,0,40,-40,-32,32);


	DleatTime = 0;
	m_flip = flip;

	m_pos = pos;
}

void PlayerEffect::Update()
{
	DleatTime++;
	if (DleatTime >= 6)
	{
		SetKill();
	}

	//—Dæ“x•ÏX
	ChangePriority(ePriorityPlayer + m_pos.z);
}

void PlayerEffect::Draw()
{
	Base::Draw3D();
}

void PlayerEffect::Collision(Task* t)
{
		switch (t->GetID())
		{
		case eType_Enemy:
		case eType_Boss:
			if (Base* b = dynamic_cast<Base*>(t))
			{
				SetKill();
			}
			break;
		}
}
