#pragma once
#include "Base.h"
class Select;//�N���X��錾���ċ�����

class Select :public Base {
	void Update();
	void Draw();
public:
	Select(const CVector2D& pos, int k);//�Ώۂ̓G��n����p


	int m_kind = 0;//��ގ��ʗp
	bool m_stop = false;
};