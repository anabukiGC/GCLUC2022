#pragma once
#include "Base.h"

class Debuff :public Base {
	void Update();
	void Draw();
public:
	Debuff(const CVector2D& pos);//�Ώۂ̓G��n����p]
	
	int LifeTime;


	
};