#pragma once
#include "Base.h"
class Enemy;//�N���X��錾���ċ�����

class EnemyHp :public Base {
	void Draw();
public:
	EnemyHp(Enemy* enemy);//�Ώۂ̓G��n����p
	
	
	Enemy* m_enemy;//enemyHp�̃����o�[
};