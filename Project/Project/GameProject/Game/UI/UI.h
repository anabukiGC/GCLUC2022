#pragma once
#include "Base.h"
class UI;//クラスを宣言して教える

class UI :public Base {
	void Update();
	void Draw();
public:
	UI(const CVector2D& pos, int k);//対象の敵を渡せる用

	
	int kind = 0;//種類識別用
};