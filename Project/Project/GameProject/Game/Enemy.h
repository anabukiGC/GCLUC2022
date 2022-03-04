#pragma once
#include "../Base/Base.h"


class Enemy : public Base
{
	enum {//整数番号を振る(0～）
		eIdle,
		eJump,
		eRun,
		eAttack,
		eDamage,
		
	};

	//状態
	int m_state;

	//攻撃エフェクトフラグ
	bool m_attack_effect;
	//状態分岐
	
	void StateIdle();//内部的な（限定的な）処理なのでややこしくならないようにここだけ(void)
	void StateJump();
	void StateRun();
	void StateAttack();
	void StateDamage();

public:
	Enemy(const CVector3D& pos,int k); //k=種類分け番号

	void Update();
	void Draw();
private:

};