#pragma once
#include "Base.h"
class Player;//クラスを宣言して教える

class PlayerHp :public Base {
public:
	PlayerHp(Player* player);//対象の敵を渡せる用

	Player* m_player;//enemyHpのメンバー
private:
	void Draw();
};
