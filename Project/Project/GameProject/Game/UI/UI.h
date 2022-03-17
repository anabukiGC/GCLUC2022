#pragma once
#include "Base.h"
class UI;//ƒNƒ‰ƒX‚ğéŒ¾‚µ‚Ä‹³‚¦‚é

class UI :public Base {
public:
	UI(const CVector2D& pos, int k);//‘ÎÛ‚Ì“G‚ğ“n‚¹‚é—p

	void Update();
	void Draw();
	
};