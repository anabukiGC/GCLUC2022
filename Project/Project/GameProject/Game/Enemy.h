#pragma once
#include "../Base/Base.h"


class Enemy : public Base
{
	enum {//整数番号を振る(0～）
		eIdle,
		eRun,
		eAttack,
		eDamage,
		eDie
		
	};

	//状態
	int m_state;
	
	int m_cnt = 0;//時間判別用

	int m_hp = 0;

	bool m_bound;

	static const float speed;

	//攻撃エフェクトフラグ
	bool m_attack_effect;
	//状態分岐
	
	void StateIdle();//内部的な（限定的な）処理なのでややこしくならないようにここだけ(void)
	void StateRun();
	void StateAttack();
	void StateDamage();
	void StateDie();

public:
	Enemy(const CVector3D& pos,int k); //k=種類分け番号

	void Update();
	void Draw();
private:

};