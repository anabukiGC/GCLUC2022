#pragma once
#include "Base.h"

class Game : public Base {
public:
	Game();
	~Game();
	void Update();
	void Draw();
	bool m_clear = false;//�N���A����

};