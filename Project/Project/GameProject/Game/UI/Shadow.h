#pragma once
#include "Base.h"

class Shadow :public Base {
public:
	Shadow(Base*b);//対象の敵を渡せる用

	void Draw();
	Base* m_chara;//enemyHpのメンバー
};