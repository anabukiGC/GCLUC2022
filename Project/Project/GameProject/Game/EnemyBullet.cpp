#include "EnemyBullet.h"
#include "Player.h"

EnemyBullet::EnemyBullet(BaseType type, const CVector3D& pos, bool flip, float ang) : Base(type, 1)
{
	m_ang = ang;
		m_img = COPY_RESOURCE("EnemyBullet", CImage);
		//画像サイズ設定
		m_img.SetSize(110, 20);
		//画像の中心位置設定
		m_img.SetCenter(55, 20);
		m_rect = RectBox(-55, 20, 55, 0, 32, -32);
		m_pos = pos;
	m_flip = flip;
}

void EnemyBullet::Update()
{
	const float BulletSpeed = 20.0f;

	if (m_flip)
	{
		m_pos.x -= BulletSpeed;
	}
	else
	{
		m_pos.x += BulletSpeed;
	}
}

void EnemyBullet::Draw()
{
	if (m_flip)
		m_img.SetAng(-m_ang);
	if (!m_flip)
		m_img.SetAng(m_ang);
	Base::Draw3D();
}

void EnemyBullet::Collision(Task* t)
{
	switch (t->GetID())
	{
	case eType_Player:
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