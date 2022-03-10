#pragma once
#include "../Base/Base.h"
#include "../TaskSystem/TaskManager.h"

class Player : public Base
{
public:
	Player(const CVector3D& pos);

	void Update();
	void Draw();
	void Collision(Task* t);

private:
	int time;
};