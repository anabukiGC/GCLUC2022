#pragma once

#include "Base.h"
class Bullet : public Base {
private:
	void Update();
	void Draw();

	float m_ang;
public:
	Bullet(BaseType type, const CVector3D& p, bool flip);

	//�����蔻�茟��
	void Collision(Task* t);
};
