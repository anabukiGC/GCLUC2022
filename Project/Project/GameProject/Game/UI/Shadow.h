#pragma once
#include"../Base/Base.h"

class Shadow :public Base {
public:
	Shadow(Base*b);//�Ώۂ̓G��n����p

	void Draw();
	Base* m_chara;//enemyHp�̃����o�[
};