#pragma once
#include "Base.h"
class UI;//�N���X��錾���ċ�����

class UI :public Base {
public:
	UI(const CVector2D& pos, int k);//�Ώۂ̓G��n����p

	void Update();
	void Draw();
	int kind = 0;//��ގ��ʗp
};