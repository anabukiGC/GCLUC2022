#pragma once
#include "Base.h"
#include"BossHP.h"
#include"Game.h"

class Boss : public Base
{
	enum {//整数番号を振る(0～）
		eIdle,
		eRun,
		eAttack1,
		eAttack2,
		eDamage,
		eDie,
	};

	//状態
	int m_state;

	

	int m_hp = 0;
	int m_max_hp = 0;

	int m_cnt = 0;//時間判別用

	//攻撃エフェクトフラグ
	bool m_attack_effect;
	//状態分岐

	void StateIdle();//内部的な（限定的な）処理なのでややこしくならないようにここだけ(void)
	void StateRun();
	void StateAttack1();
	void StateAttack2();
	void StateDamage();
	void StateDie();


	void Update();
	void Draw();

public:
	Boss(const CVector3D& pos, int k); //k=種類分け番号
	int GetHp();//Hpの取得
	int GetMaxHp();//Hpの取得
	BossHp* m_b_hp;
	Game* m_game;
	void Collision(Task* t);
};