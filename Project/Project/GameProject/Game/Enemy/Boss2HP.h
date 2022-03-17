#pragma once
#include "Base.h"
class Boss2;//クラスを宣言して教える

class Boss2Hp :public Base {
private:
	void Draw();
public:
	Boss2Hp(Boss2* boss2);//対象の敵を渡せる用


	Boss2* m_boss2;//bossHpのメンバー
};