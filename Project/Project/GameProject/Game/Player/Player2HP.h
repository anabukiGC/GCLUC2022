#pragma once
#include "Base.h"
class Player;//�N���X��錾���ċ�����

class Player2Hp :public Base {
public:
	Player2Hp(BaseType type, Player* player);//�Ώۂ̓G��n����p

	Player* m_player2;//enemyHp�̃����o�[
private:
	void Draw();
};
