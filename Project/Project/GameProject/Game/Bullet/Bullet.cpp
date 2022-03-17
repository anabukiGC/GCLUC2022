#include "Bullet.h"
#include "Player.h"

Bullet::Bullet(BaseType type, const CVector3D& pos, bool flip, float ang) : Base(type, 1)
{
	m_ang = ang;
	if (type == eType_NomalBullet)
	{
		m_img = COPY_RESOURCE("NomalBullet1", CImage);
		//画像サイズ設定
		m_img.SetSize(40, 40);
		//画像の中心位置設定
		m_img.SetCenter(20, 27);
		m_rect = RectBox(-20, -27, 20, 0, 32, -32);
	}

	if (type == eType_NomalBullet2)
	{
		m_img = COPY_RESOURCE("NomalBullet2", CImage);
		//画像サイズ設定
		m_img.SetSize(100, 100);
		//画像の中心位置設定
		m_img.SetCenter(50, 50);
		m_rect = RectBox(-20, -27, 20, 0, 32, -32);
		float m_ang = 0;

	}

	if (type == eType_ChargeBullet2)
	{
		m_img = COPY_RESOURCE("ChargeBullet2", CImage);
		//画像サイズ設定
		m_img.SetSize(1000, 200);
		//画像の中心位置設定
		m_img.SetCenter(20, 27);
		m_rect = RectBox(-20, -27, 20, 0, 32, -32);
		float m_ang = 0;

	}
	else
	{
		printf("エラー");
	}
	m_pos = pos;
	m_flip = flip;

	m_vec = CVector3D(cos(ang), sin(ang), 0);
}

void Bullet::Update()
{
	const float BulletSpeed = 20.0f;

	CVector3D v = m_vec;

		if (m_flip)
		{
			v.x *= -1;
		}
		m_pos += v * BulletSpeed;
}

void Bullet::Draw()
{
	if(m_flip)
		m_img.SetAng(-m_ang);
	if(!m_flip)
		m_img.SetAng(m_ang);
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
