#include "EnemyManager.h"
#include"Enemy.h"
EnemyData _stage1[] = {//出現データをまとめる
	{CVector3D(1000,0,500),0},//（座標）、時間（フレーム）
	{CVector3D(1000,0,500),60},
	{CVector3D(1000,0,500),60},
	{CVector3D(1000,0,500),60},
	{CVector3D(1000,0,500),60},
	{CVector3D(1000,0,500),60},
	{CVector3D(1000,0,500),60},
};
EnemyData _stage2[] = {//出現データをまとめる
	{CVector3D(1600,0,500),0},//（座標）、時間（フレーム）
	{CVector3D(1600,0,500),10},
	{CVector3D(1600,0,500),10},
	{CVector3D(1600,0,500),10},
	{CVector3D(1600,0,500),10},
	{CVector3D(1600,0,500),10},
	{CVector3D(1600,0,500),10},
};
EnemyWave wave_data[] = {
	{512,_stage1,sizeof(_stage1) / sizeof(_stage1[0])},
	{1024,_stage2,sizeof(_stage2) / sizeof(_stage2[0])}
};
EnemyManager::EnemyManager()
	:Base(0,0), m_cnt(0)//初期化の別の例
{
	m_wave_idx = 0;
	m_cnt = 0;
	m_idx = 0;
	m_wave_size = sizeof(wave_data) / sizeof(wave_data[0]);//全体のウェーブの個数を計算
}

void EnemyManager::Update()
{
	if (m_wave_idx >= m_wave_size) return;//ウェーブ全体が終わったら終了
	EnemyWave* wave = &wave_data[m_wave_idx];//ウェーブの値の内容を入れる
	if (m_scroll.x > wave->pos_x) {//指定地点に来たら
		m_ivent = true;
		if (m_idx < wave->size) {//設定した1WAVEのデータを超えたら終了
			m_cnt++;
			EnemyData* data = &_stage1[m_idx];
			if (m_cnt >= data->cnt) {//出現位置をデータから引っ張ってくるdata->pos.x,
				new Enemy(CVector3D(wave->pos_x + data->pos.x, data->pos.y, data->pos.z), 1);
				m_cnt = 0;
				m_idx++;
			}
		}
		else {
			if (isEnd()) {
				m_wave_idx++;
				m_idx = 0;
			}
		}
	}
	
}

void EnemyManager::Draw()
{
}

bool EnemyManager::isEnd()//まだ敵が出てくるかどうかの判定用
{
	if (m_idx >= m_wave_size) {//全部またはウェーブ終了出現したら
		return true;
	}
	else//まだ残っているなら
		return false;

	
}
