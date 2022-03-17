#pragma once
#include "Base.h"
class Player;//クラスを宣言して教える

class PlayerHp :public Base {
public:
	PlayerHp(Player* player);//対象の敵を渡せる用

	void Draw();
	Player* m_player;//enemyHpのメンバー
};
