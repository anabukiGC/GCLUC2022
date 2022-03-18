#pragma once
#include "Base.h"
#include "PlayerHP.h"
#include "TaskManager.h"

class Player : public Base
{
public:
	Player(int kind, const CVector3D& pos, bool flip);
	void Collision(Task* t);
	int GetHp();//Hpの取得
	int GetMaxHp();//Hpの取得

	PlayerHp* m_p_hp;

	int m_hp = 0;
	int m_max_hp = 0;

	int m_kind;
	enum
	{
		eSword,
		eGun,
	};
private:
	void Update();
	void Draw();

	//画像サイズ拡大割合
	float m_scale;

	//銃の弾を打ったフラグ
	bool Fire;

	//ジャンプフラグ
	bool m_jump;

	CVector2D m_key_dir;

	//状態
	enum 
	{
		eState_Idle,
		eState_Jump,
		eState_JumpAttack,
		eState_SwordAttack1,
		eState_SwordAttack2,
		eState_SwordAttack3,
		eState_GunAttack1,
		eState_GunAttack2,
		eState_GunAttack3,
		eState_Damage,
		eState_Die,
	};


	//状態変数
	int m_state;

	//攻撃状態変数
	int m_state_attack;
	int m_state_attack2;
	int m_state_attack3;

	//攻撃コンボ猶予時間
	int m_secondAttackTime;
	//着地フラグ
	bool m_bound;

	//無敵時間
	int m_mutekiTime;
	//ジャンプ時着地地点座標取得
	float JumpPosition;
	//一度だけY座標を取得するためのフラグ
	bool GetY;
	//ジャンプ時間
	int JumpTime;

	//左右のRect
	RectBox RectRight;
	RectBox RectLeft;

	//各状態での挙動
	void StateIdle();
	void StateJump();
	void StateJumpAttack();
	void StateSwordAttack1();
	void StateSwordAttack2();
	void StateSwordAttack3();
	void StateGunAttack1();
	void StateGunAttack2();
	void StateGunAttack3();
	void StateDamage();
	void StateDie();

	int time;

	int HoldTime;
};