#pragma once
#include "Base.h"
class Boss;//�N���X��錾���ċ�����

class BossHp :public Base {
private:
	void Draw();
public:
	BossHp(Boss* boss);//�Ώۂ̓G��n����p

	
	Boss* m_boss;//bossHp�̃����o�[
};