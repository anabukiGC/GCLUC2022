#pragma once
#include "../Base/Base.h"
#include "PlayerHP.h"
#include "../TaskSystem/TaskManager.h"

class Player : public Base
{
public:
	Player(const CVector3D& pos, bool flip);

	void Update();
	void Draw();
	void Collision(Task* t);
	int GetHp();//Hpの取得
	int GetMaxHp();//Hpの取得

	PlayerHp* m_p_hp;

	int m_hp = 0;
	int m_max_hp = 0;

	//銃の弾を打ったフラグ
	bool Fire;

private:
	//状態
	enum 
	{
		eState_Idle,
		eState_Jump,
		eState_Attack1,
		eState_Attack2,
		eState_Attack3,
	};


	//状態変数
	int m_state;

	//着地フラグ
	bool m_bound;

	//ジャンプ時着地地点座標取得
	float JumpPosition;
	//一度だけY座標を取得するためのフラグ
	bool GetY;
	//ジャンプ時間
	int JumpTime;


	//各状態での挙動
	void StateIdle();
	void StateJump();
	void StateAttack1();
	void StateAttack2();
	void StateAttack3();

	int time;
};