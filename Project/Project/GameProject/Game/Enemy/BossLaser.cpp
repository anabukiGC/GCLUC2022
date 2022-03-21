#include "BossLaser.h"
BossLaser::BossLaser(const CVector3D& p) : Base(eType_BossLaser, 2)
{
	m_img = COPY_RESOURCE("BossLaser", CImage);
	//画像サイズ設定
	m_img.SetSize(1000, 300);
	//画像の中心位置設定
	m_img.SetCenter(500,150);
	m_rect = RectBox(-500, 0, 500,-100, 32, -32); 
	m_pos = p;

	
	
}

void BossLaser::Collision(Task* t)
{
}

void BossLaser::Update()
{
	m_img.ChangeAnimation(0, false);

	if (m_img.CheckAnimationEnd() ){
		SetKill();
	}
	m_img.UpdateAnimation();
	
}

void BossLaser::Draw()
{
	Base::Draw3D();
}
