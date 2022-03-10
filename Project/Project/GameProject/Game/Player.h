#pragma once
#include "../Base/Base.h"
#include "../TaskSystem/TaskManager.h"

class Player : public Base
{
public:
	Player(const CVector3D& pos, bool flip);

	void Update();
	void Draw();
	void Collision(Task* t);


private:
	//状態
	enum 
	{
		eState_Idle,
		eState_Jump,
		eState_Attack,
	};

	//状態変数
	int m_state;

	//着地フラグ
	bool	m_is_ground;

	//ジャンプ時着地地点座標取得
	float JumpPosition;
	//一度だけY座標を取得するためのフラグ
	bool GetY;
	//ジャンプ時間
	int JumpTime;


	//各状態での挙動
	void StateIdle();
	void StateJump();
	void StateAttack();

	int time;
};