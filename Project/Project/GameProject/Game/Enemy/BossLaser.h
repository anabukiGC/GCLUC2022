#pragma once
#include "Base.h"
class BossLaser : public Base {
public:
	BossLaser(const CVector3D& p);
	//“–‚½‚è”»’èŒŸØ
	void Collision(Task* t);

private:
	void Update();
	void Draw();

	int m_lifeTime;
	float Ysize;
	float see;
};