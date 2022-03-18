#pragma once

#include "Base.h"
class PlayerEffect : public Base {
public:
	PlayerEffect(int kind, const CVector3D& pos, bool flip);

	int m_kind;
	enum
	{
		eAttack1Effect,
		eAttack2Effect,
		eAttack3Effect,
	};
private:
	int DleatTime;

	void Update();
	void Draw();
	void Collision(Task* t);
};