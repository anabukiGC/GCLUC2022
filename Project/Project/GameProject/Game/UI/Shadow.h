#pragma once
#include "Base.h"

class Shadow :public Base {
	void Draw();
public:
	Shadow(Base*b,const CVector2D&size= CVector2D(256, 256));//�Ώۂ̓G��n����p

	
	Base* m_chara;
	CVector2D m_size;
};