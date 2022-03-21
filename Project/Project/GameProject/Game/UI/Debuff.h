#pragma once
#include "Base.h"

class Debuff :public Base {
	void Update();
	void Draw();
public:
	Debuff(const CVector2D& pos);//‘ÎÛ‚Ì“G‚ğ“n‚¹‚é—p]
	
	int LifeTime;


	
};