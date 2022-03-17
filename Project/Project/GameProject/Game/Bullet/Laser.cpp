#include "Laser.h"
Laser::Laser(const CVector3D& p, bool flip, int LifeTime): Base(eType_Laser, 2)
{
	m_img = COPY_RESOURCE("ChargeBullet2", CImage);
	//画像サイズ設定
	m_img.SetSize(1000, 200);
	//画像の中心位置設定
	m_img.SetCenter(20, 27);
	m_rect = RectBox(-20, -27, 20, 0, 32, -32);
	m_pos = p;
	m_flip = flip;
	m_lifeTime = LifeTime;
}

void Laser::Collision(Task* t)
{
}

void Laser::Update()
{
	m_lifeTime--;
	if (m_lifeTime <= 0)
	{
		SetKill();
	}
}

void Laser::Draw()
{
	Base::Draw3D();
}
