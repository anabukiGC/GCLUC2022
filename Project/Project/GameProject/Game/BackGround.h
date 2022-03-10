#pragma once

#include "../Base/Base.h"
class BackGround : public Base {
private:
	CImage m_inFrontGround[3];
	CImage m_backGround;
public:
	BackGround();
	void Update();
	void Draw();
};
