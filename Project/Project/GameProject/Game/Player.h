#pragma once
#include "../Base/Base.h"

class Player : public Base
{
public:
	Player(const CVector3D& pos);

	void Update();
	void Draw();
private:
	
};