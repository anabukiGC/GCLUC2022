#pragma once
#include "Base.h"
class UI;//�N���X��錾���ċ�����

class UI :public Base {
	void Update();
	void Draw();
public:
	UI(const CVector2D& pos, int k);//�Ώۂ̓G��n����p

	
	int kind = 0;//��ގ��ʗp
};