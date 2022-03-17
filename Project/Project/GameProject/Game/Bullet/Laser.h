#pragma once

#include "Base.h"
class Laser : public Base {
private:
	void Update();
	void Draw();
public:
	Laser(BaseType type, const CVector3D& p, bool flip);
	//“–‚½‚è”»’èŒŸØ
	void Collision(Task* t);
};