#pragma once

#include "Base.h"
class PlayerEffect : public Base {
private:
	void Update();
	void Draw();
	CVector3D vec;

	float m_lifeTime;
public:
	PlayerEffect(BaseType type, const CVector3D& p, bool flip);

	//“–‚½‚è”»’èŒŸØ
	void Collision(Task* t);
};