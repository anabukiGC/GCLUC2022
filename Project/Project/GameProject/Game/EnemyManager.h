#pragma once
#include <GLLibrary.h>
#include "../Base/Base.h"
#include "../TaskSystem/TaskManager.h"
struct EnemyData {//構造体（データをまとめる）
	CVector3D pos;
	int cnt;

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
public:
	EnemyManager();//typeは弾の種類を区別する(型はベースで定義したものに合わせる）

	void Update();

	void Draw();

	bool isEnd();//bool型でtrueかfalseかの二択
	
	bool GetWave();//bool型でtrueかfalseかの二択
};