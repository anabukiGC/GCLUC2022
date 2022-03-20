#pragma once
#include "Base.h"
class GameOver : public Base {
public:
	GameOver(const CVector2D& pos);
	~GameOver();
private:
	void Update();
	void Draw();

};
