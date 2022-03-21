#pragma once

#include "Base.h"
class EnemyBullet : public Base {
private:
	void Update();
	void Draw();
	CVector3D vec;
	float m_ang;

public:
	EnemyBullet(BaseType type, const CVector3D& p, bool flip, float ang = 0);

	//“–‚½‚è”»’èŒŸØ
	void Collision(Task* t);
};
