#pragma once
#include "Base.h"

class Shadow :public Base {
	void Draw();
public:
	Shadow(Base*b);//�Ώۂ̓G��n����p

	
	Base* m_chara;//enemyHp�̃����o�[
};