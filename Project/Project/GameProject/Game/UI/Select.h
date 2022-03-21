#pragma once
#include "Base.h"
class Select;//クラスを宣言して教える

class Select :public Base {
	void Update();
	void Draw();
public:
	Select(const CVector2D& pos, int k);//対象の敵を渡せる用


	int m_kind = 0;//種類識別用
	bool m_stop = false;
};