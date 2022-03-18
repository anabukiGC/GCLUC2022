#pragma once
#include "Base.h"
class Meteor : public Base {
private:
	void Update();
	void Draw();
	CVector3D vec;
	float m_ang;

public:
	Meteor(const CVector3D& pos);

	//�����蔻�茟��
	void Collision(Task* t);
};