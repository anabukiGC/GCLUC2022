#pragma once
#include"../Base/Base.h"
class Enemy;//クラスを宣言して教える

class EnemyHp :public Base {
public:
	EnemyHp(Enemy* enemy, int k);//対象の敵を渡せる用
	
	void Draw();
	Enemy* m_enemy;//enemyHpのメンバー
};