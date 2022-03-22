#pragma once

#include"BossHP.h"
#include"Shadow.h"
#include "Debuff.h"
class Boss : public Base
{
	enum {//整数番号を振る(0～）
		eIdle,
		eRun,
		eAttack1,
		eAttack2,
		eDamage,
		eChange,
	};

	//状態
	int m_state;
	
	bool m_on;//デバフ表示用
	float m_hp = 0;
	int m_max_hp = 0;

	int m_cnt = 0;//時間判別用

	static const float speed;
	//攻撃エフェクトフラグ
	bool m_attack_effect;
	//状態分岐

	void StateIdle();//内部的な（限定的な）処理なのでややこしくならないようにここだけ(void)
	void StateRun();
	void StateAttack1();
	void StateAttack2();
	void StateDamage();
	void StateChange();


	void Update();
	void Draw();

	int m_second = 0;//秒数
	bool m_bound;//跳ね返り用
	bool m_invin = false;//攻撃中断防止
	bool Fire = false;//攻撃一回
	int m_debuffTime;
	bool m_debuff;
public:
	Boss(const CVector3D& pos); //k=種類分け番号
	int GetHp();//Hpの取得
	int GetMaxHp();//Hpの取得
	BossHp* m_b_hp;
	Shadow* m_shadow;
	Debuff* m_b_debuff;
	void Collision(Task* t);
	
	CVector2D m_shadow_size;//画像サイズ用
};