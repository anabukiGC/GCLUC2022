#pragma once
#include"../Base/Base.h"
class Enemy;//�N���X��錾���ċ�����

class EnemyHp :public Base {
public:
	EnemyHp(Enemy* enemy, int k);//�Ώۂ̓G��n����p
	
	void Draw();
	Enemy* m_enemy;//enemyHp�̃����o�[
};