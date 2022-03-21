#pragma once

#include "Base.h"
class Title : public Base {
public:
	Title();
	~Title();
private:
	void Update();
	void Draw();
	bool m_start = false;
};