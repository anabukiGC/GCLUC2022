#pragma once
#include "Base.h"

class Game : public Base {
public:
	Game();
	~Game();
	bool m_clear = false;//ƒNƒŠƒA”»’è

private:
	void Update();
	void Draw();

	bool m_gameOver;
};