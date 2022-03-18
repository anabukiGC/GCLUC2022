#include "Meteor.h"

Meteor::Meteor(const CVector3D& pos):Base(eType_Boss_Meteo,1)
{
	m_pos = pos;
	m_img = COPY_RESOURCE("Meteor", CImage);
	//�摜�T�C�Y�ݒ�
	m_img.SetSize(256, 256);
	//�摜�̒��S�ʒu�ݒ�
	m_img.SetCenter(128, 128);
	m_rect = RectBox(-128, 256, 128, 0, 32, -32);
	m_shadow_size = CVector2D(256, 256);//�摜�T�C�Y�p
	m_shadow = new Shadow(this,m_shadow_size);//�|�C���^�[�n���̂�this
	m_img.ChangeAnimation(0);
}


void Meteor::Update()
{
	
	m_vec.y -= GRAVITY;
	m_pos.y += m_vec.y;


	if (m_pos.y <= 0) {//���@�n�ʗp
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
