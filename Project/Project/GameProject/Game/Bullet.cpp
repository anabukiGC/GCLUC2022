#include "Bullet.h"

Bullet::Bullet(BaseType type, const CVector3D& pos) : Base(type, 1)
{
	m_img = COPY_RESOURCE("NomalBullet", CImage);
	//�摜�T�C�Y�ݒ�
	m_img.SetSize(40, 40);
	//�摜�̒��S�ʒu�ݒ�
	m_img.SetCenter(20, 27);
	m_pos = pos;
	m_rect = RectBox(-20, -27, 20, 0, 16, -16);
}

void Bullet::Update()
{
	const float BulletSpeed = 20.0f;
	m_pos.x += BulletSpeed;
}

void Bullet::Draw()
{
	Base::Draw3D();
}

void Bullet::Collision(Base* b)
{
}
