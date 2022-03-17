#pragma once
#include "Base.h"
class Enemy;//クラスを宣言して教える

class EnemyHp :public Base {
	void Draw();
public:
	EnemyHp(Enemy* enemy);//対象の敵を渡せる用
	
	
	Enemy* m_enemy;//enemyHpのメンバー
};