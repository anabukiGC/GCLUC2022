#pragma once
#include "Base.h"
class Player;//クラスを宣言して教える

class Player2Hp :public Base {
public:
	Player2Hp(BaseType type, Player* player);//対象の敵を渡せる用

	Player* m_player2;//enemyHpのメンバー
private:
	void Draw();
};
