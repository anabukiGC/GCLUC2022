#pragma once

#include "Base.h"
class Laser : public Base {
private:
	void Update();
	void Draw();
public:
	Laser(BaseType type, const CVector3D& p, bool flip);
	//�����蔻�茟��
	void Collision(Task* t);
};