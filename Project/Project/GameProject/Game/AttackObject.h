#pragma once
#include "../Base/Base.h"
class AttackObject : public Base {
private:
	void Update();
	void Draw();//�����蔻��p
public:
	AttackObject(BaseType type, const CVector3D& p, const RectBox &rect);
	
	//�����蔻�茟��
	void Collision(Task* t);
};
