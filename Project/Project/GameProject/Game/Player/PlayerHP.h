#pragma once
#include "Base.h"
class Player;//�N���X��錾���ċ�����

class PlayerHp :public Base {
public:
	PlayerHp(Player* player);//�Ώۂ̓G��n����p

	Player* m_player;//enemyHp�̃����o�[
private:
	void Draw();
};
