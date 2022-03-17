#pragma once
#include "../Base/Base.h"
class AttackObject : public Base {
private:
	void Update();
	void Draw();//‚ ‚½‚è”»’è—p
public:
	AttackObject(BaseType type, const CVector3D& p, const RectBox &rect);
	
	//“–‚½‚è”»’èŒŸØ
	void Collision(Task* t);
};
