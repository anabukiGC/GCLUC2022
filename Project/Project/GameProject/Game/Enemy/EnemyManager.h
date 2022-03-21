#pragma once
#include <GLLibrary.h>
#include "Base.h"
#include "TaskManager.h"
struct EnemyData {//構造体（データをまとめる）
	CVector3D pos;
	int cnt;
	enum {
		eEnemy1,
		eEnemy2,
		eEnemy3,
		eBoss
	};
	int type;//種類分け
	bool flip=false;
};

struct EnemyWave {
	int pos_x;
	EnemyData* data;
	int size;
};
class EnemyManager :public Base {//敵の出現を管理するクラス
private:
	int m_wave_idx;//waveの数（何WAVEあるのか）
	int m_wave_size;//全体のサイズ
	int m_cnt;//時間計測用
	int m_idx;//データ位置（０～何番目か）
	int m_size;//データサイズ(いくつあるのか決める配列の中身的な）
	bool m_ivent = false;
	CImage m_img2;

	void Update();

	void Draw();
public:
	EnemyManager();//typeは弾の種類を区別する(型はベースで定義したものに合わせる）


	bool isEnd();//bool型でtrueかfalseかの二択
	
	bool GetWave();//敵がいるか判別
};