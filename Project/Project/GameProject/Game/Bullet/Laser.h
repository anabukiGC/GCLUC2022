#pragma once

#include "Base.h"
class Laser : public Base {
public:
	Laser(const CVector3D& p, bool flip, int LifeTime);
	//�����蔻�茟��
	void Collision(Task* t);

private:
	void Update();
	void Draw();

	int m_lifeTime;
};