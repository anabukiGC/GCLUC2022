#pragma once
#include "Base.h"

class Shadow :public Base {
	void Draw();
public:
	Shadow(Base*b);//対象の敵を渡せる用

	
	Base* m_chara;//enemyHpのメンバー
};