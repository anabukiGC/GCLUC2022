#pragma once
#include"../Base/Base.h"
class Boss;//�N���X��錾���ċ�����

class BossHp :public Base {
public:
	BossHp(Boss* boss);//�Ώۂ̓G��n����p

	void Draw();
	Boss* m_boss;//enemyHp�̃����o�[
};