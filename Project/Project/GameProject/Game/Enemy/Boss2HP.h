#pragma once
#include "Base.h"
class Boss2;//�N���X��錾���ċ�����

class Boss2Hp :public Base {
private:
	void Draw();
public:
	Boss2Hp(Boss2* boss2);//�Ώۂ̓G��n����p


	Boss2* m_boss2;//bossHp�̃����o�[
};