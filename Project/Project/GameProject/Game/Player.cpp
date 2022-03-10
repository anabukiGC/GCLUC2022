#include "Player.h"


Player::Player(const CVector3D& pos) : Base(0,0)
{
	m_img = COPY_RESOURCE("Player", CImage);
	m_img.ChangeAnimation(0);
	m_pos = pos;
	time = 0;
}

void Player::Update()
{
	//—Dæ“x‚Ì•ÏX
	ChangePriority(10);
	m_img.UpdateAnimation();
	const float speed = 2.0f;

	if (HOLD(CInput::eUp))
	{
		m_pos.z -= speed;
	}
	if (HOLD(CInput::eDown))
	{
		m_pos.z += speed;
	}
	if (HOLD(CInput::eLeft))
	{
		m_pos.x -= speed;
	}
	if (HOLD(CInput::eRight))
	{
		m_pos.x += speed;
	}
}

void Player::Draw()
{
	Base::Draw3D();
}

void Player::Collision(Task* t)
{
	switch (t->GetID())
	{
	case eType_Enemy:
		if (Base* b = dynamic_cast<Base*>(t))
		{
			CollisionRect(b, this);
		}
		break;
	}
}
