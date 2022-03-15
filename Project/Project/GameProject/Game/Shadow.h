#pragma once
#include"../Base/Base.h"

class Shadow :public Base {
public:
	Shadow(Base*b);//‘ÎÛ‚Ì“G‚ğ“n‚¹‚é—p

	void Draw();
	Base* m_chara;//enemyHp‚Ìƒƒ“ƒo[
};