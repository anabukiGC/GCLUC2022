#pragma once

#include "Base.h"
class Laser : public Base {
public:
	Laser(const CVector3D& p, bool flip, int LifeTime);
	//“–‚½‚è”»’èŒŸØ
	void Collision(Task* t);

private:
	void Update();
	void Draw();

	int m_lifeTime;
};