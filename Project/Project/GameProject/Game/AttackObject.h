#pragma once
#include "../Base/Base.h"
class AttackObject : public Base {
private:
	void Update();
	void Draw();//あたり判定用
public:
	AttackObject(BaseType type, const CVector3D& p, const RectBox &rect);
	
	//当たり判定検証
	void Collision(Task* t);
};
