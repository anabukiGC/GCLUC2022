#pragma once

#include "Base.h"
class Bullet : public Base {
private:
	void Update();
	void Draw();
	CVector3D vec;
	float m_ang;

public:
	Bullet(BaseType type, const CVector3D& p, bool flip, float ang = 0);

	//“–‚½‚è”»’èŒŸØ
	void Collision(Task* t);
};
