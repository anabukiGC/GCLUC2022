#include "PlayerEffect.h"
#include "Player.h"

PlayerEffect::PlayerEffect(BaseType type, const CVector3D& pos, bool flip) : Base(type, 1)
{
	m_img = COPY_RESOURCE("PlayerEffect", CImage);
	//画像サイズ設定
	m_img.SetSize(40, 40);
	//画像の中心位置設定
	m_img.SetCenter(20, 40);
	m_rect = RectBox(-20, 40, 20, 0, 32, -32);
	m_pos = pos;
	m_flip = flip;

	m_lifeTime = 120;
}

void PlayerEffect::Update()
{
	m_lifeTime--;
	if (m_lifeTime <= 0)
	{
		SetKill();
	}
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
