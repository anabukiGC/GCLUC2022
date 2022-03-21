#include "Laser.h"
Laser::Laser(const CVector3D& p, bool flip, int LifeTime): Base(eType_Laser, 2)
{
	m_img = COPY_RESOURCE("ChargeBullet2", CImage);
	//画像サイズ設定
	m_img.SetSize(2000, 100);
	//画像の中心位置設定
	m_img.SetCenter(0, 100);
	m_rect = RectBox(0, 100, 2000, 0, 32, -32);
	m_pos = p;
	m_flip = flip;
	m_lifeTime = LifeTime;
	Ysize = 0;
	see = 0;
	SOUND("SE_BossLaser")->Play();
}

void Laser::Collision(Task* t)
{
}

void Laser::Update()
{
	if (Ysize <= 200)
	{
		Ysize += 10;
	}
	if (see <= 1 && m_lifeTime >= 90)
	{
		m_img.SetColor(1, 1, 1, see += 0.05);
	}
	else  if (see >= 0 && m_lifeTime >= 0 && m_lifeTime <= 20)
	{
		m_img.SetColor(1, 1, 1, see -= 0.05);
	}
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
