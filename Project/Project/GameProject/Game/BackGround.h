#pragma once

#include "Base.h"
class BackGround : public Base {
private:
	void Update();
	void Draw();

	CImage m_inFrontGround[3];
	CImage m_backGround;
	CImage m_stage;
public:
	BackGround();
};
