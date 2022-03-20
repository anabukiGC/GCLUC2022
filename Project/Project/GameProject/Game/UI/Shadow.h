#pragma once
#include "Base.h"

class Shadow :public Base {
	void Draw();
public:
	Shadow(Base*b,const CVector2D&size= CVector2D(256, 256));//‘ÎÛ‚Ì“G‚ğ“n‚¹‚é—p

	
	Base* m_chara;
	CVector2D m_size;
};