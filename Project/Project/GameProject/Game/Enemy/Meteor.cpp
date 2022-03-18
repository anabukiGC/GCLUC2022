#include "Meteor.h"

Meteor::Meteor(const CVector3D& pos):Base(eType_Boss_Meteo,1)
{
	m_pos = pos;
	m_img = COPY_RESOURCE("Meteor", CImage);
	//画像サイズ設定
	m_img.SetSize(256, 256);
	//画像の中心位置設定
	m_img.SetCenter(128, 128);
	m_rect = RectBox(-128, 256, 128, 0, 32, -32);
	m_shadow_size = CVector2D(256, 256);//画像サイズ用
	m_shadow = new Shadow(this,m_shadow_size);//ポインター渡すのでthis
	m_img.ChangeAnimation(0);
}


void Meteor::Update()
{
	
	m_vec.y -= GRAVITY;
	m_pos.y += m_vec.y;


	if (m_pos.y <= 0) {//仮　地面用
		m_pos.y = 0;
		m_vec.y = 0;
		m_img.ChangeAnimation(1,false);
		if (m_img.CheckAnimationEnd()) {
			SetKill();
		}
	}
	m_img.UpdateAnimation();
}

void Meteor::Draw()
{
	Base::Draw3D();
}



void Meteor::Collision(Task* t)
{
}
