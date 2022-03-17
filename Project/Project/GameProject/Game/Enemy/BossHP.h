#pragma once
#include "Base.h"
class Boss;//クラスを宣言して教える

class BossHp :public Base {
public:
	BossHp(Boss* boss);//対象の敵を渡せる用

	void Draw();
	Boss* m_boss;//bossHpのメンバー
};