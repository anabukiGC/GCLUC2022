#include "Bullet.h"
#include "Player.h"

Bullet::Bullet(BaseType type, const CVector3D& pos, bool flip) : Base(type, 1)
{
	if (type == eType_NomalBullet)
	{
		m_img = COPY_RESOURCE("NomalBullet1", CImage);
		//画像サイズ設定
		m_img.SetSize(40, 40);
		//画像の中心位置設定
		m_img.SetCenter(20, 27);
		m_rect = RectBox(-20, -27, 20, 0, 32, -32);
	}

	else if (type == eType_ChargeBullet2)
	{
		m_img = COPY_RESOURCE("ChargeBullet2", CImage);
		//画像サイズ設定
		m_img.SetSize(1000, 200);
		//画像の中心位置設定
		m_img.SetCenter(20, 27);
		m_rect = RectBox(-20, -27, 20, 0, 32, -32);
	}
	else
	{
		printf("エラー");
	}
	m_pos = pos;
	m_flip = flip;
}

void Bullet::Update()
{
		const float BulletSpeed = 20.0f;
		if (m_flip)
		{
			m_pos.x += BulletSpeed;
		}
		if (!m_flip)
		{
			m_pos.x -= BulletSpeed;
		}
}

void Bullet::Draw()
{
	Base::Draw3D();
}

void Bullet::Collision(Task* t)
{
	switch (t->GetID())
	{
	case eType_Enemy:
	case eType_Boss:
		if (Base* b = dynamic_cast<Base*>(t))
		{
			if (CollisionRect(b, this))
			{
				SetKill();
			}
		}
		break;
	}
}
