#pragma once
#include "Base.h"
#include"EnemyHP.h"
#include"Shadow.h"
class Enemy : public Base
{
	enum {//整数番号を振る(0〜）
		eAway,
		eRun,
		eAttack,
		eDamage,
		eDie
		
	};

	//状態
	int m_state;
	
	int m_cnt = 0;//時間判別用

	int m_hp = 0;
	int m_max_hp = 0;

	int m_bonus = 0;//ボーナス用

	bool m_bound;//跳ね返り用

	//ジャンプフラグ
	bool m_jump;
	int kind = 0;//種類識別用

	static const float speed;

	bool m_invin = false;//攻撃中断防止

	//攻撃エフェクトフラグ
	bool m_attack_effect;

	int m_debuffTime;
	bool m_debuff;

	bool Fire;

	//状態分岐
	
	void StateAway();//内部的な（限定的な）処理なのでややこしくならないようにここだけ(void)
	void StateRun();
	void StateAttack();
	void StateDamage();
	void StateDie();
	void Update();
	void Draw();
public:
	Enemy(const CVector3D& pos,int k, bool flip); //k=種類分け番号

	int GetHp();//Hpの取得
	int GetMaxHp();//Hpの取得

	void Collision(Task* t);
	EnemyHp* m_e_hp;
	Shadow* m_shadow;
	CVector2D m_shadow_size ;//画像サイズ用
};