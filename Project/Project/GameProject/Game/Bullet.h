#pragma once

#pragma once
#include "../Base/Base.h"
class Bullet : public Base {
private:
public:
	Bullet(BaseType type, const CVector2D& p);
	void Update();
	void Draw();
	//�����蔻�茟��
	void Collision(Base* b);
};