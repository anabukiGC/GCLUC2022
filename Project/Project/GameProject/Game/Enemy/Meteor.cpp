#include "Meteor.h"

Meteor::Meteor(const CVector3D& pos):Base(eType_Boss,1)
{
	m_img = COPY_RESOURCE("NomalBullet1", CImage);
	//�摜�T�C�Y�ݒ�
	m_img.SetSize(40, 40);
	//�摜�̒��S�ʒu�ݒ�
	m_img.SetCenter(20, 27);
	m_rect = RectBox(-20, -27, 20, 0, 32, -32);

}


void Meteor::Update()
{
}

void Meteor::Draw()
{
}



void Meteor::Collision(Task* t)
{
}
