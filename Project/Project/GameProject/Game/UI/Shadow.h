#pragma once
#include "Base.h"

class Shadow :public Base {
	void Draw();
public:
	Shadow(Base*b,const CVector2D&size= CVector2D(256, 256));//対象の敵を渡せる用

	
	Base* m_chara;//enemyHpのメンバー
	CVector2D m_size;
};