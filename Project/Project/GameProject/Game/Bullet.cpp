#include "Bullet.h"
#include "Player.h"

Bullet::Bullet(BaseType type, const CVector3D& pos, bool flip) : Base(type, 1)
{
	m_img = COPY_RESOURCE("NomalBullet", CImage);
	//�摜�T�C�Y�ݒ�
	m_img.SetSize(40, 40);
	//�摜�̒��S�ʒu�ݒ�
	m_img.SetCenter(20, 27);
	m_pos = pos;
	m_rect = RectBox(-20, -27, 20, 0, 32, -32);

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

void Bullet::Collision(Base* b)
{
	switch (b->GetID())
	{
	case eType_Enemy:
	case eType_Boss:
		if (Base* b = dynamic_cast<Base*>(b))
		{
			if (CollisionRect(b, this))
			{
				SetKill();
			}
		}
		break;
	}
}
