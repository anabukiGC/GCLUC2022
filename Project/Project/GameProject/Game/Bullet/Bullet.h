#pragma once

#include "Base.h"
class Bullet : public Base {
private:
	void Update();
	void Draw();
	int m_ang;

public:
	Bullet(BaseType type, const CVector3D& p, bool flip);

	//“–‚½‚è”»’èŒŸØ
	void Collision(Task* t);
};
