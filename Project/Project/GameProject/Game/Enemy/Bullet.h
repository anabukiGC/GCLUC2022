#pragma once

#include "Base.h"
class Bullet : public Base {
private:
public:
	Bullet(BaseType type, const CVector3D& p, bool flip);
	void Update();
	void Draw();
	//�����蔻�茟��
	void Collision(Task* t);
};
