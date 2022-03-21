#pragma once

#include "Base.h"
class PlayerEffect : public Base {
public:
	PlayerEffect(BaseType type, const CVector3D& pos, bool flip);
private:
	int DleatTime;

	void Update();
	void Draw();
	void Collision(Task* t);
};